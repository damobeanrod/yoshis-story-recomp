#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_805DA464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA46C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DA470: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x805DA474: beql        $t6, $zero, L_805DA4D4
    if (ctx->r14 == 0) {
        // 0x805DA478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805DA4D4;
    }
    goto skip_0;
    // 0x805DA478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805DA47C: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x805DA480: blez        $v1, L_805DA490
    if (SIGNED(ctx->r3) <= 0) {
        // 0x805DA484: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_805DA490;
    }
    // 0x805DA484: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x805DA488: b           L_805DA4D0
    // 0x805DA48C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
        goto L_805DA4D0;
    // 0x805DA48C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_805DA490:
    // 0x805DA490: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x805DA494: addiu       $at, $zero, 0x4538
    ctx->r1 = ADD32(0, 0X4538);
    // 0x805DA498: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x805DA49C: bne         $t8, $at, L_805DA4AC
    if (ctx->r24 != ctx->r1) {
        // 0x805DA4A0: addiu       $t0, $zero, 0x78
        ctx->r8 = ADD32(0, 0X78);
            goto L_805DA4AC;
    }
    // 0x805DA4A0: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x805DA4A4: b           L_805DA4B0
    // 0x805DA4A8: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
        goto L_805DA4B0;
    // 0x805DA4A8: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
L_805DA4AC:
    // 0x805DA4AC: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
L_805DA4B0:
    // 0x805DA4B0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x805DA4B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x805DA4B8: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x805DA4BC: bne         $at, $zero, L_805DA4C8
    if (ctx->r1 != 0) {
        // 0x805DA4C0: sw          $t2, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r10;
            goto L_805DA4C8;
    }
    // 0x805DA4C0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x805DA4C4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_805DA4C8:
    // 0x805DA4C8: jal         0x805DA204
    // 0x805DA4CC: nop

    func_805DA204(rdram, ctx);
        goto after_0;
    // 0x805DA4CC: nop

    after_0:
L_805DA4D0:
    // 0x805DA4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DA4D4:
    // 0x805DA4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DA4D8: jr          $ra
    // 0x805DA4DC: nop

    return;
    // 0x805DA4DC: nop

;}
RECOMP_FUNC void func_806FCD58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FCD58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806FCD5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FCD60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FCD64: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x806FCD68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806FCD6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FCD70: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x806FCD74: beq         $at, $zero, L_806FCDF4
    if (ctx->r1 == 0) {
        // 0x806FCD78: addiu       $a0, $a0, 0xC4
        ctx->r4 = ADD32(ctx->r4, 0XC4);
            goto L_806FCDF4;
    }
    // 0x806FCD78: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806FCD7C: jal         0x80048F84
    // 0x806FCD80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806FCD80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x806FCD84: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x806FCD88: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x806FCD8C: beql        $at, $zero, L_806FCDE0
    if (ctx->r1 == 0) {
        // 0x806FCD90: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806FCDE0;
    }
    goto skip_0;
    // 0x806FCD90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x806FCD94: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x806FCD98: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x806FCD9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FCDA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806FCDA4: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806FCDA8: jal         0x80066DE4
    // 0x806FCDAC: nop

    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806FCDAC: nop

    after_1:
    // 0x806FCDB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FCDB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806FCDB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806FCDBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FCDC0: nop

    // 0x806FCDC4: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806FCDC8: sub.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x806FCDCC: add.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x806FCDD0: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x806FCDD4: b           L_806FCF24
    // 0x806FCDD8: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
        goto L_806FCF24;
    // 0x806FCDD8: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x806FCDDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_806FCDE0:
    // 0x806FCDE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806FCDE4: nop

    // 0x806FCDE8: swc1        $f12, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f12.u32l;
    // 0x806FCDEC: b           L_806FCF24
    // 0x806FCDF0: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
        goto L_806FCF24;
    // 0x806FCDF0: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
L_806FCDF4:
    // 0x806FCDF4: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x806FCDF8: beq         $at, $zero, L_806FCE68
    if (ctx->r1 == 0) {
        // 0x806FCDFC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_806FCE68;
    }
    // 0x806FCDFC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x806FCE00: bnel        $v1, $at, L_806FCE20
    if (ctx->r3 != ctx->r1) {
        // 0x806FCE04: addiu       $t6, $v1, -0x14
        ctx->r14 = ADD32(ctx->r3, -0X14);
            goto L_806FCE20;
    }
    goto skip_1;
    // 0x806FCE04: addiu       $t6, $v1, -0x14
    ctx->r14 = ADD32(ctx->r3, -0X14);
    skip_1:
    // 0x806FCE08: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806FCE0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806FCE10: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x806FCE14: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x806FCE18: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x806FCE1C: addiu       $t6, $v1, -0x14
    ctx->r14 = ADD32(ctx->r3, -0X14);
L_806FCE20:
    // 0x806FCE20: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x806FCE24: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x806FCE28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806FCE2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806FCE30: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806FCE34: jal         0x80066DE4
    // 0x806FCE38: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x806FCE38: nop

    after_2:
    // 0x806FCE3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FCE40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806FCE44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806FCE48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FCE4C: nop

    // 0x806FCE50: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x806FCE54: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x806FCE58: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x806FCE5C: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x806FCE60: b           L_806FCF24
    // 0x806FCE64: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
        goto L_806FCF24;
    // 0x806FCE64: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
L_806FCE68:
    // 0x806FCE68: jal         0x8004700C
    // 0x806FCE6C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_8004700C(rdram, ctx);
        goto after_3;
    // 0x806FCE6C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_3:
    // 0x806FCE70: beql        $v0, $zero, L_806FCF28
    if (ctx->r2 == 0) {
        // 0x806FCE74: lw          $t3, 0x1E0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1E0);
            goto L_806FCF28;
    }
    goto skip_2;
    // 0x806FCE74: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
    skip_2:
    // 0x806FCE78: lbu         $v1, 0x18($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X18);
    // 0x806FCE7C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x806FCE80: beq         $v1, $at, L_806FCEFC
    if (ctx->r3 == ctx->r1) {
        // 0x806FCE84: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_806FCEFC;
    }
    // 0x806FCE84: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806FCE88: beql        $v1, $at, L_806FCF00
    if (ctx->r3 == ctx->r1) {
        // 0x806FCE8C: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_806FCF00;
    }
    goto skip_3;
    // 0x806FCE8C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    skip_3:
    // 0x806FCE90: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806FCE94: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806FCE98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806FCE9C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x806FCEA0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806FCEA4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x806FCEA8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x806FCEAC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806FCEB0: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x806FCEB4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806FCEB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806FCEBC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x806FCEC0: lwc1        $f4, 0x38($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X38);
    // 0x806FCEC4: lw          $t0, 0xA68($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA68);
    // 0x806FCEC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x806FCECC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806FCED0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x806FCED4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x806FCED8: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x806FCEDC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x806FCEE0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x806FCEE4: lw          $t9, 0x20($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X20);
    // 0x806FCEE8: jalr        $t9
    // 0x806FCEEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x806FCEEC: nop

    after_4:
    // 0x806FCEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FCEF4: jal         0x806FCFE0
    // 0x806FCEF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_806FCFE0(rdram, ctx);
        goto after_5;
    // 0x806FCEF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_806FCEFC:
    // 0x806FCEFC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
L_806FCF00:
    // 0x806FCF00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FCF04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FCF08: jal         0x806FCFE0
    // 0x806FCF0C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    func_806FCFE0(rdram, ctx);
        goto after_6;
    // 0x806FCF0C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    after_6:
    // 0x806FCF10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FCF14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806FCF18: nop

    // 0x806FCF1C: swc1        $f12, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f12.u32l;
    // 0x806FCF20: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
L_806FCF24:
    // 0x806FCF24: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
L_806FCF28:
    // 0x806FCF28: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806FCF2C: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x806FCF30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FCF34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FCF38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x806FCF3C: jr          $ra
    // 0x806FCF40: nop

    return;
    // 0x806FCF40: nop

;}
RECOMP_FUNC void func_8004661C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004661C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046620: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80046624: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80046628: lw          $a0, -0x7784($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7784);
    // 0x8004662C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046630: jal         0x800579E4
    // 0x80046634: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800579E4(rdram, ctx);
        goto after_0;
    // 0x80046634: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80046638: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x8004663C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80046640: bne         $v0, $at, L_80046660
    if (ctx->r2 != ctx->r1) {
        // 0x80046644: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80046660;
    }
    // 0x80046644: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80046648: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004664C: addiu       $a0, $a0, 0x710
    ctx->r4 = ADD32(ctx->r4, 0X710);
    // 0x80046650: jal         0x80071380
    // 0x80046654: addiu       $a1, $zero, 0x52C
    ctx->r5 = ADD32(0, 0X52C);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80046654: addiu       $a1, $zero, 0x52C
    ctx->r5 = ADD32(0, 0X52C);
    after_1:
    // 0x80046658: b           L_8004666C
    // 0x8004665C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004666C;
    // 0x8004665C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046660:
    // 0x80046660: jal         0x80057B28
    // 0x80046664: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80057B28(rdram, ctx);
        goto after_2;
    // 0x80046664: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80046668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004666C:
    // 0x8004666C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80046674: jr          $ra
    // 0x80046678: nop

    return;
    // 0x80046678: nop

;}
RECOMP_FUNC void func_80445A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445A5C: jal         0x800677F8
    // 0x80445A60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445A60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80445A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445A6C: jr          $ra
    // 0x80445A70: nop

    return;
    // 0x80445A70: nop

;}
RECOMP_FUNC void func_80073D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073D58: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x80073D5C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80073D60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80073D64: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80073D68: sw          $a1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r5;
    // 0x80073D6C: sw          $a2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r6;
    // 0x80073D70: sw          $a3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r7;
    // 0x80073D74: lw          $t6, 0x114($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X114);
    // 0x80073D78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80073D7C: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    // 0x80073D80: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80073D84: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x80073D88: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x80073D8C: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
    // 0x80073D90: lbu         $a3, 0x9($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9);
    // 0x80073D94: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x80073D98: beq         $a3, $at, L_80073DCC
    if (ctx->r7 == ctx->r1) {
        // 0x80073D9C: nop
    
            goto L_80073DCC;
    }
    // 0x80073D9C: nop

    // 0x80073DA0: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x80073DA4: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80073DA8: lbu         $a2, 0x8($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X8);
    // 0x80073DAC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80073DB0: addiu       $a0, $sp, 0x10C
    ctx->r4 = ADD32(ctx->r29, 0X10C);
    // 0x80073DB4: lw          $a1, 0x118($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X118);
    // 0x80073DB8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80073DBC: jal         0x80077084
    // 0x80073DC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80077084(rdram, ctx);
        goto after_0;
    // 0x80073DC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x80073DC4: b           L_80073F94
    // 0x80073DC8: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
        goto L_80073F94;
    // 0x80073DC8: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
L_80073DCC:
    // 0x80073DCC: lw          $v0, 0x10C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10C);
    // 0x80073DD0: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80073DD4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80073DD8: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80073DDC: lbu         $t7, 0x8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X8);
    // 0x80073DE0: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80073DE4: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80073DE8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80073DEC: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x80073DF0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80073DF4: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x80073DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80073DFC: lw          $v1, 0x10C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10C);
    // 0x80073E00: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80073E04: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80073E08: lbu         $t7, 0x8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X8);
    // 0x80073E0C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80073E10: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80073E14: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80073E18: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x80073E1C: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x80073E20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80073E24: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    // 0x80073E28: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80073E2C: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x80073E30: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80073E34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80073E38: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80073E3C: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x80073E40: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80073E44: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80073E48: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x80073E4C: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x80073E50: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80073E54: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80073E58: lw          $a3, 0x124($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X124);
    // 0x80073E5C: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80073E60: mflo        $a1
    ctx->r5 = lo;
    // 0x80073E64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80073E68: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80073E6C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80073E70: slti        $at, $a1, 0x7FF
    ctx->r1 = SIGNED(ctx->r5) < 0X7FF ? 1 : 0;
    // 0x80073E74: beq         $at, $zero, L_80073E84
    if (ctx->r1 == 0) {
        // 0x80073E78: nop
    
            goto L_80073E84;
    }
    // 0x80073E78: nop

    // 0x80073E7C: b           L_80073E84
    // 0x80073E80: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_80073E84;
    // 0x80073E80: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80073E84:
    // 0x80073E84: bgez        $a3, L_80073E94
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80073E88: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_80073E94;
    }
    // 0x80073E88: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x80073E8C: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x80073E90: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80073E94:
    // 0x80073E94: bgtz        $v0, L_80073EA4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80073E98: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80073EA4;
    }
    // 0x80073E98: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80073E9C: b           L_80073EA4
    // 0x80073EA0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80073EA4;
    // 0x80073EA0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80073EA4:
    // 0x80073EA4: bgtz        $v0, L_80073EB4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80073EA8: addiu       $t7, $t0, 0x7FF
        ctx->r15 = ADD32(ctx->r8, 0X7FF);
            goto L_80073EB4;
    }
    // 0x80073EA8: addiu       $t7, $t0, 0x7FF
    ctx->r15 = ADD32(ctx->r8, 0X7FF);
    // 0x80073EAC: b           L_80073EB8
    // 0x80073EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80073EB8;
    // 0x80073EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80073EB4:
    // 0x80073EB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80073EB8:
    // 0x80073EB8: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x80073EBC: mflo        $t8
    ctx->r24 = lo;
    // 0x80073EC0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80073EC4: bne         $a1, $zero, L_80073ED0
    if (ctx->r5 != 0) {
        // 0x80073EC8: nop
    
            goto L_80073ED0;
    }
    // 0x80073EC8: nop

    // 0x80073ECC: break       7
    do_break(2147958476);
L_80073ED0:
    // 0x80073ED0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80073ED4: bne         $a1, $at, L_80073EE8
    if (ctx->r5 != ctx->r1) {
        // 0x80073ED8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80073EE8;
    }
    // 0x80073ED8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80073EDC: bne         $t7, $at, L_80073EE8
    if (ctx->r15 != ctx->r1) {
        // 0x80073EE0: nop
    
            goto L_80073EE8;
    }
    // 0x80073EE0: nop

    // 0x80073EE4: break       6
    do_break(2147958500);
L_80073EE8:
    // 0x80073EE8: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x80073EEC: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80073EF0: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x80073EF4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80073EF8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80073EFC: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x80073F00: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80073F04: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80073F08: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80073F0C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80073F10: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80073F14: lw          $v1, 0x10C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10C);
    // 0x80073F18: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80073F1C: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
    // 0x80073F20: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x80073F24: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80073F28: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80073F2C: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x80073F30: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80073F34: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x80073F38: addiu       $t8, $a3, 0x7
    ctx->r24 = ADD32(ctx->r7, 0X7);
    // 0x80073F3C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80073F40: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80073F44: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x80073F48: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80073F4C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80073F50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80073F54: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    // 0x80073F58: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80073F5C: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80073F60: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80073F64: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80073F68: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80073F6C: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80073F70: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80073F74: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80073F78: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80073F7C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80073F80: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80073F84: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80073F88: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80073F8C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80073F90: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
L_80073F94:
    // 0x80073F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80073F98: lw          $t8, 0x11C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X11C);
    // 0x80073F9C: beq         $t6, $at, L_80073FB4
    if (ctx->r14 == ctx->r1) {
        // 0x80073FA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80073FB4;
    }
    // 0x80073FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073FA4: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80073FA8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80073FAC: b           L_80073FC0
    // 0x80073FB0: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
        goto L_80073FC0;
    // 0x80073FB0: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
L_80073FB4:
    // 0x80073FB4: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80073FB8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80073FBC: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
L_80073FC0:
    // 0x80073FC0: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80073FC4: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80073FC8: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80073FCC: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80073FD0: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80073FD4: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80073FD8: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x80073FDC: sw          $ra, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r31;
    // 0x80073FE0: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x80073FE4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80073FE8: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x80073FEC: jal         0x800734F0
    // 0x80073FF0: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    func_800734F0(rdram, ctx);
        goto after_1;
    // 0x80073FF0: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    after_1:
    // 0x80073FF4: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x80073FF8: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80073FFC: lw          $ra, 0xAC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XAC);
    // 0x80074000: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80074004: addu        $t8, $a1, $t9
    ctx->r24 = ADD32(ctx->r5, ctx->r25);
    // 0x80074008: addu        $v0, $t8, $ra
    ctx->r2 = ADD32(ctx->r24, ctx->r31);
    // 0x8007400C: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x80074010: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x80074014: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x80074018: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8007401C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80074020: lw          $v1, 0x10C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10C);
    // 0x80074024: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80074028: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8007402C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80074030: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x80074034: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80074038: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007403C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80074040: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80074044: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x80074048: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007404C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80074050: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80074054: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x80074058: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8007405C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80074060: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80074064: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x80074068: or          $t7, $t1, $t8
    ctx->r15 = ctx->r9 | ctx->r24;
    // 0x8007406C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80074070: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80074074: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x80074078: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x8007407C: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80074080: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80074084: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80074088: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8007408C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80074090: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x80074094: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x80074098: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x8007409C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800740A0: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x800740A4: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x800740A8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800740AC: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x800740B0: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x800740B4: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x800740B8: lw          $v0, 0x10C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10C);
    // 0x800740BC: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800740C0: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    // 0x800740C4: blez        $a1, L_80074148
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800740C8: addu        $t0, $a1, $t3
        ctx->r8 = ADD32(ctx->r5, ctx->r11);
            goto L_80074148;
    }
    // 0x800740C8: addu        $t0, $a1, $t3
    ctx->r8 = ADD32(ctx->r5, ctx->r11);
    // 0x800740CC: subu        $a2, $a0, $t8
    ctx->r6 = SUB32(ctx->r4, ctx->r24);
    // 0x800740D0: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800740D4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800740D8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800740DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800740E0: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x800740E4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800740E8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800740EC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800740F0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800740F4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800740F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800740FC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80074100: lw          $v1, 0x10C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10C);
    // 0x80074104: sll         $t9, $a2, 5
    ctx->r25 = S32(ctx->r6 << 5);
    // 0x80074108: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x8007410C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80074110: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80074114: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80074118: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007411C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80074120: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x80074124: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80074128: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8007412C: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x80074130: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x80074134: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80074138: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8007413C: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x80074140: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80074144: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
L_80074148:
    // 0x80074148: bltz        $a1, L_8007428C
    if (SIGNED(ctx->r5) < 0) {
        // 0x8007414C: lw          $t8, 0xB4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB4);
            goto L_8007428C;
    }
    // 0x8007414C: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x80074150: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80074154: lhu         $t4, 0xA($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XA);
    // 0x80074158: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8007415C: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80074160: subu        $t6, $t7, $t4
    ctx->r14 = SUB32(ctx->r15, ctx->r12);
    // 0x80074164: blez        $t6, L_8007428C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80074168: addu        $t0, $a0, $t3
        ctx->r8 = ADD32(ctx->r4, ctx->r11);
            goto L_8007428C;
    }
    // 0x80074168: addu        $t0, $a0, $t3
    ctx->r8 = ADD32(ctx->r4, ctx->r11);
    // 0x8007416C: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80074170: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80074174: addu        $a3, $t4, $ra
    ctx->r7 = ADD32(ctx->r12, ctx->r31);
    // 0x80074178: subu        $t1, $a0, $t9
    ctx->r9 = SUB32(ctx->r4, ctx->r25);
    // 0x8007417C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80074180: lw          $v0, 0x10C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10C);
    // 0x80074184: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80074188: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007418C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80074190: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80074194: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x80074198: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8007419C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800741A0: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800741A4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800741A8: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800741AC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800741B0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800741B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800741B8: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800741BC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800741C0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800741C4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800741C8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800741CC: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800741D0: sll         $t5, $t1, 5
    ctx->r13 = S32(ctx->r9 << 5);
    // 0x800741D4: andi        $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 & 0XFFFF;
    // 0x800741D8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800741DC: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x800741E0: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x800741E4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800741E8: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800741EC: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x800741F0: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x800741F4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800741F8: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
    // 0x800741FC: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x80074200: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80074204: lhu         $t9, 0xA($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XA);
    // 0x80074208: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8007420C: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    // 0x80074210: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80074214: subu        $v1, $t9, $t6
    ctx->r3 = SUB32(ctx->r25, ctx->r14);
    // 0x80074218: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8007421C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80074220: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x80074224: addu        $t6, $t9, $ra
    ctx->r14 = ADD32(ctx->r25, ctx->r31);
    // 0x80074228: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x8007422C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80074230: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80074234: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80074238: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x8007423C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80074240: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80074244: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80074248: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007424C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80074250: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80074254: lw          $a1, 0x10C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10C);
    // 0x80074258: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8007425C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80074260: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
    // 0x80074264: sll         $t7, $v1, 21
    ctx->r15 = S32(ctx->r3 << 21);
    // 0x80074268: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007426C: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x80074270: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80074274: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x80074278: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007427C: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x80074280: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80074284: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80074288: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
L_8007428C:
    // 0x8007428C: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x80074290: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x80074294: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80074298: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007429C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800742A0: jr          $ra
    // 0x800742A4: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x800742A4: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_80048348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004834C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048350: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048354: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80048358: jal         0x80065728
    // 0x8004835C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8004835C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80048360: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80048364: sw          $zero, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = 0;
    // 0x80048368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004836C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048370: jr          $ra
    // 0x80048374: nop

    return;
    // 0x80048374: nop

;}
RECOMP_FUNC void func_804BDF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDF84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BDF88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BDF8C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41D4) << 16);
    // 0x804BDF90: lwc1        $f4, -0x4FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41D4));
    // 0x804BDF94: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BDF98: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BDF9C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804BDFA0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BDFA4: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BDFA8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41D8) << 16);
    // 0x804BDFAC: bc1t        L_804BE034
    if (c1cs) {
        // 0x804BDFB0: lw          $v1, 0x370($t7)
        ctx->r3 = MEM_W(ctx->r15, 0X370);
            goto L_804BE034;
    }
    // 0x804BDFB0: lw          $v1, 0x370($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X370);
    // 0x804BDFB4: lwc1        $f6, -0x4F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41D8));
    // 0x804BDFB8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BDFBC: nop

    // 0x804BDFC0: bc1tl       L_804BE038
    if (c1cs) {
        // 0x804BDFC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BE038;
    }
    goto skip_0;
    // 0x804BDFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BDFC8: lh          $t8, 0x2E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDFCC: lui         $t0, 0x804C
    ctx->r8 = S32(RELOC_HI16(191, 0X3DB0) << 16);
    // 0x804BDFD0: lui         $t5, 0x804C
    ctx->r13 = S32(RELOC_HI16(191, 0X1FBC) << 16);
    // 0x804BDFD4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804BDFD8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BDFDC: lh          $t0, -0x920($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(191, 0X3DB0));
    // 0x804BDFE0: addiu       $t5, $t5, -0x2714
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(191, 0X1FBC));
    // 0x804BDFE4: sh          $t0, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r8;
    // 0x804BDFE8: lh          $t1, 0x2E($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDFEC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x804BDFF0: sh          $t2, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r10;
    // 0x804BDFF4: lh          $t3, 0x2E($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDFF8: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x804BDFFC: bnel        $at, $zero, L_804BE028
    if (ctx->r1 != 0) {
        // 0x804BE000: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_804BE028;
    }
    goto skip_1;
    // 0x804BE000: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_1:
    // 0x804BE004: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
    // 0x804BE008: sh          $zero, 0xE4($v0)
    MEM_H(0XE4, ctx->r2) = 0;
    // 0x804BE00C: lh          $t4, 0xE4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XE4);
    // 0x804BE010: sw          $t5, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r13;
    // 0x804BE014: jal         0x804BD678
    // 0x804BE018: sh          $t4, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r12;
    func_804BD678(rdram, ctx);
        goto after_0;
    // 0x804BE018: sh          $t4, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r12;
    after_0:
    // 0x804BE01C: b           L_804BE038
    // 0x804BE020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BE038;
    // 0x804BE020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BE024: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_804BE028:
    // 0x804BE028: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BE02C: nop

    // 0x804BE030: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
L_804BE034:
    // 0x804BE034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BE038:
    // 0x804BE038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BE03C: jr          $ra
    // 0x804BE040: nop

    return;
    // 0x804BE040: nop

;}
RECOMP_FUNC void func_8051789C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051789C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805178A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805178A4: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805178A8: lui         $t6, 0x8051
    ctx->r14 = S32(RELOC_HI16(288, 0X480) << 16);
    // 0x805178AC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805178B0: addiu       $t6, $t6, 0x7A00
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(288, 0X480));
    // 0x805178B4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805178B8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805178BC: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    // 0x805178C0: jal         0x805179B0
    // 0x805178C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805179B0(rdram, ctx);
        goto after_0;
    // 0x805178C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805178C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805178CC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x805178D0: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x805178D4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805178D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805178DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805178E0: jr          $ra
    // 0x805178E4: nop

    return;
    // 0x805178E4: nop

;}
RECOMP_FUNC void func_806CEC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEC44: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806CEC48: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(604, 0X3B34) << 16);
    // 0x806CEC4C: addiu       $t6, $t6, -0xDAC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(604, 0X3B34));
    // 0x806CEC50: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806CEC54: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806CEC58: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806CEC5C: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x806CEC60: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x806CEC64: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x806CEC68: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806CEC6C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806CEC70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806CEC74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806CEC78: jr          $ra
    // 0x806CEC7C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    return;
    // 0x806CEC7C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_804CBBB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CBBB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CBBB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CBBBC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804CBBC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804CBBC4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x804CBBC8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804CBBCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804CBBD0: beq         $v0, $at, L_804CBBEC
    if (ctx->r2 == ctx->r1) {
        // 0x804CBBD4: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_804CBBEC;
    }
    // 0x804CBBD4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x804CBBD8: addiu       $at, $zero, 0x4115
    ctx->r1 = ADD32(0, 0X4115);
    // 0x804CBBDC: beql        $v0, $at, L_804CBCC4
    if (ctx->r2 == ctx->r1) {
        // 0x804CBBE0: lw          $t5, 0x1F4($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X1F4);
            goto L_804CBCC4;
    }
    goto skip_0;
    // 0x804CBBE0: lw          $t5, 0x1F4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1F4);
    skip_0:
    // 0x804CBBE4: b           L_804CBD88
    // 0x804CBBE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CBD88;
    // 0x804CBBE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CBBEC:
    // 0x804CBBEC: lw          $a3, 0x1F4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1F4);
    // 0x804CBBF0: lw          $t6, 0x12EC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X12EC);
    // 0x804CBBF4: bnel        $t6, $zero, L_804CBD88
    if (ctx->r14 != 0) {
        // 0x804CBBF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CBD88;
    }
    goto skip_1;
    // 0x804CBBF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804CBBFC: lbu         $t7, 0x18($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18);
    // 0x804CBC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CBC04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804CBC08: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x804CBC0C: beq         $at, $zero, L_804CBD84
    if (ctx->r1 == 0) {
        // 0x804CBC10: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_804CBD84;
    }
    // 0x804CBC10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CBC14: jal         0x804CBA88
    // 0x804CBC18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_804CBA88(rdram, ctx);
        goto after_0;
    // 0x804CBC18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x804CBC1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804CBC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804CBC24: lbu         $t8, 0x12C9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X12C9);
    // 0x804CBC28: sw          $s0, 0x12EC($a1)
    MEM_W(0X12EC, ctx->r5) = ctx->r16;
    // 0x804CBC2C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x804CBC30: jal         0x80040C48
    // 0x804CBC34: sb          $t9, 0x12C9($a1)
    MEM_B(0X12C9, ctx->r5) = ctx->r25;
    func_80040C48(rdram, ctx);
        goto after_1;
    // 0x804CBC34: sb          $t9, 0x12C9($a1)
    MEM_B(0X12C9, ctx->r5) = ctx->r25;
    after_1:
    // 0x804CBC38: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x804CBC3C: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x804CBC40: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x804CBC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CBC48: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x804CBC4C: lw          $v0, 0x78($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X78);
    // 0x804CBC50: beql        $v0, $zero, L_804CBC64
    if (ctx->r2 == 0) {
        // 0x804CBC54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804CBC64;
    }
    goto skip_2;
    // 0x804CBC54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x804CBC58: jalr        $v0
    // 0x804CBC5C: lw          $a0, 0x108($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X108);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x804CBC5C: lw          $a0, 0x108($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X108);
    after_2:
    // 0x804CBC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_804CBC64:
    // 0x804CBC64: jal         0x804CBB50
    // 0x804CBC68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_804CBB50(rdram, ctx);
        goto after_3;
    // 0x804CBC68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x804CBC6C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1400) << 16);
    // 0x804CBC70: lwc1        $f4, -0x40C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1400));
    // 0x804CBC74: jal         0x8001D770
    // 0x804CBC78: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x804CBC78: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x804CBC7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804CBC80: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x804CBC84: jal         0x80067BF8
    // 0x804CBC88: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x804CBC88: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x804CBC8C: addiu       $a0, $zero, 0x219
    ctx->r4 = ADD32(0, 0X219);
    // 0x804CBC90: jal         0x80067818
    // 0x804CBC94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x804CBC94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x804CBC98: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x804CBC9C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CBCA0: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x804CBCA4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CBCA8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x804CBCAC: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x804CBCB0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CBCB4: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x804CBCB8: b           L_804CBD84
    // 0x804CBCBC: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
        goto L_804CBD84;
    // 0x804CBCBC: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
    // 0x804CBCC0: lw          $t5, 0x1F4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1F4);
L_804CBCC4:
    // 0x804CBCC4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x804CBCC8: lh          $t6, 0x184($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X184);
    // 0x804CBCCC: bnel        $t6, $zero, L_804CBD88
    if (ctx->r14 != 0) {
        // 0x804CBCD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CBD88;
    }
    goto skip_3;
    // 0x804CBCD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x804CBCD4: jal         0x8004700C
    // 0x804CBCD8: nop

    func_8004700C(rdram, ctx);
        goto after_7;
    // 0x804CBCD8: nop

    after_7:
    // 0x804CBCDC: lw          $t7, 0x180($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X180);
    // 0x804CBCE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CBCE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CBCE8: bne         $v0, $t7, L_804CBD04
    if (ctx->r2 != ctx->r15) {
        // 0x804CBCEC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_804CBD04;
    }
    // 0x804CBCEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804CBCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CBCF4: jal         0x804CBA88
    // 0x804CBCF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_804CBA88(rdram, ctx);
        goto after_8;
    // 0x804CBCF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x804CBCFC: b           L_804CBD10
    // 0x804CBD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_804CBD10;
    // 0x804CBD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_804CBD04:
    // 0x804CBD04: jal         0x804CBA88
    // 0x804CBD08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804CBA88(rdram, ctx);
        goto after_9;
    // 0x804CBD08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x804CBD0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_804CBD10:
    // 0x804CBD10: jal         0x804CBB50
    // 0x804CBD14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_804CBB50(rdram, ctx);
        goto after_10;
    // 0x804CBD14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x804CBD18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CBD1C: jal         0x8004700C
    // 0x804CBD20: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    func_8004700C(rdram, ctx);
        goto after_11;
    // 0x804CBD20: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    after_11:
    // 0x804CBD24: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x804CBD28: lbu         $t8, 0x12E8($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X12E8);
    // 0x804CBD2C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804CBD30: sb          $t9, 0x12E8($v1)
    MEM_B(0X12E8, ctx->r3) = ctx->r25;
    // 0x804CBD34: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x804CBD38: lh          $t0, 0x17E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X17E);
    // 0x804CBD3C: jal         0x8001D770
    // 0x804CBD40: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    func_8001D770(rdram, ctx);
        goto after_12;
    // 0x804CBD40: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    after_12:
    // 0x804CBD44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804CBD48: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x804CBD4C: jal         0x80067BF8
    // 0x804CBD50: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_13;
    // 0x804CBD50: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_13:
    // 0x804CBD54: addiu       $a0, $zero, 0x219
    ctx->r4 = ADD32(0, 0X219);
    // 0x804CBD58: jal         0x80067818
    // 0x804CBD5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_14;
    // 0x804CBD5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x804CBD60: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x804CBD64: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CBD68: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x804CBD6C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CBD70: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x804CBD74: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x804CBD78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804CBD7C: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x804CBD80: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
L_804CBD84:
    // 0x804CBD84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CBD88:
    // 0x804CBD88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804CBD8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804CBD90: jr          $ra
    // 0x804CBD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x804CBD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CBD98: nop

    // 0x804CBD9C: nop

;}
RECOMP_FUNC void func_80735B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80735B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80735B94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80735B98: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80735B9C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80735BA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80735BA4: bne         $a1, $at, L_80735BC8
    if (ctx->r5 != ctx->r1) {
        // 0x80735BA8: nop
    
            goto L_80735BC8;
    }
    // 0x80735BA8: nop

    // 0x80735BAC: jal         0x80067E78
    // 0x80735BB0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x80735BB0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80735BB4: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80735BB8: jal         0x80067F78
    // 0x80735BBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80735BBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80735BC0: b           L_80735C18
    // 0x80735BC4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80735C18;
    // 0x80735BC4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80735BC8:
    // 0x80735BC8: jal         0x80067930
    // 0x80735BCC: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x80735BCC: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_2:
    // 0x80735BD0: beq         $v0, $zero, L_80735C00
    if (ctx->r2 == 0) {
        // 0x80735BD4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80735C00;
    }
    // 0x80735BD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80735BD8: bnel        $v0, $at, L_80735C1C
    if (ctx->r2 != ctx->r1) {
        // 0x80735BDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80735C1C;
    }
    goto skip_0;
    // 0x80735BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80735BE0: jal         0x80067E78
    // 0x80735BE4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_3;
    // 0x80735BE4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x80735BE8: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80735BEC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80735BF0: jal         0x800678F0
    // 0x80735BF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x80735BF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80735BF8: b           L_80735C1C
    // 0x80735BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80735C1C;
    // 0x80735BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80735C00:
    // 0x80735C00: jal         0x80067E78
    // 0x80735C04: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_5;
    // 0x80735C04: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x80735C08: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80735C0C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80735C10: jal         0x80067838
    // 0x80735C14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x80735C14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_80735C18:
    // 0x80735C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80735C1C:
    // 0x80735C1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80735C20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80735C24: jr          $ra
    // 0x80735C28: nop

    return;
    // 0x80735C28: nop

;}
RECOMP_FUNC void func_8057FC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FC80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057FC84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057FC88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057FC8C: jal         0x80045A34
    // 0x8057FC90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8057FC90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8057FC94: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8057FC98: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8057FC9C: bne         $v0, $zero, L_8057FCAC
    if (ctx->r2 != 0) {
        // 0x8057FCA0: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_8057FCAC;
    }
    // 0x8057FCA0: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x8057FCA4: b           L_8057FCBC
    // 0x8057FCA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057FCBC;
    // 0x8057FCA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057FCAC:
    // 0x8057FCAC: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8057FCB0: jal         0x800657CC
    // 0x8057FCB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x8057FCB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8057FCB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8057FCBC:
    // 0x8057FCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057FCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057FCC4: jr          $ra
    // 0x8057FCC8: nop

    return;
    // 0x8057FCC8: nop

;}
RECOMP_FUNC void func_804338B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804338B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804338B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804338BC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804338C0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804338C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804338C8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804338CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804338D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804338D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804338D8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804338DC: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(68, 0X1C0) << 16);
    // 0x804338E0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804338E4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804338E8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804338EC: lw          $t2, 0x39F0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(68, 0X1C0));
    // 0x804338F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804338F4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804338F8: jal         0x80433918
    // 0x804338FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80433918(rdram, ctx);
        goto after_0;
    // 0x804338FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80433900: jal         0x80433974
    // 0x80433904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80433974(rdram, ctx);
        goto after_1;
    // 0x80433904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80433908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043390C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80433910: jr          $ra
    // 0x80433914: nop

    return;
    // 0x80433914: nop

;}
RECOMP_FUNC void func_806EC584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC584: lh          $v1, 0x184($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X184);
    // 0x806EC588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EC58C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806EC590: blez        $v1, L_806EC5C8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806EC594: addiu       $a2, $zero, 0x45E3
        ctx->r6 = ADD32(0, 0X45E3);
            goto L_806EC5C8;
    }
    // 0x806EC594: addiu       $a2, $zero, 0x45E3
    ctx->r6 = ADD32(0, 0X45E3);
L_806EC598:
    // 0x806EC598: lw          $a0, 0x188($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X188);
    // 0x806EC59C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x806EC5A0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x806EC5A4: beq         $a0, $zero, L_806EC5C0
    if (ctx->r4 == 0) {
        // 0x806EC5A8: nop
    
            goto L_806EC5C0;
    }
    // 0x806EC5A8: nop

    // 0x806EC5AC: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x806EC5B0: bne         $a2, $t6, L_806EC5C0
    if (ctx->r6 != ctx->r14) {
        // 0x806EC5B4: nop
    
            goto L_806EC5C0;
    }
    // 0x806EC5B4: nop

    // 0x806EC5B8: jr          $ra
    // 0x806EC5BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806EC5BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EC5C0:
    // 0x806EC5C0: bne         $at, $zero, L_806EC598
    if (ctx->r1 != 0) {
        // 0x806EC5C4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806EC598;
    }
    // 0x806EC5C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_806EC5C8:
    // 0x806EC5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EC5CC: jr          $ra
    // 0x806EC5D0: nop

    return;
    // 0x806EC5D0: nop

;}
RECOMP_FUNC void func_80698D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698D30: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80698D34: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(556, 0X260) << 16);
    // 0x80698D38: addiu       $t6, $t6, -0x7080
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(556, 0X260));
    // 0x80698D3C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80698D40: jr          $ra
    // 0x80698D44: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80698D44: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80445AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445AFC: jal         0x800677F8
    // 0x80445B00: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445B00: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80445B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445B0C: jr          $ra
    // 0x80445B10: nop

    return;
    // 0x80445B10: nop

;}
RECOMP_FUNC void func_8051EC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EC4C: jr          $ra
    // 0x8051EC50: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    return;
    // 0x8051EC50: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
;}
RECOMP_FUNC void func_804393DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804393DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x804393E0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804393E4: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x804393E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x804393EC: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x804393F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804393F4: lui         $at, 0x4388
    ctx->r1 = S32(0X4388 << 16);
    // 0x804393F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804393FC: lui         $at, 0x43C0
    ctx->r1 = S32(0X43C0 << 16);
    // 0x80439400: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80439404: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80439408: lui         $at, 0x43B0
    ctx->r1 = S32(0X43B0 << 16);
    // 0x8043940C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80439410: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80439414: addiu       $v1, $v0, 0xA1C
    ctx->r3 = ADD32(ctx->r2, 0XA1C);
L_80439418:
    // 0x80439418: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8043941C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80439420: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80439424: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80439428: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x8043942C: bc1fl       L_80439440
    if (!c1cs) {
        // 0x80439430: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80439440;
    }
    goto skip_0;
    // 0x80439430: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_0:
    // 0x80439434: b           L_80439450
    // 0x80439438: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
        goto L_80439450;
    // 0x80439438: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8043943C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80439440:
    // 0x80439440: nop

    // 0x80439444: bc1fl       L_80439454
    if (!c1cs) {
        // 0x80439448: c.lt.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
            goto L_80439454;
    }
    goto skip_1;
    // 0x80439448: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    skip_1:
    // 0x8043944C: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
L_80439450:
    // 0x80439450: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
L_80439454:
    // 0x80439454: nop

    // 0x80439458: bc1fl       L_8043946C
    if (!c1cs) {
        // 0x8043945C: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_8043946C;
    }
    goto skip_2;
    // 0x8043945C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_2:
    // 0x80439460: b           L_8043947C
    // 0x80439464: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
        goto L_8043947C;
    // 0x80439464: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80439468: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_8043946C:
    // 0x8043946C: nop

    // 0x80439470: bc1fl       L_80439480
    if (!c1cs) {
        // 0x80439474: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_80439480;
    }
    goto skip_3;
    // 0x80439474: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_3:
    // 0x80439478: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8043947C:
    // 0x8043947C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_80439480:
    // 0x80439480: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80439484: bgez        $a1, L_80439418
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80439488: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80439418;
    }
    // 0x80439488: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8043948C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80439490: jr          $ra
    // 0x80439494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80439494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80052CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052CD0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80052CD4: jr          $ra
    // 0x80052CD8: sw          $zero, 0x60D0($at)
    MEM_W(0X60D0, ctx->r1) = 0;
    return;
    // 0x80052CD8: sw          $zero, 0x60D0($at)
    MEM_W(0X60D0, ctx->r1) = 0;
;}
RECOMP_FUNC void func_805C8A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8A44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805C8A48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C8A50: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C8A54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8A58: jal         0x8004700C
    // 0x805C8A5C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C8A5C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C8A60: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C8A64: beq         $v0, $zero, L_805C8D1C
    if (ctx->r2 == 0) {
        // 0x805C8A68: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_805C8D1C;
    }
    // 0x805C8A68: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x805C8A6C: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x805C8A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8A74: lbu         $t7, 0x111($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X111);
    // 0x805C8A78: beql        $t7, $zero, L_805C8A94
    if (ctx->r15 == 0) {
        // 0x805C8A7C: lui         $at, 0x43B5
        ctx->r1 = S32(0X43B5 << 16);
            goto L_805C8A94;
    }
    goto skip_0;
    // 0x805C8A7C: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    skip_0:
    // 0x805C8A80: jal         0x805C6E30
    // 0x805C8A84: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_805C6E30(rdram, ctx);
        goto after_1;
    // 0x805C8A84: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_1:
    // 0x805C8A88: beq         $v0, $zero, L_805C8B10
    if (ctx->r2 == 0) {
        // 0x805C8A8C: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_805C8B10;
    }
    // 0x805C8A8C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C8A90: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
L_805C8A94:
    // 0x805C8A94: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C8A98: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C8A9C: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C8AA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C8AA4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C8AA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805C8AAC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x805C8AB0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805C8AB4: nop

    // 0x805C8AB8: bc1fl       L_805C8ACC
    if (!c1cs) {
        // 0x805C8ABC: sw          $t9, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->r25;
            goto L_805C8ACC;
    }
    goto skip_1;
    // 0x805C8ABC: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
    skip_1:
    // 0x805C8AC0: b           L_805C8ACC
    // 0x805C8AC4: sw          $t8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r24;
        goto L_805C8ACC;
    // 0x805C8AC4: sw          $t8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r24;
    // 0x805C8AC8: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
L_805C8ACC:
    // 0x805C8ACC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C8AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8AD4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8AD8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x805C8ADC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8AE0: bc1fl       L_805C8AF0
    if (!c1cs) {
        // 0x805C8AE4: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_805C8AF0;
    }
    goto skip_2;
    // 0x805C8AE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x805C8AE8: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x805C8AEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_805C8AF0:
    // 0x805C8AF0: jal         0x805C74C8
    // 0x805C8AF4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_805C74C8(rdram, ctx);
        goto after_2;
    // 0x805C8AF4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_2:
    // 0x805C8AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8B00: jal         0x805C9D10
    // 0x805C8B04: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_805C9D10(rdram, ctx);
        goto after_3;
    // 0x805C8B04: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_3:
    // 0x805C8B08: b           L_805C8D20
    // 0x805C8B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C8D20;
    // 0x805C8B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8B10:
    // 0x805C8B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8B14: jal         0x805C6AF0
    // 0x805C8B18: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_805C6AF0(rdram, ctx);
        goto after_4;
    // 0x805C8B18: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_4:
    // 0x805C8B1C: bne         $v0, $zero, L_805C8BE8
    if (ctx->r2 != 0) {
        // 0x805C8B20: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_805C8BE8;
    }
    // 0x805C8B20: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C8B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8B28: jal         0x805C6E30
    // 0x805C8B2C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_805C6E30(rdram, ctx);
        goto after_5;
    // 0x805C8B2C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_5:
    // 0x805C8B30: bne         $v0, $zero, L_805C8BE8
    if (ctx->r2 != 0) {
        // 0x805C8B34: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_805C8BE8;
    }
    // 0x805C8B34: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C8B38: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x805C8B3C: beq         $v0, $zero, L_805C8B4C
    if (ctx->r2 == 0) {
        // 0x805C8B40: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_805C8B4C;
    }
    // 0x805C8B40: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x805C8B44: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x805C8B48: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_805C8B4C:
    // 0x805C8B4C: bne         $v0, $zero, L_805C8BE0
    if (ctx->r2 != 0) {
        // 0x805C8B50: nop
    
            goto L_805C8BE0;
    }
    // 0x805C8B50: nop

    // 0x805C8B54: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805C8B58: jal         0x80066E88
    // 0x805C8B5C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x805C8B5C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_6:
    // 0x805C8B60: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805C8B64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C8B68: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C8B6C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x805C8B70: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x805C8B74: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805C8B78: jal         0x80066DE4
    // 0x805C8B7C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x805C8B7C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_7:
    // 0x805C8B80: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805C8B84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C8B88: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x805C8B8C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C8B90: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805C8B94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8B98: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805C8B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8BA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8BA4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x805C8BA8: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x805C8BAC: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x805C8BB0: bnel        $t1, $zero, L_805C8BD0
    if (ctx->r9 != 0) {
        // 0x805C8BB4: swc1        $f0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
            goto L_805C8BD0;
    }
    goto skip_3;
    // 0x805C8BB4: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    skip_3:
    // 0x805C8BB8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x805C8BBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C8BC0: nop

    // 0x805C8BC4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805C8BC8: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x805C8BCC: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
L_805C8BD0:
    // 0x805C8BD0: jal         0x805C9D10
    // 0x805C8BD4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    func_805C9D10(rdram, ctx);
        goto after_8;
    // 0x805C8BD4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    after_8:
    // 0x805C8BD8: b           L_805C8D20
    // 0x805C8BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C8D20;
    // 0x805C8BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8BE0:
    // 0x805C8BE0: b           L_805C8BF8
    // 0x805C8BE4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
        goto L_805C8BF8;
    // 0x805C8BE4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
L_805C8BE8:
    // 0x805C8BE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8BEC: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C8BF0: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x805C8BF4: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
L_805C8BF8:
    // 0x805C8BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8BFC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x805C8C00: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x805C8C04: jal         0x805C71D4
    // 0x805C8C08: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_805C71D4(rdram, ctx);
        goto after_9;
    // 0x805C8C08: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_9:
    // 0x805C8C0C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x805C8C10: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805C8C14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8C18: lwc1        $f10, 0x84($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X84);
    // 0x805C8C1C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x805C8C20: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x805C8C24: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C8C28: nop

    // 0x805C8C2C: bc1fl       L_805C8C9C
    if (!c1cs) {
        // 0x805C8C30: lw          $t5, 0x138($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X138);
            goto L_805C8C9C;
    }
    goto skip_4;
    // 0x805C8C30: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    skip_4:
    // 0x805C8C34: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x805C8C38: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805C8C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8C40: beq         $t3, $zero, L_805C8CF0
    if (ctx->r11 == 0) {
        // 0x805C8C44: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_805C8CF0;
    }
    // 0x805C8C44: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8C48: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x805C8C4C: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x805C8C50: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x805C8C54: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x805C8C58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C8C5C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805C8C60: jal         0x805C74C8
    // 0x805C8C64: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_805C74C8(rdram, ctx);
        goto after_10;
    // 0x805C8C64: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_10:
    // 0x805C8C68: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x805C8C6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8C78: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x805C8C7C: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x805C8C80: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x805C8C84: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x805C8C88: jal         0x805C9D10
    // 0x805C8C8C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    func_805C9D10(rdram, ctx);
        goto after_11;
    // 0x805C8C8C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    after_11:
    // 0x805C8C90: b           L_805C8CF0
    // 0x805C8C94: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_805C8CF0;
    // 0x805C8C94: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x805C8C98: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
L_805C8C9C:
    // 0x805C8C9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805C8CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8CA4: bne         $t5, $zero, L_805C8CF0
    if (ctx->r13 != 0) {
        // 0x805C8CA8: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_805C8CF0;
    }
    // 0x805C8CA8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8CAC: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x805C8CB0: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x805C8CB4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x805C8CB8: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x805C8CBC: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x805C8CC0: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x805C8CC4: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x805C8CC8: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x805C8CCC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C8CD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805C8CD4: jal         0x805C74C8
    // 0x805C8CD8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_805C74C8(rdram, ctx);
        goto after_12;
    // 0x805C8CD8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_12:
    // 0x805C8CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8CE4: jal         0x805C9D10
    // 0x805C8CE8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_805C9D10(rdram, ctx);
        goto after_13;
    // 0x805C8CE8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_13:
    // 0x805C8CEC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_805C8CF0:
    // 0x805C8CF0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805C8CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C8CF8: jal         0x80048F84
    // 0x805C8CFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_14;
    // 0x805C8CFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_14:
    // 0x805C8D00: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C8D04: jal         0x80048F84
    // 0x805C8D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_15;
    // 0x805C8D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x805C8D0C: jal         0x805C6CA4
    // 0x805C8D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C6CA4(rdram, ctx);
        goto after_16;
    // 0x805C8D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x805C8D14: jal         0x805C7ABC
    // 0x805C8D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_17;
    // 0x805C8D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_805C8D1C:
    // 0x805C8D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8D20:
    // 0x805C8D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C8D24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805C8D28: jr          $ra
    // 0x805C8D2C: nop

    return;
    // 0x805C8D2C: nop

;}
RECOMP_FUNC void func_80475B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475B40: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80475B44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80475B48: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80475B4C: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80475B50: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x80475B54: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80475B58: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80475B5C: lw          $t7, 0x6D10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D10);
    // 0x80475B60: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80475B64: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80475B68: beq         $a3, $t7, L_80475B74
    if (ctx->r7 == ctx->r15) {
        // 0x80475B6C: lw          $t4, 0x0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X0);
            goto L_80475B74;
    }
    // 0x80475B6C: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80475B70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80475B74:
    // 0x80475B74: lw          $t8, -0x71A8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X71A8);
    // 0x80475B78: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80475B7C: srl         $t1, $t9, 30
    ctx->r9 = S32(U32(ctx->r25) >> 30);
    // 0x80475B80: bnel        $t1, $zero, L_80475B90
    if (ctx->r9 != 0) {
        // 0x80475B84: sll         $t2, $t0, 2
        ctx->r10 = S32(ctx->r8 << 2);
            goto L_80475B90;
    }
    goto skip_0;
    // 0x80475B84: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    skip_0:
    // 0x80475B88: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80475B8C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
L_80475B90:
    // 0x80475B90: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80475B94: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x80475B98: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80475B9C: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x80475BA0: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80475BA4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80475BA8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80475BAC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80475BB0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80475BB4: jr          $ra
    // 0x80475BB8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    return;
    // 0x80475BB8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
;}
RECOMP_FUNC void func_80072858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007285C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072860: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80072864: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80072868: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007286C: sw          $t6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r14;
    // 0x80072870: addiu       $a0, $a0, -0x2710
    ctx->r4 = ADD32(ctx->r4, -0X2710);
    // 0x80072874: jal         0x80082210
    // 0x80072878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80072878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007287C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072884: jr          $ra
    // 0x80072888: nop

    return;
    // 0x80072888: nop

;}
RECOMP_FUNC void func_8002B00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002B018: jal         0x8002AFDC
    // 0x8002B01C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002AFDC(rdram, ctx);
        goto after_0;
    // 0x8002B01C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002B020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002B024: jal         0x800340DC
    // 0x8002B028: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800340DC(rdram, ctx);
        goto after_1;
    // 0x8002B028: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002B02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B034: jr          $ra
    // 0x8002B038: nop

    return;
    // 0x8002B038: nop

;}
RECOMP_FUNC void func_8040B478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B478: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8040B47C: lw          $v1, 0x18C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18C);
    // 0x8040B480: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x8040B484: sw          $a1, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r5;
    // 0x8040B488: sw          $a1, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r5;
    // 0x8040B48C: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x8040B490: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8040B494: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8040B498: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8040B49C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8040B4A0: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8040B4A4: lw          $a3, 0x1F4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X1F4);
    // 0x8040B4A8: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8040B4AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8040B4B0: jr          $ra
    // 0x8040B4B4: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    return;
    // 0x8040B4B4: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80039ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039ABC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80039AC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80039AC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80039AC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80039ACC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80039AD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80039AD4: beq         $a1, $zero, L_80039B08
    if (ctx->r5 == 0) {
        // 0x80039AD8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80039B08;
    }
    // 0x80039AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80039ADC:
    // 0x80039ADC: lw          $t6, 0x1F8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1F8);
    // 0x80039AE0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80039AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039AE8: bnel        $t6, $zero, L_80039B00
    if (ctx->r14 != 0) {
        // 0x80039AEC: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80039B00;
    }
    goto skip_0;
    // 0x80039AEC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x80039AF0: jal         0x80045A34
    // 0x80039AF4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80039AF4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80039AF8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80039AFC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80039B00:
    // 0x80039B00: bne         $s2, $zero, L_80039ADC
    if (ctx->r18 != 0) {
        // 0x80039B04: addiu       $s1, $s1, 0x280
        ctx->r17 = ADD32(ctx->r17, 0X280);
            goto L_80039ADC;
    }
    // 0x80039B04: addiu       $s1, $s1, 0x280
    ctx->r17 = ADD32(ctx->r17, 0X280);
L_80039B08:
    // 0x80039B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80039B0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80039B10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80039B14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80039B18: jr          $ra
    // 0x80039B1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80039B1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800650D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800650DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800650E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800650E4: sll         $s4, $a2, 16
    ctx->r20 = S32(ctx->r6 << 16);
    // 0x800650E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800650EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800650F0: srl         $s3, $a1, 1
    ctx->r19 = S32(U32(ctx->r5) >> 1);
    // 0x800650F4: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800650F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800650FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80065100: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80065104: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065108: blez        $s3, L_8006513C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8006510C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006513C;
    }
    // 0x8006510C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80065110: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80065114: addiu       $s2, $s2, 0xDA0
    ctx->r18 = ADD32(ctx->r18, 0XDA0);
L_80065118:
    // 0x80065118: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8006511C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065120: beql        $s4, $t6, L_80065134
    if (ctx->r20 == ctx->r14) {
        // 0x80065124: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80065134;
    }
    goto skip_0;
    // 0x80065124: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80065128: jal         0x80071380
    // 0x8006512C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006512C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x80065130: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80065134:
    // 0x80065134: bne         $s1, $s3, L_80065118
    if (ctx->r17 != ctx->r19) {
        // 0x80065138: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80065118;
    }
    // 0x80065138: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8006513C:
    // 0x8006513C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80065140: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065144: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065148: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006514C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80065150: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80065154: jr          $ra
    // 0x80065158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80065158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800658D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800658DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800658E0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800658E4: nop

    // 0x800658E8: bc1fl       L_8006590C
    if (!c1cs) {
        // 0x800658EC: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8006590C;
    }
    goto skip_0;
    // 0x800658EC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x800658F0: lwc1        $f4, 0xECC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XECC);
    // 0x800658F4: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800658F8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800658FC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80065900: jr          $ra
    // 0x80065904: nop

    return;
    // 0x80065904: nop

    // 0x80065908: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8006590C:
    // 0x8006590C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065914: bc1f        L_80065934
    if (!c1cs) {
        // 0x80065918: nop
    
            goto L_80065934;
    }
    // 0x80065918: nop

    // 0x8006591C: lwc1        $f10, 0xED0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XED0);
    // 0x80065920: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80065924: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80065928: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8006592C: jr          $ra
    // 0x80065930: nop

    return;
    // 0x80065930: nop

L_80065934:
    // 0x80065934: jr          $ra
    // 0x80065938: nop

    return;
    // 0x80065938: nop

;}
RECOMP_FUNC void func_8001DF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DF28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DF2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DF30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DF34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001DF38: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8001DF3C: lbu         $t6, -0x764C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X764C);
    // 0x8001DF40: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8001DF44: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001DF48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001DF4C: beq         $t6, $zero, L_8001DF74
    if (ctx->r14 == 0) {
        // 0x8001DF50: add.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
            goto L_8001DF74;
    }
    // 0x8001DF50: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001DF54: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x8001DF58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001DF5C: bnel        $t7, $at, L_8001DF8C
    if (ctx->r15 != ctx->r1) {
        // 0x8001DF60: lwc1        $f8, 0x40($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
            goto L_8001DF8C;
    }
    goto skip_0;
    // 0x8001DF60: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x8001DF64: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8001DF68: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8001DF6C: bnel        $t8, $at, L_8001DF8C
    if (ctx->r24 != ctx->r1) {
        // 0x8001DF70: lwc1        $f8, 0x40($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
            goto L_8001DF8C;
    }
    goto skip_1;
    // 0x8001DF70: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    skip_1:
L_8001DF74:
    // 0x8001DF74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DF78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DF7C: jal         0x8003DD70
    // 0x8001DF80: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_8003DD70(rdram, ctx);
        goto after_0;
    // 0x8001DF80: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8001DF84: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001DF88: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
L_8001DF8C:
    // 0x8001DF8C: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x8001DF90: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8001DF94: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8001DF98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001DF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001DFA0: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x8001DFA4: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x8001DFA8: lbu         $t1, 0x18($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18);
    // 0x8001DFAC: bne         $t1, $at, L_8001DFC4
    if (ctx->r9 != ctx->r1) {
        // 0x8001DFB0: nop
    
            goto L_8001DFC4;
    }
    // 0x8001DFB0: nop

    // 0x8001DFB4: lbu         $t2, 0x30($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X30);
    // 0x8001DFB8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8001DFBC: beql        $t2, $at, L_8001DFD0
    if (ctx->r10 == ctx->r1) {
        // 0x8001DFC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001DFD0;
    }
    goto skip_2;
    // 0x8001DFC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_8001DFC4:
    // 0x8001DFC4: jal         0x8002FABC
    // 0x8001DFC8: lui         $a1, 0xC0E0
    ctx->r5 = S32(0XC0E0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_1;
    // 0x8001DFC8: lui         $a1, 0xC0E0
    ctx->r5 = S32(0XC0E0 << 16);
    after_1:
    // 0x8001DFCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DFD0:
    // 0x8001DFD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DFD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DFD8: jr          $ra
    // 0x8001DFDC: nop

    return;
    // 0x8001DFDC: nop

;}
RECOMP_FUNC void func_80037100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003710C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037110: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80037114: jal         0x80036F00
    // 0x80037118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80036F00(rdram, ctx);
        goto after_0;
    // 0x80037118: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8003711C: lbu         $t6, 0x113($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X113);
    // 0x80037120: beq         $t6, $zero, L_80037130
    if (ctx->r14 == 0) {
        // 0x80037124: nop
    
            goto L_80037130;
    }
    // 0x80037124: nop

    // 0x80037128: jal         0x80036FA4
    // 0x8003712C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036FA4(rdram, ctx);
        goto after_1;
    // 0x8003712C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80037130:
    // 0x80037130: jal         0x80036B50
    // 0x80037134: nop

    func_80036B50(rdram, ctx);
        goto after_2;
    // 0x80037134: nop

    after_2:
    // 0x80037138: bne         $v0, $zero, L_80037154
    if (ctx->r2 != 0) {
        // 0x8003713C: nop
    
            goto L_80037154;
    }
    // 0x8003713C: nop

    // 0x80037140: lw          $v0, 0x12C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X12C);
    // 0x80037144: beq         $v0, $zero, L_80037154
    if (ctx->r2 == 0) {
        // 0x80037148: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80037154;
    }
    // 0x80037148: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8003714C: b           L_8003715C
    // 0x80037150: sw          $t7, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r15;
        goto L_8003715C;
    // 0x80037150: sw          $t7, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r15;
L_80037154:
    // 0x80037154: jal         0x80024340
    // 0x80037158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80024340(rdram, ctx);
        goto after_3;
    // 0x80037158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_8003715C:
    // 0x8003715C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80037168: jr          $ra
    // 0x8003716C: nop

    return;
    // 0x8003716C: nop

;}
RECOMP_FUNC void func_8078F1D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F1D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8078F1DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078F1E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078F1E4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8078F1E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078F1EC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078F1F0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8078F1F4: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8078F1F8: bne         $t8, $zero, L_8078F2F0
    if (ctx->r24 != 0) {
        // 0x8078F1FC: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8078F2F0;
    }
    // 0x8078F1FC: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8078F200: lw          $t9, -0x72C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72C4);
    // 0x8078F204: beql        $t9, $zero, L_8078F2F4
    if (ctx->r25 == 0) {
        // 0x8078F208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078F2F4;
    }
    goto skip_0;
    // 0x8078F208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078F20C: jal         0x800653D8
    // 0x8078F210: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8078F210: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x8078F214: lh          $t0, 0x13C($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X13C);
    // 0x8078F218: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x8078F21C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8078F220: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8078F224: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XD40) << 16);
    // 0x8078F228: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8078F22C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8078F230: lwc1        $f8, -0x130($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XD40));
    // 0x8078F234: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8078F238: andi        $t3, $v1, 0x8
    ctx->r11 = ctx->r3 & 0X8;
    // 0x8078F23C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8078F240: beq         $t3, $zero, L_8078F270
    if (ctx->r11 == 0) {
        // 0x8078F244: swc1        $f10, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
            goto L_8078F270;
    }
    // 0x8078F244: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8078F248: jal         0x800653D8
    // 0x8078F24C: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8078F24C: nop

    after_1:
    // 0x8078F250: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x8078F254: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8078F258: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDB0) << 16);
    // 0x8078F25C: lwc1        $f4, -0xC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDB0));
    // 0x8078F260: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8078F264: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8078F268: b           L_8078F298
    // 0x8078F26C: nop

        goto L_8078F298;
    // 0x8078F26C: nop

L_8078F270:
    // 0x8078F270: jal         0x800653D8
    // 0x8078F274: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8078F274: nop

    after_2:
    // 0x8078F278: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8078F27C: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x8078F280: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8078F284: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDB4) << 16);
    // 0x8078F288: lwc1        $f10, -0xBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDB4));
    // 0x8078F28C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8078F290: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8078F294: nop

L_8078F298:
    // 0x8078F298: jal         0x80066DE4
    // 0x8078F29C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8078F29C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x8078F2A0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8078F2A4: jal         0x80066E88
    // 0x8078F2A8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8078F2A8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8078F2AC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8078F2B0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8078F2B4: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8078F2B8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDB8) << 16);
    // 0x8078F2BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8078F2C0: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8078F2C4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078F2C8: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8078F2CC: lw          $t9, -0x72C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72C4);
    // 0x8078F2D0: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8078F2D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8078F2D8: lwc1        $f4, -0xB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDB8));
    // 0x8078F2DC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8078F2E0: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8078F2E4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8078F2E8: jalr        $t9
    // 0x8078F2EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8078F2EC: nop

    after_5:
L_8078F2F0:
    // 0x8078F2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078F2F4:
    // 0x8078F2F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078F2F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8078F2FC: jr          $ra
    // 0x8078F300: nop

    return;
    // 0x8078F300: nop

;}
RECOMP_FUNC void func_80447FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447FE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447FF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447FF4: bne         $a2, $zero, L_80448040
    if (ctx->r6 != 0) {
        // 0x80447FF8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80448040;
    }
    // 0x80447FF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447FFC: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80448000: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x80448004: lw          $v1, 0x100($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X100);
    // 0x80448008: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x8044800C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80448010: beq         $at, $zero, L_80448020
    if (ctx->r1 == 0) {
        // 0x80448014: sw          $t7, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r15;
            goto L_80448020;
    }
    // 0x80448014: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80448018: b           L_80448084
    // 0x8044801C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80448084;
    // 0x8044801C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80448020:
    // 0x80448020: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x80448024: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80448028: bnel        $at, $zero, L_80448084
    if (ctx->r1 != 0) {
        // 0x8044802C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80448084;
    }
    goto skip_0;
    // 0x8044802C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80448030: jal         0x804463E8
    // 0x80448034: nop

    func_804463E8(rdram, ctx);
        goto after_0;
    // 0x80448034: nop

    after_0:
    // 0x80448038: b           L_80448084
    // 0x8044803C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80448084;
    // 0x8044803C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448040:
    // 0x80448040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448044: bnel        $a2, $at, L_80448070
    if (ctx->r6 != ctx->r1) {
        // 0x80448048: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448070;
    }
    goto skip_1;
    // 0x80448048: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8044804C: jal         0x80446384
    // 0x80448050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446384(rdram, ctx);
        goto after_1;
    // 0x80448050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448054: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448058: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044805C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80448060: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448064: b           L_80448080
    // 0x80448068: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
        goto L_80448080;
    // 0x80448068: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
    // 0x8044806C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448070:
    // 0x80448070: bnel        $a2, $at, L_80448084
    if (ctx->r6 != ctx->r1) {
        // 0x80448074: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80448084;
    }
    goto skip_2;
    // 0x80448074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80448078: jal         0x804463E8
    // 0x8044807C: nop

    func_804463E8(rdram, ctx);
        goto after_2;
    // 0x8044807C: nop

    after_2:
L_80448080:
    // 0x80448080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448084:
    // 0x80448084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044808C: jr          $ra
    // 0x80448090: nop

    return;
    // 0x80448090: nop

;}
RECOMP_FUNC void func_8003E1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E1F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E1FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E200: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8003E204: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8003E208: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8003E20C: jal         0x80065ABC
    // 0x8003E210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8003E210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E218: jal         0x8003E070
    // 0x8003E21C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_8003E070(rdram, ctx);
        goto after_1;
    // 0x8003E21C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x8003E220: bne         $v0, $zero, L_8003E230
    if (ctx->r2 != 0) {
        // 0x8003E224: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8003E230;
    }
    // 0x8003E224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E228: jal         0x8003E0D4
    // 0x8003E22C: nop

    func_8003E0D4(rdram, ctx);
        goto after_2;
    // 0x8003E22C: nop

    after_2:
L_8003E230:
    // 0x8003E230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E238: jr          $ra
    // 0x8003E23C: nop

    return;
    // 0x8003E23C: nop

;}
RECOMP_FUNC void func_80056458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005645C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056460: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80056464: jal         0x800563D8
    // 0x80056468: addiu       $a1, $zero, 0x44DA
    ctx->r5 = ADD32(0, 0X44DA);
    func_800563D8(rdram, ctx);
        goto after_0;
    // 0x80056468: addiu       $a1, $zero, 0x44DA
    ctx->r5 = ADD32(0, 0X44DA);
    after_0:
    // 0x8005646C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80056470: sb          $t6, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r14;
    // 0x80056474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005647C: jr          $ra
    // 0x80056480: nop

    return;
    // 0x80056480: nop

;}
RECOMP_FUNC void func_800263B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800263B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800263B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800263BC: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x800263C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800263C4: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x800263C8: beql        $v1, $zero, L_8002641C
    if (ctx->r3 == 0) {
        // 0x800263CC: lwc1        $f8, 0x50($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X50);
            goto L_8002641C;
    }
    goto skip_0;
    // 0x800263CC: lwc1        $f8, 0x50($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X50);
    skip_0:
    // 0x800263D0: lwc1        $f4, 0x50($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X50);
    // 0x800263D4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800263D8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800263DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800263E0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800263E4: jal         0x8006593C
    // 0x800263E8: nop

    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x800263E8: nop

    after_0:
    // 0x800263EC: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800263F0: sltiu       $at, $a0, 0x5B
    ctx->r1 = ctx->r4 < 0X5B ? 1 : 0;
    // 0x800263F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800263F8: bne         $at, $zero, L_80026404
    if (ctx->r1 != 0) {
        // 0x800263FC: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80026404;
    }
    // 0x800263FC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80026400: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
L_80026404:
    // 0x80026404: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80026408: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x8002640C: mflo        $t7
    ctx->r15 = lo;
    // 0x80026410: sw          $t7, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r15;
    // 0x80026414: lw          $v1, 0x180($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X180);
    // 0x80026418: lwc1        $f8, 0x50($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X50);
L_8002641C:
    // 0x8002641C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026420: lw          $t8, 0x14C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14C);
    // 0x80026424: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80026428: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8002642C: nop

    // 0x80026430: bc1fl       L_80026440
    if (!c1cs) {
        // 0x80026434: lbu         $t1, 0x1F8($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
            goto L_80026440;
    }
    goto skip_1;
    // 0x80026434: lbu         $t1, 0x1F8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
    skip_1:
    // 0x80026438: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002643C: lbu         $t1, 0x1F8($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1F8);
L_80026440:
    // 0x80026440: lw          $t4, 0x138($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X138);
    // 0x80026444: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80026448: sltu        $t2, $zero, $t1
    ctx->r10 = 0 < ctx->r9 ? 1 : 0;
    // 0x8002644C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80026450: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80026454: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80026458: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8002645C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80026460: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80026464: lw          $t9, -0x3A88($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3A88);
    // 0x80026468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002646C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80026470: sw          $t1, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r9;
    // 0x80026474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002647C: jr          $ra
    // 0x80026480: nop

    return;
    // 0x80026480: nop

;}
RECOMP_FUNC void func_805ADCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADCBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805ADCC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805ADCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805ADCC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805ADCCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADCD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ADCD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805ADCD8: lui         $a2, 0x805B
    ctx->r6 = S32(RELOC_HI16(444, 0X1130) << 16);
    // 0x805ADCDC: lui         $a1, 0x805B
    ctx->r5 = S32(RELOC_HI16(444, 0X1178) << 16);
    // 0x805ADCE0: addiu       $a1, $a1, -0x1788
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X1178));
    // 0x805ADCE4: addiu       $a2, $a2, -0x17D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X1130));
    // 0x805ADCE8: jal         0x805AD7C8
    // 0x805ADCEC: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    func_805AD7C8(rdram, ctx);
        goto after_0;
    // 0x805ADCEC: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_0:
    // 0x805ADCF0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805ADCF4: lui         $a1, 0x805B
    ctx->r5 = S32(RELOC_HI16(444, 0X11C0) << 16);
    // 0x805ADCF8: lui         $a2, 0x805B
    ctx->r6 = S32(RELOC_HI16(444, 0X1130) << 16);
    // 0x805ADCFC: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x805ADD00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805ADD04: addiu       $a2, $a2, -0x17D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X1130));
    // 0x805ADD08: addiu       $a1, $a1, -0x1740
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X11C0));
    // 0x805ADD0C: jal         0x805AD7C8
    // 0x805ADD10: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    func_805AD7C8(rdram, ctx);
        goto after_1;
    // 0x805ADD10: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_1:
    // 0x805ADD14: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805ADD18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADD1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805ADD20: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805ADD24: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x805ADD28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805ADD2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805ADD30: jr          $ra
    // 0x805ADD34: nop

    return;
    // 0x805ADD34: nop

;}
RECOMP_FUNC void func_80525F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80525F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80525F18: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80525F1C: addiu       $at, $zero, 0x41ED
    ctx->r1 = ADD32(0, 0X41ED);
    // 0x80525F20: beq         $v0, $at, L_80525F44
    if (ctx->r2 == ctx->r1) {
        // 0x80525F24: addiu       $at, $zero, 0x41EE
        ctx->r1 = ADD32(0, 0X41EE);
            goto L_80525F44;
    }
    // 0x80525F24: addiu       $at, $zero, 0x41EE
    ctx->r1 = ADD32(0, 0X41EE);
    // 0x80525F28: beq         $v0, $at, L_80525F64
    if (ctx->r2 == ctx->r1) {
        // 0x80525F2C: addiu       $at, $zero, 0x41EF
        ctx->r1 = ADD32(0, 0X41EF);
            goto L_80525F64;
    }
    // 0x80525F2C: addiu       $at, $zero, 0x41EF
    ctx->r1 = ADD32(0, 0X41EF);
    // 0x80525F30: beq         $v0, $at, L_80525F44
    if (ctx->r2 == ctx->r1) {
        // 0x80525F34: addiu       $at, $zero, 0x41F0
        ctx->r1 = ADD32(0, 0X41F0);
            goto L_80525F44;
    }
    // 0x80525F34: addiu       $at, $zero, 0x41F0
    ctx->r1 = ADD32(0, 0X41F0);
    // 0x80525F38: beq         $v0, $at, L_80525F44
    if (ctx->r2 == ctx->r1) {
        // 0x80525F3C: addiu       $at, $zero, 0x4583
        ctx->r1 = ADD32(0, 0X4583);
            goto L_80525F44;
    }
    // 0x80525F3C: addiu       $at, $zero, 0x4583
    ctx->r1 = ADD32(0, 0X4583);
    // 0x80525F40: bne         $v0, $at, L_80525F6C
    if (ctx->r2 != ctx->r1) {
        // 0x80525F44: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80525F6C;
    }
L_80525F44:
    // 0x80525F44: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80525F48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80525F4C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80525F50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80525F54: jal         0x80525F94
    // 0x80525F58: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_80525F94(rdram, ctx);
        goto after_0;
    // 0x80525F58: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x80525F5C: b           L_80525F70
    // 0x80525F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80525F70;
    // 0x80525F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80525F64:
    // 0x80525F64: jal         0x805260DC
    // 0x80525F68: nop

    func_805260DC(rdram, ctx);
        goto after_1;
    // 0x80525F68: nop

    after_1:
L_80525F6C:
    // 0x80525F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80525F70:
    // 0x80525F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80525F74: jr          $ra
    // 0x80525F78: nop

    return;
    // 0x80525F78: nop

;}
RECOMP_FUNC void func_80521E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521E40: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(315, 0X10) << 16);
    // 0x80521E44: addiu       $v0, $v0, 0x1E50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(315, 0X10));
    // 0x80521E48: jr          $ra
    // 0x80521E4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80521E4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80065490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065490: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80065494: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80065498: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006549C: swc1        $f4, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800654A0: lwc1        $f6, -0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800654A4: swc1        $f6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800654A8: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800654AC: jr          $ra
    // 0x800654B0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800654B0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_806A9834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A9838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A983C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806A9840: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806A9844: lui         $t8, 0x806B
    ctx->r24 = S32(RELOC_HI16(589, 0X115C) << 16);
    // 0x806A9848: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806A984C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806A9850: lw          $t8, -0x56E4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(589, 0X115C));
    // 0x806A9854: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806A9858: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806A985C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806A9860: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806A9864: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806A9868: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806A986C: beql        $v1, $zero, L_806A98A0
    if (ctx->r3 == 0) {
        // 0x806A9870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806A98A0;
    }
    goto skip_0;
    // 0x806A9870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806A9874: jalr        $v1
    // 0x806A9878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806A9878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806A987C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A9880: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806A9884: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806A9888: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806A988C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806A9890: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806A9894: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806A9898: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806A989C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806A98A0:
    // 0x806A98A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A98A4: jr          $ra
    // 0x806A98A8: nop

    return;
    // 0x806A98A8: nop

;}
RECOMP_FUNC void func_8049EF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049EF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049EF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049EF20: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8049EF24: jal         0x800577D8
    // 0x8049EF28: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x8049EF28: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x8049EF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8049EF30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049EF34: jr          $ra
    // 0x8049EF38: nop

    return;
    // 0x8049EF38: nop

;}
RECOMP_FUNC void func_805A9314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A9314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A9318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A931C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A9320: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x805A9324: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A9328: beql        $a3, $zero, L_805A9378
    if (ctx->r7 == 0) {
        // 0x805A932C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A9378;
    }
    goto skip_0;
    // 0x805A932C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A9330: lw          $t6, 0x180($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X180);
    // 0x805A9334: beql        $a0, $t6, L_805A9368
    if (ctx->r4 == ctx->r14) {
        // 0x805A9338: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805A9368;
    }
    goto skip_1;
    // 0x805A9338: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x805A933C: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x805A9340: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x805A9344: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805A9348: jal         0x80048BE8
    // 0x805A934C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_0;
    // 0x805A934C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_0:
    // 0x805A9350: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805A9354: addiu       $t9, $t9, -0x7218
    ctx->r25 = ADD32(ctx->r25, -0X7218);
    // 0x805A9358: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x805A935C: b           L_805A9374
    // 0x805A9360: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
        goto L_805A9374;
    // 0x805A9360: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
    // 0x805A9364: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805A9368:
    // 0x805A9368: nop

    // 0x805A936C: swc1        $f0, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f0.u32l;
    // 0x805A9370: swc1        $f0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f0.u32l;
L_805A9374:
    // 0x805A9374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A9378:
    // 0x805A9378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A937C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A9380: jr          $ra
    // 0x805A9384: nop

    return;
    // 0x805A9384: nop

;}
RECOMP_FUNC void func_800240C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800240C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800240C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800240C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800240CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800240D0: lwc1        $f14, 0xDC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x800240D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800240D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800240DC: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x800240E0: c.eq.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl == ctx->f14.fl;
    // 0x800240E4: nop

    // 0x800240E8: bc1tl       L_80024138
    if (c1cs) {
        // 0x800240EC: lwc1        $f12, 0x0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80024138;
    }
    goto skip_0;
    // 0x800240EC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800240F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800240F4: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x800240F8: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x800240FC: nop

    // 0x80024100: bc1fl       L_80024124
    if (!c1cs) {
        // 0x80024104: lwc1        $f12, 0x0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80024124;
    }
    goto skip_1;
    // 0x80024104: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80024108: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x8002410C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80024110: jal         0x80023DD0
    // 0x80024114: lw          $a2, 0xE8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE8);
    func_80023DD0(rdram, ctx);
        goto after_0;
    // 0x80024114: lw          $a2, 0xE8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE8);
    after_0:
    // 0x80024118: b           L_8002412C
    // 0x8002411C: nop

        goto L_8002412C;
    // 0x8002411C: nop

    // 0x80024120: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
L_80024124:
    // 0x80024124: jal         0x80023E18
    // 0x80024128: lw          $a2, 0xE8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE8);
    func_80023E18(rdram, ctx);
        goto after_1;
    // 0x80024128: lw          $a2, 0xE8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE8);
    after_1:
L_8002412C:
    // 0x8002412C: b           L_8002416C
    // 0x80024130: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_8002416C;
    // 0x80024130: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80024134: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
L_80024138:
    // 0x80024138: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002413C: nop

    // 0x80024140: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80024144: nop

    // 0x80024148: bc1f        L_80024160
    if (!c1cs) {
        // 0x8002414C: nop
    
            goto L_80024160;
    }
    // 0x8002414C: nop

    // 0x80024150: jal         0x80023DD0
    // 0x80024154: lw          $a2, 0xE8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE8);
    func_80023DD0(rdram, ctx);
        goto after_2;
    // 0x80024154: lw          $a2, 0xE8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE8);
    after_2:
    // 0x80024158: b           L_8002416C
    // 0x8002415C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_8002416C;
    // 0x8002415C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80024160:
    // 0x80024160: jal         0x80023E18
    // 0x80024164: lw          $a2, 0xE8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE8);
    func_80023E18(rdram, ctx);
        goto after_3;
    // 0x80024164: lw          $a2, 0xE8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE8);
    after_3:
    // 0x80024168: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8002416C:
    // 0x8002416C: jal         0x80024020
    // 0x80024170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80024020(rdram, ctx);
        goto after_4;
    // 0x80024170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80024174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80024178: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002417C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024180: jr          $ra
    // 0x80024184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80024184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80551658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80551658: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8055165C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80551660: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80551664: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80551668: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8055166C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80551670: lwc1        $f20, 0x3C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80551674: lwc1        $f22, 0x40($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80551678: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8055167C: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x80551680: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80551684: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x80551688: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8055168C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80551690: jal         0x80065728
    // 0x80551694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80551694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80551698: lw          $t6, 0xD7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XD7C);
    // 0x8055169C: lui         $a0, 0x8055
    ctx->r4 = S32(RELOC_HI16(354, 0X3FF0) << 16);
    // 0x805516A0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x805516A4: addiu       $a0, $a0, 0x4B10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(354, 0X3FF0));
    // 0x805516A8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x805516AC: lui         $a1, 0x8055
    ctx->r5 = S32(RELOC_HI16(354, 0X4004) << 16);
    // 0x805516B0: addiu       $a1, $a1, 0x4B24
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(354, 0X4004));
    // 0x805516B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805516B8: lw          $t0, 0xDA4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XDA4);
    // 0x805516BC: sw          $a0, 0xD84($s0)
    MEM_W(0XD84, ctx->r16) = ctx->r4;
    // 0x805516C0: sw          $a1, 0xDAC($s0)
    MEM_W(0XDAC, ctx->r16) = ctx->r5;
    // 0x805516C4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x805516C8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805516CC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x805516D0: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x805516D4: sw          $t9, 0xD78($s0)
    MEM_W(0XD78, ctx->r16) = ctx->r25;
    // 0x805516D8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x805516DC: addiu       $t4, $zero, 0x3000
    ctx->r12 = ADD32(0, 0X3000);
    // 0x805516E0: addiu       $t5, $zero, 0x3800
    ctx->r13 = ADD32(0, 0X3800);
    // 0x805516E4: addiu       $t6, $zero, 0xA8
    ctx->r14 = ADD32(0, 0XA8);
    // 0x805516E8: sw          $t4, 0xD64($s0)
    MEM_W(0XD64, ctx->r16) = ctx->r12;
    // 0x805516EC: sw          $t5, 0xD8C($s0)
    MEM_W(0XD8C, ctx->r16) = ctx->r13;
    // 0x805516F0: sw          $t6, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r14;
    // 0x805516F4: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4160) << 16);
    // 0x805516F8: sw          $t3, 0xDA0($s0)
    MEM_W(0XDA0, ctx->r16) = ctx->r11;
    // 0x805516FC: lwc1        $f4, 0x4C80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4160));
    // 0x80551700: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80551704: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80551708: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x8055170C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80551710: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80551714: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80551718: lw          $t8, 0xD50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XD50);
    // 0x8055171C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80551720: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80551724: sw          $t7, 0xDE8($s0)
    MEM_W(0XDE8, ctx->r16) = ctx->r15;
    // 0x80551728: swc1        $f4, 0xDBC($s0)
    MEM_W(0XDBC, ctx->r16) = ctx->f4.u32l;
    // 0x8055172C: swc1        $f6, 0xDB8($s0)
    MEM_W(0XDB8, ctx->r16) = ctx->f6.u32l;
    // 0x80551730: addiu       $at, $zero, 0x41C6
    ctx->r1 = ADD32(0, 0X41C6);
    // 0x80551734: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80551738: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8055173C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80551740: nop

    // 0x80551744: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80551748: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8055174C: lhu         $v1, 0xC($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0XC);
    // 0x80551750: beq         $v1, $at, L_80551768
    if (ctx->r3 == ctx->r1) {
        // 0x80551754: addiu       $at, $zero, 0x470F
        ctx->r1 = ADD32(0, 0X470F);
            goto L_80551768;
    }
    // 0x80551754: addiu       $at, $zero, 0x470F
    ctx->r1 = ADD32(0, 0X470F);
    // 0x80551758: beql        $v1, $at, L_8055187C
    if (ctx->r3 == ctx->r1) {
        // 0x8055175C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8055187C;
    }
    goto skip_0;
    // 0x8055175C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80551760: b           L_8055197C
    // 0x80551764: nop

        goto L_8055197C;
    // 0x80551764: nop

L_80551768:
    // 0x80551768: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8055176C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80551770: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80551774: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x80551778: swc1        $f0, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f0.u32l;
    // 0x8055177C: swc1        $f0, 0xD60($s0)
    MEM_W(0XD60, ctx->r16) = ctx->f0.u32l;
    // 0x80551780: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80551784: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80551788: addiu       $t3, $v1, 0x2
    ctx->r11 = ADD32(ctx->r3, 0X2);
    // 0x8055178C: addiu       $t4, $v1, 0x3
    ctx->r12 = ADD32(ctx->r3, 0X3);
    // 0x80551790: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80551794: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80551798: mtc1        $t4, $f2
    ctx->f2.u32l = ctx->r12;
    // 0x8055179C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805517A0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x805517A4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805517A8: cvt.s.w     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = CVT_S_W(ctx->f2.u32l);
    // 0x805517AC: beq         $v1, $a0, L_8055181C
    if (ctx->r3 == ctx->r4) {
        // 0x805517B0: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8055181C;
    }
    // 0x805517B0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
L_805517B4:
    // 0x805517B4: add.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x805517B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x805517BC: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x805517C0: add.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x805517C4: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x805517C8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805517CC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805517D0: addiu       $t3, $v1, 0x2
    ctx->r11 = ADD32(ctx->r3, 0X2);
    // 0x805517D4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x805517D8: addiu       $t4, $v1, 0x3
    ctx->r12 = ADD32(ctx->r3, 0X3);
    // 0x805517DC: mtc1        $t4, $f2
    ctx->f2.u32l = ctx->r12;
    // 0x805517E0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805517E4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x805517E8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x805517EC: swc1        $f22, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f22.u32l;
    // 0x805517F0: swc1        $f22, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f22.u32l;
    // 0x805517F4: add.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x805517F8: swc1        $f22, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f22.u32l;
    // 0x805517FC: swc1        $f22, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x80551800: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80551804: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80551808: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8055180C: add.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x80551810: cvt.s.w     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80551814: bne         $v1, $a0, L_805517B4
    if (ctx->r3 != ctx->r4) {
        // 0x80551818: swc1        $f6, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
            goto L_805517B4;
    }
    // 0x80551818: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
L_8055181C:
    // 0x8055181C: add.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x80551820: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80551824: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80551828: add.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8055182C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80551830: swc1        $f22, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f22.u32l;
    // 0x80551834: add.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80551838: swc1        $f22, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f22.u32l;
    // 0x8055183C: swc1        $f22, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x80551840: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80551844: swc1        $f6, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80551848: add.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x8055184C: swc1        $f10, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f10.u32l;
    // 0x80551850: swc1        $f22, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x80551854: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80551858: sw          $zero, 0xDC4($s0)
    MEM_W(0XDC4, ctx->r16) = 0;
    // 0x8055185C: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4018) << 16);
    // 0x80551860: lwc1        $f4, 0x4B38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4018));
    // 0x80551864: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80551868: jal         0x80553838
    // 0x8055186C: swc1        $f4, 0xDC0($s0)
    MEM_W(0XDC0, ctx->r16) = ctx->f4.u32l;
    func_80553838(rdram, ctx);
        goto after_1;
    // 0x8055186C: swc1        $f4, 0xDC0($s0)
    MEM_W(0XDC0, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80551870: b           L_8055197C
    // 0x80551874: nop

        goto L_8055197C;
    // 0x80551874: nop

    // 0x80551878: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8055187C:
    // 0x8055187C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80551880: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x80551884: swc1        $f0, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f0.u32l;
    // 0x80551888: swc1        $f0, 0xD60($s0)
    MEM_W(0XD60, ctx->r16) = ctx->f0.u32l;
    // 0x8055188C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80551890: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80551894: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x80551898: addiu       $t7, $v1, 0x3
    ctx->r15 = ADD32(ctx->r3, 0X3);
    // 0x8055189C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805518A0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x805518A4: mtc1        $t7, $f2
    ctx->f2.u32l = ctx->r15;
    // 0x805518A8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x805518AC: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x805518B0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805518B4: cvt.s.w     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = CVT_S_W(ctx->f2.u32l);
    // 0x805518B8: beq         $v1, $a0, L_80551928
    if (ctx->r3 == ctx->r4) {
        // 0x805518BC: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80551928;
    }
    // 0x805518BC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
L_805518C0:
    // 0x805518C0: sub.s       $f10, $f20, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x805518C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x805518C8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x805518CC: sub.s       $f6, $f20, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f14.fl;
    // 0x805518D0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x805518D4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x805518D8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805518DC: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x805518E0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x805518E4: addiu       $t7, $v1, 0x3
    ctx->r15 = ADD32(ctx->r3, 0X3);
    // 0x805518E8: mtc1        $t7, $f2
    ctx->f2.u32l = ctx->r15;
    // 0x805518EC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805518F0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x805518F4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x805518F8: swc1        $f22, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f22.u32l;
    // 0x805518FC: swc1        $f22, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f22.u32l;
    // 0x80551900: sub.s       $f6, $f20, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f16.fl;
    // 0x80551904: swc1        $f22, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f22.u32l;
    // 0x80551908: swc1        $f22, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x8055190C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80551910: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80551914: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80551918: sub.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f12.fl;
    // 0x8055191C: cvt.s.w     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80551920: bne         $v1, $a0, L_805518C0
    if (ctx->r3 != ctx->r4) {
        // 0x80551924: swc1        $f6, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
            goto L_805518C0;
    }
    // 0x80551924: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
L_80551928:
    // 0x80551928: sub.s       $f6, $f20, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f14.fl;
    // 0x8055192C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80551930: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80551934: sub.s       $f10, $f20, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x80551938: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8055193C: swc1        $f22, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f22.u32l;
    // 0x80551940: sub.s       $f6, $f20, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f16.fl;
    // 0x80551944: swc1        $f22, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f22.u32l;
    // 0x80551948: swc1        $f22, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x8055194C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80551950: swc1        $f6, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80551954: sub.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f12.fl;
    // 0x80551958: swc1        $f10, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8055195C: swc1        $f22, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x80551960: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80551964: sw          $zero, 0xDC4($s0)
    MEM_W(0XDC4, ctx->r16) = 0;
    // 0x80551968: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4018) << 16);
    // 0x8055196C: lwc1        $f6, 0x4B38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4018));
    // 0x80551970: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80551974: jal         0x805538A4
    // 0x80551978: swc1        $f6, 0xDC0($s0)
    MEM_W(0XDC0, ctx->r16) = ctx->f6.u32l;
    func_805538A4(rdram, ctx);
        goto after_2;
    // 0x80551978: swc1        $f6, 0xDC0($s0)
    MEM_W(0XDC0, ctx->r16) = ctx->f6.u32l;
    after_2:
L_8055197C:
    // 0x8055197C: jal         0x80066DE4
    // 0x80551980: lwc1        $f12, 0xD5C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD5C);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80551980: lwc1        $f12, 0xD5C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD5C);
    after_3:
    // 0x80551984: lwc1        $f12, 0xD5C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD5C);
    // 0x80551988: jal         0x80066E88
    // 0x8055198C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8055198C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80551990: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80551994: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80551998: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8055199C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805519A0: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x805519A4: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x805519A8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x805519AC: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x805519B0: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x805519B4: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x805519B8: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805519BC: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x805519C0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805519C4: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x805519C8: nop

    // 0x805519CC: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x805519D0: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x805519D4: swc1        $f6, 0xDF0($s0)
    MEM_W(0XDF0, ctx->r16) = ctx->f6.u32l;
    // 0x805519D8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x805519DC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805519E0: sub.s       $f16, $f4, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x805519E4: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x805519E8: swc1        $f6, 0xDF4($s0)
    MEM_W(0XDF4, ctx->r16) = ctx->f6.u32l;
    // 0x805519EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x805519F0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x805519F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805519F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805519FC: jr          $ra
    // 0x80551A00: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80551A00: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80442678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044267C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442680: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80442684: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80442688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8044268C: bne         $v0, $at, L_804426C0
    if (ctx->r2 != ctx->r1) {
        // 0x80442690: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_804426C0;
    }
    // 0x80442690: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80442694: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80442698: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044269C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804426A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804426A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804426A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804426AC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x804426B0: jal         0x8044284C
    // 0x804426B4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_8044284C(rdram, ctx);
        goto after_0;
    // 0x804426B4: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x804426B8: b           L_804426D8
    // 0x804426BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804426D8;
    // 0x804426BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804426C0:
    // 0x804426C0: bne         $v0, $zero, L_804426D4
    if (ctx->r2 != 0) {
        // 0x804426C4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_804426D4;
    }
    // 0x804426C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804426C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804426CC: jal         0x8044284C
    // 0x804426D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8044284C(rdram, ctx);
        goto after_1;
    // 0x804426D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_804426D4:
    // 0x804426D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804426D8:
    // 0x804426D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804426DC: jr          $ra
    // 0x804426E0: nop

    return;
    // 0x804426E0: nop

;}
RECOMP_FUNC void func_80455704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80455708: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8045570C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80455710: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80455714: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455718: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8045571C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80455720: addu        $s1, $a0, $at
    ctx->r17 = ADD32(ctx->r4, ctx->r1);
    // 0x80455724: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80455728: addiu       $s3, $zero, 0x48
    ctx->r19 = ADD32(0, 0X48);
L_8045572C:
    // 0x8045572C: lw          $a0, 0x6A4C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X6A4C);
    // 0x80455730: beql        $a0, $zero, L_80455744
    if (ctx->r4 == 0) {
        // 0x80455734: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80455744;
    }
    goto skip_0;
    // 0x80455734: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80455738: jal         0x80050A2C
    // 0x8045573C: nop

    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8045573C: nop

    after_0:
    // 0x80455740: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80455744:
    // 0x80455744: bne         $s0, $s3, L_8045572C
    if (ctx->r16 != ctx->r19) {
        // 0x80455748: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8045572C;
    }
    // 0x80455748: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8045574C: jal         0x80068438
    // 0x80455750: nop

    func_80068438(rdram, ctx);
        goto after_1;
    // 0x80455750: nop

    after_1:
    // 0x80455754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80455758: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8045575C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80455760: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80455764: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80455768: jr          $ra
    // 0x8045576C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8045576C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806AA2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA2C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AA2CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AA2D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AA2D4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806AA2D8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806AA2DC: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(589, 0X1184) << 16);
    // 0x806AA2E0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806AA2E4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806AA2E8: addiu       $t7, $t7, -0x56BC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(589, 0X1184));
    // 0x806AA2EC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806AA2F0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806AA2F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806AA2F8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806AA2FC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806AA300: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806AA304: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806AA308: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AA30C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x806AA310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AA314: addiu       $a1, $zero, 0x1C4
    ctx->r5 = ADD32(0, 0X1C4);
    // 0x806AA318: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x806AA31C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806AA320: jal         0x80045A34
    // 0x806AA324: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806AA324: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x806AA328: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806AA32C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806AA330: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806AA334: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806AA338: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806AA33C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806AA340: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806AA344: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x806AA348: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x806AA34C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806AA350: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806AA354: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x806AA358: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x806AA35C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11EC) << 16);
    // 0x806AA360: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806AA364: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806AA368: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x806AA36C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x806AA370: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x806AA374: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806AA378: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x806AA37C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_806AA380:
    // 0x806AA380: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x806AA384: sh          $a1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r5;
    // 0x806AA388: sh          $a2, 0x9E($v1)
    MEM_H(0X9E, ctx->r3) = ctx->r6;
    // 0x806AA38C: sh          $a0, 0x12E($v1)
    MEM_H(0X12E, ctx->r3) = ctx->r4;
    // 0x806AA390: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // 0x806AA394: sh          $a2, 0xA0($v1)
    MEM_H(0XA0, ctx->r3) = ctx->r6;
    // 0x806AA398: sh          $a0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r4;
    // 0x806AA39C: sh          $a1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r5;
    // 0x806AA3A0: sh          $a2, 0xA2($v1)
    MEM_H(0XA2, ctx->r3) = ctx->r6;
    // 0x806AA3A4: sh          $a0, 0x132($v1)
    MEM_H(0X132, ctx->r3) = ctx->r4;
    // 0x806AA3A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x806AA3AC: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // 0x806AA3B0: sh          $a2, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r6;
    // 0x806AA3B4: bne         $a3, $t0, L_806AA380
    if (ctx->r7 != ctx->r8) {
        // 0x806AA3B8: sh          $a0, 0x124($v1)
        MEM_H(0X124, ctx->r3) = ctx->r4;
            goto L_806AA380;
    }
    // 0x806AA3B8: sh          $a0, 0x124($v1)
    MEM_H(0X124, ctx->r3) = ctx->r4;
    // 0x806AA3BC: lwc1        $f4, -0x5654($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11EC));
    // 0x806AA3C0: sh          $zero, 0x1BE($t1)
    MEM_H(0X1BE, ctx->r9) = 0;
    // 0x806AA3C4: lh          $t5, 0x1BE($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X1BE);
    // 0x806AA3C8: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x806AA3CC: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
    // 0x806AA3D0: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x806AA3D4: sh          $t5, 0x1BC($t1)
    MEM_H(0X1BC, ctx->r9) = ctx->r13;
    // 0x806AA3D8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AA3DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA3E0: jal         0x806AA2A4
    // 0x806AA3E4: sh          $zero, 0x1C0($t6)
    MEM_H(0X1C0, ctx->r14) = 0;
    func_806AA2A4(rdram, ctx);
        goto after_1;
    // 0x806AA3E4: sh          $zero, 0x1C0($t6)
    MEM_H(0X1C0, ctx->r14) = 0;
    after_1:
    // 0x806AA3E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AA3EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA3F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AA3F4: jr          $ra
    // 0x806AA3F8: nop

    return;
    // 0x806AA3F8: nop

;}
RECOMP_FUNC void func_806754EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806754EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806754F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806754F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806754F8: jal         0x80047090
    // 0x806754FC: addiu       $a0, $zero, 0x4084
    ctx->r4 = ADD32(0, 0X4084);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806754FC: addiu       $a0, $zero, 0x4084
    ctx->r4 = ADD32(0, 0X4084);
    after_0:
    // 0x80675500: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80675504: lui         $at, 0x4084
    ctx->r1 = S32(0X4084 << 16);
    // 0x80675508: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8067550C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80675510: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80675514: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80675518: jal         0x8004613C
    // 0x8067551C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8067551C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80675520: beq         $v0, $zero, L_8067555C
    if (ctx->r2 == 0) {
        // 0x80675524: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8067555C;
    }
    // 0x80675524: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80675528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067552C: jal         0x80047F9C
    // 0x80675530: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80675530: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80675534: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80675538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067553C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80675540: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80675544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80675548: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(532, 0X6A0) << 16);
    // 0x8067554C: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x80675550: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x80675554: lwc1        $f8, 0x55F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(532, 0X6A0));
    // 0x80675558: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
L_8067555C:
    // 0x8067555C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80675564: jr          $ra
    // 0x80675568: nop

    return;
    // 0x80675568: nop

    // 0x8067556C: nop

;}
RECOMP_FUNC void func_8003C190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C190: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8003C194: addiu       $v0, $v0, -0x2AB4
    ctx->r2 = ADD32(ctx->r2, -0X2AB4);
    // 0x8003C198: jr          $ra
    // 0x8003C19C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8003C19C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8069ACD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069ACD0: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(565, 0XC54) << 16);
    // 0x8069ACD4: addiu       $v0, $v0, -0x46DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(565, 0XC54));
    // 0x8069ACD8: jr          $ra
    // 0x8069ACDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8069ACDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807995A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807995A4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807995A8: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(826, 0X958) << 16);
    // 0x807995AC: addiu       $t6, $t6, -0x6B88
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(826, 0X958));
    // 0x807995B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807995B4: jr          $ra
    // 0x807995B8: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x807995B8: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void DmaMgr_RequestSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DF0C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8007DF10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007DF14: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8007DF18: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8007DF1C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x8007DF20: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8007DF24: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007DF28: jal         0x8008AE20
    // 0x8007DF2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007DF2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007DF30: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8007DF34: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007DF38: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8007DF3C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x8007DF40: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8007DF44: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8007DF48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007DF4C: jal         0x8007DE3C
    // 0x8007DF50: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    DmaMgr_SendRequest(rdram, ctx);
        goto after_1;
    // 0x8007DF50: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x8007DF54: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8007DF58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007DF5C: jal         0x800824B0
    // 0x8007DF60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007DF60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007DF64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007DF68: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8007DF6C: jr          $ra
    // 0x8007DF70: nop

    return;
    // 0x8007DF70: nop

;}
RECOMP_FUNC void func_80035900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035900: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80035904: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80035908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003590C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035914: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x80035918: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003591C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80035920: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80035924: bc1f        L_80035948
    if (!c1cs) {
        // 0x80035928: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_80035948;
    }
    // 0x80035928: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8003592C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80035930: lbu         $t7, -0x1568($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1568);
    // 0x80035934: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80035938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003593C: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x80035940: b           L_800359DC
    // 0x80035944: sw          $t9, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r25;
        goto L_800359DC;
    // 0x80035944: sw          $t9, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r25;
L_80035948:
    // 0x80035948: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003594C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80035950: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80035954: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x80035958: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8003595C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035960: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80035964: bc1f        L_800359DC
    if (!c1cs) {
        // 0x80035968: nop
    
            goto L_800359DC;
    }
    // 0x80035968: nop

    // 0x8003596C: lbu         $t1, -0x156C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X156C);
    // 0x80035970: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80035974: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80035978: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8003597C: jal         0x80067BBC
    // 0x80035980: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80035980: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80035984: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80035988: jal         0x80067818
    // 0x8003598C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8003598C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80035990: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80035994: lui         $at, 0xC208
    ctx->r1 = S32(0XC208 << 16);
    // 0x80035998: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003599C: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800359A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800359A4: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800359A8: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x800359AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800359B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800359B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800359B8: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x800359BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800359C0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800359C4: lw          $t9, 0x40($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X40);
    // 0x800359C8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800359CC: jalr        $t9
    // 0x800359D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800359D0: nop

    after_2:
    // 0x800359D4: b           L_800359DC
    // 0x800359D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800359DC;
    // 0x800359D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800359DC:
    // 0x800359DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800359E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800359E4: jr          $ra
    // 0x800359E8: nop

    return;
    // 0x800359E8: nop

;}
RECOMP_FUNC void func_80428D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428D54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80428D58: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80428D5C: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80428D60: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80428D64: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80428D68: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80428D6C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80428D70: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80428D74: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80428D78: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80428D7C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80428D80: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80428D84: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80428D88: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80428D8C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80428D90: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80428D94: jal         0x80045A34
    // 0x80428D98: addiu       $a1, $zero, 0xA58
    ctx->r5 = ADD32(0, 0XA58);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80428D98: addiu       $a1, $zero, 0xA58
    ctx->r5 = ADD32(0, 0XA58);
    after_0:
    // 0x80428D9C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80428DA0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80428DA4: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80428DA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80428DAC: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80428DB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80428DB4: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80428DB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80428DBC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80428DC0: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80428DC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80428DC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80428DCC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80428DD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80428DD4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80428DD8: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80428DDC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80428DE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80428DE4: lui         $at, 0x437C
    ctx->r1 = S32(0X437C << 16);
    // 0x80428DE8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80428DEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80428DF0: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x80428DF4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80428DF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80428DFC: lui         $at, 0x43A2
    ctx->r1 = S32(0X43A2 << 16);
    // 0x80428E00: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80428E04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80428E08: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80428E0C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x80428E10: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80428E14: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80428E18: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80428E1C: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x80428E20: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80428E24: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    // 0x80428E28: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80428E2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80428E30: jal         0x8042946C
    // 0x80428E34: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    func_8042946C(rdram, ctx);
        goto after_1;
    // 0x80428E34: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_1:
    // 0x80428E38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80428E3C: lui         $v1, 0xB800
    ctx->r3 = S32(0XB800 << 16);
    // 0x80428E40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80428E44: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80428E48: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80428E4C: sw          $v1, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->r3;
    // 0x80428E50: sw          $zero, 0x54($s6)
    MEM_W(0X54, ctx->r22) = 0;
    // 0x80428E54: mfc1        $s3, $f18
    ctx->r19 = (int32_t)ctx->f18.u32l;
    // 0x80428E58: sw          $v1, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r3;
    // 0x80428E5C: sw          $zero, 0x374($s6)
    MEM_W(0X374, ctx->r22) = 0;
    // 0x80428E60: sw          $zero, 0x690($s6)
    MEM_W(0X690, ctx->r22) = 0;
    // 0x80428E64: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x80428E68: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80428E6C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80428E70: addiu       $s7, $zero, 0x1F
    ctx->r23 = ADD32(0, 0X1F);
    // 0x80428E74: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_80428E78:
    // 0x80428E78: lwc1        $f22, 0x0($s5)
    ctx->f22.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80428E7C: add.s       $f24, $f22, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x80428E80: jal         0x80066E88
    // 0x80428E84: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80428E84: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_2:
    // 0x80428E88: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80428E8C: jal         0x80066DE4
    // 0x80428E90: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80428E90: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_3:
    // 0x80428E94: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80428E98: sub.s       $f24, $f22, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f22.fl - ctx->f28.fl;
    // 0x80428E9C: sh          $zero, 0x69C($s1)
    MEM_H(0X69C, ctx->r17) = 0;
    // 0x80428EA0: sh          $zero, 0x69E($s1)
    MEM_H(0X69E, ctx->r17) = 0;
    // 0x80428EA4: sh          $zero, 0x6A0($s1)
    MEM_H(0X6A0, ctx->r17) = 0;
    // 0x80428EA8: sh          $zero, 0x6A2($s1)
    MEM_H(0X6A2, ctx->r17) = 0;
    // 0x80428EAC: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80428EB0: sb          $s0, 0x6A4($s1)
    MEM_B(0X6A4, ctx->r17) = ctx->r16;
    // 0x80428EB4: sb          $s0, 0x6A5($s1)
    MEM_B(0X6A5, ctx->r17) = ctx->r16;
    // 0x80428EB8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80428EBC: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80428EC0: sb          $s0, 0x6A6($s1)
    MEM_B(0X6A6, ctx->r17) = ctx->r16;
    // 0x80428EC4: sb          $s0, 0x6A7($s1)
    MEM_B(0X6A7, ctx->r17) = ctx->r16;
    // 0x80428EC8: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80428ECC: sh          $zero, 0x87C($s1)
    MEM_H(0X87C, ctx->r17) = 0;
    // 0x80428ED0: sh          $zero, 0x87E($s1)
    MEM_H(0X87E, ctx->r17) = 0;
    // 0x80428ED4: sh          $zero, 0x880($s1)
    MEM_H(0X880, ctx->r17) = 0;
    // 0x80428ED8: sh          $zero, 0x882($s1)
    MEM_H(0X882, ctx->r17) = 0;
    // 0x80428EDC: sb          $s0, 0x884($s1)
    MEM_B(0X884, ctx->r17) = ctx->r16;
    // 0x80428EE0: sb          $s0, 0x885($s1)
    MEM_B(0X885, ctx->r17) = ctx->r16;
    // 0x80428EE4: sb          $s0, 0x886($s1)
    MEM_B(0X886, ctx->r17) = ctx->r16;
    // 0x80428EE8: sb          $s0, 0x887($s1)
    MEM_B(0X887, ctx->r17) = ctx->r16;
    // 0x80428EEC: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x80428EF0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80428EF4: sh          $v1, 0x698($s1)
    MEM_H(0X698, ctx->r17) = ctx->r3;
    // 0x80428EF8: sh          $v1, 0x878($s1)
    MEM_H(0X878, ctx->r17) = ctx->r3;
    // 0x80428EFC: sh          $a0, 0x69A($s1)
    MEM_H(0X69A, ctx->r17) = ctx->r4;
    // 0x80428F00: jal         0x80066E88
    // 0x80428F04: sh          $a0, 0x87A($s1)
    MEM_H(0X87A, ctx->r17) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x80428F04: sh          $a0, 0x87A($s1)
    MEM_H(0X87A, ctx->r17) = ctx->r4;
    after_4:
    // 0x80428F08: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80428F0C: jal         0x80066DE4
    // 0x80428F10: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x80428F10: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_5:
    // 0x80428F14: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x80428F18: addu        $v0, $s6, $t9
    ctx->r2 = ADD32(ctx->r22, ctx->r25);
    // 0x80428F1C: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80428F20: trunc.w.s   $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80428F24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80428F28: sh          $zero, 0x69C($v0)
    MEM_H(0X69C, ctx->r2) = 0;
    // 0x80428F2C: sh          $zero, 0x69E($v0)
    MEM_H(0X69E, ctx->r2) = 0;
    // 0x80428F30: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80428F34: sh          $zero, 0x6A0($v0)
    MEM_H(0X6A0, ctx->r2) = 0;
    // 0x80428F38: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80428F3C: sh          $zero, 0x6A2($v0)
    MEM_H(0X6A2, ctx->r2) = 0;
    // 0x80428F40: sb          $s0, 0x6A4($v0)
    MEM_B(0X6A4, ctx->r2) = ctx->r16;
    // 0x80428F44: sb          $s0, 0x6A5($v0)
    MEM_B(0X6A5, ctx->r2) = ctx->r16;
    // 0x80428F48: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80428F4C: sb          $s0, 0x6A6($v0)
    MEM_B(0X6A6, ctx->r2) = ctx->r16;
    // 0x80428F50: sb          $s0, 0x6A7($v0)
    MEM_B(0X6A7, ctx->r2) = ctx->r16;
    // 0x80428F54: sh          $zero, 0x87C($v0)
    MEM_H(0X87C, ctx->r2) = 0;
    // 0x80428F58: sh          $zero, 0x87E($v0)
    MEM_H(0X87E, ctx->r2) = 0;
    // 0x80428F5C: sh          $zero, 0x880($v0)
    MEM_H(0X880, ctx->r2) = 0;
    // 0x80428F60: sh          $zero, 0x882($v0)
    MEM_H(0X882, ctx->r2) = 0;
    // 0x80428F64: sb          $s0, 0x884($v0)
    MEM_B(0X884, ctx->r2) = ctx->r16;
    // 0x80428F68: sb          $s0, 0x885($v0)
    MEM_B(0X885, ctx->r2) = ctx->r16;
    // 0x80428F6C: sb          $s0, 0x886($v0)
    MEM_B(0X886, ctx->r2) = ctx->r16;
    // 0x80428F70: sb          $s0, 0x887($v0)
    MEM_B(0X887, ctx->r2) = ctx->r16;
    // 0x80428F74: sll         $t2, $s2, 4
    ctx->r10 = S32(ctx->r18 << 4);
    // 0x80428F78: sh          $v1, 0x698($v0)
    MEM_H(0X698, ctx->r2) = ctx->r3;
    // 0x80428F7C: sh          $v1, 0x878($v0)
    MEM_H(0X878, ctx->r2) = ctx->r3;
    // 0x80428F80: sh          $a0, 0x69A($v0)
    MEM_H(0X69A, ctx->r2) = ctx->r4;
    // 0x80428F84: sh          $a0, 0x87A($v0)
    MEM_H(0X87A, ctx->r2) = ctx->r4;
    // 0x80428F88: addu        $v0, $s6, $t2
    ctx->r2 = ADD32(ctx->r22, ctx->r10);
    // 0x80428F8C: addiu       $s4, $s4, 0x3
    ctx->r20 = ADD32(ctx->r20, 0X3);
    // 0x80428F90: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80428F94: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x80428F98: sh          $s3, 0x698($v0)
    MEM_H(0X698, ctx->r2) = ctx->r19;
    // 0x80428F9C: sh          $s3, 0x69A($v0)
    MEM_H(0X69A, ctx->r2) = ctx->r19;
    // 0x80428FA0: sh          $zero, 0x69C($v0)
    MEM_H(0X69C, ctx->r2) = 0;
    // 0x80428FA4: sh          $zero, 0x69E($v0)
    MEM_H(0X69E, ctx->r2) = 0;
    // 0x80428FA8: sh          $zero, 0x6A0($v0)
    MEM_H(0X6A0, ctx->r2) = 0;
    // 0x80428FAC: sh          $zero, 0x6A2($v0)
    MEM_H(0X6A2, ctx->r2) = 0;
    // 0x80428FB0: sb          $s0, 0x6A4($v0)
    MEM_B(0X6A4, ctx->r2) = ctx->r16;
    // 0x80428FB4: sb          $s0, 0x6A5($v0)
    MEM_B(0X6A5, ctx->r2) = ctx->r16;
    // 0x80428FB8: sb          $s0, 0x6A6($v0)
    MEM_B(0X6A6, ctx->r2) = ctx->r16;
    // 0x80428FBC: sb          $s0, 0x6A7($v0)
    MEM_B(0X6A7, ctx->r2) = ctx->r16;
    // 0x80428FC0: sh          $s3, 0x878($v0)
    MEM_H(0X878, ctx->r2) = ctx->r19;
    // 0x80428FC4: sh          $s3, 0x87A($v0)
    MEM_H(0X87A, ctx->r2) = ctx->r19;
    // 0x80428FC8: sh          $zero, 0x87C($v0)
    MEM_H(0X87C, ctx->r2) = 0;
    // 0x80428FCC: sh          $zero, 0x87E($v0)
    MEM_H(0X87E, ctx->r2) = 0;
    // 0x80428FD0: sh          $zero, 0x880($v0)
    MEM_H(0X880, ctx->r2) = 0;
    // 0x80428FD4: sh          $zero, 0x882($v0)
    MEM_H(0X882, ctx->r2) = 0;
    // 0x80428FD8: sb          $s0, 0x884($v0)
    MEM_B(0X884, ctx->r2) = ctx->r16;
    // 0x80428FDC: sb          $s0, 0x885($v0)
    MEM_B(0X885, ctx->r2) = ctx->r16;
    // 0x80428FE0: sb          $s0, 0x886($v0)
    MEM_B(0X886, ctx->r2) = ctx->r16;
    // 0x80428FE4: bne         $s4, $s7, L_80428E78
    if (ctx->r20 != ctx->r23) {
        // 0x80428FE8: sb          $s0, 0x887($v0)
        MEM_B(0X887, ctx->r2) = ctx->r16;
            goto L_80428E78;
    }
    // 0x80428FE8: sb          $s0, 0x887($v0)
    MEM_B(0X887, ctx->r2) = ctx->r16;
    // 0x80428FEC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80428FF0: lui         $t3, 0x8043
    ctx->r11 = S32(RELOC_HI16(41, 0X10F4) << 16);
    // 0x80428FF4: addiu       $t3, $t3, -0x75CC
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(41, 0X10F4));
    // 0x80428FF8: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80428FFC: sw          $t3, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r11;
    // 0x80429000: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80429004: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x80429008: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x8042900C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80429010: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80429014: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80429018: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8042901C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80429020: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80429024: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80429028: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8042902C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80429030: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80429034: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80429038: jr          $ra
    // 0x8042903C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8042903C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80790378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790380: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80790384: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80790388: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8079038C: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(817, 0X3898) << 16);
    // 0x80790390: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80790394: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80790398: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8079039C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807903A0: lw          $t8, 0x3BE8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(817, 0X3898));
    // 0x807903A4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807903A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807903AC: jal         0x80048490
    // 0x807903B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x807903B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x807903B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807903B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807903BC: jr          $ra
    // 0x807903C0: nop

    return;
    // 0x807903C0: nop

;}
RECOMP_FUNC void func_800057BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800057BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800057C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800057C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800057C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800057CC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800057D0: addiu       $a0, $a0, 0x6C28
    ctx->r4 = ADD32(ctx->r4, 0X6C28);
    // 0x800057D4: jal         0x80003698
    // 0x800057D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x800057D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800057DC: bne         $v0, $zero, L_800057F0
    if (ctx->r2 != 0) {
        // 0x800057E0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800057F0;
    }
    // 0x800057E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800057E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800057E8: b           L_80005800
    // 0x800057EC: sw          $zero, 0x7110($at)
    MEM_W(0X7110, ctx->r1) = 0;
        goto L_80005800;
    // 0x800057EC: sw          $zero, 0x7110($at)
    MEM_W(0X7110, ctx->r1) = 0;
L_800057F0:
    // 0x800057F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800057F4: addiu       $a0, $a0, 0x7108
    ctx->r4 = ADD32(ctx->r4, 0X7108);
    // 0x800057F8: jal         0x800036F0
    // 0x800057FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800036F0(rdram, ctx);
        goto after_1;
    // 0x800057FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80005800:
    // 0x80005800: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005804: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    // 0x80005808: jal         0x80003698
    // 0x8000580C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80003698(rdram, ctx);
        goto after_2;
    // 0x8000580C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80005810: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80005814: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x80005818: bne         $v0, $zero, L_80005828
    if (ctx->r2 != 0) {
        // 0x8000581C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80005828;
    }
    // 0x8000581C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80005820: b           L_80005840
    // 0x80005824: sw          $zero, 0x2694($v1)
    MEM_W(0X2694, ctx->r3) = 0;
        goto L_80005840;
    // 0x80005824: sw          $zero, 0x2694($v1)
    MEM_W(0X2694, ctx->r3) = 0;
L_80005828:
    // 0x80005828: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000582C: addiu       $a0, $a0, 0x739C
    ctx->r4 = ADD32(ctx->r4, 0X739C);
    // 0x80005830: jal         0x800036F0
    // 0x80005834: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800036F0(rdram, ctx);
        goto after_3;
    // 0x80005834: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80005838: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8000583C: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
L_80005840:
    // 0x80005840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005844: sw          $zero, 0x2688($v1)
    MEM_W(0X2688, ctx->r3) = 0;
    // 0x80005848: sw          $zero, 0x291C($v1)
    MEM_W(0X291C, ctx->r3) = 0;
    // 0x8000584C: jr          $ra
    // 0x80005850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804B6F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B6F7C: jal         0x804B6CE4
    // 0x804B6F80: addiu       $a1, $zero, 0x45AC
    ctx->r5 = ADD32(0, 0X45AC);
    func_804B6CE4(rdram, ctx);
        goto after_0;
    // 0x804B6F80: addiu       $a1, $zero, 0x45AC
    ctx->r5 = ADD32(0, 0X45AC);
    after_0:
    // 0x804B6F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6F8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804B6F90: jal         0x804B6FF0
    // 0x804B6F94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6F94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6FA0: jr          $ra
    // 0x804B6FA4: nop

    return;
    // 0x804B6FA4: nop

;}
RECOMP_FUNC void func_8001F7E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F7E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001F7EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F7F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F7F4: lwc1        $f4, 0x10C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8001F7F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001F7FC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8001F800: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8001F804: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001F808: jal         0x80065490
    // 0x8001F80C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8001F80C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001F810: jal         0x8001F27C
    // 0x8001F814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001F27C(rdram, ctx);
        goto after_1;
    // 0x8001F814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001F818: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8001F81C: jal         0x80065954
    // 0x8001F820: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8001F820: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8001F824: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8001F828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001F82C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001F830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001F834: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8001F838: nop

    // 0x8001F83C: bc1f        L_8001F84C
    if (!c1cs) {
        // 0x8001F840: nop
    
            goto L_8001F84C;
    }
    // 0x8001F840: nop

    // 0x8001F844: b           L_8001F85C
    // 0x8001F848: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
        goto L_8001F85C;
    // 0x8001F848: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
L_8001F84C:
    // 0x8001F84C: jal         0x80065490
    // 0x8001F850: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8001F850: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x8001F854: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001F858: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
L_8001F85C:
    // 0x8001F85C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001F860: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001F864: nop

    // 0x8001F868: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x8001F86C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F874: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001F878: jr          $ra
    // 0x8001F87C: nop

    return;
    // 0x8001F87C: nop

;}
RECOMP_FUNC void func_804347A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804347A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804347AC: lw          $t6, 0xB6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB6C);
    // 0x804347B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804347B4: slti        $at, $t7, 0x32
    ctx->r1 = SIGNED(ctx->r15) < 0X32 ? 1 : 0;
    // 0x804347B8: bne         $at, $zero, L_804347C4
    if (ctx->r1 != 0) {
        // 0x804347BC: sw          $t7, 0xB6C($v0)
        MEM_W(0XB6C, ctx->r2) = ctx->r15;
            goto L_804347C4;
    }
    // 0x804347BC: sw          $t7, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = ctx->r15;
    // 0x804347C0: sw          $zero, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = 0;
L_804347C4:
    // 0x804347C4: jr          $ra
    // 0x804347C8: nop

    return;
    // 0x804347C8: nop

;}
RECOMP_FUNC void func_8002F92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F92C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F934: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F938: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F93C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F940: jal         0x8002F678
    // 0x8002F944: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F944: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F948: beq         $v0, $zero, L_8002F95C
    if (ctx->r2 == 0) {
        // 0x8002F94C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002F95C;
    }
    // 0x8002F94C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F950: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002F954: addiu       $t6, $t6, -0x1358
    ctx->r14 = ADD32(ctx->r14, -0X1358);
    // 0x8002F958: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002F95C:
    // 0x8002F95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F964: jr          $ra
    // 0x8002F968: nop

    return;
    // 0x8002F968: nop

;}
RECOMP_FUNC void func_8003048C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003048C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030490: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80030494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003049C: jal         0x80042880
    // 0x800304A0: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    func_80042880(rdram, ctx);
        goto after_0;
    // 0x800304A0: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    after_0:
    // 0x800304A4: jal         0x800592AC
    // 0x800304A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800592AC(rdram, ctx);
        goto after_1;
    // 0x800304A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800304AC: bnel        $v0, $zero, L_800304C8
    if (ctx->r2 != 0) {
        // 0x800304B0: lwc1        $f12, 0xC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_800304C8;
    }
    goto skip_0;
    // 0x800304B0: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x800304B4: jal         0x8002E7C8
    // 0x800304B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E7C8(rdram, ctx);
        goto after_2;
    // 0x800304B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800304BC: b           L_80030510
    // 0x800304C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80030510;
    // 0x800304C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800304C4: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
L_800304C8:
    // 0x800304C8: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800304CC: jal         0x80065ABC
    // 0x800304D0: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x800304D0: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x800304D4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x800304D8: jal         0x80028220
    // 0x800304DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_4;
    // 0x800304DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800304E0: jal         0x80065954
    // 0x800304E4: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x800304E4: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_5:
    // 0x800304E8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800304EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800304F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800304F4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800304F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800304FC: jal         0x80041214
    // 0x80030500: nop

    func_80041214(rdram, ctx);
        goto after_6;
    // 0x80030500: nop

    after_6:
    // 0x80030504: jal         0x8003A6F0
    // 0x80030508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A6F0(rdram, ctx);
        goto after_7;
    // 0x80030508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8003050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80030510:
    // 0x80030510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80030514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80030518: jr          $ra
    // 0x8003051C: nop

    return;
    // 0x8003051C: nop

;}
RECOMP_FUNC void func_80455AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455AE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455AE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455AEC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455AF0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80455AF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455AF8: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455AFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455B00: jal         0x8044EFA0
    // 0x80455B04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455B04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455B08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455B0C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455B10: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80455B14: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455B18: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455B1C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D60) << 16);
    // 0x80455B20: lw          $t9, -0x7EC0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D60));
    // 0x80455B24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455B28: jalr        $t9
    // 0x80455B2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80455B2C: nop

    after_1:
    // 0x80455B30: jal         0x804559B4
    // 0x80455B34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804559B4(rdram, ctx);
        goto after_2;
    // 0x80455B34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80455B38: jal         0x80445CBC
    // 0x80455B3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80445CBC(rdram, ctx);
        goto after_3;
    // 0x80455B3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80455B40: jal         0x80445CC4
    // 0x80455B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_4;
    // 0x80455B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80455B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455B4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455B50: jr          $ra
    // 0x80455B54: nop

    return;
    // 0x80455B54: nop

;}
RECOMP_FUNC void func_805847EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805847EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805847F0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805847F4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805847F8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805847FC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584800: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584804: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584808: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058480C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584810: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584814: jr          $ra
    // 0x80584818: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584818: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8045D590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045D590: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8045D594: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8045D598: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8045D59C: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8045D5A0: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8045D5A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045D5A8: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8045D5AC: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8045D5B0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8045D5B4: nop

    // 0x8045D5B8: bc1fl       L_8045D5D0
    if (!c1cs) {
        // 0x8045D5BC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8045D5D0;
    }
    goto skip_0;
    // 0x8045D5BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8045D5C0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045D5C4: b           L_8045D5EC
    // 0x8045D5C8: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
        goto L_8045D5EC;
    // 0x8045D5C8: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x8045D5CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8045D5D0:
    // 0x8045D5D0: nop

    // 0x8045D5D4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8045D5D8: nop

    // 0x8045D5DC: bc1fl       L_8045D5F0
    if (!c1cs) {
        // 0x8045D5E0: lwc1        $f0, 0x24($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
            goto L_8045D5F0;
    }
    goto skip_1;
    // 0x8045D5E0: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    skip_1:
    // 0x8045D5E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045D5E8: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
L_8045D5EC:
    // 0x8045D5EC: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
L_8045D5F0:
    // 0x8045D5F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8045D5F4: nop

    // 0x8045D5F8: bc1fl       L_8045D624
    if (!c1cs) {
        // 0x8045D5FC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8045D624;
    }
    goto skip_2;
    // 0x8045D5FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x8045D600: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8045D604: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8045D608: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8045D60C: nop

    // 0x8045D610: bc1f        L_8045D64C
    if (!c1cs) {
        // 0x8045D614: nop
    
            goto L_8045D64C;
    }
    // 0x8045D614: nop

    // 0x8045D618: b           L_8045D64C
    // 0x8045D61C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8045D64C;
    // 0x8045D61C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8045D620: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8045D624:
    // 0x8045D624: nop

    // 0x8045D628: bc1f        L_8045D64C
    if (!c1cs) {
        // 0x8045D62C: nop
    
            goto L_8045D64C;
    }
    // 0x8045D62C: nop

    // 0x8045D630: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8045D634: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8045D638: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8045D63C: nop

    // 0x8045D640: bc1f        L_8045D64C
    if (!c1cs) {
        // 0x8045D644: nop
    
            goto L_8045D64C;
    }
    // 0x8045D644: nop

    // 0x8045D648: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8045D64C:
    // 0x8045D64C: jr          $ra
    // 0x8045D650: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8045D650: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_80460E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460E80: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80460E84: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80460E88: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3730) << 16);
    // 0x80460E8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80460E90: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80460E94: lw          $t8, 0x3CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3730));
    // 0x80460E98: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80460E9C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80460EA0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80460EA4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80460EA8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80460EAC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80460EB0: beql        $v1, $zero, L_80460EE4
    if (ctx->r3 == 0) {
        // 0x80460EB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80460EE4;
    }
    goto skip_0;
    // 0x80460EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80460EB8: jalr        $v1
    // 0x80460EBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80460EBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80460EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80460EC4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80460EC8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80460ECC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80460ED0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80460ED4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80460ED8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80460EDC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80460EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80460EE4:
    // 0x80460EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460EE8: jr          $ra
    // 0x80460EEC: nop

    return;
    // 0x80460EEC: nop

;}
RECOMP_FUNC void func_8057DE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DE04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8057DE08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057DE0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057DE10: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057DE14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057DE18: addiu       $a1, $zero, 0x2D8
    ctx->r5 = ADD32(0, 0X2D8);
    // 0x8057DE1C: addiu       $t0, $a3, 0x210
    ctx->r8 = ADD32(ctx->r7, 0X210);
    // 0x8057DE20: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8057DE24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8057DE28: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8057DE2C: jal         0x80065728
    // 0x8057DE30: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8057DE30: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8057DE34: lui         $v1, 0x8058
    ctx->r3 = S32(RELOC_HI16(393, 0X10A0) << 16);
    // 0x8057DE38: addiu       $v1, $v1, -0x1420
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(393, 0X10A0));
    // 0x8057DE3C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8057DE40: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8057DE44: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8057DE48: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8057DE4C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8057DE50: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8057DE54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8057DE58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8057DE5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8057DE60: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8057DE64: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8057DE68: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8057DE6C: sw          $t7, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->r15;
    // 0x8057DE70: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8057DE74: sw          $t6, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r14;
    // 0x8057DE78: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8057DE7C: sw          $t9, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r25;
    // 0x8057DE80: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8057DE84: sw          $t8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r24;
    // 0x8057DE88: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8057DE8C: sw          $t9, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r25;
    // 0x8057DE90: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8057DE94: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x8057DE98: sw          $t8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r24;
L_8057DE9C:
    // 0x8057DE9C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8057DEA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057DEA4: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8057DEA8: sw          $t2, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = ctx->r10;
    // 0x8057DEAC: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8057DEB0: sw          $t1, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->r9;
    // 0x8057DEB4: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8057DEB8: sw          $t2, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->r10;
    // 0x8057DEBC: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8057DEC0: sw          $t1, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = ctx->r9;
    // 0x8057DEC4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8057DEC8: sw          $t4, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->r12;
    // 0x8057DECC: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8057DED0: sw          $t3, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->r11;
    // 0x8057DED4: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x8057DED8: sw          $t4, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->r12;
    // 0x8057DEDC: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8057DEE0: sw          $t3, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = ctx->r11;
    // 0x8057DEE4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8057DEE8: sw          $t6, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->r14;
    // 0x8057DEEC: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x8057DEF0: sw          $t5, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r13;
    // 0x8057DEF4: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8057DEF8: sw          $t6, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->r14;
    // 0x8057DEFC: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x8057DF00: sw          $t5, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r13;
    // 0x8057DF04: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8057DF08: sw          $t8, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r24;
    // 0x8057DF0C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8057DF10: sw          $t7, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r15;
    // 0x8057DF14: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8057DF18: sw          $t8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r24;
    // 0x8057DF1C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8057DF20: bne         $a0, $a1, L_8057DE9C
    if (ctx->r4 != ctx->r5) {
        // 0x8057DF24: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_8057DE9C;
    }
    // 0x8057DF24: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8057DF28: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8057DF2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8057DF30: addiu       $a1, $a3, 0x2C0
    ctx->r5 = ADD32(ctx->r7, 0X2C0);
    // 0x8057DF34: swc1        $f4, 0x2C0($a3)
    MEM_W(0X2C0, ctx->r7) = ctx->f4.u32l;
    // 0x8057DF38: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8057DF3C: swc1        $f8, 0x2D0($a3)
    MEM_W(0X2D0, ctx->r7) = ctx->f8.u32l;
    // 0x8057DF40: sw          $t9, 0x2CC($a3)
    MEM_W(0X2CC, ctx->r7) = ctx->r25;
    // 0x8057DF44: jal         0x8057DD6C
    // 0x8057DF48: swc1        $f6, 0x2C4($a3)
    MEM_W(0X2C4, ctx->r7) = ctx->f6.u32l;
    func_8057DD6C(rdram, ctx);
        goto after_1;
    // 0x8057DF48: swc1        $f6, 0x2C4($a3)
    MEM_W(0X2C4, ctx->r7) = ctx->f6.u32l;
    after_1:
    // 0x8057DF4C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8057DF50: addiu       $at, $zero, 0x41C7
    ctx->r1 = ADD32(0, 0X41C7);
    // 0x8057DF54: beq         $v0, $at, L_8057DF74
    if (ctx->r2 == ctx->r1) {
        // 0x8057DF58: addiu       $at, $zero, 0x41D0
        ctx->r1 = ADD32(0, 0X41D0);
            goto L_8057DF74;
    }
    // 0x8057DF58: addiu       $at, $zero, 0x41D0
    ctx->r1 = ADD32(0, 0X41D0);
    // 0x8057DF5C: bne         $v0, $at, L_8057DF84
    if (ctx->r2 != ctx->r1) {
        // 0x8057DF60: lui         $t1, 0x8058
        ctx->r9 = S32(RELOC_HI16(393, 0X1068) << 16);
            goto L_8057DF84;
    }
    // 0x8057DF60: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(393, 0X1068) << 16);
    // 0x8057DF64: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x8057DF68: addiu       $t1, $t1, -0x1458
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(393, 0X1068));
    // 0x8057DF6C: b           L_8057DF84
    // 0x8057DF70: sw          $t1, 0x2D4($t2)
    MEM_W(0X2D4, ctx->r10) = ctx->r9;
        goto L_8057DF84;
    // 0x8057DF70: sw          $t1, 0x2D4($t2)
    MEM_W(0X2D4, ctx->r10) = ctx->r9;
L_8057DF74:
    // 0x8057DF74: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x8057DF78: lui         $t3, 0x8058
    ctx->r11 = S32(RELOC_HI16(393, 0X1078) << 16);
    // 0x8057DF7C: addiu       $t3, $t3, -0x1448
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(393, 0X1078));
    // 0x8057DF80: sw          $t3, 0x2D4($t4)
    MEM_W(0X2D4, ctx->r12) = ctx->r11;
L_8057DF84:
    // 0x8057DF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057DF88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057DF8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8057DF90: jr          $ra
    // 0x8057DF94: nop

    return;
    // 0x8057DF94: nop

;}
RECOMP_FUNC void func_80473190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473190: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(161, 0X10) << 16);
    // 0x80473194: addiu       $v0, $v0, 0x31A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(161, 0X10));
    // 0x80473198: jr          $ra
    // 0x8047319C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8047319C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80052950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052958: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005295C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80052960: jal         0x8005BB78
    // 0x80052964: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_8005BB78(rdram, ctx);
        goto after_0;
    // 0x80052964: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80052968: beq         $v0, $zero, L_80052984
    if (ctx->r2 == 0) {
        // 0x8005296C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80052984;
    }
    // 0x8005296C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80052970: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80052974: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052978: sb          $t7, 0x74($t8)
    MEM_B(0X74, ctx->r24) = ctx->r15;
    // 0x8005297C: jal         0x80062518
    // 0x80052980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80062518(rdram, ctx);
        goto after_1;
    // 0x80052980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80052984:
    // 0x80052984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005298C: jr          $ra
    // 0x80052990: nop

    return;
    // 0x80052990: nop

;}
RECOMP_FUNC void func_80475E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475E74: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475E78: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475E7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475E80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475E84: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E28) << 16);
    // 0x80475E88: addiu       $a2, $a2, -0x4A18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E28));
    // 0x80475E8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80475E90: jal         0x80475B40
    // 0x80475E94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475E94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475E9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475EA0: jr          $ra
    // 0x80475EA4: nop

    return;
    // 0x80475EA4: nop

;}
RECOMP_FUNC void func_80056450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056450: jr          $ra
    // 0x80056454: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80056454: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80563D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80563D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80563D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80563D6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563D70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80563D74: lw          $v1, 0x51C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X51C);
    // 0x80563D78: lw          $t8, 0x528($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X528);
    // 0x80563D7C: lw          $t6, 0x524($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X524);
    // 0x80563D80: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80563D84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80563D88: lbu         $t3, 0x0($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X0);
    // 0x80563D8C: lbu         $t5, 0x1($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1);
    // 0x80563D90: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80563D94: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x80563D98: lw          $a2, 0x520($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X520);
    // 0x80563D9C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80563DA0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80563DA4: addu        $a3, $t4, $a2
    ctx->r7 = ADD32(ctx->r12, ctx->r6);
    // 0x80563DA8: beq         $t2, $zero, L_80563DD0
    if (ctx->r10 == 0) {
        // 0x80563DAC: addu        $t0, $t6, $a2
        ctx->r8 = ADD32(ctx->r14, ctx->r6);
            goto L_80563DD0;
    }
    // 0x80563DAC: addu        $t0, $t6, $a2
    ctx->r8 = ADD32(ctx->r14, ctx->r6);
    // 0x80563DB0: beq         $t2, $at, L_80563E8C
    if (ctx->r10 == ctx->r1) {
        // 0x80563DB4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80563E8C;
    }
    // 0x80563DB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80563DB8: beq         $t2, $at, L_80563F48
    if (ctx->r10 == ctx->r1) {
        // 0x80563DBC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80563F48;
    }
    // 0x80563DBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80563DC0: beql        $t2, $at, L_80564000
    if (ctx->r10 == ctx->r1) {
        // 0x80563DC4: lhu         $t4, 0x52C($v0)
        ctx->r12 = MEM_HU(ctx->r2, 0X52C);
            goto L_80564000;
    }
    goto skip_0;
    // 0x80563DC4: lhu         $t4, 0x52C($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X52C);
    skip_0:
    // 0x80563DC8: b           L_805640AC
    // 0x80563DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805640AC;
    // 0x80563DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80563DD0:
    // 0x80563DD0: lhu         $t7, 0x52C($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X52C);
    // 0x80563DD4: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2550) << 16);
    // 0x80563DD8: lwc1        $f0, 0x5DB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2550));
    // 0x80563DDC: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x80563DE0: sh          $t8, 0x52C($v0)
    MEM_H(0X52C, ctx->r2) = ctx->r24;
    // 0x80563DE4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563DE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80563DEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80563DF0: lhu         $t9, 0x52C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X52C);
    // 0x80563DF4: addiu       $t4, $zero, -0xC
    ctx->r12 = ADD32(0, -0XC);
    // 0x80563DF8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80563DFC: andi        $t3, $t9, 0xFFFE
    ctx->r11 = ctx->r25 & 0XFFFE;
    // 0x80563E00: sh          $t3, 0x52C($v1)
    MEM_H(0X52C, ctx->r3) = ctx->r11;
    // 0x80563E04: sw          $t4, 0x510($v0)
    MEM_W(0X510, ctx->r2) = ctx->r12;
    // 0x80563E08: swc1        $f4, 0x50C($v0)
    MEM_W(0X50C, ctx->r2) = ctx->f4.u32l;
    // 0x80563E0C: lh          $t5, 0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X2);
    // 0x80563E10: lh          $t6, 0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X2);
    // 0x80563E14: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80563E18: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80563E1C: nop

    // 0x80563E20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80563E24: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80563E28: swc1        $f10, 0x504($v0)
    MEM_W(0X504, ctx->r2) = ctx->f10.u32l;
    // 0x80563E2C: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80563E30: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80563E34: nop

    // 0x80563E38: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80563E3C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80563E40: swc1        $f4, 0x514($v0)
    MEM_W(0X514, ctx->r2) = ctx->f4.u32l;
    // 0x80563E44: lh          $t3, 0x0($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X0);
    // 0x80563E48: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80563E4C: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x80563E50: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80563E54: nop

    // 0x80563E58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80563E5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80563E60: swc1        $f10, 0x518($v0)
    MEM_W(0X518, ctx->r2) = ctx->f10.u32l;
    // 0x80563E64: lh          $t5, 0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X2);
    // 0x80563E68: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80563E6C: nop

    // 0x80563E70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80563E74: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80563E78: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80563E7C: jal         0x805657B0
    // 0x80563E80: nop

    func_805657B0(rdram, ctx);
        goto after_0;
    // 0x80563E80: nop

    after_0:
    // 0x80563E84: b           L_805640AC
    // 0x80563E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805640AC;
    // 0x80563E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80563E8C:
    // 0x80563E8C: lhu         $t6, 0x52C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X52C);
    // 0x80563E90: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2554) << 16);
    // 0x80563E94: lwc1        $f0, 0x5DB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2554));
    // 0x80563E98: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80563E9C: sh          $t7, 0x52C($v0)
    MEM_H(0X52C, ctx->r2) = ctx->r15;
    // 0x80563EA0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563EA4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80563EA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80563EAC: lhu         $t8, 0x52C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X52C);
    // 0x80563EB0: addiu       $t3, $zero, -0xC
    ctx->r11 = ADD32(0, -0XC);
    // 0x80563EB4: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x80563EB8: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80563EBC: sh          $t9, 0x52C($v1)
    MEM_H(0X52C, ctx->r3) = ctx->r25;
    // 0x80563EC0: sw          $t3, 0x510($v0)
    MEM_W(0X510, ctx->r2) = ctx->r11;
    // 0x80563EC4: swc1        $f6, 0x50C($v0)
    MEM_W(0X50C, ctx->r2) = ctx->f6.u32l;
    // 0x80563EC8: lh          $t5, 0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X2);
    // 0x80563ECC: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x80563ED0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80563ED4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80563ED8: nop

    // 0x80563EDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80563EE0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80563EE4: swc1        $f16, 0x504($v0)
    MEM_W(0X504, ctx->r2) = ctx->f16.u32l;
    // 0x80563EE8: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x80563EEC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80563EF0: nop

    // 0x80563EF4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80563EF8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80563EFC: swc1        $f6, 0x514($v0)
    MEM_W(0X514, ctx->r2) = ctx->f6.u32l;
    // 0x80563F00: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80563F04: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x80563F08: subu        $t3, $t8, $t9
    ctx->r11 = SUB32(ctx->r24, ctx->r25);
    // 0x80563F0C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80563F10: nop

    // 0x80563F14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80563F18: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80563F1C: swc1        $f16, 0x518($v0)
    MEM_W(0X518, ctx->r2) = ctx->f16.u32l;
    // 0x80563F20: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x80563F24: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80563F28: nop

    // 0x80563F2C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80563F30: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80563F34: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80563F38: jal         0x805657B0
    // 0x80563F3C: nop

    func_805657B0(rdram, ctx);
        goto after_1;
    // 0x80563F3C: nop

    after_1:
    // 0x80563F40: b           L_805640AC
    // 0x80563F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805640AC;
    // 0x80563F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80563F48:
    // 0x80563F48: lhu         $t5, 0x52C($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X52C);
    // 0x80563F4C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2558) << 16);
    // 0x80563F50: lwc1        $f0, 0x5DB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2558));
    // 0x80563F54: andi        $t6, $t5, 0xFFFD
    ctx->r14 = ctx->r13 & 0XFFFD;
    // 0x80563F58: sh          $t6, 0x52C($v0)
    MEM_H(0X52C, ctx->r2) = ctx->r14;
    // 0x80563F5C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563F60: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80563F64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80563F68: lhu         $t7, 0x52C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X52C);
    // 0x80563F6C: addiu       $t9, $zero, -0xC
    ctx->r25 = ADD32(0, -0XC);
    // 0x80563F70: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80563F74: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80563F78: sh          $t8, 0x52C($v1)
    MEM_H(0X52C, ctx->r3) = ctx->r24;
    // 0x80563F7C: sw          $t9, 0x510($v0)
    MEM_W(0X510, ctx->r2) = ctx->r25;
    // 0x80563F80: swc1        $f8, 0x50C($v0)
    MEM_W(0X50C, ctx->r2) = ctx->f8.u32l;
    // 0x80563F84: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x80563F88: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80563F8C: nop

    // 0x80563F90: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80563F94: swc1        $f16, 0x514($v0)
    MEM_W(0X514, ctx->r2) = ctx->f16.u32l;
    // 0x80563F98: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x80563F9C: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x80563FA0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80563FA4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80563FA8: nop

    // 0x80563FAC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80563FB0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80563FB4: swc1        $f6, 0x518($v0)
    MEM_W(0X518, ctx->r2) = ctx->f6.u32l;
    // 0x80563FB8: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80563FBC: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x80563FC0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80563FC4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80563FC8: nop

    // 0x80563FCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80563FD0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80563FD4: swc1        $f16, 0x504($v0)
    MEM_W(0X504, ctx->r2) = ctx->f16.u32l;
    // 0x80563FD8: lh          $t3, 0x0($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X0);
    // 0x80563FDC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80563FE0: nop

    // 0x80563FE4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80563FE8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80563FEC: jal         0x80565670
    // 0x80563FF0: nop

    func_80565670(rdram, ctx);
        goto after_2;
    // 0x80563FF0: nop

    after_2:
    // 0x80563FF4: b           L_805640AC
    // 0x80563FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805640AC;
    // 0x80563FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80563FFC: lhu         $t4, 0x52C($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X52C);
L_80564000:
    // 0x80564000: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X255C) << 16);
    // 0x80564004: lwc1        $f0, 0x5DBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X255C));
    // 0x80564008: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8056400C: sh          $t5, 0x52C($v0)
    MEM_H(0X52C, ctx->r2) = ctx->r13;
    // 0x80564010: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80564014: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80564018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8056401C: lhu         $t6, 0x52C($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X52C);
    // 0x80564020: addiu       $t8, $zero, -0xC
    ctx->r24 = ADD32(0, -0XC);
    // 0x80564024: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x80564028: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8056402C: sh          $t7, 0x52C($v1)
    MEM_H(0X52C, ctx->r3) = ctx->r15;
    // 0x80564030: sw          $t8, 0x510($v0)
    MEM_W(0X510, ctx->r2) = ctx->r24;
    // 0x80564034: swc1        $f4, 0x50C($v0)
    MEM_W(0X50C, ctx->r2) = ctx->f4.u32l;
    // 0x80564038: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x8056403C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80564040: nop

    // 0x80564044: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80564048: swc1        $f8, 0x514($v0)
    MEM_W(0X514, ctx->r2) = ctx->f8.u32l;
    // 0x8056404C: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x80564050: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x80564054: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80564058: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8056405C: nop

    // 0x80564060: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80564064: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80564068: swc1        $f18, 0x518($v0)
    MEM_W(0X518, ctx->r2) = ctx->f18.u32l;
    // 0x8056406C: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80564070: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x80564074: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80564078: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8056407C: nop

    // 0x80564080: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80564084: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80564088: swc1        $f8, 0x504($v0)
    MEM_W(0X504, ctx->r2) = ctx->f8.u32l;
    // 0x8056408C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80564090: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80564094: nop

    // 0x80564098: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8056409C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x805640A0: jal         0x80565670
    // 0x805640A4: nop

    func_80565670(rdram, ctx);
        goto after_3;
    // 0x805640A4: nop

    after_3:
    // 0x805640A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805640AC:
    // 0x805640AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805640B0: jr          $ra
    // 0x805640B4: nop

    return;
    // 0x805640B4: nop

;}
RECOMP_FUNC void func_8003CC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CC14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CC18: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8003CC1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CC20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003CC24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CC28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CC2C: sb          $a2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r6;
    // 0x8003CC30: jal         0x8004700C
    // 0x8003CC34: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003CC34: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8003CC38: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003CC3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003CC40: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x8003CC44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003CC48: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8003CC4C: nop

    // 0x8003CC50: bc1fl       L_8003CD04
    if (!c1cs) {
        // 0x8003CC54: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8003CD04;
    }
    goto skip_0;
    // 0x8003CC54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8003CC58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003CC5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CC60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003CC64: lwc1        $f10, 0x1F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1F4);
    // 0x8003CC68: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8003CC6C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003CC70: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8003CC74: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003CC78: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003CC7C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003CC80: nop

    // 0x8003CC84: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003CC88: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003CC8C: nop

    // 0x8003CC90: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8003CC94: beql        $t7, $zero, L_8003CCE4
    if (ctx->r15 == 0) {
        // 0x8003CC98: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_8003CCE4;
    }
    goto skip_1;
    // 0x8003CC98: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x8003CC9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003CCA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003CCA4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003CCA8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003CCAC: nop

    // 0x8003CCB0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003CCB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003CCB8: nop

    // 0x8003CCBC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8003CCC0: bne         $t7, $zero, L_8003CCD8
    if (ctx->r15 != 0) {
        // 0x8003CCC4: nop
    
            goto L_8003CCD8;
    }
    // 0x8003CCC4: nop

    // 0x8003CCC8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8003CCCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003CCD0: b           L_8003CCF0
    // 0x8003CCD4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8003CCF0;
    // 0x8003CCD4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8003CCD8:
    // 0x8003CCD8: b           L_8003CCF0
    // 0x8003CCDC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8003CCF0;
    // 0x8003CCDC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8003CCE0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_8003CCE4:
    // 0x8003CCE4: nop

    // 0x8003CCE8: bltz        $t7, L_8003CCD8
    if (SIGNED(ctx->r15) < 0) {
        // 0x8003CCEC: nop
    
            goto L_8003CCD8;
    }
    // 0x8003CCEC: nop

L_8003CCF0:
    // 0x8003CCF0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003CCF4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8003CCF8: b           L_8003CDA4
    // 0x8003CCFC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
        goto L_8003CDA4;
    // 0x8003CCFC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8003CD00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8003CD04:
    // 0x8003CD04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003CD08: lwc1        $f8, 0x1F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1F8);
    // 0x8003CD0C: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8003CD10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003CD14: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8003CD18: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003CD1C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8003CD20: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003CD24: nop

    // 0x8003CD28: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003CD2C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8003CD30: nop

    // 0x8003CD34: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8003CD38: beql        $t0, $zero, L_8003CD88
    if (ctx->r8 == 0) {
        // 0x8003CD3C: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_8003CD88;
    }
    goto skip_2;
    // 0x8003CD3C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x8003CD40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CD44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003CD48: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003CD4C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003CD50: nop

    // 0x8003CD54: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003CD58: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8003CD5C: nop

    // 0x8003CD60: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8003CD64: bne         $t0, $zero, L_8003CD7C
    if (ctx->r8 != 0) {
        // 0x8003CD68: nop
    
            goto L_8003CD7C;
    }
    // 0x8003CD68: nop

    // 0x8003CD6C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8003CD70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003CD74: b           L_8003CD94
    // 0x8003CD78: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8003CD94;
    // 0x8003CD78: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8003CD7C:
    // 0x8003CD7C: b           L_8003CD94
    // 0x8003CD80: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8003CD94;
    // 0x8003CD80: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8003CD84: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_8003CD88:
    // 0x8003CD88: nop

    // 0x8003CD8C: bltz        $t0, L_8003CD7C
    if (SIGNED(ctx->r8) < 0) {
        // 0x8003CD90: nop
    
            goto L_8003CD7C;
    }
    // 0x8003CD90: nop

L_8003CD94:
    // 0x8003CD94: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8003CD98: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003CD9C: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x8003CDA0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
L_8003CDA4:
    // 0x8003CDA4: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8003CDA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8003CDAC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8003CDB0: lwc1        $f4, -0x1328($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1328);
    // 0x8003CDB4: lwc1        $f18, 0x6C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8003CDB8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8003CDBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8003CDC0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003CDC4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8003CDC8: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8003CDCC: lwc1        $f10, -0x11E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X11E8);
    // 0x8003CDD0: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8003CDD4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8003CDD8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003CDDC: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x8003CDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CDE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CDE8: jr          $ra
    // 0x8003CDEC: nop

    return;
    // 0x8003CDEC: nop

;}
RECOMP_FUNC void func_805E4714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805E4718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E471C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4720: jal         0x805E4460
    // 0x805E4724: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805E4460(rdram, ctx);
        goto after_0;
    // 0x805E4724: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4728: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805E472C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805E4730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4734: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805E4738: addiu       $s0, $s0, 0xC4
    ctx->r16 = ADD32(ctx->r16, 0XC4);
    // 0x805E473C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805E4740: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805E4744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E4748: bc1f        L_805E4768
    if (!c1cs) {
        // 0x805E474C: nop
    
            goto L_805E4768;
    }
    // 0x805E474C: nop

    // 0x805E4750: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x805E4754: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805E4758: jal         0x805E4D78
    // 0x805E475C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_805E4D78(rdram, ctx);
        goto after_1;
    // 0x805E475C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x805E4760: b           L_805E4770
    // 0x805E4764: nop

        goto L_805E4770;
    // 0x805E4764: nop

L_805E4768:
    // 0x805E4768: jal         0x805E4378
    // 0x805E476C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805E4378(rdram, ctx);
        goto after_2;
    // 0x805E476C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_805E4770:
    // 0x805E4770: jal         0x805E4674
    // 0x805E4774: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805E4674(rdram, ctx);
        goto after_3;
    // 0x805E4774: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x805E4778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E477C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4780: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805E4784: jr          $ra
    // 0x805E4788: nop

    return;
    // 0x805E4788: nop

;}
RECOMP_FUNC void func_8001E264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E264: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001E268: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8001E26C: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x8001E270: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001E274: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001E278: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8001E27C: lbu         $t7, 0x209($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X209);
    // 0x8001E280: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001E284: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8001E288: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8001E28C: beq         $a1, $zero, L_8001E2CC
    if (ctx->r5 == 0) {
        // 0x8001E290: sb          $t8, 0x209($v0)
        MEM_B(0X209, ctx->r2) = ctx->r24;
            goto L_8001E2CC;
    }
    // 0x8001E290: sb          $t8, 0x209($v0)
    MEM_B(0X209, ctx->r2) = ctx->r24;
    // 0x8001E294: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
L_8001E298:
    // 0x8001E298: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E29C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001E2A0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001E2A4: andi        $a2, $a2, 0x7
    ctx->r6 = ctx->r6 & 0X7;
    // 0x8001E2A8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001E2AC: mflo        $t9
    ctx->r25 = lo;
    // 0x8001E2B0: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x8001E2B4: lhu         $v1, 0x1200($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X1200);
    // 0x8001E2B8: beq         $v1, $zero, L_8001E2C4
    if (ctx->r3 == 0) {
        // 0x8001E2BC: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8001E2C4;
    }
    // 0x8001E2BC: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8001E2C0: sh          $t0, 0x1200($v0)
    MEM_H(0X1200, ctx->r2) = ctx->r8;
L_8001E2C4:
    // 0x8001E2C4: bne         $a1, $zero, L_8001E298
    if (ctx->r5 != 0) {
        // 0x8001E2C8: andi        $a2, $a2, 0xFFFF
        ctx->r6 = ctx->r6 & 0XFFFF;
            goto L_8001E298;
    }
    // 0x8001E2C8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_8001E2CC:
    // 0x8001E2CC: jr          $ra
    // 0x8001E2D0: nop

    return;
    // 0x8001E2D0: nop

;}
RECOMP_FUNC void func_80433684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043368C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80433690: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80433694: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(65, 0X948) << 16);
    // 0x80433698: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043369C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804336A0: lw          $t8, 0x3728($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(65, 0X948));
    // 0x804336A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804336A8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804336AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804336B0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804336B4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804336B8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804336BC: beql        $v1, $zero, L_804336F0
    if (ctx->r3 == 0) {
        // 0x804336C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804336F0;
    }
    goto skip_0;
    // 0x804336C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804336C4: jalr        $v1
    // 0x804336C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804336C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804336CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804336D0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804336D4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804336D8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804336DC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804336E0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804336E4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804336E8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804336EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804336F0:
    // 0x804336F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804336F4: jr          $ra
    // 0x804336F8: nop

    return;
    // 0x804336F8: nop

    // 0x804336FC: nop

;}
RECOMP_FUNC void func_80786B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80786B60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786B64: lw          $v1, 0x16C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X16C);
    // 0x80786B68: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80786B6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786B70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80786B74: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80786B78: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80786B7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80786B80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80786B84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786B88: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80786B8C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80786B90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80786B94: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80786B98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80786B9C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80786BA0: lw          $t2, -0x7290($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7290);
    // 0x80786BA4: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x80786BA8: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80786BAC: lbu         $t3, 0x42($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X42);
    // 0x80786BB0: ori         $t0, $t0, 0x7008
    ctx->r8 = ctx->r8 | 0X7008;
    // 0x80786BB4: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x80786BB8: beq         $t3, $zero, L_80786C48
    if (ctx->r11 == 0) {
        // 0x80786BBC: addiu       $v1, $v1, 0xD
        ctx->r3 = ADD32(ctx->r3, 0XD);
            goto L_80786C48;
    }
    // 0x80786BBC: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x80786BC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786BC4: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80786BC8: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x80786BCC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80786BD0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80786BD4: ori         $t6, $zero, 0xAC80
    ctx->r14 = 0 | 0XAC80;
    // 0x80786BD8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80786BDC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80786BE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786BE4: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x80786BE8: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80786BEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80786BF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80786BF4: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80786BF8: ori         $t0, $t0, 0x4240
    ctx->r8 = ctx->r8 | 0X4240;
    // 0x80786BFC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80786C00: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80786C04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786C08: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80786C0C: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x80786C10: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80786C14: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80786C18: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80786C1C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80786C20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786C24: lui         $t4, 0xFF64
    ctx->r12 = S32(0XFF64 << 16);
    // 0x80786C28: lui         $t3, 0xFCFF
    ctx->r11 = S32(0XFCFF << 16);
    // 0x80786C2C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80786C30: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80786C34: ori         $t3, $t3, 0xB3FF
    ctx->r11 = ctx->r11 | 0XB3FF;
    // 0x80786C38: ori         $t4, $t4, 0xFE7F
    ctx->r12 = ctx->r12 | 0XFE7F;
    // 0x80786C3C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80786C40: b           L_80786CBC
    // 0x80786C44: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_80786CBC;
    // 0x80786C44: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80786C48:
    // 0x80786C48: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786C4C: ori         $t7, $zero, 0xAC80
    ctx->r15 = 0 | 0XAC80;
    // 0x80786C50: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80786C54: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80786C58: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80786C5C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80786C60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80786C64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786C68: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x80786C6C: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80786C70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80786C74: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80786C78: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80786C7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80786C80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786C84: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x80786C88: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x80786C8C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80786C90: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80786C94: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80786C98: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80786C9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786CA0: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x80786CA4: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x80786CA8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80786CAC: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80786CB0: ori         $t5, $t5, 0xF279
    ctx->r13 = ctx->r13 | 0XF279;
    // 0x80786CB4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80786CB8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80786CBC:
    // 0x80786CBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786CC0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80786CC4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80786CC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786CCC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80786CD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80786CD4: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x80786CD8: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x80786CDC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80786CE0: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80786CE4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80786CE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80786CEC: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x80786CF0: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80786CF4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80786CF8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80786CFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80786D00: jr          $ra
    // 0x80786D04: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    return;
    // 0x80786D04: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_8040DEAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DEAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040DEB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040DEB4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8040DEB8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8040DEBC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8040DEC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040DEC4: jal         0x80047058
    // 0x8040DEC8: lw          $s1, 0x88($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X88);
    func_80047058(rdram, ctx);
        goto after_0;
    // 0x8040DEC8: lw          $s1, 0x88($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X88);
    after_0:
    // 0x8040DECC: beq         $v0, $zero, L_8040DEF8
    if (ctx->r2 == 0) {
        // 0x8040DED0: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8040DEF8;
    }
    // 0x8040DED0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8040DED4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8040DED8: lw          $t7, -0x7250($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7250);
    // 0x8040DEDC: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(20, 0X1E74) << 16);
    // 0x8040DEE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8040DEE4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8040DEE8: lw          $t9, -0x1B8C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(20, 0X1E74));
    // 0x8040DEEC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8040DEF0: b           L_8040DEF8
    // 0x8040DEF4: addu        $a1, $t0, $s1
    ctx->r5 = ADD32(ctx->r8, ctx->r17);
        goto L_8040DEF8;
    // 0x8040DEF4: addu        $a1, $t0, $s1
    ctx->r5 = ADD32(ctx->r8, ctx->r17);
L_8040DEF8:
    // 0x8040DEF8: jal         0x8004590C
    // 0x8040DEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x8040DEFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8040DF00: jal         0x8040DCF0
    // 0x8040DF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040DCF0(rdram, ctx);
        goto after_2;
    // 0x8040DF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8040DF08: bne         $v0, $zero, L_8040DF20
    if (ctx->r2 != 0) {
        // 0x8040DF0C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8040DF20;
    }
    // 0x8040DF0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8040DF10: jal         0x800445A4
    // 0x8040DF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8040DF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8040DF18: b           L_8040DFC8
    // 0x8040DF1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8040DFC8;
    // 0x8040DF1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8040DF20:
    // 0x8040DF20: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040DF24: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8040DF28: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8040DF2C: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
    // 0x8040DF30: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x8040DF34: sh          $t3, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r11;
    // 0x8040DF38: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040DF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DF40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040DF44: jal         0x8040E254
    // 0x8040DF48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_4;
    // 0x8040DF48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8040DF4C: jal         0x80058958
    // 0x8040DF50: nop

    func_80058958(rdram, ctx);
        goto after_5;
    // 0x8040DF50: nop

    after_5:
    // 0x8040DF54: beq         $v0, $zero, L_8040DFC4
    if (ctx->r2 == 0) {
        // 0x8040DF58: lui         $t4, 0x8010
        ctx->r12 = S32(0X8010 << 16);
            goto L_8040DFC4;
    }
    // 0x8040DF58: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8040DF5C: lw          $t4, -0x7BC4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7BC4);
    // 0x8040DF60: lw          $t5, 0x10C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10C);
    // 0x8040DF64: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8040DF68: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x8040DF6C: beql        $t7, $zero, L_8040DFC8
    if (ctx->r15 == 0) {
        // 0x8040DF70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8040DFC8;
    }
    goto skip_0;
    // 0x8040DF70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8040DF74: jal         0x80056564
    // 0x8040DF78: nop

    func_80056564(rdram, ctx);
        goto after_6;
    // 0x8040DF78: nop

    after_6:
    // 0x8040DF7C: beq         $v0, $zero, L_8040DFC4
    if (ctx->r2 == 0) {
        // 0x8040DF80: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8040DFC4;
    }
    // 0x8040DF80: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8040DF84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DF88: jal         0x800457A0
    // 0x8040DF8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_7;
    // 0x8040DF8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8040DF90: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8040DF94: addiu       $t8, $zero, 0x1F
    ctx->r24 = ADD32(0, 0X1F);
    // 0x8040DF98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8040DF9C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8040DFA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8040DFA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8040DFA8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8040DFAC: jal         0x80056584
    // 0x8040DFB0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80056584(rdram, ctx);
        goto after_8;
    // 0x8040DFB0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_8:
    // 0x8040DFB4: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8040DFB8: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8040DFBC: addiu       $t0, $t0, 0x784C
    ctx->r8 = ADD32(ctx->r8, 0X784C);
    // 0x8040DFC0: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
L_8040DFC4:
    // 0x8040DFC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8040DFC8:
    // 0x8040DFC8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8040DFCC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8040DFD0: jr          $ra
    // 0x8040DFD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8040DFD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006A64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A64C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006A658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A65C: jal         0x80069CA0
    // 0x8006A660: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80069CA0(rdram, ctx);
        goto after_0;
    // 0x8006A660: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8006A664: jal         0x80050928
    // 0x8006A668: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_80050928(rdram, ctx);
        goto after_1;
    // 0x8006A668: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_1:
    // 0x8006A66C: jal         0x80050928
    // 0x8006A670: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_80050928(rdram, ctx);
        goto after_2;
    // 0x8006A670: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_2:
    // 0x8006A674: jal         0x80064E84
    // 0x8006A678: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x8006A678: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x8006A67C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x8006A680: beql        $v0, $zero, L_8006A6B4
    if (ctx->r2 == 0) {
        // 0x8006A684: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006A6B4;
    }
    goto skip_0;
    // 0x8006A684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006A688: jal         0x80064E84
    // 0x8006A68C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    func_80064E84(rdram, ctx);
        goto after_4;
    // 0x8006A68C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    after_4:
    // 0x8006A690: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8006A694: jal         0x80064E84
    // 0x8006A698: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    func_80064E84(rdram, ctx);
        goto after_5;
    // 0x8006A698: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    after_5:
    // 0x8006A69C: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8006A6A0: jal         0x80064E84
    // 0x8006A6A4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    func_80064E84(rdram, ctx);
        goto after_6;
    // 0x8006A6A4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    after_6:
    // 0x8006A6A8: jal         0x80064E84
    // 0x8006A6AC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_80064E84(rdram, ctx);
        goto after_7;
    // 0x8006A6AC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x8006A6B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006A6B4:
    // 0x8006A6B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A6B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A6BC: jr          $ra
    // 0x8006A6C0: nop

    return;
    // 0x8006A6C0: nop

;}
RECOMP_FUNC void func_80682B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80682B44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80682B48: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80682B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80682B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80682B54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80682B58: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80682B5C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80682B60: jal         0x8068293C
    // 0x80682B64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8068293C(rdram, ctx);
        goto after_0;
    // 0x80682B64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80682B68: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80682B6C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80682B70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80682B74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80682B78: jal         0x8068293C
    // 0x80682B7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8068293C(rdram, ctx);
        goto after_1;
    // 0x80682B7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80682B80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80682B84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682B88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80682B8C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80682B90: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80682B94: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80682B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80682B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80682BA0: jr          $ra
    // 0x80682BA4: nop

    return;
    // 0x80682BA4: nop

;}
RECOMP_FUNC void func_8064A158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A15C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A160: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8064A164: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X2CE4) << 16);
    // 0x8064A168: addiu       $t8, $t8, -0x324C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(495, 0X2CE4));
    // 0x8064A16C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064A170: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8064A174: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8064A178: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8064A17C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8064A180: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8064A184: beql        $v1, $zero, L_8064A1BC
    if (ctx->r3 == 0) {
        // 0x8064A188: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A1BC;
    }
    goto skip_0;
    // 0x8064A188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064A18C: jalr        $v1
    // 0x8064A190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8064A190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064A194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064A198: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8064A19C: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x8064A1A0: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x8064A1A4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8064A1A8: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x8064A1AC: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8064A1B0: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8064A1B4: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x8064A1B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064A1BC:
    // 0x8064A1BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A1C0: jr          $ra
    // 0x8064A1C4: nop

    return;
    // 0x8064A1C4: nop

;}
RECOMP_FUNC void func_8006E4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E4B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E4B8: jal         0x80081C64
    // 0x8006E4BC: lwc1        $f12, 0x8C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8C);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8006E4BC: lwc1        $f12, 0x8C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8C);
    after_0:
    // 0x8006E4C0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E4C4: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8006E4C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8006E4CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E4D0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006E4D4: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006E4D8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E4DC: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006E4E0: addiu       $a1, $a1, -0x1BBC
    ctx->r5 = ADD32(ctx->r5, -0X1BBC);
    // 0x8006E4E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006E4E8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8006E4EC: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006E4F0: div.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8006E4F4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8006E4F8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8006E4FC: jal         0x8006E154
    // 0x8006E500: nop

    func_8006E154(rdram, ctx);
        goto after_1;
    // 0x8006E500: nop

    after_1:
    // 0x8006E504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E50C: jr          $ra
    // 0x8006E510: nop

    return;
    // 0x8006E510: nop

;}
RECOMP_FUNC void func_80029C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029C60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029C68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80029C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029C70: jal         0x8004F5A4
    // 0x80029C74: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    func_8004F5A4(rdram, ctx);
        goto after_0;
    // 0x80029C74: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    after_0:
    // 0x80029C78: jal         0x8004F5A4
    // 0x80029C7C: addiu       $a0, $s0, 0xB0
    ctx->r4 = ADD32(ctx->r16, 0XB0);
    func_8004F5A4(rdram, ctx);
        goto after_1;
    // 0x80029C7C: addiu       $a0, $s0, 0xB0
    ctx->r4 = ADD32(ctx->r16, 0XB0);
    after_1:
    // 0x80029C80: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80029C84: jal         0x80065388
    // 0x80029C88: lwc1        $f14, 0xAC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XAC);
    func_80065388(rdram, ctx);
        goto after_2;
    // 0x80029C88: lwc1        $f14, 0xAC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XAC);
    after_2:
    // 0x80029C8C: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x80029C90: lwc1        $f12, 0x88($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80029C94: jal         0x80065388
    // 0x80029C98: lwc1        $f14, 0xB0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB0);
    func_80065388(rdram, ctx);
        goto after_3;
    // 0x80029C98: lwc1        $f14, 0xB0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB0);
    after_3:
    // 0x80029C9C: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x80029CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80029CA4: jal         0x80065490
    // 0x80029CA8: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x80029CA8: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_4:
    // 0x80029CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029CB8: jr          $ra
    // 0x80029CBC: nop

    return;
    // 0x80029CBC: nop

;}
RECOMP_FUNC void func_80001148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001148: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000114C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80001150: lui         $at, 0x1700
    ctx->r1 = S32(0X1700 << 16);
    // 0x80001154: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80001158: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000115C: jr          $ra
    // 0x80001160: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    return;
    // 0x80001160: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void func_8006593C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006593C: bgez        $a0, L_8006594C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80065940: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8006594C;
    }
    // 0x80065940: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80065944: jr          $ra
    // 0x80065948: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    return;
    // 0x80065948: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_8006594C:
    // 0x8006594C: jr          $ra
    // 0x80065950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8006EABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EAC4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8006EAC8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8006EACC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8006EAD0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8006EAD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006EAD8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8006EADC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006EAE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006EAE4: lw          $t8, 0x7F6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7F6C);
    // 0x8006EAE8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8006EAEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006EAF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006EAF4: jal         0x80048490
    // 0x8006EAF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8006EAF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8006EAFC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006EB00: jal         0x80048378
    // 0x8006EB04: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8006EB04: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8006EB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EB10: jr          $ra
    // 0x8006EB14: nop

    return;
    // 0x8006EB14: nop

;}
RECOMP_FUNC void func_80022AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022AC0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80022AC4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80022AC8: lh          $v0, 0xADE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XADE);
    // 0x80022ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022AD4: beq         $v0, $zero, L_80022AF4
    if (ctx->r2 == 0) {
        // 0x80022AD8: nop
    
            goto L_80022AF4;
    }
    // 0x80022AD8: nop

    // 0x80022ADC: blez        $v0, L_80022AEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022AE0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80022AEC;
    }
    // 0x80022AE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80022AE4: b           L_80022B10
    // 0x80022AE8: sb          $t6, 0xADC($v1)
    MEM_B(0XADC, ctx->r3) = ctx->r14;
        goto L_80022B10;
    // 0x80022AE8: sb          $t6, 0xADC($v1)
    MEM_B(0XADC, ctx->r3) = ctx->r14;
L_80022AEC:
    // 0x80022AEC: b           L_80022B10
    // 0x80022AF0: sb          $zero, 0xADC($v1)
    MEM_B(0XADC, ctx->r3) = 0;
        goto L_80022B10;
    // 0x80022AF0: sb          $zero, 0xADC($v1)
    MEM_B(0XADC, ctx->r3) = 0;
L_80022AF4:
    // 0x80022AF4: jal         0x8004700C
    // 0x80022AF8: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80022AF8: nop

    after_0:
    // 0x80022AFC: beql        $v0, $zero, L_80022B14
    if (ctx->r2 == 0) {
        // 0x80022B00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022B14;
    }
    goto skip_0;
    // 0x80022B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80022B04: lw          $t7, 0x138($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X138);
    // 0x80022B08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80022B0C: sb          $t7, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r15;
L_80022B10:
    // 0x80022B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80022B14:
    // 0x80022B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022B18: jr          $ra
    // 0x80022B1C: nop

    return;
    // 0x80022B1C: nop

;}
RECOMP_FUNC void func_8045B600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045B604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B608: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8045B60C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8045B610: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8045B614: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(104, 0XD28) << 16);
    // 0x8045B618: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045B61C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8045B620: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8045B624: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8045B628: lw          $t8, -0x48C8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(104, 0XD28));
    // 0x8045B62C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8045B630: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8045B634: jal         0x80048490
    // 0x8045B638: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8045B638: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8045B63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045B640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045B644: jr          $ra
    // 0x8045B648: nop

    return;
    // 0x8045B648: nop

;}
RECOMP_FUNC void func_80439218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439218: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8043921C: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(80, 0X19E0) << 16);
    // 0x80439220: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80439224: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80439228: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8043922C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80439230: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80439234: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80439238: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8043923C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80439240: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80439244: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80439248: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8043924C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80439250: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80439254: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80439258: addiu       $t6, $t6, -0x5B60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(80, 0X19E0));
    // 0x8043925C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80439260: lw          $fp, 0x1F4($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X1F4);
    // 0x80439264: addiu       $s7, $sp, 0x6C
    ctx->r23 = ADD32(ctx->r29, 0X6C);
    // 0x80439268: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x8043926C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80439270: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x80439274: addiu       $s4, $s4, 0x7EA0
    ctx->r20 = ADD32(ctx->r20, 0X7EA0);
    // 0x80439278: sw          $t7, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r15;
    // 0x8043927C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80439280: lw          $s6, 0x478($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X478);
    // 0x80439284: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80439288: sw          $t8, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r24;
    // 0x8043928C: lwc1        $f4, 0x30($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X30);
    // 0x80439290: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80439294: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80439298: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8043929C: lwc1        $f6, 0x34($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X34);
    // 0x804392A0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804392A4: addiu       $s5, $zero, 0x11
    ctx->r21 = ADD32(0, 0X11);
    // 0x804392A8: addiu       $s0, $fp, 0xA1C
    ctx->r16 = ADD32(ctx->r30, 0XA1C);
    // 0x804392AC: addiu       $s1, $fp, 0x974
    ctx->r17 = ADD32(ctx->r30, 0X974);
    // 0x804392B0: addiu       $s3, $fp, 0xD10
    ctx->r19 = ADD32(ctx->r30, 0XD10);
    // 0x804392B4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
L_804392B8:
    // 0x804392B8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x804392BC: lw          $t2, 0x478($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X478);
    // 0x804392C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804392C4: addu        $t1, $s7, $t0
    ctx->r9 = ADD32(ctx->r23, ctx->r8);
    // 0x804392C8: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x804392CC: lwc1        $f10, 0x38($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X38);
    // 0x804392D0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804392D4: jal         0x80081C64
    // 0x804392D8: add.s       $f12, $f16, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f24.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x804392D8: add.s       $f12, $f16, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f24.fl;
    after_0:
    // 0x804392DC: lw          $s2, 0x3F4($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X3F4);
    // 0x804392E0: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x804392E4: lw          $t6, 0x478($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X478);
    // 0x804392E8: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x804392EC: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x804392F0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x804392F4: div.s       $f20, $f26, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = DIV_S(ctx->f26.fl, ctx->f18.fl);
    // 0x804392F8: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x804392FC: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80439300: lwc1        $f16, 0xAC($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0XAC);
    // 0x80439304: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80439308: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x8043930C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80439310: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80439314: div.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80439318: add.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8043931C: mul.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80439320: jal         0x80081C64
    // 0x80439324: nop

    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80439324: nop

    after_1:
    // 0x80439328: lw          $s2, 0x3F4($s4)
    ctx->r18 = MEM_W(ctx->r20, 0X3F4);
    // 0x8043932C: lwc1        $f6, 0xB0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0XB0);
    // 0x80439330: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80439334: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80439338: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8043933C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80439340: div.s       $f20, $f26, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x80439344: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80439348: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8043934C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80439350: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80439354: lwc1        $f10, -0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, -0X8);
    // 0x80439358: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8043935C: sub.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80439360: div.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80439364: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80439368: lwc1        $f16, -0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8043936C: swc1        $f18, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80439370: lw          $t7, -0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, -0X4);
    // 0x80439374: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80439378: addu        $t9, $fp, $t8
    ctx->r25 = ADD32(ctx->r30, ctx->r24);
    // 0x8043937C: lwc1        $f10, 0xA08($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XA08);
    // 0x80439380: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80439384: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x80439388: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8043938C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80439390: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80439394: bgez        $s5, L_804392B8
    if (SIGNED(ctx->r21) >= 0) {
        // 0x80439398: swc1        $f18, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f18.u32l;
            goto L_804392B8;
    }
    // 0x80439398: swc1        $f18, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8043939C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x804393A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804393A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804393A8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804393AC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804393B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x804393B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x804393B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x804393BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x804393C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x804393C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x804393C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x804393CC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x804393D0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x804393D4: jr          $ra
    // 0x804393D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x804393D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80786D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80786D08: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80786D0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80786D10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80786D14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80786D18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80786D1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80786D20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80786D24: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x80786D28: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80786D2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80786D30: lw          $v0, 0x43E0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X43E0);
    // 0x80786D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80786D38: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80786D3C: sllv        $t8, $t7, $v0
    ctx->r24 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80786D40: sb          $t8, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r24;
    // 0x80786D44: lw          $t9, 0x168($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X168);
    // 0x80786D48: sllv        $s4, $t6, $v0
    ctx->r20 = S32(ctx->r14 << (ctx->r2 & 31));
    // 0x80786D4C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80786D50: lw          $t6, 0x88($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X88);
    // 0x80786D54: addiu       $s2, $v1, 0x520C
    ctx->r18 = ADD32(ctx->r3, 0X520C);
    // 0x80786D58: andi        $s4, $s4, 0xFF
    ctx->r20 = ctx->r20 & 0XFF;
    // 0x80786D5C: sw          $s2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r18;
    // 0x80786D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80786D64: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x80786D68: jal         0x8004921C
    // 0x80786D6C: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80786D6C: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80786D70: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80786D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80786D78: jal         0x8004921C
    // 0x80786D7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80786D7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80786D80: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80786D84: lh          $t9, 0x144($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X144);
    // 0x80786D88: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x80786D8C: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80786D90: lw          $t7, 0x168($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X168);
    // 0x80786D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80786D98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80786D9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80786DA0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x80786DA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80786DA8: nop

    // 0x80786DAC: nop

    // 0x80786DB0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80786DB4: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x80786DB8: mflo        $t6
    ctx->r14 = lo;
    // 0x80786DBC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80786DC0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80786DC4: lw          $t7, 0x43E0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X43E0);
    // 0x80786DC8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80786DCC: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80786DD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80786DD4: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80786DD8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80786DDC: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80786DE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80786DE4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80786DE8: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80786DEC: jal         0x8007711C
    // 0x80786DF0: addu        $s3, $v1, $t6
    ctx->r19 = ADD32(ctx->r3, ctx->r14);
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x80786DF0: addu        $s3, $v1, $t6
    ctx->r19 = ADD32(ctx->r3, ctx->r14);
    after_2:
    // 0x80786DF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786DF8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80786DFC: lui         $a3, 0xE600
    ctx->r7 = S32(0XE600 << 16);
    // 0x80786E00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80786E04: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80786E08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80786E0C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80786E10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786E14: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80786E18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80786E1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80786E20: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80786E24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80786E28: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80786E2C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80786E30: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80786E34: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80786E38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786E3C: lui         $ra, 0x404
    ctx->r31 = S32(0X404 << 16);
    // 0x80786E40: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x80786E44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80786E48: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80786E4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80786E50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80786E54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786E58: lui         $t7, 0x73E
    ctx->r15 = S32(0X73E << 16);
    // 0x80786E5C: ori         $t7, $t7, 0xF156
    ctx->r15 = ctx->r15 | 0XF156;
    // 0x80786E60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786E64: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80786E68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80786E6C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80786E70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786E74: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80786E78: ori         $t5, $t5, 0x81F
    ctx->r13 = ctx->r13 | 0X81F;
    // 0x80786E7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80786E80: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80786E84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80786E88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80786E8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786E90: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80786E94: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80786E98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786E9C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80786EA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80786EA4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80786EA8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786EAC: ori         $t7, $t7, 0xC00
    ctx->r15 = ctx->r15 | 0XC00;
    // 0x80786EB0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80786EB4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80786EB8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80786EBC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80786EC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80786EC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786EC8: lui         $t9, 0xB
    ctx->r25 = S32(0XB << 16);
    // 0x80786ECC: ori         $t9, $t9, 0xC0A4
    ctx->r25 = ctx->r25 | 0XC0A4;
    // 0x80786ED0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786ED4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80786ED8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80786EDC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80786EE0: lbu         $t2, 0x72($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X72);
    // 0x80786EE4: ori         $ra, $ra, 0x81F
    ctx->r31 = ctx->r31 | 0X81F;
    // 0x80786EE8: addiu       $s2, $zero, 0x604
    ctx->r18 = ADD32(0, 0X604);
    // 0x80786EEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80786EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80786EF4: addiu       $s1, $zero, 0x206
    ctx->r17 = ADD32(0, 0X206);
    // 0x80786EF8: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x80786EFC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
L_80786F00:
    // 0x80786F00: and         $t6, $t7, $t2
    ctx->r14 = ctx->r15 & ctx->r10;
    // 0x80786F04: beql        $t6, $zero, L_80786F38
    if (ctx->r14 == 0) {
        // 0x80786F08: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80786F38;
    }
    goto skip_0;
    // 0x80786F08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80786F0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80786F10:
    // 0x80786F10: sltiu       $at, $v1, 0xB4
    ctx->r1 = ctx->r3 < 0XB4 ? 1 : 0;
    // 0x80786F14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80786F18: beq         $at, $zero, L_80786FE4
    if (ctx->r1 == 0) {
        // 0x80786F1C: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80786FE4;
    }
    // 0x80786F1C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80786F20: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
    // 0x80786F24: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80786F28: and         $t7, $t9, $t2
    ctx->r15 = ctx->r25 & ctx->r10;
    // 0x80786F2C: bnel        $t7, $zero, L_80786F10
    if (ctx->r15 != 0) {
        // 0x80786F30: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80786F10;
    }
    goto skip_1;
    // 0x80786F30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80786F34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80786F38:
    // 0x80786F38: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80786F3C: addu        $a2, $t8, $s3
    ctx->r6 = ADD32(ctx->r24, ctx->r19);
    // 0x80786F40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786F44: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80786F48: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80786F4C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80786F50: lbu         $t0, 0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1);
    // 0x80786F54: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80786F58: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80786F5C: and         $t9, $t0, $t2
    ctx->r25 = ctx->r8 & ctx->r10;
    // 0x80786F60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80786F64: bne         $t9, $zero, L_80786FD8
    if (ctx->r25 != 0) {
        // 0x80786F68: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80786FD8;
    }
    // 0x80786F68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80786F6C: and         $t7, $t0, $s4
    ctx->r15 = ctx->r8 & ctx->r20;
    // 0x80786F70: bne         $t7, $zero, L_80786F9C
    if (ctx->r15 != 0) {
        // 0x80786F74: or          $a3, $s4, $zero
        ctx->r7 = ctx->r20 | 0;
            goto L_80786F9C;
    }
    // 0x80786F74: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80786F78: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
L_80786F7C:
    // 0x80786F7C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80786F80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80786F84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80786F88: and         $t8, $t6, $a3
    ctx->r24 = ctx->r14 & ctx->r7;
    // 0x80786F8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80786F90: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80786F94: beq         $t8, $zero, L_80786F7C
    if (ctx->r24 == 0) {
        // 0x80786F98: addiu       $a2, $a2, 0x20
        ctx->r6 = ADD32(ctx->r6, 0X20);
            goto L_80786F7C;
    }
    // 0x80786F98: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
L_80786F9C:
    // 0x80786F9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786FA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80786FA4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80786FA8: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80786FAC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80786FB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786FB4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80786FB8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80786FBC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80786FC0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80786FC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80786FC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80786FCC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80786FD0: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80786FD4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80786FD8:
    // 0x80786FD8: sltiu       $at, $v1, 0xB4
    ctx->r1 = ctx->r3 < 0XB4 ? 1 : 0;
    // 0x80786FDC: bnel        $at, $zero, L_80786F00
    if (ctx->r1 != 0) {
        // 0x80786FE0: lbu         $t7, 0x0($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X0);
            goto L_80786F00;
    }
    goto skip_2;
    // 0x80786FE0: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    skip_2:
L_80786FE4:
    // 0x80786FE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80786FE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80786FEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80786FF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80786FF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80786FF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80786FFC: jr          $ra
    // 0x80787000: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80787000: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void guLookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087338: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8008733C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80087340: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80087344: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80087348: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8008734C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80087350: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80087354: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80087358: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8008735C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80087360: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80087364: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80087368: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8008736C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80087370: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80087374: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80087378: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8008737C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80087380: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80087384: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80087388: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8008738C: jal         0x80087080
    // 0x80087390: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    guLookAtF(rdram, ctx);
        goto after_0;
    // 0x80087390: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80087394: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80087398: jal         0x80086DA0
    // 0x8008739C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8008739C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x800873A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800873A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800873A8: jr          $ra
    // 0x800873AC: nop

    return;
    // 0x800873AC: nop

;}
RECOMP_FUNC void func_806B22D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B22D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B22D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B22DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B22E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B22E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B22E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B22EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B22F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B22F4: addiu       $t6, $zero, 0xDD4
    ctx->r14 = ADD32(0, 0XDD4);
    // 0x806B22F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B22FC: addiu       $a2, $zero, 0xA50
    ctx->r6 = ADD32(0, 0XA50);
    // 0x806B2300: addiu       $a3, $zero, 0xC30
    ctx->r7 = ADD32(0, 0XC30);
    // 0x806B2304: addiu       $a1, $zero, 0x99C
    ctx->r5 = ADD32(0, 0X99C);
    // 0x806B2308: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B230C: jal         0x806B195C
    // 0x806B2310: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B2310: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B2314: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B2318: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B231C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B2320: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B2324: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B2328: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B232C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B2330: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B2334: jr          $ra
    // 0x806B2338: nop

    return;
    // 0x806B2338: nop

;}
RECOMP_FUNC void func_8043A7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043A7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043A7DC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043A7E0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8043A7E4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043A7E8: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(83, 0X115C) << 16);
    // 0x8043A7EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043A7F0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8043A7F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043A7F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043A7FC: lw          $t8, -0x4844($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(83, 0X115C));
    // 0x8043A800: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043A804: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043A808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043A80C: jal         0x80048490
    // 0x8043A810: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8043A810: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8043A814: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043A818: jal         0x80048378
    // 0x8043A81C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8043A81C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8043A820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043A824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043A828: jr          $ra
    // 0x8043A82C: nop

    return;
    // 0x8043A82C: nop

;}
RECOMP_FUNC void func_8078A240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A240: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8078A244: addiu       $at, $zero, 0x4410
    ctx->r1 = ADD32(0, 0X4410);
    // 0x8078A248: bne         $v0, $at, L_8078A258
    if (ctx->r2 != ctx->r1) {
        // 0x8078A24C: lui         $v0, 0x8079
        ctx->r2 = S32(RELOC_HI16(793, 0XAD4) << 16);
            goto L_8078A258;
    }
    // 0x8078A24C: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(793, 0XAD4) << 16);
    // 0x8078A250: jr          $ra
    // 0x8078A254: addiu       $v0, $v0, -0x52EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(793, 0XAD4));
    return;
    // 0x8078A254: addiu       $v0, $v0, -0x52EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(793, 0XAD4));
L_8078A258:
    // 0x8078A258: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(793, 0X978) << 16);
    // 0x8078A25C: addiu       $v0, $v0, -0x5448
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(793, 0X978));
    // 0x8078A260: jr          $ra
    // 0x8078A264: nop

    return;
    // 0x8078A264: nop

;}
RECOMP_FUNC void func_80031908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031908: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003190C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80031910: lbu         $t6, -0x7D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7D78);
    // 0x80031914: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80031918: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003191C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80031920: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80031924: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80031928: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003192C: bne         $t6, $zero, L_800319C4
    if (ctx->r14 != 0) {
        // 0x80031930: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_800319C4;
    }
    // 0x80031930: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80031934: jal         0x800421B4
    // 0x80031938: lw          $a1, 0x1F4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1F4);
    func_800421B4(rdram, ctx);
        goto after_0;
    // 0x80031938: lw          $a1, 0x1F4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1F4);
    after_0:
    // 0x8003193C: beq         $v0, $zero, L_800319C4
    if (ctx->r2 == 0) {
        // 0x80031940: lui         $s1, 0x800A
        ctx->r17 = S32(0X800A << 16);
            goto L_800319C4;
    }
    // 0x80031940: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80031944: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80031948: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8003194C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80031950: addiu       $s3, $s3, -0x1788
    ctx->r19 = ADD32(ctx->r19, -0X1788);
    // 0x80031954: addiu       $s1, $s1, -0x1790
    ctx->r17 = ADD32(ctx->r17, -0X1790);
    // 0x80031958: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8003195C:
    // 0x8003195C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80031960: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80031964: subu        $s2, $t7, $t8
    ctx->r18 = SUB32(ctx->r15, ctx->r24);
    // 0x80031968: jal         0x8006593C
    // 0x8003196C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x8003196C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80031970: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80031974: beq         $at, $zero, L_80031994
    if (ctx->r1 == 0) {
        // 0x80031978: nop
    
            goto L_80031994;
    }
    // 0x80031978: nop

    // 0x8003197C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80031980: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80031984: nop

    // 0x80031988: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003198C: b           L_800319B8
    // 0x80031990: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
        goto L_800319B8;
    // 0x80031990: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
L_80031994:
    // 0x80031994: blezl       $s2, L_800319B0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80031998: lwc1        $f16, 0x3C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_800319B0;
    }
    goto skip_0;
    // 0x80031998: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x8003199C: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800319A0: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800319A4: b           L_800319B8
    // 0x800319A8: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
        goto L_800319B8;
    // 0x800319A8: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x800319AC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
L_800319B0:
    // 0x800319B0: sub.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800319B4: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
L_800319B8:
    // 0x800319B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800319BC: bne         $s1, $s3, L_8003195C
    if (ctx->r17 != ctx->r19) {
        // 0x800319C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8003195C;
    }
    // 0x800319C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800319C4:
    // 0x800319C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800319C8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800319CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800319D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800319D4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800319D8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800319DC: jr          $ra
    // 0x800319E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800319E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80028B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028B64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028B68: lwc1        $f4, -0x230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X230);
    // 0x80028B6C: lwc1        $f0, 0xAC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80028B70: lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X34);
    // 0x80028B74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028B78: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80028B7C: nop

    // 0x80028B80: bc1tl       L_80028BA0
    if (c1cs) {
        // 0x80028B84: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80028BA0;
    }
    goto skip_0;
    // 0x80028B84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80028B88: lwc1        $f6, -0x22C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X22C);
    // 0x80028B8C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80028B90: nop

    // 0x80028B94: bc1fl       L_80028BEC
    if (!c1cs) {
        // 0x80028B98: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80028BEC;
    }
    goto skip_1;
    // 0x80028B98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80028B9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80028BA0:
    // 0x80028BA0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80028BA4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80028BA8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80028BAC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80028BB0: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80028BB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80028BB8: bc1f        L_80028BD8
    if (!c1cs) {
        // 0x80028BBC: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80028BD8;
    }
    // 0x80028BBC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80028BC0: lw          $t7, -0x227C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X227C);
    // 0x80028BC4: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80028BC8: bnel        $at, $zero, L_80028BEC
    if (ctx->r1 != 0) {
        // 0x80028BCC: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80028BEC;
    }
    goto skip_2;
    // 0x80028BCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x80028BD0: jr          $ra
    // 0x80028BD4: nop

    return;
    // 0x80028BD4: nop

L_80028BD8:
    // 0x80028BD8: lw          $t9, -0x2234($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2234);
    // 0x80028BDC: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80028BE0: beq         $at, $zero, L_80028BF4
    if (ctx->r1 == 0) {
        // 0x80028BE4: nop
    
            goto L_80028BF4;
    }
    // 0x80028BE4: nop

    // 0x80028BE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80028BEC:
    // 0x80028BEC: nop

    // 0x80028BF0: swc1        $f10, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f10.u32l;
L_80028BF4:
    // 0x80028BF4: jr          $ra
    // 0x80028BF8: nop

    return;
    // 0x80028BF8: nop

;}
RECOMP_FUNC void func_8057C590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C598: jal         0x8057BB68
    // 0x8057C59C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C59C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057C5A0: jal         0x8057BD84
    // 0x8057C5A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057BD84(rdram, ctx);
        goto after_1;
    // 0x8057C5A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057C5A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C5AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C5B0: jr          $ra
    // 0x8057C5B4: nop

    return;
    // 0x8057C5B4: nop

;}
RECOMP_FUNC void func_80519C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519C5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80519C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519C64: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80519C68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80519C6C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80519C70: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    // 0x80519C74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80519C78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80519C7C: jal         0x80519AFC
    // 0x80519C80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80519AFC(rdram, ctx);
        goto after_0;
    // 0x80519C80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80519C84: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80519C88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80519C8C: addiu       $t7, $zero, 0x112
    ctx->r15 = ADD32(0, 0X112);
    // 0x80519C90: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80519C94: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80519C98: addiu       $t9, $t9, -0x6030
    ctx->r25 = ADD32(ctx->r25, -0X6030);
    // 0x80519C9C: sh          $t7, 0x4C($t8)
    MEM_H(0X4C, ctx->r24) = ctx->r15;
    // 0x80519CA0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80519CA4: sw          $t9, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r25;
    // 0x80519CA8: lw          $t1, 0x180($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X180);
    // 0x80519CAC: beq         $t1, $zero, L_80519CC0
    if (ctx->r9 == 0) {
        // 0x80519CB0: nop
    
            goto L_80519CC0;
    }
    // 0x80519CB0: nop

    // 0x80519CB4: jal         0x8004816C
    // 0x80519CB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x80519CB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80519CBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80519CC0:
    // 0x80519CC0: jal         0x80517EBC
    // 0x80519CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80517EBC(rdram, ctx);
        goto after_2;
    // 0x80519CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80519CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519CCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80519CD0: jr          $ra
    // 0x80519CD4: nop

    return;
    // 0x80519CD4: nop

;}
RECOMP_FUNC void func_804B9E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B9E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B9E7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B9E80: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2AF0) << 16);
    // 0x804B9E84: lwc1        $f4, 0xB68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB68);
    // 0x804B9E88: lwc1        $f6, 0xB6C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB6C);
    // 0x804B9E8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804B9E90: swc1        $f8, 0xB68($v0)
    MEM_W(0XB68, ctx->r2) = ctx->f8.u32l;
    // 0x804B9E94: lwc1        $f16, -0x56F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2AF0));
    // 0x804B9E98: lwc1        $f10, 0xB68($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XB68);
    // 0x804B9E9C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804B9EA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804B9EA4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804B9EA8: swc1        $f18, 0xB68($v0)
    MEM_W(0XB68, ctx->r2) = ctx->f18.u32l;
    // 0x804B9EAC: lwc1        $f4, 0xB68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB68);
    // 0x804B9EB0: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x804B9EB4: lwc1        $f12, 0xB68($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XB68);
    // 0x804B9EB8: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x804B9EBC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804B9EC0: nop

    // 0x804B9EC4: bc1f        L_804B9EFC
    if (!c1cs) {
        // 0x804B9EC8: nop
    
            goto L_804B9EFC;
    }
    // 0x804B9EC8: nop

    // 0x804B9ECC: lwc1        $f0, 0xB6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB6C);
    // 0x804B9ED0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804B9ED4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2AF4) << 16);
    // 0x804B9ED8: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x804B9EDC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x804B9EE0: nop

    // 0x804B9EE4: bc1fl       L_804B9F24
    if (!c1cs) {
        // 0x804B9EE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B9F24;
    }
    goto skip_0;
    // 0x804B9EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B9EEC: lwc1        $f16, -0x56EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2AF4));
    // 0x804B9EF0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804B9EF4: b           L_804B9F20
    // 0x804B9EF8: swc1        $f18, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = ctx->f18.u32l;
        goto L_804B9F20;
    // 0x804B9EF8: swc1        $f18, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = ctx->f18.u32l;
L_804B9EFC:
    // 0x804B9EFC: jal         0x80066DE4
    // 0x804B9F00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x804B9F00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804B9F04: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2AF8) << 16);
    // 0x804B9F08: lwc1        $f6, -0x56E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2AF8));
    // 0x804B9F0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804B9F10: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804B9F14: lwc1        $f4, 0xB6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB6C);
    // 0x804B9F18: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804B9F1C: swc1        $f10, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = ctx->f10.u32l;
L_804B9F20:
    // 0x804B9F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B9F24:
    // 0x804B9F24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B9F28: jr          $ra
    // 0x804B9F2C: nop

    return;
    // 0x804B9F2C: nop

;}
RECOMP_FUNC void func_80011360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011360: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80011364: sw          $zero, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = 0;
    // 0x80011368: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001136C: sw          $zero, -0x6D6C($at)
    MEM_W(-0X6D6C, ctx->r1) = 0;
    // 0x80011370: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80011374: jr          $ra
    // 0x80011378: sw          $zero, -0x6D68($at)
    MEM_W(-0X6D68, ctx->r1) = 0;
    return;
    // 0x80011378: sw          $zero, -0x6D68($at)
    MEM_W(-0X6D68, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8005B940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B948: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005B94C: addiu       $a0, $a0, -0x4BB0
    ctx->r4 = ADD32(ctx->r4, -0X4BB0);
    // 0x8005B950: ori         $a1, $zero, 0xCC30
    ctx->r5 = 0 | 0XCC30;
    // 0x8005B954: jal         0x800657CC
    // 0x8005B958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_0;
    // 0x8005B958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005B95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B964: jr          $ra
    // 0x8005B968: nop

    return;
    // 0x8005B968: nop

;}
RECOMP_FUNC void func_804BD8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD8EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BD8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD8F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804BD8F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x804BD8FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804BD900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BD904: lwc1        $f0, 0x50($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X50);
    // 0x804BD908: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x804BD90C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BD910: lw          $a1, 0x370($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X370);
    // 0x804BD914: bc1fl       L_804BD948
    if (!c1cs) {
        // 0x804BD918: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_804BD948;
    }
    goto skip_0;
    // 0x804BD918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x804BD91C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BD920: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BD924: nop

    // 0x804BD928: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x804BD92C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804BD930: nop

    // 0x804BD934: bc1fl       L_804BD968
    if (!c1cs) {
        // 0x804BD938: swc1        $f0, 0x50($v1)
        MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
            goto L_804BD968;
    }
    goto skip_1;
    // 0x804BD938: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    skip_1:
    // 0x804BD93C: b           L_804BD964
    // 0x804BD940: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_804BD964;
    // 0x804BD940: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804BD944: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_804BD948:
    // 0x804BD948: nop

    // 0x804BD94C: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804BD950: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BD954: nop

    // 0x804BD958: bc1fl       L_804BD968
    if (!c1cs) {
        // 0x804BD95C: swc1        $f0, 0x50($v1)
        MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
            goto L_804BD968;
    }
    goto skip_2;
    // 0x804BD95C: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    skip_2:
    // 0x804BD960: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_804BD964:
    // 0x804BD964: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
L_804BD968:
    // 0x804BD968: lwc1        $f0, 0x50($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X50);
    // 0x804BD96C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804BD970: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BD974: nop

    // 0x804BD978: bc1fl       L_804BD9AC
    if (!c1cs) {
        // 0x804BD97C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_804BD9AC;
    }
    goto skip_3;
    // 0x804BD97C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_3:
    // 0x804BD980: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804BD984: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BD988: nop

    // 0x804BD98C: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x804BD990: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804BD994: nop

    // 0x804BD998: bc1fl       L_804BD9CC
    if (!c1cs) {
        // 0x804BD99C: swc1        $f0, 0x50($a1)
        MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
            goto L_804BD9CC;
    }
    goto skip_4;
    // 0x804BD99C: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
    skip_4:
    // 0x804BD9A0: b           L_804BD9C8
    // 0x804BD9A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_804BD9C8;
    // 0x804BD9A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804BD9A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_804BD9AC:
    // 0x804BD9AC: nop

    // 0x804BD9B0: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x804BD9B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BD9B8: nop

    // 0x804BD9BC: bc1fl       L_804BD9CC
    if (!c1cs) {
        // 0x804BD9C0: swc1        $f0, 0x50($a1)
        MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
            goto L_804BD9CC;
    }
    goto skip_5;
    // 0x804BD9C0: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
    skip_5:
    // 0x804BD9C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_804BD9C8:
    // 0x804BD9C8: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
L_804BD9CC:
    // 0x804BD9CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804BD9D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x804BD9D4: lw          $t9, 0x48($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X48);
    // 0x804BD9D8: jalr        $t9
    // 0x804BD9DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804BD9DC: nop

    after_0:
    // 0x804BD9E0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804BD9E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804BD9E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804BD9EC: lwc1        $f16, 0x368($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X368);
    // 0x804BD9F0: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x804BD9F4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804BD9F8: swc1        $f4, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f4.u32l;
    // 0x804BD9FC: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x804BDA00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BDA04: nop

    // 0x804BDA08: bc1fl       L_804BDA44
    if (!c1cs) {
        // 0x804BDA0C: lwc1        $f18, 0xC($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
            goto L_804BDA44;
    }
    goto skip_6;
    // 0x804BDA0C: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    skip_6:
    // 0x804BDA10: lwc1        $f6, 0x368($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X368);
    // 0x804BDA14: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x804BDA18: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BDA1C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x804BDA20: nop

    // 0x804BDA24: bc1fl       L_804BDA70
    if (!c1cs) {
        // 0x804BDA28: lwc1        $f10, 0x36C($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
            goto L_804BDA70;
    }
    goto skip_7;
    // 0x804BDA28: lwc1        $f10, 0x36C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
    skip_7:
    // 0x804BDA2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BDA30: nop

    // 0x804BDA34: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804BDA38: b           L_804BDA6C
    // 0x804BDA3C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
        goto L_804BDA6C;
    // 0x804BDA3C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x804BDA40: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
L_804BDA44:
    // 0x804BDA44: lwc1        $f4, 0x368($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X368);
    // 0x804BDA48: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BDA4C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x804BDA50: nop

    // 0x804BDA54: bc1fl       L_804BDA70
    if (!c1cs) {
        // 0x804BDA58: lwc1        $f10, 0x36C($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
            goto L_804BDA70;
    }
    goto skip_8;
    // 0x804BDA58: lwc1        $f10, 0x36C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
    skip_8:
    // 0x804BDA5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BDA60: nop

    // 0x804BDA64: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804BDA68: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
L_804BDA6C:
    // 0x804BDA6C: lwc1        $f10, 0x36C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
L_804BDA70:
    // 0x804BDA70: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x804BDA74: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804BDA78: swc1        $f18, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f18.u32l;
    // 0x804BDA7C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x804BDA80: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BDA84: nop

    // 0x804BDA88: bc1fl       L_804BDAC4
    if (!c1cs) {
        // 0x804BDA8C: lwc1        $f16, 0x10($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
            goto L_804BDAC4;
    }
    goto skip_9;
    // 0x804BDA8C: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    skip_9:
    // 0x804BDA90: lwc1        $f4, 0x36C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x804BDA94: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x804BDA98: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BDA9C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804BDAA0: nop

    // 0x804BDAA4: bc1fl       L_804BDAF0
    if (!c1cs) {
        // 0x804BDAA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BDAF0;
    }
    goto skip_10;
    // 0x804BDAA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x804BDAAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BDAB0: nop

    // 0x804BDAB4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804BDAB8: b           L_804BDAEC
    // 0x804BDABC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
        goto L_804BDAEC;
    // 0x804BDABC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x804BDAC0: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
L_804BDAC4:
    // 0x804BDAC4: lwc1        $f18, 0x36C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x804BDAC8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BDACC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x804BDAD0: nop

    // 0x804BDAD4: bc1fl       L_804BDAF0
    if (!c1cs) {
        // 0x804BDAD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BDAF0;
    }
    goto skip_11;
    // 0x804BDAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x804BDADC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BDAE0: nop

    // 0x804BDAE4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804BDAE8: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_804BDAEC:
    // 0x804BDAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BDAF0:
    // 0x804BDAF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BDAF4: jr          $ra
    // 0x804BDAF8: nop

    return;
    // 0x804BDAF8: nop

;}
