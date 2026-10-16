#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8043A27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A27C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043A280: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043A284: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8043A288: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8043A28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043A290: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043A294: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043A298: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8043A29C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043A2A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043A2A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043A2A8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8043A2AC: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(80, 0X1A20) << 16);
    // 0x8043A2B0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043A2B4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8043A2B8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043A2BC: lw          $t2, -0x5B20($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(80, 0X1A20));
    // 0x8043A2C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043A2C4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8043A2C8: jal         0x80438B60
    // 0x8043A2CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80438B60(rdram, ctx);
        goto after_0;
    // 0x8043A2CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043A2D0: jal         0x80438AE8
    // 0x8043A2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80438AE8(rdram, ctx);
        goto after_1;
    // 0x8043A2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043A2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043A2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043A2E0: jr          $ra
    // 0x8043A2E4: nop

    return;
    // 0x8043A2E4: nop

    // 0x8043A2E8: nop

    // 0x8043A2EC: nop

;}
RECOMP_FUNC void func_8000A214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A214: beq         $a1, $zero, L_8000A254
    if (ctx->r5 == 0) {
        // 0x8000A218: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8000A254;
    }
    // 0x8000A218: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000A21C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000A220: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000A224: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000A228: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000A22C: addiu       $t7, $t7, 0x4D10
    ctx->r15 = ADD32(ctx->r15, 0X4D10);
    // 0x8000A230: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8000A234: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000A238: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000A23C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000A240: sb          $t8, 0x2A31($v0)
    MEM_B(0X2A31, ctx->r2) = ctx->r24;
    // 0x8000A244: sh          $a1, 0x2A44($v0)
    MEM_H(0X2A44, ctx->r2) = ctx->r5;
    // 0x8000A248: sh          $a1, 0x2A42($v0)
    MEM_H(0X2A42, ctx->r2) = ctx->r5;
    // 0x8000A24C: swc1        $f0, 0x2A4C($v0)
    MEM_W(0X2A4C, ctx->r2) = ctx->f0.u32l;
    // 0x8000A250: swc1        $f0, 0x2A50($v0)
    MEM_W(0X2A50, ctx->r2) = ctx->f0.u32l;
L_8000A254:
    // 0x8000A254: jr          $ra
    // 0x8000A258: nop

    return;
    // 0x8000A258: nop

;}
RECOMP_FUNC void func_8043511C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043511C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80435120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80435124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80435128: jal         0x80045A34
    // 0x8043512C: addiu       $a1, $zero, 0xB70
    ctx->r5 = ADD32(0, 0XB70);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043512C: addiu       $a1, $zero, 0xB70
    ctx->r5 = ADD32(0, 0XB70);
    after_0:
    // 0x80435130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80435134: beq         $v0, $zero, L_8043514C
    if (ctx->r2 == 0) {
        // 0x80435138: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8043514C;
    }
    // 0x80435138: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8043513C: jal         0x804350F0
    // 0x80435140: nop

    func_804350F0(rdram, ctx);
        goto after_1;
    // 0x80435140: nop

    after_1:
    // 0x80435144: jal         0x80435094
    // 0x80435148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80435094(rdram, ctx);
        goto after_2;
    // 0x80435148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8043514C:
    // 0x8043514C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80435150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80435154: jr          $ra
    // 0x80435158: nop

    return;
    // 0x80435158: nop

;}
RECOMP_FUNC void func_8078743C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078743C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80787440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80787444: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80787448: lw          $t6, 0x52D4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X52D4);
    // 0x8078744C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80787450: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80787454: mflo        $t8
    ctx->r24 = lo;
    // 0x80787458: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8078745C: jal         0x80066DE4
    // 0x80787460: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80787460: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80787464: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80787468: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078746C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80787470: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80787474: lwc1        $f6, 0x52DC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X52DC);
    // 0x80787478: lwc1        $f18, 0x52D0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X52D0);
    // 0x8078747C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80787480: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80787484: lwc1        $f6, 0x52D8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X52D8);
    // 0x80787488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078748C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80787490: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80787494: jr          $ra
    // 0x80787498: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    return;
    // 0x80787498: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
;}
RECOMP_FUNC void func_8002C5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C5D0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C5D4: addiu       $a1, $a1, -0x2858
    ctx->r5 = ADD32(ctx->r5, -0X2858);
    // 0x8002C5D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C5DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C5E0: jal         0x80028118
    // 0x8002C5E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C5E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C5E8: jal         0x8002C4F0
    // 0x8002C5EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002C4F0(rdram, ctx);
        goto after_1;
    // 0x8002C5EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002C5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C5F8: jr          $ra
    // 0x8002C5FC: nop

    return;
    // 0x8002C5FC: nop

;}
RECOMP_FUNC void func_800322BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800322BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800322C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800322C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800322C8: lw          $a3, 0x164($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X164);
    // 0x800322CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800322D0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800322D4: beql        $a3, $zero, L_80032390
    if (ctx->r7 == 0) {
        // 0x800322D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80032390;
    }
    goto skip_0;
    // 0x800322D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800322DC: lbu         $t6, 0x155($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X155);
    // 0x800322E0: bnel        $t6, $zero, L_80032390
    if (ctx->r14 != 0) {
        // 0x800322E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80032390;
    }
    goto skip_1;
    // 0x800322E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800322E8: lhu         $t7, 0xC($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XC);
    // 0x800322EC: addiu       $at, $zero, 0x41DA
    ctx->r1 = ADD32(0, 0X41DA);
    // 0x800322F0: lw          $v1, 0x174($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X174);
    // 0x800322F4: bne         $t7, $at, L_80032314
    if (ctx->r15 != ctx->r1) {
        // 0x800322F8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032314;
    }
    // 0x800322F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800322FC: jal         0x80032284
    // 0x80032300: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80032284(rdram, ctx);
        goto after_0;
    // 0x80032300: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80032304: jal         0x8002D5EC
    // 0x80032308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002D5EC(rdram, ctx);
        goto after_1;
    // 0x80032308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003230C: b           L_80032390
    // 0x80032310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032390;
    // 0x80032310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032314:
    // 0x80032314: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80032318: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8003231C: lhu         $v0, 0x1C($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X1C);
    // 0x80032320: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x80032324: beq         $t9, $zero, L_80032360
    if (ctx->r25 == 0) {
        // 0x80032328: andi        $t0, $v0, 0x18
        ctx->r8 = ctx->r2 & 0X18;
            goto L_80032360;
    }
    // 0x80032328: andi        $t0, $v0, 0x18
    ctx->r8 = ctx->r2 & 0X18;
    // 0x8003232C: jal         0x800321DC
    // 0x80032330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800321DC(rdram, ctx);
        goto after_2;
    // 0x80032330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80032334: jal         0x8001D770
    // 0x80032338: nop

    func_8001D770(rdram, ctx);
        goto after_3;
    // 0x80032338: nop

    after_3:
    // 0x8003233C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80032340: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80032344: jal         0x80067BF8
    // 0x80032348: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_4;
    // 0x80032348: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8003234C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80032350: jal         0x80067818
    // 0x80032354: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80032354: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80032358: b           L_80032390
    // 0x8003235C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80032390;
    // 0x8003235C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80032360:
    // 0x80032360: bne         $t0, $zero, L_80032378
    if (ctx->r8 != 0) {
        // 0x80032364: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032378;
    }
    // 0x80032364: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032368: jal         0x80032258
    // 0x8003236C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80032258(rdram, ctx);
        goto after_6;
    // 0x8003236C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80032370: b           L_80032390
    // 0x80032374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032390;
    // 0x80032374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032378:
    // 0x80032378: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    // 0x8003237C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032380: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    // 0x80032384: jalr        $t9
    // 0x80032388: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80032388: nop

    after_7:
    // 0x8003238C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80032390:
    // 0x80032390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003239C: jr          $ra
    // 0x800323A0: nop

    return;
    // 0x800323A0: nop

;}
RECOMP_FUNC void func_80457164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80457164: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80457168: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8045716C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80457170: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80457174: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80457178: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8045717C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80457180: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80457184: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80457188: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(98, 0X13E18) << 16);
    // 0x8045718C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80457190: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80457194: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80457198: lw          $t1, -0x7E08($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(98, 0X13E18));
    // 0x8045719C: jr          $ra
    // 0x804571A0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804571A0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804571A4: nop

    // 0x804571A8: nop

    // 0x804571AC: nop

;}
RECOMP_FUNC void func_8076075C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076075C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760760: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760764: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760768: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076076C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760770: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760774: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760778: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076077C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760780: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760784: jr          $ra
    // 0x80760788: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760788: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80790E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790E20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80790E24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80790E28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80790E2C: jal         0x8004700C
    // 0x80790E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80790E34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80790E38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80790E3C: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80790E40: jal         0x80790CB4
    // 0x80790E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790CB4(rdram, ctx);
        goto after_1;
    // 0x80790E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80790E48: jal         0x80790714
    // 0x80790E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_2;
    // 0x80790E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80790E50: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790E58: slti        $at, $v1, 0xFA
    ctx->r1 = SIGNED(ctx->r3) < 0XFA ? 1 : 0;
    // 0x80790E5C: beql        $at, $zero, L_80790E74
    if (ctx->r1 == 0) {
        // 0x80790E60: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80790E74;
    }
    goto skip_0;
    // 0x80790E60: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_0:
    // 0x80790E64: jal         0x80790878
    // 0x80790E68: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_80790878(rdram, ctx);
        goto after_3;
    // 0x80790E68: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_3:
    // 0x80790E6C: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790E70: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_80790E74:
    // 0x80790E74: bnel        $v1, $at, L_80790E8C
    if (ctx->r3 != ctx->r1) {
        // 0x80790E78: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_80790E8C;
    }
    goto skip_1;
    // 0x80790E78: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    skip_1:
    // 0x80790E7C: jal         0x800677F8
    // 0x80790E80: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x80790E80: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_4:
    // 0x80790E84: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790E88: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
L_80790E8C:
    // 0x80790E8C: bne         $v1, $at, L_80790EB4
    if (ctx->r3 != ctx->r1) {
        // 0x80790E90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80790EB4;
    }
    // 0x80790E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790E94: jal         0x80790818
    // 0x80790E98: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_80790818(rdram, ctx);
        goto after_5;
    // 0x80790E98: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_5:
    // 0x80790E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790EA0: jal         0x80790878
    // 0x80790EA4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    func_80790878(rdram, ctx);
        goto after_6;
    // 0x80790EA4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_6:
    // 0x80790EA8: jal         0x800492C0
    // 0x80790EAC: addiu       $a0, $zero, -0x67
    ctx->r4 = ADD32(0, -0X67);
    func_800492C0(rdram, ctx);
        goto after_7;
    // 0x80790EAC: addiu       $a0, $zero, -0x67
    ctx->r4 = ADD32(0, -0X67);
    after_7:
    // 0x80790EB0: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
L_80790EB4:
    // 0x80790EB4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80790EB8: bne         $v1, $at, L_80790ED4
    if (ctx->r3 != ctx->r1) {
        // 0x80790EBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80790ED4;
    }
    // 0x80790EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790EC0: jal         0x80790818
    // 0x80790EC4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    func_80790818(rdram, ctx);
        goto after_8;
    // 0x80790EC4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_8:
    // 0x80790EC8: jal         0x800677F8
    // 0x80790ECC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_800677F8(rdram, ctx);
        goto after_9;
    // 0x80790ECC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_9:
    // 0x80790ED0: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
L_80790ED4:
    // 0x80790ED4: addiu       $at, $zero, 0x159
    ctx->r1 = ADD32(0, 0X159);
    // 0x80790ED8: bnel        $v1, $at, L_80790F3C
    if (ctx->r3 != ctx->r1) {
        // 0x80790EDC: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_80790F3C;
    }
    goto skip_2;
    // 0x80790EDC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80790EE0: jal         0x8002FE38
    // 0x80790EE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8002FE38(rdram, ctx);
        goto after_10;
    // 0x80790EE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80790EE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80790EEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80790EF0: sb          $t6, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r14;
    // 0x80790EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790EF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80790EFC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80790F00: jal         0x8079393C
    // 0x80790F04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079393C(rdram, ctx);
        goto after_11;
    // 0x80790F04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80790F08: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80790F0C: lw          $t8, -0x7290($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7290);
    // 0x80790F10: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80790F14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80790F18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80790F1C: jal         0x8006CB1C
    // 0x80790F20: sb          $t7, 0x40($t8)
    MEM_B(0X40, ctx->r24) = ctx->r15;
    func_8006CB1C(rdram, ctx);
        goto after_12;
    // 0x80790F20: sb          $t7, 0x40($t8)
    MEM_B(0X40, ctx->r24) = ctx->r15;
    after_12:
    // 0x80790F24: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80790F28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80790F2C: jal         0x8006CB2C
    // 0x80790F30: nop

    func_8006CB2C(rdram, ctx);
        goto after_13;
    // 0x80790F30: nop

    after_13:
    // 0x80790F34: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790F38: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_80790F3C:
    // 0x80790F3C: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x80790F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80790F44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80790F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80790F4C: jr          $ra
    // 0x80790F50: nop

    return;
    // 0x80790F50: nop

;}
RECOMP_FUNC void func_80566F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566F5C: jal         0x80566E48
    // 0x80566F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80566F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566F64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566F68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80566F6C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80566F70: jal         0x805670F4
    // 0x80566F74: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_805670F4(rdram, ctx);
        goto after_1;
    // 0x80566F74: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x80566F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566F80: jr          $ra
    // 0x80566F84: nop

    return;
    // 0x80566F84: nop

;}
RECOMP_FUNC void func_8001D760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D760: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001D764: addiu       $v0, $v0, 0x36E0
    ctx->r2 = ADD32(ctx->r2, 0X36E0);
    // 0x8001D768: jr          $ra
    // 0x8001D76C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8001D76C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806F616C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F616C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6174: jal         0x806F6058
    // 0x806F6178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F6058(rdram, ctx);
        goto after_0;
    // 0x806F6178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F617C: jal         0x80058A14
    // 0x806F6180: nop

    func_80058A14(rdram, ctx);
        goto after_1;
    // 0x806F6180: nop

    after_1:
    // 0x806F6184: beq         $v0, $zero, L_806F61A0
    if (ctx->r2 == 0) {
        // 0x806F6188: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806F61A0;
    }
    // 0x806F6188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F618C: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
    // 0x806F6190: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x806F6194: ori         $t8, $t7, 0x18
    ctx->r24 = ctx->r15 | 0X18;
    // 0x806F6198: b           L_806F61B0
    // 0x806F619C: sb          $t8, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r24;
        goto L_806F61B0;
    // 0x806F619C: sb          $t8, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r24;
L_806F61A0:
    // 0x806F61A0: lbu         $t9, 0xE($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XE);
    // 0x806F61A4: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x806F61A8: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x806F61AC: sb          $t1, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r9;
L_806F61B0:
    // 0x806F61B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F61B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F61B8: jr          $ra
    // 0x806F61BC: nop

    return;
    // 0x806F61BC: nop

;}
RECOMP_FUNC void func_80080044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080044: jr          $ra
    // 0x80080048: nop

    return;
    // 0x80080048: nop

;}
RECOMP_FUNC void func_80470A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80470A28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80470A2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80470A30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80470A34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80470A38: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80470A3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80470A40: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80470A44: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(149, 0X1220) << 16);
    // 0x80470A48: sw          $a2, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r6;
    // 0x80470A4C: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x80470A50: addiu       $t6, $t6, 0xE30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(149, 0X1220));
    // 0x80470A54: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80470A58: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80470A5C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80470A60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80470A64: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x80470A68: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x80470A6C: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(149, 0XAA8) << 16);
    // 0x80470A70: addiu       $t8, $t8, 0x6B8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(149, 0XAA8));
    // 0x80470A74: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x80470A78: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80470A7C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80470A80: jal         0x80045A34
    // 0x80470A84: addiu       $a1, $zero, 0x1158
    ctx->r5 = ADD32(0, 0X1158);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80470A84: addiu       $a1, $zero, 0x1158
    ctx->r5 = ADD32(0, 0X1158);
    after_0:
    // 0x80470A88: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x80470A8C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80470A90: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80470A94: lw          $a0, 0x180($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X180);
    // 0x80470A98: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80470A9C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80470AA0: lh          $t7, 0x13E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X13E);
    // 0x80470AA4: lh          $t8, 0x13C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X13C);
    // 0x80470AA8: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x80470AAC: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470AB0: lw          $t8, 0x168($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X168);
    // 0x80470AB4: mflo        $t9
    ctx->r25 = lo;
    // 0x80470AB8: nop

    // 0x80470ABC: nop

    // 0x80470AC0: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470AC4: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x80470AC8: mflo        $t7
    ctx->r15 = lo;
    // 0x80470ACC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80470AD0: sw          $t6, 0x1094($v0)
    MEM_W(0X1094, ctx->r2) = ctx->r14;
    // 0x80470AD4: lw          $t8, 0x168($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X168);
    // 0x80470AD8: lw          $t7, 0x88($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X88);
    // 0x80470ADC: sw          $t7, 0x1098($v0)
    MEM_W(0X1098, ctx->r2) = ctx->r15;
    // 0x80470AE0: lh          $t9, 0x13C($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X13C);
    // 0x80470AE4: sw          $t9, 0x109C($v0)
    MEM_W(0X109C, ctx->r2) = ctx->r25;
    // 0x80470AE8: lh          $t6, 0x13E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13E);
    // 0x80470AEC: sw          $t6, 0x10A0($v0)
    MEM_W(0X10A0, ctx->r2) = ctx->r14;
    // 0x80470AF0: lh          $t1, 0x13C($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X13C);
    // 0x80470AF4: lh          $ra, 0x13E($a0)
    ctx->r31 = MEM_H(ctx->r4, 0X13E);
    // 0x80470AF8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80470AFC: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x80470B00: bgez        $t1, L_80470B0C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80470B04: addu        $at, $t1, $zero
        ctx->r1 = ADD32(ctx->r9, 0);
            goto L_80470B0C;
    }
    // 0x80470B04: addu        $at, $t1, $zero
    ctx->r1 = ADD32(ctx->r9, 0);
    // 0x80470B08: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
L_80470B0C:
    // 0x80470B0C: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80470B10: sll         $ra, $ra, 7
    ctx->r31 = S32(ctx->r31 << 7);
    // 0x80470B14: bgez        $ra, L_80470B20
    if (SIGNED(ctx->r31) >= 0) {
        // 0x80470B18: addu        $at, $ra, $zero
        ctx->r1 = ADD32(ctx->r31, 0);
            goto L_80470B20;
    }
    // 0x80470B18: addu        $at, $ra, $zero
    ctx->r1 = ADD32(ctx->r31, 0);
    // 0x80470B1C: addiu       $at, $ra, 0x7
    ctx->r1 = ADD32(ctx->r31, 0X7);
L_80470B20:
    // 0x80470B20: sra         $ra, $at, 3
    ctx->r31 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80470B24: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80470B28: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80470B2C: jal         0x80049018
    // 0x80470B30: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    func_80049018(rdram, ctx);
        goto after_1;
    // 0x80470B30: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80470B34: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80470B38: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80470B3C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80470B40: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80470B44: beq         $v0, $zero, L_80470B6C
    if (ctx->r2 == 0) {
        // 0x80470B48: lw          $ra, 0x20($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X20);
            goto L_80470B6C;
    }
    // 0x80470B48: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80470B4C: lh          $t8, 0x13C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X13C);
    // 0x80470B50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80470B54: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x80470B58: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470B5C: mflo        $t9
    ctx->r25 = lo;
    // 0x80470B60: sw          $t9, 0x108C($t2)
    MEM_W(0X108C, ctx->r10) = ctx->r25;
    // 0x80470B64: b           L_80470B88
    // 0x80470B68: lh          $t7, 0x13E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X13E);
        goto L_80470B88;
    // 0x80470B68: lh          $t7, 0x13E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X13E);
L_80470B6C:
    // 0x80470B6C: lh          $t6, 0x13C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13C);
    // 0x80470B70: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80470B74: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470B78: mflo        $t8
    ctx->r24 = lo;
    // 0x80470B7C: sw          $t8, 0x108C($t2)
    MEM_W(0X108C, ctx->r10) = ctx->r24;
    // 0x80470B80: nop

    // 0x80470B84: lh          $t7, 0x13E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X13E);
L_80470B88:
    // 0x80470B88: lw          $t6, 0x108C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X108C);
    // 0x80470B8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80470B90: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470B94: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x80470B98: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80470B9C: sw          $t7, 0x1084($t2)
    MEM_W(0X1084, ctx->r10) = ctx->r15;
    // 0x80470BA0: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x80470BA4: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80470BA8: mflo        $t9
    ctx->r25 = lo;
    // 0x80470BAC: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x80470BB0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80470BB4: sw          $t9, 0x1090($t2)
    MEM_W(0X1090, ctx->r10) = ctx->r25;
    // 0x80470BB8: sw          $t8, 0x1088($t2)
    MEM_W(0X1088, ctx->r10) = ctx->r24;
    // 0x80470BBC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80470BC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80470BC4:
    // 0x80470BC4: lw          $t0, 0x1088($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X1088);
    // 0x80470BC8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80470BCC:
    // 0x80470BCC: lw          $a0, 0x1084($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X1084);
    // 0x80470BD0: sb          $a2, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r6;
    // 0x80470BD4: sb          $a2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r6;
    // 0x80470BD8: sb          $a2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r6;
    // 0x80470BDC: sb          $a2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r6;
    // 0x80470BE0: sh          $a3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r7;
    // 0x80470BE4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80470BE8: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80470BEC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80470BF0: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x80470BF4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80470BF8: lw          $t7, 0x108C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X108C);
    // 0x80470BFC: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80470C00: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80470C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80470C08: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
L_80470C0C:
    // 0x80470C0C: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80470C10: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x80470C14: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80470C18: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80470C1C: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x80470C20: sh          $a3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r7;
    // 0x80470C24: sb          $a2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r6;
    // 0x80470C28: sb          $a2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r6;
    // 0x80470C2C: sb          $a2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r6;
    // 0x80470C30: sb          $a2, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r6;
    // 0x80470C34: lw          $t9, 0x108C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X108C);
    // 0x80470C38: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80470C3C: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // 0x80470C40: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80470C44: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    // 0x80470C48: sb          $a2, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r6;
    // 0x80470C4C: sb          $a2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r6;
    // 0x80470C50: sb          $a2, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r6;
    // 0x80470C54: sb          $a2, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r6;
    // 0x80470C58: sh          $a3, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r7;
    // 0x80470C5C: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x80470C60: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x80470C64: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x80470C68: lw          $t6, 0x108C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X108C);
    // 0x80470C6C: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80470C70: sh          $v1, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r3;
    // 0x80470C74: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80470C78: sh          $a0, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r4;
    // 0x80470C7C: sb          $a2, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r6;
    // 0x80470C80: sb          $a2, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r6;
    // 0x80470C84: sb          $a2, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r6;
    // 0x80470C88: sb          $a2, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r6;
    // 0x80470C8C: sh          $a3, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r7;
    // 0x80470C90: sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // 0x80470C94: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x80470C98: sh          $t0, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r8;
    // 0x80470C9C: lw          $t8, 0x108C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X108C);
    // 0x80470CA0: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80470CA4: sh          $v1, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r3;
    // 0x80470CA8: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80470CAC: sh          $a0, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r4;
    // 0x80470CB0: sb          $a2, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r6;
    // 0x80470CB4: sb          $a2, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = ctx->r6;
    // 0x80470CB8: sb          $a2, 0x3D($v0)
    MEM_B(0X3D, ctx->r2) = ctx->r6;
    // 0x80470CBC: sb          $a2, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r6;
    // 0x80470CC0: sh          $a3, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r7;
    // 0x80470CC4: sh          $zero, 0x36($v0)
    MEM_H(0X36, ctx->r2) = 0;
    // 0x80470CC8: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80470CCC: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // 0x80470CD0: lw          $t7, 0x108C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X108C);
    // 0x80470CD4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80470CD8: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80470CDC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80470CE0: bne         $a1, $t3, L_80470C0C
    if (ctx->r5 != ctx->r11) {
        // 0x80470CE4: addu        $a0, $a0, $t7
        ctx->r4 = ADD32(ctx->r4, ctx->r15);
            goto L_80470C0C;
    }
    // 0x80470CE4: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80470CE8: lw          $t9, 0x1090($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X1090);
    // 0x80470CEC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80470CF0: slti        $at, $t4, 0x9
    ctx->r1 = SIGNED(ctx->r12) < 0X9 ? 1 : 0;
    // 0x80470CF4: addu        $a3, $a3, $ra
    ctx->r7 = ADD32(ctx->r7, ctx->r31);
    // 0x80470CF8: bne         $at, $zero, L_80470BCC
    if (ctx->r1 != 0) {
        // 0x80470CFC: addu        $t0, $t0, $t9
        ctx->r8 = ADD32(ctx->r8, ctx->r25);
            goto L_80470BCC;
    }
    // 0x80470CFC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80470D00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80470D04: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80470D08: bnel        $at, $zero, L_80470BC4
    if (ctx->r1 != 0) {
        // 0x80470D0C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80470BC4;
    }
    goto skip_0;
    // 0x80470D0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_0:
    // 0x80470D10: lw          $t0, 0x1088($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X1088);
    // 0x80470D14: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80470D18: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80470D1C:
    // 0x80470D1C: lw          $a0, 0x1084($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X1084);
    // 0x80470D20: sh          $t0, 0xFE2($v0)
    MEM_H(0XFE2, ctx->r2) = ctx->r8;
    // 0x80470D24: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80470D28: sh          $a0, 0xF3E($v0)
    MEM_H(0XF3E, ctx->r2) = ctx->r4;
    // 0x80470D2C: lw          $t6, 0x108C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X108C);
    // 0x80470D30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80470D34: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
L_80470D38:
    // 0x80470D38: sh          $a0, 0xF40($v0)
    MEM_H(0XF40, ctx->r2) = ctx->r4;
    // 0x80470D3C: sh          $t0, 0xFE2($v0)
    MEM_H(0XFE2, ctx->r2) = ctx->r8;
    // 0x80470D40: lw          $t8, 0x108C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X108C);
    // 0x80470D44: sh          $t0, 0xFE4($v0)
    MEM_H(0XFE4, ctx->r2) = ctx->r8;
    // 0x80470D48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80470D4C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80470D50: sh          $a0, 0xF42($v0)
    MEM_H(0XF42, ctx->r2) = ctx->r4;
    // 0x80470D54: lw          $t7, 0x108C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X108C);
    // 0x80470D58: sh          $t0, 0xFE6($v0)
    MEM_H(0XFE6, ctx->r2) = ctx->r8;
    // 0x80470D5C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80470D60: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80470D64: sh          $a0, 0xF3C($v0)
    MEM_H(0XF3C, ctx->r2) = ctx->r4;
    // 0x80470D68: lw          $t9, 0x108C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X108C);
    // 0x80470D6C: sh          $t0, 0xFE0($v0)
    MEM_H(0XFE0, ctx->r2) = ctx->r8;
    // 0x80470D70: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80470D74: sh          $a0, 0xF3E($v0)
    MEM_H(0XF3E, ctx->r2) = ctx->r4;
    // 0x80470D78: lw          $t6, 0x108C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X108C);
    // 0x80470D7C: bne         $a1, $t3, L_80470D38
    if (ctx->r5 != ctx->r11) {
        // 0x80470D80: addu        $a0, $a0, $t6
        ctx->r4 = ADD32(ctx->r4, ctx->r14);
            goto L_80470D38;
    }
    // 0x80470D80: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80470D84: lw          $t8, 0x1090($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X1090);
    // 0x80470D88: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80470D8C: bne         $t4, $t3, L_80470D1C
    if (ctx->r12 != ctx->r11) {
        // 0x80470D90: addu        $t0, $t0, $t8
        ctx->r8 = ADD32(ctx->r8, ctx->r24);
            goto L_80470D1C;
    }
    // 0x80470D90: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80470D94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80470D98: jal         0x8046FC20
    // 0x80470D9C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    func_8046FC20(rdram, ctx);
        goto after_2;
    // 0x80470D9C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    after_2:
    // 0x80470DA0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80470DA4: addiu       $t7, $zero, 0x1388
    ctx->r15 = ADD32(0, 0X1388);
    // 0x80470DA8: addiu       $t9, $zero, 0x7D0
    ctx->r25 = ADD32(0, 0X7D0);
    // 0x80470DAC: sh          $t7, 0x1146($t2)
    MEM_H(0X1146, ctx->r10) = ctx->r15;
    // 0x80470DB0: sh          $t9, 0x1148($t2)
    MEM_H(0X1148, ctx->r10) = ctx->r25;
    // 0x80470DB4: sw          $zero, 0xF3C($t2)
    MEM_W(0XF3C, ctx->r10) = 0;
    // 0x80470DB8: sw          $zero, 0xF38($t2)
    MEM_W(0XF38, ctx->r10) = 0;
    // 0x80470DBC: lbu         $t6, 0x18($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X18);
    // 0x80470DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80470DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80470DC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80470DCC: jal         0x80470DE8
    // 0x80470DD0: sb          $t6, 0x114C($t2)
    MEM_B(0X114C, ctx->r10) = ctx->r14;
    func_80470DE8(rdram, ctx);
        goto after_3;
    // 0x80470DD0: sb          $t6, 0x114C($t2)
    MEM_B(0X114C, ctx->r10) = ctx->r14;
    after_3:
    // 0x80470DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80470DD8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80470DDC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80470DE0: jr          $ra
    // 0x80470DE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80470DE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806E3A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3A30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806E3A34: jr          $ra
    // 0x806E3A38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x806E3A38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80670B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670B40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80670B44: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80670B48: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80670B4C: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80670B50: lw          $t7, 0xF54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XF54);
    // 0x80670B54: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80670B58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80670B5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80670B60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80670B64: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80670B68: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80670B6C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80670B70: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80670B74: srl         $t9, $t8, 14
    ctx->r25 = S32(U32(ctx->r24) >> 14);
    // 0x80670B78: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80670B7C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80670B80: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    // 0x80670B84: lbu         $t0, 0xF5C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XF5C);
    // 0x80670B88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80670B8C: lw          $v0, 0x38($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X38);
    // 0x80670B90: lw          $v1, 0x3C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X3C);
    // 0x80670B94: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80670B98: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80670B9C: lw          $t1, 0xCE8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XCE8);
    // 0x80670BA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80670BA4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80670BA8: bnel        $t1, $zero, L_80670D28
    if (ctx->r9 != 0) {
        // 0x80670BAC: lw          $t4, 0xA68($s1)
        ctx->r12 = MEM_W(ctx->r17, 0XA68);
            goto L_80670D28;
    }
    goto skip_0;
    // 0x80670BAC: lw          $t4, 0xA68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XA68);
    skip_0:
L_80670BB0:
    // 0x80670BB0: lh          $t2, 0x20($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X20);
    // 0x80670BB4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80670BB8: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80670BBC: addiu       $t3, $t2, -0x40
    ctx->r11 = ADD32(ctx->r10, -0X40);
    // 0x80670BC0: sh          $t3, -0xA0($v0)
    MEM_H(-0XA0, ctx->r2) = ctx->r11;
    // 0x80670BC4: lh          $t4, 0x20($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X20);
    // 0x80670BC8: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x80670BCC: addiu       $t5, $t4, -0x40
    ctx->r13 = ADD32(ctx->r12, -0X40);
    // 0x80670BD0: sh          $t5, -0xA0($v1)
    MEM_H(-0XA0, ctx->r3) = ctx->r13;
    // 0x80670BD4: lh          $t7, -0x70($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X70);
    // 0x80670BD8: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x80670BDC: sh          $t8, -0x70($v0)
    MEM_H(-0X70, ctx->r2) = ctx->r24;
    // 0x80670BE0: lh          $t9, -0x70($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X70);
    // 0x80670BE4: addiu       $t6, $t9, -0x40
    ctx->r14 = ADD32(ctx->r25, -0X40);
    // 0x80670BE8: sh          $t6, -0x70($v1)
    MEM_H(-0X70, ctx->r3) = ctx->r14;
    // 0x80670BEC: lh          $t1, -0x40($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X40);
    // 0x80670BF0: addiu       $t2, $t1, -0x40
    ctx->r10 = ADD32(ctx->r9, -0X40);
    // 0x80670BF4: sh          $t2, -0x40($v0)
    MEM_H(-0X40, ctx->r2) = ctx->r10;
    // 0x80670BF8: lh          $t3, -0x40($v1)
    ctx->r11 = MEM_H(ctx->r3, -0X40);
    // 0x80670BFC: addiu       $t4, $t3, -0x40
    ctx->r12 = ADD32(ctx->r11, -0X40);
    // 0x80670C00: sh          $t4, -0x40($v1)
    MEM_H(-0X40, ctx->r3) = ctx->r12;
    // 0x80670C04: lh          $t5, -0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X10);
    // 0x80670C08: addiu       $t7, $t5, -0x40
    ctx->r15 = ADD32(ctx->r13, -0X40);
    // 0x80670C0C: sh          $t7, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r15;
    // 0x80670C10: lh          $t8, -0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, -0X10);
    // 0x80670C14: addiu       $t9, $t8, -0x40
    ctx->r25 = ADD32(ctx->r24, -0X40);
    // 0x80670C18: bne         $a0, $a1, L_80670BB0
    if (ctx->r4 != ctx->r5) {
        // 0x80670C1C: sh          $t9, -0x10($v1)
        MEM_H(-0X10, ctx->r3) = ctx->r25;
            goto L_80670BB0;
    }
    // 0x80670C1C: sh          $t9, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r25;
    // 0x80670C20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80670C24: lbu         $t6, 0xF6B($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XF6B);
    // 0x80670C28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80670C2C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80670C30: addiu       $a0, $zero, 0x4021
    ctx->r4 = ADD32(0, 0X4021);
    // 0x80670C34: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80670C38: beq         $t6, $at, L_80670CC8
    if (ctx->r14 == ctx->r1) {
        // 0x80670C3C: swc1        $f6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
            goto L_80670CC8;
    }
    // 0x80670C3C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80670C40: lw          $t1, 0xFB8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XFB8);
    // 0x80670C44: addiu       $a0, $zero, 0x4021
    ctx->r4 = ADD32(0, 0X4021);
    // 0x80670C48: addiu       $a1, $t0, 0x3C
    ctx->r5 = ADD32(ctx->r8, 0X3C);
    // 0x80670C4C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80670C50: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80670C54: bne         $t3, $zero, L_80670C98
    if (ctx->r11 != 0) {
        // 0x80670C58: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_80670C98;
    }
    // 0x80670C58: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80670C5C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2250) << 16);
    // 0x80670C60: lwc1        $f8, 0x2D80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2250));
    // 0x80670C64: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80670C68: lui         $a2, 0x8067
    ctx->r6 = S32(RELOC_HI16(526, 0X21D8) << 16);
    // 0x80670C6C: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x80670C70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80670C74: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80670C78: lw          $a2, 0x2D08($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(526, 0X21D8));
    // 0x80670C7C: addiu       $a0, $zero, 0x4021
    ctx->r4 = ADD32(0, 0X4021);
    // 0x80670C80: addiu       $a1, $t0, 0x3C
    ctx->r5 = ADD32(ctx->r8, 0X3C);
    // 0x80670C84: lui         $a3, 0xC28C
    ctx->r7 = S32(0XC28C << 16);
    // 0x80670C88: jal         0x8005CEBC
    // 0x80670C8C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_0;
    // 0x80670C8C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80670C90: b           L_80670CEC
    // 0x80670C94: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
        goto L_80670CEC;
    // 0x80670C94: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_80670C98:
    // 0x80670C98: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2254) << 16);
    // 0x80670C9C: lwc1        $f10, 0x2D84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2254));
    // 0x80670CA0: lui         $a2, 0x8067
    ctx->r6 = S32(RELOC_HI16(526, 0X21A0) << 16);
    // 0x80670CA4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80670CA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80670CAC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80670CB0: lw          $a2, 0x2CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(526, 0X21A0));
    // 0x80670CB4: lui         $a3, 0xC28C
    ctx->r7 = S32(0XC28C << 16);
    // 0x80670CB8: jal         0x8005CEBC
    // 0x80670CBC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x80670CBC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80670CC0: b           L_80670CEC
    // 0x80670CC4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
        goto L_80670CEC;
    // 0x80670CC4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_80670CC8:
    // 0x80670CC8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2258) << 16);
    // 0x80670CCC: lwc1        $f16, 0x2D88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2258));
    // 0x80670CD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80670CD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80670CD8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80670CDC: lui         $a3, 0xC28C
    ctx->r7 = S32(0XC28C << 16);
    // 0x80670CE0: jal         0x8005CEBC
    // 0x80670CE4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_2;
    // 0x80670CE4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80670CE8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_80670CEC:
    // 0x80670CEC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80670CF0: lw          $t1, 0x1F4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X1F4);
    // 0x80670CF4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80670CF8: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80670CFC: jal         0x80047F9C
    // 0x80670D00: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80670D00: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x80670D04: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X225C) << 16);
    // 0x80670D08: lwc1        $f18, 0x2D8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X225C));
    // 0x80670D0C: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x80670D10: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2260) << 16);
    // 0x80670D14: swc1        $f18, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f18.u32l;
    // 0x80670D18: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80670D1C: lwc1        $f4, 0x2D90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2260));
    // 0x80670D20: swc1        $f4, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f4.u32l;
    // 0x80670D24: lw          $t4, 0xA68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XA68);
L_80670D28:
    // 0x80670D28: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80670D2C: lw          $t9, 0xAC($t5)
    ctx->r25 = MEM_W(ctx->r13, 0XAC);
    // 0x80670D30: jalr        $t9
    // 0x80670D34: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80670D34: nop

    after_4:
    // 0x80670D38: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2264) << 16);
    // 0x80670D3C: lwc1        $f6, 0x2D94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2264));
    // 0x80670D40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80670D44: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x80670D48: jal         0x80047F9C
    // 0x80670D4C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x80670D4C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x80670D50: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2268) << 16);
    // 0x80670D54: lwc1        $f8, 0x2D98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2268));
    // 0x80670D58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80670D5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80670D60: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x80670D64: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x80670D68: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x80670D6C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80670D70: jal         0x8005CEBC
    // 0x80670D74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_6;
    // 0x80670D74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80670D78: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80670D7C: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x80670D80: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80670D84: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80670D88: jal         0x80047F9C
    // 0x80670D8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80670D8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80670D90: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X226C) << 16);
    // 0x80670D94: lwc1        $f0, 0x2D9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X226C));
    // 0x80670D98: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x80670D9C: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80670DA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80670DA4: swc1        $f0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f0.u32l;
    // 0x80670DA8: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x80670DAC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2270) << 16);
    // 0x80670DB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80670DB4: swc1        $f0, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f0.u32l;
    // 0x80670DB8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80670DBC: lwc1        $f4, 0x2DA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2270));
    // 0x80670DC0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80670DC4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80670DC8: addiu       $a0, $zero, 0x40F1
    ctx->r4 = ADD32(0, 0X40F1);
    // 0x80670DCC: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80670DD0: lui         $a2, 0x4258
    ctx->r6 = S32(0X4258 << 16);
    // 0x80670DD4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80670DD8: jal         0x8005CEBC
    // 0x80670DDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_8;
    // 0x80670DDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80670DE0: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80670DE4: lw          $t3, 0x1F4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1F4);
    // 0x80670DE8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80670DEC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80670DF0: jal         0x80047F9C
    // 0x80670DF4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x80670DF4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x80670DF8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2274) << 16);
    // 0x80670DFC: lwc1        $f0, 0x2DA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2274));
    // 0x80670E00: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x80670E04: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80670E08: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2278) << 16);
    // 0x80670E0C: swc1        $f0, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f0.u32l;
    // 0x80670E10: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x80670E14: addiu       $a0, $zero, 0x40F2
    ctx->r4 = ADD32(0, 0X40F2);
    // 0x80670E18: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80670E1C: swc1        $f0, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f0.u32l;
    // 0x80670E20: lw          $t9, -0x7478($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7478);
    // 0x80670E24: lui         $a2, 0x4258
    ctx->r6 = S32(0X4258 << 16);
    // 0x80670E28: lui         $a3, 0x4284
    ctx->r7 = S32(0X4284 << 16);
    // 0x80670E2C: beq         $t9, $zero, L_80670EE8
    if (ctx->r25 == 0) {
        // 0x80670E30: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80670EE8;
    }
    // 0x80670E30: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80670E34: lwc1        $f6, 0x2DA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2278));
    // 0x80670E38: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80670E3C: jal         0x8005CEBC
    // 0x80670E40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_10;
    // 0x80670E40: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80670E44: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80670E48: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x80670E4C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80670E50: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80670E54: jal         0x80047F9C
    // 0x80670E58: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x80670E58: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x80670E5C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X227C) << 16);
    // 0x80670E60: lwc1        $f8, 0x2DAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X227C));
    // 0x80670E64: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80670E68: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(526, 0X2280) << 16);
    // 0x80670E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80670E70: swc1        $f8, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f8.u32l;
    // 0x80670E74: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80670E78: lwc1        $f10, 0x2DB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(526, 0X2280));
    // 0x80670E7C: lui         $a1, 0x8067
    ctx->r5 = S32(RELOC_HI16(526, 0X21B8) << 16);
    // 0x80670E80: addiu       $a1, $a1, 0x2CE8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(526, 0X21B8));
    // 0x80670E84: swc1        $f10, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f10.u32l;
    // 0x80670E88: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    // 0x80670E8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80670E90: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80670E94: lw          $t3, 0x1F4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1F4);
    // 0x80670E98: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80670E9C: lw          $t4, 0xFB8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XFB8);
    // 0x80670EA0: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80670EA4: srl         $t9, $t5, 30
    ctx->r25 = S32(U32(ctx->r13) >> 30);
    // 0x80670EA8: bne         $v0, $t9, L_80670ED0
    if (ctx->r2 != ctx->r25) {
        // 0x80670EAC: nop
    
            goto L_80670ED0;
    }
    // 0x80670EAC: nop

    // 0x80670EB0: lui         $a1, 0x8067
    ctx->r5 = S32(RELOC_HI16(526, 0X2188) << 16);
    // 0x80670EB4: addiu       $a1, $a1, 0x2CB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(526, 0X2188));
    // 0x80670EB8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80670EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80670EC0: jal         0x8005C174
    // 0x80670EC4: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    func_8005C174(rdram, ctx);
        goto after_12;
    // 0x80670EC4: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    after_12:
    // 0x80670EC8: b           L_80670EDC
    // 0x80670ECC: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
        goto L_80670EDC;
    // 0x80670ECC: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
L_80670ED0:
    // 0x80670ED0: jal         0x8005C174
    // 0x80670ED4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_8005C174(rdram, ctx);
        goto after_13;
    // 0x80670ED4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_13:
    // 0x80670ED8: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
L_80670EDC:
    // 0x80670EDC: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x80670EE0: b           L_80670FB8
    // 0x80670EE4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_80670FB8;
    // 0x80670EE4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_80670EE8:
    // 0x80670EE8: lw          $v0, 0xF54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF54);
    // 0x80670EEC: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x80670EF0: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x80670EF4: beq         $t6, $zero, L_80670F44
    if (ctx->r14 == 0) {
        // 0x80670EF8: and         $t1, $v0, $at
        ctx->r9 = ctx->r2 & ctx->r1;
            goto L_80670F44;
    }
    // 0x80670EF8: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80670EFC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80670F00: sw          $t1, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r9;
    // 0x80670F04: ori         $t3, $t1, 0x100
    ctx->r11 = ctx->r9 | 0X100;
    // 0x80670F08: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80670F0C: sltiu       $at, $t5, 0x8
    ctx->r1 = ctx->r13 < 0X8 ? 1 : 0;
    // 0x80670F10: sw          $t3, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r11;
    // 0x80670F14: bne         $at, $zero, L_80670F24
    if (ctx->r1 != 0) {
        // 0x80670F18: sw          $t5, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r13;
            goto L_80670F24;
    }
    // 0x80670F18: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80670F1C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80670F20: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_80670F24:
    // 0x80670F24: lw          $t7, 0xF54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XF54);
    // 0x80670F28: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80670F2C: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80670F30: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x80670F34: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80670F38: sll         $t1, $t6, 14
    ctx->r9 = S32(ctx->r14 << 14);
    // 0x80670F3C: or          $v0, $t8, $t1
    ctx->r2 = ctx->r24 | ctx->r9;
    // 0x80670F40: sw          $v0, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r2;
L_80670F44:
    // 0x80670F44: andi        $t3, $v0, 0x400
    ctx->r11 = ctx->r2 & 0X400;
    // 0x80670F48: beq         $t3, $zero, L_80670F80
    if (ctx->r11 == 0) {
        // 0x80670F4C: addiu       $at, $zero, -0x401
        ctx->r1 = ADD32(0, -0X401);
            goto L_80670F80;
    }
    // 0x80670F4C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80670F50: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x80670F54: ori         $t9, $t4, 0x40
    ctx->r25 = ctx->r12 | 0X40;
    // 0x80670F58: sw          $t4, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r12;
    // 0x80670F5C: sw          $t9, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r25;
    // 0x80670F60: ori         $t6, $t9, 0x1000
    ctx->r14 = ctx->r25 | 0X1000;
    // 0x80670F64: sw          $t6, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r14;
    // 0x80670F68: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80670F6C: lw          $t8, -0x7498($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7498);
    // 0x80670F70: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80670F74: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80670F78: sw          $t1, -0x7498($at)
    MEM_W(-0X7498, ctx->r1) = ctx->r9;
    // 0x80670F7C: lw          $v0, 0xF54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XF54);
L_80670F80:
    // 0x80670F80: andi        $t2, $v0, 0x800
    ctx->r10 = ctx->r2 & 0X800;
    // 0x80670F84: beq         $t2, $zero, L_80670FB8
    if (ctx->r10 == 0) {
        // 0x80670F88: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_80670FB8;
    }
    // 0x80670F88: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80670F8C: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80670F90: ori         $t5, $t3, 0x80
    ctx->r13 = ctx->r11 | 0X80;
    // 0x80670F94: sw          $t3, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r11;
    // 0x80670F98: sw          $t5, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r13;
    // 0x80670F9C: ori         $t7, $t5, 0x2000
    ctx->r15 = ctx->r13 | 0X2000;
    // 0x80670FA0: sw          $t7, 0xF54($s1)
    MEM_W(0XF54, ctx->r17) = ctx->r15;
    // 0x80670FA4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80670FA8: lw          $t6, -0x7498($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7498);
    // 0x80670FAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80670FB0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80670FB4: sw          $t8, -0x7498($at)
    MEM_W(-0X7498, ctx->r1) = ctx->r24;
L_80670FB8:
    // 0x80670FB8: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80670FBC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80670FC0: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80670FC4: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80670FC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80670FCC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80670FD0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80670FD4: jr          $ra
    // 0x80670FD8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80670FD8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80456CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456CE0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80456CE4: lbu         $v0, -0x7204($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7204);
    // 0x80456CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80456CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80456CF0: bne         $v0, $zero, L_80456D08
    if (ctx->r2 != 0) {
        // 0x80456CF4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80456D08;
    }
    // 0x80456CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456CF8: jal         0x80455DE0
    // 0x80456CFC: nop

    func_80455DE0(rdram, ctx);
        goto after_0;
    // 0x80456CFC: nop

    after_0:
    // 0x80456D00: b           L_80456D8C
    // 0x80456D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80456D8C;
    // 0x80456D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80456D08:
    // 0x80456D08: bnel        $v0, $at, L_80456D24
    if (ctx->r2 != ctx->r1) {
        // 0x80456D0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80456D24;
    }
    goto skip_0;
    // 0x80456D0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80456D10: jal         0x80456090
    // 0x80456D14: nop

    func_80456090(rdram, ctx);
        goto after_1;
    // 0x80456D14: nop

    after_1:
    // 0x80456D18: b           L_80456D8C
    // 0x80456D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80456D8C;
    // 0x80456D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80456D20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80456D24:
    // 0x80456D24: bnel        $v0, $at, L_80456D40
    if (ctx->r2 != ctx->r1) {
        // 0x80456D28: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80456D40;
    }
    goto skip_1;
    // 0x80456D28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x80456D2C: jal         0x80456384
    // 0x80456D30: nop

    func_80456384(rdram, ctx);
        goto after_2;
    // 0x80456D30: nop

    after_2:
    // 0x80456D34: b           L_80456D8C
    // 0x80456D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80456D8C;
    // 0x80456D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80456D3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80456D40:
    // 0x80456D40: bnel        $v0, $at, L_80456D5C
    if (ctx->r2 != ctx->r1) {
        // 0x80456D44: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80456D5C;
    }
    goto skip_2;
    // 0x80456D44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_2:
    // 0x80456D48: jal         0x80456678
    // 0x80456D4C: nop

    func_80456678(rdram, ctx);
        goto after_3;
    // 0x80456D4C: nop

    after_3:
    // 0x80456D50: b           L_80456D8C
    // 0x80456D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80456D8C;
    // 0x80456D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80456D58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80456D5C:
    // 0x80456D5C: bnel        $v0, $at, L_80456D78
    if (ctx->r2 != ctx->r1) {
        // 0x80456D60: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80456D78;
    }
    goto skip_3;
    // 0x80456D60: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_3:
    // 0x80456D64: jal         0x8045696C
    // 0x80456D68: nop

    func_8045696C(rdram, ctx);
        goto after_4;
    // 0x80456D68: nop

    after_4:
    // 0x80456D6C: b           L_80456D8C
    // 0x80456D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80456D8C;
    // 0x80456D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80456D74: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80456D78:
    // 0x80456D78: bnel        $v0, $at, L_80456D8C
    if (ctx->r2 != ctx->r1) {
        // 0x80456D7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80456D8C;
    }
    goto skip_4;
    // 0x80456D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80456D80: jal         0x80456C60
    // 0x80456D84: nop

    func_80456C60(rdram, ctx);
        goto after_5;
    // 0x80456D84: nop

    after_5:
    // 0x80456D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80456D8C:
    // 0x80456D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80456D90: jr          $ra
    // 0x80456D94: nop

    return;
    // 0x80456D94: nop

;}
RECOMP_FUNC void func_806AEF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEF04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806AEF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AEF0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AEF10: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AEF14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AEF18: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x806AEF1C: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x806AEF20: jalr        $t9
    // 0x806AEF24: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806AEF24: nop

    after_0:
    // 0x806AEF28: jal         0x806AEBDC
    // 0x806AEF2C: nop

    func_806AEBDC(rdram, ctx);
        goto after_1;
    // 0x806AEF2C: nop

    after_1:
    // 0x806AEF30: bne         $v0, $zero, L_806AEF60
    if (ctx->r2 != 0) {
        // 0x806AEF34: lui         $t6, 0x806B
        ctx->r14 = S32(RELOC_HI16(595, 0XA80) << 16);
            goto L_806AEF60;
    }
    // 0x806AEF34: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(595, 0XA80) << 16);
    // 0x806AEF38: jal         0x806AE458
    // 0x806AEF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AE458(rdram, ctx);
        goto after_2;
    // 0x806AEF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806AEF40: beq         $v0, $zero, L_806AEF74
    if (ctx->r2 == 0) {
        // 0x806AEF44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AEF74;
    }
    // 0x806AEF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AEF48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AEF4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806AEF50: jal         0x806AF64C
    // 0x806AEF54: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_3;
    // 0x806AEF54: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x806AEF58: b           L_806AEF78
    // 0x806AEF5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806AEF78;
    // 0x806AEF5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AEF60:
    // 0x806AEF60: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x806AEF64: addiu       $t6, $t6, -0x1840
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(595, 0XA80));
    // 0x806AEF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AEF6C: jal         0x806AE458
    // 0x806AEF70: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    func_806AE458(rdram, ctx);
        goto after_4;
    // 0x806AEF70: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    after_4:
L_806AEF74:
    // 0x806AEF74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AEF78:
    // 0x806AEF78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AEF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806AEF80: jr          $ra
    // 0x806AEF84: nop

    return;
    // 0x806AEF84: nop

;}
RECOMP_FUNC void func_805840D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805840D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805840D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805840DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805840E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805840E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805840E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805840EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805840F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805840F4: addiu       $t6, $zero, 0x1E3C
    ctx->r14 = ADD32(0, 0X1E3C);
    // 0x805840F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805840FC: addiu       $a2, $zero, 0x1E0
    ctx->r6 = ADD32(0, 0X1E0);
    // 0x80584100: addiu       $a3, $zero, 0x1D4C
    ctx->r7 = ADD32(0, 0X1D4C);
    // 0x80584104: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80584108: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8058410C: jal         0x80583CCC
    // 0x80584110: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80583CCC(rdram, ctx);
        goto after_0;
    // 0x80584110: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80584114: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80584118: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8058411C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80584120: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80584124: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80584128: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8058412C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80584130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80584134: jr          $ra
    // 0x80584138: nop

    return;
    // 0x80584138: nop

;}
RECOMP_FUNC void func_806ECB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECB64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ECB68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ECB6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ECB70: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ECB74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ECB78: jal         0x800577D8
    // 0x806ECB7C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ECB7C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806ECB80: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806ECB84: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806ECB88: jal         0x80065ABC
    // 0x806ECB8C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806ECB8C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x806ECB90: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806ECB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECB98: jal         0x80049D74
    // 0x806ECB9C: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x806ECB9C: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x806ECBA0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806ECBA4: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806ECBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECBAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806ECBB0: jal         0x8004D150
    // 0x806ECBB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x806ECBB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x806ECBB8: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x806ECBBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECBC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806ECBC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806ECBC8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806ECBCC: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806ECBD0: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x806ECBD4: beql        $t0, $zero, L_806ECC68
    if (ctx->r8 == 0) {
        // 0x806ECBD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806ECC68;
    }
    goto skip_0;
    // 0x806ECBD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806ECBDC: jal         0x8004D618
    // 0x806ECBE0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x806ECBE0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_4:
    // 0x806ECBE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECBE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECBEC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806ECBF0: jal         0x806ED360
    // 0x806ECBF4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_5;
    // 0x806ECBF4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806ECBF8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x806ECBFC: jal         0x806EBFB8
    // 0x806ECC00: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_806EBFB8(rdram, ctx);
        goto after_6;
    // 0x806ECC00: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_6:
    // 0x806ECC04: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x806ECC08: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x806ECC0C: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x806ECC10: lw          $v1, 0x478($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X478);
    // 0x806ECC14: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x806ECC18: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806ECC1C: lbu         $t1, 0xF0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF0);
    // 0x806ECC20: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x806ECC24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806ECC28: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x806ECC2C: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x806ECC30: sb          $t3, 0xF0($v1)
    MEM_B(0XF0, ctx->r3) = ctx->r11;
    // 0x806ECC34: lw          $t4, 0x478($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X478);
    // 0x806ECC38: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x806ECC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECC40: sb          $zero, 0xF2($t4)
    MEM_B(0XF2, ctx->r12) = 0;
    // 0x806ECC44: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x806ECC48: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806ECC4C: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x806ECC50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806ECC54: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
    // 0x806ECC58: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806ECC5C: jal         0x806EC098
    // 0x806ECC60: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_806EC098(rdram, ctx);
        goto after_7;
    // 0x806ECC60: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x806ECC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECC68:
    // 0x806ECC68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECC6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ECC70: jr          $ra
    // 0x806ECC74: nop

    return;
    // 0x806ECC74: nop

;}
RECOMP_FUNC void func_80037170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037178: jal         0x80021958
    // 0x8003717C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003717C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037180: bne         $v0, $zero, L_80037190
    if (ctx->r2 != 0) {
        // 0x80037184: nop
    
            goto L_80037190;
    }
    // 0x80037184: nop

    // 0x80037188: b           L_800371CC
    // 0x8003718C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800371CC;
    // 0x8003718C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037190:
    // 0x80037190: jal         0x80041714
    // 0x80037194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041714(rdram, ctx);
        goto after_1;
    // 0x80037194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037198: beq         $v0, $zero, L_800371A8
    if (ctx->r2 == 0) {
        // 0x8003719C: nop
    
            goto L_800371A8;
    }
    // 0x8003719C: nop

    // 0x800371A0: b           L_800371CC
    // 0x800371A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800371CC;
    // 0x800371A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800371A8:
    // 0x800371A8: jal         0x80036CB4
    // 0x800371AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036CB4(rdram, ctx);
        goto after_2;
    // 0x800371AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800371B0: bne         $v0, $zero, L_800371C0
    if (ctx->r2 != 0) {
        // 0x800371B4: nop
    
            goto L_800371C0;
    }
    // 0x800371B4: nop

    // 0x800371B8: b           L_800371CC
    // 0x800371BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800371CC;
    // 0x800371BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800371C0:
    // 0x800371C0: jal         0x80036EDC
    // 0x800371C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036EDC(rdram, ctx);
        goto after_3;
    // 0x800371C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800371C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800371CC:
    // 0x800371CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800371D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800371D4: jr          $ra
    // 0x800371D8: nop

    return;
    // 0x800371D8: nop

;}
RECOMP_FUNC void func_80046804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046804: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80046808: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004680C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80046810: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80046814: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80046818: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004681C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80046820: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80046824: jal         0x80046118
    // 0x80046828: lhu         $a0, 0x28($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X28);
    func_80046118(rdram, ctx);
        goto after_0;
    // 0x80046828: lhu         $a0, 0x28($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X28);
    after_0:
    // 0x8004682C: bne         $v0, $zero, L_8004683C
    if (ctx->r2 != 0) {
        // 0x80046830: nop
    
            goto L_8004683C;
    }
    // 0x80046830: nop

    // 0x80046834: b           L_800468D4
    // 0x80046838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800468D4;
    // 0x80046838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004683C:
    // 0x8004683C: jal         0x800464BC
    // 0x80046840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800464BC(rdram, ctx);
        goto after_1;
    // 0x80046840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80046844: bne         $v0, $zero, L_80046854
    if (ctx->r2 != 0) {
        // 0x80046848: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80046854;
    }
    // 0x80046848: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004684C: b           L_800468D4
    // 0x80046850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800468D4;
    // 0x80046850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046854:
    // 0x80046854: lbu         $t7, 0x6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X6);
    // 0x80046858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004685C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80046860: bne         $t7, $zero, L_800468AC
    if (ctx->r15 != 0) {
        // 0x80046864: lw          $a2, 0x38($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X38);
            goto L_800468AC;
    }
    // 0x80046864: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80046868: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004686C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046870: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80046874: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80046878: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8004687C: jal         0x80046014
    // 0x80046880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046014(rdram, ctx);
        goto after_2;
    // 0x80046880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80046884: bne         $v0, $zero, L_800468A0
    if (ctx->r2 != 0) {
        // 0x80046888: lui         $t8, 0x8004
        ctx->r24 = S32(0X8004 << 16);
            goto L_800468A0;
    }
    // 0x80046888: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8004688C: jal         0x80045BD8
    // 0x80046890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80045BD8(rdram, ctx);
        goto after_3;
    // 0x80046890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80046894: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x80046898: b           L_800468D4
    // 0x8004689C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800468D4;
    // 0x8004689C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800468A0:
    // 0x800468A0: addiu       $t8, $t8, 0x5BD8
    ctx->r24 = ADD32(ctx->r24, 0X5BD8);
    // 0x800468A4: b           L_800468BC
    // 0x800468A8: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
        goto L_800468BC;
    // 0x800468A8: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
L_800468AC:
    // 0x800468AC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800468B0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800468B4: jal         0x80045CAC
    // 0x800468B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80045CAC(rdram, ctx);
        goto after_4;
    // 0x800468B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
L_800468BC:
    // 0x800468BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800468C0: sb          $t9, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r25;
    // 0x800468C4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800468C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800468CC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x800468D0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800468D4:
    // 0x800468D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800468D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800468DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800468E0: jr          $ra
    // 0x800468E4: nop

    return;
    // 0x800468E4: nop

;}
RECOMP_FUNC void pad_physical_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB98: jr          $ra
    // 0x8007FB9C: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    return;
    // 0x8007FB9C: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
;}
RECOMP_FUNC void func_8069B3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B3F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8069B3F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8069B3FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8069B400: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8069B404: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069B408: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8069B40C: lw          $t7, -0x77F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X77F0);
    // 0x8069B410: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8069B414: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8069B418: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8069B41C: slti        $at, $t8, 0x96
    ctx->r1 = SIGNED(ctx->r24) < 0X96 ? 1 : 0;
    // 0x8069B420: beql        $at, $zero, L_8069B578
    if (ctx->r1 == 0) {
        // 0x8069B424: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8069B578;
    }
    goto skip_0;
    // 0x8069B424: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8069B428: jal         0x80047090
    // 0x8069B42C: addiu       $a0, $zero, 0x458F
    ctx->r4 = ADD32(0, 0X458F);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8069B42C: addiu       $a0, $zero, 0x458F
    ctx->r4 = ADD32(0, 0X458F);
    after_0:
    // 0x8069B430: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8069B434: beq         $v0, $at, L_8069B4E0
    if (ctx->r2 == ctx->r1) {
        // 0x8069B438: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8069B4E0;
    }
    // 0x8069B438: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8069B43C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8069B440: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x8069B444: lwc1        $f0, 0x88($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X88);
    // 0x8069B448: lw          $v0, 0x10($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X10);
    // 0x8069B44C: beq         $v0, $at, L_8069B468
    if (ctx->r2 == ctx->r1) {
        // 0x8069B450: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8069B468;
    }
    // 0x8069B450: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8069B454: beq         $v0, $at, L_8069B468
    if (ctx->r2 == ctx->r1) {
        // 0x8069B458: lui         $at, 0x4188
        ctx->r1 = S32(0X4188 << 16);
            goto L_8069B468;
    }
    // 0x8069B458: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8069B45C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069B460: nop

    // 0x8069B464: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
L_8069B468:
    // 0x8069B468: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8069B46C: bne         $v0, $at, L_8069B480
    if (ctx->r2 != ctx->r1) {
        // 0x8069B470: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8069B480;
    }
    // 0x8069B470: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8069B474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8069B478: nop

    // 0x8069B47C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8069B480:
    // 0x8069B480: lui         $at, 0x458F
    ctx->r1 = S32(0X458F << 16);
    // 0x8069B484: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8069B488: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X1934) << 16);
    // 0x8069B48C: lwc1        $f10, -0x39FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(565, 0X1934));
    // 0x8069B490: lwc1        $f8, 0x8C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x8069B494: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8069B498: lw          $a1, 0x84($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X84);
    // 0x8069B49C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8069B4A0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8069B4A4: jal         0x8004613C
    // 0x8069B4A8: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8069B4A8: nop

    after_1:
    // 0x8069B4AC: beq         $v0, $zero, L_8069B4DC
    if (ctx->r2 == 0) {
        // 0x8069B4B0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8069B4DC;
    }
    // 0x8069B4B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8069B4B4: jal         0x80044194
    // 0x8069B4B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8069B4B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8069B4BC: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8069B4C0: jal         0x80067BBC
    // 0x8069B4C4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8069B4C4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_3:
    // 0x8069B4C8: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x8069B4CC: jal         0x80067818
    // 0x8069B4D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8069B4D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8069B4D4: b           L_8069B4E0
    // 0x8069B4D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
        goto L_8069B4E0;
    // 0x8069B4D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
L_8069B4DC:
    // 0x8069B4DC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
L_8069B4E0:
    // 0x8069B4E0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8069B4E4: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x8069B4E8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8069B4EC: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x8069B4F0: bne         $v0, $at, L_8069B504
    if (ctx->r2 != ctx->r1) {
        // 0x8069B4F4: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8069B504;
    }
    // 0x8069B4F4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8069B4F8: lwc1        $f18, 0x50($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8069B4FC: b           L_8069B514
    // 0x8069B500: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
        goto L_8069B514;
    // 0x8069B500: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
L_8069B504:
    // 0x8069B504: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X18D8) << 16);
    // 0x8069B508: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8069B50C: lwc1        $f4, -0x3A58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(565, 0X18D8));
    // 0x8069B510: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
L_8069B514:
    // 0x8069B514: jal         0x80066E88
    // 0x8069B518: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8069B518: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_5:
    // 0x8069B51C: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8069B520: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8069B524: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8069B528: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8069B52C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8069B530: jal         0x80066DE4
    // 0x8069B534: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8069B534: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x8069B538: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8069B53C: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8069B540: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8069B544: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8069B548: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x8069B54C: div.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8069B550: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
    // 0x8069B554: lui         $a2, 0xBC23
    ctx->r6 = S32(0XBC23 << 16);
    // 0x8069B558: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8069B55C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8069B560: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8069B564: div.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8069B568: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8069B56C: jal         0x8069B2E0
    // 0x8069B570: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    func_8069B2E0(rdram, ctx);
        goto after_7;
    // 0x8069B570: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x8069B574: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8069B578:
    // 0x8069B578: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8069B57C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8069B580: jr          $ra
    // 0x8069B584: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8069B584: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806EF560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF560: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EF564: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x806EF568: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    // 0x806EF56C: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x806EF570: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806EF574: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    // 0x806EF578: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EF57C: jr          $ra
    // 0x806EF580: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x806EF580: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_804C03C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C03C0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C03C4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C03C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804C03CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804C03D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C03D4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x804C03D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C03DC: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(194, 0X318) << 16);
    // 0x804C03E0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C03E4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C03E8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C03EC: lw          $t1, 0x428($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(194, 0X318));
    // 0x804C03F0: jr          $ra
    // 0x804C03F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804C03F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804C03F8: nop

    // 0x804C03FC: nop

;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DA0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80086DA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80086DA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80086DAC: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80086DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086DB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80086DB8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80086DBC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80086DC0: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80086DC4:
    // 0x80086DC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086DC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80086DCC: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80086DD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80086DD4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80086DD8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80086DDC: beq         $a0, $t3, L_80086E44
    if (ctx->r4 == ctx->r11) {
        // 0x80086DE0: nop
    
            goto L_80086E44;
    }
    // 0x80086DE0: nop

L_80086DE4:
    // 0x80086DE4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80086DE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80086DEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80086DF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80086DF4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80086DF8: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80086DFC: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80086E00: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80086E04: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80086E08: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80086E0C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80086E10: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80086E14: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80086E18: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80086E1C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80086E20: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80086E24: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80086E28: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80086E2C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80086E30: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80086E34: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80086E38: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80086E3C: bne         $a0, $t3, L_80086DE4
    if (ctx->r4 != ctx->r11) {
        // 0x80086E40: nop
    
            goto L_80086DE4;
    }
    // 0x80086E40: nop

L_80086E44:
    // 0x80086E44: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80086E48: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80086E4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80086E50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80086E54: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80086E58: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80086E5C: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80086E60: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80086E64: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80086E68: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80086E6C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80086E70: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80086E74: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80086E78: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80086E7C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80086E80: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80086E84: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80086E88: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80086E8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80086E90: bne         $a2, $t4, L_80086DC4
    if (ctx->r6 != ctx->r12) {
        // 0x80086E94: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80086DC4;
    }
    // 0x80086E94: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80086E98: jr          $ra
    // 0x80086E9C: nop

    return;
    // 0x80086E9C: nop

;}
RECOMP_FUNC void func_805DC1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC1F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DC1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DC1F8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805DC1FC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC200: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x805DC204: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805DC208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC20C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805DC210: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805DC214: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x805DC218: jal         0x805DD234
    // 0x805DC21C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_805DD234(rdram, ctx);
        goto after_0;
    // 0x805DC21C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805DC220: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805DC224: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805DC228: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x805DC22C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805DC230: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805DC234: lwc1        $f6, 0x5C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x805DC238: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805DC23C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805DC240: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x805DC244: jal         0x80062D14
    // 0x805DC248: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805DC248: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x805DC24C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x805DC250: lui         $at, 0x43D0
    ctx->r1 = S32(0X43D0 << 16);
    // 0x805DC254: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805DC258: lwc1        $f16, 0x60($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X60);
    // 0x805DC25C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805DC260: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC264: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805DC268: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805DC26C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DC270: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x805DC274: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DC278: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x805DC27C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805DC280: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x805DC284: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805DC288: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x805DC28C: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x805DC290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DC294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DC298: jr          $ra
    // 0x805DC29C: nop

    return;
    // 0x805DC29C: nop

;}
RECOMP_FUNC void func_807BC4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC4CC: jr          $ra
    // 0x807BC4D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807BC4D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8069A0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069A0F0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8069A0F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069A0F8: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8069A0FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069A100: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8069A104: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8069A108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069A10C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8069A110: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8069A114: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8069A118: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8069A11C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8069A120: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(562, 0X1620) << 16);
    // 0x8069A124: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x8069A128: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8069A12C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8069A130: lw          $t1, -0x5510($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(562, 0X1620));
    // 0x8069A134: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x8069A138: jal         0x80699C04
    // 0x8069A13C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_80699C04(rdram, ctx);
        goto after_0;
    // 0x8069A13C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x8069A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069A144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069A148: jr          $ra
    // 0x8069A14C: nop

    return;
    // 0x8069A14C: nop

;}
RECOMP_FUNC void func_806EBD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EBD68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EBD6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EBD70: jal         0x8004700C
    // 0x806EBD74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EBD74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EBD78: lw          $t7, 0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X38);
    // 0x806EBD7C: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x806EBD80: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x806EBD84: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x806EBD88: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806EBD8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806EBD90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806EBD94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EBD98: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806EBD9C: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806EBDA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806EBDA4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x806EBDA8: jal         0x800485B8
    // 0x806EBDAC: nop

    func_800485B8(rdram, ctx);
        goto after_1;
    // 0x806EBDAC: nop

    after_1:
    // 0x806EBDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EBDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EBDB8: jr          $ra
    // 0x806EBDBC: nop

    return;
    // 0x806EBDBC: nop

;}
RECOMP_FUNC void func_806B0404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0404: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806B0408: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B040C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806B0410: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806B0414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806B0418: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806B041C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x806B0420: lwc1        $f6, 0x50($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806B0424: jal         0x80047AB8
    // 0x806B0428: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x806B0428: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x806B042C: jal         0x80066DE4
    // 0x806B0430: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806B0430: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x806B0434: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x806B0438: jal         0x80066DE4
    // 0x806B043C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x806B043C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x806B0440: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806B0444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806B0448: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806B044C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806B0450: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806B0454: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806B0458: nop

    // 0x806B045C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806B0460: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x806B0464: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x806B0468: jal         0x80066E88
    // 0x806B046C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x806B046C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x806B0470: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x806B0474: jal         0x80066E88
    // 0x806B0478: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x806B0478: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x806B047C: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806B0480: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806B0484: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x806B0488: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806B048C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806B0490: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806B0494: nop

    // 0x806B0498: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x806B049C: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x806B04A0: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x806B04A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B04A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806B04AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806B04B0: jr          $ra
    // 0x806B04B4: nop

    return;
    // 0x806B04B4: nop

;}
RECOMP_FUNC void func_80427C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427C34: jal         0x8001D770
    // 0x80427C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80427C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80427C3C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80427C40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80427C44: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x80427C48: jal         0x80067BF8
    // 0x80427C4C: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80427C4C: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_1:
    // 0x80427C50: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    // 0x80427C54: jal         0x80067818
    // 0x80427C58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80427C58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80427C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427C64: jr          $ra
    // 0x80427C68: nop

    return;
    // 0x80427C68: nop

;}
RECOMP_FUNC void func_8006CB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB0C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006CB10: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006CB14: jr          $ra
    // 0x8006CB18: sw          $a0, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r4;
    return;
    // 0x8006CB18: sw          $a0, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r4;
;}
RECOMP_FUNC void func_805AE2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE2F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE2F8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE2FC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE300: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE304: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE308: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE30C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE310: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE314: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE318: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE31C: jr          $ra
    // 0x805AE320: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE320: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void gfxprint_open(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FA4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FA50: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8007FA54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007FA58: bnel        $t6, $zero, L_8007FA70
    if (ctx->r14 != 0) {
        // 0x8007FA5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007FA70;
    }
    goto skip_0;
    // 0x8007FA5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007FA60: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8007FA64: jal         0x8007EF00
    // 0x8007FA68: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    gfxprint_setup(rdram, ctx);
        goto after_0;
    // 0x8007FA68: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    after_0:
    // 0x8007FA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007FA70:
    // 0x8007FA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FA74: jr          $ra
    // 0x8007FA78: nop

    return;
    // 0x8007FA78: nop

;}
RECOMP_FUNC void func_8064B918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B91C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064B920: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064B924: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064B928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B92C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064B930: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8064B934: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8064B938: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064B93C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8064B940: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064B944: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064B948: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X30B8) << 16);
    // 0x8064B94C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064B950: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064B954: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064B958: lw          $t2, -0x2E78($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X30B8));
    // 0x8064B95C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064B960: jal         0x8064B6F4
    // 0x8064B964: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064B6F4(rdram, ctx);
        goto after_0;
    // 0x8064B964: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064B968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B970: jr          $ra
    // 0x8064B974: nop

    return;
    // 0x8064B974: nop

;}
RECOMP_FUNC void func_80742EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80742EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80742F00: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742F04: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80742F08: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80742F0C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80742F10: lw          $v1, 0x6E5C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E5C);
    // 0x80742F14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80742F18: beql        $v1, $zero, L_80742F34
    if (ctx->r3 == 0) {
        // 0x80742F1C: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80742F34;
    }
    goto skip_0;
    // 0x80742F1C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80742F20: jal         0x807429A4
    // 0x80742F24: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    func_807429A4(rdram, ctx);
        goto after_0;
    // 0x80742F24: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    after_0:
    // 0x80742F28: b           L_80742F58
    // 0x80742F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742F58;
    // 0x80742F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742F30: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80742F34:
    // 0x80742F34: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80742F38: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80742F3C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80742F40: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80742F44: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80742F48: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80742F4C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80742F50: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80742F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742F58:
    // 0x80742F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80742F5C: jr          $ra
    // 0x80742F60: nop

    return;
    // 0x80742F60: nop

;}
RECOMP_FUNC void func_8076E198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076E198: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8076E19C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076E1A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8076E1A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8076E1A8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8076E1AC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8076E1B0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8076E1B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8076E1B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8076E1BC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8076E1C0: jal         0x8004921C
    // 0x8076E1C4: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8076E1C4: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8076E1C8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8076E1CC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8076E1D0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8076E1D4: jal         0x8004921C
    // 0x8076E1D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8076E1D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8076E1DC: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x8076E1E0: sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // 0x8076E1E4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8076E1E8: lw          $t8, 0x168($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X168);
    // 0x8076E1EC: lw          $v1, -0x260C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260C);
    // 0x8076E1F0: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8076E1F4: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8076E1F8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8076E1FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8076E200: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8076E204: lw          $t3, 0x16C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X16C);
    // 0x8076E208: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8076E20C: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8076E210: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x8076E214: addiu       $s0, $s0, -0x60
    ctx->r16 = ADD32(ctx->r16, -0X60);
    // 0x8076E218: sw          $s0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r16;
    // 0x8076E21C: lw          $t5, 0x1F4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X1F4);
    // 0x8076E220: jal         0x80077338
    // 0x8076E224: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8076E224: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    after_2:
    // 0x8076E228: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8076E22C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8076E230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8076E234: jal         0x8007711C
    // 0x8076E238: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8076E238: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x8076E23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076E240: jal         0x8076DFB0
    // 0x8076E244: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_8076DFB0(rdram, ctx);
        goto after_4;
    // 0x8076E244: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x8076E248: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E24C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8076E250: ori         $t8, $t8, 0x185F
    ctx->r24 = ctx->r24 | 0X185F;
    // 0x8076E254: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8076E258: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8076E25C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8076E260: sw          $s0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r16;
    // 0x8076E264: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E268: lui         $t4, 0xFD50
    ctx->r12 = S32(0XFD50 << 16);
    // 0x8076E26C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8076E270: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8076E274: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8076E278: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8076E27C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8076E280: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8076E284: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8076E288: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8076E28C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E290: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8076E294: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8076E298: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8076E29C: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8076E2A0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8076E2A4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8076E2A8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8076E2B0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8076E2B4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8076E2B8: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8076E2BC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8076E2C0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8076E2C4: lh          $t2, 0x68($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X68);
    // 0x8076E2C8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E2CC: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x8076E2D0: multu       $s1, $t2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8076E2D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8076E2D8: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8076E2DC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8076E2E0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8076E2E4: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8076E2E8: mflo        $v0
    ctx->r2 = lo;
    // 0x8076E2EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8076E2F0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8076E2F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8076E2F8: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8076E2FC: beq         $at, $zero, L_8076E30C
    if (ctx->r1 == 0) {
        // 0x8076E300: nop
    
            goto L_8076E30C;
    }
    // 0x8076E300: nop

    // 0x8076E304: b           L_8076E30C
    // 0x8076E308: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8076E30C;
    // 0x8076E308: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8076E30C:
    // 0x8076E30C: bgez        $a3, L_8076E31C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8076E310: sra         $v0, $a3, 3
        ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
            goto L_8076E31C;
    }
    // 0x8076E310: sra         $v0, $a3, 3
    ctx->r2 = S32(SIGNED(ctx->r7) >> 3);
    // 0x8076E314: addiu       $at, $a3, 0x7
    ctx->r1 = ADD32(ctx->r7, 0X7);
    // 0x8076E318: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8076E31C:
    // 0x8076E31C: bgtz        $v0, L_8076E32C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8076E320: andi        $t6, $a2, 0xFFF
        ctx->r14 = ctx->r6 & 0XFFF;
            goto L_8076E32C;
    }
    // 0x8076E320: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x8076E324: b           L_8076E330
    // 0x8076E328: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8076E330;
    // 0x8076E328: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8076E32C:
    // 0x8076E32C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_8076E330:
    // 0x8076E330: bgtz        $v0, L_8076E340
    if (SIGNED(ctx->r2) > 0) {
        // 0x8076E334: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8076E340;
    }
    // 0x8076E334: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8076E338: b           L_8076E344
    // 0x8076E33C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8076E344;
    // 0x8076E33C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8076E340:
    // 0x8076E340: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8076E344:
    // 0x8076E344: div         $zero, $t9, $s0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r16)));
    // 0x8076E348: bne         $s0, $zero, L_8076E354
    if (ctx->r16 != 0) {
        // 0x8076E34C: nop
    
            goto L_8076E354;
    }
    // 0x8076E34C: nop

    // 0x8076E350: break       7
    do_break(2155275088);
L_8076E354:
    // 0x8076E354: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8076E358: bne         $s0, $at, L_8076E36C
    if (ctx->r16 != ctx->r1) {
        // 0x8076E35C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8076E36C;
    }
    // 0x8076E35C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8076E360: bne         $t9, $at, L_8076E36C
    if (ctx->r25 != ctx->r1) {
        // 0x8076E364: nop
    
            goto L_8076E36C;
    }
    // 0x8076E364: nop

    // 0x8076E368: break       6
    do_break(2155275112);
L_8076E36C:
    // 0x8076E36C: mflo        $t3
    ctx->r11 = lo;
    // 0x8076E370: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8076E374: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8076E378: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8076E37C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8076E380: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8076E384: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8076E388: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E38C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8076E390: addiu       $t7, $a3, 0x7
    ctx->r15 = ADD32(ctx->r7, 0X7);
    // 0x8076E394: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x8076E398: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8076E39C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8076E3A0: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8076E3A4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E3A8: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8076E3AC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8076E3B0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8076E3B4: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x8076E3B8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8076E3BC: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x8076E3C0: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x8076E3C4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8076E3C8: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8076E3CC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8076E3D0: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8076E3D4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8076E3D8: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E3DC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8076E3E0: addiu       $t9, $s1, -0x1
    ctx->r25 = ADD32(ctx->r17, -0X1);
    // 0x8076E3E4: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8076E3E8: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8076E3EC: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8076E3F0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8076E3F4: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x8076E3F8: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8076E3FC: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x8076E400: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8076E404: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8076E408: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x8076E40C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8076E410: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8076E414: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E418: lui         $t7, 0x8077
    ctx->r15 = S32(RELOC_HI16(766, 0X1E20) << 16);
    // 0x8076E41C: addiu       $t7, $t7, -0x19F0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(766, 0X1E20));
    // 0x8076E420: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8076E424: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8076E428: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8076E42C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8076E430: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8076E434: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8076E438: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8076E43C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8076E440: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x8076E444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076E448: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8076E44C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8076E450: jr          $ra
    // 0x8076E454: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8076E454: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_807AF6B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF6B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807AF6BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AF6C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807AF6C4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807AF6C8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807AF6CC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807AF6D0: bne         $v0, $at, L_807AF70C
    if (ctx->r2 != ctx->r1) {
        // 0x807AF6D4: nop
    
            goto L_807AF70C;
    }
    // 0x807AF6D4: nop

    // 0x807AF6D8: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x807AF6DC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807AF6E0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x807AF6E4: beq         $v0, $zero, L_807AF70C
    if (ctx->r2 == 0) {
        // 0x807AF6E8: nop
    
            goto L_807AF70C;
    }
    // 0x807AF6E8: nop

    // 0x807AF6EC: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AF6F0: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    // 0x807AF6F4: ori         $at, $at, 0xA987
    ctx->r1 = ctx->r1 | 0XA987;
    // 0x807AF6F8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807AF6FC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x807AF700: bne         $t8, $at, L_807AF70C
    if (ctx->r24 != ctx->r1) {
        // 0x807AF704: nop
    
            goto L_807AF70C;
    }
    // 0x807AF704: nop

    // 0x807AF708: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_807AF70C:
    // 0x807AF70C: jr          $ra
    // 0x807AF710: nop

    return;
    // 0x807AF710: nop

;}
RECOMP_FUNC void func_80451704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045170C: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80451710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80451714: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451718: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140D4) << 16);
    // 0x8045171C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80451720: nop

    // 0x80451724: bc1f        L_80451750
    if (!c1cs) {
        // 0x80451728: nop
    
            goto L_80451750;
    }
    // 0x80451728: nop

    // 0x8045172C: jal         0x804516BC
    // 0x80451730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804516BC(rdram, ctx);
        goto after_0;
    // 0x80451730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80451734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80451738: jal         0x80450B18
    // 0x8045173C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x8045173C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80451740: jal         0x80445A34
    // 0x80451744: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x80451744: nop

    after_2:
    // 0x80451748: b           L_80451894
    // 0x8045174C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80451894;
    // 0x8045174C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451750:
    // 0x80451750: lwc1        $f6, -0x7B4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140D4));
    // 0x80451754: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x80451758: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8045175C: nop

    // 0x80451760: bc1fl       L_80451790
    if (!c1cs) {
        // 0x80451764: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80451790;
    }
    goto skip_0;
    // 0x80451764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80451768: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8045176C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80451770: beql        $t6, $zero, L_80451894
    if (ctx->r14 == 0) {
        // 0x80451774: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451894;
    }
    goto skip_1;
    // 0x80451774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80451778: jal         0x80450B18
    // 0x8045177C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x8045177C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80451780: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451784: b           L_80451890
    // 0x80451788: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80451890;
    // 0x80451788: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8045178C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80451790:
    // 0x80451790: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80451794: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80451798: nop

    // 0x8045179C: bc1fl       L_804517D4
    if (!c1cs) {
        // 0x804517A0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_804517D4;
    }
    goto skip_2;
    // 0x804517A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x804517A4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x804517A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804517AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804517B0: beql        $t7, $at, L_80451894
    if (ctx->r15 == ctx->r1) {
        // 0x804517B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451894;
    }
    goto skip_3;
    // 0x804517B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804517B8: jal         0x80450B18
    // 0x804517BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x804517BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x804517C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804517C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804517C8: b           L_80451890
    // 0x804517CC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_80451890;
    // 0x804517CC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x804517D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_804517D4:
    // 0x804517D4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x804517D8: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804517DC: nop

    // 0x804517E0: bc1fl       L_80451818
    if (!c1cs) {
        // 0x804517E4: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80451818;
    }
    goto skip_4;
    // 0x804517E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_4:
    // 0x804517E8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x804517EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804517F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804517F4: beql        $t9, $at, L_80451894
    if (ctx->r25 == ctx->r1) {
        // 0x804517F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451894;
    }
    goto skip_5;
    // 0x804517F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x804517FC: jal         0x80450B18
    // 0x80451800: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80451800: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80451804: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451808: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8045180C: b           L_80451890
    // 0x80451810: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_80451890;
    // 0x80451810: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80451814: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80451818:
    // 0x80451818: nop

    // 0x8045181C: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80451820: nop

    // 0x80451824: bc1fl       L_80451854
    if (!c1cs) {
        // 0x80451828: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80451854;
    }
    goto skip_6;
    // 0x80451828: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_6:
    // 0x8045182C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80451830: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80451834: beql        $t1, $zero, L_80451894
    if (ctx->r9 == 0) {
        // 0x80451838: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451894;
    }
    goto skip_7;
    // 0x80451838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8045183C: jal         0x80450B18
    // 0x80451840: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_6;
    // 0x80451840: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80451844: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451848: b           L_80451890
    // 0x8045184C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80451890;
    // 0x8045184C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80451850: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80451854:
    // 0x80451854: nop

    // 0x80451858: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x8045185C: nop

    // 0x80451860: bc1fl       L_80451894
    if (!c1cs) {
        // 0x80451864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451894;
    }
    goto skip_8;
    // 0x80451864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80451868: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8045186C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80451870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80451874: beql        $t2, $at, L_80451894
    if (ctx->r10 == ctx->r1) {
        // 0x80451878: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451894;
    }
    goto skip_9;
    // 0x80451878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x8045187C: jal         0x80450B18
    // 0x80451880: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_7;
    // 0x80451880: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x80451884: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451888: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8045188C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80451890:
    // 0x80451890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451894:
    // 0x80451894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80451898: jr          $ra
    // 0x8045189C: nop

    return;
    // 0x8045189C: nop

;}
RECOMP_FUNC void func_8001ADE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ADE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001ADEC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001ADF0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001ADF4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001ADF8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001ADFC: beq         $a0, $zero, L_8001AE14
    if (ctx->r4 == 0) {
        // 0x8001AE00: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001AE14;
    }
    // 0x8001AE00: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001AE04: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8001AE08: sh          $a2, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r6;
    // 0x8001AE0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001AE10: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
L_8001AE14:
    // 0x8001AE14: jr          $ra
    // 0x8001AE18: nop

    return;
    // 0x8001AE18: nop

;}
RECOMP_FUNC void func_80455864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045586C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455870: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455874: jal         0x8044EFA0
    // 0x80455878: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455878: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8045587C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80455880: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80455884: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80455888: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045588C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455890: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80455894: jal         0x804449C0
    // 0x80455898: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x80455898: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    after_1:
    // 0x8045589C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804558A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804558A4: jal         0x80450490
    // 0x804558A8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x804558A8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x804558AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804558B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804558B4: jr          $ra
    // 0x804558B8: nop

    return;
    // 0x804558B8: nop

;}
RECOMP_FUNC void func_804BE4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE4A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804BE4AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BE4B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BE4B4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x804BE4B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804BE4BC: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x804BE4C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804BE4C4: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x804BE4C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BE4CC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x804BE4D0: lw          $a2, 0x370($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X370);
    // 0x804BE4D4: sh          $t7, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r15;
    // 0x804BE4D8: lh          $t8, 0x38($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X38);
    // 0x804BE4DC: beql        $t8, $zero, L_804BE56C
    if (ctx->r24 == 0) {
        // 0x804BE4E0: lwc1        $f10, 0x20($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
            goto L_804BE56C;
    }
    goto skip_0;
    // 0x804BE4E0: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x804BE4E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804BE4E8: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804BE4EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x804BE4F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804BE4F4: nop

    // 0x804BE4F8: bc1fl       L_804BE524
    if (!c1cs) {
        // 0x804BE4FC: lui         $at, 0xC270
        ctx->r1 = S32(0XC270 << 16);
            goto L_804BE524;
    }
    goto skip_1;
    // 0x804BE4FC: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    skip_1:
    // 0x804BE500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BE504: nop

    // 0x804BE508: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x804BE50C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BE510: nop

    // 0x804BE514: bc1fl       L_804BE524
    if (!c1cs) {
        // 0x804BE518: lui         $at, 0xC270
        ctx->r1 = S32(0XC270 << 16);
            goto L_804BE524;
    }
    goto skip_2;
    // 0x804BE518: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    skip_2:
    // 0x804BE51C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804BE520: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
L_804BE524:
    // 0x804BE524: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x804BE528: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804BE52C: lwc1        $f0, 0x50($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X50);
    // 0x804BE530: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804BE534: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804BE538: nop

    // 0x804BE53C: bc1fl       L_804BE568
    if (!c1cs) {
        // 0x804BE540: swc1        $f0, 0x50($a2)
        MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
            goto L_804BE568;
    }
    goto skip_3;
    // 0x804BE540: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
    skip_3:
    // 0x804BE544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BE548: nop

    // 0x804BE54C: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804BE550: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BE554: nop

    // 0x804BE558: bc1fl       L_804BE568
    if (!c1cs) {
        // 0x804BE55C: swc1        $f0, 0x50($a2)
        MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
            goto L_804BE568;
    }
    goto skip_4;
    // 0x804BE55C: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
    skip_4:
    // 0x804BE560: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804BE564: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
L_804BE568:
    // 0x804BE568: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
L_804BE56C:
    // 0x804BE56C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x804BE570: nop

    // 0x804BE574: bc1fl       L_804BE778
    if (!c1cs) {
        // 0x804BE578: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BE778;
    }
    goto skip_5;
    // 0x804BE578: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x804BE57C: lh          $v0, 0x34($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X34);
    // 0x804BE580: sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
    // 0x804BE584: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X2850) << 16);
    // 0x804BE588: blez        $v0, L_804BE750
    if (SIGNED(ctx->r2) <= 0) {
        // 0x804BE58C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_804BE750;
    }
    // 0x804BE58C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x804BE590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804BE594: bne         $v0, $at, L_804BE5DC
    if (ctx->r2 != ctx->r1) {
        // 0x804BE598: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_804BE5DC;
    }
    // 0x804BE598: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804BE59C: jal         0x8005FE48
    // 0x804BE5A0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x804BE5A0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x804BE5A4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x804BE5A8: lw          $t9, 0x174($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X174);
    // 0x804BE5AC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804BE5B0: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    // 0x804BE5B4: jal         0x8005FE48
    // 0x804BE5B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x804BE5B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x804BE5BC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x804BE5C0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x804BE5C4: lw          $t2, 0x174($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X174);
    // 0x804BE5C8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x804BE5CC: sh          $zero, 0x12($t3)
    MEM_H(0X12, ctx->r11) = 0;
    // 0x804BE5D0: lh          $t4, 0x34($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X34);
    // 0x804BE5D4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x804BE5D8: sh          $t5, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r13;
L_804BE5DC:
    // 0x804BE5DC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41F4) << 16);
    // 0x804BE5E0: lwc1        $f2, -0x4DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41F4));
    // 0x804BE5E4: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804BE5E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804BE5EC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41FC) << 16);
    // 0x804BE5F0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x804BE5F4: nop

    // 0x804BE5F8: bc1f        L_804BE698
    if (!c1cs) {
        // 0x804BE5FC: nop
    
            goto L_804BE698;
    }
    // 0x804BE5FC: nop

    // 0x804BE600: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x804BE604: jal         0x80047AB8
    // 0x804BE608: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x804BE608: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_2:
    // 0x804BE60C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x804BE610: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41F8) << 16);
    // 0x804BE614: lwc1        $f18, -0x4D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41F8));
    // 0x804BE618: lwc1        $f16, 0x44($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X44);
    // 0x804BE61C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804BE620: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x804BE624: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x804BE628: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(191, 0X3D0C) << 16);
    // 0x804BE62C: addiu       $a1, $a1, -0x9C4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(191, 0X3D0C));
    // 0x804BE630: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804BE634: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x804BE638: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x804BE63C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x804BE640: jalr        $t9
    // 0x804BE644: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804BE644: nop

    after_3:
    // 0x804BE648: jal         0x800610A0
    // 0x804BE64C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800610A0(rdram, ctx);
        goto after_4;
    // 0x804BE64C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x804BE650: jal         0x800447C8
    // 0x804BE654: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x804BE654: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x804BE658: lh          $t0, 0x28($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X28);
    // 0x804BE65C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x804BE660: beql        $t0, $zero, L_804BE674
    if (ctx->r8 == 0) {
        // 0x804BE664: lw          $v0, 0x44($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X44);
            goto L_804BE674;
    }
    goto skip_6;
    // 0x804BE664: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x804BE668: lw          $t1, 0x1F4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1F4);
    // 0x804BE66C: sh          $zero, 0xE4($t1)
    MEM_H(0XE4, ctx->r9) = 0;
    // 0x804BE670: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_804BE674:
    // 0x804BE674: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x804BE678: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x804BE67C: jal         0x80067BBC
    // 0x804BE680: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x804BE680: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    after_6:
    // 0x804BE684: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x804BE688: jal         0x80067818
    // 0x804BE68C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x804BE68C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x804BE690: b           L_804BE778
    // 0x804BE694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804BE778;
    // 0x804BE694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BE698:
    // 0x804BE698: lwc1        $f6, -0x4D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41FC));
    // 0x804BE69C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804BE6A0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804BE6A4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804BE6A8: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x804BE6AC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804BE6B0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x804BE6B4: nop

    // 0x804BE6B8: bc1fl       L_804BE6C8
    if (!c1cs) {
        // 0x804BE6BC: lwc1        $f18, 0x24($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
            goto L_804BE6C8;
    }
    goto skip_7;
    // 0x804BE6BC: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    skip_7:
    // 0x804BE6C0: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x804BE6C4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
L_804BE6C8:
    // 0x804BE6C8: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x804BE6CC: nop

    // 0x804BE6D0: bc1fl       L_804BE778
    if (!c1cs) {
        // 0x804BE6D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BE778;
    }
    goto skip_8;
    // 0x804BE6D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x804BE6D8: jal         0x80047AB8
    // 0x804BE6DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80047AB8(rdram, ctx);
        goto after_8;
    // 0x804BE6DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_8:
    // 0x804BE6E0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x804BE6E4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4200) << 16);
    // 0x804BE6E8: lwc1        $f6, -0x4D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4200));
    // 0x804BE6EC: lwc1        $f4, 0x44($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X44);
    // 0x804BE6F0: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804BE6F4: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x804BE6F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804BE6FC: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(191, 0X3D0C) << 16);
    // 0x804BE700: addiu       $a1, $a1, -0x9C4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(191, 0X3D0C));
    // 0x804BE704: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804BE708: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x804BE70C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x804BE710: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x804BE714: jalr        $t9
    // 0x804BE718: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x804BE718: nop

    after_9:
    // 0x804BE71C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x804BE720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BE724: nop

    // 0x804BE728: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x804BE72C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x804BE730: lw          $a0, 0x34($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X34);
    // 0x804BE734: jal         0x80067BBC
    // 0x804BE738: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x804BE738: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    after_10:
    // 0x804BE73C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x804BE740: jal         0x80067818
    // 0x804BE744: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x804BE744: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x804BE748: b           L_804BE778
    // 0x804BE74C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804BE778;
    // 0x804BE74C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BE750:
    // 0x804BE750: sh          $t6, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r14;
    // 0x804BE754: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X1FBC) << 16);
    // 0x804BE758: sh          $zero, 0x144($a2)
    MEM_H(0X144, ctx->r6) = 0;
    // 0x804BE75C: addiu       $t7, $t7, -0x1E80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X2850));
    // 0x804BE760: addiu       $t8, $t8, -0x2714
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(191, 0X1FBC));
    // 0x804BE764: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x804BE768: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x804BE76C: jal         0x804BD678
    // 0x804BE770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BD678(rdram, ctx);
        goto after_12;
    // 0x804BE770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x804BE774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BE778:
    // 0x804BE778: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BE77C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804BE780: jr          $ra
    // 0x804BE784: nop

    return;
    // 0x804BE784: nop

;}
RECOMP_FUNC void func_80062AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062AEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062AF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80062AF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80062AFC: jal         0x80065954
    // 0x80062B00: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80062B00: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80062B04: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80062B08: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80062B0C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80062B10: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80062B14: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80062B18: jal         0x80065954
    // 0x80062B1C: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80062B1C: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    after_1:
    // 0x80062B20: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80062B24: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80062B28: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80062B2C: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80062B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062B34: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80062B38: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80062B3C: nop

    // 0x80062B40: bc1fl       L_80062B78
    if (!c1cs) {
        // 0x80062B44: lwc1        $f4, 0x4($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80062B78;
    }
    goto skip_0;
    // 0x80062B44: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80062B48: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80062B4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80062B50: nop

    // 0x80062B54: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80062B58: nop

    // 0x80062B5C: bc1f        L_80062B6C
    if (!c1cs) {
        // 0x80062B60: nop
    
            goto L_80062B6C;
    }
    // 0x80062B60: nop

    // 0x80062B64: b           L_80062B98
    // 0x80062B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80062B98;
    // 0x80062B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80062B6C:
    // 0x80062B6C: b           L_80062B98
    // 0x80062B70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80062B98;
    // 0x80062B70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80062B74: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
L_80062B78:
    // 0x80062B78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80062B7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80062B80: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80062B84: nop

    // 0x80062B88: bc1f        L_80062B98
    if (!c1cs) {
        // 0x80062B8C: nop
    
            goto L_80062B98;
    }
    // 0x80062B8C: nop

    // 0x80062B90: b           L_80062B98
    // 0x80062B94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80062B98;
    // 0x80062B94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80062B98:
    // 0x80062B98: jr          $ra
    // 0x80062B9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80062B9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8042D2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D2A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042D2A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042D2AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042D2B0: jal         0x80047090
    // 0x8042D2B4: addiu       $a0, $zero, 0x44D0
    ctx->r4 = ADD32(0, 0X44D0);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8042D2B4: addiu       $a0, $zero, 0x44D0
    ctx->r4 = ADD32(0, 0X44D0);
    after_0:
    // 0x8042D2B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8042D2BC: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8042D2C0: lui         $a0, 0x44D0
    ctx->r4 = S32(0X44D0 << 16);
    // 0x8042D2C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8042D2C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8042D2CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8042D2D0: jal         0x8004613C
    // 0x8042D2D4: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8042D2D4: nop

    after_1:
    // 0x8042D2D8: bne         $v0, $zero, L_8042D2E8
    if (ctx->r2 != 0) {
        // 0x8042D2DC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8042D2E8;
    }
    // 0x8042D2DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8042D2E0: b           L_8042D314
    // 0x8042D2E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8042D314;
    // 0x8042D2E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8042D2E8:
    // 0x8042D2E8: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x8042D2EC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8042D2F0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8042D2F4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8042D2F8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8042D2FC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x8042D300: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042D304: jal         0x80047F9C
    // 0x8042D308: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8042D308: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8042D30C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8042D310: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
L_8042D314:
    // 0x8042D314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042D318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042D31C: jr          $ra
    // 0x8042D320: nop

    return;
    // 0x8042D320: nop

;}
RECOMP_FUNC void func_80464650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80464654: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80464658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046465C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80464660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80464664: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80464668: lwc1        $f10, 0xDC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8046466C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80464670: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80464674: jal         0x80065954
    // 0x80464678: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80464678: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_0:
    // 0x8046467C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80464680: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    // 0x80464684: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80464688: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8046468C: bnel        $t7, $at, L_804646B8
    if (ctx->r15 != ctx->r1) {
        // 0x80464690: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_804646B8;
    }
    goto skip_0;
    // 0x80464690: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80464694: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80464698: jal         0x80067D5C
    // 0x8046469C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8046469C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x804646A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x804646A4: jal         0x80067F78
    // 0x804646A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x804646A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x804646AC: b           L_804646D0
    // 0x804646B0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_804646D0;
    // 0x804646B0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x804646B4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_804646B8:
    // 0x804646B8: jal         0x80067D5C
    // 0x804646BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x804646BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x804646C0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x804646C4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x804646C8: jal         0x800678F0
    // 0x804646CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x804646CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
L_804646D0:
    // 0x804646D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804646D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804646D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804646DC: jr          $ra
    // 0x804646E0: nop

    return;
    // 0x804646E0: nop

;}
RECOMP_FUNC void func_80037048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003704C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037050: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037054: jal         0x80036F00
    // 0x80037058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80036F00(rdram, ctx);
        goto after_0;
    // 0x80037058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003705C: jal         0x80024260
    // 0x80037060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80024260(rdram, ctx);
        goto after_1;
    // 0x80037060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003706C: jr          $ra
    // 0x80037070: nop

    return;
    // 0x80037070: nop

;}
RECOMP_FUNC void func_806F88C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F88C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F88C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F88CC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F88D0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F88D4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806F88D8: beq         $v0, $zero, L_806F8900
    if (ctx->r2 == 0) {
        // 0x806F88DC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806F8900;
    }
    // 0x806F88DC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806F88E0: bne         $t6, $zero, L_806F8964
    if (ctx->r14 != 0) {
        // 0x806F88E4: sw          $t6, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r14;
            goto L_806F8964;
    }
    // 0x806F88E4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x806F88E8: addiu       $a0, $zero, 0x218
    ctx->r4 = ADD32(0, 0X218);
    // 0x806F88EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F88F0: jal         0x80067818
    // 0x806F88F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x806F88F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x806F88F8: b           L_806F8964
    // 0x806F88FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_806F8964;
    // 0x806F88FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_806F8900:
    // 0x806F8900: lwc1        $f0, 0x5F0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5F0);
    // 0x806F8904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F8908: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806F890C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x806F8910: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806F8914: nop

    // 0x806F8918: bc1fl       L_806F8964
    if (!c1cs) {
        // 0x806F891C: swc1        $f0, 0x5F0($v1)
        MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
            goto L_806F8964;
    }
    goto skip_0;
    // 0x806F891C: swc1        $f0, 0x5F0($v1)
    MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
    skip_0:
    // 0x806F8920: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806F8924: jal         0x8004700C
    // 0x806F8928: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x806F8928: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x806F892C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F8930: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8934: beq         $v0, $zero, L_806F8960
    if (ctx->r2 == 0) {
        // 0x806F8938: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806F8960;
    }
    // 0x806F8938: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F893C: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(694, 0X116C) << 16);
    // 0x806F8940: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x806F8944: addiu       $t9, $t9, -0x7684
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(694, 0X116C));
    // 0x806F8948: sb          $t8, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r24;
    // 0x806F894C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806F8950: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F8954: sb          $t0, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r8;
    // 0x806F8958: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x806F895C: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
L_806F8960:
    // 0x806F8960: swc1        $f0, 0x5F0($v1)
    MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
L_806F8964:
    // 0x806F8964: jal         0x806F85A0
    // 0x806F8968: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    func_806F85A0(rdram, ctx);
        goto after_2;
    // 0x806F8968: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    after_2:
    // 0x806F896C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8974: jr          $ra
    // 0x806F8978: nop

    return;
    // 0x806F8978: nop

;}
RECOMP_FUNC void func_80037498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037498: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003749C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800374A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800374A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800374A8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800374AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800374B0: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x800374B4: jal         0x8006593C
    // 0x800374B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x800374B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800374BC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800374C0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800374C4: beq         $t7, $zero, L_8003755C
    if (ctx->r15 == 0) {
        // 0x800374C8: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_8003755C;
    }
    // 0x800374C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800374CC: lw          $t8, 0x78($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X78);
    // 0x800374D0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800374D4: beql        $t8, $zero, L_80037690
    if (ctx->r24 == 0) {
        // 0x800374D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037690;
    }
    goto skip_0;
    // 0x800374D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800374DC: lbu         $t9, -0x7684($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7684);
    // 0x800374E0: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x800374E4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800374E8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800374EC: beq         $t9, $t0, L_80037520
    if (ctx->r25 == ctx->r8) {
        // 0x800374F0: nop
    
            goto L_80037520;
    }
    // 0x800374F0: nop

    // 0x800374F4: lw          $t1, 0x12EC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X12EC);
    // 0x800374F8: bne         $t1, $zero, L_80037510
    if (ctx->r9 != 0) {
        // 0x800374FC: nop
    
            goto L_80037510;
    }
    // 0x800374FC: nop

    // 0x80037500: jal         0x80040FD4
    // 0x80037504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040FD4(rdram, ctx);
        goto after_1;
    // 0x80037504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80037508: b           L_80037548
    // 0x8003750C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80037548;
    // 0x8003750C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037510:
    // 0x80037510: jal         0x80040C9C
    // 0x80037514: nop

    func_80040C9C(rdram, ctx);
        goto after_2;
    // 0x80037514: nop

    after_2:
    // 0x80037518: b           L_80037548
    // 0x8003751C: addiu       $a1, $v0, 0xB
    ctx->r5 = ADD32(ctx->r2, 0XB);
        goto L_80037548;
    // 0x8003751C: addiu       $a1, $v0, 0xB
    ctx->r5 = ADD32(ctx->r2, 0XB);
L_80037520:
    // 0x80037520: bne         $t2, $at, L_80037530
    if (ctx->r10 != ctx->r1) {
        // 0x80037524: nop
    
            goto L_80037530;
    }
    // 0x80037524: nop

    // 0x80037528: b           L_80037690
    // 0x8003752C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037690;
    // 0x8003752C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037530:
    // 0x80037530: jal         0x80040CE0
    // 0x80037534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040CE0(rdram, ctx);
        goto after_3;
    // 0x80037534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80037538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003753C: jal         0x80040E24
    // 0x80037540: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80040E24(rdram, ctx);
        goto after_4;
    // 0x80037540: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80037544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037548:
    // 0x80037548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003754C: jal         0x8004115C
    // 0x80037550: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_8004115C(rdram, ctx);
        goto after_5;
    // 0x80037550: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80037554: b           L_80037694
    // 0x80037558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037694;
    // 0x80037558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003755C:
    // 0x8003755C: lwc1        $f4, 0x10C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80037560: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80037564: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037568: lwc1        $f8, 0xF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XF0);
    // 0x8003756C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037570: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037574: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80037578: nop

    // 0x8003757C: bc1tl       L_800375B0
    if (c1cs) {
        // 0x80037580: lwc1        $f12, 0x120($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
            goto L_800375B0;
    }
    goto skip_1;
    // 0x80037580: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    skip_1:
    // 0x80037584: lwc1        $f10, 0xF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XF4);
    // 0x80037588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003758C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80037590: nop

    // 0x80037594: bc1tl       L_800375B0
    if (c1cs) {
        // 0x80037598: lwc1        $f12, 0x120($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
            goto L_800375B0;
    }
    goto skip_2;
    // 0x80037598: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    skip_2:
    // 0x8003759C: jal         0x80037380
    // 0x800375A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80037380(rdram, ctx);
        goto after_6;
    // 0x800375A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x800375A4: b           L_80037694
    // 0x800375A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037694;
    // 0x800375A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800375AC: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
L_800375B0:
    // 0x800375B0: jal         0x80066E88
    // 0x800375B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x800375B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_7:
    // 0x800375B8: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800375BC: lwc1        $f18, 0x100($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800375C0: lwc1        $f8, 0x10C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800375C4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800375C8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800375CC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800375D0: lwc1        $f16, 0x68($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X68);
    // 0x800375D4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800375D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800375DC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800375E0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800375E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800375E8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800375EC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800375F0: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x800375F4: nop

    // 0x800375F8: bc1f        L_80037670
    if (!c1cs) {
        // 0x800375FC: nop
    
            goto L_80037670;
    }
    // 0x800375FC: nop

    // 0x80037600: bnel        $t3, $at, L_80037614
    if (ctx->r11 != ctx->r1) {
        // 0x80037604: lbu         $t4, 0x22($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X22);
            goto L_80037614;
    }
    goto skip_3;
    // 0x80037604: lbu         $t4, 0x22($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X22);
    skip_3:
    // 0x80037608: b           L_80037690
    // 0x8003760C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80037690;
    // 0x8003760C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037610: lbu         $t4, 0x22($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X22);
L_80037614:
    // 0x80037614: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80037618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003761C: bne         $t4, $at, L_80037634
    if (ctx->r12 != ctx->r1) {
        // 0x80037620: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037634;
    }
    // 0x80037620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037624: jal         0x80040E24
    // 0x80037628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040E24(rdram, ctx);
        goto after_8;
    // 0x80037628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8003762C: b           L_80037640
    // 0x80037630: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80037640;
    // 0x80037630: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037634:
    // 0x80037634: jal         0x80040E24
    // 0x80037638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80040E24(rdram, ctx);
        goto after_9;
    // 0x80037638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8003763C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80037640:
    // 0x80037640: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x80037644: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80037648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003764C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80037650: jal         0x8004115C
    // 0x80037654: sb          $t5, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r13;
    func_8004115C(rdram, ctx);
        goto after_10;
    // 0x80037654: sb          $t5, -0x7684($at)
    MEM_B(-0X7684, ctx->r1) = ctx->r13;
    after_10:
    // 0x80037658: bne         $v0, $zero, L_8003768C
    if (ctx->r2 != 0) {
        // 0x8003765C: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8003768C;
    }
    // 0x8003765C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80037660: lwc1        $f8, 0xF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XF8);
    // 0x80037664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037668: b           L_80037690
    // 0x8003766C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
        goto L_80037690;
    // 0x8003766C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
L_80037670:
    // 0x80037670: lw          $t9, -0xFF4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFF4);
    // 0x80037674: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037678: lbu         $a1, -0xFBF($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFBF);
    // 0x8003767C: jalr        $t9
    // 0x80037680: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x80037680: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_11:
    // 0x80037684: b           L_80037690
    // 0x80037688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037690;
    // 0x80037688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003768C:
    // 0x8003768C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037690:
    // 0x80037690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037694:
    // 0x80037694: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003769C: jr          $ra
    // 0x800376A0: nop

    return;
    // 0x800376A0: nop

;}
RECOMP_FUNC void func_80048EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048EFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80048F00: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80048F04: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80048F08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80048F0C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80048F10: lwc1        $f16, 0x84($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X84);
    // 0x80048F14: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80048F18: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80048F1C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80048F20: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80048F24: lw          $a2, 0x94($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X94);
    // 0x80048F28: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80048F2C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80048F30: lw          $a3, 0x90($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X90);
    // 0x80048F34: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80048F38: lwc1        $f4, 0x88($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X88);
    // 0x80048F3C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80048F40: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80048F44: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80048F48: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80048F4C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80048F50: nop

    // 0x80048F54: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80048F58: lh          $t3, 0x13E($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X13E);
    // 0x80048F5C: srl         $t4, $t3, 1
    ctx->r12 = S32(U32(ctx->r11) >> 1);
    // 0x80048F60: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80048F64: lh          $t5, 0x13C($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X13C);
    // 0x80048F68: srl         $t6, $t5, 1
    ctx->r14 = S32(U32(ctx->r13) >> 1);
    // 0x80048F6C: jal         0x80065BC8
    // 0x80048F70: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80065BC8(rdram, ctx);
        goto after_0;
    // 0x80048F70: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80048F74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80048F78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80048F7C: jr          $ra
    // 0x80048F80: nop

    return;
    // 0x80048F80: nop

;}
RECOMP_FUNC void func_8003D9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D9E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003D9F0: beq         $a1, $zero, L_8003DA20
    if (ctx->r5 == 0) {
        // 0x8003D9F4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003DA20;
    }
    // 0x8003D9F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003D9F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003D9FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003DA00: jal         0x8003D8DC
    // 0x8003DA04: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8003D8DC(rdram, ctx);
        goto after_0;
    // 0x8003DA04: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003DA08: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DA0C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8003DA10: lw          $t6, 0x174($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X174);
    // 0x8003DA14: lw          $t9, 0x174($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X174);
    // 0x8003DA18: lbu         $t7, 0x1C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1C);
    // 0x8003DA1C: sb          $t7, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r15;
L_8003DA20:
    // 0x8003DA20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DA24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DA28: jr          $ra
    // 0x8003DA2C: nop

    return;
    // 0x8003DA2C: nop

;}
RECOMP_FUNC void func_8002ED3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ED3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002ED40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ED44: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002ED48: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8002ED4C: lw          $a2, 0xD4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XD4);
    // 0x8002ED50: jal         0x8002DBE4
    // 0x8002ED54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x8002ED54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002ED58: jal         0x8001D770
    // 0x8002ED5C: nop

    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x8002ED5C: nop

    after_1:
    // 0x8002ED60: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002ED64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002ED68: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8002ED6C: jal         0x80067BF8
    // 0x8002ED70: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x8002ED70: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x8002ED74: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002ED78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002ED7C: jal         0x80067838
    // 0x8002ED80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8002ED80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8002ED84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002ED88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002ED8C: jr          $ra
    // 0x8002ED90: nop

    return;
    // 0x8002ED90: nop

;}
RECOMP_FUNC void func_8069D580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D580: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(574, 0X30) << 16);
    // 0x8069D584: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8069D588: jr          $ra
    // 0x8069D58C: addiu       $v0, $v0, -0x2A50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(574, 0X30));
    return;
    // 0x8069D58C: addiu       $v0, $v0, -0x2A50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(574, 0X30));
;}
RECOMP_FUNC void guOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CCD4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8008CCD8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008CCDC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8008CCE0: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8008CCE4: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8008CCE8: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8008CCEC: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8008CCF0: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8008CCF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008CCF8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8008CCFC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8008CD00: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8008CD04: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8008CD08: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008CD0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8008CD10: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8008CD14: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8008CD18: jal         0x8008CB80
    // 0x8008CD1C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrthoF(rdram, ctx);
        goto after_0;
    // 0x8008CD1C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8008CD20: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008CD24: jal         0x80086DA0
    // 0x8008CD28: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8008CD28: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8008CD2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008CD30: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8008CD34: jr          $ra
    // 0x8008CD38: nop

    return;
    // 0x8008CD38: nop

;}
RECOMP_FUNC void func_80076190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076190: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80076194: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80076198: addiu       $a1, $a1, -0x7AF0
    ctx->r5 = ADD32(ctx->r5, -0X7AF0);
    // 0x8007619C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800761A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800761A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800761A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800761AC: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x800761B0: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x800761B4: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x800761B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800761BC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800761C0: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800761C4: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800761C8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800761CC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800761D0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x800761D4: bne         $t0, $zero, L_80076290
    if (ctx->r8 != 0) {
        // 0x800761D8: nop
    
            goto L_80076290;
    }
    // 0x800761D8: nop

    // 0x800761DC: jal         0x80071760
    // 0x800761E0: nop

    func_80071760(rdram, ctx);
        goto after_0;
    // 0x800761E0: nop

    after_0:
    // 0x800761E4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800761E8: addiu       $a1, $a1, -0x7AF0
    ctx->r5 = ADD32(ctx->r5, -0X7AF0);
    // 0x800761EC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800761F0: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x800761F4: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    // 0x800761F8: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800761FC: lbu         $t2, -0x7AE0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X7AE0);
    // 0x80076200: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80076204: sb          $t2, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r10;
    // 0x80076208: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8007620C: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x80076210: lbu         $t6, 0x8($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X8);
    // 0x80076214: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80076218: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x8007621C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80076220: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x80076224: lbu         $t8, 0x9($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9);
    // 0x80076228: sb          $t8, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r24;
    // 0x8007622C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80076230: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x80076234: lhu         $t0, 0xA($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XA);
    // 0x80076238: sh          $t0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r8;
    // 0x8007623C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80076240: lw          $t1, 0x14($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X14);
    // 0x80076244: lhu         $t3, 0xC($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0XC);
    // 0x80076248: sh          $t3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r11;
    // 0x8007624C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80076250: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x80076254: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80076258: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x8007625C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80076260: lw          $t5, -0x260C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X260C);
    // 0x80076264: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80076268: sw          $t8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r24;
    // 0x8007626C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80076270: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
    // 0x80076274: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80076278: sw          $t8, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r24;
    // 0x8007627C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80076280: sw          $t7, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r15;
    // 0x80076284: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x80076288: jal         0x80075830
    // 0x8007628C: sw          $t8, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r24;
    func_80075830(rdram, ctx);
        goto after_1;
    // 0x8007628C: sw          $t8, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r24;
    after_1:
L_80076290:
    // 0x80076290: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80076294: jal         0x8007288C
    // 0x80076298: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    func_8007288C(rdram, ctx);
        goto after_2;
    // 0x80076298: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    after_2:
    // 0x8007629C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800762A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800762A4: lw          $a1, -0x7ADC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7ADC);
    // 0x800762A8: jal         0x80072940
    // 0x800762AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80072940(rdram, ctx);
        goto after_3;
    // 0x800762AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800762B0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800762B4: lw          $a1, -0x26A0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26A0);
    // 0x800762B8: jal         0x800728CC
    // 0x800762BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800728CC(rdram, ctx);
        goto after_4;
    // 0x800762BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800762C0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800762C4: addiu       $t9, $s0, 0xF
    ctx->r25 = ADD32(ctx->r16, 0XF);
    // 0x800762C8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800762CC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800762D0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800762D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800762D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800762DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800762E0: jr          $ra
    // 0x800762E4: nop

    return;
    // 0x800762E4: nop

;}
RECOMP_FUNC void func_804C2378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C237C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C2380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C2384: jal         0x80045A34
    // 0x804C2388: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C2388: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x804C238C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C2390: bne         $v0, $zero, L_804C23A0
    if (ctx->r2 != 0) {
        // 0x804C2394: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804C23A0;
    }
    // 0x804C2394: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C2398: b           L_804C23AC
    // 0x804C239C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C23AC;
    // 0x804C239C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C23A0:
    // 0x804C23A0: jal         0x804C2348
    // 0x804C23A4: nop

    func_804C2348(rdram, ctx);
        goto after_1;
    // 0x804C23A4: nop

    after_1:
    // 0x804C23A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C23AC:
    // 0x804C23AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C23B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C23B4: jr          $ra
    // 0x804C23B8: nop

    return;
    // 0x804C23B8: nop

;}
RECOMP_FUNC void func_807BC760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC768: lbu         $t6, 0x165($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X165);
    // 0x807BC76C: bnel        $t6, $zero, L_807BC780
    if (ctx->r14 != 0) {
        // 0x807BC770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807BC780;
    }
    goto skip_0;
    // 0x807BC770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807BC774: jal         0x807BC600
    // 0x807BC778: nop

    func_807BC600(rdram, ctx);
        goto after_0;
    // 0x807BC778: nop

    after_0:
    // 0x807BC77C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BC780:
    // 0x807BC780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC784: jr          $ra
    // 0x807BC788: nop

    return;
    // 0x807BC788: nop

;}
RECOMP_FUNC void func_8001B960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B960: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001B964: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8001B968: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001B96C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001B970: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8001B974: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8001B978: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8001B97C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001B980: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8001B984: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8001B988: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8001B98C: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x8001B990: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001B994: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001B998: addiu       $s3, $s3, 0x660
    ctx->r19 = ADD32(ctx->r19, 0X660);
    // 0x8001B99C: addiu       $s1, $s1, 0x1470
    ctx->r17 = ADD32(ctx->r17, 0X1470);
    // 0x8001B9A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001B9A4: addiu       $s4, $zero, 0x48
    ctx->r20 = ADD32(0, 0X48);
    // 0x8001B9A8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8001B9AC:
    // 0x8001B9AC: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B9B0: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B9B4: addu        $a0, $s3, $t6
    ctx->r4 = ADD32(ctx->r19, ctx->r14);
    // 0x8001B9B8: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8001B9BC: beql        $t7, $zero, L_8001BA14
    if (ctx->r15 == 0) {
        // 0x8001B9C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001BA14;
    }
    goto skip_0;
    // 0x8001B9C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001B9C4: beq         $s2, $zero, L_8001B9F0
    if (ctx->r18 == 0) {
        // 0x8001B9C8: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_8001B9F0;
    }
    // 0x8001B9C8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001B9CC: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001B9D0: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x8001B9D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001B9D8: sb          $s5, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = ctx->r21;
    // 0x8001B9DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B9E0: jal         0x8001BCD0
    // 0x8001B9E4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    func_8001BCD0(rdram, ctx);
        goto after_0;
    // 0x8001B9E4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    after_0:
    // 0x8001B9E8: b           L_8001BA14
    // 0x8001B9EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8001BA14;
    // 0x8001B9EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001B9F0:
    // 0x8001B9F0: lbu         $t0, 0x3C($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X3C);
    // 0x8001B9F4: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8001B9F8: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x8001B9FC: beq         $t0, $zero, L_8001BA10
    if (ctx->r8 == 0) {
        // 0x8001BA00: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001BA10;
    }
    // 0x8001BA00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001BA04: sb          $zero, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = 0;
    // 0x8001BA08: jal         0x8001BCD0
    // 0x8001BA0C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    func_8001BCD0(rdram, ctx);
        goto after_1;
    // 0x8001BA0C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_1:
L_8001BA10:
    // 0x8001BA10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001BA14:
    // 0x8001BA14: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8001BA18: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001BA1C: slti        $at, $s0, 0x32
    ctx->r1 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
    // 0x8001BA20: bne         $at, $zero, L_8001B9AC
    if (ctx->r1 != 0) {
        // 0x8001BA24: nop
    
            goto L_8001B9AC;
    }
    // 0x8001BA24: nop

    // 0x8001BA28: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001BA2C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001BA30: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BA34: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001BA38: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8001BA3C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8001BA40: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BA44: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8001BA48: jr          $ra
    // 0x8001BA4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001BA4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8075FB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FB80: lui         $v0, 0x8076
    ctx->r2 = S32(RELOC_HI16(760, 0X108) << 16);
    // 0x8075FB84: addiu       $v0, $v0, -0x378
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(760, 0X108));
    // 0x8075FB88: jr          $ra
    // 0x8075FB8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8075FB8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80735DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735DA8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80735DAC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80735DB0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80735DB4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80735DB8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80735DBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80735DC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80735DC4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80735DC8: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X3948) << 16);
    // 0x80735DCC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80735DD0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80735DD4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80735DD8: lw          $t1, -0x6C58($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(736, 0X3948));
    // 0x80735DDC: jr          $ra
    // 0x80735DE0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80735DE0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804467CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804467CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804467D0: addiu       $t6, $zero, 0x744
    ctx->r14 = ADD32(0, 0X744);
    // 0x804467D4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804467D8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x804467DC: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x804467E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804467E4: jr          $ra
    // 0x804467E8: sw          $t7, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r15;
    return;
    // 0x804467E8: sw          $t7, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80525F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525F7C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80525F80: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(327, 0X674) << 16);
    // 0x80525F84: addiu       $t6, $t6, 0x6574
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0X674));
    // 0x80525F88: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80525F8C: jr          $ra
    // 0x80525F90: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80525F90: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807BC704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC70C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807BC710: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(898, 0X6E70) << 16);
    // 0x807BC714: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807BC718: addiu       $t6, $t6, 0x2B30
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(898, 0X6E70));
    // 0x807BC71C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807BC720: lui         $t0, 0x807C
    ctx->r8 = S32(RELOC_HI16(898, 0XA1C) << 16);
    // 0x807BC724: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807BC728: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x807BC72C: addiu       $t0, $t0, -0x3924
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(898, 0XA1C));
    // 0x807BC730: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x807BC734: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807BC738: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807BC73C: sh          $t9, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r25;
    // 0x807BC740: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x807BC744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC748: jal         0x807BC78C
    // 0x807BC74C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807BC78C(rdram, ctx);
        goto after_0;
    // 0x807BC74C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807BC750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC758: jr          $ra
    // 0x807BC75C: nop

    return;
    // 0x807BC75C: nop

;}
RECOMP_FUNC void func_80035540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035540: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80035544: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80035548: sll         $s3, $a2, 16
    ctx->r19 = S32(ctx->r6 << 16);
    // 0x8003554C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80035550: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80035554: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80035558: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8003555C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80035560: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80035564: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80035568: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003556C: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80035570: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80035574: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80035578: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8003557C: beq         $s3, $zero, L_80035614
    if (ctx->r19 == 0) {
        // 0x80035580: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80035614;
    }
    // 0x80035580: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80035584: lwc1        $f22, 0x58($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035588: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8003558C: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
L_80035590:
    // 0x80035590: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80035594: beq         $s0, $zero, L_8003560C
    if (ctx->r16 == 0) {
        // 0x80035598: nop
    
            goto L_8003560C;
    }
    // 0x80035598: nop

    // 0x8003559C: beql        $s5, $s0, L_80035604
    if (ctx->r21 == ctx->r16) {
        // 0x800355A0: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80035604;
    }
    goto skip_0;
    // 0x800355A0: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_0:
    // 0x800355A4: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
    // 0x800355A8: beql        $t6, $s0, L_80035604
    if (ctx->r14 == ctx->r16) {
        // 0x800355AC: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80035604;
    }
    goto skip_1;
    // 0x800355AC: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_1:
    // 0x800355B0: lh          $a2, 0x184($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X184);
    // 0x800355B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800355B8: addiu       $a1, $s0, 0x188
    ctx->r5 = ADD32(ctx->r16, 0X188);
    // 0x800355BC: beql        $a2, $zero, L_800355DC
    if (ctx->r6 == 0) {
        // 0x800355C0: lwc1        $f4, 0x84($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
            goto L_800355DC;
    }
    goto skip_2;
    // 0x800355C0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    skip_2:
    // 0x800355C4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800355C8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x800355CC: jal         0x80035540
    // 0x800355D0: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    func_80035540(rdram, ctx);
        goto after_0;
    // 0x800355D0: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_0:
    // 0x800355D4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800355D8: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
L_800355DC:
    // 0x800355DC: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x800355E0: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x800355E4: jal         0x80065954
    // 0x800355E8: lwc1        $f12, 0x14($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X14);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x800355E8: lwc1        $f12, 0x14($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X14);
    after_1:
    // 0x800355EC: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x800355F0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800355F4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800355F8: jalr        $s4
    // 0x800355FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_2;
    // 0x800355FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80035600: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80035604:
    // 0x80035604: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80035608: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
L_8003560C:
    // 0x8003560C: bne         $s3, $zero, L_80035590
    if (ctx->r19 != 0) {
        // 0x80035610: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80035590;
    }
    // 0x80035610: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80035614:
    // 0x80035614: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80035618: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003561C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80035620: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80035624: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80035628: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8003562C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80035630: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80035634: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80035638: jr          $ra
    // 0x8003563C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003563C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800468E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800468E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800468EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800468F0: lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5);
    // 0x800468F4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800468F8: addiu       $a1, $zero, 0x5BD
    ctx->r5 = ADD32(0, 0X5BD);
    // 0x800468FC: bnel        $v1, $zero, L_8004691C
    if (ctx->r3 != 0) {
        // 0x80046900: lbu         $t6, 0x4($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X4);
            goto L_8004691C;
    }
    goto skip_0;
    // 0x80046900: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    skip_0:
    // 0x80046904: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046908: jal         0x80071380
    // 0x8004690C: addiu       $a0, $a0, 0x720
    ctx->r4 = ADD32(ctx->r4, 0X720);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8004690C: addiu       $a0, $a0, 0x720
    ctx->r4 = ADD32(ctx->r4, 0X720);
    after_0:
    // 0x80046910: b           L_8004696C
    // 0x80046914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004696C;
    // 0x80046914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046918: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
L_8004691C:
    // 0x8004691C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80046920: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80046924: beq         $t6, $at, L_80046968
    if (ctx->r14 == ctx->r1) {
        // 0x80046928: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_80046968;
    }
    // 0x80046928: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8004692C: sh          $t7, 0x17E($a0)
    MEM_H(0X17E, ctx->r4) = ctx->r15;
    // 0x80046930: beq         $v1, $at, L_80046958
    if (ctx->r3 == ctx->r1) {
        // 0x80046934: sw          $zero, 0x1D8($a0)
        MEM_W(0X1D8, ctx->r4) = 0;
            goto L_80046958;
    }
    // 0x80046934: sw          $zero, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = 0;
    // 0x80046938: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8004693C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80046940: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80046944: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80046948: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x8004694C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80046950: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80046954: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
L_80046958:
    // 0x80046958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004695C: sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // 0x80046960: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046964: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
L_80046968:
    // 0x80046968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004696C:
    // 0x8004696C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046970: jr          $ra
    // 0x80046974: nop

    return;
    // 0x80046974: nop

;}
RECOMP_FUNC void func_806E7150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7150: jr          $ra
    // 0x806E7154: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E7154: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806B255C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B255C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2560: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2564: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2568: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B256C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2570: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2574: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2578: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B257C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2580: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2584: jr          $ra
    // 0x806B2588: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2588: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804461A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804461A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804461A4: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x804461A8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804461AC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x804461B0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x804461B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804461B8: jr          $ra
    // 0x804461BC: sw          $t7, 0x6CA4($at)
    MEM_W(0X6CA4, ctx->r1) = ctx->r15;
    return;
    // 0x804461BC: sw          $t7, 0x6CA4($at)
    MEM_W(0X6CA4, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80799FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799FB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80799FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799FB8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80799FBC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80799FC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80799FC4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80799FC8: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80799FCC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80799FD0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80799FD4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80799FD8: lbu         $t6, 0xF5C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF5C);
    // 0x80799FDC: lbu         $t8, 0xF5D($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80799FE0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80799FE4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80799FE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80799FEC: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80799FF0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80799FF4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80799FF8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80799FFC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8079A000: lw          $t9, 0xEC8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEC8);
    // 0x8079A004: lhu         $a0, 0x630C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X630C);
    // 0x8079A008: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8079A00C: jalr        $t9
    // 0x8079A010: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8079A010: nop

    after_0:
    // 0x8079A014: jal         0x80067E68
    // 0x8079A018: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x8079A018: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x8079A01C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8079A020: jal         0x80067818
    // 0x8079A024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8079A024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8079A028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079A02C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8079A030: jr          $ra
    // 0x8079A034: nop

    return;
    // 0x8079A034: nop

;}
RECOMP_FUNC void func_805366E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805366E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805366E8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805366EC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805366F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805366F4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805366F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805366FC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536700: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536704: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536708: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053670C: jr          $ra
    // 0x80536710: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536710: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8076D8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D8EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076D8F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076D8F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8076D8F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8076D8FC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D900: jal         0x8076D250
    // 0x8076D904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8076D250(rdram, ctx);
        goto after_0;
    // 0x8076D904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8076D908: beq         $v0, $zero, L_8076D944
    if (ctx->r2 == 0) {
        // 0x8076D90C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8076D944;
    }
    // 0x8076D90C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8076D910: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X34E8) << 16);
    // 0x8076D914: addiu       $v0, $v0, -0x328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X34E8));
    // 0x8076D918: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8076D91C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8076D920: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8076D924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D928: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    // 0x8076D92C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8076D930: sw          $t9, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r25;
    // 0x8076D934: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8076D938: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8076D93C: jal         0x8076DD8C
    // 0x8076D940: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_1;
    // 0x8076D940: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
L_8076D944:
    // 0x8076D944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8076D948: jal         0x8076CD88
    // 0x8076D94C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8076CD88(rdram, ctx);
        goto after_2;
    // 0x8076D94C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8076D950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076D954: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8076D958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076D95C: jr          $ra
    // 0x8076D960: nop

    return;
    // 0x8076D960: nop

;}
RECOMP_FUNC void func_8073EBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EBFC: jr          $ra
    // 0x8073EC00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073EC00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80038A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038A6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80038A70: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80038A74: lw          $t6, 0x3D50($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D50);
    // 0x80038A78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80038A7C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80038A80: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80038A84: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80038A88: addiu       $a0, $zero, 0x4003
    ctx->r4 = ADD32(0, 0X4003);
    // 0x80038A8C: jal         0x80047090
    // 0x80038A90: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80038A90: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80038A94: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80038A98: lui         $at, 0x4003
    ctx->r1 = S32(0X4003 << 16);
    // 0x80038A9C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80038AA0: or          $a1, $v0, $at
    ctx->r5 = ctx->r2 | ctx->r1;
    // 0x80038AA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80038AA8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80038AAC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80038AB0: jal         0x80046804
    // 0x80038AB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x80038AB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80038AB8: bne         $v0, $zero, L_80038AC8
    if (ctx->r2 != 0) {
        // 0x80038ABC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80038AC8;
    }
    // 0x80038ABC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80038AC0: b           L_80038AF0
    // 0x80038AC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038AF0;
    // 0x80038AC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038AC8:
    // 0x80038AC8: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x80038ACC: bnel        $t7, $zero, L_80038AF0
    if (ctx->r15 != 0) {
        // 0x80038AD0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80038AF0;
    }
    goto skip_0;
    // 0x80038AD0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
    // 0x80038AD4: jal         0x800389F4
    // 0x80038AD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800389F4(rdram, ctx);
        goto after_2;
    // 0x80038AD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80038ADC: bne         $v0, $zero, L_80038AEC
    if (ctx->r2 != 0) {
        // 0x80038AE0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80038AEC;
    }
    // 0x80038AE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80038AE4: b           L_80038AF0
    // 0x80038AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038AF0;
    // 0x80038AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038AEC:
    // 0x80038AEC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80038AF0:
    // 0x80038AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80038AF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80038AF8: jr          $ra
    // 0x80038AFC: nop

    return;
    // 0x80038AFC: nop

;}
RECOMP_FUNC void func_8005F8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F8A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F8A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005F8AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005F8B0: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8005F8B4: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8005F8B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005F8BC: addiu       $s1, $s1, 0x634C
    ctx->r17 = ADD32(ctx->r17, 0X634C);
    // 0x8005F8C0: addiu       $s0, $s0, 0x6344
    ctx->r16 = ADD32(ctx->r16, 0X6344);
L_8005F8C4:
    // 0x8005F8C4: jal         0x8005DB78
    // 0x8005F8C8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_8005DB78(rdram, ctx);
        goto after_0;
    // 0x8005F8C8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_0:
    // 0x8005F8CC: jal         0x8005E278
    // 0x8005F8D0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_8005E278(rdram, ctx);
        goto after_1;
    // 0x8005F8D0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_1:
    // 0x8005F8D4: jal         0x8005E820
    // 0x8005F8D8: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    func_8005E820(rdram, ctx);
        goto after_2;
    // 0x8005F8D8: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x8005F8DC: jal         0x8005EFE0
    // 0x8005F8E0: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    func_8005EFE0(rdram, ctx);
        goto after_3;
    // 0x8005F8E0: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    after_3:
    // 0x8005F8E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8005F8E8: bne         $s0, $s1, L_8005F8C4
    if (ctx->r16 != ctx->r17) {
        // 0x8005F8EC: nop
    
            goto L_8005F8C4;
    }
    // 0x8005F8EC: nop

    // 0x8005F8F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F8F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005F8F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005F8FC: jr          $ra
    // 0x8005F900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005F900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800579A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800579A0: lh          $a1, 0x8($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X8);
    // 0x800579A4: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800579A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800579AC: blezl       $a1, L_800579DC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800579B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800579DC;
    }
    goto skip_0;
    // 0x800579B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800579B4:
    // 0x800579B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800579B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800579BC: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800579C0: bne         $t6, $zero, L_800579D0
    if (ctx->r14 != 0) {
        // 0x800579C4: nop
    
            goto L_800579D0;
    }
    // 0x800579C4: nop

    // 0x800579C8: jr          $ra
    // 0x800579CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800579CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800579D0:
    // 0x800579D0: bne         $at, $zero, L_800579B4
    if (ctx->r1 != 0) {
        // 0x800579D4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800579B4;
    }
    // 0x800579D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800579D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800579DC:
    // 0x800579DC: jr          $ra
    // 0x800579E0: nop

    return;
    // 0x800579E0: nop

;}
RECOMP_FUNC void func_804F5384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5384: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804F5388: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F538C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804F5390: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804F5394: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804F5398: jal         0x8004700C
    // 0x804F539C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804F539C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x804F53A0: beq         $v0, $zero, L_804F53DC
    if (ctx->r2 == 0) {
        // 0x804F53A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804F53DC;
    }
    // 0x804F53A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804F53A8: jal         0x80047AB8
    // 0x804F53AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x804F53AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x804F53B0: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x804F53B4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804F53B8: jal         0x80065954
    // 0x804F53BC: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x804F53BC: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_2:
    // 0x804F53C0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x804F53C4: lwc1        $f2, 0x3C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x804F53C8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804F53CC: jal         0x80065954
    // 0x804F53D0: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x804F53D0: sub.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f2.fl;
    after_3:
    // 0x804F53D4: b           L_804F53F4
    // 0x804F53D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_804F53F4;
    // 0x804F53D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804F53DC:
    // 0x804F53DC: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x804F53E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804F53E4: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x804F53E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804F53EC: nop

    // 0x804F53F0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_804F53F4:
    // 0x804F53F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x804F53F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804F53FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x804F5400: jal         0x804F5134
    // 0x804F5404: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_804F5134(rdram, ctx);
        goto after_4;
    // 0x804F5404: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x804F5408: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x804F540C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804F5410: blez        $v0, L_804F541C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x804F5414: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_804F541C;
    }
    // 0x804F5414: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x804F5418: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
L_804F541C:
    // 0x804F541C: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x804F5420: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x804F5424: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x804F5428: bne         $at, $zero, L_804F5438
    if (ctx->r1 != 0) {
        // 0x804F542C: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_804F5438;
    }
    // 0x804F542C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x804F5430: b           L_804F5450
    // 0x804F5434: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
        goto L_804F5450;
    // 0x804F5434: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_804F5438:
    // 0x804F5438: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x804F543C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x804F5440: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x804F5444: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804F5448: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x804F544C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
L_804F5450:
    // 0x804F5450: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x804F5454: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804F5458: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x804F545C: bnel        $t2, $zero, L_804F54E4
    if (ctx->r10 != 0) {
        // 0x804F5460: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804F54E4;
    }
    goto skip_0;
    // 0x804F5460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804F5464: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F5468: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x804F546C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804F5470: nop

    // 0x804F5474: bc1fl       L_804F54E4
    if (!c1cs) {
        // 0x804F5478: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804F54E4;
    }
    goto skip_1;
    // 0x804F5478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x804F547C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804F5480: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804F5484: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x804F5488: nop

    // 0x804F548C: bc1fl       L_804F54E4
    if (!c1cs) {
        // 0x804F5490: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804F54E4;
    }
    goto skip_2;
    // 0x804F5490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x804F5494: lw          $t3, -0x6DA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6DA8);
    // 0x804F5498: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x804F549C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F54A0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x804F54A4: lw          $a1, 0x3C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X3C);
    // 0x804F54A8: swc1        $f4, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f4.u32l;
    // 0x804F54AC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x804F54B0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x804F54B4: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x804F54B8: lw          $v0, 0x1F4($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X1F4);
    // 0x804F54BC: lw          $t9, 0x1160($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1160);
    // 0x804F54C0: lw          $a0, 0x115C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X115C);
    // 0x804F54C4: jalr        $t9
    // 0x804F54C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x804F54C8: nop

    after_5:
    // 0x804F54CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804F54D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F54D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804F54D8: jal         0x804F5CE8
    // 0x804F54DC: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_804F5CE8(rdram, ctx);
        goto after_6;
    // 0x804F54DC: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_6:
    // 0x804F54E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F54E4:
    // 0x804F54E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804F54E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804F54EC: jr          $ra
    // 0x804F54F0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x804F54F0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8007662C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007662C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80076630: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80076634: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80076638: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8007663C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80076640: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80076644: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80076648: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007664C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80076650: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80076654: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80076658: lw          $v0, -0x7AE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AE8);
    // 0x8007665C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80076660: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80076664: lw          $s3, -0x7AEC($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X7AEC);
    // 0x80076668: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8007666C: blez        $v0, L_800767F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80076670: sw          $t7, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r15;
            goto L_800767F8;
    }
    // 0x80076670: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80076674: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80076678: addiu       $s2, $s2, -0x7A20
    ctx->r18 = ADD32(ctx->r18, -0X7A20);
    // 0x8007667C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80076680: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
L_80076684:
    // 0x80076684: lw          $s0, 0x4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X4);
    // 0x80076688: beql        $s0, $zero, L_800767EC
    if (ctx->r16 == 0) {
        // 0x8007668C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800767EC;
    }
    goto skip_0;
    // 0x8007668C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x80076690: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80076694: beql        $t8, $zero, L_800766B4
    if (ctx->r24 == 0) {
        // 0x80076698: lbu         $v0, 0x0($s3)
        ctx->r2 = MEM_BU(ctx->r19, 0X0);
            goto L_800766B4;
    }
    goto skip_1;
    // 0x80076698: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    skip_1:
    // 0x8007669C: jal         0x80075DAC
    // 0x800766A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80075DAC(rdram, ctx);
        goto after_0;
    // 0x800766A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800766A4: jal         0x80075FDC
    // 0x800766A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80075FDC(rdram, ctx);
        goto after_1;
    // 0x800766A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800766AC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800766B0: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
L_800766B4:
    // 0x800766B4: addiu       $t9, $v0, -0x3
    ctx->r25 = ADD32(ctx->r2, -0X3);
    // 0x800766B8: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x800766BC: beq         $at, $zero, L_800767B4
    if (ctx->r1 == 0) {
        // 0x800766C0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800767B4;
    }
    // 0x800766C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800766C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800766C8: addu        $at, $at, $t9
    gpr jr_addend_800766D0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800766CC: lw          $t9, 0x26A8($at)
    ctx->r25 = ADD32(ctx->r1, 0X26A8);
    // 0x800766D0: jr          $t9
    // 0x800766D4: nop

    switch (jr_addend_800766D0 >> 2) {
        case 0: goto L_80076780; break;
        case 1: goto L_8007674C; break;
        case 2: goto L_800766D8; break;
        case 3: goto L_8007676C; break;
        case 4: goto L_80076794; break;
        case 5: goto L_800766F8; break;
        case 6: goto L_80076724; break;
        default: switch_error(__func__, 0x800766D0, 0x800B26A8);
    }
    // 0x800766D4: nop

L_800766D8:
    // 0x800766D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800766DC: jal         0x800762E8
    // 0x800766E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800762E8(rdram, ctx);
        goto after_2;
    // 0x800766E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800766E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800766E8: jal         0x80077930
    // 0x800766EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80077930(rdram, ctx);
        goto after_3;
    // 0x800766EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800766F0: b           L_800767E0
    // 0x800766F4: nop

        goto L_800767E0;
    // 0x800766F4: nop

L_800766F8:
    // 0x800766F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800766FC: jal         0x800762E8
    // 0x80076700: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800762E8(rdram, ctx);
        goto after_4;
    // 0x80076700: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80076704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076708: jal         0x8007BEE8
    // 0x8007670C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8007BEE8(rdram, ctx);
        goto after_5;
    // 0x8007670C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80076710: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076714: sw          $zero, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = 0;
    // 0x80076718: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007671C: b           L_800767E0
    // 0x80076720: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
        goto L_800767E0;
    // 0x80076720: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
L_80076724:
    // 0x80076724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076728: jal         0x8007638C
    // 0x8007672C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8007638C(rdram, ctx);
        goto after_6;
    // 0x8007672C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80076730: lhu         $t0, 0x10($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X10);
    // 0x80076734: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80076738: bne         $t1, $zero, L_80076744
    if (ctx->r9 != 0) {
        // 0x8007673C: nop
    
            goto L_80076744;
    }
    // 0x8007673C: nop

    // 0x80076740: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
L_80076744:
    // 0x80076744: b           L_800767E0
    // 0x80076748: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
        goto L_800767E0;
    // 0x80076748: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
L_8007674C:
    // 0x8007674C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80076750: jal         0x800762E8
    // 0x80076754: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800762E8(rdram, ctx);
        goto after_7;
    // 0x80076754: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
    // 0x80076758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007675C: jal         0x80078C20
    // 0x80076760: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80078C20(rdram, ctx);
        goto after_8;
    // 0x80076760: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80076764: b           L_800767E0
    // 0x80076768: nop

        goto L_800767E0;
    // 0x80076768: nop

L_8007676C:
    // 0x8007676C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076770: jal         0x80078A40
    // 0x80076774: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80078A40(rdram, ctx);
        goto after_9;
    // 0x80076774: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80076778: b           L_800767E0
    // 0x8007677C: nop

        goto L_800767E0;
    // 0x8007677C: nop

L_80076780:
    // 0x80076780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076784: jal         0x800787F8
    // 0x80076788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800787F8(rdram, ctx);
        goto after_10;
    // 0x80076788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x8007678C: b           L_800767E0
    // 0x80076790: nop

        goto L_800767E0;
    // 0x80076790: nop

L_80076794:
    // 0x80076794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80076798: jal         0x800762E8
    // 0x8007679C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800762E8(rdram, ctx);
        goto after_11;
    // 0x8007679C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x800767A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800767A4: jal         0x80077F30
    // 0x800767A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80077F30(rdram, ctx);
        goto after_12;
    // 0x800767A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x800767AC: b           L_800767E0
    // 0x800767B0: nop

        goto L_800767E0;
    // 0x800767B0: nop

L_800767B4:
    // 0x800767B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800767B8: sw          $zero, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = 0;
    // 0x800767BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800767C0: sw          $zero, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = 0;
    // 0x800767C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800767C8: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x800767CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800767D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800767D4: sw          $t2, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->r10;
L_800767D8:
    // 0x800767D8: b           L_800767D8
    pause_self(rdram);
    // 0x800767DC: nop

L_800767E0:
    // 0x800767E0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800767E4: lw          $v0, -0x7AE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AE8);
    // 0x800767E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800767EC:
    // 0x800767EC: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800767F0: bne         $at, $zero, L_80076684
    if (ctx->r1 != 0) {
        // 0x800767F4: addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
            goto L_80076684;
    }
    // 0x800767F4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_800767F8:
    // 0x800767F8: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800767FC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80076800: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80076804: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80076808: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007680C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80076810: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80076814: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80076818: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8007681C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80076820: jr          $ra
    // 0x80076824: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80076824: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_805845AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805845AC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805845B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805845B4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805845B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805845BC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805845C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805845C4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805845C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805845CC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805845D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805845D4: jr          $ra
    // 0x805845D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805845D8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807B8298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8298: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B829C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B82A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B82A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B82A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B82AC: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B82B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B82B4: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x807B82B8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x807B82BC: blezl       $v0, L_807B82FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807B82C0: sw          $zero, 0x3C($s2)
        MEM_W(0X3C, ctx->r18) = 0;
            goto L_807B82FC;
    }
    goto skip_0;
    // 0x807B82C0: sw          $zero, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = 0;
    skip_0:
L_807B82C4:
    // 0x807B82C4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x807B82C8: beql        $a0, $zero, L_807B82EC
    if (ctx->r4 == 0) {
        // 0x807B82CC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_807B82EC;
    }
    goto skip_1;
    // 0x807B82CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x807B82D0: jal         0x8005C9A8
    // 0x807B82D4: nop

    func_8005C9A8(rdram, ctx);
        goto after_0;
    // 0x807B82D4: nop

    after_0:
    // 0x807B82D8: jal         0x800447C8
    // 0x807B82DC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807B82DC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_1:
    // 0x807B82E0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x807B82E4: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x807B82E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_807B82EC:
    // 0x807B82EC: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x807B82F0: bne         $at, $zero, L_807B82C4
    if (ctx->r1 != 0) {
        // 0x807B82F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_807B82C4;
    }
    // 0x807B82F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807B82F8: sw          $zero, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = 0;
L_807B82FC:
    // 0x807B82FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B8300: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B8304: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8308: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B830C: jr          $ra
    // 0x807B8310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B8310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80062D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80062D5C: jal         0x80047090
    // 0x80062D60: addiu       $a0, $zero, 0x400D
    ctx->r4 = ADD32(0, 0X400D);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80062D60: addiu       $a0, $zero, 0x400D
    ctx->r4 = ADD32(0, 0X400D);
    after_0:
    // 0x80062D64: lui         $a0, 0x400D
    ctx->r4 = S32(0X400D << 16);
    // 0x80062D68: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80062D6C: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x80062D70: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x80062D74: lui         $a2, 0x42B0
    ctx->r6 = S32(0X42B0 << 16);
    // 0x80062D78: jal         0x8004613C
    // 0x80062D7C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80062D7C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_1:
    // 0x80062D80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80062D84: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x80062D88: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80062D8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80062D90: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80062D94: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80062D98: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80062D9C: jal         0x80062D14
    // 0x80062DA0: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    func_80062D14(rdram, ctx);
        goto after_2;
    // 0x80062DA0: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    after_2:
    // 0x80062DA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80062DA8: jal         0x800461F4
    // 0x80062DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800461F4(rdram, ctx);
        goto after_3;
    // 0x80062DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80062DB0: jal         0x80044194
    // 0x80062DB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x80062DB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80062DB8: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x80062DBC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80062DC0: sw          $t2, 0x1E0($t3)
    MEM_W(0X1E0, ctx->r11) = ctx->r10;
    // 0x80062DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062DCC: jr          $ra
    // 0x80062DD0: nop

    return;
    // 0x80062DD0: nop

;}
RECOMP_FUNC void func_80453A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453A6C: jal         0x804539F0
    // 0x80453A70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_804539F0(rdram, ctx);
        goto after_0;
    // 0x80453A70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80453A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453A7C: jr          $ra
    // 0x80453A80: nop

    return;
    // 0x80453A80: nop

;}
RECOMP_FUNC void func_804BB074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB07C: jal         0x800653D8
    // 0x804BB080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804BB080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB084: andi        $t6, $v0, 0x4F
    ctx->r14 = ctx->r2 & 0X4F;
    // 0x804BB088: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804BB08C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x804BB090: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BB094: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BB098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB09C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804BB0A0: jal         0x804BAC7C
    // 0x804BB0A4: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    func_804BAC7C(rdram, ctx);
        goto after_1;
    // 0x804BB0A4: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x804BB0A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB0AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB0B0: jal         0x804BB4C4
    // 0x804BB0B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804BB4C4(rdram, ctx);
        goto after_2;
    // 0x804BB0B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x804BB0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB0C0: jr          $ra
    // 0x804BB0C4: nop

    return;
    // 0x804BB0C4: nop

;}
RECOMP_FUNC void func_805ABF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABF60: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805ABF64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805ABF68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ABF6C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X59C) << 16);
    // 0x805ABF70: lwc1        $f6, -0x3ED4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X59C));
    // 0x805ABF74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ABF78: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x805ABF7C: addiu       $t6, $zero, -0x10
    ctx->r14 = ADD32(0, -0X10);
    // 0x805ABF80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ABF84: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x805ABF88: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x805ABF8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805ABF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805ABF94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805ABF98: jal         0x805ABD0C
    // 0x805ABF9C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_805ABD0C(rdram, ctx);
        goto after_0;
    // 0x805ABF9C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x805ABFA0: beq         $v0, $zero, L_805ABFB0
    if (ctx->r2 == 0) {
        // 0x805ABFA4: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_805ABFB0;
    }
    // 0x805ABFA4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x805ABFA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805ABFAC: sb          $t7, 0x165($t8)
    MEM_B(0X165, ctx->r24) = ctx->r15;
L_805ABFB0:
    // 0x805ABFB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ABFB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ABFB8: jr          $ra
    // 0x805ABFBC: nop

    return;
    // 0x805ABFBC: nop

;}
RECOMP_FUNC void func_8064B750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B750: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8064B754: lwc1        $f16, 0xDC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8064B758: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064B75C: lwc1        $f6, 0xE8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x8064B760: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8064B764: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064B768: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064B76C: bc1f        L_8064B798
    if (!c1cs) {
        // 0x8064B770: swc1        $f8, 0xC4($a0)
        MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
            goto L_8064B798;
    }
    // 0x8064B770: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8064B774: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8064B778: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8064B77C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B780: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8064B784: nop

    // 0x8064B788: bc1fl       L_8064B7B8
    if (!c1cs) {
        // 0x8064B78C: lwc1        $f6, 0x3C($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_8064B7B8;
    }
    goto skip_0;
    // 0x8064B78C: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x8064B790: b           L_8064B7B4
    // 0x8064B794: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_8064B7B4;
    // 0x8064B794: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8064B798:
    // 0x8064B798: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8064B79C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B7A0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8064B7A4: nop

    // 0x8064B7A8: bc1fl       L_8064B7B8
    if (!c1cs) {
        // 0x8064B7AC: lwc1        $f6, 0x3C($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_8064B7B8;
    }
    goto skip_1;
    // 0x8064B7AC: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    skip_1:
    // 0x8064B7B0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8064B7B4:
    // 0x8064B7B4: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
L_8064B7B8:
    // 0x8064B7B8: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064B7BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8064B7C0: jr          $ra
    // 0x8064B7C4: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8064B7C4: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8076CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CBF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076CBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076CBF8: jal         0x8002FD38
    // 0x8076CBFC: nop

    func_8002FD38(rdram, ctx);
        goto after_0;
    // 0x8076CBFC: nop

    after_0:
    // 0x8076CC00: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8076CC04: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8076CC08: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x8076CC0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076CC10: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8076CC14: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8076CC18: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x8076CC1C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8076CC20: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8076CC24: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x8076CC28: jr          $ra
    // 0x8076CC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8076CC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8057F9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F9B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057F9BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057F9C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057F9C4: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8057F9C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8057F9CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057F9D0: bne         $v0, $at, L_8057FA04
    if (ctx->r2 != ctx->r1) {
        // 0x8057F9D4: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_8057FA04;
    }
    // 0x8057F9D4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F9D8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8057F9DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057F9E0: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8057F9E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057F9E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8057F9EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8057F9F0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8057F9F4: jal         0x805802D8
    // 0x8057F9F8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    func_805802D8(rdram, ctx);
        goto after_0;
    // 0x8057F9F8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x8057F9FC: b           L_8057FA34
    // 0x8057FA00: nop

        goto L_8057FA34;
    // 0x8057FA00: nop

L_8057FA04:
    // 0x8057FA04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8057FA08: bne         $v0, $at, L_8057FA34
    if (ctx->r2 != ctx->r1) {
        // 0x8057FA0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8057FA34;
    }
    // 0x8057FA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FA10: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8057FA14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057FA18: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8057FA1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057FA20: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8057FA24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8057FA28: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8057FA2C: jal         0x805802D8
    // 0x8057FA30: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    func_805802D8(rdram, ctx);
        goto after_1;
    // 0x8057FA30: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    after_1:
L_8057FA34:
    // 0x8057FA34: jal         0x8057F964
    // 0x8057FA38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F964(rdram, ctx);
        goto after_2;
    // 0x8057FA38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8057FA3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057FA40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8057FA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FA48: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8057FA4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8057FA50: jal         0x8057F7CC
    // 0x8057FA54: nop

    func_8057F7CC(rdram, ctx);
        goto after_3;
    // 0x8057FA54: nop

    after_3:
    // 0x8057FA58: jal         0x8057F810
    // 0x8057FA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F810(rdram, ctx);
        goto after_4;
    // 0x8057FA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8057FA60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057FA64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057FA68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057FA6C: jr          $ra
    // 0x8057FA70: nop

    return;
    // 0x8057FA70: nop

;}
RECOMP_FUNC void func_80004AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004AD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004ADC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004AE0: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80004AE4: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x80004AE8: lh          $t6, 0x1D7C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1D7C);
    // 0x80004AEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80004AF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004AF4: bne         $t6, $at, L_80004B08
    if (ctx->r14 != ctx->r1) {
        // 0x80004AF8: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80004B08;
    }
    // 0x80004AF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80004AFC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80004B00: b           L_80004B10
    // 0x80004B04: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80004B10;
    // 0x80004B04: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80004B08:
    // 0x80004B08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80004B0C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80004B10:
    // 0x80004B10: lbu         $t9, 0x2A22($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2A22);
    // 0x80004B14: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80004B18: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80004B1C: beq         $at, $zero, L_80004DA4
    if (ctx->r1 == 0) {
        // 0x80004B20: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80004DA4;
    }
    // 0x80004B20: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004B24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80004B28: addu        $at, $at, $t0
    gpr jr_addend_80004B30 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80004B2C: lw          $t0, -0x4414($at)
    ctx->r8 = ADD32(ctx->r1, -0X4414);
    // 0x80004B30: jr          $t0
    // 0x80004B34: nop

    switch (jr_addend_80004B30 >> 2) {
        case 0: goto L_80004D30; break;
        case 1: goto L_80004CFC; break;
        case 2: goto L_80004C94; break;
        case 3: goto L_80004BC0; break;
        case 4: goto L_80004B38; break;
        default: switch_error(__func__, 0x80004B30, 0x800ABBEC);
    }
    // 0x80004B34: nop

L_80004B38:
    // 0x80004B38: lh          $t1, 0x1D90($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X1D90);
    // 0x80004B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80004B40: blezl       $t1, L_80004B7C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80004B44: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80004B7C;
    }
    goto skip_0;
    // 0x80004B44: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80004B48: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80004B4C: addiu       $s0, $s0, 0x7740
    ctx->r16 = ADD32(ctx->r16, 0X7740);
    // 0x80004B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80004B54:
    // 0x80004B54: jal         0x8000DAE8
    // 0x80004B58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8000DAE8(rdram, ctx);
        goto after_0;
    // 0x80004B58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80004B5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80004B60: lh          $t2, 0x1D90($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1D90);
    // 0x80004B64: addiu       $s0, $s0, 0x160
    ctx->r16 = ADD32(ctx->r16, 0X160);
    // 0x80004B68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80004B6C: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80004B70: bnel        $at, $zero, L_80004B54
    if (ctx->r1 != 0) {
        // 0x80004B74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80004B54;
    }
    goto skip_1;
    // 0x80004B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80004B78: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80004B7C:
    // 0x80004B7C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80004B80: lbu         $v0, 0x2A22($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2A22);
    // 0x80004B84: div         $zero, $t4, $t3
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r11)));
    // 0x80004B88: mflo        $t5
    ctx->r13 = lo;
    // 0x80004B8C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80004B90: bne         $t3, $zero, L_80004B9C
    if (ctx->r11 != 0) {
        // 0x80004B94: nop
    
            goto L_80004B9C;
    }
    // 0x80004B94: nop

    // 0x80004B98: break       7
    do_break(2147503000);
L_80004B9C:
    // 0x80004B9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004BA0: bne         $t3, $at, L_80004BB4
    if (ctx->r11 != ctx->r1) {
        // 0x80004BA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004BB4;
    }
    // 0x80004BA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004BA8: bne         $t4, $at, L_80004BB4
    if (ctx->r12 != ctx->r1) {
        // 0x80004BAC: nop
    
            goto L_80004BB4;
    }
    // 0x80004BAC: nop

    // 0x80004BB0: break       6
    do_break(2147503024);
L_80004BB4:
    // 0x80004BB4: sw          $t5, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r13;
    // 0x80004BB8: b           L_80004DA4
    // 0x80004BBC: sb          $t6, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r14;
        goto L_80004DA4;
    // 0x80004BBC: sb          $t6, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r14;
L_80004BC0:
    // 0x80004BC0: lw          $v0, 0x2A24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2A24);
    // 0x80004BC4: beq         $v0, $zero, L_80004BDC
    if (ctx->r2 == 0) {
        // 0x80004BC8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80004BDC;
    }
    // 0x80004BC8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80004BCC: jal         0x800048A0
    // 0x80004BD0: sw          $t7, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r15;
    func_800048A0(rdram, ctx);
        goto after_1;
    // 0x80004BD0: sw          $t7, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r15;
    after_1:
    // 0x80004BD4: b           L_80004DA8
    // 0x80004BD8: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
        goto L_80004DA8;
    // 0x80004BD8: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
L_80004BDC:
    // 0x80004BDC: lw          $a0, 0x1DAC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1DAC);
    // 0x80004BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80004BE4: blezl       $a0, L_80004C50
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80004BE8: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80004C50;
    }
    goto skip_2;
    // 0x80004BE8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80004BEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80004BF0:
    // 0x80004BF0: lw          $t8, 0x2A2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2A2C);
    // 0x80004BF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80004BF8: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x80004BFC: lw          $t9, 0xB0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB0);
    // 0x80004C00: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80004C04: beql        $t0, $zero, L_80004C44
    if (ctx->r8 == 0) {
        // 0x80004C08: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80004C44;
    }
    goto skip_3;
    // 0x80004C08: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    skip_3:
    // 0x80004C0C: lbu         $t1, 0x60($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X60);
    // 0x80004C10: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80004C14: beql        $t2, $zero, L_80004C44
    if (ctx->r10 == 0) {
        // 0x80004C18: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80004C44;
    }
    goto skip_4;
    // 0x80004C18: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    skip_4:
    // 0x80004C1C: lwc1        $f4, 0x1D98($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1D98);
    // 0x80004C20: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x80004C24: lw          $t4, 0x2A2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2A2C);
    // 0x80004C28: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80004C2C: lbu         $t3, 0x60($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X60);
    // 0x80004C30: andi        $t5, $t3, 0xFFEF
    ctx->r13 = ctx->r11 & 0XFFEF;
    // 0x80004C34: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80004C38: sb          $t6, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r14;
    // 0x80004C3C: lw          $a0, 0x1DAC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1DAC);
    // 0x80004C40: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80004C44:
    // 0x80004C44: bne         $at, $zero, L_80004BF0
    if (ctx->r1 != 0) {
        // 0x80004C48: addiu       $v1, $v1, 0xD0
        ctx->r3 = ADD32(ctx->r3, 0XD0);
            goto L_80004BF0;
    }
    // 0x80004C48: addiu       $v1, $v1, 0xD0
    ctx->r3 = ADD32(ctx->r3, 0XD0);
    // 0x80004C4C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80004C50:
    // 0x80004C50: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80004C54: lbu         $v0, 0x2A22($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2A22);
    // 0x80004C58: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x80004C5C: mflo        $t9
    ctx->r25 = lo;
    // 0x80004C60: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80004C64: bne         $t7, $zero, L_80004C70
    if (ctx->r15 != 0) {
        // 0x80004C68: nop
    
            goto L_80004C70;
    }
    // 0x80004C68: nop

    // 0x80004C6C: break       7
    do_break(2147503212);
L_80004C70:
    // 0x80004C70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004C74: bne         $t7, $at, L_80004C88
    if (ctx->r15 != ctx->r1) {
        // 0x80004C78: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004C88;
    }
    // 0x80004C78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004C7C: bne         $t8, $at, L_80004C88
    if (ctx->r24 != ctx->r1) {
        // 0x80004C80: nop
    
            goto L_80004C88;
    }
    // 0x80004C80: nop

    // 0x80004C84: break       6
    do_break(2147503236);
L_80004C88:
    // 0x80004C88: sw          $t9, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r25;
    // 0x80004C8C: b           L_80004DA4
    // 0x80004C90: sb          $t0, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r8;
        goto L_80004DA4;
    // 0x80004C90: sb          $t0, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r8;
L_80004C94:
    // 0x80004C94: lw          $v0, 0x2A24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2A24);
    // 0x80004C98: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80004C9C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80004CA0: beq         $v0, $zero, L_80004CBC
    if (ctx->r2 == 0) {
        // 0x80004CA4: nop
    
            goto L_80004CBC;
    }
    // 0x80004CA4: nop

    // 0x80004CA8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80004CAC: jal         0x800048A0
    // 0x80004CB0: sw          $t1, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r9;
    func_800048A0(rdram, ctx);
        goto after_2;
    // 0x80004CB0: sw          $t1, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r9;
    after_2:
    // 0x80004CB4: b           L_80004DA8
    // 0x80004CB8: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
        goto L_80004DA8;
    // 0x80004CB8: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
L_80004CBC:
    // 0x80004CBC: div         $zero, $t4, $t2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r10)));
    // 0x80004CC0: lbu         $v0, 0x2A22($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2A22);
    // 0x80004CC4: mflo        $t3
    ctx->r11 = lo;
    // 0x80004CC8: sw          $t3, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r11;
    // 0x80004CCC: bne         $t2, $zero, L_80004CD8
    if (ctx->r10 != 0) {
        // 0x80004CD0: nop
    
            goto L_80004CD8;
    }
    // 0x80004CD0: nop

    // 0x80004CD4: break       7
    do_break(2147503316);
L_80004CD8:
    // 0x80004CD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004CDC: bne         $t2, $at, L_80004CF0
    if (ctx->r10 != ctx->r1) {
        // 0x80004CE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004CF0;
    }
    // 0x80004CE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004CE4: bne         $t4, $at, L_80004CF0
    if (ctx->r12 != ctx->r1) {
        // 0x80004CE8: nop
    
            goto L_80004CF0;
    }
    // 0x80004CE8: nop

    // 0x80004CEC: break       6
    do_break(2147503340);
L_80004CF0:
    // 0x80004CF0: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80004CF4: b           L_80004DA4
    // 0x80004CF8: sb          $t5, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r13;
        goto L_80004DA4;
    // 0x80004CF8: sb          $t5, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r13;
L_80004CFC:
    // 0x80004CFC: jal         0x80004A6C
    // 0x80004D00: nop

    func_80004A6C(rdram, ctx);
        goto after_3;
    // 0x80004D00: nop

    after_3:
    // 0x80004D04: lw          $v0, 0x2A24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2A24);
    // 0x80004D08: beq         $v0, $zero, L_80004D18
    if (ctx->r2 == 0) {
        // 0x80004D0C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80004D18;
    }
    // 0x80004D0C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80004D10: b           L_80004DA4
    // 0x80004D14: sw          $t6, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r14;
        goto L_80004DA4;
    // 0x80004D14: sw          $t6, 0x2A24($s1)
    MEM_W(0X2A24, ctx->r17) = ctx->r14;
L_80004D18:
    // 0x80004D18: lbu         $v0, 0x2A22($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2A22);
    // 0x80004D1C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80004D20: jal         0x80005D78
    // 0x80004D24: sb          $t8, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r24;
    func_80005D78(rdram, ctx);
        goto after_4;
    // 0x80004D24: sb          $t8, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = ctx->r24;
    after_4:
    // 0x80004D28: b           L_80004DA8
    // 0x80004D2C: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
        goto L_80004DA8;
    // 0x80004D2C: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
L_80004D30:
    // 0x80004D30: jal         0x80004DD4
    // 0x80004D34: nop

    func_80004DD4(rdram, ctx);
        goto after_5;
    // 0x80004D34: nop

    after_5:
    // 0x80004D38: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80004D3C: addiu       $v1, $t7, 0x4D10
    ctx->r3 = ADD32(ctx->r15, 0X4D10);
    // 0x80004D40: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80004D44: sb          $zero, 0x2A22($s1)
    MEM_B(0X2A22, ctx->r17) = 0;
    // 0x80004D48: addiu       $a3, $a3, 0x4D1C
    ctx->r7 = ADD32(ctx->r7, 0X4D1C);
    // 0x80004D4C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80004D50: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
L_80004D54:
    // 0x80004D54: lh          $t9, 0x1D84($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1D84);
    // 0x80004D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004D5C: sh          $t9, 0x1E8C($a2)
    MEM_H(0X1E8C, ctx->r6) = ctx->r25;
L_80004D60:
    // 0x80004D60: lw          $t0, 0x1E80($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1E80);
    // 0x80004D64: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80004D68: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80004D6C: lw          $t4, 0x1E80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1E80);
    // 0x80004D70: addu        $t2, $t4, $v0
    ctx->r10 = ADD32(ctx->r12, ctx->r2);
    // 0x80004D74: sh          $zero, 0x2($t2)
    MEM_H(0X2, ctx->r10) = 0;
    // 0x80004D78: lw          $t3, 0x1E80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1E80);
    // 0x80004D7C: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x80004D80: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80004D84: lw          $t6, 0x1E80($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1E80);
    // 0x80004D88: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80004D8C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80004D90: bne         $v0, $a0, L_80004D60
    if (ctx->r2 != ctx->r4) {
        // 0x80004D94: sh          $zero, 0x6($t8)
        MEM_H(0X6, ctx->r24) = 0;
            goto L_80004D60;
    }
    // 0x80004D94: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x80004D98: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004D9C: bne         $v1, $a3, L_80004D54
    if (ctx->r3 != ctx->r7) {
        // 0x80004DA0: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80004D54;
    }
    // 0x80004DA0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_80004DA4:
    // 0x80004DA4: lbu         $t7, 0x2A22($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X2A22);
L_80004DA8:
    // 0x80004DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004DB0: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80004DB4: beq         $at, $zero, L_80004DC4
    if (ctx->r1 == 0) {
        // 0x80004DB8: nop
    
            goto L_80004DC4;
    }
    // 0x80004DB8: nop

    // 0x80004DBC: b           L_80004DC4
    // 0x80004DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004DC4;
    // 0x80004DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004DC4:
    // 0x80004DC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80004DC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004DCC: jr          $ra
    // 0x80004DD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80004DD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80454D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454D74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80454D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454D80: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13908) << 16);
    // 0x80454D84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454D88: jal         0x804548E4
    // 0x80454D8C: lw          $a1, 0x7CE8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13908));
    func_804548E4(rdram, ctx);
        goto after_0;
    // 0x80454D8C: lw          $a1, 0x7CE8($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13908));
    after_0:
    // 0x80454D90: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80454D94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454D98: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80454D9C: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x80454DA0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454DA4: ori         $at, $at, 0x6D64
    ctx->r1 = ctx->r1 | 0X6D64;
    // 0x80454DA8: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x80454DAC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454DB0: ori         $at, $at, 0x6D68
    ctx->r1 = ctx->r1 | 0X6D68;
    // 0x80454DB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80454DB8: addu        $a2, $v1, $at
    ctx->r6 = ADD32(ctx->r3, ctx->r1);
    // 0x80454DBC: jal         0x804549D4
    // 0x80454DC0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804549D4(rdram, ctx);
        goto after_1;
    // 0x80454DC0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80454DC4: beq         $v0, $zero, L_80454DEC
    if (ctx->r2 == 0) {
        // 0x80454DC8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80454DEC;
    }
    // 0x80454DC8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80454DCC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454DD0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80454DD4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80454DD8: sw          $t6, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r14;
    // 0x80454DDC: jal         0x804457C0
    // 0x80454DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804457C0(rdram, ctx);
        goto after_2;
    // 0x80454DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80454DE4: jal         0x80453564
    // 0x80454DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80453564(rdram, ctx);
        goto after_3;
    // 0x80454DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80454DEC:
    // 0x80454DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80454DF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80454DF8: jr          $ra
    // 0x80454DFC: nop

    return;
    // 0x80454DFC: nop

;}
RECOMP_FUNC void func_80050DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050E00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050E04: jal         0x80050CF0
    // 0x80050E08: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80050CF0(rdram, ctx);
        goto after_0;
    // 0x80050E08: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80050E0C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80050E10: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050E14: bne         $v0, $zero, L_80050E28
    if (ctx->r2 != 0) {
        // 0x80050E18: sw          $v0, 0x34($t7)
        MEM_W(0X34, ctx->r15) = ctx->r2;
            goto L_80050E28;
    }
    // 0x80050E18: sw          $v0, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r2;
    // 0x80050E1C: addiu       $a0, $a0, 0xA20
    ctx->r4 = ADD32(ctx->r4, 0XA20);
    // 0x80050E20: jal         0x80071380
    // 0x80050E24: addiu       $a1, $zero, 0x2A1
    ctx->r5 = ADD32(0, 0X2A1);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80050E24: addiu       $a1, $zero, 0x2A1
    ctx->r5 = ADD32(0, 0X2A1);
    after_1:
L_80050E28:
    // 0x80050E28: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80050E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050E30: lw          $v0, 0x34($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X34);
    // 0x80050E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050E38: jr          $ra
    // 0x80050E3C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x80050E3C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_80436188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436188: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043618C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80436190: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80436194: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x80436198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043619C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804361A0: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x804361A4: jal         0x80051194
    // 0x804361A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804361A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x804361AC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804361B0: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804361B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804361B8: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x804361BC: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x804361C0: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x804361C4: jal         0x80436148
    // 0x804361C8: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    func_80436148(rdram, ctx);
        goto after_1;
    // 0x804361C8: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x804361CC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x804361D0: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(71, 0X2A7C) << 16);
    // 0x804361D4: addiu       $t7, $t7, 0x652C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(71, 0X2A7C));
    // 0x804361D8: bne         $t6, $zero, L_804361F0
    if (ctx->r14 != 0) {
        // 0x804361DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804361F0;
    }
    // 0x804361DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804361E0: jal         0x800445A4
    // 0x804361E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x804361E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804361E8: b           L_80436224
    // 0x804361EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80436224;
    // 0x804361EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804361F0:
    // 0x804361F0: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804361F4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804361F8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804361FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80436200: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80436204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80436208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043620C: jal         0x80436234
    // 0x80436210: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80436234(rdram, ctx);
        goto after_3;
    // 0x80436210: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80436214: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80436218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043621C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80436220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80436224:
    // 0x80436224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80436228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043622C: jr          $ra
    // 0x80436230: nop

    return;
    // 0x80436230: nop

;}
RECOMP_FUNC void func_80048C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048C6C: lw          $v0, 0x1D8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1D8);
    // 0x80048C70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80048C74: beql        $v0, $zero, L_80048C98
    if (ctx->r2 == 0) {
        // 0x80048C78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80048C98;
    }
    goto skip_0;
    // 0x80048C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80048C7C: lw          $t7, 0x1DC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1DC);
    // 0x80048C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80048C84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80048C88: lw          $a2, 0x88($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X88);
    // 0x80048C8C: jal         0x80048C18
    // 0x80048C90: lw          $a1, 0x84($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X84);
    func_80048C18(rdram, ctx);
        goto after_0;
    // 0x80048C90: lw          $a1, 0x84($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X84);
    after_0:
    // 0x80048C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C98:
    // 0x80048C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048C9C: jr          $ra
    // 0x80048CA0: nop

    return;
    // 0x80048CA0: nop

;}
RECOMP_FUNC void func_804F4BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4BE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804F4BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F4BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F4BF0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x804F4BF4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804F4BF8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804F4BFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804F4C00: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x804F4C04: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x804F4C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804F4C0C: jal         0x8004921C
    // 0x804F4C10: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804F4C10: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    after_0:
    // 0x804F4C14: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x804F4C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F4C1C: jal         0x8004921C
    // 0x804F4C20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804F4C20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804F4C24: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x804F4C28: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804F4C2C: lbu         $t2, 0x145($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X145);
    // 0x804F4C30: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804F4C34: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x804F4C38: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x804F4C3C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x804F4C40: lw          $t4, 0x80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X80);
    // 0x804F4C44: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x804F4C48: mflo        $t1
    ctx->r9 = lo;
    // 0x804F4C4C: nop

    // 0x804F4C50: nop

    // 0x804F4C54: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804F4C58: mflo        $t3
    ctx->r11 = lo;
    // 0x804F4C5C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x804F4C60: jal         0x80062E30
    // 0x804F4C64: nop

    func_80062E30(rdram, ctx);
        goto after_2;
    // 0x804F4C64: nop

    after_2:
    // 0x804F4C68: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x804F4C6C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x804F4C70: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x804F4C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804F4C78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F4C7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804F4C80: jr          $ra
    // 0x804F4C84: nop

    return;
    // 0x804F4C84: nop

;}
RECOMP_FUNC void func_807705FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807705FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80770600: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80770604: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80770608: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8077060C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80770610: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80770614: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80770618: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8077061C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80770620: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80770624: jr          $ra
    // 0x80770628: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80770628: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8077062C: nop

;}
RECOMP_FUNC void func_8001D78C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D78C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001D790: sltiu       $t6, $a1, 0x1
    ctx->r14 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8001D794: addiu       $v1, $v1, -0x68E0
    ctx->r3 = ADD32(ctx->r3, -0X68E0);
    // 0x8001D798: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D79C: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x8001D7A0: sw          $a1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r5;
    // 0x8001D7A4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8001D7A8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8001D7AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001D7B0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8001D7B4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001D7B8: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8001D7BC: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
    // 0x8001D7C0: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001D7C4: jr          $ra
    // 0x8001D7C8: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8001D7C8: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_807BA970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BA974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BA978: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807BA97C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x807BA980: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(895, 0X11D8) << 16);
    // 0x807BA984: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807BA988: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807BA98C: lw          $t8, -0x4618($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(895, 0X11D8));
    // 0x807BA990: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x807BA994: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x807BA998: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x807BA99C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x807BA9A0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x807BA9A4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x807BA9A8: beql        $v1, $zero, L_807BA9DC
    if (ctx->r3 == 0) {
        // 0x807BA9AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807BA9DC;
    }
    goto skip_0;
    // 0x807BA9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807BA9B0: jalr        $v1
    // 0x807BA9B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x807BA9B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BA9B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BA9BC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x807BA9C0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x807BA9C4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x807BA9C8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x807BA9CC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x807BA9D0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x807BA9D4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x807BA9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BA9DC:
    // 0x807BA9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BA9E0: jr          $ra
    // 0x807BA9E4: nop

    return;
    // 0x807BA9E4: nop

;}
RECOMP_FUNC void func_80799560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079956C: jal         0x80045A34
    // 0x80799570: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80799570: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80799574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80799578: bne         $v0, $zero, L_80799588
    if (ctx->r2 != 0) {
        // 0x8079957C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80799588;
    }
    // 0x8079957C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80799580: b           L_80799594
    // 0x80799584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80799594;
    // 0x80799584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80799588:
    // 0x80799588: jal         0x80799554
    // 0x8079958C: nop

    func_80799554(rdram, ctx);
        goto after_1;
    // 0x8079958C: nop

    after_1:
    // 0x80799590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80799594:
    // 0x80799594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079959C: jr          $ra
    // 0x807995A0: nop

    return;
    // 0x807995A0: nop

;}
RECOMP_FUNC void func_8005EBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBE8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBEC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8005EBF0: jr          $ra
    // 0x8005EBF4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
    return;
    // 0x8005EBF4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_8004FE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FE44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004FE48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004FE4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004FE50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004FE54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004FE58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004FE5C: jal         0x8004F970
    // 0x8004FE60: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    func_8004F970(rdram, ctx);
        goto after_0;
    // 0x8004FE60: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    after_0:
    // 0x8004FE64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FE68: jal         0x8004FC28
    // 0x8004FE6C: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    func_8004FC28(rdram, ctx);
        goto after_1;
    // 0x8004FE6C: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    after_1:
    // 0x8004FE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FE74: jal         0x8004FD78
    // 0x8004FE78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8004FD78(rdram, ctx);
        goto after_2;
    // 0x8004FE78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8004FE7C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8004FE80: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004FE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FE88: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004FE8C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8004FE90: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004FE94: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8004FE98: jal         0x8004F26C
    // 0x8004FE9C: sb          $t6, 0x38($t9)
    MEM_B(0X38, ctx->r25) = ctx->r14;
    func_8004F26C(rdram, ctx);
        goto after_3;
    // 0x8004FE9C: sb          $t6, 0x38($t9)
    MEM_B(0X38, ctx->r25) = ctx->r14;
    after_3:
    // 0x8004FEA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FEA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004FEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004FEAC: jr          $ra
    // 0x8004FEB0: nop

    return;
    // 0x8004FEB0: nop

;}
RECOMP_FUNC void func_805AE0E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE0E4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE0E8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE0EC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE0F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE0F4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE0F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE0FC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE100: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE104: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE108: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE10C: jr          $ra
    // 0x805AE110: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE110: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
