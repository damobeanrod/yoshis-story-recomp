#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80079A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079A20: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80079A24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80079A28: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80079A2C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80079A30: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80079A34: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80079A38: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80079A3C: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80079A40: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80079A44: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80079A48: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80079A4C: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80079A50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80079A54: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80079A58: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80079A5C: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80079A60: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80079A64: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
    // 0x80079A68: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x80079A6C: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80079A70: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80079A74: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80079A78: andi        $t6, $a2, 0x1
    ctx->r14 = ctx->r6 & 0X1;
    // 0x80079A7C: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80079A80: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
    // 0x80079A84: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    // 0x80079A88: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80079A8C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079A90: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80079A94: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80079A98: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80079A9C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80079AA0: nop

    // 0x80079AA4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80079AA8: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80079AAC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80079AB0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80079AB4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80079AB8: beq         $t6, $zero, L_80079ACC
    if (ctx->r14 == 0) {
        // 0x80079ABC: or          $t2, $a1, $zero
        ctx->r10 = ctx->r5 | 0;
            goto L_80079ACC;
    }
    // 0x80079ABC: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80079AC0: sll         $t5, $v0, 5
    ctx->r13 = S32(ctx->r2 << 5);
    // 0x80079AC4: b           L_80079AD0
    // 0x80079AC8: negu        $t1, $v1
    ctx->r9 = SUB32(0, ctx->r3);
        goto L_80079AD0;
    // 0x80079AC8: negu        $t1, $v1
    ctx->r9 = SUB32(0, ctx->r3);
L_80079ACC:
    // 0x80079ACC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_80079AD0:
    // 0x80079AD0: beq         $t7, $zero, L_80079AE0
    if (ctx->r15 == 0) {
        // 0x80079AD4: sll         $t4, $a0, 5
        ctx->r12 = S32(ctx->r4 << 5);
            goto L_80079AE0;
    }
    // 0x80079AD4: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x80079AD8: b           L_80079AE4
    // 0x80079ADC: negu        $t2, $a1
    ctx->r10 = SUB32(0, ctx->r5);
        goto L_80079AE4;
    // 0x80079ADC: negu        $t2, $a1
    ctx->r10 = SUB32(0, ctx->r5);
L_80079AE0:
    // 0x80079AE0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80079AE4:
    // 0x80079AE4: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80079AE8: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80079AEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80079AF0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80079AF4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80079AF8: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80079AFC: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80079B00: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80079B04: jal         0x80077084
    // 0x80079B08: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    func_80077084(rdram, ctx);
        goto after_0;
    // 0x80079B08: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    after_0:
    // 0x80079B0C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079B10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80079B14: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80079B18: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80079B1C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80079B20: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80079B24: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x80079B28: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80079B2C: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80079B30: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80079B34: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079B38: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80079B3C: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x80079B40: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80079B44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80079B48: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80079B4C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80079B50: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80079B54: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80079B58: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80079B5C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80079B60: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80079B64: blez        $v0, L_80079B74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80079B68: sll         $a0, $a0, 16
        ctx->r4 = S32(ctx->r4 << 16);
            goto L_80079B74;
    }
    // 0x80079B68: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80079B6C: b           L_80079B74
    // 0x80079B70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80079B74;
    // 0x80079B70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80079B74:
    // 0x80079B74: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80079B78: blez        $a0, L_80079B88
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80079B7C: andi        $t8, $v1, 0xFFF
        ctx->r24 = ctx->r3 & 0XFFF;
            goto L_80079B88;
    }
    // 0x80079B7C: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x80079B80: b           L_80079B8C
    // 0x80079B84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80079B8C;
    // 0x80079B84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80079B88:
    // 0x80079B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079B8C:
    // 0x80079B8C: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x80079B90: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80079B94: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80079B98: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80079B9C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80079BA0: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80079BA4: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80079BA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80079BAC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079BB0: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80079BB4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80079BB8: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80079BBC: nop

    // 0x80079BC0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80079BC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80079BC8: blez        $a0, L_80079BD8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80079BCC: trunc.w.s   $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
            goto L_80079BD8;
    }
    // 0x80079BCC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80079BD0: b           L_80079BD8
    // 0x80079BD4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80079BD8;
    // 0x80079BD4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80079BD8:
    // 0x80079BD8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80079BDC: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80079BE0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80079BE4: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80079BE8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80079BEC: blez        $a1, L_80079BFC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80079BF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80079BFC;
    }
    // 0x80079BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80079BF4: b           L_80079BFC
    // 0x80079BF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80079BFC;
    // 0x80079BF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80079BFC:
    // 0x80079BFC: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x80079C00: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80079C04: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80079C08: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x80079C0C: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80079C10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80079C14: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80079C18: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x80079C1C: bgez        $a0, L_80079C88
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80079C20: sw          $t8, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r24;
            goto L_80079C88;
    }
    // 0x80079C20: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80079C24: sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9 << 16);
    // 0x80079C28: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80079C2C: bgez        $v1, L_80079C5C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80079C30: nop
    
            goto L_80079C5C;
    }
    // 0x80079C30: nop

    // 0x80079C34: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079C38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80079C3C: mflo        $v0
    ctx->r2 = lo;
    // 0x80079C40: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079C44: blez        $v0, L_80079C54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80079C48: nop
    
            goto L_80079C54;
    }
    // 0x80079C48: nop

    // 0x80079C4C: b           L_80079C88
    // 0x80079C50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80079C88;
    // 0x80079C50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80079C54:
    // 0x80079C54: b           L_80079C88
    // 0x80079C58: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80079C88;
    // 0x80079C58: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80079C5C:
    // 0x80079C5C: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079C60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80079C64: mflo        $v0
    ctx->r2 = lo;
    // 0x80079C68: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079C6C: bgez        $v0, L_80079C7C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80079C70: nop
    
            goto L_80079C7C;
    }
    // 0x80079C70: nop

    // 0x80079C74: b           L_80079C7C
    // 0x80079C78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80079C7C;
    // 0x80079C78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80079C7C:
    // 0x80079C7C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80079C80: b           L_80079C88
    // 0x80079C84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80079C88;
    // 0x80079C84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80079C88:
    // 0x80079C88: bgez        $a3, L_80079CF4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80079C8C: subu        $t8, $t5, $a2
        ctx->r24 = SUB32(ctx->r13, ctx->r6);
            goto L_80079CF4;
    }
    // 0x80079C8C: subu        $t8, $t5, $a2
    ctx->r24 = SUB32(ctx->r13, ctx->r6);
    // 0x80079C90: sll         $v1, $t2, 16
    ctx->r3 = S32(ctx->r10 << 16);
    // 0x80079C94: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80079C98: bgez        $v1, L_80079CC8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80079C9C: nop
    
            goto L_80079CC8;
    }
    // 0x80079C9C: nop

    // 0x80079CA0: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079CA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80079CA8: mflo        $v0
    ctx->r2 = lo;
    // 0x80079CAC: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079CB0: blez        $v0, L_80079CC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80079CB4: nop
    
            goto L_80079CC0;
    }
    // 0x80079CB4: nop

    // 0x80079CB8: b           L_80079CFC
    // 0x80079CBC: subu        $t7, $t4, $v0
    ctx->r15 = SUB32(ctx->r12, ctx->r2);
        goto L_80079CFC;
    // 0x80079CBC: subu        $t7, $t4, $v0
    ctx->r15 = SUB32(ctx->r12, ctx->r2);
L_80079CC0:
    // 0x80079CC0: b           L_80079CF8
    // 0x80079CC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80079CF8;
    // 0x80079CC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80079CC8:
    // 0x80079CC8: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079CCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80079CD0: mflo        $v0
    ctx->r2 = lo;
    // 0x80079CD4: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079CD8: bgez        $v0, L_80079CE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80079CDC: nop
    
            goto L_80079CE8;
    }
    // 0x80079CDC: nop

    // 0x80079CE0: b           L_80079CE8
    // 0x80079CE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80079CE8;
    // 0x80079CE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80079CE8:
    // 0x80079CE8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80079CEC: b           L_80079CF8
    // 0x80079CF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80079CF8;
    // 0x80079CF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80079CF4:
    // 0x80079CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079CF8:
    // 0x80079CF8: subu        $t7, $t4, $v0
    ctx->r15 = SUB32(ctx->r12, ctx->r2);
L_80079CFC:
    // 0x80079CFC: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x80079D00: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80079D04: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80079D08: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80079D0C: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x80079D10: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80079D14: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x80079D18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80079D1C: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x80079D20: andi        $t6, $t2, 0xFFFF
    ctx->r14 = ctx->r10 & 0XFFFF;
    // 0x80079D24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80079D28: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80079D2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80079D30: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80079D34: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80079D38: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80079D3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80079D40: jr          $ra
    // 0x80079D44: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80079D44: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_806CC984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CC984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CC988: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x806CC98C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x806CC990: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x806CC994: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x806CC998: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x806CC99C: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x806CC9A0: lw          $a3, 0x16C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X16C);
    // 0x806CC9A4: lui         $s3, 0x806D
    ctx->r19 = S32(RELOC_HI16(604, 0X3AE0) << 16);
    // 0x806CC9A8: lw          $t6, 0x588($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X588);
    // 0x806CC9AC: lbu         $t8, 0xD($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XD);
    // 0x806CC9B0: addiu       $s3, $s3, -0xE00
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(604, 0X3AE0));
    // 0x806CC9B4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x806CC9B8: sb          $t8, 0xC($s3)
    MEM_B(0XC, ctx->r19) = ctx->r24;
    // 0x806CC9BC: lbu         $t9, 0x11($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X11);
    // 0x806CC9C0: lui         $s4, 0x806D
    ctx->r20 = S32(RELOC_HI16(604, 0X3AD0) << 16);
    // 0x806CC9C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806CC9C8: addiu       $s4, $s4, -0xE10
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(604, 0X3AD0));
    // 0x806CC9CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806CC9D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806CC9D4: sb          $t9, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r25;
    // 0x806CC9D8: lbu         $t6, 0xE($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XE);
    // 0x806CC9DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806CC9E0: addu        $t5, $a2, $t7
    ctx->r13 = ADD32(ctx->r6, ctx->r15);
    // 0x806CC9E4: sb          $t6, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r14;
    // 0x806CC9E8: lbu         $t7, 0x12($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X12);
    // 0x806CC9EC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x806CC9F0: addiu       $s0, $t5, 0x2C4
    ctx->r16 = ADD32(ctx->r13, 0X2C4);
    // 0x806CC9F4: sb          $t7, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r15;
    // 0x806CC9F8: lbu         $t8, 0xF($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XF);
    // 0x806CC9FC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x806CCA00: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x806CCA04: sb          $t8, 0xE($s3)
    MEM_B(0XE, ctx->r19) = ctx->r24;
    // 0x806CCA08: lbu         $t9, 0x13($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X13);
    // 0x806CCA0C: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    // 0x806CCA10: sb          $t9, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r25;
    // 0x806CCA14: lbu         $t6, 0x3($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3);
    // 0x806CCA18: sb          $t6, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r14;
    // 0x806CCA1C: lbu         $t7, 0x3($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3);
    // 0x806CCA20: sb          $t7, 0xF($s4)
    MEM_B(0XF, ctx->r20) = ctx->r15;
    // 0x806CCA24: lw          $t3, -0x260C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X260C);
    // 0x806CCA28: lw          $v0, 0xC($t3)
    ctx->r2 = MEM_W(ctx->r11, 0XC);
    // 0x806CCA2C: addiu       $v0, $v0, -0x760
    ctx->r2 = ADD32(ctx->r2, -0X760);
    // 0x806CCA30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x806CCA34: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    // 0x806CCA38: sw          $v0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r2;
L_806CCA3C:
    // 0x806CCA3C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x806CCA40: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x806CCA44: sltiu       $at, $t4, 0xEC
    ctx->r1 = ctx->r12 < 0XEC ? 1 : 0;
    // 0x806CCA48: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x806CCA4C: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x806CCA50: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x806CCA54: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806CCA58: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x806CCA5C: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x806CCA60: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x806CCA64: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x806CCA68: sw          $t9, -0x18($s1)
    MEM_W(-0X18, ctx->r17) = ctx->r25;
    // 0x806CCA6C: lw          $t8, 0xC($s4)
    ctx->r24 = MEM_W(ctx->r20, 0XC);
    // 0x806CCA70: sw          $t8, -0x14($s1)
    MEM_W(-0X14, ctx->r17) = ctx->r24;
    // 0x806CCA74: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x806CCA78: sw          $t7, -0x20($s2)
    MEM_W(-0X20, ctx->r18) = ctx->r15;
    // 0x806CCA7C: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x806CCA80: sw          $t6, -0x1C($s2)
    MEM_W(-0X1C, ctx->r18) = ctx->r14;
    // 0x806CCA84: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x806CCA88: sw          $t7, -0x18($s2)
    MEM_W(-0X18, ctx->r18) = ctx->r15;
    // 0x806CCA8C: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x806CCA90: sw          $t6, -0x14($s2)
    MEM_W(-0X14, ctx->r18) = ctx->r14;
    // 0x806CCA94: lh          $t8, -0x4($t5)
    ctx->r24 = MEM_H(ctx->r13, -0X4);
    // 0x806CCA98: sh          $t8, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r24;
    // 0x806CCA9C: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x806CCAA0: sh          $t9, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r25;
    // 0x806CCAA4: lh          $t6, -0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, -0X2);
    // 0x806CCAA8: sh          $t6, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r14;
    // 0x806CCAAC: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x806CCAB0: bne         $at, $zero, L_806CCA3C
    if (ctx->r1 != 0) {
        // 0x806CCAB4: sh          $t7, -0xE($s1)
        MEM_H(-0XE, ctx->r17) = ctx->r15;
            goto L_806CCA3C;
    }
    // 0x806CCAB4: sh          $t7, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r15;
    // 0x806CCAB8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCABC: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x806CCAC0: ori         $t3, $t3, 0x103F
    ctx->r11 = ctx->r11 | 0X103F;
    // 0x806CCAC4: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806CCAC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806CCACC: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x806CCAD0: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806CCAD4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCAD8: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x806CCADC: addiu       $t5, $zero, 0x206
    ctx->r13 = ADD32(0, 0X206);
    // 0x806CCAE0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806CCAE4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806CCAE8: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806CCAEC: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCAF0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCAF4: addiu       $s0, $zero, 0x604
    ctx->r16 = ADD32(0, 0X604);
    // 0x806CCAF8: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x806CCAFC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806CCB00: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CCB04: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806CCB08: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCB0C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCB10: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x806CCB14: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x806CCB18: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806CCB1C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806CCB20: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x806CCB24: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806CCB28: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCB2C: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x806CCB30: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x806CCB34: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806CCB38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CCB3C: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806CCB40: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCB44: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCB48: addiu       $v1, $zero, 0x3A
    ctx->r3 = ADD32(0, 0X3A);
    // 0x806CCB4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806CCB50: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806CCB54: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806CCB58: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806CCB5C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_806CCB60:
    // 0x806CCB60: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCB64: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806CCB68: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806CCB6C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806CCB70: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806CCB74: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806CCB78: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCB7C: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806CCB80: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806CCB84: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CCB88: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806CCB8C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCB90: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCB94: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806CCB98: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806CCB9C: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806CCBA0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCBA4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCBA8: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806CCBAC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806CCBB0: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806CCBB4: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806CCBB8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCBBC: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806CCBC0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806CCBC4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806CCBC8: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806CCBCC: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCBD0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCBD4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806CCBD8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CCBDC: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806CCBE0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCBE4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCBE8: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806CCBEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806CCBF0: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806CCBF4: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806CCBF8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCBFC: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806CCC00: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806CCC04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806CCC08: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806CCC0C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCC10: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCC14: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806CCC18: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806CCC1C: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806CCC20: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCC24: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCC28: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806CCC2C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806CCC30: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806CCC34: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806CCC38: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCC3C: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806CCC40: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806CCC44: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806CCC48: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806CCC4C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCC50: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806CCC54: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806CCC58: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806CCC5C: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806CCC60: bne         $a1, $v1, L_806CCB60
    if (ctx->r5 != ctx->r3) {
        // 0x806CCC64: sw          $t4, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r12;
            goto L_806CCB60;
    }
    // 0x806CCC64: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806CCC68: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x806CCC6C: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x806CCC70: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x806CCC74: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x806CCC78: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x806CCC7C: jr          $ra
    // 0x806CCC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806CCC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80062684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062684: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80062688: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8006268C: lh          $v0, 0x184($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X184);
    // 0x80062690: addiu       $v1, $a0, 0x188
    ctx->r3 = ADD32(ctx->r4, 0X188);
    // 0x80062694: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80062698: lh          $t7, 0x58($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X58);
    // 0x8006269C: lh          $t8, 0x52($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X52);
    // 0x800626A0: lw          $t6, 0x70($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X70);
    // 0x800626A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800626A8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800626AC: lwc1        $f2, 0x4($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800626B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800626B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800626B8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800626BC: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800626C0: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800626C4: beq         $v0, $zero, L_80062740
    if (ctx->r2 == 0) {
        // 0x800626C8: sub.s       $f0, $f10, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_80062740;
    }
    // 0x800626C8: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
L_800626CC:
    // 0x800626CC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800626D0: beq         $a1, $zero, L_80062738
    if (ctx->r5 == 0) {
        // 0x800626D4: nop
    
            goto L_80062738;
    }
    // 0x800626D4: nop

    // 0x800626D8: lw          $a2, 0x174($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X174);
    // 0x800626DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800626E0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800626E4: beq         $a2, $zero, L_80062738
    if (ctx->r6 == 0) {
        // 0x800626E8: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80062738;
    }
    // 0x800626E8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800626EC: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800626F0: bne         $a0, $t9, L_80062738
    if (ctx->r4 != ctx->r25) {
        // 0x800626F4: nop
    
            goto L_80062738;
    }
    // 0x800626F4: nop

    // 0x800626F8: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800626FC: lh          $t1, 0x6($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X6);
    // 0x80062700: lh          $t2, 0xC($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XC);
    // 0x80062704: lw          $t0, 0x70($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X70);
    // 0x80062708: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8006270C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80062710: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80062714: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80062718: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006271C: mul.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80062720: nop

    // 0x80062724: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80062728: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006272C: add.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80062730: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80062734: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
L_80062738:
    // 0x80062738: bne         $v0, $zero, L_800626CC
    if (ctx->r2 != 0) {
        // 0x8006273C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800626CC;
    }
    // 0x8006273C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80062740:
    // 0x80062740: jr          $ra
    // 0x80062744: nop

    return;
    // 0x80062744: nop

;}
RECOMP_FUNC void func_806F72C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F72C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F72C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F72C8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806F72CC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806F72D0: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(691, 0X8F4) << 16);
    // 0x806F72D4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806F72D8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F72DC: addiu       $t7, $t7, 0x7684
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(691, 0X8F4));
    // 0x806F72E0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806F72E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F72E8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806F72EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806F72F0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F72F4: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806F72F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F72FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F7300: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806F7304: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x806F7308: jal         0x80048378
    // 0x806F730C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806F730C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x806F7310: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F7314: jal         0x80045A34
    // 0x806F7318: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806F7318: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x806F731C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806F7320: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x806F7324: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x806F7328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F732C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F7330: jr          $ra
    // 0x806F7334: nop

    return;
    // 0x806F7334: nop

;}
RECOMP_FUNC void func_80064D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064D1C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80064D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064D24: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80064D28: beq         $t6, $zero, L_80064D40
    if (ctx->r14 == 0) {
        // 0x80064D2C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80064D40;
    }
    // 0x80064D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064D30: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80064D34: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80064D38: b           L_80064D44
    // 0x80064D3C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
        goto L_80064D44;
    // 0x80064D3C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80064D40:
    // 0x80064D40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80064D44:
    // 0x80064D44: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80064D48: addiu       $a1, $v1, -0x6C08
    ctx->r5 = ADD32(ctx->r3, -0X6C08);
    // 0x80064D4C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80064D50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064D54: beq         $v0, $a1, L_80064DA8
    if (ctx->r2 == ctx->r5) {
        // 0x80064D58: nop
    
            goto L_80064DA8;
    }
    // 0x80064D58: nop

    // 0x80064D5C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
L_80064D60:
    // 0x80064D60: bnel        $t7, $zero, L_80064DA0
    if (ctx->r15 != 0) {
        // 0x80064D64: lw          $v0, 0x8($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X8);
            goto L_80064DA0;
    }
    goto skip_0;
    // 0x80064D64: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80064D68: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80064D6C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80064D70: bnel        $at, $zero, L_80064DA0
    if (ctx->r1 != 0) {
        // 0x80064D74: lw          $v0, 0x8($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X8);
            goto L_80064DA0;
    }
    goto skip_1;
    // 0x80064D74: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x80064D78: bnel        $a0, $zero, L_80064D8C
    if (ctx->r4 != 0) {
        // 0x80064D7C: lw          $t8, 0xC($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XC);
            goto L_80064D8C;
    }
    goto skip_2;
    // 0x80064D7C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80064D80: b           L_80064D9C
    // 0x80064D84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80064D9C;
    // 0x80064D84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80064D88: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
L_80064D8C:
    // 0x80064D8C: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80064D90: beql        $at, $zero, L_80064DA0
    if (ctx->r1 == 0) {
        // 0x80064D94: lw          $v0, 0x8($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X8);
            goto L_80064DA0;
    }
    goto skip_3;
    // 0x80064D94: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    skip_3:
    // 0x80064D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80064D9C:
    // 0x80064D9C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_80064DA0:
    // 0x80064DA0: bnel        $v0, $a1, L_80064D60
    if (ctx->r2 != ctx->r5) {
        // 0x80064DA4: lhu         $t7, 0x2($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X2);
            goto L_80064D60;
    }
    goto skip_4;
    // 0x80064DA4: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    skip_4:
L_80064DA8:
    // 0x80064DA8: beq         $a0, $zero, L_80064DC0
    if (ctx->r4 == 0) {
        // 0x80064DAC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80064DC0;
    }
    // 0x80064DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80064DB0: jal         0x80064C8C
    // 0x80064DB4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80064C8C(rdram, ctx);
        goto after_0;
    // 0x80064DB4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80064DB8: b           L_80064DC4
    // 0x80064DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80064DC4;
    // 0x80064DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064DC0:
    // 0x80064DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064DC4:
    // 0x80064DC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064DC8: jr          $ra
    // 0x80064DCC: nop

    return;
    // 0x80064DCC: nop

;}
RECOMP_FUNC void func_80437160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437160: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437164: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437168: lwc1        $f6, 0x4C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8043716C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80437170: jr          $ra
    // 0x80437174: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80437174: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8057AB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057AB3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057AB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057AB44: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057AB48: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8057AB4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8057AB50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8057AB54: jal         0x8057A2B8
    // 0x8057AB58: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8057A2B8(rdram, ctx);
        goto after_0;
    // 0x8057AB58: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8057AB5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8057AB60: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8057AB64: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8057AB68: lw          $t0, 0x168($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X168);
    // 0x8057AB6C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8057AB70: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8057AB74: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x8057AB78: lh          $t3, 0x7C($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X7C);
    // 0x8057AB7C: lw          $v1, 0x16C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X16C);
    // 0x8057AB80: lw          $t5, 0x80($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X80);
    // 0x8057AB84: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057AB88: lbu         $t6, 0x34($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X34);
    // 0x8057AB8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057AB90: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8057AB94: lw          $a0, 0x38($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X38);
    // 0x8057AB98: mflo        $t4
    ctx->r12 = lo;
    // 0x8057AB9C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x8057ABA0: jal         0x8005B350
    // 0x8057ABA4: nop

    func_8005B350(rdram, ctx);
        goto after_1;
    // 0x8057ABA4: nop

    after_1:
    // 0x8057ABA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8057ABAC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8057ABB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8057ABB4: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x8057ABB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8057ABBC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8057ABC0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8057ABC4: bne         $at, $zero, L_8057ABE4
    if (ctx->r1 != 0) {
        // 0x8057ABC8: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_8057ABE4;
    }
    // 0x8057ABC8: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x8057ABCC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8057ABD0: sw          $zero, 0x488($v0)
    MEM_W(0X488, ctx->r2) = 0;
    // 0x8057ABD4: sw          $zero, 0x484($v0)
    MEM_W(0X484, ctx->r2) = 0;
    // 0x8057ABD8: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8057ABDC: jal         0x8057B444
    // 0x8057ABE0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    func_8057B444(rdram, ctx);
        goto after_2;
    // 0x8057ABE0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    after_2:
L_8057ABE4:
    // 0x8057ABE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057ABE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057ABEC: jr          $ra
    // 0x8057ABF0: nop

    return;
    // 0x8057ABF0: nop

;}
RECOMP_FUNC void func_8002EED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002EEDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002EEE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002EEE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002EEE8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002EEEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002EEF0: jal         0x80040C48
    // 0x8002EEF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80040C48(rdram, ctx);
        goto after_0;
    // 0x8002EEF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8002EEF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002EEFC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002EF00: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8002EF04: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8002EF08: addiu       $t8, $t8, 0x34EC
    ctx->r24 = ADD32(ctx->r24, 0X34EC);
    // 0x8002EF0C: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002EF10: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8002EF14: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002EF18: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002EF1C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8002EF20: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x8002EF24: addiu       $a2, $a2, -0x30F4
    ctx->r6 = ADD32(ctx->r6, -0X30F4);
    // 0x8002EF28: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8002EF2C: bne         $v0, $zero, L_8002EF50
    if (ctx->r2 != 0) {
        // 0x8002EF30: nop
    
            goto L_8002EF50;
    }
    // 0x8002EF30: nop

    // 0x8002EF34: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002EF38: addiu       $a2, $a2, -0x3124
    ctx->r6 = ADD32(ctx->r6, -0X3124);
    // 0x8002EF3C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8002EF40: jal         0x800280F4
    // 0x8002EF44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800280F4(rdram, ctx);
        goto after_1;
    // 0x8002EF44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8002EF48: b           L_8002EF5C
    // 0x8002EF4C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_8002EF5C;
    // 0x8002EF4C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8002EF50:
    // 0x8002EF50: jal         0x800280F4
    // 0x8002EF54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800280F4(rdram, ctx);
        goto after_2;
    // 0x8002EF54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002EF58: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8002EF5C:
    // 0x8002EF5C: sh          $v0, 0x152($s0)
    MEM_H(0X152, ctx->r16) = ctx->r2;
    // 0x8002EF60: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // 0x8002EF64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EF68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002EF6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002EF70: jr          $ra
    // 0x8002EF74: nop

    return;
    // 0x8002EF74: nop

;}
RECOMP_FUNC void func_8059EA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EA78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059EA7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059EA80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059EA84: jal         0x8059EB34
    // 0x8059EA88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8059EB34(rdram, ctx);
        goto after_0;
    // 0x8059EA88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8059EA8C: beql        $v0, $zero, L_8059EB00
    if (ctx->r2 == 0) {
        // 0x8059EA90: lw          $a0, 0x180($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X180);
            goto L_8059EB00;
    }
    goto skip_0;
    // 0x8059EA90: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x8059EA94: jal         0x8059EB6C
    // 0x8059EA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059EB6C(rdram, ctx);
        goto after_1;
    // 0x8059EA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8059EA9C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8059EAA0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8059EAA4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8059EAA8: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(405, 0X7F8) << 16);
    // 0x8059EAAC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8059EAB0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8059EAB4: addiu       $t7, $t7, -0xDB8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(405, 0X7F8));
    // 0x8059EAB8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8059EABC: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x8059EAC0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8059EAC4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8059EAC8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8059EACC: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(405, 0X5E4) << 16);
    // 0x8059EAD0: addiu       $t9, $t9, -0xFCC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(405, 0X5E4));
    // 0x8059EAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059EAD8: jal         0x8059EA60
    // 0x8059EADC: sw          $t9, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r25;
    func_8059EA60(rdram, ctx);
        goto after_2;
    // 0x8059EADC: sw          $t9, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r25;
    after_2:
    // 0x8059EAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059EAE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059EAE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8059EAEC: jal         0x8059F190
    // 0x8059EAF0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8059F190(rdram, ctx);
        goto after_3;
    // 0x8059EAF0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8059EAF4: b           L_8059EB24
    // 0x8059EAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8059EB24;
    // 0x8059EAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8059EAFC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
L_8059EB00:
    // 0x8059EB00: beq         $a0, $zero, L_8059EB18
    if (ctx->r4 == 0) {
        // 0x8059EB04: nop
    
            goto L_8059EB18;
    }
    // 0x8059EB04: nop

    // 0x8059EB08: jal         0x800445A4
    // 0x8059EB0C: nop

    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8059EB0C: nop

    after_4:
    // 0x8059EB10: b           L_8059EB24
    // 0x8059EB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8059EB24;
    // 0x8059EB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8059EB18:
    // 0x8059EB18: jal         0x800445A4
    // 0x8059EB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8059EB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8059EB20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8059EB24:
    // 0x8059EB24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059EB28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059EB2C: jr          $ra
    // 0x8059EB30: nop

    return;
    // 0x8059EB30: nop

;}
RECOMP_FUNC void func_8006EB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EB20: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8006EB24: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8006EB28: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8006EB2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006EB30: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006EB34: lw          $t8, 0x7F88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7F88);
    // 0x8006EB38: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006EB3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8006EB40: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006EB44: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8006EB48: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8006EB4C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8006EB50: beql        $v1, $zero, L_8006EB84
    if (ctx->r3 == 0) {
        // 0x8006EB54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006EB84;
    }
    goto skip_0;
    // 0x8006EB54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006EB58: jalr        $v1
    // 0x8006EB5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8006EB5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006EB60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006EB64: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8006EB68: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8006EB6C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8006EB70: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8006EB74: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006EB78: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8006EB7C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8006EB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006EB84:
    // 0x8006EB84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EB88: jr          $ra
    // 0x8006EB8C: nop

    return;
    // 0x8006EB8C: nop

;}
RECOMP_FUNC void func_80532F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532F20: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80532F24: beql        $v0, $zero, L_80532F48
    if (ctx->r2 == 0) {
        // 0x80532F28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80532F48;
    }
    goto skip_0;
    // 0x80532F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80532F2C: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x80532F30: addiu       $at, $zero, 0x450E
    ctx->r1 = ADD32(0, 0X450E);
    // 0x80532F34: bnel        $t6, $at, L_80532F48
    if (ctx->r14 != ctx->r1) {
        // 0x80532F38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80532F48;
    }
    goto skip_1;
    // 0x80532F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80532F3C: jal         0x80532DFC
    // 0x80532F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80532DFC(rdram, ctx);
        goto after_0;
    // 0x80532F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80532F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80532F48:
    // 0x80532F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532F4C: jr          $ra
    // 0x80532F50: nop

    return;
    // 0x80532F50: nop

;}
RECOMP_FUNC void func_804350F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804350F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804350F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804350F8: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x804350FC: addiu       $v1, $v0, 0x89C
    ctx->r3 = ADD32(ctx->r2, 0X89C);
L_80435100:
    // 0x80435100: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80435104: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80435108: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8043510C: bgez        $a1, L_80435100
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80435110: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80435100;
    }
    // 0x80435110: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80435114: jr          $ra
    // 0x80435118: sw          $zero, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = 0;
    return;
    // 0x80435118: sw          $zero, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8078DDC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DDC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8078DDCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078DDD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078DDD4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8078DDD8: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(805, 0X120) << 16);
    // 0x8078DDDC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8078DDE0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8078DDE4: addiu       $t6, $t6, -0x2130
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(805, 0X120));
    // 0x8078DDE8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8078DDEC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8078DDF0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8078DDF4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8078DDF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078DDFC: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8078DE00: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8078DE04: jal         0x80045A34
    // 0x8078DE08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078DE08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8078DE0C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8078DE10: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8078DE14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8078DE18: jal         0x80047090
    // 0x8078DE1C: addiu       $a0, $zero, 0x4681
    ctx->r4 = ADD32(0, 0X4681);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8078DE1C: addiu       $a0, $zero, 0x4681
    ctx->r4 = ADD32(0, 0X4681);
    after_1:
    // 0x8078DE20: lui         $at, 0x4681
    ctx->r1 = S32(0X4681 << 16);
    // 0x8078DE24: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x8078DE28: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8078DE2C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8078DE30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8078DE34: jal         0x8004613C
    // 0x8078DE38: lui         $a2, 0xC204
    ctx->r6 = S32(0XC204 << 16);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x8078DE38: lui         $a2, 0xC204
    ctx->r6 = S32(0XC204 << 16);
    after_2:
    // 0x8078DE3C: bne         $v0, $zero, L_8078DE54
    if (ctx->r2 != 0) {
        // 0x8078DE40: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078DE54;
    }
    // 0x8078DE40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078DE44: jal         0x800445A4
    // 0x8078DE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8078DE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8078DE4C: b           L_8078DE84
    // 0x8078DE50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078DE84;
    // 0x8078DE50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078DE54:
    // 0x8078DE54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078DE58: jal         0x80047F9C
    // 0x8078DE5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8078DE5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x8078DE60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8078DE64: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8078DE68: jal         0x8005FDC4
    // 0x8078DE6C: sb          $t0, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r8;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x8078DE6C: sb          $t0, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r8;
    after_5:
    // 0x8078DE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078DE74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078DE78: jal         0x8078DE94
    // 0x8078DE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078DE94(rdram, ctx);
        goto after_6;
    // 0x8078DE7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8078DE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078DE84:
    // 0x8078DE84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078DE88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8078DE8C: jr          $ra
    // 0x8078DE90: nop

    return;
    // 0x8078DE90: nop

;}
RECOMP_FUNC void func_8006A534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A53C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006A540: bne         $a1, $zero, L_8006A550
    if (ctx->r5 != 0) {
        // 0x8006A544: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8006A550;
    }
    // 0x8006A544: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8006A548: b           L_8006A5B0
    // 0x8006A54C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A5B0;
    // 0x8006A54C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A550:
    // 0x8006A550: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8006A554: addiu       $a1, $zero, 0x22D
    ctx->r5 = ADD32(0, 0X22D);
    // 0x8006A558: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006A55C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8006A560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A564: beq         $t7, $zero, L_8006A580
    if (ctx->r15 == 0) {
        // 0x8006A568: nop
    
            goto L_8006A580;
    }
    // 0x8006A568: nop

    // 0x8006A56C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A570: jal         0x80071380
    // 0x8006A574: addiu       $a0, $a0, 0xFD0
    ctx->r4 = ADD32(ctx->r4, 0XFD0);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006A574: addiu       $a0, $a0, 0xFD0
    ctx->r4 = ADD32(ctx->r4, 0XFD0);
    after_0:
    // 0x8006A578: b           L_8006A5B0
    // 0x8006A57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A5B0;
    // 0x8006A57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A580:
    // 0x8006A580: jal         0x80069FE4
    // 0x8006A584: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    func_80069FE4(rdram, ctx);
        goto after_1;
    // 0x8006A584: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x8006A588: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006A58C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A590: bne         $v0, $zero, L_8006A5AC
    if (ctx->r2 != 0) {
        // 0x8006A594: sw          $v0, 0x24($t8)
        MEM_W(0X24, ctx->r24) = ctx->r2;
            goto L_8006A5AC;
    }
    // 0x8006A594: sw          $v0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r2;
    // 0x8006A598: addiu       $a0, $a0, 0xFE0
    ctx->r4 = ADD32(ctx->r4, 0XFE0);
    // 0x8006A59C: jal         0x80071380
    // 0x8006A5A0: addiu       $a1, $zero, 0x238
    ctx->r5 = ADD32(0, 0X238);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8006A5A0: addiu       $a1, $zero, 0x238
    ctx->r5 = ADD32(0, 0X238);
    after_2:
    // 0x8006A5A4: b           L_8006A5B0
    // 0x8006A5A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A5B0;
    // 0x8006A5A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A5AC:
    // 0x8006A5AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A5B0:
    // 0x8006A5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A5B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A5B8: jr          $ra
    // 0x8006A5BC: nop

    return;
    // 0x8006A5BC: nop

;}
RECOMP_FUNC void func_800035B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800035B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800035BC: jal         0x8000363C
    // 0x800035C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8000363C(rdram, ctx);
        goto after_0;
    // 0x800035C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800035C4: beq         $v0, $zero, L_800035E4
    if (ctx->r2 == 0) {
        // 0x800035C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800035E4;
    }
    // 0x800035C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800035CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800035D0: jal         0x8000ACD0
    // 0x800035D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000ACD0(rdram, ctx);
        goto after_1;
    // 0x800035D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800035D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800035DC: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x800035E0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800035E4:
    // 0x800035E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800035E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800035EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800035F0: jr          $ra
    // 0x800035F4: nop

    return;
    // 0x800035F4: nop

;}
RECOMP_FUNC void func_80078A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078A40: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80078A44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80078A48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80078A4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80078A50: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80078A54: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80078A58: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80078A5C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80078A60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80078A64: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80078A68: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80078A6C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80078A70: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80078A74: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80078A78: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80078A7C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80078A80: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80078A84: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80078A88: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80078A8C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80078A90: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80078A94: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80078A98: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80078A9C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80078AA0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80078AA4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80078AA8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80078AAC: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80078AB0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80078AB4: lhu         $a1, 0xA($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XA);
    // 0x80078AB8: lbu         $a2, 0x24($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X24);
    // 0x80078ABC: jal         0x80077338
    // 0x80078AC0: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80078AC0: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_0:
    // 0x80078AC4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80078AC8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80078ACC: lbu         $a1, 0x4($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X4);
    // 0x80078AD0: lbu         $a2, 0x5($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X5);
    // 0x80078AD4: jal         0x8007711C
    // 0x80078AD8: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80078AD8: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    after_1:
    // 0x80078ADC: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80078AE0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80078AE4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80078AE8: beq         $v1, $zero, L_80078B04
    if (ctx->r3 == 0) {
        // 0x80078AEC: addiu       $t1, $t9, 0x8
        ctx->r9 = ADD32(ctx->r25, 0X8);
            goto L_80078B04;
    }
    // 0x80078AEC: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80078AF0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80078AF4: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80078AF8: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x80078AFC: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x80078B00: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
L_80078B04:
    // 0x80078B04: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80078B08: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80078B0C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80078B10: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80078B14: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80078B18: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80078B1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80078B20: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80078B24: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80078B28: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80078B2C: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
    // 0x80078B30: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80078B34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80078B38: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80078B3C: jal         0x800780F0
    // 0x80078B40: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800780F0(rdram, ctx);
        goto after_2;
    // 0x80078B40: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_2:
    // 0x80078B44: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80078B48: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80078B4C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80078B50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80078B54: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80078B58: jr          $ra
    // 0x80078B5C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80078B5C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80409EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409EE0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80409EE4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80409EE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80409EEC: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(11, 0X1714) << 16);
    // 0x80409EF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80409EF4: addiu       $t6, $t6, -0x6F1C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(11, 0X1714));
    // 0x80409EF8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80409EFC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80409F00: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80409F04: jal         0x80409CD0
    // 0x80409F08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80409CD0(rdram, ctx);
        goto after_0;
    // 0x80409F08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80409F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80409F10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80409F14: jr          $ra
    // 0x80409F18: nop

    return;
    // 0x80409F18: nop

;}
RECOMP_FUNC void func_8057E620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E620: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8057E624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057E628: lw          $v0, 0x2CC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2CC);
    // 0x8057E62C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8057E630: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8057E634: bne         $v0, $zero, L_8057E6F4
    if (ctx->r2 != 0) {
        // 0x8057E638: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8057E6F4;
    }
    // 0x8057E638: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8057E63C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057E640: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8057E644: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8057E648: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8057E64C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8057E650: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10C0) << 16);
    // 0x8057E654: swc1        $f2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f2.u32l;
    // 0x8057E658: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8057E65C: lwc1        $f6, -0x1400($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10C0));
    // 0x8057E660: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8057E664: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10C4) << 16);
    // 0x8057E668: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x8057E66C: lwc1        $f8, 0x2D0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2D0);
    // 0x8057E670: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8057E674: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8057E678: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8057E67C: lw          $t6, 0x2C8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C8);
    // 0x8057E680: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8057E684: sw          $t7, 0x2C8($a1)
    MEM_W(0X2C8, ctx->r5) = ctx->r15;
    // 0x8057E688: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8057E68C: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057E690: lwc1        $f18, -0x13FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10C4));
    // 0x8057E694: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8057E698: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8057E69C: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057E6A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8057E6A4: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10C8) << 16);
    // 0x8057E6A8: lwc1        $f8, -0x13F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10C8));
    // 0x8057E6AC: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10CC) << 16);
    // 0x8057E6B0: lwc1        $f10, -0x13F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10CC));
    // 0x8057E6B4: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8057E6B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8057E6BC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8057E6C0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8057E6C4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8057E6C8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8057E6CC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8057E6D0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8057E6D4: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8057E6D8: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8057E6DC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8057E6E0: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x8057E6E4: jalr        $t9
    // 0x8057E6E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8057E6E8: nop

    after_0:
    // 0x8057E6EC: b           L_8057E7C8
    // 0x8057E6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8057E7C8;
    // 0x8057E6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057E6F4:
    // 0x8057E6F4: sw          $t1, 0x2CC($a1)
    MEM_W(0X2CC, ctx->r5) = ctx->r9;
    // 0x8057E6F8: lw          $v1, 0x1E0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1E0);
    // 0x8057E6FC: beq         $v1, $zero, L_8057E70C
    if (ctx->r3 == 0) {
        // 0x8057E700: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_8057E70C;
    }
    // 0x8057E700: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8057E704: b           L_8057E7C4
    // 0x8057E708: sw          $t2, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r10;
        goto L_8057E7C4;
    // 0x8057E708: sw          $t2, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r10;
L_8057E70C:
    // 0x8057E70C: jal         0x800653D8
    // 0x8057E710: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8057E710: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_1:
    // 0x8057E714: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8057E718: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x8057E71C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8057E720: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8057E724: sw          $t4, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r12;
    // 0x8057E728: jal         0x800653D8
    // 0x8057E72C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8057E72C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_2:
    // 0x8057E730: andi        $t6, $v0, 0x1F
    ctx->r14 = ctx->r2 & 0X1F;
    // 0x8057E734: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8057E738: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8057E73C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8057E740: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8057E744: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8057E748: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8057E74C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8057E750: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8057E754: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10D0) << 16);
    // 0x8057E758: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8057E75C: lwc1        $f18, -0x13F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10D0));
    // 0x8057E760: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8057E764: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8057E768: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8057E76C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8057E770: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10D4) << 16);
    // 0x8057E774: lwc1        $f8, -0x13EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10D4));
    // 0x8057E778: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8057E77C: lwc1        $f16, 0x88($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8057E780: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(393, 0X10D8) << 16);
    // 0x8057E784: lwc1        $f10, -0x13E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(393, 0X10D8));
    // 0x8057E788: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8057E78C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8057E790: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8057E794: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8057E798: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8057E79C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8057E7A0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8057E7A4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8057E7A8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8057E7AC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8057E7B0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8057E7B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8057E7B8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8057E7BC: jalr        $t9
    // 0x8057E7C0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8057E7C0: nop

    after_3:
L_8057E7C4:
    // 0x8057E7C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057E7C8:
    // 0x8057E7C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8057E7CC: jr          $ra
    // 0x8057E7D0: nop

    return;
    // 0x8057E7D0: nop

;}
RECOMP_FUNC void func_80437904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437904: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80437908: lw          $v1, -0x77F0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X77F0);
    // 0x8043790C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80437910: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
    // 0x80437914: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80437918: beql        $a1, $zero, L_80437958
    if (ctx->r5 == 0) {
        // 0x8043791C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80437958;
    }
    goto skip_0;
    // 0x8043791C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80437920:
    // 0x80437920: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80437924: beq         $v1, $zero, L_8043794C
    if (ctx->r3 == 0) {
        // 0x80437928: nop
    
            goto L_8043794C;
    }
    // 0x80437928: nop

    // 0x8043792C: beq         $a2, $v1, L_80437944
    if (ctx->r6 == ctx->r3) {
        // 0x80437930: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80437944;
    }
    // 0x80437930: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80437934: bnel        $a0, $v1, L_80437948
    if (ctx->r4 != ctx->r3) {
        // 0x80437938: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_80437948;
    }
    goto skip_1;
    // 0x80437938: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_1:
    // 0x8043793C: jr          $ra
    // 0x80437940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80437940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80437944:
    // 0x80437944: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
L_80437948:
    // 0x80437948: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_8043794C:
    // 0x8043794C: bne         $a1, $zero, L_80437920
    if (ctx->r5 != 0) {
        // 0x80437950: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80437920;
    }
    // 0x80437950: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80437954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80437958:
    // 0x80437958: jr          $ra
    // 0x8043795C: nop

    return;
    // 0x8043795C: nop

;}
RECOMP_FUNC void func_8052E628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E628: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052E62C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052E630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052E634: jal         0x8052E144
    // 0x8052E638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8052E144(rdram, ctx);
        goto after_0;
    // 0x8052E638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8052E63C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8052E640: addiu       $at, $zero, 0x41A8
    ctx->r1 = ADD32(0, 0X41A8);
    // 0x8052E644: beq         $v0, $at, L_8052E664
    if (ctx->r2 == ctx->r1) {
        // 0x8052E648: addiu       $at, $zero, 0x41A9
        ctx->r1 = ADD32(0, 0X41A9);
            goto L_8052E664;
    }
    // 0x8052E648: addiu       $at, $zero, 0x41A9
    ctx->r1 = ADD32(0, 0X41A9);
    // 0x8052E64C: beq         $v0, $at, L_8052E664
    if (ctx->r2 == ctx->r1) {
        // 0x8052E650: addiu       $at, $zero, 0x41AA
        ctx->r1 = ADD32(0, 0X41AA);
            goto L_8052E664;
    }
    // 0x8052E650: addiu       $at, $zero, 0x41AA
    ctx->r1 = ADD32(0, 0X41AA);
    // 0x8052E654: beq         $v0, $at, L_8052E664
    if (ctx->r2 == ctx->r1) {
        // 0x8052E658: addiu       $at, $zero, 0x41AB
        ctx->r1 = ADD32(0, 0X41AB);
            goto L_8052E664;
    }
    // 0x8052E658: addiu       $at, $zero, 0x41AB
    ctx->r1 = ADD32(0, 0X41AB);
    // 0x8052E65C: bne         $v0, $at, L_8052E66C
    if (ctx->r2 != ctx->r1) {
        // 0x8052E660: nop
    
            goto L_8052E66C;
    }
    // 0x8052E660: nop

L_8052E664:
    // 0x8052E664: jal         0x8052E5F4
    // 0x8052E668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052E5F4(rdram, ctx);
        goto after_1;
    // 0x8052E668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8052E66C:
    // 0x8052E66C: jal         0x8052E16C
    // 0x8052E670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052E16C(rdram, ctx);
        goto after_2;
    // 0x8052E670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8052E674: jal         0x8052E430
    // 0x8052E678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052E430(rdram, ctx);
        goto after_3;
    // 0x8052E678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8052E67C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052E680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8052E684: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052E688: jr          $ra
    // 0x8052E68C: nop

    return;
    // 0x8052E68C: nop

;}
RECOMP_FUNC void func_80446640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446640: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446644: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80446648: jr          $ra
    // 0x8044664C: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    return;
    // 0x8044664C: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80453AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453AEC: jal         0x804539F0
    // 0x80453AF0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_804539F0(rdram, ctx);
        goto after_0;
    // 0x80453AF0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80453AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453AFC: jr          $ra
    // 0x80453B00: nop

    return;
    // 0x80453B00: nop

;}
RECOMP_FUNC void func_80052464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052464: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80052468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005246C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80052470: jal         0x8007C61C
    // 0x80052474: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8007C61C(rdram, ctx);
        goto after_0;
    // 0x80052474: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052478: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005247C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80052480: addiu       $a1, $a1, -0x4D70
    ctx->r5 = ADD32(ctx->r5, -0X4D70);
    // 0x80052484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052488: jal         0x8008DFA0
    // 0x8005248C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    osPfsInitPak_recomp(rdram, ctx);
        goto after_1;
    // 0x8005248C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80052490: bne         $v0, $zero, L_80052514
    if (ctx->r2 != 0) {
        // 0x80052494: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80052514;
    }
    // 0x80052494: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052498: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8005249C: addiu       $t6, $t6, 0xAD0
    ctx->r14 = ADD32(ctx->r14, 0XAD0);
    // 0x800524A0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800524A4: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800524A8: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800524AC: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800524B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800524B4: addiu       $a3, $a3, 0xAC0
    ctx->r7 = ADD32(ctx->r7, 0XAC0);
    // 0x800524B8: lw          $a2, 0x5CC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CC4);
    // 0x800524BC: lhu         $a1, 0x5CC0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5CC0);
    // 0x800524C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800524C4: jal         0x800892E0
    // 0x800524C8: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    osPfsFindFile_recomp(rdram, ctx);
        goto after_2;
    // 0x800524C8: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    after_2:
    // 0x800524CC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800524D0: bne         $v0, $at, L_800524EC
    if (ctx->r2 != ctx->r1) {
        // 0x800524D4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800524EC;
    }
    // 0x800524D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800524D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800524DC: jal         0x80052354
    // 0x800524E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80052354(rdram, ctx);
        goto after_3;
    // 0x800524E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x800524E4: b           L_80052514
    // 0x800524E8: nop

        goto L_80052514;
    // 0x800524E8: nop

L_800524EC:
    // 0x800524EC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800524F0: addiu       $a2, $a2, -0x4D08
    ctx->r6 = ADD32(ctx->r6, -0X4D08);
    // 0x800524F4: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x800524F8: jal         0x8008DCB0
    // 0x800524FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    osPfsFileState_recomp(rdram, ctx);
        goto after_4;
    // 0x800524FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80052500: bne         $v0, $zero, L_80052514
    if (ctx->r2 != 0) {
        // 0x80052504: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80052514;
    }
    // 0x80052504: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80052508: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8005250C: jal         0x80052300
    // 0x80052510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052300(rdram, ctx);
        goto after_5;
    // 0x80052510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80052514:
    // 0x80052514: jal         0x8007C640
    // 0x80052518: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8007C640(rdram, ctx);
        goto after_6;
    // 0x80052518: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x8005251C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052520: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80052524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052528: jr          $ra
    // 0x8005252C: nop

    return;
    // 0x8005252C: nop

;}
RECOMP_FUNC void func_80022360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022360: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80022364: lw          $t6, -0x76C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76C0);
    // 0x80022368: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002236C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022370: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022374: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80022378: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002237C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80022380: lhu         $a0, -0x63C8($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X63C8);
    // 0x80022384: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022388: jal         0x80047090
    // 0x8002238C: sh          $a0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r4;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8002238C: sh          $a0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r4;
    after_0:
    // 0x80022390: lhu         $t8, 0x52($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X52);
    // 0x80022394: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x80022398: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    // 0x8002239C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800223A0: or          $a0, $v0, $t9
    ctx->r4 = ctx->r2 | ctx->r25;
    // 0x800223A4: ori         $a0, $a0, 0x1800
    ctx->r4 = ctx->r4 | 0X1800;
    // 0x800223A8: jal         0x8004613C
    // 0x800223AC: lw          $a3, 0x8C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x800223AC: lw          $a3, 0x8C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8C);
    after_1:
    // 0x800223B0: beq         $v0, $zero, L_80022434
    if (ctx->r2 == 0) {
        // 0x800223B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80022434;
    }
    // 0x800223B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800223B8: jal         0x80044194
    // 0x800223BC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x800223BC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_2:
    // 0x800223C0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800223C4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800223C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800223CC: sw          $t0, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r8;
    // 0x800223D0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800223D4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800223D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800223DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800223E0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800223E4: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800223E8: lwc1        $f10, -0x394($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X394);
    // 0x800223EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800223F0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800223F4: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800223F8: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x800223FC: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x80022400: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80022404: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80022408: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8002240C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80022410: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80022414: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80022418: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8002241C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80022420: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80022424: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80022428: lw          $t9, 0x10($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X10);
    // 0x8002242C: jalr        $t9
    // 0x80022430: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80022430: nop

    after_3:
L_80022434:
    // 0x80022434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022438: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002243C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80022440: jr          $ra
    // 0x80022444: nop

    return;
    // 0x80022444: nop

;}
RECOMP_FUNC void pad_press_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FC04: jr          $ra
    // 0x8007FC08: lb          $v0, 0xE($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XE);
    return;
    // 0x8007FC08: lb          $v0, 0xE($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XE);
;}
RECOMP_FUNC void func_80742C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80742C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80742C90: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742C94: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80742C98: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80742C9C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80742CA0: lw          $v1, 0x6E60($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E60);
    // 0x80742CA4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80742CA8: beql        $v1, $zero, L_80742CC4
    if (ctx->r3 == 0) {
        // 0x80742CAC: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80742CC4;
    }
    goto skip_0;
    // 0x80742CAC: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80742CB0: jal         0x807429D4
    // 0x80742CB4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    func_807429D4(rdram, ctx);
        goto after_0;
    // 0x80742CB4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_0:
    // 0x80742CB8: b           L_80742CE8
    // 0x80742CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742CE8;
    // 0x80742CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742CC0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80742CC4:
    // 0x80742CC4: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80742CC8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80742CCC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80742CD0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80742CD4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80742CD8: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80742CDC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80742CE0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80742CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742CE8:
    // 0x80742CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80742CEC: jr          $ra
    // 0x80742CF0: nop

    return;
    // 0x80742CF0: nop

;}
RECOMP_FUNC void func_804305F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804305F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804305FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430600: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80430604: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80430608: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043060C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X38B8) << 16);
    // 0x80430610: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80430614: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80430618: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043061C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80430620: lw          $t8, 0x1998($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X38B8));
    // 0x80430624: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80430628: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043062C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80430630: jal         0x80048490
    // 0x80430634: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80430634: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80430638: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043063C: jal         0x80048378
    // 0x80430640: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80430640: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80430644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043064C: jr          $ra
    // 0x80430650: nop

    return;
    // 0x80430650: nop

;}
RECOMP_FUNC void func_8000B808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B80C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000B810: bne         $a0, $at, L_8000B820
    if (ctx->r4 != ctx->r1) {
        // 0x8000B814: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000B820;
    }
    // 0x8000B814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B818: b           L_8000B8CC
    // 0x8000B81C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B8CC;
    // 0x8000B81C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B820:
    // 0x8000B820: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B824: jal         0x800066A8
    // 0x8000B828: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800066A8(rdram, ctx);
        goto after_0;
    // 0x8000B828: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000B82C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B830: bne         $v0, $zero, L_8000B854
    if (ctx->r2 != 0) {
        // 0x8000B834: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8000B854;
    }
    // 0x8000B834: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B838: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8000B83C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8000B840: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x8000B844: addu        $t6, $a0, $at
    ctx->r14 = ADD32(ctx->r4, ctx->r1);
    // 0x8000B848: sw          $t6, 0x1E98($a2)
    MEM_W(0X1E98, ctx->r6) = ctx->r14;
    // 0x8000B84C: b           L_8000B8CC
    // 0x8000B850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B8CC;
    // 0x8000B850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B854:
    // 0x8000B854: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8000B858: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x8000B85C: lw          $t7, 0x1D78($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1D78);
    // 0x8000B860: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8000B864: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8000B868: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000B86C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8000B870: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000B874: sll         $t0, $a0, 8
    ctx->r8 = S32(ctx->r4 << 8);
    // 0x8000B878: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8000B87C: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000B880: bne         $at, $zero, L_8000B898
    if (ctx->r1 != 0) {
        // 0x8000B884: lui         $at, 0x300
        ctx->r1 = S32(0X300 << 16);
            goto L_8000B898;
    }
    // 0x8000B884: lui         $at, 0x300
    ctx->r1 = S32(0X300 << 16);
    // 0x8000B888: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8000B88C: sw          $t2, 0x1E98($a2)
    MEM_W(0X1E98, ctx->r6) = ctx->r10;
    // 0x8000B890: b           L_8000B8CC
    // 0x8000B894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B8CC;
    // 0x8000B894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B898:
    // 0x8000B898: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8000B89C: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8000B8A0: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x8000B8A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000B8A8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x8000B8AC: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8000B8B0: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000B8B4: bne         $v1, $zero, L_8000B8C8
    if (ctx->r3 != 0) {
        // 0x8000B8B8: addu        $t8, $t7, $at
        ctx->r24 = ADD32(ctx->r15, ctx->r1);
            goto L_8000B8C8;
    }
    // 0x8000B8B8: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8000B8BC: sw          $t8, 0x1E98($a2)
    MEM_W(0X1E98, ctx->r6) = ctx->r24;
    // 0x8000B8C0: b           L_8000B8CC
    // 0x8000B8C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000B8CC;
    // 0x8000B8C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B8C8:
    // 0x8000B8C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B8CC:
    // 0x8000B8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B8D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B8D4: jr          $ra
    // 0x8000B8D8: nop

    return;
    // 0x8000B8D8: nop

;}
RECOMP_FUNC void func_800778E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800778EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800778F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800778F4: lwc1        $f4, 0x27E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X27E8);
    // 0x800778F8: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800778FC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80077900: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80077904: jal         0x8008D3C0
    // 0x80077908: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    coss(rdram, ctx);
        goto after_0;
    // 0x80077908: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8007790C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80077910: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077914: lwc1        $f18, 0x27EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X27EC);
    // 0x80077918: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007791C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077920: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80077924: nop

    // 0x80077928: jr          $ra
    // 0x8007792C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007792C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_807AF010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF010: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807AF014: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807AF018: lw          $t6, 0xAA0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAA0);
    // 0x807AF01C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x807AF020: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807AF024: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x807AF028: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807AF02C: lhu         $t8, 0x6300($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X6300);
    // 0x807AF030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF034: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x807AF038: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x807AF03C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x807AF040: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AF044: lw          $t9, 0xA68($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA68);
    // 0x807AF048: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x807AF04C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807AF050: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807AF054: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x807AF058: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x807AF05C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x807AF060: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x807AF064: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x807AF068: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x807AF06C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x807AF070: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x807AF074: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x807AF078: lw          $t9, 0x54($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X54);
    // 0x807AF07C: jalr        $t9
    // 0x807AF080: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807AF080: nop

    after_0:
    // 0x807AF084: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x807AF088: beq         $v0, $zero, L_807AF0B4
    if (ctx->r2 == 0) {
        // 0x807AF08C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807AF0B4;
    }
    // 0x807AF08C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807AF090: lw          $a2, 0x1DC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1DC);
    // 0x807AF094: lw          $a1, 0x1D8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1D8);
    // 0x807AF098: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x807AF09C: jal         0x80048BE8
    // 0x807AF0A0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_1;
    // 0x807AF0A0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_1:
    // 0x807AF0A4: jal         0x800447C8
    // 0x807AF0A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x807AF0A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x807AF0AC: b           L_807AF0C0
    // 0x807AF0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807AF0C0;
    // 0x807AF0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AF0B4:
    // 0x807AF0B4: jal         0x800445A4
    // 0x807AF0B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x807AF0B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x807AF0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AF0C0:
    // 0x807AF0C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x807AF0C4: jr          $ra
    // 0x807AF0C8: nop

    return;
    // 0x807AF0C8: nop

    // 0x807AF0CC: nop

;}
RECOMP_FUNC void func_8003B8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B8B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B8BC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8003B8C0: sll         $t8, $a1, 9
    ctx->r24 = S32(ctx->r5 << 9);
    // 0x8003B8C4: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x8003B8C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B8CC: jal         0x8004590C
    // 0x8003B8D0: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8003B8D0: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    after_0:
    // 0x8003B8D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B8D8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B8DC: sw          $t9, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r25;
    // 0x8003B8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B8E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B8E8: jr          $ra
    // 0x8003B8EC: nop

    return;
    // 0x8003B8EC: nop

;}
RECOMP_FUNC void func_806B1578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1578: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806B157C: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(598, 0X14E0) << 16);
    // 0x806B1580: addiu       $t6, $t6, 0x1470
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(598, 0X14E0));
    // 0x806B1584: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806B1588: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(598, 0X154C) << 16);
    // 0x806B158C: addiu       $t9, $t9, 0x14DC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(598, 0X154C));
    // 0x806B1590: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x806B1594: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x806B1598: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806B159C: jr          $ra
    // 0x806B15A0: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x806B15A0: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_8076DF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DF70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076DF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076DF78: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076DF7C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8076DF80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8076DF84: jal         0x80065728
    // 0x8076DF88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8076DF88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8076DF8C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8076DF90: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8076DF94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076DF98: nop

    // 0x8076DF9C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8076DFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076DFA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076DFA8: jr          $ra
    // 0x8076DFAC: nop

    return;
    // 0x8076DFAC: nop

;}
RECOMP_FUNC void func_8006CA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA74: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006CA78: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8006CA7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CA80: bne         $a1, $zero, L_8006CA9C
    if (ctx->r5 != 0) {
        // 0x8006CA84: lhu         $v1, 0x64($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X64);
            goto L_8006CA9C;
    }
    // 0x8006CA84: lhu         $v1, 0x64($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X64);
    // 0x8006CA88: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x8006CA8C: beql        $t6, $zero, L_8006CAD8
    if (ctx->r14 == 0) {
        // 0x8006CA90: swc1        $f12, 0x60($v0)
        MEM_W(0X60, ctx->r2) = ctx->f12.u32l;
            goto L_8006CAD8;
    }
    goto skip_0;
    // 0x8006CA90: swc1        $f12, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f12.u32l;
    skip_0:
    // 0x8006CA94: jr          $ra
    // 0x8006CA98: nop

    return;
    // 0x8006CA98: nop

L_8006CA9C:
    // 0x8006CA9C: bne         $a1, $at, L_8006CAD8
    if (ctx->r5 != ctx->r1) {
        // 0x8006CAA0: nop
    
            goto L_8006CAD8;
    }
    // 0x8006CAA0: nop

    // 0x8006CAA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006CAA8: nop

    // 0x8006CAAC: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8006CAB0: nop

    // 0x8006CAB4: bc1fl       L_8006CACC
    if (!c1cs) {
        // 0x8006CAB8: ori         $v1, $v1, 0x2
        ctx->r3 = ctx->r3 | 0X2;
            goto L_8006CACC;
    }
    goto skip_1;
    // 0x8006CAB8: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    skip_1:
    // 0x8006CABC: andi        $v1, $v1, 0xFFFD
    ctx->r3 = ctx->r3 & 0XFFFD;
    // 0x8006CAC0: b           L_8006CAD0
    // 0x8006CAC4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_8006CAD0;
    // 0x8006CAC4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8006CAC8: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
L_8006CACC:
    // 0x8006CACC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8006CAD0:
    // 0x8006CAD0: sh          $v1, 0x64($v0)
    MEM_H(0X64, ctx->r2) = ctx->r3;
    // 0x8006CAD4: swc1        $f12, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f12.u32l;
L_8006CAD8:
    // 0x8006CAD8: jr          $ra
    // 0x8006CADC: nop

    return;
    // 0x8006CADC: nop

;}
RECOMP_FUNC void func_8074155C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8074155C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80741560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80741564: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80741568: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8074156C: addiu       $a0, $zero, 0x464B
    ctx->r4 = ADD32(0, 0X464B);
    // 0x80741570: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x80741574: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80741578: jal         0x80046E88
    // 0x8074157C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x8074157C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80741580: beq         $v0, $zero, L_80741598
    if (ctx->r2 == 0) {
        // 0x80741584: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80741598;
    }
    // 0x80741584: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80741588: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x8074158C: sw          $a3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r7;
    // 0x80741590: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80741594: sw          $v0, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->r2;
L_80741598:
    // 0x80741598: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8074159C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807415A0: jal         0x80741E44
    // 0x807415A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80741E44(rdram, ctx);
        goto after_1;
    // 0x807415A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x807415A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807415AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807415B0: jr          $ra
    // 0x807415B4: nop

    return;
    // 0x807415B4: nop

;}
RECOMP_FUNC void func_8079F6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F6A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079F6A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079F6AC: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8079F6B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8079F6B4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8079F6B8: beq         $v0, $at, L_8079F6F4
    if (ctx->r2 == ctx->r1) {
        // 0x8079F6BC: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_8079F6F4;
    }
    // 0x8079F6BC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8079F6C0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8079F6C4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8079F6C8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8079F6CC: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(838, 0XE50) << 16);
    // 0x8079F6D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8079F6D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8079F6D8: lw          $t7, 0x4B0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(838, 0XE50));
    // 0x8079F6DC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8079F6E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8079F6E4: jal         0x80048490
    // 0x8079F6E8: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8079F6E8: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x8079F6EC: b           L_8079F724
    // 0x8079F6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079F724;
    // 0x8079F6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079F6F4:
    // 0x8079F6F4: lw          $t2, 0x12C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X12C);
    // 0x8079F6F8: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(838, 0XE50) << 16);
    // 0x8079F6FC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8079F700: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8079F704: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8079F708: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8079F70C: lw          $t1, 0x4B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(838, 0XE50));
    // 0x8079F710: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8079F714: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8079F718: jal         0x80048490
    // 0x8079F71C: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    func_80048490(rdram, ctx);
        goto after_1;
    // 0x8079F71C: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    after_1:
    // 0x8079F720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079F724:
    // 0x8079F724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079F728: jr          $ra
    // 0x8079F72C: nop

    return;
    // 0x8079F72C: nop

;}
RECOMP_FUNC void func_80067BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067BC4: jal         0x80067B74
    // 0x80067BC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80067B74(rdram, ctx);
        goto after_0;
    // 0x80067BC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80067BCC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80067BD0: sh          $v0, -0x6A50($at)
    MEM_H(-0X6A50, ctx->r1) = ctx->r2;
    // 0x80067BD4: jal         0x80067B74
    // 0x80067BD8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80067B74(rdram, ctx);
        goto after_1;
    // 0x80067BD8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80067BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BE0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067BE4: addiu       $v1, $v1, -0x6A50
    ctx->r3 = ADD32(ctx->r3, -0X6A50);
    // 0x80067BE8: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80067BEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80067BF0: jr          $ra
    // 0x80067BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805DAA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAA20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DAA24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805DAA28: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805DAA2C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805DAA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DAA34: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805DAA38: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x805DAA3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805DAA40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805DAA44: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805DAA48: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805DAA4C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805DAA50: lui         $t2, 0x805E
    ctx->r10 = S32(RELOC_HI16(477, 0XB6C) << 16);
    // 0x805DAA54: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805DAA58: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805DAA5C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805DAA60: lw          $t2, -0x5454($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(477, 0XB6C));
    // 0x805DAA64: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805DAA68: jal         0x805DA8D4
    // 0x805DAA6C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_805DA8D4(rdram, ctx);
        goto after_0;
    // 0x805DAA6C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x805DAA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DAA74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DAA78: jr          $ra
    // 0x805DAA7C: nop

    return;
    // 0x805DAA7C: nop

;}
RECOMP_FUNC void func_8075FF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FF58: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8075FF5C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8075FF60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8075FF64: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8075FF68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8075FF6C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8075FF70: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8075FF74: lui         $t1, 0x8076
    ctx->r9 = S32(RELOC_HI16(760, 0X498) << 16);
    // 0x8075FF78: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8075FF7C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8075FF80: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8075FF84: lw          $t1, 0x18($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(760, 0X498));
    // 0x8075FF88: jr          $ra
    // 0x8075FF8C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8075FF8C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8066B840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B848: jal         0x8066B7C0
    // 0x8066B84C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066B7C0(rdram, ctx);
        goto after_0;
    // 0x8066B84C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8066B85C: jal         0x8066B970
    // 0x8066B860: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066B970(rdram, ctx);
        goto after_1;
    // 0x8066B860: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8066B864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066B86C: jr          $ra
    // 0x8066B870: nop

    return;
    // 0x8066B870: nop

;}
RECOMP_FUNC void func_8040ECBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040ECBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040ECC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040ECC4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040ECC8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8040ECCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040ECD0: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8040ECD4: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040ECD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040ECDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8040ECE0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8040ECE4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8040ECE8: nop

    // 0x8040ECEC: bc1fl       L_8040ED00
    if (!c1cs) {
        // 0x8040ECF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040ED00;
    }
    goto skip_0;
    // 0x8040ECF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040ECF4: jal         0x8040F0B8
    // 0x8040ECF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040ECF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8040ECFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040ED00:
    // 0x8040ED00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040ED04: jr          $ra
    // 0x8040ED08: nop

    return;
    // 0x8040ED08: nop

;}
RECOMP_FUNC void func_8043E960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E964: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8043E968: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8043E96C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043E970: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8043E974: jal         0x80047090
    // 0x8043E978: addiu       $a0, $zero, 0x406C
    ctx->r4 = ADD32(0, 0X406C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8043E978: addiu       $a0, $zero, 0x406C
    ctx->r4 = ADD32(0, 0X406C);
    after_0:
    // 0x8043E97C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043E980: lui         $at, 0x406C
    ctx->r1 = S32(0X406C << 16);
    // 0x8043E984: ori         $at, $at, 0x1800
    ctx->r1 = ctx->r1 | 0X1800;
    // 0x8043E988: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8043E98C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8043E990: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8043E994: jal         0x8004613C
    // 0x8043E998: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8043E998: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8043E99C: bne         $v0, $zero, L_8043E9AC
    if (ctx->r2 != 0) {
        // 0x8043E9A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8043E9AC;
    }
    // 0x8043E9A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8043E9A4: b           L_8043EA2C
    // 0x8043E9A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043EA2C;
    // 0x8043E9A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043E9AC:
    // 0x8043E9AC: jal         0x8043E814
    // 0x8043E9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043E814(rdram, ctx);
        goto after_2;
    // 0x8043E9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043E9B4: bne         $v0, $zero, L_8043E9CC
    if (ctx->r2 != 0) {
        // 0x8043E9B8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8043E9CC;
    }
    // 0x8043E9B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8043E9BC: jal         0x800447C8
    // 0x8043E9C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8043E9C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043E9C4: b           L_8043EA2C
    // 0x8043E9C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043EA2C;
    // 0x8043E9C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043E9CC:
    // 0x8043E9CC: jal         0x80047F9C
    // 0x8043E9D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8043E9D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8043E9D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8043E9D8: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x8043E9DC: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8043E9E0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B94) << 16);
    // 0x8043E9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043E9E8: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8043E9EC: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8043E9F0: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8043E9F4: lwc1        $f10, -0x142C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B94));
    // 0x8043E9F8: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8043E9FC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043EA00: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x8043EA04: lw          $t7, 0x138($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X138);
    // 0x8043EA08: jal         0x8005FDC4
    // 0x8043EA0C: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x8043EA0C: sw          $t7, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r15;
    after_5:
    // 0x8043EA10: lhu         $t8, 0xC($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XC);
    // 0x8043EA14: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8043EA18: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8043EA1C: bne         $t8, $at, L_8043EA2C
    if (ctx->r24 != ctx->r1) {
        // 0x8043EA20: nop
    
            goto L_8043EA2C;
    }
    // 0x8043EA20: nop

    // 0x8043EA24: lw          $t9, 0x1F4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1F4);
    // 0x8043EA28: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
L_8043EA2C:
    // 0x8043EA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043EA30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8043EA34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8043EA38: jr          $ra
    // 0x8043EA3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8043EA3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005AA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AA68: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005AA6C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005AA70: lw          $t6, 0x3EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3EC);
    // 0x8005AA74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005AA78: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005AA7C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8005AA80: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8005AA84: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005AA88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005AA8C: addiu       $t9, $t8, 0x47C
    ctx->r25 = ADD32(ctx->r24, 0X47C);
    // 0x8005AA90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005AA94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005AA98: sw          $t9, 0x478($v0)
    MEM_W(0X478, ctx->r2) = ctx->r25;
    // 0x8005AA9C: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x8005AAA0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8005AAA4: addiu       $s3, $s3, 0x5284
    ctx->r19 = ADD32(ctx->r19, 0X5284);
    // 0x8005AAA8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005AAAC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8005AAB0:
    // 0x8005AAB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AAB4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005AAB8: jal         0x80065728
    // 0x8005AABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8005AABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005AAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AAC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005AAC8: jal         0x8005A994
    // 0x8005AACC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005A994(rdram, ctx);
        goto after_1;
    // 0x8005AACC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x8005AAD0: jal         0x8005A52C
    // 0x8005AAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005A52C(rdram, ctx);
        goto after_2;
    // 0x8005AAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005AAD8: jal         0x8005A824
    // 0x8005AADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005A824(rdram, ctx);
        goto after_3;
    // 0x8005AADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005AAE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005AAE4: bne         $s1, $s2, L_8005AAB0
    if (ctx->r17 != ctx->r18) {
        // 0x8005AAE8: addiu       $s0, $s0, 0x100
        ctx->r16 = ADD32(ctx->r16, 0X100);
            goto L_8005AAB0;
    }
    // 0x8005AAE8: addiu       $s0, $s0, 0x100
    ctx->r16 = ADD32(ctx->r16, 0X100);
    // 0x8005AAEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005AAF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005AAF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005AAF8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AAFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005AB00: jr          $ra
    // 0x8005AB04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005AB04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005AB08: nop

    // 0x8005AB0C: nop

;}
RECOMP_FUNC void func_806B291C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B291C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2920: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2924: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2928: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B292C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2930: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2934: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2938: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B293C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2940: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2944: jr          $ra
    // 0x806B2948: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2948: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8005EB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EB38: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8005EB3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005EB40: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8005EB44: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8005EB48: bne         $v0, $at, L_8005EB58
    if (ctx->r2 != ctx->r1) {
        // 0x8005EB4C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8005EB58;
    }
    // 0x8005EB4C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8005EB50: jr          $ra
    // 0x8005EB54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005EB54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EB58:
    // 0x8005EB58: lw          $t6, -0x76C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76C4);
    // 0x8005EB5C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8005EB60: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EB64: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8005EB68: beq         $a1, $zero, L_8005EB84
    if (ctx->r5 == 0) {
        // 0x8005EB6C: nop
    
            goto L_8005EB84;
    }
    // 0x8005EB6C: nop

    // 0x8005EB70: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
    // 0x8005EB74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EB78: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8005EB7C: bne         $t8, $at, L_8005EB8C
    if (ctx->r24 != ctx->r1) {
        // 0x8005EB80: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8005EB8C;
    }
    // 0x8005EB80: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8005EB84:
    // 0x8005EB84: jr          $ra
    // 0x8005EB88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005EB88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EB8C:
    // 0x8005EB8C: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8005EB90: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8005EB94: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x8005EB98: sh          $t0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r8;
    // 0x8005EB9C: lw          $t1, 0x30($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X30);
    // 0x8005EBA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8005EBA4: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x8005EBA8: lw          $t2, 0x34($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X34);
    // 0x8005EBAC: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8005EBB0: jr          $ra
    // 0x8005EBB4: nop

    return;
    // 0x8005EBB4: nop

;}
RECOMP_FUNC void func_80052CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052CA8: jr          $ra
    // 0x80052CAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80052CAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8007E3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E3D0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8007E3D4: addiu       $a2, $a2, -0x65B0
    ctx->r6 = ADD32(ctx->r6, -0X65B0);
    // 0x8007E3D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007E3DC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8007E3E0: addiu       $t7, $t7, -0x1270
    ctx->r15 = ADD32(ctx->r15, -0X1270);
    // 0x8007E3E4: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8007E3E8: beq         $at, $zero, L_8007E404
    if (ctx->r1 == 0) {
        // 0x8007E3EC: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_8007E404;
    }
    // 0x8007E3EC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8007E3F0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E3F4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8007E3F8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8007E3FC: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8007E400: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8007E404:
    // 0x8007E404: jr          $ra
    // 0x8007E408: nop

    return;
    // 0x8007E408: nop

;}
RECOMP_FUNC void func_8064AFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AFF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064AFFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064B000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064B004: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064B008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064B00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B010: blez        $v0, L_8064B024
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064B014: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064B024;
    }
    // 0x8064B014: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064B018: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064B01C: b           L_8064B050
    // 0x8064B020: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064B050;
    // 0x8064B020: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064B024:
    // 0x8064B024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064B028: jal         0x8064B3E0
    // 0x8064B02C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064B3E0(rdram, ctx);
        goto after_0;
    // 0x8064B02C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064B030: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064B034: jal         0x80067BBC
    // 0x8064B038: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064B038: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064B03C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064B040: jal         0x80067818
    // 0x8064B044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064B044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064B048: jal         0x8064A43C
    // 0x8064B04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064B04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064B050:
    // 0x8064B050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064B054: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064B058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064B05C: jr          $ra
    // 0x8064B060: nop

    return;
    // 0x8064B060: nop

;}
RECOMP_FUNC void func_804A1320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A1324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A1328: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804A132C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x804A1330: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x804A1334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A1338: lwc1        $f4, 0x6C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x804A133C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x804A1340: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x804A1344: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1348: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804A134C: lwc1        $f10, 0x70($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X70);
    // 0x804A1350: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A1354: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x804A1358: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804A135C: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x804A1360: lui         $t9, 0x804A
    ctx->r25 = S32(RELOC_HI16(173, 0X2FDC) << 16);
    // 0x804A1364: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x804A1368: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804A136C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804A1370: lw          $t9, 0x341C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(173, 0X2FDC));
    // 0x804A1374: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x804A1378: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x804A137C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x804A1380: jalr        $t9
    // 0x804A1384: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804A1384: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x804A1388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A138C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A1390: jr          $ra
    // 0x804A1394: nop

    return;
    // 0x804A1394: nop

;}
RECOMP_FUNC void func_8070FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FC30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070FC34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070FC38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8070FC3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8070FC40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8070FC44: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8070FC48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070FC4C: addiu       $a2, $zero, 0x59
    ctx->r6 = ADD32(0, 0X59);
    // 0x8070FC50: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x8070FC54: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8070FC58: bne         $at, $zero, L_8070FC68
    if (ctx->r1 != 0) {
        // 0x8070FC5C: sw          $v0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r2;
            goto L_8070FC68;
    }
    // 0x8070FC5C: sw          $v0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r2;
    // 0x8070FC60: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8070FC64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8070FC68:
    // 0x8070FC68: sra         $s1, $v0, 1
    ctx->r17 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8070FC6C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8070FC70: beq         $a1, $zero, L_8070FC9C
    if (ctx->r5 == 0) {
        // 0x8070FC74: andi        $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 & 0XFFFF;
            goto L_8070FC9C;
    }
    // 0x8070FC74: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8070FC78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8070FC7C: beq         $a1, $at, L_8070FCAC
    if (ctx->r5 == ctx->r1) {
        // 0x8070FC80: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8070FCAC;
    }
    // 0x8070FC80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8070FC84: beq         $a1, $at, L_8070FCC0
    if (ctx->r5 == ctx->r1) {
        // 0x8070FC88: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8070FCC0;
    }
    // 0x8070FC88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8070FC8C: beql        $a1, $at, L_8070FCD8
    if (ctx->r5 == ctx->r1) {
        // 0x8070FC90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8070FCD8;
    }
    goto skip_0;
    // 0x8070FC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8070FC94: b           L_8070FCEC
    // 0x8070FC98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8070FCEC;
    // 0x8070FC98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8070FC9C:
    // 0x8070FC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FCA0: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FCA4: jal         0x8005C27C
    // 0x8070FCA8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x8070FCA8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_0:
L_8070FCAC:
    // 0x8070FCAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FCB0: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FCB4: addiu       $a2, $zero, 0x51
    ctx->r6 = ADD32(0, 0X51);
    // 0x8070FCB8: jal         0x8005C27C
    // 0x8070FCBC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8070FCBC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
L_8070FCC0:
    // 0x8070FCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070FCC4: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FCC8: addiu       $a2, $zero, 0x49
    ctx->r6 = ADD32(0, 0X49);
    // 0x8070FCCC: jal         0x8005C27C
    // 0x8070FCD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x8070FCD0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8070FCD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8070FCD8:
    // 0x8070FCD8: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // 0x8070FCDC: addiu       $a2, $zero, 0x41
    ctx->r6 = ADD32(0, 0X41);
    // 0x8070FCE0: jal         0x8005C27C
    // 0x8070FCE4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x8070FCE4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8070FCE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8070FCEC:
    // 0x8070FCEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8070FCF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8070FCF4: jr          $ra
    // 0x8070FCF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8070FCF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800591EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800591EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800591F0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800591F4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800591F8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800591FC: negu        $t6, $a2
    ctx->r14 = SUB32(0, ctx->r6);
    // 0x80059200: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80059204: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80059208: beq         $at, $zero, L_8005926C
    if (ctx->r1 == 0) {
        // 0x8005920C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_8005926C;
    }
    // 0x8005920C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80059210: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80059214: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80059218: negu        $t0, $a3
    ctx->r8 = SUB32(0, ctx->r7);
    // 0x8005921C: lwc1        $f4, 0x9C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x80059220: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80059224: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80059228: nop

    // 0x8005922C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80059230: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80059234: beq         $at, $zero, L_8005926C
    if (ctx->r1 == 0) {
        // 0x80059238: slt         $at, $t0, $a1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8005926C;
    }
    // 0x80059238: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005923C: beql        $at, $zero, L_80059270
    if (ctx->r1 == 0) {
        // 0x80059240: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80059270;
    }
    goto skip_0;
    // 0x80059240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80059244: lwc1        $f8, 0xA0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XA0);
    // 0x80059248: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005924C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80059250: nop

    // 0x80059254: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x80059258: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8005925C: beql        $at, $zero, L_80059270
    if (ctx->r1 == 0) {
        // 0x80059260: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80059270;
    }
    goto skip_1;
    // 0x80059260: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80059264: jr          $ra
    // 0x80059268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80059268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005926C:
    // 0x8005926C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059270:
    // 0x80059270: jr          $ra
    // 0x80059274: nop

    return;
    // 0x80059274: nop

;}
RECOMP_FUNC void func_804C22D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C22D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C22DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C22E0: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804C22E4: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(203, 0X111C) << 16);
    // 0x804C22E8: addiu       $t8, $t8, 0x288C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(203, 0X111C));
    // 0x804C22EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C22F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804C22F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C22F8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804C22FC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C2300: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C2304: beql        $v1, $zero, L_804C233C
    if (ctx->r3 == 0) {
        // 0x804C2308: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C233C;
    }
    goto skip_0;
    // 0x804C2308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C230C: jalr        $v1
    // 0x804C2310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C2310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C2314: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C2318: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804C231C: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804C2320: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804C2324: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804C2328: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804C232C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804C2330: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804C2334: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804C2338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C233C:
    // 0x804C233C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C2340: jr          $ra
    // 0x804C2344: nop

    return;
    // 0x804C2344: nop

;}
RECOMP_FUNC void func_8003159C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003159C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800315A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800315A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800315A8: jal         0x8003150C
    // 0x800315AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8003150C(rdram, ctx);
        goto after_0;
    // 0x800315AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800315B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800315B4: jal         0x800310D0
    // 0x800315B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_1;
    // 0x800315B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800315BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800315C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800315C4: lwc1        $f6, -0x4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4);
    // 0x800315C8: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800315CC: lui         $a1, 0xBBA3
    ctx->r5 = S32(0XBBA3 << 16);
    // 0x800315D0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x800315D4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800315D8: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    // 0x800315DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800315E0: jal         0x80031170
    // 0x800315E4: nop

    func_80031170(rdram, ctx);
        goto after_2;
    // 0x800315E4: nop

    after_2:
    // 0x800315E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800315EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800315F0: jr          $ra
    // 0x800315F4: nop

    return;
    // 0x800315F4: nop

;}
RECOMP_FUNC void func_8001A5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A5C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001A5C8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001A5CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001A5D0: beq         $a0, $zero, L_8001A5E8
    if (ctx->r4 == 0) {
        // 0x8001A5D4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001A5E8;
    }
    // 0x8001A5D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001A5D8: beq         $a0, $at, L_8001A5F0
    if (ctx->r4 == ctx->r1) {
        // 0x8001A5DC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8001A5F0;
    }
    // 0x8001A5DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001A5E0: b           L_8001A5F8
    // 0x8001A5E4: nop

        goto L_8001A5F8;
    // 0x8001A5E4: nop

L_8001A5E8:
    // 0x8001A5E8: jr          $ra
    // 0x8001A5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001A5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001A5F0:
    // 0x8001A5F0: jr          $ra
    // 0x8001A5F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A5F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A5F8:
    // 0x8001A5F8: jr          $ra
    // 0x8001A5FC: nop

    return;
    // 0x8001A5FC: nop

;}
RECOMP_FUNC void func_805815A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805815A4: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x805815A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805815AC: beq         $v1, $zero, L_805815C8
    if (ctx->r3 == 0) {
        // 0x805815B0: nop
    
            goto L_805815C8;
    }
    // 0x805815B0: nop

    // 0x805815B4: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x805815B8: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x805815BC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x805815C0: jr          $ra
    // 0x805815C4: lw          $v0, 0x6EF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EF8);
    return;
    // 0x805815C4: lw          $v0, 0x6EF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EF8);
L_805815C8:
    // 0x805815C8: jr          $ra
    // 0x805815CC: nop

    return;
    // 0x805815CC: nop

;}
RECOMP_FUNC void func_804D1320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D1320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D1324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D1328: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804D132C: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(246, 0X3A0) << 16);
    // 0x804D1330: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804D1334: addiu       $t6, $t6, 0x1670
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(246, 0X3A0));
    // 0x804D1338: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804D133C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D1340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804D1344: jal         0x804D1528
    // 0x804D1348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804D1528(rdram, ctx);
        goto after_0;
    // 0x804D1348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804D134C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D1350: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(246, 0XA4) << 16);
    // 0x804D1354: addiu       $t8, $t8, 0x1374
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(246, 0XA4));
    // 0x804D1358: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x804D135C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D1360: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804D1364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804D1368: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x804D136C: jr          $ra
    // 0x804D1370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D1370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80675770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675770: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80675774: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80675778: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8067577C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80675780: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80675784: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80675788: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8067578C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80675790: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80675794: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80675798: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8067579C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806757A0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806757A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806757A8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x806757AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806757B0: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x806757B4: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x806757B8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x806757BC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x806757C0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806757C4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x806757C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806757CC: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x806757D0: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x806757D4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x806757D8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806757DC: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x806757E0: ori         $a3, $a3, 0x41C8
    ctx->r7 = ctx->r7 | 0X41C8;
    // 0x806757E4: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x806757E8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x806757EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806757F0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x806757F4: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x806757F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806757FC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80675800: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80675804: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80675808: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8067580C: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x80675810: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80675814: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80675818: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8067581C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80675820: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x80675824: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80675828: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8067582C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80675830: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x80675834: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x80675838: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8067583C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80675840: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80675844: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80675848: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8067584C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80675850: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80675854: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80675858: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8067585C: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x80675860: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80675864: jr          $ra
    // 0x80675868: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x80675868: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8079D96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079D96C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8079D970: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x8079D974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079D978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079D97C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8079D980: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x8079D984: jal         0x8079D7C8
    // 0x8079D988: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    func_8079D7C8(rdram, ctx);
        goto after_0;
    // 0x8079D988: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x8079D98C: bne         $v0, $zero, L_8079D9F0
    if (ctx->r2 != 0) {
        // 0x8079D990: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_8079D9F0;
    }
    // 0x8079D990: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8079D994: lw          $t9, -0x72D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72D4);
    // 0x8079D998: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079D99C: jalr        $t9
    // 0x8079D9A0: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8079D9A0: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    after_1:
    // 0x8079D9A4: beq         $v0, $zero, L_8079D9F0
    if (ctx->r2 == 0) {
        // 0x8079D9A8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8079D9F0;
    }
    // 0x8079D9A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079D9AC: jal         0x8079D8EC
    // 0x8079D9B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8079D8EC(rdram, ctx);
        goto after_2;
    // 0x8079D9B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8079D9B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8079D9B8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8079D9BC: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x8079D9C0: lw          $a1, 0x1D8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1D8);
    // 0x8079D9C4: jal         0x80048BE8
    // 0x8079D9C8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_3;
    // 0x8079D9C8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x8079D9CC: jal         0x80044194
    // 0x8079D9D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x8079D9D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8079D9D4: jal         0x800447C8
    // 0x8079D9D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x8079D9D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8079D9DC: jal         0x80067E68
    // 0x8079D9E0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80067E68(rdram, ctx);
        goto after_6;
    // 0x8079D9E0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x8079D9E4: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8079D9E8: jal         0x80067818
    // 0x8079D9EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8079D9EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
L_8079D9F0:
    // 0x8079D9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079D9F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079D9F8: jr          $ra
    // 0x8079D9FC: nop

    return;
    // 0x8079D9FC: nop

;}
RECOMP_FUNC void func_80073070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073070: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80073074: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80073078: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007307C: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x80073080: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
    // 0x80073084: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x80073088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007308C: sllv        $a1, $t6, $t7
    ctx->r5 = S32(ctx->r14 << (ctx->r15 & 31));
    // 0x80073090: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80073094: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80073098: lui         $v1, 0xC00
    ctx->r3 = S32(0XC00 << 16);
    // 0x8007309C: bne         $t8, $at, L_800730AC
    if (ctx->r24 != ctx->r1) {
        // 0x800730A0: sra         $a1, $a1, 1
        ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800730AC;
    }
    // 0x800730A0: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800730A4: b           L_800730B0
    // 0x800730A8: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
        goto L_800730B0;
    // 0x800730A8: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_800730AC:
    // 0x800730AC: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
L_800730B0:
    // 0x800730B0: div         $zero, $a2, $a1
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r5)));
    // 0x800730B4: lhu         $t2, 0xA($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XA);
    // 0x800730B8: mflo        $t0
    ctx->r8 = lo;
    // 0x800730BC: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800730C0: bne         $a1, $zero, L_800730CC
    if (ctx->r5 != 0) {
        // 0x800730C4: nop
    
            goto L_800730CC;
    }
    // 0x800730C4: nop

    // 0x800730C8: break       7
    do_break(2147954888);
L_800730CC:
    // 0x800730CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800730D0: bne         $a1, $at, L_800730E4
    if (ctx->r5 != ctx->r1) {
        // 0x800730D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800730E4;
    }
    // 0x800730D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800730D8: bne         $a2, $at, L_800730E4
    if (ctx->r6 != ctx->r1) {
        // 0x800730DC: nop
    
            goto L_800730E4;
    }
    // 0x800730DC: nop

    // 0x800730E0: break       6
    do_break(2147954912);
L_800730E4:
    // 0x800730E4: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x800730E8: blez        $t9, L_80073264
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800730EC: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80073264;
    }
    // 0x800730EC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800730F0: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x800730F4: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800730F8: addiu       $s1, $zero, 0x400
    ctx->r17 = ADD32(0, 0X400);
    // 0x800730FC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80073100: addiu       $t5, $zero, 0x7FF
    ctx->r13 = ADD32(0, 0X7FF);
    // 0x80073104: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80073108: addiu       $t3, $zero, 0x1033
    ctx->r11 = ADD32(0, 0X1033);
    // 0x8007310C: mflo        $a2
    ctx->r6 = lo;
    // 0x80073110: nop

    // 0x80073114: nop

    // 0x80073118: addu        $a1, $t1, $a3
    ctx->r5 = ADD32(ctx->r9, ctx->r7);
L_8007311C:
    // 0x8007311C: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80073120: beql        $at, $zero, L_80073134
    if (ctx->r1 == 0) {
        // 0x80073124: sw          $t3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r11;
            goto L_80073134;
    }
    goto skip_0;
    // 0x80073124: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    skip_0:
    // 0x80073128: subu        $a3, $t2, $t1
    ctx->r7 = SUB32(ctx->r10, ctx->r9);
    // 0x8007312C: addu        $a1, $t1, $a3
    ctx->r5 = ADD32(ctx->r9, ctx->r7);
    // 0x80073130: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80073134:
    // 0x80073134: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80073138: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
    // 0x8007313C: sll         $t0, $a3, 5
    ctx->r8 = S32(ctx->r7 << 5);
    // 0x80073140: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x80073144: subu        $t8, $t4, $t7
    ctx->r24 = SUB32(ctx->r12, ctx->r15);
    // 0x80073148: srav        $t9, $zero, $t8
    ctx->r25 = S32(SIGNED(0) >> (ctx->r24 & 31));
    // 0x8007314C: sh          $t9, -0x28($v0)
    MEM_H(-0X28, ctx->r2) = ctx->r25;
    // 0x80073150: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x80073154: lbu         $t8, 0x5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5);
    // 0x80073158: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8007315C: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073160: subu        $t9, $t4, $t8
    ctx->r25 = SUB32(ctx->r12, ctx->r24);
    // 0x80073164: mflo        $t7
    ctx->r15 = lo;
    // 0x80073168: srav        $t6, $t7, $t9
    ctx->r14 = S32(SIGNED(ctx->r15) >> (ctx->r25 & 31));
    // 0x8007316C: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80073170: sh          $t8, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = ctx->r24;
    // 0x80073174: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
    // 0x80073178: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x8007317C: sh          $zero, -0x22($v0)
    MEM_H(-0X22, ctx->r2) = 0;
    // 0x80073180: subu        $t6, $t4, $t9
    ctx->r14 = SUB32(ctx->r12, ctx->r25);
    // 0x80073184: srav        $t8, $t7, $t6
    ctx->r24 = S32(SIGNED(ctx->r15) >> (ctx->r14 & 31));
    // 0x80073188: div         $zero, $t5, $t8
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r24)));
    // 0x8007318C: mflo        $t9
    ctx->r25 = lo;
    // 0x80073190: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80073194: sh          $t7, -0x24($v0)
    MEM_H(-0X24, ctx->r2) = ctx->r15;
    // 0x80073198: sw          $s0, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->r16;
    // 0x8007319C: sw          $zero, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = 0;
    // 0x800731A0: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x800731A4: bne         $t8, $zero, L_800731B0
    if (ctx->r24 != 0) {
        // 0x800731A8: nop
    
            goto L_800731B0;
    }
    // 0x800731A8: nop

    // 0x800731AC: break       7
    do_break(2147955116);
L_800731B0:
    // 0x800731B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800731B4: bne         $t8, $at, L_800731C8
    if (ctx->r24 != ctx->r1) {
        // 0x800731B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800731C8;
    }
    // 0x800731B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800731BC: bne         $t5, $at, L_800731C8
    if (ctx->r13 != ctx->r1) {
        // 0x800731C0: nop
    
            goto L_800731C8;
    }
    // 0x800731C0: nop

    // 0x800731C4: break       6
    do_break(2147955140);
L_800731C8:
    // 0x800731C8: lh          $t7, 0xC($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XC);
    // 0x800731CC: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800731D0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800731D4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800731D8: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800731DC: sh          $t8, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r24;
    // 0x800731E0: lhu         $t7, 0xA($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XA);
    // 0x800731E4: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    // 0x800731E8: sh          $s1, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = ctx->r17;
    // 0x800731EC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800731F0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800731F4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800731F8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800731FC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80073200: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80073204: sh          $t6, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r14;
    // 0x80073208: sh          $s1, -0xE($v0)
    MEM_H(-0XE, ctx->r2) = ctx->r17;
    // 0x8007320C: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80073210: sh          $t0, -0xC($v0)
    MEM_H(-0XC, ctx->r2) = ctx->r8;
    // 0x80073214: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x80073218: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x8007321C: sh          $t9, -0x14($v0)
    MEM_H(-0X14, ctx->r2) = ctx->r25;
    // 0x80073220: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x80073224: lhu         $t8, 0x8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X8);
    // 0x80073228: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x8007322C: subu        $t7, $t4, $t6
    ctx->r15 = SUB32(ctx->r12, ctx->r14);
    // 0x80073230: srav        $t9, $t8, $t7
    ctx->r25 = S32(SIGNED(ctx->r24) >> (ctx->r15 & 31));
    // 0x80073234: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x80073238: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x8007323C: sb          $t6, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r14;
    // 0x80073240: lbu         $t8, 0x5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5);
    // 0x80073244: sb          $zero, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = 0;
    // 0x80073248: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8007324C: sb          $t8, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r24;
    // 0x80073250: lhu         $t2, 0xA($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XA);
    // 0x80073254: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x80073258: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007325C: bnel        $at, $zero, L_8007311C
    if (ctx->r1 != 0) {
        // 0x80073260: addu        $a1, $t1, $a3
        ctx->r5 = ADD32(ctx->r9, ctx->r7);
            goto L_8007311C;
    }
    goto skip_1;
    // 0x80073260: addu        $a1, $t1, $a3
    ctx->r5 = ADD32(ctx->r9, ctx->r7);
    skip_1:
L_80073264:
    // 0x80073264: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80073268: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007326C: jr          $ra
    // 0x80073270: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80073270: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80444840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444840: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80444844: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80444848: lw          $t6, 0xF54($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF54);
    // 0x8044484C: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80444850: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80444854: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80444858: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8044485C: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80444860: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80444864: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x80444868: sw          $t7, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r15;
    // 0x8044486C: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80444870: sw          $t9, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r25;
    // 0x80444874: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80444878: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
    // 0x8044487C: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x80444880: sw          $t3, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r11;
    // 0x80444884: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80444888: jr          $ra
    // 0x8044488C: sw          $t5, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r13;
    return;
    // 0x8044488C: sw          $t5, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80448094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448098: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044809C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804480A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804480A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804480A8: bne         $a2, $zero, L_804480EC
    if (ctx->r6 != 0) {
        // 0x804480AC: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804480EC;
    }
    // 0x804480AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804480B0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x804480B4: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x804480B8: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804480BC: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x804480C0: beq         $at, $zero, L_804480D0
    if (ctx->r1 == 0) {
        // 0x804480C4: sw          $t7, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r15;
            goto L_804480D0;
    }
    // 0x804480C4: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x804480C8: b           L_80448130
    // 0x804480CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80448130;
    // 0x804480CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804480D0:
    // 0x804480D0: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x804480D4: bgtzl       $t9, L_80448130
    if (SIGNED(ctx->r25) > 0) {
        // 0x804480D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80448130;
    }
    goto skip_0;
    // 0x804480D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804480DC: jal         0x804463DC
    // 0x804480E0: nop

    func_804463DC(rdram, ctx);
        goto after_0;
    // 0x804480E0: nop

    after_0:
    // 0x804480E4: b           L_80448130
    // 0x804480E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80448130;
    // 0x804480E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804480EC:
    // 0x804480EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804480F0: bnel        $a2, $at, L_8044811C
    if (ctx->r6 != ctx->r1) {
        // 0x804480F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044811C;
    }
    goto skip_1;
    // 0x804480F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x804480F8: jal         0x80446384
    // 0x804480FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446384(rdram, ctx);
        goto after_1;
    // 0x804480FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448100: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448104: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448108: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8044810C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448110: b           L_8044812C
    // 0x80448114: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_8044812C;
    // 0x80448114: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80448118: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044811C:
    // 0x8044811C: bnel        $a2, $at, L_80448130
    if (ctx->r6 != ctx->r1) {
        // 0x80448120: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80448130;
    }
    goto skip_2;
    // 0x80448120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80448124: jal         0x804463DC
    // 0x80448128: nop

    func_804463DC(rdram, ctx);
        goto after_2;
    // 0x80448128: nop

    after_2:
L_8044812C:
    // 0x8044812C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448130:
    // 0x80448130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448138: jr          $ra
    // 0x8044813C: nop

    return;
    // 0x8044813C: nop

;}
RECOMP_FUNC void func_80032E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032E64: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80032E68: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80032E6C: lwc1        $f4, 0xB0C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XB0C);
    // 0x80032E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032E78: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80032E7C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80032E80: nop

    // 0x80032E84: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80032E88: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80032E8C: beql        $v0, $zero, L_80032F70
    if (ctx->r2 == 0) {
        // 0x80032E90: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80032F70;
    }
    goto skip_0;
    // 0x80032E90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x80032E94: lwc1        $f8, 0xAEC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XAEC);
    // 0x80032E98: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80032E9C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80032EA0: nop

    // 0x80032EA4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80032EA8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80032EAC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032EB0: bne         $at, $zero, L_80032F38
    if (ctx->r1 != 0) {
        // 0x80032EB4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80032F38;
    }
    // 0x80032EB4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80032EB8: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80032EBC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80032EC0: lwc1        $f0, 0x188($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X188);
    // 0x80032EC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032EC8: lwc1        $f16, 0x180($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X180);
    // 0x80032ECC: mflo        $t8
    ctx->r24 = lo;
    // 0x80032ED0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80032ED4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80032ED8: sw          $t9, 0x190($a1)
    MEM_W(0X190, ctx->r5) = ctx->r25;
    // 0x80032EDC: swc1        $f0, 0x194($a1)
    MEM_W(0X194, ctx->r5) = ctx->f0.u32l;
    // 0x80032EE0: bc1f        L_80032F04
    if (!c1cs) {
        // 0x80032EE4: swc1        $f16, 0x184($a1)
        MEM_W(0X184, ctx->r5) = ctx->f16.u32l;
            goto L_80032F04;
    }
    // 0x80032EE4: swc1        $f16, 0x184($a1)
    MEM_W(0X184, ctx->r5) = ctx->f16.u32l;
    // 0x80032EE8: lw          $t0, 0x198($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X198);
    // 0x80032EEC: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x80032EF0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80032EF4: sltiu       $at, $t1, 0x28
    ctx->r1 = ctx->r9 < 0X28 ? 1 : 0;
    // 0x80032EF8: bne         $at, $zero, L_80032F04
    if (ctx->r1 != 0) {
        // 0x80032EFC: sw          $t1, 0x198($a1)
        MEM_W(0X198, ctx->r5) = ctx->r9;
            goto L_80032F04;
    }
    // 0x80032EFC: sw          $t1, 0x198($a1)
    MEM_W(0X198, ctx->r5) = ctx->r9;
    // 0x80032F00: sw          $t3, 0x198($a1)
    MEM_W(0X198, ctx->r5) = ctx->r11;
L_80032F04:
    // 0x80032F04: lw          $t4, 0x1F4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X1F4);
    // 0x80032F08: bnel        $t4, $zero, L_80032F90
    if (ctx->r12 != 0) {
        // 0x80032F0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032F90;
    }
    goto skip_1;
    // 0x80032F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80032F10: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80032F14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032F18: beq         $v0, $zero, L_80032F28
    if (ctx->r2 == 0) {
        // 0x80032F1C: nop
    
            goto L_80032F28;
    }
    // 0x80032F1C: nop

    // 0x80032F20: bnel        $v0, $at, L_80032F90
    if (ctx->r2 != ctx->r1) {
        // 0x80032F24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032F90;
    }
    goto skip_2;
    // 0x80032F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80032F28:
    // 0x80032F28: jal         0x80038E80
    // 0x80032F2C: nop

    func_80038E80(rdram, ctx);
        goto after_0;
    // 0x80032F2C: nop

    after_0:
    // 0x80032F30: b           L_80032F90
    // 0x80032F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80032F90;
    // 0x80032F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032F38:
    // 0x80032F38: lw          $t5, 0x190($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X190);
    // 0x80032F3C: addiu       $v0, $a1, 0x190
    ctx->r2 = ADD32(ctx->r5, 0X190);
    // 0x80032F40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80032F44: beq         $t5, $zero, L_80032F5C
    if (ctx->r13 == 0) {
        // 0x80032F48: nop
    
            goto L_80032F5C;
    }
    // 0x80032F48: nop

    // 0x80032F4C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80032F50: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80032F54: b           L_80032F8C
    // 0x80032F58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_80032F8C;
    // 0x80032F58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80032F5C:
    // 0x80032F5C: jal         0x80032E38
    // 0x80032F60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80032E38(rdram, ctx);
        goto after_1;
    // 0x80032F60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80032F64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80032F68: sw          $zero, 0x198($a1)
    MEM_W(0X198, ctx->r5) = 0;
    // 0x80032F6C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80032F70:
    // 0x80032F70: jal         0x80032E38
    // 0x80032F74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80032E38(rdram, ctx);
        goto after_2;
    // 0x80032F74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80032F78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80032F7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032F80: sw          $zero, 0x190($a1)
    MEM_W(0X190, ctx->r5) = 0;
    // 0x80032F84: sw          $zero, 0x198($a1)
    MEM_W(0X198, ctx->r5) = 0;
    // 0x80032F88: swc1        $f4, 0x194($a1)
    MEM_W(0X194, ctx->r5) = ctx->f4.u32l;
L_80032F8C:
    // 0x80032F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032F90:
    // 0x80032F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032F94: jr          $ra
    // 0x80032F98: nop

    return;
    // 0x80032F98: nop

;}
RECOMP_FUNC void func_80066DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DE4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80066DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066DF0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80066DF4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80066DF8: bc1fl       L_80066E20
    if (!c1cs) {
        // 0x80066DFC: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80066E20;
    }
    goto skip_0;
    // 0x80066DFC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x80066E00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066E04: nop

    // 0x80066E08: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_80066E0C:
    // 0x80066E0C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80066E10: nop

    // 0x80066E14: bc1tl       L_80066E0C
    if (c1cs) {
        // 0x80066E18: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_80066E0C;
    }
    goto skip_1;
    // 0x80066E18: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_1:
    // 0x80066E1C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80066E20:
    // 0x80066E20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066E24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066E28: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80066E2C: nop

    // 0x80066E30: bc1f        L_80066E4C
    if (!c1cs) {
        // 0x80066E34: nop
    
            goto L_80066E4C;
    }
    // 0x80066E34: nop

    // 0x80066E38: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_80066E3C:
    // 0x80066E3C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80066E40: nop

    // 0x80066E44: bc1tl       L_80066E3C
    if (c1cs) {
        // 0x80066E48: sub.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80066E3C;
    }
    goto skip_2;
    // 0x80066E48: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    skip_2:
L_80066E4C:
    // 0x80066E4C: lwc1        $f4, 0xF04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF04);
    // 0x80066E50: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80066E54: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80066E58: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80066E5C: jal         0x800828F0
    // 0x80066E60: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sins(rdram, ctx);
        goto after_0;
    // 0x80066E60: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80066E64: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80066E68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066E6C: lwc1        $f18, 0xF08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XF08);
    // 0x80066E70: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80066E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E7C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80066E80: jr          $ra
    // 0x80066E84: nop

    return;
    // 0x80066E84: nop

;}
RECOMP_FUNC void func_800576EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800576EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800576F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800576F4: jal         0x800575B4
    // 0x800576F8: addiu       $a1, $zero, 0x404E
    ctx->r5 = ADD32(0, 0X404E);
    func_800575B4(rdram, ctx);
        goto after_0;
    // 0x800576F8: addiu       $a1, $zero, 0x404E
    ctx->r5 = ADD32(0, 0X404E);
    after_0:
    // 0x800576FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057704: jr          $ra
    // 0x80057708: nop

    return;
    // 0x80057708: nop

;}
RECOMP_FUNC void func_8064AC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AC38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AC40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064AC44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064AC48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064AC4C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064AC50: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064AC54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064AC58: bne         $v0, $at, L_8064AC80
    if (ctx->r2 != ctx->r1) {
        // 0x8064AC5C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064AC80;
    }
    // 0x8064AC5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064AC60: jal         0x8064A1C8
    // 0x8064AC64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064AC64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8064AC68: beq         $v0, $zero, L_8064AC80
    if (ctx->r2 == 0) {
        // 0x8064AC6C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064AC80;
    }
    // 0x8064AC6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064AC70: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064AC74: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064AC78: jal         0x8002F6E4
    // 0x8064AC7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064AC7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064AC80:
    // 0x8064AC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064AC84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AC88: jr          $ra
    // 0x8064AC8C: nop

    return;
    // 0x8064AC8C: nop

;}
RECOMP_FUNC void func_8066626C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066626C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80666270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80666274: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80666278: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2D20) << 16);
    // 0x8066627C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80666280: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80666284: addiu       $t6, $t6, 0x79F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(504, 0X2D20));
    // 0x80666288: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8066628C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80666290: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x80666294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80666298: jal         0x806662B8
    // 0x8066629C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806662B8(rdram, ctx);
        goto after_0;
    // 0x8066629C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x806662A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806662A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806662A8: jr          $ra
    // 0x806662AC: nop

    return;
    // 0x806662AC: nop

;}
RECOMP_FUNC void func_8044FEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FEF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044FEF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044FEFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044FF00: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044FF04: addiu       $a1, $zero, 0x40F5
    ctx->r5 = ADD32(0, 0X40F5);
    // 0x8044FF08: jal         0x80444408
    // 0x8044FF0C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x8044FF0C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8044FF10: beq         $v0, $zero, L_8044FF20
    if (ctx->r2 == 0) {
        // 0x8044FF14: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8044FF20;
    }
    // 0x8044FF14: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8044FF18: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8044FF1C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
L_8044FF20:
    // 0x8044FF20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044FF24: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8044FF28: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044FF2C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8044FF30: swc1        $f6, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->f6.u32l;
    // 0x8044FF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044FF38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044FF3C: jr          $ra
    // 0x8044FF40: nop

    return;
    // 0x8044FF40: nop

;}
RECOMP_FUNC void func_8007180C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007180C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071814: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80071818: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007181C: addiu       $a0, $a0, -0x5E30
    ctx->r4 = ADD32(ctx->r4, -0X5E30);
    // 0x80071820: jal         0x80082210
    // 0x80071824: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071824: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80071828: jal         0x80086880
    // 0x8007182C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_1;
    // 0x8007182C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80071830: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80071834: bne         $v0, $at, L_8007184C
    if (ctx->r2 != ctx->r1) {
        // 0x80071838: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_8007184C;
    }
    // 0x80071838: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007183C: addiu       $v0, $v0, -0x7B80
    ctx->r2 = ADD32(ctx->r2, -0X7B80);
    // 0x80071840: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80071844: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80071848: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8007184C:
    // 0x8007184C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071854: jr          $ra
    // 0x80071858: nop

    return;
    // 0x80071858: nop

;}
RECOMP_FUNC void func_8006AA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AA18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006AA1C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8006AA20: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006AA24: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8006AA28: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006AA2C: bltz        $a1, L_8006AA3C
    if (SIGNED(ctx->r5) < 0) {
        // 0x8006AA30: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8006AA3C;
    }
    // 0x8006AA30: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006AA34: bgezl       $a2, L_8006AA48
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006AA38: lh          $t8, 0x12($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X12);
            goto L_8006AA48;
    }
    goto skip_0;
    // 0x8006AA38: lh          $t8, 0x12($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X12);
    skip_0:
L_8006AA3C:
    // 0x8006AA3C: jr          $ra
    // 0x8006AA40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006AA40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006AA44: lh          $t8, 0x12($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X12);
L_8006AA48:
    // 0x8006AA48: sra         $t6, $a1, 4
    ctx->r14 = S32(SIGNED(ctx->r5) >> 4);
    // 0x8006AA4C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8006AA50: slt         $v0, $t7, $t8
    ctx->r2 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006AA54: beq         $v0, $zero, L_8006AA6C
    if (ctx->r2 == 0) {
        // 0x8006AA58: nop
    
            goto L_8006AA6C;
    }
    // 0x8006AA58: nop

    // 0x8006AA5C: lh          $t1, 0x14($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X14);
    // 0x8006AA60: sra         $t9, $a2, 4
    ctx->r25 = S32(SIGNED(ctx->r6) >> 4);
    // 0x8006AA64: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8006AA68: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
L_8006AA6C:
    // 0x8006AA6C: jr          $ra
    // 0x8006AA70: nop

    return;
    // 0x8006AA70: nop

;}
RECOMP_FUNC void func_8070C690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C690: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(721, 0XBE0) << 16);
    // 0x8070C694: lw          $t6, -0x2D90($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(721, 0XBE0));
    // 0x8070C698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070C69C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070C6A0: bne         $t6, $zero, L_8070C6CC
    if (ctx->r14 != 0) {
        // 0x8070C6A4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8070C6CC;
    }
    // 0x8070C6A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8070C6A8: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(721, 0XF50) << 16);
    // 0x8070C6AC: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(721, 0XF60) << 16);
    // 0x8070C6B0: addiu       $a1, $a1, -0x2A10
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(721, 0XF60));
    // 0x8070C6B4: addiu       $a0, $a0, -0x2A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(721, 0XF50));
    // 0x8070C6B8: jal         0x8004667C
    // 0x8070C6BC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8070C6BC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x8070C6C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8070C6C4: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XBE0) << 16);
    // 0x8070C6C8: sw          $t7, -0x2D90($at)
    MEM_W((int16_t)RELOC_LO16(721, 0XBE0), ctx->r1) = ctx->r15;
L_8070C6CC:
    // 0x8070C6CC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8070C6D0: addiu       $at, $zero, 0x461C
    ctx->r1 = ADD32(0, 0X461C);
    // 0x8070C6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070C6D8: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x8070C6DC: beq         $v0, $at, L_8070C6F4
    if (ctx->r2 == ctx->r1) {
        // 0x8070C6E0: addiu       $at, $zero, 0x461D
        ctx->r1 = ADD32(0, 0X461D);
            goto L_8070C6F4;
    }
    // 0x8070C6E0: addiu       $at, $zero, 0x461D
    ctx->r1 = ADD32(0, 0X461D);
    // 0x8070C6E4: beq         $v0, $at, L_8070C700
    if (ctx->r2 == ctx->r1) {
        // 0x8070C6E8: nop
    
            goto L_8070C700;
    }
    // 0x8070C6E8: nop

    // 0x8070C6EC: b           L_8070C70C
    // 0x8070C6F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8070C70C;
    // 0x8070C6F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8070C6F4:
    // 0x8070C6F4: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(721, 0XAC8) << 16);
    // 0x8070C6F8: b           L_8070C70C
    // 0x8070C6FC: addiu       $v0, $v0, -0x2EA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(721, 0XAC8));
        goto L_8070C70C;
    // 0x8070C6FC: addiu       $v0, $v0, -0x2EA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(721, 0XAC8));
L_8070C700:
    // 0x8070C700: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(721, 0X230) << 16);
    // 0x8070C704: b           L_8070C70C
    // 0x8070C708: addiu       $v0, $v0, -0x3740
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(721, 0X230));
        goto L_8070C70C;
    // 0x8070C708: addiu       $v0, $v0, -0x3740
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(721, 0X230));
L_8070C70C:
    // 0x8070C70C: jr          $ra
    // 0x8070C710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8070C710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80453784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453784: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80453788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045378C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80453790: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453794: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80453798: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045379C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804537A0: swc1        $f4, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->f4.u32l;
    // 0x804537A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804537A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804537AC: sw          $a1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r5;
    // 0x804537B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804537B4: jal         0x8044EFA0
    // 0x804537B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804537B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804537BC: jal         0x8044E87C
    // 0x804537C0: nop

    func_8044E87C(rdram, ctx);
        goto after_1;
    // 0x804537C0: nop

    after_1:
    // 0x804537C4: jal         0x8044DED8
    // 0x804537C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_2;
    // 0x804537C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804537CC: jal         0x80444C94
    // 0x804537D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80444C94(rdram, ctx);
        goto after_3;
    // 0x804537D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804537D4: jal         0x80445DF0
    // 0x804537D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80445DF0(rdram, ctx);
        goto after_4;
    // 0x804537D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804537DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804537E0: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x804537E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x804537E8: jal         0x8044FE40
    // 0x804537EC: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    func_8044FE40(rdram, ctx);
        goto after_5;
    // 0x804537EC: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    after_5:
    // 0x804537F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804537F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804537F8: jal         0x8044FE64
    // 0x804537FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8044FE64(rdram, ctx);
        goto after_6;
    // 0x804537FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x80453800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80453804: jal         0x8044FEF4
    // 0x80453808: lui         $a1, 0x4313
    ctx->r5 = S32(0X4313 << 16);
    func_8044FEF4(rdram, ctx);
        goto after_7;
    // 0x80453808: lui         $a1, 0x4313
    ctx->r5 = S32(0X4313 << 16);
    after_7:
    // 0x8045380C: jal         0x80445B14
    // 0x80453810: nop

    func_80445B14(rdram, ctx);
        goto after_8;
    // 0x80453810: nop

    after_8:
    // 0x80453814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80453818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045381C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80453820: jr          $ra
    // 0x80453824: nop

    return;
    // 0x80453824: nop

;}
RECOMP_FUNC void func_80558DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558DB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80558DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80558DC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558DC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80558DC8: jal         0x805582E0
    // 0x80558DCC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805582E0(rdram, ctx);
        goto after_0;
    // 0x80558DCC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80558DD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80558DD4: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X9534) << 16);
    // 0x80558DD8: lwc1        $f0, 0x1084($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X9534));
    // 0x80558DDC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80558DE0: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80558DE4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80558DE8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80558DEC: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X9538) << 16);
    // 0x80558DF0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80558DF4: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80558DF8: lwc1        $f12, 0x6C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80558DFC: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x80558E00: lwc1        $f16, 0x1088($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X9538));
    // 0x80558E04: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80558E08: nop

    // 0x80558E0C: bc1fl       L_80558E30
    if (!c1cs) {
        // 0x80558E10: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80558E30;
    }
    goto skip_0;
    // 0x80558E10: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80558E14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80558E18: jal         0x80048D4C
    // 0x80558E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048D4C(rdram, ctx);
        goto after_1;
    // 0x80558E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80558E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80558E24: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80558E28: lwc1        $f12, 0x6C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80558E2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80558E30:
    // 0x80558E30: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80558E34: swc1        $f12, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f12.u32l;
    // 0x80558E38: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80558E3C: swc1        $f12, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f12.u32l;
    // 0x80558E40: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80558E44: swc1        $f12, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f12.u32l;
    // 0x80558E48: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80558E4C: swc1        $f12, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f12.u32l;
    // 0x80558E50: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80558E54: lwc1        $f18, 0x78($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80558E58: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80558E5C: swc1        $f4, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f4.u32l;
    // 0x80558E60: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80558E64: swc1        $f2, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f2.u32l;
    // 0x80558E68: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80558E6C: swc1        $f2, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f2.u32l;
    // 0x80558E70: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80558E74: swc1        $f2, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f2.u32l;
    // 0x80558E78: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x80558E7C: swc1        $f2, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f2.u32l;
    // 0x80558E80: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80558E84: lwc1        $f6, 0x7C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x80558E88: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80558E8C: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
    // 0x80558E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80558E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80558E98: jr          $ra
    // 0x80558E9C: nop

    return;
    // 0x80558E9C: nop

;}
RECOMP_FUNC void func_80678C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678C88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80678C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80678C90: lwc1        $f14, 0x88($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80678C94: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80678C98: jal         0x80053924
    // 0x80678C9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x80678C9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80678CA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80678CA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80678CA8: bne         $v0, $at, L_80678CC0
    if (ctx->r2 != ctx->r1) {
        // 0x80678CAC: sh          $v0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r2;
            goto L_80678CC0;
    }
    // 0x80678CAC: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80678CB0: jal         0x800447C8
    // 0x80678CB4: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80678CB4: nop

    after_1:
    // 0x80678CB8: b           L_80678CE8
    // 0x80678CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80678CE8;
    // 0x80678CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80678CC0:
    // 0x80678CC0: lbu         $t6, 0x1E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1E);
    // 0x80678CC4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80678CC8: andi        $t7, $t6, 0xF8
    ctx->r15 = ctx->r14 & 0XF8;
    // 0x80678CCC: beq         $t7, $at, L_80678CE4
    if (ctx->r15 == ctx->r1) {
        // 0x80678CD0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80678CE4;
    }
    // 0x80678CD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80678CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80678CD8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80678CDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80678CE0: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
L_80678CE4:
    // 0x80678CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80678CE8:
    // 0x80678CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80678CEC: jr          $ra
    // 0x80678CF0: nop

    return;
    // 0x80678CF0: nop

;}
RECOMP_FUNC void func_805CA9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA9FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CAA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CAA04: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805CAA08: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x805CAA0C: bne         $v0, $zero, L_805CAA24
    if (ctx->r2 != 0) {
        // 0x805CAA10: sw          $v0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r2;
            goto L_805CAA24;
    }
    // 0x805CAA10: sw          $v0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r2;
    // 0x805CAA14: jal         0x805CA8C0
    // 0x805CAA18: nop

    func_805CA8C0(rdram, ctx);
        goto after_0;
    // 0x805CAA18: nop

    after_0:
    // 0x805CAA1C: b           L_805CAA58
    // 0x805CAA20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CAA58;
    // 0x805CAA20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CAA24:
    // 0x805CAA24: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x805CAA28: beql        $at, $zero, L_805CAA58
    if (ctx->r1 == 0) {
        // 0x805CAA2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_805CAA58;
    }
    goto skip_0;
    // 0x805CAA2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x805CAA30: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x805CAA34: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x805CAA38: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x805CAA3C: slti        $at, $v1, 0x21
    ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x805CAA40: beq         $at, $zero, L_805CAA50
    if (ctx->r1 == 0) {
        // 0x805CAA44: addiu       $t8, $v1, -0x20
        ctx->r24 = ADD32(ctx->r3, -0X20);
            goto L_805CAA50;
    }
    // 0x805CAA44: addiu       $t8, $v1, -0x20
    ctx->r24 = ADD32(ctx->r3, -0X20);
    // 0x805CAA48: b           L_805CAA54
    // 0x805CAA4C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
        goto L_805CAA54;
    // 0x805CAA4C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
L_805CAA50:
    // 0x805CAA50: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_805CAA54:
    // 0x805CAA54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805CAA58:
    // 0x805CAA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CAA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CAA60: jr          $ra
    // 0x805CAA64: nop

    return;
    // 0x805CAA64: nop

;}
RECOMP_FUNC void func_8006C3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C3F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C3F8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006C3FC: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006C400: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8006C404: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006C408: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006C40C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8006C410: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8006C414: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006C418: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8006C41C: nop

    // 0x8006C420: bc1fl       L_8006C448
    if (!c1cs) {
        // 0x8006C424: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8006C448;
    }
    goto skip_0;
    // 0x8006C424: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x8006C428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C42C: nop

    // 0x8006C430: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8006C434: nop

    // 0x8006C438: bc1fl       L_8006C448
    if (!c1cs) {
        // 0x8006C43C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8006C448;
    }
    goto skip_1;
    // 0x8006C43C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_1:
    // 0x8006C440: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8006C444: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8006C448:
    // 0x8006C448: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006C44C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8006C450:
    // 0x8006C450: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8006C454: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8006C458: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006C45C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006C460: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x8006C464: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8006C468: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8006C46C: nop

    // 0x8006C470: bc1f        L_8006C480
    if (!c1cs) {
        // 0x8006C474: nop
    
            goto L_8006C480;
    }
    // 0x8006C474: nop

    // 0x8006C478: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006C47C: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
L_8006C480:
    // 0x8006C480: bne         $v1, $a0, L_8006C450
    if (ctx->r3 != ctx->r4) {
        // 0x8006C484: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006C450;
    }
    // 0x8006C484: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006C488: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8006C48C: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006C490: lwc1        $f14, 0xC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006C494: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
    // 0x8006C498: lw          $a3, 0x20($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X20);
    // 0x8006C49C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8006C4A0: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8006C4A4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8006C4A8: jal         0x8006BF80
    // 0x8006C4AC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_8006BF80(rdram, ctx);
        goto after_0;
    // 0x8006C4AC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8006C4B0: jal         0x8006C3C4
    // 0x8006C4B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8006C3C4(rdram, ctx);
        goto after_1;
    // 0x8006C4B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8006C4B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C4BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006C4C0: jr          $ra
    // 0x8006C4C4: nop

    return;
    // 0x8006C4C4: nop

;}
RECOMP_FUNC void func_80705568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80705568: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8070556C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80705570: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80705574: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80705578: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8070557C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80705580: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x80705584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80705588: beq         $v0, $zero, L_80705594
    if (ctx->r2 == 0) {
        // 0x8070558C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80705594;
    }
    // 0x8070558C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80705590: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
L_80705594:
    // 0x80705594: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80705598: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8070559C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807055A0: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x807055A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x807055A8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x807055AC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x807055B0: nop

    // 0x807055B4: bc1fl       L_807055F4
    if (!c1cs) {
        // 0x807055B8: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_807055F4;
    }
    goto skip_0;
    // 0x807055B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x807055BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807055C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807055C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x807055C8: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x807055CC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x807055D0: nop

    // 0x807055D4: bc1f        L_807055E8
    if (!c1cs) {
        // 0x807055D8: nop
    
            goto L_807055E8;
    }
    // 0x807055D8: nop

    // 0x807055DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807055E0: nop

    // 0x807055E4: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
L_807055E8:
    // 0x807055E8: b           L_807055F8
    // 0x807055EC: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
        goto L_807055F8;
    // 0x807055EC: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x807055F0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_807055F4:
    // 0x807055F4: swc1        $f14, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f14.u32l;
L_807055F8:
    // 0x807055F8: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x807055FC: beql        $t7, $zero, L_80705724
    if (ctx->r15 == 0) {
        // 0x80705600: addiu       $a2, $s0, 0xC4
        ctx->r6 = ADD32(ctx->r16, 0XC4);
            goto L_80705724;
    }
    goto skip_1;
    // 0x80705600: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x80705604: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80705608: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x8070560C: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    // 0x80705610: nop

    // 0x80705614: bc1fl       L_80705724
    if (!c1cs) {
        // 0x80705618: addiu       $a2, $s0, 0xC4
        ctx->r6 = ADD32(ctx->r16, 0XC4);
            goto L_80705724;
    }
    goto skip_2;
    // 0x80705618: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    skip_2:
    // 0x8070561C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80705620: lwc1        $f18, 0x1C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80705624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80705628: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8070562C: nop

    // 0x80705630: bc1tl       L_80705658
    if (c1cs) {
        // 0x80705634: lwc1        $f0, 0x6C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
            goto L_80705658;
    }
    goto skip_3;
    // 0x80705634: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    skip_3:
    // 0x80705638: swc1        $f12, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f12.u32l;
    // 0x8070563C: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x80705640: swc1        $f12, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f12.u32l;
    // 0x80705644: jal         0x8070429C
    // 0x80705648: swc1        $f12, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f12.u32l;
    func_8070429C(rdram, ctx);
        goto after_0;
    // 0x80705648: swc1        $f12, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f12.u32l;
    after_0:
    // 0x8070564C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80705650: nop

    // 0x80705654: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
L_80705658:
    // 0x80705658: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38C0) << 16);
    // 0x8070565C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80705660: nop

    // 0x80705664: bc1fl       L_80705678
    if (!c1cs) {
        // 0x80705668: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_80705678;
    }
    goto skip_4;
    // 0x80705668: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_4:
    // 0x8070566C: lwc1        $f4, 0x6D30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38C0));
    // 0x80705670: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80705674: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_80705678:
    // 0x80705678: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8070567C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38C4) << 16);
    // 0x80705680: lwc1        $f6, 0x6D34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38C4));
    // 0x80705684: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80705688: nop

    // 0x8070568C: bc1fl       L_80705724
    if (!c1cs) {
        // 0x80705690: addiu       $a2, $s0, 0xC4
        ctx->r6 = ADD32(ctx->r16, 0XC4);
            goto L_80705724;
    }
    goto skip_5;
    // 0x80705690: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    skip_5:
    // 0x80705694: jal         0x807043F0
    // 0x80705698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807043F0(rdram, ctx);
        goto after_1;
    // 0x80705698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8070569C: jal         0x800447C8
    // 0x807056A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x807056A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807056A4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x807056A8: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x807056AC: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(709, 0X37B4) << 16);
    // 0x807056B0: addiu       $a1, $a1, 0x6C24
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(709, 0X37B4));
    // 0x807056B4: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x807056B8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x807056BC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x807056C0: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x807056C4: jalr        $t9
    // 0x807056C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x807056C8: nop

    after_3:
    // 0x807056CC: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807056D0: lw          $t0, -0x77F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X77F0);
    // 0x807056D4: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x807056D8: slti        $at, $t1, 0x96
    ctx->r1 = SIGNED(ctx->r9) < 0X96 ? 1 : 0;
    // 0x807056DC: beql        $at, $zero, L_80705754
    if (ctx->r1 == 0) {
        // 0x807056E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80705754;
    }
    goto skip_6;
    // 0x807056E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x807056E4: jal         0x80047090
    // 0x807056E8: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x807056E8: addiu       $a0, $zero, 0x45B6
    ctx->r4 = ADD32(0, 0X45B6);
    after_4:
    // 0x807056EC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807056F0: beq         $v0, $at, L_80705720
    if (ctx->r2 == ctx->r1) {
        // 0x807056F4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80705720;
    }
    // 0x807056F4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807056F8: lui         $at, 0x45B6
    ctx->r1 = S32(0X45B6 << 16);
    // 0x807056FC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80705700: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80705704: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80705708: jal         0x8004613C
    // 0x8070570C: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x8070570C: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    after_5:
    // 0x80705710: beq         $v0, $zero, L_80705720
    if (ctx->r2 == 0) {
        // 0x80705714: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80705720;
    }
    // 0x80705714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80705718: jal         0x80044194
    // 0x8070571C: nop

    func_80044194(rdram, ctx);
        goto after_6;
    // 0x8070571C: nop

    after_6:
L_80705720:
    // 0x80705720: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
L_80705724:
    // 0x80705724: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80705728: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8070572C: jal         0x80048F84
    // 0x80705730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x80705730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80705734: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80705738: jal         0x80048F84
    // 0x8070573C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x8070573C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80705740: jal         0x8070384C
    // 0x80705744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_9;
    // 0x80705744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80705748: jal         0x80703F10
    // 0x8070574C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_10;
    // 0x8070574C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80705750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80705754:
    // 0x80705754: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80705758: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8070575C: jr          $ra
    // 0x80705760: nop

    return;
    // 0x80705760: nop

;}
RECOMP_FUNC void func_8005BC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BC68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BC6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BC70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BC74: jal         0x8005BA30
    // 0x8005BC78: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BC78: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BC7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BC80: bne         $v0, $at, L_8005BC90
    if (ctx->r2 != ctx->r1) {
        // 0x8005BC84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005BC90;
    }
    // 0x8005BC84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005BC88: b           L_8005BCA8
    // 0x8005BC8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005BCA8;
    // 0x8005BC8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BC90:
    // 0x8005BC90: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8005BC94: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BC98: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BC9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BCA0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005BCA4: lw          $v0, -0x4BA8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA8);
L_8005BCA8:
    // 0x8005BCA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BCB0: jr          $ra
    // 0x8005BCB4: nop

    return;
    // 0x8005BCB4: nop

;}
RECOMP_FUNC void func_8044CE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CE3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044CE40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044CE44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044CE48: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044CE4C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044CE50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044CE54: jal         0x80065954
    // 0x8044CE58: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8044CE58: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8044CE5C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8044CE60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8044CE64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8044CE68: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8044CE6C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8044CE70: nop

    // 0x8044CE74: bc1fl       L_8044CEC8
    if (!c1cs) {
        // 0x8044CE78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044CEC8;
    }
    goto skip_0;
    // 0x8044CE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044CE7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8044CE80: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8044CE84: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8044CE88: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8044CE8C: nop

    // 0x8044CE90: bc1fl       L_8044CEB4
    if (!c1cs) {
        // 0x8044CE94: lwc1        $f8, 0x0($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
            goto L_8044CEB4;
    }
    goto skip_1;
    // 0x8044CE94: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x8044CE98: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8044CE9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044CEA0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044CEA4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8044CEA8: b           L_8044CEC4
    // 0x8044CEAC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8044CEC4;
    // 0x8044CEAC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8044CEB0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
L_8044CEB4:
    // 0x8044CEB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044CEB8: nop

    // 0x8044CEBC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044CEC0: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
L_8044CEC4:
    // 0x8044CEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CEC8:
    // 0x8044CEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044CECC: jr          $ra
    // 0x8044CED0: nop

    return;
    // 0x8044CED0: nop

;}
RECOMP_FUNC void func_806D0E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D0E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D0E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D0E4C: jal         0x806D0DE4
    // 0x806D0E50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806D0DE4(rdram, ctx);
        goto after_0;
    // 0x806D0E50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806D0E54: bne         $v0, $zero, L_806D0E64
    if (ctx->r2 != 0) {
        // 0x806D0E58: nop
    
            goto L_806D0E64;
    }
    // 0x806D0E58: nop

    // 0x806D0E5C: b           L_806D0EB4
    // 0x806D0E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D0EB4;
    // 0x806D0E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D0E64:
    // 0x806D0E64: jal         0x806D0E28
    // 0x806D0E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D0E28(rdram, ctx);
        goto after_1;
    // 0x806D0E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D0E6C: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806D0E70: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806D0E74: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806D0E78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D0E7C: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(607, 0X1A98) << 16);
    // 0x806D0E80: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806D0E84: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x806D0E88: addiu       $t8, $t8, 0x1238
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(607, 0X1A98));
    // 0x806D0E8C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806D0E90: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806D0E94: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806D0E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0E9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0EA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D0EA4: jal         0x806D0EC8
    // 0x806D0EA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D0EC8(rdram, ctx);
        goto after_2;
    // 0x806D0EA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806D0EAC: jal         0x806D0D4C
    // 0x806D0EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D0D4C(rdram, ctx);
        goto after_3;
    // 0x806D0EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_806D0EB4:
    // 0x806D0EB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0EB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D0EBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D0EC0: jr          $ra
    // 0x806D0EC4: nop

    return;
    // 0x806D0EC4: nop

;}
RECOMP_FUNC void func_806A9D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9D68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806A9D6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A9D70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A9D74: jal         0x800653D8
    // 0x806A9D78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806A9D78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806A9D7C: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x806A9D80: bne         $t6, $zero, L_806A9DC8
    if (ctx->r14 != 0) {
        // 0x806A9D84: nop
    
            goto L_806A9DC8;
    }
    // 0x806A9D84: nop

    // 0x806A9D88: jal         0x800653D8
    // 0x806A9D8C: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806A9D8C: nop

    after_1:
    // 0x806A9D90: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x806A9D94: beq         $t7, $zero, L_806A9DB8
    if (ctx->r15 == 0) {
        // 0x806A9D98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806A9DB8;
    }
    // 0x806A9D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9DA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806A9DA8: jal         0x806AA784
    // 0x806A9DAC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_2;
    // 0x806A9DAC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x806A9DB0: b           L_806A9DC8
    // 0x806A9DB4: nop

        goto L_806A9DC8;
    // 0x806A9DB4: nop

L_806A9DB8:
    // 0x806A9DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9DBC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806A9DC0: jal         0x806AA784
    // 0x806A9DC4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_3;
    // 0x806A9DC4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
L_806A9DC8:
    // 0x806A9DC8: jal         0x806A9CD8
    // 0x806A9DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A9CD8(rdram, ctx);
        goto after_4;
    // 0x806A9DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806A9DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9DD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A9DD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806A9DDC: jr          $ra
    // 0x806A9DE0: nop

    return;
    // 0x806A9DE0: nop

;}
RECOMP_FUNC void func_80449148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044914C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449150: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044915C: bne         $a2, $zero, L_8044919C
    if (ctx->r6 != 0) {
        // 0x80449160: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_8044919C;
    }
    // 0x80449160: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449164: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x80449168: lw          $v1, 0x50($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X50);
    // 0x8044916C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80449170: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80449174: bne         $at, $zero, L_804491DC
    if (ctx->r1 != 0) {
        // 0x80449178: sw          $t7, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r15;
            goto L_804491DC;
    }
    // 0x80449178: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x8044917C: jal         0x804468D4
    // 0x80449180: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804468D4(rdram, ctx);
        goto after_0;
    // 0x80449180: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80449184: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449188: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044918C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80449190: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449194: b           L_804491DC
    // 0x80449198: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_804491DC;
    // 0x80449198: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044919C:
    // 0x8044919C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804491A0: bnel        $a2, $at, L_804491CC
    if (ctx->r6 != ctx->r1) {
        // 0x804491A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804491CC;
    }
    goto skip_0;
    // 0x804491A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804491A8: jal         0x804468D4
    // 0x804491AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804468D4(rdram, ctx);
        goto after_1;
    // 0x804491AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804491B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804491B4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804491B8: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x804491BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804491C0: b           L_804491DC
    // 0x804491C4: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_804491DC;
    // 0x804491C4: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x804491C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804491CC:
    // 0x804491CC: bnel        $a2, $at, L_804491E0
    if (ctx->r6 != ctx->r1) {
        // 0x804491D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804491E0;
    }
    goto skip_1;
    // 0x804491D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804491D4: jal         0x8044692C
    // 0x804491D8: nop

    func_8044692C(rdram, ctx);
        goto after_2;
    // 0x804491D8: nop

    after_2:
L_804491DC:
    // 0x804491DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804491E0:
    // 0x804491E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804491E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804491E8: jr          $ra
    // 0x804491EC: nop

    return;
    // 0x804491EC: nop

;}
RECOMP_FUNC void func_8002BCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BCE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BCEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BCF0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BCF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BCF8: jal         0x8002AFA0
    // 0x8002BCFC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002AFA0(rdram, ctx);
        goto after_0;
    // 0x8002BCFC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002BD00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002BD04: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002BD08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002BD0C: addiu       $t8, $t8, 0x3450
    ctx->r24 = ADD32(ctx->r24, 0X3450);
    // 0x8002BD10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002BD14: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002BD18: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002BD1C: jal         0x8002DBE4
    // 0x8002BD20: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x8002BD20: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002BD24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002BD28: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8002BD2C: addiu       $t9, $t9, 0x33B4
    ctx->r25 = ADD32(ctx->r25, 0X33B4);
    // 0x8002BD30: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8002BD34: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BD38: sw          $zero, 0xD8($t0)
    MEM_W(0XD8, ctx->r8) = 0;
    // 0x8002BD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BD40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BD44: jr          $ra
    // 0x8002BD48: nop

    return;
    // 0x8002BD48: nop

;}
RECOMP_FUNC void func_80067AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067AB4: jal         0x80010558
    // 0x80067AB8: nop

    func_80010558(rdram, ctx);
        goto after_0;
    // 0x80067AB8: nop

    after_0:
    // 0x80067ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067AC4: jr          $ra
    // 0x80067AC8: nop

    return;
    // 0x80067AC8: nop

;}
RECOMP_FUNC void func_8004DB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DB70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004DB74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004DB78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004DB7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DB80: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004DB84: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004DB88: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004DB8C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004DB90: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004DB94: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DB98: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x8004DB9C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004DBA0: beql        $v0, $zero, L_8004DBFC
    if (ctx->r2 == 0) {
        // 0x8004DBA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DBFC;
    }
    goto skip_0;
    // 0x8004DBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004DBA8: beql        $v0, $at, L_8004DBFC
    if (ctx->r2 == ctx->r1) {
        // 0x8004DBAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DBFC;
    }
    goto skip_1;
    // 0x8004DBAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004DBB0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004DBB4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004DBB8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004DBBC: beq         $v0, $at, L_8004DBF8
    if (ctx->r2 == ctx->r1) {
        // 0x8004DBC0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004DBF8;
    }
    // 0x8004DBC0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004DBC4: beq         $v0, $at, L_8004DBF8
    if (ctx->r2 == ctx->r1) {
        // 0x8004DBC8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004DBF8;
    }
    // 0x8004DBC8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004DBCC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004DBD0: jal         0x8004AF8C
    // 0x8004DBD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004AF8C(rdram, ctx);
        goto after_0;
    // 0x8004DBD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004DBD8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DBDC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004DBE0: lbu         $t1, 0x14($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X14);
    // 0x8004DBE4: beql        $t1, $zero, L_8004DBFC
    if (ctx->r9 == 0) {
        // 0x8004DBE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DBFC;
    }
    goto skip_2;
    // 0x8004DBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004DBEC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004DBF0: ori         $t3, $t2, 0xF000
    ctx->r11 = ctx->r10 | 0XF000;
    // 0x8004DBF4: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_8004DBF8:
    // 0x8004DBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004DBFC:
    // 0x8004DBFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004DC00: jr          $ra
    // 0x8004DC04: nop

    return;
    // 0x8004DC04: nop

;}
RECOMP_FUNC void func_800452C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800452C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800452C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800452C8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800452CC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800452D0: sb          $t6, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r14;
    // 0x800452D4: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x800452D8: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x800452DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800452E0: jal         0x800657CC
    // 0x800452E4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800657CC(rdram, ctx);
        goto after_0;
    // 0x800452E4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_0:
    // 0x800452E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800452EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800452F0: jr          $ra
    // 0x800452F4: nop

    return;
    // 0x800452F4: nop

;}
RECOMP_FUNC void func_8056888C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056888C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80568890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568894: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568898: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8056889C: addiu       $at, $zero, 0x4151
    ctx->r1 = ADD32(0, 0X4151);
    // 0x805688A0: beq         $v0, $at, L_805688C4
    if (ctx->r2 == ctx->r1) {
        // 0x805688A4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_805688C4;
    }
    // 0x805688A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805688A8: addiu       $at, $zero, 0x415D
    ctx->r1 = ADD32(0, 0X415D);
    // 0x805688AC: beq         $v0, $at, L_805688D4
    if (ctx->r2 == ctx->r1) {
        // 0x805688B0: addiu       $at, $zero, 0x4169
        ctx->r1 = ADD32(0, 0X4169);
            goto L_805688D4;
    }
    // 0x805688B0: addiu       $at, $zero, 0x4169
    ctx->r1 = ADD32(0, 0X4169);
    // 0x805688B4: beql        $v0, $at, L_805688E8
    if (ctx->r2 == ctx->r1) {
        // 0x805688B8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_805688E8;
    }
    goto skip_0;
    // 0x805688B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x805688BC: b           L_805688F4
    // 0x805688C0: nop

        goto L_805688F4;
    // 0x805688C0: nop

L_805688C4:
    // 0x805688C4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805688C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805688CC: b           L_805688F4
    // 0x805688D0: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
        goto L_805688F4;
    // 0x805688D0: swc1        $f4, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f4.u32l;
L_805688D4:
    // 0x805688D4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21D4) << 16);
    // 0x805688D8: lwc1        $f6, -0x687C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21D4));
    // 0x805688DC: b           L_805688F4
    // 0x805688E0: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
        goto L_805688F4;
    // 0x805688E0: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    // 0x805688E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_805688E8:
    // 0x805688E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805688EC: nop

    // 0x805688F0: swc1        $f8, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f8.u32l;
L_805688F4:
    // 0x805688F4: jal         0x80568710
    // 0x805688F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x805688F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x805688FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80568900: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80568904: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568908: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8056890C: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21D8) << 16);
    // 0x80568910: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
    // 0x80568914: swc1        $f10, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f10.u32l;
    // 0x80568918: swc1        $f16, 0xDC($a2)
    MEM_W(0XDC, ctx->r6) = ctx->f16.u32l;
    // 0x8056891C: lwc1        $f18, -0x6878($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21D8));
    // 0x80568920: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x80568924: lwc1        $f4, 0x3C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x80568928: swc1        $f18, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f18.u32l;
    // 0x8056892C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80568930: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80568934: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x80568938: jal         0x80048F84
    // 0x8056893C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8056893C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80568940: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80568944: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80568948: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8056894C: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568950: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80568954: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568958: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8056895C: jal         0x80569310
    // 0x80568960: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568960: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x80568964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568968: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8056896C: jr          $ra
    // 0x80568970: nop

    return;
    // 0x80568970: nop

;}
RECOMP_FUNC void func_80580D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580D54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80580D58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80580D5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80580D60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80580D64: jal         0x8057EF14
    // 0x80580D68: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80580D68: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    after_0:
    // 0x80580D6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80580D70: jal         0x80580C70
    // 0x80580D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80580C70(rdram, ctx);
        goto after_1;
    // 0x80580D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80580D78: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80580D7C: beql        $t6, $zero, L_80580DE8
    if (ctx->r14 == 0) {
        // 0x80580D80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80580DE8;
    }
    goto skip_0;
    // 0x80580D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80580D84: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80580D88: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80580D8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80580D90: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80580D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80580D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580D9C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80580DA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580DA4: bc1f        L_80580DDC
    if (!c1cs) {
        // 0x80580DA8: nop
    
            goto L_80580DDC;
    }
    // 0x80580DA8: nop

    // 0x80580DAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80580DB0: nop

    // 0x80580DB4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80580DB8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80580DBC: jal         0x80580CE8
    // 0x80580DC0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    func_80580CE8(rdram, ctx);
        goto after_2;
    // 0x80580DC0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x80580DC4: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80580DC8: sb          $v0, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r2;
    // 0x80580DCC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80580DD0: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80580DD4: b           L_80580DE4
    // 0x80580DD8: sb          $v0, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r2;
        goto L_80580DE4;
    // 0x80580DD8: sb          $v0, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r2;
L_80580DDC:
    // 0x80580DDC: jal         0x80580F6C
    // 0x80580DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80580F6C(rdram, ctx);
        goto after_3;
    // 0x80580DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80580DE4:
    // 0x80580DE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80580DE8:
    // 0x80580DE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80580DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80580DF0: jr          $ra
    // 0x80580DF4: nop

    return;
    // 0x80580DF4: nop

;}
RECOMP_FUNC void func_8042F380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042F384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042F388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042F38C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042F390: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8042F394: jal         0x80048F84
    // 0x8042F398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8042F398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8042F39C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042F3A0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8042F3A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F3A8: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8042F3AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042F3B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8042F3B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042F3B8: nop

    // 0x8042F3BC: bc1f        L_8042F3DC
    if (!c1cs) {
        // 0x8042F3C0: nop
    
            goto L_8042F3DC;
    }
    // 0x8042F3C0: nop

    // 0x8042F3C4: jal         0x8042F574
    // 0x8042F3C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042F574(rdram, ctx);
        goto after_1;
    // 0x8042F3C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8042F3CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042F3D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042F3D4: nop

    // 0x8042F3D8: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
L_8042F3DC:
    // 0x8042F3DC: jal         0x8042F134
    // 0x8042F3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042F134(rdram, ctx);
        goto after_2;
    // 0x8042F3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042F3E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042F3E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042F3EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042F3F0: jr          $ra
    // 0x8042F3F4: nop

    return;
    // 0x8042F3F4: nop

;}
RECOMP_FUNC void func_80776B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776B84: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80776B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80776B8C: beq         $t6, $zero, L_80776BC8
    if (ctx->r14 == 0) {
        // 0x80776B90: nop
    
            goto L_80776BC8;
    }
    // 0x80776B90: nop

    // 0x80776B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80776B98: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80776B9C: jalr        $t9
    // 0x80776BA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80776BA0: nop

    after_0:
    // 0x80776BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80776BA8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80776BAC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80776BB0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80776BB4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80776BB8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80776BBC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80776BC0: b           L_80776BC8
    // 0x80776BC4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80776BC8;
    // 0x80776BC4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80776BC8:
    // 0x80776BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80776BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776BD0: jr          $ra
    // 0x80776BD4: nop

    return;
    // 0x80776BD4: nop

;}
RECOMP_FUNC void func_8042C604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042C608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042C60C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042C610: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042C614: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042C618: jal         0x8004700C
    // 0x8042C61C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042C61C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8042C620: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8042C624: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042C628: jal         0x8006CB1C
    // 0x8042C62C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8006CB1C(rdram, ctx);
        goto after_1;
    // 0x8042C62C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8042C630: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8042C634: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042C638: jal         0x8006CB2C
    // 0x8042C63C: nop

    func_8006CB2C(rdram, ctx);
        goto after_2;
    // 0x8042C63C: nop

    after_2:
    // 0x8042C640: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8042C644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8042C648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C64C: beq         $v0, $zero, L_8042C664
    if (ctx->r2 == 0) {
        // 0x8042C650: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_8042C664;
    }
    // 0x8042C650: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8042C654: jal         0x8042BD04
    // 0x8042C658: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    func_8042BD04(rdram, ctx);
        goto after_3;
    // 0x8042C658: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    after_3:
    // 0x8042C65C: b           L_8042C670
    // 0x8042C660: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
        goto L_8042C670;
    // 0x8042C660: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
L_8042C664:
    // 0x8042C664: jal         0x8042BD04
    // 0x8042C668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BD04(rdram, ctx);
        goto after_4;
    // 0x8042C668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8042C66C: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
L_8042C670:
    // 0x8042C670: jal         0x8042A9DC
    // 0x8042C674: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_5;
    // 0x8042C674: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_5:
    // 0x8042C678: jal         0x8042BB3C
    // 0x8042C67C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_6;
    // 0x8042C67C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8042C680: jal         0x8042BA84
    // 0x8042C684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BA84(rdram, ctx);
        goto after_7;
    // 0x8042C684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8042C688: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042C68C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8042C690: slti        $at, $t8, 0x96
    ctx->r1 = SIGNED(ctx->r24) < 0X96 ? 1 : 0;
    // 0x8042C694: bnel        $at, $zero, L_8042C734
    if (ctx->r1 != 0) {
        // 0x8042C698: lw          $t3, 0x1E0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1E0);
            goto L_8042C734;
    }
    goto skip_0;
    // 0x8042C698: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x8042C69C: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x8042C6A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C6A4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8042C6A8: bne         $v0, $at, L_8042C6F0
    if (ctx->r2 != ctx->r1) {
        // 0x8042C6AC: nop
    
            goto L_8042C6F0;
    }
    // 0x8042C6AC: nop

    // 0x8042C6B0: lwc1        $f4, 0x84($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X84);
    // 0x8042C6B4: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8042C6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C6BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C6C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042C6C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8042C6C8: bc1f        L_8042C6F0
    if (!c1cs) {
        // 0x8042C6CC: nop
    
            goto L_8042C6F0;
    }
    // 0x8042C6CC: nop

    // 0x8042C6D0: jal         0x8042D50C
    // 0x8042C6D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042D50C(rdram, ctx);
        goto after_8;
    // 0x8042C6D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8042C6D8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8042C6DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C6E0: jal         0x8042C194
    // 0x8042C6E4: addiu       $a1, $zero, 0x28E
    ctx->r5 = ADD32(0, 0X28E);
    func_8042C194(rdram, ctx);
        goto after_9;
    // 0x8042C6E4: addiu       $a1, $zero, 0x28E
    ctx->r5 = ADD32(0, 0X28E);
    after_9:
    // 0x8042C6E8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8042C6EC: lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XC);
L_8042C6F0:
    // 0x8042C6F0: bne         $v0, $zero, L_8042C730
    if (ctx->r2 != 0) {
        // 0x8042C6F4: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8042C730;
    }
    // 0x8042C6F4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8042C6F8: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8042C6FC: lwc1        $f10, 0x84($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X84);
    // 0x8042C700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C708: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8042C70C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8042C710: bc1fl       L_8042C734
    if (!c1cs) {
        // 0x8042C714: lw          $t3, 0x1E0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1E0);
            goto L_8042C734;
    }
    goto skip_1;
    // 0x8042C714: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
    skip_1:
    // 0x8042C718: jal         0x8042D50C
    // 0x8042C71C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_10;
    // 0x8042C71C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x8042C720: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8042C724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042C728: jal         0x8042C194
    // 0x8042C72C: addiu       $a1, $zero, 0x28E
    ctx->r5 = ADD32(0, 0X28E);
    func_8042C194(rdram, ctx);
        goto after_11;
    // 0x8042C72C: addiu       $a1, $zero, 0x28E
    ctx->r5 = ADD32(0, 0X28E);
    after_11:
L_8042C730:
    // 0x8042C730: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
L_8042C734:
    // 0x8042C734: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8042C738: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x8042C73C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C740: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042C744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042C748: jr          $ra
    // 0x8042C74C: nop

    return;
    // 0x8042C74C: nop

;}
RECOMP_FUNC void func_8002CD7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CD7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CD80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002CD84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002CD88: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8002CD8C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CD90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CD94: jal         0x8002AFDC
    // 0x8002CD98: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8002AFDC(rdram, ctx);
        goto after_0;
    // 0x8002CD98: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002CD9C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDA0: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002CDA4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002CDA8: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x8002CDAC: addiu       $t8, $t8, 0x1FD8
    ctx->r24 = ADD32(ctx->r24, 0X1FD8);
    // 0x8002CDB0: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x8002CDB4: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8002CDB8: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8002CDBC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8002CDC0: lw          $v1, -0x727C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X727C);
    // 0x8002CDC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002CDC8: beql        $v1, $zero, L_8002CDEC
    if (ctx->r3 == 0) {
        // 0x8002CDCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002CDEC;
    }
    goto skip_0;
    // 0x8002CDCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8002CDD0: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8002CDD4: lwc1        $f14, 0x88($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8002CDD8: lw          $a2, 0x8C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8C);
    // 0x8002CDDC: jalr        $v1
    // 0x8002CDE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x8002CDE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8002CDE4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002CDEC:
    // 0x8002CDEC: jal         0x8005FE48
    // 0x8002CDF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8002CDF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002CDF4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002CDFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002CE00: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002CE04: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8002CE08: sb          $zero, 0x74($t9)
    MEM_B(0X74, ctx->r25) = 0;
    // 0x8002CE0C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8002CE10: sb          $zero, 0x75($t0)
    MEM_B(0X75, ctx->r8) = 0;
    // 0x8002CE14: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8002CE18: sw          $zero, 0x44($t1)
    MEM_W(0X44, ctx->r9) = 0;
    // 0x8002CE1C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8002CE20: sh          $zero, 0x4C($t2)
    MEM_H(0X4C, ctx->r10) = 0;
    // 0x8002CE24: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8002CE28: sb          $t3, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r11;
    // 0x8002CE2C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8002CE30: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8002CE34: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8002CE38: jal         0x800677F8
    // 0x8002CE3C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x8002CE3C: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x8002CE40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CE44: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8002CE48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002CE4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002CE50: sb          $t4, 0x7EA2($at)
    MEM_B(0X7EA2, ctx->r1) = ctx->r12;
    // 0x8002CE54: jr          $ra
    // 0x8002CE58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002CE58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80798950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798950: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(823, 0XE4) << 16);
    // 0x80798954: addiu       $t6, $t6, -0x75CC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(823, 0XE4));
    // 0x80798958: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079895C: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(823, 0X54) << 16);
    // 0x80798960: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80798964: sw          $t6, -0x72B8($at)
    MEM_W(-0X72B8, ctx->r1) = ctx->r14;
    // 0x80798968: jr          $ra
    // 0x8079896C: addiu       $v0, $v0, -0x765C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(823, 0X54));
    return;
    // 0x8079896C: addiu       $v0, $v0, -0x765C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(823, 0X54));
;}
RECOMP_FUNC void func_8001AF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF14: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001AF18: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001AF1C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001AF20: jr          $ra
    // 0x8001AF24: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8001AF24: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_80050848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005084C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050850: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80050854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050858: jal         0x800506B4
    // 0x8005085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800506B4(rdram, ctx);
        goto after_0;
    // 0x8005085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80050860: bne         $v0, $zero, L_8005087C
    if (ctx->r2 != 0) {
        // 0x80050864: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005087C;
    }
    // 0x80050864: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80050868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005086C: jal         0x80050790
    // 0x80050870: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80050790(rdram, ctx);
        goto after_1;
    // 0x80050870: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80050874: b           L_80050884
    // 0x80050878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050884;
    // 0x80050878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005087C:
    // 0x8005087C: jal         0x80050820
    // 0x80050880: nop

    func_80050820(rdram, ctx);
        goto after_2;
    // 0x80050880: nop

    after_2:
L_80050884:
    // 0x80050884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005088C: jr          $ra
    // 0x80050890: nop

    return;
    // 0x80050890: nop

;}
RECOMP_FUNC void func_80424EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80424EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424EC8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80424ECC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80424ED0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80424ED4: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X362C) << 16);
    // 0x80424ED8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80424EDC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80424EE0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80424EE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80424EE8: lw          $t8, 0x602C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X362C));
    // 0x80424EEC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80424EF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80424EF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80424EF8: jal         0x80048490
    // 0x80424EFC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80424EFC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80424F00: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80424F04: jal         0x80048378
    // 0x80424F08: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80424F08: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80424F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80424F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424F14: jr          $ra
    // 0x80424F18: nop

    return;
    // 0x80424F18: nop

;}
RECOMP_FUNC void func_807B810C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B810C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807B8110: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807B8114: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x807B8118: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B811C: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(883, 0X544) << 16);
    // 0x807B8120: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807B8124: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807B8128: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807B812C: lw          $t8, -0x7E7C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(883, 0X544));
    // 0x807B8130: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807B8134: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807B8138: jr          $ra
    // 0x807B813C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x807B813C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80052354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052354: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80052358: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8005235C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052360: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80052364: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052368: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x8005236C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80052370: jal         0x8008D960
    // 0x80052374: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_0;
    // 0x80052374: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80052378: beq         $v0, $zero, L_80052388
    if (ctx->r2 == 0) {
        // 0x8005237C: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80052388;
    }
    // 0x8005237C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80052380: b           L_80052458
    // 0x80052384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80052458;
    // 0x80052384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80052388:
    // 0x80052388: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8005238C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052390: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x80052394: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80052398: bne         $at, $zero, L_800523A8
    if (ctx->r1 != 0) {
        // 0x8005239C: nop
    
            goto L_800523A8;
    }
    // 0x8005239C: nop

    // 0x800523A0: b           L_80052454
    // 0x800523A4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80052454;
    // 0x800523A4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800523A8:
    // 0x800523A8: jal         0x80082360
    // 0x800523AC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_1;
    // 0x800523AC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x800523B0: beq         $v0, $zero, L_800523C0
    if (ctx->r2 == 0) {
        // 0x800523B4: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_800523C0;
    }
    // 0x800523B4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800523B8: b           L_80052458
    // 0x800523BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80052458;
    // 0x800523BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800523C0:
    // 0x800523C0: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x800523C4: beq         $at, $zero, L_800523D4
    if (ctx->r1 == 0) {
        // 0x800523C8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800523D4;
    }
    // 0x800523C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800523CC: b           L_80052454
    // 0x800523D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80052454;
    // 0x800523D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800523D4:
    // 0x800523D4: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800523D8: addiu       $t9, $t9, 0xAD0
    ctx->r25 = ADD32(ctx->r25, 0XAD0);
    // 0x800523DC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800523E0: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800523E4: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800523E8: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x800523EC: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800523F0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800523F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800523F8: addiu       $a3, $a3, 0xAC0
    ctx->r7 = ADD32(ctx->r7, 0XAC0);
    // 0x800523FC: lw          $a2, 0x5CC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CC4);
    // 0x80052400: lhu         $a1, 0x5CC0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X5CC0);
    // 0x80052404: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80052408: jal         0x80087B50
    // 0x8005240C: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_2;
    // 0x8005240C: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    after_2:
    // 0x80052410: beq         $v0, $zero, L_80052420
    if (ctx->r2 == 0) {
        // 0x80052414: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_80052420;
    }
    // 0x80052414: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80052418: b           L_80052458
    // 0x8005241C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80052458;
    // 0x8005241C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80052420:
    // 0x80052420: addiu       $a0, $a0, 0x5CC8
    ctx->r4 = ADD32(ctx->r4, 0X5CC8);
    // 0x80052424: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80052428: jal         0x80052300
    // 0x8005242C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80052300(rdram, ctx);
        goto after_3;
    // 0x8005242C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80052430: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80052434: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80052438: jal         0x80052300
    // 0x8005243C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80052300(rdram, ctx);
        goto after_4;
    // 0x8005243C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80052440: beql        $v0, $zero, L_80052454
    if (ctx->r2 == 0) {
        // 0x80052444: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80052454;
    }
    goto skip_0;
    // 0x80052444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80052448: b           L_80052458
    // 0x8005244C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80052458;
    // 0x8005244C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052454:
    // 0x80052454: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80052458:
    // 0x80052458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005245C: jr          $ra
    // 0x80052460: nop

    return;
    // 0x80052460: nop

;}
RECOMP_FUNC void func_807B8340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8340: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807B8344: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x807B8348: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x807B834C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x807B8350: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x807B8354: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x807B8358: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x807B835C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x807B8360: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B8364: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B8368: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x807B836C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8370: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x807B8374: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B8378: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x807B837C: addiu       $s6, $zero, 0x60
    ctx->r22 = ADD32(0, 0X60);
    // 0x807B8380: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(886, 0X1DA0) << 16);
    // 0x807B8384: blez        $v0, L_807B842C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807B8388: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_807B842C;
    }
    // 0x807B8388: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x807B838C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x807B8390: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x807B8394: lwc1        $f20, -0x5FF0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(886, 0X1DA0));
    // 0x807B8398: addiu       $s5, $zero, 0x111
    ctx->r21 = ADD32(0, 0X111);
    // 0x807B839C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_807B83A0:
    // 0x807B83A0: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x807B83A4: beql        $a1, $zero, L_807B8420
    if (ctx->r5 == 0) {
        // 0x807B83A8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_807B8420;
    }
    goto skip_0;
    // 0x807B83A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x807B83AC: jal         0x80047F9C
    // 0x807B83B0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80047F9C(rdram, ctx);
        goto after_0;
    // 0x807B83B0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x807B83B4: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x807B83B8: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
    // 0x807B83BC: lw          $v0, 0xFB8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XFB8);
    // 0x807B83C0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x807B83C4: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x807B83C8: beql        $v0, $zero, L_807B83E4
    if (ctx->r2 == 0) {
        // 0x807B83CC: lw          $a1, 0x24($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X24);
            goto L_807B83E4;
    }
    goto skip_1;
    // 0x807B83CC: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x807B83D0: beql        $v0, $s4, L_807B8404
    if (ctx->r2 == ctx->r20) {
        // 0x807B83D4: lw          $a1, 0x24($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X24);
            goto L_807B8404;
    }
    goto skip_2;
    // 0x807B83D4: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x807B83D8: b           L_807B841C
    // 0x807B83DC: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
        goto L_807B841C;
    // 0x807B83DC: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x807B83E0: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
L_807B83E4:
    // 0x807B83E4: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x807B83E8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x807B83EC: beq         $s6, $t8, L_807B83F8
    if (ctx->r22 == ctx->r24) {
        // 0x807B83F0: nop
    
            goto L_807B83F8;
    }
    // 0x807B83F0: nop

    // 0x807B83F4: swc1        $f20, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f20.u32l;
L_807B83F8:
    // 0x807B83F8: b           L_807B841C
    // 0x807B83FC: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
        goto L_807B841C;
    // 0x807B83FC: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x807B8400: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
L_807B8404:
    // 0x807B8404: lw          $t9, 0x1F4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1F4);
    // 0x807B8408: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x807B840C: beql        $s5, $t0, L_807B841C
    if (ctx->r21 == ctx->r8) {
        // 0x807B8410: lw          $v0, 0x3C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X3C);
            goto L_807B841C;
    }
    goto skip_3;
    // 0x807B8410: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    skip_3:
    // 0x807B8414: swc1        $f20, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f20.u32l;
    // 0x807B8418: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
L_807B841C:
    // 0x807B841C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_807B8420:
    // 0x807B8420: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x807B8424: bne         $at, $zero, L_807B83A0
    if (ctx->r1 != 0) {
        // 0x807B8428: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_807B83A0;
    }
    // 0x807B8428: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_807B842C:
    // 0x807B842C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x807B8430: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x807B8434: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8438: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B843C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x807B8440: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x807B8444: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x807B8448: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x807B844C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x807B8450: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x807B8454: jr          $ra
    // 0x807B8458: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x807B8458: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80446AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446AE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446AEC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446AF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446AF4: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80446AF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446AFC: sw          $t6, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r14;
    // 0x80446B00: addiu       $v1, $zero, 0x744
    ctx->r3 = ADD32(0, 0X744);
    // 0x80446B04: addiu       $t7, $zero, 0x3C0
    ctx->r15 = ADD32(0, 0X3C0);
    // 0x80446B08: addiu       $t8, $zero, 0x618
    ctx->r24 = ADD32(0, 0X618);
    // 0x80446B0C: addiu       $t9, $zero, 0xAC8
    ctx->r25 = ADD32(0, 0XAC8);
    // 0x80446B10: sw          $t7, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r15;
    // 0x80446B14: sw          $t8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r24;
    // 0x80446B18: sw          $v1, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r3;
    // 0x80446B1C: sw          $v1, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->r3;
    // 0x80446B20: jr          $ra
    // 0x80446B24: sw          $t9, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r25;
    return;
    // 0x80446B24: sw          $t9, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_8006DDCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DDCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DDD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DDD4: jal         0x8006D7E8
    // 0x8006DDD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006D7E8(rdram, ctx);
        goto after_0;
    // 0x8006DDD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006DDDC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8006DDE0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8006DDE4: lw          $t6, 0x3F0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3F0);
    // 0x8006DDE8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8006DDEC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006DDF0: sb          $v0, 0x598($t7)
    MEM_B(0X598, ctx->r15) = ctx->r2;
    // 0x8006DDF4: jal         0x8006DA0C
    // 0x8006DDF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006DA0C(rdram, ctx);
        goto after_1;
    // 0x8006DDF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006DDFC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006DE00: jal         0x8006DD34
    // 0x8006DE04: lw          $a0, 0x20($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20);
    func_8006DD34(rdram, ctx);
        goto after_2;
    // 0x8006DE04: lw          $a0, 0x20($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20);
    after_2:
    // 0x8006DE08: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8006DE0C: lw          $t9, -0x7890($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7890);
    // 0x8006DE10: sh          $zero, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = 0;
    // 0x8006DE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DE1C: jr          $ra
    // 0x8006DE20: nop

    return;
    // 0x8006DE20: nop

;}
