#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void guTranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F188: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8008F18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F190: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8008F194: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8008F198: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8008F19C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8008F1A0: jal         0x80086EA0
    // 0x8008F1A4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8008F1A4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8008F1A8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8008F1AC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8008F1B0: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8008F1B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008F1B8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8008F1BC: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8008F1C0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8008F1C4: jal         0x80086DA0
    // 0x8008F1C8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8008F1C8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8008F1CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F1D0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8008F1D4: jr          $ra
    // 0x8008F1D8: nop

    return;
    // 0x8008F1D8: nop

;}
RECOMP_FUNC void func_80475F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475F88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475F8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475F90: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475F94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475F9C: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E98) << 16);
    // 0x80475FA0: addiu       $a2, $a2, -0x49A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E98));
    // 0x80475FA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80475FA8: jal         0x80475C4C
    // 0x80475FAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475C4C(rdram, ctx);
        goto after_0;
    // 0x80475FAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475FB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475FB8: jr          $ra
    // 0x80475FBC: nop

    return;
    // 0x80475FBC: nop

;}
RECOMP_FUNC void func_804C30F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C30F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C30FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3100: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x804C3104: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804C3108: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804C310C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x804C3110: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x804C3114: lw          $t8, 0x280($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X280);
    // 0x804C3118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C311C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C3120: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804C3124: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x804C3128: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x804C312C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x804C3130: lw          $t1, 0x168($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X168);
    // 0x804C3134: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804C3138: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x804C313C: jal         0x80077338
    // 0x804C3140: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x804C3140: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x804C3144: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x804C3148: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804C314C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804C3150: jal         0x8007711C
    // 0x804C3154: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x804C3154: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x804C3158: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x804C315C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x804C3160: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804C3164: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x804C3168: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804C316C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804C3170: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x804C3174: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x804C3178: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x804C317C: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x804C3180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C3188: jr          $ra
    // 0x804C318C: nop

    return;
    // 0x804C318C: nop

;}
RECOMP_FUNC void func_80067E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067EA0: jal         0x80067BF8
    // 0x80067EA4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_80067BF8(rdram, ctx);
        goto after_0;
    // 0x80067EA4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x80067EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067EB0: jr          $ra
    // 0x80067EB4: nop

    return;
    // 0x80067EB4: nop

;}
RECOMP_FUNC void func_805AA840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AA844: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AA848: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AA84C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805AA850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805AA854: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805AA858: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AA85C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805AA860: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x805AA864: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x805AA868: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805AA86C: jal         0x80067BBC
    // 0x805AA870: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805AA870: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x805AA874: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x805AA878: jal         0x80067818
    // 0x805AA87C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805AA87C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805AA880: jal         0x800653D8
    // 0x805AA884: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805AA884: nop

    after_2:
    // 0x805AA888: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x805AA88C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805AA890: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x805AA894: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x805AA898: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805AA89C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805AA8A0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(432, 0XAE8) << 16);
    // 0x805AA8A4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805AA8A8: lwc1        $f16, -0x5228($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(432, 0XAE8));
    // 0x805AA8AC: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x805AA8B0: bc1f        L_805AA8C0
    if (!c1cs) {
        // 0x805AA8B4: swc1        $f16, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
            goto L_805AA8C0;
    }
    // 0x805AA8B4: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x805AA8B8: b           L_805AA8C4
    // 0x805AA8BC: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_805AA8C4;
    // 0x805AA8BC: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_805AA8C0:
    // 0x805AA8C0: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_805AA8C4:
    // 0x805AA8C4: jal         0x8005FE48
    // 0x805AA8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x805AA8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805AA8CC: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x805AA8D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805AA8D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805AA8D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805AA8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AA8E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AA8E4: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x805AA8E8: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x805AA8EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805AA8F0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805AA8F4: sh          $zero, 0x14($t1)
    MEM_H(0X14, ctx->r9) = 0;
    // 0x805AA8F8: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805AA8FC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805AA900: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x805AA904: jal         0x805AABAC
    // 0x805AA908: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    func_805AABAC(rdram, ctx);
        goto after_4;
    // 0x805AA908: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x805AA90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805AA910: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AA914: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805AA918: jr          $ra
    // 0x805AA91C: nop

    return;
    // 0x805AA91C: nop

;}
RECOMP_FUNC void func_80464DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464DAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80464DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80464DB4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80464DB8: lw          $t6, 0x1F20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F20);
    // 0x80464DBC: addiu       $v1, $v0, 0x1F20
    ctx->r3 = ADD32(ctx->r2, 0X1F20);
    // 0x80464DC0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80464DC4: sltiu       $at, $t7, 0x10E
    ctx->r1 = ctx->r15 < 0X10E ? 1 : 0;
    // 0x80464DC8: beq         $at, $zero, L_80464DF8
    if (ctx->r1 == 0) {
        // 0x80464DCC: sw          $t7, 0x1F20($v0)
        MEM_W(0X1F20, ctx->r2) = ctx->r15;
            goto L_80464DF8;
    }
    // 0x80464DCC: sw          $t7, 0x1F20($v0)
    MEM_W(0X1F20, ctx->r2) = ctx->r15;
    // 0x80464DD0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80464DD4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80464DD8: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80464DDC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E10) << 16);
    // 0x80464DE0: lwc1        $f8, 0x63E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E10));
    // 0x80464DE4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80464DE8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80464DEC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80464DF0: b           L_80464E8C
    // 0x80464DF4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_80464E8C;
    // 0x80464DF4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80464DF8:
    // 0x80464DF8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80464DFC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80464E00: sltiu       $at, $a1, 0x21C
    ctx->r1 = ctx->r5 < 0X21C ? 1 : 0;
    // 0x80464E04: beql        $at, $zero, L_80464E34
    if (ctx->r1 == 0) {
        // 0x80464E08: sltiu       $at, $a1, 0x32A
        ctx->r1 = ctx->r5 < 0X32A ? 1 : 0;
            goto L_80464E34;
    }
    goto skip_0;
    // 0x80464E08: sltiu       $at, $a1, 0x32A
    ctx->r1 = ctx->r5 < 0X32A ? 1 : 0;
    skip_0:
    // 0x80464E0C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80464E10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80464E14: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(125, 0X1E14) << 16);
    // 0x80464E18: lwc1        $f6, 0x63E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(125, 0X1E14));
    // 0x80464E1C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80464E20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80464E24: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80464E28: b           L_80464E8C
    // 0x80464E2C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_80464E8C;
    // 0x80464E2C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80464E30: sltiu       $at, $a1, 0x32A
    ctx->r1 = ctx->r5 < 0X32A ? 1 : 0;
L_80464E34:
    // 0x80464E34: beql        $at, $zero, L_80464E4C
    if (ctx->r1 == 0) {
        // 0x80464E38: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80464E4C;
    }
    goto skip_1;
    // 0x80464E38: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x80464E3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80464E40: b           L_80464E8C
    // 0x80464E44: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
        goto L_80464E8C;
    // 0x80464E44: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
    // 0x80464E48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80464E4C:
    // 0x80464E4C: jal         0x800653D8
    // 0x80464E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80464E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80464E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80464E58: bgez        $v0, L_80464E6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80464E5C: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_80464E6C;
    }
    // 0x80464E5C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80464E60: beq         $t9, $zero, L_80464E6C
    if (ctx->r25 == 0) {
        // 0x80464E64: nop
    
            goto L_80464E6C;
    }
    // 0x80464E64: nop

    // 0x80464E68: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80464E6C:
    // 0x80464E6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80464E70: bne         $t9, $at, L_80464E8C
    if (ctx->r25 != ctx->r1) {
        // 0x80464E74: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_80464E8C;
    }
    // 0x80464E74: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80464E78: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80464E7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80464E80: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80464E84: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80464E88: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
L_80464E8C:
    // 0x80464E8C: jal         0x80464650
    // 0x80464E90: nop

    func_80464650(rdram, ctx);
        goto after_1;
    // 0x80464E90: nop

    after_1:
    // 0x80464E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80464E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80464E9C: jr          $ra
    // 0x80464EA0: nop

    return;
    // 0x80464EA0: nop

;}
RECOMP_FUNC void func_80042290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042290: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80042294: beq         $v0, $zero, L_800422AC
    if (ctx->r2 == 0) {
        // 0x80042298: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800422AC;
    }
    // 0x80042298: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004229C: bnel        $v0, $zero, L_800422AC
    if (ctx->r2 != 0) {
        // 0x800422A0: sw          $v0, 0x16C($a0)
        MEM_W(0X16C, ctx->r4) = ctx->r2;
            goto L_800422AC;
    }
    goto skip_0;
    // 0x800422A0: sw          $v0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->r2;
    skip_0:
    // 0x800422A4: sw          $zero, 0x168($a0)
    MEM_W(0X168, ctx->r4) = 0;
    // 0x800422A8: sw          $v0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->r2;
L_800422AC:
    // 0x800422AC: jr          $ra
    // 0x800422B0: nop

    return;
    // 0x800422B0: nop

;}
RECOMP_FUNC void func_800262B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800262B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800262B8: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x800262BC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800262C0: addiu       $t7, $t7, 0x61E0
    ctx->r15 = ADD32(ctx->r15, 0X61E0);
    // 0x800262C4: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x800262C8: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x800262CC: sb          $t6, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = ctx->r14;
    // 0x800262D0: jr          $ra
    // 0x800262D4: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
    return;
    // 0x800262D4: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8070429C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070429C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x807042A0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807042A4: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X388C) << 16);
    // 0x807042A8: lwc1        $f24, 0x6CFC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X388C));
    // 0x807042AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807042B0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3890) << 16);
    // 0x807042B4: lwc1        $f22, 0x6D00($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3890));
    // 0x807042B8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x807042BC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x807042C0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x807042C4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x807042C8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x807042CC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x807042D0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x807042D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807042D8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x807042DC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x807042E0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x807042E4: lui         $s0, 0x8070
    ctx->r16 = S32(RELOC_HI16(709, 0X3708) << 16);
    // 0x807042E8: lui         $s1, 0x8070
    ctx->r17 = S32(RELOC_HI16(709, 0X36D8) << 16);
    // 0x807042EC: lui         $s2, 0x8070
    ctx->r18 = S32(RELOC_HI16(709, 0X36E8) << 16);
    // 0x807042F0: lui         $s3, 0x8070
    ctx->r19 = S32(RELOC_HI16(709, 0X3718) << 16);
    // 0x807042F4: lui         $s4, 0x8070
    ctx->r20 = S32(RELOC_HI16(709, 0X36F8) << 16);
    // 0x807042F8: lui         $s7, 0x800F
    ctx->r23 = S32(0X800F << 16);
    // 0x807042FC: lui         $fp, 0x8070
    ctx->r30 = S32(RELOC_HI16(709, 0X3718) << 16);
    // 0x80704300: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80704304: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80704308: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8070430C: addiu       $fp, $fp, 0x6B88
    ctx->r30 = ADD32(ctx->r30, (int16_t)RELOC_LO16(709, 0X3718));
    // 0x80704310: addiu       $s7, $s7, 0x7EA0
    ctx->r23 = ADD32(ctx->r23, 0X7EA0);
    // 0x80704314: addiu       $s4, $s4, 0x6B68
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(709, 0X36F8));
    // 0x80704318: addiu       $s3, $s3, 0x6B88
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(709, 0X3718));
    // 0x8070431C: addiu       $s2, $s2, 0x6B58
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(709, 0X36E8));
    // 0x80704320: addiu       $s1, $s1, 0x6B48
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(709, 0X36D8));
    // 0x80704324: addiu       $s0, $s0, 0x6B78
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(709, 0X3708));
    // 0x80704328: addiu       $s6, $sp, 0x70
    ctx->r22 = ADD32(ctx->r29, 0X70);
L_8070432C:
    // 0x8070432C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80704330: lwc1        $f6, 0x3C($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X3C);
    // 0x80704334: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80704338: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8070433C: lw          $t6, 0xA68($s7)
    ctx->r14 = MEM_W(ctx->r23, 0XA68);
    // 0x80704340: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80704344: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80704348: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8070434C: lwc1        $f16, 0x40($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X40);
    // 0x80704350: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80704354: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80704358: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8070435C: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80704360: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80704364: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x80704368: lwc1        $f6, 0x44($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X44);
    // 0x8070436C: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80704370: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80704374: swc1        $f22, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f22.u32l;
    // 0x80704378: swc1        $f24, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f24.u32l;
    // 0x8070437C: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x80704380: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    // 0x80704384: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x80704388: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x8070438C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80704390: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x80704394: jalr        $t9
    // 0x80704398: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80704398: nop

    after_0:
    // 0x8070439C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x807043A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807043A4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807043A8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807043AC: bne         $s0, $fp, L_8070432C
    if (ctx->r16 != ctx->r30) {
        // 0x807043B0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8070432C;
    }
    // 0x807043B0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x807043B4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x807043B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807043BC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x807043C0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x807043C4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x807043C8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x807043CC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x807043D0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x807043D4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x807043D8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x807043DC: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x807043E0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x807043E4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x807043E8: jr          $ra
    // 0x807043EC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x807043EC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80018F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018F94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018F98: jal         0x80019160
    // 0x80018F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80019160(rdram, ctx);
        goto after_0;
    // 0x80018F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80018FA0: jal         0x800190D0
    // 0x80018FA4: nop

    func_800190D0(rdram, ctx);
        goto after_1;
    // 0x80018FA4: nop

    after_1:
    // 0x80018FA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80018FAC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
L_80018FB0:
    // 0x80018FB0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80018FB4: jal         0x80019D78
    // 0x80018FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80019D78(rdram, ctx);
        goto after_2;
    // 0x80018FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80018FBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80018FC0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80018FC4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80018FC8: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80018FCC: bnel        $at, $zero, L_80018FB0
    if (ctx->r1 != 0) {
        // 0x80018FD0: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_80018FB0;
    }
    goto skip_0;
    // 0x80018FD0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    skip_0:
    // 0x80018FD4: jal         0x80019F90
    // 0x80018FD8: nop

    func_80019F90(rdram, ctx);
        goto after_3;
    // 0x80018FD8: nop

    after_3:
    // 0x80018FDC: jal         0x8001AF80
    // 0x80018FE0: nop

    func_8001AF80(rdram, ctx);
        goto after_4;
    // 0x80018FE0: nop

    after_4:
    // 0x80018FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018FE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80018FEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018FF0: jr          $ra
    // 0x80018FF4: nop

    return;
    // 0x80018FF4: nop

;}
RECOMP_FUNC void func_800687B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800687B8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800687BC: lw          $t6, 0x310($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X310);
    // 0x800687C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800687C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800687C8: xori        $t7, $t6, 0x17D8
    ctx->r15 = ctx->r14 ^ 0X17D8;
    // 0x800687CC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800687D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800687D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800687D8: sw          $t7, 0x6EB4($at)
    MEM_W(0X6EB4, ctx->r1) = ctx->r15;
    // 0x800687DC: lui         $t8, 0xA000
    ctx->r24 = S32(0XA000 << 16);
    // 0x800687E0: lw          $t9, 0x164($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X164);
    // 0x800687E4: lui         $at, 0x1EC
    ctx->r1 = S32(0X1EC << 16);
    // 0x800687E8: ori         $at, $at, 0x6021
    ctx->r1 = ctx->r1 | 0X6021;
    // 0x800687EC: xor         $t0, $t9, $at
    ctx->r8 = ctx->r25 ^ ctx->r1;
    // 0x800687F0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800687F4: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800687F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800687FC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068800: sw          $t0, 0x6EB8($at)
    MEM_W(0X6EB8, ctx->r1) = ctx->r8;
    // 0x80068804: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80068808: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x8006880C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80068810: addiu       $t1, $t1, 0x5284
    ctx->r9 = ADD32(ctx->r9, 0X5284);
    // 0x80068814: sw          $t1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r9;
    // 0x80068818: addiu       $a0, $a0, 0xAA0
    ctx->r4 = ADD32(ctx->r4, 0XAA0);
    // 0x8006881C: jal         0x80052298
    // 0x80068820: sb          $t2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r10;
    func_80052298(rdram, ctx);
        goto after_0;
    // 0x80068820: sb          $t2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r10;
    after_0:
    // 0x80068824: addiu       $a0, $s0, 0x57C
    ctx->r4 = ADD32(ctx->r16, 0X57C);
    // 0x80068828: jal         0x8006DDCC
    // 0x8006882C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8006DDCC(rdram, ctx);
        goto after_1;
    // 0x8006882C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80068830: jal         0x8006D1CC
    // 0x80068834: nop

    func_8006D1CC(rdram, ctx);
        goto after_2;
    // 0x80068834: nop

    after_2:
    // 0x80068838: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006883C: lw          $a1, -0x7BC4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BC4);
    // 0x80068840: addiu       $a0, $s0, 0x634
    ctx->r4 = ADD32(ctx->r16, 0X634);
    // 0x80068844: jal         0x800519C0
    // 0x80068848: lw          $a2, 0x8D0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8D0);
    func_800519C0(rdram, ctx);
        goto after_3;
    // 0x80068848: lw          $a2, 0x8D0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8D0);
    after_3:
    // 0x8006884C: jal         0x8006DE24
    // 0x80068850: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8006DE24(rdram, ctx);
        goto after_4;
    // 0x80068850: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80068854: jal         0x8006C77C
    // 0x80068858: addiu       $a0, $s0, 0x3F4
    ctx->r4 = ADD32(ctx->r16, 0X3F4);
    func_8006C77C(rdram, ctx);
        goto after_5;
    // 0x80068858: addiu       $a0, $s0, 0x3F4
    ctx->r4 = ADD32(ctx->r16, 0X3F4);
    after_5:
    // 0x8006885C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80068860: lw          $a1, -0x7BC4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BC4);
    // 0x80068864: jal         0x8005A9BC
    // 0x80068868: addiu       $a0, $s0, 0x478
    ctx->r4 = ADD32(ctx->r16, 0X478);
    func_8005A9BC(rdram, ctx);
        goto after_6;
    // 0x80068868: addiu       $a0, $s0, 0x478
    ctx->r4 = ADD32(ctx->r16, 0X478);
    after_6:
    // 0x8006886C: jal         0x80058C7C
    // 0x80068870: nop

    func_80058C7C(rdram, ctx);
        goto after_7;
    // 0x80068870: nop

    after_7:
    // 0x80068874: jal         0x80044C58
    // 0x80068878: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    func_80044C58(rdram, ctx);
        goto after_8;
    // 0x80068878: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    after_8:
    // 0x8006887C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068884: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80068888: jr          $ra
    // 0x8006888C: nop

    return;
    // 0x8006888C: nop

;}
RECOMP_FUNC void func_8077FF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FF0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077FF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FF14: jal         0x8077FE4C
    // 0x8077FF18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077FE4C(rdram, ctx);
        goto after_0;
    // 0x8077FF18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8077FF1C: beq         $v0, $zero, L_8077FF70
    if (ctx->r2 == 0) {
        // 0x8077FF20: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8077FF70;
    }
    // 0x8077FF20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8077FF24: lui         $t8, 0x8078
    ctx->r24 = S32(RELOC_HI16(781, 0X36C) << 16);
    // 0x8077FF28: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8077FF2C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8077FF30: addiu       $t8, $t8, -0x384
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(781, 0X36C));
    // 0x8077FF34: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8077FF38: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8077FF3C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8077FF40: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8077FF44: jal         0x8077FEDC
    // 0x8077FF48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8077FEDC(rdram, ctx);
        goto after_1;
    // 0x8077FF48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8077FF4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8077FF50: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8077FF54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8077FF58: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8077FF5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8077FF60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8077FF64: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8077FF68: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x8077FF6C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
L_8077FF70:
    // 0x8077FF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077FF78: jr          $ra
    // 0x8077FF7C: nop

    return;
    // 0x8077FF7C: nop

;}
RECOMP_FUNC void func_8000DE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DE44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DE48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DE4C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000DE50: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8000DE54: bltzl       $t8, L_8000DE70
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000DE58: lw          $v0, 0x2C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X2C);
            goto L_8000DE70;
    }
    goto skip_0;
    // 0x8000DE58: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    skip_0:
    // 0x8000DE5C: jal         0x8000BBF4
    // 0x8000DE60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000BBF4(rdram, ctx);
        goto after_0;
    // 0x8000DE60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000DE64: b           L_8000DE90
    // 0x8000DE68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_8000DE90;
    // 0x8000DE68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000DE6C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
L_8000DE70:
    // 0x8000DE70: beql        $v0, $zero, L_8000DE94
    if (ctx->r2 == 0) {
        // 0x8000DE74: lbu         $v0, 0x20($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X20);
            goto L_8000DE94;
    }
    goto skip_1;
    // 0x8000DE74: lbu         $v0, 0x20($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X20);
    skip_1:
    // 0x8000DE78: lw          $t9, 0x48($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X48);
    // 0x8000DE7C: bnel        $a0, $t9, L_8000DE94
    if (ctx->r4 != ctx->r25) {
        // 0x8000DE80: lbu         $v0, 0x20($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X20);
            goto L_8000DE94;
    }
    goto skip_2;
    // 0x8000DE80: lbu         $v0, 0x20($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X20);
    skip_2:
    // 0x8000DE84: jal         0x8000BBF4
    // 0x8000DE88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000BBF4(rdram, ctx);
        goto after_1;
    // 0x8000DE88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8000DE8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8000DE90:
    // 0x8000DE90: lbu         $v0, 0x20($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X20);
L_8000DE94:
    // 0x8000DE94: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8000DE98: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8000DE9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DEA0: beq         $v0, $at, L_8000DEB0
    if (ctx->r2 == ctx->r1) {
        // 0x8000DEA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000DEB0;
    }
    // 0x8000DEA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000DEA8: bnel        $v0, $at, L_8000DEB8
    if (ctx->r2 != ctx->r1) {
        // 0x8000DEAC: lbu         $t1, 0x0($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X0);
            goto L_8000DEB8;
    }
    goto skip_3;
    // 0x8000DEAC: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_8000DEB0:
    // 0x8000DEB0: sb          $zero, 0x20($a0)
    MEM_B(0X20, ctx->r4) = 0;
    // 0x8000DEB4: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
L_8000DEB8:
    // 0x8000DEB8: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8000DEBC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x8000DEC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DEC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000DEC8: jr          $ra
    // 0x8000DECC: nop

    return;
    // 0x8000DECC: nop

;}
RECOMP_FUNC void func_8044AF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AF14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044AF18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AF1C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044AF20: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AF24: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AF28: lw          $a1, 0x6A64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A64);
    // 0x8044AF2C: beq         $a1, $zero, L_8044AF44
    if (ctx->r5 == 0) {
        // 0x8044AF30: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044AF44;
    }
    // 0x8044AF30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044AF34: jal         0x80050A2C
    // 0x8044AF38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044AF38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044AF3C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AF40: sw          $zero, 0x6A64($v1)
    MEM_W(0X6A64, ctx->r3) = 0;
L_8044AF44:
    // 0x8044AF44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AF48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044AF4C: jr          $ra
    // 0x8044AF50: nop

    return;
    // 0x8044AF50: nop

;}
RECOMP_FUNC void func_80034BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034BC4: jal         0x80034A70
    // 0x80034BC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80034A70(rdram, ctx);
        goto after_0;
    // 0x80034BC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034BCC: jal         0x80023F90
    // 0x80034BD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023F90(rdram, ctx);
        goto after_1;
    // 0x80034BD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034BDC: jr          $ra
    // 0x80034BE0: nop

    return;
    // 0x80034BE0: nop

;}
RECOMP_FUNC void func_8064DF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064DF90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064DF94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064DF98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064DF9C: jal         0x80045A34
    // 0x8064DFA0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064DFA0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x8064DFA4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8064DFA8: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8064DFAC: bne         $v0, $zero, L_8064DFBC
    if (ctx->r2 != 0) {
        // 0x8064DFB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064DFBC;
    }
    // 0x8064DFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064DFB4: b           L_8064DFC0
    // 0x8064DFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064DFC0;
    // 0x8064DFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064DFBC:
    // 0x8064DFBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064DFC0:
    // 0x8064DFC0: jr          $ra
    // 0x8064DFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8064DFC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003BB20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BB20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BB24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8003BB28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BB2C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8003BB30: addiu       $t6, $zero, 0x4004
    ctx->r14 = ADD32(0, 0X4004);
    // 0x8003BB34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003BB38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003BB3C: lw          $a3, 0x426C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X426C);
    // 0x8003BB40: jal         0x8003BA90
    // 0x8003BB44: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    func_8003BA90(rdram, ctx);
        goto after_0;
    // 0x8003BB44: sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003BB48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BB4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BB50: jr          $ra
    // 0x8003BB54: nop

    return;
    // 0x8003BB54: nop

;}
RECOMP_FUNC void func_80069E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069E98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80069E9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069EA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069EA4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069EA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80069EAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80069EB0: jal         0x80069D84
    // 0x80069EB4: sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
    func_80069D84(rdram, ctx);
        goto after_0;
    // 0x80069EB4: sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
    after_0:
    // 0x80069EB8: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    // 0x80069EBC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80069EC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80069EC4: beq         $a2, $zero, L_80069EF8
    if (ctx->r6 == 0) {
        // 0x80069EC8: lui         $a3, 0x8006
        ctx->r7 = S32(0X8006 << 16);
            goto L_80069EF8;
    }
    // 0x80069EC8: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80069ECC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80069ED0: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80069ED4: jal         0x800675D0
    // 0x80069ED8: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x80069ED8: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    after_1:
    // 0x80069EDC: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x80069EE0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80069EE4: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x80069EE8: srl         $t9, $t8, 3
    ctx->r25 = S32(U32(ctx->r24) >> 3);
    // 0x80069EEC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80069EF0: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x80069EF4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80069EF8:
    // 0x80069EF8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80069EFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80069F00: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80069F04: beq         $v0, $zero, L_80069F4C
    if (ctx->r2 == 0) {
        // 0x80069F08: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80069F4C;
    }
    // 0x80069F08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80069F0C: addiu       $t1, $v0, 0x7
    ctx->r9 = ADD32(ctx->r2, 0X7);
    // 0x80069F10: srl         $t2, $t1, 3
    ctx->r10 = S32(U32(ctx->r9) >> 3);
    // 0x80069F14: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80069F18: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80069F1C: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
    // 0x80069F20: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80069F24: jal         0x800675D0
    // 0x80069F28: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x80069F28: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    after_2:
    // 0x80069F2C: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
    // 0x80069F30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80069F34: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80069F38: bne         $t4, $zero, L_80069F4C
    if (ctx->r12 != 0) {
        // 0x80069F3C: sw          $a0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r4;
            goto L_80069F4C;
    }
    // 0x80069F3C: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    // 0x80069F40: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80069F44: jal         0x80071380
    // 0x80069F48: addiu       $a0, $a0, 0xF20
    ctx->r4 = ADD32(ctx->r4, 0XF20);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x80069F48: addiu       $a0, $a0, 0xF20
    ctx->r4 = ADD32(ctx->r4, 0XF20);
    after_3:
L_80069F4C:
    // 0x80069F4C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80069F50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80069F54: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80069F58: beq         $v0, $zero, L_80069F88
    if (ctx->r2 == 0) {
        // 0x80069F5C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80069F88;
    }
    // 0x80069F5C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80069F60: addiu       $t5, $v0, 0x7
    ctx->r13 = ADD32(ctx->r2, 0X7);
    // 0x80069F64: srl         $t6, $t5, 3
    ctx->r14 = S32(U32(ctx->r13) >> 3);
    // 0x80069F68: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80069F6C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80069F70: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x80069F74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80069F78: jal         0x800675D0
    // 0x80069F7C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    func_800675D0(rdram, ctx);
        goto after_4;
    // 0x80069F7C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    after_4:
    // 0x80069F80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80069F84: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
L_80069F88:
    // 0x80069F88: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80069F8C: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80069F90: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80069F94: beq         $a1, $zero, L_80069FA8
    if (ctx->r5 == 0) {
        // 0x80069F98: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80069FA8;
    }
    // 0x80069F98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80069F9C: jal         0x800675D0
    // 0x80069FA0: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    func_800675D0(rdram, ctx);
        goto after_5;
    // 0x80069FA0: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    after_5:
    // 0x80069FA4: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
L_80069FA8:
    // 0x80069FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80069FAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069FB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80069FB4: jr          $ra
    // 0x80069FB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80069FB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80446634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446634: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446638: jr          $ra
    // 0x8044663C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    return;
    // 0x8044663C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80446B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446B28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80446B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446B30: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446B34: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80446B38: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131FC) << 16);
    // 0x80446B3C: sw          $a1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r5;
    // 0x80446B40: sw          $a1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r5;
    // 0x80446B44: lw          $v1, 0x75DC($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131FC));
    // 0x80446B48: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80446B4C: beql        $v1, $zero, L_80446B64
    if (ctx->r3 == 0) {
        // 0x80446B50: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80446B64;
    }
    goto skip_0;
    // 0x80446B50: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_0:
    // 0x80446B54: jalr        $v1
    // 0x80446B58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446B58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80446B5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80446B60: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80446B64:
    // 0x80446B64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446B68: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80446B6C: sw          $t6, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r14;
    // 0x80446B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80446B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80446B78: jr          $ra
    // 0x80446B7C: nop

    return;
    // 0x80446B7C: nop

;}
RECOMP_FUNC void func_80049724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049724: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80049728: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8004972C: lbu         $t6, 0xF6D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF6D);
    // 0x80049730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049738: bnel        $t6, $zero, L_80049770
    if (ctx->r14 != 0) {
        // 0x8004973C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049770;
    }
    goto skip_0;
    // 0x8004973C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80049740: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80049744: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80049748: bnel        $t7, $at, L_80049770
    if (ctx->r15 != ctx->r1) {
        // 0x8004974C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049770;
    }
    goto skip_1;
    // 0x8004974C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80049750: jal         0x800492C0
    // 0x80049754: addiu       $a0, $zero, -0x73
    ctx->r4 = ADD32(0, -0X73);
    func_800492C0(rdram, ctx);
        goto after_0;
    // 0x80049754: addiu       $a0, $zero, -0x73
    ctx->r4 = ADD32(0, -0X73);
    after_0:
    // 0x80049758: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8004975C: beq         $v0, $zero, L_8004976C
    if (ctx->r2 == 0) {
        // 0x80049760: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_8004976C;
    }
    // 0x80049760: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80049764: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80049768: sb          $t8, 0xF6D($v1)
    MEM_B(0XF6D, ctx->r3) = ctx->r24;
L_8004976C:
    // 0x8004976C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049770:
    // 0x80049770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049774: jr          $ra
    // 0x80049778: nop

    return;
    // 0x80049778: nop

;}
RECOMP_FUNC void func_8004E4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E4C4: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x8004E4C8: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004E4CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004E4D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004E4D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004E4D8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004E4DC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8004E4E0: lw          $v0, 0x40($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X40);
    // 0x8004E4E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004E4E8: mflo        $t7
    ctx->r15 = lo;
    // 0x8004E4EC: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x8004E4F0: addu        $t9, $t0, $v1
    ctx->r25 = ADD32(ctx->r8, ctx->r3);
    // 0x8004E4F4: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004E4F8: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8004E4FC: mflo        $t8
    ctx->r24 = lo;
    // 0x8004E500: addu        $t1, $v0, $t8
    ctx->r9 = ADD32(ctx->r2, ctx->r24);
    // 0x8004E504: addu        $t3, $t1, $v1
    ctx->r11 = ADD32(ctx->r9, ctx->r3);
    // 0x8004E508: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8004E50C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8004E510: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8004E514: jal         0x80065954
    // 0x8004E518: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8004E518: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8004E51C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8004E520: jal         0x80065954
    // 0x8004E524: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8004E524: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8004E528: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004E52C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004E530: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8004E534: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8004E538: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8004E53C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004E540: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004E544: bc1f        L_8004E560
    if (!c1cs) {
        // 0x8004E548: addu        $v0, $t5, $v1
        ctx->r2 = ADD32(ctx->r13, ctx->r3);
            goto L_8004E560;
    }
    // 0x8004E548: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x8004E54C: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8004E550: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8004E554: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004E558: b           L_8004E56C
    // 0x8004E55C: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
        goto L_8004E56C;
    // 0x8004E55C: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
L_8004E560:
    // 0x8004E560: lwc1        $f18, 0x3C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8004E564: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004E568: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
L_8004E56C:
    // 0x8004E56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004E570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004E574: jr          $ra
    // 0x8004E578: nop

    return;
    // 0x8004E578: nop

;}
RECOMP_FUNC void func_806D7A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D7A20: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806D7A24: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806D7A28: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806D7A2C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806D7A30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806D7A34: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806D7A38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D7A3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806D7A40: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806D7A44: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(622, 0X1B1C) << 16);
    // 0x806D7A48: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806D7A4C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D7A50: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806D7A54: lw          $t1, -0x7934($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(622, 0X1B1C));
    // 0x806D7A58: jr          $ra
    // 0x806D7A5C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806D7A5C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8006E3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E3D0: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E3D4: addiu       $v0, $v0, -0x1C20
    ctx->r2 = ADD32(ctx->r2, -0X1C20);
    // 0x8006E3D8: jr          $ra
    // 0x8006E3DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E3DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804251D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804251D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804251D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804251DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804251E0: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x804251E4: jal         0x80051194
    // 0x804251E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804251E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x804251EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804251F0: jal         0x804234C0
    // 0x804251F4: sw          $v0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r2;
    func_804234C0(rdram, ctx);
        goto after_1;
    // 0x804251F4: sw          $v0, 0x168($a0)
    MEM_W(0X168, ctx->r4) = ctx->r2;
    after_1:
    // 0x804251F8: bne         $v0, $zero, L_80425208
    if (ctx->r2 != 0) {
        // 0x804251FC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80425208;
    }
    // 0x804251FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80425200: b           L_80425230
    // 0x80425204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80425230;
    // 0x80425204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80425208:
    // 0x80425208: lw          $t8, 0x16C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X16C);
    // 0x8042520C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80425210: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80425214: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X31C8) << 16);
    // 0x80425218: sw          $t6, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r14;
    // 0x8042521C: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x80425220: addiu       $t7, $t7, 0x5BC8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X31C8));
    // 0x80425224: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80425228: sw          $zero, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = 0;
    // 0x8042522C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80425230:
    // 0x80425230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80425234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80425238: jr          $ra
    // 0x8042523C: nop

    return;
    // 0x8042523C: nop

;}
RECOMP_FUNC void func_805614FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805614FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80561500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80561504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80561508: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8056150C: addiu       $at, $zero, 0x41CA
    ctx->r1 = ADD32(0, 0X41CA);
    // 0x80561510: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80561514: beq         $v0, $at, L_80561540
    if (ctx->r2 == ctx->r1) {
        // 0x80561518: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80561540;
    }
    // 0x80561518: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8056151C: addiu       $at, $zero, 0x41CB
    ctx->r1 = ADD32(0, 0X41CB);
    // 0x80561520: beq         $v0, $at, L_80561540
    if (ctx->r2 == ctx->r1) {
        // 0x80561524: addiu       $at, $zero, 0x41CC
        ctx->r1 = ADD32(0, 0X41CC);
            goto L_80561540;
    }
    // 0x80561524: addiu       $at, $zero, 0x41CC
    ctx->r1 = ADD32(0, 0X41CC);
    // 0x80561528: beq         $v0, $at, L_805615B4
    if (ctx->r2 == ctx->r1) {
        // 0x8056152C: addiu       $at, $zero, 0x41CD
        ctx->r1 = ADD32(0, 0X41CD);
            goto L_805615B4;
    }
    // 0x8056152C: addiu       $at, $zero, 0x41CD
    ctx->r1 = ADD32(0, 0X41CD);
    // 0x80561530: beql        $v0, $at, L_805615B8
    if (ctx->r2 == ctx->r1) {
        // 0x80561534: lwc1        $f8, 0xC8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_805615B8;
    }
    goto skip_0;
    // 0x80561534: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x80561538: b           L_80561628
    // 0x8056153C: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
        goto L_80561628;
    // 0x8056153C: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
L_80561540:
    // 0x80561540: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80561544: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80561548: nop

    // 0x8056154C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80561550: nop

    // 0x80561554: bc1fl       L_8056158C
    if (!c1cs) {
        // 0x80561558: lw          $t8, 0x87C($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X87C);
            goto L_8056158C;
    }
    goto skip_1;
    // 0x80561558: lw          $t8, 0x87C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X87C);
    skip_1:
    // 0x8056155C: lw          $t6, 0x87C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X87C);
    // 0x80561560: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80561564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80561568: beql        $t6, $at, L_80561628
    if (ctx->r14 == ctx->r1) {
        // 0x8056156C: lh          $t4, 0x1F0($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X1F0);
            goto L_80561628;
    }
    goto skip_2;
    // 0x8056156C: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
    skip_2:
    // 0x80561570: jal         0x805614C0
    // 0x80561574: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805614C0(rdram, ctx);
        goto after_0;
    // 0x80561574: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80561578: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8056157C: addiu       $t7, $zero, 0x43
    ctx->r15 = ADD32(0, 0X43);
    // 0x80561580: b           L_80561624
    // 0x80561584: sw          $t7, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r15;
        goto L_80561624;
    // 0x80561584: sw          $t7, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r15;
    // 0x80561588: lw          $t8, 0x87C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X87C);
L_8056158C:
    // 0x8056158C: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80561590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80561594: beql        $t8, $at, L_80561628
    if (ctx->r24 == ctx->r1) {
        // 0x80561598: lh          $t4, 0x1F0($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X1F0);
            goto L_80561628;
    }
    goto skip_3;
    // 0x80561598: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
    skip_3:
    // 0x8056159C: jal         0x805614C0
    // 0x805615A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805614C0(rdram, ctx);
        goto after_1;
    // 0x805615A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x805615A4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805615A8: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x805615AC: b           L_80561624
    // 0x805615B0: sw          $t9, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r25;
        goto L_80561624;
    // 0x805615B0: sw          $t9, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r25;
L_805615B4:
    // 0x805615B4: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
L_805615B8:
    // 0x805615B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x805615BC: nop

    // 0x805615C0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805615C4: nop

    // 0x805615C8: bc1fl       L_80561600
    if (!c1cs) {
        // 0x805615CC: lw          $t2, 0x87C($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X87C);
            goto L_80561600;
    }
    goto skip_4;
    // 0x805615CC: lw          $t2, 0x87C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X87C);
    skip_4:
    // 0x805615D0: lw          $t0, 0x87C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X87C);
    // 0x805615D4: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x805615D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805615DC: beql        $t0, $at, L_80561628
    if (ctx->r8 == ctx->r1) {
        // 0x805615E0: lh          $t4, 0x1F0($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X1F0);
            goto L_80561628;
    }
    goto skip_5;
    // 0x805615E0: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
    skip_5:
    // 0x805615E4: jal         0x805614C0
    // 0x805615E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805614C0(rdram, ctx);
        goto after_2;
    // 0x805615E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x805615EC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805615F0: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
    // 0x805615F4: b           L_80561624
    // 0x805615F8: sw          $t1, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r9;
        goto L_80561624;
    // 0x805615F8: sw          $t1, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r9;
    // 0x805615FC: lw          $t2, 0x87C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X87C);
L_80561600:
    // 0x80561600: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80561604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80561608: beql        $t2, $at, L_80561628
    if (ctx->r10 == ctx->r1) {
        // 0x8056160C: lh          $t4, 0x1F0($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X1F0);
            goto L_80561628;
    }
    goto skip_6;
    // 0x8056160C: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
    skip_6:
    // 0x80561610: jal         0x805614C0
    // 0x80561614: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805614C0(rdram, ctx);
        goto after_3;
    // 0x80561614: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80561618: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8056161C: addiu       $t3, $zero, 0x42
    ctx->r11 = ADD32(0, 0X42);
    // 0x80561620: sw          $t3, 0x87C($v1)
    MEM_W(0X87C, ctx->r3) = ctx->r11;
L_80561624:
    // 0x80561624: lh          $t4, 0x1F0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1F0);
L_80561628:
    // 0x80561628: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8056162C: bnel        $t4, $at, L_80561660
    if (ctx->r12 != ctx->r1) {
        // 0x80561630: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_80561660;
    }
    goto skip_7;
    // 0x80561630: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_7:
    // 0x80561634: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80561638: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8056163C: jal         0x80067BBC
    // 0x80561640: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80561640: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x80561644: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80561648: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8056164C: jal         0x80067F78
    // 0x80561650: lw          $a0, 0x87C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X87C);
    func_80067F78(rdram, ctx);
        goto after_5;
    // 0x80561650: lw          $a0, 0x87C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X87C);
    after_5:
    // 0x80561654: b           L_80561680
    // 0x80561658: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80561680;
    // 0x80561658: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8056165C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_80561660:
    // 0x80561660: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80561664: jal         0x80067BBC
    // 0x80561668: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x80561668: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x8056166C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80561670: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80561674: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80561678: jal         0x800678F0
    // 0x8056167C: lw          $a0, 0x87C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X87C);
    func_800678F0(rdram, ctx);
        goto after_7;
    // 0x8056167C: lw          $a0, 0x87C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X87C);
    after_7:
L_80561680:
    // 0x80561680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80561684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80561688: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8056168C: jr          $ra
    // 0x80561690: nop

    return;
    // 0x80561690: nop

;}
RECOMP_FUNC void func_80574060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574060: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80574064: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80574068: lw          $t6, 0x3EC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3EC);
    // 0x8057406C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80574070: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80574074: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80574078: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8057407C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80574080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80574084: bne         $a1, $at, L_805740A0
    if (ctx->r5 != ctx->r1) {
        // 0x80574088: lbu         $v0, 0x598($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X598);
            goto L_805740A0;
    }
    // 0x80574088: lbu         $v0, 0x598($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X598);
    // 0x8057408C: jal         0x80573F94
    // 0x80574090: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80573F94(rdram, ctx);
        goto after_0;
    // 0x80574090: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80574094: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80574098: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057409C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_805740A0:
    // 0x805740A0: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x805740A4: beq         $v0, $at, L_80574144
    if (ctx->r2 == ctx->r1) {
        // 0x805740A8: slti        $at, $v0, 0xA2
        ctx->r1 = SIGNED(ctx->r2) < 0XA2 ? 1 : 0;
            goto L_80574144;
    }
    // 0x805740A8: slti        $at, $v0, 0xA2
    ctx->r1 = SIGNED(ctx->r2) < 0XA2 ? 1 : 0;
    // 0x805740AC: bne         $at, $zero, L_805740BC
    if (ctx->r1 != 0) {
        // 0x805740B0: slti        $at, $v0, 0xA6
        ctx->r1 = SIGNED(ctx->r2) < 0XA6 ? 1 : 0;
            goto L_805740BC;
    }
    // 0x805740B0: slti        $at, $v0, 0xA6
    ctx->r1 = SIGNED(ctx->r2) < 0XA6 ? 1 : 0;
    // 0x805740B4: bnel        $at, $zero, L_80574148
    if (ctx->r1 != 0) {
        // 0x805740B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80574148;
    }
    goto skip_0;
    // 0x805740B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_805740BC:
    // 0x805740BC: lw          $a0, 0xB30($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB30);
    // 0x805740C0: jal         0x800495AC
    // 0x805740C4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800495AC(rdram, ctx);
        goto after_1;
    // 0x805740C4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x805740C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805740CC: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x805740D0: bnel        $at, $zero, L_80574148
    if (ctx->r1 != 0) {
        // 0x805740D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80574148;
    }
    goto skip_1;
    // 0x805740D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805740D8: jal         0x8004700C
    // 0x805740DC: nop

    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x805740DC: nop

    after_2:
    // 0x805740E0: beq         $v0, $zero, L_80574144
    if (ctx->r2 == 0) {
        // 0x805740E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80574144;
    }
    // 0x805740E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805740E8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805740EC: lw          $t8, -0x7BAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BAC);
    // 0x805740F0: addiu       $t9, $t8, -0x9
    ctx->r25 = ADD32(ctx->r24, -0X9);
    // 0x805740F4: sltiu       $at, $t9, 0x10
    ctx->r1 = ctx->r25 < 0X10 ? 1 : 0;
    // 0x805740F8: beq         $at, $zero, L_8057412C
    if (ctx->r1 == 0) {
        // 0x805740FC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8057412C;
    }
    // 0x805740FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80574100: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEA0) << 16);
    // 0x80574104: addu        $at, $at, $t9
    gpr jr_addend_8057410C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80574108: lw          $t9, 0x4D30($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(381, 0XEA0));
    // 0x8057410C: jr          $t9
    // 0x80574110: nop

    switch (jr_addend_8057410C >> 2) {
        case 0: goto L_80574114; break;
        case 1: goto L_80574114; break;
        case 2: goto L_80574114; break;
        case 3: goto L_80574114; break;
        case 4: goto L_8057412C; break;
        case 5: goto L_8057412C; break;
        case 6: goto L_8057412C; break;
        case 7: goto L_8057412C; break;
        case 8: goto L_8057412C; break;
        case 9: goto L_8057412C; break;
        case 10: goto L_8057412C; break;
        case 11: goto L_8057412C; break;
        case 12: goto L_80574114; break;
        case 13: goto L_80574114; break;
        case 14: goto L_80574114; break;
        case 15: goto L_80574114; break;
        default: switch_error(__func__, 0x8057410C, 0x80574D30);
    }
    // 0x80574110: nop

L_80574114:
    // 0x80574114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80574118: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8057411C: jal         0x8002F7AC
    // 0x80574120: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    func_8002F7AC(rdram, ctx);
        goto after_3;
    // 0x80574120: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_3:
    // 0x80574124: b           L_8057413C
    // 0x80574128: nop

        goto L_8057413C;
    // 0x80574128: nop

L_8057412C:
    // 0x8057412C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80574130: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80574134: jal         0x8002F7AC
    // 0x80574138: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_8002F7AC(rdram, ctx);
        goto after_4;
    // 0x80574138: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_4:
L_8057413C:
    // 0x8057413C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80574140: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
L_80574144:
    // 0x80574144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80574148:
    // 0x80574148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057414C: jr          $ra
    // 0x80574150: nop

    return;
    // 0x80574150: nop

;}
RECOMP_FUNC void func_8003AA10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AA10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AA18: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8003AA1C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003AA20: lwc1        $f6, 0x84($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X84);
    // 0x8003AA24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003AA28: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003AA2C: jal         0x8003A620
    // 0x8003AA30: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003AA30: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8003AA34: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003AA38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003AA3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003AA40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8003AA44: nop

    // 0x8003AA48: bc1fl       L_8003AA5C
    if (!c1cs) {
        // 0x8003AA4C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8003AA5C;
    }
    goto skip_0;
    // 0x8003AA4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x8003AA50: b           L_8003AA6C
    // 0x8003AA54: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
        goto L_8003AA6C;
    // 0x8003AA54: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8003AA58: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8003AA5C:
    // 0x8003AA5C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003AA60: bc1fl       L_8003AA70
    if (!c1cs) {
        // 0x8003AA64: lwc1        $f12, 0xC8($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_8003AA70;
    }
    goto skip_1;
    // 0x8003AA64: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    skip_1:
    // 0x8003AA68: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
L_8003AA6C:
    // 0x8003AA6C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
L_8003AA70:
    // 0x8003AA70: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8003AA74: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8003AA78: jal         0x80065ABC
    // 0x8003AA7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8003AA7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003AA80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003AA84: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8003AA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AA8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AA90: jr          $ra
    // 0x8003AA94: nop

    return;
    // 0x8003AA94: nop

;}
RECOMP_FUNC void func_8041E20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E20C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041E210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E214: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8041E218: jal         0x80045A34
    // 0x8041E21C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8041E21C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x8041E220: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8041E224: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8041E228: bne         $v0, $zero, L_8041E238
    if (ctx->r2 != 0) {
        // 0x8041E22C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8041E238;
    }
    // 0x8041E22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E230: b           L_8041E23C
    // 0x8041E234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8041E23C;
    // 0x8041E234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8041E238:
    // 0x8041E238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8041E23C:
    // 0x8041E23C: jr          $ra
    // 0x8041E240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8041E240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805333A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805333A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805333A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805333AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805333B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805333B4: jal         0x80533878
    // 0x805333B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80533878(rdram, ctx);
        goto after_0;
    // 0x805333B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805333BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805333C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805333C4: jr          $ra
    // 0x805333C8: nop

    return;
    // 0x805333C8: nop

;}
RECOMP_FUNC void func_8074179C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8074179C: jr          $ra
    // 0x807417A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807417A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8046CE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CE9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046CEA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046CEA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046CEA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046CEAC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046CEB0: jal         0x80048F84
    // 0x8046CEB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046CEB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8046CEB8: jal         0x8046C850
    // 0x8046CEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046CEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046CEC0: beql        $v0, $zero, L_8046CF1C
    if (ctx->r2 == 0) {
        // 0x8046CEC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046CF1C;
    }
    goto skip_0;
    // 0x8046CEC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8046CEC8: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x8046CECC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8046CED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CED4: beq         $t6, $at, L_8046CF00
    if (ctx->r14 == ctx->r1) {
        // 0x8046CED8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8046CF00;
    }
    // 0x8046CED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CEDC: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x8046CEE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CEE8: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8046CEEC: sw          $t8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r24;
    // 0x8046CEF0: jal         0x8046D3E8
    // 0x8046CEF4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046CEF4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x8046CEF8: b           L_8046CF1C
    // 0x8046CEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046CF1C;
    // 0x8046CEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046CF00:
    // 0x8046CF00: jal         0x8046D3E8
    // 0x8046CF04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8046D3E8(rdram, ctx);
        goto after_3;
    // 0x8046CF04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8046CF08: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CF0C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8046CF10: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CF14: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8046CF18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046CF1C:
    // 0x8046CF1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046CF20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046CF24: jr          $ra
    // 0x8046CF28: nop

    return;
    // 0x8046CF28: nop

;}
RECOMP_FUNC void func_80799B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799B94: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80799B98: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80799B9C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80799BA0: lw          $v0, 0x40($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X40);
    // 0x80799BA4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80799BA8: andi        $t9, $t8, 0xF8
    ctx->r25 = ctx->r24 & 0XF8;
    // 0x80799BAC: bnel        $v1, $t9, L_80799BC0
    if (ctx->r3 != ctx->r25) {
        // 0x80799BB0: lbu         $t0, 0x18($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X18);
            goto L_80799BC0;
    }
    goto skip_0;
    // 0x80799BB0: lbu         $t0, 0x18($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X18);
    skip_0:
    // 0x80799BB4: jr          $ra
    // 0x80799BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80799BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80799BBC: lbu         $t0, 0x18($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X18);
L_80799BC0:
    // 0x80799BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80799BC4: andi        $t1, $t0, 0xF8
    ctx->r9 = ctx->r8 & 0XF8;
    // 0x80799BC8: bne         $v1, $t1, L_80799BD8
    if (ctx->r3 != ctx->r9) {
        // 0x80799BCC: nop
    
            goto L_80799BD8;
    }
    // 0x80799BCC: nop

    // 0x80799BD0: jr          $ra
    // 0x80799BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80799BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80799BD8:
    // 0x80799BD8: jr          $ra
    // 0x80799BDC: nop

    return;
    // 0x80799BDC: nop

;}
RECOMP_FUNC void func_8000ED48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ED48: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000ED4C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000ED50: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8000ED54: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8000ED58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000ED5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000ED60: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000ED64: jr          $ra
    // 0x8000ED68: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8000ED68: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80669D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80669D80: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80669D84: addiu       $at, $zero, 0x4555
    ctx->r1 = ADD32(0, 0X4555);
    // 0x80669D88: beq         $v0, $at, L_80669DA8
    if (ctx->r2 == ctx->r1) {
        // 0x80669D8C: addiu       $at, $zero, 0x455B
        ctx->r1 = ADD32(0, 0X455B);
            goto L_80669DA8;
    }
    // 0x80669D8C: addiu       $at, $zero, 0x455B
    ctx->r1 = ADD32(0, 0X455B);
    // 0x80669D90: beq         $v0, $at, L_80669DB4
    if (ctx->r2 == ctx->r1) {
        // 0x80669D94: addiu       $at, $zero, 0x455C
        ctx->r1 = ADD32(0, 0X455C);
            goto L_80669DB4;
    }
    // 0x80669D94: addiu       $at, $zero, 0x455C
    ctx->r1 = ADD32(0, 0X455C);
    // 0x80669D98: beq         $v0, $at, L_80669DC0
    if (ctx->r2 == ctx->r1) {
        // 0x80669D9C: nop
    
            goto L_80669DC0;
    }
    // 0x80669D9C: nop

    // 0x80669DA0: b           L_80669DCC
    // 0x80669DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80669DCC;
    // 0x80669DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80669DA8:
    // 0x80669DA8: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(511, 0X918) << 16);
    // 0x80669DAC: jr          $ra
    // 0x80669DB0: addiu       $v0, $v0, -0x5968
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(511, 0X918));
    return;
    // 0x80669DB0: addiu       $v0, $v0, -0x5968
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(511, 0X918));
L_80669DB4:
    // 0x80669DB4: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(511, 0X918) << 16);
    // 0x80669DB8: jr          $ra
    // 0x80669DBC: addiu       $v0, $v0, -0x5968
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(511, 0X918));
    return;
    // 0x80669DBC: addiu       $v0, $v0, -0x5968
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(511, 0X918));
L_80669DC0:
    // 0x80669DC0: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(511, 0X918) << 16);
    // 0x80669DC4: jr          $ra
    // 0x80669DC8: addiu       $v0, $v0, -0x5968
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(511, 0X918));
    return;
    // 0x80669DC8: addiu       $v0, $v0, -0x5968
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(511, 0X918));
L_80669DCC:
    // 0x80669DCC: jr          $ra
    // 0x80669DD0: nop

    return;
    // 0x80669DD0: nop

;}
RECOMP_FUNC void func_8046895C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046895C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80468960: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80468964: lw          $v1, -0x260C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X260C);
    // 0x80468968: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8046896C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80468970: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80468974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80468978: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8046897C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80468980: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80468984: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    // 0x80468988: addiu       $t2, $t2, -0x200
    ctx->r10 = ADD32(ctx->r10, -0X200);
    // 0x8046898C: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80468990: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80468994: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80468998: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8046899C: addiu       $a3, $zero, -0x80
    ctx->r7 = ADD32(0, -0X80);
    // 0x804689A0: addiu       $a2, $zero, -0x60
    ctx->r6 = ADD32(0, -0X60);
    // 0x804689A4: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x804689A8: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
L_804689AC:
    // 0x804689AC: sh          $a2, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r6;
    // 0x804689B0: sh          $a2, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r6;
    // 0x804689B4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x804689B8: slti        $at, $a2, 0xA0
    ctx->r1 = SIGNED(ctx->r6) < 0XA0 ? 1 : 0;
    // 0x804689BC: sh          $a3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r7;
    // 0x804689C0: sh          $a3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r7;
    // 0x804689C4: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x804689C8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x804689CC: sh          $a0, -0x40($v0)
    MEM_H(-0X40, ctx->r2) = ctx->r4;
    // 0x804689D0: sh          $zero, -0x3C($v0)
    MEM_H(-0X3C, ctx->r2) = 0;
    // 0x804689D4: sh          $zero, -0x3A($v0)
    MEM_H(-0X3A, ctx->r2) = 0;
    // 0x804689D8: sh          $zero, -0x38($v0)
    MEM_H(-0X38, ctx->r2) = 0;
    // 0x804689DC: sh          $zero, -0x36($v0)
    MEM_H(-0X36, ctx->r2) = 0;
    // 0x804689E0: sb          $v1, -0x34($v0)
    MEM_B(-0X34, ctx->r2) = ctx->r3;
    // 0x804689E4: sb          $v1, -0x33($v0)
    MEM_B(-0X33, ctx->r2) = ctx->r3;
    // 0x804689E8: sb          $v1, -0x32($v0)
    MEM_B(-0X32, ctx->r2) = ctx->r3;
    // 0x804689EC: sb          $v1, -0x31($v0)
    MEM_B(-0X31, ctx->r2) = ctx->r3;
    // 0x804689F0: sh          $a1, -0x30($v0)
    MEM_H(-0X30, ctx->r2) = ctx->r5;
    // 0x804689F4: sh          $zero, -0x2C($v0)
    MEM_H(-0X2C, ctx->r2) = 0;
    // 0x804689F8: sh          $zero, -0x2A($v0)
    MEM_H(-0X2A, ctx->r2) = 0;
    // 0x804689FC: sh          $t0, -0x28($v0)
    MEM_H(-0X28, ctx->r2) = ctx->r8;
    // 0x80468A00: sh          $zero, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = 0;
    // 0x80468A04: sb          $v1, -0x24($v0)
    MEM_B(-0X24, ctx->r2) = ctx->r3;
    // 0x80468A08: sb          $v1, -0x23($v0)
    MEM_B(-0X23, ctx->r2) = ctx->r3;
    // 0x80468A0C: sb          $v1, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r3;
    // 0x80468A10: sb          $v1, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r3;
    // 0x80468A14: sh          $a0, -0x20($v0)
    MEM_H(-0X20, ctx->r2) = ctx->r4;
    // 0x80468A18: sh          $zero, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = 0;
    // 0x80468A1C: sh          $zero, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = 0;
    // 0x80468A20: sh          $zero, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = 0;
    // 0x80468A24: sh          $t1, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = ctx->r9;
    // 0x80468A28: sb          $v1, -0x14($v0)
    MEM_B(-0X14, ctx->r2) = ctx->r3;
    // 0x80468A2C: sb          $v1, -0x13($v0)
    MEM_B(-0X13, ctx->r2) = ctx->r3;
    // 0x80468A30: sb          $v1, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r3;
    // 0x80468A34: sb          $v1, -0x11($v0)
    MEM_B(-0X11, ctx->r2) = ctx->r3;
    // 0x80468A38: sh          $a1, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r5;
    // 0x80468A3C: sh          $zero, -0xC($v0)
    MEM_H(-0XC, ctx->r2) = 0;
    // 0x80468A40: sh          $zero, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = 0;
    // 0x80468A44: sh          $t0, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r8;
    // 0x80468A48: sh          $t1, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r9;
    // 0x80468A4C: sb          $v1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r3;
    // 0x80468A50: sb          $v1, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r3;
    // 0x80468A54: sb          $v1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r3;
    // 0x80468A58: bne         $at, $zero, L_804689AC
    if (ctx->r1 != 0) {
        // 0x80468A5C: sb          $v1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r3;
            goto L_804689AC;
    }
    // 0x80468A5C: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
    // 0x80468A60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468A64: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80468A68: ori         $t7, $t7, 0x81FF
    ctx->r15 = ctx->r15 | 0X81FF;
    // 0x80468A6C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468A70: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468A74: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80468A78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80468A7C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80468A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80468A84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80468A88: lw          $t0, 0x168($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X168);
    // 0x80468A8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80468A90: lw          $s1, 0x80($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X80);
    // 0x80468A94: jal         0x8007711C
    // 0x80468A98: lw          $a3, 0x88($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X88);
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x80468A98: lw          $a3, 0x88($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X88);
    after_0:
    // 0x80468A9C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468AA0: lui         $s2, 0xE600
    ctx->r18 = S32(0XE600 << 16);
    // 0x80468AA4: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80468AA8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468AAC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468AB0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468AB4: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80468AB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468ABC: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80468AC0: lui         $ra, 0xBF00
    ctx->r31 = S32(0XBF00 << 16);
    // 0x80468AC4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468AC8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468ACC: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x80468AD0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80468AD4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468AD8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80468ADC: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x80468AE0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468AE4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468AE8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80468AEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80468AF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468AF4: lui         $t6, 0x70F
    ctx->r14 = S32(0X70F << 16);
    // 0x80468AF8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x80468AFC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468B00: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468B04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468B08: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80468B0C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468B10: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80468B14: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80468B18: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468B1C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468B20: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80468B24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80468B28: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468B2C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80468B30: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80468B34: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468B38: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468B3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468B40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80468B44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468B48: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80468B4C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80468B50: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468B54: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468B58: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468B5C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80468B60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468B64: lui         $t9, 0x3
    ctx->r25 = S32(0X3 << 16);
    // 0x80468B68: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x80468B6C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468B70: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468B74: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80468B78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80468B7C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468B80: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80468B84: ori         $t7, $t7, 0xA0C
    ctx->r15 = ctx->r15 | 0XA0C;
    // 0x80468B88: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468B8C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468B90: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468B94: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468B98: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468B9C: lui         $t9, 0xA
    ctx->r25 = S32(0XA << 16);
    // 0x80468BA0: ori         $t9, $t9, 0xE0C
    ctx->r25 = ctx->r25 | 0XE0C;
    // 0x80468BA4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468BA8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468BAC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80468BB0: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468BB4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468BB8: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x80468BBC: ori         $t7, $t7, 0x1214
    ctx->r15 = ctx->r15 | 0X1214;
    // 0x80468BC0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468BC4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468BC8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468BCC: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468BD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468BD4: lui         $t9, 0x12
    ctx->r25 = S32(0X12 << 16);
    // 0x80468BD8: ori         $t9, $t9, 0x1614
    ctx->r25 = ctx->r25 | 0X1614;
    // 0x80468BDC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468BE0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468BE4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80468BE8: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468BEC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468BF0: addiu       $a2, $v0, 0x2
    ctx->r6 = ADD32(ctx->r2, 0X2);
    // 0x80468BF4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80468BF8: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80468BFC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468C00: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468C04: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80468C08: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x80468C0C: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x80468C10: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80468C14: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80468C18: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80468C1C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468C20: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468C24: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468C28: addiu       $t6, $v0, 0x6
    ctx->r14 = ADD32(ctx->r2, 0X6);
    // 0x80468C2C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80468C30: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468C34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468C38: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80468C3C: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80468C40: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80468C44: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80468C48: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468C4C: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468C50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468C54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80468C58: addiu       $t0, $v0, 0xA
    ctx->r8 = ADD32(ctx->r2, 0XA);
    // 0x80468C5C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468C60: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468C64: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x80468C68: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80468C6C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80468C70: sll         $t9, $t0, 8
    ctx->r25 = S32(ctx->r8 << 8);
    // 0x80468C74: addiu       $t1, $v0, 0xC
    ctx->r9 = ADD32(ctx->r2, 0XC);
    // 0x80468C78: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x80468C7C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80468C80: or          $t6, $t8, $t1
    ctx->r14 = ctx->r24 | ctx->r9;
    // 0x80468C84: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80468C88: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468C8C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468C90: addiu       $t8, $v0, 0xE
    ctx->r24 = ADD32(ctx->r2, 0XE);
    // 0x80468C94: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80468C98: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468C9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468CA0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80468CA4: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x80468CA8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80468CAC: or          $t6, $t8, $t1
    ctx->r14 = ctx->r24 | ctx->r9;
    // 0x80468CB0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80468CB4: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468CB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468CBC: addiu       $t7, $v0, 0x10
    ctx->r15 = ADD32(ctx->r2, 0X10);
    // 0x80468CC0: addiu       $t2, $v0, 0x12
    ctx->r10 = ADD32(ctx->r2, 0X12);
    // 0x80468CC4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468CC8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468CCC: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x80468CD0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80468CD4: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80468CD8: sll         $t9, $t2, 8
    ctx->r25 = S32(ctx->r10 << 8);
    // 0x80468CDC: addiu       $t3, $v0, 0x14
    ctx->r11 = ADD32(ctx->r2, 0X14);
    // 0x80468CE0: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x80468CE4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80468CE8: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x80468CEC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80468CF0: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468CF4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468CF8: addiu       $t7, $v0, 0x16
    ctx->r15 = ADD32(ctx->r2, 0X16);
    // 0x80468CFC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80468D00: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468D04: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468D08: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x80468D0C: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x80468D10: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80468D14: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x80468D18: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80468D1C: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468D20: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468D24: addiu       $t6, $v0, 0x18
    ctx->r14 = ADD32(ctx->r2, 0X18);
    // 0x80468D28: addiu       $t4, $v0, 0x1A
    ctx->r12 = ADD32(ctx->r2, 0X1A);
    // 0x80468D2C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468D30: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468D34: andi        $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 & 0XFF;
    // 0x80468D38: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80468D3C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80468D40: sll         $t9, $t4, 8
    ctx->r25 = S32(ctx->r12 << 8);
    // 0x80468D44: addiu       $t5, $v0, 0x1C
    ctx->r13 = ADD32(ctx->r2, 0X1C);
    // 0x80468D48: andi        $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 & 0XFF;
    // 0x80468D4C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80468D50: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x80468D54: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468D58: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468D5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468D60: addiu       $t6, $v0, 0x1E
    ctx->r14 = ADD32(ctx->r2, 0X1E);
    // 0x80468D64: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80468D68: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468D6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468D70: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80468D74: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x80468D78: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80468D7C: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x80468D80: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468D84: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468D88: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80468D8C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468D90: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80468D94: lw          $t9, 0x168($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X168);
    // 0x80468D98: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468D9C: lw          $s1, 0x80($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X80);
    // 0x80468DA0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468DA4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468DA8: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80468DAC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468DB0: addiu       $s1, $s1, 0x400
    ctx->r17 = ADD32(ctx->r17, 0X400);
    // 0x80468DB4: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x80468DB8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468DBC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468DC0: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x80468DC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80468DC8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468DCC: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80468DD0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468DD4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468DD8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80468DDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80468DE0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468DE4: lui         $t6, 0x70F
    ctx->r14 = S32(0X70F << 16);
    // 0x80468DE8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x80468DEC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468DF0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468DF4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468DF8: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80468DFC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468E00: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80468E04: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468E08: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468E0C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80468E10: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80468E14: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468E18: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80468E1C: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80468E20: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468E24: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468E28: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468E2C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80468E30: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468E34: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80468E38: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80468E3C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468E40: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468E44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468E48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80468E4C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468E50: lui         $t8, 0x3
    ctx->r24 = S32(0X3 << 16);
    // 0x80468E54: ori         $t8, $t8, 0xC07C
    ctx->r24 = ctx->r24 | 0XC07C;
    // 0x80468E58: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468E5C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468E60: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80468E64: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80468E68: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468E6C: addiu       $t7, $zero, 0x204
    ctx->r15 = ADD32(0, 0X204);
    // 0x80468E70: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80468E74: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468E78: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468E7C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468E80: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468E84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80468E88: ori         $t8, $t8, 0x604
    ctx->r24 = ctx->r24 | 0X604;
    // 0x80468E8C: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80468E90: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468E94: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80468E98: sw          $ra, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r31;
    // 0x80468E9C: lw          $t6, 0x168($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X168);
    // 0x80468EA0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468EA4: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x80468EA8: lw          $s1, 0x80($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X80);
    // 0x80468EAC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468EB0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468EB4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468EB8: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80468EBC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468EC0: addiu       $s1, $s1, 0x200
    ctx->r17 = ADD32(ctx->r17, 0X200);
    // 0x80468EC4: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x80468EC8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468ECC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468ED0: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x80468ED4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80468ED8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468EDC: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80468EE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468EE4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468EE8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80468EEC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80468EF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468EF4: lui         $t9, 0x70F
    ctx->r25 = S32(0X70F << 16);
    // 0x80468EF8: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x80468EFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468F00: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468F04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468F08: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80468F0C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468F10: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80468F14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468F18: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468F1C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80468F20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80468F24: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468F28: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80468F2C: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x80468F30: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468F34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468F38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468F3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80468F40: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468F44: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80468F48: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80468F4C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80468F50: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80468F54: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80468F58: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80468F5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468F60: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x80468F64: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x80468F68: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80468F6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80468F70: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468F74: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80468F78: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468F7C: lui         $t8, 0x38
    ctx->r24 = S32(0X38 << 16);
    // 0x80468F80: ori         $t8, $t8, 0x3A3C
    ctx->r24 = ctx->r24 | 0X3A3C;
    // 0x80468F84: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80468F88: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80468F8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80468F90: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468F94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80468F98: lui         $t7, 0x3A
    ctx->r15 = S32(0X3A << 16);
    // 0x80468F9C: ori         $t7, $t7, 0x3E3C
    ctx->r15 = ctx->r15 | 0X3E3C;
    // 0x80468FA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80468FA4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80468FA8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80468FAC: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80468FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80468FB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80468FB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80468FBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80468FC0: jr          $ra
    // 0x80468FC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80468FC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005D420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D420: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005D424: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005D428: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8005D42C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005D430: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005D434: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005D438: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005D43C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005D440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D444: lui         $t6, 0xA000
    ctx->r14 = S32(0XA000 << 16);
    // 0x8005D448: lw          $t7, 0x2B8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2B8);
    // 0x8005D44C: lui         $at, 0x8941
    ctx->r1 = S32(0X8941 << 16);
    // 0x8005D450: ori         $at, $at, 0x680C
    ctx->r1 = ctx->r1 | 0X680C;
    // 0x8005D454: xor         $t8, $t7, $at
    ctx->r24 = ctx->r15 ^ ctx->r1;
    // 0x8005D458: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8005D45C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005D460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005D464: sw          $t8, 0x62F0($at)
    MEM_W(0X62F0, ctx->r1) = ctx->r24;
    // 0x8005D468: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x8005D46C: jal         0x80065728
    // 0x8005D470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8005D470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005D474: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005D478: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005D47C: lw          $t9, 0x3EC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3EC);
    // 0x8005D480: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x8005D484: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x8005D488: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8005D48C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8005D490: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8005D494: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8005D498: addiu       $t2, $t1, 0x8D4
    ctx->r10 = ADD32(ctx->r9, 0X8D4);
    // 0x8005D49C: sw          $t2, 0x8D0($v0)
    MEM_W(0X8D0, ctx->r2) = ctx->r10;
    // 0x8005D4A0: lw          $s5, 0x0($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X0);
    // 0x8005D4A4: addiu       $s6, $s6, -0x7DC8
    ctx->r22 = ADD32(ctx->r22, -0X7DC8);
    // 0x8005D4A8: addiu       $s4, $s4, -0x7F58
    ctx->r20 = ADD32(ctx->r20, -0X7F58);
    // 0x8005D4AC: addiu       $s3, $zero, 0x190
    ctx->r19 = ADD32(0, 0X190);
L_8005D4B0:
    // 0x8005D4B0: addiu       $s0, $s5, 0x4
    ctx->r16 = ADD32(ctx->r21, 0X4);
    // 0x8005D4B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005D4B8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_8005D4BC:
    // 0x8005D4BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D4C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005D4C4: jal         0x80058110
    // 0x8005D4C8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_80058110(rdram, ctx);
        goto after_1;
    // 0x8005D4C8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x8005D4CC: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
    // 0x8005D4D0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8005D4D4: bne         $s1, $s3, L_8005D4BC
    if (ctx->r17 != ctx->r19) {
        // 0x8005D4D8: addiu       $s2, $s2, 0x50
        ctx->r18 = ADD32(ctx->r18, 0X50);
            goto L_8005D4BC;
    }
    // 0x8005D4D8: addiu       $s2, $s2, 0x50
    ctx->r18 = ADD32(ctx->r18, 0X50);
    // 0x8005D4DC: addiu       $s4, $s4, 0x190
    ctx->r20 = ADD32(ctx->r20, 0X190);
    // 0x8005D4E0: bne         $s4, $s6, L_8005D4B0
    if (ctx->r20 != ctx->r22) {
        // 0x8005D4E4: addiu       $s5, $s5, 0x84
        ctx->r21 = ADD32(ctx->r21, 0X84);
            goto L_8005D4B0;
    }
    // 0x8005D4E4: addiu       $s5, $s5, 0x84
    ctx->r21 = ADD32(ctx->r21, 0X84);
    // 0x8005D4E8: jal         0x8005D518
    // 0x8005D4EC: nop

    func_8005D518(rdram, ctx);
        goto after_2;
    // 0x8005D4EC: nop

    after_2:
    // 0x8005D4F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005D4F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D4F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D4FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005D500: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005D504: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005D508: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D50C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005D510: jr          $ra
    // 0x8005D514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005D514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805D7F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D7F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D7F90: jal         0x80045A34
    // 0x805D7F94: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805D7F94: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_0:
    // 0x805D7F98: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805D7F9C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x805D7FA0: bne         $v0, $zero, L_805D7FB0
    if (ctx->r2 != 0) {
        // 0x805D7FA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D7FB0;
    }
    // 0x805D7FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D7FA8: b           L_805D7FB4
    // 0x805D7FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D7FB4;
    // 0x805D7FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D7FB0:
    // 0x805D7FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805D7FB4:
    // 0x805D7FB4: jr          $ra
    // 0x805D7FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805D7FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804A0FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A0FE0: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x804A0FE4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804A0FE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804A0FEC: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x804A0FF0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x804A0FF4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x804A0FF8: beq         $v0, $zero, L_804A1068
    if (ctx->r2 == 0) {
        // 0x804A0FFC: sub.s       $f12, $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_804A1068;
    }
    // 0x804A0FFC: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x804A1000: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A1004: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A1008: nop

    // 0x804A100C: bc1fl       L_804A106C
    if (!c1cs) {
        // 0x804A1010: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A106C;
    }
    goto skip_0;
    // 0x804A1010: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x804A1014: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A1018: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804A101C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804A1020: sub.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x804A1024: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A1028: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A102C: bc1fl       L_804A106C
    if (!c1cs) {
        // 0x804A1030: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A106C;
    }
    goto skip_1;
    // 0x804A1030: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x804A1034: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A1038: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x804A103C: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x804A1040: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A1044: nop

    // 0x804A1048: bc1fl       L_804A106C
    if (!c1cs) {
        // 0x804A104C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A106C;
    }
    goto skip_2;
    // 0x804A104C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x804A1050: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A1054: nop

    // 0x804A1058: bc1fl       L_804A106C
    if (!c1cs) {
        // 0x804A105C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A106C;
    }
    goto skip_3;
    // 0x804A105C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x804A1060: b           L_804A1310
    // 0x804A1064: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A1064: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_804A1068:
    // 0x804A1068: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A106C:
    // 0x804A106C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804A1070: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804A1074: beq         $v0, $zero, L_804A10DC
    if (ctx->r2 == 0) {
        // 0x804A1078: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_804A10DC;
    }
    // 0x804A1078: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A107C: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A1080: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A1084: nop

    // 0x804A1088: bc1fl       L_804A10E0
    if (!c1cs) {
        // 0x804A108C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A10E0;
    }
    goto skip_4;
    // 0x804A108C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_4:
    // 0x804A1090: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A1094: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x804A1098: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A109C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A10A0: bc1fl       L_804A10E0
    if (!c1cs) {
        // 0x804A10A4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A10E0;
    }
    goto skip_5;
    // 0x804A10A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_5:
    // 0x804A10A8: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A10AC: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x804A10B0: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x804A10B4: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A10B8: nop

    // 0x804A10BC: bc1fl       L_804A10E0
    if (!c1cs) {
        // 0x804A10C0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A10E0;
    }
    goto skip_6;
    // 0x804A10C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_6:
    // 0x804A10C4: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A10C8: nop

    // 0x804A10CC: bc1fl       L_804A10E0
    if (!c1cs) {
        // 0x804A10D0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A10E0;
    }
    goto skip_7;
    // 0x804A10D0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_7:
    // 0x804A10D4: b           L_804A1310
    // 0x804A10D8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A10D8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_804A10DC:
    // 0x804A10DC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A10E0:
    // 0x804A10E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A10E4: beql        $v0, $zero, L_804A1150
    if (ctx->r2 == 0) {
        // 0x804A10E8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1150;
    }
    goto skip_8;
    // 0x804A10E8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_8:
    // 0x804A10EC: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A10F0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A10F4: nop

    // 0x804A10F8: bc1fl       L_804A1150
    if (!c1cs) {
        // 0x804A10FC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1150;
    }
    goto skip_9;
    // 0x804A10FC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x804A1100: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A1104: sub.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x804A1108: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A110C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A1110: bc1fl       L_804A1150
    if (!c1cs) {
        // 0x804A1114: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1150;
    }
    goto skip_10;
    // 0x804A1114: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x804A1118: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A111C: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x804A1120: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x804A1124: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A1128: nop

    // 0x804A112C: bc1fl       L_804A1150
    if (!c1cs) {
        // 0x804A1130: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1150;
    }
    goto skip_11;
    // 0x804A1130: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_11:
    // 0x804A1134: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A1138: nop

    // 0x804A113C: bc1fl       L_804A1150
    if (!c1cs) {
        // 0x804A1140: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1150;
    }
    goto skip_12;
    // 0x804A1140: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_12:
    // 0x804A1144: b           L_804A1310
    // 0x804A1148: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A1148: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A114C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A1150:
    // 0x804A1150: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A1154: beql        $v0, $zero, L_804A11C0
    if (ctx->r2 == 0) {
        // 0x804A1158: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A11C0;
    }
    goto skip_13;
    // 0x804A1158: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_13:
    // 0x804A115C: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A1160: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A1164: nop

    // 0x804A1168: bc1fl       L_804A11C0
    if (!c1cs) {
        // 0x804A116C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A11C0;
    }
    goto skip_14;
    // 0x804A116C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_14:
    // 0x804A1170: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A1174: sub.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x804A1178: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A117C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A1180: bc1fl       L_804A11C0
    if (!c1cs) {
        // 0x804A1184: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A11C0;
    }
    goto skip_15;
    // 0x804A1184: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_15:
    // 0x804A1188: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A118C: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x804A1190: sub.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x804A1194: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x804A1198: nop

    // 0x804A119C: bc1fl       L_804A11C0
    if (!c1cs) {
        // 0x804A11A0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A11C0;
    }
    goto skip_16;
    // 0x804A11A0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_16:
    // 0x804A11A4: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A11A8: nop

    // 0x804A11AC: bc1fl       L_804A11C0
    if (!c1cs) {
        // 0x804A11B0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A11C0;
    }
    goto skip_17;
    // 0x804A11B0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_17:
    // 0x804A11B4: b           L_804A1310
    // 0x804A11B8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A11B8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A11BC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A11C0:
    // 0x804A11C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A11C4: beql        $v0, $zero, L_804A1230
    if (ctx->r2 == 0) {
        // 0x804A11C8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1230;
    }
    goto skip_18;
    // 0x804A11C8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_18:
    // 0x804A11CC: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A11D0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A11D4: nop

    // 0x804A11D8: bc1fl       L_804A1230
    if (!c1cs) {
        // 0x804A11DC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1230;
    }
    goto skip_19;
    // 0x804A11DC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_19:
    // 0x804A11E0: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A11E4: sub.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x804A11E8: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A11EC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A11F0: bc1fl       L_804A1230
    if (!c1cs) {
        // 0x804A11F4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1230;
    }
    goto skip_20;
    // 0x804A11F4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_20:
    // 0x804A11F8: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A11FC: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x804A1200: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x804A1204: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A1208: nop

    // 0x804A120C: bc1fl       L_804A1230
    if (!c1cs) {
        // 0x804A1210: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1230;
    }
    goto skip_21;
    // 0x804A1210: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_21:
    // 0x804A1214: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A1218: nop

    // 0x804A121C: bc1fl       L_804A1230
    if (!c1cs) {
        // 0x804A1220: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A1230;
    }
    goto skip_22;
    // 0x804A1220: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_22:
    // 0x804A1224: b           L_804A1310
    // 0x804A1228: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A1228: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A122C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A1230:
    // 0x804A1230: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A1234: beql        $v0, $zero, L_804A12A0
    if (ctx->r2 == 0) {
        // 0x804A1238: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A12A0;
    }
    goto skip_23;
    // 0x804A1238: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_23:
    // 0x804A123C: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A1240: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A1244: nop

    // 0x804A1248: bc1fl       L_804A12A0
    if (!c1cs) {
        // 0x804A124C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A12A0;
    }
    goto skip_24;
    // 0x804A124C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_24:
    // 0x804A1250: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A1254: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x804A1258: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A125C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A1260: bc1fl       L_804A12A0
    if (!c1cs) {
        // 0x804A1264: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A12A0;
    }
    goto skip_25;
    // 0x804A1264: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_25:
    // 0x804A1268: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A126C: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x804A1270: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x804A1274: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A1278: nop

    // 0x804A127C: bc1fl       L_804A12A0
    if (!c1cs) {
        // 0x804A1280: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A12A0;
    }
    goto skip_26;
    // 0x804A1280: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_26:
    // 0x804A1284: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A1288: nop

    // 0x804A128C: bc1fl       L_804A12A0
    if (!c1cs) {
        // 0x804A1290: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A12A0;
    }
    goto skip_27;
    // 0x804A1290: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_27:
    // 0x804A1294: b           L_804A1310
    // 0x804A1298: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A1298: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A129C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A12A0:
    // 0x804A12A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A12A4: beql        $v0, $zero, L_804A1310
    if (ctx->r2 == 0) {
        // 0x804A12A8: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A1310;
    }
    goto skip_28;
    // 0x804A12A8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_28:
    // 0x804A12AC: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A12B0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A12B4: nop

    // 0x804A12B8: bc1fl       L_804A1310
    if (!c1cs) {
        // 0x804A12BC: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A1310;
    }
    goto skip_29;
    // 0x804A12BC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_29:
    // 0x804A12C0: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A12C4: sub.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x804A12C8: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A12CC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A12D0: bc1fl       L_804A1310
    if (!c1cs) {
        // 0x804A12D4: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A1310;
    }
    goto skip_30;
    // 0x804A12D4: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_30:
    // 0x804A12D8: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A12DC: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x804A12E0: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x804A12E4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A12E8: nop

    // 0x804A12EC: bc1fl       L_804A1310
    if (!c1cs) {
        // 0x804A12F0: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A1310;
    }
    goto skip_31;
    // 0x804A12F0: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_31:
    // 0x804A12F4: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A12F8: nop

    // 0x804A12FC: bc1fl       L_804A1310
    if (!c1cs) {
        // 0x804A1300: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A1310;
    }
    goto skip_32;
    // 0x804A1300: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_32:
    // 0x804A1304: b           L_804A1310
    // 0x804A1308: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A1310;
    // 0x804A1308: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A130C: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_804A1310:
    // 0x804A1310: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804A1314: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x804A1318: jr          $ra
    // 0x804A131C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804A131C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80664CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80664CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80664CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80664CE8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80664CEC: addiu       $at, $zero, 0x454F
    ctx->r1 = ADD32(0, 0X454F);
    // 0x80664CF0: beq         $v0, $at, L_80664D18
    if (ctx->r2 == ctx->r1) {
        // 0x80664CF4: addiu       $at, $zero, 0x4551
        ctx->r1 = ADD32(0, 0X4551);
            goto L_80664D18;
    }
    // 0x80664CF4: addiu       $at, $zero, 0x4551
    ctx->r1 = ADD32(0, 0X4551);
    // 0x80664CF8: beq         $v0, $at, L_80664D28
    if (ctx->r2 == ctx->r1) {
        // 0x80664CFC: addiu       $at, $zero, 0x455A
        ctx->r1 = ADD32(0, 0X455A);
            goto L_80664D28;
    }
    // 0x80664CFC: addiu       $at, $zero, 0x455A
    ctx->r1 = ADD32(0, 0X455A);
    // 0x80664D00: bnel        $v0, $at, L_80664D34
    if (ctx->r2 != ctx->r1) {
        // 0x80664D04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80664D34;
    }
    goto skip_0;
    // 0x80664D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80664D08: jal         0x80664E18
    // 0x80664D0C: nop

    func_80664E18(rdram, ctx);
        goto after_0;
    // 0x80664D0C: nop

    after_0:
    // 0x80664D10: b           L_80664D34
    // 0x80664D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80664D34;
    // 0x80664D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80664D18:
    // 0x80664D18: jal         0x80666438
    // 0x80664D1C: nop

    func_80666438(rdram, ctx);
        goto after_1;
    // 0x80664D1C: nop

    after_1:
    // 0x80664D20: b           L_80664D34
    // 0x80664D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80664D34;
    // 0x80664D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80664D28:
    // 0x80664D28: jal         0x8066626C
    // 0x80664D2C: nop

    func_8066626C(rdram, ctx);
        goto after_2;
    // 0x80664D2C: nop

    after_2:
    // 0x80664D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80664D34:
    // 0x80664D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80664D38: jr          $ra
    // 0x80664D3C: nop

    return;
    // 0x80664D3C: nop

;}
RECOMP_FUNC void func_80031EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031EB4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031EB8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80031EBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80031EC0: lbu         $t6, 0x1B4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1B4);
    // 0x80031EC4: beql        $t6, $zero, L_80031EF4
    if (ctx->r14 == 0) {
        // 0x80031EC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80031EF4;
    }
    goto skip_0;
    // 0x80031EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80031ECC: jal         0x80062DD4
    // 0x80031ED0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80062DD4(rdram, ctx);
        goto after_0;
    // 0x80031ED0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031ED4: beq         $v0, $zero, L_80031EF0
    if (ctx->r2 == 0) {
        // 0x80031ED8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80031EF0;
    }
    // 0x80031ED8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80031EDC: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80031EE0: addiu       $t7, $t7, 0x1F00
    ctx->r15 = ADD32(ctx->r15, 0X1F00);
    // 0x80031EE4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80031EE8: sw          $t7, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r15;
    // 0x80031EEC: sw          $t8, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r24;
L_80031EF0:
    // 0x80031EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031EF4:
    // 0x80031EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031EF8: jr          $ra
    // 0x80031EFC: nop

    return;
    // 0x80031EFC: nop

;}
RECOMP_FUNC void func_80465CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465CAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80465CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465CB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80465CB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465CBC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80465CC0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80465CC4: addiu       $t7, $v0, 0xBA8
    ctx->r15 = ADD32(ctx->r2, 0XBA8);
    // 0x80465CC8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80465CCC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80465CD0: jal         0x80465C8C
    // 0x80465CD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80465C8C(rdram, ctx);
        goto after_0;
    // 0x80465CD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80465CD8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80465CDC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80465CE0: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(125, 0X165C) << 16);
    // 0x80465CE4: sw          $t8, 0x1750($v0)
    MEM_W(0X1750, ctx->r2) = ctx->r24;
    // 0x80465CE8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80465CEC: addiu       $t9, $t9, 0x5C2C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(125, 0X165C));
    // 0x80465CF0: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x80465CF4: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x80465CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465CFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80465D00: jr          $ra
    // 0x80465D04: nop

    return;
    // 0x80465D04: nop

;}
RECOMP_FUNC void func_80456E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456E04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80456E08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80456E0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80456E10: jal         0x80456D98
    // 0x80456E14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80456D98(rdram, ctx);
        goto after_0;
    // 0x80456E14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80456E18: jal         0x80455948
    // 0x80456E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455948(rdram, ctx);
        goto after_1;
    // 0x80456E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80456E20: jal         0x80455770
    // 0x80456E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455770(rdram, ctx);
        goto after_2;
    // 0x80456E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80456E28: jal         0x80455864
    // 0x80456E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455864(rdram, ctx);
        goto after_3;
    // 0x80456E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80456E30: jal         0x8044FD5C
    // 0x80456E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_4;
    // 0x80456E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80456E38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80456E3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80456E40: jal         0x80450490
    // 0x80456E44: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_5;
    // 0x80456E44: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_5:
    // 0x80456E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80456E50: jal         0x80457164
    // 0x80456E54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80457164(rdram, ctx);
        goto after_6;
    // 0x80456E54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80456E58: lui         $a3, 0xC40D
    ctx->r7 = S32(0XC40D << 16);
    // 0x80456E5C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80456E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456E64: lui         $a1, 0x4254
    ctx->r5 = S32(0X4254 << 16);
    // 0x80456E68: jal         0x80444AB4
    // 0x80456E6C: lui         $a2, 0x4268
    ctx->r6 = S32(0X4268 << 16);
    func_80444AB4(rdram, ctx);
        goto after_7;
    // 0x80456E6C: lui         $a2, 0x4268
    ctx->r6 = S32(0X4268 << 16);
    after_7:
    // 0x80456E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80456E74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80456E78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80456E7C: jr          $ra
    // 0x80456E80: nop

    return;
    // 0x80456E80: nop

;}
RECOMP_FUNC void func_800290B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800290BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800290C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800290C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800290C8: jal         0x80028BFC
    // 0x800290CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80028BFC(rdram, ctx);
        goto after_0;
    // 0x800290CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800290D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800290D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800290D8: jal         0x80028E80
    // 0x800290DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80028E80(rdram, ctx);
        goto after_1;
    // 0x800290DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800290E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800290E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800290E8: jr          $ra
    // 0x800290EC: nop

    return;
    // 0x800290EC: nop

;}
RECOMP_FUNC void func_80534D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534D24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80534D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80534D2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80534D30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80534D34: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80534D38: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534D3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80534D40: jal         0x80534B48
    // 0x80534D44: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80534B48(rdram, ctx);
        goto after_0;
    // 0x80534D44: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80534D48: lhu         $t6, 0xE($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XE);
    // 0x80534D4C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80534D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534D54: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80534D58: bne         $t7, $zero, L_80534D78
    if (ctx->r15 != 0) {
        // 0x80534D5C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80534D78;
    }
    // 0x80534D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534D60: beql        $v0, $zero, L_80534D7C
    if (ctx->r2 == 0) {
        // 0x80534D64: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80534D7C;
    }
    goto skip_0;
    // 0x80534D64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_0:
    // 0x80534D68: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x80534D6C: lhu         $t9, 0x119E($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X119E);
    // 0x80534D70: andi        $t0, $t9, 0x6
    ctx->r8 = ctx->r25 & 0X6;
    // 0x80534D74: bne         $t0, $zero, L_80534D8C
    if (ctx->r8 != 0) {
        // 0x80534D78: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80534D8C;
    }
L_80534D78:
    // 0x80534D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80534D7C:
    // 0x80534D7C: jal         0x805350A0
    // 0x80534D80: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_805350A0(rdram, ctx);
        goto after_1;
    // 0x80534D80: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x80534D84: b           L_80534D98
    // 0x80534D88: lw          $t1, 0x12C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X12C);
        goto L_80534D98;
    // 0x80534D88: lw          $t1, 0x12C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X12C);
L_80534D8C:
    // 0x80534D8C: jal         0x80534BB4
    // 0x80534D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534BB4(rdram, ctx);
        goto after_2;
    // 0x80534D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80534D94: lw          $t1, 0x12C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X12C);
L_80534D98:
    // 0x80534D98: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(348, 0X1038) << 16);
    // 0x80534D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534DA0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80534DA4: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80534DA8: lw          $t9, 0x5648($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(348, 0X1038));
    // 0x80534DAC: jalr        $t9
    // 0x80534DB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80534DB0: nop

    after_3:
    // 0x80534DB4: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x80534DB8: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
    // 0x80534DBC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80534DC0: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x80534DC4: bne         $at, $zero, L_80534DE4
    if (ctx->r1 != 0) {
        // 0x80534DC8: sw          $t4, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r12;
            goto L_80534DE4;
    }
    // 0x80534DC8: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x80534DCC: jal         0x800653D8
    // 0x80534DD0: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80534DD0: nop

    after_4:
    // 0x80534DD4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80534DD8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80534DDC: sh          $t7, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r15;
    // 0x80534DE0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_80534DE4:
    // 0x80534DE4: lhu         $t8, 0x10($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X10);
    // 0x80534DE8: beq         $t8, $zero, L_80534E10
    if (ctx->r24 == 0) {
        // 0x80534DEC: nop
    
            goto L_80534E10;
    }
    // 0x80534DEC: nop

    // 0x80534DF0: jal         0x805347F0
    // 0x80534DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805347F0(rdram, ctx);
        goto after_5;
    // 0x80534DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80534DF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534DFC: bne         $v0, $at, L_80534E10
    if (ctx->r2 != ctx->r1) {
        // 0x80534E00: nop
    
            goto L_80534E10;
    }
    // 0x80534E00: nop

    // 0x80534E04: lhu         $t0, 0x10($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X10);
    // 0x80534E08: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80534E0C: sh          $t1, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r9;
L_80534E10:
    // 0x80534E10: jal         0x8053484C
    // 0x80534E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8053484C(rdram, ctx);
        goto after_6;
    // 0x80534E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80534E18: jal         0x80534678
    // 0x80534E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534678(rdram, ctx);
        goto after_7;
    // 0x80534E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80534E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80534E24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80534E28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80534E2C: jr          $ra
    // 0x80534E30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80534E30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8040E824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E82C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8040E830: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8040E834: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(23, 0XCEC) << 16);
    // 0x8040E838: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040E83C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8040E840: lw          $t8, -0xB74($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(23, 0XCEC));
    // 0x8040E844: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8040E848: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8040E84C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8040E850: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8040E854: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8040E858: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8040E85C: beql        $v1, $zero, L_8040E890
    if (ctx->r3 == 0) {
        // 0x8040E860: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E890;
    }
    goto skip_0;
    // 0x8040E860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040E864: jalr        $v1
    // 0x8040E868: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8040E868: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040E86C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040E870: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8040E874: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8040E878: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8040E87C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8040E880: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8040E884: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8040E888: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8040E88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E890:
    // 0x8040E890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E894: jr          $ra
    // 0x8040E898: nop

    return;
    // 0x8040E898: nop

;}
RECOMP_FUNC void func_8000B2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2D4: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x8000B2D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B2DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000B2E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000B2E4: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000B2E8: bne         $t8, $at, L_8000B2FC
    if (ctx->r24 != ctx->r1) {
        // 0x8000B2EC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000B2FC;
    }
    // 0x8000B2EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000B2F0: lbu         $t9, 0xB0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XB0);
    // 0x8000B2F4: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x8000B2F8: sb          $t0, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r8;
L_8000B2FC:
    // 0x8000B2FC: lbu         $t1, 0xB0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XB0);
    // 0x8000B300: lbu         $t5, 0x60($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X60);
    // 0x8000B304: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8000B308: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x8000B30C: sb          $t2, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r10;
    // 0x8000B310: lbu         $t3, 0xB0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XB0);
    // 0x8000B314: andi        $t6, $t5, 0xFFF0
    ctx->r14 = ctx->r13 & 0XFFF0;
    // 0x8000B318: sb          $zero, 0x34($a0)
    MEM_B(0X34, ctx->r4) = 0;
    // 0x8000B31C: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x8000B320: sb          $t4, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r12;
    // 0x8000B324: sw          $v0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r2;
    // 0x8000B328: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x8000B32C: sb          $t6, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r14;
    // 0x8000B330: jr          $ra
    // 0x8000B334: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8000B334: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8051A680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051A684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A688: jal         0x8051A640
    // 0x8051A68C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8051A640(rdram, ctx);
        goto after_0;
    // 0x8051A68C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051A690: jal         0x80045BD8
    // 0x8051A694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8051A694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8051A698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051A69C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051A6A0: jr          $ra
    // 0x8051A6A4: nop

    return;
    // 0x8051A6A4: nop

;}
RECOMP_FUNC void func_804EEE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EEE64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EEE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EEE6C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804EEE70: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804EEE74: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X1050) << 16);
    // 0x804EEE78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EEE7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804EEE80: lw          $t8, -0x220($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(267, 0X1050));
    // 0x804EEE84: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804EEE88: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804EEE8C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804EEE90: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804EEE94: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804EEE98: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804EEE9C: beql        $v1, $zero, L_804EEED0
    if (ctx->r3 == 0) {
        // 0x804EEEA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804EEED0;
    }
    goto skip_0;
    // 0x804EEEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804EEEA4: jalr        $v1
    // 0x804EEEA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804EEEA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EEEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EEEB0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804EEEB4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804EEEB8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804EEEBC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804EEEC0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804EEEC4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804EEEC8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804EEECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EEED0:
    // 0x804EEED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EEED4: jr          $ra
    // 0x804EEED8: nop

    return;
    // 0x804EEED8: nop

;}
RECOMP_FUNC void func_80553934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553934: lwc1        $f4, 0xDB8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XDB8);
    // 0x80553938: jr          $ra
    // 0x8055393C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8055393C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80052860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052868: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005286C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80052870: addiu       $t7, $v0, 0x2C
    ctx->r15 = ADD32(ctx->r2, 0X2C);
    // 0x80052874: beq         $t7, $zero, L_80052888
    if (ctx->r15 == 0) {
        // 0x80052878: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80052888;
    }
    // 0x80052878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005287C: jal         0x8004A6AC
    // 0x80052880: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8004A6AC(rdram, ctx);
        goto after_0;
    // 0x80052880: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80052884: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80052888:
    // 0x80052888: jal         0x80064E84
    // 0x8005288C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8005288C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80052890: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80052894: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80052898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005289C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800528A0: jr          $ra
    // 0x800528A4: nop

    return;
    // 0x800528A4: nop

;}
RECOMP_FUNC void func_807C35A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C35A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C35AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C35B0: jal         0x807C3448
    // 0x807C35B4: nop

    func_807C3448(rdram, ctx);
        goto after_0;
    // 0x807C35B4: nop

    after_0:
    // 0x807C35B8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807C35BC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807C35C0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x807C35C4: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x807C35C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807C35CC: beq         $at, $zero, L_807C36A4
    if (ctx->r1 == 0) {
        // 0x807C35D0: sw          $t6, 0xF80($v1)
        MEM_W(0XF80, ctx->r3) = ctx->r14;
            goto L_807C36A4;
    }
    // 0x807C35D0: sw          $t6, 0xF80($v1)
    MEM_W(0XF80, ctx->r3) = ctx->r14;
    // 0x807C35D4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x807C35D8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(907, 0X1490) << 16);
    // 0x807C35DC: addu        $at, $at, $t7
    gpr jr_addend_807C35E4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x807C35E0: lw          $t7, 0x47F0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(907, 0X1490));
    // 0x807C35E4: jr          $t7
    // 0x807C35E8: nop

    switch (jr_addend_807C35E4 >> 2) {
        case 0: goto L_807C35EC; break;
        case 1: goto L_807C3604; break;
        case 2: goto L_807C361C; break;
        case 3: goto L_807C3634; break;
        case 4: goto L_807C364C; break;
        case 5: goto L_807C3664; break;
        case 6: goto L_807C367C; break;
        case 7: goto L_807C3694; break;
        default: switch_error(__func__, 0x807C35E4, 0x807C47F0);
    }
    // 0x807C35E8: nop

L_807C35EC:
    // 0x807C35EC: lw          $t8, 0xF54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XF54);
    // 0x807C35F0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x807C35F4: jal         0x807C3568
    // 0x807C35F8: sw          $t9, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r25;
    func_807C3568(rdram, ctx);
        goto after_1;
    // 0x807C35F8: sw          $t9, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r25;
    after_1:
    // 0x807C35FC: b           L_807C36A8
    // 0x807C3600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3604:
    // 0x807C3604: lw          $t0, 0xF54($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3608: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x807C360C: jal         0x807C3568
    // 0x807C3610: sw          $t1, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r9;
    func_807C3568(rdram, ctx);
        goto after_2;
    // 0x807C3610: sw          $t1, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r9;
    after_2:
    // 0x807C3614: b           L_807C36A8
    // 0x807C3618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C361C:
    // 0x807C361C: lw          $t2, 0xF54($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3620: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x807C3624: jal         0x807C3568
    // 0x807C3628: sw          $t3, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r11;
    func_807C3568(rdram, ctx);
        goto after_3;
    // 0x807C3628: sw          $t3, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r11;
    after_3:
    // 0x807C362C: b           L_807C36A8
    // 0x807C3630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3634:
    // 0x807C3634: lw          $t4, 0xF54($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3638: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x807C363C: jal         0x807C3568
    // 0x807C3640: sw          $t5, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r13;
    func_807C3568(rdram, ctx);
        goto after_4;
    // 0x807C3640: sw          $t5, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r13;
    after_4:
    // 0x807C3644: b           L_807C36A8
    // 0x807C3648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C364C:
    // 0x807C364C: lw          $t6, 0xF54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3650: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x807C3654: jal         0x807C3568
    // 0x807C3658: sw          $t7, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r15;
    func_807C3568(rdram, ctx);
        goto after_5;
    // 0x807C3658: sw          $t7, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r15;
    after_5:
    // 0x807C365C: b           L_807C36A8
    // 0x807C3660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3664:
    // 0x807C3664: lw          $t8, 0xF54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3668: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x807C366C: jal         0x807C3568
    // 0x807C3670: sw          $t9, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r25;
    func_807C3568(rdram, ctx);
        goto after_6;
    // 0x807C3670: sw          $t9, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r25;
    after_6:
    // 0x807C3674: b           L_807C36A8
    // 0x807C3678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C367C:
    // 0x807C367C: lw          $t0, 0xF54($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3680: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x807C3684: jal         0x807C3568
    // 0x807C3688: sw          $t1, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r9;
    func_807C3568(rdram, ctx);
        goto after_7;
    // 0x807C3688: sw          $t1, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r9;
    after_7:
    // 0x807C368C: b           L_807C36A8
    // 0x807C3690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C36A8;
    // 0x807C3690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C3694:
    // 0x807C3694: lw          $t2, 0xF54($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XF54);
    // 0x807C3698: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x807C369C: jal         0x807C3568
    // 0x807C36A0: sw          $t3, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r11;
    func_807C3568(rdram, ctx);
        goto after_8;
    // 0x807C36A0: sw          $t3, 0xF54($v1)
    MEM_W(0XF54, ctx->r3) = ctx->r11;
    after_8:
L_807C36A4:
    // 0x807C36A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C36A8:
    // 0x807C36A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807C36AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C36B0: jr          $ra
    // 0x807C36B4: nop

    return;
    // 0x807C36B4: nop

;}
RECOMP_FUNC void func_804270AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804270AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804270B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804270B4: jal         0x80426FCC
    // 0x804270B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80426FCC(rdram, ctx);
        goto after_0;
    // 0x804270B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804270BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804270C0: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(38, 0X1224) << 16);
    // 0x804270C4: lwc1        $f6, 0x7824($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(38, 0X1224));
    // 0x804270C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804270CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804270D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804270D4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804270D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804270DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804270E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804270E4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x804270E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804270EC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804270F0: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804270F4: nop

    // 0x804270F8: bc1fl       L_8042710C
    if (!c1cs) {
        // 0x804270FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042710C;
    }
    goto skip_0;
    // 0x804270FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80427100: jal         0x80427118
    // 0x80427104: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    func_80427118(rdram, ctx);
        goto after_1;
    // 0x80427104: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x80427108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042710C:
    // 0x8042710C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427110: jr          $ra
    // 0x80427114: nop

    return;
    // 0x80427114: nop

;}
RECOMP_FUNC void func_80566088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566088: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8056608C: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80566090: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x80566094: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80566098: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8056609C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x805660A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805660A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805660A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805660AC: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805660B0: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x805660B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805660B8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805660BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805660C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x805660C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805660C8: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x805660CC: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x805660D0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x805660D4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805660D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x805660DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805660E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805660E4: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x805660E8: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x805660EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x805660F0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x805660F4: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x805660F8: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x805660FC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80566100: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80566104: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80566108: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8056610C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80566110: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80566114: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80566118: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8056611C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80566120: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80566124: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x80566128: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8056612C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80566130: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80566134: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80566138: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x8056613C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80566140: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80566144: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80566148: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8056614C: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x80566150: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80566154: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80566158: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8056615C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80566160: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80566164: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80566168: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x8056616C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80566170: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80566174: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x80566178: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8056617C: jr          $ra
    // 0x80566180: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x80566180: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8004389C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004389C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800438A0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800438A4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800438A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800438AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800438B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800438B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800438B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800438BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800438C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800438C4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800438C8: addiu       $s4, $zero, 0x64
    ctx->r20 = ADD32(0, 0X64);
L_800438CC:
    // 0x800438CC: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x800438D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800438D4: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800438D8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800438DC: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800438E0: bnel        $s3, $t8, L_80043900
    if (ctx->r19 != ctx->r24) {
        // 0x800438E4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80043900;
    }
    goto skip_0;
    // 0x800438E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800438E8: jal         0x80057BAC
    // 0x800438EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057BAC(rdram, ctx);
        goto after_0;
    // 0x800438EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800438F0: lh          $t9, 0x6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X6);
    // 0x800438F4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800438F8: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
    // 0x800438FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80043900:
    // 0x80043900: bne         $s0, $s4, L_800438CC
    if (ctx->r16 != ctx->r20) {
        // 0x80043904: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800438CC;
    }
    // 0x80043904: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80043908: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8004390C: bnel        $t1, $zero, L_80043920
    if (ctx->r9 != 0) {
        // 0x80043910: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80043920;
    }
    goto skip_1;
    // 0x80043910: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80043914: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x80043918: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x8004391C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80043920:
    // 0x80043920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043924: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043928: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004392C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80043930: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043934: jr          $ra
    // 0x80043938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80043938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001F904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001F910: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001F914: jal         0x8001F560
    // 0x8001F918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8001F560(rdram, ctx);
        goto after_0;
    // 0x8001F918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001F91C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F920: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8001F924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001F928: lbu         $t6, 0x12($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X12);
    // 0x8001F92C: lw          $t2, 0x2C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X2C);
    // 0x8001F930: lbu         $t9, 0x111($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X111);
    // 0x8001F934: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8001F938: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8001F93C: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x8001F940: andi        $t3, $t2, 0x700
    ctx->r11 = ctx->r10 & 0X700;
    // 0x8001F944: sltu        $t4, $zero, $t3
    ctx->r12 = 0 < ctx->r11 ? 1 : 0;
    // 0x8001F948: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8001F94C: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8001F950: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8001F954: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8001F958: andi        $t9, $t7, 0x700
    ctx->r25 = ctx->r15 & 0X700;
    // 0x8001F95C: sltu        $t8, $zero, $t9
    ctx->r24 = 0 < ctx->r25 ? 1 : 0;
    // 0x8001F960: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8001F964: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8001F968: sltu        $t4, $zero, $t3
    ctx->r12 = 0 < ctx->r11 ? 1 : 0;
    // 0x8001F96C: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8001F970: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x8001F974: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x8001F978: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8001F97C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8001F980: lw          $t9, -0x6668($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6668);
    // 0x8001F984: jalr        $t9
    // 0x8001F988: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8001F988: nop

    after_1:
    // 0x8001F98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F994: jr          $ra
    // 0x8001F998: nop

    return;
    // 0x8001F998: nop

;}
RECOMP_FUNC void func_8057A7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057A7E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057A7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057A7E8: jal         0x8004700C
    // 0x8057A7EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8057A7EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057A7F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8057A7F4: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B30) << 16);
    // 0x8057A7F8: lwc1        $f4, -0x4A90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B30));
    // 0x8057A7FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8057A800: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x8057A804: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8057A808: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8057A80C: lbu         $a0, -0x7204($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7204);
    // 0x8057A810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8057A814: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8057A818: swc1        $f4, 0x228($v1)
    MEM_W(0X228, ctx->r3) = ctx->f4.u32l;
    // 0x8057A81C: swc1        $f6, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = ctx->f6.u32l;
    // 0x8057A820: beq         $a0, $at, L_8057A834
    if (ctx->r4 == ctx->r1) {
        // 0x8057A824: sb          $zero, 0x165($a1)
        MEM_B(0X165, ctx->r5) = 0;
            goto L_8057A834;
    }
    // 0x8057A824: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x8057A828: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8057A82C: bne         $a0, $at, L_8057A888
    if (ctx->r4 != ctx->r1) {
        // 0x8057A830: nop
    
            goto L_8057A888;
    }
    // 0x8057A830: nop

L_8057A834:
    // 0x8057A834: jal         0x8057A738
    // 0x8057A838: nop

    func_8057A738(rdram, ctx);
        goto after_1;
    // 0x8057A838: nop

    after_1:
    // 0x8057A83C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8057A840: beq         $v0, $at, L_8057A858
    if (ctx->r2 == ctx->r1) {
        // 0x8057A844: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8057A858;
    }
    // 0x8057A844: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8057A848: beq         $v0, $at, L_8057A868
    if (ctx->r2 == ctx->r1) {
        // 0x8057A84C: nop
    
            goto L_8057A868;
    }
    // 0x8057A84C: nop

    // 0x8057A850: b           L_8057A878
    // 0x8057A854: nop

        goto L_8057A878;
    // 0x8057A854: nop

L_8057A858:
    // 0x8057A858: jal         0x800677F8
    // 0x8057A85C: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    func_800677F8(rdram, ctx);
        goto after_2;
    // 0x8057A85C: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_2:
    // 0x8057A860: b           L_8057A8D4
    // 0x8057A864: nop

        goto L_8057A8D4;
    // 0x8057A864: nop

L_8057A868:
    // 0x8057A868: jal         0x800677F8
    // 0x8057A86C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x8057A86C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_3:
    // 0x8057A870: b           L_8057A8D4
    // 0x8057A874: nop

        goto L_8057A8D4;
    // 0x8057A874: nop

L_8057A878:
    // 0x8057A878: jal         0x800677F8
    // 0x8057A87C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x8057A87C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_4:
    // 0x8057A880: b           L_8057A8D4
    // 0x8057A884: nop

        goto L_8057A8D4;
    // 0x8057A884: nop

L_8057A888:
    // 0x8057A888: jal         0x8057A738
    // 0x8057A88C: nop

    func_8057A738(rdram, ctx);
        goto after_5;
    // 0x8057A88C: nop

    after_5:
    // 0x8057A890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8057A894: beq         $v0, $at, L_8057A8AC
    if (ctx->r2 == ctx->r1) {
        // 0x8057A898: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8057A8AC;
    }
    // 0x8057A898: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8057A89C: beq         $v0, $at, L_8057A8BC
    if (ctx->r2 == ctx->r1) {
        // 0x8057A8A0: nop
    
            goto L_8057A8BC;
    }
    // 0x8057A8A0: nop

    // 0x8057A8A4: b           L_8057A8CC
    // 0x8057A8A8: nop

        goto L_8057A8CC;
    // 0x8057A8A8: nop

L_8057A8AC:
    // 0x8057A8AC: jal         0x800677F8
    // 0x8057A8B0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    func_800677F8(rdram, ctx);
        goto after_6;
    // 0x8057A8B0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_6:
    // 0x8057A8B4: b           L_8057A8D4
    // 0x8057A8B8: nop

        goto L_8057A8D4;
    // 0x8057A8B8: nop

L_8057A8BC:
    // 0x8057A8BC: jal         0x800677F8
    // 0x8057A8C0: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_800677F8(rdram, ctx);
        goto after_7;
    // 0x8057A8C0: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_7:
    // 0x8057A8C4: b           L_8057A8D4
    // 0x8057A8C8: nop

        goto L_8057A8D4;
    // 0x8057A8C8: nop

L_8057A8CC:
    // 0x8057A8CC: jal         0x800677F8
    // 0x8057A8D0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800677F8(rdram, ctx);
        goto after_8;
    // 0x8057A8D0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_8:
L_8057A8D4:
    // 0x8057A8D4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8057A8D8: lw          $t6, -0x7B30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B30);
    // 0x8057A8DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8057A8E0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8057A8E4: bnel        $at, $zero, L_8057A91C
    if (ctx->r1 != 0) {
        // 0x8057A8E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057A91C;
    }
    goto skip_0;
    // 0x8057A8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057A8EC: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x8057A8F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8057A8F4: beql        $t7, $at, L_8057A91C
    if (ctx->r15 == ctx->r1) {
        // 0x8057A8F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057A91C;
    }
    goto skip_1;
    // 0x8057A8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8057A8FC: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8057A900: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8057A904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8057A908: beq         $t8, $at, L_8057A918
    if (ctx->r24 == ctx->r1) {
        // 0x8057A90C: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_8057A918;
    }
    // 0x8057A90C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8057A910: jal         0x8002F7AC
    // 0x8057A914: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    func_8002F7AC(rdram, ctx);
        goto after_9;
    // 0x8057A914: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_9:
L_8057A918:
    // 0x8057A918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057A91C:
    // 0x8057A91C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057A920: jr          $ra
    // 0x8057A924: nop

    return;
    // 0x8057A924: nop

;}
RECOMP_FUNC void func_80448E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80448E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448E20: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14054) << 16);
    // 0x80448E24: lwc1        $f4, -0x7BCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14054));
    // 0x80448E28: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80448E2C: lui         $at, 0x4425
    ctx->r1 = S32(0X4425 << 16);
    // 0x80448E30: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80448E34: nop

    // 0x80448E38: bc1fl       L_80448E64
    if (!c1cs) {
        // 0x80448E3C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80448E64;
    }
    goto skip_0;
    // 0x80448E3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80448E40: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80448E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448E48: beql        $v0, $t6, L_80448FA8
    if (ctx->r2 == ctx->r14) {
        // 0x80448E4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_1;
    // 0x80448E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448E50: jal         0x80445930
    // 0x80448E54: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_80445930(rdram, ctx);
        goto after_0;
    // 0x80448E54: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_0:
    // 0x80448E58: b           L_80448FA8
    // 0x80448E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448FA8;
    // 0x80448E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448E60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80448E64:
    // 0x80448E64: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14058) << 16);
    // 0x80448E68: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80448E6C: nop

    // 0x80448E70: bc1f        L_80448E98
    if (!c1cs) {
        // 0x80448E74: nop
    
            goto L_80448E98;
    }
    // 0x80448E74: nop

    // 0x80448E78: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x80448E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448E80: beql        $v0, $t7, L_80448FA8
    if (ctx->r2 == ctx->r15) {
        // 0x80448E84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_2;
    // 0x80448E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80448E88: jal         0x80445954
    // 0x80448E8C: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_1;
    // 0x80448E8C: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    after_1:
    // 0x80448E90: b           L_80448FA8
    // 0x80448E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448FA8;
    // 0x80448E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448E98:
    // 0x80448E98: lwc1        $f8, -0x7BC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14058));
    // 0x80448E9C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1405C) << 16);
    // 0x80448EA0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80448EA4: nop

    // 0x80448EA8: bc1f        L_80448ED0
    if (!c1cs) {
        // 0x80448EAC: nop
    
            goto L_80448ED0;
    }
    // 0x80448EAC: nop

    // 0x80448EB0: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x80448EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448EB8: beql        $v0, $t8, L_80448FA8
    if (ctx->r2 == ctx->r24) {
        // 0x80448EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_3;
    // 0x80448EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80448EC0: jal         0x80445954
    // 0x80448EC4: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_2;
    // 0x80448EC4: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    after_2:
    // 0x80448EC8: b           L_80448FA8
    // 0x80448ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448FA8;
    // 0x80448ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448ED0:
    // 0x80448ED0: lwc1        $f10, -0x7BC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1405C));
    // 0x80448ED4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14060) << 16);
    // 0x80448ED8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80448EDC: nop

    // 0x80448EE0: bc1f        L_80448F08
    if (!c1cs) {
        // 0x80448EE4: nop
    
            goto L_80448F08;
    }
    // 0x80448EE4: nop

    // 0x80448EE8: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80448EEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448EF0: beql        $v0, $t9, L_80448FA8
    if (ctx->r2 == ctx->r25) {
        // 0x80448EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_4;
    // 0x80448EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80448EF8: jal         0x80445954
    // 0x80448EFC: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_3;
    // 0x80448EFC: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    after_3:
    // 0x80448F00: b           L_80448FA8
    // 0x80448F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448FA8;
    // 0x80448F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448F08:
    // 0x80448F08: lwc1        $f16, -0x7BC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14060));
    // 0x80448F0C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80448F10: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80448F14: nop

    // 0x80448F18: bc1fl       L_80448F44
    if (!c1cs) {
        // 0x80448F1C: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80448F44;
    }
    goto skip_5;
    // 0x80448F1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_5:
    // 0x80448F20: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x80448F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448F28: beql        $v0, $t0, L_80448FA8
    if (ctx->r2 == ctx->r8) {
        // 0x80448F2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_6;
    // 0x80448F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80448F30: jal         0x80445954
    // 0x80448F34: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_4;
    // 0x80448F34: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    after_4:
    // 0x80448F38: b           L_80448FA8
    // 0x80448F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448FA8;
    // 0x80448F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80448F40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80448F44:
    // 0x80448F44: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14064) << 16);
    // 0x80448F48: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80448F4C: nop

    // 0x80448F50: bc1f        L_80448F78
    if (!c1cs) {
        // 0x80448F54: nop
    
            goto L_80448F78;
    }
    // 0x80448F54: nop

    // 0x80448F58: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x80448F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448F60: beql        $v0, $t1, L_80448FA8
    if (ctx->r2 == ctx->r9) {
        // 0x80448F64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_7;
    // 0x80448F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80448F68: jal         0x80445954
    // 0x80448F6C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_5;
    // 0x80448F6C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    after_5:
    // 0x80448F70: b           L_80448FA8
    // 0x80448F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448FA8;
    // 0x80448F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448F78:
    // 0x80448F78: lwc1        $f4, -0x7BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14064));
    // 0x80448F7C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80448F80: nop

    // 0x80448F84: bc1fl       L_80448FA8
    if (!c1cs) {
        // 0x80448F88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_8;
    // 0x80448F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80448F8C: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x80448F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448F94: beql        $v0, $t2, L_80448FA8
    if (ctx->r2 == ctx->r10) {
        // 0x80448F98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448FA8;
    }
    goto skip_9;
    // 0x80448F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80448F9C: jal         0x80445954
    // 0x80448FA0: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    func_80445954(rdram, ctx);
        goto after_6;
    // 0x80448FA0: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    after_6:
    // 0x80448FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448FA8:
    // 0x80448FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80448FAC: jr          $ra
    // 0x80448FB0: nop

    return;
    // 0x80448FB0: nop

;}
RECOMP_FUNC void func_805A6AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6AB0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x805A6AB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A6AB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A6ABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A6AC0: jal         0x80062684
    // 0x805A6AC4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x805A6AC4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x805A6AC8: lh          $a0, 0x184($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X184);
    // 0x805A6ACC: addiu       $v1, $s0, 0x188
    ctx->r3 = ADD32(ctx->r16, 0X188);
    // 0x805A6AD0: addiu       $a1, $zero, 0x4001
    ctx->r5 = ADD32(0, 0X4001);
    // 0x805A6AD4: beql        $a0, $zero, L_805A6BA4
    if (ctx->r4 == 0) {
        // 0x805A6AD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A6BA4;
    }
    goto skip_0;
    // 0x805A6AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_805A6ADC:
    // 0x805A6ADC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x805A6AE0: beq         $v0, $zero, L_805A6B98
    if (ctx->r2 == 0) {
        // 0x805A6AE4: nop
    
            goto L_805A6B98;
    }
    // 0x805A6AE4: nop

    // 0x805A6AE8: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x805A6AEC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x805A6AF0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x805A6AF4: bne         $a1, $t6, L_805A6B98
    if (ctx->r5 != ctx->r14) {
        // 0x805A6AF8: sra         $a0, $a0, 16
        ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
            goto L_805A6B98;
    }
    // 0x805A6AF8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x805A6AFC: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x805A6B00: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x805A6B04: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x805A6B08: beq         $t9, $zero, L_805A6B98
    if (ctx->r25 == 0) {
        // 0x805A6B0C: nop
    
            goto L_805A6B98;
    }
    // 0x805A6B0C: nop

    // 0x805A6B10: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x805A6B14: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805A6B18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805A6B1C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805A6B20: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x805A6B24: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805A6B28: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x805A6B2C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x805A6B30: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x805A6B34: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x805A6B38: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x805A6B3C: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805A6B40: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x805A6B44: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x805A6B48: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x805A6B4C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x805A6B50: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x805A6B54: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x805A6B58: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x805A6B5C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x805A6B60: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x805A6B64: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x805A6B68: lw          $t9, 0x10($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X10);
    // 0x805A6B6C: jalr        $t9
    // 0x805A6B70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805A6B70: nop

    after_1:
    // 0x805A6B74: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x805A6B78: jal         0x80061170
    // 0x805A6B7C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_80061170(rdram, ctx);
        goto after_2;
    // 0x805A6B7C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x805A6B80: jal         0x800447C8
    // 0x805A6B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x805A6B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A6B88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805A6B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A6B90: b           L_805A6BA0
    // 0x805A6B94: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
        goto L_805A6BA0;
    // 0x805A6B94: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
L_805A6B98:
    // 0x805A6B98: bne         $a0, $zero, L_805A6ADC
    if (ctx->r4 != 0) {
        // 0x805A6B9C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_805A6ADC;
    }
    // 0x805A6B9C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_805A6BA0:
    // 0x805A6BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A6BA4:
    // 0x805A6BA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A6BA8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x805A6BAC: jr          $ra
    // 0x805A6BB0: nop

    return;
    // 0x805A6BB0: nop

;}
RECOMP_FUNC void func_807C6C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6C84: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C6C88: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x807C6C8C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807C6C90: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(919, 0X270) << 16);
    // 0x807C6C94: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C6C98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x807C6C9C: lw          $t7, 0x6CB0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(919, 0X270));
    // 0x807C6CA0: jr          $ra
    // 0x807C6CA4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x807C6CA4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x807C6CA8: nop

    // 0x807C6CAC: nop

;}
RECOMP_FUNC void func_805ADE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADE14: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADE18: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADE1C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADE20: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADE24: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADE28: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADE2C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADE30: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADE34: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADE38: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADE3C: jr          $ra
    // 0x805ADE40: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADE40: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806814D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806814D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806814D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806814D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806814DC: jal         0x80045A34
    // 0x806814E0: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806814E0: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_0:
    // 0x806814E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806814E8: bne         $v0, $zero, L_806814F8
    if (ctx->r2 != 0) {
        // 0x806814EC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806814F8;
    }
    // 0x806814EC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806814F0: b           L_80681504
    // 0x806814F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80681504;
    // 0x806814F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806814F8:
    // 0x806814F8: jal         0x80681480
    // 0x806814FC: nop

    func_80681480(rdram, ctx);
        goto after_1;
    // 0x806814FC: nop

    after_1:
    // 0x80681500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80681504:
    // 0x80681504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80681508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8068150C: jr          $ra
    // 0x80681510: nop

    return;
    // 0x80681510: nop

;}
RECOMP_FUNC void Math_FFloorF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081C6C: jal         0x80081FE0
    // 0x80081C70: nop

    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x80081C70: nop

    after_0:
    // 0x80081C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081C7C: jr          $ra
    // 0x80081C80: nop

    return;
    // 0x80081C80: nop

;}
RECOMP_FUNC void func_804750F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804750F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804750F4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804750F8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804750FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475100: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475104: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475108: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047510C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475110: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475114: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475118: jr          $ra
    // 0x8047511C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047511C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80029774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029774: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80029778: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x8002977C: lw          $t1, 0xD0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XD0);
    // 0x80029780: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80029784: lw          $t8, 0xFC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XFC);
    // 0x80029788: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8002978C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80029790: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80029794: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80029798: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002979C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800297A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800297A4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800297A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800297AC: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800297B0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800297B4: lw          $t4, -0x218C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X218C);
    // 0x800297B8: lw          $t6, 0x38($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X38);
    // 0x800297BC: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x800297C0: lw          $t5, -0x21BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X21BC);
    // 0x800297C4: subu        $v0, $t6, $t4
    ctx->r2 = SUB32(ctx->r14, ctx->r12);
    // 0x800297C8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800297CC: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800297D0: bne         $at, $zero, L_8002983C
    if (ctx->r1 != 0) {
        // 0x800297D4: addu        $t8, $t8, $v1
        ctx->r24 = ADD32(ctx->r24, ctx->r3);
            goto L_8002983C;
    }
    // 0x800297D4: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800297D8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800297DC: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800297E0: lw          $t7, -0x21A4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X21A4);
    // 0x800297E4: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800297E8: beq         $at, $zero, L_80029824
    if (ctx->r1 == 0) {
        // 0x800297EC: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80029824;
    }
    // 0x800297EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800297F0: lwc1        $f4, -0x1CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1CC);
    // 0x800297F4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800297F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800297FC: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80029800: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029804: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80029808: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8002980C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80029810: nop

    // 0x80029814: bc1f        L_800298AC
    if (!c1cs) {
        // 0x80029818: nop
    
            goto L_800298AC;
    }
    // 0x80029818: nop

    // 0x8002981C: jr          $ra
    // 0x80029820: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80029820: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_80029824:
    // 0x80029824: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029828: nop

    // 0x8002982C: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x80029830: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80029834: jr          $ra
    // 0x80029838: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80029838: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_8002983C:
    // 0x8002983C: lw          $t8, -0x21EC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X21EC);
    // 0x80029840: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80029844: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80029848: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002984C: bne         $at, $zero, L_800298AC
    if (ctx->r1 != 0) {
        // 0x80029850: nop
    
            goto L_800298AC;
    }
    // 0x80029850: nop

    // 0x80029854: lw          $t9, -0x21D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X21D4);
    // 0x80029858: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002985C: beq         $at, $zero, L_80029898
    if (ctx->r1 == 0) {
        // 0x80029860: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80029898;
    }
    // 0x80029860: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029864: lwc1        $f10, -0x1C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C8);
    // 0x80029868: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8002986C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80029870: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80029874: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029878: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8002987C: lwc1        $f18, 0xC4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80029880: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80029884: nop

    // 0x80029888: bc1f        L_800298AC
    if (!c1cs) {
        // 0x8002988C: nop
    
            goto L_800298AC;
    }
    // 0x8002988C: nop

    // 0x80029890: jr          $ra
    // 0x80029894: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80029894: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_80029898:
    // 0x80029898: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002989C: nop

    // 0x800298A0: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x800298A4: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800298A8: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
L_800298AC:
    // 0x800298AC: jr          $ra
    // 0x800298B0: nop

    return;
    // 0x800298B0: nop

;}
RECOMP_FUNC void func_807B8C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8C78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B8C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8C80: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8C84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B8C88: jal         0x807B8AE4
    // 0x807B8C8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_807B8AE4(rdram, ctx);
        goto after_0;
    // 0x807B8C8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x807B8C90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B8C94: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8C98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x807B8C9C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807B8CA0: addiu       $t7, $t6, -0x5
    ctx->r15 = ADD32(ctx->r14, -0X5);
    // 0x807B8CA4: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x807B8CA8: beq         $at, $zero, L_807B8D20
    if (ctx->r1 == 0) {
        // 0x807B8CAC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_807B8D20;
    }
    // 0x807B8CAC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B8CB0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(886, 0X1DA4) << 16);
    // 0x807B8CB4: addu        $at, $at, $t7
    gpr jr_addend_807B8CBC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x807B8CB8: lw          $t7, -0x5FEC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(886, 0X1DA4));
    // 0x807B8CBC: jr          $t7
    // 0x807B8CC0: nop

    switch (jr_addend_807B8CBC >> 2) {
        case 0: goto L_807B8CC4; break;
        case 1: goto L_807B8CD8; break;
        case 2: goto L_807B8CEC; break;
        case 3: goto L_807B8D00; break;
        case 4: goto L_807B8D14; break;
        default: switch_error(__func__, 0x807B8CBC, 0x807BA014);
    }
    // 0x807B8CC0: nop

L_807B8CC4:
    // 0x807B8CC4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x807B8CC8: jal         0x807B8B70
    // 0x807B8CCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_807B8B70(rdram, ctx);
        goto after_1;
    // 0x807B8CCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x807B8CD0: b           L_807B8D24
    // 0x807B8CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B8D24;
    // 0x807B8CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8CD8:
    // 0x807B8CD8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x807B8CDC: jal         0x807B8B70
    // 0x807B8CE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_807B8B70(rdram, ctx);
        goto after_2;
    // 0x807B8CE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x807B8CE4: b           L_807B8D24
    // 0x807B8CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B8D24;
    // 0x807B8CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8CEC:
    // 0x807B8CEC: addiu       $a0, $v1, 0xC
    ctx->r4 = ADD32(ctx->r3, 0XC);
    // 0x807B8CF0: jal         0x807B8B70
    // 0x807B8CF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_807B8B70(rdram, ctx);
        goto after_3;
    // 0x807B8CF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x807B8CF8: b           L_807B8D24
    // 0x807B8CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B8D24;
    // 0x807B8CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8D00:
    // 0x807B8D00: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
    // 0x807B8D04: jal         0x807B8B70
    // 0x807B8D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_807B8B70(rdram, ctx);
        goto after_4;
    // 0x807B8D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x807B8D0C: b           L_807B8D24
    // 0x807B8D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B8D24;
    // 0x807B8D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8D14:
    // 0x807B8D14: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    // 0x807B8D18: jal         0x807B8BF4
    // 0x807B8D1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_807B8BF4(rdram, ctx);
        goto after_5;
    // 0x807B8D1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_807B8D20:
    // 0x807B8D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8D24:
    // 0x807B8D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B8D28: jr          $ra
    // 0x807B8D2C: nop

    return;
    // 0x807B8D2C: nop

;}
RECOMP_FUNC void func_80064F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F94: beq         $a0, $zero, L_80064FE0
    if (ctx->r4 == 0) {
        // 0x80064F98: sll         $t6, $a0, 4
        ctx->r14 = S32(ctx->r4 << 4);
            goto L_80064FE0;
    }
    // 0x80064F98: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80064F9C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80064FA0: bne         $t7, $zero, L_80064FE0
    if (ctx->r15 != 0) {
        // 0x80064FA4: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_80064FE0;
    }
    // 0x80064FA4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80064FA8: lw          $t8, -0x6C10($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6C10);
    // 0x80064FAC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80064FB0: sltu        $at, $a0, $t8
    ctx->r1 = ctx->r4 < ctx->r24 ? 1 : 0;
    // 0x80064FB4: bnel        $at, $zero, L_80064FE4
    if (ctx->r1 != 0) {
        // 0x80064FB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80064FE4;
    }
    goto skip_0;
    // 0x80064FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80064FBC: lw          $t9, -0x6C0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6C0C);
    // 0x80064FC0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80064FC4: sltu        $at, $a0, $t0
    ctx->r1 = ctx->r4 < ctx->r8 ? 1 : 0;
    // 0x80064FC8: beql        $at, $zero, L_80064FE4
    if (ctx->r1 == 0) {
        // 0x80064FCC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80064FE4;
    }
    goto skip_1;
    // 0x80064FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80064FD0: lhu         $v0, -0x10($a0)
    ctx->r2 = MEM_HU(ctx->r4, -0X10);
    // 0x80064FD4: xori        $v0, $v0, 0x913
    ctx->r2 = ctx->r2 ^ 0X913;
    // 0x80064FD8: jr          $ra
    // 0x80064FDC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80064FDC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80064FE0:
    // 0x80064FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80064FE4:
    // 0x80064FE4: jr          $ra
    // 0x80064FE8: nop

    return;
    // 0x80064FE8: nop

;}
RECOMP_FUNC void func_80791820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791820: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80791824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079182C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80791830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80791834: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80791838: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8079183C: lw          $t8, 0x88($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X88);
    // 0x80791840: jal         0x8004700C
    // 0x80791844: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80791844: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80791848: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8079184C: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x80791850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791854: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80791858: jal         0x80791690
    // 0x8079185C: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    func_80791690(rdram, ctx);
        goto after_1;
    // 0x8079185C: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    after_1:
    // 0x80791860: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80791864: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80791868: jal         0x807903C4
    // 0x8079186C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_2;
    // 0x8079186C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80791870: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x80791874: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80791878: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079187C: bne         $t1, $zero, L_8079189C
    if (ctx->r9 != 0) {
        // 0x80791880: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_8079189C;
    }
    // 0x80791880: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80791884: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x80791888: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079188C: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x80791890: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80791894: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80791898: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
L_8079189C:
    // 0x8079189C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x807918A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807918A4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x807918A8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x807918AC: lbu         $t8, 0x2C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2C);
    // 0x807918B0: beq         $t8, $zero, L_807918E4
    if (ctx->r24 == 0) {
        // 0x807918B4: nop
    
            goto L_807918E4;
    }
    // 0x807918B4: nop

    // 0x807918B8: jal         0x807907AC
    // 0x807918BC: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    func_807907AC(rdram, ctx);
        goto after_3;
    // 0x807918BC: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    after_3:
    // 0x807918C0: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x807918C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807918C8: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x807918CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807918D0: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x807918D4: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x807918D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807918DC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x807918E0: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_807918E4:
    // 0x807918E4: jal         0x80790714
    // 0x807918E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_4;
    // 0x807918E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807918EC: beq         $v0, $zero, L_807919B4
    if (ctx->r2 == 0) {
        // 0x807918F0: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_807919B4;
    }
    // 0x807918F0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x807918F4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x807918F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807918FC: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x80791900: lbu         $t5, 0x2C($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2C);
    // 0x80791904: beql        $t5, $zero, L_807919B8
    if (ctx->r13 == 0) {
        // 0x80791908: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807919B8;
    }
    goto skip_0;
    // 0x80791908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8079190C: jal         0x80790818
    // 0x80791910: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    func_80790818(rdram, ctx);
        goto after_5;
    // 0x80791910: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    after_5:
    // 0x80791914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791918: jal         0x8004590C
    // 0x8079191C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004590C(rdram, ctx);
        goto after_6;
    // 0x8079191C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80791920: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80791924: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x80791928: jal         0x80791690
    // 0x8079192C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80791690(rdram, ctx);
        goto after_7;
    // 0x8079192C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80791930: lw          $t7, 0x1E4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E4);
    // 0x80791934: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80791938: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079193C: beq         $t7, $zero, L_80791968
    if (ctx->r15 == 0) {
        // 0x80791940: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791968;
    }
    // 0x80791940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791944: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80791948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079194C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80791950: jal         0x8079393C
    // 0x80791954: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_8079393C(rdram, ctx);
        goto after_8;
    // 0x80791954: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_8:
    // 0x80791958: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8079195C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80791960: b           L_807919C0
    // 0x80791964: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
        goto L_807919C0;
    // 0x80791964: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
L_80791968:
    // 0x80791968: jal         0x807907AC
    // 0x8079196C: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    func_807907AC(rdram, ctx);
        goto after_9;
    // 0x8079196C: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    after_9:
    // 0x80791970: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80791974: sb          $t0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r8;
    // 0x80791978: jal         0x8002FFDC
    // 0x8079197C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8002FFDC(rdram, ctx);
        goto after_10;
    // 0x8079197C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80791980: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80791984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079198C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80791990: jal         0x8079393C
    // 0x80791994: lw          $a3, 0x68($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X68);
    func_8079393C(rdram, ctx);
        goto after_11;
    // 0x80791994: lw          $a3, 0x68($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X68);
    after_11:
    // 0x80791998: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8079199C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807919A0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807919A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807919A8: sb          $t2, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r10;
    // 0x807919AC: b           L_807919C0
    // 0x807919B0: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
        goto L_807919C0;
    // 0x807919B0: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
L_807919B4:
    // 0x807919B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807919B8:
    // 0x807919B8: jal         0x80790878
    // 0x807919BC: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    func_80790878(rdram, ctx);
        goto after_12;
    // 0x807919BC: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    after_12:
L_807919C0:
    // 0x807919C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807919C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807919C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x807919CC: jr          $ra
    // 0x807919D0: nop

    return;
    // 0x807919D0: nop

;}
RECOMP_FUNC void func_807907AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807907AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807907B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807907B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807907B8: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x807907BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807907C0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x807907C4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x807907C8: bnel        $at, $zero, L_807907DC
    if (ctx->r1 != 0) {
        // 0x807907CC: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_807907DC;
    }
    goto skip_0;
    // 0x807907CC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_0:
    // 0x807907D0: b           L_807907F0
    // 0x807907D4: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
        goto L_807907F0;
    // 0x807907D4: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
    // 0x807907D8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_807907DC:
    // 0x807907DC: beq         $at, $zero, L_807907F0
    if (ctx->r1 == 0) {
        // 0x807907E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_807907F0;
    }
    // 0x807907E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807907E4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x807907E8: b           L_807907F0
    // 0x807907EC: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
        goto L_807907F0;
    // 0x807907EC: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
L_807907F0:
    // 0x807907F0: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x807907F4: jal         0x80067D5C
    // 0x807907F8: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x807907F8: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_0:
    // 0x807907FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80790800: jal         0x80067818
    // 0x80790804: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80790804: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80790808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80790810: jr          $ra
    // 0x80790814: nop

    return;
    // 0x80790814: nop

;}
RECOMP_FUNC void func_8002D958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D960: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D964: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002D968: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002D96C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8002D970: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D974: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002D978: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002D97C: addiu       $t7, $t7, 0x3984
    ctx->r15 = ADD32(ctx->r15, 0X3984);
    // 0x8002D980: addiu       $t8, $t8, 0x3A00
    ctx->r24 = ADD32(ctx->r24, 0X3A00);
    // 0x8002D984: sw          $t7, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r15;
    // 0x8002D988: sw          $t8, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r24;
    // 0x8002D98C: sw          $zero, 0x190($v0)
    MEM_W(0X190, ctx->r2) = 0;
    // 0x8002D990: jal         0x800230DC
    // 0x8002D994: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    func_800230DC(rdram, ctx);
        goto after_0;
    // 0x8002D994: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x8002D998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D99C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D9A0: jr          $ra
    // 0x8002D9A4: nop

    return;
    // 0x8002D9A4: nop

;}
RECOMP_FUNC void func_805826F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805826F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805826F8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805826FC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80582700: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80582704: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80582708: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8058270C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80582710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80582714: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80582718: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8058271C: jal         0x8005C27C
    // 0x80582720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80582720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80582724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582728: lhu         $a1, 0x12($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X12);
    // 0x8058272C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80582730: jal         0x8005C27C
    // 0x80582734: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x80582734: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x80582738: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
    // 0x8058273C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80582740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582748: jal         0x8005C27C
    // 0x8058274C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x8058274C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
    // 0x80582750: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80582754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582758: lhu         $a1, 0xE($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0XE);
    // 0x8058275C: jal         0x8005C27C
    // 0x80582760: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x80582760: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
    // 0x80582764: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    // 0x80582768: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8058276C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80582774: jal         0x8005C27C
    // 0x80582778: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_4;
    // 0x80582778: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
    // 0x8058277C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80582780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80582784: lhu         $a1, 0xA($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0XA);
    // 0x80582788: jal         0x8005C27C
    // 0x8058278C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x8058278C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
    // 0x80582790: addiu       $a2, $s2, 0x18
    ctx->r6 = ADD32(ctx->r18, 0X18);
    // 0x80582794: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80582798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8058279C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805827A0: jal         0x8005C27C
    // 0x805827A4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x805827A4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x805827A8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x805827AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805827B0: lhu         $a1, 0x6($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X6);
    // 0x805827B4: jal         0x8005C27C
    // 0x805827B8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x805827B8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x805827BC: addiu       $a2, $s2, 0x20
    ctx->r6 = ADD32(ctx->r18, 0X20);
    // 0x805827C0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x805827C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805827C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805827CC: jal         0x8005C27C
    // 0x805827D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x805827D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x805827D4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x805827D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805827DC: lhu         $a1, 0x2($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X2);
    // 0x805827E0: jal         0x8005C27C
    // 0x805827E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x805827E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_9:
    // 0x805827E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805827EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805827F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805827F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x805827F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x805827FC: jr          $ra
    // 0x80582800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80582800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8057D750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057D750: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x8057D754: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(390, 0X338) << 16);
    // 0x8057D758: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8057D75C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8057D760: lhu         $t8, -0x2588($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(390, 0X338));
    // 0x8057D764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057D768: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8057D76C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057D770: addiu       $t0, $a1, 0x200
    ctx->r8 = ADD32(ctx->r5, 0X200);
    // 0x8057D774: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(390, 0X348) << 16);
    // 0x8057D778: lui         $a2, 0x8058
    ctx->r6 = S32(RELOC_HI16(390, 0X368) << 16);
    // 0x8057D77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057D780: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8057D784: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8057D788: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8057D78C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8057D790: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8057D794: or          $a0, $t9, $t0
    ctx->r4 = ctx->r25 | ctx->r8;
    // 0x8057D798: lw          $a1, -0x2578($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(390, 0X348));
    // 0x8057D79C: jal         0x8004613C
    // 0x8057D7A0: lw          $a2, -0x2558($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(390, 0X368));
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8057D7A0: lw          $a2, -0x2558($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(390, 0X368));
    after_0:
    // 0x8057D7A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8057D7A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8057D7AC: jal         0x80047F9C
    // 0x8057D7B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8057D7B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8057D7B4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8057D7B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8057D7BC: sb          $t1, 0x17C($t2)
    MEM_B(0X17C, ctx->r10) = ctx->r9;
    // 0x8057D7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057D7C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057D7C8: jr          $ra
    // 0x8057D7CC: nop

    return;
    // 0x8057D7CC: nop

;}
RECOMP_FUNC void func_80580A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580A20: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80580A24: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80580A28: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80580A2C: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X45E4) << 16);
    // 0x80580A30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80580A34: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80580A38: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80580A3C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80580A40: lw          $t8, 0x33F4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X45E4));
    // 0x80580A44: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80580A48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80580A4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580A50: jal         0x80048490
    // 0x80580A54: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80580A54: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80580A58: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80580A5C: jal         0x80048378
    // 0x80580A60: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80580A60: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80580A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580A6C: jr          $ra
    // 0x80580A70: nop

    return;
    // 0x80580A70: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883D0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800883D4: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800883D8: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800883DC: blez        $a1, L_80088420
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800883E0: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_80088420;
    }
    // 0x800883E0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800883E4:
    // 0x800883E4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800883E8: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800883EC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800883F0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800883F4: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800883F8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800883FC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80088400: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80088404: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80088408: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8008840C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x80088410: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80088414: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80088418: bne         $at, $zero, L_800883E4
    if (ctx->r1 != 0) {
        // 0x8008841C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800883E4;
    }
    // 0x8008841C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_80088420:
    // 0x80088420: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x80088424: jr          $ra
    // 0x80088428: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80088428: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80434164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434164: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434168: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8043416C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80434170: lw          $v1, 0x7A0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7A0);
    // 0x80434174: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80434178: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8043417C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80434180: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80434184: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80434188: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8043418C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80434190: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80434194: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80434198: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x8043419C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x804341A0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x804341A4: addiu       $a3, $zero, 0x77
    ctx->r7 = ADD32(0, 0X77);
    // 0x804341A8: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x804341AC: addiu       $a1, $v0, 0x7AC
    ctx->r5 = ADD32(ctx->r2, 0X7AC);
    // 0x804341B0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_804341B4:
    // 0x804341B4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x804341B8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x804341BC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804341C0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x804341C4: bc1f        L_80434324
    if (!c1cs) {
        // 0x804341C8: nop
    
            goto L_80434324;
    }
    // 0x804341C8: nop

    // 0x804341CC: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x804341D0: nop

    // 0x804341D4: bc1f        L_80434324
    if (!c1cs) {
        // 0x804341D8: nop
    
            goto L_80434324;
    }
    // 0x804341D8: nop

    // 0x804341DC: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x804341E0: nop

    // 0x804341E4: bc1f        L_80434324
    if (!c1cs) {
        // 0x804341E8: nop
    
            goto L_80434324;
    }
    // 0x804341E8: nop

    // 0x804341EC: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x804341F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804341F4: bc1f        L_80434324
    if (!c1cs) {
        // 0x804341F8: nop
    
            goto L_80434324;
    }
    // 0x804341F8: nop

    // 0x804341FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80434200: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80434204: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80434208: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8043420C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80434210: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80434214: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80434218: nop

    // 0x8043421C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80434220: beql        $t0, $zero, L_80434270
    if (ctx->r8 == 0) {
        // 0x80434224: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_80434270;
    }
    goto skip_0;
    // 0x80434224: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80434228: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043422C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80434230: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80434234: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80434238: nop

    // 0x8043423C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80434240: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80434244: nop

    // 0x80434248: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8043424C: bne         $t0, $zero, L_80434264
    if (ctx->r8 != 0) {
        // 0x80434250: nop
    
            goto L_80434264;
    }
    // 0x80434250: nop

    // 0x80434254: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80434258: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043425C: b           L_8043427C
    // 0x80434260: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8043427C;
    // 0x80434260: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80434264:
    // 0x80434264: b           L_8043427C
    // 0x80434268: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8043427C;
    // 0x80434268: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8043426C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_80434270:
    // 0x80434270: nop

    // 0x80434274: bltz        $t0, L_80434264
    if (SIGNED(ctx->r8) < 0) {
        // 0x80434278: nop
    
            goto L_80434264;
    }
    // 0x80434278: nop

L_8043427C:
    // 0x8043427C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80434280: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80434284: andi        $t0, $t0, 0x3FF
    ctx->r8 = ctx->r8 & 0X3FF;
    // 0x80434288: sll         $t0, $t0, 14
    ctx->r8 = S32(ctx->r8 << 14);
    // 0x8043428C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80434290: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80434294: or          $t9, $t0, $t2
    ctx->r25 = ctx->r8 | ctx->r10;
    // 0x80434298: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8043429C: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x804342A0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x804342A4: nop

    // 0x804342A8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x804342AC: beql        $t1, $zero, L_804342FC
    if (ctx->r9 == 0) {
        // 0x804342B0: mfc1        $t1, $f6
        ctx->r9 = (int32_t)ctx->f6.u32l;
            goto L_804342FC;
    }
    goto skip_1;
    // 0x804342B0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x804342B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804342B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804342BC: sub.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x804342C0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x804342C4: nop

    // 0x804342C8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x804342CC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x804342D0: nop

    // 0x804342D4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x804342D8: bne         $t1, $zero, L_804342F0
    if (ctx->r9 != 0) {
        // 0x804342DC: nop
    
            goto L_804342F0;
    }
    // 0x804342DC: nop

    // 0x804342E0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x804342E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804342E8: b           L_80434308
    // 0x804342EC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80434308;
    // 0x804342EC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_804342F0:
    // 0x804342F0: b           L_80434308
    // 0x804342F4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80434308;
    // 0x804342F4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x804342F8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
L_804342FC:
    // 0x804342FC: nop

    // 0x80434300: bltz        $t1, L_804342F0
    if (SIGNED(ctx->r9) < 0) {
        // 0x80434304: nop
    
            goto L_804342F0;
    }
    // 0x80434304: nop

L_80434308:
    // 0x80434308: andi        $t1, $t1, 0x3FF
    ctx->r9 = ctx->r9 & 0X3FF;
    // 0x8043430C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80434310: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80434314: or          $t3, $t9, $t1
    ctx->r11 = ctx->r25 | ctx->r9;
    // 0x80434318: or          $t4, $t0, $t1
    ctx->r12 = ctx->r8 | ctx->r9;
    // 0x8043431C: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x80434320: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_80434324:
    // 0x80434324: bgezl       $a3, L_804341B4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80434328: lwc1        $f0, 0x0($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
            goto L_804341B4;
    }
    goto skip_2;
    // 0x80434328: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x8043432C: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x80434330: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80434334: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80434338: jr          $ra
    // 0x8043433C: sw          $v1, 0x7A0($v0)
    MEM_W(0X7A0, ctx->r2) = ctx->r3;
    return;
    // 0x8043433C: sw          $v1, 0x7A0($v0)
    MEM_W(0X7A0, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80454740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454740: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80454744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454748: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045474C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454750: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80454754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454758: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045475C: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x80454760: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80454764: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80454768: bne         $t6, $at, L_80454794
    if (ctx->r14 != ctx->r1) {
        // 0x8045476C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80454794;
    }
    // 0x8045476C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80454770: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454774: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454778: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8045477C: jal         0x8044EDC4
    // 0x80454780: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x80454780: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80454784: jal         0x80446D70
    // 0x80454788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x80454788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8045478C: b           L_804547A4
    // 0x80454790: nop

        goto L_804547A4;
    // 0x80454790: nop

L_80454794:
    // 0x80454794: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454798: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8045479C: jal         0x804536C4
    // 0x804547A0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    func_804536C4(rdram, ctx);
        goto after_2;
    // 0x804547A0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    after_2:
L_804547A4:
    // 0x804547A4: jal         0x80454664
    // 0x804547A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80454664(rdram, ctx);
        goto after_3;
    // 0x804547A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804547AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804547B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804547B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804547B8: jr          $ra
    // 0x804547BC: nop

    return;
    // 0x804547BC: nop

;}
RECOMP_FUNC void func_805315A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805315A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805315A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805315AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805315B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805315B4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805315B8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805315BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805315C0: bnel        $t6, $at, L_8053166C
    if (ctx->r14 != ctx->r1) {
        // 0x805315C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_0;
    // 0x805315C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805315C8: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x805315CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805315D0: bnel        $t7, $at, L_8053166C
    if (ctx->r15 != ctx->r1) {
        // 0x805315D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_1;
    // 0x805315D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805315D8: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x805315DC: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x805315E0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x805315E4: andi        $t0, $t9, 0xF000
    ctx->r8 = ctx->r25 & 0XF000;
    // 0x805315E8: beql        $t0, $zero, L_8053166C
    if (ctx->r8 == 0) {
        // 0x805315EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_2;
    // 0x805315EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805315F0: lh          $t1, -0x7680($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7680);
    // 0x805315F4: blezl       $t1, L_8053166C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x805315F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_3;
    // 0x805315F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805315FC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80531600: lw          $t2, 0x12EC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X12EC);
    // 0x80531604: bnel        $t2, $zero, L_8053166C
    if (ctx->r10 != 0) {
        // 0x80531608: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_4;
    // 0x80531608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8053160C: lbu         $t3, 0x154($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X154);
    // 0x80531610: bnel        $t3, $zero, L_8053166C
    if (ctx->r11 != 0) {
        // 0x80531614: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_5;
    // 0x80531614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80531618: lbu         $t4, 0x155($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X155);
    // 0x8053161C: bnel        $t4, $zero, L_8053166C
    if (ctx->r12 != 0) {
        // 0x80531620: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8053166C;
    }
    goto skip_6;
    // 0x80531620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80531624: lbu         $t5, 0x1F8($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1F8);
    // 0x80531628: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8053162C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80531630: bne         $t5, $zero, L_80531668
    if (ctx->r13 != 0) {
        // 0x80531634: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80531668;
    }
    // 0x80531634: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80531638: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8053163C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80531640: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80531644: jal         0x8002F7AC
    // 0x80531648: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8002F7AC(rdram, ctx);
        goto after_0;
    // 0x80531648: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x8053164C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80531650: jal         0x805323E8
    // 0x80531654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805323E8(rdram, ctx);
        goto after_1;
    // 0x80531654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80531658: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8053165C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80531660: jal         0x80531440
    // 0x80531664: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80531440(rdram, ctx);
        goto after_2;
    // 0x80531664: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
L_80531668:
    // 0x80531668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8053166C:
    // 0x8053166C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80531670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80531674: jr          $ra
    // 0x80531678: nop

    return;
    // 0x80531678: nop

;}
RECOMP_FUNC void func_8051571C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051571C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80515720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80515724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80515728: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8051572C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80515730: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80515734: bne         $t6, $zero, L_80515748
    if (ctx->r14 != 0) {
        // 0x80515738: nop
    
            goto L_80515748;
    }
    // 0x80515738: nop

    // 0x8051573C: jal         0x80045A34
    // 0x80515740: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80515740: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80515744: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
L_80515748:
    // 0x80515748: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8051574C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80515750: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80515754: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE54) << 16);
    // 0x80515758: lwc1        $f0, 0x62F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE54));
    // 0x8051575C: lwc1        $f4, 0x30($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X30);
    // 0x80515760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80515764: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80515768: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x8051576C: lwc1        $f6, 0x34($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X34);
    // 0x80515770: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80515774: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80515778: jal         0x8051552C
    // 0x8051577C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    func_8051552C(rdram, ctx);
        goto after_1;
    // 0x8051577C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80515780: bne         $v0, $zero, L_80515798
    if (ctx->r2 != 0) {
        // 0x80515784: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_80515798;
    }
    // 0x80515784: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80515788: jal         0x800445A4
    // 0x8051578C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8051578C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80515790: b           L_805157E4
    // 0x80515794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805157E4;
    // 0x80515794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80515798:
    // 0x80515798: sh          $t9, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r25;
    // 0x8051579C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805157A0: jal         0x80515DD4
    // 0x805157A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80515DD4(rdram, ctx);
        goto after_3;
    // 0x805157A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805157A8: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x805157AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x805157B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805157B4: jal         0x8006CA74
    // 0x805157B8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    func_8006CA74(rdram, ctx);
        goto after_4;
    // 0x805157B8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    after_4:
    // 0x805157BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805157C0: jal         0x80067BBC
    // 0x805157C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805157C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x805157C8: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    // 0x805157CC: jal         0x80067818
    // 0x805157D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x805157D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x805157D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805157D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805157DC: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x805157E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805157E4:
    // 0x805157E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805157E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805157EC: jr          $ra
    // 0x805157F0: nop

    return;
    // 0x805157F0: nop

;}
RECOMP_FUNC void func_804B87CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B87CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B87D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B87D4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804B87D8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804B87DC: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(185, 0X29CC) << 16);
    // 0x804B87E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804B87E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804B87E8: lw          $t8, -0x5814($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(185, 0X29CC));
    // 0x804B87EC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804B87F0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804B87F4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804B87F8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804B87FC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804B8800: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804B8804: beql        $v1, $zero, L_804B8838
    if (ctx->r3 == 0) {
        // 0x804B8808: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B8838;
    }
    goto skip_0;
    // 0x804B8808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B880C: jalr        $v1
    // 0x804B8810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804B8810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B8814: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B8818: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804B881C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804B8820: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804B8824: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804B8828: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804B882C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804B8830: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804B8834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B8838:
    // 0x804B8838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B883C: jr          $ra
    // 0x804B8840: nop

    return;
    // 0x804B8840: nop

;}
RECOMP_FUNC void func_8064C4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C4E4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064C4E8: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0X2278) << 16);
    // 0x8064C4EC: addiu       $t6, $t6, -0x3CB8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0X2278));
    // 0x8064C4F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064C4F4: jr          $ra
    // 0x8064C4F8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064C4F8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806D0DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0DBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D0DC0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806D0DC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806D0DC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D0DCC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806D0DD0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x806D0DD4: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x806D0DD8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x806D0DDC: jr          $ra
    // 0x806D0DE0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x806D0DE0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_806DB758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB75C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DB764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806DB768: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806DB76C: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x806DB770: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806DB774: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806DB778: bne         $t7, $at, L_806DB7C4
    if (ctx->r15 != ctx->r1) {
        // 0x806DB77C: nop
    
            goto L_806DB7C4;
    }
    // 0x806DB77C: nop

    // 0x806DB780: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806DB784: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806DB788: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x806DB78C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x806DB790: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x806DB794: nop

    // 0x806DB798: bc1fl       L_806DB7B4
    if (!c1cs) {
        // 0x806DB79C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_806DB7B4;
    }
    goto skip_0;
    // 0x806DB79C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x806DB7A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806DB7A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806DB7A8: b           L_806DB7BC
    // 0x806DB7AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_806DB7BC;
    // 0x806DB7AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806DB7B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_806DB7B4:
    // 0x806DB7B4: nop

    // 0x806DB7B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_806DB7BC:
    // 0x806DB7BC: jal         0x8002F96C
    // 0x806DB7C0: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_8002F96C(rdram, ctx);
        goto after_0;
    // 0x806DB7C0: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_0:
L_806DB7C4:
    // 0x806DB7C4: jal         0x806DB6C0
    // 0x806DB7C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806DB6C0(rdram, ctx);
        goto after_1;
    // 0x806DB7C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DB7CC: jal         0x800447C8
    // 0x806DB7D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x806DB7D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806DB7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB7D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB7DC: jr          $ra
    // 0x806DB7E0: nop

    return;
    // 0x806DB7E0: nop

;}
RECOMP_FUNC void func_8043ADFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043ADFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043AE00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043AE04: jal         0x8043A6B4
    // 0x8043AE08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043A6B4(rdram, ctx);
        goto after_0;
    // 0x8043AE08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043AE0C: jal         0x80045BD8
    // 0x8043AE10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8043AE10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043AE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043AE18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043AE1C: jr          $ra
    // 0x8043AE20: nop

    return;
    // 0x8043AE20: nop

;}
RECOMP_FUNC void func_806D9770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9778: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806D977C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806D9780: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806D9784: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(631, 0X3B8) << 16);
    // 0x806D9788: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x806D978C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806D9790: addiu       $t7, $t7, -0x6538
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(631, 0X3B8));
    // 0x806D9794: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806D9798: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806D979C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x806D97A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D97A4: jal         0x806D996C
    // 0x806D97A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806D996C(rdram, ctx);
        goto after_0;
    // 0x806D97A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x806D97AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D97B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D97B4: jr          $ra
    // 0x806D97B8: nop

    return;
    // 0x806D97B8: nop

;}
RECOMP_FUNC void func_807BAD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAD68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BAD6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BAD70: jal         0x8004700C
    // 0x807BAD74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807BAD74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BAD78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807BAD7C: bne         $v0, $zero, L_807BAD8C
    if (ctx->r2 != 0) {
        // 0x807BAD80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_807BAD8C;
    }
    // 0x807BAD80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807BAD84: b           L_807BAE34
    // 0x807BAD88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BAE34;
    // 0x807BAD88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BAD8C:
    // 0x807BAD8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x807BAD90: jal         0x807BAC5C
    // 0x807BAD94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_807BAC5C(rdram, ctx);
        goto after_1;
    // 0x807BAD94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x807BAD98: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807BAD9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807BADA0: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x807BADA4: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807BADA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807BADAC: nop

    // 0x807BADB0: bc1fl       L_807BADD8
    if (!c1cs) {
        // 0x807BADB4: lw          $t9, 0x1F4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X1F4);
            goto L_807BADD8;
    }
    goto skip_0;
    // 0x807BADB4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    skip_0:
    // 0x807BADB8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BADBC: lhu         $v0, 0x28($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X28);
    // 0x807BADC0: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x807BADC4: beql        $t8, $zero, L_807BADF4
    if (ctx->r24 == 0) {
        // 0x807BADC8: lwc1        $f8, 0x88($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
            goto L_807BADF4;
    }
    goto skip_1;
    // 0x807BADC8: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    skip_1:
    // 0x807BADCC: b           L_807BAE34
    // 0x807BADD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807BAE34;
    // 0x807BADD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807BADD4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
L_807BADD8:
    // 0x807BADD8: lhu         $v0, 0x28($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X28);
    // 0x807BADDC: andi        $t1, $v0, 0x20
    ctx->r9 = ctx->r2 & 0X20;
    // 0x807BADE0: beql        $t1, $zero, L_807BADF4
    if (ctx->r9 == 0) {
        // 0x807BADE4: lwc1        $f8, 0x88($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
            goto L_807BADF4;
    }
    goto skip_2;
    // 0x807BADE4: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    skip_2:
    // 0x807BADE8: b           L_807BAE34
    // 0x807BADEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807BAE34;
    // 0x807BADEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807BADF0: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
L_807BADF4:
    // 0x807BADF4: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807BADF8: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x807BADFC: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
    // 0x807BAE00: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x807BAE04: nop

    // 0x807BAE08: bc1f        L_807BAE20
    if (!c1cs) {
        // 0x807BAE0C: nop
    
            goto L_807BAE20;
    }
    // 0x807BAE0C: nop

    // 0x807BAE10: beql        $t3, $zero, L_807BAE34
    if (ctx->r11 == 0) {
        // 0x807BAE14: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807BAE34;
    }
    goto skip_3;
    // 0x807BAE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x807BAE18: b           L_807BAE34
    // 0x807BAE1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807BAE34;
    // 0x807BAE1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807BAE20:
    // 0x807BAE20: beql        $t5, $zero, L_807BAE34
    if (ctx->r13 == 0) {
        // 0x807BAE24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807BAE34;
    }
    goto skip_4;
    // 0x807BAE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x807BAE28: b           L_807BAE34
    // 0x807BAE2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807BAE34;
    // 0x807BAE2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807BAE30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BAE34:
    // 0x807BAE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BAE38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BAE3C: jr          $ra
    // 0x807BAE40: nop

    return;
    // 0x807BAE40: nop

;}
RECOMP_FUNC void func_806D36C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D36C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D36C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D36CC: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806D36D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x806D36D4: sw          $zero, 0x44($t6)
    MEM_W(0X44, ctx->r14) = 0;
    // 0x806D36D8: jal         0x8005FE48
    // 0x806D36DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x806D36DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D36E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D36E4: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806D36E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806D36EC: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x806D36F0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806D36F4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806D36F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D36FC: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(616, 0X3640) << 16);
    // 0x806D3700: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x806D3704: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x806D3708: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x806D370C: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x806D3710: lwc1        $f16, 0x65F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0X3640));
    // 0x806D3714: lui         $t7, 0x806D
    ctx->r15 = S32(RELOC_HI16(616, 0X678) << 16);
    // 0x806D3718: addiu       $t7, $t7, 0x3628
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(616, 0X678));
    // 0x806D371C: swc1        $f16, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f16.u32l;
    // 0x806D3720: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806D3724: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806D3728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D372C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D3730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D3734: jr          $ra
    // 0x806D3738: nop

    return;
    // 0x806D3738: nop

;}
RECOMP_FUNC void func_804CF2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF2B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CF2B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CF2B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CF2BC: jal         0x804CF254
    // 0x804CF2C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804CF254(rdram, ctx);
        goto after_0;
    // 0x804CF2C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CF2C4: bne         $v0, $zero, L_804CF2DC
    if (ctx->r2 != 0) {
        // 0x804CF2C8: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_804CF2DC;
    }
    // 0x804CF2C8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804CF2CC: jal         0x800445A4
    // 0x804CF2D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804CF2D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CF2D4: b           L_804CF33C
    // 0x804CF2D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CF33C;
    // 0x804CF2D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CF2DC:
    // 0x804CF2DC: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804CF2E0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804CF2E4: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(240, 0X1A8C) << 16);
    // 0x804CF2E8: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x804CF2EC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804CF2F0: addiu       $t7, $t7, -0x2C4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(240, 0X1A8C));
    // 0x804CF2F4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804CF2F8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804CF2FC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804CF300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CF304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CF308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CF30C: jal         0x804CF34C
    // 0x804CF310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CF34C(rdram, ctx);
        goto after_2;
    // 0x804CF310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804CF314: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804CF318: jal         0x804CF298
    // 0x804CF31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF298(rdram, ctx);
        goto after_3;
    // 0x804CF31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CF320: jal         0x804CF198
    // 0x804CF324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF198(rdram, ctx);
        goto after_4;
    // 0x804CF324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804CF328: bnel        $v0, $zero, L_804CF33C
    if (ctx->r2 != 0) {
        // 0x804CF32C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CF33C;
    }
    goto skip_0;
    // 0x804CF32C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CF330: jal         0x800445A4
    // 0x804CF334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804CF334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804CF338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CF33C:
    // 0x804CF33C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CF340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CF344: jr          $ra
    // 0x804CF348: nop

    return;
    // 0x804CF348: nop

;}
RECOMP_FUNC void func_805ADF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADF34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADF38: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADF3C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADF40: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADF44: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADF48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADF4C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADF50: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADF54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADF58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADF5C: jr          $ra
    // 0x805ADF60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADF60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807C38CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C38CC: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x807C38D0: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(907, 0XEB0) << 16);
    // 0x807C38D4: addiu       $t7, $t7, 0x4210
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(907, 0XEB0));
    // 0x807C38D8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x807C38DC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x807C38E0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x807C38E4: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(907, 0X1400) << 16);
    // 0x807C38E8: lui         $t0, 0x807C
    ctx->r8 = S32(RELOC_HI16(907, 0X13F8) << 16);
    // 0x807C38EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x807C38F0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x807C38F4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x807C38F8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x807C38FC: addiu       $t0, $t0, 0x4758
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(907, 0X13F8));
    // 0x807C3900: addiu       $v1, $v1, 0x4760
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(907, 0X1400));
    // 0x807C3904: lbu         $t8, 0x20($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X20);
    // 0x807C3908: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x807C390C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x807C3910: sb          $t8, 0x165($t9)
    MEM_B(0X165, ctx->r25) = ctx->r24;
    // 0x807C3914: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x807C3918: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x807C391C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x807C3920: nop

    // 0x807C3924: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807C3928: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807C392C: beql        $t0, $v1, L_807C39D0
    if (ctx->r8 == ctx->r3) {
        // 0x807C3930: swc1        $f18, 0x3C($t2)
        MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
            goto L_807C39D0;
    }
    goto skip_0;
    // 0x807C3930: swc1        $f18, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
    skip_0:
    // 0x807C3934: swc1        $f18, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
L_807C3938:
    // 0x807C3938: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x807C393C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x807C3940: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x807C3944: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x807C3948: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x807C394C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x807C3950: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807C3954: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807C3958: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x807C395C: lwc1        $f16, -0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X10);
    // 0x807C3960: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x807C3964: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807C3968: swc1        $f16, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f16.u32l;
    // 0x807C396C: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x807C3970: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x807C3974: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807C3978: swc1        $f16, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f16.u32l;
    // 0x807C397C: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x807C3980: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x807C3984: swc1        $f16, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f16.u32l;
    // 0x807C3988: lw          $t8, -0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X4);
    // 0x807C398C: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x807C3990: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
    // 0x807C3994: lw          $t1, -0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X4);
    // 0x807C3998: lwc1        $f16, -0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X8);
    // 0x807C399C: swc1        $f16, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f16.u32l;
    // 0x807C39A0: lbu         $t8, 0x20($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X20);
    // 0x807C39A4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x807C39A8: sb          $t8, 0x165($t9)
    MEM_B(0X165, ctx->r25) = ctx->r24;
    // 0x807C39AC: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x807C39B0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x807C39B4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x807C39B8: nop

    // 0x807C39BC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807C39C0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807C39C4: bnel        $t0, $v1, L_807C3938
    if (ctx->r8 != ctx->r3) {
        // 0x807C39C8: swc1        $f18, 0x3C($t2)
        MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
            goto L_807C3938;
    }
    goto skip_1;
    // 0x807C39C8: swc1        $f18, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
    skip_1:
    // 0x807C39CC: swc1        $f18, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f18.u32l;
L_807C39D0:
    // 0x807C39D0: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x807C39D4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x807C39D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x807C39DC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x807C39E0: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x807C39E4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807C39E8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807C39EC: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x807C39F0: lwc1        $f16, -0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X10);
    // 0x807C39F4: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x807C39F8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807C39FC: swc1        $f16, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f16.u32l;
    // 0x807C3A00: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x807C3A04: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x807C3A08: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807C3A0C: swc1        $f16, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f16.u32l;
    // 0x807C3A10: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x807C3A14: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x807C3A18: swc1        $f16, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f16.u32l;
    // 0x807C3A1C: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x807C3A20: lw          $t8, -0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X4);
    // 0x807C3A24: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
    // 0x807C3A28: lwc1        $f16, -0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X4);
    // 0x807C3A2C: lw          $t1, -0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X4);
    // 0x807C3A30: swc1        $f16, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f16.u32l;
    // 0x807C3A34: jr          $ra
    // 0x807C3A38: nop

    return;
    // 0x807C3A38: nop

;}
RECOMP_FUNC void func_80525574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525574: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80525578: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8052557C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80525580: beq         $t6, $at, L_80525628
    if (ctx->r14 == ctx->r1) {
        // 0x80525584: nop
    
            goto L_80525628;
    }
    // 0x80525584: nop

    // 0x80525588: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x8052558C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80525590: beq         $t7, $at, L_80525628
    if (ctx->r15 == ctx->r1) {
        // 0x80525594: nop
    
            goto L_80525628;
    }
    // 0x80525594: nop

    // 0x80525598: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8052559C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x805255A0: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x805255A4: beq         $t0, $zero, L_80525628
    if (ctx->r8 == 0) {
        // 0x805255A8: nop
    
            goto L_80525628;
    }
    // 0x805255A8: nop

    // 0x805255AC: lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XE);
    // 0x805255B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805255B4: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x805255B8: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x805255BC: beq         $v0, $at, L_805255DC
    if (ctx->r2 == ctx->r1) {
        // 0x805255C0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_805255DC;
    }
    // 0x805255C0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x805255C4: beql        $v0, $at, L_805255E0
    if (ctx->r2 == ctx->r1) {
        // 0x805255C8: lwc1        $f0, 0xC4($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0XC4);
            goto L_805255E0;
    }
    goto skip_0;
    // 0x805255C8: lwc1        $f0, 0xC4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC4);
    skip_0:
    // 0x805255CC: beq         $v0, $zero, L_805255DC
    if (ctx->r2 == 0) {
        // 0x805255D0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_805255DC;
    }
    // 0x805255D0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x805255D4: bne         $v0, $at, L_80525628
    if (ctx->r2 != ctx->r1) {
        // 0x805255D8: nop
    
            goto L_80525628;
    }
    // 0x805255D8: nop

L_805255DC:
    // 0x805255DC: lwc1        $f0, 0xC4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC4);
L_805255E0:
    // 0x805255E0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x805255E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805255E8: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(324, 0X870) << 16);
    // 0x805255EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805255F0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x805255F4: nop

    // 0x805255F8: bc1f        L_80525628
    if (!c1cs) {
        // 0x805255FC: nop
    
            goto L_80525628;
    }
    // 0x805255FC: nop

    // 0x80525600: lw          $v0, 0x138($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X138);
    // 0x80525604: lwc1        $f16, 0xDC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XDC);
    // 0x80525608: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8052560C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80525610: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80525614: lw          $t2, 0x5D80($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(324, 0X870));
    // 0x80525618: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8052561C: swc1        $f10, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f10.u32l;
    // 0x80525620: swc1        $f18, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f18.u32l;
    // 0x80525624: sw          $t2, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r10;
L_80525628:
    // 0x80525628: jr          $ra
    // 0x8052562C: nop

    return;
    // 0x8052562C: nop

;}
RECOMP_FUNC void func_80025B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B30: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80025B34: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80025B38: addiu       $t7, $t7, 0x5ADC
    ctx->r15 = ADD32(ctx->r15, 0X5ADC);
    // 0x80025B3C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025B40: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x80025B44: jr          $ra
    // 0x80025B48: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    return;
    // 0x80025B48: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_806F7DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7DD8: lw          $t6, 0x168($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X168);
    // 0x806F7DDC: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7DE0: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x806F7DE4: lw          $v0, 0x80($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X80);
    // 0x806F7DE8: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x806F7DEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806F7DF0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x806F7DF4: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x806F7DF8: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7DFC: lui         $t3, 0x705
    ctx->r11 = S32(0X705 << 16);
    // 0x806F7E00: ori         $t3, $t3, 0x4150
    ctx->r11 = ctx->r11 | 0X4150;
    // 0x806F7E04: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x806F7E08: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7E0C: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x806F7E10: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x806F7E14: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x806F7E18: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7E1C: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x806F7E20: lui         $t8, 0x71F
    ctx->r24 = S32(0X71F << 16);
    // 0x806F7E24: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x806F7E28: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x806F7E2C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806F7E30: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x806F7E34: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7E38: ori         $t8, $t8, 0xF200
    ctx->r24 = ctx->r24 | 0XF200;
    // 0x806F7E3C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x806F7E40: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x806F7E44: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7E48: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x806F7E4C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x806F7E50: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7E54: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x806F7E58: lui         $t5, 0x5
    ctx->r13 = S32(0X5 << 16);
    // 0x806F7E5C: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x806F7E60: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7E64: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806F7E68: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x806F7E6C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7E70: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x806F7E74: ori         $t4, $t4, 0x800
    ctx->r12 = ctx->r12 | 0X800;
    // 0x806F7E78: addiu       $t3, $a2, 0x8
    ctx->r11 = ADD32(ctx->r6, 0X8);
    // 0x806F7E7C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x806F7E80: ori         $t5, $t5, 0x4150
    ctx->r13 = ctx->r13 | 0X4150;
    // 0x806F7E84: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x806F7E88: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x806F7E8C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x806F7E90: lui         $t8, 0x7
    ctx->r24 = S32(0X7 << 16);
    // 0x806F7E94: ori         $t8, $t8, 0xC07C
    ctx->r24 = ctx->r24 | 0XC07C;
    // 0x806F7E98: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x806F7E9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7EA0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x806F7EA4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x806F7EA8: jr          $ra
    // 0x806F7EAC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    return;
    // 0x806F7EAC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void func_8051A530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051A534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A538: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8051A53C: beql        $v0, $zero, L_8051A55C
    if (ctx->r2 == 0) {
        // 0x8051A540: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051A55C;
    }
    goto skip_0;
    // 0x8051A540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8051A544: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8051A548: beql        $a0, $zero, L_8051A55C
    if (ctx->r4 == 0) {
        // 0x8051A54C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051A55C;
    }
    goto skip_1;
    // 0x8051A54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8051A550: jal         0x800577D8
    // 0x8051A554: nop

    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x8051A554: nop

    after_0:
    // 0x8051A558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051A55C:
    // 0x8051A55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051A560: jr          $ra
    // 0x8051A564: nop

    return;
    // 0x8051A564: nop

;}
RECOMP_FUNC void func_8006BF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006BF84: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8006BF88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006BF8C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006BF90: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006BF94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006BF98: lwc1        $f6, 0x1060($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1060);
    // 0x8006BF9C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006BFA0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006BFA4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8006BFA8: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8006BFAC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006BFB0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8006BFB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006BFB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006BFBC: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8006BFC0: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006BFC4: addiu       $s0, $s0, 0x530
    ctx->r16 = ADD32(ctx->r16, 0X530);
    // 0x8006BFC8: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x8006BFCC: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006BFD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006BFD4: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x8006BFD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006BFDC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8006BFE0: jal         0x80086600
    // 0x8006BFE4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspective(rdram, ctx);
        goto after_0;
    // 0x8006BFE4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8006BFE8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8006BFEC: lw          $t7, -0x7D6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D6C);
    // 0x8006BFF0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8006BFF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006BFF8: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8006BFFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006C000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C004: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006C008: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006C00C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006C010: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8006C014: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8006C018: jal         0x8007FFF0
    // 0x8006C01C: nop

    func_8007FFF0(rdram, ctx);
        goto after_1;
    // 0x8006C01C: nop

    after_1:
    // 0x8006C020: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C024: lwc1        $f8, 0x1064($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1064);
    // 0x8006C028: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006C02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C030: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006C034: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8006C038: jal         0x8007FF58
    // 0x8006C03C: nop

    func_8007FF58(rdram, ctx);
        goto after_2;
    // 0x8006C03C: nop

    after_2:
    // 0x8006C040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C044: lwc1        $f18, 0x1068($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1068);
    // 0x8006C048: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006C04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C050: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006C054: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8006C058: jal         0x8007FF0C
    // 0x8006C05C: nop

    func_8007FF0C(rdram, ctx);
        goto after_3;
    // 0x8006C05C: nop

    after_3:
    // 0x8006C060: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C064: lwc1        $f8, 0x106C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X106C);
    // 0x8006C068: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006C06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C070: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006C074: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8006C078: jal         0x8007FEC8
    // 0x8006C07C: nop

    func_8007FEC8(rdram, ctx);
        goto after_4;
    // 0x8006C07C: nop

    after_4:
    // 0x8006C080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C084: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8006C088: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C08C: jal         0x8007FFF0
    // 0x8006C090: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_8007FFF0(rdram, ctx);
        goto after_5;
    // 0x8006C090: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8006C094: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8006C098: addiu       $v0, $v0, -0x7AF0
    ctx->r2 = ADD32(ctx->r2, -0X7AF0);
    // 0x8006C09C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006C0A0: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x8006C0A4: addiu       $t2, $s0, 0x3C
    ctx->r10 = ADD32(ctx->r16, 0X3C);
L_8006C0A8:
    // 0x8006C0A8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8006C0AC: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8006C0B0: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8006C0B4: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
    // 0x8006C0B8: lw          $t9, -0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X8);
    // 0x8006C0BC: sw          $t9, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r25;
    // 0x8006C0C0: lw          $t0, -0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, -0X4);
    // 0x8006C0C4: bne         $t1, $t2, L_8006C0A8
    if (ctx->r9 != ctx->r10) {
        // 0x8006C0C8: sw          $t0, 0x1C($t8)
        MEM_W(0X1C, ctx->r24) = ctx->r8;
            goto L_8006C0A8;
    }
    // 0x8006C0C8: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x8006C0CC: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8006C0D0: sw          $t0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r8;
    // 0x8006C0D4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8006C0D8: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    // 0x8006C0DC: sh          $t3, 0x60($t4)
    MEM_H(0X60, ctx->r12) = ctx->r11;
    // 0x8006C0E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C0E4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006C0E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006C0EC: jr          $ra
    // 0x8006C0F0: nop

    return;
    // 0x8006C0F0: nop

;}
RECOMP_FUNC void guS2DEmuSetScissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EE0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80082EE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082EE8: sh          $t7, -0x5450($at)
    MEM_H(-0X5450, ctx->r1) = ctx->r15;
    // 0x80082EEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082EF0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80082EF4: sh          $t9, -0x544C($at)
    MEM_H(-0X544C, ctx->r1) = ctx->r25;
    // 0x80082EF8: lbu         $t4, 0x13($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X13);
    // 0x80082EFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082F00: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x80082F04: sh          $t1, -0x5448($at)
    MEM_H(-0X5448, ctx->r1) = ctx->r9;
    // 0x80082F08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082F0C: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x80082F10: beq         $t4, $zero, L_80082F28
    if (ctx->r12 == 0) {
        // 0x80082F14: sh          $t3, -0x5444($at)
        MEM_H(-0X5444, ctx->r1) = ctx->r11;
            goto L_80082F28;
    }
    // 0x80082F14: sh          $t3, -0x5444($at)
    MEM_H(-0X5444, ctx->r1) = ctx->r11;
    // 0x80082F18: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80082F1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082F20: jr          $ra
    // 0x80082F24: sb          $t5, -0x5440($at)
    MEM_B(-0X5440, ctx->r1) = ctx->r13;
    return;
    // 0x80082F24: sb          $t5, -0x5440($at)
    MEM_B(-0X5440, ctx->r1) = ctx->r13;
L_80082F28:
    // 0x80082F28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80082F2C: sb          $zero, -0x5440($at)
    MEM_B(-0X5440, ctx->r1) = 0;
    // 0x80082F30: jr          $ra
    // 0x80082F34: nop

    return;
    // 0x80082F34: nop

;}
RECOMP_FUNC void func_807AD56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD56C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AD570: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x807AD574: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807AD578: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26C8) << 16);
    // 0x807AD57C: lwc1        $f6, -0x12D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26C8));
    // 0x807AD580: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807AD584: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807AD588: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807AD58C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AD590: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26CC) << 16);
    // 0x807AD594: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807AD598: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807AD59C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807AD5A0: nop

    // 0x807AD5A4: bc1fl       L_807AD5B4
    if (!c1cs) {
        // 0x807AD5A8: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_807AD5B4;
    }
    goto skip_0;
    // 0x807AD5A8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x807AD5AC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807AD5B0: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
L_807AD5B4:
    // 0x807AD5B4: lwc1        $f18, -0x12D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26CC));
    // 0x807AD5B8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26D0) << 16);
    // 0x807AD5BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x807AD5C0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x807AD5C4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807AD5C8: lwc1        $f6, -0x12D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26D0));
    // 0x807AD5CC: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807AD5D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807AD5D4: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x807AD5D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807AD5DC: nop

    // 0x807AD5E0: bc1fl       L_807AD5F0
    if (!c1cs) {
        // 0x807AD5E4: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_807AD5F0;
    }
    goto skip_1;
    // 0x807AD5E4: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x807AD5E8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x807AD5EC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_807AD5F0:
    // 0x807AD5F0: jr          $ra
    // 0x807AD5F4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x807AD5F4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8045FCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FCD0: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(116, 0X10) << 16);
    // 0x8045FCD4: addiu       $v0, $v0, -0x320
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(116, 0X10));
    // 0x8045FCD8: jr          $ra
    // 0x8045FCDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8045FCDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804A48C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A48C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A48CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A48D0: jal         0x804A49CC
    // 0x804A48D4: nop

    func_804A49CC(rdram, ctx);
        goto after_0;
    // 0x804A48D4: nop

    after_0:
    // 0x804A48D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A48DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A48E0: jr          $ra
    // 0x804A48E4: nop

    return;
    // 0x804A48E4: nop

;}
RECOMP_FUNC void func_807AE8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE8F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE8F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE8FC: jal         0x8004700C
    // 0x807AE900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807AE900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AE904: beq         $v0, $zero, L_807AE918
    if (ctx->r2 == 0) {
        // 0x807AE908: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807AE918;
    }
    // 0x807AE908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AE90C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE910: jal         0x807AEA24
    // 0x807AE914: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_807AEA24(rdram, ctx);
        goto after_1;
    // 0x807AE914: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
L_807AE918:
    // 0x807AE918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE91C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE920: jr          $ra
    // 0x807AE924: nop

    return;
    // 0x807AE924: nop

;}
RECOMP_FUNC void func_804BA5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA5DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BA5E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA5E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804BA5E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BA5EC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x804BA5F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804BA5F4: addiu       $t7, $v0, 0x4B0
    ctx->r15 = ADD32(ctx->r2, 0X4B0);
    // 0x804BA5F8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x804BA5FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804BA600: jal         0x804BA360
    // 0x804BA604: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_804BA360(rdram, ctx);
        goto after_0;
    // 0x804BA604: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804BA608: jal         0x804BA380
    // 0x804BA60C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804BA380(rdram, ctx);
        goto after_1;
    // 0x804BA60C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x804BA610: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804BA614: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BA618: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804BA61C: sw          $t8, 0x960($v0)
    MEM_W(0X960, ctx->r2) = ctx->r24;
    // 0x804BA620: swc1        $f0, 0xB68($v0)
    MEM_W(0XB68, ctx->r2) = ctx->f0.u32l;
    // 0x804BA624: swc1        $f0, 0xB6C($v0)
    MEM_W(0XB6C, ctx->r2) = ctx->f0.u32l;
    // 0x804BA628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BA62C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BA630: jr          $ra
    // 0x804BA634: nop

    return;
    // 0x804BA634: nop

;}
