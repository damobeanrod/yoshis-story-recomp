#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80437410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437410: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80437414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437418: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043741C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80437420: jal         0x8005FB74
    // 0x80437424: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8005FB74(rdram, ctx);
        goto after_0;
    // 0x80437424: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80437428: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8043742C: sw          $zero, 0x34($t7)
    MEM_W(0X34, ctx->r15) = 0;
    // 0x80437430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80437438: jr          $ra
    // 0x8043743C: nop

    return;
    // 0x8043743C: nop

;}
RECOMP_FUNC void func_8064C930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064C934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064C938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064C93C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C940: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C944: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8064C948: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C94C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064C954: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064C958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C95C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8064C960: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064C964: nop

    // 0x8064C968: bc1fl       L_8064C99C
    if (!c1cs) {
        // 0x8064C96C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8064C99C;
    }
    goto skip_0;
    // 0x8064C96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8064C970: jal         0x8064CD50
    // 0x8064C974: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C974: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064C978: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064C97C: jal         0x80067BBC
    // 0x8064C980: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064C980: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064C984: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064C988: jal         0x80067818
    // 0x8064C98C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064C98C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064C990: jal         0x8064A43C
    // 0x8064C994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064C994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064C998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064C99C:
    // 0x8064C99C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064C9A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064C9A4: jr          $ra
    // 0x8064C9A8: nop

    return;
    // 0x8064C9A8: nop

;}
RECOMP_FUNC void func_8045C928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045C928: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8045C92C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8045C930: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8045C934: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8045C938: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8045C93C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8045C940: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8045C944: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8045C948: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8045C94C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8045C950: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8045C954: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8045C958: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8045C95C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8045C960: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8045C964: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x8045C968: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8045C96C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045C970: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045C974: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045C978: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x8045C97C: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8045C980: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22C4) << 16);
    // 0x8045C984: lwc1        $f24, -0x24AC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22C4));
    // 0x8045C988: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045C98C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X2198) << 16);
    // 0x8045C990: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8045C994: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8045C998: lwc1        $f26, -0x25D8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X2198));
    // 0x8045C99C: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x8045C9A0: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8045C9A4: lw          $s0, 0x4($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X4);
    // 0x8045C9A8: lw          $s6, 0x30($t7)
    ctx->r22 = MEM_W(ctx->r15, 0X30);
    // 0x8045C9AC: lwc1        $f6, 0x6C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x8045C9B0: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x8045C9B4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8045C9B8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8045C9BC: sltiu       $at, $s6, 0x2
    ctx->r1 = ctx->r22 < 0X2 ? 1 : 0;
    // 0x8045C9C0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8045C9C4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8045C9C8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8045C9CC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x8045C9D0: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8045C9D4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045C9D8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8045C9DC: nop

    // 0x8045C9E0: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
    // 0x8045C9E4: lw          $t3, 0x174($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X174);
    // 0x8045C9E8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8045C9EC: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x8045C9F0: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x8045C9F4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8045C9F8: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8045C9FC: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x8045CA00: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8045CA04: addiu       $s2, $t4, 0x3C
    ctx->r18 = ADD32(ctx->r12, 0X3C);
    // 0x8045CA08: addiu       $s3, $t4, 0x6C
    ctx->r19 = ADD32(ctx->r12, 0X6C);
    // 0x8045CA0C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8045CA10: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8045CA14: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8045CA18: nop

    // 0x8045CA1C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x8045CA20: lw          $t9, 0x174($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X174);
    // 0x8045CA24: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8045CA28: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8045CA2C: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x8045CA30: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x8045CA34: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8045CA38: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8045CA3C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8045CA40: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8045CA44: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8045CA48: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8045CA4C: nop

    // 0x8045CA50: sw          $t3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r11;
    // 0x8045CA54: lwc1        $f8, 0x6C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x8045CA58: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8045CA5C: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8045CA60: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8045CA64: nop

    // 0x8045CA68: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x8045CA6C: lwc1        $f16, 0x70($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8045CA70: lwc1        $f4, 0x28($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8045CA74: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8045CA78: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8045CA7C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8045CA80: nop

    // 0x8045CA84: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8045CA88: lw          $t7, 0x174($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X174);
    // 0x8045CA8C: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8045CA90: lh          $t2, 0xE($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XE);
    // 0x8045CA94: lw          $t1, 0x70($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X70);
    // 0x8045CA98: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8045CA9C: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8045CAA0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8045CAA4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8045CAA8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8045CAAC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8045CAB0: bne         $at, $zero, L_8045CBB0
    if (ctx->r1 != 0) {
        // 0x8045CAB4: sw          $t5, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r13;
            goto L_8045CBB0;
    }
    // 0x8045CAB4: sw          $t5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r13;
    // 0x8045CAB8: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
L_8045CABC:
    // 0x8045CABC: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8045CAC0: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045CAC4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8045CAC8: mul.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8045CACC: addiu       $t6, $s0, 0xC
    ctx->r14 = ADD32(ctx->r16, 0XC);
    // 0x8045CAD0: addiu       $t8, $s0, 0x14
    ctx->r24 = ADD32(ctx->r16, 0X14);
    // 0x8045CAD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8045CAD8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8045CADC: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8045CAE0: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    // 0x8045CAE4: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8045CAE8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8045CAEC: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x8045CAF0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8045CAF4: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8045CAF8: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8045CAFC: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8045CB00: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8045CB04: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x8045CB08: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8045CB0C: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8045CB10: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8045CB14: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8045CB18: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8045CB1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8045CB20: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8045CB24: jal         0x8045C760
    // 0x8045CB28: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    func_8045C760(rdram, ctx);
        goto after_0;
    // 0x8045CB28: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8045CB2C: andi        $t0, $v0, 0x8
    ctx->r8 = ctx->r2 & 0X8;
    // 0x8045CB30: beql        $t0, $zero, L_8045CBA8
    if (ctx->r8 == 0) {
        // 0x8045CB34: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8045CBA8;
    }
    goto skip_0;
    // 0x8045CB34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8045CB38: jal         0x80065954
    // 0x8045CB3C: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8045CB3C: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    after_1:
    // 0x8045CB40: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8045CB44: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8045CB48: bc1fl       L_8045CB70
    if (!c1cs) {
        // 0x8045CB4C: c.eq.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
            goto L_8045CB70;
    }
    goto skip_1;
    // 0x8045CB4C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    skip_1:
    // 0x8045CB50: jal         0x80065954
    // 0x8045CB54: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8045CB54: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x8045CB58: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8045CB5C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8045CB60: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x8045CB64: b           L_8045CBA4
    // 0x8045CB68: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
        goto L_8045CBA4;
    // 0x8045CB68: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x8045CB6C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
L_8045CB70:
    // 0x8045CB70: nop

    // 0x8045CB74: bc1fl       L_8045CBA8
    if (!c1cs) {
        // 0x8045CB78: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8045CBA8;
    }
    goto skip_2;
    // 0x8045CB78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8045CB7C: jal         0x80065954
    // 0x8045CB80: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8045CB80: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    after_3:
    // 0x8045CB84: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x8045CB88: nop

    // 0x8045CB8C: bc1fl       L_8045CBA8
    if (!c1cs) {
        // 0x8045CB90: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8045CBA8;
    }
    goto skip_3;
    // 0x8045CB90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x8045CB94: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8045CB98: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8045CB9C: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x8045CBA0: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
L_8045CBA4:
    // 0x8045CBA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8045CBA8:
    // 0x8045CBA8: bne         $s1, $s6, L_8045CABC
    if (ctx->r17 != ctx->r22) {
        // 0x8045CBAC: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8045CABC;
    }
    // 0x8045CBAC: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_8045CBB0:
    // 0x8045CBB0: beq         $s5, $zero, L_8045CCAC
    if (ctx->r21 == 0) {
        // 0x8045CBB4: lw          $a0, 0xD0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XD0);
            goto L_8045CCAC;
    }
    // 0x8045CBB4: lw          $a0, 0xD0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD0);
    // 0x8045CBB8: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8045CBBC: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8045CBC0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8045CBC4: jal         0x8045C8E4
    // 0x8045CBC8: addiu       $s3, $a0, 0x6C
    ctx->r19 = ADD32(ctx->r4, 0X6C);
    func_8045C8E4(rdram, ctx);
        goto after_4;
    // 0x8045CBC8: addiu       $s3, $a0, 0x6C
    ctx->r19 = ADD32(ctx->r4, 0X6C);
    after_4:
    // 0x8045CBCC: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8045CBD0: sw          $s5, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r21;
    // 0x8045CBD4: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8045CBD8: sw          $s4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->r20;
    // 0x8045CBDC: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8045CBE0: jal         0x80048114
    // 0x8045CBE4: lw          $a0, 0xD0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD0);
    func_80048114(rdram, ctx);
        goto after_5;
    // 0x8045CBE4: lw          $a0, 0xD0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD0);
    after_5:
    // 0x8045CBE8: jal         0x8005FBC0
    // 0x8045CBEC: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    func_8005FBC0(rdram, ctx);
        goto after_6;
    // 0x8045CBEC: lw          $a0, 0xD4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD4);
    after_6:
    // 0x8045CBF0: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8045CBF4: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045CBF8: lwc1        $f18, 0xC($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8045CBFC: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8045CC00: lw          $t2, 0xD4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD4);
    // 0x8045CC04: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8045CC08: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8045CC0C: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8045CC10: lw          $t3, 0x174($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X174);
    // 0x8045CC14: lw          $t5, 0x18($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X18);
    // 0x8045CC18: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8045CC1C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8045CC20: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8045CC24: addiu       $t4, $t5, -0x2
    ctx->r12 = ADD32(ctx->r13, -0X2);
    // 0x8045CC28: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8045CC2C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8045CC30: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045CC34: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8045CC38: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8045CC3C: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8045CC40: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8045CC44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8045CC48: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045CC4C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8045CC50: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8045CC54: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8045CC58: sub.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8045CC5C: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x8045CC60: swc1        $f6, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f6.u32l;
    // 0x8045CC64: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8045CC68: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8045CC6C: swc1        $f4, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f4.u32l;
    // 0x8045CC70: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8045CC74: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8045CC78: lwc1        $f18, 0x8C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8C);
    // 0x8045CC7C: lwc1        $f16, 0x8C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8C);
    // 0x8045CC80: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8045CC84: swc1        $f10, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f10.u32l;
    // 0x8045CC88: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8045CC8C: sw          $zero, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = 0;
    // 0x8045CC90: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x8045CC94: lw          $v1, 0x1F4($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X1F4);
    // 0x8045CC98: lw          $t5, 0x34($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X34);
    // 0x8045CC9C: ori         $t4, $t5, 0x700
    ctx->r12 = ctx->r13 | 0X700;
    // 0x8045CCA0: sw          $t4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r12;
    // 0x8045CCA4: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8045CCA8: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
L_8045CCAC:
    // 0x8045CCAC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8045CCB0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8045CCB4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8045CCB8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8045CCBC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8045CCC0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8045CCC4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8045CCC8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8045CCCC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8045CCD0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8045CCD4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8045CCD8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8045CCDC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8045CCE0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8045CCE4: jr          $ra
    // 0x8045CCE8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8045CCE8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800384E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800384E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800384E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800384EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800384F0: lbu         $t6, 0x1F8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1F8);
    // 0x800384F4: beq         $t6, $zero, L_8003850C
    if (ctx->r14 == 0) {
        // 0x800384F8: nop
    
            goto L_8003850C;
    }
    // 0x800384F8: nop

    // 0x800384FC: jal         0x80022FE4
    // 0x80038500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022FE4(rdram, ctx);
        goto after_0;
    // 0x80038500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038504: b           L_80038540
    // 0x80038508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80038540;
    // 0x80038508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8003850C:
    // 0x8003850C: jal         0x800238A8
    // 0x80038510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800238A8(rdram, ctx);
        goto after_1;
    // 0x80038510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80038514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038518: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003851C: lwc1        $f4, 0x130($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X130);
    // 0x80038520: lwc1        $f6, 0xE8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x80038524: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038528: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8003852C: nop

    // 0x80038530: bc1f        L_80038540
    if (!c1cs) {
        // 0x80038534: nop
    
            goto L_80038540;
    }
    // 0x80038534: nop

    // 0x80038538: lwc1        $f8, 0x134($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X134);
    // 0x8003853C: swc1        $f8, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f8.u32l;
L_80038540:
    // 0x80038540: jal         0x80023EA0
    // 0x80038544: nop

    func_80023EA0(rdram, ctx);
        goto after_2;
    // 0x80038544: nop

    after_2:
    // 0x80038548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003854C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038550: jr          $ra
    // 0x80038554: nop

    return;
    // 0x80038554: nop

;}
RECOMP_FUNC void func_80798A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798A34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80798A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798A3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80798A40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80798A44: jal         0x80047090
    // 0x80798A48: addiu       $a0, $zero, 0x4026
    ctx->r4 = ADD32(0, 0X4026);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80798A48: addiu       $a0, $zero, 0x4026
    ctx->r4 = ADD32(0, 0X4026);
    after_0:
    // 0x80798A4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80798A50: lui         $at, 0x4026
    ctx->r1 = S32(0X4026 << 16);
    // 0x80798A54: ori         $at, $at, 0x1C00
    ctx->r1 = ctx->r1 | 0X1C00;
    // 0x80798A58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80798A5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80798A60: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80798A64: jal         0x8004613C
    // 0x80798A68: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80798A68: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80798A6C: beq         $v0, $zero, L_80798A98
    if (ctx->r2 == 0) {
        // 0x80798A70: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80798A98;
    }
    // 0x80798A70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80798A74: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x80798A78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80798A7C: sw          $t6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r14;
    // 0x80798A80: jal         0x80047F9C
    // 0x80798A84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80798A84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80798A88: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80798A8C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80798A90: jal         0x80065490
    // 0x80798A94: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80798A94: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    after_3:
L_80798A98:
    // 0x80798A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80798AA0: jr          $ra
    // 0x80798AA4: nop

    return;
    // 0x80798AA4: nop

    // 0x80798AA8: nop

    // 0x80798AAC: nop

;}
RECOMP_FUNC void func_80036838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036838: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003683C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80036840: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80036844: jal         0x80021958
    // 0x80036848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80036848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003684C: bne         $v0, $zero, L_8003685C
    if (ctx->r2 != 0) {
        // 0x80036850: nop
    
            goto L_8003685C;
    }
    // 0x80036850: nop

    // 0x80036854: b           L_800368EC
    // 0x80036858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800368EC;
    // 0x80036858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003685C:
    // 0x8003685C: jal         0x800415FC
    // 0x80036860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80036860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80036864: beq         $v0, $zero, L_80036874
    if (ctx->r2 == 0) {
        // 0x80036868: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80036874;
    }
    // 0x80036868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003686C: b           L_800368EC
    // 0x80036870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800368EC;
    // 0x80036870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036874:
    // 0x80036874: jal         0x800351BC
    // 0x80036878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800351BC(rdram, ctx);
        goto after_2;
    // 0x80036878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8003687C: bnel        $v0, $zero, L_80036890
    if (ctx->r2 != 0) {
        // 0x80036880: lw          $t6, 0x1F4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1F4);
            goto L_80036890;
    }
    goto skip_0;
    // 0x80036880: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80036884: b           L_800368EC
    // 0x80036888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800368EC;
    // 0x80036888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003688C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
L_80036890:
    // 0x80036890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036894: lw          $t7, 0x78($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X78);
    // 0x80036898: beq         $t7, $zero, L_800368EC
    if (ctx->r15 == 0) {
        // 0x8003689C: nop
    
            goto L_800368EC;
    }
    // 0x8003689C: nop

    // 0x800368A0: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x800368A4: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x800368A8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x800368AC: bne         $t8, $at, L_800368D8
    if (ctx->r24 != ctx->r1) {
        // 0x800368B0: nop
    
            goto L_800368D8;
    }
    // 0x800368B0: nop

    // 0x800368B4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800368B8: jal         0x800653D8
    // 0x800368BC: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x800368BC: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    after_3:
    // 0x800368C0: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x800368C4: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x800368C8: addiu       $t0, $t9, 0x6
    ctx->r8 = ADD32(ctx->r25, 0X6);
    // 0x800368CC: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x800368D0: b           L_800368D8
    // 0x800368D4: sw          $t0, 0x140($t1)
    MEM_W(0X140, ctx->r9) = ctx->r8;
        goto L_800368D8;
    // 0x800368D4: sw          $t0, 0x140($t1)
    MEM_W(0X140, ctx->r9) = ctx->r8;
L_800368D8:
    // 0x800368D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800368DC: jal         0x8002DBE4
    // 0x800368E0: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_4;
    // 0x800368E0: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x800368E4: b           L_800368EC
    // 0x800368E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800368EC;
    // 0x800368E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800368EC:
    // 0x800368EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800368F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800368F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800368F8: jr          $ra
    // 0x800368FC: nop

    return;
    // 0x800368FC: nop

;}
RECOMP_FUNC void func_800648A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800648A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800648A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800648AC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800648B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800648B4: beq         $a1, $zero, L_800648CC
    if (ctx->r5 == 0) {
        // 0x800648B8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800648CC;
    }
    // 0x800648B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800648BC: jal         0x80064830
    // 0x800648C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80064830(rdram, ctx);
        goto after_0;
    // 0x800648C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800648C4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800648C8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800648CC:
    // 0x800648CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800648D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800648D4: jr          $ra
    // 0x800648D8: nop

    return;
    // 0x800648D8: nop

;}
RECOMP_FUNC void func_8005C060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C060: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8005C064: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005C068: sll         $s6, $a3, 16
    ctx->r22 = S32(ctx->r7 << 16);
    // 0x8005C06C: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8005C070: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8005C074: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8005C078: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005C07C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005C080: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8005C084: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8005C088: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8005C08C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005C090: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005C094: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005C098: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005C09C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005C0A0: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x8005C0A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8005C0A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005C0AC: bgez        $s6, L_8005C0B8
    if (SIGNED(ctx->r22) >= 0) {
        // 0x8005C0B0: addu        $at, $s6, $zero
        ctx->r1 = ADD32(ctx->r22, 0);
            goto L_8005C0B8;
    }
    // 0x8005C0B0: addu        $at, $s6, $zero
    ctx->r1 = ADD32(ctx->r22, 0);
    // 0x8005C0B4: addiu       $at, $s6, 0x1
    ctx->r1 = ADD32(ctx->r22, 0X1);
L_8005C0B8:
    // 0x8005C0B8: sra         $s6, $at, 1
    ctx->r22 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8005C0BC: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8005C0C0: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8005C0C4: sll         $a1, $s6, 4
    ctx->r5 = S32(ctx->r22 << 4);
    // 0x8005C0C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8005C0CC: jal         0x800657CC
    // 0x8005C0D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_0;
    // 0x8005C0D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005C0D4: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x8005C0D8: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x8005C0DC: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x8005C0E0: slti        $at, $a2, 0x1000
    ctx->r1 = SIGNED(ctx->r6) < 0X1000 ? 1 : 0;
    // 0x8005C0E4: beq         $at, $zero, L_8005C140
    if (ctx->r1 == 0) {
        // 0x8005C0E8: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8005C140;
    }
    // 0x8005C0E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8005C0EC: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
    // 0x8005C0F0: lw          $s4, 0xF8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XF8);
L_8005C0F4:
    // 0x8005C0F4: addu        $t7, $a2, $fp
    ctx->r15 = ADD32(ctx->r6, ctx->r30);
    // 0x8005C0F8: beq         $v0, $zero, L_8005C124
    if (ctx->r2 == 0) {
        // 0x8005C0FC: lbu         $s1, 0x0($t7)
        ctx->r17 = MEM_BU(ctx->r15, 0X0);
            goto L_8005C124;
    }
    // 0x8005C0FC: lbu         $s1, 0x0($t7)
    ctx->r17 = MEM_BU(ctx->r15, 0X0);
    // 0x8005C100: addiu       $a1, $s5, 0x7
    ctx->r5 = ADD32(ctx->r21, 0X7);
    // 0x8005C104: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x8005C108: sll         $a3, $s6, 16
    ctx->r7 = S32(ctx->r22 << 16);
    // 0x8005C10C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005C110: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8005C114: addu        $a0, $s7, $s2
    ctx->r4 = ADD32(ctx->r23, ctx->r18);
    // 0x8005C118: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8005C11C: jal         0x8005BF50
    // 0x8005C120: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    func_8005BF50(rdram, ctx);
        goto after_1;
    // 0x8005C120: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_1:
L_8005C124:
    // 0x8005C124: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x8005C128: addu        $s2, $s2, $s1
    ctx->r18 = ADD32(ctx->r18, ctx->r17);
    // 0x8005C12C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005C130: slti        $at, $a2, 0x1000
    ctx->r1 = SIGNED(ctx->r6) < 0X1000 ? 1 : 0;
    // 0x8005C134: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8005C138: bne         $at, $zero, L_8005C0F4
    if (ctx->r1 != 0) {
        // 0x8005C13C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8005C0F4;
    }
    // 0x8005C13C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8005C140:
    // 0x8005C140: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8005C144: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8005C148: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005C14C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005C150: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005C154: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005C158: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005C15C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005C160: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005C164: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C168: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8005C16C: jr          $ra
    // 0x8005C170: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8005C170: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_807AEA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AEA24: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807AEA28: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807AEA2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807AEA30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807AEA34: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807AEA38: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807AEA3C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807AEA40: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AEA44: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807AEA48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807AEA4C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807AEA50: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(859, 0X2644) << 16);
    // 0x807AEA54: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AEA58: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807AEA5C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807AEA60: lw          $t1, -0x135C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(859, 0X2644));
    // 0x807AEA64: jr          $ra
    // 0x807AEA68: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807AEA68: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80676C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676C68: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80676C6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80676C70: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80676C74: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80676C78: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80676C7C: nop

    // 0x80676C80: bc1fl       L_80676C90
    if (!c1cs) {
        // 0x80676C84: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80676C90;
    }
    goto skip_0;
    // 0x80676C84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80676C88: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80676C8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80676C90:
    // 0x80676C90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80676C94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80676C98: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80676C9C: nop

    // 0x80676CA0: bc1f        L_80676CAC
    if (!c1cs) {
        // 0x80676CA4: nop
    
            goto L_80676CAC;
    }
    // 0x80676CA4: nop

    // 0x80676CA8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80676CAC:
    // 0x80676CAC: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80676CB0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80676CB4: lwc1        $f8, 0x10C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x80676CB8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80676CBC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80676CC0: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80676CC4: jr          $ra
    // 0x80676CC8: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80676CC8: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8007C540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007C544: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C548: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C54C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007C550: addiu       $a1, $a1, -0x2548
    ctx->r5 = ADD32(ctx->r5, -0X2548);
    // 0x8007C554: addiu       $a0, $a0, -0x2560
    ctx->r4 = ADD32(ctx->r4, -0X2560);
    // 0x8007C558: jal         0x8008AE20
    // 0x8007C55C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C55C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007C560: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007C564: addiu       $a1, $a1, -0x2560
    ctx->r5 = ADD32(ctx->r5, -0X2560);
    // 0x8007C568: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8007C56C: jal         0x80089D70
    // 0x8007C570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007C570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8007C574: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8007C578: addiu       $t7, $t7, 0x2AA0
    ctx->r15 = ADD32(ctx->r15, 0X2AA0);
    // 0x8007C57C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C580: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007C584: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8007C588: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x8007C58C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007C590: addiu       $a2, $a2, -0x2140
    ctx->r6 = ADD32(ctx->r6, -0X2140);
    // 0x8007C594: addiu       $a1, $a1, -0x2540
    ctx->r5 = ADD32(ctx->r5, -0X2540);
    // 0x8007C598: addiu       $a0, $a0, -0x2140
    ctx->r4 = ADD32(ctx->r4, -0X2140);
    // 0x8007C59C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8007C5A0: jal         0x80081910
    // 0x8007C5A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_2;
    // 0x8007C5A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8007C5A8: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8007C5AC: addiu       $t9, $t9, -0x2140
    ctx->r25 = ADD32(ctx->r25, -0X2140);
    // 0x8007C5B0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C5B4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007C5B8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8007C5BC: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8007C5C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8007C5C4: addiu       $a2, $a2, 0x1F8
    ctx->r6 = ADD32(ctx->r6, 0X1F8);
    // 0x8007C5C8: addiu       $a1, $a1, -0x2560
    ctx->r5 = ADD32(ctx->r5, -0X2560);
    // 0x8007C5CC: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    // 0x8007C5D0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007C5D4: jal         0x80075020
    // 0x8007C5D8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80075020(rdram, ctx);
        goto after_3;
    // 0x8007C5D8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_3:
    // 0x8007C5DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C5E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007C5E4: jr          $ra
    // 0x8007C5E8: nop

    return;
    // 0x8007C5E8: nop

;}
RECOMP_FUNC void func_804603FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804603FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460404: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x80460408: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8046040C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80460410: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(119, 0X430) << 16);
    // 0x80460414: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80460418: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x8046041C: addiu       $t8, $t8, 0x520
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(119, 0X430));
    // 0x80460420: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80460424: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80460428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80460430: jal         0x80460470
    // 0x80460434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80460470(rdram, ctx);
        goto after_0;
    // 0x80460434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80460438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046043C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80460440: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80460444: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80460448: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8046044C: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x80460450: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(119, 0X10C) << 16);
    // 0x80460454: addiu       $t1, $t1, 0x1FC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(119, 0X10C));
    // 0x80460458: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    // 0x8046045C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80460460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460468: jr          $ra
    // 0x8046046C: nop

    return;
    // 0x8046046C: nop

;}
RECOMP_FUNC void func_806F9A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F9A2C: jal         0x80047090
    // 0x806F9A30: addiu       $a0, $zero, 0x4301
    ctx->r4 = ADD32(0, 0X4301);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806F9A30: addiu       $a0, $zero, 0x4301
    ctx->r4 = ADD32(0, 0X4301);
    after_0:
    // 0x806F9A34: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806F9A38: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x806F9A3C: ori         $at, $at, 0x1800
    ctx->r1 = ctx->r1 | 0X1800;
    // 0x806F9A40: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x806F9A44: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x806F9A48: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x806F9A4C: jal         0x8004613C
    // 0x806F9A50: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806F9A50: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_1:
    // 0x806F9A54: bne         $v0, $zero, L_806F9A64
    if (ctx->r2 != 0) {
        // 0x806F9A58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806F9A64;
    }
    // 0x806F9A58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806F9A5C: b           L_806F9A68
    // 0x806F9A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F9A68;
    // 0x806F9A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F9A64:
    // 0x806F9A64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_806F9A68:
    // 0x806F9A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9A70: jr          $ra
    // 0x806F9A74: nop

    return;
    // 0x806F9A74: nop

;}
RECOMP_FUNC void func_80064AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064AB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80064AB4: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x80064AB8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80064ABC: jalr        $t9
    // 0x80064AC0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80064AC0: nop

    after_0:
    // 0x80064AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064ACC: jr          $ra
    // 0x80064AD0: nop

    return;
    // 0x80064AD0: nop

;}
RECOMP_FUNC void func_806B26DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B26DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B26E0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B26E4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B26E8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B26EC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B26F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B26F4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B26F8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B26FC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2700: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2704: jr          $ra
    // 0x806B2708: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2708: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80465AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465AE8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80465AEC: beq         $v0, $zero, L_80465AFC
    if (ctx->r2 == 0) {
        // 0x80465AF0: nop
    
            goto L_80465AFC;
    }
    // 0x80465AF0: nop

    // 0x80465AF4: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80465AF8: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
L_80465AFC:
    // 0x80465AFC: jr          $ra
    // 0x80465B00: nop

    return;
    // 0x80465B00: nop

;}
RECOMP_FUNC void func_8067B9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B9A0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8067B9A4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8067B9A8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8067B9AC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8067B9B0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8067B9B4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8067B9B8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8067B9BC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8067B9C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8067B9C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8067B9C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8067B9CC: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8067B9D0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8067B9D4: addiu       $s4, $sp, 0xA4
    ctx->r20 = ADD32(ctx->r29, 0XA4);
    // 0x8067B9D8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8067B9DC: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x8067B9E0: lw          $fp, 0x1F4($a1)
    ctx->r30 = MEM_W(ctx->r5, 0X1F4);
    // 0x8067B9E4: lw          $t8, 0x168($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X168);
    // 0x8067B9E8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8067B9EC: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x8067B9F0: lw          $s0, 0x88($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X88);
    // 0x8067B9F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8067B9F8: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x8067B9FC: sw          $t0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r8;
    // 0x8067BA00: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x8067BA04: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8067BA08: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    // 0x8067BA0C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8067BA10: jal         0x8067B7D8
    // 0x8067BA14: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    func_8067B7D8(rdram, ctx);
        goto after_0;
    // 0x8067BA14: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    after_0:
    // 0x8067BA18: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8067BA1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8067BA20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8067BA24: jal         0x8007711C
    // 0x8067BA28: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x8067BA28: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8067BA2C: lui         $s1, 0x8068
    ctx->r17 = S32(RELOC_HI16(541, 0X3A08) << 16);
    // 0x8067BA30: lui         $s6, 0x8068
    ctx->r22 = S32(RELOC_HI16(541, 0X3180) << 16);
    // 0x8067BA34: addiu       $s6, $s6, -0x31D0
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(541, 0X3180));
    // 0x8067BA38: addiu       $s1, $s1, -0x2948
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(541, 0X3A08));
    // 0x8067BA3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8067BA40: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8067BA44: addiu       $s7, $zero, 0x7
    ctx->r23 = ADD32(0, 0X7);
    // 0x8067BA48: addiu       $s5, $sp, 0x5C
    ctx->r21 = ADD32(ctx->r29, 0X5C);
L_8067BA4C:
    // 0x8067BA4C: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x8067BA50: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8067BA54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8067BA58: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8067BA5C: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x8067BA60: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8067BA64: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8067BA68: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x8067BA6C: jal         0x8067B8C4
    // 0x8067BA70: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8067B8C4(rdram, ctx);
        goto after_2;
    // 0x8067BA70: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8067BA74: lw          $t7, 0x14C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X14C);
    // 0x8067BA78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8067BA7C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8067BA80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067BA84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8067BA88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8067BA8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8067BA90: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8067BA94: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8067BA98: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8067BA9C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8067BAA0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8067BAA4: jal         0x8067B66C
    // 0x8067BAA8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_8067B66C(rdram, ctx);
        goto after_3;
    // 0x8067BAA8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_3:
    // 0x8067BAAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8067BAB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8067BAB4: bne         $s0, $s7, L_8067BA4C
    if (ctx->r16 != ctx->r23) {
        // 0x8067BAB8: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_8067BA4C;
    }
    // 0x8067BAB8: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8067BABC: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x8067BAC0: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8067BAC4: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8067BAC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8067BACC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8067BAD0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8067BAD4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8067BAD8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8067BADC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8067BAE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8067BAE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8067BAE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8067BAEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8067BAF0: jr          $ra
    // 0x8067BAF4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8067BAF4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_806B12FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B12FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B1300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B1304: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806B1308: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806B130C: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806B1310: lw          $a1, 0x108($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X108);
    // 0x806B1314: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806B1318: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1784) << 16);
    // 0x806B131C: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x806B1320: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806B1324: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806B1328: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806B132C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806B1330: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B1334: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806B1338: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(598, 0XE50) << 16);
    // 0x806B133C: lui         $t0, 0x806B
    ctx->r8 = S32(RELOC_HI16(598, 0X9A4) << 16);
    // 0x806B1340: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x806B1344: addiu       $t9, $t9, 0xDE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(598, 0XE50));
    // 0x806B1348: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x806B134C: addiu       $t0, $t0, 0x934
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(598, 0X9A4));
    // 0x806B1350: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x806B1354: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x806B1358: lwc1        $f6, 0x1714($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1784));
    // 0x806B135C: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806B1360: sb          $t7, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r15;
    // 0x806B1364: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806B1368: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806B136C: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
    // 0x806B1370: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806B1374: swc1        $f2, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f2.u32l;
    // 0x806B1378: swc1        $f0, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f0.u32l;
    // 0x806B137C: swc1        $f0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f0.u32l;
    // 0x806B1380: swc1        $f0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->f0.u32l;
    // 0x806B1384: lwc1        $f16, 0xC4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806B1388: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806B138C: swc1        $f16, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f16.u32l;
    // 0x806B1390: lwc1        $f10, 0xC4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x806B1394: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x806B1398: nop

    // 0x806B139C: bc1fl       L_806B13C8
    if (!c1cs) {
        // 0x806B13A0: addiu       $v0, $a1, 0xC4
        ctx->r2 = ADD32(ctx->r5, 0XC4);
            goto L_806B13C8;
    }
    goto skip_0;
    // 0x806B13A0: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    skip_0:
    // 0x806B13A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B13A8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B13AC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806B13B0: nop

    // 0x806B13B4: bc1fl       L_806B13C8
    if (!c1cs) {
        // 0x806B13B8: addiu       $v0, $a1, 0xC4
        ctx->r2 = ADD32(ctx->r5, 0XC4);
            goto L_806B13C8;
    }
    goto skip_1;
    // 0x806B13B8: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    skip_1:
    // 0x806B13BC: b           L_806B13FC
    // 0x806B13C0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_806B13FC;
    // 0x806B13C0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B13C4: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
L_806B13C8:
    // 0x806B13C8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B13CC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806B13D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806B13D4: nop

    // 0x806B13D8: bc1fl       L_806B1400
    if (!c1cs) {
        // 0x806B13DC: lwc1        $f4, 0xC8($a2)
        ctx->f4.u32l = MEM_W(ctx->r6, 0XC8);
            goto L_806B1400;
    }
    goto skip_2;
    // 0x806B13DC: lwc1        $f4, 0xC8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC8);
    skip_2:
    // 0x806B13E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806B13E4: nop

    // 0x806B13E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806B13EC: nop

    // 0x806B13F0: bc1fl       L_806B1400
    if (!c1cs) {
        // 0x806B13F4: lwc1        $f4, 0xC8($a2)
        ctx->f4.u32l = MEM_W(ctx->r6, 0XC8);
            goto L_806B1400;
    }
    goto skip_3;
    // 0x806B13F4: lwc1        $f4, 0xC8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC8);
    skip_3:
    // 0x806B13F8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_806B13FC:
    // 0x806B13FC: lwc1        $f4, 0xC8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC8);
L_806B1400:
    // 0x806B1400: sb          $t8, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r24;
    // 0x806B1404: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
    // 0x806B1408: sw          $zero, 0x130($a1)
    MEM_W(0X130, ctx->r5) = 0;
    // 0x806B140C: swc1        $f4, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->f4.u32l;
    // 0x806B1410: jal         0x806B15A4
    // 0x806B1414: sw          $t0, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->r8;
    func_806B15A4(rdram, ctx);
        goto after_0;
    // 0x806B1414: sw          $t0, 0x130($a2)
    MEM_W(0X130, ctx->r6) = ctx->r8;
    after_0:
    // 0x806B1418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B141C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B1420: jr          $ra
    // 0x806B1424: nop

    return;
    // 0x806B1424: nop

;}
RECOMP_FUNC void func_8057C0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C0BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057C0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C0C4: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8057C0C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8057C0CC: jal         0x8057BB68
    // 0x8057C0D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C0D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8057C0D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8057C0D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8057C0DC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8057C0E0: beq         $v0, $zero, L_8057C130
    if (ctx->r2 == 0) {
        // 0x8057C0E4: nop
    
            goto L_8057C130;
    }
    // 0x8057C0E4: nop

    // 0x8057C0E8: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8057C0EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8057C0F0: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057C0F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8057C0F8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8057C0FC: nop

    // 0x8057C100: bc1f        L_8057C130
    if (!c1cs) {
        // 0x8057C104: nop
    
            goto L_8057C130;
    }
    // 0x8057C104: nop

    // 0x8057C108: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8057C10C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8057C110: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8057C114: jal         0x8057C6B0
    // 0x8057C118: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    func_8057C6B0(rdram, ctx);
        goto after_1;
    // 0x8057C118: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x8057C11C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8057C120: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057C124: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8057C128: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8057C12C: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
L_8057C130:
    // 0x8057C130: jal         0x8057BD84
    // 0x8057C134: nop

    func_8057BD84(rdram, ctx);
        goto after_2;
    // 0x8057C134: nop

    after_2:
    // 0x8057C138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C13C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057C140: jr          $ra
    // 0x8057C144: nop

    return;
    // 0x8057C144: nop

;}
RECOMP_FUNC void func_805DAFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAFBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DAFC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805DAFC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805DAFC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805DAFCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DAFD0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805DAFD4: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x805DAFD8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x805DAFDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x805DAFE0: lw          $s1, 0x1F4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X1F4);
    // 0x805DAFE4: lw          $t6, 0x70($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X70);
    // 0x805DAFE8: blez        $t6, L_805DB038
    if (SIGNED(ctx->r14) <= 0) {
        // 0x805DAFEC: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_805DB038;
    }
    // 0x805DAFEC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
L_805DAFF0:
    // 0x805DAFF0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x805DAFF4: jal         0x80067930
    // 0x805DAFF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x805DAFF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x805DAFFC: bne         $v0, $zero, L_805DB01C
    if (ctx->r2 != 0) {
        // 0x805DB000: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_805DB01C;
    }
    // 0x805DB000: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x805DB004: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x805DB008: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x805DB00C: jal         0x80067838
    // 0x805DB010: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80067838(rdram, ctx);
        goto after_1;
    // 0x805DB010: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x805DB014: b           L_805DB03C
    // 0x805DB018: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_805DB03C;
    // 0x805DB018: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805DB01C:
    // 0x805DB01C: lw          $t7, 0x70($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X70);
    // 0x805DB020: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x805DB024: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x805DB028: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x805DB02C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x805DB030: bnel        $at, $zero, L_805DAFF0
    if (ctx->r1 != 0) {
        // 0x805DB034: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_805DAFF0;
    }
    goto skip_0;
    // 0x805DB034: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    skip_0:
L_805DB038:
    // 0x805DB038: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_805DB03C:
    // 0x805DB03C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805DB040: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DB044: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805DB048: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805DB04C: jr          $ra
    // 0x805DB050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805DB050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002BF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BF0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BF14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002BF18: lw          $a2, 0x108($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X108);
    // 0x8002BF1C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002BF20: beq         $a2, $zero, L_8002BF48
    if (ctx->r6 == 0) {
        // 0x8002BF24: nop
    
            goto L_8002BF48;
    }
    // 0x8002BF24: nop

    // 0x8002BF28: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8002BF2C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002BF30: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8002BF34: lw          $v0, 0x78($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X78);
    // 0x8002BF38: beq         $v0, $zero, L_8002BF48
    if (ctx->r2 == 0) {
        // 0x8002BF3C: nop
    
            goto L_8002BF48;
    }
    // 0x8002BF3C: nop

    // 0x8002BF40: jalr        $v0
    // 0x8002BF44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002BF44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_8002BF48:
    // 0x8002BF48: jal         0x8003F03C
    // 0x8002BF4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8003F03C(rdram, ctx);
        goto after_1;
    // 0x8002BF4C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002BF50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BF54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BF58: jr          $ra
    // 0x8002BF5C: nop

    return;
    // 0x8002BF5C: nop

;}
RECOMP_FUNC void func_8005D91C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D91C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D920: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D924: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D928: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8005D92C: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8005D930: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D934: addiu       $s1, $s1, 0x63D0
    ctx->r17 = ADD32(ctx->r17, 0X63D0);
    // 0x8005D938: addiu       $s0, $s0, 0x6344
    ctx->r16 = ADD32(ctx->r16, 0X6344);
    // 0x8005D93C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_8005D940:
    // 0x8005D940: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8005D944: jal         0x800657CC
    // 0x8005D948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_0;
    // 0x8005D948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005D94C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8005D950: bnel        $s0, $s1, L_8005D940
    if (ctx->r16 != ctx->r17) {
        // 0x8005D954: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_8005D940;
    }
    goto skip_0;
    // 0x8005D954: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8005D958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D95C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D960: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D964: jr          $ra
    // 0x8005D968: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005D968: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804386FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804386FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80438700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438704: jal         0x804386DC
    // 0x80438708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804386DC(rdram, ctx);
        goto after_0;
    // 0x80438708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043870C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80438710: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(77, 0X1E54) << 16);
    // 0x80438714: addiu       $t6, $t6, -0x790C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(77, 0X1E54));
    // 0x80438718: sw          $t6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r14;
    // 0x8043871C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80438724: jr          $ra
    // 0x80438728: nop

    return;
    // 0x80438728: nop

    // 0x8043872C: nop

;}
RECOMP_FUNC void func_80456678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456678: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8045667C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80456680: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80456684: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80456688: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045668C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80456690: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80456694: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80456698: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045669C: jal         0x8044EFA0
    // 0x804566A0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804566A0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x804566A4: jal         0x804449C0
    // 0x804566A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x804566A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804566AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804566B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804566B4: jal         0x80450490
    // 0x804566B8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x804566B8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x804566BC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x804566C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804566C4: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x804566C8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804566CC: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x804566D0: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D70) << 16);
    // 0x804566D4: lw          $t9, -0x7EB0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D70));
    // 0x804566D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804566DC: jalr        $t9
    // 0x804566E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804566E0: nop

    after_3:
    // 0x804566E4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x804566E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804566EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804566F0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x804566F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804566F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x804566FC: jal         0x80455D88
    // 0x80456700: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80455D88(rdram, ctx);
        goto after_4;
    // 0x80456700: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x80456704: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80456708: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8045670C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456710: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80456714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456718: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8045671C: jal         0x80455D88
    // 0x80456720: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    func_80455D88(rdram, ctx);
        goto after_5;
    // 0x80456720: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x80456724: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80456728: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8045672C: lw          $t2, 0xFB8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XFB8);
    // 0x80456730: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80456734: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x80456738: bnel        $t4, $zero, L_80456864
    if (ctx->r12 != 0) {
        // 0x8045673C: lbu         $v0, 0xF5D($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
            goto L_80456864;
    }
    goto skip_0;
    // 0x8045673C: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    skip_0:
    // 0x80456740: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80456744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456748: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x8045674C: bne         $v0, $zero, L_8045678C
    if (ctx->r2 != 0) {
        // 0x80456750: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8045678C;
    }
    // 0x80456750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456754: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141B8) << 16);
    // 0x80456758: lwc1        $f0, -0x7A68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141B8));
    // 0x8045675C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80456764: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141BC) << 16);
    // 0x80456768: lwc1        $f10, -0x7A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141BC));
    // 0x8045676C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80456770: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456774: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456778: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8045677C: jal         0x80444B28
    // 0x80456780: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_6;
    // 0x80456780: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80456784: b           L_8045695C
    // 0x80456788: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x80456788: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8045678C:
    // 0x8045678C: bne         $v0, $at, L_804567D0
    if (ctx->r2 != ctx->r1) {
        // 0x80456790: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804567D0;
    }
    // 0x80456790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456794: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141C0) << 16);
    // 0x80456798: lwc1        $f0, -0x7A60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141C0));
    // 0x8045679C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804567A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804567A4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141C4) << 16);
    // 0x804567A8: lwc1        $f18, -0x7A5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141C4));
    // 0x804567AC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804567B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x804567B4: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x804567B8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804567BC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x804567C0: jal         0x80444B28
    // 0x804567C4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_7;
    // 0x804567C4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x804567C8: b           L_8045695C
    // 0x804567CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x804567CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804567D0:
    // 0x804567D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804567D4: bne         $v0, $at, L_80456818
    if (ctx->r2 != ctx->r1) {
        // 0x804567D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456818;
    }
    // 0x804567D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804567DC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141C8) << 16);
    // 0x804567E0: lwc1        $f0, -0x7A58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141C8));
    // 0x804567E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804567E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804567EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141CC) << 16);
    // 0x804567F0: lwc1        $f6, -0x7A54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141CC));
    // 0x804567F4: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804567F8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x804567FC: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456800: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456804: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80456808: jal         0x80444B28
    // 0x8045680C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_8;
    // 0x8045680C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80456810: b           L_8045695C
    // 0x80456814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x80456814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456818:
    // 0x80456818: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8045681C: bne         $v0, $at, L_80456958
    if (ctx->r2 != ctx->r1) {
        // 0x80456820: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456958;
    }
    // 0x80456820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456824: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141D0) << 16);
    // 0x80456828: lwc1        $f0, -0x7A50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141D0));
    // 0x8045682C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80456830: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80456834: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141D4) << 16);
    // 0x80456838: lwc1        $f10, -0x7A4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141D4));
    // 0x8045683C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456840: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80456844: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456848: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8045684C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80456850: jal         0x80444B28
    // 0x80456854: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_9;
    // 0x80456854: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80456858: b           L_8045695C
    // 0x8045685C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x8045685C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80456860: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
L_80456864:
    // 0x80456864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456868: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x8045686C: bne         $v0, $zero, L_804568A4
    if (ctx->r2 != 0) {
        // 0x80456870: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_804568A4;
    }
    // 0x80456870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456874: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141D8) << 16);
    // 0x80456878: lwc1        $f0, -0x7A48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141D8));
    // 0x8045687C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456880: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80456884: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80456888: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x8045688C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456890: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456894: jal         0x80444B28
    // 0x80456898: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80444B28(rdram, ctx);
        goto after_10;
    // 0x80456898: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x8045689C: b           L_8045695C
    // 0x804568A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x804568A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804568A4:
    // 0x804568A4: bne         $v0, $at, L_804568E0
    if (ctx->r2 != ctx->r1) {
        // 0x804568A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804568E0;
    }
    // 0x804568A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804568AC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141DC) << 16);
    // 0x804568B0: lwc1        $f0, -0x7A44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141DC));
    // 0x804568B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804568B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804568BC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804568C0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x804568C4: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x804568C8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804568CC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804568D0: jal         0x80444B28
    // 0x804568D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_11;
    // 0x804568D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x804568D8: b           L_8045695C
    // 0x804568DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x804568DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804568E0:
    // 0x804568E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804568E4: bne         $v0, $at, L_80456920
    if (ctx->r2 != ctx->r1) {
        // 0x804568E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456920;
    }
    // 0x804568E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804568EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141E0) << 16);
    // 0x804568F0: lwc1        $f0, -0x7A40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141E0));
    // 0x804568F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804568F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804568FC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456900: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80456904: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456908: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8045690C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456910: jal         0x80444B28
    // 0x80456914: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80444B28(rdram, ctx);
        goto after_12;
    // 0x80456914: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80456918: b           L_8045695C
    // 0x8045691C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8045695C;
    // 0x8045691C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456920:
    // 0x80456920: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456924: bne         $v0, $at, L_80456958
    if (ctx->r2 != ctx->r1) {
        // 0x80456928: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456958;
    }
    // 0x80456928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045692C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141E4) << 16);
    // 0x80456930: lwc1        $f0, -0x7A3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141E4));
    // 0x80456934: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456938: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045693C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456940: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80456944: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456948: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8045694C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456950: jal         0x80444B28
    // 0x80456954: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_13;
    // 0x80456954: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
L_80456958:
    // 0x80456958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8045695C:
    // 0x8045695C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80456960: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80456964: jr          $ra
    // 0x80456968: nop

    return;
    // 0x80456968: nop

;}
RECOMP_FUNC void func_80047590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047598: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004759C: lh          $t6, 0x13E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13E);
    // 0x800475A0: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800475A4: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800475A8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800475AC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800475B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800475B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800475B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800475BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800475C0: jal         0x800471D8
    // 0x800475C4: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    func_800471D8(rdram, ctx);
        goto after_0;
    // 0x800475C4: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    after_0:
    // 0x800475C8: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800475CC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800475D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800475D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800475D8: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800475DC: nop

    // 0x800475E0: slt         $v0, $t8, $t0
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800475E4: jr          $ra
    // 0x800475E8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x800475E8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
RECOMP_FUNC void func_805334D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805334D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805334D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805334DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805334E0: jal         0x800692D4
    // 0x805334E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x805334E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805334E8: jal         0x80532CFC
    // 0x805334EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532CFC(rdram, ctx);
        goto after_1;
    // 0x805334EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805334F0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805334F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805334F8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805334FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80533500: nop

    // 0x80533504: bc1fl       L_80533520
    if (!c1cs) {
        // 0x80533508: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80533520;
    }
    goto skip_0;
    // 0x80533508: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_0:
    // 0x8053350C: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80533510: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80533514: b           L_80533520
    // 0x80533518: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80533520;
    // 0x80533518: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8053351C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80533520:
    // 0x80533520: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80533524: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80533528: nop

    // 0x8053352C: bc1fl       L_80533548
    if (!c1cs) {
        // 0x80533530: swc1        $f2, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
            goto L_80533548;
    }
    goto skip_1;
    // 0x80533530: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x80533534: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80533538: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8053353C: b           L_80533548
    // 0x80533540: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_80533548;
    // 0x80533540: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80533544: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
L_80533548:
    // 0x80533548: jal         0x80533170
    // 0x8053354C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533170(rdram, ctx);
        goto after_2;
    // 0x8053354C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80533550: jal         0x8053332C
    // 0x80533554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8053332C(rdram, ctx);
        goto after_3;
    // 0x80533554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80533558: jal         0x80532B50
    // 0x8053355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532B50(rdram, ctx);
        goto after_4;
    // 0x8053355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80533560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80533564: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80533568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8053356C: jr          $ra
    // 0x80533570: nop

    return;
    // 0x80533570: nop

;}
RECOMP_FUNC void func_8005BCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BCB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BCBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BCC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BCC4: jal         0x8005BA30
    // 0x8005BCC8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BCC8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BCCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BCD0: bne         $v0, $at, L_8005BCE0
    if (ctx->r2 != ctx->r1) {
        // 0x8005BCD4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005BCE0;
    }
    // 0x8005BCD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005BCD8: b           L_8005BCF8
    // 0x8005BCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005BCF8;
    // 0x8005BCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BCE0:
    // 0x8005BCE0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8005BCE4: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BCE8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BCEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BCF0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005BCF4: lw          $v0, -0x4BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA4);
L_8005BCF8:
    // 0x8005BCF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BCFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BD00: jr          $ra
    // 0x8005BD04: nop

    return;
    // 0x8005BD04: nop

;}
RECOMP_FUNC void func_804C8D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8D14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C8D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C8D1C: lh          $v0, 0x184($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X184);
    // 0x804C8D20: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804C8D24: addiu       $v1, $a0, 0x188
    ctx->r3 = ADD32(ctx->r4, 0X188);
    // 0x804C8D28: beq         $v0, $zero, L_804C8DAC
    if (ctx->r2 == 0) {
        // 0x804C8D2C: addiu       $a0, $zero, 0x4001
        ctx->r4 = ADD32(0, 0X4001);
            goto L_804C8DAC;
    }
    // 0x804C8D2C: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
L_804C8D30:
    // 0x804C8D30: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x804C8D34: beq         $a1, $zero, L_804C8DA4
    if (ctx->r5 == 0) {
        // 0x804C8D38: nop
    
            goto L_804C8DA4;
    }
    // 0x804C8D38: nop

    // 0x804C8D3C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x804C8D40: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x804C8D44: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x804C8D48: bne         $a0, $t6, L_804C8DA4
    if (ctx->r4 != ctx->r14) {
        // 0x804C8D4C: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_804C8DA4;
    }
    // 0x804C8D4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x804C8D50: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x804C8D54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804C8D58: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x804C8D5C: bne         $at, $zero, L_804C8D80
    if (ctx->r1 != 0) {
        // 0x804C8D60: slti        $at, $v0, 0x123
        ctx->r1 = SIGNED(ctx->r2) < 0X123 ? 1 : 0;
            goto L_804C8D80;
    }
    // 0x804C8D60: slti        $at, $v0, 0x123
    ctx->r1 = SIGNED(ctx->r2) < 0X123 ? 1 : 0;
    // 0x804C8D64: beq         $at, $zero, L_804C8D80
    if (ctx->r1 == 0) {
        // 0x804C8D68: nop
    
            goto L_804C8D80;
    }
    // 0x804C8D68: nop

    // 0x804C8D6C: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
    // 0x804C8D70: bltz        $v0, L_804C8D80
    if (SIGNED(ctx->r2) < 0) {
        // 0x804C8D74: slti        $at, $v0, 0xF1
        ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
            goto L_804C8D80;
    }
    // 0x804C8D74: slti        $at, $v0, 0xF1
    ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x804C8D78: bne         $at, $zero, L_804C8D9C
    if (ctx->r1 != 0) {
        // 0x804C8D7C: nop
    
            goto L_804C8D9C;
    }
    // 0x804C8D7C: nop

L_804C8D80:
    // 0x804C8D80: jal         0x80061170
    // 0x804C8D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80061170(rdram, ctx);
        goto after_0;
    // 0x804C8D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804C8D88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x804C8D8C: jal         0x8002FABC
    // 0x804C8D90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8002FABC(rdram, ctx);
        goto after_1;
    // 0x804C8D90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x804C8D94: b           L_804C8DB0
    // 0x804C8D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C8DB0;
    // 0x804C8D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C8D9C:
    // 0x804C8D9C: b           L_804C8DB0
    // 0x804C8DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804C8DB0;
    // 0x804C8DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C8DA4:
    // 0x804C8DA4: bne         $v0, $zero, L_804C8D30
    if (ctx->r2 != 0) {
        // 0x804C8DA8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_804C8D30;
    }
    // 0x804C8DA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_804C8DAC:
    // 0x804C8DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C8DB0:
    // 0x804C8DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C8DB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C8DB8: jr          $ra
    // 0x804C8DBC: nop

    return;
    // 0x804C8DBC: nop

;}
RECOMP_FUNC void func_80410234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80410234: lw          $t6, 0x1E0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1E0);
    // 0x80410238: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8041023C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80410240: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80410244: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80410248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041024C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80410250: lui         $t2, 0x1F
    ctx->r10 = S32(0X1F << 16);
    // 0x80410254: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80410258: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x8041025C: ori         $t2, $t2, 0x3205
    ctx->r10 = ctx->r10 | 0X3205;
    // 0x80410260: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x80410264: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80410268: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8041026C: ori         $t0, $t0, 0x41C8
    ctx->r8 = ctx->r8 | 0X41C8;
    // 0x80410270: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x80410274: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80410278: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8041027C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80410280: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80410284: nop

    // 0x80410288: bgez        $v1, L_80410298
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8041028C: slti        $at, $v1, 0x100
        ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
            goto L_80410298;
    }
    // 0x8041028C: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80410290: b           L_804102A4
    // 0x80410294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_804102A4;
    // 0x80410294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80410298:
    // 0x80410298: bnel        $at, $zero, L_804102A8
    if (ctx->r1 != 0) {
        // 0x8041029C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_804102A8;
    }
    goto skip_0;
    // 0x8041029C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x804102A0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_804102A4:
    // 0x804102A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_804102A8:
    // 0x804102A8: ori         $t7, $t7, 0x2C80
    ctx->r15 = ctx->r15 | 0X2C80;
    // 0x804102AC: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x804102B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804102B4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x804102B8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x804102BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x804102C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804102C4: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x804102C8: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x804102CC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x804102D0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x804102D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804102D8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x804102DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804102E0: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x804102E4: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x804102E8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x804102EC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x804102F0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804102F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x804102F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804102FC: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x80410300: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x80410304: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80410308: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8041030C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80410310: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410314: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410318: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x8041031C: ori         $t6, $t6, 0xF67B
    ctx->r14 = ctx->r14 | 0XF67B;
    // 0x80410320: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80410324: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80410328: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8041032C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80410330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410334: addiu       $t8, $zero, 0x204
    ctx->r24 = ADD32(0, 0X204);
    // 0x80410338: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8041033C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80410340: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80410344: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80410348: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8041034C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410350: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x80410354: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x80410358: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8041035C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80410360: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80410364: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80410368: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8041036C: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x80410370: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x80410374: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80410378: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8041037C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80410380: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80410384: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410388: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8041038C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80410390: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80410394: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80410398: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8041039C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x804103A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804103A4: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x804103A8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x804103AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804103B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804103B4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x804103B8: jr          $ra
    // 0x804103BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x804103BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8053471C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053471C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80534720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534724: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80534728: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8053472C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80534730: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(348, 0XF90) << 16);
    // 0x80534734: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80534738: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8053473C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80534740: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80534744: lw          $t8, 0x55A0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(348, 0XF90));
    // 0x80534748: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8053474C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80534750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80534754: jal         0x80048490
    // 0x80534758: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80534758: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8053475C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80534760: jal         0x80048378
    // 0x80534764: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80534764: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80534768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8053476C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80534770: jr          $ra
    // 0x80534774: nop

    return;
    // 0x80534774: nop

;}
RECOMP_FUNC void func_806830D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806830D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806830D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806830DC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806830E0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806830E4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806830E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806830EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806830F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806830F4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806830F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806830FC: jr          $ra
    // 0x80683100: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80683100: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80474EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474EE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474EE4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474EE8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474EEC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474EF0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474EF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474EF8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474EFC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474F00: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474F04: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474F08: jr          $ra
    // 0x80474F0C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474F0C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804F3FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F3FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F3FD4: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804F3FD8: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(270, 0XE14) << 16);
    // 0x804F3FDC: addiu       $t8, $t8, 0x4144
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(270, 0XE14));
    // 0x804F3FE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804F3FE4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804F3FE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804F3FEC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804F3FF0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804F3FF4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804F3FF8: beql        $v1, $zero, L_804F4030
    if (ctx->r3 == 0) {
        // 0x804F3FFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804F4030;
    }
    goto skip_0;
    // 0x804F3FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804F4000: jalr        $v1
    // 0x804F4004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804F4004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804F4008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804F400C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804F4010: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804F4014: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804F4018: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804F401C: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804F4020: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804F4024: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804F4028: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804F402C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F4030:
    // 0x804F4030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F4034: jr          $ra
    // 0x804F4038: nop

    return;
    // 0x804F4038: nop

    // 0x804F403C: nop

;}
RECOMP_FUNC void func_806781B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806781B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806781B4: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x806781B8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x806781BC: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x806781C0: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x806781C4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x806781C8: lw          $a3, 0x16C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X16C);
    // 0x806781CC: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x806781D0: lui         $s3, 0x8068
    ctx->r19 = S32(RELOC_HI16(538, 0X1428) << 16);
    // 0x806781D4: lbu         $t8, 0xD($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XD);
    // 0x806781D8: lw          $t6, 0x300($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X300);
    // 0x806781DC: addiu       $s3, $s3, -0x6C68
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(538, 0X1428));
    // 0x806781E0: sb          $t8, 0xC($s3)
    MEM_B(0XC, ctx->r19) = ctx->r24;
    // 0x806781E4: lbu         $t9, 0x11($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X11);
    // 0x806781E8: lui         $s4, 0x8068
    ctx->r20 = S32(RELOC_HI16(538, 0X1438) << 16);
    // 0x806781EC: addiu       $s4, $s4, -0x6C58
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(538, 0X1438));
    // 0x806781F0: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x806781F4: sb          $t9, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r25;
    // 0x806781F8: lbu         $t6, 0xE($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XE);
    // 0x806781FC: addu        $t5, $a2, $t7
    ctx->r13 = ADD32(ctx->r6, ctx->r15);
    // 0x80678200: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80678204: sb          $t6, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r14;
    // 0x80678208: lbu         $t7, 0x12($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X12);
    // 0x8067820C: addiu       $s0, $t5, 0x180
    ctx->r16 = ADD32(ctx->r13, 0X180);
    // 0x80678210: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80678214: sb          $t7, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r15;
    // 0x80678218: lbu         $t8, 0xF($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XF);
    // 0x8067821C: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    // 0x80678220: sb          $t8, 0xE($s3)
    MEM_B(0XE, ctx->r19) = ctx->r24;
    // 0x80678224: lbu         $t9, 0x6($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6);
    // 0x80678228: sb          $t9, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r25;
    // 0x8067822C: lbu         $t6, 0x3($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3);
    // 0x80678230: sb          $t6, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r14;
    // 0x80678234: lbu         $t7, 0x3($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3);
    // 0x80678238: sb          $t7, 0xF($s4)
    MEM_B(0XF, ctx->r20) = ctx->r15;
    // 0x8067823C: lw          $t3, -0x260C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X260C);
    // 0x80678240: lw          $v0, 0xC($t3)
    ctx->r2 = MEM_W(ctx->r11, 0XC);
    // 0x80678244: addiu       $v0, $v0, -0x400
    ctx->r2 = ADD32(ctx->r2, -0X400);
    // 0x80678248: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8067824C: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    // 0x80678250: sw          $v0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r2;
L_80678254:
    // 0x80678254: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80678258: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8067825C: sltiu       $at, $t4, 0x80
    ctx->r1 = ctx->r12 < 0X80 ? 1 : 0;
    // 0x80678260: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80678264: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x80678268: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8067826C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80678270: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80678274: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80678278: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8067827C: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x80678280: sw          $t9, -0x18($s1)
    MEM_W(-0X18, ctx->r17) = ctx->r25;
    // 0x80678284: lw          $t8, 0xC($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XC);
    // 0x80678288: sw          $t8, -0x14($s1)
    MEM_W(-0X14, ctx->r17) = ctx->r24;
    // 0x8067828C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80678290: sw          $t7, -0x20($s2)
    MEM_W(-0X20, ctx->r18) = ctx->r15;
    // 0x80678294: lw          $t6, 0x4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X4);
    // 0x80678298: sw          $t6, -0x1C($s2)
    MEM_W(-0X1C, ctx->r18) = ctx->r14;
    // 0x8067829C: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
    // 0x806782A0: sw          $t7, -0x18($s2)
    MEM_W(-0X18, ctx->r18) = ctx->r15;
    // 0x806782A4: lw          $t6, 0xC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0XC);
    // 0x806782A8: sw          $t6, -0x14($s2)
    MEM_W(-0X14, ctx->r18) = ctx->r14;
    // 0x806782AC: lh          $t8, -0x4($t5)
    ctx->r24 = MEM_H(ctx->r13, -0X4);
    // 0x806782B0: sh          $t8, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r24;
    // 0x806782B4: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x806782B8: sh          $t9, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r25;
    // 0x806782BC: lh          $t6, -0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, -0X2);
    // 0x806782C0: sh          $t6, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r14;
    // 0x806782C4: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x806782C8: bne         $at, $zero, L_80678254
    if (ctx->r1 != 0) {
        // 0x806782CC: sh          $t7, -0xE($s1)
        MEM_H(-0XE, ctx->r17) = ctx->r15;
            goto L_80678254;
    }
    // 0x806782CC: sh          $t7, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r15;
    // 0x806782D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806782D4: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x806782D8: ori         $t3, $t3, 0x103F
    ctx->r11 = ctx->r11 | 0X103F;
    // 0x806782DC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806782E0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806782E4: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x806782E8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806782EC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806782F0: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x806782F4: addiu       $t5, $zero, 0x206
    ctx->r13 = ADD32(0, 0X206);
    // 0x806782F8: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806782FC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80678300: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80678304: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678308: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067830C: addiu       $s0, $zero, 0x604
    ctx->r16 = ADD32(0, 0X604);
    // 0x80678310: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80678314: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80678318: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8067831C: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80678320: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678324: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678328: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8067832C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80678330: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80678334: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80678338: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8067833C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80678340: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678344: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80678348: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8067834C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80678350: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80678354: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80678358: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x8067835C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678360: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80678364: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80678368: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8067836C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80678370: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80678374: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678378: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067837C: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x80678380: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x80678384: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x80678388: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8067838C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80678390: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80678394: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678398: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x8067839C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x806783A0: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806783A4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806783A8: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806783AC: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806783B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806783B4: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806783B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806783BC: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806783C0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_806783C4:
    // 0x806783C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806783C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806783CC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806783D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806783D4: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806783D8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806783DC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806783E0: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806783E4: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806783E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806783EC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806783F0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806783F4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806783F8: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806783FC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80678400: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80678404: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678408: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067840C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80678410: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80678414: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80678418: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8067841C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678420: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80678424: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80678428: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8067842C: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80678430: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678434: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678438: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8067843C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80678440: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80678444: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678448: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067844C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x80678450: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80678454: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80678458: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8067845C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678460: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80678464: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80678468: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8067846C: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80678470: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678474: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80678478: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8067847C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80678480: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80678484: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80678488: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067848C: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80678490: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80678494: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80678498: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8067849C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806784A0: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806784A4: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806784A8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806784AC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806784B0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806784B4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806784B8: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806784BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806784C0: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806784C4: bne         $a1, $v1, L_806783C4
    if (ctx->r5 != ctx->r3) {
        // 0x806784C8: sw          $t4, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r12;
            goto L_806783C4;
    }
    // 0x806784C8: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806784CC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x806784D0: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x806784D4: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x806784D8: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x806784DC: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x806784E0: jr          $ra
    // 0x806784E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806784E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80567B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567B54: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80567B58: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x80567B5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80567B60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80567B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80567B68: beq         $t6, $zero, L_80567C38
    if (ctx->r14 == 0) {
        // 0x80567B6C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80567C38;
    }
    // 0x80567B6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80567B70: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80567B74: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80567B78: jal         0x8005FDC4
    // 0x80567B7C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x80567B7C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    after_0:
    // 0x80567B80: jal         0x80567AC4
    // 0x80567B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567AC4(rdram, ctx);
        goto after_1;
    // 0x80567B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80567B88: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80567B8C: jal         0x80067BBC
    // 0x80567B90: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80567B90: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80567B94: jal         0x80067E68
    // 0x80567B98: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x80567B98: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x80567B9C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80567BA0: jal         0x80067818
    // 0x80567BA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80567BA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80567BA8: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80567BAC: addiu       $at, $zero, 0x4668
    ctx->r1 = ADD32(0, 0X4668);
    // 0x80567BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80567BB4: beq         $v0, $at, L_80567BCC
    if (ctx->r2 == ctx->r1) {
        // 0x80567BB8: addiu       $at, $zero, 0x4669
        ctx->r1 = ADD32(0, 0X4669);
            goto L_80567BCC;
    }
    // 0x80567BB8: addiu       $at, $zero, 0x4669
    ctx->r1 = ADD32(0, 0X4669);
    // 0x80567BBC: beq         $v0, $at, L_80567C04
    if (ctx->r2 == ctx->r1) {
        // 0x80567BC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80567C04;
    }
    // 0x80567BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80567BC4: b           L_80567C3C
    // 0x80567BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80567C3C;
    // 0x80567BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80567BCC:
    // 0x80567BCC: jal         0x80569310
    // 0x80567BD0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80569310(rdram, ctx);
        goto after_5;
    // 0x80567BD0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80567BD4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80567BD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80567BDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80567BE0: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X218C) << 16);
    // 0x80567BE4: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x80567BE8: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x80567BEC: lwc1        $f8, -0x68C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X218C));
    // 0x80567BF0: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80567BF4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80567BF8: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80567BFC: b           L_80567C38
    // 0x80567C00: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
        goto L_80567C38;
    // 0x80567C00: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
L_80567C04:
    // 0x80567C04: jal         0x80569310
    // 0x80567C08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80569310(rdram, ctx);
        goto after_6;
    // 0x80567C08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80567C0C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80567C10: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80567C14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80567C18: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2190) << 16);
    // 0x80567C1C: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x80567C20: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x80567C24: lwc1        $f4, -0x68C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2190));
    // 0x80567C28: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x80567C2C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80567C30: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80567C34: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
L_80567C38:
    // 0x80567C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80567C3C:
    // 0x80567C3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80567C40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80567C44: jr          $ra
    // 0x80567C48: nop

    return;
    // 0x80567C48: nop

;}
RECOMP_FUNC void func_8069B8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B8C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069B8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069B8D0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8069B8D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8069B8D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8069B8DC: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(565, 0X1044) << 16);
    // 0x8069B8E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069B8E4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8069B8E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8069B8EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8069B8F0: lw          $t8, -0x42EC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(565, 0X1044));
    // 0x8069B8F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8069B8F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8069B8FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069B900: jal         0x80048490
    // 0x8069B904: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8069B904: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8069B908: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8069B90C: jal         0x80048378
    // 0x8069B910: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8069B910: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8069B914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069B918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069B91C: jr          $ra
    // 0x8069B920: nop

    return;
    // 0x8069B920: nop

;}
RECOMP_FUNC void func_80787004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787004: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80787008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078700C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80787010: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80787014: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80787018: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8078701C: jal         0x80786B60
    // 0x80787020: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80786B60(rdram, ctx);
        goto after_0;
    // 0x80787020: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80787024: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80787028: jal         0x80786D08
    // 0x8078702C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80786D08(rdram, ctx);
        goto after_1;
    // 0x8078702C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80787030: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80787034: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80787038: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8078703C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80787040: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80787044: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80787048: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8078704C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80787050: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80787054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80787058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078705C: jr          $ra
    // 0x80787060: nop

    return;
    // 0x80787060: nop

;}
RECOMP_FUNC void func_806B297C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B297C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2980: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2984: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2988: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B298C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2990: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2994: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2998: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B299C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B29A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B29A4: jr          $ra
    // 0x806B29A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B29A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805276E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805276E0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6184) << 16);
    // 0x805276E4: lwc1        $f4, -0x3F7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6184));
    // 0x805276E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805276EC: lui         $v1, 0x8053
    ctx->r3 = S32(RELOC_HI16(327, 0X60B4) << 16);
    // 0x805276F0: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(327, 0X1890) << 16);
    // 0x805276F4: addiu       $v1, $v1, -0x404C
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(327, 0X60B4));
    // 0x805276F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x805276FC: addiu       $t6, $t6, 0x7790
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0X1890));
    // 0x80527700: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80527704: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80527708: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8052770C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80527710: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80527714: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    // 0x80527718: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x8052771C: jr          $ra
    // 0x80527720: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80527720: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_807BC6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC6B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC6B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC6BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807BC6C0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x807BC6C4: jal         0x80067878
    // 0x807BC6C8: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x807BC6C8: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_0:
    // 0x807BC6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC6D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC6D4: jr          $ra
    // 0x807BC6D8: nop

    return;
    // 0x807BC6D8: nop

;}
RECOMP_FUNC void func_800470F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800470F4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800470F8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800470FC: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x80047100: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80047104: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80047108: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004710C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80047110: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80047114: lwc1        $f10, 0x40($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80047118: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8004711C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80047120: jr          $ra
    // 0x80047124: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80047124: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8005BDA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BDA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BDAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BDB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BDB4: jal         0x8005BA30
    // 0x8005BDB8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BDB8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BDBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BDC0: bne         $v0, $at, L_8005BDD0
    if (ctx->r2 != ctx->r1) {
        // 0x8005BDC4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005BDD0;
    }
    // 0x8005BDC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005BDC8: b           L_8005BDE8
    // 0x8005BDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005BDE8;
    // 0x8005BDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BDD0:
    // 0x8005BDD0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8005BDD4: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BDD8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BDDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BDE0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005BDE4: lw          $v0, -0x4BA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA0);
L_8005BDE8:
    // 0x8005BDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BDEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BDF0: jr          $ra
    // 0x8005BDF4: nop

    return;
    // 0x8005BDF4: nop

;}
RECOMP_FUNC void func_80058B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B18: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80058B1C: lw          $v0, -0x6DA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6DA8);
    // 0x80058B20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80058B24: addiu       $a0, $v0, 0x120
    ctx->r4 = ADD32(ctx->r2, 0X120);
    // 0x80058B28: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80058B2C:
    // 0x80058B2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80058B30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80058B34: bne         $v1, $v0, L_80058B2C
    if (ctx->r3 != ctx->r2) {
        // 0x80058B38: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80058B2C;
    }
    // 0x80058B38: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x80058B3C: jr          $ra
    // 0x80058B40: nop

    return;
    // 0x80058B40: nop

;}
RECOMP_FUNC void func_8067424C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067424C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80674250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80674254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80674258: jal         0x800659EC
    // 0x8067425C: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x8067425C: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    after_0:
    // 0x80674260: lui         $at, 0xC333
    ctx->r1 = S32(0XC333 << 16);
    // 0x80674264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80674268: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C3C) << 16);
    // 0x8067426C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80674270: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80674274: nop

    // 0x80674278: bc1fl       L_806742A8
    if (!c1cs) {
        // 0x8067427C: lui         $at, 0x4333
        ctx->r1 = S32(0X4333 << 16);
            goto L_806742A8;
    }
    goto skip_0;
    // 0x8067427C: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    skip_0:
    // 0x80674280: lwc1        $f6, 0x4C1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C3C));
    // 0x80674284: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C40) << 16);
    // 0x80674288: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8067428C: nop

    // 0x80674290: bc1fl       L_806742A8
    if (!c1cs) {
        // 0x80674294: lui         $at, 0x4333
        ctx->r1 = S32(0X4333 << 16);
            goto L_806742A8;
    }
    goto skip_1;
    // 0x80674294: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    skip_1:
    // 0x80674298: lwc1        $f8, 0x4C20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C40));
    // 0x8067429C: b           L_806742F0
    // 0x806742A0: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
        goto L_806742F0;
    // 0x806742A0: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x806742A4: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
L_806742A8:
    // 0x806742A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806742AC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C44) << 16);
    // 0x806742B0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806742B4: nop

    // 0x806742B8: bc1fl       L_806742E8
    if (!c1cs) {
        // 0x806742BC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_806742E8;
    }
    goto skip_2;
    // 0x806742BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_2:
    // 0x806742C0: lwc1        $f16, 0x4C24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C44));
    // 0x806742C4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C48) << 16);
    // 0x806742C8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806742CC: nop

    // 0x806742D0: bc1fl       L_806742E8
    if (!c1cs) {
        // 0x806742D4: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_806742E8;
    }
    goto skip_3;
    // 0x806742D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_3:
    // 0x806742D8: lwc1        $f18, 0x4C28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C48));
    // 0x806742DC: b           L_806742F0
    // 0x806742E0: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
        goto L_806742F0;
    // 0x806742E0: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x806742E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_806742E8:
    // 0x806742E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806742EC: nop

L_806742F0:
    // 0x806742F0: swc1        $f2, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f2.u32l;
    // 0x806742F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806742F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806742FC: jr          $ra
    // 0x80674300: nop

    return;
    // 0x80674300: nop

;}
RECOMP_FUNC void func_806FB184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FB184: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x806FB188: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x806FB18C: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x806FB190: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x806FB194: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x806FB198: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x806FB19C: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x806FB1A0: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x806FB1A4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x806FB1A8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x806FB1AC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x806FB1B0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x806FB1B4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x806FB1B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806FB1BC: lwc1        $f4, 0x6C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x806FB1C0: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x806FB1C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FB1C8: mul.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806FB1CC: lwc1        $f8, 0x70($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X70);
    // 0x806FB1D0: lwc1        $f20, 0x8($a1)
    ctx->f20.u32l = MEM_W(ctx->r5, 0X8);
    // 0x806FB1D4: lwc1        $f22, 0xC($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0XC);
    // 0x806FB1D8: mul.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806FB1DC: lwc1        $f24, 0x14A4($a1)
    ctx->f24.u32l = MEM_W(ctx->r5, 0X14A4);
    // 0x806FB1E0: addiu       $s1, $a1, 0x8
    ctx->r17 = ADD32(ctx->r5, 0X8);
    // 0x806FB1E4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x806FB1E8: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x806FB1EC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x806FB1F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806FB1F4: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x806FB1F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x806FB1FC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x806FB200: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x806FB204: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806FB208: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x806FB20C: jal         0x806FB050
    // 0x806FB210: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_806FB050(rdram, ctx);
        goto after_0;
    // 0x806FB210: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x806FB214: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x806FB218: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
L_806FB21C:
    // 0x806FB21C: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x806FB220: addiu       $s3, $s3, 0x400
    ctx->r19 = ADD32(ctx->r19, 0X400);
    // 0x806FB224: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x806FB228: sub.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x806FB22C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806FB230: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x806FB234: sub.s       $f14, $f22, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x806FB238: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x806FB23C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x806FB240: jal         0x80067114
    // 0x806FB244: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x806FB244: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    after_1:
    // 0x806FB248: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x806FB24C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x806FB250: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x806FB254: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x806FB258: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x806FB25C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x806FB260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FB264: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x806FB268: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x806FB26C: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x806FB270: jal         0x806FB050
    // 0x806FB274: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_806FB050(rdram, ctx);
        goto after_2;
    // 0x806FB274: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_2:
    // 0x806FB278: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806FB27C: slti        $at, $s2, 0x11
    ctx->r1 = SIGNED(ctx->r18) < 0X11 ? 1 : 0;
    // 0x806FB280: bnel        $at, $zero, L_806FB21C
    if (ctx->r1 != 0) {
        // 0x806FB284: lwc1        $f0, 0x8($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
            goto L_806FB21C;
    }
    goto skip_0;
    // 0x806FB284: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x806FB288: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806FB28C: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x806FB290: addiu       $s3, $s3, 0x3FF
    ctx->r19 = ADD32(ctx->r19, 0X3FF);
    // 0x806FB294: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x806FB298: sub.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x806FB29C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806FB2A0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x806FB2A4: sub.s       $f14, $f22, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x806FB2A8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x806FB2AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x806FB2B0: jal         0x80067114
    // 0x806FB2B4: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    func_80067114(rdram, ctx);
        goto after_3;
    // 0x806FB2B4: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    after_3:
    // 0x806FB2B8: neg.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = -ctx->f0.fl;
    // 0x806FB2BC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x806FB2C0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x806FB2C4: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x806FB2C8: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x806FB2CC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x806FB2D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FB2D4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x806FB2D8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x806FB2DC: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x806FB2E0: jal         0x806FB050
    // 0x806FB2E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_806FB050(rdram, ctx);
        goto after_4;
    // 0x806FB2E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_4:
    // 0x806FB2E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806FB2EC: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x806FB2F0: beq         $at, $zero, L_806FB38C
    if (ctx->r1 == 0) {
        // 0x806FB2F4: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_806FB38C;
    }
    // 0x806FB2F4: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_806FB2F8:
    // 0x806FB2F8: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x806FB2FC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x806FB300: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x806FB304: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x806FB308: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x806FB30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FB310: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x806FB314: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x806FB318: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806FB31C: jal         0x806FB050
    // 0x806FB320: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_806FB050(rdram, ctx);
        goto after_5;
    // 0x806FB320: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_5:
    // 0x806FB324: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806FB328: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x806FB32C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x806FB330: sub.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x806FB334: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x806FB338: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x806FB33C: sub.s       $f14, $f22, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x806FB340: jal         0x80067114
    // 0x806FB344: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    func_80067114(rdram, ctx);
        goto after_6;
    // 0x806FB344: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    after_6:
    // 0x806FB348: neg.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = -ctx->f0.fl;
    // 0x806FB34C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x806FB350: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x806FB354: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x806FB358: addiu       $t1, $zero, 0x3E0
    ctx->r9 = ADD32(0, 0X3E0);
    // 0x806FB35C: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x806FB360: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x806FB364: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x806FB368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FB36C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x806FB370: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x806FB374: jal         0x806FB050
    // 0x806FB378: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_806FB050(rdram, ctx);
        goto after_7;
    // 0x806FB378: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_7:
    // 0x806FB37C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806FB380: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x806FB384: bnel        $at, $zero, L_806FB2F8
    if (ctx->r1 != 0) {
        // 0x806FB388: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_806FB2F8;
    }
    goto skip_1;
    // 0x806FB388: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    skip_1:
L_806FB38C:
    // 0x806FB38C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x806FB390: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x806FB394: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x806FB398: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x806FB39C: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x806FB3A0: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x806FB3A4: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x806FB3A8: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x806FB3AC: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x806FB3B0: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x806FB3B4: jr          $ra
    // 0x806FB3B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x806FB3B8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80031AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031AB4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80031AB8: bne         $v0, $zero, L_80031AD0
    if (ctx->r2 != 0) {
        // 0x80031ABC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80031AD0;
    }
    // 0x80031ABC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80031AC0: jal         0x800409F0
    // 0x80031AC4: nop

    func_800409F0(rdram, ctx);
        goto after_0;
    // 0x80031AC4: nop

    after_0:
    // 0x80031AC8: b           L_80031AD8
    // 0x80031ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031AD8;
    // 0x80031ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031AD0:
    // 0x80031AD0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x80031AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031AD8:
    // 0x80031AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031ADC: jr          $ra
    // 0x80031AE0: nop

    return;
    // 0x80031AE0: nop

;}
RECOMP_FUNC void func_800442F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800442F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800442F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800442F8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800442FC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80044300: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80044304: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80044308: bne         $t7, $at, L_8004433C
    if (ctx->r15 != ctx->r1) {
        // 0x8004430C: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8004433C;
    }
    // 0x8004430C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80044310: lh          $a1, 0x17E($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X17E);
    // 0x80044314: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80044318: jal         0x80043D0C
    // 0x8004431C: addiu       $a0, $a0, -0x77D4
    ctx->r4 = ADD32(ctx->r4, -0X77D4);
    func_80043D0C(rdram, ctx);
        goto after_0;
    // 0x8004431C: addiu       $a0, $a0, -0x77D4
    ctx->r4 = ADD32(ctx->r4, -0X77D4);
    after_0:
    // 0x80044320: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80044324: lh          $t8, -0x77CE($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X77CE);
    // 0x80044328: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004432C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044330: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80044334: jal         0x80044214
    // 0x80044338: sh          $t9, -0x77CE($at)
    MEM_H(-0X77CE, ctx->r1) = ctx->r25;
    func_80044214(rdram, ctx);
        goto after_1;
    // 0x80044338: sh          $t9, -0x77CE($at)
    MEM_H(-0X77CE, ctx->r1) = ctx->r25;
    after_1:
L_8004433C:
    // 0x8004433C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044344: jr          $ra
    // 0x80044348: nop

    return;
    // 0x80044348: nop

;}
RECOMP_FUNC void func_806D3DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3DCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D3DD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D3DD4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806D3DD8: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(616, 0X3620) << 16);
    // 0x806D3DDC: addiu       $t6, $t6, 0x65D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(616, 0X3620));
    // 0x806D3DE0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806D3DE4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806D3DE8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806D3DEC: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x806D3DF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x806D3DF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D3DF8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806D3DFC: jal         0x806D414C
    // 0x806D3E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D414C(rdram, ctx);
        goto after_0;
    // 0x806D3E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x806D3E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D3E08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806D3E0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806D3E10: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806D3E14: jr          $ra
    // 0x806D3E18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806D3E18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8045BD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BD74: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045BD78: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x8045BD7C: srl         $a3, $a1, 1
    ctx->r7 = S32(U32(ctx->r5) >> 1);
    // 0x8045BD80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045BD84: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8045BD88: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8045BD8C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8045BD90: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x8045BD94: beq         $a3, $zero, L_8045BDD4
    if (ctx->r7 == 0) {
        // 0x8045BD98: sw          $a1, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r5;
            goto L_8045BDD4;
    }
    // 0x8045BD98: sw          $a1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r5;
    // 0x8045BD9C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045BDA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045BDA4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BDA8: nop

L_8045BDAC:
    // 0x8045BDAC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8045BDB0: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8045BDB4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8045BDB8: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x8045BDBC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8045BDC0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8045BDC4: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8045BDC8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8045BDCC: bne         $at, $zero, L_8045BDAC
    if (ctx->r1 != 0) {
        // 0x8045BDD0: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8045BDAC;
    }
    // 0x8045BDD0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8045BDD4:
    // 0x8045BDD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BDD8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X229C) << 16);
    // 0x8045BDDC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8045BDE0: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x8045BDE4: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8045BDE8: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8045BDEC: lwc1        $f4, -0x24D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X229C));
    // 0x8045BDF0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22A0) << 16);
    // 0x8045BDF4: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x8045BDF8: lwc1        $f6, -0x24D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22A0));
    // 0x8045BDFC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8045BE00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8045BE04: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22A4) << 16);
    // 0x8045BE08: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8045BE0C: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x8045BE10: lwc1        $f10, -0x24CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22A4));
    // 0x8045BE14: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8045BE18: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
    // 0x8045BE1C: jr          $ra
    // 0x8045BE20: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8045BE20: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8066A568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A568: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8066A56C: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x8066A570: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8066A574: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8066A578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8066A57C:
    // 0x8066A57C: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8066A580: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8066A584: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8066A588: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8066A58C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8066A590: bc1f        L_8066A5B4
    if (!c1cs) {
        // 0x8066A594: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_8066A5B4;
    }
    // 0x8066A594: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8066A598: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8066A59C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8066A5A0: nop

    // 0x8066A5A4: bc1fl       L_8066A5D0
    if (!c1cs) {
        // 0x8066A5A8: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8066A5D0;
    }
    goto skip_0;
    // 0x8066A5A8: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_0:
    // 0x8066A5AC: b           L_8066A5CC
    // 0x8066A5B0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8066A5CC;
    // 0x8066A5B0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8066A5B4:
    // 0x8066A5B4: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8066A5B8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8066A5BC: nop

    // 0x8066A5C0: bc1fl       L_8066A5D0
    if (!c1cs) {
        // 0x8066A5C4: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8066A5D0;
    }
    goto skip_1;
    // 0x8066A5C4: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_1:
    // 0x8066A5C8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8066A5CC:
    // 0x8066A5CC: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
L_8066A5D0:
    // 0x8066A5D0: lwc1        $f4, 0xC4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8066A5D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8066A5D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8066A5DC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8066A5E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8066A5E4: bne         $v0, $a0, L_8066A57C
    if (ctx->r2 != ctx->r4) {
        // 0x8066A5E8: swc1        $f6, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
            goto L_8066A57C;
    }
    // 0x8066A5E8: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x8066A5EC: jr          $ra
    // 0x8066A5F0: nop

    return;
    // 0x8066A5F0: nop

;}
RECOMP_FUNC void func_8002FE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FE38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FE40: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FE44: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FE48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8002FE4C: jal         0x8002F678
    // 0x8002FE50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FE50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FE54: beq         $v0, $zero, L_8002FE68
    if (ctx->r2 == 0) {
        // 0x8002FE58: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FE68;
    }
    // 0x8002FE58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FE5C: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FE60: addiu       $t6, $t6, -0x30C0
    ctx->r14 = ADD32(ctx->r14, -0X30C0);
    // 0x8002FE64: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FE68:
    // 0x8002FE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FE70: jr          $ra
    // 0x8002FE74: nop

    return;
    // 0x8002FE74: nop

;}
RECOMP_FUNC void func_804B8C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B8C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B8C60: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804B8C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804B8C68: beq         $t6, $zero, L_804B8CA4
    if (ctx->r14 == 0) {
        // 0x804B8C6C: nop
    
            goto L_804B8CA4;
    }
    // 0x804B8C6C: nop

    // 0x804B8C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B8C74: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804B8C78: jalr        $t9
    // 0x804B8C7C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804B8C7C: nop

    after_0:
    // 0x804B8C80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B8C84: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804B8C88: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804B8C8C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804B8C90: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804B8C94: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804B8C98: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804B8C9C: b           L_804B8CA4
    // 0x804B8CA0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804B8CA4;
    // 0x804B8CA0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804B8CA4:
    // 0x804B8CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B8CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B8CAC: jr          $ra
    // 0x804B8CB0: nop

    return;
    // 0x804B8CB0: nop

;}
RECOMP_FUNC void func_80737F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80737F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737F8C: jal         0x80735B44
    // 0x80737F90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80735B44(rdram, ctx);
        goto after_0;
    // 0x80737F90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80737F94: jal         0x80045BD8
    // 0x80737F98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80737F98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80737F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80737FA4: jr          $ra
    // 0x80737FA8: nop

    return;
    // 0x80737FA8: nop

;}
RECOMP_FUNC void func_80058E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058E10: jal         0x80081C64
    // 0x80058E14: nop

    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80058E14: nop

    after_0:
    // 0x80058E18: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80058E1C: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80058E20: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058E24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058E28: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80058E2C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058E30: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80058E34: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80058E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058E3C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80058E40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058E44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80058E48: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80058E4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058E50: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80058E54: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80058E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058E5C: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80058E60: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80058E64: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80058E68: jr          $ra
    // 0x80058E6C: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    return;
    // 0x80058E6C: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
;}
RECOMP_FUNC void func_805A7350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7350: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(426, 0X10) << 16);
    // 0x805A7354: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805A7358: jr          $ra
    // 0x805A735C: addiu       $v0, $v0, 0x7360
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(426, 0X10));
    return;
    // 0x805A735C: addiu       $v0, $v0, 0x7360
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(426, 0X10));
;}
RECOMP_FUNC void func_806DB89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB89C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806DB8A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DB8A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806DB8A8: jal         0x806DB590
    // 0x806DB8AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806DB590(rdram, ctx);
        goto after_0;
    // 0x806DB8AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806DB8B0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806DB8B4: jal         0x80048F84
    // 0x806DB8B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806DB8B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806DB8BC: jal         0x806DB860
    // 0x806DB8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DB860(rdram, ctx);
        goto after_2;
    // 0x806DB8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806DB8C4: bnel        $v0, $zero, L_806DB8F0
    if (ctx->r2 != 0) {
        // 0x806DB8C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806DB8F0;
    }
    goto skip_0;
    // 0x806DB8C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806DB8CC: jal         0x806DB7E4
    // 0x806DB8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DB7E4(rdram, ctx);
        goto after_3;
    // 0x806DB8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806DB8D4: beq         $v0, $zero, L_806DB8EC
    if (ctx->r2 == 0) {
        // 0x806DB8D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806DB8EC;
    }
    // 0x806DB8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806DB8DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806DB8E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806DB8E4: jal         0x806DB928
    // 0x806DB8E8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_806DB928(rdram, ctx);
        goto after_4;
    // 0x806DB8E8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
L_806DB8EC:
    // 0x806DB8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DB8F0:
    // 0x806DB8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806DB8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806DB8F8: jr          $ra
    // 0x806DB8FC: nop

    return;
    // 0x806DB8FC: nop

;}
RECOMP_FUNC void func_80672AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672AEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80672AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80672AF4: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672AF8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80672AFC: lbu         $v0, -0x7204($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7204);
    // 0x80672B00: lw          $t6, 0x18($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X18);
    // 0x80672B04: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80672B08: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80672B0C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80672B10: lbu         $t9, 0x10($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X10);
    // 0x80672B14: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80672B18: lw          $t0, 0x10($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X10);
    // 0x80672B1C: beql        $t0, $zero, L_80672B44
    if (ctx->r8 == 0) {
        // 0x80672B20: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_80672B44;
    }
    goto skip_0;
    // 0x80672B20: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80672B24: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80672B28: jal         0x80672750
    // 0x80672B2C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80672750(rdram, ctx);
        goto after_0;
    // 0x80672B2C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80672B30: jal         0x806728F4
    // 0x80672B34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806728F4(rdram, ctx);
        goto after_1;
    // 0x80672B34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80672B38: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80672B3C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80672B40: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
L_80672B44:
    // 0x80672B44: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80672B48: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x80672B4C: sltiu       $at, $t2, 0xFF
    ctx->r1 = ctx->r10 < 0XFF ? 1 : 0;
    // 0x80672B50: bne         $at, $zero, L_80672C64
    if (ctx->r1 != 0) {
        // 0x80672B54: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80672C64;
    }
    // 0x80672B54: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80672B58: lw          $t4, -0x7478($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7478);
    // 0x80672B5C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80672B60: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80672B64: beq         $t4, $zero, L_80672BF4
    if (ctx->r12 == 0) {
        // 0x80672B68: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_80672BF4;
    }
    // 0x80672B68: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80672B6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80672B70: jal         0x80672A34
    // 0x80672B74: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80672A34(rdram, ctx);
        goto after_2;
    // 0x80672B74: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80672B78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80672B7C: sw          $v0, -0x7470($at)
    MEM_W(-0X7470, ctx->r1) = ctx->r2;
    // 0x80672B80: beq         $v0, $zero, L_80672BAC
    if (ctx->r2 == 0) {
        // 0x80672B84: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80672BAC;
    }
    // 0x80672B84: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80672B88: lw          $t5, 0x28($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X28);
    // 0x80672B8C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80672B90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80672B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80672B98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80672B9C: jal         0x8006E0FC
    // 0x80672BA0: sw          $t5, -0x7494($at)
    MEM_W(-0X7494, ctx->r1) = ctx->r13;
    func_8006E0FC(rdram, ctx);
        goto after_3;
    // 0x80672BA0: sw          $t5, -0x7494($at)
    MEM_W(-0X7494, ctx->r1) = ctx->r13;
    after_3:
    // 0x80672BA4: b           L_80672C68
    // 0x80672BA8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
        goto L_80672C68;
    // 0x80672BA8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_80672BAC:
    // 0x80672BAC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80672BB0: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80672BB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80672BB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80672BBC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80672BC0: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80672BC4: bne         $t8, $at, L_80672BE4
    if (ctx->r24 != ctx->r1) {
        // 0x80672BC8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80672BE4;
    }
    // 0x80672BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80672BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80672BD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80672BD4: jal         0x8006E0FC
    // 0x80672BD8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_4;
    // 0x80672BD8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_4:
    // 0x80672BDC: b           L_80672C68
    // 0x80672BE0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
        goto L_80672C68;
    // 0x80672BE0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_80672BE4:
    // 0x80672BE4: jal         0x8006E0FC
    // 0x80672BE8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_5;
    // 0x80672BE8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_5:
    // 0x80672BEC: b           L_80672C68
    // 0x80672BF0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
        goto L_80672C68;
    // 0x80672BF0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_80672BF4:
    // 0x80672BF4: lbu         $t9, -0x71F5($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X71F5);
    // 0x80672BF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80672BFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80672C00: bne         $t9, $at, L_80672C20
    if (ctx->r25 != ctx->r1) {
        // 0x80672C04: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80672C20;
    }
    // 0x80672C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80672C08: jal         0x8006E0FC
    // 0x80672C0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_6;
    // 0x80672C0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80672C10: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80672C14: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80672C18: b           L_80672C64
    // 0x80672C1C: sw          $t0, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r8;
        goto L_80672C64;
    // 0x80672C1C: sw          $t0, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r8;
L_80672C20:
    // 0x80672C20: lw          $t1, 0x28($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X28);
    // 0x80672C24: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80672C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80672C2C: sw          $t1, -0x7494($at)
    MEM_W(-0X7494, ctx->r1) = ctx->r9;
    // 0x80672C30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80672C34: beq         $v0, $at, L_80672C48
    if (ctx->r2 == ctx->r1) {
        // 0x80672C38: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80672C48;
    }
    // 0x80672C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80672C3C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80672C40: bne         $v0, $at, L_80672C58
    if (ctx->r2 != ctx->r1) {
        // 0x80672C44: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80672C58;
    }
    // 0x80672C44: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_80672C48:
    // 0x80672C48: jal         0x8006E0FC
    // 0x80672C4C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    func_8006E0FC(rdram, ctx);
        goto after_7;
    // 0x80672C4C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_7:
    // 0x80672C50: b           L_80672C68
    // 0x80672C54: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
        goto L_80672C68;
    // 0x80672C54: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_80672C58:
    // 0x80672C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80672C5C: jal         0x8006E0FC
    // 0x80672C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_8;
    // 0x80672C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_80672C64:
    // 0x80672C64: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_80672C68:
    // 0x80672C68: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80672C6C: sb          $t2, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r10;
    // 0x80672C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80672C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80672C78: jr          $ra
    // 0x80672C7C: nop

    return;
    // 0x80672C7C: nop

;}
RECOMP_FUNC void func_804BB930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB930: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(191, 0X10) << 16);
    // 0x804BB934: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804BB938: jr          $ra
    // 0x804BB93C: addiu       $v0, $v0, -0x46C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(191, 0X10));
    return;
    // 0x804BB93C: addiu       $v0, $v0, -0x46C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(191, 0X10));
;}
RECOMP_FUNC void func_80788F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80788F84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80788F88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80788F8C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80788F90: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80788F94: lbu         $t6, 0x165($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X165);
    // 0x80788F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80788F9C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80788FA0: beq         $t6, $at, L_8078917C
    if (ctx->r14 == ctx->r1) {
        // 0x80788FA4: lhu         $v1, 0xC($a1)
        ctx->r3 = MEM_HU(ctx->r5, 0XC);
            goto L_8078917C;
    }
    // 0x80788FA4: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x80788FA8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80788FAC: beq         $v1, $at, L_80788FCC
    if (ctx->r3 == ctx->r1) {
        // 0x80788FB0: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_80788FCC;
    }
    // 0x80788FB0: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80788FB4: beq         $v1, $at, L_80789050
    if (ctx->r3 == ctx->r1) {
        // 0x80788FB8: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_80789050;
    }
    // 0x80788FB8: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x80788FBC: beql        $v1, $at, L_807890E8
    if (ctx->r3 == ctx->r1) {
        // 0x80788FC0: lbu         $t0, 0x18($a1)
        ctx->r8 = MEM_BU(ctx->r5, 0X18);
            goto L_807890E8;
    }
    goto skip_0;
    // 0x80788FC0: lbu         $t0, 0x18($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X18);
    skip_0:
    // 0x80788FC4: b           L_80789180
    // 0x80788FC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80789180;
    // 0x80788FC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80788FCC:
    // 0x80788FCC: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80788FD0: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(787, 0X1B90) << 16);
    // 0x80788FD4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80788FD8: lhu         $v0, 0x52F0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X52F0);
    // 0x80788FDC: addiu       $t4, $t4, -0x7A30
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(787, 0X1B90));
    // 0x80788FE0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80788FE4: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80788FE8: beq         $t9, $zero, L_80789020
    if (ctx->r25 == 0) {
        // 0x80788FEC: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_80789020;
    }
    // 0x80788FEC: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80788FF0: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80788FF4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80788FF8: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80788FFC: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(787, 0X1BF4) << 16);
    // 0x80789000: addiu       $t1, $t1, -0x79CC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(787, 0X1BF4));
    // 0x80789004: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x80789008: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8078900C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80789010: jal         0x80788AB0
    // 0x80789014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80788AB0(rdram, ctx);
        goto after_0;
    // 0x80789014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80789018: b           L_80789180
    // 0x8078901C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80789180;
    // 0x8078901C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80789020:
    // 0x80789020: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80789024: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80789028: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8078902C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80789030: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80789034: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80789038: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8078903C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80789040: jal         0x80788AB0
    // 0x80789044: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80788AB0(rdram, ctx);
        goto after_1;
    // 0x80789044: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80789048: b           L_80789180
    // 0x8078904C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80789180;
    // 0x8078904C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80789050:
    // 0x80789050: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
    // 0x80789054: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80789058: bnel        $t8, $at, L_80789180
    if (ctx->r24 != ctx->r1) {
        // 0x8078905C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80789180;
    }
    goto skip_1;
    // 0x8078905C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80789060: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x80789064: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(787, 0X1D88) << 16);
    // 0x80789068: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8078906C: lhu         $v0, 0x52F0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X52F0);
    // 0x80789070: addiu       $t6, $t6, -0x7838
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(787, 0X1D88));
    // 0x80789074: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80789078: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8078907C: beq         $t1, $zero, L_807890B4
    if (ctx->r9 == 0) {
        // 0x80789080: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_807890B4;
    }
    // 0x80789080: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x80789084: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80789088: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8078908C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80789090: lui         $t3, 0x8079
    ctx->r11 = S32(RELOC_HI16(787, 0X1E84) << 16);
    // 0x80789094: addiu       $t3, $t3, -0x773C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(787, 0X1E84));
    // 0x80789098: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8078909C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x807890A0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x807890A4: jal         0x80788AB0
    // 0x807890A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80788AB0(rdram, ctx);
        goto after_2;
    // 0x807890A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x807890AC: b           L_80789180
    // 0x807890B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80789180;
    // 0x807890B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807890B4:
    // 0x807890B4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x807890B8: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x807890BC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x807890C0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x807890C4: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x807890C8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x807890CC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x807890D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x807890D4: jal         0x80788AB0
    // 0x807890D8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80788AB0(rdram, ctx);
        goto after_3;
    // 0x807890D8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x807890DC: b           L_80789180
    // 0x807890E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80789180;
    // 0x807890E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807890E4: lbu         $t0, 0x18($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X18);
L_807890E8:
    // 0x807890E8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x807890EC: bnel        $t0, $at, L_80789180
    if (ctx->r8 != ctx->r1) {
        // 0x807890F0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80789180;
    }
    goto skip_2;
    // 0x807890F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x807890F4: lbu         $t1, 0x30($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X30);
    // 0x807890F8: bnel        $t1, $zero, L_80789180
    if (ctx->r9 != 0) {
        // 0x807890FC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80789180;
    }
    goto skip_3;
    // 0x807890FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80789100: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80789104: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(787, 0X1D88) << 16);
    // 0x80789108: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8078910C: lhu         $v0, 0x52F0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X52F0);
    // 0x80789110: addiu       $t9, $t9, -0x7838
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(787, 0X1D88));
    // 0x80789114: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80789118: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x8078911C: beq         $t4, $zero, L_80789154
    if (ctx->r12 == 0) {
        // 0x80789120: andi        $t1, $v0, 0x2
        ctx->r9 = ctx->r2 & 0X2;
            goto L_80789154;
    }
    // 0x80789120: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x80789124: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80789128: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8078912C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80789130: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(787, 0X1E84) << 16);
    // 0x80789134: addiu       $t6, $t6, -0x773C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(787, 0X1E84));
    // 0x80789138: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8078913C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80789140: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80789144: jal         0x80788AB0
    // 0x80789148: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80788AB0(rdram, ctx);
        goto after_4;
    // 0x80789148: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8078914C: b           L_80789180
    // 0x80789150: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80789180;
    // 0x80789150: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80789154:
    // 0x80789154: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80789158: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8078915C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80789160: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80789164: sltiu       $t2, $t1, 0x1
    ctx->r10 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80789168: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8078916C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80789170: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80789174: jal         0x80788AB0
    // 0x80789178: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80788AB0(rdram, ctx);
        goto after_5;
    // 0x80789178: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
L_8078917C:
    // 0x8078917C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80789180:
    // 0x80789180: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80789184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80789188: jr          $ra
    // 0x8078918C: nop

    return;
    // 0x8078918C: nop

;}
RECOMP_FUNC void func_80580330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580330: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80580334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80580338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8058033C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80580340: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80580344: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X4208) << 16);
    // 0x80580348: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8058034C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80580350: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80580354: addiu       $t7, $t7, 0x3018
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X4208));
    // 0x80580358: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8058035C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80580360: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80580364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8058036C: jal         0x805802D8
    // 0x80580370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805802D8(rdram, ctx);
        goto after_0;
    // 0x80580370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80580374: jal         0x8057FC80
    // 0x80580378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057FC80(rdram, ctx);
        goto after_1;
    // 0x80580378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8058037C: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80580380: lui         $t9, 0x8058
    ctx->r25 = S32(RELOC_HI16(399, 0XF60) << 16);
    // 0x80580384: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80580388: addiu       $t9, $t9, -0x290
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(399, 0XF60));
    // 0x8058038C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80580390: jal         0x80051194
    // 0x80580394: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    func_80051194(rdram, ctx);
        goto after_2;
    // 0x80580394: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    after_2:
    // 0x80580398: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8058039C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x805803A0: jal         0x8057F718
    // 0x805803A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F718(rdram, ctx);
        goto after_3;
    // 0x805803A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805803A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805803AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805803B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805803B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805803B8: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x805803BC: jr          $ra
    // 0x805803C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805803C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806F8E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8E80: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F8E84: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(694, 0XB80) << 16);
    // 0x806F8E88: addiu       $t6, $t6, -0x7C70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(694, 0XB80));
    // 0x806F8E8C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F8E90: jr          $ra
    // 0x806F8E94: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x806F8E94: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8067F1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F1F0: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(547, 0XF0C) << 16);
    // 0x8067F1F4: addiu       $v0, $v0, 0xFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(547, 0XF0C));
    // 0x8067F1F8: jr          $ra
    // 0x8067F1FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8067F1FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80566560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566568: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8056656C: slti        $at, $v0, 0x4684
    ctx->r1 = SIGNED(ctx->r2) < 0X4684 ? 1 : 0;
    // 0x80566570: bne         $at, $zero, L_80566594
    if (ctx->r1 != 0) {
        // 0x80566574: addiu       $t6, $v0, -0x4174
        ctx->r14 = ADD32(ctx->r2, -0X4174);
            goto L_80566594;
    }
    // 0x80566574: addiu       $t6, $v0, -0x4174
    ctx->r14 = ADD32(ctx->r2, -0X4174);
    // 0x80566578: addiu       $at, $zero, 0x4687
    ctx->r1 = ADD32(0, 0X4687);
    // 0x8056657C: beq         $v0, $at, L_8056662C
    if (ctx->r2 == ctx->r1) {
        // 0x80566580: addiu       $at, $zero, 0x4688
        ctx->r1 = ADD32(0, 0X4688);
            goto L_8056662C;
    }
    // 0x80566580: addiu       $at, $zero, 0x4688
    ctx->r1 = ADD32(0, 0X4688);
    // 0x80566584: beq         $v0, $at, L_8056663C
    if (ctx->r2 == ctx->r1) {
        // 0x80566588: nop
    
            goto L_8056663C;
    }
    // 0x80566588: nop

    // 0x8056658C: b           L_80566668
    // 0x80566590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80566594:
    // 0x80566594: slti        $at, $v0, 0x4683
    ctx->r1 = SIGNED(ctx->r2) < 0X4683 ? 1 : 0;
    // 0x80566598: bne         $at, $zero, L_805665B0
    if (ctx->r1 != 0) {
        // 0x8056659C: addiu       $at, $zero, 0x4683
        ctx->r1 = ADD32(0, 0X4683);
            goto L_805665B0;
    }
    // 0x8056659C: addiu       $at, $zero, 0x4683
    ctx->r1 = ADD32(0, 0X4683);
    // 0x805665A0: beq         $v0, $at, L_8056661C
    if (ctx->r2 == ctx->r1) {
        // 0x805665A4: nop
    
            goto L_8056661C;
    }
    // 0x805665A4: nop

    // 0x805665A8: b           L_80566668
    // 0x805665AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x805665AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805665B0:
    // 0x805665B0: slti        $at, $v0, 0x417C
    ctx->r1 = SIGNED(ctx->r2) < 0X417C ? 1 : 0;
    // 0x805665B4: bne         $at, $zero, L_805665CC
    if (ctx->r1 != 0) {
        // 0x805665B8: addiu       $at, $zero, 0x4682
        ctx->r1 = ADD32(0, 0X4682);
            goto L_805665CC;
    }
    // 0x805665B8: addiu       $at, $zero, 0x4682
    ctx->r1 = ADD32(0, 0X4682);
    // 0x805665BC: beq         $v0, $at, L_8056660C
    if (ctx->r2 == ctx->r1) {
        // 0x805665C0: nop
    
            goto L_8056660C;
    }
    // 0x805665C0: nop

    // 0x805665C4: b           L_80566668
    // 0x805665C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x805665C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805665CC:
    // 0x805665CC: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x805665D0: beq         $at, $zero, L_80566664
    if (ctx->r1 == 0) {
        // 0x805665D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80566664;
    }
    // 0x805665D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805665D8: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XD10) << 16);
    // 0x805665DC: addu        $at, $at, $t6
    gpr jr_addend_805665E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805665E0: lw          $t6, 0x7260($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(375, 0XD10));
    // 0x805665E4: jr          $t6
    // 0x805665E8: nop

    switch (jr_addend_805665E4 >> 2) {
        case 0: goto L_805665EC; break;
        case 1: goto L_805665EC; break;
        case 2: goto L_805665EC; break;
        case 3: goto L_805665FC; break;
        case 4: goto L_805665FC; break;
        case 5: goto L_805665FC; break;
        case 6: goto L_8056665C; break;
        case 7: goto L_8056664C; break;
        default: switch_error(__func__, 0x805665E4, 0x80567260);
    }
    // 0x805665E8: nop

L_805665EC:
    // 0x805665EC: jal         0x80566EC0
    // 0x805665F0: nop

    func_80566EC0(rdram, ctx);
        goto after_0;
    // 0x805665F0: nop

    after_0:
    // 0x805665F4: b           L_80566668
    // 0x805665F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x805665F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805665FC:
    // 0x805665FC: jal         0x80566EEC
    // 0x80566600: nop

    func_80566EEC(rdram, ctx);
        goto after_1;
    // 0x80566600: nop

    after_1:
    // 0x80566604: b           L_80566668
    // 0x80566608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056660C:
    // 0x8056660C: jal         0x80566F20
    // 0x80566610: nop

    func_80566F20(rdram, ctx);
        goto after_2;
    // 0x80566610: nop

    after_2:
    // 0x80566614: b           L_80566668
    // 0x80566618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056661C:
    // 0x8056661C: jal         0x80566F54
    // 0x80566620: nop

    func_80566F54(rdram, ctx);
        goto after_3;
    // 0x80566620: nop

    after_3:
    // 0x80566624: b           L_80566668
    // 0x80566628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056662C:
    // 0x8056662C: jal         0x80567010
    // 0x80566630: nop

    func_80567010(rdram, ctx);
        goto after_4;
    // 0x80566630: nop

    after_4:
    // 0x80566634: b           L_80566668
    // 0x80566638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056663C:
    // 0x8056663C: jal         0x8056704C
    // 0x80566640: nop

    func_8056704C(rdram, ctx);
        goto after_5;
    // 0x80566640: nop

    after_5:
    // 0x80566644: b           L_80566668
    // 0x80566648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056664C:
    // 0x8056664C: jal         0x80566FA0
    // 0x80566650: nop

    func_80566FA0(rdram, ctx);
        goto after_6;
    // 0x80566650: nop

    after_6:
    // 0x80566654: b           L_80566668
    // 0x80566658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566668;
    // 0x80566658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056665C:
    // 0x8056665C: jal         0x80566FD4
    // 0x80566660: nop

    func_80566FD4(rdram, ctx);
        goto after_7;
    // 0x80566660: nop

    after_7:
L_80566664:
    // 0x80566664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80566668:
    // 0x80566668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8056666C: jr          $ra
    // 0x80566670: nop

    return;
    // 0x80566670: nop

;}
RECOMP_FUNC void func_806F20A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F20A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F20AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F20B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F20B4: jal         0x8004700C
    // 0x806F20B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F20B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F20BC: beql        $v0, $zero, L_806F2170
    if (ctx->r2 == 0) {
        // 0x806F20C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2170;
    }
    goto skip_0;
    // 0x806F20C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F20C4: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x806F20C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F20CC: bnel        $t6, $at, L_806F2170
    if (ctx->r14 != ctx->r1) {
        // 0x806F20D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2170;
    }
    goto skip_1;
    // 0x806F20D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806F20D4: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x806F20D8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x806F20DC: bnel        $t7, $at, L_806F2170
    if (ctx->r15 != ctx->r1) {
        // 0x806F20E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2170;
    }
    goto skip_2;
    // 0x806F20E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806F20E4: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806F20E8: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806F20EC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BE4) << 16);
    // 0x806F20F0: lwc1        $f8, 0x3164($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BE4));
    // 0x806F20F4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F20F8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806F20FC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806F2100: nop

    // 0x806F2104: bc1fl       L_806F2170
    if (!c1cs) {
        // 0x806F2108: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2170;
    }
    goto skip_3;
    // 0x806F2108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806F210C: lw          $t8, 0x174($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X174);
    // 0x806F2110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F2114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2118: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x806F211C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F2120: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x806F2124: beql        $t0, $zero, L_806F2170
    if (ctx->r8 == 0) {
        // 0x806F2128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2170;
    }
    goto skip_4;
    // 0x806F2128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x806F212C: jal         0x806F2554
    // 0x806F2130: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F2554(rdram, ctx);
        goto after_1;
    // 0x806F2130: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806F2134: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F2138: jal         0x8005FDC4
    // 0x806F213C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x806F213C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F2140: jal         0x806F1FC8
    // 0x806F2144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F1FC8(rdram, ctx);
        goto after_3;
    // 0x806F2144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F2148: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x806F214C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x806F2150: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x806F2154: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x806F2158: jal         0x80067E68
    // 0x806F215C: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
    func_80067E68(rdram, ctx);
        goto after_4;
    // 0x806F215C: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
    after_4:
    // 0x806F2160: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F2164: jal         0x80067818
    // 0x806F2168: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806F2168: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806F216C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2170:
    // 0x806F2170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F2174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F2178: jr          $ra
    // 0x806F217C: nop

    return;
    // 0x806F217C: nop

;}
RECOMP_FUNC void func_800439F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800439F4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800439F8: sb          $t6, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r14;
    // 0x800439FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80043A00: lw          $v0, -0x77F8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F8);
    // 0x80043A04: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80043A08: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80043A0C: jr          $ra
    // 0x80043A10: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x80043A10: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_804C2454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2454: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804C2458: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(203, 0X964) << 16);
    // 0x804C245C: addiu       $t6, $t6, 0x20D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(203, 0X964));
    // 0x804C2460: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C2464: jr          $ra
    // 0x804C2468: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804C2468: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8042BB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042BB3C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8042BB40: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8042BB44: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8042BB48: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8042BB4C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8042BB50: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8042BB54: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8042BB58: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8042BB5C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8042BB60: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8042BB64: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8042BB68: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8042BB6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8042BB70: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042BB74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042BB78: lwc1        $f26, 0xC4($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042BB7C: lw          $s3, 0x0($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X0);
    // 0x8042BB80: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8042BB84: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
    // 0x8042BB88: lw          $t6, 0x2C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X2C);
    // 0x8042BB8C: lw          $s4, 0x4($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X4);
    // 0x8042BB90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042BB94: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x8042BB98: bne         $t9, $at, L_8042BBA4
    if (ctx->r25 != ctx->r1) {
        // 0x8042BB9C: lw          $a1, 0x20($t8)
        ctx->r5 = MEM_W(ctx->r24, 0X20);
            goto L_8042BBA4;
    }
    // 0x8042BB9C: lw          $a1, 0x20($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X20);
    // 0x8042BBA0: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
L_8042BBA4:
    // 0x8042BBA4: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8042BBA8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X301C) << 16);
    // 0x8042BBAC: lwc1        $f4, -0x2744($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X301C));
    // 0x8042BBB0: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x8042BBB4: slti        $at, $v0, 0x49
    ctx->r1 = SIGNED(ctx->r2) < 0X49 ? 1 : 0;
    // 0x8042BBB8: mul.s       $f26, $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x8042BBBC: bne         $at, $zero, L_8042BBCC
    if (ctx->r1 != 0) {
        // 0x8042BBC0: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_8042BBCC;
    }
    // 0x8042BBC0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8042BBC4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8042BBC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8042BBCC:
    // 0x8042BBCC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8042BBD0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8042BBD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042BBD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8042BBDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8042BBE0: lw          $t2, 0x4C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4C);
    // 0x8042BBE4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8042BBE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042BBEC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8042BBF0: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8042BBF4: slti        $at, $t2, 0x11
    ctx->r1 = SIGNED(ctx->r10) < 0X11 ? 1 : 0;
    // 0x8042BBF8: bne         $at, $zero, L_8042BCCC
    if (ctx->r1 != 0) {
        // 0x8042BBFC: addiu       $s2, $zero, 0x10
        ctx->r18 = ADD32(0, 0X10);
            goto L_8042BCCC;
    }
    // 0x8042BBFC: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x8042BC00: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042BC04: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8042BC08: addiu       $s0, $a1, 0x100
    ctx->r16 = ADD32(ctx->r5, 0X100);
L_8042BC0C:
    // 0x8042BC0C: neg.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = -ctx->f20.fl;
    // 0x8042BC10: jal         0x80066DE4
    // 0x8042BC14: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8042BC14: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8042BC18: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8042BC1C: lwc1        $f4, 0x50($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X50);
    // 0x8042BC20: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8042BC24: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8042BC28: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8042BC2C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8042BC30: add.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x8042BC34: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8042BC38: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8042BC3C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8042BC40: nop

    // 0x8042BC44: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8042BC48: jal         0x80066DE4
    // 0x8042BC4C: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8042BC4C: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    after_1:
    // 0x8042BC50: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8042BC54: lwc1        $f18, 0x50($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X50);
    // 0x8042BC58: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8042BC5C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8042BC60: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8042BC64: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8042BC68: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8042BC6C: add.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8042BC70: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8042BC74: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8042BC78: c.lt.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl < ctx->f20.fl;
    // 0x8042BC7C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8042BC80: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8042BC84: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8042BC88: nop

    // 0x8042BC8C: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x8042BC90: bc1f        L_8042BC9C
    if (!c1cs) {
        // 0x8042BC94: sh          $t5, -0x10($s0)
        MEM_H(-0X10, ctx->r16) = ctx->r13;
            goto L_8042BC9C;
    }
    // 0x8042BC94: sh          $t5, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r13;
    // 0x8042BC98: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
L_8042BC9C:
    // 0x8042BC9C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8042BCA0: lw          $t6, 0x4C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4C);
    // 0x8042BCA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042BCA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042BCAC: add.s       $f28, $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f22.fl;
    // 0x8042BCB0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3020) << 16);
    // 0x8042BCB4: lwc1        $f22, -0x2740($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3020));
    // 0x8042BCB8: add.s       $f24, $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x8042BCBC: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8042BCC0: mul.s       $f26, $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x8042BCC4: bne         $at, $zero, L_8042BC0C
    if (ctx->r1 != 0) {
        // 0x8042BCC8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8042BC0C;
    }
    // 0x8042BCC8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8042BCCC:
    // 0x8042BCCC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8042BCD0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8042BCD4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8042BCD8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8042BCDC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8042BCE0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8042BCE4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8042BCE8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8042BCEC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8042BCF0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8042BCF4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8042BCF8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8042BCFC: jr          $ra
    // 0x8042BD00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8042BD00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_804C3A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3A40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C3A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3A48: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x804C3A4C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804C3A50: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804C3A54: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x804C3A58: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x804C3A5C: lw          $t8, 0x300($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X300);
    // 0x804C3A60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C3A64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C3A68: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x804C3A6C: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x804C3A70: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x804C3A74: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x804C3A78: lw          $t1, 0x168($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X168);
    // 0x804C3A7C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804C3A80: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x804C3A84: jal         0x80077338
    // 0x804C3A88: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x804C3A88: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x804C3A8C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x804C3A90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804C3A94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804C3A98: jal         0x8007711C
    // 0x804C3A9C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x804C3A9C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x804C3AA0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x804C3AA4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x804C3AA8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804C3AAC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x804C3AB0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804C3AB4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804C3AB8: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x804C3ABC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x804C3AC0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x804C3AC4: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x804C3AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3ACC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C3AD0: jr          $ra
    // 0x804C3AD4: nop

    return;
    // 0x804C3AD4: nop

;}
RECOMP_FUNC void func_800356E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800356E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800356EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800356F0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800356F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800356F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800356FC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80035700: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80035704: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x80035708: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x8003570C: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x80035710: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80035714: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80035718: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8003571C: lw          $t9, 0x38($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X38);
    // 0x80035720: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80035724: beq         $t8, $zero, L_80035770
    if (ctx->r24 == 0) {
        // 0x80035728: sw          $t9, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r25;
            goto L_80035770;
    }
    // 0x80035728: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x8003572C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80035730: jal         0x80035640
    // 0x80035734: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80035640(rdram, ctx);
        goto after_0;
    // 0x80035734: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80035738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003573C: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x80035740: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035744: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80035748: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003574C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80035750: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80035754: nop

    // 0x80035758: bc1f        L_80035768
    if (!c1cs) {
        // 0x8003575C: nop
    
            goto L_80035768;
    }
    // 0x8003575C: nop

    // 0x80035760: sh          $v1, 0x148($a2)
    MEM_H(0X148, ctx->r6) = ctx->r3;
    // 0x80035764: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
L_80035768:
    // 0x80035768: b           L_8003578C
    // 0x8003576C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8003578C;
    // 0x8003576C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80035770:
    // 0x80035770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80035774: jal         0x80035694
    // 0x80035778: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80035694(rdram, ctx);
        goto after_1;
    // 0x80035778: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003577C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035780: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80035784: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80035788: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
L_8003578C:
    // 0x8003578C: swc1        $f0, 0x14C($a2)
    MEM_W(0X14C, ctx->r6) = ctx->f0.u32l;
    // 0x80035790: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80035794: beql        $t2, $zero, L_80035828
    if (ctx->r10 == 0) {
        // 0x80035798: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035828;
    }
    goto skip_0;
    // 0x80035798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003579C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800357A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800357A4: beql        $v0, $zero, L_800357CC
    if (ctx->r2 == 0) {
        // 0x800357A8: lwc1        $f8, 0xC($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
            goto L_800357CC;
    }
    goto skip_1;
    // 0x800357A8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x800357AC: beq         $v0, $v1, L_800357F4
    if (ctx->r2 == ctx->r3) {
        // 0x800357B0: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800357F4;
    }
    // 0x800357B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800357B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800357B8: beql        $v0, $at, L_80035824
    if (ctx->r2 == ctx->r1) {
        // 0x800357BC: sw          $v1, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r3;
            goto L_80035824;
    }
    goto skip_2;
    // 0x800357BC: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    skip_2:
    // 0x800357C0: b           L_80035828
    // 0x800357C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035828;
    // 0x800357C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800357C8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
L_800357CC:
    // 0x800357CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800357D0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800357D4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800357D8: nop

    // 0x800357DC: bc1f        L_800357EC
    if (!c1cs) {
        // 0x800357E0: nop
    
            goto L_800357EC;
    }
    // 0x800357E0: nop

    // 0x800357E4: b           L_80035824
    // 0x800357E8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
        goto L_80035824;
    // 0x800357E8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800357EC:
    // 0x800357EC: b           L_80035824
    // 0x800357F0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
        goto L_80035824;
    // 0x800357F0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_800357F4:
    // 0x800357F4: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800357F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800357FC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80035800: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80035804: nop

    // 0x80035808: bc1f        L_80035818
    if (!c1cs) {
        // 0x8003580C: nop
    
            goto L_80035818;
    }
    // 0x8003580C: nop

    // 0x80035810: b           L_80035824
    // 0x80035814: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
        goto L_80035824;
    // 0x80035814: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_80035818:
    // 0x80035818: b           L_80035824
    // 0x8003581C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
        goto L_80035824;
    // 0x8003581C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80035820: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_80035824:
    // 0x80035824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035828:
    // 0x80035828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003582C: jr          $ra
    // 0x80035830: nop

    return;
    // 0x80035830: nop

;}
RECOMP_FUNC void func_8053348C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053348C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80533490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80533494: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80533498: jal         0x800692D4
    // 0x8053349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x8053349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805334A0: jal         0x80532CFC
    // 0x805334A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532CFC(rdram, ctx);
        goto after_1;
    // 0x805334A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805334A8: jal         0x805332DC
    // 0x805334AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805332DC(rdram, ctx);
        goto after_2;
    // 0x805334AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805334B0: jal         0x80533170
    // 0x805334B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533170(rdram, ctx);
        goto after_3;
    // 0x805334B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805334B8: jal         0x80532B50
    // 0x805334BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532B50(rdram, ctx);
        goto after_4;
    // 0x805334BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805334C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805334C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805334C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805334CC: jr          $ra
    // 0x805334D0: nop

    return;
    // 0x805334D0: nop

;}
RECOMP_FUNC void func_800016A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016A8: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800016AC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800016B0: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x800016B4: addiu       $s4, $s4, 0x4D10
    ctx->r20 = ADD32(ctx->r20, 0X4D10);
    // 0x800016B8: lb          $t0, 0x1($s4)
    ctx->r8 = MEM_B(ctx->r20, 0X1);
    // 0x800016BC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800016C0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800016C4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800016C8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800016CC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800016D0: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800016D4: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800016D8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800016DC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800016E0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800016E4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800016E8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800016EC: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800016F0: bne         $t0, $zero, L_80001760
    if (ctx->r8 != 0) {
        // 0x800016F4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80001760;
    }
    // 0x800016F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800016F8: lw          $a0, 0x1DAC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1DAC);
    // 0x800016FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80001700: blez        $a0, L_80001758
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80001704: nop
    
            goto L_80001758;
    }
    // 0x80001704: nop

    // 0x80001708: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000170C: lw          $t6, 0x14($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X14);
    // 0x80001710: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80001714: mflo        $t7
    ctx->r15 = lo;
    // 0x80001718: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8000171C: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
L_80001720:
    // 0x80001720: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80001724: addu        $t2, $a1, $s2
    ctx->r10 = ADD32(ctx->r5, ctx->r18);
    // 0x80001728: srl         $t1, $t9, 31
    ctx->r9 = S32(U32(ctx->r25) >> 31);
    // 0x8000172C: beql        $t1, $zero, L_80001748
    if (ctx->r9 == 0) {
        // 0x80001730: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80001748;
    }
    goto skip_0;
    // 0x80001730: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80001734: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80001738: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8000173C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80001740: sb          $s1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r17;
    // 0x80001744: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80001748:
    // 0x80001748: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000174C: bne         $at, $zero, L_80001720
    if (ctx->r1 != 0) {
        // 0x80001750: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80001720;
    }
    // 0x80001750: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80001754: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80001758:
    // 0x80001758: b           L_80001868
    // 0x8000175C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80001868;
    // 0x8000175C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80001760:
    // 0x80001760: blez        $t0, L_800017F0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80001764: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800017F0;
    }
    // 0x80001764: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80001768: lw          $a0, 0x1DAC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1DAC);
    // 0x8000176C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
L_80001770:
    // 0x80001770: blez        $a0, L_800017D4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80001774: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800017D4;
    }
    // 0x80001774: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80001778: multu       $a0, $s6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000177C: lw          $t5, 0x14($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X14);
    // 0x80001780: mflo        $t3
    ctx->r11 = lo;
    // 0x80001784: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80001788: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
L_8000178C:
    // 0x8000178C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80001790: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80001794: srl         $t6, $t7, 31
    ctx->r14 = S32(U32(ctx->r15) >> 31);
    // 0x80001798: beql        $t6, $zero, L_800017C8
    if (ctx->r14 == 0) {
        // 0x8000179C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800017C8;
    }
    goto skip_1;
    // 0x8000179C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800017A0: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800017A4: addu        $t1, $a1, $s2
    ctx->r9 = ADD32(ctx->r5, ctx->r18);
    // 0x800017A8: srl         $t9, $t8, 5
    ctx->r25 = S32(U32(ctx->r24) >> 5);
    // 0x800017AC: bnel        $s3, $t9, L_800017C8
    if (ctx->r19 != ctx->r25) {
        // 0x800017B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800017C8;
    }
    goto skip_2;
    // 0x800017B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800017B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800017B8: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800017BC: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800017C0: sb          $s1, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r17;
    // 0x800017C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800017C8:
    // 0x800017C8: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800017CC: bne         $at, $zero, L_8000178C
    if (ctx->r1 != 0) {
        // 0x800017D0: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_8000178C;
    }
    // 0x800017D0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_800017D4:
    // 0x800017D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800017D8: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x800017DC: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800017E0: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800017E4: bne         $at, $zero, L_80001770
    if (ctx->r1 != 0) {
        // 0x800017E8: nop
    
            goto L_80001770;
    }
    // 0x800017E8: nop

    // 0x800017EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800017F0:
    // 0x800017F0: lw          $a0, 0x1DAC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X1DAC);
    // 0x800017F4: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x800017F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800017FC: blezl       $a0, L_8000186C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80001800: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_8000186C;
    }
    goto skip_3;
    // 0x80001800: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    skip_3:
    // 0x80001804: multu       $a0, $s6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001808: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x8000180C: mflo        $t2
    ctx->r10 = lo;
    // 0x80001810: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80001814: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
L_80001818:
    // 0x80001818: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000181C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80001820: srl         $t7, $t5, 31
    ctx->r15 = S32(U32(ctx->r13) >> 31);
    // 0x80001824: beql        $t7, $zero, L_80001858
    if (ctx->r15 == 0) {
        // 0x80001828: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80001858;
    }
    goto skip_4;
    // 0x80001828: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8000182C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80001830: addu        $t9, $a1, $s2
    ctx->r25 = ADD32(ctx->r5, ctx->r18);
    // 0x80001834: srl         $t8, $t6, 5
    ctx->r24 = S32(U32(ctx->r14) >> 5);
    // 0x80001838: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000183C: bnel        $at, $zero, L_80001858
    if (ctx->r1 != 0) {
        // 0x80001840: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80001858;
    }
    goto skip_5;
    // 0x80001840: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x80001844: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80001848: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8000184C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80001850: sb          $s1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r17;
    // 0x80001854: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80001858:
    // 0x80001858: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000185C: bne         $at, $zero, L_80001818
    if (ctx->r1 != 0) {
        // 0x80001860: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_80001818;
    }
    // 0x80001860: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80001864: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80001868:
    // 0x80001868: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8000186C:
    // 0x8000186C: lui         $t1, 0x200
    ctx->r9 = S32(0X200 << 16);
    // 0x80001870: ori         $t1, $t1, 0x940
    ctx->r9 = ctx->r9 | 0X940;
    // 0x80001874: addiu       $t2, $zero, 0x340
    ctx->r10 = ADD32(0, 0X340);
    // 0x80001878: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8000187C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80001880: lb          $t3, 0x1($s4)
    ctx->r11 = MEM_B(ctx->r20, 0X1);
    // 0x80001884: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80001888: addiu       $s7, $zero, 0xD0
    ctx->r23 = ADD32(0, 0XD0);
    // 0x8000188C: blez        $t3, L_80001A0C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80001890: sll         $t4, $s3, 2
        ctx->r12 = S32(ctx->r19 << 2);
            goto L_80001A0C;
    }
    // 0x80001890: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
L_80001894:
    // 0x80001894: subu        $t4, $t4, $s3
    ctx->r12 = SUB32(ctx->r12, ctx->r19);
    // 0x80001898: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8000189C: subu        $t4, $t4, $s3
    ctx->r12 = SUB32(ctx->r12, ctx->r19);
    // 0x800018A0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800018A4: subu        $t4, $t4, $s3
    ctx->r12 = SUB32(ctx->r12, ctx->r19);
    // 0x800018A8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800018AC: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x800018B0: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x800018B4: lbu         $t6, 0x19($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X19);
    // 0x800018B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800018BC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800018C0: beq         $t6, $zero, L_800018E0
    if (ctx->r14 == 0) {
        // 0x800018C4: sw          $t6, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r14;
            goto L_800018E0;
    }
    // 0x800018C4: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x800018C8: sll         $a2, $s3, 16
    ctx->r6 = S32(ctx->r19 << 16);
    // 0x800018CC: sll         $a3, $s6, 16
    ctx->r7 = S32(ctx->r22 << 16);
    // 0x800018D0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800018D4: jal         0x80001470
    // 0x800018D8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    func_80001470(rdram, ctx);
        goto after_0;
    // 0x800018D8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_0:
    // 0x800018DC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_800018E0:
    // 0x800018E0: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800018E4: beq         $at, $zero, L_80001970
    if (ctx->r1 == 0) {
        // 0x800018E8: addiu       $t8, $sp, 0x84
        ctx->r24 = ADD32(ctx->r29, 0X84);
            goto L_80001970;
    }
    // 0x800018E8: addiu       $t8, $sp, 0x84
    ctx->r24 = ADD32(ctx->r29, 0X84);
    // 0x800018EC: addu        $s0, $s1, $t8
    ctx->r16 = ADD32(ctx->r17, ctx->r24);
L_800018F0:
    // 0x800018F0: lw          $t9, 0x1DAC($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X1DAC);
    // 0x800018F4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800018F8: lw          $v1, 0x14($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X14);
    // 0x800018FC: multu       $s6, $t9
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001900: sll         $t1, $v0, 5
    ctx->r9 = S32(ctx->r2 << 5);
    // 0x80001904: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80001908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000190C: mflo        $t0
    ctx->r8 = lo;
    // 0x80001910: sll         $t3, $t0, 5
    ctx->r11 = S32(ctx->r8 << 5);
    // 0x80001914: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80001918: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x8000191C: srl         $t7, $t5, 5
    ctx->r15 = S32(U32(ctx->r13) >> 5);
    // 0x80001920: bnel        $s3, $t7, L_80001974
    if (ctx->r19 != ctx->r15) {
        // 0x80001924: lw          $t2, 0x78($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X78);
            goto L_80001974;
    }
    goto skip_6;
    // 0x80001924: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    skip_6:
    // 0x80001928: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000192C: lw          $t1, 0x2A2C($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X2A2C);
    // 0x80001930: addu        $t6, $v0, $t0
    ctx->r14 = ADD32(ctx->r2, ctx->r8);
    // 0x80001934: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80001938: addu        $a1, $t8, $v1
    ctx->r5 = ADD32(ctx->r24, ctx->r3);
    // 0x8000193C: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x80001940: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80001944: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80001948: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x8000194C: mflo        $t9
    ctx->r25 = lo;
    // 0x80001950: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x80001954: jal         0x80001B28
    // 0x80001958: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_80001B28(rdram, ctx);
        goto after_1;
    // 0x80001958: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_1:
    // 0x8000195C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80001960: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80001964: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80001968: bne         $at, $zero, L_800018F0
    if (ctx->r1 != 0) {
        // 0x8000196C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800018F0;
    }
    // 0x8000196C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80001970:
    // 0x80001970: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
L_80001974:
    // 0x80001974: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80001978: beql        $t2, $zero, L_800019F4
    if (ctx->r10 == 0) {
        // 0x8000197C: lb          $t8, 0x1($s4)
        ctx->r24 = MEM_B(ctx->r20, 0X1);
            goto L_800019F4;
    }
    goto skip_7;
    // 0x8000197C: lb          $t8, 0x1($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X1);
    skip_7:
    // 0x80001980: lw          $t4, 0x118($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X118);
    // 0x80001984: sll         $s0, $s6, 16
    ctx->r16 = S32(ctx->r22 << 16);
    // 0x80001988: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8000198C: bne         $t4, $zero, L_8000199C
    if (ctx->r12 != 0) {
        // 0x80001990: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8000199C;
    }
    // 0x80001990: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80001994: lw          $t5, 0x11C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X11C);
    // 0x80001998: beq         $t5, $zero, L_800019AC
    if (ctx->r13 == 0) {
        // 0x8000199C: sll         $a1, $fp, 1
        ctx->r5 = S32(ctx->r30 << 1);
            goto L_800019AC;
    }
L_8000199C:
    // 0x8000199C: sll         $a1, $fp, 1
    ctx->r5 = S32(ctx->r30 << 1);
    // 0x800019A0: jal         0x80000E24
    // 0x800019A4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80000E24(rdram, ctx);
        goto after_2;
    // 0x800019A4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x800019A8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_800019AC:
    // 0x800019AC: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x800019B0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800019B4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800019B8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800019BC: jal         0x8000157C
    // 0x800019C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8000157C(rdram, ctx);
        goto after_3;
    // 0x800019C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x800019C4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800019C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800019CC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800019D0: lb          $t6, 0x1D($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X1D);
    // 0x800019D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800019D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800019DC: beql        $t6, $at, L_800019F4
    if (ctx->r14 == ctx->r1) {
        // 0x800019E0: lb          $t8, 0x1($s4)
        ctx->r24 = MEM_B(ctx->r20, 0X1);
            goto L_800019F4;
    }
    goto skip_8;
    // 0x800019E0: lb          $t8, 0x1($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X1);
    skip_8:
    // 0x800019E4: jal         0x80000EF4
    // 0x800019E8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_80000EF4(rdram, ctx);
        goto after_4;
    // 0x800019E8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x800019EC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800019F0: lb          $t8, 0x1($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X1);
L_800019F4:
    // 0x800019F4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800019F8: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x800019FC: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80001A00: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80001A04: bnel        $at, $zero, L_80001894
    if (ctx->r1 != 0) {
        // 0x80001A08: sll         $t4, $s3, 2
        ctx->r12 = S32(ctx->r19 << 2);
            goto L_80001894;
    }
    goto skip_9;
    // 0x80001A08: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    skip_9:
L_80001A0C:
    // 0x80001A0C: sll         $t9, $fp, 1
    ctx->r25 = S32(ctx->r30 << 1);
    // 0x80001A10: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80001A14: addiu       $s7, $zero, 0xD0
    ctx->r23 = ADD32(0, 0XD0);
    // 0x80001A18: beq         $at, $zero, L_80001A88
    if (ctx->r1 == 0) {
        // 0x80001A1C: sw          $t9, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r25;
            goto L_80001A88;
    }
    // 0x80001A1C: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80001A20: addiu       $t1, $sp, 0x84
    ctx->r9 = ADD32(ctx->r29, 0X84);
    // 0x80001A24: addu        $s0, $s1, $t1
    ctx->r16 = ADD32(ctx->r17, ctx->r9);
    // 0x80001A28: addu        $s3, $s2, $t1
    ctx->r19 = ADD32(ctx->r18, ctx->r9);
L_80001A2C:
    // 0x80001A2C: lw          $t2, 0x1DAC($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X1DAC);
    // 0x80001A30: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80001A34: lw          $t8, 0x2A2C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X2A2C);
    // 0x80001A38: multu       $s6, $t2
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001A3C: lw          $t7, 0x14($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X14);
    // 0x80001A40: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x80001A44: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80001A48: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80001A4C: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x80001A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80001A54: mflo        $t4
    ctx->r12 = lo;
    // 0x80001A58: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x80001A5C: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x80001A60: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001A64: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x80001A68: mflo        $t6
    ctx->r14 = lo;
    // 0x80001A6C: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x80001A70: jal         0x80001B28
    // 0x80001A74: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_80001B28(rdram, ctx);
        goto after_5;
    // 0x80001A74: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_5:
    // 0x80001A78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001A7C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80001A80: bne         $at, $zero, L_80001A2C
    if (ctx->r1 != 0) {
        // 0x80001A84: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_80001A2C;
    }
    // 0x80001A84: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_80001A88:
    // 0x80001A88: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80001A8C: lui         $at, 0xD00
    ctx->r1 = S32(0XD00 << 16);
    // 0x80001A90: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x80001A94: sra         $t1, $t9, 4
    ctx->r9 = S32(SIGNED(ctx->r25) >> 4);
    // 0x80001A98: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80001A9C: sll         $t4, $t2, 16
    ctx->r12 = S32(ctx->r10 << 16);
    // 0x80001AA0: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x80001AA4: lui         $t7, 0x940
    ctx->r15 = S32(0X940 << 16);
    // 0x80001AA8: ori         $t7, $t7, 0xAE0
    ctx->r15 = ctx->r15 | 0XAE0;
    // 0x80001AAC: ori         $t5, $t3, 0x3C0
    ctx->r13 = ctx->r11 | 0X3C0;
    // 0x80001AB0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80001AB4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80001AB8: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80001ABC: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x80001AC0: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80001AC4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80001AC8: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x80001ACC: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80001AD0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001AD4: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80001AD8: ori         $t3, $t4, 0x3C0
    ctx->r11 = ctx->r12 | 0X3C0;
    // 0x80001ADC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80001AE0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80001AE4: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x80001AE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80001AEC: addiu       $v0, $s5, 0x8
    ctx->r2 = ADD32(ctx->r21, 0X8);
    // 0x80001AF0: addu        $t7, $t5, $at
    ctx->r15 = ADD32(ctx->r13, ctx->r1);
    // 0x80001AF4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80001AF8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80001AFC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80001B00: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80001B04: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80001B08: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80001B0C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80001B10: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80001B14: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80001B18: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80001B1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80001B20: jr          $ra
    // 0x80001B24: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80001B24: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_805AD70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD70C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x805AD710: beql        $at, $zero, L_805AD724
    if (ctx->r1 == 0) {
        // 0x805AD714: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_805AD724;
    }
    goto skip_0;
    // 0x805AD714: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x805AD718: jr          $ra
    // 0x805AD71C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x805AD71C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x805AD720: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_805AD724:
    // 0x805AD724: beq         $at, $zero, L_805AD760
    if (ctx->r1 == 0) {
        // 0x805AD728: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_805AD760;
    }
    // 0x805AD728: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x805AD72C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x805AD730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AD734: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805AD738: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x805AD73C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805AD740: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x805AD744: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x805AD748: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x805AD74C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805AD750: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805AD754: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x805AD758: jr          $ra
    // 0x805AD75C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x805AD75C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_805AD760:
    // 0x805AD760: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x805AD764: beq         $at, $zero, L_805AD77C
    if (ctx->r1 == 0) {
        // 0x805AD768: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_805AD77C;
    }
    // 0x805AD768: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x805AD76C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AD770: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805AD774: jr          $ra
    // 0x805AD778: nop

    return;
    // 0x805AD778: nop

L_805AD77C:
    // 0x805AD77C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x805AD780: beq         $at, $zero, L_805AD7C0
    if (ctx->r1 == 0) {
        // 0x805AD784: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_805AD7C0;
    }
    // 0x805AD784: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805AD788: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x805AD78C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x805AD790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AD794: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805AD798: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805AD79C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805AD7A0: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x805AD7A4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x805AD7A8: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x805AD7AC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805AD7B0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805AD7B4: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805AD7B8: jr          $ra
    // 0x805AD7BC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x805AD7BC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_805AD7C0:
    // 0x805AD7C0: jr          $ra
    // 0x805AD7C4: nop

    return;
    // 0x805AD7C4: nop

;}
RECOMP_FUNC void func_80521F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521F5C: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80521F60: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(315, 0X26C) << 16);
    // 0x80521F64: addiu       $t8, $t8, 0x20AC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(315, 0X26C));
    // 0x80521F68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80521F6C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80521F70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80521F74: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80521F78: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80521F7C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80521F80: beql        $v1, $zero, L_80521FB4
    if (ctx->r3 == 0) {
        // 0x80521F84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80521FB4;
    }
    goto skip_0;
    // 0x80521F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80521F88: jalr        $v1
    // 0x80521F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80521F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80521F90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80521F94: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80521F98: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x80521F9C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80521FA0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80521FA4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80521FA8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80521FAC: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x80521FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80521FB4:
    // 0x80521FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521FB8: jr          $ra
    // 0x80521FBC: nop

    return;
    // 0x80521FBC: nop

;}
RECOMP_FUNC void func_80046AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046AFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80046B08: jal         0x80045B2C
    // 0x80046B0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80045B2C(rdram, ctx);
        goto after_0;
    // 0x80046B0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80046B10: bne         $v0, $zero, L_80046B30
    if (ctx->r2 != 0) {
        // 0x80046B14: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80046B30;
    }
    // 0x80046B14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80046B18: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046B1C: addiu       $a0, $a0, 0x770
    ctx->r4 = ADD32(ctx->r4, 0X770);
    // 0x80046B20: jal         0x80071380
    // 0x80046B24: addiu       $a1, $zero, 0x668
    ctx->r5 = ADD32(0, 0X668);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80046B24: addiu       $a1, $zero, 0x668
    ctx->r5 = ADD32(0, 0X668);
    after_1:
    // 0x80046B28: b           L_80046B60
    // 0x80046B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046B60;
    // 0x80046B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046B30:
    // 0x80046B30: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80046B34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80046B38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80046B3C: jal         0x80046AC0
    // 0x80046B40: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80046AC0(rdram, ctx);
        goto after_2;
    // 0x80046B40: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x80046B44: beq         $v0, $zero, L_80046B5C
    if (ctx->r2 == 0) {
        // 0x80046B48: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80046B5C;
    }
    // 0x80046B48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80046B4C: jal         0x80045AE8
    // 0x80046B50: nop

    func_80045AE8(rdram, ctx);
        goto after_3;
    // 0x80046B50: nop

    after_3:
    // 0x80046B54: b           L_80046B60
    // 0x80046B58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046B60;
    // 0x80046B58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046B5C:
    // 0x80046B5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80046B60:
    // 0x80046B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80046B68: jr          $ra
    // 0x80046B6C: nop

    return;
    // 0x80046B6C: nop

;}
RECOMP_FUNC void func_807C6B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C6B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C6B08: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C6B0C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807C6B10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807C6B14: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x807C6B18: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807C6B1C: sb          $t6, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r14;
    // 0x807C6B20: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x807C6B24: lwc1        $f4, 0x30($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X30);
    // 0x807C6B28: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807C6B2C: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x807C6B30: lwc1        $f6, 0x34($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X34);
    // 0x807C6B34: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x807C6B38: lbu         $t0, 0x5($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X5);
    // 0x807C6B3C: bnel        $t0, $zero, L_807C6BF4
    if (ctx->r8 != 0) {
        // 0x807C6B40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C6BF4;
    }
    goto skip_0;
    // 0x807C6B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807C6B44: lbu         $t1, 0x6($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X6);
    // 0x807C6B48: bnel        $t1, $zero, L_807C6BF4
    if (ctx->r9 != 0) {
        // 0x807C6B4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C6BF4;
    }
    goto skip_1;
    // 0x807C6B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x807C6B50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807C6B54: jal         0x8004700C
    // 0x807C6B58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807C6B58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C6B5C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807C6B60: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807C6B64: beq         $v0, $zero, L_807C6BF0
    if (ctx->r2 == 0) {
        // 0x807C6B68: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_807C6BF0;
    }
    // 0x807C6B68: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807C6B6C: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x807C6B70: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x807C6B74: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x807C6B78: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x807C6B7C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x807C6B80: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x807C6B84: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x807C6B88: bne         $t4, $at, L_807C6BF0
    if (ctx->r12 != ctx->r1) {
        // 0x807C6B8C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_807C6BF0;
    }
    // 0x807C6B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807C6B90: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    // 0x807C6B94: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x807C6B98: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x807C6B9C: jal         0x8005A994
    // 0x807C6BA0: lw          $a0, 0x478($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X478);
    func_8005A994(rdram, ctx);
        goto after_1;
    // 0x807C6BA0: lw          $a0, 0x478($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X478);
    after_1:
    // 0x807C6BA4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807C6BA8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807C6BAC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807C6BB0: lw          $t5, 0x478($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X478);
    // 0x807C6BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807C6BB8: swc1        $f12, 0xB0($t5)
    MEM_W(0XB0, ctx->r13) = ctx->f12.u32l;
    // 0x807C6BBC: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x807C6BC0: lwc1        $f8, 0xB0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x807C6BC4: jal         0x8006CA74
    // 0x807C6BC8: swc1        $f8, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f8.u32l;
    func_8006CA74(rdram, ctx);
        goto after_2;
    // 0x807C6BC8: swc1        $f8, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f8.u32l;
    after_2:
    // 0x807C6BCC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x807C6BD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807C6BD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807C6BD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x807C6BDC: jal         0x807C6C84
    // 0x807C6BE0: sb          $zero, 0x165($t7)
    MEM_B(0X165, ctx->r15) = 0;
    func_807C6C84(rdram, ctx);
        goto after_3;
    // 0x807C6BE0: sb          $zero, 0x165($t7)
    MEM_B(0X165, ctx->r15) = 0;
    after_3:
    // 0x807C6BE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807C6BE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807C6BEC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_807C6BF0:
    // 0x807C6BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C6BF4:
    // 0x807C6BF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C6BF8: jr          $ra
    // 0x807C6BFC: nop

    return;
    // 0x807C6BFC: nop

;}
RECOMP_FUNC void func_804608BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804608BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804608C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804608C4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804608C8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x804608CC: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x804608D0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x804608D4: lb          $t8, 0x2($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X2);
    // 0x804608D8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x804608DC: nop

    // 0x804608E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804608E4: jal         0x804608AC
    // 0x804608E8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_804608AC(rdram, ctx);
        goto after_0;
    // 0x804608E8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x804608EC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804608F0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x804608F4: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x804608F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804608FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80460900: jr          $ra
    // 0x80460904: nop

    return;
    // 0x80460904: nop

;}
RECOMP_FUNC void func_8070CA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CA34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070CA38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070CA3C: jal         0x8070C934
    // 0x8070CA40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8070C934(rdram, ctx);
        goto after_0;
    // 0x8070CA40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8070CA44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8070CA48: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD4C) << 16);
    // 0x8070CA4C: lwc1        $f6, -0x2C24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD4C));
    // 0x8070CA50: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8070CA54: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8070CA58: nop

    // 0x8070CA5C: bc1fl       L_8070CA84
    if (!c1cs) {
        // 0x8070CA60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8070CA84;
    }
    goto skip_0;
    // 0x8070CA60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8070CA64: jal         0x8005FCA8
    // 0x8070CA68: nop

    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x8070CA68: nop

    after_1:
    // 0x8070CA6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8070CA70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070CA74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8070CA78: jal         0x8070D208
    // 0x8070CA7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8070D208(rdram, ctx);
        goto after_2;
    // 0x8070CA7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8070CA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8070CA84:
    // 0x8070CA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070CA88: jr          $ra
    // 0x8070CA8C: nop

    return;
    // 0x8070CA8C: nop

;}
RECOMP_FUNC void func_807BC1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC1CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC1D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC1D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807BC1D8: jal         0x80046E88
    // 0x807BC1DC: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x807BC1DC: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x807BC1E0: beq         $v0, $zero, L_807BC22C
    if (ctx->r2 == 0) {
        // 0x807BC1E4: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_807BC22C;
    }
    // 0x807BC1E4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807BC1E8: lw          $a0, 0x16C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X16C);
    // 0x807BC1EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC1F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807BC1F4: lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X10);
    // 0x807BC1F8: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x807BC1FC: beq         $v1, $zero, L_807BC21C
    if (ctx->r3 == 0) {
        // 0x807BC200: addiu       $v1, $v1, -0x2
        ctx->r3 = ADD32(ctx->r3, -0X2);
            goto L_807BC21C;
    }
    // 0x807BC200: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x807BC204: bgez        $v1, L_807BC214
    if (SIGNED(ctx->r3) >= 0) {
        // 0x807BC208: nop
    
            goto L_807BC214;
    }
    // 0x807BC208: nop

    // 0x807BC20C: b           L_807BC23C
    // 0x807BC210: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
        goto L_807BC23C;
    // 0x807BC210: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
L_807BC214:
    // 0x807BC214: b           L_807BC23C
    // 0x807BC218: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
        goto L_807BC23C;
    // 0x807BC218: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_807BC21C:
    // 0x807BC21C: jal         0x807BC4D4
    // 0x807BC220: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_807BC4D4(rdram, ctx);
        goto after_1;
    // 0x807BC220: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x807BC224: b           L_807BC240
    // 0x807BC228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807BC240;
    // 0x807BC228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BC22C:
    // 0x807BC22C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807BC230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC234: jal         0x807BC4D4
    // 0x807BC238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807BC4D4(rdram, ctx);
        goto after_2;
    // 0x807BC238: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_807BC23C:
    // 0x807BC23C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BC240:
    // 0x807BC240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC244: jr          $ra
    // 0x807BC248: nop

    return;
    // 0x807BC248: nop

;}
RECOMP_FUNC void func_804BD064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD064: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x804BD068: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804BD06C: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BD070: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BD074: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804BD078: lw          $v0, 0x370($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X370);
    // 0x804BD07C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x804BD080: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BD084: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804BD088: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
    // 0x804BD08C: lwc1        $f16, 0x74($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X74);
    // 0x804BD090: jr          $ra
    // 0x804BD094: swc1        $f16, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x804BD094: swc1        $f16, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_807B8B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B8B74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807B8B78: bne         $a2, $at, L_807B8BAC
    if (ctx->r6 != ctx->r1) {
        // 0x807B8B7C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_807B8BAC;
    }
    // 0x807B8B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8B80: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x807B8B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B8B88: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x807B8B8C: bgez        $t7, L_807B8B9C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x807B8B90: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_807B8B9C;
    }
    // 0x807B8B90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x807B8B94: b           L_807B8BE4
    // 0x807B8B98: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_807B8BE4;
    // 0x807B8B98: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_807B8B9C:
    // 0x807B8B9C: jal         0x80067818
    // 0x807B8BA0: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x807B8BA0: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    after_0:
    // 0x807B8BA4: b           L_807B8BE8
    // 0x807B8BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B8BE8;
    // 0x807B8BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8BAC:
    // 0x807B8BAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x807B8BB0: bnel        $a2, $at, L_807B8BE8
    if (ctx->r6 != ctx->r1) {
        // 0x807B8BB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807B8BE8;
    }
    goto skip_0;
    // 0x807B8BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807B8BB8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x807B8BBC: addiu       $t2, $a1, -0x1
    ctx->r10 = ADD32(ctx->r5, -0X1);
    // 0x807B8BC0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x807B8BC4: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x807B8BC8: bne         $at, $zero, L_807B8BD8
    if (ctx->r1 != 0) {
        // 0x807B8BCC: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_807B8BD8;
    }
    // 0x807B8BCC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x807B8BD0: b           L_807B8BE4
    // 0x807B8BD4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
        goto L_807B8BE4;
    // 0x807B8BD4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_807B8BD8:
    // 0x807B8BD8: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x807B8BDC: jal         0x80067818
    // 0x807B8BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807B8BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_807B8BE4:
    // 0x807B8BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8BE8:
    // 0x807B8BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B8BEC: jr          $ra
    // 0x807B8BF0: nop

    return;
    // 0x807B8BF0: nop

;}
RECOMP_FUNC void func_807B5F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5F10: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x807B5F14: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807B5F18: lbu         $t6, -0x7204($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7204);
    // 0x807B5F1C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B5F20: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x807B5F24: or          $a0, $sp, $zero
    ctx->r4 = ctx->r29 | 0;
    // 0x807B5F28: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B5F2C: addiu       $a0, $a0, 0xA3
    ctx->r4 = ADD32(ctx->r4, 0XA3);
    // 0x807B5F30: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807B5F34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B5F38: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x807B5F3C: lui         $t9, 0x361
    ctx->r25 = S32(0X361 << 16);
    // 0x807B5F40: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x807B5F44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B5F48: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x807B5F4C: addiu       $t9, $t9, -0x2570
    ctx->r25 = ADD32(ctx->r25, -0X2570);
    // 0x807B5F50: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x807B5F54: addiu       $t8, $t7, 0xB1C
    ctx->r24 = ADD32(ctx->r15, 0XB1C);
    // 0x807B5F58: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B5F5C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B5F60: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B5F64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B5F68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B5F6C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x807B5F70: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x807B5F74: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x807B5F78: jal         0x800675D0
    // 0x807B5F7C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x807B5F7C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x807B5F80: or          $s4, $sp, $zero
    ctx->r20 = ctx->r29 | 0;
    // 0x807B5F84: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x807B5F88: addiu       $s4, $s4, 0x7B
    ctx->r20 = ADD32(ctx->r20, 0X7B);
    // 0x807B5F8C: srl         $s4, $s4, 3
    ctx->r20 = S32(U32(ctx->r20) >> 3);
    // 0x807B5F90: sll         $s4, $s4, 3
    ctx->r20 = S32(ctx->r20 << 3);
    // 0x807B5F94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B5F98: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x807B5F9C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x807B5FA0: jal         0x800675D0
    // 0x807B5FA4: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x807B5FA4: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    after_1:
    // 0x807B5FA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5FAC: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
L_807B5FB0:
    // 0x807B5FB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5FB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5FB8: jal         0x8005C27C
    // 0x807B5FBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x807B5FBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x807B5FC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5FC4: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5FC8: bnel        $at, $zero, L_807B5FB0
    if (ctx->r1 != 0) {
        // 0x807B5FCC: lw          $a0, 0xC($s3)
        ctx->r4 = MEM_W(ctx->r19, 0XC);
            goto L_807B5FB0;
    }
    goto skip_0;
    // 0x807B5FCC: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    skip_0:
    // 0x807B5FD0: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B5FD4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x807B5FD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B5FDC: jal         0x8005C27C
    // 0x807B5FE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x807B5FE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x807B5FE4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x807B5FE8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B5FEC: addiu       $s5, $zero, 0x1000
    ctx->r21 = ADD32(0, 0X1000);
    // 0x807B5FF0: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
L_807B5FF4:
    // 0x807B5FF4: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x807B5FF8: lhu         $s0, 0x0($t1)
    ctx->r16 = MEM_HU(ctx->r9, 0X0);
    // 0x807B5FFC: sll         $a2, $s1, 3
    ctx->r6 = S32(ctx->r17 << 3);
    // 0x807B6000: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x807B6004: bne         $s5, $s0, L_807B6018
    if (ctx->r21 != ctx->r16) {
        // 0x807B6008: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_807B6018;
    }
    // 0x807B6008: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x807B600C: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x807B6010: b           L_807B6024
    // 0x807B6014: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
        goto L_807B6024;
    // 0x807B6014: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
L_807B6018:
    // 0x807B6018: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B601C: jal         0x8005C27C
    // 0x807B6020: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_4;
    // 0x807B6020: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_807B6024:
    // 0x807B6024: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807B6028: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
    // 0x807B602C: bnel        $at, $zero, L_807B5FF4
    if (ctx->r1 != 0) {
        // 0x807B6030: sll         $t0, $s1, 1
        ctx->r8 = S32(ctx->r17 << 1);
            goto L_807B5FF4;
    }
    goto skip_1;
    // 0x807B6030: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    skip_1:
    // 0x807B6034: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x807B6038: blez        $s2, L_807B6074
    if (SIGNED(ctx->r18) <= 0) {
        // 0x807B603C: sll         $t2, $s2, 1
        ctx->r10 = S32(ctx->r18 << 1);
            goto L_807B6074;
    }
    // 0x807B603C: sll         $t2, $s2, 1
    ctx->r10 = S32(ctx->r18 << 1);
L_807B6040:
    // 0x807B6040: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x807B6044: lhu         $s0, 0x0($t3)
    ctx->r16 = MEM_HU(ctx->r11, 0X0);
    // 0x807B6048: sll         $a2, $s2, 3
    ctx->r6 = S32(ctx->r18 << 3);
    // 0x807B604C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x807B6050: beq         $s0, $zero, L_807B6068
    if (ctx->r16 == 0) {
        // 0x807B6054: addiu       $a1, $zero, 0x3B
        ctx->r5 = ADD32(0, 0X3B);
            goto L_807B6068;
    }
    // 0x807B6054: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x807B6058: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B605C: jal         0x8005C27C
    // 0x807B6060: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B6060: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x807B6064: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_807B6068:
    // 0x807B6068: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x807B606C: bgtzl       $s2, L_807B6040
    if (SIGNED(ctx->r18) > 0) {
        // 0x807B6070: sll         $t2, $s2, 1
        ctx->r10 = S32(ctx->r18 << 1);
            goto L_807B6040;
    }
    goto skip_2;
    // 0x807B6070: sll         $t2, $s2, 1
    ctx->r10 = S32(ctx->r18 << 1);
    skip_2:
L_807B6074:
    // 0x807B6074: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x807B6078: lbu         $t4, -0x7204($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X7204);
    // 0x807B607C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807B6080: lbu         $t6, -0x7203($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7203);
    // 0x807B6084: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x807B6088: lui         $t9, 0x361
    ctx->r25 = S32(0X361 << 16);
    // 0x807B608C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x807B6090: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x807B6094: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x807B6098: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B609C: addiu       $t8, $t7, 0x9C0
    ctx->r24 = ADD32(ctx->r15, 0X9C0);
    // 0x807B60A0: addiu       $t9, $t9, -0x2570
    ctx->r25 = ADD32(ctx->r25, -0X2570);
    // 0x807B60A4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x807B60A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x807B60AC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x807B60B0: jal         0x800675D0
    // 0x807B60B4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_800675D0(rdram, ctx);
        goto after_6;
    // 0x807B60B4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x807B60B8: or          $s4, $sp, $zero
    ctx->r20 = ctx->r29 | 0;
    // 0x807B60BC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x807B60C0: addiu       $s4, $s4, 0x57
    ctx->r20 = ADD32(ctx->r20, 0X57);
    // 0x807B60C4: srl         $s4, $s4, 3
    ctx->r20 = S32(U32(ctx->r20) >> 3);
    // 0x807B60C8: sll         $s4, $s4, 3
    ctx->r20 = S32(ctx->r20 << 3);
    // 0x807B60CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B60D0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x807B60D4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x807B60D8: jal         0x800675D0
    // 0x807B60DC: lhu         $a2, 0x4($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X4);
    func_800675D0(rdram, ctx);
        goto after_7;
    // 0x807B60DC: lhu         $a2, 0x4($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X4);
    after_7:
    // 0x807B60E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B60E4: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
L_807B60E8:
    // 0x807B60E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B60EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B60F0: jal         0x8005C27C
    // 0x807B60F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x807B60F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_8:
    // 0x807B60F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B60FC: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B6100: bnel        $at, $zero, L_807B60E8
    if (ctx->r1 != 0) {
        // 0x807B6104: lw          $a0, 0xC($s3)
        ctx->r4 = MEM_W(ctx->r19, 0XC);
            goto L_807B60E8;
    }
    goto skip_3;
    // 0x807B6104: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    skip_3:
    // 0x807B6108: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B610C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B6110: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
L_807B6114:
    // 0x807B6114: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x807B6118: lhu         $s0, 0x0($t2)
    ctx->r16 = MEM_HU(ctx->r10, 0X0);
    // 0x807B611C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B6120: subu        $a2, $s1, $s2
    ctx->r6 = SUB32(ctx->r17, ctx->r18);
    // 0x807B6124: bne         $s5, $s0, L_807B6148
    if (ctx->r21 != ctx->r16) {
        // 0x807B6128: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_807B6148;
    }
    // 0x807B6128: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x807B612C: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x807B6130: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x807B6134: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B6138: jal         0x8005C27C
    // 0x807B613C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x807B613C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_9:
    // 0x807B6140: b           L_807B61A0
    // 0x807B6144: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
        goto L_807B61A0;
    // 0x807B6144: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
L_807B6148:
    // 0x807B6148: beq         $s2, $zero, L_807B6170
    if (ctx->r18 == 0) {
        // 0x807B614C: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_807B6170;
    }
    // 0x807B614C: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x807B6150: subu        $a2, $s1, $s2
    ctx->r6 = SUB32(ctx->r17, ctx->r18);
    // 0x807B6154: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x807B6158: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x807B615C: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B6160: jal         0x8005C27C
    // 0x807B6164: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_10;
    // 0x807B6164: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_10:
    // 0x807B6168: b           L_807B61A4
    // 0x807B616C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_807B61A4;
    // 0x807B616C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_807B6170:
    // 0x807B6170: beq         $v0, $zero, L_807B61A0
    if (ctx->r2 == 0) {
        // 0x807B6174: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_807B61A0;
    }
    // 0x807B6174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B6178: addiu       $s2, $s1, 0x1
    ctx->r18 = ADD32(ctx->r17, 0X1);
    // 0x807B617C: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B6180: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B6184: jal         0x8005C27C
    // 0x807B6188: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x807B6188: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_11:
    // 0x807B618C: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B6190: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x807B6194: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x807B6198: jal         0x8005C27C
    // 0x807B619C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_12;
    // 0x807B619C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
L_807B61A0:
    // 0x807B61A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_807B61A4:
    // 0x807B61A4: slti        $at, $s1, 0xE
    ctx->r1 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // 0x807B61A8: bnel        $at, $zero, L_807B6114
    if (ctx->r1 != 0) {
        // 0x807B61AC: sll         $t1, $s1, 1
        ctx->r9 = S32(ctx->r17 << 1);
            goto L_807B6114;
    }
    goto skip_4;
    // 0x807B61AC: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    skip_4:
    // 0x807B61B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B61B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B61B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B61BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B61C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B61C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B61C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B61CC: jr          $ra
    // 0x807B61D0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x807B61D0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8002BCA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BCA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BCAC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BCB0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002BCB4: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002BCB8: addiu       $a1, $a1, -0x29B8
    ctx->r5 = ADD32(ctx->r5, -0X29B8);
    // 0x8002BCBC: addiu       $t7, $t7, 0x1BC8
    ctx->r15 = ADD32(ctx->r15, 0X1BC8);
    // 0x8002BCC0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002BCC4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002BCC8: jal         0x80028118
    // 0x8002BCCC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002BCCC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002BCD0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BCD4: sw          $zero, 0x78($t8)
    MEM_W(0X78, ctx->r24) = 0;
    // 0x8002BCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BCDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BCE0: jr          $ra
    // 0x8002BCE4: nop

    return;
    // 0x8002BCE4: nop

;}
RECOMP_FUNC void func_80468264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80468268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046826C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80468270: jal         0x804686B4
    // 0x80468274: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_804686B4(rdram, ctx);
        goto after_0;
    // 0x80468274: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80468278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046827C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80468280: jr          $ra
    // 0x80468284: nop

    return;
    // 0x80468284: nop

;}
RECOMP_FUNC void func_80742DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742DD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742DD8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742DDC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742DE0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742DE4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742DE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742DEC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742DF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742DF4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742DF8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742DFC: jr          $ra
    // 0x80742E00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742E00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8041FFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FFDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041FFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041FFE4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8041FFE8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8041FFEC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8041FFF0: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(29, 0X3494) << 16);
    // 0x8041FFF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8041FFF8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8041FFFC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80420000: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80420004: lw          $t8, 0xAF4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(29, 0X3494));
    // 0x80420008: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042000C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80420010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80420014: jal         0x80048490
    // 0x80420018: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80420018: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042001C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80420020: jal         0x80048378
    // 0x80420024: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80420024: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80420028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80420030: jr          $ra
    // 0x80420034: nop

    return;
    // 0x80420034: nop

;}
RECOMP_FUNC void func_8046BC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BC90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8046BC94: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(138, 0X28F8) << 16);
    // 0x8046BC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BC9C: addiu       $t6, $t6, -0x3FC8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(138, 0X28F8));
    // 0x8046BCA0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8046BCA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046BCA8: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x8046BCAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8046BCB0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8046BCB4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8046BCB8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8046BCBC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8046BCC0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8046BCC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046BCC8: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8046BCCC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8046BCD0: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x8046BCD4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8046BCD8: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x8046BCDC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8046BCE0: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x8046BCE4: sw          $t0, 0xE90($v0)
    MEM_W(0XE90, ctx->r2) = ctx->r8;
    // 0x8046BCE8: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8046BCEC: sw          $t9, 0xE94($v0)
    MEM_W(0XE94, ctx->r2) = ctx->r25;
    // 0x8046BCF0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8046BCF4: sw          $t0, 0xE98($v0)
    MEM_W(0XE98, ctx->r2) = ctx->r8;
    // 0x8046BCF8: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8046BCFC: sw          $t9, 0xE9C($v0)
    MEM_W(0XE9C, ctx->r2) = ctx->r25;
    // 0x8046BD00: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x8046BD04: sw          $t0, 0xEA0($v0)
    MEM_W(0XEA0, ctx->r2) = ctx->r8;
    // 0x8046BD08: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x8046BD0C: swc1        $f4, 0xE08($v0)
    MEM_W(0XE08, ctx->r2) = ctx->f4.u32l;
    // 0x8046BD10: jal         0x8046BC34
    // 0x8046BD14: sw          $t9, 0xEA4($v0)
    MEM_W(0XEA4, ctx->r2) = ctx->r25;
    func_8046BC34(rdram, ctx);
        goto after_0;
    // 0x8046BD14: sw          $t9, 0xEA4($v0)
    MEM_W(0XEA4, ctx->r2) = ctx->r25;
    after_0:
    // 0x8046BD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BD1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8046BD20: jr          $ra
    // 0x8046BD24: nop

    return;
    // 0x8046BD24: nop

;}
RECOMP_FUNC void func_805AE754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE754: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE758: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE75C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE760: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE764: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE768: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE76C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE770: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE774: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE778: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE77C: jr          $ra
    // 0x805AE780: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE780: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F58: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80086F5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80086F60: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80086F64: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80086F68: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80086F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086F70: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80086F74: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80086F78: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80086F7C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80086F80:
    // 0x80086F80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086F84: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80086F88:
    // 0x80086F88: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80086F8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80086F90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80086F94: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80086F98: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80086F9C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x80086FA0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80086FA4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80086FA8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80086FAC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80086FB0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80086FB4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80086FB8: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80086FBC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80086FC0: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x80086FC4: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x80086FC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086FCC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80086FD0: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x80086FD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80086FD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80086FDC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80086FE0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80086FE4: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80086FE8: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80086FEC: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x80086FF0: bne         $a0, $t3, L_80086F88
    if (ctx->r4 != ctx->r11) {
        // 0x80086FF4: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_80086F88;
    }
    // 0x80086FF4: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80086FF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80086FFC: bne         $a2, $t4, L_80086F80
    if (ctx->r6 != ctx->r12) {
        // 0x80087000: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80086F80;
    }
    // 0x80087000: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80087004: jr          $ra
    // 0x80087008: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80087008: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8008700C: nop

;}
RECOMP_FUNC void func_805846FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805846FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584700: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584704: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584708: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058470C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584710: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584714: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584718: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058471C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584720: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584724: jr          $ra
    // 0x80584728: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584728: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80019BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019BA0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80019BA4: lw          $v1, -0x20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X20);
    // 0x80019BA8: bnel        $v1, $zero, L_80019BBC
    if (ctx->r3 != 0) {
        // 0x80019BAC: lw          $v0, 0x44($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X44);
            goto L_80019BBC;
    }
    goto skip_0;
    // 0x80019BAC: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    skip_0:
    // 0x80019BB0: jr          $ra
    // 0x80019BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80019BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80019BB8: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
L_80019BBC:
    // 0x80019BBC: beql        $v0, $zero, L_80019BD8
    if (ctx->r2 == 0) {
        // 0x80019BC0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80019BD8;
    }
    goto skip_1;
    // 0x80019BC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80019BC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80019BC8:
    // 0x80019BC8: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x80019BCC: bnel        $v0, $zero, L_80019BC8
    if (ctx->r2 != 0) {
        // 0x80019BD0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80019BC8;
    }
    goto skip_2;
    // 0x80019BD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_2:
    // 0x80019BD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80019BD8:
    // 0x80019BD8: jr          $ra
    // 0x80019BDC: nop

    return;
    // 0x80019BDC: nop

;}
RECOMP_FUNC void func_80062D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D14: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80062D18: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80062D1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80062D20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80062D24: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80062D28: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80062D2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80062D30: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80062D34: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80062D38: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80062D3C: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80062D40: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80062D44: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80062D48: jr          $ra
    // 0x80062D4C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80062D4C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80021444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002144C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80021450: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80021454: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80021458: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002145C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80021460: bne         $t6, $at, L_800214A0
    if (ctx->r14 != ctx->r1) {
        // 0x80021464: nop
    
            goto L_800214A0;
    }
    // 0x80021464: nop

    // 0x80021468: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8002146C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80021470: bne         $t7, $at, L_800214A0
    if (ctx->r15 != ctx->r1) {
        // 0x80021474: nop
    
            goto L_800214A0;
    }
    // 0x80021474: nop

    // 0x80021478: lwc1        $f4, 0xA8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x8002147C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80021480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021484: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80021488: nop

    // 0x8002148C: bc1f        L_800214DC
    if (!c1cs) {
        // 0x80021490: nop
    
            goto L_800214DC;
    }
    // 0x80021490: nop

    // 0x80021494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80021498: b           L_800214DC
    // 0x8002149C: nop

        goto L_800214DC;
    // 0x8002149C: nop

L_800214A0:
    // 0x800214A0: jal         0x80066E88
    // 0x800214A4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800214A4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_0:
    // 0x800214A8: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800214AC: lwc1        $f10, 0x100($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800214B0: lwc1        $f4, 0x10C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800214B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800214B8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800214BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800214C0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800214C4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800214C8: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x800214CC: nop

    // 0x800214D0: bc1f        L_800214DC
    if (!c1cs) {
        // 0x800214D4: nop
    
            goto L_800214DC;
    }
    // 0x800214D4: nop

    // 0x800214D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800214DC:
    // 0x800214DC: beq         $v0, $zero, L_80021530
    if (ctx->r2 == 0) {
        // 0x800214E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021530;
    }
    // 0x800214E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800214E4: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800214E8: addiu       $s1, $s1, -0x301C
    ctx->r17 = ADD32(ctx->r17, -0X301C);
    // 0x800214EC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800214F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800214F4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800214F8: jal         0x8004D23C
    // 0x800214FC: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_1;
    // 0x800214FC: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_1:
    // 0x80021500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021504: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80021508: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002150C: jal         0x8004D23C
    // 0x80021510: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_2;
    // 0x80021510: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_2:
    // 0x80021514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021518: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8002151C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021520: jal         0x8004D23C
    // 0x80021524: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_3;
    // 0x80021524: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_3:
    // 0x80021528: b           L_80021574
    // 0x8002152C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80021574;
    // 0x8002152C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021530:
    // 0x80021530: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80021534: addiu       $s1, $s1, -0x301C
    ctx->r17 = ADD32(ctx->r17, -0X301C);
    // 0x80021538: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002153C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80021540: jal         0x8004D23C
    // 0x80021544: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_4;
    // 0x80021544: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x80021548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002154C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80021550: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021554: jal         0x8004D23C
    // 0x80021558: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_5;
    // 0x80021558: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x8002155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021560: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80021564: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021568: jal         0x8004D23C
    // 0x8002156C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_6;
    // 0x8002156C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x80021570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021574:
    // 0x80021574: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80021578: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002157C: jr          $ra
    // 0x80021580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80021580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80781054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80781054: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80781058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078105C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80781060: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80781064: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80781068: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078106C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80781070: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80781074: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80781078: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8078107C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80781080: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80781084: lw          $t9, 0x180($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X180);
    // 0x80781088: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8078108C: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x80781090: beq         $t1, $zero, L_807810AC
    if (ctx->r9 == 0) {
        // 0x80781094: nop
    
            goto L_807810AC;
    }
    // 0x80781094: nop

    // 0x80781098: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8078109C: jal         0x80780DC4
    // 0x807810A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80780DC4(rdram, ctx);
        goto after_0;
    // 0x807810A0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x807810A4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x807810A8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
L_807810AC:
    // 0x807810AC: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X666C) << 16);
    // 0x807810B0: lwc1        $f2, 0x685C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X666C));
    // 0x807810B4: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X6670) << 16);
    // 0x807810B8: lwc1        $f8, 0x6860($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X6670));
    // 0x807810BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807810C0: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x807810C4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x807810C8: nop

    // 0x807810CC: bc1fl       L_807810DC
    if (!c1cs) {
        // 0x807810D0: swc1        $f0, 0x6C($a3)
        MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
            goto L_807810DC;
    }
    goto skip_0;
    // 0x807810D0: swc1        $f0, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
    skip_0:
    // 0x807810D4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x807810D8: swc1        $f0, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f0.u32l;
L_807810DC:
    // 0x807810DC: swc1        $f0, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f0.u32l;
    // 0x807810E0: jal         0x80780260
    // 0x807810E4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_80780260(rdram, ctx);
        goto after_1;
    // 0x807810E4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x807810E8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x807810EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807810F0: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x807810F4: jal         0x80048F84
    // 0x807810F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x807810F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x807810FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80781100: jal         0x80048F84
    // 0x80781104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x80781104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80781108: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8078110C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80781110: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80781114: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80781118: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8078111C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80781120: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x80781124: bc1fl       L_807811E8
    if (!c1cs) {
        // 0x80781128: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_807811E8;
    }
    goto skip_1;
    // 0x80781128: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_1:
    // 0x8078112C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80781130: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x80781134: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80781138: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x8078113C: nop

    // 0x80781140: bc1fl       L_807811E8
    if (!c1cs) {
        // 0x80781144: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_807811E8;
    }
    goto skip_2;
    // 0x80781144: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_2:
    // 0x80781148: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078114C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80781150: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80781154: nop

    // 0x80781158: bc1fl       L_807811E8
    if (!c1cs) {
        // 0x8078115C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_807811E8;
    }
    goto skip_3;
    // 0x8078115C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_3:
    // 0x80781160: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80781164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80781168: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8078116C: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x80781170: nop

    // 0x80781174: bc1fl       L_807811E8
    if (!c1cs) {
        // 0x80781178: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_807811E8;
    }
    goto skip_4;
    // 0x80781178: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_4:
    // 0x8078117C: lh          $t2, 0x184($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X184);
    // 0x80781180: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80781184: sb          $t0, 0x165($a3)
    MEM_B(0X165, ctx->r7) = ctx->r8;
    // 0x80781188: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8078118C: blez        $t3, L_807811BC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80781190: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807811BC;
    }
    // 0x80781190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80781194: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80781198: lw          $t4, 0x188($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X188);
L_8078119C:
    // 0x8078119C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x807811A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807811A4: sb          $t0, 0x165($t4)
    MEM_B(0X165, ctx->r12) = ctx->r8;
    // 0x807811A8: lh          $t5, 0x184($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X184);
    // 0x807811AC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x807811B0: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x807811B4: bnel        $at, $zero, L_8078119C
    if (ctx->r1 != 0) {
        // 0x807811B8: lw          $t4, 0x188($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X188);
            goto L_8078119C;
    }
    goto skip_5;
    // 0x807811B8: lw          $t4, 0x188($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X188);
    skip_5:
L_807811BC:
    // 0x807811BC: jal         0x807813F0
    // 0x807811C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_807813F0(rdram, ctx);
        goto after_4;
    // 0x807811C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x807811C4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x807811C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807811CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807811D0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x807811D4: lw          $t1, 0x1F4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1F4);
    // 0x807811D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807811DC: b           L_80781250
    // 0x807811E0: sw          $t8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r24;
        goto L_80781250;
    // 0x807811E0: sw          $t8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r24;
    // 0x807811E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_807811E8:
    // 0x807811E8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x807811EC: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x807811F0: nop

    // 0x807811F4: bc1tl       L_80781254
    if (c1cs) {
        // 0x807811F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80781254;
    }
    goto skip_6;
    // 0x807811F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x807811FC: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80781200: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80781204: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80781208: nop

    // 0x8078120C: bc1tl       L_80781254
    if (c1cs) {
        // 0x80781210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80781254;
    }
    goto skip_7;
    // 0x80781210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80781214: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x80781218: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8078121C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80781220: lwc1        $f18, 0x84($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X84);
    // 0x80781224: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x80781228: nop

    // 0x8078122C: bc1fl       L_80781254
    if (!c1cs) {
        // 0x80781230: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80781254;
    }
    goto skip_8;
    // 0x80781230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80781234: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80781238: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8078123C: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80781240: nop

    // 0x80781244: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80781248: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8078124C: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
L_80781250:
    // 0x80781250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80781254:
    // 0x80781254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80781258: jr          $ra
    // 0x8078125C: nop

    return;
    // 0x8078125C: nop

;}
RECOMP_FUNC void func_8001B84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B84C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B85C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001B860: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001B864: jal         0x8001B2E0
    // 0x8001B868: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001B2E0(rdram, ctx);
        goto after_0;
    // 0x8001B868: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001B86C: bne         $v0, $zero, L_8001B87C
    if (ctx->r2 != 0) {
        // 0x8001B870: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8001B87C;
    }
    // 0x8001B870: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001B874: b           L_8001B8E8
    // 0x8001B878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B8E8;
    // 0x8001B878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B87C:
    // 0x8001B87C: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x8001B880: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B884: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x8001B888: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x8001B88C: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8001B890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001B894: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001B898: nop

    // 0x8001B89C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001B8A0: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x8001B8A4: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8001B8A8: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x8001B8AC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001B8B0: jal         0x8001B17C
    // 0x8001B8B4: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    func_8001B17C(rdram, ctx);
        goto after_1;
    // 0x8001B8B4: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_1:
    // 0x8001B8B8: jal         0x8001B3AC
    // 0x8001B8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001B3AC(rdram, ctx);
        goto after_2;
    // 0x8001B8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001B8C0: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001B8C4: bgez        $v0, L_8001B8D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B8C8: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8001B8D8;
    }
    // 0x8001B8C8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001B8CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B8D0: b           L_8001B8E4
    // 0x8001B8D4: sw          $t0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r8;
        goto L_8001B8E4;
    // 0x8001B8D4: sw          $t0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r8;
L_8001B8D8:
    // 0x8001B8D8: sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    // 0x8001B8DC: jal         0x8001B200
    // 0x8001B8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001B200(rdram, ctx);
        goto after_3;
    // 0x8001B8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8001B8E4:
    // 0x8001B8E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8001B8E8:
    // 0x8001B8E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B8EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B8F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B8F4: jr          $ra
    // 0x8001B8F8: nop

    return;
    // 0x8001B8F8: nop

;}
RECOMP_FUNC void func_8057ED50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057ED50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057ED54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057ED58: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8057ED5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8057ED60: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(396, 0X80) << 16);
    // 0x8057ED64: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8057ED68: addiu       $t7, $t7, -0x1240
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(396, 0X80));
    // 0x8057ED6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057ED70: jal         0x8057ED98
    // 0x8057ED74: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_8057ED98(rdram, ctx);
        goto after_0;
    // 0x8057ED74: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_0:
    // 0x8057ED78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057ED7C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8057ED80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8057ED84: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8057ED88: jr          $ra
    // 0x8057ED8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8057ED8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80041838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041838: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x8004183C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80041840: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80041844: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004184C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041850: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80041854: lwc1        $f4, 0x300($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X300);
    // 0x80041858: mflo        $t8
    ctx->r24 = lo;
    // 0x8004185C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80041860: lwc1        $f0, 0x120C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X120C);
    // 0x80041864: lw          $v0, 0x11FC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X11FC);
    // 0x80041868: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004186C: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80041870: nop

    // 0x80041874: bc1fl       L_800418C0
    if (!c1cs) {
        // 0x80041878: swc1        $f0, 0x120C($v1)
        MEM_W(0X120C, ctx->r3) = ctx->f0.u32l;
            goto L_800418C0;
    }
    goto skip_0;
    // 0x80041878: swc1        $f0, 0x120C($v1)
    MEM_W(0X120C, ctx->r3) = ctx->f0.u32l;
    skip_0:
    // 0x8004187C: lbu         $t9, 0x1202($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1202);
    // 0x80041880: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80041884: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80041888: sb          $t0, 0x1202($v1)
    MEM_B(0X1202, ctx->r3) = ctx->r8;
    // 0x8004188C: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    // 0x80041890: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80041894: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041898: mflo        $t3
    ctx->r11 = lo;
    // 0x8004189C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800418A0: sh          $zero, 0x1200($t4)
    MEM_H(0X1200, ctx->r12) = 0;
    // 0x800418A4: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x800418A8: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x800418AC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800418B0: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800418B4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800418B8: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800418BC: swc1        $f0, 0x120C($v1)
    MEM_W(0X120C, ctx->r3) = ctx->f0.u32l;
L_800418C0:
    // 0x800418C0: lhu         $t9, 0x8($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X8);
    // 0x800418C4: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800418C8: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800418CC: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800418D0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800418D4: lwc1        $f10, 0x84($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X84);
    // 0x800418D8: mflo        $t0
    ctx->r8 = lo;
    // 0x800418DC: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x800418E0: lwc1        $f6, 0x1204($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1204);
    // 0x800418E4: lwc1        $f4, 0x1208($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1208);
    // 0x800418E8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800418EC: nop

    // 0x800418F0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800418F4: lwc1        $f10, 0x88($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X88);
    // 0x800418F8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800418FC: add.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80041900: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80041904: swc1        $f2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f2.u32l;
    // 0x80041908: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004190C: jr          $ra
    // 0x80041910: swc1        $f14, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x80041910: swc1        $f14, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80454630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454630: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454634: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80454638: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x8045463C: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x80454640: sw          $v1, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r3;
    // 0x80454644: jr          $ra
    // 0x80454648: sw          $t6, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r14;
    return;
    // 0x80454648: sw          $t6, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_806B0D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B0D7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B0D80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806B0D84: jal         0x8004700C
    // 0x806B0D88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806B0D88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B0D8C: beq         $v0, $zero, L_806B0DCC
    if (ctx->r2 == 0) {
        // 0x806B0D90: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806B0DCC;
    }
    // 0x806B0D90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806B0D94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B0D98: jal         0x806B0A70
    // 0x806B0D9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_806B0A70(rdram, ctx);
        goto after_1;
    // 0x806B0D9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806B0DA0: bne         $v0, $zero, L_806B0DCC
    if (ctx->r2 != 0) {
        // 0x806B0DA4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806B0DCC;
    }
    // 0x806B0DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B0DA8: jal         0x806B0404
    // 0x806B0DAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806B0404(rdram, ctx);
        goto after_2;
    // 0x806B0DAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x806B0DB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B0DB4: jal         0x806B0AD0
    // 0x806B0DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806B0AD0(rdram, ctx);
        goto after_3;
    // 0x806B0DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x806B0DBC: jal         0x806B0A08
    // 0x806B0DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806B0A08(rdram, ctx);
        goto after_4;
    // 0x806B0DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x806B0DC4: jal         0x806AFFC8
    // 0x806B0DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AFFC8(rdram, ctx);
        goto after_5;
    // 0x806B0DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_806B0DCC:
    // 0x806B0DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B0DD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806B0DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B0DD8: jr          $ra
    // 0x806B0DDC: nop

    return;
    // 0x806B0DDC: nop

;}
RECOMP_FUNC void func_8040C444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040C448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040C44C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040C450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040C454: jal         0x80051194
    // 0x8040C458: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8040C458: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8040C45C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8040C460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040C464: jal         0x80045A34
    // 0x8040C468: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8040C468: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8040C46C: bne         $v0, $zero, L_8040C47C
    if (ctx->r2 != 0) {
        // 0x8040C470: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8040C47C;
    }
    // 0x8040C470: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8040C474: b           L_8040C49C
    // 0x8040C478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040C49C;
    // 0x8040C478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040C47C:
    // 0x8040C47C: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040C480: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8040C484: jal         0x80065728
    // 0x8040C488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8040C488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8040C48C: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040C490: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8040C494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040C498: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_8040C49C:
    // 0x8040C49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040C4A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040C4A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040C4A8: jr          $ra
    // 0x8040C4AC: nop

    return;
    // 0x8040C4AC: nop

;}
RECOMP_FUNC void func_807801F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807801F0: lui         $v0, 0x8078
    ctx->r2 = S32(RELOC_HI16(784, 0X4D4) << 16);
    // 0x807801F4: addiu       $v0, $v0, 0x6C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X4D4));
    // 0x807801F8: jr          $ra
    // 0x807801FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807801FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
