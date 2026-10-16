#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804C4DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C4DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C4DAC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804C4DB0: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(209, 0XE40) << 16);
    // 0x804C4DB4: addiu       $t8, $t8, 0x4E30
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(209, 0XE40));
    // 0x804C4DB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C4DBC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804C4DC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C4DC4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804C4DC8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C4DCC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C4DD0: beql        $v1, $zero, L_804C4E08
    if (ctx->r3 == 0) {
        // 0x804C4DD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C4E08;
    }
    goto skip_0;
    // 0x804C4DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C4DD8: jalr        $v1
    // 0x804C4DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C4DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C4DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C4DE4: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804C4DE8: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804C4DEC: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804C4DF0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804C4DF4: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804C4DF8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804C4DFC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804C4E00: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804C4E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C4E08:
    // 0x804C4E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C4E0C: jr          $ra
    // 0x804C4E10: nop

    return;
    // 0x804C4E10: nop

    // 0x804C4E14: nop

    // 0x804C4E18: nop

    // 0x804C4E1C: nop

;}
RECOMP_FUNC void func_800461F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800461F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800461F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800461FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046200: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x80046204: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80046208: lw          $v0, 0x168($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X168);
    // 0x8004620C: bne         $t6, $zero, L_8004623C
    if (ctx->r14 != 0) {
        // 0x80046210: nop
    
            goto L_8004623C;
    }
    // 0x80046210: nop

    // 0x80046214: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x80046218: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8004621C: bne         $t7, $at, L_8004623C
    if (ctx->r15 != ctx->r1) {
        // 0x80046220: nop
    
            goto L_8004623C;
    }
    // 0x80046220: nop

    // 0x80046224: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046228: addiu       $a0, $a0, 0x700
    ctx->r4 = ADD32(ctx->r4, 0X700);
    // 0x8004622C: jal         0x80071380
    // 0x80046230: addiu       $a1, $zero, 0x403
    ctx->r5 = ADD32(0, 0X403);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80046230: addiu       $a1, $zero, 0x403
    ctx->r5 = ADD32(0, 0X403);
    after_0:
    // 0x80046234: b           L_8004624C
    // 0x80046238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004624C;
    // 0x80046238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004623C:
    // 0x8004623C: beq         $v0, $zero, L_80046248
    if (ctx->r2 == 0) {
        // 0x80046240: sb          $a1, 0x4($a0)
        MEM_B(0X4, ctx->r4) = ctx->r5;
            goto L_80046248;
    }
    // 0x80046240: sb          $a1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r5;
    // 0x80046244: sb          $a1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r5;
L_80046248:
    // 0x80046248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004624C:
    // 0x8004624C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046254: jr          $ra
    // 0x80046258: nop

    return;
    // 0x80046258: nop

;}
RECOMP_FUNC void func_807AA878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AA878: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807AA87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AA880: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x807AA884: lwc1        $f4, 0x7C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x807AA888: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807AA88C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x807AA890: lwc1        $f6, 0x80($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X80);
    // 0x807AA894: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807AA898: jal         0x80066DE4
    // 0x807AA89C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x807AA89C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x807AA8A0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807AA8A4: jal         0x80066E88
    // 0x807AA8A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807AA8A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807AA8AC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x807AA8B0: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807AA8B4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807AA8B8: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x807AA8BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807AA8C0: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x807AA8C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x807AA8C8: mul.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x807AA8CC: nop

    // 0x807AA8D0: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x807AA8D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807AA8D8: swc1        $f16, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f16.u32l;
    // 0x807AA8DC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807AA8E0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x807AA8E4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x807AA8E8: swc1        $f8, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f8.u32l;
    // 0x807AA8EC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x807AA8F0: lwc1        $f10, 0xD0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XD0);
    // 0x807AA8F4: swc1        $f10, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f10.u32l;
    // 0x807AA8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AA8FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807AA900: jr          $ra
    // 0x807AA904: nop

    return;
    // 0x807AA904: nop

;}
RECOMP_FUNC void func_80437FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437FF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80437FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437FFC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80438000: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80438008: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8043800C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80438010: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80438014: jal         0x8004A97C
    // 0x80438018: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8004A97C(rdram, ctx);
        goto after_0;
    // 0x80438018: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043801C: jal         0x80066E88
    // 0x80438020: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80438020: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80438024: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80438028: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8043802C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80438030: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80438034: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80438038: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8043803C: nop

    // 0x80438040: bc1fl       L_80438068
    if (!c1cs) {
        // 0x80438044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80438068;
    }
    goto skip_0;
    // 0x80438044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80438048: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8043804C: nop

    // 0x80438050: bc1fl       L_80438068
    if (!c1cs) {
        // 0x80438054: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80438068;
    }
    goto skip_1;
    // 0x80438054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80438058: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8043805C: nop

    // 0x80438060: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80438064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80438068:
    // 0x80438068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043806C: jr          $ra
    // 0x80438070: nop

    return;
    // 0x80438070: nop

;}
RECOMP_FUNC void func_8064E014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064E018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064E01C: jal         0x800692D4
    // 0x8064E020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x8064E020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064E024: beq         $v0, $zero, L_8064E068
    if (ctx->r2 == 0) {
        // 0x8064E028: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064E068;
    }
    // 0x8064E028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064E02C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064E030: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8064E034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064E038: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(498, 0XBE0) << 16);
    // 0x8064E03C: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8064E040: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x8064E044: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8064E048: lwc1        $f6, -0x1750($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(498, 0XBE0));
    // 0x8064E04C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064E050: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064E054: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064E058: jal         0x8064E7C0
    // 0x8064E05C: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    func_8064E7C0(rdram, ctx);
        goto after_1;
    // 0x8064E05C: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x8064E060: b           L_8064E06C
    // 0x8064E064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8064E06C;
    // 0x8064E064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064E068:
    // 0x8064E068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064E06C:
    // 0x8064E06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064E070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064E074: jr          $ra
    // 0x8064E078: nop

    return;
    // 0x8064E078: nop

;}
RECOMP_FUNC void func_805ABFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABFC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805ABFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ABFC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805ABFCC: jal         0x80045A34
    // 0x805ABFD0: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805ABFD0: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    after_0:
    // 0x805ABFD4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805ABFD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805ABFDC: bne         $v0, $zero, L_805ABFF4
    if (ctx->r2 != 0) {
        // 0x805ABFE0: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_805ABFF4;
    }
    // 0x805ABFE0: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x805ABFE4: jal         0x800445A4
    // 0x805ABFE8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805ABFE8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x805ABFEC: b           L_805AC018
    // 0x805ABFF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805AC018;
    // 0x805ABFF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805ABFF4:
    // 0x805ABFF4: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    // 0x805ABFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805ABFFC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x805AC000: jal         0x80065728
    // 0x805AC004: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x805AC004: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x805AC008: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AC00C: jal         0x8005D730
    // 0x805AC010: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x805AC010: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x805AC014: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805AC018:
    // 0x805AC018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC01C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AC020: jr          $ra
    // 0x805AC024: nop

    return;
    // 0x805AC024: nop

;}
RECOMP_FUNC void func_806CB8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CB8F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806CB8F8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x806CB8FC: lui         $t0, 0x806D
    ctx->r8 = S32(RELOC_HI16(604, 0X3A3C) << 16);
    // 0x806CB900: addiu       $t0, $t0, -0xEA4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(604, 0X3A3C));
    // 0x806CB904: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x806CB908: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x806CB90C: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x806CB910: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806CB914: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x806CB918: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x806CB91C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806CB920: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x806CB924: addu        $t2, $v1, $a3
    ctx->r10 = ADD32(ctx->r3, ctx->r7);
    // 0x806CB928: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x806CB92C: lb          $t3, 0x0($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X0);
    // 0x806CB930: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x806CB934: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x806CB938: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x806CB93C: addu        $t4, $v0, $a3
    ctx->r12 = ADD32(ctx->r2, ctx->r7);
    // 0x806CB940: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x806CB944: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x806CB948: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x806CB94C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CB950: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x806CB954: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806CB958: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806CB95C: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(604, 0X3A74) << 16);
    // 0x806CB960: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CB964: addiu       $t1, $t1, -0xE6C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(604, 0X3A74));
    // 0x806CB968: addu        $t8, $t1, $a0
    ctx->r24 = ADD32(ctx->r9, ctx->r4);
    // 0x806CB96C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x806CB970: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x806CB974: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CB978: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806CB97C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C00) << 16);
    // 0x806CB980: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806CB984: mul.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x806CB988: beql        $t9, $zero, L_806CB998
    if (ctx->r25 == 0) {
        // 0x806CB98C: lbu         $t3, 0x0($t2)
        ctx->r11 = MEM_BU(ctx->r10, 0X0);
            goto L_806CB998;
    }
    goto skip_0;
    // 0x806CB98C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    skip_0:
    // 0x806CB990: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x806CB994: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
L_806CB998:
    // 0x806CB998: beql        $t3, $zero, L_806CB9A8
    if (ctx->r11 == 0) {
        // 0x806CB99C: add.s       $f6, $f12, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
            goto L_806CB9A8;
    }
    goto skip_1;
    // 0x806CB99C: add.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
    skip_1:
    // 0x806CB9A0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x806CB9A4: add.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
L_806CB9A8:
    // 0x806CB9A8: lwc1        $f10, -0xCE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C00));
    // 0x806CB9AC: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806CB9B0: jr          $ra
    // 0x806CB9B4: nop

    return;
    // 0x806CB9B4: nop

;}
RECOMP_FUNC void func_80058EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058EEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058EF4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80058EF8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80058EFC: jal         0x80058E08
    // 0x80058F00: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80058E08(rdram, ctx);
        goto after_0;
    // 0x80058F00: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80058F04: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80058F08: jal         0x80081C64
    // 0x80058F0C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80058F0C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80058F10: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80058F14: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80058F18: lw          $v0, 0x3F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3F4);
    // 0x80058F1C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058F20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058F24: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80058F28: lw          $t6, 0x478($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X478);
    // 0x80058F2C: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058F30: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80058F34: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80058F38: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058F3C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80058F40: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80058F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058F48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058F4C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80058F50: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80058F54: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80058F58: div.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80058F5C: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80058F60: jr          $ra
    // 0x80058F64: nop

    return;
    // 0x80058F64: nop

;}
RECOMP_FUNC void func_80439F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439F08: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80439F0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80439F10: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80439F14: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80439F18: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80439F1C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80439F20: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80439F24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80439F28: lwc1        $f22, 0x3C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80439F2C: lwc1        $f24, 0x40($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80439F30: addiu       $s1, $zero, 0x11
    ctx->r17 = ADD32(0, 0X11);
    // 0x80439F34: addiu       $s0, $v0, 0xA1C
    ctx->r16 = ADD32(ctx->r2, 0XA1C);
    // 0x80439F38: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
L_80439F3C:
    // 0x80439F3C: jal         0x800653D8
    // 0x80439F40: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80439F40: nop

    after_0:
    // 0x80439F44: addiu       $at, $zero, 0x180
    ctx->r1 = ADD32(0, 0X180);
    // 0x80439F48: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80439F4C: mfhi        $t6
    ctx->r14 = hi;
    // 0x80439F50: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80439F54: jal         0x800653D8
    // 0x80439F58: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80439F58: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x80439F5C: addiu       $at, $zero, 0x130
    ctx->r1 = ADD32(0, 0X130);
    // 0x80439F60: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80439F64: mfhi        $t7
    ctx->r15 = hi;
    // 0x80439F68: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80439F6C: lui         $at, 0x43B0
    ctx->r1 = S32(0X43B0 << 16);
    // 0x80439F70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80439F74: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80439F78: lui         $at, 0x43C0
    ctx->r1 = S32(0X43C0 << 16);
    // 0x80439F7C: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80439F80: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80439F84: bc1fl       L_80439F9C
    if (!c1cs) {
        // 0x80439F88: lui         $at, 0x4388
        ctx->r1 = S32(0X4388 << 16);
            goto L_80439F9C;
    }
    goto skip_0;
    // 0x80439F88: lui         $at, 0x4388
    ctx->r1 = S32(0X4388 << 16);
    skip_0:
    // 0x80439F8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80439F90: nop

    // 0x80439F94: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x80439F98: lui         $at, 0x4388
    ctx->r1 = S32(0X4388 << 16);
L_80439F9C:
    // 0x80439F9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80439FA0: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x80439FA4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80439FA8: nop

    // 0x80439FAC: bc1fl       L_80439FC4
    if (!c1cs) {
        // 0x80439FB0: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80439FC4;
    }
    goto skip_1;
    // 0x80439FB0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_1:
    // 0x80439FB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80439FB8: nop

    // 0x80439FBC: sub.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80439FC0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80439FC4:
    // 0x80439FC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80439FC8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80439FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80439FD0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x80439FD4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80439FD8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80439FDC: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80439FE0: add.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x80439FE4: add.s       $f10, $f24, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x80439FE8: swc1        $f8, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80439FEC: bgez        $s1, L_80439F3C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80439FF0: swc1        $f10, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
            goto L_80439F3C;
    }
    // 0x80439FF0: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80439FF4: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80439FF8: addiu       $v0, $sp, 0x60
    ctx->r2 = ADD32(ctx->r29, 0X60);
    // 0x80439FFC: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x8043A000: sw          $zero, 0xAAC($t8)
    MEM_W(0XAAC, ctx->r24) = 0;
    // 0x8043A004: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8043A008: addiu       $v1, $a3, 0xAB0
    ctx->r3 = ADD32(ctx->r7, 0XAB0);
    // 0x8043A00C: addiu       $a0, $a3, 0xAFC
    ctx->r4 = ADD32(ctx->r7, 0XAFC);
    // 0x8043A010: addiu       $a1, $a3, 0xB48
    ctx->r5 = ADD32(ctx->r7, 0XB48);
    // 0x8043A014: addiu       $a2, $a3, 0xB94
    ctx->r6 = ADD32(ctx->r7, 0XB94);
    // 0x8043A018: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
L_8043A01C:
    // 0x8043A01C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8043A020: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x8043A024: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x8043A028: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8043A02C: sw          $v1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r3;
    // 0x8043A030: addiu       $v1, $v1, 0x130
    ctx->r3 = ADD32(ctx->r3, 0X130);
    // 0x8043A034: addiu       $a2, $a2, 0x130
    ctx->r6 = ADD32(ctx->r6, 0X130);
    // 0x8043A038: addiu       $a1, $a1, 0x130
    ctx->r5 = ADD32(ctx->r5, 0X130);
    // 0x8043A03C: bne         $v0, $a3, L_8043A01C
    if (ctx->r2 != ctx->r7) {
        // 0x8043A040: addiu       $a0, $a0, 0x130
        ctx->r4 = ADD32(ctx->r4, 0X130);
            goto L_8043A01C;
    }
    // 0x8043A040: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8043A044: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
L_8043A048:
    // 0x8043A048: jal         0x800653D8
    // 0x8043A04C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8043A04C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    after_2:
    // 0x8043A050: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8043A054: bgez        $v0, L_8043A068
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8043A058: andi        $t9, $v0, 0x7
        ctx->r25 = ctx->r2 & 0X7;
            goto L_8043A068;
    }
    // 0x8043A058: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x8043A05C: beq         $t9, $zero, L_8043A068
    if (ctx->r25 == 0) {
        // 0x8043A060: nop
    
            goto L_8043A068;
    }
    // 0x8043A060: nop

    // 0x8043A064: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_8043A068:
    // 0x8043A068: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043A06C: addu        $v1, $s0, $t0
    ctx->r3 = ADD32(ctx->r16, ctx->r8);
    // 0x8043A070: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8043A074: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x8043A078: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8043A07C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8043A080: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8043A084: bgez        $a0, L_8043A048
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8043A088: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_8043A048;
    }
    // 0x8043A088: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8043A08C: addiu       $v0, $sp, 0x60
    ctx->r2 = ADD32(ctx->r29, 0X60);
    // 0x8043A090: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x8043A094: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8043A098:
    // 0x8043A098: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8043A09C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8043A0A0: sw          $v1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r3;
    // 0x8043A0A4: lw          $t5, -0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, -0XC);
    // 0x8043A0A8: sw          $v1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r3;
    // 0x8043A0AC: lw          $t6, -0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X8);
    // 0x8043A0B0: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8043A0B4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8043A0B8: bne         $v0, $a0, L_8043A098
    if (ctx->r2 != ctx->r4) {
        // 0x8043A0BC: sw          $v1, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r3;
            goto L_8043A098;
    }
    // 0x8043A0BC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8043A0C0: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8043A0C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8043A0C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8043A0CC: sw          $v1, 0xD10($t8)
    MEM_W(0XD10, ctx->r24) = ctx->r3;
    // 0x8043A0D0: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x8043A0D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8043A0D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8043A0DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8043A0E0:
    // 0x8043A0E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8043A0E4: sw          $v1, 0xD14($v0)
    MEM_W(0XD14, ctx->r2) = ctx->r3;
    // 0x8043A0E8: sw          $v1, 0xD18($v0)
    MEM_W(0XD18, ctx->r2) = ctx->r3;
    // 0x8043A0EC: sw          $v1, 0xD1C($v0)
    MEM_W(0XD1C, ctx->r2) = ctx->r3;
    // 0x8043A0F0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8043A0F4: bne         $a0, $a1, L_8043A0E0
    if (ctx->r4 != ctx->r5) {
        // 0x8043A0F8: sw          $v1, 0xD00($v0)
        MEM_W(0XD00, ctx->r2) = ctx->r3;
            goto L_8043A0E0;
    }
    // 0x8043A0F8: sw          $v1, 0xD00($v0)
    MEM_W(0XD00, ctx->r2) = ctx->r3;
    // 0x8043A0FC: slti        $at, $a0, 0xF
    ctx->r1 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x8043A100: beq         $at, $zero, L_8043A11C
    if (ctx->r1 == 0) {
        // 0x8043A104: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8043A11C;
    }
    // 0x8043A104: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8043A108:
    // 0x8043A108: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8043A10C: slti        $at, $a0, 0xF
    ctx->r1 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x8043A110: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8043A114: bne         $at, $zero, L_8043A108
    if (ctx->r1 != 0) {
        // 0x8043A118: sw          $v1, 0xD0C($v0)
        MEM_W(0XD0C, ctx->r2) = ctx->r3;
            goto L_8043A108;
    }
    // 0x8043A118: sw          $v1, 0xD0C($v0)
    MEM_W(0XD0C, ctx->r2) = ctx->r3;
L_8043A11C:
    // 0x8043A11C: slti        $at, $a0, 0x12
    ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x8043A120: beq         $at, $zero, L_8043A13C
    if (ctx->r1 == 0) {
        // 0x8043A124: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_8043A13C;
    }
    // 0x8043A124: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8043A128:
    // 0x8043A128: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8043A12C: slti        $at, $a0, 0x12
    ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x8043A130: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8043A134: bne         $at, $zero, L_8043A128
    if (ctx->r1 != 0) {
        // 0x8043A138: sw          $zero, 0xD0C($v0)
        MEM_W(0XD0C, ctx->r2) = 0;
            goto L_8043A128;
    }
    // 0x8043A138: sw          $zero, 0xD0C($v0)
    MEM_W(0XD0C, ctx->r2) = 0;
L_8043A13C:
    // 0x8043A13C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043A140: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
L_8043A144:
    // 0x8043A144: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8043A148: slti        $at, $s1, 0x12
    ctx->r1 = SIGNED(ctx->r17) < 0X12 ? 1 : 0;
    // 0x8043A14C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8043A150: swc1        $f0, 0x96C($v0)
    MEM_W(0X96C, ctx->r2) = ctx->f0.u32l;
    // 0x8043A154: bne         $at, $zero, L_8043A144
    if (ctx->r1 != 0) {
        // 0x8043A158: swc1        $f0, 0x970($v0)
        MEM_W(0X970, ctx->r2) = ctx->f0.u32l;
            goto L_8043A144;
    }
    // 0x8043A158: swc1        $f0, 0x970($v0)
    MEM_W(0X970, ctx->r2) = ctx->f0.u32l;
    // 0x8043A15C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8043A160: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
L_8043A164:
    // 0x8043A164: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8043A168: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8043A16C: swc1        $f0, 0x9FC($v0)
    MEM_W(0X9FC, ctx->r2) = ctx->f0.u32l;
    // 0x8043A170: bne         $s1, $v1, L_8043A164
    if (ctx->r17 != ctx->r3) {
        // 0x8043A174: swc1        $f0, 0xA00($v0)
        MEM_W(0XA00, ctx->r2) = ctx->f0.u32l;
            goto L_8043A164;
    }
    // 0x8043A174: swc1        $f0, 0xA00($v0)
    MEM_W(0XA00, ctx->r2) = ctx->f0.u32l;
    // 0x8043A178: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8043A17C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8043A180: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8043A184: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8043A188: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8043A18C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8043A190: jr          $ra
    // 0x8043A194: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8043A194: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_807A0F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0F40: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807A0F44: addiu       $at, $zero, 0x403B
    ctx->r1 = ADD32(0, 0X403B);
    // 0x807A0F48: beq         $v0, $at, L_807A0F5C
    if (ctx->r2 == ctx->r1) {
        // 0x807A0F4C: addiu       $at, $zero, 0x403C
        ctx->r1 = ADD32(0, 0X403C);
            goto L_807A0F5C;
    }
    // 0x807A0F4C: addiu       $at, $zero, 0x403C
    ctx->r1 = ADD32(0, 0X403C);
    // 0x807A0F50: beq         $v0, $at, L_807A0F5C
    if (ctx->r2 == ctx->r1) {
        // 0x807A0F54: addiu       $at, $zero, 0x403D
        ctx->r1 = ADD32(0, 0X403D);
            goto L_807A0F5C;
    }
    // 0x807A0F54: addiu       $at, $zero, 0x403D
    ctx->r1 = ADD32(0, 0X403D);
    // 0x807A0F58: bne         $v0, $at, L_807A0F68
    if (ctx->r2 != ctx->r1) {
        // 0x807A0F5C: lui         $v0, 0x807A
        ctx->r2 = S32(RELOC_HI16(841, 0XB70) << 16);
            goto L_807A0F68;
    }
L_807A0F5C:
    // 0x807A0F5C: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(841, 0XB70) << 16);
    // 0x807A0F60: jr          $ra
    // 0x807A0F64: addiu       $v0, $v0, 0x1AB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(841, 0XB70));
    return;
    // 0x807A0F64: addiu       $v0, $v0, 0x1AB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(841, 0XB70));
L_807A0F68:
    // 0x807A0F68: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(841, 0XB70) << 16);
    // 0x807A0F6C: addiu       $v0, $v0, 0x1AB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(841, 0XB70));
    // 0x807A0F70: jr          $ra
    // 0x807A0F74: nop

    return;
    // 0x807A0F74: nop

;}
RECOMP_FUNC void func_807034D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807034D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807034DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807034E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807034E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x807034E8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807034EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807034F0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x807034F4: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x807034F8: bnel        $t6, $zero, L_80703604
    if (ctx->r14 != 0) {
        // 0x807034FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80703604;
    }
    goto skip_0;
    // 0x807034FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80703500: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    // 0x80703504: bnel        $t7, $zero, L_80703604
    if (ctx->r15 != 0) {
        // 0x80703508: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80703604;
    }
    goto skip_1;
    // 0x80703508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8070350C: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x80703510: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80703514: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80703518: beq         $t8, $zero, L_80703560
    if (ctx->r24 == 0) {
        // 0x8070351C: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_80703560;
    }
    // 0x8070351C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80703520: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80703524: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80703528: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8070352C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80703530: jal         0x8004D1F0
    // 0x80703534: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x80703534: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80703538: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8070353C: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x80703540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80703544: jal         0x8004D698
    // 0x80703548: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80703548: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8070354C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80703550: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80703554: ori         $t0, $t9, 0xF
    ctx->r8 = ctx->r25 | 0XF;
    // 0x80703558: b           L_80703598
    // 0x8070355C: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
        goto L_80703598;
    // 0x8070355C: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
L_80703560:
    // 0x80703560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80703564: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80703568: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8070356C: jal         0x8004D1F0
    // 0x80703570: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x80703570: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80703574: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80703578: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x8070357C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80703580: jal         0x8004D698
    // 0x80703584: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x80703584: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80703588: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8070358C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80703590: ori         $t2, $t1, 0xF0
    ctx->r10 = ctx->r9 | 0XF0;
    // 0x80703594: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
L_80703598:
    // 0x80703598: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8070359C: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x807035A0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x807035A4: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
    // 0x807035A8: lbu         $t5, 0x30($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X30);
    // 0x807035AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807035B0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x807035B4: beql        $t5, $at, L_807035D0
    if (ctx->r13 == ctx->r1) {
        // 0x807035B8: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_807035D0;
    }
    goto skip_2;
    // 0x807035B8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x807035BC: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x807035C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807035C4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x807035C8: sw          $t8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r24;
    // 0x807035CC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_807035D0:
    // 0x807035D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807035D4: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x807035D8: nop

    // 0x807035DC: bc1tl       L_80703604
    if (c1cs) {
        // 0x807035E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80703604;
    }
    goto skip_3;
    // 0x807035E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x807035E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807035E8: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807035EC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807035F0: nop

    // 0x807035F4: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x807035F8: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x807035FC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80703600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80703604:
    // 0x80703604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80703608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8070360C: jr          $ra
    // 0x80703610: nop

    return;
    // 0x80703610: nop

;}
RECOMP_FUNC void func_800362FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800362FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036304: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036308: jal         0x80028220
    // 0x8003630C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80028220(rdram, ctx);
        goto after_0;
    // 0x8003630C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80036310: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80036314: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80036318: sw          $t7, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->r15;
    // 0x8003631C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036324: jr          $ra
    // 0x80036328: nop

    return;
    // 0x80036328: nop

;}
RECOMP_FUNC void func_8003B26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B26C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B274: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8003B278: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8003B27C: jal         0x8003AE00
    // 0x8003B280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003AE00(rdram, ctx);
        goto after_0;
    // 0x8003B280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B284: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003B288: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B28C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B290: jal         0x8004A498
    // 0x8003B294: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    func_8004A498(rdram, ctx);
        goto after_1;
    // 0x8003B294: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    after_1:
    // 0x8003B298: jal         0x8003AF90
    // 0x8003B29C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003AF90(rdram, ctx);
        goto after_2;
    // 0x8003B29C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003B2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B2A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B2A8: jr          $ra
    // 0x8003B2AC: nop

    return;
    // 0x8003B2AC: nop

;}
RECOMP_FUNC void func_80029678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029678: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8002967C: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x80029680: lw          $t1, 0xD0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XD0);
    // 0x80029684: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80029688: lw          $t8, 0xFC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XFC);
    // 0x8002968C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80029690: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80029694: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80029698: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8002969C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800296A0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800296A4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800296A8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800296AC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800296B0: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800296B4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800296B8: lw          $t4, -0x218C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X218C);
    // 0x800296BC: lw          $t6, 0x38($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X38);
    // 0x800296C0: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x800296C4: lw          $t5, -0x21BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X21BC);
    // 0x800296C8: subu        $v0, $t6, $t4
    ctx->r2 = SUB32(ctx->r14, ctx->r12);
    // 0x800296CC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800296D0: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800296D4: bne         $at, $zero, L_80029738
    if (ctx->r1 != 0) {
        // 0x800296D8: addu        $t7, $t7, $v1
        ctx->r15 = ADD32(ctx->r15, ctx->r3);
            goto L_80029738;
    }
    // 0x800296D8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800296DC: lw          $t7, -0x21A4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X21A4);
    // 0x800296E0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800296E4: beq         $at, $zero, L_80029720
    if (ctx->r1 == 0) {
        // 0x800296E8: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80029720;
    }
    // 0x800296E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800296EC: lwc1        $f4, -0x1D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1D4);
    // 0x800296F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800296F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800296F8: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x800296FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029700: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80029704: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80029708: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8002970C: nop

    // 0x80029710: bc1f        L_8002976C
    if (!c1cs) {
        // 0x80029714: nop
    
            goto L_8002976C;
    }
    // 0x80029714: nop

    // 0x80029718: jr          $ra
    // 0x8002971C: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8002971C: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_80029720:
    // 0x80029720: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029724: nop

    // 0x80029728: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8002972C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80029730: jr          $ra
    // 0x80029734: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80029734: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_80029738:
    // 0x80029738: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002973C: lwc1        $f10, -0x1D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1D0);
    // 0x80029740: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80029744: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80029748: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8002974C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029750: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x80029754: lwc1        $f18, 0xC4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80029758: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8002975C: nop

    // 0x80029760: bc1f        L_8002976C
    if (!c1cs) {
        // 0x80029764: nop
    
            goto L_8002976C;
    }
    // 0x80029764: nop

    // 0x80029768: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_8002976C:
    // 0x8002976C: jr          $ra
    // 0x80029770: nop

    return;
    // 0x80029770: nop

;}
RECOMP_FUNC void func_8057B444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057B444: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8057B448: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8057B44C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057B450: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(384, 0X1AC8) << 16);
    // 0x8057B454: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8057B458: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8057B45C: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    // 0x8057B460: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8057B464: lw          $t8, -0x4AF8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(384, 0X1AC8));
    // 0x8057B468: jr          $ra
    // 0x8057B46C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8057B46C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80789CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789CB0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80789CB4: addiu       $at, $zero, 0x466D
    ctx->r1 = ADD32(0, 0X466D);
    // 0x80789CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80789CBC: bne         $t6, $at, L_80789CD0
    if (ctx->r14 != ctx->r1) {
        // 0x80789CC0: nop
    
            goto L_80789CD0;
    }
    // 0x80789CC0: nop

    // 0x80789CC4: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(790, 0X418) << 16);
    // 0x80789CC8: jr          $ra
    // 0x80789CCC: addiu       $v0, $v0, -0x5F38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(790, 0X418));
    return;
    // 0x80789CCC: addiu       $v0, $v0, -0x5F38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(790, 0X418));
L_80789CD0:
    // 0x80789CD0: jr          $ra
    // 0x80789CD4: nop

    return;
    // 0x80789CD4: nop

;}
RECOMP_FUNC void func_806F0018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F0018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F0020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F0024: jal         0x806EC16C
    // 0x806F0028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806F0028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F002C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F0030: jal         0x800577D8
    // 0x806F0034: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806F0034: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806F0038: jal         0x806EF504
    // 0x806F003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_2;
    // 0x806F003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F0040: jal         0x806EF584
    // 0x806F0044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_3;
    // 0x806F0044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F0048: jal         0x806EF638
    // 0x806F004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF638(rdram, ctx);
        goto after_4;
    // 0x806F004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806F0050: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806F0054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F0058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F005C: blez        $v0, L_806F0070
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806F0060: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_806F0070;
    }
    // 0x806F0060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F0064: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806F0068: b           L_806F0078
    // 0x806F006C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_806F0078;
    // 0x806F006C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806F0070:
    // 0x806F0070: jal         0x806F0348
    // 0x806F0074: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_5;
    // 0x806F0074: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
L_806F0078:
    // 0x806F0078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F007C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F0080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F0084: jr          $ra
    // 0x806F0088: nop

    return;
    // 0x806F0088: nop

;}
RECOMP_FUNC void func_80666CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80666CF8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80666CFC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80666D00: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80666D04: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80666D08: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80666D0C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80666D10: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80666D14: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80666D18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80666D1C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80666D20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80666D24: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80666D28: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80666D2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80666D30: mul.s       $f24, $f4, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80666D34: addiu       $s0, $a0, 0x54
    ctx->r16 = ADD32(ctx->r4, 0X54);
    // 0x80666D38: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80666D3C: mul.s       $f26, $f6, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80666D40: beq         $v0, $zero, L_80666E0C
    if (ctx->r2 == 0) {
        // 0x80666D44: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80666E0C;
    }
    // 0x80666D44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80666D48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80666D4C: bnel        $v0, $at, L_80666DA0
    if (ctx->r2 != ctx->r1) {
        // 0x80666D50: mtc1        $v0, $f10
        ctx->f10.u32l = ctx->r2;
            goto L_80666DA0;
    }
    goto skip_0;
    // 0x80666D50: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    skip_0:
    // 0x80666D54: beql        $s1, $zero, L_80666E10
    if (ctx->r17 == 0) {
        // 0x80666D58: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80666E10;
    }
    goto skip_1;
    // 0x80666D58: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x80666D5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80666D60: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80666D64: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80666D68:
    // 0x80666D68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80666D6C: beq         $v0, $zero, L_80666D84
    if (ctx->r2 == 0) {
        // 0x80666D70: nop
    
            goto L_80666D84;
    }
    // 0x80666D70: nop

    // 0x80666D74: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x80666D78: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80666D7C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80666D80: swc1        $f0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f0.u32l;
L_80666D84:
    // 0x80666D84: beq         $s1, $zero, L_80666E0C
    if (ctx->r17 == 0) {
        // 0x80666D88: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80666E0C;
    }
    // 0x80666D88: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80666D8C: bnel        $s2, $v1, L_80666D68
    if (ctx->r18 != ctx->r3) {
        // 0x80666D90: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80666D68;
    }
    goto skip_2;
    // 0x80666D90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80666D94: b           L_80666E10
    // 0x80666D98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80666E10;
    // 0x80666D98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80666D9C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_80666DA0:
    // 0x80666DA0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80666DA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80666DA8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80666DAC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80666DB0: beq         $s1, $zero, L_80666E0C
    if (ctx->r17 == 0) {
        // 0x80666DB4: div.s       $f22, $f8, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
            goto L_80666E0C;
    }
    // 0x80666DB4: div.s       $f22, $f8, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80666DB8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_80666DBC:
    // 0x80666DBC: beql        $t7, $zero, L_80666DF8
    if (ctx->r15 == 0) {
        // 0x80666DC0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80666DF8;
    }
    goto skip_3;
    // 0x80666DC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x80666DC4: jal         0x80066DE4
    // 0x80666DC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80666DC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80666DCC: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80666DD0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80666DD4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80666DD8: jal         0x80066E88
    // 0x80666DDC: swc1        $f18, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80666DDC: swc1        $f18, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f18.u32l;
    after_1:
    // 0x80666DE0: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80666DE4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80666DE8: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80666DEC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80666DF0: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80666DF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80666DF8:
    // 0x80666DF8: beq         $s1, $zero, L_80666E0C
    if (ctx->r17 == 0) {
        // 0x80666DFC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80666E0C;
    }
    // 0x80666DFC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80666E00: slti        $at, $s2, 0xC
    ctx->r1 = SIGNED(ctx->r18) < 0XC ? 1 : 0;
    // 0x80666E04: bnel        $at, $zero, L_80666DBC
    if (ctx->r1 != 0) {
        // 0x80666E08: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_80666DBC;
    }
    goto skip_4;
    // 0x80666E08: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_4:
L_80666E0C:
    // 0x80666E0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80666E10:
    // 0x80666E10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80666E14: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80666E18: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80666E1C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80666E20: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80666E24: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80666E28: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80666E2C: jr          $ra
    // 0x80666E30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80666E30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8042E198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042E19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E1A0: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8042E1A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042E1A8: jal         0x80049D74
    // 0x8042E1AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8042E1AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8042E1B0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8042E1B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8042E1B8: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8042E1BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042E1C0: jal         0x8004D150
    // 0x8042E1C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x8042E1C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8042E1C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8042E1CC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B7C) << 16);
    // 0x8042E1D0: lwc1        $f4, 0x1C5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B7C));
    // 0x8042E1D4: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8042E1D8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8042E1DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042E1E0: nop

    // 0x8042E1E4: bc1fl       L_8042E214
    if (!c1cs) {
        // 0x8042E1E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E214;
    }
    goto skip_0;
    // 0x8042E1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042E1EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8042E1F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042E1F4: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8042E1F8: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8042E1FC: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x8042E200: beql        $t9, $zero, L_8042E214
    if (ctx->r25 == 0) {
        // 0x8042E204: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E214;
    }
    goto skip_1;
    // 0x8042E204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8042E208: jal         0x8004D618
    // 0x8042E20C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x8042E20C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_2:
    // 0x8042E210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E214:
    // 0x8042E214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042E218: jr          $ra
    // 0x8042E21C: nop

    return;
    // 0x8042E21C: nop

;}
RECOMP_FUNC void func_800452F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800452F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800452FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045300: addiu       $a0, $a0, 0x1FC
    ctx->r4 = ADD32(ctx->r4, 0X1FC);
    // 0x80045304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80045308: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8004530C: jal         0x80065728
    // 0x80045310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80045310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80045314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045318: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8004531C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80045320: jr          $ra
    // 0x80045324: nop

    return;
    // 0x80045324: nop

;}
RECOMP_FUNC void func_8043DDF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DDF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043DDFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DE00: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8043DE04: lh          $v0, 0x13C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X13C);
    // 0x8043DE08: lw          $v1, 0x8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X8);
    // 0x8043DE0C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8043DE10: srl         $t7, $v1, 28
    ctx->r15 = S32(U32(ctx->r3) >> 28);
    // 0x8043DE14: bne         $t7, $zero, L_8043DE24
    if (ctx->r15 != 0) {
        // 0x8043DE18: andi        $t8, $v1, 0xF00
        ctx->r24 = ctx->r3 & 0XF00;
            goto L_8043DE24;
    }
    // 0x8043DE18: andi        $t8, $v1, 0xF00
    ctx->r24 = ctx->r3 & 0XF00;
    // 0x8043DE1C: bnel        $t8, $zero, L_8043DE38
    if (ctx->r24 != 0) {
        // 0x8043DE20: lw          $t9, 0x138($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X138);
            goto L_8043DE38;
    }
    goto skip_0;
    // 0x8043DE20: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    skip_0:
L_8043DE24:
    // 0x8043DE24: jal         0x8043E0F8
    // 0x8043DE28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8043E0F8(rdram, ctx);
        goto after_0;
    // 0x8043DE28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8043DE2C: b           L_8043DE80
    // 0x8043DE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043DE80;
    // 0x8043DE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043DE34: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
L_8043DE38:
    // 0x8043DE38: bnel        $t9, $zero, L_8043DE64
    if (ctx->r25 != 0) {
        // 0x8043DE3C: lw          $t2, 0x34($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X34);
            goto L_8043DE64;
    }
    goto skip_1;
    // 0x8043DE3C: lw          $t2, 0x34($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X34);
    skip_1:
    // 0x8043DE40: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8043DE44: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x8043DE48: bgezl       $t1, L_8043DE80
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8043DE4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043DE80;
    }
    goto skip_2;
    // 0x8043DE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8043DE50: jal         0x8043E0F8
    // 0x8043DE54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8043E0F8(rdram, ctx);
        goto after_1;
    // 0x8043DE54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8043DE58: b           L_8043DE80
    // 0x8043DE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043DE80;
    // 0x8043DE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043DE60: lw          $t2, 0x34($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X34);
L_8043DE64:
    // 0x8043DE64: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8043DE68: slti        $at, $t3, 0x141
    ctx->r1 = SIGNED(ctx->r11) < 0X141 ? 1 : 0;
    // 0x8043DE6C: bnel        $at, $zero, L_8043DE80
    if (ctx->r1 != 0) {
        // 0x8043DE70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043DE80;
    }
    goto skip_3;
    // 0x8043DE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8043DE74: jal         0x8043E0F8
    // 0x8043DE78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8043E0F8(rdram, ctx);
        goto after_2;
    // 0x8043DE78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8043DE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043DE80:
    // 0x8043DE80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043DE84: jr          $ra
    // 0x8043DE88: nop

    return;
    // 0x8043DE88: nop

;}
RECOMP_FUNC void func_8005B0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B0AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B0B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B0B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005B0B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005B0BC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8005B0C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8005B0C4: jal         0x80051DA0
    // 0x8005B0C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80051DA0(rdram, ctx);
        goto after_0;
    // 0x8005B0C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8005B0CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005B0D0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8005B0D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005B0D8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8005B0DC: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8005B0E0: lbu         $t6, 0x1C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1C);
    // 0x8005B0E4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8005B0E8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8005B0EC: sb          $t6, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r14;
    // 0x8005B0F0: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x8005B0F4: sw          $t9, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r25;
    // 0x8005B0F8: sb          $t7, 0x11($a2)
    MEM_B(0X11, ctx->r6) = ctx->r15;
    // 0x8005B0FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B104: jr          $ra
    // 0x8005B108: nop

    return;
    // 0x8005B108: nop

;}
RECOMP_FUNC void func_805A1714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A1718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A171C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805A1720: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A1724: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A1728: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x805A172C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A1730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A1734: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x805A1738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805A173C: jal         0x8004D150
    // 0x805A1740: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x805A1740: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x805A1744: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x805A1748: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805A174C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805A1750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A1754: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x805A1758: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x805A175C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x805A1760: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x805A1764: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x805A1768: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x805A176C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x805A1770: lbu         $t2, 0x14($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X14);
    // 0x805A1774: beql        $t2, $zero, L_805A17B8
    if (ctx->r10 == 0) {
        // 0x805A1778: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A17B8;
    }
    goto skip_0;
    // 0x805A1778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A177C: lbu         $t3, 0x30($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X30);
    // 0x805A1780: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x805A1784: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x805A1788: beq         $t3, $at, L_805A179C
    if (ctx->r11 == ctx->r1) {
        // 0x805A178C: addiu       $a2, $a2, 0x5284
        ctx->r6 = ADD32(ctx->r6, 0X5284);
            goto L_805A179C;
    }
    // 0x805A178C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x805A1790: jal         0x8004D618
    // 0x805A1794: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x805A1794: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805A1798: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_805A179C:
    // 0x805A179C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x805A17A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A17A4: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x805A17A8: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x805A17AC: ori         $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 | 0XF00;
    // 0x805A17B0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x805A17B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A17B8:
    // 0x805A17B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A17BC: jr          $ra
    // 0x805A17C0: nop

    return;
    // 0x805A17C0: nop

;}
RECOMP_FUNC void func_80424CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424CA4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80424CA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80424CAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80424CB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80424CB4: jal         0x80051194
    // 0x80424CB8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80424CB8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80424CBC: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80424CC0: jal         0x804234C0
    // 0x80424CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804234C0(rdram, ctx);
        goto after_1;
    // 0x80424CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80424CC8: bnel        $v0, $zero, L_80424CE4
    if (ctx->r2 != 0) {
        // 0x80424CCC: lw          $t0, 0x1F4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1F4);
            goto L_80424CE4;
    }
    goto skip_0;
    // 0x80424CCC: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80424CD0: jal         0x800445A4
    // 0x80424CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80424CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80424CD8: b           L_80424E44
    // 0x80424CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80424E44;
    // 0x80424CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80424CE0: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
L_80424CE4:
    // 0x80424CE4: lui         $v1, 0x8042
    ctx->r3 = S32(RELOC_HI16(35, 0X3408) << 16);
    // 0x80424CE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80424CEC: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x80424CF0: addiu       $v1, $v1, 0x5E08
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(35, 0X3408));
    // 0x80424CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80424CF8: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x80424CFC: beq         $a2, $zero, L_80424D64
    if (ctx->r6 == 0) {
        // 0x80424D00: addiu       $v0, $t0, 0xA0
        ctx->r2 = ADD32(ctx->r8, 0XA0);
            goto L_80424D64;
    }
    // 0x80424D00: addiu       $v0, $t0, 0xA0
    ctx->r2 = ADD32(ctx->r8, 0XA0);
    // 0x80424D04: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x80424D08: beq         $a3, $zero, L_80424D30
    if (ctx->r7 == 0) {
        // 0x80424D0C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80424D30;
    }
    // 0x80424D0C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80424D10:
    // 0x80424D10: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80424D14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80424D18: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80424D1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80424D20: bne         $a1, $a0, L_80424D10
    if (ctx->r5 != ctx->r4) {
        // 0x80424D24: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80424D10;
    }
    // 0x80424D24: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80424D28: beql        $a0, $a2, L_80424D64
    if (ctx->r4 == ctx->r6) {
        // 0x80424D2C: lw          $t0, 0x1F4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1F4);
            goto L_80424D64;
    }
    goto skip_1;
    // 0x80424D2C: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
L_80424D30:
    // 0x80424D30: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80424D34: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80424D38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80424D3C: swc1        $f6, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80424D40: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80424D44: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80424D48: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80424D4C: lwc1        $f10, -0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X8);
    // 0x80424D50: swc1        $f10, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80424D54: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80424D58: bne         $a0, $a2, L_80424D30
    if (ctx->r4 != ctx->r6) {
        // 0x80424D5C: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_80424D30;
    }
    // 0x80424D5C: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80424D60: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
L_80424D64:
    // 0x80424D64: swc1        $f18, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->f18.u32l;
    // 0x80424D68: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424D6C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80424D70: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80424D74: sw          $zero, 0xF4($t6)
    MEM_W(0XF4, ctx->r14) = 0;
    // 0x80424D78: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424D7C: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(35, 0X31C8) << 16);
    // 0x80424D80: addiu       $t1, $t1, 0x5BC8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(35, 0X31C8));
    // 0x80424D84: lw          $t7, 0xF4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XF4);
    // 0x80424D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424D90: sw          $t7, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->r15;
    // 0x80424D94: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424D98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80424D9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80424DA0: sw          $zero, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = 0;
    // 0x80424DA4: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x80424DA8: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x80424DAC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80424DB0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80424DB4: jal         0x80424E54
    // 0x80424DB8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_80424E54(rdram, ctx);
        goto after_3;
    // 0x80424DB8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_3:
    // 0x80424DBC: jal         0x80047090
    // 0x80424DC0: addiu       $a0, $zero, 0x4066
    ctx->r4 = ADD32(0, 0X4066);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x80424DC0: addiu       $a0, $zero, 0x4066
    ctx->r4 = ADD32(0, 0X4066);
    after_4:
    // 0x80424DC4: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80424DC8: bne         $a0, $v0, L_80424DE0
    if (ctx->r4 != ctx->r2) {
        // 0x80424DCC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80424DE0;
    }
    // 0x80424DCC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80424DD0: jal         0x800445A4
    // 0x80424DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x80424DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80424DD8: b           L_80424E44
    // 0x80424DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80424E44;
    // 0x80424DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80424DE0:
    // 0x80424DE0: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x80424DE4: beql        $a0, $t3, L_80424E44
    if (ctx->r4 == ctx->r11) {
        // 0x80424DE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80424E44;
    }
    goto skip_2;
    // 0x80424DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80424DEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80424DF0: lui         $at, 0x4066
    ctx->r1 = S32(0X4066 << 16);
    // 0x80424DF4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80424DF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80424DFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80424E00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80424E04: jal         0x8004613C
    // 0x80424E08: nop

    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x80424E08: nop

    after_6:
    // 0x80424E0C: beq         $v0, $zero, L_80424E38
    if (ctx->r2 == 0) {
        // 0x80424E10: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80424E38;
    }
    // 0x80424E10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80424E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424E18: jal         0x80047F9C
    // 0x80424E1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80424E1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // 0x80424E20: jal         0x804255F0
    // 0x80424E24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_804255F0(rdram, ctx);
        goto after_8;
    // 0x80424E24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80424E28: jal         0x804235A8
    // 0x80424E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804235A8(rdram, ctx);
        goto after_9;
    // 0x80424E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80424E30: b           L_80424E44
    // 0x80424E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80424E44;
    // 0x80424E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80424E38:
    // 0x80424E38: jal         0x800445A4
    // 0x80424E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_10;
    // 0x80424E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80424E40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80424E44:
    // 0x80424E44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80424E48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80424E4C: jr          $ra
    // 0x80424E50: nop

    return;
    // 0x80424E50: nop

;}
RECOMP_FUNC void func_80682F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682F84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682F88: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682F8C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682F90: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682F94: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682F98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682F9C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682FA0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682FA4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682FA8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682FAC: jr          $ra
    // 0x80682FB0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682FB0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807071A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807071A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807071A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807071A8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807071AC: addiu       $at, $zero, 0x4608
    ctx->r1 = ADD32(0, 0X4608);
    // 0x807071B0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807071B4: bne         $v0, $at, L_807071F4
    if (ctx->r2 != ctx->r1) {
        // 0x807071B8: lui         $t6, 0x8070
        ctx->r14 = S32(RELOC_HI16(712, 0X630) << 16);
            goto L_807071F4;
    }
    // 0x807071B8: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(712, 0X630) << 16);
    // 0x807071BC: lw          $t6, 0x77D0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(712, 0X630));
    // 0x807071C0: lui         $a0, 0x8070
    ctx->r4 = S32(RELOC_HI16(712, 0X758) << 16);
    // 0x807071C4: addiu       $a0, $a0, 0x78F8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(712, 0X758));
    // 0x807071C8: bne         $t6, $zero, L_807071F4
    if (ctx->r14 != 0) {
        // 0x807071CC: lui         $a1, 0x8070
        ctx->r5 = S32(RELOC_HI16(712, 0X778) << 16);
            goto L_807071F4;
    }
    // 0x807071CC: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(712, 0X778) << 16);
    // 0x807071D0: addiu       $a1, $a1, 0x7918
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(712, 0X778));
    // 0x807071D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807071D8: jal         0x8004667C
    // 0x807071DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x807071DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807071E0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807071E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807071E8: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(712, 0X630) << 16);
    // 0x807071EC: sw          $t7, 0x77D0($at)
    MEM_W((int16_t)RELOC_LO16(712, 0X630), ctx->r1) = ctx->r15;
    // 0x807071F0: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
L_807071F4:
    // 0x807071F4: addiu       $at, $zero, 0x4609
    ctx->r1 = ADD32(0, 0X4609);
    // 0x807071F8: bne         $v0, $at, L_8070722C
    if (ctx->r2 != ctx->r1) {
        // 0x807071FC: lui         $t8, 0x8070
        ctx->r24 = S32(RELOC_HI16(712, 0X634) << 16);
            goto L_8070722C;
    }
    // 0x807071FC: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(712, 0X634) << 16);
    // 0x80707200: lw          $t8, 0x77D4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(712, 0X634));
    // 0x80707204: lui         $a0, 0x8070
    ctx->r4 = S32(RELOC_HI16(712, 0X768) << 16);
    // 0x80707208: addiu       $a0, $a0, 0x7908
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(712, 0X768));
    // 0x8070720C: bne         $t8, $zero, L_8070722C
    if (ctx->r24 != 0) {
        // 0x80707210: lui         $a1, 0x8071
        ctx->r5 = S32(RELOC_HI16(712, 0X1178) << 16);
            goto L_8070722C;
    }
    // 0x80707210: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(712, 0X1178) << 16);
    // 0x80707214: addiu       $a1, $a1, -0x7CE8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(712, 0X1178));
    // 0x80707218: jal         0x8004667C
    // 0x8070721C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8004667C(rdram, ctx);
        goto after_1;
    // 0x8070721C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80707220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80707224: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(712, 0X634) << 16);
    // 0x80707228: sw          $t9, 0x77D4($at)
    MEM_W((int16_t)RELOC_LO16(712, 0X634), ctx->r1) = ctx->r25;
L_8070722C:
    // 0x8070722C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80707230: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x80707234: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80707238: addiu       $t0, $t0, 0x78F0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(712, 0X750));
    // 0x8070723C: sw          $t0, 0xE90($v1)
    MEM_W(0XE90, ctx->r3) = ctx->r8;
    // 0x80707240: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80707244: lw          $t2, 0xE90($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XE90);
    // 0x80707248: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(712, 0X564) << 16);
    // 0x8070724C: addiu       $v0, $v0, 0x7704
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(712, 0X564));
    // 0x80707250: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80707254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80707258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070725C: jr          $ra
    // 0x80707260: nop

    return;
    // 0x80707260: nop

;}
RECOMP_FUNC void func_800594F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800594F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800594FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059504: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059508: jal         0x80081C64
    // 0x8005950C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8005950C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059510: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80059514: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059518: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x8005951C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059520: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059524: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059528: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005952C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059530: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80059534: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80059538: lw          $t7, 0x478($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X478);
    // 0x8005953C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80059540: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80059544: lwc1        $f4, 0xBA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XBA0);
    // 0x80059548: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8005954C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059554: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80059558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005955C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80059560: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80059564: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059568: lwc1        $f16, 0x30($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8005956C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059570: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80059574: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059578: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005957C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80059580: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059584: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80059588: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8005958C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80059590: nop

    // 0x80059594: bc1f        L_800595A0
    if (!c1cs) {
        // 0x80059598: nop
    
            goto L_800595A0;
    }
    // 0x80059598: nop

    // 0x8005959C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800595A0:
    // 0x800595A0: jr          $ra
    // 0x800595A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800595A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80461C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461C80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80461C84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80461C88: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x80461C8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80461C90: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80461C94: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A2C) << 16);
    // 0x80461C98: bc1f        L_80461CB0
    if (!c1cs) {
        // 0x80461C9C: nop
    
            goto L_80461CB0;
    }
    // 0x80461C9C: nop

    // 0x80461CA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80461CA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80461CA8: b           L_80461CEC
    // 0x80461CAC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
        goto L_80461CEC;
    // 0x80461CAC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
L_80461CB0:
    // 0x80461CB0: lwc1        $f6, 0x3FBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A2C));
    // 0x80461CB4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80461CB8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80461CBC: nop

    // 0x80461CC0: bc1fl       L_80461CE4
    if (!c1cs) {
        // 0x80461CC4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80461CE4;
    }
    goto skip_0;
    // 0x80461CC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80461CC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80461CCC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80461CD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80461CD4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80461CD8: b           L_80461CE8
    // 0x80461CDC: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
        goto L_80461CE8;
    // 0x80461CDC: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80461CE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80461CE4:
    // 0x80461CE4: nop

L_80461CE8:
    // 0x80461CE8: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
L_80461CEC:
    // 0x80461CEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80461CF0: bc1f        L_80461D08
    if (!c1cs) {
        // 0x80461CF4: nop
    
            goto L_80461D08;
    }
    // 0x80461CF4: nop

    // 0x80461CF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80461CFC: nop

    // 0x80461D00: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80461D04: nop

L_80461D08:
    // 0x80461D08: jr          $ra
    // 0x80461D0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80461D0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8007291C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007291C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072924: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80072928: jal         0x80072858
    // 0x8007292C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    func_80072858(rdram, ctx);
        goto after_0;
    // 0x8007292C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    after_0:
    // 0x80072930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072938: jr          $ra
    // 0x8007293C: nop

    return;
    // 0x8007293C: nop

;}
RECOMP_FUNC void func_8064EFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EFE8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064EFEC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064EFF0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064EFF4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064EFF8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064EFFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F000: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F004: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F008: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F00C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F010: jr          $ra
    // 0x8064F014: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F014: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805EC230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805EC230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805EC234: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x805EC238: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x805EC23C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x805EC240: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x805EC244: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x805EC248: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x805EC24C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x805EC250: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x805EC254: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x805EC258: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x805EC25C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x805EC260: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805EC264: lw          $a2, 0x1F4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1F4);
    // 0x805EC268: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x805EC26C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC270: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x805EC274: lw          $t0, 0x6C8C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C8C);
    // 0x805EC278: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC27C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC280: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x805EC284: sll         $t6, $t0, 5
    ctx->r14 = S32(ctx->r8 << 5);
    // 0x805EC288: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x805EC28C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC290: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x805EC294: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC298: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805EC29C: lui         $t7, 0x805F
    ctx->r15 = S32(RELOC_HI16(492, 0X470) << 16);
    // 0x805EC2A0: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x805EC2A4: sll         $t6, $t6, 10
    ctx->r14 = S32(ctx->r14 << 10);
    // 0x805EC2A8: addiu       $t7, $t7, -0x3990
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(492, 0X470));
    // 0x805EC2AC: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x805EC2B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805EC2B4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805EC2B8: lui         $t7, 0x8065
    ctx->r15 = S32(RELOC_HI16(492, 0X5C878) << 16);
    // 0x805EC2BC: addiu       $t7, $t7, -0x7588
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(492, 0X5C878));
    // 0x805EC2C0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x805EC2C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805EC2C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805EC2CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC2D0: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x805EC2D4: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x805EC2D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC2DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC2E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC2E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805EC2E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC2EC: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x805EC2F0: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x805EC2F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC2F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC2FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805EC300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805EC304: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC308: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x805EC30C: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x805EC310: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805EC314: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805EC318: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC31C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805EC320: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC324: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x805EC328: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x805EC32C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC330: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC334: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805EC338: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805EC33C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC340: lui         $t9, 0x1F
    ctx->r25 = S32(0X1F << 16);
    // 0x805EC344: ori         $t9, $t9, 0x3205
    ctx->r25 = ctx->r25 | 0X3205;
    // 0x805EC348: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC34C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC350: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC354: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x805EC358: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC35C: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x805EC360: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x805EC364: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC368: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC36C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805EC370: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805EC374: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC378: addiu       $t8, $zero, 0x2205
    ctx->r24 = ADD32(0, 0X2205);
    // 0x805EC37C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x805EC380: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC384: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC388: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805EC38C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805EC390: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC394: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x805EC398: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x805EC39C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805EC3A0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805EC3A4: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x805EC3A8: ori         $t7, $t7, 0xAC00
    ctx->r15 = ctx->r15 | 0XAC00;
    // 0x805EC3AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805EC3B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805EC3B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC3B8: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x805EC3BC: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x805EC3C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC3C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC3C8: ori         $t0, $t0, 0x2078
    ctx->r8 = ctx->r8 | 0X2078;
    // 0x805EC3CC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x805EC3D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805EC3D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC3D8: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x805EC3DC: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x805EC3E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC3E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC3E8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x805EC3EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805EC3F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC3F4: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x805EC3F8: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x805EC3FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC400: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC404: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x805EC408: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x805EC40C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805EC410: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805EC414: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC418: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x805EC41C: lui         $t8, 0xBB00
    ctx->r24 = S32(0XBB00 << 16);
    // 0x805EC420: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC424: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC428: lui         $t7, 0x8065
    ctx->r15 = S32(RELOC_HI16(492, 0X5CA78) << 16);
    // 0x805EC42C: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x805EC430: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x805EC434: addiu       $t7, $t7, -0x7388
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(492, 0X5CA78));
    // 0x805EC438: sll         $t6, $zero, 4
    ctx->r14 = S32(0 << 4);
    // 0x805EC43C: lui         $s4, 0xF548
    ctx->r20 = S32(0XF548 << 16);
    // 0x805EC440: lui         $s6, 0x400
    ctx->r22 = S32(0X400 << 16);
    // 0x805EC444: lui         $s7, 0xB102
    ctx->r23 = S32(0XB102 << 16);
    // 0x805EC448: lui         $fp, 0x2
    ctx->r30 = S32(0X2 << 16);
    // 0x805EC44C: lui         $t5, 0x51
    ctx->r13 = S32(0X51 << 16);
    // 0x805EC450: lui         $t4, 0x73D
    ctx->r12 = S32(0X73D << 16);
    // 0x805EC454: ori         $t4, $t4, 0x7032
    ctx->r12 = ctx->r12 | 0X7032;
    // 0x805EC458: ori         $t5, $t5, 0xC014
    ctx->r13 = ctx->r13 | 0XC014;
    // 0x805EC45C: ori         $fp, $fp, 0x600
    ctx->r30 = ctx->r30 | 0X600;
    // 0x805EC460: ori         $s7, $s7, 0x406
    ctx->r23 = ctx->r23 | 0X406;
    // 0x805EC464: ori         $s6, $s6, 0x103F
    ctx->r22 = ctx->r22 | 0X103F;
    // 0x805EC468: ori         $s4, $s4, 0x5200
    ctx->r20 = ctx->r20 | 0X5200;
    // 0x805EC46C: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x805EC470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x805EC474: addiu       $s0, $zero, 0x4C
    ctx->r16 = ADD32(0, 0X4C);
    // 0x805EC478: lui         $s1, 0xFD50
    ctx->r17 = S32(0XFD50 << 16);
    // 0x805EC47C: lui         $s2, 0xF550
    ctx->r18 = S32(0XF550 << 16);
    // 0x805EC480: lui         $s3, 0xF300
    ctx->r19 = S32(0XF300 << 16);
    // 0x805EC484: lui         $s5, 0xF200
    ctx->r21 = S32(0XF200 << 16);
    // 0x805EC488: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805EC48C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_805EC490:
    // 0x805EC490: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC494: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x805EC498: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x805EC49C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC4A0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC4A4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x805EC4A8: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x805EC4AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC4B0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x805EC4B4: addiu       $t3, $t3, 0x668
    ctx->r11 = ADD32(ctx->r11, 0X668);
    // 0x805EC4B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805EC4BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805EC4C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805EC4C4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x805EC4C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC4CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC4D0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC4D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC4D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805EC4DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC4E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805EC4E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805EC4E8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x805EC4EC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x805EC4F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC4F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC4F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC4FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC500: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x805EC504: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC508: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC50C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC510: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC514: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x805EC518: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC51C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC520: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC524: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x805EC528: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x805EC52C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC530: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805EC534: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805EC538: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x805EC53C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x805EC540: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC544: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
    // 0x805EC548: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC54C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC550: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x805EC554: bne         $a3, $s0, L_805EC490
    if (ctx->r7 != ctx->r16) {
        // 0x805EC558: sw          $s7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r23;
            goto L_805EC490;
    }
    // 0x805EC558: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x805EC55C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC560: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x805EC564: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC568: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC56C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x805EC570: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x805EC574: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC578: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x805EC57C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC580: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC584: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805EC588: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x805EC58C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC590: lui         $t9, 0x728
    ctx->r25 = S32(0X728 << 16);
    // 0x805EC594: ori         $t9, $t9, 0xF032
    ctx->r25 = ctx->r25 | 0XF032;
    // 0x805EC598: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC59C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC5A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC5A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805EC5A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC5AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC5B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC5B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805EC5B8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x805EC5BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC5C0: lui         $t9, 0x51
    ctx->r25 = S32(0X51 << 16);
    // 0x805EC5C4: ori         $t9, $t9, 0xC00C
    ctx->r25 = ctx->r25 | 0XC00C;
    // 0x805EC5C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC5CC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC5D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC5D4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x805EC5D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC5DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC5E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC5E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805EC5E8: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x805EC5EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC5F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805EC5F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805EC5F8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805EC5FC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x805EC600: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC604: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805EC608: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805EC60C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x805EC610: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x805EC614: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805EC618: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805EC61C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805EC620: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x805EC624: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x805EC628: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x805EC62C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x805EC630: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x805EC634: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x805EC638: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x805EC63C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x805EC640: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x805EC644: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x805EC648: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x805EC64C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x805EC650: jr          $ra
    // 0x805EC654: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805EC654: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805EC658: nop

    // 0x805EC65C: nop

;}
RECOMP_FUNC void func_80740E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80740E60: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(751, 0X484) << 16);
    // 0x80740E64: addiu       $v0, $v0, 0x12E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(751, 0X484));
    // 0x80740E68: jr          $ra
    // 0x80740E6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80740E6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806830A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806830A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806830A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806830AC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806830B0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806830B4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806830B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806830BC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806830C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806830C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806830C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806830CC: jr          $ra
    // 0x806830D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806830D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044B1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B1A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044B1A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B1AC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044B1B0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044B1B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044B1B8: jal         0x8044A558
    // 0x8044B1BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044B1BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8044B1C0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B1C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044B1C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044B1CC: bne         $v0, $zero, L_8044B1E4
    if (ctx->r2 != 0) {
        // 0x8044B1D0: nop
    
            goto L_8044B1E4;
    }
    // 0x8044B1D0: nop

    // 0x8044B1D4: jal         0x80446848
    // 0x8044B1D8: nop

    func_80446848(rdram, ctx);
        goto after_1;
    // 0x8044B1D8: nop

    after_1:
    // 0x8044B1DC: b           L_8044B208
    // 0x8044B1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B208;
    // 0x8044B1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B1E4:
    // 0x8044B1E4: bne         $v0, $at, L_8044B1FC
    if (ctx->r2 != ctx->r1) {
        // 0x8044B1E8: nop
    
            goto L_8044B1FC;
    }
    // 0x8044B1E8: nop

    // 0x8044B1EC: jal         0x80446880
    // 0x8044B1F0: nop

    func_80446880(rdram, ctx);
        goto after_2;
    // 0x8044B1F0: nop

    after_2:
    // 0x8044B1F4: b           L_8044B208
    // 0x8044B1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044B208;
    // 0x8044B1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B1FC:
    // 0x8044B1FC: jal         0x804468D4
    // 0x8044B200: nop

    func_804468D4(rdram, ctx);
        goto after_3;
    // 0x8044B200: nop

    after_3:
    // 0x8044B204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044B208:
    // 0x8044B208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044B20C: jr          $ra
    // 0x8044B210: nop

    return;
    // 0x8044B210: nop

;}
RECOMP_FUNC void Fault_PrintChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7B8: lui         $t6, 0xFFFA
    ctx->r14 = S32(0XFFFA << 16);
    // 0x8006F7BC: or          $t7, $sp, $zero
    ctx->r15 = ctx->r29 | 0;
    // 0x8006F7C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F7C4: ori         $t6, $t6, 0x5A5A
    ctx->r14 = ctx->r14 | 0X5A5A;
L_8006F7C8:
    // 0x8006F7C8: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
    // 0x8006F7CC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8006F7D0: bne         $t7, $sp, L_8006F7C8
    if (ctx->r15 != ctx->r29) {
        // 0x8006F7D4: sw          $t6, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r14;
            goto L_8006F7C8;
    }
    // 0x8006F7D4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8006F7D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006F7DC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8006F7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F7E4: jal         0x8006F69C
    // 0x8006F7E8: nop

    Fault_PrintCharImpl(rdram, ctx);
        goto after_0;
    // 0x8006F7E8: nop

    after_0:
    // 0x8006F7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F7F4: jr          $ra
    // 0x8006F7F8: nop

    return;
    // 0x8006F7F8: nop

;}
RECOMP_FUNC void func_80445954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044595C: addiu       $a0, $zero, 0x227
    ctx->r4 = ADD32(0, 0X227);
    // 0x80445960: jal         0x80067818
    // 0x80445964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x80445964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80445968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044596C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445970: jr          $ra
    // 0x80445974: nop

    return;
    // 0x80445974: nop

;}
RECOMP_FUNC void func_80455234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80455238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045523C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455240: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80455244: lui         $a1, 0x8046
    ctx->r5 = S32(RELOC_HI16(98, 0X13CCC) << 16);
    // 0x80455248: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8045524C: lw          $v1, 0x6CE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CE4);
    // 0x80455250: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80455254: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80455258: lw          $a1, -0x7F54($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13CCC));
    // 0x8045525C: jalr        $a1
    // 0x80455260: nop

    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x80455260: nop

    after_0:
    // 0x80455264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045526C: jr          $ra
    // 0x80455270: nop

    return;
    // 0x80455270: nop

;}
RECOMP_FUNC void func_806CDF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CDF60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CDF64: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806CDF68: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806CDF6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CDF70: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806CDF74: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x806CDF78: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x806CDF7C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x806CDF80: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806CDF84: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x806CDF88: bc1t        L_806CE074
    if (c1cs) {
        // 0x806CDF8C: swc1        $f6, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
            goto L_806CE074;
    }
    // 0x806CDF8C: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x806CDF90: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x806CDF94: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806CDF98: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x806CDF9C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806CDFA0: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x806CDFA4: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x806CDFA8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C58) << 16);
    // 0x806CDFAC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806CDFB0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806CDFB4: lwc1        $f10, -0xC88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C58));
    // 0x806CDFB8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C5C) << 16);
    // 0x806CDFBC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CDFC0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806CDFC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806CDFC8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x806CDFCC: lwc1        $f4, -0xC84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C5C));
    // 0x806CDFD0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806CDFD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806CDFD8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806CDFDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806CDFE0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806CDFE4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CDFE8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x806CDFEC: nop

    // 0x806CDFF0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x806CDFF4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CDFF8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806CDFFC: nop

    // 0x806CE000: bc1f        L_806CE074
    if (!c1cs) {
        // 0x806CE004: nop
    
            goto L_806CE074;
    }
    // 0x806CE004: nop

    // 0x806CE008: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x806CE00C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CE010: bc1fl       L_806CE02C
    if (!c1cs) {
        // 0x806CE014: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_806CE02C;
    }
    goto skip_0;
    // 0x806CE014: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x806CE018: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CE01C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CE020: b           L_806CE034
    // 0x806CE024: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
        goto L_806CE034;
    // 0x806CE024: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
    // 0x806CE028: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_806CE02C:
    // 0x806CE02C: nop

    // 0x806CE030: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
L_806CE034:
    // 0x806CE034: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x806CE038: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806CE03C: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x806CE040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CE044: jalr        $t9
    // 0x806CE048: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806CE048: nop

    after_0:
    // 0x806CE04C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806CE050: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806CE054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CE058: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806CE05C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806CE060: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CE064: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CE068: nop

    // 0x806CE06C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x806CE070: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_806CE074:
    // 0x806CE074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CE078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806CE07C: jr          $ra
    // 0x806CE080: nop

    return;
    // 0x806CE080: nop

;}
RECOMP_FUNC void func_804C1F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1F8C: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x804C1F90: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C1F94: lui         $a2, 0x804C
    ctx->r6 = S32(RELOC_HI16(203, 0X1038) << 16);
    // 0x804C1F98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804C1F9C: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x804C1FA0: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
    // 0x804C1FA4: addiu       $a2, $a2, 0x27A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(203, 0X1038));
    // 0x804C1FA8: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x804C1FAC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x804C1FB0: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x804C1FB4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x804C1FB8: sltu        $at, $t7, $t2
    ctx->r1 = ctx->r15 < ctx->r10 ? 1 : 0;
    // 0x804C1FBC: bnel        $at, $zero, L_804C2000
    if (ctx->r1 != 0) {
        // 0x804C1FC0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804C2000;
    }
    goto skip_0;
    // 0x804C1FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804C1FC4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x804C1FC8: lh          $t3, 0x10($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X10);
    // 0x804C1FCC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x804C1FD0: sh          $t4, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r12;
    // 0x804C1FD4: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x804C1FD8: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x804C1FDC: bne         $at, $zero, L_804C1FF0
    if (ctx->r1 != 0) {
        // 0x804C1FE0: sll         $t5, $a1, 3
        ctx->r13 = S32(ctx->r5 << 3);
            goto L_804C1FF0;
    }
    // 0x804C1FE0: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x804C1FE4: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x804C1FE8: jr          $ra
    // 0x804C1FEC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x804C1FEC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_804C1FF0:
    // 0x804C1FF0: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x804C1FF4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804C1FF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804C1FFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C2000:
    // 0x804C2000: jr          $ra
    // 0x804C2004: nop

    return;
    // 0x804C2004: nop

;}
RECOMP_FUNC void func_80789E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80789E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80789E78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80789E7C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80789E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80789E84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80789E88: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80789E8C: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x80789E90: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80789E94: sh          $v0, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r2;
    // 0x80789E98: lw          $t0, 0x174($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X174);
    // 0x80789E9C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80789EA0: sh          $v0, 0x10($t1)
    MEM_H(0X10, ctx->r9) = ctx->r2;
    // 0x80789EA4: jal         0x8005FCA8
    // 0x80789EA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x80789EA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80789EAC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80789EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80789EB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80789EB8: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
    // 0x80789EBC: jal         0x8078A148
    // 0x80789EC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8078A148(rdram, ctx);
        goto after_1;
    // 0x80789EC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80789EC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80789EC8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80789ECC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80789ED0: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80789ED4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80789ED8: jal         0x80789DA0
    // 0x80789EDC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_80789DA0(rdram, ctx);
        goto after_2;
    // 0x80789EDC: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_2:
    // 0x80789EE0: jal         0x80067E68
    // 0x80789EE4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x80789EE4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80789EE8: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80789EEC: jal         0x80067818
    // 0x80789EF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80789EF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80789EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80789EF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80789EFC: jr          $ra
    // 0x80789F00: nop

    return;
    // 0x80789F00: nop

;}
RECOMP_FUNC void func_805AB6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB6F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AB6F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AB6F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805AB6FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805AB700: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AB704: lh          $s0, 0x0($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X0);
    // 0x805AB708: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
    // 0x805AB70C: beql        $s0, $zero, L_805AB750
    if (ctx->r16 == 0) {
        // 0x805AB710: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_805AB750;
    }
    goto skip_0;
    // 0x805AB710: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_805AB714:
    // 0x805AB714: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x805AB718: beq         $a0, $zero, L_805AB744
    if (ctx->r4 == 0) {
        // 0x805AB71C: nop
    
            goto L_805AB744;
    }
    // 0x805AB71C: nop

    // 0x805AB720: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
    // 0x805AB724: bnel        $t7, $zero, L_805AB73C
    if (ctx->r15 != 0) {
        // 0x805AB728: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_805AB73C;
    }
    goto skip_1;
    // 0x805AB728: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x805AB72C: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x805AB730: jalr        $t9
    // 0x805AB734: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805AB734: nop

    after_0:
    // 0x805AB738: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_805AB73C:
    // 0x805AB73C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x805AB740: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_805AB744:
    // 0x805AB744: bne         $s0, $zero, L_805AB714
    if (ctx->r16 != 0) {
        // 0x805AB748: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_805AB714;
    }
    // 0x805AB748: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x805AB74C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_805AB750:
    // 0x805AB750: lw          $a0, 0x268($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X268);
    // 0x805AB754: beql        $a0, $zero, L_805AB768
    if (ctx->r4 == 0) {
        // 0x805AB758: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805AB768;
    }
    goto skip_2;
    // 0x805AB758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805AB75C: jal         0x800568E0
    // 0x805AB760: nop

    func_800568E0(rdram, ctx);
        goto after_1;
    // 0x805AB760: nop

    after_1:
    // 0x805AB764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AB768:
    // 0x805AB768: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805AB76C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805AB770: jr          $ra
    // 0x805AB774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805AB774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806E66BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E66BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E66C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E66C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E66C8: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E66CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E66D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E66D4: lw          $v0, 0x40($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X40);
    // 0x806E66D8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x806E66DC: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x806E66E0: beq         $v0, $zero, L_806E66EC
    if (ctx->r2 == 0) {
        // 0x806E66E4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806E66EC;
    }
    // 0x806E66E4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806E66E8: sw          $t6, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->r14;
L_806E66EC:
    // 0x806E66EC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x806E66F0: jal         0x80062748
    // 0x806E66F4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x806E66F4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x806E66F8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x806E66FC: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806E6700: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x806E6704: lwc1        $f4, 0x30($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X30);
    // 0x806E6708: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806E670C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x806E6710: nop

    // 0x806E6714: bc1fl       L_806E67FC
    if (!c1cs) {
        // 0x806E6718: lw          $t7, 0x3C($t1)
        ctx->r15 = MEM_W(ctx->r9, 0X3C);
            goto L_806E67FC;
    }
    goto skip_0;
    // 0x806E6718: lw          $t7, 0x3C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X3C);
    skip_0:
    // 0x806E671C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806E6720: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x806E6724: addiu       $v0, $t1, 0x8
    ctx->r2 = ADD32(ctx->r9, 0X8);
    // 0x806E6728: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x806E672C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x806E6730: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x806E6734: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x806E6738: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E673C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806E6740: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x806E6744: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x806E6748: lwc1        $f16, 0x40($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E674C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x806E6750: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x806E6754: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x806E6758: beq         $a3, $t0, L_806E67AC
    if (ctx->r7 == ctx->r8) {
        // 0x806E675C: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_806E67AC;
    }
    // 0x806E675C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_806E6760:
    // 0x806E6760: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x806E6764: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x806E6768: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x806E676C: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E6770: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x806E6774: lw          $a0, -0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0XC);
    // 0x806E6778: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E677C: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E6780: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x806E6784: lw          $a1, -0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X8);
    // 0x806E6788: lwc1        $f18, 0x40($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E678C: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E6790: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x806E6794: lw          $a2, -0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X4);
    // 0x806E6798: lwc1        $f18, 0x40($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X40);
    // 0x806E679C: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E67A0: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
    // 0x806E67A4: bne         $a3, $t0, L_806E6760
    if (ctx->r7 != ctx->r8) {
        // 0x806E67A8: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_806E6760;
    }
    // 0x806E67A8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_806E67AC:
    // 0x806E67AC: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x806E67B0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x806E67B4: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E67B8: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x806E67BC: lw          $a0, -0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0XC);
    // 0x806E67C0: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E67C4: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E67C8: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x806E67CC: lw          $a1, -0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X8);
    // 0x806E67D0: lwc1        $f18, 0x40($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X40);
    // 0x806E67D4: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E67D8: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x806E67DC: lw          $a2, -0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X4);
    // 0x806E67E0: lwc1        $f18, 0x40($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X40);
    // 0x806E67E4: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806E67E8: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
    // 0x806E67EC: lwc1        $f8, 0x40($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X40);
    // 0x806E67F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806E67F4: swc1        $f10, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f10.u32l;
    // 0x806E67F8: lw          $t7, 0x3C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X3C);
L_806E67FC:
    // 0x806E67FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806E6800: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806E6804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806E6808: bne         $t7, $at, L_806E6840
    if (ctx->r15 != ctx->r1) {
        // 0x806E680C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806E6840;
    }
    // 0x806E680C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E6810: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x806E6814: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806E6818: lwc1        $f2, 0x34($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X34);
    // 0x806E681C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806E6820: nop

    // 0x806E6824: bc1fl       L_806E683C
    if (!c1cs) {
        // 0x806E6828: sh          $zero, 0x2E($t1)
        MEM_H(0X2E, ctx->r9) = 0;
            goto L_806E683C;
    }
    goto skip_1;
    // 0x806E6828: sh          $zero, 0x2E($t1)
    MEM_H(0X2E, ctx->r9) = 0;
    skip_1:
    // 0x806E682C: add.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x806E6830: b           L_806E6840
    // 0x806E6834: swc1        $f16, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f16.u32l;
        goto L_806E6840;
    // 0x806E6834: swc1        $f16, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f16.u32l;
    // 0x806E6838: sh          $zero, 0x2E($t1)
    MEM_H(0X2E, ctx->r9) = 0;
L_806E683C:
    // 0x806E683C: swc1        $f12, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f12.u32l;
L_806E6840:
    // 0x806E6840: jal         0x806E5FB0
    // 0x806E6844: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_806E5FB0(rdram, ctx);
        goto after_1;
    // 0x806E6844: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_1:
    // 0x806E6848: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806E684C: jal         0x80048F84
    // 0x806E6850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x806E6850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x806E6854: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x806E6858: lw          $t8, 0x44($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X44);
    // 0x806E685C: bnel        $t8, $zero, L_806E6870
    if (ctx->r24 != 0) {
        // 0x806E6860: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E6870;
    }
    goto skip_2;
    // 0x806E6860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806E6864: jal         0x806E5DA8
    // 0x806E6868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E5DA8(rdram, ctx);
        goto after_3;
    // 0x806E6868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E686C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E6870:
    // 0x806E6870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E6874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806E6878: jr          $ra
    // 0x806E687C: nop

    return;
    // 0x806E687C: nop

;}
RECOMP_FUNC void Fault_LogFPCSR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB6C: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8006FB70: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8006FB74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006FB78: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_8006FB7C:
    // 0x8006FB7C: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8006FB80: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006FB84: bne         $t9, $sp, L_8006FB7C
    if (ctx->r25 != ctx->r29) {
        // 0x8006FB88: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_8006FB7C;
    }
    // 0x8006FB88: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006FB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FB90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006FB94: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8006FB98: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006FB9C: addiu       $a0, $a0, 0x13F4
    ctx->r4 = ADD32(ctx->r4, 0X13F4);
    // 0x8006FBA0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8006FBA4: jal         0x8008AD5C
    // 0x8006FBA8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    osSyncPrintf(rdram, ctx);
        goto after_0;
    // 0x8006FBA8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006FBAC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8006FBB0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8006FBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006FBB8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_8006FBBC:
    // 0x8006FBBC: and         $t6, $a1, $v1
    ctx->r14 = ctx->r5 & ctx->r3;
    // 0x8006FBC0: beq         $t6, $zero, L_8006FBE8
    if (ctx->r14 == 0) {
        // 0x8006FBC4: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8006FBE8;
    }
    // 0x8006FBC4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006FBC8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8006FBCC: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8006FBD0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006FBD4: addiu       $a0, $a0, 0x1404
    ctx->r4 = ADD32(ctx->r4, 0X1404);
    // 0x8006FBD8: jal         0x8008AD5C
    // 0x8006FBDC: lw          $a1, -0x7BAC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BAC);
    osSyncPrintf(rdram, ctx);
        goto after_1;
    // 0x8006FBDC: lw          $a1, -0x7BAC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BAC);
    after_1:
    // 0x8006FBE0: b           L_8006FBF8
    // 0x8006FBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006FBF8;
    // 0x8006FBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006FBE8:
    // 0x8006FBE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006FBEC: bne         $v0, $a0, L_8006FBBC
    if (ctx->r2 != ctx->r4) {
        // 0x8006FBF0: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_8006FBBC;
    }
    // 0x8006FBF0: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8006FBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006FBF8:
    // 0x8006FBF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006FBFC: jr          $ra
    // 0x8006FC00: nop

    return;
    // 0x8006FC00: nop

;}
RECOMP_FUNC void func_8057C658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C65C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057C664: jal         0x8057C6B0
    // 0x8057C668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8057C6B0(rdram, ctx);
        goto after_0;
    // 0x8057C668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8057C66C: jal         0x8057C5F8
    // 0x8057C670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057C5F8(rdram, ctx);
        goto after_1;
    // 0x8057C670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057C674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C67C: jr          $ra
    // 0x8057C680: nop

    return;
    // 0x8057C680: nop

;}
RECOMP_FUNC void func_804416CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804416CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804416D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804416D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804416D8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804416DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804416E0: jal         0x8043F33C
    // 0x804416E4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x804416E4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804416E8: jal         0x8043FBDC
    // 0x804416EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FBDC(rdram, ctx);
        goto after_1;
    // 0x804416EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804416F0: jal         0x8043F150
    // 0x804416F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x804416F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804416F8: jal         0x804400F0
    // 0x804416FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804400F0(rdram, ctx);
        goto after_3;
    // 0x804416FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80441700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441704: jal         0x8043EF80
    // 0x80441708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_4;
    // 0x80441708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8044170C: jal         0x8043F360
    // 0x80441710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_5;
    // 0x80441710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80441714: beq         $v0, $zero, L_8044176C
    if (ctx->r2 == 0) {
        // 0x80441718: nop
    
            goto L_8044176C;
    }
    // 0x80441718: nop

    // 0x8044171C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80441720: lw          $t7, 0x2628($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2628);
    // 0x80441724: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80441728: slti        $at, $t8, 0x5B
    ctx->r1 = SIGNED(ctx->r24) < 0X5B ? 1 : 0;
    // 0x8044172C: bne         $at, $zero, L_80441744
    if (ctx->r1 != 0) {
        // 0x80441730: sw          $t8, 0x2628($v0)
        MEM_W(0X2628, ctx->r2) = ctx->r24;
            goto L_80441744;
    }
    // 0x80441730: sw          $t8, 0x2628($v0)
    MEM_W(0X2628, ctx->r2) = ctx->r24;
    // 0x80441734: jal         0x8043F6F4
    // 0x80441738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F6F4(rdram, ctx);
        goto after_6;
    // 0x80441738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8044173C: b           L_80441778
    // 0x80441740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441778;
    // 0x80441740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441744:
    // 0x80441744: lw          $t0, 0x12C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X12C);
    // 0x80441748: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(95, 0X4CAC) << 16);
    // 0x8044174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441750: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80441754: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80441758: lw          $t9, 0x3BAC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(95, 0X4CAC));
    // 0x8044175C: jalr        $t9
    // 0x80441760: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80441760: nop

    after_7:
    // 0x80441764: b           L_80441778
    // 0x80441768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441778;
    // 0x80441768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044176C:
    // 0x8044176C: jal         0x8043F93C
    // 0x80441770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_8;
    // 0x80441770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80441774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441778:
    // 0x80441778: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8044177C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80441780: jr          $ra
    // 0x80441784: nop

    return;
    // 0x80441784: nop

;}
RECOMP_FUNC void func_800009AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800009AC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800009B0: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x800009B4: lh          $t6, 0x1D88($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X1D88);
    // 0x800009B8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800009BC: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800009C0: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800009C4: beq         $at, $zero, L_80000A18
    if (ctx->r1 == 0) {
        // 0x800009C8: nop
    
            goto L_80000A18;
    }
    // 0x800009C8: nop

    // 0x800009CC: lw          $t8, 0x1DAC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1DAC);
L_800009D0:
    // 0x800009D0: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x800009D4: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800009D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800009DC: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x800009E0: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x800009E4: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x800009E8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800009EC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800009F0: bltz        $t4, L_80000A18
    if (SIGNED(ctx->r12) < 0) {
        // 0x800009F4: nop
    
            goto L_80000A18;
    }
    // 0x800009F4: nop

    // 0x800009F8: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800009FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80000A00: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x80000A04: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80000A08: lh          $t8, 0x1D88($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1D88);
    // 0x80000A0C: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80000A10: bnel        $at, $zero, L_800009D0
    if (ctx->r1 != 0) {
        // 0x80000A14: lw          $t8, 0x1DAC($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X1DAC);
            goto L_800009D0;
    }
    goto skip_0;
    // 0x80000A14: lw          $t8, 0x1DAC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1DAC);
    skip_0:
L_80000A18:
    // 0x80000A18: jr          $ra
    // 0x80000A1C: nop

    return;
    // 0x80000A1C: nop

;}
RECOMP_FUNC void func_806E0398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E0398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E039C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806E03A0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806E03A4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806E03A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E03AC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806E03B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806E03B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806E03B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806E03BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806E03C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806E03C4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806E03C8: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(643, 0X1148) << 16);
    // 0x806E03CC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E03D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806E03D4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806E03D8: lw          $t2, 0x578($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(643, 0X1148));
    // 0x806E03DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806E03E0: jal         0x806DF624
    // 0x806E03E4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806DF624(rdram, ctx);
        goto after_0;
    // 0x806E03E4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806E03E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E03EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E03F0: jr          $ra
    // 0x806E03F4: nop

    return;
    // 0x806E03F4: nop

    // 0x806E03F8: nop

    // 0x806E03FC: nop

;}
RECOMP_FUNC void func_800232A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800232A8: lwc1        $f4, -0x300($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X300);
    // 0x800232AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800232B0: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x800232B4: lwc1        $f6, -0x2FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2FC);
    // 0x800232B8: jr          $ra
    // 0x800232BC: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x800232BC: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80798C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798C80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80798C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798C8C: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x80798C90: nop

    // 0x80798C94: bc1fl       L_80798CA8
    if (!c1cs) {
        // 0x80798C98: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_80798CA8;
    }
    goto skip_0;
    // 0x80798C98: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x80798C9C: b           L_80798CCC
    // 0x80798CA0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80798CCC;
    // 0x80798CA0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80798CA4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_80798CA8:
    // 0x80798CA8: jal         0x80065414
    // 0x80798CAC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x80798CAC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80798CB0: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80798CB4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80798CB8: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80798CBC: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80798CC0: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80798CC4: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80798CC8: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_80798CCC:
    // 0x80798CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80798CD4: jr          $ra
    // 0x80798CD8: nop

    return;
    // 0x80798CD8: nop

;}
RECOMP_FUNC void func_8001CD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD24: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8001CD28: addiu       $t6, $t6, -0x2904
    ctx->r14 = ADD32(ctx->r14, -0X2904);
    // 0x8001CD2C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8001CD30: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001CD34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001CD38: sw          $t6, -0x728C($at)
    MEM_W(-0X728C, ctx->r1) = ctx->r14;
    // 0x8001CD3C: jr          $ra
    // 0x8001CD40: addiu       $v0, $v0, -0x2A4C
    ctx->r2 = ADD32(ctx->r2, -0X2A4C);
    return;
    // 0x8001CD40: addiu       $v0, $v0, -0x2A4C
    ctx->r2 = ADD32(ctx->r2, -0X2A4C);
;}
RECOMP_FUNC void func_805A2ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A2AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A2AD4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805A2AD8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805A2ADC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805A2AE0: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(411, 0X1BB0) << 16);
    // 0x805A2AE4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A2AE8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805A2AEC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805A2AF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A2AF4: lw          $t8, 0x2F20($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(411, 0X1BB0));
    // 0x805A2AF8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805A2AFC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A2B00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A2B04: jal         0x80048490
    // 0x805A2B08: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805A2B08: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805A2B0C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805A2B10: jal         0x80048378
    // 0x805A2B14: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x805A2B14: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x805A2B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A2B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A2B20: jr          $ra
    // 0x805A2B24: nop

    return;
    // 0x805A2B24: nop

;}
RECOMP_FUNC void func_807A17A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A17A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A17A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A17AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A17B0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807A17B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A17B8: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x807A17BC: blez        $v0, L_807A17CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A17C0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807A17CC;
    }
    // 0x807A17C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A17C4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A17C8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807A17CC:
    // 0x807A17CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807A17D0: jal         0x807A0FFC
    // 0x807A17D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A17D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x807A17D8: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x807A17DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x807A17E0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XDA8) << 16);
    // 0x807A17E4: beq         $t7, $zero, L_807A1800
    if (ctx->r15 == 0) {
        // 0x807A17E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807A1800;
    }
    // 0x807A17E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A17EC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x807A17F0: lwc1        $f6, 0x1CE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XDA8));
    // 0x807A17F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807A17F8: b           L_807A180C
    // 0x807A17FC: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
        goto L_807A180C;
    // 0x807A17FC: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_807A1800:
    // 0x807A1800: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x807A1804: nop

    // 0x807A1808: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
L_807A180C:
    // 0x807A180C: jal         0x807A10CC
    // 0x807A1810: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_807A10CC(rdram, ctx);
        goto after_1;
    // 0x807A1810: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x807A1814: beq         $v0, $zero, L_807A1854
    if (ctx->r2 == 0) {
        // 0x807A1818: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_807A1854;
    }
    // 0x807A1818: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x807A181C: lw          $t8, 0x68($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X68);
    // 0x807A1820: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x807A1824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A1828: bne         $t8, $zero, L_807A184C
    if (ctx->r24 != 0) {
        // 0x807A182C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807A184C;
    }
    // 0x807A182C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A1834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1838: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x807A183C: jal         0x807A1AE4
    // 0x807A1840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807A1AE4(rdram, ctx);
        goto after_2;
    // 0x807A1840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x807A1844: b           L_807A1858
    // 0x807A1848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807A1858;
    // 0x807A1848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A184C:
    // 0x807A184C: jal         0x807A1AE4
    // 0x807A1850: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807A1AE4(rdram, ctx);
        goto after_3;
    // 0x807A1850: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_807A1854:
    // 0x807A1854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A1858:
    // 0x807A1858: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A185C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A1860: jr          $ra
    // 0x807A1864: nop

    return;
    // 0x807A1864: nop

;}
RECOMP_FUNC void func_804A2368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2368: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A236C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A2370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A2374: jal         0x804A2910
    // 0x804A2378: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A2378: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804A237C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804A2380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804A2384: jal         0x80048F84
    // 0x804A2388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804A2388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804A238C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x804A2390: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A2394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2398: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x804A239C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804A23A0: jal         0x804A2910
    // 0x804A23A4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    func_804A2910(rdram, ctx);
        goto after_2;
    // 0x804A23A4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x804A23A8: beq         $v0, $zero, L_804A23CC
    if (ctx->r2 == 0) {
        // 0x804A23AC: lui         $at, 0x804A
        ctx->r1 = S32(RELOC_HI16(173, 0X31A8) << 16);
            goto L_804A23CC;
    }
    // 0x804A23AC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X31A8) << 16);
    // 0x804A23B0: lwc1        $f10, 0x35E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X31A8));
    // 0x804A23B4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x804A23B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A23BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A23C0: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x804A23C4: jal         0x804A27A0
    // 0x804A23C8: swc1        $f10, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f10.u32l;
    func_804A27A0(rdram, ctx);
        goto after_3;
    // 0x804A23C8: swc1        $f10, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f10.u32l;
    after_3:
L_804A23CC:
    // 0x804A23CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A23D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A23D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804A23D8: jr          $ra
    // 0x804A23DC: nop

    return;
    // 0x804A23DC: nop

;}
RECOMP_FUNC void func_80010730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010730: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010734: sb          $zero, -0x6D80($at)
    MEM_B(-0X6D80, ctx->r1) = 0;
    // 0x80010738: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001073C: sb          $zero, -0x6D14($at)
    MEM_B(-0X6D14, ctx->r1) = 0;
    // 0x80010740: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80010744: lbu         $t6, -0x6DA0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6DA0);
    // 0x80010748: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001074C: sb          $zero, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = 0;
    // 0x80010750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010754: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001075C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80010760: beq         $t6, $zero, L_80010774
    if (ctx->r14 == 0) {
        // 0x80010764: sh          $zero, -0x6D74($at)
        MEM_H(-0X6D74, ctx->r1) = 0;
            goto L_80010774;
    }
    // 0x80010764: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    // 0x80010768: jal         0x80010688
    // 0x8001076C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80010688(rdram, ctx);
        goto after_0;
    // 0x8001076C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80010770: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_80010774:
    // 0x80010774: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80010778: lbu         $t7, -0x6D9C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6D9C);
    // 0x8001077C: beq         $t7, $zero, L_80010790
    if (ctx->r15 == 0) {
        // 0x80010780: nop
    
            goto L_80010790;
    }
    // 0x80010780: nop

    // 0x80010784: jal         0x800114E8
    // 0x80010788: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800114E8(rdram, ctx);
        goto after_1;
    // 0x80010788: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001078C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_80010790:
    // 0x80010790: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80010794: lbu         $t8, -0x6D7C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6D7C);
    // 0x80010798: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8001079C: beq         $t8, $zero, L_800107B0
    if (ctx->r24 == 0) {
        // 0x800107A0: nop
    
            goto L_800107B0;
    }
    // 0x800107A0: nop

    // 0x800107A4: jal         0x80010A74
    // 0x800107A8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80010A74(rdram, ctx);
        goto after_2;
    // 0x800107A8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x800107AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_800107B0:
    // 0x800107B0: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800107B4: lw          $t9, -0x6D30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6D30);
    // 0x800107B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800107BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800107C0: bne         $t9, $at, L_800107D4
    if (ctx->r25 != ctx->r1) {
        // 0x800107C4: nop
    
            goto L_800107D4;
    }
    // 0x800107C4: nop

    // 0x800107C8: jal         0x800186E0
    // 0x800107CC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800186E0(rdram, ctx);
        goto after_3;
    // 0x800107CC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x800107D0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_800107D4:
    // 0x800107D4: beq         $a1, $zero, L_8001082C
    if (ctx->r5 == 0) {
        // 0x800107D8: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_8001082C;
    }
    // 0x800107D8: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800107DC: beq         $a1, $at, L_8001083C
    if (ctx->r5 == ctx->r1) {
        // 0x800107E0: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8001083C;
    }
    // 0x800107E0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800107E4: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800107E8: beq         $a1, $at, L_8001083C
    if (ctx->r5 == ctx->r1) {
        // 0x800107EC: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_8001083C;
    }
    // 0x800107EC: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x800107F0: beq         $a1, $at, L_80010848
    if (ctx->r5 == ctx->r1) {
        // 0x800107F4: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_80010848;
    }
    // 0x800107F4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800107F8: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800107FC: beq         $a1, $at, L_8001080C
    if (ctx->r5 == ctx->r1) {
        // 0x80010800: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_8001080C;
    }
    // 0x80010800: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010804: b           L_80010850
    // 0x80010808: sh          $zero, -0x6D8C($at)
    MEM_H(-0X6D8C, ctx->r1) = 0;
        goto L_80010850;
    // 0x80010808: sh          $zero, -0x6D8C($at)
    MEM_H(-0X6D8C, ctx->r1) = 0;
L_8001080C:
    // 0x8001080C: jal         0x80018F90
    // 0x80010810: nop

    func_80018F90(rdram, ctx);
        goto after_4;
    // 0x80010810: nop

    after_4:
    // 0x80010814: jal         0x80011360
    // 0x80010818: nop

    func_80011360(rdram, ctx);
        goto after_5;
    // 0x80010818: nop

    after_5:
    // 0x8001081C: jal         0x80011A1C
    // 0x80010820: nop

    func_80011A1C(rdram, ctx);
        goto after_6;
    // 0x80010820: nop

    after_6:
    // 0x80010824: b           L_800109D0
    // 0x80010828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800109D0;
    // 0x80010828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001082C:
    // 0x8001082C: jal         0x80011C64
    // 0x80010830: nop

    func_80011C64(rdram, ctx);
        goto after_7;
    // 0x80010830: nop

    after_7:
    // 0x80010834: b           L_800109D0
    // 0x80010838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800109D0;
    // 0x80010838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001083C:
    // 0x8001083C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010840: b           L_80010850
    // 0x80010844: sh          $t0, -0x6D8C($at)
    MEM_H(-0X6D8C, ctx->r1) = ctx->r8;
        goto L_80010850;
    // 0x80010844: sh          $t0, -0x6D8C($at)
    MEM_H(-0X6D8C, ctx->r1) = ctx->r8;
L_80010848:
    // 0x80010848: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001084C: sh          $t1, -0x6D8C($at)
    MEM_H(-0X6D8C, ctx->r1) = ctx->r9;
L_80010850:
    // 0x80010850: jal         0x80011C3C
    // 0x80010854: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80011C3C(rdram, ctx);
        goto after_8;
    // 0x80010854: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_8:
    // 0x80010858: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001085C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010860: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80010864: sh          $a1, -0x6D90($at)
    MEM_H(-0X6D90, ctx->r1) = ctx->r5;
    // 0x80010868: lh          $t2, -0x6D90($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6D90);
    // 0x8001086C: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80010870: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010874: bne         $t2, $at, L_800108C8
    if (ctx->r10 != ctx->r1) {
        // 0x80010878: nop
    
            goto L_800108C8;
    }
    // 0x80010878: nop

    // 0x8001087C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010880: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80010884: sh          $t3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r11;
    // 0x80010888: beq         $a0, $zero, L_800108D8
    if (ctx->r4 == 0) {
        // 0x8001088C: nop
    
            goto L_800108D8;
    }
    // 0x8001088C: nop

    // 0x80010890: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x80010894: addiu       $t5, $t4, -0x10
    ctx->r13 = ADD32(ctx->r12, -0X10);
    // 0x80010898: sltiu       $at, $t5, 0x1F
    ctx->r1 = ctx->r13 < 0X1F ? 1 : 0;
    // 0x8001089C: beq         $at, $zero, L_800108D8
    if (ctx->r1 == 0) {
        // 0x800108A0: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800108D8;
    }
    // 0x800108A0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800108A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800108A8: addu        $at, $at, $t5
    gpr jr_addend_800108B0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800108AC: lw          $t5, -0x3B58($at)
    ctx->r13 = ADD32(ctx->r1, -0X3B58);
    // 0x800108B0: jr          $t5
    // 0x800108B4: nop

    switch (jr_addend_800108B0 >> 2) {
        case 0: goto L_800108B8; break;
        case 1: goto L_800108D8; break;
        case 2: goto L_800108B8; break;
        case 3: goto L_800108B8; break;
        case 4: goto L_800108D8; break;
        case 5: goto L_800108D8; break;
        case 6: goto L_800108B8; break;
        case 7: goto L_800108B8; break;
        case 8: goto L_800108D8; break;
        case 9: goto L_800108B8; break;
        case 10: goto L_800108D8; break;
        case 11: goto L_800108D8; break;
        case 12: goto L_800108D8; break;
        case 13: goto L_800108D8; break;
        case 14: goto L_800108D8; break;
        case 15: goto L_800108D8; break;
        case 16: goto L_800108D8; break;
        case 17: goto L_800108D8; break;
        case 18: goto L_800108D8; break;
        case 19: goto L_800108D8; break;
        case 20: goto L_800108D8; break;
        case 21: goto L_800108D8; break;
        case 22: goto L_800108D8; break;
        case 23: goto L_800108D8; break;
        case 24: goto L_800108D8; break;
        case 25: goto L_800108D8; break;
        case 26: goto L_800108D8; break;
        case 27: goto L_800108D8; break;
        case 28: goto L_800108D8; break;
        case 29: goto L_800108D8; break;
        case 30: goto L_800108B8; break;
        default: switch_error(__func__, 0x800108B0, 0x800AC4A8);
    }
    // 0x800108B4: nop

L_800108B8:
    // 0x800108B8: jal         0x80010A74
    // 0x800108BC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80010A74(rdram, ctx);
        goto after_9;
    // 0x800108BC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_9:
    // 0x800108C0: b           L_800109D0
    // 0x800108C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800109D0;
    // 0x800108C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800108C8:
    // 0x800108C8: jal         0x800116C4
    // 0x800108CC: nop

    func_800116C4(rdram, ctx);
        goto after_10;
    // 0x800108CC: nop

    after_10:
    // 0x800108D0: bltz        $v0, L_800109CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800108D4: sh          $v0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r2;
            goto L_800109CC;
    }
    // 0x800108D4: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_800108D8:
    // 0x800108D8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800108DC: lh          $t6, -0x6D8C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6D8C);
    // 0x800108E0: beq         $t6, $zero, L_80010900
    if (ctx->r14 == 0) {
        // 0x800108E4: nop
    
            goto L_80010900;
    }
    // 0x800108E4: nop

    // 0x800108E8: jal         0x80019040
    // 0x800108EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80019040(rdram, ctx);
        goto after_11;
    // 0x800108EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_11:
    // 0x800108F0: jal         0x80011A1C
    // 0x800108F4: nop

    func_80011A1C(rdram, ctx);
        goto after_12;
    // 0x800108F4: nop

    after_12:
    // 0x800108F8: jal         0x80011360
    // 0x800108FC: nop

    func_80011360(rdram, ctx);
        goto after_13;
    // 0x800108FC: nop

    after_13:
L_80010900:
    // 0x80010900: jal         0x80011400
    // 0x80010904: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80011400(rdram, ctx);
        goto after_14;
    // 0x80010904: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80010908: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x8001090C: jal         0x80011600
    // 0x80010910: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80011600(rdram, ctx);
        goto after_15;
    // 0x80010910: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_15:
    // 0x80010914: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010918: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x8001091C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80010920: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010924: beq         $a0, $zero, L_80010930
    if (ctx->r4 == 0) {
        // 0x80010928: nop
    
            goto L_80010930;
    }
    // 0x80010928: nop

    // 0x8001092C: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
L_80010930:
    // 0x80010930: lh          $v0, -0x6D90($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6D90);
    // 0x80010934: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80010938: bnel        $v0, $at, L_80010964
    if (ctx->r2 != ctx->r1) {
        // 0x8001093C: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80010964;
    }
    goto skip_0;
    // 0x8001093C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_0:
    // 0x80010940: jal         0x80018EF4
    // 0x80010944: nop

    func_80018EF4(rdram, ctx);
        goto after_16;
    // 0x80010944: nop

    after_16:
    // 0x80010948: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001094C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010950: jal         0x8001AE64
    // 0x80010954: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    func_8001AE64(rdram, ctx);
        goto after_17;
    // 0x80010954: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_17:
    // 0x80010958: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001095C: lh          $v0, -0x6D90($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6D90);
    // 0x80010960: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
L_80010964:
    // 0x80010964: bne         $v0, $at, L_800109CC
    if (ctx->r2 != ctx->r1) {
        // 0x80010968: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800109CC;
    }
    // 0x80010968: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001096C: lh          $v0, -0x6D10($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6D10);
    // 0x80010970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010974: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010978: beq         $v0, $at, L_800109CC
    if (ctx->r2 == ctx->r1) {
        // 0x8001097C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800109CC;
    }
    // 0x8001097C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010980: beq         $v0, $at, L_800109A4
    if (ctx->r2 == ctx->r1) {
        // 0x80010984: lw          $a0, -0x6D70($a0)
        ctx->r4 = MEM_W(ctx->r4, -0X6D70);
            goto L_800109A4;
    }
    // 0x80010984: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001098C: beq         $v0, $at, L_800109B4
    if (ctx->r2 == ctx->r1) {
        // 0x80010990: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800109B4;
    }
    // 0x80010990: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80010994: beq         $v0, $at, L_800109C4
    if (ctx->r2 == ctx->r1) {
        // 0x80010998: nop
    
            goto L_800109C4;
    }
    // 0x80010998: nop

    // 0x8001099C: b           L_800109C4
    // 0x800109A0: nop

        goto L_800109C4;
    // 0x800109A0: nop

L_800109A4:
    // 0x800109A4: jal         0x8001AE64
    // 0x800109A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8001AE64(rdram, ctx);
        goto after_18;
    // 0x800109A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x800109AC: b           L_800109D0
    // 0x800109B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800109D0;
    // 0x800109B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800109B4:
    // 0x800109B4: jal         0x8001AE64
    // 0x800109B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8001AE64(rdram, ctx);
        goto after_19;
    // 0x800109B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_19:
    // 0x800109BC: b           L_800109D0
    // 0x800109C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800109D0;
    // 0x800109C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800109C4:
    // 0x800109C4: jal         0x8001AE64
    // 0x800109C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8001AE64(rdram, ctx);
        goto after_20;
    // 0x800109C8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_20:
L_800109CC:
    // 0x800109CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800109D0:
    // 0x800109D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800109D4: jr          $ra
    // 0x800109D8: nop

    return;
    // 0x800109D8: nop

;}
RECOMP_FUNC void func_80527CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527CE0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80527CE4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80527CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80527CEC: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80527CF4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80527CF8: nop

    // 0x80527CFC: bc1fl       L_80527D4C
    if (!c1cs) {
        // 0x80527D00: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80527D4C;
    }
    goto skip_0;
    // 0x80527D00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80527D04: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527D08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527D0C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80527D10: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527D14: blez        $v0, L_80527D2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80527D18: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80527D2C;
    }
    // 0x80527D18: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80527D1C: jal         0x80527038
    // 0x80527D20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80527038(rdram, ctx);
        goto after_0;
    // 0x80527D20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80527D24: b           L_80527D5C
    // 0x80527D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527D5C;
    // 0x80527D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527D2C:
    // 0x80527D2C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80527D30: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80527D34: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80527D38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80527D3C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80527D40: b           L_80527D58
    // 0x80527D44: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527D58;
    // 0x80527D44: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80527D48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80527D4C:
    // 0x80527D4C: nop

    // 0x80527D50: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80527D54: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_80527D58:
    // 0x80527D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527D5C:
    // 0x80527D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527D60: jr          $ra
    // 0x80527D64: nop

    return;
    // 0x80527D64: nop

;}
RECOMP_FUNC void func_806F2DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2DE4: jal         0x806F2D54
    // 0x806F2DE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F2D54(rdram, ctx);
        goto after_0;
    // 0x806F2DE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F2DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F2DF0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(679, 0X1B94) << 16);
    // 0x806F2DF4: addiu       $t6, $t6, 0x3114
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(679, 0X1B94));
    // 0x806F2DF8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806F2DFC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806F2E00: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F2E04: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806F2E08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2E0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F2E10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806F2E14: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F2E18: jal         0x806F2E38
    // 0x806F2E1C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    func_806F2E38(rdram, ctx);
        goto after_1;
    // 0x806F2E1C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    after_1:
    // 0x806F2E20: jal         0x806F2D6C
    // 0x806F2E24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F2D6C(rdram, ctx);
        goto after_2;
    // 0x806F2E24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806F2E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2E30: jr          $ra
    // 0x806F2E34: nop

    return;
    // 0x806F2E34: nop

;}
RECOMP_FUNC void func_804A1C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1C80: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x804A1C84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804A1C88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A1C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1C90: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x804A1C94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1C98: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804A1C9C: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A1CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1CA4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1CA8: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x804A1CAC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x804A1CB0: nop

    // 0x804A1CB4: bc1fl       L_804A1CC8
    if (!c1cs) {
        // 0x804A1CB8: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_804A1CC8;
    }
    goto skip_0;
    // 0x804A1CB8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x804A1CBC: b           L_804A1D08
    // 0x804A1CC0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
        goto L_804A1D08;
    // 0x804A1CC0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x804A1CC4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_804A1CC8:
    // 0x804A1CC8: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x804A1CCC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x804A1CD0: jal         0x804A1320
    // 0x804A1CD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804A1320(rdram, ctx);
        goto after_0;
    // 0x804A1CD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1CD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804A1CDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804A1CE0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804A1CE4: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x804A1CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804A1CEC: bc1tl       L_804A1D08
    if (c1cs) {
        // 0x804A1CF0: swc1        $f2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
            goto L_804A1D08;
    }
    goto skip_1;
    // 0x804A1CF0: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x804A1CF4: add.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x804A1CF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1CFC: b           L_804A1D08
    // 0x804A1D00: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
        goto L_804A1D08;
    // 0x804A1D00: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x804A1D04: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
L_804A1D08:
    // 0x804A1D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A1D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A1D10: jr          $ra
    // 0x804A1D14: nop

    return;
    // 0x804A1D14: nop

;}
RECOMP_FUNC void func_8041D9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D9B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041D9B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041D9BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041D9C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8041D9C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8041D9C8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8041D9CC: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8041D9D0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8041D9D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8041D9D8: bnel        $t6, $at, L_8041D9F4
    if (ctx->r14 != ctx->r1) {
        // 0x8041D9DC: lhu         $t7, 0xC($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0XC);
            goto L_8041D9F4;
    }
    goto skip_0;
    // 0x8041D9DC: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    skip_0:
    // 0x8041D9E0: jal         0x8041D8D4
    // 0x8041D9E4: nop

    func_8041D8D4(rdram, ctx);
        goto after_0;
    // 0x8041D9E4: nop

    after_0:
    // 0x8041D9E8: b           L_8041DA8C
    // 0x8041D9EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041DA8C;
    // 0x8041D9EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041D9F0: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
L_8041D9F4:
    // 0x8041D9F4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8041D9F8: bnel        $t7, $at, L_8041DA8C
    if (ctx->r15 != ctx->r1) {
        // 0x8041D9FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041DA8C;
    }
    goto skip_1;
    // 0x8041D9FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8041DA00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041DA04: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8041DA08: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8041DA0C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8041DA10: nop

    // 0x8041DA14: bc1fl       L_8041DA78
    if (!c1cs) {
        // 0x8041DA18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041DA78;
    }
    goto skip_2;
    // 0x8041DA18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8041DA1C: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8041DA20: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8041DA24: nop

    // 0x8041DA28: bc1fl       L_8041DA78
    if (!c1cs) {
        // 0x8041DA2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041DA78;
    }
    goto skip_3;
    // 0x8041DA2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8041DA30: jal         0x80065954
    // 0x8041DA34: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8041DA34: nop

    after_1:
    // 0x8041DA38: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8041DA3C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8041DA40: jal         0x80065954
    // 0x8041DA44: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8041DA44: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    after_2:
    // 0x8041DA48: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8041DA4C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8041DA50: nop

    // 0x8041DA54: bc1fl       L_8041DA78
    if (!c1cs) {
        // 0x8041DA58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041DA78;
    }
    goto skip_4;
    // 0x8041DA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8041DA5C: jal         0x8002F92C
    // 0x8041DA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F92C(rdram, ctx);
        goto after_3;
    // 0x8041DA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041DA64: jal         0x8041D8D4
    // 0x8041DA68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8041D8D4(rdram, ctx);
        goto after_4;
    // 0x8041DA68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8041DA6C: b           L_8041DA8C
    // 0x8041DA70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041DA8C;
    // 0x8041DA70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041DA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8041DA78:
    // 0x8041DA78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8041DA7C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8041DA80: jal         0x8002F6E4
    // 0x8041DA84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_5;
    // 0x8041DA84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8041DA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041DA8C:
    // 0x8041DA8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041DA90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8041DA94: jr          $ra
    // 0x8041DA98: nop

    return;
    // 0x8041DA98: nop

;}
RECOMP_FUNC void func_8046BE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BE28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046BE2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046BE30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046BE34: jal         0x8046BD28
    // 0x8046BE38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8046BD28(rdram, ctx);
        goto after_0;
    // 0x8046BE38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046BE3C: bne         $v0, $zero, L_8046BE54
    if (ctx->r2 != 0) {
        // 0x8046BE40: lui         $t6, 0x8047
        ctx->r14 = S32(RELOC_HI16(138, 0X28D0) << 16);
            goto L_8046BE54;
    }
    // 0x8046BE40: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(138, 0X28D0) << 16);
    // 0x8046BE44: jal         0x800445A4
    // 0x8046BE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8046BE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046BE4C: b           L_8046BEA8
    // 0x8046BE50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046BEA8;
    // 0x8046BE50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046BE54:
    // 0x8046BE54: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8046BE58: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8046BE5C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8046BE60: addiu       $t6, $t6, -0x3FF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(138, 0X28D0));
    // 0x8046BE64: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8046BE68: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8046BE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046BE70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046BE74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8046BE78: jal         0x8046BEB8
    // 0x8046BE7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046BEB8(rdram, ctx);
        goto after_2;
    // 0x8046BE7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8046BE80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8046BE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8046BE88: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8046BE8C: jal         0x8046BD6C
    // 0x8046BE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046BD6C(rdram, ctx);
        goto after_3;
    // 0x8046BE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046BE94: bnel        $v0, $zero, L_8046BEA8
    if (ctx->r2 != 0) {
        // 0x8046BE98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046BEA8;
    }
    goto skip_0;
    // 0x8046BE98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8046BE9C: jal         0x800445A4
    // 0x8046BEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8046BEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8046BEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046BEA8:
    // 0x8046BEA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046BEAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046BEB0: jr          $ra
    // 0x8046BEB4: nop

    return;
    // 0x8046BEB4: nop

;}
RECOMP_FUNC void func_8073D1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D1D0: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(745, 0X28) << 16);
    // 0x8073D1D4: addiu       $v0, $v0, -0x2E08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(745, 0X28));
    // 0x8073D1D8: jr          $ra
    // 0x8073D1DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073D1DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80006EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006EB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80006EB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006EBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006EC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80006EC4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80006EC8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80006ECC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80006ED0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006ED4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80006ED8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80006EDC: jal         0x800073BC
    // 0x80006EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006EE4: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80006EE8: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80006EEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80006EF0: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80006EF4: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80006EF8: addiu       $s3, $s3, 0x4D10
    ctx->r19 = ADD32(ctx->r19, 0X4D10);
    // 0x80006EFC: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80006F00: addu        $s4, $s3, $t6
    ctx->r20 = ADD32(ctx->r19, ctx->r14);
    // 0x80006F04: addiu       $s4, $s4, 0x2A30
    ctx->r20 = ADD32(ctx->r20, 0X2A30);
    // 0x80006F08: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80006F0C: jal         0x8000DAE8
    // 0x80006F10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8000DAE8(rdram, ctx);
        goto after_1;
    // 0x80006F10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80006F14: lw          $v0, 0x1D70($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1D70);
    // 0x80006F18: sll         $t7, $s5, 1
    ctx->r15 = S32(ctx->r21 << 1);
    // 0x80006F1C: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x80006F20: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80006F24: lhu         $s0, 0x0($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X0);
    // 0x80006F28: addu        $t9, $s0, $v0
    ctx->r25 = ADD32(ctx->r16, ctx->r2);
    // 0x80006F2C: lbu         $s1, 0x0($t9)
    ctx->r17 = MEM_BU(ctx->r25, 0X0);
    // 0x80006F30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006F34: blez        $s1, L_80006F60
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80006F38: nop
    
            goto L_80006F60;
    }
    // 0x80006F38: nop

    // 0x80006F3C: lw          $t0, 0x1D70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1D70);
L_80006F40:
    // 0x80006F40: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80006F44: lbu         $s2, 0x0($t1)
    ctx->r18 = MEM_BU(ctx->r9, 0X0);
    // 0x80006F48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80006F4C: jal         0x800070EC
    // 0x80006F50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800070EC(rdram, ctx);
        goto after_2;
    // 0x80006F50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80006F54: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80006F58: bgtzl       $s1, L_80006F40
    if (SIGNED(ctx->r17) > 0) {
        // 0x80006F5C: lw          $t0, 0x1D70($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X1D70);
            goto L_80006F40;
    }
    goto skip_0;
    // 0x80006F5C: lw          $t0, 0x1D70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1D70);
    skip_0:
L_80006F60:
    // 0x80006F60: jal         0x80006FE0
    // 0x80006F64: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80006FE0(rdram, ctx);
        goto after_3;
    // 0x80006F64: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x80006F68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80006F6C: jal         0x80010230
    // 0x80006F70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80010230(rdram, ctx);
        goto after_4;
    // 0x80006F70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80006F74: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x80006F78: sb          $s5, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r21;
    // 0x80006F7C: sb          $s2, 0x5($s4)
    MEM_B(0X5, ctx->r20) = ctx->r18;
    // 0x80006F80: ori         $t5, $t3, 0x80
    ctx->r13 = ctx->r11 | 0X80;
    // 0x80006F84: sb          $t5, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r13;
    // 0x80006F88: andi        $t6, $t5, 0xBF
    ctx->r14 = ctx->r13 & 0XBF;
    // 0x80006F8C: sw          $s0, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r16;
    // 0x80006F90: sw          $s0, 0x74($s4)
    MEM_W(0X74, ctx->r20) = ctx->r16;
    // 0x80006F94: sb          $zero, 0x8C($s4)
    MEM_B(0X8C, ctx->r20) = 0;
    // 0x80006F98: sh          $zero, 0x10($s4)
    MEM_H(0X10, ctx->r20) = 0;
    // 0x80006F9C: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    // 0x80006FA0: jal         0x800101E0
    // 0x80006FA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800101E0(rdram, ctx);
        goto after_5;
    // 0x80006FA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80006FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006FAC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80006FB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80006FB4:
    // 0x80006FB4: bnel        $v0, $v1, L_80006FB4
    if (ctx->r2 != ctx->r3) {
        // 0x80006FB8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80006FB4;
    }
    goto skip_1;
    // 0x80006FB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x80006FBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80006FC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80006FC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80006FC8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80006FCC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80006FD0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80006FD4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80006FD8: jr          $ra
    // 0x80006FDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80006FDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8044625C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044625C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80446260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446264: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446268: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x8044626C: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446270: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446274: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80446278: sw          $a1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r5;
    // 0x8044627C: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x80446280: sw          $t6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r14;
    // 0x80446284: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446288: sw          $t7, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->r15;
    // 0x8044628C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131E0) << 16);
    // 0x80446290: lw          $v1, 0x75C0($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131E0));
    // 0x80446294: beql        $v1, $zero, L_804462A8
    if (ctx->r3 == 0) {
        // 0x80446298: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804462A8;
    }
    goto skip_0;
    // 0x80446298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044629C: jalr        $v1
    // 0x804462A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804462A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x804462A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804462A8:
    // 0x804462A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804462AC: jr          $ra
    // 0x804462B0: nop

    return;
    // 0x804462B0: nop

;}
RECOMP_FUNC void func_8073C5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C5D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8073C5D8: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(742, 0XF78) << 16);
    // 0x8073C5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073C5E0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8073C5E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8073C5E8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8073C5EC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8073C5F0: addiu       $t8, $t8, -0x2F28
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(742, 0XF78));
    // 0x8073C5F4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8073C5F8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073C5FC: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x8073C600: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8073C604: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8073C608: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8073C60C: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    // 0x8073C610: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x8073C614: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8073C618: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8073C61C: lhu         $v0, 0xC($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0XC);
    // 0x8073C620: beq         $a2, $v0, L_8073C638
    if (ctx->r6 == ctx->r2) {
        // 0x8073C624: nop
    
            goto L_8073C638;
    }
    // 0x8073C624: nop

    // 0x8073C628: lbu         $t2, 0x18($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X18);
    // 0x8073C62C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8073C630: bnel        $t2, $at, L_8073C6BC
    if (ctx->r10 != ctx->r1) {
        // 0x8073C634: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073C6BC;
    }
    goto skip_0;
    // 0x8073C634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8073C638:
    // 0x8073C638: bnel        $a2, $v0, L_8073C6BC
    if (ctx->r6 != ctx->r2) {
        // 0x8073C63C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073C6BC;
    }
    goto skip_1;
    // 0x8073C63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8073C640: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8073C644: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8073C648: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8073C64C: bne         $t3, $zero, L_8073C6B8
    if (ctx->r11 != 0) {
        // 0x8073C650: lui         $a1, 0x8074
        ctx->r5 = S32(RELOC_HI16(742, 0XF70) << 16);
            goto L_8073C6B8;
    }
    // 0x8073C650: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(742, 0XF70) << 16);
    // 0x8073C654: lw          $t5, 0x138($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X138);
    // 0x8073C658: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8073C65C: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    // 0x8073C660: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8073C664: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8073C668: lw          $a1, -0x2F30($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(742, 0XF70));
    // 0x8073C66C: jal         0x8002F96C
    // 0x8073C670: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_0;
    // 0x8073C670: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x8073C674: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8073C678: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073C67C: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x8073C680: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073C684: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8073C688: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8073C68C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x8073C690: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8073C694: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8073C698: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8073C69C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x8073C6A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8073C6A4: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x8073C6A8: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8073C6AC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8073C6B0: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8073C6B4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
L_8073C6B8:
    // 0x8073C6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073C6BC:
    // 0x8073C6BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8073C6C0: jr          $ra
    // 0x8073C6C4: nop

    return;
    // 0x8073C6C4: nop

;}
RECOMP_FUNC void func_806AB28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB28C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806AB290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AB294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AB298: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x806AB29C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AB2A0: jal         0x8004700C
    // 0x806AB2A4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806AB2A4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x806AB2A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x806AB2AC: beq         $a1, $zero, L_806AB350
    if (ctx->r5 == 0) {
        // 0x806AB2B0: nop
    
            goto L_806AB350;
    }
    // 0x806AB2B0: nop

    // 0x806AB2B4: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x806AB2B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806AB2BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806AB2C0: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x806AB2C4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806AB2C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806AB2CC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806AB2D0: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806AB2D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AB2D8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806AB2DC: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806AB2E0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x806AB2E4: nop

    // 0x806AB2E8: bc1f        L_806AB30C
    if (!c1cs) {
        // 0x806AB2EC: nop
    
            goto L_806AB30C;
    }
    // 0x806AB2EC: nop

    // 0x806AB2F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806AB2F4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB2F8: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x806AB2FC: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x806AB300: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x806AB304: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x806AB308: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_806AB30C:
    // 0x806AB30C: beq         $v0, $zero, L_806AB350
    if (ctx->r2 == 0) {
        // 0x806AB310: nop
    
            goto L_806AB350;
    }
    // 0x806AB310: nop

    // 0x806AB314: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x806AB318: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x806AB31C: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x806AB320: beq         $t2, $zero, L_806AB350
    if (ctx->r10 == 0) {
        // 0x806AB324: nop
    
            goto L_806AB350;
    }
    // 0x806AB324: nop

    // 0x806AB328: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x806AB32C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806AB330: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806AB334: nop

    // 0x806AB338: bc1f        L_806AB350
    if (!c1cs) {
        // 0x806AB33C: nop
    
            goto L_806AB350;
    }
    // 0x806AB33C: nop

    // 0x806AB340: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB344: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x806AB348: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x806AB34C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_806AB350:
    // 0x806AB350: jal         0x806AB0A0
    // 0x806AB354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AB0A0(rdram, ctx);
        goto after_1;
    // 0x806AB354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806AB358: beql        $v0, $zero, L_806AB3B8
    if (ctx->r2 == 0) {
        // 0x806AB35C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AB3B8;
    }
    goto skip_0;
    // 0x806AB35C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806AB360: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AB368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AB36C: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x806AB370: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806AB374: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806AB378: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x806AB37C: beq         $t8, $zero, L_806AB3B4
    if (ctx->r24 == 0) {
        // 0x806AB380: addiu       $t9, $s0, 0xC4
        ctx->r25 = ADD32(ctx->r16, 0XC4);
            goto L_806AB3B4;
    }
    // 0x806AB380: addiu       $t9, $s0, 0xC4
    ctx->r25 = ADD32(ctx->r16, 0XC4);
    // 0x806AB384: jal         0x806AB72C
    // 0x806AB388: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_806AB72C(rdram, ctx);
        goto after_2;
    // 0x806AB388: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_2:
    // 0x806AB38C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806AB390: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x806AB394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AB398: addiu       $a1, $zero, 0x270
    ctx->r5 = ADD32(0, 0X270);
    // 0x806AB39C: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x806AB3A0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB3A4: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x806AB3A8: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x806AB3AC: jal         0x806AAC54
    // 0x806AB3B0: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    func_806AAC54(rdram, ctx);
        goto after_3;
    // 0x806AB3B0: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    after_3:
L_806AB3B4:
    // 0x806AB3B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AB3B8:
    // 0x806AB3B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AB3BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806AB3C0: jr          $ra
    // 0x806AB3C4: nop

    return;
    // 0x806AB3C4: nop

;}
RECOMP_FUNC void func_8005FA48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FA48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FA4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FA50: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FA54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FA58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FA5C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FA60: lbu         $t7, 0x76($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X76);
    // 0x8005FA64: bnel        $t7, $zero, L_8005FA88
    if (ctx->r15 != 0) {
        // 0x8005FA68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FA88;
    }
    goto skip_0;
    // 0x8005FA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FA6C: jal         0x8005F9A8
    // 0x8005FA70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005F9A8(rdram, ctx);
        goto after_0;
    // 0x8005FA70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005FA74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FA78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005FA7C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005FA80: sb          $t8, 0x76($t9)
    MEM_B(0X76, ctx->r25) = ctx->r24;
    // 0x8005FA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FA88:
    // 0x8005FA88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FA8C: jr          $ra
    // 0x8005FA90: nop

    return;
    // 0x8005FA90: nop

;}
RECOMP_FUNC void func_8066D63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D63C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8066D640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066D644: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066D648: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8066D64C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066D650: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066D654: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8066D658: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8066D65C: bnel        $t6, $zero, L_8066D6F4
    if (ctx->r14 != 0) {
        // 0x8066D660: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8066D6F4;
    }
    goto skip_0;
    // 0x8066D660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8066D664: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8066D668: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D66C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x8066D670: beq         $t7, $zero, L_8066D6B4
    if (ctx->r15 == 0) {
        // 0x8066D674: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_8066D6B4;
    }
    // 0x8066D674: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8066D678: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D67C: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x8066D680: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8066D684: jal         0x8004D1F0
    // 0x8066D688: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8066D688: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8066D68C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D690: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x8066D694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066D698: jal         0x8004D698
    // 0x8066D69C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8066D69C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8066D6A0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8066D6A4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8066D6A8: ori         $t9, $t8, 0xF
    ctx->r25 = ctx->r24 | 0XF;
    // 0x8066D6AC: b           L_8066D6E8
    // 0x8066D6B0: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
        goto L_8066D6E8;
    // 0x8066D6B0: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_8066D6B4:
    // 0x8066D6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066D6B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8066D6BC: jal         0x8004D1F0
    // 0x8066D6C0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x8066D6C0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8066D6C4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D6C8: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x8066D6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066D6D0: jal         0x8004D698
    // 0x8066D6D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x8066D6D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8066D6D8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8066D6DC: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8066D6E0: ori         $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 | 0XF0;
    // 0x8066D6E4: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
L_8066D6E8:
    // 0x8066D6E8: jal         0x8066D5D0
    // 0x8066D6EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066D5D0(rdram, ctx);
        goto after_4;
    // 0x8066D6EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8066D6F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066D6F4:
    // 0x8066D6F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066D6F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066D6FC: jr          $ra
    // 0x8066D700: nop

    return;
    // 0x8066D700: nop

;}
RECOMP_FUNC void func_80760228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760228: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8076022C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80760230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80760234: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80760238: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8076023C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80760240: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80760244: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80760248: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8076024C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80760250: addiu       $t6, $zero, 0x4B0
    ctx->r14 = ADD32(0, 0X4B0);
    // 0x80760254: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80760258: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8076025C: addiu       $a3, $zero, 0x474
    ctx->r7 = ADD32(0, 0X474);
    // 0x80760260: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80760264: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80760268: jal         0x8076009C
    // 0x8076026C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x8076026C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80760270: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80760274: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80760278: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8076027C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80760280: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80760284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80760288: jr          $ra
    // 0x8076028C: nop

    return;
    // 0x8076028C: nop

;}
RECOMP_FUNC void func_80736F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736F20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736F28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736F2C: jal         0x80047090
    // 0x80736F30: addiu       $a0, $zero, 0x4629
    ctx->r4 = ADD32(0, 0X4629);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80736F30: addiu       $a0, $zero, 0x4629
    ctx->r4 = ADD32(0, 0X4629);
    after_0:
    // 0x80736F34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80736F38: lui         $at, 0x4629
    ctx->r1 = S32(0X4629 << 16);
    // 0x80736F3C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80736F40: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80736F44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80736F48: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80736F4C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80736F50: jal         0x8004613C
    // 0x80736F54: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80736F54: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x80736F58: bne         $v0, $zero, L_80736F68
    if (ctx->r2 != 0) {
        // 0x80736F5C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80736F68;
    }
    // 0x80736F5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80736F60: b           L_80736F90
    // 0x80736F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80736F90;
    // 0x80736F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80736F68:
    // 0x80736F68: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x80736F6C: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x80736F70: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80736F74: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80736F78: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80736F7C: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x80736F80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80736F84: jal         0x80047F9C
    // 0x80736F88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80736F88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80736F8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80736F90:
    // 0x80736F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736F94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736F98: jr          $ra
    // 0x80736F9C: nop

    return;
    // 0x80736F9C: nop

;}
RECOMP_FUNC void func_80030194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80030198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003019C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800301A0: lw          $v0, 0xC0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC0);
    // 0x800301A4: beql        $v0, $zero, L_800301E4
    if (ctx->r2 == 0) {
        // 0x800301A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800301E4;
    }
    goto skip_0;
    // 0x800301A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800301AC: lw          $t6, 0xD8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XD8);
    // 0x800301B0: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x800301B4: bnel        $at, $zero, L_800301E0
    if (ctx->r1 != 0) {
        // 0x800301B8: sw          $zero, 0xC0($a1)
        MEM_W(0XC0, ctx->r5) = 0;
            goto L_800301E0;
    }
    goto skip_1;
    // 0x800301B8: sw          $zero, 0xC0($a1)
    MEM_W(0XC0, ctx->r5) = 0;
    skip_1:
    // 0x800301BC: jal         0x80021A44
    // 0x800301C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80021A44(rdram, ctx);
        goto after_0;
    // 0x800301C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800301C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800301C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800301CC: jalr        $v0
    // 0x800301D0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800301D0: nop

    after_1:
    // 0x800301D4: b           L_800301E4
    // 0x800301D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800301E4;
    // 0x800301D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800301DC: sw          $zero, 0xC0($a1)
    MEM_W(0XC0, ctx->r5) = 0;
L_800301E0:
    // 0x800301E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800301E4:
    // 0x800301E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800301E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800301EC: jr          $ra
    // 0x800301F0: nop

    return;
    // 0x800301F0: nop

;}
RECOMP_FUNC void func_807BB1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB1E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB1E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BB1EC: jal         0x807BA848
    // 0x807BB1F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807BA848(rdram, ctx);
        goto after_0;
    // 0x807BB1F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807BB1F4: jal         0x807BABD4
    // 0x807BB1F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BABD4(rdram, ctx);
        goto after_1;
    // 0x807BB1F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BB1FC: jal         0x807BAB94
    // 0x807BB200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAB94(rdram, ctx);
        goto after_2;
    // 0x807BB200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807BB204: jal         0x807BAA20
    // 0x807BB208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAA20(rdram, ctx);
        goto after_3;
    // 0x807BB208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807BB20C: beq         $v0, $zero, L_807BB224
    if (ctx->r2 == 0) {
        // 0x807BB210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BB224;
    }
    // 0x807BB210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807BB21C: jal         0x807BB7A4
    // 0x807BB220: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_807BB7A4(rdram, ctx);
        goto after_4;
    // 0x807BB220: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
L_807BB224:
    // 0x807BB224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BB228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BB22C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BB230: jr          $ra
    // 0x807BB234: nop

    return;
    // 0x807BB234: nop

;}
RECOMP_FUNC void func_8046B3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B3B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B3B8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8046B3BC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8046B3C0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8046B3C4: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(138, 0X28CC) << 16);
    // 0x8046B3C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046B3CC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8046B3D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8046B3D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8046B3D8: lw          $t8, -0x3FF4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(138, 0X28CC));
    // 0x8046B3DC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8046B3E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8046B3E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046B3E8: jal         0x80048490
    // 0x8046B3EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8046B3EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8046B3F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8046B3F4: jal         0x80048378
    // 0x8046B3F8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8046B3F8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8046B3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046B400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B404: jr          $ra
    // 0x8046B408: nop

    return;
    // 0x8046B408: nop

;}
RECOMP_FUNC void func_805AE024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE024: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE028: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE02C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE030: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE034: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE038: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE03C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE040: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE044: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE048: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE04C: jr          $ra
    // 0x805AE050: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE050: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C2008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2008: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(203, 0X1038) << 16);
    // 0x804C200C: lw          $t6, 0x27A8($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(203, 0X1038));
    // 0x804C2010: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(203, 0X81C) << 16);
    // 0x804C2014: addiu       $t7, $t7, 0x1F8C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(203, 0X81C));
    // 0x804C2018: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x804C201C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C2020: jr          $ra
    // 0x804C2024: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    return;
    // 0x804C2024: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_806809E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806809E4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806809E8: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806809EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806809F0: jr          $ra
    // 0x806809F4: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x806809F4: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80452154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80452158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045215C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140EC) << 16);
    // 0x80452160: lwc1        $f4, -0x7B34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140EC));
    // 0x80452164: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80452168: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045216C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80452170: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80452174: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140F0) << 16);
    // 0x80452178: bc1f        L_804521D4
    if (!c1cs) {
        // 0x8045217C: nop
    
            goto L_804521D4;
    }
    // 0x8045217C: nop

    // 0x80452180: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80452184: jal         0x80450760
    // 0x80452188: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80450760(rdram, ctx);
        goto after_0;
    // 0x80452188: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045218C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80452190: jal         0x80450B18
    // 0x80452194: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x80452194: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80452198: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8045219C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804521A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804521A4: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x804521A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804521AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804521B0: lwc1        $f6, 0x6F10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x804521B4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804521B8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804521BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804521C0: swc1        $f10, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f10.u32l;
    // 0x804521C4: jal         0x8044E9C0
    // 0x804521C8: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_2;
    // 0x804521C8: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_2:
    // 0x804521CC: b           L_80452430
    // 0x804521D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452430;
    // 0x804521D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804521D4:
    // 0x804521D4: lwc1        $f16, -0x7B30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140F0));
    // 0x804521D8: lui         $at, 0x4487
    ctx->r1 = S32(0X4487 << 16);
    // 0x804521DC: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804521E0: nop

    // 0x804521E4: bc1fl       L_8045225C
    if (!c1cs) {
        // 0x804521E8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8045225C;
    }
    goto skip_0;
    // 0x804521E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x804521EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x804521F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x804521F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804521F8: beql        $t6, $at, L_80452228
    if (ctx->r14 == ctx->r1) {
        // 0x804521FC: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80452228;
    }
    goto skip_1;
    // 0x804521FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_1:
    // 0x80452200: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80452204: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80452208: jal         0x80450B18
    // 0x8045220C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x8045220C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x80452210: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80452214: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80452218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045221C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80452220: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80452224: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80452228:
    // 0x80452228: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8045222C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80452234: lwc1        $f18, 0x6F10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x80452238: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045223C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80452240: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80452244: swc1        $f6, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f6.u32l;
    // 0x80452248: jal         0x8044E9C0
    // 0x8045224C: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_4;
    // 0x8045224C: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_4:
    // 0x80452250: b           L_80452430
    // 0x80452254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452430;
    // 0x80452254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452258: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8045225C:
    // 0x8045225C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140F4) << 16);
    // 0x80452260: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80452264: nop

    // 0x80452268: bc1f        L_804522DC
    if (!c1cs) {
        // 0x8045226C: nop
    
            goto L_804522DC;
    }
    // 0x8045226C: nop

    // 0x80452270: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80452274: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80452278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8045227C: beql        $t8, $at, L_804522AC
    if (ctx->r24 == ctx->r1) {
        // 0x80452280: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_804522AC;
    }
    goto skip_2;
    // 0x80452280: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_2:
    // 0x80452284: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80452288: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8045228C: jal         0x80450B18
    // 0x80452290: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80452290: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x80452294: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80452298: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8045229C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804522A0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x804522A4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804522A8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_804522AC:
    // 0x804522AC: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x804522B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804522B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804522B8: lwc1        $f10, 0x6F10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x804522BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804522C0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804522C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804522C8: swc1        $f18, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f18.u32l;
    // 0x804522CC: jal         0x8044E9C0
    // 0x804522D0: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_6;
    // 0x804522D0: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_6:
    // 0x804522D4: b           L_80452430
    // 0x804522D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452430;
    // 0x804522D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804522DC:
    // 0x804522DC: lwc1        $f4, -0x7B2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140F4));
    // 0x804522E0: lui         $at, 0x4425
    ctx->r1 = S32(0X4425 << 16);
    // 0x804522E4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804522E8: nop

    // 0x804522EC: bc1fl       L_80452324
    if (!c1cs) {
        // 0x804522F0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80452324;
    }
    goto skip_3;
    // 0x804522F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_3:
    // 0x804522F4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x804522F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x804522FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452300: beql        $t0, $at, L_80452430
    if (ctx->r8 == ctx->r1) {
        // 0x80452304: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80452430;
    }
    goto skip_4;
    // 0x80452304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80452308: jal         0x80450B18
    // 0x8045230C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_7;
    // 0x8045230C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_7:
    // 0x80452310: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80452314: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80452318: b           L_8045242C
    // 0x8045231C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_8045242C;
    // 0x8045231C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80452320: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80452324:
    // 0x80452324: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80452328: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8045232C: nop

    // 0x80452330: bc1fl       L_80452368
    if (!c1cs) {
        // 0x80452334: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80452368;
    }
    goto skip_5;
    // 0x80452334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_5:
    // 0x80452338: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8045233C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80452340: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452344: beql        $t2, $at, L_80452430
    if (ctx->r10 == ctx->r1) {
        // 0x80452348: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80452430;
    }
    goto skip_6;
    // 0x80452348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8045234C: jal         0x80450B18
    // 0x80452350: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_8;
    // 0x80452350: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x80452354: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80452358: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8045235C: b           L_8045242C
    // 0x80452360: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8045242C;
    // 0x80452360: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80452364: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80452368:
    // 0x80452368: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8045236C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80452370: nop

    // 0x80452374: bc1fl       L_804523AC
    if (!c1cs) {
        // 0x80452378: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_804523AC;
    }
    goto skip_7;
    // 0x80452378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_7:
    // 0x8045237C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80452380: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80452384: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452388: beql        $t4, $at, L_80452430
    if (ctx->r12 == ctx->r1) {
        // 0x8045238C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80452430;
    }
    goto skip_8;
    // 0x8045238C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80452390: jal         0x80450B18
    // 0x80452394: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_9;
    // 0x80452394: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_9:
    // 0x80452398: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8045239C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x804523A0: b           L_8045242C
    // 0x804523A4: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
        goto L_8045242C;
    // 0x804523A4: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x804523A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_804523AC:
    // 0x804523AC: nop

    // 0x804523B0: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804523B4: nop

    // 0x804523B8: bc1fl       L_804523F0
    if (!c1cs) {
        // 0x804523BC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_804523F0;
    }
    goto skip_9;
    // 0x804523BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_9:
    // 0x804523C0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x804523C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804523C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804523CC: beql        $t6, $at, L_80452430
    if (ctx->r14 == ctx->r1) {
        // 0x804523D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80452430;
    }
    goto skip_10;
    // 0x804523D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x804523D4: jal         0x80450B18
    // 0x804523D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_10;
    // 0x804523D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_10:
    // 0x804523DC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x804523E0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x804523E4: b           L_8045242C
    // 0x804523E8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_8045242C;
    // 0x804523E8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x804523EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_804523F0:
    // 0x804523F0: nop

    // 0x804523F4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804523F8: nop

    // 0x804523FC: bc1fl       L_80452430
    if (!c1cs) {
        // 0x80452400: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80452430;
    }
    goto skip_11;
    // 0x80452400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80452404: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80452408: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8045240C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80452410: beql        $t8, $at, L_80452430
    if (ctx->r24 == ctx->r1) {
        // 0x80452414: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80452430;
    }
    goto skip_12;
    // 0x80452414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x80452418: jal         0x80450B18
    // 0x8045241C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_11;
    // 0x8045241C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_11:
    // 0x80452420: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80452424: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80452428: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_8045242C:
    // 0x8045242C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452430:
    // 0x80452430: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80452434: jr          $ra
    // 0x80452438: nop

    return;
    // 0x80452438: nop

;}
RECOMP_FUNC void func_804E7DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7DC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804E7DC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804E7DC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804E7DCC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804E7DD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804E7DD4: jal         0x80047090
    // 0x804E7DD8: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804E7DD8: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    after_0:
    // 0x804E7DDC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804E7DE0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804E7DE4: beq         $v0, $at, L_804E7E50
    if (ctx->r2 == ctx->r1) {
        // 0x804E7DE8: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_804E7E50;
    }
    // 0x804E7DE8: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x804E7DEC: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x804E7DF0: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x804E7DF4: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(261, 0X800) << 16);
    // 0x804E7DF8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x804E7DFC: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x804E7E00: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x804E7E04: or          $a1, $t7, $t0
    ctx->r5 = ctx->r15 | ctx->r8;
    // 0x804E7E08: addiu       $a0, $a0, -0x7FA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(261, 0X800));
    // 0x804E7E0C: jal         0x80046804
    // 0x804E7E10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x804E7E10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804E7E14: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x804E7E18: beq         $v0, $zero, L_804E7E50
    if (ctx->r2 == 0) {
        // 0x804E7E1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804E7E50;
    }
    // 0x804E7E1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804E7E20: beq         $v1, $zero, L_804E7E40
    if (ctx->r3 == 0) {
        // 0x804E7E24: nop
    
            goto L_804E7E40;
    }
    // 0x804E7E24: nop

    // 0x804E7E28: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804E7E2C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x804E7E30: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804E7E34: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x804E7E38: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x804E7E3C: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_804E7E40:
    // 0x804E7E40: jal         0x80044194
    // 0x804E7E44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804E7E44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x804E7E48: b           L_804E7E54
    // 0x804E7E4C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_804E7E54;
    // 0x804E7E4C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_804E7E50:
    // 0x804E7E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804E7E54:
    // 0x804E7E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804E7E58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804E7E5C: jr          $ra
    // 0x804E7E60: nop

    return;
    // 0x804E7E60: nop

    // 0x804E7E64: nop

    // 0x804E7E68: nop

    // 0x804E7E6C: nop

;}
RECOMP_FUNC void func_806D6860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6860: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D6864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D6868: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806D686C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806D6870: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806D6874: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806D6878: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x806D687C: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806D6880: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(619, 0X2F0) << 16);
    // 0x806D6884: lwc1        $f10, 0x6B40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(619, 0X2F0));
    // 0x806D6888: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x806D688C: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806D6890: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D6894: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806D6898: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806D689C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806D68A0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806D68A4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x806D68A8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x806D68AC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806D68B0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806D68B4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806D68B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806D68BC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806D68C0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806D68C4: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x806D68C8: jalr        $t9
    // 0x806D68CC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806D68CC: nop

    after_0:
    // 0x806D68D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D68D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806D68D8: jr          $ra
    // 0x806D68DC: nop

    return;
    // 0x806D68DC: nop

;}
RECOMP_FUNC void func_8078A268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A268: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A26C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8078A270: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x8078A274: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8078A278: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8078A27C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8078A280: lw          $t8, 0x134($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X134);
    // 0x8078A284: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8078A288: lui         $t2, 0x8079
    ctx->r10 = S32(RELOC_HI16(793, 0XD98) << 16);
    // 0x8078A28C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078A290: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8078A294: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8078A298: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8078A29C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8078A2A0: lw          $t2, -0x5028($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(793, 0XD98));
    // 0x8078A2A4: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x8078A2A8: lui         $t5, 0x6
    ctx->r13 = S32(0X6 << 16);
    // 0x8078A2AC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8078A2B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8078A2B4: ori         $t5, $t5, 0x4
    ctx->r13 = ctx->r13 | 0X4;
    // 0x8078A2B8: ori         $t4, $t4, 0x204
    ctx->r12 = ctx->r12 | 0X204;
    // 0x8078A2BC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8078A2C0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8078A2C4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8078A2C8: jr          $ra
    // 0x8078A2CC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    return;
    // 0x8078A2CC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void static_4_80088238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088238: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008823C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088240: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80088244: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80088248: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008824C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80088250: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80088254: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80088258: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8008825C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x80088260: jal         0x800890BC
    // 0x80088264: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x80088264: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80088268: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8008826C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80088270: beq         $t8, $zero, L_80088280
    if (ctx->r24 == 0) {
        // 0x80088274: nop
    
            goto L_80088280;
    }
    // 0x80088274: nop

    // 0x80088278: b           L_800882E8
    // 0x8008827C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800882E8;
    // 0x8008827C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80088280:
    // 0x80088280: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80088284:
    // 0x80088284: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80088288: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008828C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80088290: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80088294: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x80088298: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8008829C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800882A0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800882A4: jal         0x8008F1E0
    // 0x800882A8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x800882A8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800882AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800882B0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800882B4: bne         $t3, $zero, L_800882D0
    if (ctx->r11 != 0) {
        // 0x800882B8: nop
    
            goto L_800882D0;
    }
    // 0x800882B8: nop

    // 0x800882BC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800882C0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800882C4: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800882C8: bne         $at, $zero, L_80088284
    if (ctx->r1 != 0) {
        // 0x800882CC: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80088284;
    }
    // 0x800882CC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800882D0:
    // 0x800882D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800882D4: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800882D8: jal         0x800890BC
    // 0x800882DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800882DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800882E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800882E4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800882E8:
    // 0x800882E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800882EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800882F0: jr          $ra
    // 0x800882F4: nop

    return;
    // 0x800882F4: nop

    // 0x800882F8: nop

    // 0x800882FC: nop

;}
RECOMP_FUNC void static_4_80089EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089EA4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80089EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089EAC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80089EB0: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80089EB4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80089EB8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80089EBC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80089EC0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80089EC4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80089EC8: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80089ECC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80089ED0: bne         $at, $zero, L_80089EFC
    if (ctx->r1 != 0) {
        // 0x80089ED4: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80089EFC;
    }
    // 0x80089ED4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80089ED8: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x80089EDC: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x80089EE0: beq         $at, $zero, L_8008A4E8
    if (ctx->r1 == 0) {
        // 0x80089EE4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8008A4E8;
    }
    // 0x80089EE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089EE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80089EEC: addu        $at, $at, $t7
    gpr jr_addend_80089EF4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80089EF0: lw          $t7, 0x3314($at)
    ctx->r15 = ADD32(ctx->r1, 0X3314);
    // 0x80089EF4: jr          $t7
    // 0x80089EF8: nop

    switch (jr_addend_80089EF4 >> 2) {
        case 0: goto L_8008A208; break;
        case 1: goto L_8008A4E8; break;
        case 2: goto L_8008A208; break;
        case 3: goto L_8008A4E8; break;
        case 4: goto L_8008A4E8; break;
        case 5: goto L_8008A4E8; break;
        case 6: goto L_8008A4E8; break;
        case 7: goto L_8008A4E8; break;
        case 8: goto L_8008A4E8; break;
        case 9: goto L_8008A4E8; break;
        case 10: goto L_8008A4E8; break;
        case 11: goto L_8008A4E8; break;
        case 12: goto L_8008A4E8; break;
        case 13: goto L_8008A4E8; break;
        case 14: goto L_8008A4E8; break;
        case 15: goto L_8008A4E8; break;
        case 16: goto L_8008A4E8; break;
        case 17: goto L_8008A4E8; break;
        case 18: goto L_8008A4E8; break;
        case 19: goto L_8008A0B8; break;
        case 20: goto L_8008A4E8; break;
        case 21: goto L_8008A4E8; break;
        case 22: goto L_8008A4E8; break;
        case 23: goto L_8008A4E8; break;
        case 24: goto L_8008A4E8; break;
        case 25: goto L_8008A4E8; break;
        case 26: goto L_8008A4E8; break;
        case 27: goto L_8008A4E8; break;
        case 28: goto L_8008A4E8; break;
        case 29: goto L_8008A4E8; break;
        case 30: goto L_80089F10; break;
        case 31: goto L_80089F48; break;
        case 32: goto L_8008A208; break;
        case 33: goto L_8008A208; break;
        case 34: goto L_8008A208; break;
        case 35: goto L_8008A4E8; break;
        case 36: goto L_80089F48; break;
        case 37: goto L_8008A4E8; break;
        case 38: goto L_8008A4E8; break;
        case 39: goto L_8008A4E8; break;
        case 40: goto L_8008A4E8; break;
        case 41: goto L_8008A36C; break;
        case 42: goto L_8008A0B8; break;
        case 43: goto L_8008A43C; break;
        case 44: goto L_8008A4E8; break;
        case 45: goto L_8008A4E8; break;
        case 46: goto L_8008A484; break;
        case 47: goto L_8008A4E8; break;
        case 48: goto L_8008A0B8; break;
        case 49: goto L_8008A4E8; break;
        case 50: goto L_8008A4E8; break;
        case 51: goto L_8008A0B8; break;
        default: switch_error(__func__, 0x80089EF4, 0x800B3314);
    }
    // 0x80089EF8: nop

L_80089EFC:
    // 0x80089EFC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80089F00: beql        $v1, $at, L_8008A4CC
    if (ctx->r3 == ctx->r1) {
        // 0x80089F04: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8008A4CC;
    }
    goto skip_0;
    // 0x80089F04: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80089F08: b           L_8008A4EC
    // 0x80089F0C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_8008A4EC;
    // 0x80089F0C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80089F10:
    // 0x80089F10: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80089F14: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80089F18: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80089F1C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x80089F20: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80089F24: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80089F28: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80089F2C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80089F30: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80089F34: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80089F38: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80089F3C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80089F40: b           L_8008A500
    // 0x80089F44: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_8008A500;
    // 0x80089F44: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80089F48:
    // 0x80089F48: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80089F4C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80089F50: bnel        $v0, $at, L_80089F88
    if (ctx->r2 != ctx->r1) {
        // 0x80089F54: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80089F88;
    }
    goto skip_1;
    // 0x80089F54: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x80089F58: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80089F5C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80089F60: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x80089F64: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80089F68: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80089F6C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80089F70: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x80089F74: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80089F78: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80089F7C: b           L_80089FE4
    // 0x80089F80: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80089FE4;
    // 0x80089F80: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80089F84: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80089F88:
    // 0x80089F88: bnel        $v0, $at, L_80089FC0
    if (ctx->r2 != ctx->r1) {
        // 0x80089F8C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80089FC0;
    }
    goto skip_2;
    // 0x80089F8C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x80089F90: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80089F94: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80089F98: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80089F9C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80089FA0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80089FA4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80089FA8: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x80089FAC: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x80089FB0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80089FB4: b           L_80089FE4
    // 0x80089FB8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80089FE4;
    // 0x80089FB8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80089FBC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80089FC0:
    // 0x80089FC0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80089FC4: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x80089FC8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80089FCC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80089FD0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80089FD4: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80089FD8: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80089FDC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80089FE0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_80089FE4:
    // 0x80089FE4: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x80089FE8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80089FEC: bnel        $t7, $at, L_8008A010
    if (ctx->r15 != ctx->r1) {
        // 0x80089FF0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8008A010;
    }
    goto skip_3;
    // 0x80089FF0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80089FF4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80089FF8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80089FFC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008A000: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8008A004: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008A008: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8008A00C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8008A010:
    // 0x8008A010: bgtzl       $t6, L_8008A04C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8008A014: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8008A04C;
    }
    goto skip_4;
    // 0x8008A014: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x8008A018: bltzl       $t6, L_8008A02C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8008A01C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_8008A02C;
    }
    goto skip_5;
    // 0x8008A01C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x8008A020: b           L_8008A04C
    // 0x8008A024: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_8008A04C;
    // 0x8008A024: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x8008A028: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_8008A02C:
    // 0x8008A02C: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8008A030: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8008A034: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8008A038: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008A03C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8008A040: b           L_8008A09C
    // 0x8008A044: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_8008A09C;
    // 0x8008A044: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8008A048: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8008A04C:
    // 0x8008A04C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8008A050: beq         $t8, $zero, L_8008A078
    if (ctx->r24 == 0) {
        // 0x8008A054: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_8008A078;
    }
    // 0x8008A054: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8008A058: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008A05C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x8008A060: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x8008A064: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8008A068: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8008A06C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8008A070: b           L_8008A09C
    // 0x8008A074: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_8008A09C;
    // 0x8008A074: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_8008A078:
    // 0x8008A078: beql        $t6, $zero, L_8008A0A0
    if (ctx->r14 == 0) {
        // 0x8008A07C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_8008A0A0;
    }
    goto skip_6;
    // 0x8008A07C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x8008A080: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8008A084: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8008A088: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8008A08C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8008A090: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8008A094: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8008A098: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8008A09C:
    // 0x8008A09C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_8008A0A0:
    // 0x8008A0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A0A4: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x8008A0A8: jal         0x80090400
    // 0x8008A0AC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x8008A0AC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x8008A0B0: b           L_8008A504
    // 0x8008A0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A504;
    // 0x8008A0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A0B8:
    // 0x8008A0B8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8008A0BC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8008A0C0: bnel        $v0, $at, L_8008A0F8
    if (ctx->r2 != ctx->r1) {
        // 0x8008A0C4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8008A0F8;
    }
    goto skip_7;
    // 0x8008A0C4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x8008A0C8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8008A0CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A0D0: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x8008A0D4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8008A0D8: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x8008A0DC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8008A0E0: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x8008A0E4: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x8008A0E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8008A0EC: b           L_8008A154
    // 0x8008A0F0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_8008A154;
    // 0x8008A0F0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8008A0F4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8008A0F8:
    // 0x8008A0F8: bnel        $v0, $at, L_8008A130
    if (ctx->r2 != ctx->r1) {
        // 0x8008A0FC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_8008A130;
    }
    goto skip_8;
    // 0x8008A0FC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x8008A100: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008A104: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8008A108: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8008A10C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8008A110: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8008A114: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8008A118: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8008A11C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8008A120: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8008A124: b           L_8008A154
    // 0x8008A128: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_8008A154;
    // 0x8008A128: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008A12C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_8008A130:
    // 0x8008A130: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A134: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x8008A138: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8008A13C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8008A140: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008A144: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x8008A148: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x8008A14C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008A150: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_8008A154:
    // 0x8008A154: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8008A158: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8008A15C: bne         $v0, $at, L_8008A17C
    if (ctx->r2 != ctx->r1) {
        // 0x8008A160: nop
    
            goto L_8008A17C;
    }
    // 0x8008A160: nop

    // 0x8008A164: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008A168: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8008A16C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8008A170: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8008A174: b           L_8008A194
    // 0x8008A178: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_8008A194;
    // 0x8008A178: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8008A17C:
    // 0x8008A17C: bnel        $v0, $zero, L_8008A198
    if (ctx->r2 != 0) {
        // 0x8008A180: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_8008A198;
    }
    goto skip_9;
    // 0x8008A180: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x8008A184: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008A188: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8008A18C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008A190: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8008A194:
    // 0x8008A194: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_8008A198:
    // 0x8008A198: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x8008A19C: beql        $t6, $zero, L_8008A1F0
    if (ctx->r14 == 0) {
        // 0x8008A1A0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8008A1F0;
    }
    goto skip_10;
    // 0x8008A1A0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x8008A1A4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8008A1A8: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x8008A1AC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8008A1B0: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x8008A1B4: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x8008A1B8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8008A1BC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8008A1C0: beq         $v1, $at, L_8008A1D4
    if (ctx->r3 == ctx->r1) {
        // 0x8008A1C4: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_8008A1D4;
    }
    // 0x8008A1C4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8008A1C8: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8008A1CC: bnel        $v1, $at, L_8008A1F0
    if (ctx->r3 != ctx->r1) {
        // 0x8008A1D0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8008A1F0;
    }
    goto skip_11;
    // 0x8008A1D0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_8008A1D4:
    // 0x8008A1D4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8008A1D8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8008A1DC: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x8008A1E0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8008A1E4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8008A1E8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8008A1EC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8008A1F0:
    // 0x8008A1F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A1F4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x8008A1F8: jal         0x80090400
    // 0x8008A1FC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x8008A1FC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x8008A200: b           L_8008A504
    // 0x8008A204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A504;
    // 0x8008A204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A208:
    // 0x8008A208: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x8008A20C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x8008A210: bnel        $t6, $at, L_8008A278
    if (ctx->r14 != ctx->r1) {
        // 0x8008A214: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_8008A278;
    }
    goto skip_12;
    // 0x8008A214: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x8008A218: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008A21C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8008A220: beq         $t9, $zero, L_8008A238
    if (ctx->r25 == 0) {
        // 0x8008A224: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008A238;
    }
    // 0x8008A224: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008A228: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x8008A22C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8008A230: b           L_8008A268
    // 0x8008A234: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_8008A268;
    // 0x8008A234: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_8008A238:
    // 0x8008A238: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8008A23C: beq         $t7, $zero, L_8008A254
    if (ctx->r15 == 0) {
        // 0x8008A240: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_8008A254;
    }
    // 0x8008A240: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x8008A244: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x8008A248: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008A24C: b           L_8008A264
    // 0x8008A250: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_8008A264;
    // 0x8008A250: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_8008A254:
    // 0x8008A254: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8008A258: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8008A25C: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x8008A260: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_8008A264:
    // 0x8008A264: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008A268:
    // 0x8008A268: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x8008A26C: b           L_8008A2CC
    // 0x8008A270: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_8008A2CC;
    // 0x8008A270: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x8008A274: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_8008A278:
    // 0x8008A278: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8008A27C: beq         $t6, $zero, L_8008A294
    if (ctx->r14 == 0) {
        // 0x8008A280: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008A294;
    }
    // 0x8008A280: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008A284: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x8008A288: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008A28C: b           L_8008A2C4
    // 0x8008A290: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_8008A2C4;
    // 0x8008A290: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_8008A294:
    // 0x8008A294: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8008A298: beq         $t8, $zero, L_8008A2B0
    if (ctx->r24 == 0) {
        // 0x8008A29C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_8008A2B0;
    }
    // 0x8008A29C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x8008A2A0: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x8008A2A4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8008A2A8: b           L_8008A2C0
    // 0x8008A2AC: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_8008A2C0;
    // 0x8008A2AC: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_8008A2B0:
    // 0x8008A2B0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8008A2B4: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x8008A2B8: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x8008A2BC: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_8008A2C0:
    // 0x8008A2C0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008A2C4:
    // 0x8008A2C4: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x8008A2C8: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_8008A2CC:
    // 0x8008A2CC: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x8008A2D0: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x8008A2D4: beql        $t6, $zero, L_8008A300
    if (ctx->r14 == 0) {
        // 0x8008A2D8: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8008A300;
    }
    goto skip_13;
    // 0x8008A2D8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x8008A2DC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8008A2E0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x8008A2E4: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8008A2E8: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x8008A2EC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8008A2F0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8008A2F4: b           L_8008A350
    // 0x8008A2F8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_8008A350;
    // 0x8008A2F8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x8008A2FC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8008A300:
    // 0x8008A300: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8008A304: beq         $t9, $zero, L_8008A32C
    if (ctx->r25 == 0) {
        // 0x8008A308: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_8008A32C;
    }
    // 0x8008A308: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8008A30C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8008A310: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x8008A314: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x8008A318: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008A31C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8008A320: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8008A324: b           L_8008A350
    // 0x8008A328: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_8008A350;
    // 0x8008A328: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_8008A32C:
    // 0x8008A32C: beql        $t7, $zero, L_8008A354
    if (ctx->r15 == 0) {
        // 0x8008A330: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_8008A354;
    }
    goto skip_14;
    // 0x8008A330: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x8008A334: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8008A338: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8008A33C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8008A340: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8008A344: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008A348: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8008A34C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_8008A350:
    // 0x8008A350: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8008A354:
    // 0x8008A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A358: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x8008A35C: jal         0x8008FD20
    // 0x8008A360: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x8008A360: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x8008A364: b           L_8008A504
    // 0x8008A368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A504;
    // 0x8008A368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A36C:
    // 0x8008A36C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8008A370: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8008A374: bnel        $v0, $at, L_8008A3A8
    if (ctx->r2 != ctx->r1) {
        // 0x8008A378: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_8008A3A8;
    }
    goto skip_15;
    // 0x8008A378: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x8008A37C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8008A380: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A384: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8008A388: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8008A38C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8008A390: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008A394: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x8008A398: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8008A39C: b           L_8008A500
    // 0x8008A3A0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_8008A500;
    // 0x8008A3A0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x8008A3A4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_8008A3A8:
    // 0x8008A3A8: bnel        $v0, $at, L_8008A3DC
    if (ctx->r2 != ctx->r1) {
        // 0x8008A3AC: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_8008A3DC;
    }
    goto skip_16;
    // 0x8008A3AC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x8008A3B0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008A3B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A3B8: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x8008A3BC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8008A3C0: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x8008A3C4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008A3C8: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x8008A3CC: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x8008A3D0: b           L_8008A500
    // 0x8008A3D4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_8008A500;
    // 0x8008A3D4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8008A3D8: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_8008A3DC:
    // 0x8008A3DC: bnel        $v0, $at, L_8008A418
    if (ctx->r2 != ctx->r1) {
        // 0x8008A3E0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_8008A418;
    }
    goto skip_17;
    // 0x8008A3E0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x8008A3E4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8008A3E8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A3EC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8008A3F0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8008A3F4: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8008A3F8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008A3FC: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x8008A400: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8008A404: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8008A408: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8008A40C: b           L_8008A500
    // 0x8008A410: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_8008A500;
    // 0x8008A410: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8008A414: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_8008A418:
    // 0x8008A418: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A41C: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x8008A420: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8008A424: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x8008A428: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008A42C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8008A430: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8008A434: b           L_8008A500
    // 0x8008A438: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_8008A500;
    // 0x8008A438: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_8008A43C:
    // 0x8008A43C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008A440: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A448: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x8008A44C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8008A450: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8008A454: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8008A458: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x8008A45C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008A460: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8008A464: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8008A468: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8008A46C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x8008A470: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008A474: jal         0x80090400
    // 0x8008A478: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x8008A478: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x8008A47C: b           L_8008A504
    // 0x8008A480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A504;
    // 0x8008A480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A484:
    // 0x8008A484: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008A488: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A48C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x8008A490: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8008A494: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x8008A498: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008A49C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x8008A4A0: jal         0x8008ADAC
    // 0x8008A4A4: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x8008A4A4: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x8008A4A8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8008A4AC: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8008A4B0: bltz        $v1, L_8008A500
    if (SIGNED(ctx->r3) < 0) {
        // 0x8008A4B4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8008A500;
    }
    // 0x8008A4B4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008A4B8: beql        $at, $zero, L_8008A504
    if (ctx->r1 == 0) {
        // 0x8008A4BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008A504;
    }
    goto skip_18;
    // 0x8008A4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x8008A4C0: b           L_8008A500
    // 0x8008A4C4: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_8008A500;
    // 0x8008A4C4: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x8008A4C8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_8008A4CC:
    // 0x8008A4CC: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x8008A4D0: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8008A4D4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8008A4D8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008A4DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008A4E0: b           L_8008A500
    // 0x8008A4E4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_8008A500;
    // 0x8008A4E4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8008A4E8:
    // 0x8008A4E8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_8008A4EC:
    // 0x8008A4EC: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x8008A4F0: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x8008A4F4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008A4F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008A4FC: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_8008A500:
    // 0x8008A500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A504:
    // 0x8008A504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A508: jr          $ra
    // 0x8008A50C: nop

    return;
    // 0x8008A50C: nop

;}
RECOMP_FUNC void static_4_8008F7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F7B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F7B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008F7B8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8008F7BC: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008F7C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008F7C4: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8008F7C8: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8008F7CC: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x8008F7D0: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x8008F7D4: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x8008F7D8: bgtz        $s3, L_8008F7EC
    if (SIGNED(ctx->r19) > 0) {
        // 0x8008F7DC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8008F7EC;
    }
    // 0x8008F7DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F7E0: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8008F7E4: addiu       $s1, $s1, 0x34A0
    ctx->r17 = ADD32(ctx->r17, 0X34A0);
    // 0x8008F7E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8008F7EC:
    // 0x8008F7EC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8008F7F0: beq         $v0, $s4, L_8008F824
    if (ctx->r2 == ctx->r20) {
        // 0x8008F7F4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_8008F824;
    }
    // 0x8008F7F4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x8008F7F8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x8008F7FC: beq         $a0, $v1, L_8008F808
    if (ctx->r4 == ctx->r3) {
        // 0x8008F800: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_8008F808;
    }
    // 0x8008F800: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x8008F804: bne         $v1, $at, L_8008FA60
    if (ctx->r3 != ctx->r1) {
        // 0x8008F808: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_8008FA60;
    }
L_8008F808:
    // 0x8008F808: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x8008F80C: bne         $at, $zero, L_8008FA60
    if (ctx->r1 != 0) {
        // 0x8008F810: nop
    
            goto L_8008FA60;
    }
    // 0x8008F810: nop

    // 0x8008F814: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8008F818: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008F81C: beq         $at, $zero, L_8008FA60
    if (ctx->r1 == 0) {
        // 0x8008F820: nop
    
            goto L_8008FA60;
    }
    // 0x8008F820: nop

L_8008F824:
    // 0x8008F824: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008F828: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x8008F82C: beq         $v0, $v1, L_8008F868
    if (ctx->r2 == ctx->r3) {
        // 0x8008F830: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8008F868;
    }
    // 0x8008F830: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8008F834: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x8008F838: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008F83C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8008F840: bne         $t7, $zero, L_8008F858
    if (ctx->r15 != 0) {
        // 0x8008F844: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8008F858;
    }
    // 0x8008F844: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008F848: beql        $at, $zero, L_8008F85C
    if (ctx->r1 == 0) {
        // 0x8008F84C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_8008F85C;
    }
    goto skip_0;
    // 0x8008F84C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x8008F850: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x8008F854: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8008F858:
    // 0x8008F858: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_8008F85C:
    // 0x8008F85C: bgez        $t8, L_8008F868
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008F860: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_8008F868;
    }
    // 0x8008F860: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x8008F864: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8008F868:
    // 0x8008F868: bgtz        $s2, L_8008F938
    if (SIGNED(ctx->r18) > 0) {
        // 0x8008F86C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8008F938;
    }
    // 0x8008F86C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8008F870: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8008F874: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008F878: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x8008F87C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x8008F880: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008F884: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8008F888: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008F88C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008F890: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F894: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F898: bgtz        $v0, L_8008F8B0
    if (SIGNED(ctx->r2) > 0) {
        // 0x8008F89C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_8008F8B0;
    }
    // 0x8008F89C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x8008F8A0: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x8008F8A4: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x8008F8A8: beql        $t9, $zero, L_8008F8D8
    if (ctx->r25 == 0) {
        // 0x8008F8AC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8008F8D8;
    }
    goto skip_1;
    // 0x8008F8AC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_8008F8B0:
    // 0x8008F8B0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8008F8B4: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8008F8B8: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x8008F8BC: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8008F8C0: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x8008F8C4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008F8C8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008F8CC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8008F8D0: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8008F8D4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8008F8D8:
    // 0x8008F8D8: beql        $at, $zero, L_8008F8F4
    if (ctx->r1 == 0) {
        // 0x8008F8DC: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_8008F8F4;
    }
    goto skip_2;
    // 0x8008F8DC: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x8008F8E0: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x8008F8E4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x8008F8E8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8008F8EC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x8008F8F0: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_8008F8F4:
    // 0x8008F8F4: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008F8F8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x8008F8FC: beq         $at, $zero, L_8008F910
    if (ctx->r1 == 0) {
        // 0x8008F900: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_8008F910;
    }
    // 0x8008F900: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x8008F904: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x8008F908: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8008F90C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_8008F910:
    // 0x8008F910: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8008F914: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8008F918: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x8008F91C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8008F920: jal         0x8008AD80
    // 0x8008F924: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8008F924: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x8008F928: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8008F92C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x8008F930: b           L_8008FCBC
    // 0x8008F934: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_8008FCBC;
    // 0x8008F934: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_8008F938:
    // 0x8008F938: beq         $at, $zero, L_8008F9B0
    if (ctx->r1 == 0) {
        // 0x8008F93C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8008F9B0;
    }
    // 0x8008F93C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F940: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8008F944: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8008F948: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008F94C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8008F950: jal         0x8008AD80
    // 0x8008F954: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x8008F954: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x8008F958: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008F95C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008F960: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x8008F964: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x8008F968: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8008F96C: bgtz        $v0, L_8008F984
    if (SIGNED(ctx->r2) > 0) {
        // 0x8008F970: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_8008F984;
    }
    // 0x8008F970: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x8008F974: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8008F978: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x8008F97C: beq         $t8, $zero, L_8008F9A8
    if (ctx->r24 == 0) {
        // 0x8008F980: nop
    
            goto L_8008F9A8;
    }
    // 0x8008F980: nop

L_8008F984:
    // 0x8008F984: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8008F988: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8008F98C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8008F990: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8008F994: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8008F998: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x8008F99C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008F9A0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8008F9A4: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_8008F9A8:
    // 0x8008F9A8: b           L_8008FCBC
    // 0x8008F9AC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_8008FCBC;
    // 0x8008F9AC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_8008F9B0:
    // 0x8008F9B0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8008F9B4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008F9B8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008F9BC: jal         0x8008AD80
    // 0x8008F9C0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x8008F9C0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x8008F9C4: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008F9C8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008F9CC: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x8008F9D0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8008F9D4: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x8008F9D8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x8008F9DC: bgtz        $v0, L_8008F9F4
    if (SIGNED(ctx->r2) > 0) {
        // 0x8008F9E0: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8008F9F4;
    }
    // 0x8008F9E0: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008F9E4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8008F9E8: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8008F9EC: beql        $t9, $zero, L_8008FA1C
    if (ctx->r25 == 0) {
        // 0x8008F9F0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8008FA1C;
    }
    goto skip_3;
    // 0x8008F9F0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_8008F9F4:
    // 0x8008F9F4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8008F9F8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008F9FC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8008FA00: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8008FA04: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x8008FA08: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008FA0C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008FA10: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8008FA14: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8008FA18: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_8008FA1C:
    // 0x8008FA1C: beq         $at, $zero, L_8008FA30
    if (ctx->r1 == 0) {
        // 0x8008FA20: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_8008FA30;
    }
    // 0x8008FA20: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x8008FA24: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8008FA28: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8008FA2C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_8008FA30:
    // 0x8008FA30: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8008FA34: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008FA38: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8008FA3C: jal         0x8008AD80
    // 0x8008FA40: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x8008FA40: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x8008FA44: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008FA48: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8008FA4C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x8008FA50: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x8008FA54: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8008FA58: b           L_8008FCBC
    // 0x8008FA5C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_8008FCBC;
    // 0x8008FA5C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_8008FA60:
    // 0x8008FA60: beq         $a0, $v1, L_8008FA70
    if (ctx->r4 == ctx->r3) {
        // 0x8008FA64: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_8008FA70;
    }
    // 0x8008FA64: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x8008FA68: bnel        $v1, $at, L_8008FAB0
    if (ctx->r3 != ctx->r1) {
        // 0x8008FA6C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_8008FAB0;
    }
    goto skip_4;
    // 0x8008FA6C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_8008FA70:
    // 0x8008FA70: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008FA74: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x8008FA78: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008FA7C: beql        $at, $zero, L_8008FA90
    if (ctx->r1 == 0) {
        // 0x8008FA80: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8008FA90;
    }
    goto skip_5;
    // 0x8008FA80: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x8008FA84: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x8008FA88: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8008FA8C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_8008FA90:
    // 0x8008FA90: bgez        $t7, L_8008FA9C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8008FA94: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_8008FA9C;
    }
    // 0x8008FA94: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x8008FA98: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8008FA9C:
    // 0x8008FA9C: bne         $a0, $v1, L_8008FAAC
    if (ctx->r4 != ctx->r3) {
        // 0x8008FAA0: nop
    
            goto L_8008FAAC;
    }
    // 0x8008FAA0: nop

    // 0x8008FAA4: b           L_8008FAAC
    // 0x8008FAA8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_8008FAAC;
    // 0x8008FAA8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_8008FAAC:
    // 0x8008FAAC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_8008FAB0:
    // 0x8008FAB0: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008FAB4: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x8008FAB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008FABC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8008FAC0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8008FAC4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008FAC8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008FACC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8008FAD0: bgtz        $v0, L_8008FAE8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8008FAD4: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_8008FAE8;
    }
    // 0x8008FAD4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8008FAD8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8008FADC: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x8008FAE0: beq         $t6, $zero, L_8008FB0C
    if (ctx->r14 == 0) {
        // 0x8008FAE4: nop
    
            goto L_8008FB0C;
    }
    // 0x8008FAE4: nop

L_8008FAE8:
    // 0x8008FAE8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8008FAEC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8008FAF0: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x8008FAF4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8008FAF8: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8008FAFC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008FB00: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8008FB04: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8008FB08: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_8008FB0C:
    // 0x8008FB0C: blezl       $v0, L_8008FB68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008FB10: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_8008FB68;
    }
    goto skip_6;
    // 0x8008FB10: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x8008FB14: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8008FB18: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8008FB1C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8008FB20: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008FB24: beq         $at, $zero, L_8008FB38
    if (ctx->r1 == 0) {
        // 0x8008FB28: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8008FB38;
    }
    // 0x8008FB28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008FB2C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8008FB30: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8008FB34: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_8008FB38:
    // 0x8008FB38: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8008FB3C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8008FB40: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8008FB44: jal         0x8008AD80
    // 0x8008FB48: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x8008FB48: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x8008FB4C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8008FB50: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8008FB54: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8008FB58: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x8008FB5C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8008FB60: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8008FB64: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_8008FB68:
    // 0x8008FB68: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008FB6C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x8008FB70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008FB74: bltz        $s2, L_8008FB8C
    if (SIGNED(ctx->r18) < 0) {
        // 0x8008FB78: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_8008FB8C;
    }
    // 0x8008FB78: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x8008FB7C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x8008FB80: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x8008FB84: b           L_8008FBA8
    // 0x8008FB88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8008FBA8;
    // 0x8008FB88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8008FB8C:
    // 0x8008FB8C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x8008FB90: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8008FB94: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8008FB98: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008FB9C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8008FBA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008FBA4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_8008FBA8:
    // 0x8008FBA8: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x8008FBAC: bnel        $at, $zero, L_8008FC58
    if (ctx->r1 != 0) {
        // 0x8008FBB0: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8008FC58;
    }
    goto skip_7;
    // 0x8008FBB0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x8008FBB4: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x8008FBB8: bne         $at, $zero, L_8008FC08
    if (ctx->r1 != 0) {
        // 0x8008FBBC: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_8008FC08;
    }
    // 0x8008FBBC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8008FBC0: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8008FBC4: bne         $v0, $zero, L_8008FBD0
    if (ctx->r2 != 0) {
        // 0x8008FBC8: nop
    
            goto L_8008FBD0;
    }
    // 0x8008FBC8: nop

    // 0x8008FBCC: break       7
    do_break(2148072396);
L_8008FBD0:
    // 0x8008FBD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008FBD4: bne         $v0, $at, L_8008FBE8
    if (ctx->r2 != ctx->r1) {
        // 0x8008FBD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008FBE8;
    }
    // 0x8008FBD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008FBDC: bne         $s2, $at, L_8008FBE8
    if (ctx->r18 != ctx->r1) {
        // 0x8008FBE0: nop
    
            goto L_8008FBE8;
    }
    // 0x8008FBE0: nop

    // 0x8008FBE4: break       6
    do_break(2148072420);
L_8008FBE8:
    // 0x8008FBE8: mfhi        $s2
    ctx->r18 = hi;
    // 0x8008FBEC: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8008FBF0: mflo        $t9
    ctx->r25 = lo;
    // 0x8008FBF4: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x8008FBF8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008FBFC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8008FC00: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8008FC04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8008FC08:
    // 0x8008FC08: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8008FC0C: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8008FC10: bne         $v0, $zero, L_8008FC1C
    if (ctx->r2 != 0) {
        // 0x8008FC14: nop
    
            goto L_8008FC1C;
    }
    // 0x8008FC14: nop

    // 0x8008FC18: break       7
    do_break(2148072472);
L_8008FC1C:
    // 0x8008FC1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008FC20: bne         $v0, $at, L_8008FC34
    if (ctx->r2 != ctx->r1) {
        // 0x8008FC24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008FC34;
    }
    // 0x8008FC24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008FC28: bne         $s2, $at, L_8008FC34
    if (ctx->r18 != ctx->r1) {
        // 0x8008FC2C: nop
    
            goto L_8008FC34;
    }
    // 0x8008FC2C: nop

    // 0x8008FC30: break       6
    do_break(2148072496);
L_8008FC34:
    // 0x8008FC34: mfhi        $s2
    ctx->r18 = hi;
    // 0x8008FC38: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8008FC3C: mflo        $t9
    ctx->r25 = lo;
    // 0x8008FC40: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x8008FC44: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008FC48: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8008FC4C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8008FC50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008FC54: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8008FC58:
    // 0x8008FC58: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8008FC5C: bne         $v0, $zero, L_8008FC68
    if (ctx->r2 != 0) {
        // 0x8008FC60: nop
    
            goto L_8008FC68;
    }
    // 0x8008FC60: nop

    // 0x8008FC64: break       7
    do_break(2148072548);
L_8008FC68:
    // 0x8008FC68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008FC6C: bne         $v0, $at, L_8008FC80
    if (ctx->r2 != ctx->r1) {
        // 0x8008FC70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008FC80;
    }
    // 0x8008FC70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008FC74: bne         $s2, $at, L_8008FC80
    if (ctx->r18 != ctx->r1) {
        // 0x8008FC78: nop
    
            goto L_8008FC80;
    }
    // 0x8008FC78: nop

    // 0x8008FC7C: break       6
    do_break(2148072572);
L_8008FC80:
    // 0x8008FC80: mfhi        $s2
    ctx->r18 = hi;
    // 0x8008FC84: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8008FC88: mflo        $t9
    ctx->r25 = lo;
    // 0x8008FC8C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x8008FC90: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008FC94: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x8008FC98: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8008FC9C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x8008FCA0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8008FCA4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8008FCA8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8008FCAC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008FCB0: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x8008FCB4: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x8008FCB8: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_8008FCBC:
    // 0x8008FCBC: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x8008FCC0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8008FCC4: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x8008FCC8: bnel        $t6, $at, L_8008FD0C
    if (ctx->r14 != ctx->r1) {
        // 0x8008FCCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008FD0C;
    }
    goto skip_8;
    // 0x8008FCCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x8008FCD0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008FCD4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8008FCD8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x8008FCDC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8008FCE0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8008FCE4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8008FCE8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8008FCEC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x8008FCF0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8008FCF4: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8008FCF8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008FCFC: beq         $at, $zero, L_8008FD08
    if (ctx->r1 == 0) {
        // 0x8008FD00: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_8008FD08;
    }
    // 0x8008FD00: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x8008FD04: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_8008FD08:
    // 0x8008FD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008FD0C:
    // 0x8008FD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FD10: jr          $ra
    // 0x8008FD14: nop

    return;
    // 0x8008FD14: nop

    // 0x8008FD18: jr          $ra
    // 0x8008FD1C: nop

    return;
    // 0x8008FD1C: nop

;}
RECOMP_FUNC void static_98_804444FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804444FC: jr          $ra
    // 0x80444500: nop

    return;
    // 0x80444500: nop

;}
