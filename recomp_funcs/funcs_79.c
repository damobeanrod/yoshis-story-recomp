#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800522B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800522B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800522BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800522C0: addiu       $a1, $zero, 0x518
    ctx->r5 = ADD32(0, 0X518);
    // 0x800522C4: jal         0x80065728
    // 0x800522C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x800522C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800522CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800522D0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800522D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800522D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800522DC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800522E0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800522E4: sw          $t6, 0xAA8($v0)
    MEM_W(0XAA8, ctx->r2) = ctx->r14;
    // 0x800522E8: sb          $zero, 0xB2C($v0)
    MEM_B(0XB2C, ctx->r2) = 0;
    // 0x800522EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800522F0: jr          $ra
    // 0x800522F4: swc1        $f4, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x800522F4: swc1        $f4, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->f4.u32l;
    // 0x800522F8: nop

    // 0x800522FC: nop

;}
RECOMP_FUNC void func_80080050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080050: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80080054: addiu       $t6, $t6, -0x5CB0
    ctx->r14 = ADD32(ctx->r14, -0X5CB0);
    // 0x80080058: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8008005C: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_80080060:
    // 0x80080060: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80080064: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80080068: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8008006C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80080070: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80080074: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80080078: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8008007C: bne         $t6, $t0, L_80080060
    if (ctx->r14 != ctx->r8) {
        // 0x80080080: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80080060;
    }
    // 0x80080080: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80080084: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80080088: jr          $ra
    // 0x8008008C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    return;
    // 0x8008008C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void func_8067323C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067323C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80673240: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80673244: lw          $t1, 0x70($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X70);
    // 0x80673248: lw          $v1, 0x2C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X2C);
    // 0x8067324C: lw          $a3, 0x30($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X30);
    // 0x80673250: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80673254: lwc1        $f2, 0x4($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80673258: lw          $t0, 0x34($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X34);
    // 0x8067325C: beq         $v1, $zero, L_806734AC
    if (ctx->r3 == 0) {
        // 0x80673260: sw          $a1, 0x3C($a2)
        MEM_W(0X3C, ctx->r6) = ctx->r5;
            goto L_806734AC;
    }
    // 0x80673260: sw          $a1, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r5;
    // 0x80673264: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x80673268: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8067326C: beq         $a0, $zero, L_80673304
    if (ctx->r4 == 0) {
        // 0x80673270: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_80673304;
    }
    // 0x80673270: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x80673274: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80673278: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8067327C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80673280: nop

    // 0x80673284: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673288: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8067328C: beql        $v0, $v1, L_806732DC
    if (ctx->r2 == ctx->r3) {
        // 0x80673290: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_806732DC;
    }
    goto skip_0;
    // 0x80673290: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_0:
    // 0x80673294: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_80673298:
    // 0x80673298: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8067329C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x806732A0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x806732A4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806732A8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806732AC: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x806732B0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806732B4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x806732B8: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x806732BC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x806732C0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806732C4: nop

    // 0x806732C8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806732CC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806732D0: bnel        $v0, $v1, L_80673298
    if (ctx->r2 != ctx->r3) {
        // 0x806732D4: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_80673298;
    }
    goto skip_1;
    // 0x806732D4: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_1:
    // 0x806732D8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_806732DC:
    // 0x806732DC: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x806732E0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x806732E4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806732E8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806732EC: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x806732F0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806732F4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x806732F8: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x806732FC: beq         $v1, $zero, L_806734AC
    if (ctx->r3 == 0) {
        // 0x80673300: nop
    
            goto L_806734AC;
    }
    // 0x80673300: nop

L_80673304:
    // 0x80673304: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80673308: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8067330C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80673310: nop

    // 0x80673314: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673318: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8067331C: beql        $v1, $zero, L_806733FC
    if (ctx->r3 == 0) {
        // 0x80673320: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_806733FC;
    }
    goto skip_2;
    // 0x80673320: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_2:
    // 0x80673324: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_80673328:
    // 0x80673328: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x8067332C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80673330: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80673334: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80673338: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8067333C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80673340: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673344: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80673348: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x8067334C: lh          $t2, -0x12($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X12);
    // 0x80673350: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80673354: nop

    // 0x80673358: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067335C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80673360: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80673364: lh          $t3, -0x10($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X10);
    // 0x80673368: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8067336C: nop

    // 0x80673370: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673374: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80673378: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8067337C: lh          $t4, -0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, -0XC);
    // 0x80673380: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80673384: nop

    // 0x80673388: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067338C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80673390: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x80673394: lh          $t5, -0xA($a1)
    ctx->r13 = MEM_H(ctx->r5, -0XA);
    // 0x80673398: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8067339C: nop

    // 0x806733A0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806733A4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x806733A8: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x806733AC: lh          $t6, -0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, -0X6);
    // 0x806733B0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806733B4: nop

    // 0x806733B8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806733BC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806733C0: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x806733C4: lh          $t7, -0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, -0X4);
    // 0x806733C8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x806733CC: nop

    // 0x806733D0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806733D4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x806733D8: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x806733DC: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x806733E0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806733E4: nop

    // 0x806733E8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806733EC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806733F0: bnel        $v1, $zero, L_80673328
    if (ctx->r3 != 0) {
        // 0x806733F4: swc1        $f18, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
            goto L_80673328;
    }
    goto skip_3;
    // 0x806733F4: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    skip_3:
    // 0x806733F8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_806733FC:
    // 0x806733FC: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80673400: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80673404: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80673408: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8067340C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80673410: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673414: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80673418: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x8067341C: lh          $t2, -0x12($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X12);
    // 0x80673420: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80673424: nop

    // 0x80673428: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067342C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80673430: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80673434: lh          $t3, -0x10($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X10);
    // 0x80673438: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8067343C: nop

    // 0x80673440: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673444: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80673448: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8067344C: lh          $t4, -0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, -0XC);
    // 0x80673450: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80673454: nop

    // 0x80673458: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067345C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80673460: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x80673464: lh          $t5, -0xA($a1)
    ctx->r13 = MEM_H(ctx->r5, -0XA);
    // 0x80673468: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8067346C: nop

    // 0x80673470: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80673474: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80673478: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8067347C: lh          $t6, -0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, -0X6);
    // 0x80673480: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80673484: nop

    // 0x80673488: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8067348C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80673490: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x80673494: lh          $t7, -0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, -0X4);
    // 0x80673498: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8067349C: nop

    // 0x806734A0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806734A4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x806734A8: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
L_806734AC:
    // 0x806734AC: jr          $ra
    // 0x806734B0: nop

    return;
    // 0x806734B0: nop

;}
RECOMP_FUNC void func_804BB1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB1F8: jal         0x804BB0C8
    // 0x804BB1FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804BB0C8(rdram, ctx);
        goto after_0;
    // 0x804BB1FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB200: bne         $v0, $zero, L_804BB280
    if (ctx->r2 != 0) {
        // 0x804BB204: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804BB280;
    }
    // 0x804BB204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB208: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x804BB20C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB210: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x804BB214: beql        $at, $zero, L_804BB230
    if (ctx->r1 == 0) {
        // 0x804BB218: lw          $t7, 0x1E0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X1E0);
            goto L_804BB230;
    }
    goto skip_0;
    // 0x804BB218: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    skip_0:
    // 0x804BB21C: jal         0x804BB4C4
    // 0x804BB220: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_804BB4C4(rdram, ctx);
        goto after_1;
    // 0x804BB220: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x804BB224: b           L_804BB284
    // 0x804BB228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB284;
    // 0x804BB228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB22C: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
L_804BB230:
    // 0x804BB230: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x804BB234: slti        $at, $t8, 0x3C
    ctx->r1 = SIGNED(ctx->r24) < 0X3C ? 1 : 0;
    // 0x804BB238: bne         $at, $zero, L_804BB280
    if (ctx->r1 != 0) {
        // 0x804BB23C: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_804BB280;
    }
    // 0x804BB23C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x804BB240: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x804BB244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BB248: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804BB24C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x804BB250: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804BB254: nop

    // 0x804BB258: bc1fl       L_804BB284
    if (!c1cs) {
        // 0x804BB25C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BB284;
    }
    goto skip_1;
    // 0x804BB25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804BB260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BB264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB268: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x804BB26C: nop

    // 0x804BB270: bc1fl       L_804BB284
    if (!c1cs) {
        // 0x804BB274: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BB284;
    }
    goto skip_2;
    // 0x804BB274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804BB278: jal         0x804BB4C4
    // 0x804BB27C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_804BB4C4(rdram, ctx);
        goto after_2;
    // 0x804BB27C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
L_804BB280:
    // 0x804BB280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB284:
    // 0x804BB284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB288: jr          $ra
    // 0x804BB28C: nop

    return;
    // 0x804BB28C: nop

;}
RECOMP_FUNC void func_800628E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800628E4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800628E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800628EC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800628F0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800628F4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800628F8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800628FC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80062900: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80062904: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80062908: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8006290C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80062910: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80062914: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80062918: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8006291C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80062920: lh          $s1, 0x184($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X184);
    // 0x80062924: addiu       $s0, $a0, 0x188
    ctx->r16 = ADD32(ctx->r4, 0X188);
    // 0x80062928: lh          $t8, 0x56($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X56);
    // 0x8006292C: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x80062930: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80062934: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80062938: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8006293C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80062940: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80062944: mul.s       $f22, $f4, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80062948: jal         0x80047AB8
    // 0x8006294C: nop

    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8006294C: nop

    after_0:
    // 0x80062950: beq         $s1, $zero, L_80062ABC
    if (ctx->r17 == 0) {
        // 0x80062954: addiu       $s5, $zero, 0x4001
        ctx->r21 = ADD32(0, 0X4001);
            goto L_80062ABC;
    }
    // 0x80062954: addiu       $s5, $zero, 0x4001
    ctx->r21 = ADD32(0, 0X4001);
    // 0x80062958: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8006295C: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
L_80062960:
    // 0x80062960: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80062964: beq         $v0, $zero, L_80062AB4
    if (ctx->r2 == 0) {
        // 0x80062968: nop
    
            goto L_80062AB4;
    }
    // 0x80062968: nop

    // 0x8006296C: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x80062970: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80062974: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80062978: bne         $s5, $t9, L_80062AB4
    if (ctx->r21 != ctx->r25) {
        // 0x8006297C: sra         $s1, $s1, 16
        ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
            goto L_80062AB4;
    }
    // 0x8006297C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80062980: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x80062984: beq         $v1, $zero, L_80062AB4
    if (ctx->r3 == 0) {
        // 0x80062988: nop
    
            goto L_80062AB4;
    }
    // 0x80062988: nop

    // 0x8006298C: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80062990: bne         $s2, $t0, L_80062AB4
    if (ctx->r18 != ctx->r8) {
        // 0x80062994: nop
    
            goto L_80062AB4;
    }
    // 0x80062994: nop

    // 0x80062998: lwc1        $f10, 0xC4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x8006299C: mul.s       $f20, $f22, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800629A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800629A4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800629A8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800629AC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800629B0: lwc1        $f16, 0xC8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x800629B4: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x800629B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800629BC: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x800629C0: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800629C4: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x800629C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800629CC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800629D0: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800629D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800629D8: swc1        $f16, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f16.u32l;
    // 0x800629DC: jal         0x80047AB8
    // 0x800629E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x800629E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800629E4: bne         $s3, $zero, L_80062A08
    if (ctx->r19 != 0) {
        // 0x800629E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80062A08;
    }
    // 0x800629E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800629EC: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800629F0: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800629F4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800629F8: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800629FC: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80062A00: b           L_80062A14
    // 0x80062A04: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
        goto L_80062A14;
    // 0x80062A04: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
L_80062A08:
    // 0x80062A08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80062A0C: jalr        $s3
    // 0x80062A10: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_2;
    // 0x80062A10: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
L_80062A14:
    // 0x80062A14: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80062A18: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80062A1C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80062A20: mul.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80062A24: c.le.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl <= ctx->f20.fl;
    // 0x80062A28: nop

    // 0x80062A2C: bc1fl       L_80062A90
    if (!c1cs) {
        // 0x80062A30: add.s       $f8, $f18, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
            goto L_80062A90;
    }
    goto skip_0;
    // 0x80062A30: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    skip_0:
    // 0x80062A34: sub.s       $f0, $f20, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f12.fl;
    // 0x80062A38: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80062A3C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80062A40: lw          $t3, 0x174($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X174);
    // 0x80062A44: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80062A48: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x80062A4C: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80062A50: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80062A54: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80062A58: lwc1        $f2, 0x4($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80062A5C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80062A60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80062A64: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80062A68: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80062A6C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80062A70: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80062A74: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80062A78: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80062A7C: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x80062A80: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80062A84: b           L_80062A9C
    // 0x80062A88: swc1        $f24, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f24.u32l;
        goto L_80062A9C;
    // 0x80062A88: swc1        $f24, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f24.u32l;
    // 0x80062A8C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
L_80062A90:
    // 0x80062A90: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80062A94: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80062A98: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
L_80062A9C:
    // 0x80062A9C: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80062AA0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80062AA4: swc1        $f16, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f16.u32l;
    // 0x80062AA8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80062AAC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80062AB0: swc1        $f18, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f18.u32l;
L_80062AB4:
    // 0x80062AB4: bne         $s1, $zero, L_80062960
    if (ctx->r17 != 0) {
        // 0x80062AB8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80062960;
    }
    // 0x80062AB8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80062ABC:
    // 0x80062ABC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80062AC0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80062AC4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80062AC8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80062ACC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80062AD0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80062AD4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80062AD8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80062ADC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80062AE0: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80062AE4: jr          $ra
    // 0x80062AE8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80062AE8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_806B282C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B282C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2830: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2834: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2838: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B283C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2840: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2844: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2848: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B284C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2850: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2854: jr          $ra
    // 0x806B2858: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2858: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8058457C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058457C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584580: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584584: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584588: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058458C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584590: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584594: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584598: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058459C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805845A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805845A4: jr          $ra
    // 0x805845A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805845A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B1470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B1474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B1478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806B147C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806B1480: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806B1484: bnel        $t6, $at, L_806B14D0
    if (ctx->r14 != ctx->r1) {
        // 0x806B1488: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B14D0;
    }
    goto skip_0;
    // 0x806B1488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806B148C: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x806B1490: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x806B1494: beql        $at, $zero, L_806B14D0
    if (ctx->r1 == 0) {
        // 0x806B1498: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B14D0;
    }
    goto skip_1;
    // 0x806B1498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806B149C: jal         0x806B1224
    // 0x806B14A0: nop

    func_806B1224(rdram, ctx);
        goto after_0;
    // 0x806B14A0: nop

    after_0:
    // 0x806B14A4: jal         0x8001D770
    // 0x806B14A8: nop

    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x806B14A8: nop

    after_1:
    // 0x806B14AC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806B14B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806B14B4: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x806B14B8: jal         0x80067BF8
    // 0x806B14BC: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x806B14BC: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_2:
    // 0x806B14C0: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    // 0x806B14C4: jal         0x80067818
    // 0x806B14C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806B14C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806B14CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B14D0:
    // 0x806B14D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B14D4: jr          $ra
    // 0x806B14D8: nop

    return;
    // 0x806B14D8: nop

;}
RECOMP_FUNC void func_80474934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474934: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80474938: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8047493C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80474940: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80474944: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80474948: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8047494C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80474950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80474954: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80474958: lw          $t6, 0x6D10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X6D10);
    // 0x8047495C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80474960: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474964: beq         $t6, $zero, L_804749B0
    if (ctx->r14 == 0) {
        // 0x80474968: addiu       $a1, $zero, 0x21C
        ctx->r5 = ADD32(0, 0X21C);
            goto L_804749B0;
    }
    // 0x80474968: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x8047496C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474970: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474974: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294E0) << 16);
    // 0x80474978: lwc1        $f4, -0x2360($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294E0));
    // 0x8047497C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80474980: addiu       $t7, $zero, 0x1D10
    ctx->r15 = ADD32(0, 0X1D10);
    // 0x80474984: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80474988: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8047498C: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474990: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474994: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80474998: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8047499C: jal         0x804747CC
    // 0x804749A0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_804747CC(rdram, ctx);
        goto after_0;
    // 0x804749A0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x804749A4: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x804749A8: b           L_804749FC
    // 0x804749AC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_804749FC;
    // 0x804749AC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_804749B0:
    // 0x804749B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804749B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804749B8: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294E4) << 16);
    // 0x804749BC: lwc1        $f8, -0x235C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294E4));
    // 0x804749C0: lwc1        $f0, 0x6AA0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6AA0);
    // 0x804749C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804749C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804749CC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294E8) << 16);
    // 0x804749D0: lwc1        $f16, -0x2358($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294E8));
    // 0x804749D4: addiu       $t8, $zero, 0x1D10
    ctx->r24 = ADD32(0, 0X1D10);
    // 0x804749D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x804749DC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x804749E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x804749E4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x804749E8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x804749EC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x804749F0: jal         0x804748D0
    // 0x804749F4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_804748D0(rdram, ctx);
        goto after_1;
    // 0x804749F4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x804749F8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_804749FC:
    // 0x804749FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474A00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474A04: nop

    // 0x80474A08: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80474A0C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80474A10: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80474A14: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80474A18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80474A1C: jr          $ra
    // 0x80474A20: nop

    return;
    // 0x80474A20: nop

;}
RECOMP_FUNC void func_80522F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522F48: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80522F4C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80522F50: lw          $t6, 0xE88($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XE88);
    // 0x80522F54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80522F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522F5C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80522F60: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80522F64: bnel        $v0, $zero, L_80522F7C
    if (ctx->r2 != 0) {
        // 0x80522F68: sw          $zero, 0x20($v1)
        MEM_W(0X20, ctx->r3) = 0;
            goto L_80522F7C;
    }
    goto skip_0;
    // 0x80522F68: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    skip_0:
    // 0x80522F6C: lw          $t7, 0xE84($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XE84);
    // 0x80522F70: beql        $t7, $zero, L_80523010
    if (ctx->r15 == 0) {
        // 0x80522F74: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80523010;
    }
    goto skip_1;
    // 0x80522F74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    skip_1:
    // 0x80522F78: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
L_80522F7C:
    // 0x80522F7C: lw          $t8, 0xE84($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XE84);
    // 0x80522F80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80522F84: beql        $t8, $zero, L_80522F94
    if (ctx->r24 == 0) {
        // 0x80522F88: lbu         $t0, 0x165($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X165);
            goto L_80522F94;
    }
    goto skip_2;
    // 0x80522F88: lbu         $t0, 0x165($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X165);
    skip_2:
    // 0x80522F8C: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x80522F90: lbu         $t0, 0x165($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X165);
L_80522F94:
    // 0x80522F94: beql        $t0, $zero, L_80522FEC
    if (ctx->r8 == 0) {
        // 0x80522F98: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80522FEC;
    }
    goto skip_3;
    // 0x80522F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_3:
    // 0x80522F9C: lw          $t1, 0x20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X20);
    // 0x80522FA0: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80522FA4: beql        $t1, $zero, L_80522FC4
    if (ctx->r9 == 0) {
        // 0x80522FA8: lw          $t3, 0x174($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X174);
            goto L_80522FC4;
    }
    goto skip_4;
    // 0x80522FA8: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    skip_4:
    // 0x80522FAC: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80522FB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80522FB4: nop

    // 0x80522FB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80522FBC: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80522FC0: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
L_80522FC4:
    // 0x80522FC4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80522FC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80522FCC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80522FD0: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    // 0x80522FD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80522FD8: jal         0x8005FCA8
    // 0x80522FDC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x80522FDC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80522FE0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80522FE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80522FE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80522FEC:
    // 0x80522FEC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80522FF0: jal         0x80522AD4
    // 0x80522FF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80522AD4(rdram, ctx);
        goto after_1;
    // 0x80522FF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80522FF8: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x80522FFC: lw          $t5, -0x72D8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X72D8);
    // 0x80523000: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80523004: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80523008: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x8052300C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80523010:
    // 0x80523010: bne         $a2, $v0, L_80523030
    if (ctx->r6 != ctx->r2) {
        // 0x80523014: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80523030;
    }
    // 0x80523014: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80523018: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8052301C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x80523020: sw          $a2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r6;
    // 0x80523024: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
    // 0x80523028: jal         0x80523830
    // 0x8052302C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80523830(rdram, ctx);
        goto after_2;
    // 0x8052302C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
L_80523030:
    // 0x80523030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80523034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80523038: jr          $ra
    // 0x8052303C: nop

    return;
    // 0x8052303C: nop

;}
RECOMP_FUNC void func_80036FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036FA4: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x80036FA8: bne         $v0, $zero, L_80036FB8
    if (ctx->r2 != 0) {
        // 0x80036FAC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80036FB8;
    }
    // 0x80036FAC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80036FB0: jr          $ra
    // 0x80036FB4: sb          $zero, 0x113($a0)
    MEM_B(0X113, ctx->r4) = 0;
    return;
    // 0x80036FB4: sb          $zero, 0x113($a0)
    MEM_B(0X113, ctx->r4) = 0;
L_80036FB8:
    // 0x80036FB8: sw          $t6, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->r14;
    // 0x80036FBC: jr          $ra
    // 0x80036FC0: nop

    return;
    // 0x80036FC0: nop

;}
RECOMP_FUNC void func_806EFD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFD78: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806EFD7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EFD80: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EFD84: bne         $t6, $zero, L_806EFDD4
    if (ctx->r14 != 0) {
        // 0x806EFD88: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_806EFDD4;
    }
    // 0x806EFD88: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x806EFD8C: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x806EFD90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EFD94: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D98) << 16);
    // 0x806EFD98: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EFD9C: nop

    // 0x806EFDA0: bc1fl       L_806EFDC4
    if (!c1cs) {
        // 0x806EFDA4: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EFDC4;
    }
    goto skip_0;
    // 0x806EFDA4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x806EFDA8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D94) << 16);
    // 0x806EFDAC: lwc1        $f8, 0xCE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D94));
    // 0x806EFDB0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EFDB4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EFDB8: b           L_806EFE14
    // 0x806EFDBC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_806EFE14;
    // 0x806EFDBC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806EFDC0: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
L_806EFDC4:
    // 0x806EFDC4: lwc1        $f18, 0xCE8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D98));
    // 0x806EFDC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806EFDCC: b           L_806EFE14
    // 0x806EFDD0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_806EFE14;
    // 0x806EFDD0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_806EFDD4:
    // 0x806EFDD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806EFDD8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4DA0) << 16);
    // 0x806EFDDC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806EFDE0: nop

    // 0x806EFDE4: bc1fl       L_806EFE08
    if (!c1cs) {
        // 0x806EFDE8: lwc1        $f18, 0x4($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EFE08;
    }
    goto skip_1;
    // 0x806EFDE8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x806EFDEC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D9C) << 16);
    // 0x806EFDF0: lwc1        $f10, 0xCEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D9C));
    // 0x806EFDF4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EFDF8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806EFDFC: b           L_806EFE14
    // 0x806EFE00: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
        goto L_806EFE14;
    // 0x806EFE00: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806EFE04: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
L_806EFE08:
    // 0x806EFE08: lwc1        $f4, 0xCF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4DA0));
    // 0x806EFE0C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806EFE10: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_806EFE14:
    // 0x806EFE14: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806EFE18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EFE1C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EFE20: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x806EFE24: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806EFE28: nop

    // 0x806EFE2C: bc1fl       L_806EFE44
    if (!c1cs) {
        // 0x806EFE30: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EFE44;
    }
    goto skip_2;
    // 0x806EFE30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_2:
    // 0x806EFE34: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806EFE38: b           L_806EFE60
    // 0x806EFE3C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
        goto L_806EFE60;
    // 0x806EFE3C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EFE40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EFE44:
    // 0x806EFE44: nop

    // 0x806EFE48: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806EFE4C: nop

    // 0x806EFE50: bc1fl       L_806EFE64
    if (!c1cs) {
        // 0x806EFE54: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_806EFE64;
    }
    goto skip_3;
    // 0x806EFE54: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    skip_3:
    // 0x806EFE58: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806EFE5C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
L_806EFE60:
    // 0x806EFE60: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_806EFE64:
    // 0x806EFE64: jr          $ra
    // 0x806EFE68: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x806EFE68: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_804627D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804627D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804627D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804627D8: lw          $a2, 0x180($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X180);
    // 0x804627DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804627E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x804627E4: jal         0x80045A34
    // 0x804627E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804627E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x804627EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804627F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804627F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804627F8: bne         $v0, $zero, L_80462808
    if (ctx->r2 != 0) {
        // 0x804627FC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80462808;
    }
    // 0x804627FC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80462800: b           L_80462840
    // 0x80462804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80462840;
    // 0x80462804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80462808:
    // 0x80462808: bnel        $a2, $zero, L_8046281C
    if (ctx->r6 != 0) {
        // 0x8046280C: lw          $v1, 0x1F4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X1F4);
            goto L_8046281C;
    }
    goto skip_0;
    // 0x8046280C: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    skip_0:
    // 0x80462810: b           L_80462840
    // 0x80462814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80462840;
    // 0x80462814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80462818: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
L_8046281C:
    // 0x8046281C: bnel        $v1, $zero, L_80462830
    if (ctx->r3 != 0) {
        // 0x80462820: lwc1        $f4, 0x0($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
            goto L_80462830;
    }
    goto skip_1;
    // 0x80462820: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80462824: b           L_80462840
    // 0x80462828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80462840;
    // 0x80462828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8046282C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
L_80462830:
    // 0x80462830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80462834: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80462838: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8046283C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
L_80462840:
    // 0x80462840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80462848: jr          $ra
    // 0x8046284C: nop

    return;
    // 0x8046284C: nop

;}
RECOMP_FUNC void func_805648B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805648B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805648BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805648C0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x805648C4: lw          $v1, 0x2EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2EC);
    // 0x805648C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x805648CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805648D0: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x805648D4: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x805648D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805648DC: addu        $a3, $v0, $t8
    ctx->r7 = ADD32(ctx->r2, ctx->r24);
    // 0x805648E0: sllv        $a1, $t6, $v1
    ctx->r5 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x805648E4: sllv        $a2, $t7, $v1
    ctx->r6 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x805648E8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805648EC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x805648F0: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x805648F4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x805648F8: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x805648FC: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_80564900:
    // 0x80564900: lwc1        $f4, 0x3E8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X3E8);
    // 0x80564904: lwc1        $f6, 0x2F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X2F0);
    // 0x80564908: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8056490C: slti        $at, $t1, 0x3E
    ctx->r1 = SIGNED(ctx->r9) < 0X3E ? 1 : 0;
    // 0x80564910: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80564914: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80564918: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8056491C: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // 0x80564920: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80564924: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80564928: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8056492C: nop

    // 0x80564930: sh          $t5, -0x4($t2)
    MEM_H(-0X4, ctx->r10) = ctx->r13;
    // 0x80564934: lwc1        $f4, 0x2EC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X2EC);
    // 0x80564938: lwc1        $f18, 0x3E4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X3E4);
    // 0x8056493C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80564940: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80564944: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80564948: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8056494C: bne         $at, $zero, L_80564900
    if (ctx->r1 != 0) {
        // 0x80564950: sh          $t7, -0x2($t2)
        MEM_H(-0X2, ctx->r10) = ctx->r15;
            goto L_80564900;
    }
    // 0x80564950: sh          $t7, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r15;
    // 0x80564954: addiu       $v1, $v0, 0x4E0
    ctx->r3 = ADD32(ctx->r2, 0X4E0);
    // 0x80564958: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x8056495C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80564960: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80564964:
    // 0x80564964: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x80564968: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8056496C: slti        $at, $t1, 0x1F
    ctx->r1 = SIGNED(ctx->r9) < 0X1F ? 1 : 0;
    // 0x80564970: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80564974: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80564978: bne         $at, $zero, L_80564964
    if (ctx->r1 != 0) {
        // 0x8056497C: sb          $t9, -0x1($t2)
        MEM_B(-0X1, ctx->r10) = ctx->r25;
            goto L_80564964;
    }
    // 0x8056497C: sb          $t9, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r25;
    // 0x80564980: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80564984: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80564988: sltiu       $v0, $a2, 0x1
    ctx->r2 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x8056498C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80564990: addiu       $t3, $zero, 0x1D
    ctx->r11 = ADD32(0, 0X1D);
L_80564994:
    // 0x80564994: lbu         $t5, 0x0($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X0);
    // 0x80564998: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8056499C: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x805649A0: beql        $t6, $zero, L_80564A18
    if (ctx->r14 == 0) {
        // 0x805649A4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_0;
    // 0x805649A4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_0:
    // 0x805649A8: lbu         $a2, 0x1($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X1);
    // 0x805649AC: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x805649B0: beql        $t7, $zero, L_80564A18
    if (ctx->r15 == 0) {
        // 0x805649B4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_1;
    // 0x805649B4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_1:
    // 0x805649B8: lbu         $t8, 0x2($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2);
    // 0x805649BC: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x805649C0: addu        $v1, $a3, $t5
    ctx->r3 = ADD32(ctx->r7, ctx->r13);
    // 0x805649C4: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x805649C8: beql        $t9, $zero, L_80564A18
    if (ctx->r25 == 0) {
        // 0x805649CC: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_2;
    // 0x805649CC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_2:
    // 0x805649D0: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x805649D4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x805649D8: bnel        $t6, $a1, L_80564A18
    if (ctx->r14 != ctx->r5) {
        // 0x805649DC: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_3;
    // 0x805649DC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_3:
    // 0x805649E0: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x805649E4: bnel        $a1, $t7, L_80564A18
    if (ctx->r5 != ctx->r15) {
        // 0x805649E8: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_4;
    // 0x805649E8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_4:
    // 0x805649EC: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
    // 0x805649F0: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x805649F4: bnel        $t8, $a1, L_80564A18
    if (ctx->r24 != ctx->r5) {
        // 0x805649F8: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_5;
    // 0x805649F8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_5:
    // 0x805649FC: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x80564A00: xori        $t5, $a0, 0xFF
    ctx->r13 = ctx->r4 ^ 0XFF;
    // 0x80564A04: and         $t6, $a2, $t5
    ctx->r14 = ctx->r6 & ctx->r13;
    // 0x80564A08: bnel        $a1, $t9, L_80564A18
    if (ctx->r5 != ctx->r25) {
        // 0x80564A0C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80564A18;
    }
    goto skip_6;
    // 0x80564A0C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_6:
    // 0x80564A10: sb          $t6, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r14;
    // 0x80564A14: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80564A18:
    // 0x80564A18: bne         $t1, $t3, L_80564994
    if (ctx->r9 != ctx->r11) {
        // 0x80564A1C: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_80564994;
    }
    // 0x80564A1C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80564A20: jr          $ra
    // 0x80564A24: nop

    return;
    // 0x80564A24: nop

;}
RECOMP_FUNC void func_804B8AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B8AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B8AC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804B8ACC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B8AD0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x804B8AD4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804B8AD8: addiu       $t7, $v0, 0xF8
    ctx->r15 = ADD32(ctx->r2, 0XF8);
    // 0x804B8ADC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x804B8AE0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804B8AE4: jal         0x804B8844
    // 0x804B8AE8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_804B8844(rdram, ctx);
        goto after_0;
    // 0x804B8AE8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804B8AEC: jal         0x804B8864
    // 0x804B8AF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804B8864(rdram, ctx);
        goto after_1;
    // 0x804B8AF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x804B8AF4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804B8AF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804B8AFC: sw          $t8, 0x1F0($v0)
    MEM_W(0X1F0, ctx->r2) = ctx->r24;
    // 0x804B8B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B8B04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B8B08: jr          $ra
    // 0x804B8B0C: nop

    return;
    // 0x804B8B0C: nop

;}
RECOMP_FUNC void func_80456C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456C60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80456C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80456C68: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80456C6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80456C70: jal         0x804449C0
    // 0x80456C74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x80456C74: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80456C78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80456C7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80456C80: jal         0x80450490
    // 0x80456C84: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_1;
    // 0x80456C84: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_1:
    // 0x80456C88: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80456C8C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456C90: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x80456C94: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80456C98: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80456C9C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D88) << 16);
    // 0x80456CA0: lw          $t9, -0x7E98($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D88));
    // 0x80456CA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80456CA8: jalr        $t9
    // 0x80456CAC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80456CAC: nop

    after_2:
    // 0x80456CB0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80456CB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80456CB8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456CBC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80456CC0: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x80456CC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80456CC8: jal         0x80455D88
    // 0x80456CCC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80455D88(rdram, ctx);
        goto after_3;
    // 0x80456CCC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80456CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80456CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80456CD8: jr          $ra
    // 0x80456CDC: nop

    return;
    // 0x80456CDC: nop

;}
RECOMP_FUNC void func_807B8FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8FC0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807B8FC4: lw          $v1, -0x71A8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X71A8);
    // 0x807B8FC8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8FCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x807B8FD0: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x807B8FD4: beq         $v1, $zero, L_807B8FF8
    if (ctx->r3 == 0) {
        // 0x807B8FD8: nop
    
            goto L_807B8FF8;
    }
    // 0x807B8FD8: nop

    // 0x807B8FDC: beq         $v1, $a0, L_807B9000
    if (ctx->r3 == ctx->r4) {
        // 0x807B8FE0: nop
    
            goto L_807B9000;
    }
    // 0x807B8FE0: nop

    // 0x807B8FE4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x807B8FE8: beql        $v1, $a0, L_807B900C
    if (ctx->r3 == ctx->r4) {
        // 0x807B8FEC: sw          $a0, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r4;
            goto L_807B900C;
    }
    goto skip_0;
    // 0x807B8FEC: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    skip_0:
    // 0x807B8FF0: jr          $ra
    // 0x807B8FF4: nop

    return;
    // 0x807B8FF4: nop

L_807B8FF8:
    // 0x807B8FF8: jr          $ra
    // 0x807B8FFC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    return;
    // 0x807B8FFC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_807B9000:
    // 0x807B9000: jr          $ra
    // 0x807B9004: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    return;
    // 0x807B9004: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x807B9008: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_807B900C:
    // 0x807B900C: jr          $ra
    // 0x807B9010: nop

    return;
    // 0x807B9010: nop

;}
RECOMP_FUNC void func_807911B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807911B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807911B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807911BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807911C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807911C4: jal         0x80790CB4
    // 0x807911C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x807911C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x807911CC: jal         0x80790714
    // 0x807911D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x807911D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x807911D4: beq         $v0, $zero, L_80791214
    if (ctx->r2 == 0) {
        // 0x807911D8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80791214;
    }
    // 0x807911D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807911DC: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
    // 0x807911E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807911E4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x807911E8: bne         $t7, $zero, L_8079120C
    if (ctx->r15 != 0) {
        // 0x807911EC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8079120C;
    }
    // 0x807911EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x807911F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x807911F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807911F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x807911FC: jal         0x8079393C
    // 0x80791200: lbu         $a2, 0x10($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X10);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80791200: lbu         $a2, 0x10($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X10);
    after_2:
    // 0x80791204: b           L_80791218
    // 0x80791208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80791218;
    // 0x80791208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079120C:
    // 0x8079120C: jal         0x8079393C
    // 0x80791210: lbu         $a2, 0x10($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X10);
    func_8079393C(rdram, ctx);
        goto after_3;
    // 0x80791210: lbu         $a2, 0x10($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X10);
    after_3:
L_80791214:
    // 0x80791214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80791218:
    // 0x80791218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079121C: jr          $ra
    // 0x80791220: nop

    return;
    // 0x80791220: nop

;}
RECOMP_FUNC void func_8040D164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D164: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8040D168: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8040D16C: lw          $v0, 0xF70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XF70);
    // 0x8040D170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040D174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040D178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040D17C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8040D180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040D184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D188: bne         $a2, $v1, L_8040D1A0
    if (ctx->r6 != ctx->r3) {
        // 0x8040D18C: lw          $a1, 0x1F4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X1F4);
            goto L_8040D1A0;
    }
    // 0x8040D18C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D190: jal         0x800447C8
    // 0x8040D194: sw          $a2, 0xE84($a3)
    MEM_W(0XE84, ctx->r7) = ctx->r6;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8040D194: sw          $a2, 0xE84($a3)
    MEM_W(0XE84, ctx->r7) = ctx->r6;
    after_0:
    // 0x8040D198: b           L_8040D220
    // 0x8040D19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040D220;
    // 0x8040D19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040D1A0:
    // 0x8040D1A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040D1A4: bnel        $v1, $at, L_8040D220
    if (ctx->r3 != ctx->r1) {
        // 0x8040D1A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040D220;
    }
    goto skip_0;
    // 0x8040D1A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8040D1AC: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
    // 0x8040D1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D1B4: bnel        $a2, $t6, L_8040D1D0
    if (ctx->r6 != ctx->r14) {
        // 0x8040D1B8: lw          $t7, 0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X4);
            goto L_8040D1D0;
    }
    goto skip_1;
    // 0x8040D1B8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8040D1BC: jal         0x8005FDC4
    // 0x8040D1C0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x8040D1C0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    after_1:
    // 0x8040D1C4: b           L_8040D220
    // 0x8040D1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040D220;
    // 0x8040D1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040D1CC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
L_8040D1D0:
    // 0x8040D1D0: beq         $t7, $zero, L_8040D1FC
    if (ctx->r15 == 0) {
        // 0x8040D1D4: nop
    
            goto L_8040D1FC;
    }
    // 0x8040D1D4: nop

    // 0x8040D1D8: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
    // 0x8040D1DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D1E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D1E4: bne         $t8, $zero, L_8040D21C
    if (ctx->r24 != 0) {
        // 0x8040D1E8: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8040D21C;
    }
    // 0x8040D1E8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8040D1EC: jal         0x8040E254
    // 0x8040D1F0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040D1F0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8040D1F4: b           L_8040D220
    // 0x8040D1F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040D220;
    // 0x8040D1F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040D1FC:
    // 0x8040D1FC: jal         0x8040C6D8
    // 0x8040D200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040C6D8(rdram, ctx);
        goto after_3;
    // 0x8040D200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8040D204: jal         0x80060FE0
    // 0x8040D208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_4;
    // 0x8040D208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8040D20C: jal         0x8005FE48
    // 0x8040D210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_5;
    // 0x8040D210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8040D214: jal         0x800447C8
    // 0x8040D218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x8040D218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8040D21C:
    // 0x8040D21C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040D220:
    // 0x8040D220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040D224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040D228: jr          $ra
    // 0x8040D22C: nop

    return;
    // 0x8040D22C: nop

;}
RECOMP_FUNC void func_8006502C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006502C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065034: jal         0x80064FEC
    // 0x80065038: nop

    func_80064FEC(rdram, ctx);
        goto after_0;
    // 0x80065038: nop

    after_0:
    // 0x8006503C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80065040: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80065044: lw          $t7, -0x6C10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C10);
    // 0x80065048: lw          $t6, -0x6C0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C0C);
    // 0x8006504C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065054: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80065058: jr          $ra
    // 0x8006505C: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
    return;
    // 0x8006505C: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
;}
RECOMP_FUNC void func_8043E870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E878: jal         0x8043D154
    // 0x8043E87C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043D154(rdram, ctx);
        goto after_0;
    // 0x8043E87C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043E880: jal         0x80045BD8
    // 0x8043E884: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8043E884: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043E888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E88C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E890: jr          $ra
    // 0x8043E894: nop

    return;
    // 0x8043E894: nop

;}
RECOMP_FUNC void func_80682E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682E64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682E68: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682E6C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682E70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682E74: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682E78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682E7C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682E80: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682E84: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682E88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682E8C: jr          $ra
    // 0x80682E90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682E90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8002FD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FD38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FD3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FD40: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FD44: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FD48: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002FD4C: jal         0x8002F678
    // 0x8002FD50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FD50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FD54: beq         $v0, $zero, L_8002FD68
    if (ctx->r2 == 0) {
        // 0x8002FD58: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FD68;
    }
    // 0x8002FD58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FD5C: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FD60: addiu       $t6, $t6, -0x2AC4
    ctx->r14 = ADD32(ctx->r14, -0X2AC4);
    // 0x8002FD64: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FD68:
    // 0x8002FD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FD6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FD70: jr          $ra
    // 0x8002FD74: nop

    return;
    // 0x8002FD74: nop

;}
RECOMP_FUNC void func_805D7EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7EB4: jr          $ra
    // 0x805D7EB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805D7EB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8045359C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045359C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804535A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804535A4: jal         0x8045341C
    // 0x804535A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8045341C(rdram, ctx);
        goto after_0;
    // 0x804535A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x804535AC: jal         0x80445CBC
    // 0x804535B0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80445CBC(rdram, ctx);
        goto after_1;
    // 0x804535B0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x804535B4: jal         0x80445D08
    // 0x804535B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445D08(rdram, ctx);
        goto after_2;
    // 0x804535B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x804535BC: jal         0x804444FC
    // 0x804535C0: nop

    static_98_804444FC(rdram, ctx);
        goto after_3;
    // 0x804535C0: nop

    after_3:
    // 0x804535C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804535C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804535CC: jr          $ra
    // 0x804535D0: nop

    return;
    // 0x804535D0: nop

;}
RECOMP_FUNC void func_8004EDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EDB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004EDB8: beq         $a0, $zero, L_8004EDC8
    if (ctx->r4 == 0) {
        // 0x8004EDBC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8004EDC8;
    }
    // 0x8004EDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EDC0: jal         0x80064E84
    // 0x8004EDC4: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8004EDC4: nop

    after_0:
L_8004EDC8:
    // 0x8004EDC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EDCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004EDD0: jr          $ra
    // 0x8004EDD4: nop

    return;
    // 0x8004EDD4: nop

;}
RECOMP_FUNC void func_80001210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001210: jr          $ra
    // 0x80001214: nop

    return;
    // 0x80001214: nop

    // 0x80001218: jr          $ra
    // 0x8000121C: nop

    return;
    // 0x8000121C: nop

    // 0x80001220: jr          $ra
    // 0x80001224: nop

    return;
    // 0x80001224: nop

;}
RECOMP_FUNC void func_806CFC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFC5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CFC60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CFC64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CFC68: jal         0x806CF9B8
    // 0x806CFC6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CF9B8(rdram, ctx);
        goto after_0;
    // 0x806CFC6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CFC70: jal         0x806CFA34
    // 0x806CFC74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFA34(rdram, ctx);
        goto after_1;
    // 0x806CFC74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CFC78: jal         0x806CFAB8
    // 0x806CFC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFAB8(rdram, ctx);
        goto after_2;
    // 0x806CFC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CFC80: bne         $v0, $zero, L_806CFCB0
    if (ctx->r2 != 0) {
        // 0x806CFC84: lui         $at, 0x806D
        ctx->r1 = S32(RELOC_HI16(607, 0X1AE0) << 16);
            goto L_806CFCB0;
    }
    // 0x806CFC84: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AE0) << 16);
    // 0x806CFC88: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806CFC8C: lwc1        $f6, 0x1280($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AE0));
    // 0x806CFC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CFC94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFC98: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806CFC9C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806CFCA0: bc1fl       L_806CFCB4
    if (!c1cs) {
        // 0x806CFCA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CFCB4;
    }
    goto skip_0;
    // 0x806CFCA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CFCA8: jal         0x806D093C
    // 0x806CFCAC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806CFCAC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
L_806CFCB0:
    // 0x806CFCB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CFCB4:
    // 0x806CFCB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CFCB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CFCBC: jr          $ra
    // 0x806CFCC0: nop

    return;
    // 0x806CFCC0: nop

;}
RECOMP_FUNC void func_8078ABB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078ABB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078ABBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078ABC0: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8078ABC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078ABC8: jal         0x8078AB10
    // 0x8078ABCC: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    func_8078AB10(rdram, ctx);
        goto after_0;
    // 0x8078ABCC: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    after_0:
    // 0x8078ABD0: beq         $v0, $zero, L_8078ACE0
    if (ctx->r2 == 0) {
        // 0x8078ABD4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8078ACE0;
    }
    // 0x8078ABD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078ABD8: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x8078ABDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8078ABE0: slti        $at, $v0, 0x4395
    ctx->r1 = SIGNED(ctx->r2) < 0X4395 ? 1 : 0;
    // 0x8078ABE4: bne         $at, $zero, L_8078ABFC
    if (ctx->r1 != 0) {
        // 0x8078ABE8: slti        $at, $v0, 0x43AB
        ctx->r1 = SIGNED(ctx->r2) < 0X43AB ? 1 : 0;
            goto L_8078ABFC;
    }
    // 0x8078ABE8: slti        $at, $v0, 0x43AB
    ctx->r1 = SIGNED(ctx->r2) < 0X43AB ? 1 : 0;
    // 0x8078ABEC: beql        $at, $zero, L_8078AC00
    if (ctx->r1 == 0) {
        // 0x8078ABF0: sw          $t7, 0x134($a0)
        MEM_W(0X134, ctx->r4) = ctx->r15;
            goto L_8078AC00;
    }
    goto skip_0;
    // 0x8078ABF0: sw          $t7, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r15;
    skip_0:
    // 0x8078ABF4: b           L_8078AC00
    // 0x8078ABF8: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
        goto L_8078AC00;
    // 0x8078ABF8: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
L_8078ABFC:
    // 0x8078ABFC: sw          $t7, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r15;
L_8078AC00:
    // 0x8078AC00: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078AC04: lui         $t3, 0x8079
    ctx->r11 = S32(RELOC_HI16(793, 0XDB0) << 16);
    // 0x8078AC08: lw          $t5, 0x16C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X16C);
    // 0x8078AC0C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8078AC10: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(793, 0XC00) << 16);
    // 0x8078AC14: addiu       $t4, $t4, -0x51C0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(793, 0XC00));
    // 0x8078AC18: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(793, 0XDB8) << 16);
    // 0x8078AC1C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8078AC20: nop

    // 0x8078AC24: sra         $t0, $t9, 5
    ctx->r8 = S32(SIGNED(ctx->r25) >> 5);
    // 0x8078AC28: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x8078AC2C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8078AC30: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8078AC34: lh          $t3, -0x5010($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(793, 0XDB0));
    // 0x8078AC38: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x8078AC3C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8078AC40: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8078AC44: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8078AC48: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078AC4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078AC50: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8078AC54: lwc1        $f8, -0x5008($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(793, 0XDB8));
    // 0x8078AC58: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8078AC5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078AC60: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8078AC64: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8078AC68: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x8078AC6C: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8078AC70: jal         0x8078A748
    // 0x8078AC74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8078A748(rdram, ctx);
        goto after_1;
    // 0x8078AC74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8078AC78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078AC7C: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(793, 0XDC0) << 16);
    // 0x8078AC80: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8078AC84: lw          $t8, 0x134($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X134);
    // 0x8078AC88: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8078AC8C: lui         $t4, 0x8079
    ctx->r12 = S32(RELOC_HI16(793, 0X260) << 16);
    // 0x8078AC90: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8078AC94: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8078AC98: lh          $t0, -0x5000($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(793, 0XDC0));
    // 0x8078AC9C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8078ACA0: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(793, 0X260));
    // 0x8078ACA4: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(793, 0X758) << 16);
    // 0x8078ACA8: sh          $t0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r8;
    // 0x8078ACAC: lw          $t5, 0x16C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X16C);
    // 0x8078ACB0: sw          $t3, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r11;
    // 0x8078ACB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8078ACB8: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    // 0x8078ACBC: addiu       $t7, $t7, -0x5668
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(793, 0X758));
    // 0x8078ACC0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8078ACC4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8078ACC8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8078ACCC: jal         0x8078ABA0
    // 0x8078ACD0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    func_8078ABA0(rdram, ctx);
        goto after_2;
    // 0x8078ACD0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    after_2:
    // 0x8078ACD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8078ACD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8078ACDC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_8078ACE0:
    // 0x8078ACE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078ACE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078ACE8: jr          $ra
    // 0x8078ACEC: nop

    return;
    // 0x8078ACEC: nop

;}
RECOMP_FUNC void func_8044EAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044EAE0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8044EAE4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8044EAE8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8044EAEC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8044EAF0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8044EAF4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8044EAF8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8044EAFC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8044EB00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8044EB04: lw          $s5, 0x1F4($a2)
    ctx->r21 = MEM_W(ctx->r6, 0X1F4);
    // 0x8044EB08: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(98, 0X13C90) << 16);
    // 0x8044EB0C: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8044EB10: addiu       $t6, $t6, -0x7F90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13C90));
    // 0x8044EB14: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044EB18: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x8044EB1C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044EB20: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8044EB24: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044EB28: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8044EB2C: ori         $at, $at, 0x6990
    ctx->r1 = ctx->r1 | 0X6990;
    // 0x8044EB30: addu        $a1, $s5, $at
    ctx->r5 = ADD32(ctx->r21, ctx->r1);
    // 0x8044EB34: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8044EB38: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044EB3C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044EB40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044EB44: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8044EB48: ori         $at, $at, 0x6984
    ctx->r1 = ctx->r1 | 0X6984;
    // 0x8044EB4C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x8044EB50: addu        $a2, $s5, $at
    ctx->r6 = ADD32(ctx->r21, ctx->r1);
    // 0x8044EB54: jal         0x8044CCE4
    // 0x8044EB58: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    func_8044CCE4(rdram, ctx);
        goto after_0;
    // 0x8044EB58: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    after_0:
    // 0x8044EB5C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x8044EB60: jal         0x8044CB6C
    // 0x8044EB64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8044CB6C(rdram, ctx);
        goto after_1;
    // 0x8044EB64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8044EB68: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044EB6C: ori         $at, $at, 0x69A0
    ctx->r1 = ctx->r1 | 0X69A0;
    // 0x8044EB70: addu        $a1, $s5, $at
    ctx->r5 = ADD32(ctx->r21, ctx->r1);
    // 0x8044EB74: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8044EB78: jal         0x8044C260
    // 0x8044EB7C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_8044C260(rdram, ctx);
        goto after_2;
    // 0x8044EB7C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_2:
    // 0x8044EB80: addiu       $t9, $sp, 0x80
    ctx->r25 = ADD32(ctx->r29, 0X80);
    // 0x8044EB84: sw          $t9, 0xA64($s5)
    MEM_W(0XA64, ctx->r21) = ctx->r25;
    // 0x8044EB88: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8044EB8C: lui         $t1, 0x106
    ctx->r9 = S32(0X106 << 16);
    // 0x8044EB90: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8044EB94: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x8044EB98: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8044EB9C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8044EBA0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8044EBA4: lui         $s2, 0x8045
    ctx->r18 = S32(RELOC_HI16(98, 0X12E78) << 16);
    // 0x8044EBA8: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
    // 0x8044EBAC: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x8044EBB0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8044EBB4: addiu       $s2, $s2, 0x7258
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(98, 0X12E78));
    // 0x8044EBB8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8044EBBC: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x8044EBC0: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8044EBC4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8044EBC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044EBCC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044EBD0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8044EBD4: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8044EBD8: jal         0x8044D490
    // 0x8044EBDC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    func_8044D490(rdram, ctx);
        goto after_3;
    // 0x8044EBDC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    after_3:
    // 0x8044EBE0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8044EBE4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8044EBE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044EBEC: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x8044EBF0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8044EBF4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044EBF8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8044EBFC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8044EC00: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8044EC04: jal         0x8044D51C
    // 0x8044EC08: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    func_8044D51C(rdram, ctx);
        goto after_4;
    // 0x8044EC08: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    after_4:
    // 0x8044EC0C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8044EC10: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8044EC14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044EC18: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x8044EC1C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8044EC20: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044EC24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8044EC28: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8044EC2C: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8044EC30: jal         0x8044D394
    // 0x8044EC34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    func_8044D394(rdram, ctx);
        goto after_5;
    // 0x8044EC34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_5:
    // 0x8044EC38: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8044EC3C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8044EC40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044EC44: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8044EC48: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8044EC4C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044EC50: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8044EC54: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8044EC58: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8044EC5C: jal         0x8044D410
    // 0x8044EC60: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    func_8044D410(rdram, ctx);
        goto after_6;
    // 0x8044EC60: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    after_6:
    // 0x8044EC64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044EC68: ori         $at, $at, 0x6A28
    ctx->r1 = ctx->r1 | 0X6A28;
    // 0x8044EC6C: addu        $s0, $s5, $at
    ctx->r16 = ADD32(ctx->r21, ctx->r1);
    // 0x8044EC70: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044EC74: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8044EC78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044EC7C: bne         $a3, $at, L_8044ED04
    if (ctx->r7 != ctx->r1) {
        // 0x8044EC80: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_8044ED04;
    }
    // 0x8044EC80: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044EC84: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044EC88: ori         $at, $at, 0x6A24
    ctx->r1 = ctx->r1 | 0X6A24;
    // 0x8044EC8C: addu        $s0, $s5, $at
    ctx->r16 = ADD32(ctx->r21, ctx->r1);
    // 0x8044EC90: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044EC94: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8044EC98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044EC9C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044ECA0: jal         0x8044DC48
    // 0x8044ECA4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8044DC48(rdram, ctx);
        goto after_7;
    // 0x8044ECA4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_7:
    // 0x8044ECA8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044ECAC: ori         $at, $at, 0x6A20
    ctx->r1 = ctx->r1 | 0X6A20;
    // 0x8044ECB0: addu        $s2, $s5, $at
    ctx->r18 = ADD32(ctx->r21, ctx->r1);
    // 0x8044ECB4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8044ECB8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8044ECBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044ECC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044ECC4: jal         0x8044DC48
    // 0x8044ECC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8044DC48(rdram, ctx);
        goto after_8;
    // 0x8044ECC8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_8:
    // 0x8044ECCC: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044ECD0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8044ECD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044ECD8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044ECDC: jal         0x8044DD48
    // 0x8044ECE0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8044DD48(rdram, ctx);
        goto after_9;
    // 0x8044ECE0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x8044ECE4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8044ECE8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8044ECEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044ECF0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044ECF4: jal         0x8044DD48
    // 0x8044ECF8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8044DD48(rdram, ctx);
        goto after_10;
    // 0x8044ECF8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_10:
    // 0x8044ECFC: b           L_8044ED2C
    // 0x8044ED00: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
        goto L_8044ED2C;
    // 0x8044ED00: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8044ED04:
    // 0x8044ED04: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8044ED08: jal         0x8044DC48
    // 0x8044ED0C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_8044DC48(rdram, ctx);
        goto after_11;
    // 0x8044ED0C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_11:
    // 0x8044ED10: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8044ED14: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8044ED18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8044ED1C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8044ED20: jal         0x8044DD48
    // 0x8044ED24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8044DD48(rdram, ctx);
        goto after_12;
    // 0x8044ED24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_12:
    // 0x8044ED28: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8044ED2C:
    // 0x8044ED2C: lui         $t2, 0xBD00
    ctx->r10 = S32(0XBD00 << 16);
    // 0x8044ED30: addiu       $t1, $s0, 0x8
    ctx->r9 = ADD32(ctx->r16, 0X8);
    // 0x8044ED34: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8044ED38: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8044ED3C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8044ED40: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8044ED44: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8044ED48: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8044ED4C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8044ED50: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8044ED54: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8044ED58: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8044ED5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044ED60: jr          $ra
    // 0x8044ED64: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8044ED64: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_80067170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067170: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80067174: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80067178: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006717C: lwc1        $f4, 0xF14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF14);
    // 0x80067180: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80067184: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80067188: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8006718C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80067190: nop

    // 0x80067194: bc1fl       L_80067210
    if (!c1cs) {
        // 0x80067198: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80067210;
    }
    goto skip_0;
    // 0x80067198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8006719C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x800671A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800671A4: nop

    // 0x800671A8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800671AC: nop

    // 0x800671B0: bc1fl       L_800671EC
    if (!c1cs) {
        // 0x800671B4: sub.s       $f16, $f2, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_800671EC;
    }
    goto skip_1;
    // 0x800671B4: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
    skip_1:
    // 0x800671B8: add.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800671BC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800671C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800671C4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800671C8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800671CC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800671D0: nop

    // 0x800671D4: bc1f        L_8006727C
    if (!c1cs) {
        // 0x800671D8: nop
    
            goto L_8006727C;
    }
    // 0x800671D8: nop

    // 0x800671DC: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800671E0: jr          $ra
    // 0x800671E4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800671E4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800671E8: sub.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f14.fl;
L_800671EC:
    // 0x800671EC: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800671F0: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800671F4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800671F8: nop

    // 0x800671FC: bc1f        L_8006727C
    if (!c1cs) {
        // 0x80067200: nop
    
            goto L_8006727C;
    }
    // 0x80067200: nop

    // 0x80067204: jr          $ra
    // 0x80067208: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80067208: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8006720C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80067210:
    // 0x80067210: nop

    // 0x80067214: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80067218: nop

    // 0x8006721C: bc1fl       L_8006724C
    if (!c1cs) {
        // 0x80067220: sub.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_8006724C;
    }
    goto skip_2;
    // 0x80067220: sub.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
    skip_2:
    // 0x80067224: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80067228: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8006722C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80067230: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80067234: nop

    // 0x80067238: bc1f        L_8006727C
    if (!c1cs) {
        // 0x8006723C: nop
    
            goto L_8006727C;
    }
    // 0x8006723C: nop

    // 0x80067240: jr          $ra
    // 0x80067244: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80067244: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80067248: sub.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
L_8006724C:
    // 0x8006724C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80067250: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80067254: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80067258: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006725C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80067260: nop

    // 0x80067264: bc1f        L_8006727C
    if (!c1cs) {
        // 0x80067268: nop
    
            goto L_8006727C;
    }
    // 0x80067268: nop

    // 0x8006726C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067270: nop

    // 0x80067274: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80067278: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_8006727C:
    // 0x8006727C: jr          $ra
    // 0x80067280: nop

    return;
    // 0x80067280: nop

;}
RECOMP_FUNC void func_80437E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437E1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80437E20: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80437E24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437E28: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x80437E2C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80437E30: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x80437E34: bc1fl       L_80437E68
    if (!c1cs) {
        // 0x80437E38: lwc1        $f6, 0x0($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
            goto L_80437E68;
    }
    goto skip_0;
    // 0x80437E38: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80437E3C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80437E40: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80437E44: lbu         $t8, 0x44($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X44);
    // 0x80437E48: bne         $t8, $zero, L_80437E5C
    if (ctx->r24 != 0) {
        // 0x80437E4C: nop
    
            goto L_80437E5C;
    }
    // 0x80437E4C: nop

    // 0x80437E50: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80437E54: bgez        $t9, L_80437E9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80437E58: nop
    
            goto L_80437E9C;
    }
    // 0x80437E58: nop

L_80437E5C:
    // 0x80437E5C: jr          $ra
    // 0x80437E60: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80437E60: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x80437E64: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
L_80437E68:
    // 0x80437E68: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80437E6C: nop

    // 0x80437E70: bc1f        L_80437E9C
    if (!c1cs) {
        // 0x80437E74: nop
    
            goto L_80437E9C;
    }
    // 0x80437E74: nop

    // 0x80437E78: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80437E7C: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x80437E80: lbu         $t2, 0x5C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5C);
    // 0x80437E84: bnel        $t2, $zero, L_80437E9C
    if (ctx->r10 != 0) {
        // 0x80437E88: swc1        $f0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
            goto L_80437E9C;
    }
    goto skip_1;
    // 0x80437E88: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x80437E8C: lw          $t3, 0x54($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X54);
    // 0x80437E90: blez        $t3, L_80437E9C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80437E94: nop
    
            goto L_80437E9C;
    }
    // 0x80437E94: nop

    // 0x80437E98: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_80437E9C:
    // 0x80437E9C: jr          $ra
    // 0x80437EA0: nop

    return;
    // 0x80437EA0: nop

;}
RECOMP_FUNC void func_8076D7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D7B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076D7B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076D7BC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D7C0: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8076D7C4: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8076D7C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8076D7CC: jal         0x8076CD88
    // 0x8076D7D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_8076CD88(rdram, ctx);
        goto after_0;
    // 0x8076D7D0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8076D7D4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8076D7D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8076D7DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D7E0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8076D7E4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8076D7E8: bnel        $t9, $zero, L_8076D7FC
    if (ctx->r25 != 0) {
        // 0x8076D7EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076D7FC;
    }
    goto skip_0;
    // 0x8076D7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8076D7F0: jal         0x8076DD8C
    // 0x8076D7F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_1;
    // 0x8076D7F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8076D7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8076D7FC:
    // 0x8076D7FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076D800: jr          $ra
    // 0x8076D804: nop

    return;
    // 0x8076D804: nop

;}
RECOMP_FUNC void func_80036CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036CF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80036CF4: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80036CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036CFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80036D00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80036D04: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80036D08: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80036D0C: jal         0x800659EC
    // 0x80036D10: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x80036D10: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80036D14: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80036D18: lwc1        $f16, 0x54($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X54);
    // 0x80036D1C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80036D20: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80036D24: jal         0x800659EC
    // 0x80036D28: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x80036D28: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80036D2C: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80036D30: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80036D34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036D38: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80036D3C: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80036D40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80036D44: bc1fl       L_80036D54
    if (!c1cs) {
        // 0x80036D48: c.eq.s      $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
            goto L_80036D54;
    }
    goto skip_0;
    // 0x80036D48: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    skip_0:
    // 0x80036D4C: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80036D50: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
L_80036D54:
    // 0x80036D54: nop

    // 0x80036D58: bc1tl       L_80036DD8
    if (c1cs) {
        // 0x80036D5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036DD8;
    }
    goto skip_1;
    // 0x80036D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80036D60: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80036D64: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x80036D68: jal         0x80065954
    // 0x80036D6C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80036D6C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80036D70: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80036D74: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80036D78: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80036D7C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80036D80: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80036D84: bc1fl       L_80036D98
    if (!c1cs) {
        // 0x80036D88: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80036D98;
    }
    goto skip_2;
    // 0x80036D88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x80036D8C: b           L_80036DD0
    // 0x80036D90: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
        goto L_80036DD0;
    // 0x80036D90: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80036D94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80036D98:
    // 0x80036D98: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80036D9C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80036DA0: nop

    // 0x80036DA4: bc1t        L_80036DC4
    if (c1cs) {
        // 0x80036DA8: nop
    
            goto L_80036DC4;
    }
    // 0x80036DA8: nop

    // 0x80036DAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036DB0: nop

    // 0x80036DB4: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80036DB8: nop

    // 0x80036DBC: bc1fl       L_80036DD0
    if (!c1cs) {
        // 0x80036DC0: sub.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_80036DD0;
    }
    goto skip_3;
    // 0x80036DC0: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    skip_3:
L_80036DC4:
    // 0x80036DC4: b           L_80036DD0
    // 0x80036DC8: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
        goto L_80036DD0;
    // 0x80036DC8: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80036DCC: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
L_80036DD0:
    // 0x80036DD0: swc1        $f2, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f2.u32l;
    // 0x80036DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036DD8:
    // 0x80036DD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80036DDC: jr          $ra
    // 0x80036DE0: nop

    return;
    // 0x80036DE0: nop

;}
RECOMP_FUNC void func_8067FC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067FC5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8067FC60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067FC64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067FC68: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067FC6C: lw          $a3, 0x174($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X174);
    // 0x8067FC70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067FC74: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8067FC78: jal         0x8004700C
    // 0x8067FC7C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8067FC7C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8067FC80: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8067FC84: beq         $v0, $zero, L_8067FE50
    if (ctx->r2 == 0) {
        // 0x8067FC88: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_8067FE50;
    }
    // 0x8067FC88: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8067FC8C: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    // 0x8067FC90: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067FC94: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x8067FC98: beq         $v1, $zero, L_8067FCA8
    if (ctx->r3 == 0) {
        // 0x8067FC9C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8067FCA8;
    }
    // 0x8067FC9C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8067FCA0: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x8067FCA4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8067FCA8:
    // 0x8067FCA8: bne         $v1, $zero, L_8067FCE0
    if (ctx->r3 != 0) {
        // 0x8067FCAC: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8067FCE0;
    }
    // 0x8067FCAC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8067FCB0: jal         0x80044658
    // 0x8067FCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x8067FCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8067FCB8: jal         0x8067F738
    // 0x8067FCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067F738(rdram, ctx);
        goto after_2;
    // 0x8067FCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8067FCC0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8067FCC4: jal         0x80067BBC
    // 0x8067FCC8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8067FCC8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8067FCCC: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    // 0x8067FCD0: jal         0x80067818
    // 0x8067FCD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8067FCD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8067FCD8: b           L_8067FE54
    // 0x8067FCDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067FE54;
    // 0x8067FCDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067FCE0:
    // 0x8067FCE0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8067FCE4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8067FCE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067FCEC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8067FCF0: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8067FCF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8067FCF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8067FCFC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8067FD00: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8067FD04: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8067FD08: nop

    // 0x8067FD0C: bc1fl       L_8067FD1C
    if (!c1cs) {
        // 0x8067FD10: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_8067FD1C;
    }
    goto skip_0;
    // 0x8067FD10: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x8067FD14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8067FD18: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_8067FD1C:
    // 0x8067FD1C: nop

    // 0x8067FD20: bc1fl       L_8067FD30
    if (!c1cs) {
        // 0x8067FD24: swc1        $f0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
            goto L_8067FD30;
    }
    goto skip_1;
    // 0x8067FD24: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x8067FD28: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8067FD2C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_8067FD30:
    // 0x8067FD30: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x8067FD34: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8067FD38: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8067FD3C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8067FD40: nop

    // 0x8067FD44: bc1fl       L_8067FD54
    if (!c1cs) {
        // 0x8067FD48: lw          $t9, 0x0($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X0);
            goto L_8067FD54;
    }
    goto skip_2;
    // 0x8067FD48: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x8067FD4C: sh          $t8, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r24;
    // 0x8067FD50: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
L_8067FD54:
    // 0x8067FD54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067FD58: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x8067FD5C: lhu         $a0, 0x18($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X18);
    // 0x8067FD60: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8067FD64: jal         0x8004A97C
    // 0x8067FD68: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x8067FD68: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_5:
    // 0x8067FD6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8067FD70: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8067FD74: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8067FD78: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8067FD7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067FD80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8067FD84: bc1tl       L_8067FDD0
    if (c1cs) {
        // 0x8067FD88: lw          $t4, 0x0($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X0);
            goto L_8067FDD0;
    }
    goto skip_3;
    // 0x8067FD88: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    skip_3:
    // 0x8067FD8C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8067FD90: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8067FD94: lbu         $t3, 0x2C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2C);
    // 0x8067FD98: beq         $t3, $zero, L_8067FE34
    if (ctx->r11 == 0) {
        // 0x8067FD9C: nop
    
            goto L_8067FE34;
    }
    // 0x8067FD9C: nop

    // 0x8067FDA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8067FDA4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8067FDA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067FDAC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8067FDB0: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8067FDB4: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
    // 0x8067FDB8: bc1f        L_8067FE34
    if (!c1cs) {
        // 0x8067FDBC: nop
    
            goto L_8067FE34;
    }
    // 0x8067FDBC: nop

    // 0x8067FDC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067FDC4: b           L_8067FE34
    // 0x8067FDC8: swc1        $f16, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f16.u32l;
        goto L_8067FE34;
    // 0x8067FDC8: swc1        $f16, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f16.u32l;
    // 0x8067FDCC: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
L_8067FDD0:
    // 0x8067FDD0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8067FDD4: lw          $v0, 0x40($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X40);
    // 0x8067FDD8: lbu         $t5, 0x44($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X44);
    // 0x8067FDDC: beql        $t5, $zero, L_8067FE0C
    if (ctx->r13 == 0) {
        // 0x8067FDE0: lbu         $t7, 0x5C($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X5C);
            goto L_8067FE0C;
    }
    goto skip_4;
    // 0x8067FDE0: lbu         $t7, 0x5C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5C);
    skip_4:
    // 0x8067FDE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067FDE8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8067FDEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067FDF0: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8067FDF4: swc1        $f18, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f18.u32l;
    // 0x8067FDF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8067FDFC: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8067FE00: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8067FE04: lw          $v0, 0x40($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X40);
    // 0x8067FE08: lbu         $t7, 0x5C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5C);
L_8067FE0C:
    // 0x8067FE0C: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8067FE10: beq         $t7, $zero, L_8067FE34
    if (ctx->r15 == 0) {
        // 0x8067FE14: nop
    
            goto L_8067FE34;
    }
    // 0x8067FE14: nop

    // 0x8067FE18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067FE1C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8067FE20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067FE24: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8067FE28: swc1        $f10, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f10.u32l;
    // 0x8067FE2C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8067FE30: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
L_8067FE34:
    // 0x8067FE34: jal         0x80048F84
    // 0x8067FE38: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x8067FE38: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_6:
    // 0x8067FE3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8067FE40: jal         0x80048F84
    // 0x8067FE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x8067FE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8067FE48: jal         0x8067F5D8
    // 0x8067FE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067F5D8(rdram, ctx);
        goto after_8;
    // 0x8067FE4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8067FE50:
    // 0x8067FE50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067FE54:
    // 0x8067FE54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067FE58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8067FE5C: jr          $ra
    // 0x8067FE60: nop

    return;
    // 0x8067FE60: nop

;}
RECOMP_FUNC void func_8076DCAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DCAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8076DCB0: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(766, 0X3AC4) << 16);
    // 0x8076DCB4: lwc1        $f2, 0x2B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(766, 0X3AC4));
    // 0x8076DCB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076DCBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8076DCC0: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(766, 0X3AC8) << 16);
    // 0x8076DCC4: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8076DCC8: lwc1        $f4, 0x2B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(766, 0X3AC8));
    // 0x8076DCCC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076DCD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8076DCD4: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8076DCD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8076DCDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8076DCE0: nop

    // 0x8076DCE4: bc1fl       L_8076DCF4
    if (!c1cs) {
        // 0x8076DCE8: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_8076DCF4;
    }
    goto skip_0;
    // 0x8076DCE8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x8076DCEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8076DCF0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_8076DCF4:
    // 0x8076DCF4: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8076DCF8: jal         0x8076D188
    // 0x8076DCFC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_8076D188(rdram, ctx);
        goto after_0;
    // 0x8076DCFC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x8076DD00: beq         $v0, $zero, L_8076DD70
    if (ctx->r2 == 0) {
        // 0x8076DD04: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8076DD70;
    }
    // 0x8076DD04: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8076DD08: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8076DD0C: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(766, 0X3ACC) << 16);
    // 0x8076DD10: lwc1        $f10, 0x2BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(766, 0X3ACC));
    // 0x8076DD14: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8076DD18: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8076DD1C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8076DD20: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8076DD24: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8076DD28: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8076DD2C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8076DD30: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8076DD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8076DD38: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8076DD3C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8076DD40: jalr        $t9
    // 0x8076DD44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8076DD44: nop

    after_1:
    // 0x8076DD48: jal         0x800447C8
    // 0x8076DD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8076DD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8076DD50: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8076DD54: jal         0x80067BBC
    // 0x8076DD58: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8076DD58: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8076DD5C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    // 0x8076DD60: jal         0x80067818
    // 0x8076DD64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8076DD64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8076DD68: b           L_8076DD7C
    // 0x8076DD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076DD7C;
    // 0x8076DD6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076DD70:
    // 0x8076DD70: jal         0x8076CD88
    // 0x8076DD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8076CD88(rdram, ctx);
        goto after_5;
    // 0x8076DD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8076DD78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076DD7C:
    // 0x8076DD7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8076DD80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8076DD84: jr          $ra
    // 0x8076DD88: nop

    return;
    // 0x8076DD88: nop

;}
RECOMP_FUNC void func_80474F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474F10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474F14: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474F18: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474F1C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474F20: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474F24: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474F28: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474F2C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474F30: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474F34: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474F38: jr          $ra
    // 0x80474F3C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474F3C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80460E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460E1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460E24: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80460E28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80460E2C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80460E30: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X36F4) << 16);
    // 0x80460E34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80460E38: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80460E3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80460E40: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80460E44: lw          $t8, 0x3C84($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X36F4));
    // 0x80460E48: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80460E4C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80460E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80460E54: jal         0x80048490
    // 0x80460E58: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80460E58: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80460E5C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80460E60: jal         0x80048378
    // 0x80460E64: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80460E64: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80460E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460E70: jr          $ra
    // 0x80460E74: nop

    return;
    // 0x80460E74: nop

;}
RECOMP_FUNC void func_807BC24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC24C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807BC250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BC254: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807BC258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807BC25C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BC260: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807BC264: addiu       $a1, $s1, 0x6C
    ctx->r5 = ADD32(ctx->r17, 0X6C);
    // 0x807BC268: jal         0x807BBF84
    // 0x807BC26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BBF84(rdram, ctx);
        goto after_0;
    // 0x807BC26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x807BC270: jal         0x807BC128
    // 0x807BC274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BC128(rdram, ctx);
        goto after_1;
    // 0x807BC274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BC278: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x807BC27C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x807BC280: bnel        $at, $zero, L_807BC29C
    if (ctx->r1 != 0) {
        // 0x807BC284: lw          $v0, 0x4C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4C);
            goto L_807BC29C;
    }
    goto skip_0;
    // 0x807BC284: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    skip_0:
    // 0x807BC288: jal         0x807BC180
    // 0x807BC28C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807BC180(rdram, ctx);
        goto after_2;
    // 0x807BC28C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x807BC290: bnel        $v0, $zero, L_807BC410
    if (ctx->r2 != 0) {
        // 0x807BC294: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BC410;
    }
    goto skip_1;
    // 0x807BC294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807BC298: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
L_807BC29C:
    // 0x807BC29C: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x807BC2A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807BC2A4: beq         $v0, $zero, L_807BC2DC
    if (ctx->r2 == 0) {
        // 0x807BC2A8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_807BC2DC;
    }
    // 0x807BC2A8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x807BC2AC: bne         $t7, $zero, L_807BC40C
    if (ctx->r15 != 0) {
        // 0x807BC2B0: sw          $t7, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->r15;
            goto L_807BC40C;
    }
    // 0x807BC2B0: sw          $t7, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r15;
    // 0x807BC2B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807BC2B8: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x807BC2BC: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x807BC2C0: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x807BC2C4: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(898, 0X6E14) << 16);
    // 0x807BC2C8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x807BC2CC: lw          $t9, 0x2AD4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(898, 0X6E14));
    // 0x807BC2D0: sw          $t9, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r25;
    // 0x807BC2D4: b           L_807BC40C
    // 0x807BC2D8: sb          $zero, 0x58($s0)
    MEM_B(0X58, ctx->r16) = 0;
        goto L_807BC40C;
    // 0x807BC2D8: sb          $zero, 0x58($s0)
    MEM_B(0X58, ctx->r16) = 0;
L_807BC2DC:
    // 0x807BC2DC: jal         0x80048F84
    // 0x807BC2E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x807BC2E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x807BC2E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807BC2E8: jal         0x80048F84
    // 0x807BC2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x807BC2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x807BC2F0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6EB0) << 16);
    // 0x807BC2F4: lwc1        $f2, 0x2B70($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(898, 0X6EB0));
    // 0x807BC2F8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6EB4) << 16);
    // 0x807BC2FC: lwc1        $f6, 0x2B74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(898, 0X6EB4));
    // 0x807BC300: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x807BC304: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807BC308: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x807BC30C: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x807BC310: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807BC314: nop

    // 0x807BC318: bc1fl       L_807BC32C
    if (!c1cs) {
        // 0x807BC31C: lwc1        $f2, 0x6C($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
            goto L_807BC32C;
    }
    goto skip_2;
    // 0x807BC31C: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    skip_2:
    // 0x807BC320: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x807BC324: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x807BC328: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
L_807BC32C:
    // 0x807BC32C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807BC330: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807BC334: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x807BC338: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807BC33C: nop

    // 0x807BC340: bc1fl       L_807BC350
    if (!c1cs) {
        // 0x807BC344: lwc1        $f12, 0x50($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
            goto L_807BC350;
    }
    goto skip_3;
    // 0x807BC344: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    skip_3:
    // 0x807BC348: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x807BC34C: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
L_807BC350:
    // 0x807BC350: swc1        $f2, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f2.u32l;
    // 0x807BC354: swc1        $f2, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f2.u32l;
    // 0x807BC358: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x807BC35C: jal         0x80066DE4
    // 0x807BC360: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x807BC360: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x807BC364: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807BC368: jal         0x80066E88
    // 0x807BC36C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x807BC36C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x807BC370: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807BC374: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807BC378: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807BC37C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x807BC380: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807BC384: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x807BC388: lw          $v0, 0x1E0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1E0);
    // 0x807BC38C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807BC390: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x807BC394: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807BC398: nop

    // 0x807BC39C: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x807BC3A0: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    // 0x807BC3A4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807BC3A8: beq         $v0, $zero, L_807BC3B8
    if (ctx->r2 == 0) {
        // 0x807BC3AC: swc1        $f8, 0xC8($s1)
        MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
            goto L_807BC3B8;
    }
    // 0x807BC3AC: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
    // 0x807BC3B0: b           L_807BC3F0
    // 0x807BC3B4: sw          $t0, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r8;
        goto L_807BC3F0;
    // 0x807BC3B4: sw          $t0, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r8;
L_807BC3B8:
    // 0x807BC3B8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x807BC3BC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x807BC3C0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x807BC3C4: beq         $at, $zero, L_807BC3D4
    if (ctx->r1 == 0) {
        // 0x807BC3C8: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_807BC3D4;
    }
    // 0x807BC3C8: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x807BC3CC: b           L_807BC3D8
    // 0x807BC3D0: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
        goto L_807BC3D8;
    // 0x807BC3D0: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
L_807BC3D4:
    // 0x807BC3D4: sw          $t2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r10;
L_807BC3D8:
    // 0x807BC3D8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x807BC3DC: lui         $t4, 0x807C
    ctx->r12 = S32(RELOC_HI16(898, 0X6E14) << 16);
    // 0x807BC3E0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x807BC3E4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x807BC3E8: lw          $t4, 0x2AD4($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(898, 0X6E14));
    // 0x807BC3EC: sw          $t4, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r12;
L_807BC3F0:
    // 0x807BC3F0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x807BC3F4: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6E00) << 16);
    // 0x807BC3F8: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x807BC3FC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x807BC400: lwc1        $f10, 0x2AC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(898, 0X6E00));
    // 0x807BC404: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x807BC408: swc1        $f12, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f12.u32l;
L_807BC40C:
    // 0x807BC40C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BC410:
    // 0x807BC410: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807BC414: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807BC418: jr          $ra
    // 0x807BC41C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x807BC41C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80064F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80064F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064F40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80064F44: lw          $a2, -0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, -0X4);
    // 0x80064F48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80064F4C: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x80064F50: beq         $at, $zero, L_80064F5C
    if (ctx->r1 == 0) {
        // 0x80064F54: nop
    
            goto L_80064F5C;
    }
    // 0x80064F54: nop

    // 0x80064F58: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80064F5C:
    // 0x80064F5C: jal         0x80064D1C
    // 0x80064F60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80064F60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80064F64: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80064F68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80064F6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80064F70: jal         0x80065528
    // 0x80064F74: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80065528(rdram, ctx);
        goto after_1;
    // 0x80064F74: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80064F78: jal         0x80064E84
    // 0x80064F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x80064F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80064F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064F84: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80064F88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80064F8C: jr          $ra
    // 0x80064F90: nop

    return;
    // 0x80064F90: nop

;}
RECOMP_FUNC void func_8069C97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C97C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8069C980: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(568, 0X168) << 16);
    // 0x8069C984: addiu       $t6, $t6, -0x36F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(568, 0X168));
    // 0x8069C988: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8069C98C: jr          $ra
    // 0x8069C990: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8069C990: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8069D7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D7BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8069D7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D7C4: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069D7C8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8069D7CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8069D7D0: jal         0x80065728
    // 0x8069D7D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8069D7D4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D7D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8069D7DC: lui         $v1, 0x806A
    ctx->r3 = S32(RELOC_HI16(574, 0XC40) << 16);
    // 0x8069D7E0: addiu       $v1, $v1, -0x1E40
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(574, 0XC40));
    // 0x8069D7E4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8069D7E8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8069D7EC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8069D7F0: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8069D7F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8069D7F8: ori         $t9, $v0, 0x1
    ctx->r25 = ctx->r2 | 0X1;
    // 0x8069D7FC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8069D800: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8069D804: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x8069D808: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8069D80C: sw          $t2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r10;
    // 0x8069D810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8069D818: jr          $ra
    // 0x8069D81C: nop

    return;
    // 0x8069D81C: nop

;}
RECOMP_FUNC void func_804C17B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C17B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C17B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C17B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C17BC: jal         0x8004700C
    // 0x804C17C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804C17C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C17C4: beq         $v0, $zero, L_804C1824
    if (ctx->r2 == 0) {
        // 0x804C17C8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_804C1824;
    }
    // 0x804C17C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C17CC: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804C17D0: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x804C17D4: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x804C17D8: lwc1        $f10, 0x88($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X88);
    // 0x804C17DC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804C17E0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(203, 0X1140) << 16);
    // 0x804C17E4: lwc1        $f6, 0x28B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(203, 0X1140));
    // 0x804C17E8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804C17EC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804C17F0: nop

    // 0x804C17F4: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804C17F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804C17FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C1800: nop

    // 0x804C1804: bc1f        L_804C1824
    if (!c1cs) {
        // 0x804C1808: nop
    
            goto L_804C1824;
    }
    // 0x804C1808: nop

    // 0x804C180C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x804C1810: jal         0x80067BBC
    // 0x804C1814: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x804C1814: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x804C1818: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x804C181C: jal         0x80067818
    // 0x804C1820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804C1820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_804C1824:
    // 0x804C1824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C1828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C182C: jr          $ra
    // 0x804C1830: nop

    return;
    // 0x804C1830: nop

;}
RECOMP_FUNC void func_80475360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475360: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475364: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475368: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047536C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475370: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475374: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475378: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047537C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475380: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475384: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475388: jr          $ra
    // 0x8047538C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047538C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806EFCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFCC4: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x806EFCC8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806EFCCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EFCD0: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x806EFCD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EFCD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EFCDC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EFCE0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D8C) << 16);
    // 0x806EFCE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EFCE8: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x806EFCEC: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EFCF0: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x806EFCF4: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x806EFCF8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806EFCFC: swc1        $f18, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f18.u32l;
    // 0x806EFD00: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x806EFD04: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x806EFD08: nop

    // 0x806EFD0C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x806EFD10: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x806EFD14: lwc1        $f6, 0xCDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D8C));
    // 0x806EFD18: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D90) << 16);
    // 0x806EFD1C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x806EFD20: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806EFD24: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806EFD28: nop

    // 0x806EFD2C: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806EFD30: nop

    // 0x806EFD34: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806EFD38: swc1        $f16, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f16.u32l;
    // 0x806EFD3C: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x806EFD40: add.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x806EFD44: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x806EFD48: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x806EFD4C: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806EFD50: mul.s       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806EFD54: swc1        $f18, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f18.u32l;
    // 0x806EFD58: lwc1        $f6, 0xCE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D90));
    // 0x806EFD5C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806EFD60: nop

    // 0x806EFD64: bc1f        L_806EFD70
    if (!c1cs) {
        // 0x806EFD68: nop
    
            goto L_806EFD70;
    }
    // 0x806EFD68: nop

    // 0x806EFD6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EFD70:
    // 0x806EFD70: jr          $ra
    // 0x806EFD74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806EFD74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80430A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430A68: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80430A6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80430A70: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x80430A74: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80430A78: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80430A7C: addiu       $t7, $t7, 0x1230
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x80430A80: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80430A84: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80430A88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80430A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80430A90: jal         0x80430AB0
    // 0x80430A94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80430AB0(rdram, ctx);
        goto after_0;
    // 0x80430A94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80430A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430A9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80430AA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80430AA4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80430AA8: jr          $ra
    // 0x80430AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80430AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8067586C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067586C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80675870: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80675874: lw          $a2, 0x16C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X16C);
    // 0x80675878: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x8067587C: lui         $t4, 0x8067
    ctx->r12 = S32(RELOC_HI16(535, 0X2480) << 16);
    // 0x80675880: lbu         $t2, 0xD($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XD);
    // 0x80675884: lw          $t6, 0x2E8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2E8);
    // 0x80675888: lui         $t5, 0x8067
    ctx->r13 = S32(RELOC_HI16(535, 0X2470) << 16);
    // 0x8067588C: addiu       $t5, $t5, 0x7B30
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(535, 0X2470));
    // 0x80675890: addiu       $t4, $t4, 0x7B40
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(535, 0X2480));
    // 0x80675894: sb          $t2, 0xC($t4)
    MEM_B(0XC, ctx->r12) = ctx->r10;
    // 0x80675898: sb          $t2, 0xC($t5)
    MEM_B(0XC, ctx->r13) = ctx->r10;
    // 0x8067589C: lbu         $t2, 0xE($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XE);
    // 0x806758A0: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x806758A4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x806758A8: sb          $t2, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r10;
    // 0x806758AC: sb          $t2, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r10;
    // 0x806758B0: lbu         $t2, 0xF($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XF);
    // 0x806758B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806758B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806758BC: sb          $t2, 0xE($t4)
    MEM_B(0XE, ctx->r12) = ctx->r10;
    // 0x806758C0: sb          $t2, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r10;
    // 0x806758C4: lbu         $t2, 0x10($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X10);
    // 0x806758C8: addu        $t0, $v1, $t7
    ctx->r8 = ADD32(ctx->r3, ctx->r15);
    // 0x806758CC: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x806758D0: sb          $t2, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r10;
    // 0x806758D4: sb          $t2, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r10;
    // 0x806758D8: lw          $t3, -0x260C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X260C);
    // 0x806758DC: addiu       $t1, $t0, 0x174
    ctx->r9 = ADD32(ctx->r8, 0X174);
    // 0x806758E0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x806758E4: lw          $v0, 0xC($t3)
    ctx->r2 = MEM_W(ctx->r11, 0XC);
    // 0x806758E8: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x806758EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806758F0: addiu       $v0, $v0, -0x3E0
    ctx->r2 = ADD32(ctx->r2, -0X3E0);
    // 0x806758F4: sw          $v0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r2;
    // 0x806758F8: addiu       $t3, $v0, 0x10
    ctx->r11 = ADD32(ctx->r2, 0X10);
    // 0x806758FC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_80675900:
    // 0x80675900: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80675904: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80675908: sltiu       $at, $a1, 0x7C
    ctx->r1 = ctx->r5 < 0X7C ? 1 : 0;
    // 0x8067590C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80675910: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80675914: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80675918: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8067591C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80675920: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x80675924: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80675928: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x8067592C: sw          $t9, -0x18($t2)
    MEM_W(-0X18, ctx->r10) = ctx->r25;
    // 0x80675930: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x80675934: sw          $t8, -0x14($t2)
    MEM_W(-0X14, ctx->r10) = ctx->r24;
    // 0x80675938: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8067593C: sw          $t7, -0x20($t3)
    MEM_W(-0X20, ctx->r11) = ctx->r15;
    // 0x80675940: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80675944: sw          $t6, -0x1C($t3)
    MEM_W(-0X1C, ctx->r11) = ctx->r14;
    // 0x80675948: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x8067594C: sw          $t7, -0x18($t3)
    MEM_W(-0X18, ctx->r11) = ctx->r15;
    // 0x80675950: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80675954: sw          $t6, -0x14($t3)
    MEM_W(-0X14, ctx->r11) = ctx->r14;
    // 0x80675958: lh          $t8, -0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X4);
    // 0x8067595C: sh          $t8, -0x20($t2)
    MEM_H(-0X20, ctx->r10) = ctx->r24;
    // 0x80675960: lh          $t9, -0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, -0X4);
    // 0x80675964: sh          $t9, -0x1E($t2)
    MEM_H(-0X1E, ctx->r10) = ctx->r25;
    // 0x80675968: lh          $t6, -0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X2);
    // 0x8067596C: sh          $t6, -0x10($t2)
    MEM_H(-0X10, ctx->r10) = ctx->r14;
    // 0x80675970: lh          $t7, -0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, -0X2);
    // 0x80675974: bne         $at, $zero, L_80675900
    if (ctx->r1 != 0) {
        // 0x80675978: sh          $t7, -0xE($t2)
        MEM_H(-0XE, ctx->r10) = ctx->r15;
            goto L_80675900;
    }
    // 0x80675978: sh          $t7, -0xE($t2)
    MEM_H(-0XE, ctx->r10) = ctx->r15;
    // 0x8067597C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675980: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x80675984: ori         $t3, $t3, 0x103F
    ctx->r11 = ctx->r11 | 0X103F;
    // 0x80675988: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x8067598C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80675990: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x80675994: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80675998: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067599C: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x806759A0: addiu       $t5, $zero, 0x206
    ctx->r13 = ADD32(0, 0X206);
    // 0x806759A4: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806759A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806759AC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806759B0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806759B4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806759B8: addiu       $s0, $zero, 0x604
    ctx->r16 = ADD32(0, 0X604);
    // 0x806759BC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x806759C0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806759C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806759C8: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806759CC: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806759D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806759D4: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x806759D8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x806759DC: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806759E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806759E4: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x806759E8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806759EC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806759F0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x806759F4: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x806759F8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806759FC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80675A00: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80675A04: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675A08: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A0C: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80675A10: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80675A14: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80675A18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80675A1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80675A20: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80675A24: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_80675A28:
    // 0x80675A28: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A2C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80675A30: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80675A34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80675A38: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80675A3C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80675A40: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A44: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80675A48: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80675A4C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80675A50: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80675A54: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675A58: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A5C: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80675A60: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80675A64: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80675A68: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675A6C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A70: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x80675A74: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80675A78: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80675A7C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80675A80: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A84: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80675A88: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80675A8C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80675A90: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80675A94: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675A98: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675A9C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80675AA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80675AA4: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80675AA8: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675AAC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675AB0: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80675AB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80675AB8: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80675ABC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80675AC0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675AC4: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80675AC8: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x80675ACC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80675AD0: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80675AD4: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675AD8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675ADC: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x80675AE0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80675AE4: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80675AE8: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675AEC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675AF0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80675AF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80675AF8: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x80675AFC: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80675B00: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675B04: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x80675B08: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80675B0C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80675B10: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80675B14: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675B18: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80675B1C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x80675B20: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80675B24: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x80675B28: bne         $a1, $v1, L_80675A28
    if (ctx->r5 != ctx->r3) {
        // 0x80675B2C: sw          $t4, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r12;
            goto L_80675A28;
    }
    // 0x80675B2C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80675B30: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80675B34: jr          $ra
    // 0x80675B38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80675B38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8044CC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CC54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044CC58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8044CC5C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8044CC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044CC64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8044CC68: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8044CC6C: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044CC70: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8044CC74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044CC78: lw          $a3, 0xA60($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XA60);
    // 0x8044CC7C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8044CC80: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8044CC84: lw          $a1, 0xA64($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XA64);
    // 0x8044CC88: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8044CC8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8044CC90: jal         0x8044C360
    // 0x8044CC94: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8044C360(rdram, ctx);
        goto after_0;
    // 0x8044CC94: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8044CC98: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8044CC9C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8044CCA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8044CCA4: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8044CCA8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8044CCAC: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8044CCB0: sw          $a0, 0xA64($t0)
    MEM_W(0XA64, ctx->r8) = ctx->r4;
    // 0x8044CCB4: sw          $v0, 0xA60($v1)
    MEM_W(0XA60, ctx->r3) = ctx->r2;
    // 0x8044CCB8: jal         0x8044C260
    // 0x8044CCBC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8044C260(rdram, ctx);
        goto after_1;
    // 0x8044CCBC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8044CCC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044CCC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044CCC8: jr          $ra
    // 0x8044CCCC: nop

    return;
    // 0x8044CCCC: nop

;}
RECOMP_FUNC void func_806F3B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F3B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F3B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F3B34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F3B38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F3B3C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806F3B40: lw          $a0, 0x16C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C);
    // 0x806F3B44: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(682, 0X980) << 16);
    // 0x806F3B48: addiu       $t9, $t9, 0x3DD0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(682, 0X980));
    // 0x806F3B4C: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x806F3B50: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x806F3B54: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806F3B58: jal         0x800655F4
    // 0x806F3B5C: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x806F3B5C: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    after_0:
    // 0x806F3B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F3B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806F3B68: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806F3B6C: jal         0x806F3A1C
    // 0x806F3B70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_806F3A1C(rdram, ctx);
        goto after_1;
    // 0x806F3B70: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x806F3B74: bne         $v0, $zero, L_806F3B84
    if (ctx->r2 != 0) {
        // 0x806F3B78: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_806F3B84;
    }
    // 0x806F3B78: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806F3B7C: b           L_806F3BA8
    // 0x806F3B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F3BA8;
    // 0x806F3B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F3B84:
    // 0x806F3B84: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
    // 0x806F3B88: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x806F3B8C: lw          $t2, 0x174($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X174);
    // 0x806F3B90: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(682, 0X990) << 16);
    // 0x806F3B94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806F3B98: lbu         $t1, 0x3DE0($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(682, 0X990));
    // 0x806F3B9C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x806F3BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F3BA4: sb          $t1, 0x74($t3)
    MEM_B(0X74, ctx->r11) = ctx->r9;
L_806F3BA8:
    // 0x806F3BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F3BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F3BB0: jr          $ra
    // 0x806F3BB4: nop

    return;
    // 0x806F3BB4: nop

;}
RECOMP_FUNC void func_800485B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800485B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800485BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800485C0: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800485C4: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x800485C8: lw          $t6, 0x478($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X478);
    // 0x800485CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800485D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800485D4: lwc1        $f12, 0x38($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X38);
    // 0x800485D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800485DC: jal         0x80081C64
    // 0x800485E0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x800485E0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800485E4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800485E8: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x800485EC: lw          $v0, 0x3F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X3F4);
    // 0x800485F0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800485F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800485F8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800485FC: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80048600: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048604: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80048608: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004860C: lw          $t7, 0x478($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X478);
    // 0x80048610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80048614: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80048618: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004861C: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80048620: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80048624: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x80048628: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004862C: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80048630: div.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80048634: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80048638: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004863C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80048640: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80048644: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80048648: lw          $t8, 0x478($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X478);
    // 0x8004864C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80048650: lwc1        $f8, 0x34($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X34);
    // 0x80048654: sb          $t9, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r25;
    // 0x80048658: swc1        $f14, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f14.u32l;
    // 0x8004865C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80048660: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80048664: lbu         $t0, 0x24($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X24);
    // 0x80048668: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x8004866C: sb          $t1, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r9;
    // 0x80048670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80048678: jr          $ra
    // 0x8004867C: nop

    return;
    // 0x8004867C: nop

;}
RECOMP_FUNC void func_807B0DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0DB0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3930) << 16);
    // 0x807B0DB4: lwc1        $f6, 0x3480($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3930));
    // 0x807B0DB8: lwc1        $f4, 0x64($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807B0DBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B0DC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B0DC4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807B0DC8: swc1        $f8, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f8.u32l;
    // 0x807B0DCC: lwc1        $f10, 0x64($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807B0DD0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x807B0DD4: nop

    // 0x807B0DD8: bc1f        L_807B0DE8
    if (!c1cs) {
        // 0x807B0DDC: nop
    
            goto L_807B0DE8;
    }
    // 0x807B0DDC: nop

    // 0x807B0DE0: swc1        $f0, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f0.u32l;
    // 0x807B0DE4: sw          $t6, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r14;
L_807B0DE8:
    // 0x807B0DE8: jr          $ra
    // 0x807B0DEC: nop

    return;
    // 0x807B0DEC: nop

;}
RECOMP_FUNC void func_807887C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807887C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807887CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x807887D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x807887D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807887D8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x807887DC: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x807887E0: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x807887E4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x807887E8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F4C) << 16);
    // 0x807887EC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x807887F0: bc1t        L_807888B4
    if (c1cs) {
        // 0x807887F4: swc1        $f6, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
            goto L_807888B4;
    }
    // 0x807887F4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x807887F8: lwc1        $f12, -0x6674($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F4C));
    // 0x807887FC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80788800: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80788804: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80788808: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8078880C: nop

    // 0x80788810: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80788814: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80788818: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8078881C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80788820: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80788824: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80788828: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8078882C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80788830: nop

    // 0x80788834: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80788838: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8078883C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80788840: nop

    // 0x80788844: bc1f        L_807888B4
    if (!c1cs) {
        // 0x80788848: nop
    
            goto L_807888B4;
    }
    // 0x80788848: nop

    // 0x8078884C: beq         $v1, $at, L_80788868
    if (ctx->r3 == ctx->r1) {
        // 0x80788850: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80788868;
    }
    // 0x80788850: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80788854: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x80788858: beq         $v1, $at, L_8078888C
    if (ctx->r3 == ctx->r1) {
        // 0x8078885C: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_8078888C;
    }
    // 0x8078885C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80788860: b           L_807888B0
    // 0x80788864: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
        goto L_807888B0;
    // 0x80788864: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
L_80788868:
    // 0x80788868: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x8078886C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80788870: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80788874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80788878: jalr        $t9
    // 0x8078887C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8078887C: nop

    after_0:
    // 0x80788880: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80788884: b           L_807888AC
    // 0x80788888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_807888AC;
    // 0x80788888: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8078888C:
    // 0x8078888C: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x80788890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80788894: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80788898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078889C: jalr        $t9
    // 0x807888A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x807888A0: nop

    after_1:
    // 0x807888A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x807888A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_807888AC:
    // 0x807888AC: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
L_807888B0:
    // 0x807888B0: swc1        $f14, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f14.u32l;
L_807888B4:
    // 0x807888B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807888B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807888BC: jr          $ra
    // 0x807888C0: nop

    return;
    // 0x807888C0: nop

;}
RECOMP_FUNC void func_8066AD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066AD18: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8066AD1C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8066AD20: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8066AD24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8066AD28: nop

    // 0x8066AD2C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8066AD30: nop

    // 0x8066AD34: bc1fl       L_8066AD64
    if (!c1cs) {
        // 0x8066AD38: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8066AD64;
    }
    goto skip_0;
    // 0x8066AD38: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8066AD3C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8066AD40: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8066AD44: nop

    // 0x8066AD48: bc1f        L_8066AD80
    if (!c1cs) {
        // 0x8066AD4C: nop
    
            goto L_8066AD80;
    }
    // 0x8066AD4C: nop

    // 0x8066AD50: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8066AD54: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8066AD58: jr          $ra
    // 0x8066AD5C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8066AD5C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8066AD60: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_8066AD64:
    // 0x8066AD64: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8066AD68: nop

    // 0x8066AD6C: bc1f        L_8066AD80
    if (!c1cs) {
        // 0x8066AD70: nop
    
            goto L_8066AD80;
    }
    // 0x8066AD70: nop

    // 0x8066AD74: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8066AD78: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8066AD7C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8066AD80:
    // 0x8066AD80: jr          $ra
    // 0x8066AD84: nop

    return;
    // 0x8066AD84: nop

;}
RECOMP_FUNC void func_80005698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005698: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000569C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800056A0: lw          $t6, 0x6F84($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6F84);
    // 0x800056A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800056A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800056AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800056B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800056B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800056B8: addiu       $a0, $a0, 0x6F78
    ctx->r4 = ADD32(ctx->r4, 0X6F78);
    // 0x800056BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800056C0: jal         0x80003698
    // 0x800056C4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x800056C4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x800056C8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800056CC: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800056D0: addiu       $t9, $t9, 0x4D10
    ctx->r25 = ADD32(ctx->r25, 0X4D10);
    // 0x800056D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800056D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800056DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800056E0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800056E4: bne         $v0, $zero, L_800056F4
    if (ctx->r2 != 0) {
        // 0x800056E8: sw          $v0, 0x2278($v1)
        MEM_W(0X2278, ctx->r3) = ctx->r2;
            goto L_800056F4;
    }
    // 0x800056E8: sw          $v0, 0x2278($v1)
    MEM_W(0X2278, ctx->r3) = ctx->r2;
    // 0x800056EC: b           L_8000570C
    // 0x800056F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000570C;
    // 0x800056F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800056F4:
    // 0x800056F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800056F8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800056FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80005700: sh          $t0, 0x2280($v1)
    MEM_H(0X2280, ctx->r3) = ctx->r8;
    // 0x80005704: sh          $t1, 0x2282($v1)
    MEM_H(0X2282, ctx->r3) = ctx->r9;
    // 0x80005708: sw          $t2, 0x227C($v1)
    MEM_W(0X227C, ctx->r3) = ctx->r10;
L_8000570C:
    // 0x8000570C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005714: jr          $ra
    // 0x80005718: nop

    return;
    // 0x80005718: nop

;}
RECOMP_FUNC void func_807B5664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5664: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B5668: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B566C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B5670: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B5674: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B5678: lw          $s2, 0x10($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X10);
    // 0x807B567C: jal         0x807B4D10
    // 0x807B5680: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_807B4D10(rdram, ctx);
        goto after_0;
    // 0x807B5680: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x807B5684: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807B5688: lw          $t6, -0x7250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7250);
    // 0x807B568C: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x807B5690: bne         $at, $zero, L_807B56A8
    if (ctx->r1 != 0) {
        // 0x807B5694: nop
    
            goto L_807B56A8;
    }
    // 0x807B5694: nop

    // 0x807B5698: jal         0x807B4D88
    // 0x807B569C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_807B4D88(rdram, ctx);
        goto after_1;
    // 0x807B569C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x807B56A0: b           L_807B56B4
    // 0x807B56A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_807B56B4;
    // 0x807B56A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_807B56A8:
    // 0x807B56A8: jal         0x807B4D4C
    // 0x807B56AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_807B4D4C(rdram, ctx);
        goto after_2;
    // 0x807B56AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x807B56B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_807B56B4:
    // 0x807B56B4: addiu       $s1, $zero, 0x80
    ctx->r17 = ADD32(0, 0X80);
    // 0x807B56B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_807B56BC:
    // 0x807B56BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B56C0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B56C4: jal         0x8005C27C
    // 0x807B56C8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x807B56C8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_3:
    // 0x807B56CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B56D0: bnel        $s0, $s1, L_807B56BC
    if (ctx->r16 != ctx->r17) {
        // 0x807B56D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_807B56BC;
    }
    goto skip_0;
    // 0x807B56D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x807B56D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B56DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B56E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B56E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B56E8: jr          $ra
    // 0x807B56EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B56EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80461C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80461C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461C0C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80461C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80461C14: beq         $t6, $zero, L_80461C50
    if (ctx->r14 == 0) {
        // 0x80461C18: nop
    
            goto L_80461C50;
    }
    // 0x80461C18: nop

    // 0x80461C1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80461C20: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80461C24: jalr        $t9
    // 0x80461C28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80461C28: nop

    after_0:
    // 0x80461C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80461C30: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80461C34: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80461C38: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80461C3C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80461C40: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80461C44: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80461C48: b           L_80461C50
    // 0x80461C4C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80461C50;
    // 0x80461C4C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80461C50:
    // 0x80461C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80461C58: jr          $ra
    // 0x80461C5C: nop

    return;
    // 0x80461C5C: nop

;}
RECOMP_FUNC void guNormalize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C158: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008C15C: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8008C160: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8008C164: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8008C168: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008C16C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008C170: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8008C174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C178: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8008C17C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008C180: jal         0x80089DE0
    // 0x8008C184: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8008C184: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8008C188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008C18C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008C190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008C194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C198: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8008C19C: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008C1A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008C1A4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8008C1A8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8008C1AC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8008C1B0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8008C1B4: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8008C1B8: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8008C1BC: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8008C1C0: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8008C1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C1C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C1CC: jr          $ra
    // 0x8008C1D0: nop

    return;
    // 0x8008C1D0: nop

;}
RECOMP_FUNC void func_80029B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029B84: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029B88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80029B8C: addiu       $a1, $a2, 0x1D0
    ctx->r5 = ADD32(ctx->r6, 0X1D0);
    // 0x80029B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029B94: addiu       $a2, $a2, 0x1D8
    ctx->r6 = ADD32(ctx->r6, 0X1D8);
    // 0x80029B98: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80029B9C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029BA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029BA4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80029BA8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80029BAC: jal         0x80029574
    // 0x80029BB0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029574(rdram, ctx);
        goto after_0;
    // 0x80029BB0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80029BB4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80029BB8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80029BBC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80029BC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029BC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029BC8: jal         0x80029774
    // 0x80029BCC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029774(rdram, ctx);
        goto after_1;
    // 0x80029BCC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80029BD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029BD4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80029BD8: jal         0x80029220
    // 0x80029BDC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_80029220(rdram, ctx);
        goto after_2;
    // 0x80029BDC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80029BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029BE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029BE8: jr          $ra
    // 0x80029BEC: nop

    return;
    // 0x80029BEC: nop

;}
RECOMP_FUNC void func_800733D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800733D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800733DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800733E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800733E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800733E8: lbu         $a2, 0x14($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X14);
    // 0x800733EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800733F0: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
    // 0x800733F4: jal         0x80077270
    // 0x800733F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_80077270(rdram, ctx);
        goto after_0;
    // 0x800733F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_0:
    // 0x800733FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073404: jr          $ra
    // 0x80073408: nop

    return;
    // 0x80073408: nop

;}
RECOMP_FUNC void func_8003B504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B50C: jal         0x8003A5BC
    // 0x8003B510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003A5BC(rdram, ctx);
        goto after_0;
    // 0x8003B510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B514: jal         0x8003B41C
    // 0x8003B518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003B41C(rdram, ctx);
        goto after_1;
    // 0x8003B518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003B51C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B520: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003B524: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003B528: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8003B52C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8003B530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B538: jr          $ra
    // 0x8003B53C: nop

    return;
    // 0x8003B53C: nop

;}
RECOMP_FUNC void func_806D6BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6BB0: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(622, 0XC80) << 16);
    // 0x806D6BB4: addiu       $v0, $v0, 0x7830
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(622, 0XC80));
    // 0x806D6BB8: jr          $ra
    // 0x806D6BBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806D6BBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804C44B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C44B4: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x804C44B8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x804C44BC: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    // 0x804C44C0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804C44C4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x804C44C8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x804C44CC: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x804C44D0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x804C44D4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x804C44D8: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x804C44DC: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x804C44E0: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
    // 0x804C44E4: jr          $ra
    // 0x804C44E8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    return;
    // 0x804C44E8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_80673D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673D24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80673D28: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80673D2C: jr          $ra
    // 0x80673D30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x80673D30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8002DE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DE68: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8002DE6C: lh          $v1, -0x7680($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7680);
    // 0x8002DE70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002DE74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002DE78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002DE7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DE80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002DE84: slti        $v1, $v1, 0x1F
    ctx->r3 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x8002DE88: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8002DE8C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8002DE90: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8002DE94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DE98: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8002DE9C: jal         0x8002B9E4
    // 0x8002DEA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002DEA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002DEA4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002DEA8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8002DEAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DEB0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002DEB4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8002DEB8: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x8002DEBC: lbu         $t6, -0x1814($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1814);
    // 0x8002DEC0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8002DEC4: sb          $zero, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = 0;
    // 0x8002DEC8: sb          $zero, 0xF7($v0)
    MEM_B(0XF7, ctx->r2) = 0;
    // 0x8002DECC: sb          $t6, 0xF5($v0)
    MEM_B(0XF5, ctx->r2) = ctx->r14;
    // 0x8002DED0: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8002DED4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8002DED8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8002DEDC: sltu        $t8, $zero, $t7
    ctx->r24 = 0 < ctx->r15 ? 1 : 0;
    // 0x8002DEE0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8002DEE4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002DEE8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002DEEC: lw          $t2, -0x1824($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1824);
    // 0x8002DEF0: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002DEF4: jal         0x8001D770
    // 0x8002DEF8: sw          $t2, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r10;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x8002DEF8: sw          $t2, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r10;
    after_1:
    // 0x8002DEFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DF00: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002DF04: jal         0x80067BF8
    // 0x8002DF08: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x8002DF08: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8002DF0C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002DF10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DF14: jal         0x80067838
    // 0x8002DF18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8002DF18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8002DF1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DF20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DF24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002DF28: jr          $ra
    // 0x8002DF2C: nop

    return;
    // 0x8002DF2C: nop

;}
RECOMP_FUNC void func_80705458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80705458: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070545C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80705460: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80705464: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80705468: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x8070546C: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x80705470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80705474: beq         $v0, $zero, L_80705484
    if (ctx->r2 == 0) {
        // 0x80705478: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80705484;
    }
    // 0x80705478: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8070547C: sw          $t6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r14;
    // 0x80705480: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80705484:
    // 0x80705484: bnel        $v0, $zero, L_807054F4
    if (ctx->r2 != 0) {
        // 0x80705488: lwc1        $f0, 0xC($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
            goto L_807054F4;
    }
    goto skip_0;
    // 0x80705488: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x8070548C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80705490: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80705494: jal         0x800447C8
    // 0x80705498: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80705498: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8070549C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807054A0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x807054A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807054A8: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x807054AC: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(709, 0X37A8) << 16);
    // 0x807054B0: addiu       $a1, $a1, 0x6C18
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(709, 0X37A8));
    // 0x807054B4: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807054B8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x807054BC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807054C0: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x807054C4: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x807054C8: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x807054CC: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x807054D0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x807054D4: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x807054D8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x807054DC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x807054E0: jalr        $t9
    // 0x807054E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x807054E4: nop

    after_1:
    // 0x807054E8: b           L_8070555C
    // 0x807054EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8070555C;
    // 0x807054EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807054F0: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
L_807054F4:
    // 0x807054F4: lwc1        $f12, 0x6C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x807054F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807054FC: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80705500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80705504: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38B8) << 16);
    // 0x80705508: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8070550C: mul.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80705510: bc1fl       L_80705528
    if (!c1cs) {
        // 0x80705514: lwc1        $f0, 0x70($a3)
        ctx->f0.u32l = MEM_W(ctx->r7, 0X70);
            goto L_80705528;
    }
    goto skip_1;
    // 0x80705514: lwc1        $f0, 0x70($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X70);
    skip_1:
    // 0x80705518: lwc1        $f10, 0x6D28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38B8));
    // 0x8070551C: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80705520: swc1        $f16, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = ctx->f16.u32l;
    // 0x80705524: lwc1        $f0, 0x70($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X70);
L_80705528:
    // 0x80705528: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38BC) << 16);
    // 0x8070552C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80705530: nop

    // 0x80705534: bc1f        L_80705548
    if (!c1cs) {
        // 0x80705538: nop
    
            goto L_80705548;
    }
    // 0x80705538: nop

    // 0x8070553C: lwc1        $f18, 0x6D2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38BC));
    // 0x80705540: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80705544: swc1        $f4, 0x70($a3)
    MEM_W(0X70, ctx->r7) = ctx->f4.u32l;
L_80705548:
    // 0x80705548: jal         0x80048F84
    // 0x8070554C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8070554C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80705550: jal         0x80703F10
    // 0x80705554: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80703F10(rdram, ctx);
        goto after_3;
    // 0x80705554: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80705558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8070555C:
    // 0x8070555C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80705560: jr          $ra
    // 0x80705564: nop

    return;
    // 0x80705564: nop

;}
RECOMP_FUNC void func_805ACA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ACA24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ACA28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805ACA2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805ACA30: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805ACA34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805ACA38: jal         0x805AC884
    // 0x805ACA3C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_805AC884(rdram, ctx);
        goto after_0;
    // 0x805ACA3C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x805ACA40: jal         0x805AC528
    // 0x805ACA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AC528(rdram, ctx);
        goto after_1;
    // 0x805ACA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805ACA48: jal         0x805AC68C
    // 0x805ACA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AC68C(rdram, ctx);
        goto after_2;
    // 0x805ACA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805ACA50: beq         $v0, $zero, L_805ACA78
    if (ctx->r2 == 0) {
        // 0x805ACA54: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_805ACA78;
    }
    // 0x805ACA54: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805ACA58: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x805ACA5C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x805ACA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACA64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ACA68: jal         0x805AD274
    // 0x805ACA6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_805AD274(rdram, ctx);
        goto after_3;
    // 0x805ACA6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x805ACA70: b           L_805ACAFC
    // 0x805ACA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805ACAFC;
    // 0x805ACA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805ACA78:
    // 0x805ACA78: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x805ACA7C: beq         $v0, $zero, L_805ACA8C
    if (ctx->r2 == 0) {
        // 0x805ACA80: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805ACA8C;
    }
    // 0x805ACA80: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805ACA84: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x805ACA88: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_805ACA8C:
    // 0x805ACA8C: bnel        $v0, $zero, L_805ACAF0
    if (ctx->r2 != 0) {
        // 0x805ACA90: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805ACAF0;
    }
    goto skip_0;
    // 0x805ACA90: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805ACA94: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x805ACA98: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(441, 0X11E0) << 16);
    // 0x805ACA9C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x805ACAA0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x805ACAA4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805ACAA8: lh          $t9, -0x2C30($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(441, 0X11E0));
    // 0x805ACAAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805ACAB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805ACAB4: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x805ACAB8: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x805ACABC: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x805ACAC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805ACAC4: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x805ACAC8: bne         $at, $zero, L_805ACAEC
    if (ctx->r1 != 0) {
        // 0x805ACACC: sw          $t1, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r9;
            goto L_805ACAEC;
    }
    // 0x805ACACC: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x805ACAD0: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x805ACAD4: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x805ACAD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ACADC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805ACAE0: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x805ACAE4: jal         0x805AD274
    // 0x805ACAE8: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    func_805AD274(rdram, ctx);
        goto after_4;
    // 0x805ACAE8: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    after_4:
L_805ACAEC:
    // 0x805ACAEC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805ACAF0:
    // 0x805ACAF0: jal         0x80048F84
    // 0x805ACAF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x805ACAF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805ACAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805ACAFC:
    // 0x805ACAFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805ACB00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ACB04: jr          $ra
    // 0x805ACB08: nop

    return;
    // 0x805ACB08: nop

;}
RECOMP_FUNC void func_80449A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449A94: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80449A98: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80449A9C: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x80449AA0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80449AA4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80449AA8: bnel        $t8, $zero, L_80449AD4
    if (ctx->r24 != 0) {
        // 0x80449AAC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80449AD4;
    }
    goto skip_0;
    // 0x80449AAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80449AB0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14078) << 16);
    // 0x80449AB4: lwc1        $f4, -0x7BA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14078));
    // 0x80449AB8: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80449ABC: nop

    // 0x80449AC0: bc1fl       L_80449AF4
    if (!c1cs) {
        // 0x80449AC4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80449AF4;
    }
    goto skip_1;
    // 0x80449AC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80449AC8: jr          $ra
    // 0x80449ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80449ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449AD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80449AD4:
    // 0x80449AD4: nop

    // 0x80449AD8: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80449ADC: nop

    // 0x80449AE0: bc1fl       L_80449AF4
    if (!c1cs) {
        // 0x80449AE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80449AF4;
    }
    goto skip_2;
    // 0x80449AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80449AE8: jr          $ra
    // 0x80449AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80449AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80449AF4:
    // 0x80449AF4: jr          $ra
    // 0x80449AF8: nop

    return;
    // 0x80449AF8: nop

;}
RECOMP_FUNC void func_80423EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423EF8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80423EFC: srl         $v0, $a3, 1
    ctx->r2 = S32(U32(ctx->r7) >> 1);
    // 0x80423F00: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80423F04: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80423F08: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80423F0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80423F10: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80423F14: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80423F18: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80423F1C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80423F20: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80423F24: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80423F28: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80423F2C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80423F30: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80423F34: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80423F38: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80423F3C: bgez        $v0, L_80423F54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80423F40: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80423F54;
    }
    // 0x80423F40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80423F44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80423F48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80423F4C: nop

    // 0x80423F50: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80423F54:
    // 0x80423F54: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80423F58: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x80423F5C: addiu       $s3, $v0, 0x3
    ctx->r19 = ADD32(ctx->r2, 0X3);
    // 0x80423F60: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80423F64: sltiu       $at, $s3, 0x3
    ctx->r1 = ctx->r19 < 0X3 ? 1 : 0;
    // 0x80423F68: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x80423F6C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80423F70: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80423F74: addiu       $s0, $a0, 0x18
    ctx->r16 = ADD32(ctx->r4, 0X18);
    // 0x80423F78: addiu       $s1, $a1, 0x18
    ctx->r17 = ADD32(ctx->r5, 0X18);
    // 0x80423F7C: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80423F80: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80423F84: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80423F88: lwc1        $f20, 0x5C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80423F8C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80423F90: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80423F94: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x80423F98: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80423F9C: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x80423FA0: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x80423FA4: sh          $t9, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r25;
    // 0x80423FA8: lh          $t0, 0x8($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X8);
    // 0x80423FAC: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x80423FB0: lh          $t1, 0xA($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XA);
    // 0x80423FB4: sh          $t1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r9;
    // 0x80423FB8: lh          $t2, 0xC($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XC);
    // 0x80423FBC: sh          $t2, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r10;
    // 0x80423FC0: lh          $t3, 0xE($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XE);
    // 0x80423FC4: sh          $t3, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r11;
    // 0x80423FC8: lh          $t4, 0x10($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X10);
    // 0x80423FCC: sh          $t4, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r12;
    // 0x80423FD0: lh          $t5, 0x12($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X12);
    // 0x80423FD4: sh          $t5, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r13;
    // 0x80423FD8: lh          $t6, 0x14($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X14);
    // 0x80423FDC: sh          $t6, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r14;
    // 0x80423FE0: lh          $t7, 0x16($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X16);
    // 0x80423FE4: bne         $at, $zero, L_804240C8
    if (ctx->r1 != 0) {
        // 0x80423FE8: sh          $t7, 0x16($a0)
        MEM_H(0X16, ctx->r4) = ctx->r15;
            goto L_804240C8;
    }
    // 0x80423FE8: sh          $t7, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r15;
    // 0x80423FEC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80423FF0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80423FF4: nop

L_80423FF8:
    // 0x80423FF8: sub.s       $f16, $f20, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x80423FFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80424000: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80424004: nop

    // 0x80424008: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8042400C: add.s       $f26, $f4, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80424010: jal         0x80066E88
    // 0x80424014: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80424014: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x80424018: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8042401C: jal         0x80066DE4
    // 0x80424020: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80424020: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_1:
    // 0x80424024: mul.s       $f2, $f24, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x80424028: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8042402C: mul.s       $f14, $f24, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80424030: sub.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x80424034: sub.s       $f10, $f30, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f30.fl - ctx->f14.fl;
    // 0x80424038: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8042403C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80424040: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80424044: add.s       $f18, $f28, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f28.fl + ctx->f2.fl;
    // 0x80424048: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8042404C: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x80424050: add.s       $f8, $f30, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f30.fl + ctx->f14.fl;
    // 0x80424054: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80424058: lh          $t2, 0x4($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X4);
    // 0x8042405C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80424060: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80424064: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80424068: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8042406C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80424070: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x80424074: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x80424078: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x8042407C: jal         0x80066E88
    // 0x80424080: sh          $t7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r15;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80424080: sh          $t7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r15;
    after_2:
    // 0x80424084: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80424088: jal         0x80066DE4
    // 0x8042408C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8042408C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x80424090: mul.s       $f26, $f24, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80424094: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80424098: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8042409C: mul.s       $f16, $f24, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x804240A0: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x804240A4: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x804240A8: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x804240AC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x804240B0: add.s       $f28, $f26, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f28.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x804240B4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x804240B8: bne         $at, $zero, L_80423FF8
    if (ctx->r1 != 0) {
        // 0x804240BC: sub.s       $f30, $f30, $f16
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f16.fl;
            goto L_80423FF8;
    }
    // 0x804240BC: sub.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x804240C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x804240C4: nop

L_804240C8:
    // 0x804240C8: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x804240CC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36CC) << 16);
    // 0x804240D0: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    // 0x804240D4: swc1        $f30, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f30.u32l;
    // 0x804240D8: lwc1        $f4, 0x60CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36CC));
    // 0x804240DC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804240E0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x804240E4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x804240E8: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x804240EC: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x804240F0: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    // 0x804240F4: nop

    // 0x804240F8: bc1fl       L_80424144
    if (!c1cs) {
        // 0x804240FC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80424144;
    }
    goto skip_0;
    // 0x804240FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80424100: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x80424104: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80424108: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042410C: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x80424110: nop

    // 0x80424114: bc1fl       L_80424170
    if (!c1cs) {
        // 0x80424118: swc1        $f20, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
            goto L_80424170;
    }
    goto skip_1;
    // 0x80424118: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
    skip_1:
    // 0x8042411C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80424120: nop

    // 0x80424124: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_80424128:
    // 0x80424128: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x8042412C: nop

    // 0x80424130: bc1tl       L_80424128
    if (c1cs) {
        // 0x80424134: add.s       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
            goto L_80424128;
    }
    goto skip_2;
    // 0x80424134: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    skip_2:
    // 0x80424138: b           L_80424170
    // 0x8042413C: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
        goto L_80424170;
    // 0x8042413C: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
    // 0x80424140: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80424144:
    // 0x80424144: nop

    // 0x80424148: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8042414C: nop

    // 0x80424150: bc1fl       L_80424170
    if (!c1cs) {
        // 0x80424154: swc1        $f20, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
            goto L_80424170;
    }
    goto skip_3;
    // 0x80424154: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
    skip_3:
    // 0x80424158: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
L_8042415C:
    // 0x8042415C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80424160: nop

    // 0x80424164: bc1tl       L_8042415C
    if (c1cs) {
        // 0x80424168: sub.s       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
            goto L_8042415C;
    }
    goto skip_4;
    // 0x80424168: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    skip_4:
    // 0x8042416C: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
L_80424170:
    // 0x80424170: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80424174: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80424178: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8042417C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80424180: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80424184: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80424188: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8042418C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80424190: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80424194: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80424198: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8042419C: jr          $ra
    // 0x804241A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x804241A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8042DDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DDB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042DDB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042DDBC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042DDC0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8042DDC4: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(53, 0X3D0) << 16);
    // 0x8042DDC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042DDCC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042DDD0: lw          $t8, -0x2010($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(53, 0X3D0));
    // 0x8042DDD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042DDD8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042DDDC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042DDE0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042DDE4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042DDE8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042DDEC: beql        $v1, $zero, L_8042DE20
    if (ctx->r3 == 0) {
        // 0x8042DDF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042DE20;
    }
    goto skip_0;
    // 0x8042DDF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042DDF4: jalr        $v1
    // 0x8042DDF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042DDF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042DDFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042DE00: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042DE04: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042DE08: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042DE0C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042DE10: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042DE14: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042DE18: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042DE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042DE20:
    // 0x8042DE20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042DE24: jr          $ra
    // 0x8042DE28: nop

    return;
    // 0x8042DE28: nop

;}
RECOMP_FUNC void func_8046CA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CA1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046CA20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8046CA24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8046CA28: jal         0x8004700C
    // 0x8046CA2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046CA2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046CA30: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8046CA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CA38: jal         0x80048F84
    // 0x8046CA3C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8046CA3C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x8046CA40: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8046CA44: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x8046CA48: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8046CA4C: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x8046CA50: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8046CA54: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x8046CA58: jal         0x8046C92C
    // 0x8046CA5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8046C92C(rdram, ctx);
        goto after_2;
    // 0x8046CA5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x8046CA60: beq         $v0, $zero, L_8046CAD4
    if (ctx->r2 == 0) {
        // 0x8046CA64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8046CAD4;
    }
    // 0x8046CA64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CA68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CA6C: jal         0x8046D3E8
    // 0x8046CA70: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8046D3E8(rdram, ctx);
        goto after_3;
    // 0x8046CA70: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x8046CA74: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8046CA78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046CA7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046CA80: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8046CA84: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x8046CA88: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8046CA8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8046CA90: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8046CA94: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8046CA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CA9C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8046CAA0: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8046CAA4: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x8046CAA8: lui         $a3, 0xC180
    ctx->r7 = S32(0XC180 << 16);
    // 0x8046CAAC: jalr        $t9
    // 0x8046CAB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8046CAB0: nop

    after_4:
    // 0x8046CAB4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8046CAB8: jal         0x80067BBC
    // 0x8046CABC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8046CABC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8046CAC0: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x8046CAC4: jal         0x80067818
    // 0x8046CAC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8046CAC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8046CACC: b           L_8046CB48
    // 0x8046CAD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8046CB48;
    // 0x8046CAD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8046CAD4:
    // 0x8046CAD4: lw          $t0, 0x1E0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E0);
    // 0x8046CAD8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8046CADC: slti        $at, $t1, 0x1E
    ctx->r1 = SIGNED(ctx->r9) < 0X1E ? 1 : 0;
    // 0x8046CAE0: bne         $at, $zero, L_8046CB44
    if (ctx->r1 != 0) {
        // 0x8046CAE4: sw          $t1, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r9;
            goto L_8046CB44;
    }
    // 0x8046CAE4: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
    // 0x8046CAE8: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CAEC: lui         $a2, 0x8047
    ctx->r6 = S32(RELOC_HI16(143, 0X1398) << 16);
    // 0x8046CAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CAF4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8046CAF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CAFC: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8046CB00: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8046CB04: jal         0x8046D3E8
    // 0x8046CB08: lbu         $a2, -0x2818($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(143, 0X1398));
    func_8046D3E8(rdram, ctx);
        goto after_7;
    // 0x8046CB08: lbu         $a2, -0x2818($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(143, 0X1398));
    after_7:
    // 0x8046CB0C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CB10: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8046CB14: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8046CB18: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8046CB1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8046CB20: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x8046CB24: beql        $t8, $at, L_8046CB48
    if (ctx->r24 == ctx->r1) {
        // 0x8046CB28: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8046CB48;
    }
    goto skip_0;
    // 0x8046CB28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8046CB2C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8046CB30: jal         0x80067BBC
    // 0x8046CB34: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_8;
    // 0x8046CB34: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x8046CB38: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x8046CB3C: jal         0x80067818
    // 0x8046CB40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8046CB40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_8046CB44:
    // 0x8046CB44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8046CB48:
    // 0x8046CB48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8046CB4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046CB50: jr          $ra
    // 0x8046CB54: nop

    return;
    // 0x8046CB54: nop

;}
RECOMP_FUNC void func_80026C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026C8C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026C90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80026C94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80026C98: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80026C9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026CA0: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80026CA4: beql        $t8, $zero, L_80026CC0
    if (ctx->r24 == 0) {
        // 0x80026CA8: addiu       $a0, $a1, 0x14C
        ctx->r4 = ADD32(ctx->r5, 0X14C);
            goto L_80026CC0;
    }
    goto skip_0;
    // 0x80026CA8: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
    skip_0:
    // 0x80026CAC: jal         0x80026C4C
    // 0x80026CB0: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    func_80026C4C(rdram, ctx);
        goto after_0;
    // 0x80026CB0: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    after_0:
    // 0x80026CB4: b           L_80026CCC
    // 0x80026CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80026CCC;
    // 0x80026CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026CBC: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
L_80026CC0:
    // 0x80026CC0: jal         0x80024680
    // 0x80026CC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    func_80024680(rdram, ctx);
        goto after_1;
    // 0x80026CC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80026CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026CCC:
    // 0x80026CCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026CD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026CD4: jr          $ra
    // 0x80026CD8: nop

    return;
    // 0x80026CD8: nop

;}
RECOMP_FUNC void func_80525CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525CEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80525CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80525CF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80525CF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80525CFC: jal         0x80047090
    // 0x80525D00: addiu       $a0, $zero, 0x45D7
    ctx->r4 = ADD32(0, 0X45D7);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80525D00: addiu       $a0, $zero, 0x45D7
    ctx->r4 = ADD32(0, 0X45D7);
    after_0:
    // 0x80525D04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80525D08: lui         $at, 0x45D7
    ctx->r1 = S32(0X45D7 << 16);
    // 0x80525D0C: ori         $at, $at, 0x4400
    ctx->r1 = ctx->r1 | 0X4400;
    // 0x80525D10: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80525D14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80525D18: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80525D1C: jal         0x8004613C
    // 0x80525D20: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80525D20: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80525D24: beq         $v0, $zero, L_80525D64
    if (ctx->r2 == 0) {
        // 0x80525D28: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80525D64;
    }
    // 0x80525D28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80525D2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80525D30: jal         0x80047F9C
    // 0x80525D34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80525D34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80525D38: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x80525D3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80525D40: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X8FC) << 16);
    // 0x80525D44: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80525D48: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80525D4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80525D50: lwc1        $f4, 0x5E0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X8FC));
    // 0x80525D54: sb          $v0, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r2;
    // 0x80525D58: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x80525D5C: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x80525D60: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
L_80525D64:
    // 0x80525D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80525D68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80525D6C: jr          $ra
    // 0x80525D70: nop

    return;
    // 0x80525D70: nop

    // 0x80525D74: nop

    // 0x80525D78: nop

    // 0x80525D7C: nop

;}
RECOMP_FUNC void func_804645D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804645D0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804645D4: addiu       $at, $zero, 0x4096
    ctx->r1 = ADD32(0, 0X4096);
    // 0x804645D8: beq         $v0, $at, L_804645F0
    if (ctx->r2 == ctx->r1) {
        // 0x804645DC: addiu       $at, $zero, 0x4097
        ctx->r1 = ADD32(0, 0X4097);
            goto L_804645F0;
    }
    // 0x804645DC: addiu       $at, $zero, 0x4097
    ctx->r1 = ADD32(0, 0X4097);
    // 0x804645E0: beq         $v0, $at, L_804645FC
    if (ctx->r2 == ctx->r1) {
        // 0x804645E4: nop
    
            goto L_804645FC;
    }
    // 0x804645E4: nop

    // 0x804645E8: b           L_80464608
    // 0x804645EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80464608;
    // 0x804645EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804645F0:
    // 0x804645F0: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(125, 0XD00) << 16);
    // 0x804645F4: jr          $ra
    // 0x804645F8: addiu       $v0, $v0, 0x52D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(125, 0XD00));
    return;
    // 0x804645F8: addiu       $v0, $v0, 0x52D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(125, 0XD00));
L_804645FC:
    // 0x804645FC: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(125, 0X1928) << 16);
    // 0x80464600: jr          $ra
    // 0x80464604: addiu       $v0, $v0, 0x5EF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(125, 0X1928));
    return;
    // 0x80464604: addiu       $v0, $v0, 0x5EF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(125, 0X1928));
L_80464608:
    // 0x80464608: jr          $ra
    // 0x8046460C: nop

    return;
    // 0x8046460C: nop

;}
RECOMP_FUNC void func_8076D744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D744: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076D748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076D74C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8076D750: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8076D754: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D758: jal         0x8076D1EC
    // 0x8076D75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8076D1EC(rdram, ctx);
        goto after_0;
    // 0x8076D75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8076D760: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8076D764: jal         0x8076CD88
    // 0x8076D768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8076CD88(rdram, ctx);
        goto after_1;
    // 0x8076D768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8076D76C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8076D770: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8076D774: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8076D778: bnel        $t7, $at, L_8076D7A4
    if (ctx->r15 != ctx->r1) {
        // 0x8076D77C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8076D7A4;
    }
    goto skip_0;
    // 0x8076D77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8076D780: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8076D784: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8076D788: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D78C: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x8076D790: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8076D794: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8076D798: jal         0x8076DD8C
    // 0x8076D79C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_2;
    // 0x8076D79C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
    // 0x8076D7A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076D7A4:
    // 0x8076D7A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8076D7A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076D7AC: jr          $ra
    // 0x8076D7B0: nop

    return;
    // 0x8076D7B0: nop

;}
RECOMP_FUNC void func_806F8D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8D58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F8D5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8D60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F8D64: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F8D68: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x806F8D6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806F8D70: addiu       $a1, $zero, 0x5F8
    ctx->r5 = ADD32(0, 0X5F8);
    // 0x806F8D74: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x806F8D78: jal         0x80045A34
    // 0x806F8D7C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F8D7C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x806F8D80: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x806F8D84: bne         $v0, $zero, L_806F8D9C
    if (ctx->r2 != 0) {
        // 0x806F8D88: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806F8D9C;
    }
    // 0x806F8D88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806F8D8C: jal         0x800445A4
    // 0x806F8D90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F8D90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x806F8D94: b           L_806F8DDC
    // 0x806F8D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F8DDC;
    // 0x806F8D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F8D9C:
    // 0x806F8D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F8DA0: addiu       $a1, $zero, 0x5F8
    ctx->r5 = ADD32(0, 0X5F8);
    // 0x806F8DA4: jal         0x80065728
    // 0x806F8DA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x806F8DA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x806F8DAC: sw          $zero, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = 0;
    // 0x806F8DB0: jal         0x806F80FC
    // 0x806F8DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F80FC(rdram, ctx);
        goto after_3;
    // 0x806F8DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F8DB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F8DBC: jal         0x8005D730
    // 0x806F8DC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_4;
    // 0x806F8DC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x806F8DC4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x806F8DC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F8DCC: sw          $t8, 0x260($s0)
    MEM_W(0X260, ctx->r16) = ctx->r24;
    // 0x806F8DD0: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x806F8DD4: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x806F8DD8: sh          $t0, 0x25C($s0)
    MEM_H(0X25C, ctx->r16) = ctx->r8;
L_806F8DDC:
    // 0x806F8DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8DE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F8DE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F8DE8: jr          $ra
    // 0x806F8DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806F8DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806D02A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D02A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D02A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D02AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D02B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D02B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806D02B8: bne         $a1, $zero, L_806D034C
    if (ctx->r5 != 0) {
        // 0x806D02BC: lw          $s0, 0x1F4($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X1F4);
            goto L_806D034C;
    }
    // 0x806D02BC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D02C0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806D02C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D02C8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806D02CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806D02D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D02D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806D02D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806D02DC: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x806D02E0: jal         0x806CF864
    // 0x806D02E4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    func_806CF864(rdram, ctx);
        goto after_0;
    // 0x806D02E4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x806D02E8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x806D02EC: jal         0x80066DE4
    // 0x806D02F0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806D02F0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x806D02F4: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806D02F8: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806D02FC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x806D0300: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806D0304: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D0308: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x806D030C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806D0310: jal         0x80066E88
    // 0x806D0314: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806D0314: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x806D0318: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806D031C: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x806D0320: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x806D0324: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806D0328: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D032C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B08) << 16);
    // 0x806D0330: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x806D0334: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806D0338: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806D033C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x806D0340: lwc1        $f10, 0x12A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B08));
    // 0x806D0344: b           L_806D03D4
    // 0x806D0348: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
        goto L_806D03D4;
    // 0x806D0348: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
L_806D034C:
    // 0x806D034C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806D0350: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D0354: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806D0358: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806D035C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806D0360: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806D0364: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806D0368: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x806D036C: jal         0x806CF864
    // 0x806D0370: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    func_806CF864(rdram, ctx);
        goto after_3;
    // 0x806D0370: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x806D0374: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x806D0378: jal         0x80066DE4
    // 0x806D037C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x806D037C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x806D0380: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806D0384: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806D0388: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x806D038C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806D0390: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D0394: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806D0398: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806D039C: jal         0x80066E88
    // 0x806D03A0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x806D03A0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x806D03A4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806D03A8: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x806D03AC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x806D03B0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806D03B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D03B8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B0C) << 16);
    // 0x806D03BC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x806D03C0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806D03C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806D03C8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x806D03CC: lwc1        $f6, 0x12AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B0C));
    // 0x806D03D0: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_806D03D4:
    // 0x806D03D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D03D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D03DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D03E0: jr          $ra
    // 0x806D03E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806D03E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80683104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80683104: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80683108: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8068310C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80683110: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80683114: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80683118: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8068311C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80683120: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80683124: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80683128: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8068312C: jr          $ra
    // 0x80683130: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80683130: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8066D8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D8D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8066D8DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8066D8E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8066D8E4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8066D8E8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8066D8EC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8066D8F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8066D8F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8066D8F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8066D8FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8066D900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066D904: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066D908: lw          $s5, 0x174($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X174);
    // 0x8066D90C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8066D910: lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X18);
    // 0x8066D914: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8066D918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8066D91C: beq         $v0, $zero, L_8066D92C
    if (ctx->r2 == 0) {
        // 0x8066D920: lw          $s0, 0x2C($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X2C);
            goto L_8066D92C;
    }
    // 0x8066D920: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x8066D924: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8066D928: sw          $t7, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r15;
L_8066D92C:
    // 0x8066D92C: jal         0x80049D74
    // 0x8066D930: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8066D930: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x8066D934: beq         $s0, $zero, L_8066D9F8
    if (ctx->r16 == 0) {
        // 0x8066D938: sw          $zero, 0x8($s5)
        MEM_W(0X8, ctx->r21) = 0;
            goto L_8066D9F8;
    }
    // 0x8066D938: sw          $zero, 0x8($s5)
    MEM_W(0X8, ctx->r21) = 0;
    // 0x8066D93C: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x8066D940: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8066D944: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8066D948: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
    // 0x8066D94C: addiu       $s7, $zero, 0x38
    ctx->r23 = ADD32(0, 0X38);
    // 0x8066D950: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x8066D954: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8066D958: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_8066D95C:
    // 0x8066D95C: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x8066D960: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8066D964: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8066D968: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x8066D96C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8066D970: beq         $v1, $zero, L_8066D9C4
    if (ctx->r3 == 0) {
        // 0x8066D974: nop
    
            goto L_8066D9C4;
    }
    // 0x8066D974: nop

    // 0x8066D978: beq         $s6, $v1, L_8066D9C4
    if (ctx->r22 == ctx->r3) {
        // 0x8066D97C: nop
    
            goto L_8066D9C4;
    }
    // 0x8066D97C: nop

    // 0x8066D980: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8066D984: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8066D988: beq         $s7, $v1, L_8066D9C4
    if (ctx->r23 == ctx->r3) {
        // 0x8066D98C: nop
    
            goto L_8066D9C4;
    }
    // 0x8066D98C: nop

    // 0x8066D990: beq         $fp, $v1, L_8066D9C4
    if (ctx->r30 == ctx->r3) {
        // 0x8066D994: nop
    
            goto L_8066D9C4;
    }
    // 0x8066D994: nop

    // 0x8066D998: beq         $s0, $s2, L_8066D9F0
    if (ctx->r16 == ctx->r18) {
        // 0x8066D99C: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_8066D9F0;
    }
    // 0x8066D99C: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8066D9A0: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(517, 0XF70) << 16);
    // 0x8066D9A4: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8066D9A8: lw          $t9, -0x1AD0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(517, 0XF70));
    // 0x8066D9AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8066D9B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8066D9B4: jalr        $t9
    // 0x8066D9B8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8066D9B8: nop

    after_1:
    // 0x8066D9BC: b           L_8066D9F0
    // 0x8066D9C0: nop

        goto L_8066D9F0;
    // 0x8066D9C0: nop

L_8066D9C4:
    // 0x8066D9C4: bne         $s0, $s2, L_8066D9F0
    if (ctx->r16 != ctx->r18) {
        // 0x8066D9C8: nop
    
            goto L_8066D9F0;
    }
    // 0x8066D9C8: nop

    // 0x8066D9CC: lw          $t1, 0x18($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X18);
    // 0x8066D9D0: bne         $t1, $zero, L_8066D9F0
    if (ctx->r9 != 0) {
        // 0x8066D9D4: nop
    
            goto L_8066D9F0;
    }
    // 0x8066D9D4: nop

    // 0x8066D9D8: lw          $t2, 0x24($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X24);
    // 0x8066D9DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8066D9E0: bne         $t2, $at, L_8066D9F0
    if (ctx->r10 != ctx->r1) {
        // 0x8066D9E4: nop
    
            goto L_8066D9F0;
    }
    // 0x8066D9E4: nop

    // 0x8066D9E8: jal         0x8066D5D0
    // 0x8066D9EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8066D5D0(rdram, ctx);
        goto after_2;
    // 0x8066D9EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
L_8066D9F0:
    // 0x8066D9F0: bnel        $s0, $zero, L_8066D95C
    if (ctx->r16 != 0) {
        // 0x8066D9F4: lw          $t8, 0x0($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X0);
            goto L_8066D95C;
    }
    goto skip_0;
    // 0x8066D9F4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    skip_0:
L_8066D9F8:
    // 0x8066D9F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8066D9FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066DA00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8066DA04: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8066DA08: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8066DA0C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8066DA10: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8066DA14: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8066DA18: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8066DA1C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8066DA20: jr          $ra
    // 0x8066DA24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8066DA24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800436A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800436A0: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x800436A4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800436A8: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x800436AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800436B0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800436B4: addiu       $t0, $t0, -0x1F6C
    ctx->r8 = ADD32(ctx->r8, -0X1F6C);
    // 0x800436B8: sw          $t7, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->r15;
    // 0x800436BC: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x800436C0: lui         $t3, 0x8002
    ctx->r11 = S32(0X8002 << 16);
    // 0x800436C4: addiu       $t3, $t3, -0x1DF4
    ctx->r11 = ADD32(ctx->r11, -0X1DF4);
    // 0x800436C8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800436CC: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x800436D0: lw          $t4, 0x174($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X174);
    // 0x800436D4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800436D8: jr          $ra
    // 0x800436DC: sw          $t3, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r11;
    return;
    // 0x800436DC: sw          $t3, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r11;
;}
RECOMP_FUNC void func_80053924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053924: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80053928: lw          $t6, 0x60D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X60D0);
    // 0x8005392C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80053930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053934: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80053938: bne         $t6, $zero, L_80053958
    if (ctx->r14 != 0) {
        // 0x8005393C: swc1        $f14, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
            goto L_80053958;
    }
    // 0x8005393C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80053940: jal         0x80052CDC
    // 0x80053944: nop

    func_80052CDC(rdram, ctx);
        goto after_0;
    // 0x80053944: nop

    after_0:
    // 0x80053948: bne         $v0, $zero, L_80053958
    if (ctx->r2 != 0) {
        // 0x8005394C: nop
    
            goto L_80053958;
    }
    // 0x8005394C: nop

    // 0x80053950: b           L_80053A04
    // 0x80053954: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053A04;
    // 0x80053954: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80053958:
    // 0x80053958: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005395C: lw          $v0, 0x60D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60D0);
    // 0x80053960: lw          $t7, 0x16C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X16C);
    // 0x80053964: lw          $v1, 0x1B0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X1B0);
    // 0x80053968: beq         $v1, $zero, L_80053984
    if (ctx->r3 == 0) {
        // 0x8005396C: nop
    
            goto L_80053984;
    }
    // 0x8005396C: nop

    // 0x80053970: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x80053974: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80053978: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8005397C: bnel        $t9, $zero, L_80053990
    if (ctx->r25 != 0) {
        // 0x80053980: trunc.w.s   $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
            goto L_80053990;
    }
    goto skip_0;
    // 0x80053980: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    skip_0:
L_80053984:
    // 0x80053984: b           L_80053A04
    // 0x80053988: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053A04;
    // 0x80053988: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005398C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
L_80053990:
    // 0x80053990: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80053994: nop

    // 0x80053998: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8005399C: jal         0x8006A99C
    // 0x800539A0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x800539A0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x800539A4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800539A8: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x800539AC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800539B0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800539B4: nop

    // 0x800539B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800539BC: jal         0x8006A99C
    // 0x800539C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x800539C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x800539C4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800539C8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800539CC: bltz        $v0, L_800539DC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800539D0: lh          $a2, 0x1C($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X1C);
            goto L_800539DC;
    }
    // 0x800539D0: lh          $a2, 0x1C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1C);
    // 0x800539D4: bgez        $a2, L_800539E4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800539D8: sll         $a0, $a2, 16
        ctx->r4 = S32(ctx->r6 << 16);
            goto L_800539E4;
    }
    // 0x800539D8: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
L_800539DC:
    // 0x800539DC: b           L_80053A04
    // 0x800539E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053A04;
    // 0x800539E0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_800539E4:
    // 0x800539E4: jal         0x8006ABF0
    // 0x800539E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006ABF0(rdram, ctx);
        goto after_3;
    // 0x800539E8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x800539EC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800539F0: bne         $v0, $at, L_80053A00
    if (ctx->r2 != ctx->r1) {
        // 0x800539F4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80053A00;
    }
    // 0x800539F4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800539F8: b           L_80053A04
    // 0x800539FC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_80053A04;
    // 0x800539FC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80053A00:
    // 0x80053A00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80053A04:
    // 0x80053A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053A08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80053A0C: jr          $ra
    // 0x80053A10: nop

    return;
    // 0x80053A10: nop

    // 0x80053A14: nop

    // 0x80053A18: nop

    // 0x80053A1C: nop

;}
RECOMP_FUNC void func_806EE6AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE6AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806EE6B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806EE6B4: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x806EE6B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_806EE6BC:
    // 0x806EE6BC: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x806EE6C0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806EE6C4: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x806EE6C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806EE6CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806EE6D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EE6D4: bc1f        L_806EE6F8
    if (!c1cs) {
        // 0x806EE6D8: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_806EE6F8;
    }
    // 0x806EE6D8: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x806EE6DC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806EE6E0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806EE6E4: nop

    // 0x806EE6E8: bc1f        L_806EE710
    if (!c1cs) {
        // 0x806EE6EC: nop
    
            goto L_806EE710;
    }
    // 0x806EE6EC: nop

    // 0x806EE6F0: b           L_806EE710
    // 0x806EE6F4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_806EE710;
    // 0x806EE6F4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806EE6F8:
    // 0x806EE6F8: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806EE6FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806EE700: nop

    // 0x806EE704: bc1f        L_806EE710
    if (!c1cs) {
        // 0x806EE708: nop
    
            goto L_806EE710;
    }
    // 0x806EE708: nop

    // 0x806EE70C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806EE710:
    // 0x806EE710: bne         $v1, $v0, L_806EE6BC
    if (ctx->r3 != ctx->r2) {
        // 0x806EE714: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806EE6BC;
    }
    // 0x806EE714: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806EE718: jr          $ra
    // 0x806EE71C: nop

    return;
    // 0x806EE71C: nop

;}
RECOMP_FUNC void func_8001D148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D148: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D150: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D154: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8001D158: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D15C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D160: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8001D164: sub.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001D168: jal         0x80065954
    // 0x8001D16C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8001D16C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8001D170: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D174: lwc1        $f14, -0x468($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X468);
    // 0x8001D178: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001D17C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D180: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8001D184: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D18C: bc1fl       L_8001D1A4
    if (!c1cs) {
        // 0x8001D190: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8001D1A4;
    }
    goto skip_0;
    // 0x8001D190: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8001D194: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D198: b           L_8001D1C8
    // 0x8001D19C: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
        goto L_8001D1C8;
    // 0x8001D19C: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8001D1A4:
    // 0x8001D1A4: nop

    // 0x8001D1A8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8001D1AC: nop

    // 0x8001D1B0: bc1fl       L_8001D1C4
    if (!c1cs) {
        // 0x8001D1B4: add.s       $f2, $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_8001D1C4;
    }
    goto skip_1;
    // 0x8001D1B4: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    skip_1:
    // 0x8001D1B8: b           L_8001D1C4
    // 0x8001D1BC: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
        goto L_8001D1C4;
    // 0x8001D1BC: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8001D1C0: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_8001D1C4:
    // 0x8001D1C4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
L_8001D1C8:
    // 0x8001D1C8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D1D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D1D4: jr          $ra
    // 0x8001D1D8: nop

    return;
    // 0x8001D1D8: nop

;}
RECOMP_FUNC void func_8040A1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A1A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8040A1A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040A1A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8040A1AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8040A1B0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8040A1B4: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(11, 0X2DE8) << 16);
    // 0x8040A1B8: lw          $v0, 0x7F78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F78);
    // 0x8040A1BC: addiu       $t7, $t7, -0x5848
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(11, 0X2DE8));
    // 0x8040A1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8040A1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8040A1C8: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8040A1CC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040A1D0: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8040A1D4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8040A1D8: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8040A1DC: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(11, 0X2C30) << 16);
    // 0x8040A1E0: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x8040A1E4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8040A1E8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8040A1EC: lbu         $t0, -0x5A00($t0)
    ctx->r8 = MEM_BU(ctx->r8, (int16_t)RELOC_LO16(11, 0X2C30));
    // 0x8040A1F0: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(11, 0X2C40) << 16);
    // 0x8040A1F4: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8040A1F8: sb          $t0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r8;
    // 0x8040A1FC: lbu         $t1, -0x59F0($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(11, 0X2C40));
    // 0x8040A200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040A204: jal         0x80409618
    // 0x8040A208: sb          $t1, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r9;
    func_80409618(rdram, ctx);
        goto after_0;
    // 0x8040A208: sb          $t1, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r9;
    after_0:
    // 0x8040A20C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8040A210: jal         0x80047AB8
    // 0x8040A214: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8040A214: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8040A218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8040A21C: jal         0x804091BC
    // 0x8040A220: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_804091BC(rdram, ctx);
        goto after_2;
    // 0x8040A220: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8040A224: lw          $t2, 0xB4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XB4C);
    // 0x8040A228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8040A22C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8040A230: addu        $t9, $sp, $t3
    ctx->r25 = ADD32(ctx->r29, ctx->r11);
    // 0x8040A234: lw          $t9, 0x20($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20);
    // 0x8040A238: jalr        $t9
    // 0x8040A23C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8040A23C: nop

    after_3:
    // 0x8040A240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040A244: jal         0x80409798
    // 0x8040A248: addiu       $a1, $s1, 0xB50
    ctx->r5 = ADD32(ctx->r17, 0XB50);
    func_80409798(rdram, ctx);
        goto after_4;
    // 0x8040A248: addiu       $a1, $s1, 0xB50
    ctx->r5 = ADD32(ctx->r17, 0XB50);
    after_4:
    // 0x8040A24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A250: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8040A254: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8040A258: jr          $ra
    // 0x8040A25C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8040A25C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804E79DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E79DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E79E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E79E4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804E79E8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804E79EC: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804E79F0: lui         $t7, 0x804E
    ctx->r15 = S32(RELOC_HI16(261, 0X63C) << 16);
    // 0x804E79F4: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804E79F8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804E79FC: addiu       $t7, $t7, 0x7E9C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(261, 0X63C));
    // 0x804E7A00: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804E7A04: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804E7A08: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x804E7A0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804E7A10: jal         0x804E7CF8
    // 0x804E7A14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804E7CF8(rdram, ctx);
        goto after_0;
    // 0x804E7A14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x804E7A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7A20: jr          $ra
    // 0x804E7A24: nop

    return;
    // 0x804E7A24: nop

;}
RECOMP_FUNC void func_8042C1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C1D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042C1DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042C1E0: jal         0x8042C194
    // 0x8042C1E4: addiu       $a1, $zero, 0x20B
    ctx->r5 = ADD32(0, 0X20B);
    func_8042C194(rdram, ctx);
        goto after_0;
    // 0x8042C1E4: addiu       $a1, $zero, 0x20B
    ctx->r5 = ADD32(0, 0X20B);
    after_0:
    // 0x8042C1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042C1EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042C1F0: jr          $ra
    // 0x8042C1F4: nop

    return;
    // 0x8042C1F4: nop

;}
RECOMP_FUNC void func_806AAFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AAFDC: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806AAFE0: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(592, 0X2F40) << 16);
    // 0x806AAFE4: addiu       $t9, $t9, -0x24E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(592, 0X2F40));
    // 0x806AAFE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806AAFEC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806AAFF0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806AAFF4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806AAFF8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x806AAFFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AB000: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AB004: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x806AB008: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x806AB00C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x806AB010: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x806AB014: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x806AB018: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x806AB01C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806AB020: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x806AB024: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x806AB028: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x806AB02C: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x806AB030: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x806AB034: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x806AB038: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x806AB03C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806AB040: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x806AB044: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x806AB048: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x806AB04C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x806AB050: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x806AB054: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x806AB058: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x806AB05C: bnel        $at, $zero, L_806AB098
    if (ctx->r1 != 0) {
        // 0x806AB060: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806AB098;
    }
    goto skip_0;
    // 0x806AB060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806AB064: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x806AB068: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x806AB06C: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x806AB070: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x806AB074: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x806AB078: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x806AB07C: bne         $at, $zero, L_806AB08C
    if (ctx->r1 != 0) {
        // 0x806AB080: nop
    
            goto L_806AB08C;
    }
    // 0x806AB080: nop

    // 0x806AB084: b           L_806AB098
    // 0x806AB088: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
        goto L_806AB098;
    // 0x806AB088: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_806AB08C:
    // 0x806AB08C: b           L_806AB098
    // 0x806AB090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806AB098;
    // 0x806AB090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806AB094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AB098:
    // 0x806AB098: jr          $ra
    // 0x806AB09C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806AB09C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80433840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433840: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x80433844: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80433848: slti        $at, $t7, 0x101
    ctx->r1 = SIGNED(ctx->r15) < 0X101 ? 1 : 0;
    // 0x8043384C: bne         $at, $zero, L_80433858
    if (ctx->r1 != 0) {
        // 0x80433850: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_80433858;
    }
    // 0x80433850: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x80433854: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_80433858:
    // 0x80433858: jr          $ra
    // 0x8043385C: nop

    return;
    // 0x8043385C: nop

;}
RECOMP_FUNC void func_800650B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800650B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800650B8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800650BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800650C0: jal         0x80065728
    // 0x800650C4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x800650C4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_0:
    // 0x800650C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800650CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800650D0: jr          $ra
    // 0x800650D4: nop

    return;
    // 0x800650D4: nop

;}
RECOMP_FUNC void func_807C388C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C388C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C3890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C3894: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C3898: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x807C389C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807C38A0: jal         0x80065728
    // 0x807C38A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x807C38A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C38A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807C38AC: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x807C38B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807C38B4: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x807C38B8: sb          $t7, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r15;
    // 0x807C38BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C38C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C38C4: jr          $ra
    // 0x807C38C8: nop

    return;
    // 0x807C38C8: nop

;}
RECOMP_FUNC void func_807ABFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ABFE8: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(856, 0XAB8) << 16);
    // 0x807ABFEC: addiu       $t6, $t6, -0x3AF8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(856, 0XAB8));
    // 0x807ABFF0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x807ABFF4: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(856, 0XAC8) << 16);
    // 0x807ABFF8: addiu       $t9, $t9, -0x3AE8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(856, 0XAC8));
    // 0x807ABFFC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x807AC000: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x807AC004: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(856, 0XAD8) << 16);
    // 0x807AC008: addiu       $t2, $t2, -0x3AD8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(856, 0XAD8));
    // 0x807AC00C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x807AC010: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x807AC014: lui         $t5, 0x807B
    ctx->r13 = S32(RELOC_HI16(856, 0XAE8) << 16);
    // 0x807AC018: addiu       $t5, $t5, -0x3AC8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(856, 0XAE8));
    // 0x807AC01C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x807AC020: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x807AC024: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // 0x807AC028: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x807AC02C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x807AC030: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x807AC034: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x807AC038: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x807AC03C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x807AC040: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x807AC044: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x807AC048: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x807AC04C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x807AC050: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x807AC054: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x807AC058: sw          $t3, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r11;
    // 0x807AC05C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x807AC060: sw          $t4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r12;
    // 0x807AC064: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x807AC068: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x807AC06C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x807AC070: sw          $t7, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r15;
    // 0x807AC074: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x807AC078: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
    // 0x807AC07C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x807AC080: sw          $t7, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r15;
    // 0x807AC084: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x807AC088: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x807AC08C: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x807AC090: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x807AC094: sh          $a2, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r6;
    // 0x807AC098: sh          $a1, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r5;
    // 0x807AC09C: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x807AC0A0: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x807AC0A4: sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // 0x807AC0A8: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
    // 0x807AC0AC: sh          $v1, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r3;
    // 0x807AC0B0: jr          $ra
    // 0x807AC0B4: sh          $v1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r3;
    return;
    // 0x807AC0B4: sh          $v1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8043B590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B590: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B594: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043B598: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8043B59C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8043B5A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043B5A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043B5A8: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8043B5AC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043B5B0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8043B5B4: nop

    // 0x8043B5B8: bc1fl       L_8043B5D0
    if (!c1cs) {
        // 0x8043B5BC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8043B5D0;
    }
    goto skip_0;
    // 0x8043B5BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x8043B5C0: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8043B5C4: jr          $ra
    // 0x8043B5C8: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8043B5C8: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8043B5CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8043B5D0:
    // 0x8043B5D0: nop

    // 0x8043B5D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8043B5D8: nop

    // 0x8043B5DC: bc1f        L_8043B5EC
    if (!c1cs) {
        // 0x8043B5E0: nop
    
            goto L_8043B5EC;
    }
    // 0x8043B5E0: nop

    // 0x8043B5E4: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8043B5E8: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_8043B5EC:
    // 0x8043B5EC: jr          $ra
    // 0x8043B5F0: nop

    return;
    // 0x8043B5F0: nop

;}
RECOMP_FUNC void func_8069D12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D12C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8069D130: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8069D134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D13C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069D140: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8069D144: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8069D148: beq         $t8, $zero, L_8069D158
    if (ctx->r24 == 0) {
        // 0x8069D14C: nop
    
            goto L_8069D158;
    }
    // 0x8069D14C: nop

    // 0x8069D150: jal         0x8069CD84
    // 0x8069D154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8069CD84(rdram, ctx);
        goto after_0;
    // 0x8069D154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_8069D158:
    // 0x8069D158: jal         0x80045BD8
    // 0x8069D15C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8069D15C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8069D160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D168: jr          $ra
    // 0x8069D16C: nop

    return;
    // 0x8069D16C: nop

;}
RECOMP_FUNC void func_8007BEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BEE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007BEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007BEF0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8007BEF4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8007BEF8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8007BEFC: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8007BF00: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8007BF04: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8007BF08: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8007BF0C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007BF10: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BF14: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007BF18: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8007BF1C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8007BF20: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8007BF24: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BF28: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8007BF2C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8007BF30: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8007BF34: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8007BF38: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8007BF3C: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8007BF40: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8007BF44: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BF48: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007BF4C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007BF50: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8007BF54: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x8007BF58: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8007BF5C: lbu         $a2, 0x1C($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X1C);
    // 0x8007BF60: jal         0x80077338
    // 0x8007BF64: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x8007BF64: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007BF68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8007BF6C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BF70: lw          $t1, 0x14($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X14);
    // 0x8007BF74: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007BF78: beql        $t1, $zero, L_8007BFD4
    if (ctx->r9 == 0) {
        // 0x8007BF7C: lw          $v0, 0x18($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X18);
            goto L_8007BFD4;
    }
    goto skip_0;
    // 0x8007BF7C: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    skip_0:
    // 0x8007BF80: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8007BF84: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x8007BF88: lui         $at, 0xBC00
    ctx->r1 = S32(0XBC00 << 16);
    // 0x8007BF8C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8007BF90: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8007BF94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007BF98: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8007BF9C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8007BFA0: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8007BFA4: ori         $t2, $t1, 0x6
    ctx->r10 = ctx->r9 | 0X6;
    // 0x8007BFA8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BFAC: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x8007BFB0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8007BFB4: lw          $t3, 0x10($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X10);
    // 0x8007BFB8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007BFBC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8007BFC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007BFC4: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8007BFC8: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8007BFCC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BFD0: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
L_8007BFD4:
    // 0x8007BFD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BFD8: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8007BFDC: beq         $v0, $zero, L_8007BFF8
    if (ctx->r2 == 0) {
        // 0x8007BFE0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007BFF8;
    }
    // 0x8007BFE0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007BFE4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007BFE8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8007BFEC: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8007BFF0: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8007BFF4: sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
L_8007BFF8:
    // 0x8007BFF8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BFFC: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8007C000: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8007C004: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8007C008: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8007C00C: lw          $t5, 0x10($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X10);
    // 0x8007C010: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8007C014: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8007C018: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007C01C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8007C020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C024: jr          $ra
    // 0x8007C028: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007C028: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8007C02C: nop

;}
RECOMP_FUNC void func_804F46E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F46E4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x804F46E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F46EC: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x804F46F0: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x804F46F4: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x804F46F8: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x804F46FC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804F4700: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F4704: lw          $v1, 0x174($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X174);
    // 0x804F4708: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x804F470C: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804F4710: lwc1        $f8, 0x60($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X60);
    // 0x804F4714: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x804F4718: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804F471C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804F4720: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804F4724: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804F4728: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x804F472C: lwc1        $f4, 0x74($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X74);
    // 0x804F4730: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x804F4734: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x804F4738: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x804F473C: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x804F4740: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x804F4744: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x804F4748: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804F474C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x804F4750: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x804F4754: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x804F4758: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x804F475C: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x804F4760: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x804F4764: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x804F4768: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804F476C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804F4770: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x804F4774: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x804F4778: lh          $t2, 0xE($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XE);
    // 0x804F477C: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x804F4780: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x804F4784: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x804F4788: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x804F478C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804F4790: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x804F4794: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x804F4798: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
    // 0x804F479C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x804F47A0: bnel        $t4, $zero, L_804F47BC
    if (ctx->r12 != 0) {
        // 0x804F47A4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_804F47BC;
    }
    goto skip_0;
    // 0x804F47A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x804F47A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804F47AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804F47B0: b           L_804F47C4
    // 0x804F47B4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
        goto L_804F47C4;
    // 0x804F47B4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x804F47B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_804F47BC:
    // 0x804F47BC: nop

    // 0x804F47C0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
L_804F47C4:
    // 0x804F47C4: jal         0x80047AB8
    // 0x804F47C8: sw          $a3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x804F47C8: sw          $a3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r7;
    after_0:
    // 0x804F47CC: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x804F47D0: jal         0x80047AB8
    // 0x804F47D4: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x804F47D4: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    after_1:
    // 0x804F47D8: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F47DC: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F47E0: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x804F47E4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804F47E8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804F47EC: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x804F47F0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804F47F4: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x804F47F8: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804F47FC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804F4800: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804F4804: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x804F4808: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804F480C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804F4810: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x804F4814: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x804F4818: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804F481C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x804F4820: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x804F4824: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x804F4828: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x804F482C: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x804F4830: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x804F4834: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804F4838: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x804F483C: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x804F4840: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x804F4844: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x804F4848: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x804F484C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x804F4850: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804F4854: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x804F4858: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x804F485C: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804F4860: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x804F4864: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804F4868: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x804F486C: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x804F4870: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x804F4874: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x804F4878: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804F487C: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x804F4880: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x804F4884: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x804F4888: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804F488C: jal         0x80065954
    // 0x804F4890: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x804F4890: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x804F4894: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804F4898: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F489C: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F48A0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x804F48A4: nop

    // 0x804F48A8: bc1tl       L_804F48FC
    if (c1cs) {
        // 0x804F48AC: lwc1        $f0, 0x5C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_804F48FC;
    }
    goto skip_1;
    // 0x804F48AC: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x804F48B0: jal         0x80065954
    // 0x804F48B4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x804F48B4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x804F48B8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804F48BC: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F48C0: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F48C4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804F48C8: nop

    // 0x804F48CC: bc1tl       L_804F48FC
    if (c1cs) {
        // 0x804F48D0: lwc1        $f0, 0x5C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_804F48FC;
    }
    goto skip_2;
    // 0x804F48D0: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x804F48D4: jal         0x80065954
    // 0x804F48D8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x804F48D8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x804F48DC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804F48E0: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F48E4: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F48E8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804F48EC: nop

    // 0x804F48F0: bc1fl       L_804F4B18
    if (!c1cs) {
        // 0x804F48F4: lw          $t5, 0xA4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA4);
            goto L_804F4B18;
    }
    goto skip_3;
    // 0x804F48F4: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    skip_3:
    // 0x804F48F8: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
L_804F48FC:
    // 0x804F48FC: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804F4900: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804F4904: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x804F4908: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804F490C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x804F4910: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804F4914: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804F4918: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804F491C: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x804F4920: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804F4924: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x804F4928: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x804F492C: mul.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x804F4930: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804F4934: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x804F4938: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x804F493C: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x804F4940: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x804F4944: sub.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x804F4948: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x804F494C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804F4950: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x804F4954: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x804F4958: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x804F495C: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x804F4960: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x804F4964: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x804F4968: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x804F496C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x804F4970: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x804F4974: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804F4978: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x804F497C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804F4980: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x804F4984: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x804F4988: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x804F498C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x804F4990: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804F4994: mul.s       $f10, $f14, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x804F4998: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x804F499C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x804F49A0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804F49A4: jal         0x80065954
    // 0x804F49A8: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x804F49A8: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x804F49AC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804F49B0: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F49B4: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F49B8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804F49BC: nop

    // 0x804F49C0: bc1tl       L_804F4A14
    if (c1cs) {
        // 0x804F49C4: lwc1        $f0, 0x5C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_804F4A14;
    }
    goto skip_4;
    // 0x804F49C4: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    skip_4:
    // 0x804F49C8: jal         0x80065954
    // 0x804F49CC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x804F49CC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x804F49D0: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804F49D4: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F49D8: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F49DC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804F49E0: nop

    // 0x804F49E4: bc1tl       L_804F4A14
    if (c1cs) {
        // 0x804F49E8: lwc1        $f0, 0x5C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_804F4A14;
    }
    goto skip_5;
    // 0x804F49E8: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    skip_5:
    // 0x804F49EC: jal         0x80065954
    // 0x804F49F0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x804F49F0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x804F49F4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804F49F8: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(273, 0X20764) << 16);
    // 0x804F49FC: addiu       $v0, $v0, 0x49F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(273, 0X20764));
    // 0x804F4A00: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804F4A04: nop

    // 0x804F4A08: bc1fl       L_804F4B18
    if (!c1cs) {
        // 0x804F4A0C: lw          $t5, 0xA4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA4);
            goto L_804F4B18;
    }
    goto skip_6;
    // 0x804F4A0C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    skip_6:
    // 0x804F4A10: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
L_804F4A14:
    // 0x804F4A14: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x804F4A18: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804F4A1C: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x804F4A20: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804F4A24: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x804F4A28: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804F4A2C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x804F4A30: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x804F4A34: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x804F4A38: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804F4A3C: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x804F4A40: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x804F4A44: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x804F4A48: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804F4A4C: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x804F4A50: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x804F4A54: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x804F4A58: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x804F4A5C: sub.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x804F4A60: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x804F4A64: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804F4A68: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x804F4A6C: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x804F4A70: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x804F4A74: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x804F4A78: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x804F4A7C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x804F4A80: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804F4A84: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x804F4A88: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x804F4A8C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804F4A90: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804F4A94: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804F4A98: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x804F4A9C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x804F4AA0: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x804F4AA4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x804F4AA8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804F4AAC: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x804F4AB0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x804F4AB4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x804F4AB8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804F4ABC: jal         0x80065954
    // 0x804F4AC0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    func_80065954(rdram, ctx);
        goto after_8;
    // 0x804F4AC0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x804F4AC4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804F4AC8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804F4ACC: nop

    // 0x804F4AD0: bc1tl       L_804F4B14
    if (c1cs) {
        // 0x804F4AD4: sw          $zero, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = 0;
            goto L_804F4B14;
    }
    goto skip_7;
    // 0x804F4AD4: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    skip_7:
    // 0x804F4AD8: jal         0x80065954
    // 0x804F4ADC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_80065954(rdram, ctx);
        goto after_9;
    // 0x804F4ADC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x804F4AE0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804F4AE4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804F4AE8: nop

    // 0x804F4AEC: bc1tl       L_804F4B14
    if (c1cs) {
        // 0x804F4AF0: sw          $zero, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = 0;
            goto L_804F4B14;
    }
    goto skip_8;
    // 0x804F4AF0: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    skip_8:
    // 0x804F4AF4: jal         0x80065954
    // 0x804F4AF8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    func_80065954(rdram, ctx);
        goto after_10;
    // 0x804F4AF8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x804F4AFC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804F4B00: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x804F4B04: nop

    // 0x804F4B08: bc1fl       L_804F4B18
    if (!c1cs) {
        // 0x804F4B0C: lw          $t5, 0xA4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA4);
            goto L_804F4B18;
    }
    goto skip_9;
    // 0x804F4B0C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    skip_9:
    // 0x804F4B10: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
L_804F4B14:
    // 0x804F4B14: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
L_804F4B18:
    // 0x804F4B18: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x804F4B1C: beql        $t5, $zero, L_804F4BD8
    if (ctx->r13 == 0) {
        // 0x804F4B20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804F4BD8;
    }
    goto skip_10;
    // 0x804F4B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x804F4B24: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x804F4B28: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804F4B2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x804F4B30: bne         $t7, $at, L_804F4B50
    if (ctx->r15 != ctx->r1) {
        // 0x804F4B34: lw          $t8, 0xAC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XAC);
            goto L_804F4B50;
    }
    // 0x804F4B34: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x804F4B38: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x804F4B3C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x804F4B40: jal         0x8002F6E4
    // 0x804F4B44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_11;
    // 0x804F4B44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x804F4B48: b           L_804F4BD8
    // 0x804F4B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804F4BD8;
    // 0x804F4B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F4B50:
    // 0x804F4B50: lbu         $t9, 0x18($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X18);
    // 0x804F4B54: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x804F4B58: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x804F4B5C: bnel        $t9, $at, L_804F4BD8
    if (ctx->r25 != ctx->r1) {
        // 0x804F4B60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804F4BD8;
    }
    goto skip_11;
    // 0x804F4B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x804F4B64: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x804F4B68: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x804F4B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804F4B70: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x804F4B74: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x804F4B78: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x804F4B7C: jalr        $t9
    // 0x804F4B80: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x804F4B80: nop

    after_12:
    // 0x804F4B84: jal         0x800447C8
    // 0x804F4B88: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    func_800447C8(rdram, ctx);
        goto after_13;
    // 0x804F4B88: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_13:
    // 0x804F4B8C: jal         0x804F57E4
    // 0x804F4B90: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    func_804F57E4(rdram, ctx);
        goto after_14;
    // 0x804F4B90: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_14:
    // 0x804F4B94: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x804F4B98: lw          $a0, 0x34($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X34);
    // 0x804F4B9C: jal         0x80067BBC
    // 0x804F4BA0: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_15;
    // 0x804F4BA0: lw          $a1, 0x38($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X38);
    after_15:
    // 0x804F4BA4: addiu       $a0, $zero, 0x208
    ctx->r4 = ADD32(0, 0X208);
    // 0x804F4BA8: jal         0x80067818
    // 0x804F4BAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_16;
    // 0x804F4BAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x804F4BB0: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x804F4BB4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804F4BB8: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x804F4BBC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804F4BC0: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x804F4BC4: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x804F4BC8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804F4BCC: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x804F4BD0: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    // 0x804F4BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F4BD8:
    // 0x804F4BD8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x804F4BDC: jr          $ra
    // 0x804F4BE0: nop

    return;
    // 0x804F4BE0: nop

;}
RECOMP_FUNC void func_8052171C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052171C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80521720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521724: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(309, 0X464) << 16);
    // 0x80521728: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8052172C: lwc1        $f4, 0x1B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(309, 0X464));
    // 0x80521730: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80521734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80521738: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8052173C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80521740: nop

    // 0x80521744: bc1fl       L_80521764
    if (!c1cs) {
        // 0x80521748: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80521764;
    }
    goto skip_0;
    // 0x80521748: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x8052174C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80521750: jal         0x805218D8
    // 0x80521754: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_805218D8(rdram, ctx);
        goto after_0;
    // 0x80521754: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80521758: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8052175C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80521760: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80521764:
    // 0x80521764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80521768: nop

    // 0x8052176C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80521770: nop

    // 0x80521774: bc1fl       L_805217B0
    if (!c1cs) {
        // 0x80521778: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_805217B0;
    }
    goto skip_1;
    // 0x80521778: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_1:
    // 0x8052177C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80521780: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80521784: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80521788: lh          $t7, 0x12($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X12);
    // 0x8052178C: bnel        $t7, $zero, L_805217B0
    if (ctx->r15 != 0) {
        // 0x80521790: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_805217B0;
    }
    goto skip_2;
    // 0x80521790: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_2:
    // 0x80521794: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x80521798: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8052179C: jal         0x8005FDC4
    // 0x805217A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x805217A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x805217A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805217A8: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805217AC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_805217B0:
    // 0x805217B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805217B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805217B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805217BC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805217C0: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x805217C4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x805217C8: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x805217CC: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x805217D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805217D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805217D8: jr          $ra
    // 0x805217DC: nop

    return;
    // 0x805217DC: nop

;}
RECOMP_FUNC void func_8044B07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B07C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044B080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B084: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044B088: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044B08C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044B090: jal         0x8044A558
    // 0x8044B094: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044B094: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x8044B098: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B09C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044B0A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044B0A4: bne         $v0, $zero, L_8044B0BC
    if (ctx->r2 != 0) {
        // 0x8044B0A8: nop
    
            goto L_8044B0BC;
    }
    // 0x8044B0A8: nop

    // 0x8044B0AC: jal         0x804466CC
    // 0x8044B0B0: nop

    func_804466CC(rdram, ctx);
        goto after_1;
    // 0x8044B0B0: nop

    after_1:
    // 0x8044B0B4: b           L_8044B0E0
    // 0x8044B0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B0E0;
    // 0x8044B0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B0BC:
    // 0x8044B0BC: bne         $v0, $at, L_8044B0D4
    if (ctx->r2 != ctx->r1) {
        // 0x8044B0C0: nop
    
            goto L_8044B0D4;
    }
    // 0x8044B0C0: nop

    // 0x8044B0C4: jal         0x80446704
    // 0x8044B0C8: nop

    func_80446704(rdram, ctx);
        goto after_2;
    // 0x8044B0C8: nop

    after_2:
    // 0x8044B0CC: b           L_8044B0E0
    // 0x8044B0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B0E0;
    // 0x8044B0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B0D4:
    // 0x8044B0D4: jal         0x80446758
    // 0x8044B0D8: nop

    func_80446758(rdram, ctx);
        goto after_3;
    // 0x8044B0D8: nop

    after_3:
    // 0x8044B0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B0E0:
    // 0x8044B0E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044B0E4: jr          $ra
    // 0x8044B0E8: nop

    return;
    // 0x8044B0E8: nop

;}
RECOMP_FUNC void func_806F1644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1644: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806F1648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F164C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806F1650: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806F1654: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BD0) << 16);
    // 0x806F1658: lwc1        $f10, 0x3150($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BD0));
    // 0x806F165C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806F1660: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F1664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F1668: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806F166C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806F1670: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806F1674: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806F1678: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806F167C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F1680: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F1684: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F1688: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806F168C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x806F1690: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806F1694: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806F1698: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806F169C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806F16A0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x806F16A4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x806F16A8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806F16AC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806F16B0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806F16B4: jalr        $t9
    // 0x806F16B8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806F16B8: nop

    after_0:
    // 0x806F16BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F16C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806F16C4: jr          $ra
    // 0x806F16C8: nop

    return;
    // 0x806F16C8: nop

;}
RECOMP_FUNC void func_80475FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475FC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475FC4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475FC8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475FCC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475FD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475FD4: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26EF8) << 16);
    // 0x80475FD8: addiu       $a2, $a2, -0x4948
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26EF8));
    // 0x80475FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80475FE0: jal         0x80475C4C
    // 0x80475FE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475C4C(rdram, ctx);
        goto after_0;
    // 0x80475FE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475FEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475FF0: jr          $ra
    // 0x80475FF4: nop

    return;
    // 0x80475FF4: nop

    // 0x80475FF8: nop

    // 0x80475FFC: nop

;}
RECOMP_FUNC void func_80051E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051E60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051E64: jal         0x80064E84
    // 0x80051E68: lw          $a0, 0x40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80051E68: lw          $a0, 0x40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40);
    after_0:
    // 0x80051E6C: jal         0x80064E84
    // 0x80051E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80051E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80051E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051E7C: jr          $ra
    // 0x80051E80: nop

    return;
    // 0x80051E80: nop

;}
RECOMP_FUNC void func_8069D590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D590: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8069D594: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(574, 0X38C) << 16);
    // 0x8069D598: addiu       $t6, $t6, -0x26F4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(574, 0X38C));
    // 0x8069D59C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8069D5A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8069D5A4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x8069D5A8: jr          $ra
    // 0x8069D5AC: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    return;
    // 0x8069D5AC: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
;}
