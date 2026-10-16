#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806F87D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F87D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F87DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F87E0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F87E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806F87E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F87EC: lwc1        $f2, 0x5F0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X5F0);
    // 0x806F87F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806F87F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F87F8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x806F87FC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x806F8800: nop

    // 0x806F8804: bc1fl       L_806F88AC
    if (!c1cs) {
        // 0x806F8808: swc1        $f2, 0x5F0($a1)
        MEM_W(0X5F0, ctx->r5) = ctx->f2.u32l;
            goto L_806F88AC;
    }
    goto skip_0;
    // 0x806F8808: swc1        $f2, 0x5F0($a1)
    MEM_W(0X5F0, ctx->r5) = ctx->f2.u32l;
    skip_0:
    // 0x806F880C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806F8810: jal         0x8004700C
    // 0x806F8814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F8814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F8818: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806F881C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806F8820: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806F8824: beq         $v0, $zero, L_806F88A8
    if (ctx->r2 == 0) {
        // 0x806F8828: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_806F88A8;
    }
    // 0x806F8828: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806F882C: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806F8830: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F8834: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x806F8838: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806F883C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806F8840: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806F8844: jal         0x80065954
    // 0x806F8848: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x806F8848: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_1:
    // 0x806F884C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806F8850: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F8854: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8858: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806F885C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x806F8860: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806F8864: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806F8868: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806F886C: bc1f        L_806F88A8
    if (!c1cs) {
        // 0x806F8870: lui         $t7, 0x8070
        ctx->r15 = S32(RELOC_HI16(694, 0X10B4) << 16);
            goto L_806F88A8;
    }
    // 0x806F8870: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(694, 0X10B4) << 16);
    // 0x806F8874: addiu       $t7, $t7, -0x773C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(694, 0X10B4));
    // 0x806F8878: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x806F887C: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806F8880: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806F8884: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x806F8888: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B34) << 16);
    // 0x806F888C: lwc1        $f4, -0x6CBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B34));
    // 0x806F8890: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806F8894: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F8898: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F889C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806F88A0: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x806F88A4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
L_806F88A8:
    // 0x806F88A8: swc1        $f2, 0x5F0($a1)
    MEM_W(0X5F0, ctx->r5) = ctx->f2.u32l;
L_806F88AC:
    // 0x806F88AC: jal         0x806F85A0
    // 0x806F88B0: addiu       $a0, $a1, 0x268
    ctx->r4 = ADD32(ctx->r5, 0X268);
    func_806F85A0(rdram, ctx);
        goto after_2;
    // 0x806F88B0: addiu       $a0, $a1, 0x268
    ctx->r4 = ADD32(ctx->r5, 0X268);
    after_2:
    // 0x806F88B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F88B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F88BC: jr          $ra
    // 0x806F88C0: nop

    return;
    // 0x806F88C0: nop

;}
RECOMP_FUNC void func_80050E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050E44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050E48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80050E4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050E50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80050E54: jal         0x80050C8C
    // 0x80050E58: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_80050C8C(rdram, ctx);
        goto after_0;
    // 0x80050E58: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x80050E5C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80050E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80050E64: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80050E68: bne         $a1, $zero, L_80050E80
    if (ctx->r5 != 0) {
        // 0x80050E6C: lui         $a3, 0x8006
        ctx->r7 = S32(0X8006 << 16);
            goto L_80050E80;
    }
    // 0x80050E6C: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80050E70: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80050E74: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80050E78: b           L_80050ECC
    // 0x80050E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80050ECC;
    // 0x80050E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050E80:
    // 0x80050E80: jal         0x800675D0
    // 0x80050E84: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x80050E84: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    after_1:
    // 0x80050E88: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x80050E8C: beql        $t7, $zero, L_80050EB0
    if (ctx->r15 == 0) {
        // 0x80050E90: lw          $t8, 0x34($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X34);
            goto L_80050EB0;
    }
    goto skip_0;
    // 0x80050E90: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80050E94: jal         0x80050DB0
    // 0x80050E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80050DB0(rdram, ctx);
        goto after_2;
    // 0x80050E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80050E9C: bnel        $v0, $zero, L_80050EB0
    if (ctx->r2 != 0) {
        // 0x80050EA0: lw          $t8, 0x34($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X34);
            goto L_80050EB0;
    }
    goto skip_1;
    // 0x80050EA0: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x80050EA4: b           L_80050ECC
    // 0x80050EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050ECC;
    // 0x80050EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80050EAC: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
L_80050EB0:
    // 0x80050EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050EB4: beq         $t8, $zero, L_80050ECC
    if (ctx->r24 == 0) {
        // 0x80050EB8: nop
    
            goto L_80050ECC;
    }
    // 0x80050EB8: nop

    // 0x80050EBC: jal         0x80050DF8
    // 0x80050EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80050DF8(rdram, ctx);
        goto after_3;
    // 0x80050EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80050EC4: b           L_80050ED0
    // 0x80050EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80050ED0;
    // 0x80050EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80050ECC:
    // 0x80050ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80050ED0:
    // 0x80050ED0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050ED8: jr          $ra
    // 0x80050EDC: nop

    return;
    // 0x80050EDC: nop

;}
RECOMP_FUNC void func_8051A520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A520: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(294, 0X188) << 16);
    // 0x8051A524: addiu       $v0, $v0, -0x5958
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(294, 0X188));
    // 0x8051A528: jr          $ra
    // 0x8051A52C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8051A52C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806D2844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2844: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D2848: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D284C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D2850: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D2854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D2858: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x806D285C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x806D2860: jal         0x8004700C
    // 0x806D2864: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D2864: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_0:
    // 0x806D2868: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x806D286C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x806D2870: beq         $v0, $zero, L_806D2980
    if (ctx->r2 == 0) {
        // 0x806D2874: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_806D2980;
    }
    // 0x806D2874: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806D2878: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x806D287C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D2880: beq         $v0, $zero, L_806D2890
    if (ctx->r2 == 0) {
        // 0x806D2884: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806D2890;
    }
    // 0x806D2884: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806D2888: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x806D288C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_806D2890:
    // 0x806D2890: bne         $v0, $zero, L_806D294C
    if (ctx->r2 != 0) {
        // 0x806D2894: nop
    
            goto L_806D294C;
    }
    // 0x806D2894: nop

    // 0x806D2898: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806D289C: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D28A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806D28A4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806D28A8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x806D28AC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x806D28B0: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x806D28B4: lwc1        $f8, 0x6C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x806D28B8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806D28BC: swc1        $f10, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f10.u32l;
    // 0x806D28C0: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D28C4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806D28C8: nop

    // 0x806D28CC: bc1f        L_806D294C
    if (!c1cs) {
        // 0x806D28D0: nop
    
            goto L_806D294C;
    }
    // 0x806D28D0: nop

    // 0x806D28D4: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x806D28D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806D28DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806D28E0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x806D28E4: lw          $t8, 0xE70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE70);
    // 0x806D28E8: lw          $t7, 0xE88($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE88);
    // 0x806D28EC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x806D28F0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x806D28F4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x806D28F8: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x806D28FC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806D2900: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x806D2904: lwc1        $f16, 0x8C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8C);
    // 0x806D2908: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x806D290C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x806D2910: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x806D2914: jalr        $t9
    // 0x806D2918: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806D2918: nop

    after_1:
    // 0x806D291C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x806D2920: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x806D2924: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X16B8) << 16);
    // 0x806D2928: addiu       $a1, $a1, 0x2C78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X16B8));
    // 0x806D292C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x806D2930: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x806D2934: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D2938: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x806D293C: jalr        $t9
    // 0x806D2940: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x806D2940: nop

    after_2:
    // 0x806D2944: jal         0x800447C8
    // 0x806D2948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x806D2948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_806D294C:
    // 0x806D294C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806D2950: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x806D2954: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x806D2958: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D295C: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x806D2960: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x806D2964: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x806D2968: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806D296C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806D2970: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x806D2974: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x806D2978: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806D297C: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
L_806D2980:
    // 0x806D2980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D2984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D2988: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806D298C: jr          $ra
    // 0x806D2990: nop

    return;
    // 0x806D2990: nop

;}
RECOMP_FUNC void func_80075FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075FDC: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
    // 0x80075FE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80075FE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075FE8: lui         $t6, 0xD00
    ctx->r14 = S32(0XD00 << 16);
    // 0x80075FEC: addiu       $t6, $t6, 0x180
    ctx->r14 = ADD32(ctx->r14, 0X180);
    // 0x80075FF0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80075FF4: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80075FF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80075FFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076000: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x80076004: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80076008: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007600C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80076010: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076014: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80076018: lw          $t9, -0x7AF0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AF0);
    // 0x8007601C: lui         $t2, 0xD00
    ctx->r10 = S32(0XD00 << 16);
    // 0x80076020: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076024: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80076028: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x8007602C: addiu       $t2, $t2, 0x150
    ctx->r10 = ADD32(ctx->r10, 0X150);
    // 0x80076030: beq         $t0, $zero, L_80076048
    if (ctx->r8 == 0) {
        // 0x80076034: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80076048;
    }
    // 0x80076034: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076038: addiu       $t1, $t1, 0x168
    ctx->r9 = ADD32(ctx->r9, 0X168);
    // 0x8007603C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80076040: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076044: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_80076048:
    // 0x80076048: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007604C: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80076050: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80076054: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076058: sw          $zero, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = 0;
    // 0x8007605C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076060: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x80076064: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80076068: jr          $ra
    // 0x8007606C: nop

    return;
    // 0x8007606C: nop

;}
RECOMP_FUNC void func_8005FAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FAE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FAE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FAE8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FAEC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FAF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005FAF4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FAF8: lbu         $t7, 0x77($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X77);
    // 0x8005FAFC: bnel        $t7, $zero, L_8005FB20
    if (ctx->r15 != 0) {
        // 0x8005FB00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FB20;
    }
    goto skip_0;
    // 0x8005FB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FB04: jal         0x8005F9A8
    // 0x8005FB08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005F9A8(rdram, ctx);
        goto after_0;
    // 0x8005FB08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005FB0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FB10: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005FB14: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005FB18: sb          $t8, 0x77($t9)
    MEM_B(0X77, ctx->r25) = ctx->r24;
    // 0x8005FB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FB20:
    // 0x8005FB20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FB24: jr          $ra
    // 0x8005FB28: nop

    return;
    // 0x8005FB28: nop

;}
RECOMP_FUNC void func_80008A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008A58: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80008A5C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80008A60: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80008A64: addiu       $s1, $a1, 0xF
    ctx->r17 = ADD32(ctx->r5, 0XF);
    // 0x80008A68: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80008A6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80008A70: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80008A74: and         $s1, $s1, $at
    ctx->r17 = ctx->r17 & ctx->r1;
    // 0x80008A78: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80008A7C: jal         0x8000AC90
    // 0x80008A80: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    func_8000AC90(rdram, ctx);
        goto after_0;
    // 0x80008A80: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    after_0:
    // 0x80008A84: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80008A88: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80008A8C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x80008A90: jal         0x8008AE20
    // 0x80008A94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80008A94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80008A98: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80008A9C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80008AA0: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80008AA4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80008AA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80008AAC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80008AB0: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x80008AB4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80008AB8: addiu       $t9, $t9, -0x7CC0
    ctx->r25 = ADD32(ctx->r25, -0X7CC0);
    // 0x80008ABC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80008AC0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80008AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80008ACC: jal         0x800077AC
    // 0x80008AD0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_800077AC(rdram, ctx);
        goto after_2;
    // 0x80008AD0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_2:
    // 0x80008AD4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80008AD8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80008ADC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80008AE0: jr          $ra
    // 0x80008AE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80008AE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8057D740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057D740: lui         $v0, 0x8058
    ctx->r2 = S32(RELOC_HI16(390, 0X254) << 16);
    // 0x8057D744: addiu       $v0, $v0, -0x266C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(390, 0X254));
    // 0x8057D748: jr          $ra
    // 0x8057D74C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8057D74C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806B1BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1BC4: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x806B1BC8: beql        $at, $zero, L_806B1BE0
    if (ctx->r1 == 0) {
        // 0x806B1BCC: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_806B1BE0;
    }
    goto skip_0;
    // 0x806B1BCC: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x806B1BD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B1BD4: jr          $ra
    // 0x806B1BD8: nop

    return;
    // 0x806B1BD8: nop

    // 0x806B1BDC: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_806B1BE0:
    // 0x806B1BE0: beq         $at, $zero, L_806B1C10
    if (ctx->r1 == 0) {
        // 0x806B1BE4: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_806B1C10;
    }
    // 0x806B1BE4: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x806B1BE8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806B1BEC: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806B1BF0: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x806B1BF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806B1BF8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x806B1BFC: nop

    // 0x806B1C00: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806B1C04: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x806B1C08: jr          $ra
    // 0x806B1C0C: div.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    return;
    // 0x806B1C0C: div.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
L_806B1C10:
    // 0x806B1C10: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x806B1C14: beq         $at, $zero, L_806B1C24
    if (ctx->r1 == 0) {
        // 0x806B1C18: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_806B1C24;
    }
    // 0x806B1C18: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x806B1C1C: jr          $ra
    // 0x806B1C20: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x806B1C20: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
L_806B1C24:
    // 0x806B1C24: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x806B1C28: beq         $at, $zero, L_806B1C5C
    if (ctx->r1 == 0) {
        // 0x806B1C2C: subu        $t8, $a0, $a3
        ctx->r24 = SUB32(ctx->r4, ctx->r7);
            goto L_806B1C5C;
    }
    // 0x806B1C2C: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x806B1C30: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x806B1C34: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x806B1C38: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x806B1C3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806B1C40: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x806B1C44: nop

    // 0x806B1C48: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806B1C4C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x806B1C50: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806B1C54: jr          $ra
    // 0x806B1C58: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
    return;
    // 0x806B1C58: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
L_806B1C5C:
    // 0x806B1C5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B1C60: nop

    // 0x806B1C64: jr          $ra
    // 0x806B1C68: nop

    return;
    // 0x806B1C68: nop

;}
RECOMP_FUNC void func_8073F760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073F764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073F768: jal         0x8004700C
    // 0x8073F76C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073F76C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073F770: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8073F774: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8073F778: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8073F77C: addiu       $a1, $v1, 0xC4
    ctx->r5 = ADD32(ctx->r3, 0XC4);
    // 0x8073F780: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8073F784: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8073F788: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8073F78C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8073F790: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8073F794: bc1f        L_8073F7B8
    if (!c1cs) {
        // 0x8073F798: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_8073F7B8;
    }
    // 0x8073F798: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8073F79C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8073F7A0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8073F7A4: nop

    // 0x8073F7A8: bc1f        L_8073F7D0
    if (!c1cs) {
        // 0x8073F7AC: nop
    
            goto L_8073F7D0;
    }
    // 0x8073F7AC: nop

    // 0x8073F7B0: b           L_8073F7D0
    // 0x8073F7B4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8073F7D0;
    // 0x8073F7B4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8073F7B8:
    // 0x8073F7B8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8073F7BC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8073F7C0: nop

    // 0x8073F7C4: bc1f        L_8073F7D0
    if (!c1cs) {
        // 0x8073F7C8: nop
    
            goto L_8073F7D0;
    }
    // 0x8073F7C8: nop

    // 0x8073F7CC: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8073F7D0:
    // 0x8073F7D0: beql        $v0, $zero, L_8073F83C
    if (ctx->r2 == 0) {
        // 0x8073F7D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F83C;
    }
    goto skip_0;
    // 0x8073F7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8073F7D8: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8073F7DC: bnel        $v1, $t6, L_8073F83C
    if (ctx->r3 != ctx->r14) {
        // 0x8073F7E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F83C;
    }
    goto skip_1;
    // 0x8073F7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8073F7E4: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x8073F7E8: bne         $t7, $zero, L_8073F818
    if (ctx->r15 != 0) {
        // 0x8073F7EC: nop
    
            goto L_8073F818;
    }
    // 0x8073F7EC: nop

    // 0x8073F7F0: jal         0x800474D8
    // 0x8073F7F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800474D8(rdram, ctx);
        goto after_1;
    // 0x8073F7F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8073F7F8: beql        $v0, $zero, L_8073F83C
    if (ctx->r2 == 0) {
        // 0x8073F7FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F83C;
    }
    goto skip_2;
    // 0x8073F7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8073F800: jal         0x80060FE0
    // 0x8073F804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80060FE0(rdram, ctx);
        goto after_2;
    // 0x8073F804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8073F808: jal         0x8005FE48
    // 0x8073F80C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8073F80C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8073F810: b           L_8073F83C
    // 0x8073F814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8073F83C;
    // 0x8073F814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073F818:
    // 0x8073F818: jal         0x80047534
    // 0x8073F81C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    func_80047534(rdram, ctx);
        goto after_4;
    // 0x8073F81C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    after_4:
    // 0x8073F820: beql        $v0, $zero, L_8073F83C
    if (ctx->r2 == 0) {
        // 0x8073F824: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F83C;
    }
    goto skip_3;
    // 0x8073F824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8073F828: jal         0x80060FE0
    // 0x8073F82C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80060FE0(rdram, ctx);
        goto after_5;
    // 0x8073F82C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8073F830: jal         0x8005FE48
    // 0x8073F834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FE48(rdram, ctx);
        goto after_6;
    // 0x8073F834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x8073F838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073F83C:
    // 0x8073F83C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073F840: jr          $ra
    // 0x8073F844: nop

    return;
    // 0x8073F844: nop

;}
RECOMP_FUNC void func_80521ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521ED4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80521ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521EDC: jal         0x80521FC0
    // 0x80521EE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80521FC0(rdram, ctx);
        goto after_0;
    // 0x80521EE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80521EE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80521EE8: lw          $t6, 0x1E0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1E0);
    // 0x80521EEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80521EF0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80521EF4: slti        $at, $t7, 0xC8
    ctx->r1 = SIGNED(ctx->r15) < 0XC8 ? 1 : 0;
    // 0x80521EF8: bne         $at, $zero, L_80521F0C
    if (ctx->r1 != 0) {
        // 0x80521EFC: sw          $t7, 0x1E0($a2)
        MEM_W(0X1E0, ctx->r6) = ctx->r15;
            goto L_80521F0C;
    }
    // 0x80521EFC: sw          $t7, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r15;
    // 0x80521F00: jal         0x80521EA0
    // 0x80521F04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80521EA0(rdram, ctx);
        goto after_1;
    // 0x80521F04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80521F08: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80521F0C:
    // 0x80521F0C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x80521F10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80521F14: jal         0x80048F84
    // 0x80521F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80521F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80521F1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80521F20: jal         0x80048F84
    // 0x80521F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x80521F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80521F28: beq         $v0, $zero, L_80521F44
    if (ctx->r2 == 0) {
        // 0x80521F2C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80521F44;
    }
    // 0x80521F2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80521F30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80521F34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80521F38: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80521F3C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80521F40: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
L_80521F44:
    // 0x80521F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521F48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80521F4C: jr          $ra
    // 0x80521F50: nop

    return;
    // 0x80521F50: nop

;}
RECOMP_FUNC void func_80788AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80788AB0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80788AB4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80788AB8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80788ABC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80788AC0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80788AC4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80788AC8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80788ACC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80788AD0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80788AD4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80788AD8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80788ADC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80788AE0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80788AE4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80788AE8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80788AEC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80788AF0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80788AF4: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x80788AF8: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x80788AFC: lhu         $t8, 0xDA($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XDA);
    // 0x80788B00: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80788B04: lw          $t6, 0x43E4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X43E4);
    // 0x80788B08: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80788B0C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80788B10: sllv        $s7, $t7, $t6
    ctx->r23 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80788B14: beq         $t8, $zero, L_80788B40
    if (ctx->r24 == 0) {
        // 0x80788B18: andi        $s7, $s7, 0xFF
        ctx->r23 = ctx->r23 & 0XFF;
            goto L_80788B40;
    }
    // 0x80788B18: andi        $s7, $s7, 0xFF
    ctx->r23 = ctx->r23 & 0XFF;
    // 0x80788B1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80788B20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80788B24: lwc1        $f6, 0x52C8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X52C8);
    // 0x80788B28: lwc1        $f10, 0x52CC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X52CC);
    // 0x80788B2C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80788B30: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80788B34: mul.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80788B38: b           L_80788B68
    // 0x80788B3C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
        goto L_80788B68;
    // 0x80788B3C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
L_80788B40:
    // 0x80788B40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80788B44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80788B48: lwc1        $f4, 0x52C8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X52C8);
    // 0x80788B4C: lwc1        $f10, 0x52CC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X52CC);
    // 0x80788B50: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80788B54: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80788B58: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x80788B5C: mul.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80788B60: nop

    // 0x80788B64: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
L_80788B68:
    // 0x80788B68: mfc1        $s6, $f18
    ctx->r22 = (int32_t)ctx->f18.u32l;
    // 0x80788B6C: nop

    // 0x80788B70: bltz        $s6, L_80788F3C
    if (SIGNED(ctx->r22) < 0) {
        // 0x80788B74: slti        $at, $s6, 0xB5
        ctx->r1 = SIGNED(ctx->r22) < 0XB5 ? 1 : 0;
            goto L_80788F3C;
    }
    // 0x80788B74: slti        $at, $s6, 0xB5
    ctx->r1 = SIGNED(ctx->r22) < 0XB5 ? 1 : 0;
    // 0x80788B78: beq         $at, $zero, L_80788F3C
    if (ctx->r1 == 0) {
        // 0x80788B7C: sll         $t0, $s6, 2
        ctx->r8 = S32(ctx->r22 << 2);
            goto L_80788F3C;
    }
    // 0x80788B7C: sll         $t0, $s6, 2
    ctx->r8 = S32(ctx->r22 << 2);
    // 0x80788B80: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x80788B84: lwc1        $f4, 0x4990($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4990);
    // 0x80788B88: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x80788B8C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80788B90: c.lt.s      $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f4.fl < ctx->f26.fl;
    // 0x80788B94: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80788B98: lwc1        $f28, 0xD0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80788B9C: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x80788BA0: bc1fl       L_80788D6C
    if (!c1cs) {
        // 0x80788BA4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80788D6C;
    }
    goto skip_0;
    // 0x80788BA4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80788BA8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80788BAC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80788BB0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80788BB4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80788BB8: lwc1        $f28, 0xD0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80788BBC: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x80788BC0: mov.s       $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    ctx->f24.fl = ctx->f22.fl;
L_80788BC4:
    // 0x80788BC4: subu        $s1, $s6, $s4
    ctx->r17 = SUB32(ctx->r22, ctx->r20);
    // 0x80788BC8: bltz        $s1, L_80788C7C
    if (SIGNED(ctx->r17) < 0) {
        // 0x80788BCC: sll         $t2, $s1, 2
        ctx->r10 = S32(ctx->r17 << 2);
            goto L_80788C7C;
    }
    // 0x80788BCC: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80788BD0: sll         $t4, $s1, 3
    ctx->r12 = S32(ctx->r17 << 3);
    // 0x80788BD4: addu        $s0, $s3, $t4
    ctx->r16 = ADD32(ctx->r19, ctx->r12);
    // 0x80788BD8: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x80788BDC: lwc1        $f10, 0x4990($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788BE0: lwc1        $f16, 0x43E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X43E8);
    // 0x80788BE4: sub.s       $f8, $f28, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f30.fl;
    // 0x80788BE8: addu        $t5, $s3, $s1
    ctx->r13 = ADD32(ctx->r19, ctx->r17);
    // 0x80788BEC: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80788BF0: add.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80788BF4: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x80788BF8: nop

    // 0x80788BFC: bc1fl       L_80788C80
    if (!c1cs) {
        // 0x80788C00: addu        $s1, $s6, $s4
        ctx->r17 = ADD32(ctx->r22, ctx->r20);
            goto L_80788C80;
    }
    goto skip_1;
    // 0x80788C00: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
    skip_1:
    // 0x80788C04: lbu         $t7, 0x520C($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X520C);
    // 0x80788C08: and         $t6, $t7, $s7
    ctx->r14 = ctx->r15 & ctx->r23;
    // 0x80788C0C: bnel        $t6, $zero, L_80788C80
    if (ctx->r14 != 0) {
        // 0x80788C10: addu        $s1, $s6, $s4
        ctx->r17 = ADD32(ctx->r22, ctx->r20);
            goto L_80788C80;
    }
    goto skip_2;
    // 0x80788C10: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
    skip_2:
    // 0x80788C14: jal         0x80066E88
    // 0x80788C18: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80788C18: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80788C1C: sub.s       $f18, $f20, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x80788C20: lwc1        $f6, 0x43E8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X43E8);
    // 0x80788C24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80788C28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80788C2C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80788C30: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80788C34: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80788C38: swc1        $f10, 0x43E8($s0)
    MEM_W(0X43E8, ctx->r16) = ctx->f10.u32l;
    // 0x80788C3C: jal         0x807889C4
    // 0x80788C40: lw          $a2, 0x43E8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X43E8);
    func_807889C4(rdram, ctx);
        goto after_1;
    // 0x80788C40: lw          $a2, 0x43E8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X43E8);
    after_1:
    // 0x80788C44: lwc1        $f16, 0x4990($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788C48: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80788C4C: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80788C50: swc1        $f18, 0x4990($s2)
    MEM_W(0X4990, ctx->r18) = ctx->f18.u32l;
    // 0x80788C54: lwc1        $f6, 0x43E8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X43E8);
    // 0x80788C58: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80788C5C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80788C60: swc1        $f10, 0x43E8($s0)
    MEM_W(0X43E8, ctx->r16) = ctx->f10.u32l;
    // 0x80788C64: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80788C68: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
    // 0x80788C6C: nop

    // 0x80788C70: bc1fl       L_80788C80
    if (!c1cs) {
        // 0x80788C74: addu        $s1, $s6, $s4
        ctx->r17 = ADD32(ctx->r22, ctx->r20);
            goto L_80788C80;
    }
    goto skip_3;
    // 0x80788C74: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
    skip_3:
    // 0x80788C78: mov.s       $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    ctx->f24.fl = ctx->f16.fl;
L_80788C7C:
    // 0x80788C7C: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
L_80788C80:
    // 0x80788C80: slti        $at, $s1, 0xB5
    ctx->r1 = SIGNED(ctx->r17) < 0XB5 ? 1 : 0;
    // 0x80788C84: beq         $at, $zero, L_80788D38
    if (ctx->r1 == 0) {
        // 0x80788C88: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_80788D38;
    }
    // 0x80788C88: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80788C8C: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x80788C90: addu        $s0, $s3, $t0
    ctx->r16 = ADD32(ctx->r19, ctx->r8);
    // 0x80788C94: addu        $s2, $s3, $t8
    ctx->r18 = ADD32(ctx->r19, ctx->r24);
    // 0x80788C98: lwc1        $f8, 0x4990($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788C9C: lwc1        $f18, 0x43E8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X43E8);
    // 0x80788CA0: sub.s       $f6, $f28, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f30.fl;
    // 0x80788CA4: addu        $t1, $s3, $s1
    ctx->r9 = ADD32(ctx->r19, ctx->r17);
    // 0x80788CA8: add.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80788CAC: add.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80788CB0: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x80788CB4: nop

    // 0x80788CB8: bc1fl       L_80788D3C
    if (!c1cs) {
        // 0x80788CBC: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80788D3C;
    }
    goto skip_4;
    // 0x80788CBC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_4:
    // 0x80788CC0: lbu         $t2, 0x520C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X520C);
    // 0x80788CC4: and         $t3, $t2, $s7
    ctx->r11 = ctx->r10 & ctx->r23;
    // 0x80788CC8: bnel        $t3, $zero, L_80788D3C
    if (ctx->r11 != 0) {
        // 0x80788CCC: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80788D3C;
    }
    goto skip_5;
    // 0x80788CCC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_5:
    // 0x80788CD0: jal         0x80066E88
    // 0x80788CD4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80788CD4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x80788CD8: sub.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x80788CDC: lwc1        $f4, 0x43E8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X43E8);
    // 0x80788CE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80788CE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80788CE8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80788CEC: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80788CF0: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80788CF4: swc1        $f8, 0x43E8($s0)
    MEM_W(0X43E8, ctx->r16) = ctx->f8.u32l;
    // 0x80788CF8: jal         0x807889C4
    // 0x80788CFC: lw          $a2, 0x43E8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X43E8);
    func_807889C4(rdram, ctx);
        goto after_3;
    // 0x80788CFC: lw          $a2, 0x43E8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X43E8);
    after_3:
    // 0x80788D00: lwc1        $f18, 0x4990($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788D04: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80788D08: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80788D0C: swc1        $f10, 0x4990($s2)
    MEM_W(0X4990, ctx->r18) = ctx->f10.u32l;
    // 0x80788D10: lwc1        $f4, 0x43E8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X43E8);
    // 0x80788D14: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80788D18: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80788D1C: swc1        $f8, 0x43E8($s0)
    MEM_W(0X43E8, ctx->r16) = ctx->f8.u32l;
    // 0x80788D20: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80788D24: c.lt.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl < ctx->f18.fl;
    // 0x80788D28: nop

    // 0x80788D2C: bc1fl       L_80788D3C
    if (!c1cs) {
        // 0x80788D30: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80788D3C;
    }
    goto skip_6;
    // 0x80788D30: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_6:
    // 0x80788D34: mov.s       $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    ctx->f24.fl = ctx->f18.fl;
L_80788D38:
    // 0x80788D38: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80788D3C:
    // 0x80788D3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80788D40: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80788D44: bne         $s4, $fp, L_80788BC4
    if (ctx->r20 != ctx->r30) {
        // 0x80788D48: add.s       $f22, $f22, $f6
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
            goto L_80788BC4;
    }
    // 0x80788D48: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80788D4C: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x80788D50: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80788D54: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x80788D58: jalr        $t9
    // 0x80788D5C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80788D5C: nop

    after_4:
    // 0x80788D60: b           L_80788F40
    // 0x80788D64: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
        goto L_80788F40;
    // 0x80788D64: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80788D68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80788D6C:
    // 0x80788D6C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80788D70: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x80788D74: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    // 0x80788D78: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
L_80788D7C:
    // 0x80788D7C: subu        $s1, $s6, $s4
    ctx->r17 = SUB32(ctx->r22, ctx->r20);
    // 0x80788D80: bltz        $s1, L_80788E40
    if (SIGNED(ctx->r17) < 0) {
        // 0x80788D84: sll         $t4, $s1, 2
        ctx->r12 = S32(ctx->r17 << 2);
            goto L_80788E40;
    }
    // 0x80788D84: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80788D88: sll         $t7, $s1, 3
    ctx->r15 = S32(ctx->r17 << 3);
    // 0x80788D8C: addu        $s0, $s3, $t7
    ctx->r16 = ADD32(ctx->r19, ctx->r15);
    // 0x80788D90: addu        $s2, $s3, $t4
    ctx->r18 = ADD32(ctx->r19, ctx->r12);
    // 0x80788D94: lwc1        $f10, 0x4990($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788D98: lwc1        $f4, 0x43EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788D9C: sub.s       $f16, $f28, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f28.fl - ctx->f30.fl;
    // 0x80788DA0: addu        $t6, $s3, $s1
    ctx->r14 = ADD32(ctx->r19, ctx->r17);
    // 0x80788DA4: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80788DA8: sub.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80788DAC: add.s       $f20, $f8, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x80788DB0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80788DB4: nop

    // 0x80788DB8: bc1fl       L_80788E44
    if (!c1cs) {
        // 0x80788DBC: addu        $s1, $s6, $s4
        ctx->r17 = ADD32(ctx->r22, ctx->r20);
            goto L_80788E44;
    }
    goto skip_7;
    // 0x80788DBC: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
    skip_7:
    // 0x80788DC0: lbu         $t8, 0x520C($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X520C);
    // 0x80788DC4: and         $t0, $t8, $s7
    ctx->r8 = ctx->r24 & ctx->r23;
    // 0x80788DC8: bnel        $t0, $zero, L_80788E44
    if (ctx->r8 != 0) {
        // 0x80788DCC: addu        $s1, $s6, $s4
        ctx->r17 = ADD32(ctx->r22, ctx->r20);
            goto L_80788E44;
    }
    goto skip_8;
    // 0x80788DCC: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
    skip_8:
    // 0x80788DD0: jal         0x80066E88
    // 0x80788DD4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x80788DD4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_5:
    // 0x80788DD8: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80788DDC: lwc1        $f18, 0x43EC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788DE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80788DE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80788DE8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80788DEC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80788DF0: swc1        $f10, 0x43EC($s0)
    MEM_W(0X43EC, ctx->r16) = ctx->f10.u32l;
    // 0x80788DF4: lwc1        $f4, 0x43EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788DF8: neg.s       $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = -ctx->f4.fl;
    // 0x80788DFC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80788E00: jal         0x807889C4
    // 0x80788E04: nop

    func_807889C4(rdram, ctx);
        goto after_6;
    // 0x80788E04: nop

    after_6:
    // 0x80788E08: lwc1        $f8, 0x4990($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788E0C: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80788E10: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80788E14: swc1        $f6, 0x4990($s2)
    MEM_W(0X4990, ctx->r18) = ctx->f6.u32l;
    // 0x80788E18: lwc1        $f10, 0x43EC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788E1C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80788E20: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80788E24: swc1        $f16, 0x43EC($s0)
    MEM_W(0X43EC, ctx->r16) = ctx->f16.u32l;
    // 0x80788E28: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80788E2C: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x80788E30: nop

    // 0x80788E34: bc1fl       L_80788E44
    if (!c1cs) {
        // 0x80788E38: addu        $s1, $s6, $s4
        ctx->r17 = ADD32(ctx->r22, ctx->r20);
            goto L_80788E44;
    }
    goto skip_9;
    // 0x80788E38: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
    skip_9:
    // 0x80788E3C: mov.s       $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = ctx->f8.fl;
L_80788E40:
    // 0x80788E40: addu        $s1, $s6, $s4
    ctx->r17 = ADD32(ctx->r22, ctx->r20);
L_80788E44:
    // 0x80788E44: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80788E48: slti        $at, $s1, 0xB5
    ctx->r1 = SIGNED(ctx->r17) < 0XB5 ? 1 : 0;
    // 0x80788E4C: beq         $at, $zero, L_80788F0C
    if (ctx->r1 == 0) {
        // 0x80788E50: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_80788F0C;
    }
    // 0x80788E50: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80788E54: sll         $t3, $s1, 3
    ctx->r11 = S32(ctx->r17 << 3);
    // 0x80788E58: addu        $s0, $s3, $t3
    ctx->r16 = ADD32(ctx->r19, ctx->r11);
    // 0x80788E5C: addu        $s2, $s3, $t1
    ctx->r18 = ADD32(ctx->r19, ctx->r9);
    // 0x80788E60: lwc1        $f18, 0x4990($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788E64: lwc1        $f6, 0x43EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788E68: sub.s       $f10, $f28, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f30.fl;
    // 0x80788E6C: addu        $t9, $s3, $s1
    ctx->r25 = ADD32(ctx->r19, ctx->r17);
    // 0x80788E70: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80788E74: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80788E78: add.s       $f20, $f4, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x80788E7C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80788E80: nop

    // 0x80788E84: bc1fl       L_80788F10
    if (!c1cs) {
        // 0x80788E88: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80788F10;
    }
    goto skip_10;
    // 0x80788E88: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_10:
    // 0x80788E8C: lbu         $t4, 0x520C($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X520C);
    // 0x80788E90: and         $t5, $t4, $s7
    ctx->r13 = ctx->r12 & ctx->r23;
    // 0x80788E94: bnel        $t5, $zero, L_80788F10
    if (ctx->r13 != 0) {
        // 0x80788E98: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80788F10;
    }
    goto skip_11;
    // 0x80788E98: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_11:
    // 0x80788E9C: jal         0x80066E88
    // 0x80788EA0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x80788EA0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_7:
    // 0x80788EA4: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80788EA8: lwc1        $f16, 0x43EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788EAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80788EB0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80788EB4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80788EB8: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80788EBC: swc1        $f18, 0x43EC($s0)
    MEM_W(0X43EC, ctx->r16) = ctx->f18.u32l;
    // 0x80788EC0: lwc1        $f6, 0x43EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788EC4: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80788EC8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80788ECC: jal         0x807889C4
    // 0x80788ED0: nop

    func_807889C4(rdram, ctx);
        goto after_8;
    // 0x80788ED0: nop

    after_8:
    // 0x80788ED4: lwc1        $f4, 0x4990($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4990);
    // 0x80788ED8: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80788EDC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80788EE0: swc1        $f8, 0x4990($s2)
    MEM_W(0X4990, ctx->r18) = ctx->f8.u32l;
    // 0x80788EE4: lwc1        $f18, 0x43EC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X43EC);
    // 0x80788EE8: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80788EEC: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80788EF0: swc1        $f10, 0x43EC($s0)
    MEM_W(0X43EC, ctx->r16) = ctx->f10.u32l;
    // 0x80788EF4: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80788EF8: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x80788EFC: nop

    // 0x80788F00: bc1fl       L_80788F10
    if (!c1cs) {
        // 0x80788F04: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80788F10;
    }
    goto skip_12;
    // 0x80788F04: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_12:
    // 0x80788F08: mov.s       $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = ctx->f4.fl;
L_80788F0C:
    // 0x80788F0C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80788F10:
    // 0x80788F10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80788F14: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80788F18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80788F1C: bne         $s4, $fp, L_80788D7C
    if (ctx->r20 != ctx->r30) {
        // 0x80788F20: add.s       $f22, $f22, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
            goto L_80788D7C;
    }
    // 0x80788F20: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x80788F24: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x80788F28: neg.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = -ctx->f24.fl;
    // 0x80788F2C: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x80788F30: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80788F34: jalr        $t9
    // 0x80788F38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80788F38: nop

    after_9:
L_80788F3C:
    // 0x80788F3C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80788F40:
    // 0x80788F40: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80788F44: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80788F48: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80788F4C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80788F50: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80788F54: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80788F58: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80788F5C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80788F60: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80788F64: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80788F68: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80788F6C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80788F70: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80788F74: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80788F78: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80788F7C: jr          $ra
    // 0x80788F80: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80788F80: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80027D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027D5C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027D60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80027D64: addiu       $t6, $t6, 0x4778
    ctx->r14 = ADD32(ctx->r14, 0X4778);
    // 0x80027D68: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x80027D6C: sb          $v0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r2;
    // 0x80027D70: jr          $ra
    // 0x80027D74: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    return;
    // 0x80027D74: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8000E02C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E02C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000E030: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000E034: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000E038: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000E03C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000E040: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000E044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000E048: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000E04C: lw          $s4, 0x50($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X50);
    // 0x8000E050: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000E054: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000E058: lwc1        $f20, -0x4258($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4258);
    // 0x8000E05C: addiu       $s2, $a0, 0x54
    ctx->r18 = ADD32(ctx->r4, 0X54);
    // 0x8000E060: lw          $s3, 0x4C($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X4C);
L_8000E064:
    // 0x8000E064: jal         0x8000DCB4
    // 0x8000E068: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_0;
    // 0x8000E068: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8000E06C: slti        $at, $v0, 0xC1
    ctx->r1 = SIGNED(ctx->r2) < 0XC1 ? 1 : 0;
    // 0x8000E070: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8000E074: beq         $at, $zero, L_8000E084
    if (ctx->r1 == 0) {
        // 0x8000E078: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000E084;
    }
    // 0x8000E078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000E07C: b           L_8000E374
    // 0x8000E080: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8000E374;
    // 0x8000E080: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8000E084:
    // 0x8000E084: slti        $at, $a0, 0xF2
    ctx->r1 = SIGNED(ctx->r4) < 0XF2 ? 1 : 0;
    // 0x8000E088: bne         $at, $zero, L_8000E0C8
    if (ctx->r1 != 0) {
        // 0x8000E08C: addiu       $t6, $a0, -0xC1
        ctx->r14 = ADD32(ctx->r4, -0XC1);
            goto L_8000E0C8;
    }
    // 0x8000E08C: addiu       $t6, $a0, -0xC1
    ctx->r14 = ADD32(ctx->r4, -0XC1);
    // 0x8000E090: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000E094: jal         0x8000D330
    // 0x8000E098: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    func_8000D330(rdram, ctx);
        goto after_1;
    // 0x8000E098: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_1:
    // 0x8000E09C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000E0A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000E0A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8000E0A8: jal         0x8000D398
    // 0x8000E0AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_8000D398(rdram, ctx);
        goto after_2;
    // 0x8000E0AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_2:
    // 0x8000E0B0: beq         $v0, $zero, L_8000E064
    if (ctx->r2 == 0) {
        // 0x8000E0B4: nop
    
            goto L_8000E064;
    }
    // 0x8000E0B4: nop

    // 0x8000E0B8: jal         0x8000D7E0
    // 0x8000E0BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000D7E0(rdram, ctx);
        goto after_3;
    // 0x8000E0BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8000E0C0: b           L_8000E374
    // 0x8000E0C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E374;
    // 0x8000E0C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E0C8:
    // 0x8000E0C8: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x8000E0CC: beq         $at, $zero, L_8000E310
    if (ctx->r1 == 0) {
        // 0x8000E0D0: andi        $v1, $a0, 0xF0
        ctx->r3 = ctx->r4 & 0XF0;
            goto L_8000E310;
    }
    // 0x8000E0D0: andi        $v1, $a0, 0xF0
    ctx->r3 = ctx->r4 & 0XF0;
    // 0x8000E0D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E0D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000E0DC: addu        $at, $at, $t6
    gpr jr_addend_8000E0E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E0E0: lw          $t6, -0x4254($at)
    ctx->r14 = ADD32(ctx->r1, -0X4254);
    // 0x8000E0E4: jr          $t6
    // 0x8000E0E8: nop

    switch (jr_addend_8000E0E4 >> 2) {
        case 0: goto L_8000E0EC; break;
        case 1: goto L_8000E12C; break;
        case 2: goto L_8000E198; break;
        case 3: goto L_8000E154; break;
        case 4: goto L_8000E154; break;
        case 5: goto L_8000E1A8; break;
        case 6: goto L_8000E218; break;
        case 7: goto L_8000E298; break;
        case 8: goto L_8000E12C; break;
        case 9: goto L_8000E0EC; break;
        case 10: goto L_8000E2A0; break;
        case 11: goto L_8000E2C8; break;
        case 12: goto L_8000E2D8; break;
        case 13: goto L_8000E2E8; break;
        case 14: goto L_8000E2B8; break;
        default: switch_error(__func__, 0x8000E0E4, 0x800ABDAC);
    }
    // 0x8000E0E8: nop

L_8000E0EC:
    // 0x8000E0EC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000E0F0: addiu       $at, $zero, 0xC1
    ctx->r1 = ADD32(0, 0XC1);
    // 0x8000E0F4: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E0F8: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8000E0FC: bne         $a0, $at, L_8000E124
    if (ctx->r4 != ctx->r1) {
        // 0x8000E100: sw          $t7, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r15;
            goto L_8000E124;
    }
    // 0x8000E100: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8000E104: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E108: mflo        $t8
    ctx->r24 = lo;
    // 0x8000E10C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000E110: nop

    // 0x8000E114: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E118: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8000E11C: b           L_8000E064
    // 0x8000E120: swc1        $f8, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f8.u32l;
        goto L_8000E064;
    // 0x8000E120: swc1        $f8, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f8.u32l;
L_8000E124:
    // 0x8000E124: b           L_8000E064
    // 0x8000E128: sb          $a1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r5;
        goto L_8000E064;
    // 0x8000E128: sb          $a1, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r5;
L_8000E12C:
    // 0x8000E12C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000E130: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x8000E134: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E138: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8000E13C: bne         $a0, $at, L_8000E14C
    if (ctx->r4 != ctx->r1) {
        // 0x8000E140: sw          $t9, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r25;
            goto L_8000E14C;
    }
    // 0x8000E140: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8000E144: b           L_8000E064
    // 0x8000E148: sb          $a1, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r5;
        goto L_8000E064;
    // 0x8000E148: sb          $a1, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r5;
L_8000E14C:
    // 0x8000E14C: b           L_8000E064
    // 0x8000E150: sh          $a1, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r5;
        goto L_8000E064;
    // 0x8000E150: sh          $a1, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r5;
L_8000E154:
    // 0x8000E154: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
    // 0x8000E158: bnel        $a0, $at, L_8000E174
    if (ctx->r4 != ctx->r1) {
        // 0x8000E15C: lbu         $t3, 0x0($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X0);
            goto L_8000E174;
    }
    goto skip_0;
    // 0x8000E15C: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    skip_0:
    // 0x8000E160: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x8000E164: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8000E168: b           L_8000E17C
    // 0x8000E16C: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
        goto L_8000E17C;
    // 0x8000E16C: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
    // 0x8000E170: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
L_8000E174:
    // 0x8000E174: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x8000E178: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
L_8000E17C:
    // 0x8000E17C: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    // 0x8000E180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000E184: andi        $t6, $t5, 0xFFFD
    ctx->r14 = ctx->r13 & 0XFFFD;
    // 0x8000E188: jal         0x8000BBF4
    // 0x8000E18C: sb          $t6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r14;
    func_8000BBF4(rdram, ctx);
        goto after_4;
    // 0x8000E18C: sb          $t6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r14;
    after_4:
    // 0x8000E190: b           L_8000E064
    // 0x8000E194: nop

        goto L_8000E064;
    // 0x8000E194: nop

L_8000E198:
    // 0x8000E198: jal         0x8000DD00
    // 0x8000E19C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DD00(rdram, ctx);
        goto after_5;
    // 0x8000E19C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8000E1A0: b           L_8000E064
    // 0x8000E1A4: sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
        goto L_8000E064;
    // 0x8000E1A4: sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
L_8000E1A8:
    // 0x8000E1A8: jal         0x8000DCB4
    // 0x8000E1AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_6;
    // 0x8000E1AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8000E1B0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x8000E1B4: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8000E1B8: bne         $at, $zero, L_8000E1F0
    if (ctx->r1 != 0) {
        // 0x8000E1BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000E1F0;
    }
    // 0x8000E1BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000E1C0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8000E1C4: bnel        $v0, $at, L_8000E1D8
    if (ctx->r2 != ctx->r1) {
        // 0x8000E1C8: sb          $v0, 0x2($s1)
        MEM_B(0X2, ctx->r17) = ctx->r2;
            goto L_8000E1D8;
    }
    goto skip_1;
    // 0x8000E1C8: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    skip_1:
    // 0x8000E1CC: b           L_8000E1DC
    // 0x8000E1D0: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
        goto L_8000E1DC;
    // 0x8000E1D0: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
    // 0x8000E1D4: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
L_8000E1D8:
    // 0x8000E1D8: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
L_8000E1DC:
    // 0x8000E1DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8000E1E0: bne         $a0, $at, L_8000E064
    if (ctx->r4 != ctx->r1) {
        // 0x8000E1E4: nop
    
            goto L_8000E064;
    }
    // 0x8000E1E4: nop

    // 0x8000E1E8: b           L_8000E064
    // 0x8000E1EC: sb          $zero, 0x18($s1)
    MEM_B(0X18, ctx->r17) = 0;
        goto L_8000E064;
    // 0x8000E1EC: sb          $zero, 0x18($s1)
    MEM_B(0X18, ctx->r17) = 0;
L_8000E1F0:
    // 0x8000E1F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000E1F4: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8000E1F8: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    // 0x8000E1FC: jal         0x8000EC48
    // 0x8000E200: addiu       $a3, $s1, 0x18
    ctx->r7 = ADD32(ctx->r17, 0X18);
    func_8000EC48(rdram, ctx);
        goto after_7;
    // 0x8000E200: addiu       $a3, $s1, 0x18
    ctx->r7 = ADD32(ctx->r17, 0X18);
    after_7:
    // 0x8000E204: bne         $v0, $zero, L_8000E064
    if (ctx->r2 != 0) {
        // 0x8000E208: sb          $v0, 0x2($s1)
        MEM_B(0X2, ctx->r17) = ctx->r2;
            goto L_8000E064;
    }
    // 0x8000E208: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8000E20C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8000E210: b           L_8000E064
    // 0x8000E214: sb          $t7, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r15;
        goto L_8000E064;
    // 0x8000E214: sb          $t7, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r15;
L_8000E218:
    // 0x8000E218: jal         0x8000DCB4
    // 0x8000E21C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_8;
    // 0x8000E21C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x8000E220: sb          $v0, 0x20($s1)
    MEM_B(0X20, ctx->r17) = ctx->r2;
    // 0x8000E224: jal         0x8000DCB4
    // 0x8000E228: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_9;
    // 0x8000E228: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8000E22C: lh          $t8, 0x26($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X26);
    // 0x8000E230: lh          $t9, 0x10($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X10);
    // 0x8000E234: lh          $t0, 0xE($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XE);
    // 0x8000E238: addu        $s0, $v0, $t8
    ctx->r16 = ADD32(ctx->r2, ctx->r24);
    // 0x8000E23C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8000E240: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8000E244: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8000E248: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x8000E24C: bnel        $at, $zero, L_8000E25C
    if (ctx->r1 != 0) {
        // 0x8000E250: lbu         $t1, 0x20($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X20);
            goto L_8000E25C;
    }
    goto skip_2;
    // 0x8000E250: lbu         $t1, 0x20($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X20);
    skip_2:
    // 0x8000E254: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000E258: lbu         $t1, 0x20($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X20);
L_8000E25C:
    // 0x8000E25C: sb          $s0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r16;
    // 0x8000E260: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8000E264: beq         $t2, $zero, L_8000E288
    if (ctx->r10 == 0) {
        // 0x8000E268: nop
    
            goto L_8000E288;
    }
    // 0x8000E268: nop

    // 0x8000E26C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000E270: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8000E274: sh          $t4, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r12;
    // 0x8000E278: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8000E27C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000E280: b           L_8000E064
    // 0x8000E284: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
        goto L_8000E064;
    // 0x8000E284: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_8000E288:
    // 0x8000E288: jal         0x8000DD00
    // 0x8000E28C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DD00(rdram, ctx);
        goto after_10;
    // 0x8000E28C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8000E290: b           L_8000E064
    // 0x8000E294: sh          $v0, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r2;
        goto L_8000E064;
    // 0x8000E294: sh          $v0, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r2;
L_8000E298:
    // 0x8000E298: b           L_8000E064
    // 0x8000E29C: sb          $zero, 0x20($s1)
    MEM_B(0X20, ctx->r17) = 0;
        goto L_8000E064;
    // 0x8000E29C: sb          $zero, 0x20($s1)
    MEM_B(0X20, ctx->r17) = 0;
L_8000E2A0:
    // 0x8000E2A0: jal         0x8000DCC8
    // 0x8000E2A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCC8(rdram, ctx);
        goto after_11;
    // 0x8000E2A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x8000E2A8: lw          $t7, 0x18($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X18);
    // 0x8000E2AC: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8000E2B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000E2B4: sw          $t9, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r25;
L_8000E2B8:
    // 0x8000E2B8: jal         0x8000DCB4
    // 0x8000E2BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_12;
    // 0x8000E2BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x8000E2C0: b           L_8000E064
    // 0x8000E2C4: sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
        goto L_8000E064;
    // 0x8000E2C4: sb          $v0, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r2;
L_8000E2C8:
    // 0x8000E2C8: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x8000E2CC: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8000E2D0: b           L_8000E064
    // 0x8000E2D4: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
        goto L_8000E064;
    // 0x8000E2D4: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
L_8000E2D8:
    // 0x8000E2D8: jal         0x8000DCB4
    // 0x8000E2DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_13;
    // 0x8000E2DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x8000E2E0: b           L_8000E064
    // 0x8000E2E4: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_8000E064;
    // 0x8000E2E4: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_8000E2E8:
    // 0x8000E2E8: jal         0x8000DCB4
    // 0x8000E2EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8000DCB4(rdram, ctx);
        goto after_14;
    // 0x8000E2EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x8000E2F0: addiu       $t3, $v0, 0x80
    ctx->r11 = ADD32(ctx->r2, 0X80);
    // 0x8000E2F4: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8000E2F8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000E2FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000E300: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8000E304: lwc1        $f10, 0x65D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65D4);
    // 0x8000E308: b           L_8000E064
    // 0x8000E30C: swc1        $f10, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f10.u32l;
        goto L_8000E064;
    // 0x8000E30C: swc1        $f10, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f10.u32l;
L_8000E310:
    // 0x8000E310: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x8000E314: beq         $v1, $at, L_8000E32C
    if (ctx->r3 == ctx->r1) {
        // 0x8000E318: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_8000E32C;
    }
    // 0x8000E318: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x8000E31C: beql        $v1, $at, L_8000E360
    if (ctx->r3 == ctx->r1) {
        // 0x8000E320: lw          $t0, 0x94($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X94);
            goto L_8000E360;
    }
    goto skip_3;
    // 0x8000E320: lw          $t0, 0x94($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X94);
    skip_3:
    // 0x8000E324: b           L_8000E064
    // 0x8000E328: nop

        goto L_8000E064;
    // 0x8000E328: nop

L_8000E32C:
    // 0x8000E32C: lw          $t6, 0x90($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X90);
    // 0x8000E330: andi        $t7, $a0, 0xF
    ctx->r15 = ctx->r4 & 0XF;
    // 0x8000E334: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000E338: lbu         $a1, 0x0($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X0);
    // 0x8000E33C: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E340: mflo        $t9
    ctx->r25 = lo;
    // 0x8000E344: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8000E348: nop

    // 0x8000E34C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000E350: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8000E354: b           L_8000E064
    // 0x8000E358: swc1        $f4, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f4.u32l;
        goto L_8000E064;
    // 0x8000E358: swc1        $f4, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f4.u32l;
    // 0x8000E35C: lw          $t0, 0x94($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X94);
L_8000E360:
    // 0x8000E360: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x8000E364: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000E368: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8000E36C: b           L_8000E064
    // 0x8000E370: sb          $t3, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r11;
        goto L_8000E064;
    // 0x8000E370: sb          $t3, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r11;
L_8000E374:
    // 0x8000E374: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000E378: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000E37C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000E380: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000E384: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000E388: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E38C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000E390: jr          $ra
    // 0x8000E394: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000E394: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8053363C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053363C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80533640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80533644: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80533648: jal         0x800692D4
    // 0x8053364C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x8053364C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80533650: jal         0x80532CFC
    // 0x80533654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532CFC(rdram, ctx);
        goto after_1;
    // 0x80533654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80533658: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8053365C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80533660: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80533664: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80533668: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8053366C: nop

    // 0x80533670: bc1t        L_80533688
    if (c1cs) {
        // 0x80533674: nop
    
            goto L_80533688;
    }
    // 0x80533674: nop

    // 0x80533678: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8053367C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80533680: b           L_80533690
    // 0x80533684: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_80533690;
    // 0x80533684: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_80533688:
    // 0x80533688: jal         0x805333CC
    // 0x8053368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805333CC(rdram, ctx);
        goto after_2;
    // 0x8053368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80533690:
    // 0x80533690: jal         0x80533170
    // 0x80533694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533170(rdram, ctx);
        goto after_3;
    // 0x80533694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80533698: jal         0x80532B50
    // 0x8053369C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532B50(rdram, ctx);
        goto after_4;
    // 0x8053369C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805336A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805336A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805336A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805336AC: jr          $ra
    // 0x805336B0: nop

    return;
    // 0x805336B0: nop

;}
RECOMP_FUNC void func_8007FD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD30: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8007FD34: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x8007FD38: addiu       $t0, $a1, 0x3C
    ctx->r8 = ADD32(ctx->r5, 0X3C);
L_8007FD3C:
    // 0x8007FD3C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8007FD40: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8007FD44: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8007FD48: sw          $t7, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r15;
    // 0x8007FD4C: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x8007FD50: sw          $t6, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r14;
    // 0x8007FD54: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x8007FD58: bne         $t8, $t0, L_8007FD3C
    if (ctx->r24 != ctx->r8) {
        // 0x8007FD5C: sw          $t7, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r15;
            goto L_8007FD3C;
    }
    // 0x8007FD5C: sw          $t7, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r15;
    // 0x8007FD60: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8007FD64: jr          $ra
    // 0x8007FD68: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    return;
    // 0x8007FD68: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
;}
RECOMP_FUNC void func_80046790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046794: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80046798: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004679C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800467A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800467A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800467A8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800467AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800467B0: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x800467B4: blez        $v0, L_800467E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800467B8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800467E8;
    }
    // 0x800467B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800467BC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800467C0:
    // 0x800467C0: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x800467C4: bnel        $s2, $t6, L_800467DC
    if (ctx->r18 != ctx->r14) {
        // 0x800467C8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800467DC;
    }
    goto skip_0;
    // 0x800467C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800467CC: jal         0x800462E0
    // 0x800467D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800462E0(rdram, ctx);
        goto after_0;
    // 0x800467D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x800467D4: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x800467D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800467DC:
    // 0x800467DC: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800467E0: bne         $at, $zero, L_800467C0
    if (ctx->r1 != 0) {
        // 0x800467E4: addiu       $s0, $s0, 0x280
        ctx->r16 = ADD32(ctx->r16, 0X280);
            goto L_800467C0;
    }
    // 0x800467E4: addiu       $s0, $s0, 0x280
    ctx->r16 = ADD32(ctx->r16, 0X280);
L_800467E8:
    // 0x800467E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800467EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800467F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800467F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800467F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800467FC: jr          $ra
    // 0x80046800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80046800: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806EF7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF7A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EF7A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF7A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EF7AC: jal         0x8004700C
    // 0x806EF7B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EF7B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EF7B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EF7B8: jal         0x806EC16C
    // 0x806EF7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC16C(rdram, ctx);
        goto after_1;
    // 0x806EF7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EF7C0: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EF7C4: jal         0x800577D8
    // 0x806EF7C8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_2;
    // 0x806EF7C8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x806EF7CC: jal         0x806EF504
    // 0x806EF7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_3;
    // 0x806EF7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EF7D4: jal         0x806EF584
    // 0x806EF7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_4;
    // 0x806EF7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EF7DC: jal         0x806EF638
    // 0x806EF7E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF638(rdram, ctx);
        goto after_5;
    // 0x806EF7E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EF7E4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806EF7E8: beql        $v0, $zero, L_806EF86C
    if (ctx->r2 == 0) {
        // 0x806EF7EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EF86C;
    }
    goto skip_0;
    // 0x806EF7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EF7F0: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806EF7F4: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EF7F8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806EF7FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806EF800: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EF804: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x806EF808: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806EF80C: nop

    // 0x806EF810: bc1fl       L_806EF828
    if (!c1cs) {
        // 0x806EF814: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_806EF828;
    }
    goto skip_1;
    // 0x806EF814: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x806EF818: lw          $t7, 0x12C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X12C);
    // 0x806EF81C: beq         $t7, $zero, L_806EF84C
    if (ctx->r15 == 0) {
        // 0x806EF820: nop
    
            goto L_806EF84C;
    }
    // 0x806EF820: nop

    // 0x806EF824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_806EF828:
    // 0x806EF828: nop

    // 0x806EF82C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806EF830: nop

    // 0x806EF834: bc1fl       L_806EF86C
    if (!c1cs) {
        // 0x806EF838: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EF86C;
    }
    goto skip_2;
    // 0x806EF838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806EF83C: lw          $t8, 0x12C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X12C);
    // 0x806EF840: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EF844: bnel        $t8, $at, L_806EF86C
    if (ctx->r24 != ctx->r1) {
        // 0x806EF848: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EF86C;
    }
    goto skip_3;
    // 0x806EF848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_806EF84C:
    // 0x806EF84C: jal         0x806EF560
    // 0x806EF850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF560(rdram, ctx);
        goto after_6;
    // 0x806EF850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806EF854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF85C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EF860: jal         0x806F0348
    // 0x806EF864: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_7;
    // 0x806EF864: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EF868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EF86C:
    // 0x806EF86C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EF870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EF874: jr          $ra
    // 0x806EF878: nop

    return;
    // 0x806EF878: nop

;}
RECOMP_FUNC void func_806E8508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E850C: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x806E8510: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x806E8514: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x806E8518: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x806E851C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x806E8520: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x806E8524: lw          $a3, 0x16C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X16C);
    // 0x806E8528: lui         $s3, 0x806F
    ctx->r19 = S32(RELOC_HI16(667, 0X1678) << 16);
    // 0x806E852C: lw          $t6, 0x450($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X450);
    // 0x806E8530: lbu         $t8, 0xD($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XD);
    // 0x806E8534: addiu       $s3, $s3, -0x66D8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(667, 0X1678));
    // 0x806E8538: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E853C: sb          $t8, 0xC($s3)
    MEM_B(0XC, ctx->r19) = ctx->r24;
    // 0x806E8540: lbu         $t9, 0x11($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X11);
    // 0x806E8544: lui         $s4, 0x806F
    ctx->r20 = S32(RELOC_HI16(667, 0X1688) << 16);
    // 0x806E8548: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806E854C: addiu       $s4, $s4, -0x66C8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(667, 0X1688));
    // 0x806E8550: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x806E8554: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806E8558: sb          $t9, 0xC($s4)
    MEM_B(0XC, ctx->r20) = ctx->r25;
    // 0x806E855C: lbu         $t6, 0xE($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XE);
    // 0x806E8560: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x806E8564: addu        $t5, $a2, $t7
    ctx->r13 = ADD32(ctx->r6, ctx->r15);
    // 0x806E8568: sb          $t6, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r14;
    // 0x806E856C: lbu         $t7, 0x12($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X12);
    // 0x806E8570: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x806E8574: addiu       $s0, $t5, 0x228
    ctx->r16 = ADD32(ctx->r13, 0X228);
    // 0x806E8578: sb          $t7, 0xD($s4)
    MEM_B(0XD, ctx->r20) = ctx->r15;
    // 0x806E857C: lbu         $t8, 0xF($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XF);
    // 0x806E8580: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x806E8584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E8588: sb          $t8, 0xE($s3)
    MEM_B(0XE, ctx->r19) = ctx->r24;
    // 0x806E858C: lbu         $t9, 0x13($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X13);
    // 0x806E8590: addiu       $v1, $zero, 0x2D
    ctx->r3 = ADD32(0, 0X2D);
    // 0x806E8594: addiu       $a3, $a3, 0xD
    ctx->r7 = ADD32(ctx->r7, 0XD);
    // 0x806E8598: sb          $t9, 0xE($s4)
    MEM_B(0XE, ctx->r20) = ctx->r25;
    // 0x806E859C: lbu         $t6, 0x3($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3);
    // 0x806E85A0: sb          $t6, 0xF($s3)
    MEM_B(0XF, ctx->r19) = ctx->r14;
    // 0x806E85A4: lbu         $t7, 0x3($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3);
    // 0x806E85A8: sb          $t7, 0xF($s4)
    MEM_B(0XF, ctx->r20) = ctx->r15;
    // 0x806E85AC: lw          $t3, -0x260C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X260C);
    // 0x806E85B0: lw          $v0, 0xC($t3)
    ctx->r2 = MEM_W(ctx->r11, 0XC);
    // 0x806E85B4: addiu       $v0, $v0, -0x5C0
    ctx->r2 = ADD32(ctx->r2, -0X5C0);
    // 0x806E85B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x806E85BC: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    // 0x806E85C0: sw          $v0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r2;
L_806E85C4:
    // 0x806E85C4: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x806E85C8: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x806E85CC: sltiu       $at, $t4, 0xB8
    ctx->r1 = ctx->r12 < 0XB8 ? 1 : 0;
    // 0x806E85D0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x806E85D4: lw          $t8, 0x4($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4);
    // 0x806E85D8: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x806E85DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E85E0: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x806E85E4: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x806E85E8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x806E85EC: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x806E85F0: sw          $t9, -0x18($s1)
    MEM_W(-0X18, ctx->r17) = ctx->r25;
    // 0x806E85F4: lw          $t8, 0xC($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XC);
    // 0x806E85F8: sw          $t8, -0x14($s1)
    MEM_W(-0X14, ctx->r17) = ctx->r24;
    // 0x806E85FC: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x806E8600: sw          $t7, -0x20($s2)
    MEM_W(-0X20, ctx->r18) = ctx->r15;
    // 0x806E8604: lw          $t6, 0x4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X4);
    // 0x806E8608: sw          $t6, -0x1C($s2)
    MEM_W(-0X1C, ctx->r18) = ctx->r14;
    // 0x806E860C: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
    // 0x806E8610: sw          $t7, -0x18($s2)
    MEM_W(-0X18, ctx->r18) = ctx->r15;
    // 0x806E8614: lw          $t6, 0xC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0XC);
    // 0x806E8618: sw          $t6, -0x14($s2)
    MEM_W(-0X14, ctx->r18) = ctx->r14;
    // 0x806E861C: lh          $t8, -0x4($t5)
    ctx->r24 = MEM_H(ctx->r13, -0X4);
    // 0x806E8620: sh          $t8, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r24;
    // 0x806E8624: lh          $t9, -0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X4);
    // 0x806E8628: sh          $t9, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r25;
    // 0x806E862C: lh          $t6, -0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, -0X2);
    // 0x806E8630: sh          $t6, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r14;
    // 0x806E8634: lh          $t7, -0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X2);
    // 0x806E8638: bne         $at, $zero, L_806E85C4
    if (ctx->r1 != 0) {
        // 0x806E863C: sh          $t7, -0xE($s1)
        MEM_H(-0XE, ctx->r17) = ctx->r15;
            goto L_806E85C4;
    }
    // 0x806E863C: sh          $t7, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r15;
    // 0x806E8640: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8644: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x806E8648: ori         $t3, $t3, 0x103F
    ctx->r11 = ctx->r11 | 0X103F;
    // 0x806E864C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806E8650: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806E8654: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x806E8658: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806E865C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8660: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x806E8664: addiu       $t5, $zero, 0x206
    ctx->r13 = ADD32(0, 0X206);
    // 0x806E8668: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806E866C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806E8670: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806E8674: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E8678: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E867C: addiu       $s0, $zero, 0x604
    ctx->r16 = ADD32(0, 0X604);
    // 0x806E8680: addiu       $t2, $v0, 0x20
    ctx->r10 = ADD32(ctx->r2, 0X20);
    // 0x806E8684: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806E8688: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806E868C: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806E8690: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_806E8694:
    // 0x806E8694: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8698: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806E869C: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806E86A0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806E86A4: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806E86A8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806E86AC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E86B0: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806E86B4: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806E86B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806E86BC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806E86C0: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E86C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E86C8: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806E86CC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806E86D0: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806E86D4: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E86D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E86DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806E86E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806E86E4: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806E86E8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806E86EC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E86F0: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806E86F4: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806E86F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806E86FC: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806E8700: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E8704: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8708: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806E870C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806E8710: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806E8714: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E8718: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E871C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806E8720: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806E8724: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806E8728: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806E872C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8730: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806E8734: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806E8738: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806E873C: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806E8740: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E8744: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8748: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x806E874C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806E8750: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806E8754: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E8758: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E875C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x806E8760: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806E8764: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x806E8768: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x806E876C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8770: addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // 0x806E8774: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x806E8778: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806E877C: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x806E8780: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E8784: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806E8788: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806E878C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806E8790: sw          $s0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r16;
    // 0x806E8794: bne         $a1, $v1, L_806E8694
    if (ctx->r5 != ctx->r3) {
        // 0x806E8798: sw          $t4, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r12;
            goto L_806E8694;
    }
    // 0x806E8798: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x806E879C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x806E87A0: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x806E87A4: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x806E87A8: lw          $s3, 0x10($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X10);
    // 0x806E87AC: lw          $s4, 0x14($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X14);
    // 0x806E87B0: jr          $ra
    // 0x806E87B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806E87B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804082B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804082B0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x804082B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804082B8: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x804082BC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804082C0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804082C4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804082C8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804082CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804082D0: jal         0x8004700C
    // 0x804082D4: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804082D4: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    after_0:
    // 0x804082D8: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x804082DC: lui         $v1, 0x8041
    ctx->r3 = S32(RELOC_HI16(11, 0X2D00) << 16);
    // 0x804082E0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x804082E4: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x804082E8: addiu       $v1, $v1, -0x5930
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(11, 0X2D00));
    // 0x804082EC: beq         $v0, $zero, L_804082FC
    if (ctx->r2 == 0) {
        // 0x804082F0: lw          $t0, 0x4($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X4);
            goto L_804082FC;
    }
    // 0x804082F0: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x804082F4: b           L_804084A4
    // 0x804082F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804084A4;
    // 0x804082F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804082FC:
    // 0x804082FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80408300: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80408304: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x80408308: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x8040830C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80408310: jal         0x80047AB8
    // 0x80408314: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80408314: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80408318: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8040831C: jal         0x80047AB8
    // 0x80408320: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x80408320: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    after_2:
    // 0x80408324: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80408328: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8040832C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80408330: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80408334: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80408338: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8040833C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80408340: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80408344: bc1fl       L_80408358
    if (!c1cs) {
        // 0x80408348: lw          $a0, 0x24($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X24);
            goto L_80408358;
    }
    goto skip_0;
    // 0x80408348: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    skip_0:
    // 0x8040834C: b           L_804084A4
    // 0x80408350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804084A4;
    // 0x80408350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80408354: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
L_80408358:
    // 0x80408358: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8040835C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80408360: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80408364: blez        $a0, L_80408418
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80408368: sub.s       $f22, $f16, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f24.fl;
            goto L_80408418;
    }
    // 0x80408368: sub.s       $f22, $f16, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x8040836C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80408370: lwc1        $f26, 0x4($t0)
    ctx->f26.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80408374: neg.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f30.fl = -ctx->f24.fl;
L_80408378:
    // 0x80408378: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8040837C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80408380: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80408384: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80408388: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x8040838C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80408390: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80408394: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80408398: sub.s       $f20, $f22, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x8040839C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804083A0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804083A4: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x804083A8: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x804083AC: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x804083B0: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x804083B4: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x804083B8: div.s       $f10, $f2, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f30.fl);
    // 0x804083BC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804083C0: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x804083C4: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x804083C8: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x804083CC: div.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f24.fl);
    // 0x804083D0: c.lt.s      $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f14.fl < ctx->f28.fl;
    // 0x804083D4: nop

    // 0x804083D8: bc1fl       L_804083E8
    if (!c1cs) {
        // 0x804083DC: lwc1        $f10, 0x90($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
            goto L_804083E8;
    }
    goto skip_1;
    // 0x804083DC: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    skip_1:
    // 0x804083E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804083E4: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
L_804083E8:
    // 0x804083E8: sub.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x804083EC: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804083F0: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x804083F4: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x804083F8: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x804083FC: c.lt.s      $f8, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f8.fl < ctx->f28.fl;
    // 0x80408400: nop

    // 0x80408404: bc1f        L_80408410
    if (!c1cs) {
        // 0x80408408: nop
    
            goto L_80408410;
    }
    // 0x80408408: nop

    // 0x8040840C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80408410:
    // 0x80408410: bne         $at, $zero, L_80408378
    if (ctx->r1 != 0) {
        // 0x80408414: mov.s       $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
            goto L_80408378;
    }
    // 0x80408414: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_80408418:
    // 0x80408418: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8040841C: beql        $a2, $zero, L_804084A4
    if (ctx->r6 == 0) {
        // 0x80408420: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_804084A4;
    }
    goto skip_2;
    // 0x80408420: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_2:
    // 0x80408424: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80408428: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8040842C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80408430: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80408434: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80408438: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8040843C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80408440: neg.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = -ctx->f24.fl;
    // 0x80408444: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80408448: div.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8040844C: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80408450: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80408454: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80408458: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8040845C: div.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80408460: c.lt.s      $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f14.fl < ctx->f28.fl;
    // 0x80408464: nop

    // 0x80408468: bc1fl       L_80408478
    if (!c1cs) {
        // 0x8040846C: lwc1        $f8, 0x90($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
            goto L_80408478;
    }
    goto skip_3;
    // 0x8040846C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    skip_3:
    // 0x80408470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80408474: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
L_80408478:
    // 0x80408478: sub.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x8040847C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80408480: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80408484: add.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80408488: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8040848C: c.lt.s      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.fl < ctx->f28.fl;
    // 0x80408490: nop

    // 0x80408494: bc1fl       L_804084A4
    if (!c1cs) {
        // 0x80408498: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_804084A4;
    }
    goto skip_4;
    // 0x80408498: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_4:
    // 0x8040849C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804084A0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_804084A4:
    // 0x804084A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x804084A8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804084AC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804084B0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804084B4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804084B8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804084BC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x804084C0: jr          $ra
    // 0x804084C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x804084C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_807888C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807888C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x807888C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807888CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x807888D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807888D4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807888D8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x807888DC: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x807888E0: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x807888E4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(787, 0X2F50) << 16);
    // 0x807888E8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x807888EC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x807888F0: bc1t        L_807889B4
    if (c1cs) {
        // 0x807888F4: swc1        $f6, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
            goto L_807889B4;
    }
    // 0x807888F4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x807888F8: lwc1        $f12, -0x6670($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(787, 0X2F50));
    // 0x807888FC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80788900: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80788904: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80788908: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8078890C: nop

    // 0x80788910: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80788914: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80788918: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8078891C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80788920: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80788924: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80788928: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8078892C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80788930: nop

    // 0x80788934: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80788938: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8078893C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80788940: nop

    // 0x80788944: bc1f        L_807889B4
    if (!c1cs) {
        // 0x80788948: nop
    
            goto L_807889B4;
    }
    // 0x80788948: nop

    // 0x8078894C: beq         $v1, $at, L_80788968
    if (ctx->r3 == ctx->r1) {
        // 0x80788950: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80788968;
    }
    // 0x80788950: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80788954: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x80788958: beq         $v1, $at, L_8078898C
    if (ctx->r3 == ctx->r1) {
        // 0x8078895C: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_8078898C;
    }
    // 0x8078895C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80788960: b           L_807889B0
    // 0x80788964: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
        goto L_807889B0;
    // 0x80788964: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
L_80788968:
    // 0x80788968: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x8078896C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80788970: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80788974: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80788978: jalr        $t9
    // 0x8078897C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8078897C: nop

    after_0:
    // 0x80788980: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80788984: b           L_807889AC
    // 0x80788988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_807889AC;
    // 0x80788988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8078898C:
    // 0x8078898C: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x80788990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80788994: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80788998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078899C: jalr        $t9
    // 0x807889A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x807889A0: nop

    after_1:
    // 0x807889A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x807889A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_807889AC:
    // 0x807889AC: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
L_807889B0:
    // 0x807889B0: swc1        $f14, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f14.u32l;
L_807889B4:
    // 0x807889B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807889B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807889BC: jr          $ra
    // 0x807889C0: nop

    return;
    // 0x807889C0: nop

;}
RECOMP_FUNC void func_805A7B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7B00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A7B04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7B08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A7B0C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A7B10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7B14: jal         0x805A7440
    // 0x805A7B18: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805A7440(rdram, ctx);
        goto after_0;
    // 0x805A7B18: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A7B1C: jal         0x800692D4
    // 0x805A7B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800692D4(rdram, ctx);
        goto after_1;
    // 0x805A7B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A7B24: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805A7B28: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x805A7B2C: addiu       $a2, $zero, -0x28
    ctx->r6 = ADD32(0, -0X28);
    // 0x805A7B30: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x805A7B34: beq         $a0, $zero, L_805A7B44
    if (ctx->r4 == 0) {
        // 0x805A7B38: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_805A7B44;
    }
    // 0x805A7B38: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x805A7B3C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x805A7B40: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_805A7B44:
    // 0x805A7B44: bnel        $a0, $zero, L_805A7B88
    if (ctx->r4 != 0) {
        // 0x805A7B48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A7B88;
    }
    goto skip_0;
    // 0x805A7B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x805A7B4C: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x805A7B50: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(426, 0X16D8) << 16);
    // 0x805A7B54: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x805A7B58: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x805A7B5C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805A7B60: lh          $t9, -0x75D8($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(426, 0X16D8));
    // 0x805A7B64: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x805A7B68: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x805A7B6C: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x805A7B70: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805A7B74: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x805A7B78: bne         $at, $zero, L_805A7B84
    if (ctx->r1 != 0) {
        // 0x805A7B7C: sw          $t1, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r9;
            goto L_805A7B84;
    }
    // 0x805A7B7C: sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
    // 0x805A7B80: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_805A7B84:
    // 0x805A7B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805A7B88:
    // 0x805A7B88: jal         0x80047590
    // 0x805A7B8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80047590(rdram, ctx);
        goto after_2;
    // 0x805A7B8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x805A7B90: beq         $v0, $zero, L_805A7BA8
    if (ctx->r2 == 0) {
        // 0x805A7B94: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_805A7BA8;
    }
    // 0x805A7B94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A7B98: jal         0x80044658
    // 0x805A7B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_3;
    // 0x805A7B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A7BA0: b           L_805A7BC8
    // 0x805A7BA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A7BC8;
    // 0x805A7BA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7BA8:
    // 0x805A7BA8: jal         0x80048F84
    // 0x805A7BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805A7BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x805A7BB0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A7BB4: jal         0x80048F84
    // 0x805A7BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x805A7BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805A7BBC: jal         0x805A7460
    // 0x805A7BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7460(rdram, ctx);
        goto after_6;
    // 0x805A7BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805A7BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7BC8:
    // 0x805A7BC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A7BCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A7BD0: jr          $ra
    // 0x805A7BD4: nop

    return;
    // 0x805A7BD4: nop

;}
RECOMP_FUNC void func_80431228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80431228: jr          $ra
    // 0x8043122C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8043122C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807419D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807419D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807419D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807419D8: lh          $t6, 0x13C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X13C);
    // 0x807419DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807419E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807419E4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x807419E8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x807419EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807419F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807419F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807419F8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807419FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741A00: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80741A04: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80741A08: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80741A0C: lwc1        $f0, -0x88($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, -0X88);
    // 0x80741A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80741A14: jal         0x80048F84
    // 0x80741A18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80741A18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80741A1C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80741A20: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80741A24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80741A28: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80741A2C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80741A30: nop

    // 0x80741A34: bc1fl       L_80741A50
    if (!c1cs) {
        // 0x80741A38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80741A50;
    }
    goto skip_0;
    // 0x80741A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80741A3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80741A40: nop

    // 0x80741A44: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80741A48: swc1        $f0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f0.u32l;
    // 0x80741A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80741A50:
    // 0x80741A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80741A54: jr          $ra
    // 0x80741A58: nop

    return;
    // 0x80741A58: nop

;}
RECOMP_FUNC void func_80444D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444D5C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80444D60: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80444D64: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80444D68: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80444D6C: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x80444D70: mtc1        $a3, $f28
    ctx->f28.u32l = ctx->r7;
    // 0x80444D74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80444D78: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80444D7C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80444D80: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80444D84: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80444D88: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80444D8C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80444D90: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80444D94: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80444D98: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80444D9C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80444DA0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80444DA4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80444DA8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80444DAC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80444DB0: jal         0x80047090
    // 0x80444DB4: addiu       $a0, $zero, 0x40F3
    ctx->r4 = ADD32(0, 0X40F3);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80444DB4: addiu       $a0, $zero, 0x40F3
    ctx->r4 = ADD32(0, 0X40F3);
    after_0:
    // 0x80444DB8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444DBC: beq         $v0, $at, L_80444F04
    if (ctx->r2 == ctx->r1) {
        // 0x80444DC0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444F04;
    }
    // 0x80444DC0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80444DC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80444DC8: lui         $at, 0x40F3
    ctx->r1 = S32(0X40F3 << 16);
    // 0x80444DCC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444DD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80444DD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80444DD8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80444DDC: jal         0x8004613C
    // 0x80444DE0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444DE0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x80444DE4: beq         $v0, $zero, L_80444F04
    if (ctx->r2 == 0) {
        // 0x80444DE8: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_80444F04;
    }
    // 0x80444DE8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80444DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80444DF0: jal         0x80047F9C
    // 0x80444DF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444DF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80444DF8: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80444DFC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80444E00: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x80444E04: sb          $s6, 0x17C($s5)
    MEM_B(0X17C, ctx->r21) = ctx->r22;
    // 0x80444E08: lw          $t6, 0x478($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X478);
    // 0x80444E0C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FE8) << 16);
    // 0x80444E10: sll         $t9, $s7, 4
    ctx->r25 = S32(ctx->r23 << 4);
    // 0x80444E14: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80444E18: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X130B8) << 16);
    // 0x80444E1C: addiu       $t0, $t0, 0x7498
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(98, 0X130B8));
    // 0x80444E20: swc1        $f0, 0x84($s5)
    MEM_W(0X84, ctx->r21) = ctx->f0.u32l;
    // 0x80444E24: swc1        $f0, 0x3C($s5)
    MEM_W(0X3C, ctx->r21) = ctx->f0.u32l;
    // 0x80444E28: lw          $t7, 0x478($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X478);
    // 0x80444E2C: lui         $s2, 0x8045
    ctx->r18 = S32(RELOC_HI16(98, 0X13134) << 16);
    // 0x80444E30: addiu       $s2, $s2, 0x7514
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(98, 0X13134));
    // 0x80444E34: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80444E38: addu        $s4, $t9, $t0
    ctx->r20 = ADD32(ctx->r25, ctx->r8);
    // 0x80444E3C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80444E40: swc1        $f0, 0x88($s5)
    MEM_W(0X88, ctx->r21) = ctx->f0.u32l;
    // 0x80444E44: swc1        $f0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->f0.u32l;
    // 0x80444E48: lw          $t8, 0x478($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X478);
    // 0x80444E4C: lwc1        $f6, -0x7C38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FE8));
    // 0x80444E50: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FEC) << 16);
    // 0x80444E54: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80444E58: sb          $zero, 0x165($s5)
    MEM_B(0X165, ctx->r21) = 0;
    // 0x80444E5C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80444E60: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80444E64: addiu       $fp, $zero, 0x10
    ctx->r30 = ADD32(0, 0X10);
    // 0x80444E68: swc1        $f0, 0x8C($s5)
    MEM_W(0X8C, ctx->r21) = ctx->f0.u32l;
    // 0x80444E6C: swc1        $f0, 0x44($s5)
    MEM_W(0X44, ctx->r21) = ctx->f0.u32l;
    // 0x80444E70: lwc1        $f20, 0x80($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80444E74: lwc1        $f22, 0x84($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80444E78: lwc1        $f24, -0x7C34($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FEC));
L_80444E7C:
    // 0x80444E7C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80444E80: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80444E84: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80444E88: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x80444E8C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80444E90: jal         0x8005D078
    // 0x80444E94: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_8005D078(rdram, ctx);
        goto after_3;
    // 0x80444E94: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x80444E98: beq         $v0, $zero, L_80444EF4
    if (ctx->r2 == 0) {
        // 0x80444E9C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80444EF4;
    }
    // 0x80444E9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80444EA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80444EA4: jal         0x80047F9C
    // 0x80444EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80444EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80444EAC: sb          $s6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r22;
    // 0x80444EB0: lw          $t1, 0x478($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X478);
    // 0x80444EB4: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x80444EB8: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80444EBC: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x80444EC0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80444EC4: lw          $t2, 0x478($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X478);
    // 0x80444EC8: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80444ECC: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x80444ED0: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80444ED4: lw          $t3, 0x478($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X478);
    // 0x80444ED8: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80444EDC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80444EE0: sb          $s7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r23;
    // 0x80444EE4: add.s       $f0, $f8, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80444EE8: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80444EEC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80444EF0: sb          $zero, 0x10($t4)
    MEM_B(0X10, ctx->r12) = 0;
L_80444EF4:
    // 0x80444EF4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80444EF8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80444EFC: bne         $s3, $fp, L_80444E7C
    if (ctx->r19 != ctx->r30) {
        // 0x80444F00: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80444E7C;
    }
    // 0x80444F00: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80444F04:
    // 0x80444F04: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80444F08: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80444F0C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80444F10: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80444F14: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80444F18: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80444F1C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80444F20: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80444F24: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80444F28: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80444F2C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80444F30: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80444F34: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80444F38: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80444F3C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80444F40: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80444F44: jr          $ra
    // 0x80444F48: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80444F48: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_807048D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807048D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807048D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807048D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807048DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807048E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807048E4: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x807048E8: beq         $v1, $zero, L_807048F8
    if (ctx->r3 == 0) {
        // 0x807048EC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_807048F8;
    }
    // 0x807048EC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x807048F0: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x807048F4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_807048F8:
    // 0x807048F8: bnel        $v1, $zero, L_807049C4
    if (ctx->r3 != 0) {
        // 0x807048FC: addiu       $a2, $s0, 0xC4
        ctx->r6 = ADD32(ctx->r16, 0XC4);
            goto L_807049C4;
    }
    goto skip_0;
    // 0x807048FC: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x80704900: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80704904: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(709, 0X35B8) << 16);
    // 0x80704908: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(709, 0X35F0) << 16);
    // 0x8070490C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80704910: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80704914: lw          $t7, 0x6A28($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(709, 0X35B8));
    // 0x80704918: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8070491C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80704920: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x80704924: lw          $t8, 0x6A60($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(709, 0X35F0));
    // 0x80704928: slti        $at, $t9, 0xE
    ctx->r1 = SIGNED(ctx->r25) < 0XE ? 1 : 0;
    // 0x8070492C: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x80704930: bne         $at, $zero, L_807049C0
    if (ctx->r1 != 0) {
        // 0x80704934: sw          $t8, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r24;
            goto L_807049C0;
    }
    // 0x80704934: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x80704938: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8070493C: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x80704940: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3728) << 16);
    // 0x80704944: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x80704948: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8070494C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80704950: lwc1        $f4, 0x6B98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3728));
    // 0x80704954: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80704958: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8070495C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80704960: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80704964: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80704968: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8070496C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80704970: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x80704974: swc1        $f10, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f10.u32l;
    // 0x80704978: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8070497C: jal         0x80067BBC
    // 0x80704980: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80704980: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_0:
    // 0x80704984: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80704988: jal         0x80067818
    // 0x8070498C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8070498C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80704990: jal         0x807041F8
    // 0x80704994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807041F8(rdram, ctx);
        goto after_2;
    // 0x80704994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80704998: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8070499C: jal         0x80067BBC
    // 0x807049A0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x807049A0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x807049A4: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x807049A8: jal         0x80067818
    // 0x807049AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x807049AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x807049B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807049B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807049B8: jal         0x80705A5C
    // 0x807049BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80705A5C(rdram, ctx);
        goto after_5;
    // 0x807049BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_807049C0:
    // 0x807049C0: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
L_807049C4:
    // 0x807049C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807049C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x807049CC: jal         0x80048F84
    // 0x807049D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x807049D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x807049D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807049D8: jal         0x80048F84
    // 0x807049DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x807049DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x807049E0: jal         0x8070384C
    // 0x807049E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_8;
    // 0x807049E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x807049E8: jal         0x80703F10
    // 0x807049EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_9;
    // 0x807049EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x807049F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807049F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807049F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807049FC: jr          $ra
    // 0x80704A00: nop

    return;
    // 0x80704A00: nop

;}
RECOMP_FUNC void func_807B0D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0D14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B0D18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B0D1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B0D20: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807B0D24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B0D28: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807B0D2C: jal         0x80045A34
    // 0x807B0D30: addiu       $a1, $zero, 0x3CC
    ctx->r5 = ADD32(0, 0X3CC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807B0D30: addiu       $a1, $zero, 0x3CC
    ctx->r5 = ADD32(0, 0X3CC);
    after_0:
    // 0x807B0D34: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x807B0D38: jal         0x80064D1C
    // 0x807B0D3C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x807B0D3C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_1:
    // 0x807B0D40: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B0D44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807B0D48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B0D4C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x807B0D50: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B0D54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B0D58: sw          $t7, 0x68($t8)
    MEM_W(0X68, ctx->r24) = ctx->r15;
    // 0x807B0D5C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B0D60: swc1        $f4, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->f4.u32l;
    // 0x807B0D64: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B0D68: jal         0x807AFEEC
    // 0x807B0D6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_807AFEEC(rdram, ctx);
        goto after_2;
    // 0x807B0D6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x807B0D70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807B0D74: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x807B0D78: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x807B0D7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x807B0D80: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x807B0D84: jal         0x807B0170
    // 0x807B0D88: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    func_807B0170(rdram, ctx);
        goto after_3;
    // 0x807B0D88: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    after_3:
    // 0x807B0D8C: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x807B0D90: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(871, 0XBB4) << 16);
    // 0x807B0D94: addiu       $t2, $t2, 0x704
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(871, 0XBB4));
    // 0x807B0D98: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
    // 0x807B0D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B0DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B0DA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B0DA8: jr          $ra
    // 0x807B0DAC: nop

    return;
    // 0x807B0DAC: nop

;}
RECOMP_FUNC void func_804C5758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5758: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804C575C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x804C5760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C576C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x804C5770: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804C5774: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x804C5778: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x804C577C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C5780: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    // 0x804C5784: jalr        $t9
    // 0x804C5788: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804C5788: nop

    after_0:
    // 0x804C578C: jal         0x80044658
    // 0x804C5790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x804C5790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C5794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5798: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804C579C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C57A0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x804C57A4: jr          $ra
    // 0x804C57A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804C57A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8066DDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DDC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066DDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066DDCC: jal         0x8066DB84
    // 0x8066DDD0: nop

    func_8066DB84(rdram, ctx);
        goto after_0;
    // 0x8066DDD0: nop

    after_0:
    // 0x8066DDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066DDD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066DDDC: jr          $ra
    // 0x8066DDE0: nop

    return;
    // 0x8066DDE0: nop

;}
RECOMP_FUNC void func_800610A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800610A0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800610A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800610A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800610AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800610B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800610B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800610B8: lh          $s0, 0x184($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X184);
    // 0x800610BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800610C0: addiu       $s1, $a0, 0x188
    ctx->r17 = ADD32(ctx->r4, 0X188);
    // 0x800610C4: beq         $s0, $zero, L_80061110
    if (ctx->r16 == 0) {
        // 0x800610C8: addiu       $s3, $sp, 0x30
        ctx->r19 = ADD32(ctx->r29, 0X30);
            goto L_80061110;
    }
    // 0x800610C8: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
L_800610CC:
    // 0x800610CC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800610D0: beq         $v0, $zero, L_80061108
    if (ctx->r2 == 0) {
        // 0x800610D4: nop
    
            goto L_80061108;
    }
    // 0x800610D4: nop

    // 0x800610D8: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x800610DC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800610E0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800610E4: beq         $v1, $zero, L_80061108
    if (ctx->r3 == 0) {
        // 0x800610E8: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_80061108;
    }
    // 0x800610E8: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800610EC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800610F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800610F4: bne         $s2, $t6, L_80061108
    if (ctx->r18 != ctx->r14) {
        // 0x800610F8: nop
    
            goto L_80061108;
    }
    // 0x800610F8: nop

    // 0x800610FC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80061100: jal         0x8006106C
    // 0x80061104: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    func_8006106C(rdram, ctx);
        goto after_0;
    // 0x80061104: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_0:
L_80061108:
    // 0x80061108: bne         $s0, $zero, L_800610CC
    if (ctx->r16 != 0) {
        // 0x8006110C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800610CC;
    }
    // 0x8006110C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80061110:
    // 0x80061110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80061114: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80061118: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006111C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80061120: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80061124: jr          $ra
    // 0x80061128: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80061128: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8075F1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8075F1F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8075F1F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8075F1FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075F200: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    // 0x8075F204: jal         0x80067878
    // 0x8075F208: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8075F208: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x8075F20C: jal         0x80045BD8
    // 0x8075F210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8075F210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8075F214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8075F218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8075F21C: jr          $ra
    // 0x8075F220: nop

    return;
    // 0x8075F220: nop

;}
RECOMP_FUNC void func_8002E22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E22C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E234: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E23C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8002E240: lbu         $t6, 0x154($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X154);
    // 0x8002E244: bne         $t6, $zero, L_8002E25C
    if (ctx->r14 != 0) {
        // 0x8002E248: nop
    
            goto L_8002E25C;
    }
    // 0x8002E248: nop

    // 0x8002E24C: jal         0x800345AC
    // 0x8002E250: nop

    func_800345AC(rdram, ctx);
        goto after_0;
    // 0x8002E250: nop

    after_0:
    // 0x8002E254: b           L_8002E268
    // 0x8002E258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E268;
    // 0x8002E258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E25C:
    // 0x8002E25C: jal         0x8002B9E4
    // 0x8002E260: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_1;
    // 0x8002E260: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002E264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E268:
    // 0x8002E268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E26C: jr          $ra
    // 0x8002E270: nop

    return;
    // 0x8002E270: nop

;}
RECOMP_FUNC void func_8058460C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058460C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584610: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584614: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584618: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058461C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584620: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584624: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584628: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058462C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584630: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584634: jr          $ra
    // 0x80584638: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584638: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003444C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003444C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034454: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034458: jal         0x800340F8
    // 0x8003445C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800340F8(rdram, ctx);
        goto after_0;
    // 0x8003445C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034460: beq         $v0, $zero, L_80034470
    if (ctx->r2 == 0) {
        // 0x80034464: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80034470;
    }
    // 0x80034464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80034468: b           L_8003448C
    // 0x8003446C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003448C;
    // 0x8003446C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80034470:
    // 0x80034470: jal         0x800342C0
    // 0x80034474: nop

    func_800342C0(rdram, ctx);
        goto after_1;
    // 0x80034474: nop

    after_1:
    // 0x80034478: beql        $v0, $zero, L_8003448C
    if (ctx->r2 == 0) {
        // 0x8003447C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003448C;
    }
    goto skip_0;
    // 0x8003447C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80034480: b           L_8003448C
    // 0x80034484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003448C;
    // 0x80034484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003448C:
    // 0x8003448C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034494: jr          $ra
    // 0x80034498: nop

    return;
    // 0x80034498: nop

;}
RECOMP_FUNC void func_804BDBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDBAC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804BDBB0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BDBB4: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BDBB8: addiu       $a1, $v1, 0x350
    ctx->r5 = ADD32(ctx->r3, 0X350);
    // 0x804BDBBC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x804BDBC0: lw          $v0, 0x370($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X370);
    // 0x804BDBC4: slti        $at, $t7, 0x16
    ctx->r1 = SIGNED(ctx->r15) < 0X16 ? 1 : 0;
    // 0x804BDBC8: bne         $at, $zero, L_804BDBD4
    if (ctx->r1 != 0) {
        // 0x804BDBCC: nop
    
            goto L_804BDBD4;
    }
    // 0x804BDBCC: nop

    // 0x804BDBD0: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_804BDBD4:
    // 0x804BDBD4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41B4) << 16);
    // 0x804BDBD8: lwc1        $f4, -0x51C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41B4));
    // 0x804BDBDC: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BDBE0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41B8) << 16);
    // 0x804BDBE4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BDBE8: nop

    // 0x804BDBEC: bc1t        L_804BDC68
    if (c1cs) {
        // 0x804BDBF0: nop
    
            goto L_804BDC68;
    }
    // 0x804BDBF0: nop

    // 0x804BDBF4: lwc1        $f6, -0x518($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41B8));
    // 0x804BDBF8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BDBFC: nop

    // 0x804BDC00: bc1t        L_804BDC68
    if (c1cs) {
        // 0x804BDC04: nop
    
            goto L_804BDC68;
    }
    // 0x804BDC04: nop

    // 0x804BDC08: lh          $t8, 0x2E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDC0C: lui         $t0, 0x804C
    ctx->r8 = S32(RELOC_HI16(191, 0X3DA8) << 16);
    // 0x804BDC10: lui         $t4, 0x804C
    ctx->r12 = S32(RELOC_HI16(191, 0X2448) << 16);
    // 0x804BDC14: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804BDC18: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BDC1C: lh          $t0, -0x928($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(191, 0X3DA8));
    // 0x804BDC20: addiu       $t4, $t4, -0x2288
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(191, 0X2448));
    // 0x804BDC24: sh          $t0, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r8;
    // 0x804BDC28: lh          $t1, 0x2E($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDC2C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x804BDC30: sh          $t2, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r10;
    // 0x804BDC34: lh          $t3, 0x2E($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDC38: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x804BDC3C: bne         $at, $zero, L_804BDC58
    if (ctx->r1 != 0) {
        // 0x804BDC40: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_804BDC58;
    }
    // 0x804BDC40: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804BDC44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BDC48: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
    // 0x804BDC4C: sw          $t4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r12;
    // 0x804BDC50: jr          $ra
    // 0x804BDC54: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x804BDC54: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
L_804BDC58:
    // 0x804BDC58: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804BDC5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BDC60: nop

    // 0x804BDC64: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
L_804BDC68:
    // 0x804BDC68: jr          $ra
    // 0x804BDC6C: nop

    return;
    // 0x804BDC6C: nop

;}
RECOMP_FUNC void func_8078FC2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FC2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078FC30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078FC34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078FC38: jal         0x8078FAE8
    // 0x8078FC3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8078FAE8(rdram, ctx);
        goto after_0;
    // 0x8078FC3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8078FC40: beq         $v0, $zero, L_8078FCF0
    if (ctx->r2 == 0) {
        // 0x8078FC44: addiu       $t6, $zero, 0xFF
        ctx->r14 = ADD32(0, 0XFF);
            goto L_8078FCF0;
    }
    // 0x8078FC44: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8078FC48: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8078FC4C: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(814, 0XD70) << 16);
    // 0x8078FC50: sw          $t6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r14;
    // 0x8078FC54: addiu       $t7, $t7, -0x100
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(814, 0XD70));
    // 0x8078FC58: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8078FC5C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8078FC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078FC64: jal         0x8078FD04
    // 0x8078FC68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8078FD04(rdram, ctx);
        goto after_1;
    // 0x8078FC68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8078FC6C: jal         0x8078FB4C
    // 0x8078FC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078FB4C(rdram, ctx);
        goto after_2;
    // 0x8078FC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8078FC74: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8078FC78: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8078FC7C: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8078FC80: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDC4) << 16);
    // 0x8078FC84: lwc1        $f4, -0xAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDC4));
    // 0x8078FC88: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDC8) << 16);
    // 0x8078FC8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078FC90: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x8078FC94: lwc1        $f6, -0xA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDC8));
    // 0x8078FC98: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8078FC9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8078FCA0: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x8078FCA4: jal         0x8078F510
    // 0x8078FCA8: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    func_8078F510(rdram, ctx);
        goto after_3;
    // 0x8078FCA8: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8078FCAC: lw          $t1, 0x168($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X168);
    // 0x8078FCB0: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(814, 0X9E8) << 16);
    // 0x8078FCB4: addiu       $t0, $t0, -0x488
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(814, 0X9E8));
    // 0x8078FCB8: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // 0x8078FCBC: lw          $v0, 0x88($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X88);
    // 0x8078FCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078FCC4: jal         0x8004590C
    // 0x8078FCC8: addiu       $a1, $v0, 0x800
    ctx->r5 = ADD32(ctx->r2, 0X800);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x8078FCC8: addiu       $a1, $v0, 0x800
    ctx->r5 = ADD32(ctx->r2, 0X800);
    after_4:
    // 0x8078FCCC: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8078FCD0: sw          $t2, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r10;
    // 0x8078FCD4: jal         0x80052BA4
    // 0x8078FCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_5;
    // 0x8078FCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8078FCDC: jal         0x8005FDC4
    // 0x8078FCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_6;
    // 0x8078FCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8078FCE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8078FCE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8078FCEC: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
L_8078FCF0:
    // 0x8078FCF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078FCF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078FCF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078FCFC: jr          $ra
    // 0x8078FD00: nop

    return;
    // 0x8078FD00: nop

;}
RECOMP_FUNC void func_806E8818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8818: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E881C: lw          $v1, 0x454($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X454);
    // 0x806E8820: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x806E8824: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x806E8828: sw          $t6, 0x454($v0)
    MEM_W(0X454, ctx->r2) = ctx->r14;
    // 0x806E882C: bne         $at, $zero, L_806E8838
    if (ctx->r1 != 0) {
        // 0x806E8830: sw          $v1, 0x450($v0)
        MEM_W(0X450, ctx->r2) = ctx->r3;
            goto L_806E8838;
    }
    // 0x806E8830: sw          $v1, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->r3;
    // 0x806E8834: sw          $zero, 0x454($v0)
    MEM_W(0X454, ctx->r2) = 0;
L_806E8838:
    // 0x806E8838: jr          $ra
    // 0x806E883C: nop

    return;
    // 0x806E883C: nop

;}
RECOMP_FUNC void func_80040E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040E24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80040E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040E2C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80040E30: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x80040E34: beql        $v0, $zero, L_80040E60
    if (ctx->r2 == 0) {
        // 0x80040E38: lw          $t6, 0x12EC($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X12EC);
            goto L_80040E60;
    }
    goto skip_0;
    // 0x80040E38: lw          $t6, 0x12EC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X12EC);
    skip_0:
    // 0x80040E3C: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80040E40: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80040E44: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80040E48: nop

    // 0x80040E4C: bc1fl       L_80040E60
    if (!c1cs) {
        // 0x80040E50: lw          $t6, 0x12EC($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X12EC);
            goto L_80040E60;
    }
    goto skip_1;
    // 0x80040E50: lw          $t6, 0x12EC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X12EC);
    skip_1:
    // 0x80040E54: b           L_80040F48
    // 0x80040E58: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
        goto L_80040F48;
    // 0x80040E58: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80040E5C: lw          $t6, 0x12EC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X12EC);
L_80040E60:
    // 0x80040E60: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80040E64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80040E68: bnel        $t6, $zero, L_80040F4C
    if (ctx->r14 != 0) {
        // 0x80040E6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040F4C;
    }
    goto skip_2;
    // 0x80040E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80040E70: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80040E74: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80040E78: lh          $a3, -0x7680($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X7680);
    // 0x80040E7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80040E80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80040E84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80040E88: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80040E8C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    // 0x80040E90: jal         0x80053924
    // 0x80040E94: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x80040E94: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80040E98: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80040E9C: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x80040EA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80040EA4: lbu         $t7, 0x22($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X22);
    // 0x80040EA8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80040EAC: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80040EB0: beql        $t7, $zero, L_80040F18
    if (ctx->r15 == 0) {
        // 0x80040EB4: slti        $at, $a3, -0x27
        ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
            goto L_80040F18;
    }
    goto skip_3;
    // 0x80040EB4: slti        $at, $a3, -0x27
    ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
    skip_3:
    // 0x80040EB8: beq         $v0, $zero, L_80040F14
    if (ctx->r2 == 0) {
        // 0x80040EBC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80040F14;
    }
    // 0x80040EBC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80040EC0: beq         $v0, $at, L_80040F14
    if (ctx->r2 == ctx->r1) {
        // 0x80040EC4: lbu         $a2, 0x1C($sp)
        ctx->r6 = MEM_BU(ctx->r29, 0X1C);
            goto L_80040F14;
    }
    // 0x80040EC4: lbu         $a2, 0x1C($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1C);
    // 0x80040EC8: andi        $v0, $a2, 0xF8
    ctx->r2 = ctx->r6 & 0XF8;
    // 0x80040ECC: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80040ED0: beq         $v0, $at, L_80040F14
    if (ctx->r2 == ctx->r1) {
        // 0x80040ED4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80040F14;
    }
    // 0x80040ED4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80040ED8: beql        $v0, $at, L_80040F18
    if (ctx->r2 == ctx->r1) {
        // 0x80040EDC: slti        $at, $a3, -0x27
        ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
            goto L_80040F18;
    }
    goto skip_4;
    // 0x80040EDC: slti        $at, $a3, -0x27
    ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
    skip_4:
    // 0x80040EE0: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x80040EE4: xori        $t9, $v0, 0x28
    ctx->r25 = ctx->r2 ^ 0X28;
    // 0x80040EE8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80040EEC: lbu         $v1, 0x10($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0X10);
    // 0x80040EF0: andi        $t2, $a2, 0x1
    ctx->r10 = ctx->r6 & 0X1;
    // 0x80040EF4: beq         $v1, $zero, L_80040F04
    if (ctx->r3 == 0) {
        // 0x80040EF8: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80040F04;
    }
    // 0x80040EF8: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80040EFC: bnel        $t9, $t0, L_80040F18
    if (ctx->r25 != ctx->r8) {
        // 0x80040F00: slti        $at, $a3, -0x27
        ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
            goto L_80040F18;
    }
    goto skip_5;
    // 0x80040F00: slti        $at, $a3, -0x27
    ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
    skip_5:
L_80040F04:
    // 0x80040F04: beql        $t2, $zero, L_80040F18
    if (ctx->r10 == 0) {
        // 0x80040F08: slti        $at, $a3, -0x27
        ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
            goto L_80040F18;
    }
    goto skip_6;
    // 0x80040F08: slti        $at, $a3, -0x27
    ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
    skip_6:
    // 0x80040F0C: b           L_80040F48
    // 0x80040F10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80040F48;
    // 0x80040F10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80040F14:
    // 0x80040F14: slti        $at, $a3, -0x27
    ctx->r1 = SIGNED(ctx->r7) < -0X27 ? 1 : 0;
L_80040F18:
    // 0x80040F18: beql        $at, $zero, L_80040F3C
    if (ctx->r1 == 0) {
        // 0x80040F1C: slti        $at, $a3, 0x28
        ctx->r1 = SIGNED(ctx->r7) < 0X28 ? 1 : 0;
            goto L_80040F3C;
    }
    goto skip_7;
    // 0x80040F1C: slti        $at, $a3, 0x28
    ctx->r1 = SIGNED(ctx->r7) < 0X28 ? 1 : 0;
    skip_7:
    // 0x80040F20: lw          $t3, 0x1F4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1F4);
    // 0x80040F24: lbu         $t4, 0x1F8($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1F8);
    // 0x80040F28: bnel        $t4, $zero, L_80040F4C
    if (ctx->r12 != 0) {
        // 0x80040F2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040F4C;
    }
    goto skip_8;
    // 0x80040F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80040F30: b           L_80040F48
    // 0x80040F34: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80040F48;
    // 0x80040F34: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80040F38: slti        $at, $a3, 0x28
    ctx->r1 = SIGNED(ctx->r7) < 0X28 ? 1 : 0;
L_80040F3C:
    // 0x80040F3C: bnel        $at, $zero, L_80040F4C
    if (ctx->r1 != 0) {
        // 0x80040F40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040F4C;
    }
    goto skip_9;
    // 0x80040F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80040F44: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80040F48:
    // 0x80040F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040F4C:
    // 0x80040F4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80040F50: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80040F54: jr          $ra
    // 0x80040F58: nop

    return;
    // 0x80040F58: nop

;}
RECOMP_FUNC void func_804093A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804093A8: addiu       $v0, $a0, 0xA00
    ctx->r2 = ADD32(ctx->r4, 0XA00);
    // 0x804093AC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x804093B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804093B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804093B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804093BC: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x804093C0: addiu       $t2, $zero, 0x7C0
    ctx->r10 = ADD32(0, 0X7C0);
    // 0x804093C4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x804093C8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804093CC: beq         $t0, $t3, L_804094F8
    if (ctx->r8 == ctx->r11) {
        // 0x804093D0: sh          $a2, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r6;
            goto L_804094F8;
    }
    // 0x804093D0: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_804093D4:
    // 0x804093D4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804093D8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804093DC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804093E0: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804093E4: sll         $a0, $a3, 6
    ctx->r4 = S32(ctx->r7 << 6);
    // 0x804093E8: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
    // 0x804093EC: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804093F0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x804093F4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804093F8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x804093FC: sh          $t7, -0x3E($v1)
    MEM_H(-0X3E, ctx->r3) = ctx->r15;
    // 0x80409400: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80409404: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80409408: sb          $t8, -0x34($v1)
    MEM_B(-0X34, ctx->r3) = ctx->r24;
    // 0x8040940C: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x80409410: sb          $t9, -0x33($v1)
    MEM_B(-0X33, ctx->r3) = ctx->r25;
    // 0x80409414: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80409418: sb          $t4, -0x32($v1)
    MEM_B(-0X32, ctx->r3) = ctx->r12;
    // 0x8040941C: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80409420: sh          $a2, -0x30($v1)
    MEM_H(-0X30, ctx->r3) = ctx->r6;
    // 0x80409424: sh          $t1, -0x2E($v1)
    MEM_H(-0X2E, ctx->r3) = ctx->r9;
    // 0x80409428: sb          $t5, -0x31($v1)
    MEM_B(-0X31, ctx->r3) = ctx->r13;
    // 0x8040942C: sh          $zero, -0x2C($v1)
    MEM_H(-0X2C, ctx->r3) = 0;
    // 0x80409430: sh          $zero, -0x2A($v1)
    MEM_H(-0X2A, ctx->r3) = 0;
    // 0x80409434: sh          $a0, -0x28($v1)
    MEM_H(-0X28, ctx->r3) = ctx->r4;
    // 0x80409438: sh          $t2, -0x26($v1)
    MEM_H(-0X26, ctx->r3) = ctx->r10;
    // 0x8040943C: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x80409440: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80409444: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x80409448: sb          $t6, -0x24($v1)
    MEM_B(-0X24, ctx->r3) = ctx->r14;
    // 0x8040944C: lbu         $t7, 0x5($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X5);
    // 0x80409450: sll         $a0, $a3, 6
    ctx->r4 = S32(ctx->r7 << 6);
    // 0x80409454: sb          $t7, -0x23($v1)
    MEM_B(-0X23, ctx->r3) = ctx->r15;
    // 0x80409458: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x8040945C: sb          $t8, -0x22($v1)
    MEM_B(-0X22, ctx->r3) = ctx->r24;
    // 0x80409460: lbu         $t9, 0x7($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X7);
    // 0x80409464: sh          $a2, -0x20($v1)
    MEM_H(-0X20, ctx->r3) = ctx->r6;
    // 0x80409468: sb          $t9, -0x21($v1)
    MEM_B(-0X21, ctx->r3) = ctx->r25;
    // 0x8040946C: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80409470: sh          $zero, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = 0;
    // 0x80409474: sh          $zero, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = 0;
    // 0x80409478: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8040947C: sh          $a0, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r4;
    // 0x80409480: sh          $zero, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = 0;
    // 0x80409484: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80409488: nop

    // 0x8040948C: sh          $t5, -0x1E($v1)
    MEM_H(-0X1E, ctx->r3) = ctx->r13;
    // 0x80409490: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80409494: sb          $t6, -0x14($v1)
    MEM_B(-0X14, ctx->r3) = ctx->r14;
    // 0x80409498: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x8040949C: sb          $t7, -0x13($v1)
    MEM_B(-0X13, ctx->r3) = ctx->r15;
    // 0x804094A0: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x804094A4: sb          $t8, -0x12($v1)
    MEM_B(-0X12, ctx->r3) = ctx->r24;
    // 0x804094A8: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x804094AC: sh          $a2, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r6;
    // 0x804094B0: sh          $t1, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = ctx->r9;
    // 0x804094B4: sb          $t9, -0x11($v1)
    MEM_B(-0X11, ctx->r3) = ctx->r25;
    // 0x804094B8: sh          $zero, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = 0;
    // 0x804094BC: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x804094C0: sh          $a0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r4;
    // 0x804094C4: sh          $t2, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r10;
    // 0x804094C8: lbu         $t4, 0x4($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X4);
    // 0x804094CC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x804094D0: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x804094D4: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x804094D8: lbu         $t5, 0x5($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X5);
    // 0x804094DC: sb          $t5, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r13;
    // 0x804094E0: lbu         $t6, 0x6($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X6);
    // 0x804094E4: sb          $t6, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r14;
    // 0x804094E8: lbu         $t7, 0x7($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X7);
    // 0x804094EC: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x804094F0: bne         $t0, $t3, L_804093D4
    if (ctx->r8 != ctx->r11) {
        // 0x804094F4: sb          $t7, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r15;
            goto L_804093D4;
    }
    // 0x804094F4: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
L_804094F8:
    // 0x804094F8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804094FC: sll         $a0, $a3, 6
    ctx->r4 = S32(ctx->r7 << 6);
    // 0x80409500: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
    // 0x80409504: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80409508: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8040950C: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80409510: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80409514: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80409518: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x8040951C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80409520: sh          $t7, -0x3E($v1)
    MEM_H(-0X3E, ctx->r3) = ctx->r15;
    // 0x80409524: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80409528: sb          $t8, -0x34($v1)
    MEM_B(-0X34, ctx->r3) = ctx->r24;
    // 0x8040952C: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x80409530: sb          $t9, -0x33($v1)
    MEM_B(-0X33, ctx->r3) = ctx->r25;
    // 0x80409534: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80409538: sb          $t4, -0x32($v1)
    MEM_B(-0X32, ctx->r3) = ctx->r12;
    // 0x8040953C: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80409540: sh          $t2, -0x26($v1)
    MEM_H(-0X26, ctx->r3) = ctx->r10;
    // 0x80409544: sh          $a0, -0x28($v1)
    MEM_H(-0X28, ctx->r3) = ctx->r4;
    // 0x80409548: sh          $zero, -0x2A($v1)
    MEM_H(-0X2A, ctx->r3) = 0;
    // 0x8040954C: sh          $zero, -0x2C($v1)
    MEM_H(-0X2C, ctx->r3) = 0;
    // 0x80409550: sh          $t1, -0x2E($v1)
    MEM_H(-0X2E, ctx->r3) = ctx->r9;
    // 0x80409554: sh          $a2, -0x30($v1)
    MEM_H(-0X30, ctx->r3) = ctx->r6;
    // 0x80409558: sb          $t5, -0x31($v1)
    MEM_B(-0X31, ctx->r3) = ctx->r13;
    // 0x8040955C: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x80409560: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80409564: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x80409568: sb          $t6, -0x24($v1)
    MEM_B(-0X24, ctx->r3) = ctx->r14;
    // 0x8040956C: lbu         $t7, 0x5($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X5);
    // 0x80409570: sll         $a0, $a3, 6
    ctx->r4 = S32(ctx->r7 << 6);
    // 0x80409574: sb          $t7, -0x23($v1)
    MEM_B(-0X23, ctx->r3) = ctx->r15;
    // 0x80409578: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x8040957C: sb          $t8, -0x22($v1)
    MEM_B(-0X22, ctx->r3) = ctx->r24;
    // 0x80409580: lbu         $t9, 0x7($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X7);
    // 0x80409584: sh          $a2, -0x20($v1)
    MEM_H(-0X20, ctx->r3) = ctx->r6;
    // 0x80409588: sb          $t9, -0x21($v1)
    MEM_B(-0X21, ctx->r3) = ctx->r25;
    // 0x8040958C: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80409590: sh          $zero, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = 0;
    // 0x80409594: sh          $a0, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r4;
    // 0x80409598: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8040959C: sh          $zero, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = 0;
    // 0x804095A0: sh          $zero, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = 0;
    // 0x804095A4: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x804095A8: nop

    // 0x804095AC: sh          $t5, -0x1E($v1)
    MEM_H(-0X1E, ctx->r3) = ctx->r13;
    // 0x804095B0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x804095B4: sb          $t6, -0x14($v1)
    MEM_B(-0X14, ctx->r3) = ctx->r14;
    // 0x804095B8: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x804095BC: sb          $t7, -0x13($v1)
    MEM_B(-0X13, ctx->r3) = ctx->r15;
    // 0x804095C0: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x804095C4: sb          $t8, -0x12($v1)
    MEM_B(-0X12, ctx->r3) = ctx->r24;
    // 0x804095C8: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x804095CC: sh          $t2, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r10;
    // 0x804095D0: sh          $a0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r4;
    // 0x804095D4: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x804095D8: sh          $zero, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = 0;
    // 0x804095DC: sh          $t1, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = ctx->r9;
    // 0x804095E0: sh          $a2, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r6;
    // 0x804095E4: sb          $t9, -0x11($v1)
    MEM_B(-0X11, ctx->r3) = ctx->r25;
    // 0x804095E8: lbu         $t4, 0x4($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X4);
    // 0x804095EC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x804095F0: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x804095F4: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x804095F8: lbu         $t5, 0x5($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X5);
    // 0x804095FC: sb          $t5, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r13;
    // 0x80409600: lbu         $t6, 0x6($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X6);
    // 0x80409604: sb          $t6, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r14;
    // 0x80409608: lbu         $t7, 0x7($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X7);
    // 0x8040960C: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x80409610: jr          $ra
    // 0x80409614: nop

    return;
    // 0x80409614: nop

;}
RECOMP_FUNC void func_80069A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069A88: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80069A8C: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80069A90: addiu       $a0, $a3, -0x6808
    ctx->r4 = ADD32(ctx->r7, -0X6808);
    // 0x80069A94: jal         0x80065528
    // 0x80069A98: addiu       $a2, $zero, 0x3FA
    ctx->r6 = ADD32(0, 0X3FA);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x80069A98: addiu       $a2, $zero, 0x3FA
    ctx->r6 = ADD32(0, 0X3FA);
    after_0:
    // 0x80069A9C: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80069AA0: jal         0x800699BC
    // 0x80069AA4: addiu       $a0, $a3, -0x6808
    ctx->r4 = ADD32(ctx->r7, -0X6808);
    func_800699BC(rdram, ctx);
        goto after_1;
    // 0x80069AA4: addiu       $a0, $a3, -0x6808
    ctx->r4 = ADD32(ctx->r7, -0X6808);
    after_1:
    // 0x80069AA8: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80069AAC: addiu       $a3, $a3, -0x6808
    ctx->r7 = ADD32(ctx->r7, -0X6808);
    // 0x80069AB0: lui         $t6, 0x8131
    ctx->r14 = S32(0X8131 << 16);
    // 0x80069AB4: ori         $t6, $t6, 0x7531
    ctx->r14 = ctx->r14 | 0X7531;
    // 0x80069AB8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80069ABC: sh          $v0, 0x3FA($a3)
    MEM_H(0X3FA, ctx->r7) = ctx->r2;
    // 0x80069AC0: sw          $t6, 0x3FC($a3)
    MEM_W(0X3FC, ctx->r7) = ctx->r14;
    // 0x80069AC4: addiu       $t7, $t7, -0x6408
    ctx->r15 = ADD32(ctx->r15, -0X6408);
    // 0x80069AC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x80069ACC: addiu       $t1, $a3, 0x3FC
    ctx->r9 = ADD32(ctx->r7, 0X3FC);
L_80069AD0:
    // 0x80069AD0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80069AD4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80069AD8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80069ADC: sw          $t9, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r25;
    // 0x80069AE0: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x80069AE4: sw          $t8, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r24;
    // 0x80069AE8: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x80069AEC: bne         $t0, $t1, L_80069AD0
    if (ctx->r8 != ctx->r9) {
        // 0x80069AF0: sw          $t9, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r25;
            goto L_80069AD0;
    }
    // 0x80069AF0: sw          $t9, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r25;
    // 0x80069AF4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80069AF8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069AFC: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    // 0x80069B00: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80069B04: jal         0x8007D590
    // 0x80069B08: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    eepmgr_SendWrite(rdram, ctx);
        goto after_2;
    // 0x80069B08: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    after_2:
    // 0x80069B0C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069B10: jal         0x8007D508
    // 0x80069B14: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    func_8007D508(rdram, ctx);
        goto after_3;
    // 0x80069B14: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    after_3:
    // 0x80069B18: beq         $v0, $zero, L_80069B28
    if (ctx->r2 == 0) {
        // 0x80069B1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069B28;
    }
    // 0x80069B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069B20: b           L_80069B2C
    // 0x80069B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80069B2C;
    // 0x80069B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069B28:
    // 0x80069B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069B2C:
    // 0x80069B2C: jr          $ra
    // 0x80069B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800579E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800579E4: lh          $a1, 0x8($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X8);
    // 0x800579E8: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800579EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800579F0: blezl       $a1, L_80057A20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800579F4: addiu       $v0, $zero, 0x96
        ctx->r2 = ADD32(0, 0X96);
            goto L_80057A20;
    }
    goto skip_0;
    // 0x800579F4: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    skip_0:
L_800579F8:
    // 0x800579F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800579FC: bnel        $t6, $zero, L_80057A10
    if (ctx->r14 != 0) {
        // 0x80057A00: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80057A10;
    }
    goto skip_1;
    // 0x80057A00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80057A04: jr          $ra
    // 0x80057A08: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80057A08: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80057A0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80057A10:
    // 0x80057A10: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80057A14: bne         $at, $zero, L_800579F8
    if (ctx->r1 != 0) {
        // 0x80057A18: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800579F8;
    }
    // 0x80057A18: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80057A1C: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80057A20:
    // 0x80057A20: jr          $ra
    // 0x80057A24: nop

    return;
    // 0x80057A24: nop

;}
RECOMP_FUNC void func_8071177C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071177C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80711780: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80711784: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80711788: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8071178C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80711790: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80711794: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80711798: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8071179C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x807117A0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x807117A4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x807117A8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x807117AC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x807117B0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x807117B4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807117B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807117BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x807117C0: beq         $v0, $at, L_80711808
    if (ctx->r2 == ctx->r1) {
        // 0x807117C4: lw          $fp, 0x1F4($a0)
        ctx->r30 = MEM_W(ctx->r4, 0X1F4);
            goto L_80711808;
    }
    // 0x807117C4: lw          $fp, 0x1F4($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X1F4);
    // 0x807117C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807117CC: beq         $v0, $at, L_8071183C
    if (ctx->r2 == ctx->r1) {
        // 0x807117D0: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8071183C;
    }
    // 0x807117D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x807117D4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807117D8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x807117DC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x807117E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x807117E4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x807117E8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x807117EC: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x807117F0: sb          $t0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r8;
    // 0x807117F4: sb          $t9, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r25;
    // 0x807117F8: sb          $t8, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r24;
    // 0x807117FC: sb          $t7, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r15;
    // 0x80711800: b           L_80711868
    // 0x80711804: sb          $t6, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r14;
        goto L_80711868;
    // 0x80711804: sb          $t6, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r14;
L_80711808:
    // 0x80711808: addiu       $t2, $zero, 0xBF
    ctx->r10 = ADD32(0, 0XBF);
    // 0x8071180C: addiu       $t3, $zero, 0xBF
    ctx->r11 = ADD32(0, 0XBF);
    // 0x80711810: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80711814: addiu       $t5, $zero, 0xBF
    ctx->r13 = ADD32(0, 0XBF);
    // 0x80711818: addiu       $t6, $zero, 0xBF
    ctx->r14 = ADD32(0, 0XBF);
    // 0x8071181C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80711820: sb          $t4, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r12;
    // 0x80711824: sb          $t3, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r11;
    // 0x80711828: sb          $t2, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r10;
    // 0x8071182C: sb          $t7, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r15;
    // 0x80711830: sb          $t6, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r14;
    // 0x80711834: b           L_80711868
    // 0x80711838: sb          $t5, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r13;
        goto L_80711868;
    // 0x80711838: sb          $t5, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r13;
L_8071183C:
    // 0x8071183C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80711840: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80711844: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80711848: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8071184C: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80711850: sb          $t0, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r8;
    // 0x80711854: sb          $t9, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r25;
    // 0x80711858: sb          $t8, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r24;
    // 0x8071185C: sb          $t3, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r11;
    // 0x80711860: sb          $t2, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r10;
    // 0x80711864: sb          $t1, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r9;
L_80711868:
    // 0x80711868: lw          $t4, 0x1E0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X1E0);
    // 0x8071186C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80711870: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x80711874: sh          $t4, 0x2($fp)
    MEM_H(0X2, ctx->r30) = ctx->r12;
L_80711878:
    // 0x80711878: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8071187C: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80711880: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80711884: bne         $at, $zero, L_80711878
    if (ctx->r1 != 0) {
        // 0x80711888: sw          $zero, 0x8($s1)
        MEM_W(0X8, ctx->r17) = 0;
            goto L_80711878;
    }
    // 0x80711888: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8071188C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(727, 0X1960) << 16);
    // 0x80711890: lwc1        $f24, 0x28D0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(727, 0X1960));
    // 0x80711894: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(727, 0X1964) << 16);
    // 0x80711898: lui         $s6, 0x4627
    ctx->r22 = S32(0X4627 << 16);
    // 0x8071189C: lui         $s5, 0x8071
    ctx->r21 = S32(RELOC_HI16(727, 0X1AA0) << 16);
    // 0x807118A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807118A4: addiu       $s5, $s5, 0x2A10
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(727, 0X1AA0));
    // 0x807118A8: ori         $s6, $s6, 0x2000
    ctx->r22 = ctx->r22 | 0X2000;
    // 0x807118AC: lwc1        $f22, 0x28D4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(727, 0X1964));
    // 0x807118B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807118B4: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    // 0x807118B8: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x807118BC: addiu       $s4, $zero, 0x3FF
    ctx->r20 = ADD32(0, 0X3FF);
L_807118C0:
    // 0x807118C0: jal         0x80047090
    // 0x807118C4: addiu       $a0, $zero, 0x4627
    ctx->r4 = ADD32(0, 0X4627);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807118C4: addiu       $a0, $zero, 0x4627
    ctx->r4 = ADD32(0, 0X4627);
    after_0:
    // 0x807118C8: beq         $s4, $v0, L_807119A0
    if (ctx->r20 == ctx->r2) {
        // 0x807118CC: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_807119A0;
    }
    // 0x807118CC: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x807118D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807118D4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x807118D8: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x807118DC: addu        $s1, $fp, $t5
    ctx->r17 = ADD32(ctx->r30, ctx->r13);
    // 0x807118E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807118E4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x807118E8: jal         0x80046804
    // 0x807118EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x807118EC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x807118F0: beq         $v0, $zero, L_8071198C
    if (ctx->r2 == 0) {
        // 0x807118F4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8071198C;
    }
    // 0x807118F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807118F8: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x807118FC: andi        $t7, $s3, 0x3FF
    ctx->r15 = ctx->r19 & 0X3FF;
    // 0x80711900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80711904: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80711908: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8071190C: jal         0x80711690
    // 0x80711910: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    func_80711690(rdram, ctx);
        goto after_2;
    // 0x80711910: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    after_2:
    // 0x80711914: lw          $t1, 0x1E0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E0);
    // 0x80711918: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8071191C: beq         $t1, $zero, L_80711934
    if (ctx->r9 == 0) {
        // 0x80711920: nop
    
            goto L_80711934;
    }
    // 0x80711920: nop

    // 0x80711924: jal         0x800445A4
    // 0x80711928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x80711928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8071192C: b           L_8071198C
    // 0x80711930: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8071198C;
    // 0x80711930: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80711934:
    // 0x80711934: jal         0x80047F9C
    // 0x80711938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80711938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8071193C: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x80711940: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x80711944: lw          $v0, 0x16C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X16C);
    // 0x80711948: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8071194C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x80711950: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80711954: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x80711958: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8071195C: lbu         $t2, 0x60($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X60);
    // 0x80711960: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80711964: lbu         $t3, 0x61($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X61);
    // 0x80711968: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    // 0x8071196C: lbu         $t4, 0x62($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X62);
    // 0x80711970: sb          $t4, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r12;
    // 0x80711974: lbu         $t5, 0x64($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X64);
    // 0x80711978: sb          $t5, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r13;
    // 0x8071197C: lbu         $t6, 0x65($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X65);
    // 0x80711980: sb          $t6, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r14;
    // 0x80711984: lbu         $t8, 0x66($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X66);
    // 0x80711988: sb          $t8, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r24;
L_8071198C:
    // 0x8071198C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80711990: bne         $s2, $s7, L_807118C0
    if (ctx->r18 != ctx->r23) {
        // 0x80711994: sw          $s0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r16;
            goto L_807118C0;
    }
    // 0x80711994: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
    // 0x80711998: sw          $zero, 0x8($fp)
    MEM_W(0X8, ctx->r30) = 0;
    // 0x8071199C: sw          $zero, 0x4($fp)
    MEM_W(0X4, ctx->r30) = 0;
L_807119A0:
    // 0x807119A0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x807119A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x807119A8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x807119AC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x807119B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x807119B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x807119B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x807119BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x807119C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x807119C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x807119C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x807119CC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x807119D0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x807119D4: jr          $ra
    // 0x807119D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x807119D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_804309C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804309C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804309CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804309D0: jal         0x8004700C
    // 0x804309D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804309D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804309D8: bne         $v0, $zero, L_80430A48
    if (ctx->r2 != 0) {
        // 0x804309DC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80430A48;
    }
    // 0x804309DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804309E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x804309E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804309E8: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804309EC: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804309F0: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804309F4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x804309F8: nop

    // 0x804309FC: bc1fl       L_80430A4C
    if (!c1cs) {
        // 0x80430A00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80430A4C;
    }
    goto skip_0;
    // 0x80430A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80430A04: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80430A08: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80430A0C: nop

    // 0x80430A10: bc1fl       L_80430A4C
    if (!c1cs) {
        // 0x80430A14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80430A4C;
    }
    goto skip_1;
    // 0x80430A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80430A18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80430A1C: nop

    // 0x80430A20: bc1f        L_80430A38
    if (!c1cs) {
        // 0x80430A24: nop
    
            goto L_80430A38;
    }
    // 0x80430A24: nop

    // 0x80430A28: jal         0x804308DC
    // 0x80430A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804308DC(rdram, ctx);
        goto after_1;
    // 0x80430A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80430A30: b           L_80430A40
    // 0x80430A34: nop

        goto L_80430A40;
    // 0x80430A34: nop

L_80430A38:
    // 0x80430A38: jal         0x804308DC
    // 0x80430A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804308DC(rdram, ctx);
        goto after_2;
    // 0x80430A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80430A40:
    // 0x80430A40: jal         0x800447C8
    // 0x80430A44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x80430A44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_80430A48:
    // 0x80430A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430A4C:
    // 0x80430A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430A50: jr          $ra
    // 0x80430A54: nop

    return;
    // 0x80430A54: nop

;}
RECOMP_FUNC void func_80020820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002082C: jal         0x80049C70
    // 0x80020830: addiu       $a3, $a0, 0x84
    ctx->r7 = ADD32(ctx->r4, 0X84);
    func_80049C70(rdram, ctx);
        goto after_0;
    // 0x80020830: addiu       $a3, $a0, 0x84
    ctx->r7 = ADD32(ctx->r4, 0X84);
    after_0:
    // 0x80020834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002083C: jr          $ra
    // 0x80020840: nop

    return;
    // 0x80020840: nop

;}
RECOMP_FUNC void func_800773A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800773A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800773AC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800773B0: sll         $t0, $a2, 7
    ctx->r8 = S32(ctx->r6 << 7);
    // 0x800773B4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800773B8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800773BC: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800773C0: addiu       $t1, $t1, -0x79C8
    ctx->r9 = ADD32(ctx->r9, -0X79C8);
    // 0x800773C4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800773C8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800773CC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800773D0: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x800773D4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800773D8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800773DC: beq         $a1, $at, L_800773FC
    if (ctx->r5 == ctx->r1) {
        // 0x800773E0: lw          $t3, 0x4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4);
            goto L_800773FC;
    }
    // 0x800773E0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800773E4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800773E8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800773EC: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800773F0: ori         $t5, $t5, 0xE02
    ctx->r13 = ctx->r13 | 0XE02;
    // 0x800773F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800773F8: sw          $a1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r5;
L_800773FC:
    // 0x800773FC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80077400: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80077404: jr          $ra
    // 0x80077408: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80077408: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80741AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741AA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80741AA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80741AA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80741AAC: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80741AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80741AB4: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
    // 0x80741AB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80741ABC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80741AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741AC4: jal         0x80048F84
    // 0x80741AC8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80741AC8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80741ACC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80741AD0: jal         0x80048F84
    // 0x80741AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80741AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80741AD8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80741ADC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80741AE0: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80741AE4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80741AE8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11F8) << 16);
    // 0x80741AEC: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80741AF0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80741AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80741AF8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80741AFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80741B00: bc1f        L_80741B18
    if (!c1cs) {
        // 0x80741B04: nop
    
            goto L_80741B18;
    }
    // 0x80741B04: nop

    // 0x80741B08: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(751, 0X11F4) << 16);
    // 0x80741B0C: lwc1        $f8, 0x2054($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11F4));
    // 0x80741B10: b           L_80741B20
    // 0x80741B14: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
        goto L_80741B20;
    // 0x80741B14: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80741B18:
    // 0x80741B18: lwc1        $f10, 0x2058($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(751, 0X11F8));
    // 0x80741B1C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80741B20:
    // 0x80741B20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80741B24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80741B28: nop

    // 0x80741B2C: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80741B30: nop

    // 0x80741B34: bc1fl       L_80741B58
    if (!c1cs) {
        // 0x80741B38: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_80741B58;
    }
    goto skip_0;
    // 0x80741B38: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x80741B3C: sw          $t6, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r14;
    // 0x80741B40: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80741B44: sw          $zero, 0x6C($a3)
    MEM_W(0X6C, ctx->r7) = 0;
    // 0x80741B48: jal         0x80741E44
    // 0x80741B4C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80741E44(rdram, ctx);
        goto after_2;
    // 0x80741B4C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80741B50: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80741B54: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_80741B58:
    // 0x80741B58: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80741B5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80741B60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80741B64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80741B68: jr          $ra
    // 0x80741B6C: nop

    return;
    // 0x80741B6C: nop

;}
RECOMP_FUNC void func_8044BB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB04: jr          $ra
    // 0x8044BB08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_806A9F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9F5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A9F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A9F64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A9F68: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A9F6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806A9F70: jal         0x806A98AC
    // 0x806A9F74: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_806A98AC(rdram, ctx);
        goto after_0;
    // 0x806A9F74: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x806A9F78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806A9F7C: bne         $v0, $at, L_806A9F94
    if (ctx->r2 != ctx->r1) {
        // 0x806A9F80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806A9F94;
    }
    // 0x806A9F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9F88: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806A9F8C: jal         0x806AA784
    // 0x806A9F90: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806A9F90: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
L_806A9F94:
    // 0x806A9F94: jal         0x806A9A30
    // 0x806A9F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A9A30(rdram, ctx);
        goto after_2;
    // 0x806A9F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806A9F9C: beq         $v0, $zero, L_806A9FC8
    if (ctx->r2 == 0) {
        // 0x806A9FA0: nop
    
            goto L_806A9FC8;
    }
    // 0x806A9FA0: nop

    // 0x806A9FA4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806A9FA8: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806A9FAC: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x806A9FB0: lh          $t1, 0x1BE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1BE);
    // 0x806A9FB4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x806A9FB8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806A9FBC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x806A9FC0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x806A9FC4: sh          $t0, 0x12C($t3)
    MEM_H(0X12C, ctx->r11) = ctx->r8;
L_806A9FC8:
    // 0x806A9FC8: jal         0x806A99EC
    // 0x806A9FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A99EC(rdram, ctx);
        goto after_3;
    // 0x806A9FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806A9FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9FD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A9FD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806A9FDC: jr          $ra
    // 0x806A9FE0: nop

    return;
    // 0x806A9FE0: nop

;}
RECOMP_FUNC void func_80029B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029B14: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029B18: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80029B1C: addiu       $a1, $a2, 0x1D0
    ctx->r5 = ADD32(ctx->r6, 0X1D0);
    // 0x80029B20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029B24: addiu       $a2, $a2, 0x1D8
    ctx->r6 = ADD32(ctx->r6, 0X1D8);
    // 0x80029B28: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80029B2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029B30: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029B34: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80029B38: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80029B3C: jal         0x80029574
    // 0x80029B40: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029574(rdram, ctx);
        goto after_0;
    // 0x80029B40: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80029B44: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80029B48: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80029B4C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80029B50: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029B54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029B58: jal         0x80029774
    // 0x80029B5C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029774(rdram, ctx);
        goto after_1;
    // 0x80029B5C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80029B60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029B64: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80029B68: jal         0x80029220
    // 0x80029B6C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_80029220(rdram, ctx);
        goto after_2;
    // 0x80029B6C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80029B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029B74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029B78: jr          $ra
    // 0x80029B7C: nop

    return;
    // 0x80029B7C: nop

;}
RECOMP_FUNC void func_80667DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667DCC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80667DD0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80667DD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80667DD8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80667DDC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80667DE0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80667DE4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80667DE8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80667DEC: lui         $t1, 0x8066
    ctx->r9 = S32(RELOC_HI16(507, 0X200) << 16);
    // 0x80667DF0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80667DF4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80667DF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80667DFC: lw          $t1, 0x7ED0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(507, 0X200));
    // 0x80667E00: jr          $ra
    // 0x80667E04: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80667E04: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804C5320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5320: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x804C5324: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(212, 0X974) << 16);
    // 0x804C5328: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x804C532C: lw          $v0, 0x58B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(212, 0X974));
    // 0x804C5330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5338: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C533C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C5340: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x804C5344: jalr        $t9
    // 0x804C5348: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804C5348: nop

    after_0:
    // 0x804C534C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C5350: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804C5354: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804C5358: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804C535C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804C5360: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804C5364: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804C5368: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x804C536C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5374: jr          $ra
    // 0x804C5378: nop

    return;
    // 0x804C5378: nop

;}
RECOMP_FUNC void func_8002C128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C12C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C130: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C134: addiu       $a1, $a1, -0x2AC0
    ctx->r5 = ADD32(ctx->r5, -0X2AC0);
    // 0x8002C138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C13C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C140: jal         0x80028118
    // 0x8002C144: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C144: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C14C: jal         0x8002C064
    // 0x8002C150: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002C064(rdram, ctx);
        goto after_1;
    // 0x8002C150: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002C154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C15C: jr          $ra
    // 0x8002C160: nop

    return;
    // 0x8002C160: nop

;}
RECOMP_FUNC void func_8074253C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8074253C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80742540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742544: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742548: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8074254C: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x80742550: lw          $v1, 0x6E6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6E6C);
    // 0x80742554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80742558: lw          $t1, 0x6E54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6E54);
    // 0x8074255C: bne         $v1, $at, L_8074256C
    if (ctx->r3 != ctx->r1) {
        // 0x80742560: nop
    
            goto L_8074256C;
    }
    // 0x80742560: nop

    // 0x80742564: beq         $t1, $zero, L_8074257C
    if (ctx->r9 == 0) {
        // 0x80742568: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8074257C;
    }
    // 0x80742568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8074256C:
    // 0x8074256C: jal         0x807424D8
    // 0x80742570: nop

    func_807424D8(rdram, ctx);
        goto after_0;
    // 0x80742570: nop

    after_0:
    // 0x80742574: b           L_807425DC
    // 0x80742578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807425DC;
    // 0x80742578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8074257C:
    // 0x8074257C: lwc1        $f12, 0x6BE0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6BE0);
    // 0x80742580: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742584: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80742588: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8074258C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742590: jal         0x80742308
    // 0x80742594: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80742308(rdram, ctx);
        goto after_1;
    // 0x80742594: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80742598: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8074259C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807425A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807425A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807425A8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x807425AC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x807425B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807425B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807425B8: jal         0x80742354
    // 0x807425BC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_80742354(rdram, ctx);
        goto after_2;
    // 0x807425BC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x807425C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807425C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807425C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807425CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807425D0: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x807425D4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x807425D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807425DC:
    // 0x807425DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807425E0: jr          $ra
    // 0x807425E4: nop

    return;
    // 0x807425E4: nop

;}
RECOMP_FUNC void func_8005B75C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B75C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B760: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005B764: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8005B768: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8005B76C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8005B770: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B774: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8005B778: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005B77C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8005B780: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005B784: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005B788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B78C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005B790: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8005B794: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005B798: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005B79C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8005B7A0: jal         0x8005B54C
    // 0x8005B7A4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_8005B54C(rdram, ctx);
        goto after_0;
    // 0x8005B7A4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x8005B7A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B7AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005B7B0: jr          $ra
    // 0x8005B7B4: nop

    return;
    // 0x8005B7B4: nop

;}
RECOMP_FUNC void func_806CF864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CF864: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806CF868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CF86C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CF870: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x806CF874: nop

    // 0x806CF878: bc1fl       L_806CF88C
    if (!c1cs) {
        // 0x806CF87C: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_806CF88C;
    }
    goto skip_0;
    // 0x806CF87C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x806CF880: b           L_806CF8B0
    // 0x806CF884: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_806CF8B0;
    // 0x806CF884: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x806CF888: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_806CF88C:
    // 0x806CF88C: jal         0x80065414
    // 0x806CF890: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x806CF890: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x806CF894: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x806CF898: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806CF89C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806CF8A0: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806CF8A4: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x806CF8A8: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x806CF8AC: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_806CF8B0:
    // 0x806CF8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CF8B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CF8B8: jr          $ra
    // 0x806CF8BC: nop

    return;
    // 0x806CF8BC: nop

;}
RECOMP_FUNC void func_80046FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046FBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046FC0: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80046FC4: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80046FC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80046FCC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80046FD0: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80046FD4: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80046FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046FDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80046FE0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80046FE4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80046FE8: sh          $a2, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r6;
    // 0x80046FEC: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x80046FF0: addiu       $a0, $a0, 0x6F80
    ctx->r4 = ADD32(ctx->r4, 0X6F80);
    // 0x80046FF4: jal         0x80046D2C
    // 0x80046FF8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80046D2C(rdram, ctx);
        goto after_0;
    // 0x80046FF8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80046FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80047004: jr          $ra
    // 0x80047008: nop

    return;
    // 0x80047008: nop

;}
RECOMP_FUNC void func_80039338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003933C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039340: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80039344: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80039348: beql        $a2, $zero, L_8003935C
    if (ctx->r6 == 0) {
        // 0x8003934C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003935C;
    }
    goto skip_0;
    // 0x8003934C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80039350: jal         0x800390F0
    // 0x80039354: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800390F0(rdram, ctx);
        goto after_0;
    // 0x80039354: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80039358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003935C:
    // 0x8003935C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039360: jr          $ra
    // 0x80039364: nop

    return;
    // 0x80039364: nop

;}
RECOMP_FUNC void func_80067CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067CE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067CEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067CF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067CF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80067CF8: jal         0x80067BBC
    // 0x80067CFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067CFC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80067D00: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80067D04: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067D08: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067D0C: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80067D10: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80067D14: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80067D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067D20: jr          $ra
    // 0x80067D24: nop

    return;
    // 0x80067D24: nop

;}
RECOMP_FUNC void func_80698EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80698EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80698EC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80698EC8: jal         0x80045A34
    // 0x80698ECC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80698ECC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80698ED0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80698ED4: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80698ED8: bne         $v0, $zero, L_80698EE8
    if (ctx->r2 != 0) {
        // 0x80698EDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80698EE8;
    }
    // 0x80698EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80698EE0: b           L_80698EEC
    // 0x80698EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80698EEC;
    // 0x80698EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80698EE8:
    // 0x80698EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80698EEC:
    // 0x80698EEC: jr          $ra
    // 0x80698EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80698EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void guTranslateF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F148: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008F14C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008F150: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8008F154: jal         0x80086EA0
    // 0x8008F158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8008F158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F15C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008F160: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008F164: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8008F168: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008F16C: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8008F170: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008F174: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8008F178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F180: jr          $ra
    // 0x8008F184: nop

    return;
    // 0x8008F184: nop

;}
RECOMP_FUNC void func_8043BA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BA40: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(86, 0X120) << 16);
    // 0x8043BA44: addiu       $v0, $v0, -0x44A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(86, 0X120));
    // 0x8043BA48: jr          $ra
    // 0x8043BA4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8043BA4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80031C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031C44: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031C48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031C4C: jal         0x800310A0
    // 0x80031C50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031C50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031C54: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80031C58: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80031C5C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80031C60: lbu         $t6, 0x1B4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1B4);
    // 0x80031C64: beq         $t6, $zero, L_80031C9C
    if (ctx->r14 == 0) {
        // 0x80031C68: nop
    
            goto L_80031C9C;
    }
    // 0x80031C68: nop

    // 0x80031C6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80031C70: jal         0x80062DD4
    // 0x80031C74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80062DD4(rdram, ctx);
        goto after_1;
    // 0x80031C74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80031C78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80031C7C: beq         $v0, $zero, L_80031C9C
    if (ctx->r2 == 0) {
        // 0x80031C80: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80031C9C;
    }
    // 0x80031C80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80031C84: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x80031C88: addiu       $t7, $t7, 0x1CB4
    ctx->r15 = ADD32(ctx->r15, 0X1CB4);
    // 0x80031C8C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80031C90: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x80031C94: b           L_80031CA4
    // 0x80031C98: sw          $t8, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r24;
        goto L_80031CA4;
    // 0x80031C98: sw          $t8, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r24;
L_80031C9C:
    // 0x80031C9C: jal         0x800310D0
    // 0x80031CA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031CA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_80031CA4:
    // 0x80031CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031CA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031CAC: jr          $ra
    // 0x80031CB0: nop

    return;
    // 0x80031CB0: nop

;}
RECOMP_FUNC void func_80445B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445B3C: jal         0x800679B0
    // 0x80445B40: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    func_800679B0(rdram, ctx);
        goto after_0;
    // 0x80445B40: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_0:
    // 0x80445B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445B4C: jr          $ra
    // 0x80445B50: nop

    return;
    // 0x80445B50: nop

;}
RECOMP_FUNC void func_80449A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449A04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449A08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449A0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449A14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449A18: bne         $a2, $zero, L_80449A40
    if (ctx->r6 != 0) {
        // 0x80449A1C: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449A40;
    }
    // 0x80449A1C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449A20: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80449A24: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80449A28: bgtz        $t7, L_80449A80
    if (SIGNED(ctx->r15) > 0) {
        // 0x80449A2C: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_80449A80;
    }
    // 0x80449A2C: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80449A30: jal         0x80446A50
    // 0x80449A34: nop

    func_80446A50(rdram, ctx);
        goto after_0;
    // 0x80449A34: nop

    after_0:
    // 0x80449A38: b           L_80449A84
    // 0x80449A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449A84;
    // 0x80449A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449A40:
    // 0x80449A40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449A44: bnel        $a2, $at, L_80449A70
    if (ctx->r6 != ctx->r1) {
        // 0x80449A48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449A70;
    }
    goto skip_0;
    // 0x80449A48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449A4C: jal         0x804469FC
    // 0x80449A50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804469FC(rdram, ctx);
        goto after_1;
    // 0x80449A50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449A54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449A58: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449A5C: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80449A60: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449A64: b           L_80449A80
    // 0x80449A68: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449A80;
    // 0x80449A68: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80449A6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449A70:
    // 0x80449A70: bnel        $a2, $at, L_80449A84
    if (ctx->r6 != ctx->r1) {
        // 0x80449A74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449A84;
    }
    goto skip_1;
    // 0x80449A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449A78: jal         0x80446A50
    // 0x80449A7C: nop

    func_80446A50(rdram, ctx);
        goto after_2;
    // 0x80449A7C: nop

    after_2:
L_80449A80:
    // 0x80449A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449A84:
    // 0x80449A84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449A8C: jr          $ra
    // 0x80449A90: nop

    return;
    // 0x80449A90: nop

;}
RECOMP_FUNC void func_80463198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046319C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804631A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804631A4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804631A8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804631AC: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X3930) << 16);
    // 0x804631B0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804631B4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804631B8: addiu       $t7, $t7, 0x3EC0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X3930));
    // 0x804631BC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804631C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804631C4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804631C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804631CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804631D0: jal         0x80463260
    // 0x804631D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80463260(rdram, ctx);
        goto after_0;
    // 0x804631D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804631D8: jal         0x80463124
    // 0x804631DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80463124(rdram, ctx);
        goto after_1;
    // 0x804631DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804631E0: bne         $v0, $zero, L_804631F8
    if (ctx->r2 != 0) {
        // 0x804631E4: lui         $t9, 0x8005
        ctx->r25 = S32(0X8005 << 16);
            goto L_804631F8;
    }
    // 0x804631E4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804631E8: jal         0x800445A4
    // 0x804631EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x804631EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804631F0: b           L_80463250
    // 0x804631F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80463250;
    // 0x804631F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804631F8:
    // 0x804631F8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804631FC: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x80463200: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80463204: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80463208: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8046320C: jal         0x80462988
    // 0x80463210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80462988(rdram, ctx);
        goto after_3;
    // 0x80463210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80463214: jal         0x80463180
    // 0x80463218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80463180(rdram, ctx);
        goto after_4;
    // 0x80463218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8046321C: jal         0x804630D8
    // 0x80463220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804630D8(rdram, ctx);
        goto after_5;
    // 0x80463220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80463224: bne         $v0, $zero, L_8046323C
    if (ctx->r2 != 0) {
        // 0x80463228: lui         $t1, 0x8046
        ctx->r9 = S32(RELOC_HI16(122, 0X1A0) << 16);
            goto L_8046323C;
    }
    // 0x80463228: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(122, 0X1A0) << 16);
    // 0x8046322C: jal         0x800445A4
    // 0x80463230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80463230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80463234: b           L_80463250
    // 0x80463238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80463250;
    // 0x80463238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046323C:
    // 0x8046323C: addiu       $t1, $t1, 0x730
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(122, 0X1A0));
    // 0x80463240: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80463244: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x80463248: sh          $t2, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r10;
    // 0x8046324C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80463250:
    // 0x80463250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80463254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80463258: jr          $ra
    // 0x8046325C: nop

    return;
    // 0x8046325C: nop

;}
RECOMP_FUNC void func_8006A6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A6C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A6C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A6CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A6D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A6D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A6D8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006A6DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006A6E0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8006A6E4: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8006A6E8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8006A6EC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8006A6F0: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x8006A6F4: jal         0x80064DD0
    // 0x8006A6F8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8006A6F8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x8006A6FC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006A700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006A704: bne         $v0, $zero, L_8006A724
    if (ctx->r2 != 0) {
        // 0x8006A708: sw          $v0, 0x20($t9)
        MEM_W(0X20, ctx->r25) = ctx->r2;
            goto L_8006A724;
    }
    // 0x8006A708: sw          $v0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r2;
    // 0x8006A70C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006A710: addiu       $a0, $a0, 0x1010
    ctx->r4 = ADD32(ctx->r4, 0X1010);
    // 0x8006A714: jal         0x80071380
    // 0x8006A718: addiu       $a1, $zero, 0x299
    ctx->r5 = ADD32(0, 0X299);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8006A718: addiu       $a1, $zero, 0x299
    ctx->r5 = ADD32(0, 0X299);
    after_1:
    // 0x8006A71C: b           L_8006A894
    // 0x8006A720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A894;
    // 0x8006A720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A724:
    // 0x8006A724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A728: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8006A72C: jal         0x80065728
    // 0x8006A730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8006A730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8006A734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A738: jal         0x8006A4A8
    // 0x8006A73C: lw          $a1, 0x40($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X40);
    func_8006A4A8(rdram, ctx);
        goto after_3;
    // 0x8006A73C: lw          $a1, 0x40($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X40);
    after_3:
    // 0x8006A740: sltiu       $s1, $v0, 0x1
    ctx->r17 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A748: jal         0x8006A328
    // 0x8006A74C: lw          $a1, 0x48($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X48);
    func_8006A328(rdram, ctx);
        goto after_4;
    // 0x8006A74C: lw          $a1, 0x48($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X48);
    after_4:
    // 0x8006A750: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A754: or          $s1, $s1, $t0
    ctx->r17 = ctx->r17 | ctx->r8;
    // 0x8006A758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A75C: jal         0x8006A534
    // 0x8006A760: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    func_8006A534(rdram, ctx);
        goto after_5;
    // 0x8006A760: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    after_5:
    // 0x8006A764: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A768: or          $s1, $s1, $t1
    ctx->r17 = ctx->r17 | ctx->r9;
    // 0x8006A76C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006A770: jal         0x8006A5C0
    // 0x8006A774: lw          $a1, 0x58($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X58);
    func_8006A5C0(rdram, ctx);
        goto after_6;
    // 0x8006A774: lw          $a1, 0x58($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X58);
    after_6:
    // 0x8006A778: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A77C: or          $s1, $s1, $t2
    ctx->r17 = ctx->r17 | ctx->r10;
    // 0x8006A780: beq         $s1, $zero, L_8006A798
    if (ctx->r17 == 0) {
        // 0x8006A784: addiu       $v0, $s2, 0x5C
        ctx->r2 = ADD32(ctx->r18, 0X5C);
            goto L_8006A798;
    }
    // 0x8006A784: addiu       $v0, $s2, 0x5C
    ctx->r2 = ADD32(ctx->r18, 0X5C);
    // 0x8006A788: jal         0x8006A64C
    // 0x8006A78C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8006A64C(rdram, ctx);
        goto after_7;
    // 0x8006A78C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x8006A790: b           L_8006A894
    // 0x8006A794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A894;
    // 0x8006A794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A798:
    // 0x8006A798: lbu         $t3, 0x60($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X60);
    // 0x8006A79C: addiu       $v1, $s2, 0x5E
    ctx->r3 = ADD32(ctx->r18, 0X5E);
    // 0x8006A7A0: sb          $t3, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r11;
    // 0x8006A7A4: lh          $t4, 0x5C($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X5C);
    // 0x8006A7A8: bnel        $t4, $zero, L_8006A7D0
    if (ctx->r12 != 0) {
        // 0x8006A7AC: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_8006A7D0;
    }
    goto skip_0;
    // 0x8006A7AC: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    skip_0:
    // 0x8006A7B0: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8006A7B4: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8006A7B8: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8006A7BC: bnel        $t5, $zero, L_8006A7D0
    if (ctx->r13 != 0) {
        // 0x8006A7C0: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_8006A7D0;
    }
    goto skip_1;
    // 0x8006A7C0: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    skip_1:
    // 0x8006A7C4: sh          $t6, 0x5C($s2)
    MEM_H(0X5C, ctx->r18) = ctx->r14;
    // 0x8006A7C8: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8006A7CC: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
L_8006A7D0:
    // 0x8006A7D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8006A7D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A7D8: addiu       $v1, $s2, 0x5E
    ctx->r3 = ADD32(ctx->r18, 0X5E);
    // 0x8006A7DC: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x8006A7E0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8006A7E4: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x8006A7E8: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8006A7EC: bgez        $t0, L_8006A7FC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8006A7F0: sra         $t1, $t0, 4
        ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
            goto L_8006A7FC;
    }
    // 0x8006A7F0: sra         $t1, $t0, 4
    ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8006A7F4: addiu       $at, $t0, 0xF
    ctx->r1 = ADD32(ctx->r8, 0XF);
    // 0x8006A7F8: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8006A7FC:
    // 0x8006A7FC: sh          $t1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r9;
    // 0x8006A800: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x8006A804: bgez        $t2, L_8006A814
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006A808: sra         $t3, $t2, 4
        ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
            goto L_8006A814;
    }
    // 0x8006A808: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8006A80C: addiu       $at, $t2, 0xF
    ctx->r1 = ADD32(ctx->r10, 0XF);
    // 0x8006A810: sra         $t3, $at, 4
    ctx->r11 = S32(SIGNED(ctx->r1) >> 4);
L_8006A814:
    // 0x8006A814: sh          $t3, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r11;
    // 0x8006A818: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x8006A81C: bgez        $t4, L_8006A82C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8006A820: sra         $t5, $t4, 8
        ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
            goto L_8006A82C;
    }
    // 0x8006A820: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x8006A824: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x8006A828: sra         $t5, $at, 8
    ctx->r13 = S32(SIGNED(ctx->r1) >> 8);
L_8006A82C:
    // 0x8006A82C: sh          $t5, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r13;
    // 0x8006A830: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x8006A834: bgez        $t6, L_8006A844
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006A838: sra         $t7, $t6, 8
        ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
            goto L_8006A844;
    }
    // 0x8006A838: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8006A83C: addiu       $at, $t6, 0xFF
    ctx->r1 = ADD32(ctx->r14, 0XFF);
    // 0x8006A840: sra         $t7, $at, 8
    ctx->r15 = S32(SIGNED(ctx->r1) >> 8);
L_8006A844:
    // 0x8006A844: sh          $t7, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r15;
    // 0x8006A848: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8006A84C: lhu         $t9, 0x18($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X18);
    // 0x8006A850: bgez        $t9, L_8006A860
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006A854: sra         $t0, $t9, 4
        ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
            goto L_8006A860;
    }
    // 0x8006A854: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8006A858: addiu       $at, $t9, 0xF
    ctx->r1 = ADD32(ctx->r25, 0XF);
    // 0x8006A85C: sra         $t0, $at, 4
    ctx->r8 = S32(SIGNED(ctx->r1) >> 4);
L_8006A860:
    // 0x8006A860: beq         $a1, $zero, L_8006A890
    if (ctx->r5 == 0) {
        // 0x8006A864: sh          $t0, 0x16($s0)
        MEM_H(0X16, ctx->r16) = ctx->r8;
            goto L_8006A890;
    }
    // 0x8006A864: sh          $t0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r8;
    // 0x8006A868: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8006A86C: bne         $v0, $zero, L_8006A87C
    if (ctx->r2 != 0) {
        // 0x8006A870: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8006A87C;
    }
    // 0x8006A870: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006A874: b           L_8006A894
    // 0x8006A878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A894;
    // 0x8006A878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A87C:
    // 0x8006A87C: bgez        $v0, L_8006A88C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006A880: sra         $t2, $v0, 8
        ctx->r10 = S32(SIGNED(ctx->r2) >> 8);
            goto L_8006A88C;
    }
    // 0x8006A880: sra         $t2, $v0, 8
    ctx->r10 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8006A884: addiu       $at, $v0, 0xFF
    ctx->r1 = ADD32(ctx->r2, 0XFF);
    // 0x8006A888: sra         $t2, $at, 8
    ctx->r10 = S32(SIGNED(ctx->r1) >> 8);
L_8006A88C:
    // 0x8006A88C: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
L_8006A890:
    // 0x8006A890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A894:
    // 0x8006A894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A89C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A8A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A8A4: jr          $ra
    // 0x8006A8A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006A8A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8064F0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F0D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F0DC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F0E0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F0E4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F0E8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F0EC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F0F0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F0F4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F0F8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F0FC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F100: jr          $ra
    // 0x8064F104: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F104: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8040EA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EA08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EA0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040EA10: bne         $a1, $at, L_8040EA28
    if (ctx->r5 != ctx->r1) {
        // 0x8040EA14: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8040EA28;
    }
    // 0x8040EA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EA18: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8040EA1C: beql        $t6, $zero, L_8040EA2C
    if (ctx->r14 == 0) {
        // 0x8040EA20: addiu       $v0, $a0, 0x14C
        ctx->r2 = ADD32(ctx->r4, 0X14C);
            goto L_8040EA2C;
    }
    goto skip_0;
    // 0x8040EA20: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    skip_0:
    // 0x8040EA24: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_8040EA28:
    // 0x8040EA28: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
L_8040EA2C:
    // 0x8040EA2C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8040EA30: bnel        $t7, $zero, L_8040EA7C
    if (ctx->r15 != 0) {
        // 0x8040EA34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040EA7C;
    }
    goto skip_1;
    // 0x8040EA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040EA38: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8040EA3C: bnel        $t8, $zero, L_8040EA7C
    if (ctx->r24 != 0) {
        // 0x8040EA40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040EA7C;
    }
    goto skip_2;
    // 0x8040EA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8040EA44: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EA48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040EA4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EA50: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8040EA54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040EA58: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8040EA5C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8040EA60: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EA64: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8040EA68: bnel        $t2, $at, L_8040EA7C
    if (ctx->r10 != ctx->r1) {
        // 0x8040EA6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040EA7C;
    }
    goto skip_3;
    // 0x8040EA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8040EA70: jal         0x8040F0B8
    // 0x8040EA74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040F0B8(rdram, ctx);
        goto after_0;
    // 0x8040EA74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8040EA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EA7C:
    // 0x8040EA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EA80: jr          $ra
    // 0x8040EA84: nop

    return;
    // 0x8040EA84: nop

;}
RECOMP_FUNC void func_80787064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80787064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80787068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078706C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80787070: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80787074: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80787078: addiu       $v0, $zero, -0x96
    ctx->r2 = ADD32(0, -0X96);
    // 0x8078707C: lhu         $t8, 0x52F0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X52F0);
    // 0x80787080: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80787084: beq         $t9, $zero, L_80787094
    if (ctx->r25 == 0) {
        // 0x80787088: nop
    
            goto L_80787094;
    }
    // 0x80787088: nop

    // 0x8078708C: b           L_80787094
    // 0x80787090: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
        goto L_80787094;
    // 0x80787090: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80787094:
    // 0x80787094: lw          $t0, 0x34($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X34);
    // 0x80787098: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8078709C: jal         0x80067BBC
    // 0x807870A0: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x807870A0: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    after_0:
    // 0x807870A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x807870A8: jal         0x80067818
    // 0x807870AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807870AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807870B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807870B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807870B8: jr          $ra
    // 0x807870BC: nop

    return;
    // 0x807870BC: nop

;}
RECOMP_FUNC void func_80581968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058196C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581970: jal         0x80580C70
    // 0x80581974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x80581974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581978: jal         0x80581734
    // 0x8058197C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80581734(rdram, ctx);
        goto after_1;
    // 0x8058197C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80581980: jal         0x8058178C
    // 0x80581984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8058178C(rdram, ctx);
        goto after_2;
    // 0x80581984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80581988: jal         0x805818EC
    // 0x8058198C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805818EC(rdram, ctx);
        goto after_3;
    // 0x8058198C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80581990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581998: jr          $ra
    // 0x8058199C: nop

    return;
    // 0x8058199C: nop

;}
RECOMP_FUNC void func_8059F8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F8FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059F900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059F904: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059F908: jal         0x8059F6C4
    // 0x8059F90C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8059F6C4(rdram, ctx);
        goto after_0;
    // 0x8059F90C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8059F910: beq         $v0, $zero, L_8059F928
    if (ctx->r2 == 0) {
        // 0x8059F914: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8059F928;
    }
    // 0x8059F914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F91C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8059F920: jal         0x805A0790
    // 0x8059F924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_1;
    // 0x8059F924: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8059F928:
    // 0x8059F928: jal         0x8059F608
    // 0x8059F92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F608(rdram, ctx);
        goto after_2;
    // 0x8059F92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8059F930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8059F934: beq         $v0, $at, L_8059F94C
    if (ctx->r2 == ctx->r1) {
        // 0x8059F938: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8059F94C;
    }
    // 0x8059F938: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8059F93C: beq         $v0, $at, L_8059F95C
    if (ctx->r2 == ctx->r1) {
        // 0x8059F940: nop
    
            goto L_8059F95C;
    }
    // 0x8059F940: nop

    // 0x8059F944: b           L_8059F9E0
    // 0x8059F948: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F9E0;
    // 0x8059F948: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F94C:
    // 0x8059F94C: jal         0x8059F3CC
    // 0x8059F950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059F3CC(rdram, ctx);
        goto after_3;
    // 0x8059F950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8059F954: b           L_8059F9E0
    // 0x8059F958: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F9E0;
    // 0x8059F958: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F95C:
    // 0x8059F95C: jal         0x800653D8
    // 0x8059F960: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x8059F960: nop

    after_4:
    // 0x8059F964: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8059F968: andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // 0x8059F96C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8059F970: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8059F974: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8059F978: subu        $t1, $t0, $v1
    ctx->r9 = SUB32(ctx->r8, ctx->r3);
    // 0x8059F97C: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8059F980: beq         $at, $zero, L_8059F9A4
    if (ctx->r1 == 0) {
        // 0x8059F984: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_8059F9A4;
    }
    // 0x8059F984: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x8059F988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F98C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F990: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8059F994: jal         0x805A0790
    // 0x8059F998: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_5;
    // 0x8059F998: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8059F99C: b           L_8059F9E0
    // 0x8059F9A0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F9E0;
    // 0x8059F9A0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F9A4:
    // 0x8059F9A4: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x8059F9A8: beq         $t2, $zero, L_8059F9CC
    if (ctx->r10 == 0) {
        // 0x8059F9AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8059F9CC;
    }
    // 0x8059F9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F9B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F9B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8059F9BC: jal         0x805A0790
    // 0x8059F9C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_6;
    // 0x8059F9C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8059F9C4: b           L_8059F9E0
    // 0x8059F9C8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_8059F9E0;
    // 0x8059F9C8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F9CC:
    // 0x8059F9CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059F9D0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8059F9D4: jal         0x805A0790
    // 0x8059F9D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_7;
    // 0x8059F9D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8059F9DC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_8059F9E0:
    // 0x8059F9E0: lhu         $t3, 0x8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8);
    // 0x8059F9E4: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x8059F9E8: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    // 0x8059F9EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8059F9F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059F9F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059F9F8: jr          $ra
    // 0x8059F9FC: nop

    return;
    // 0x8059F9FC: nop

;}
RECOMP_FUNC void func_800806B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800806B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800806B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800806B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800806BC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800806C0: jal         0x80082730
    // 0x800806C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x800806C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800806C8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800806CC: jal         0x8008D250
    // 0x800806D0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x800806D0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800806D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800806D8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800806DC: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800806E0: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800806E4: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800806E8: nop

    // 0x800806EC: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800806F0: nop

    // 0x800806F4: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800806F8: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800806FC: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080700: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080704: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080708: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008070C: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80080710: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080714: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080718: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8008071C: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80080720: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080724: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080728: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008072C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x80080730: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080734: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80080738: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8008073C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080740: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080744: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80080748: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8008074C: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80080750: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080754: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80080758: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008075C: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x80080760: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080764: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080768: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8008076C: nop

    // 0x80080770: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080774: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80080778: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008077C: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x80080780: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080784: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80080788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008078C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080790: jr          $ra
    // 0x80080794: nop

    return;
    // 0x80080794: nop

;}
RECOMP_FUNC void func_8064BE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BE24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064BE28: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064BE2C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8064BE30: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064BE34: jr          $ra
    // 0x8064BE38: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8064BE38: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80051BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051BB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051BB8: jal         0x80051100
    // 0x80051BBC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80051100(rdram, ctx);
        goto after_0;
    // 0x80051BBC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80051BC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80051BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051BC8: beql        $t6, $zero, L_80051BDC
    if (ctx->r14 == 0) {
        // 0x80051BCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80051BDC;
    }
    goto skip_0;
    // 0x80051BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80051BD0: jal         0x80051B48
    // 0x80051BD4: nop

    func_80051B48(rdram, ctx);
        goto after_1;
    // 0x80051BD4: nop

    after_1:
    // 0x80051BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80051BDC:
    // 0x80051BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051BE0: jr          $ra
    // 0x80051BE4: nop

    return;
    // 0x80051BE4: nop

;}
RECOMP_FUNC void func_80527790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527798: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052779C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805277A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805277A4: lw          $t6, 0x88($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X88);
    // 0x805277A8: bnel        $t6, $at, L_805277B8
    if (ctx->r14 != ctx->r1) {
        // 0x805277AC: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_805277B8;
    }
    goto skip_0;
    // 0x805277AC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_0:
    // 0x805277B0: sw          $t7, 0x90($a1)
    MEM_W(0X90, ctx->r5) = ctx->r15;
    // 0x805277B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_805277B8:
    // 0x805277B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805277BC: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x805277C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805277C4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x805277C8: nop

    // 0x805277CC: bc1fl       L_805278B0
    if (!c1cs) {
        // 0x805277D0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805278B0;
    }
    goto skip_1;
    // 0x805277D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x805277D4: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x805277D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805277DC: addiu       $v0, $t8, 0x1
    ctx->r2 = ADD32(ctx->r24, 0X1);
    // 0x805277E0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x805277E4: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x805277E8: bne         $at, $zero, L_80527890
    if (ctx->r1 != 0) {
        // 0x805277EC: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80527890;
    }
    // 0x805277EC: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x805277F0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805277F4: addiu       $at, $zero, 0x4583
    ctx->r1 = ADD32(0, 0X4583);
    // 0x805277F8: bnel        $v0, $at, L_80527830
    if (ctx->r2 != ctx->r1) {
        // 0x805277FC: lw          $t2, 0x78($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X78);
            goto L_80527830;
    }
    goto skip_2;
    // 0x805277FC: lw          $t2, 0x78($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X78);
    skip_2:
    // 0x80527800: lw          $t0, 0x90($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X90);
    // 0x80527804: beql        $t0, $zero, L_80527820
    if (ctx->r8 == 0) {
        // 0x80527808: lw          $t1, 0x4($a1)
        ctx->r9 = MEM_W(ctx->r5, 0X4);
            goto L_80527820;
    }
    goto skip_3;
    // 0x80527808: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    skip_3:
    // 0x8052780C: jal         0x80527724
    // 0x80527810: sw          $zero, 0x90($a1)
    MEM_W(0X90, ctx->r5) = 0;
    func_80527724(rdram, ctx);
        goto after_0;
    // 0x80527810: sw          $zero, 0x90($a1)
    MEM_W(0X90, ctx->r5) = 0;
    after_0:
    // 0x80527814: b           L_805278C0
    // 0x80527818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805278C0;
    // 0x80527818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052781C: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
L_80527820:
    // 0x80527820: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80527824: b           L_805278BC
    // 0x80527828: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_805278BC;
    // 0x80527828: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8052782C: lw          $t2, 0x78($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X78);
L_80527830:
    // 0x80527830: addiu       $at, $zero, 0x41ED
    ctx->r1 = ADD32(0, 0X41ED);
    // 0x80527834: blez        $t2, L_80527858
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80527838: nop
    
            goto L_80527858;
    }
    // 0x80527838: nop

    // 0x8052783C: lw          $t4, 0x78($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X78);
    // 0x80527840: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x80527844: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80527848: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8052784C: sw          $t5, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r13;
    // 0x80527850: b           L_805278BC
    // 0x80527854: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_805278BC;
    // 0x80527854: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_80527858:
    // 0x80527858: beq         $v0, $at, L_80527880
    if (ctx->r2 == ctx->r1) {
        // 0x8052785C: addiu       $at, $zero, 0x41EF
        ctx->r1 = ADD32(0, 0X41EF);
            goto L_80527880;
    }
    // 0x8052785C: addiu       $at, $zero, 0x41EF
    ctx->r1 = ADD32(0, 0X41EF);
    // 0x80527860: beq         $v0, $at, L_80527880
    if (ctx->r2 == ctx->r1) {
        // 0x80527864: addiu       $at, $zero, 0x41F0
        ctx->r1 = ADD32(0, 0X41F0);
            goto L_80527880;
    }
    // 0x80527864: addiu       $at, $zero, 0x41F0
    ctx->r1 = ADD32(0, 0X41F0);
    // 0x80527868: bne         $v0, $at, L_80527880
    if (ctx->r2 != ctx->r1) {
        // 0x8052786C: nop
    
            goto L_80527880;
    }
    // 0x8052786C: nop

    // 0x80527870: jal         0x80527744
    // 0x80527874: nop

    func_80527744(rdram, ctx);
        goto after_1;
    // 0x80527874: nop

    after_1:
    // 0x80527878: b           L_805278C0
    // 0x8052787C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805278C0;
    // 0x8052787C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527880:
    // 0x80527880: jal         0x80527724
    // 0x80527884: nop

    func_80527724(rdram, ctx);
        goto after_2;
    // 0x80527884: nop

    after_2:
    // 0x80527888: b           L_805278C0
    // 0x8052788C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805278C0;
    // 0x8052788C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527890:
    // 0x80527890: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80527894: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80527898: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8052789C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805278A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x805278A4: b           L_805278BC
    // 0x805278A8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
        goto L_805278BC;
    // 0x805278A8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x805278AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805278B0:
    // 0x805278B0: nop

    // 0x805278B4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x805278B8: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_805278BC:
    // 0x805278BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805278C0:
    // 0x805278C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805278C4: jr          $ra
    // 0x805278C8: nop

    return;
    // 0x805278C8: nop

;}
RECOMP_FUNC void func_8078C2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078C2E0: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8078C2E4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8078C2E8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8078C2EC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8078C2F0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8078C2F4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8078C2F8: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8078C2FC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8078C300: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8078C304: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8078C308: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8078C30C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8078C310: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x8078C314: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x8078C318: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8078C31C: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8078C320: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8078C324: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8078C328: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8078C32C: addiu       $s2, $zero, 0xD
    ctx->r18 = ADD32(0, 0XD);
    // 0x8078C330: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x8078C334: jal         0x80066DE4
    // 0x8078C338: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8078C338: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8078C33C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8078C340: jal         0x80066E88
    // 0x8078C344: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8078C344: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8078C348: lw          $t6, 0x174($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X174);
    // 0x8078C34C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8078C350: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078C354: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8078C358: lwc1        $f18, 0x88($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X88);
    // 0x8078C35C: mul.s       $f20, $f6, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8078C360: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8078C364: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x8078C368: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    // 0x8078C36C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8078C370: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8078C374: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8078C378: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8078C37C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8078C380: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8078C384: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8078C388: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8078C38C: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x8078C390: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8078C394: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8078C398: nop

    // 0x8078C39C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8078C3A0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8078C3A4: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x8078C3A8: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x8078C3AC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8078C3B0: nop

    // 0x8078C3B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8078C3B8: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8078C3BC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x8078C3C0: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8078C3C4: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x8078C3C8: lwc1        $f10, 0x88($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8078C3CC: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8078C3D0: jal         0x80049018
    // 0x8078C3D4: lw          $s1, 0x1F4($a2)
    ctx->r17 = MEM_W(ctx->r6, 0X1F4);
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x8078C3D4: lw          $s1, 0x1F4($a2)
    ctx->r17 = MEM_W(ctx->r6, 0X1F4);
    after_2:
    // 0x8078C3D8: beql        $v0, $zero, L_8078C410
    if (ctx->r2 == 0) {
        // 0x8078C3DC: lw          $t3, 0x174($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X174);
            goto L_8078C410;
    }
    goto skip_0;
    // 0x8078C3DC: lw          $t3, 0x174($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X174);
    skip_0:
    // 0x8078C3E0: lw          $t0, 0x174($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X174);
    // 0x8078C3E4: lwc1        $f6, 0x84($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X84);
    // 0x8078C3E8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8078C3EC: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x8078C3F0: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x8078C3F4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8078C3F8: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8078C3FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8078C400: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8078C404: b           L_8078C434
    // 0x8078C408: sub.s       $f30, $f6, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_8078C434;
    // 0x8078C408: sub.s       $f30, $f6, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8078C40C: lw          $t3, 0x174($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X174);
L_8078C410:
    // 0x8078C410: lwc1        $f6, 0x84($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X84);
    // 0x8078C414: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8078C418: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8078C41C: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x8078C420: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8078C424: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8078C428: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8078C42C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8078C430: add.s       $f30, $f4, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f4.fl + ctx->f6.fl;
L_8078C434:
    // 0x8078C434: lbu         $t6, 0x18($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X18);
    // 0x8078C438: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8078C43C: beql        $t6, $at, L_8078C53C
    if (ctx->r14 == ctx->r1) {
        // 0x8078C440: lhu         $t8, 0xC($s3)
        ctx->r24 = MEM_HU(ctx->r19, 0XC);
            goto L_8078C53C;
    }
    goto skip_1;
    // 0x8078C440: lhu         $t8, 0xC($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0XC);
    skip_1:
    // 0x8078C444: lhu         $t7, 0xC($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0XC);
    // 0x8078C448: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078C44C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8078C450: bne         $t7, $at, L_8078C65C
    if (ctx->r15 != ctx->r1) {
        // 0x8078C454: lui         $at, 0x8079
        ctx->r1 = S32(RELOC_HI16(796, 0X1B68) << 16);
            goto L_8078C65C;
    }
    // 0x8078C454: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B68) << 16);
    // 0x8078C458: lwc1        $f28, -0x3308($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B68));
L_8078C45C:
    // 0x8078C45C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8078C460: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8078C464: add.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8078C468: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8078C46C: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8078C470: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x8078C474: swc1        $f16, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f16.u32l;
    // 0x8078C478: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8078C47C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8078C480: mul.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8078C484: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8078C488: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8078C48C: nop

    // 0x8078C490: mul.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8078C494: nop

    // 0x8078C498: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8078C49C: sub.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8078C4A0: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8078C4A4: nop

    // 0x8078C4A8: mul.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8078C4AC: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8078C4B0: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8078C4B4: sub.s       $f12, $f6, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f30.fl;
    // 0x8078C4B8: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8078C4BC: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8078C4C0: swc1        $f12, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f12.u32l;
    // 0x8078C4C4: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8078C4C8: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8078C4CC: jal         0x80065954
    // 0x8078C4D0: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8078C4D0: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8078C4D4: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8078C4D8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8078C4DC: nop

    // 0x8078C4E0: bc1f        L_8078C51C
    if (!c1cs) {
        // 0x8078C4E4: nop
    
            goto L_8078C51C;
    }
    // 0x8078C4E4: nop

    // 0x8078C4E8: jal         0x80065954
    // 0x8078C4EC: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8078C4EC: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    after_4:
    // 0x8078C4F0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8078C4F4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8078C4F8: nop

    // 0x8078C4FC: bc1f        L_8078C51C
    if (!c1cs) {
        // 0x8078C500: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8078C51C;
    }
    // 0x8078C500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8078C504: lw          $a1, 0xE8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE8);
    // 0x8078C508: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x8078C50C: jal         0x8002F6E4
    // 0x8078C510: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_5;
    // 0x8078C510: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8078C514: b           L_8078C660
    // 0x8078C518: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8078C660;
    // 0x8078C518: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8078C51C:
    // 0x8078C51C: mul.s       $f6, $f28, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x8078C520: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8078C524: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8078C528: bne         $s0, $s2, L_8078C45C
    if (ctx->r16 != ctx->r18) {
        // 0x8078C52C: sub.s       $f20, $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f6.fl;
            goto L_8078C45C;
    }
    // 0x8078C52C: sub.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x8078C530: b           L_8078C660
    // 0x8078C534: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8078C660;
    // 0x8078C534: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8078C538: lhu         $t8, 0xC($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0XC);
L_8078C53C:
    // 0x8078C53C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078C540: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8078C544: beq         $t8, $at, L_8078C65C
    if (ctx->r24 == ctx->r1) {
        // 0x8078C548: lui         $at, 0x8079
        ctx->r1 = S32(RELOC_HI16(796, 0X1B6C) << 16);
            goto L_8078C65C;
    }
    // 0x8078C548: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B6C) << 16);
    // 0x8078C54C: lwc1        $f28, -0x3304($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B6C));
L_8078C550:
    // 0x8078C550: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8078C554: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8078C558: add.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8078C55C: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8078C560: add.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8078C564: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8078C568: swc1        $f16, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f16.u32l;
    // 0x8078C56C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8078C570: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8078C574: mul.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8078C578: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8078C57C: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8078C580: nop

    // 0x8078C584: mul.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8078C588: nop

    // 0x8078C58C: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8078C590: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8078C594: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8078C598: nop

    // 0x8078C59C: mul.s       $f8, $f2, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8078C5A0: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8078C5A4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8078C5A8: sub.s       $f12, $f6, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f30.fl;
    // 0x8078C5AC: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8078C5B0: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8078C5B4: swc1        $f12, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f12.u32l;
    // 0x8078C5B8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8078C5BC: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8078C5C0: jal         0x80065954
    // 0x8078C5C4: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x8078C5C4: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8078C5C8: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8078C5CC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8078C5D0: nop

    // 0x8078C5D4: bc1f        L_8078C648
    if (!c1cs) {
        // 0x8078C5D8: nop
    
            goto L_8078C648;
    }
    // 0x8078C5D8: nop

    // 0x8078C5DC: jal         0x80065954
    // 0x8078C5E0: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x8078C5E0: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    after_7:
    // 0x8078C5E4: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8078C5E8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8078C5EC: nop

    // 0x8078C5F0: bc1f        L_8078C648
    if (!c1cs) {
        // 0x8078C5F4: nop
    
            goto L_8078C648;
    }
    // 0x8078C5F4: nop

    // 0x8078C5F8: lwc1        $f6, 0x3C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x8078C5FC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B70) << 16);
    // 0x8078C600: lwc1        $f8, -0x3300($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B70));
    // 0x8078C604: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x8078C608: lwc1        $f10, 0x40($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8078C60C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078C610: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8078C614: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
    // 0x8078C618: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x8078C61C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8078C620: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x8078C624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8078C628: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x8078C62C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8078C630: jalr        $t9
    // 0x8078C634: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8078C634: nop

    after_8:
    // 0x8078C638: jal         0x800447C8
    // 0x8078C63C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800447C8(rdram, ctx);
        goto after_9;
    // 0x8078C63C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x8078C640: b           L_8078C660
    // 0x8078C644: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8078C660;
    // 0x8078C644: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8078C648:
    // 0x8078C648: mul.s       $f18, $f28, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x8078C64C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8078C650: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8078C654: bne         $s0, $s2, L_8078C550
    if (ctx->r16 != ctx->r18) {
        // 0x8078C658: sub.s       $f20, $f20, $f18
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
            goto L_8078C550;
    }
    // 0x8078C658: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
L_8078C65C:
    // 0x8078C65C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8078C660:
    // 0x8078C660: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8078C664: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8078C668: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8078C66C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8078C670: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8078C674: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8078C678: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8078C67C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8078C680: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8078C684: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8078C688: jr          $ra
    // 0x8078C68C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8078C68C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_80666ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80666ACC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80666AD0: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80666AD4: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80666AD8: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80666ADC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80666AE0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80666AE4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80666AE8: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80666AEC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80666AF0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80666AF4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80666AF8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80666AFC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80666B00: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80666B04: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80666B08: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80666B0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80666B10: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80666B14: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x80666B18: jal         0x8004700C
    // 0x80666B1C: addiu       $s1, $a0, 0x54
    ctx->r17 = ADD32(ctx->r4, 0X54);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80666B1C: addiu       $s1, $a0, 0x54
    ctx->r17 = ADD32(ctx->r4, 0X54);
    after_0:
    // 0x80666B20: beq         $v0, $zero, L_80666CB4
    if (ctx->r2 == 0) {
        // 0x80666B24: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_80666CB4;
    }
    // 0x80666B24: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80666B28: beql        $s2, $zero, L_80666C70
    if (ctx->r18 == 0) {
        // 0x80666B2C: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_80666C70;
    }
    goto skip_0;
    // 0x80666B2C: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_0:
    // 0x80666B30: beq         $s2, $zero, L_80666C6C
    if (ctx->r18 == 0) {
        // 0x80666B34: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80666C6C;
    }
    // 0x80666B34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80666B38: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80666B3C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80666B40: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D80) << 16);
    // 0x80666B44: lwc1        $f24, 0x7A50($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D80));
    // 0x80666B48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80666B4C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80666B50: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80666B54: lui         $fp, 0x8010
    ctx->r30 = S32(0X8010 << 16);
    // 0x80666B58: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80666B5C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80666B60: addiu       $fp, $fp, -0x5508
    ctx->r30 = ADD32(ctx->r30, -0X5508);
    // 0x80666B64: addiu       $s7, $zero, 0x64
    ctx->r23 = ADD32(0, 0X64);
    // 0x80666B68: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x80666B6C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80666B70:
    // 0x80666B70: beql        $v0, $zero, L_80666C5C
    if (ctx->r2 == 0) {
        // 0x80666B74: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80666C5C;
    }
    goto skip_1;
    // 0x80666B74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80666B78: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x80666B7C: bnel        $s7, $t6, L_80666C58
    if (ctx->r23 != ctx->r14) {
        // 0x80666B80: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80666C58;
    }
    goto skip_2;
    // 0x80666B80: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_2:
    // 0x80666B84: lw          $t7, 0x1F4($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X1F4);
    // 0x80666B88: lw          $t8, 0x138($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X138);
    // 0x80666B8C: lwc1        $f0, 0x174($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X174);
    // 0x80666B90: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x80666B94: sw          $t9, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r25;
    // 0x80666B98: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80666B9C: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x80666BA0: beql        $t1, $zero, L_80666BBC
    if (ctx->r9 == 0) {
        // 0x80666BA4: c.lt.s      $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
            goto L_80666BBC;
    }
    goto skip_3;
    // 0x80666BA4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    skip_3:
    // 0x80666BA8: sub.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80666BAC: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80666BB0: b           L_80666BD8
    // 0x80666BB4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
        goto L_80666BD8;
    // 0x80666BB4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x80666BB8: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80666BBC:
    // 0x80666BBC: nop

    // 0x80666BC0: bc1fl       L_80666BD8
    if (!c1cs) {
        // 0x80666BC4: swc1        $f0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
            goto L_80666BD8;
    }
    goto skip_4;
    // 0x80666BC4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    skip_4:
    // 0x80666BC8: add.s       $f6, $f0, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x80666BCC: b           L_80666BD8
    // 0x80666BD0: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_80666BD8;
    // 0x80666BD0: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80666BD4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_80666BD8:
    // 0x80666BD8: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80666BDC: swc1        $f0, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->f0.u32l;
    // 0x80666BE0: lw          $t3, 0x138($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X138);
    // 0x80666BE4: beql        $t3, $zero, L_80666BFC
    if (ctx->r11 == 0) {
        // 0x80666BE8: lw          $t4, 0x84($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X84);
            goto L_80666BFC;
    }
    goto skip_5;
    // 0x80666BE8: lw          $t4, 0x84($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X84);
    skip_5:
    // 0x80666BEC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80666BF0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80666BF4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x80666BF8: lw          $t4, 0x84($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X84);
L_80666BFC:
    // 0x80666BFC: swc1        $f24, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f24.u32l;
    // 0x80666C00: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80666C04: sw          $t5, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r13;
    // 0x80666C08: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80666C0C: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
    // 0x80666C10: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80666C14: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x80666C18: lw          $a2, 0x38($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X38);
    // 0x80666C1C: lw          $a1, 0x34($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X34);
    // 0x80666C20: jal         0x80067D5C
    // 0x80666C24: subu        $a0, $s5, $t7
    ctx->r4 = SUB32(ctx->r21, ctx->r15);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x80666C24: subu        $a0, $s5, $t7
    ctx->r4 = SUB32(ctx->r21, ctx->r15);
    after_1:
    // 0x80666C28: addiu       $a0, $zero, 0x20A
    ctx->r4 = ADD32(0, 0X20A);
    // 0x80666C2C: jal         0x80067818
    // 0x80666C30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80666C30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80666C34: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x80666C38: sb          $t8, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r24;
    // 0x80666C3C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80666C40: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80666C44: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x80666C48: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80666C4C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80666C50: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x80666C54: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80666C58:
    // 0x80666C58: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80666C5C:
    // 0x80666C5C: beq         $s2, $zero, L_80666C6C
    if (ctx->r18 == 0) {
        // 0x80666C60: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80666C6C;
    }
    // 0x80666C60: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80666C64: bnel        $s3, $s5, L_80666B70
    if (ctx->r19 != ctx->r21) {
        // 0x80666C68: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_80666B70;
    }
    goto skip_6;
    // 0x80666C68: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_6:
L_80666C6C:
    // 0x80666C6C: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_80666C70:
    // 0x80666C70: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D84) << 16);
    // 0x80666C74: lwc1        $f4, 0x7A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D84));
    // 0x80666C78: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80666C7C: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D88) << 16);
    // 0x80666C80: lwc1        $f8, 0x7A58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D88));
    // 0x80666C84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80666C88: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80666C8C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80666C90: beq         $v0, $zero, L_80666CA4
    if (ctx->r2 == 0) {
        // 0x80666C94: swc1        $f10, 0x90($s0)
        MEM_W(0X90, ctx->r16) = ctx->f10.u32l;
            goto L_80666CA4;
    }
    // 0x80666C94: swc1        $f10, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f10.u32l;
    // 0x80666C98: lh          $t1, 0x184($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X184);
    // 0x80666C9C: bnel        $t1, $zero, L_80666CB8
    if (ctx->r9 != 0) {
        // 0x80666CA0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80666CB8;
    }
    goto skip_7;
    // 0x80666CA0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_7:
L_80666CA4:
    // 0x80666CA4: lw          $t3, 0x180($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X180);
    // 0x80666CA8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80666CAC: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x80666CB0: sw          $t2, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r10;
L_80666CB4:
    // 0x80666CB4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80666CB8:
    // 0x80666CB8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80666CBC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80666CC0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80666CC4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80666CC8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80666CCC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80666CD0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80666CD4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80666CD8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80666CDC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80666CE0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80666CE4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80666CE8: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80666CEC: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80666CF0: jr          $ra
    // 0x80666CF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80666CF4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8073F3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F3A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F3A8: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8073F3AC: jr          $ra
    // 0x8073F3B0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    return;
    // 0x8073F3B0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8002FEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FEB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FEC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FEC4: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FEC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002FECC: jal         0x8002F678
    // 0x8002FED0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FED0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FED4: beq         $v0, $zero, L_8002FEE8
    if (ctx->r2 == 0) {
        // 0x8002FED8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FEE8;
    }
    // 0x8002FED8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FEDC: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FEE0: addiu       $t6, $t6, -0x4318
    ctx->r14 = ADD32(ctx->r14, -0X4318);
    // 0x8002FEE4: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FEE8:
    // 0x8002FEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FEEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FEF0: jr          $ra
    // 0x8002FEF4: nop

    return;
    // 0x8002FEF4: nop

;}
RECOMP_FUNC void func_804255F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804255F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804255F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804255F8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804255FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80425600: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X2D50) << 16);
    // 0x80425604: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80425608: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8042560C: addiu       $t7, $t7, 0x5750
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X2D50));
    // 0x80425610: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80425614: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80425618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042561C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80425620: jal         0x80425680
    // 0x80425624: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425680(rdram, ctx);
        goto after_0;
    // 0x80425624: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80425628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042562C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80425630: jr          $ra
    // 0x80425634: nop

    return;
    // 0x80425634: nop

;}
RECOMP_FUNC void func_8001A6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A6EC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001A6F0: lw          $a1, 0x650($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X650);
    // 0x8001A6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A6FC: beq         $a1, $zero, L_8001A71C
    if (ctx->r5 == 0) {
        // 0x8001A700: nop
    
            goto L_8001A71C;
    }
    // 0x8001A700: nop

    // 0x8001A704: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
L_8001A708:
    // 0x8001A708: beq         $a0, $t6, L_8001A71C
    if (ctx->r4 == ctx->r14) {
        // 0x8001A70C: nop
    
            goto L_8001A71C;
    }
    // 0x8001A70C: nop

    // 0x8001A710: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    // 0x8001A714: bnel        $a1, $zero, L_8001A708
    if (ctx->r5 != 0) {
        // 0x8001A718: lw          $t6, 0x4($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X4);
            goto L_8001A708;
    }
    goto skip_0;
    // 0x8001A718: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    skip_0:
L_8001A71C:
    // 0x8001A71C: beql        $a1, $zero, L_8001A730
    if (ctx->r5 == 0) {
        // 0x8001A720: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001A730;
    }
    goto skip_1;
    // 0x8001A720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8001A724: jal         0x8001A64C
    // 0x8001A728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8001A64C(rdram, ctx);
        goto after_0;
    // 0x8001A728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8001A72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001A730:
    // 0x8001A730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A734: jr          $ra
    // 0x8001A738: nop

    return;
    // 0x8001A738: nop

;}
RECOMP_FUNC void func_80079448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079448: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8007944C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80079450: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80079454: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80079458: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x8007945C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x80079460: lwc1        $f2, 0x100($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80079464: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80079468: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8007946C: lwc1        $f12, 0x104($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80079470: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80079474: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80079478: abs.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = fabsf(ctx->f2.fl);
    // 0x8007947C: abs.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = fabsf(ctx->f12.fl);
    // 0x80079480: bc1f        L_800794A0
    if (!c1cs) {
        // 0x80079484: sw          $t7, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r15;
            goto L_800794A0;
    }
    // 0x80079484: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80079488: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x8007948C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80079490: subu        $t4, $t9, $t8
    ctx->r12 = SUB32(ctx->r25, ctx->r24);
    // 0x80079494: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80079498: b           L_800794A4
    // 0x8007949C: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
        goto L_800794A4;
    // 0x8007949C: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
L_800794A0:
    // 0x800794A0: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
L_800794A4:
    // 0x800794A4: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800794A8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800794AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800794B0: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x800794B4: bc1f        L_800794D0
    if (!c1cs) {
        // 0x800794B8: div.s       $f12, $f4, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
            goto L_800794D0;
    }
    // 0x800794B8: div.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800794BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800794C0: subu        $t9, $t7, $t6
    ctx->r25 = SUB32(ctx->r15, ctx->r14);
    // 0x800794C4: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x800794C8: b           L_800794D4
    // 0x800794CC: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
        goto L_800794D4;
    // 0x800794CC: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
L_800794D0:
    // 0x800794D0: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
L_800794D4:
    // 0x800794D4: jal         0x80081FE0
    // 0x800794D8: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x800794D8: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800794DC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800794E0: lui         $at, 0x3A80
    ctx->r1 = S32(0X3A80 << 16);
    // 0x800794E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800794E8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800794EC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800794F0: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800794F4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800794F8: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x800794FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80079500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80079504: nop

    // 0x80079508: div.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8007950C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80079510: jal         0x80081FE0
    // 0x80079514: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    floorf_recomp(rdram, ctx);
        goto after_1;
    // 0x80079514: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80079518: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007951C: lw          $t7, 0xF0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF0);
    // 0x80079520: lui         $at, 0x3A80
    ctx->r1 = S32(0X3A80 << 16);
    // 0x80079524: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80079528: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8007952C: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80079530: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80079534: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80079538: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007953C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80079540: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80079544: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80079548: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007954C: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x80079550: jal         0x80081FE0
    // 0x80079554: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x80079554: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    after_2:
    // 0x80079558: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x8007955C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80079560: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80079564: addiu       $t4, $t8, -0x1
    ctx->r12 = ADD32(ctx->r24, -0X1);
    // 0x80079568: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8007956C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80079570: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079574: sw          $a1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r5;
    // 0x80079578: jal         0x80081FE0
    // 0x8007957C: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007957C: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    after_3:
    // 0x80079580: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80079584: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80079588: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x8007958C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80079590: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80079594: lw          $a0, -0x7AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7AF0);
    // 0x80079598: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x8007959C: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800795A0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800795A4: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800795A8: addu        $a3, $t1, $v1
    ctx->r7 = ADD32(ctx->r9, ctx->r3);
    // 0x800795AC: addu        $t0, $t1, $t7
    ctx->r8 = ADD32(ctx->r9, ctx->r15);
    // 0x800795B0: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x800795B4: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x800795B8: sra         $a2, $a1, 1
    ctx->r6 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800795BC: lhu         $t9, 0x18($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X18);
    // 0x800795C0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800795C4: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800795C8: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x800795CC: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800795D0: bnel        $at, $zero, L_80079934
    if (ctx->r1 != 0) {
        // 0x800795D4: lw          $t9, 0xDC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XDC);
            goto L_80079934;
    }
    goto skip_0;
    // 0x800795D4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    skip_0:
    // 0x800795D8: lhu         $t8, 0x1C($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1C);
    // 0x800795DC: addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // 0x800795E0: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800795E4: beql        $at, $zero, L_80079934
    if (ctx->r1 == 0) {
        // 0x800795E8: lw          $t9, 0xDC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XDC);
            goto L_80079934;
    }
    goto skip_1;
    // 0x800795E8: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    skip_1:
    // 0x800795EC: lhu         $t4, 0x1A($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X1A);
    // 0x800795F0: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800795F4: bnel        $at, $zero, L_80079934
    if (ctx->r1 != 0) {
        // 0x800795F8: lw          $t9, 0xDC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XDC);
            goto L_80079934;
    }
    goto skip_2;
    // 0x800795F8: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    skip_2:
    // 0x800795FC: lhu         $t5, 0x1E($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X1E);
    // 0x80079600: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80079604: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x80079608: slt         $at, $a3, $t5
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007960C: beq         $at, $zero, L_80079930
    if (ctx->r1 == 0) {
        // 0x80079610: lw          $a2, 0xEC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XEC);
            goto L_80079930;
    }
    // 0x80079610: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80079614: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x80079618: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x8007961C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80079620: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80079624: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80079628: jal         0x80076DB8
    // 0x8007962C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80076DB8(rdram, ctx);
        goto after_4;
    // 0x8007962C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80079630: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80079634: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80079638: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007963C: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80079640: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    // 0x80079644: lw          $a2, 0x110($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X110);
    // 0x80079648: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x8007964C: jal         0x80076DB8
    // 0x80079650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80076DB8(rdram, ctx);
        goto after_5;
    // 0x80079650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x80079654: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x80079658: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x8007965C: lw          $t5, 0x110($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X110);
    // 0x80079660: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x80079664: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80079668: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x8007966C: lw          $a1, 0xE8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE8);
    // 0x80079670: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80079674: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x80079678: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007967C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80079680: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80079684: jal         0x80076EDC
    // 0x80079688: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    func_80076EDC(rdram, ctx);
        goto after_6;
    // 0x80079688: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_6:
    // 0x8007968C: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80079690: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x80079694: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x80079698: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x8007969C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800796A0: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x800796A4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800796A8: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x800796AC: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800796B0: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x800796B4: ori         $t7, $t7, 0xF438
    ctx->r15 = ctx->r15 | 0XF438;
    // 0x800796B8: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800796BC: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    // 0x800796C0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800796C4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800796C8: lui         $a1, 0xC18
    ctx->r5 = S32(0XC18 << 16);
    // 0x800796CC: ori         $a1, $a1, 0x41C8
    ctx->r5 = ctx->r5 | 0X41C8;
    // 0x800796D0: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x800796D4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800796D8: lui         $t4, 0x10
    ctx->r12 = S32(0X10 << 16);
    // 0x800796DC: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800796E0: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x800796E4: ori         $t4, $t4, 0x2C34
    ctx->r12 = ctx->r12 | 0X2C34;
    // 0x800796E8: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x800796EC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800796F0: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800796F4: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x800796F8: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x800796FC: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80079700: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x80079704: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80079708: sw          $a1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r5;
    // 0x8007970C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80079710: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x80079714: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x80079718: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x8007971C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80079720: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80079724: sw          $a1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r5;
    // 0x80079728: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x8007972C: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x80079730: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80079734: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80079738: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8007973C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80079740: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80079744: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80079748: blez        $v0, L_80079758
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007974C: sw          $v1, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r3;
            goto L_80079758;
    }
    // 0x8007974C: sw          $v1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r3;
    // 0x80079750: b           L_8007975C
    // 0x80079754: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8007975C;
    // 0x80079754: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80079758:
    // 0x80079758: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007975C:
    // 0x8007975C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80079760: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80079764: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80079768: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8007976C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80079770: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80079774: blez        $a0, L_80079784
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80079778: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_80079784;
    }
    // 0x80079778: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007977C: b           L_80079788
    // 0x80079780: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80079788;
    // 0x80079780: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80079784:
    // 0x80079784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079788:
    // 0x80079788: andi        $t5, $v0, 0xFFF
    ctx->r13 = ctx->r2 & 0XFFF;
    // 0x8007978C: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80079790: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80079794: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80079798: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8007979C: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x800797A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800797A4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800797A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800797AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800797B0: blez        $a0, L_800797C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800797B4: sll         $a3, $a3, 2
        ctx->r7 = S32(ctx->r7 << 2);
            goto L_800797C0;
    }
    // 0x800797B4: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x800797B8: b           L_800797C0
    // 0x800797BC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800797C0;
    // 0x800797BC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800797C0:
    // 0x800797C0: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x800797C4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800797C8: blez        $a1, L_800797D8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800797CC: andi        $t5, $v1, 0xFFF
        ctx->r13 = ctx->r3 & 0XFFF;
            goto L_800797D8;
    }
    // 0x800797CC: andi        $t5, $v1, 0xFFF
    ctx->r13 = ctx->r3 & 0XFFF;
    // 0x800797D0: b           L_800797DC
    // 0x800797D4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800797DC;
    // 0x800797D4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800797D8:
    // 0x800797D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800797DC:
    // 0x800797DC: andi        $t4, $v0, 0xFFF
    ctx->r12 = ctx->r2 & 0XFFF;
    // 0x800797E0: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x800797E4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800797E8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800797EC: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800797F0: lui         $t5, 0xB400
    ctx->r13 = S32(0XB400 << 16);
    // 0x800797F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800797F8: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800797FC: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80079800: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80079804: bgez        $a0, L_8007986C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80079808: lw          $t4, 0xA4($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA4);
            goto L_8007986C;
    }
    // 0x80079808: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x8007980C: lh          $v1, 0xB2($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XB2);
    // 0x80079810: bgez        $v1, L_80079840
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80079814: nop
    
            goto L_80079840;
    }
    // 0x80079814: nop

    // 0x80079818: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007981C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80079820: mflo        $v0
    ctx->r2 = lo;
    // 0x80079824: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079828: blez        $v0, L_80079838
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007982C: nop
    
            goto L_80079838;
    }
    // 0x8007982C: nop

    // 0x80079830: b           L_8007986C
    // 0x80079834: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8007986C;
    // 0x80079834: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80079838:
    // 0x80079838: b           L_8007986C
    // 0x8007983C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_8007986C;
    // 0x8007983C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80079840:
    // 0x80079840: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079844: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80079848: mflo        $v0
    ctx->r2 = lo;
    // 0x8007984C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079850: bgez        $v0, L_80079860
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80079854: nop
    
            goto L_80079860;
    }
    // 0x80079854: nop

    // 0x80079858: b           L_80079860
    // 0x8007985C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80079860;
    // 0x8007985C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80079860:
    // 0x80079860: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80079864: b           L_8007986C
    // 0x80079868: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8007986C;
    // 0x80079868: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8007986C:
    // 0x8007986C: bgez        $a3, L_800798D4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80079870: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_800798D4;
    }
    // 0x80079870: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80079874: lh          $v1, 0xAE($sp)
    ctx->r3 = MEM_H(ctx->r29, 0XAE);
    // 0x80079878: bgez        $v1, L_800798A8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007987C: nop
    
            goto L_800798A8;
    }
    // 0x8007987C: nop

    // 0x80079880: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80079888: mflo        $v0
    ctx->r2 = lo;
    // 0x8007988C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80079890: blez        $v0, L_800798A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80079894: nop
    
            goto L_800798A0;
    }
    // 0x80079894: nop

    // 0x80079898: b           L_800798DC
    // 0x8007989C: subu        $t6, $t4, $v0
    ctx->r14 = SUB32(ctx->r12, ctx->r2);
        goto L_800798DC;
    // 0x8007989C: subu        $t6, $t4, $v0
    ctx->r14 = SUB32(ctx->r12, ctx->r2);
L_800798A0:
    // 0x800798A0: b           L_800798D8
    // 0x800798A4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800798D8;
    // 0x800798A4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800798A8:
    // 0x800798A8: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800798AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800798B0: mflo        $v0
    ctx->r2 = lo;
    // 0x800798B4: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800798B8: bgez        $v0, L_800798C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800798BC: nop
    
            goto L_800798C8;
    }
    // 0x800798BC: nop

    // 0x800798C0: b           L_800798C8
    // 0x800798C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800798C8;
    // 0x800798C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800798C8:
    // 0x800798C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800798CC: b           L_800798D8
    // 0x800798D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800798D8;
    // 0x800798D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800798D4:
    // 0x800798D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800798D8:
    // 0x800798D8: subu        $t6, $t4, $v0
    ctx->r14 = SUB32(ctx->r12, ctx->r2);
L_800798DC:
    // 0x800798DC: subu        $t5, $t9, $a2
    ctx->r13 = SUB32(ctx->r25, ctx->r6);
    // 0x800798E0: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x800798E4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800798E8: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x800798EC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800798F0: lw          $v1, 0xDC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XDC);
    // 0x800798F4: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x800798F8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800798FC: sw          $t8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r24;
    // 0x80079900: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80079904: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80079908: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x8007990C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x80079910: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80079914: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x80079918: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8007991C: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x80079920: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x80079924: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    // 0x80079928: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007992C: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_80079930:
    // 0x80079930: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
L_80079934:
    // 0x80079934: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80079938: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8007993C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80079940: jr          $ra
    // 0x80079944: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80079944: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80025854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025854: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80025858: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002585C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80025860: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80025864: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80025868: sb          $t7, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r15;
    // 0x8002586C: lw          $t9, 0xA0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA0);
    // 0x80025870: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80025874: lui         $t3, 0x8002
    ctx->r11 = S32(0X8002 << 16);
    // 0x80025878: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002587C: lw          $t0, 0xA0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA0);
    // 0x80025880: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x80025884: addiu       $t3, $t3, 0x57EC
    ctx->r11 = ADD32(ctx->r11, 0X57EC);
    // 0x80025888: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8002588C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80025890: jr          $ra
    // 0x80025894: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    return;
    // 0x80025894: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_80519F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519F88: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80519F8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80519F90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80519F94: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x80519F98: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x80519F9C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80519FA0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80519FA4: jal         0x80047090
    // 0x80519FA8: addiu       $a0, $zero, 0x4144
    ctx->r4 = ADD32(0, 0X4144);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80519FA8: addiu       $a0, $zero, 0x4144
    ctx->r4 = ADD32(0, 0X4144);
    after_0:
    // 0x80519FAC: lui         $at, 0x4144
    ctx->r1 = S32(0X4144 << 16);
    // 0x80519FB0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x80519FB4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80519FB8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80519FBC: jal         0x8004613C
    // 0x80519FC0: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80519FC0: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x80519FC4: beq         $v0, $zero, L_8051A0A0
    if (ctx->r2 == 0) {
        // 0x80519FC8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8051A0A0;
    }
    // 0x80519FC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80519FCC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80519FD0: addiu       $t6, $t6, -0x71F4
    ctx->r14 = ADD32(ctx->r14, -0X71F4);
    // 0x80519FD4: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80519FD8: jal         0x80517E78
    // 0x80519FDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80517E78(rdram, ctx);
        goto after_2;
    // 0x80519FDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80519FE0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80519FE4: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(291, 0X25E8) << 16);
    // 0x80519FE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80519FEC: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80519FF0: lbu         $t7, -0x5DA8($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(291, 0X25E8));
    // 0x80519FF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80519FF8: bne         $v0, $zero, L_8051A090
    if (ctx->r2 != 0) {
        // 0x80519FFC: sb          $t7, 0x30($s0)
        MEM_B(0X30, ctx->r16) = ctx->r15;
            goto L_8051A090;
    }
    // 0x80519FFC: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8051A000: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8051A004: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2604) << 16);
    // 0x8051A008: lwc1        $f10, -0x5D8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2604));
    // 0x8051A00C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8051A010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051A014: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8051A018: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8051A01C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8051A020: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8051A024: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8051A028: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8051A02C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8051A030: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8051A034: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8051A038: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8051A03C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8051A040: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8051A044: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8051A048: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8051A04C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8051A050: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8051A054: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8051A058: lw          $t9, 0x10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X10);
    // 0x8051A05C: jalr        $t9
    // 0x8051A060: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8051A060: nop

    after_3:
    // 0x8051A064: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8051A068: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    // 0x8051A06C: jal         0x80067BBC
    // 0x8051A070: lw          $a1, 0x38($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8051A070: lw          $a1, 0x38($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X38);
    after_4:
    // 0x8051A074: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x8051A078: jal         0x80067818
    // 0x8051A07C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8051A07C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8051A080: jal         0x80044194
    // 0x8051A084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_6;
    // 0x8051A084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8051A088: b           L_8051A0A4
    // 0x8051A08C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8051A0A4;
    // 0x8051A08C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8051A090:
    // 0x8051A090: jal         0x80047F9C
    // 0x8051A094: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x8051A094: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_7:
    // 0x8051A098: jal         0x8005FCA8
    // 0x8051A09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_8;
    // 0x8051A09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8051A0A0:
    // 0x8051A0A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8051A0A4:
    // 0x8051A0A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8051A0A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051A0AC: jr          $ra
    // 0x8051A0B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8051A0B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8051A0B4: nop

    // 0x8051A0B8: nop

    // 0x8051A0BC: nop

;}
RECOMP_FUNC void func_80518CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518CC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80518CCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80518CD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80518CD4: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x80518CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80518CDC: slti        $at, $v1, 0x28
    ctx->r1 = SIGNED(ctx->r3) < 0X28 ? 1 : 0;
    // 0x80518CE0: beq         $at, $zero, L_80518D10
    if (ctx->r1 == 0) {
        // 0x80518CE4: addiu       $t1, $v1, -0x28
        ctx->r9 = ADD32(ctx->r3, -0X28);
            goto L_80518D10;
    }
    // 0x80518CE4: addiu       $t1, $v1, -0x28
    ctx->r9 = ADD32(ctx->r3, -0X28);
    // 0x80518CE8: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80518CEC: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x80518CF0: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80518CF4: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x80518CF8: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80518CFC: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    // 0x80518D00: jal         0x8004590C
    // 0x80518D04: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x80518D04: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    after_0:
    // 0x80518D08: b           L_80518D58
    // 0x80518D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80518D58;
    // 0x80518D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80518D10:
    // 0x80518D10: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80518D14: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80518D18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80518D1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80518D20: lw          $t0, 0x168($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X168);
    // 0x80518D24: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x80518D28: lw          $v0, 0x88($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X88);
    // 0x80518D2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80518D30: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80518D34: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    // 0x80518D38: addiu       $a2, $v0, 0x400
    ctx->r6 = ADD32(ctx->r2, 0X400);
    // 0x80518D3C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80518D40: jal         0x8051830C
    // 0x80518D44: nop

    func_8051830C(rdram, ctx);
        goto after_1;
    // 0x80518D44: nop

    after_1:
    // 0x80518D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80518D4C: jal         0x8004590C
    // 0x80518D50: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x80518D50: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80518D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80518D58:
    // 0x80518D58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80518D5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80518D60: jr          $ra
    // 0x80518D64: nop

    return;
    // 0x80518D64: nop

;}
RECOMP_FUNC void func_805D2090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D2094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2098: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D209C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805D20A0: jal         0x80047090
    // 0x805D20A4: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805D20A4: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x805D20A8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D20AC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x805D20B0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x805D20B4: lw          $a3, 0x8C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8C);
    // 0x805D20B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x805D20BC: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x805D20C0: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x805D20C4: jal         0x8004613C
    // 0x805D20C8: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805D20C8: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    after_1:
    // 0x805D20CC: bne         $v0, $zero, L_805D20DC
    if (ctx->r2 != 0) {
        // 0x805D20D0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805D20DC;
    }
    // 0x805D20D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D20D4: b           L_805D2100
    // 0x805D20D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D2100;
    // 0x805D20D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D20DC:
    // 0x805D20DC: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x805D20E0: lhu         $t9, 0xE($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XE);
    // 0x805D20E4: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x805D20E8: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805D20EC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805D20F0: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    // 0x805D20F4: jal         0x80044194
    // 0x805D20F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D20F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x805D20FC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_805D2100:
    // 0x805D2100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D2104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D2108: jr          $ra
    // 0x805D210C: nop

    return;
    // 0x805D210C: nop

;}
RECOMP_FUNC void func_8003D840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D848: lw          $v0, 0x15C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X15C);
    // 0x8003D84C: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x8003D850: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8003D854: lh          $t7, 0x10($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10);
    // 0x8003D858: bne         $t7, $zero, L_8003D86C
    if (ctx->r15 != 0) {
        // 0x8003D85C: nop
    
            goto L_8003D86C;
    }
    // 0x8003D85C: nop

    // 0x8003D860: lw          $t8, 0xF0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XF0);
    // 0x8003D864: beql        $t8, $zero, L_8003D878
    if (ctx->r24 == 0) {
        // 0x8003D868: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D878;
    }
    goto skip_0;
    // 0x8003D868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8003D86C:
    // 0x8003D86C: jal         0x8003D76C
    // 0x8003D870: nop

    func_8003D76C(rdram, ctx);
        goto after_0;
    // 0x8003D870: nop

    after_0:
    // 0x8003D874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D878:
    // 0x8003D878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D87C: jr          $ra
    // 0x8003D880: nop

    return;
    // 0x8003D880: nop

;}
RECOMP_FUNC void func_807C4CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C4CD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807C4CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C4CD8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C4CDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807C4CE0: jal         0x8004700C
    // 0x807C4CE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807C4CE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x807C4CE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807C4CEC: jal         0x807C49D0
    // 0x807C4CF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807C49D0(rdram, ctx);
        goto after_1;
    // 0x807C4CF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x807C4CF4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x807C4CF8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C4CFC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C4D00: beql        $t6, $zero, L_807C5074
    if (ctx->r14 == 0) {
        // 0x807C4D04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C5074;
    }
    goto skip_0;
    // 0x807C4D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807C4D08: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x807C4D0C: beq         $v0, $zero, L_807C4D1C
    if (ctx->r2 == 0) {
        // 0x807C4D10: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_807C4D1C;
    }
    // 0x807C4D10: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x807C4D14: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x807C4D18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_807C4D1C:
    // 0x807C4D1C: bnel        $v0, $zero, L_807C4F28
    if (ctx->r2 != 0) {
        // 0x807C4D20: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_807C4F28;
    }
    goto skip_1;
    // 0x807C4D20: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_1:
    // 0x807C4D24: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x807C4D28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x807C4D2C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x807C4D30: beql        $v0, $zero, L_807C4D54
    if (ctx->r2 == 0) {
        // 0x807C4D34: lw          $v0, 0x18($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18);
            goto L_807C4D54;
    }
    goto skip_2;
    // 0x807C4D34: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    skip_2:
    // 0x807C4D38: beq         $v0, $a0, L_807C4DF8
    if (ctx->r2 == ctx->r4) {
        // 0x807C4D3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_807C4DF8;
    }
    // 0x807C4D3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807C4D40: beql        $v0, $at, L_807C4EF8
    if (ctx->r2 == ctx->r1) {
        // 0x807C4D44: lw          $v0, 0x18($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18);
            goto L_807C4EF8;
    }
    goto skip_3;
    // 0x807C4D44: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    skip_3:
    // 0x807C4D48: b           L_807C4F28
    // 0x807C4D4C: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
        goto L_807C4F28;
    // 0x807C4D4C: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x807C4D50: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
L_807C4D54:
    // 0x807C4D54: lui         $t0, 0x807C
    ctx->r8 = S32(RELOC_HI16(910, 0XEE8) << 16);
    // 0x807C4D58: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x807C4D5C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x807C4D60: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x807C4D64: lw          $t0, 0x58A8($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(910, 0XEE8));
    // 0x807C4D68: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x807C4D6C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x807C4D70: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x807C4D74: bne         $at, $zero, L_807C4F24
    if (ctx->r1 != 0) {
        // 0x807C4D78: sw          $t0, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r8;
            goto L_807C4F24;
    }
    // 0x807C4D78: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
    // 0x807C4D7C: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x807C4D80: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x807C4D84: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x807C4D88: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x807C4D8C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x807C4D90: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x807C4D94: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x807C4D98: jal         0x80067BBC
    // 0x807C4D9C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x807C4D9C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x807C4DA0: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    // 0x807C4DA4: jal         0x80067818
    // 0x807C4DA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807C4DA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x807C4DAC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C4DB0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C4DB4: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x807C4DB8: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x807C4DBC: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x807C4DC0: bnel        $at, $zero, L_807C4F28
    if (ctx->r1 != 0) {
        // 0x807C4DC4: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_807C4F28;
    }
    goto skip_4;
    // 0x807C4DC4: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_4:
    // 0x807C4DC8: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x807C4DCC: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x807C4DD0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x807C4DD4: jal         0x800653D8
    // 0x807C4DD8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x807C4DD8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x807C4DDC: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x807C4DE0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C4DE4: bne         $t7, $zero, L_807C4F24
    if (ctx->r15 != 0) {
        // 0x807C4DE8: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_807C4F24;
    }
    // 0x807C4DE8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C4DEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x807C4DF0: b           L_807C4F24
    // 0x807C4DF4: sw          $a0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r4;
        goto L_807C4F24;
    // 0x807C4DF4: sw          $a0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r4;
L_807C4DF8:
    // 0x807C4DF8: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x807C4DFC: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(910, 0X1040) << 16);
    // 0x807C4E00: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(910, 0XF40) << 16);
    // 0x807C4E04: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x807C4E08: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x807C4E0C: lw          $t8, 0x5A00($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(910, 0X1040));
    // 0x807C4E10: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x807C4E14: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x807C4E18: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x807C4E1C: lw          $t9, 0x5900($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(910, 0XF40));
    // 0x807C4E20: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x807C4E24: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
    // 0x807C4E28: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x807C4E2C: bne         $t1, $zero, L_807C4E60
    if (ctx->r9 != 0) {
        // 0x807C4E30: sw          $t9, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r25;
            goto L_807C4E60;
    }
    // 0x807C4E30: sw          $t9, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r25;
    // 0x807C4E34: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x807C4E38: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x807C4E3C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x807C4E40: jal         0x80067BBC
    // 0x807C4E44: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x807C4E44: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_5:
    // 0x807C4E48: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x807C4E4C: jal         0x80067818
    // 0x807C4E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x807C4E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x807C4E54: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C4E58: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C4E5C: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
L_807C4E60:
    // 0x807C4E60: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x807C4E64: bnel        $at, $zero, L_807C4F28
    if (ctx->r1 != 0) {
        // 0x807C4E68: lw          $v0, 0x28($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X28);
            goto L_807C4F28;
    }
    goto skip_5;
    // 0x807C4E68: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    skip_5:
    // 0x807C4E6C: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x807C4E70: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x807C4E74: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x807C4E78: blez        $t3, L_807C4F24
    if (SIGNED(ctx->r11) <= 0) {
        // 0x807C4E7C: sw          $t3, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r11;
            goto L_807C4F24;
    }
    // 0x807C4E7C: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x807C4E80: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x807C4E84: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x807C4E88: jal         0x800653D8
    // 0x807C4E8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x807C4E8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x807C4E90: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x807C4E94: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C4E98: bne         $t5, $zero, L_807C4F24
    if (ctx->r13 != 0) {
        // 0x807C4E9C: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_807C4F24;
    }
    // 0x807C4E9C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C4EA0: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x807C4EA4: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(910, 0XEF8) << 16);
    // 0x807C4EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807C4EAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807C4EB0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807C4EB4: lw          $t8, 0x58B8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(910, 0XEF8));
    // 0x807C4EB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807C4EBC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x807C4EC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C4EC4: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x807C4EC8: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x807C4ECC: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x807C4ED0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(910, 0X1340) << 16);
    // 0x807C4ED4: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x807C4ED8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x807C4EDC: lwc1        $f8, 0x5D00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(910, 0X1340));
    // 0x807C4EE0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807C4EE4: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x807C4EE8: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x807C4EEC: b           L_807C4F24
    // 0x807C4EF0: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
        goto L_807C4F24;
    // 0x807C4EF0: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x807C4EF4: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
L_807C4EF8:
    // 0x807C4EF8: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(910, 0XEF8) << 16);
    // 0x807C4EFC: sw          $a0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r4;
    // 0x807C4F00: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x807C4F04: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C4F08: lw          $t1, 0x58B8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(910, 0XEF8));
    // 0x807C4F0C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x807C4F10: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x807C4F14: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x807C4F18: bne         $at, $zero, L_807C4F24
    if (ctx->r1 != 0) {
        // 0x807C4F1C: sw          $t1, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r9;
            goto L_807C4F24;
    }
    // 0x807C4F1C: sw          $t1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r9;
    // 0x807C4F20: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
L_807C4F24:
    // 0x807C4F24: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
L_807C4F28:
    // 0x807C4F28: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x807C4F2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C4F30: beq         $v0, $zero, L_807C4F3C
    if (ctx->r2 == 0) {
        // 0x807C4F34: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_807C4F3C;
    }
    // 0x807C4F34: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x807C4F38: sw          $t4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r12;
L_807C4F3C:
    // 0x807C4F3C: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x807C4F40: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x807C4F44: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x807C4F48: nop

    // 0x807C4F4C: bc1fl       L_807C4FAC
    if (!c1cs) {
        // 0x807C4F50: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_807C4FAC;
    }
    goto skip_6;
    // 0x807C4F50: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_6:
    // 0x807C4F54: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x807C4F58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807C4F5C: bnel        $t5, $at, L_807C4FAC
    if (ctx->r13 != ctx->r1) {
        // 0x807C4F60: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_807C4FAC;
    }
    goto skip_7;
    // 0x807C4F60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_7:
    // 0x807C4F64: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x807C4F68: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x807C4F6C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x807C4F70: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x807C4F74: nop

    // 0x807C4F78: bc1fl       L_807C4FAC
    if (!c1cs) {
        // 0x807C4F7C: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_807C4FAC;
    }
    goto skip_8;
    // 0x807C4F7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_8:
    // 0x807C4F80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x807C4F84: swc1        $f0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f0.u32l;
    // 0x807C4F88: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(910, 0XEF8) << 16);
    // 0x807C4F8C: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x807C4F90: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x807C4F94: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x807C4F98: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x807C4F9C: lw          $t7, 0x58B8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(910, 0XEF8));
    // 0x807C4FA0: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x807C4FA4: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x807C4FA8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_807C4FAC:
    // 0x807C4FAC: jal         0x80048F84
    // 0x807C4FB0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_8;
    // 0x807C4FB0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_8:
    // 0x807C4FB4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C4FB8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x807C4FBC: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x807C4FC0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x807C4FC4: beql        $at, $zero, L_807C5074
    if (ctx->r1 == 0) {
        // 0x807C4FC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C5074;
    }
    goto skip_9;
    // 0x807C4FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x807C4FCC: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x807C4FD0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x807C4FD4: beql        $t9, $zero, L_807C5034
    if (ctx->r25 == 0) {
        // 0x807C4FD8: lwc1        $f8, 0x3C($a3)
        ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
            goto L_807C5034;
    }
    goto skip_10;
    // 0x807C4FD8: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
    skip_10:
    // 0x807C4FDC: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    // 0x807C4FE0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x807C4FE4: bnel        $t0, $zero, L_807C5074
    if (ctx->r8 != 0) {
        // 0x807C4FE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C5074;
    }
    goto skip_11;
    // 0x807C4FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x807C4FEC: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x807C4FF0: lwc1        $f6, 0x84($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X84);
    // 0x807C4FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807C4FF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C4FFC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807C5000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C5004: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807C5008: bc1fl       L_807C5018
    if (!c1cs) {
        // 0x807C500C: lw          $t2, 0x138($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X138);
            goto L_807C5018;
    }
    goto skip_12;
    // 0x807C500C: lw          $t2, 0x138($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X138);
    skip_12:
    // 0x807C5010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C5014: lw          $t2, 0x138($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X138);
L_807C5018:
    // 0x807C5018: beql        $v0, $t2, L_807C5074
    if (ctx->r2 == ctx->r10) {
        // 0x807C501C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C5074;
    }
    goto skip_13;
    // 0x807C501C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_13:
    // 0x807C5020: jal         0x807C5464
    // 0x807C5024: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    func_807C5464(rdram, ctx);
        goto after_9;
    // 0x807C5024: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    after_9:
    // 0x807C5028: b           L_807C5074
    // 0x807C502C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C5074;
    // 0x807C502C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C5030: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
L_807C5034:
    // 0x807C5034: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807C5038: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x807C503C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C5040: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807C5044: lwc1        $f18, 0x84($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X84);
    // 0x807C5048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C504C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807C5050: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x807C5054: nop

    // 0x807C5058: bc1fl       L_807C5074
    if (!c1cs) {
        // 0x807C505C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C5074;
    }
    goto skip_14;
    // 0x807C505C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_14:
    // 0x807C5060: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x807C5064: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x807C5068: jal         0x807C5464
    // 0x807C506C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    func_807C5464(rdram, ctx);
        goto after_10;
    // 0x807C506C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    after_10:
    // 0x807C5070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C5074:
    // 0x807C5074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807C5078: jr          $ra
    // 0x807C507C: nop

    return;
    // 0x807C507C: nop

;}
RECOMP_FUNC void func_80675098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675098: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067509C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806750A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x806750A4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806750A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806750AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806750B0: lhu         $a1, 0xC($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0XC);
    // 0x806750B4: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(532, 0X638) << 16);
    // 0x806750B8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x806750BC: xori        $a1, $a1, 0x4083
    ctx->r5 = ctx->r5 ^ 0X4083;
    // 0x806750C0: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x806750C4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806750C8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x806750CC: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x806750D0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x806750D4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x806750D8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x806750DC: lwc1        $f20, 0x3C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806750E0: lwc1        $f22, 0x40($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806750E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x806750E8: addiu       $t9, $t9, 0x5588
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(532, 0X638));
    // 0x806750EC: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x806750F0: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    // 0x806750F4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x806750F8: jal         0x800538BC
    // 0x806750FC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800538BC(rdram, ctx);
        goto after_0;
    // 0x806750FC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_0:
    // 0x80675100: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80675104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80675108: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8067510C: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x80675110: jal         0x800538BC
    // 0x80675114: sub.s       $f14, $f22, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f4.fl;
    func_800538BC(rdram, ctx);
        goto after_1;
    // 0x80675114: sub.s       $f14, $f22, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f22.fl - ctx->f4.fl;
    after_1:
    // 0x80675118: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8067511C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80675120: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80675124: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    // 0x80675128: jal         0x800538BC
    // 0x8067512C: add.s       $f14, $f22, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f22.fl + ctx->f6.fl;
    func_800538BC(rdram, ctx);
        goto after_2;
    // 0x8067512C: add.s       $f14, $f22, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f22.fl + ctx->f6.fl;
    after_2:
    // 0x80675130: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80675134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80675138: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8067513C: lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6);
    // 0x80675140: jal         0x800538BC
    // 0x80675144: sub.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f8.fl;
    func_800538BC(rdram, ctx);
        goto after_3;
    // 0x80675144: sub.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f8.fl;
    after_3:
    // 0x80675148: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8067514C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80675150: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80675154: lhu         $a2, 0x8($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X8);
    // 0x80675158: jal         0x800538BC
    // 0x8067515C: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
    func_800538BC(rdram, ctx);
        goto after_4;
    // 0x8067515C: add.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f10.fl;
    after_4:
    // 0x80675160: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80675164: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80675168: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8067516C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80675170: jr          $ra
    // 0x80675174: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80675174: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80583E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80583E84: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80583E88: beql        $at, $zero, L_80583E9C
    if (ctx->r1 == 0) {
        // 0x80583E8C: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80583E9C;
    }
    goto skip_0;
    // 0x80583E8C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80583E90: jr          $ra
    // 0x80583E94: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    return;
    // 0x80583E94: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80583E98: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80583E9C:
    // 0x80583E9C: beq         $at, $zero, L_80583ED8
    if (ctx->r1 == 0) {
        // 0x80583EA0: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_80583ED8;
    }
    // 0x80583EA0: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x80583EA4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80583EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583EAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80583EB0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80583EB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80583EB8: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x80583EBC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80583EC0: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80583EC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80583EC8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80583ECC: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80583ED0: jr          $ra
    // 0x80583ED4: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x80583ED4: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_80583ED8:
    // 0x80583ED8: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80583EDC: beq         $at, $zero, L_80583EF4
    if (ctx->r1 == 0) {
        // 0x80583EE0: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_80583EF4;
    }
    // 0x80583EE0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80583EE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583EE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80583EEC: jr          $ra
    // 0x80583EF0: nop

    return;
    // 0x80583EF0: nop

L_80583EF4:
    // 0x80583EF4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80583EF8: beq         $at, $zero, L_80583F38
    if (ctx->r1 == 0) {
        // 0x80583EFC: lw          $v1, 0x14($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X14);
            goto L_80583F38;
    }
    // 0x80583EFC: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x80583F00: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x80583F04: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80583F08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583F0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80583F10: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80583F14: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80583F18: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80583F1C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80583F20: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80583F24: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80583F28: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80583F2C: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80583F30: jr          $ra
    // 0x80583F34: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    return;
    // 0x80583F34: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
L_80583F38:
    // 0x80583F38: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80583F3C: beq         $at, $zero, L_80583F74
    if (ctx->r1 == 0) {
        // 0x80583F40: subu        $t0, $a0, $v0
        ctx->r8 = SUB32(ctx->r4, ctx->r2);
            goto L_80583F74;
    }
    // 0x80583F40: subu        $t0, $a0, $v0
    ctx->r8 = SUB32(ctx->r4, ctx->r2);
    // 0x80583F44: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80583F48: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80583F4C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80583F50: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80583F54: subu        $t1, $v1, $v0
    ctx->r9 = SUB32(ctx->r3, ctx->r2);
    // 0x80583F58: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80583F5C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80583F60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80583F64: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80583F68: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80583F6C: jr          $ra
    // 0x80583F70: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
    return;
    // 0x80583F70: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
L_80583F74:
    // 0x80583F74: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80583F78: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80583F7C: subu        $t2, $a0, $v1
    ctx->r10 = SUB32(ctx->r4, ctx->r3);
    // 0x80583F80: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80583F84: beq         $at, $zero, L_80583FBC
    if (ctx->r1 == 0) {
        // 0x80583F88: nop
    
            goto L_80583FBC;
    }
    // 0x80583F88: nop

    // 0x80583F8C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80583F90: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80583F94: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80583F98: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80583F9C: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x80583FA0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80583FA4: sub.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80583FA8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80583FAC: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80583FB0: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80583FB4: jr          $ra
    // 0x80583FB8: sub.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f6.fl;
    return;
    // 0x80583FB8: sub.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f6.fl;
L_80583FBC:
    // 0x80583FBC: jr          $ra
    // 0x80583FC0: nop

    return;
    // 0x80583FC0: nop

;}
RECOMP_FUNC void func_80568C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568C3C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568C40: addiu       $at, $zero, 0x4154
    ctx->r1 = ADD32(0, 0X4154);
    // 0x80568C44: beq         $v0, $at, L_80568C64
    if (ctx->r2 == ctx->r1) {
        // 0x80568C48: addiu       $at, $zero, 0x4160
        ctx->r1 = ADD32(0, 0X4160);
            goto L_80568C64;
    }
    // 0x80568C48: addiu       $at, $zero, 0x4160
    ctx->r1 = ADD32(0, 0X4160);
    // 0x80568C4C: beq         $v0, $at, L_80568C74
    if (ctx->r2 == ctx->r1) {
        // 0x80568C50: addiu       $at, $zero, 0x416C
        ctx->r1 = ADD32(0, 0X416C);
            goto L_80568C74;
    }
    // 0x80568C50: addiu       $at, $zero, 0x416C
    ctx->r1 = ADD32(0, 0X416C);
    // 0x80568C54: beql        $v0, $at, L_80568C88
    if (ctx->r2 == ctx->r1) {
        // 0x80568C58: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568C88;
    }
    goto skip_0;
    // 0x80568C58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568C5C: b           L_80568C94
    // 0x80568C60: nop

        goto L_80568C94;
    // 0x80568C60: nop

L_80568C64:
    // 0x80568C64: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568C68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568C6C: b           L_80568C94
    // 0x80568C70: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
        goto L_80568C94;
    // 0x80568C70: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
L_80568C74:
    // 0x80568C74: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21EC) << 16);
    // 0x80568C78: lwc1        $f6, -0x6864($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21EC));
    // 0x80568C7C: b           L_80568C94
    // 0x80568C80: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
        goto L_80568C94;
    // 0x80568C80: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80568C84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568C88:
    // 0x80568C88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568C8C: nop

    // 0x80568C90: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80568C94:
    // 0x80568C94: jal         0x80568710
    // 0x80568C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568C98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568C9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568CA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80568CA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568CA8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568CAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80568CB0: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x80568CB4: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568CB8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568CBC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568CC0: jal         0x80569310
    // 0x80568CC4: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80568CC4: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80568CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568CD0: jr          $ra
    // 0x80568CD4: nop

    return;
    // 0x80568CD4: nop

;}
RECOMP_FUNC void func_8006E2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E2E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E2E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E2E8: jal         0x8006E2B0
    // 0x8006E2EC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    func_8006E2B0(rdram, ctx);
        goto after_0;
    // 0x8006E2EC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    after_0:
    // 0x8006E2F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E2F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E2F8: jr          $ra
    // 0x8006E2FC: nop

    return;
    // 0x8006E2FC: nop

;}
RECOMP_FUNC void func_80682A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80682A90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682A94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80682A98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80682A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80682AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80682AA4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80682AA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80682AAC: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80682AB0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80682AB4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80682AB8: jal         0x8068293C
    // 0x80682ABC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8068293C(rdram, ctx);
        goto after_0;
    // 0x80682ABC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80682AC0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80682AC4: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80682AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80682ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80682AD0: jr          $ra
    // 0x80682AD4: nop

    return;
    // 0x80682AD4: nop

;}
RECOMP_FUNC void func_805DC390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC390: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DC394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DC398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DC39C: jal         0x8004700C
    // 0x805DC3A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805DC3A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805DC3A4: beq         $v0, $zero, L_805DC3F0
    if (ctx->r2 == 0) {
        // 0x805DC3A8: lw          $v1, 0x1F4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1F4);
            goto L_805DC3F0;
    }
    // 0x805DC3A8: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x805DC3AC: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805DC3B0: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805DC3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC3B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC3BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805DC3C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805DC3C4: bc1fl       L_805DC3E0
    if (!c1cs) {
        // 0x805DC3C8: lhu         $t8, 0x74($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X74);
            goto L_805DC3E0;
    }
    goto skip_0;
    // 0x805DC3C8: lhu         $t8, 0x74($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X74);
    skip_0:
    // 0x805DC3CC: lhu         $t6, 0x74($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X74);
    // 0x805DC3D0: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x805DC3D4: b           L_805DC3E8
    // 0x805DC3D8: sh          $t7, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r15;
        goto L_805DC3E8;
    // 0x805DC3D8: sh          $t7, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r15;
    // 0x805DC3DC: lhu         $t8, 0x74($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X74);
L_805DC3E0:
    // 0x805DC3E0: andi        $t9, $t8, 0xFFFD
    ctx->r25 = ctx->r24 & 0XFFFD;
    // 0x805DC3E4: sh          $t9, 0x74($v1)
    MEM_H(0X74, ctx->r3) = ctx->r25;
L_805DC3E8:
    // 0x805DC3E8: jal         0x805DD234
    // 0x805DC3EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805DD234(rdram, ctx);
        goto after_1;
    // 0x805DC3EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_805DC3F0:
    // 0x805DC3F0: jal         0x805DC2A0
    // 0x805DC3F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DC2A0(rdram, ctx);
        goto after_2;
    // 0x805DC3F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805DC3F8: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x805DC3FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DC404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DC408: jr          $ra
    // 0x805DC40C: nop

    return;
    // 0x805DC40C: nop

;}
RECOMP_FUNC void func_80046E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046E64: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80046E68: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80046E6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80046E70: bne         $t6, $t7, L_80046E80
    if (ctx->r14 != ctx->r15) {
        // 0x80046E74: nop
    
            goto L_80046E80;
    }
    // 0x80046E74: nop

    // 0x80046E78: jr          $ra
    // 0x80046E7C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80046E7C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80046E80:
    // 0x80046E80: jr          $ra
    // 0x80046E84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80046E84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80011C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011C44: jal         0x8001AF80
    // 0x80011C48: nop

    func_8001AF80(rdram, ctx);
        goto after_0;
    // 0x80011C48: nop

    after_0:
    // 0x80011C4C: jal         0x80011A1C
    // 0x80011C50: nop

    func_80011A1C(rdram, ctx);
        goto after_1;
    // 0x80011C50: nop

    after_1:
    // 0x80011C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011C5C: jr          $ra
    // 0x80011C60: nop

    return;
    // 0x80011C60: nop

;}
RECOMP_FUNC void func_806B0AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0AD0: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x806B0AD4: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806B0AD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806B0ADC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806B0AE0: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x806B0AE4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x806B0AE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806B0AEC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806B0AF0: lw          $v1, 0x174($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X174);
    // 0x806B0AF4: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806B0AF8: bc1t        L_806B0B1C
    if (c1cs) {
        // 0x806B0AFC: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_806B0B1C;
    }
    // 0x806B0AFC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806B0B00: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x806B0B04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806B0B08: nop

    // 0x806B0B0C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x806B0B10: nop

    // 0x806B0B14: bc1fl       L_806B0B44
    if (!c1cs) {
        // 0x806B0B18: lw          $a2, 0x8($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X8);
            goto L_806B0B44;
    }
    goto skip_0;
    // 0x806B0B18: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    skip_0:
L_806B0B1C:
    // 0x806B0B1C: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x806B0B20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806B0B24: nop

    // 0x806B0B28: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x806B0B2C: nop

    // 0x806B0B30: bc1fl       L_806B0B44
    if (!c1cs) {
        // 0x806B0B34: lw          $a2, 0x8($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X8);
            goto L_806B0B44;
    }
    goto skip_1;
    // 0x806B0B34: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x806B0B38: b           L_806B0B90
    // 0x806B0B3C: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_806B0B90;
    // 0x806B0B3C: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x806B0B40: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
L_806B0B44:
    // 0x806B0B44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806B0B48: andi        $t7, $a2, 0xF0
    ctx->r15 = ctx->r6 & 0XF0;
    // 0x806B0B4C: beq         $t7, $zero, L_806B0B6C
    if (ctx->r15 == 0) {
        // 0x806B0B50: andi        $t8, $a2, 0xF
        ctx->r24 = ctx->r6 & 0XF;
            goto L_806B0B6C;
    }
    // 0x806B0B50: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x806B0B54: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806B0B58: nop

    // 0x806B0B5C: bc1f        L_806B0B6C
    if (!c1cs) {
        // 0x806B0B60: nop
    
            goto L_806B0B6C;
    }
    // 0x806B0B60: nop

    // 0x806B0B64: b           L_806B0B90
    // 0x806B0B68: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_806B0B90;
    // 0x806B0B68: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_806B0B6C:
    // 0x806B0B6C: beql        $t8, $zero, L_806B0B90
    if (ctx->r24 == 0) {
        // 0x806B0B70: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_806B0B90;
    }
    goto skip_2;
    // 0x806B0B70: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    skip_2:
    // 0x806B0B74: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x806B0B78: nop

    // 0x806B0B7C: bc1fl       L_806B0B90
    if (!c1cs) {
        // 0x806B0B80: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_806B0B90;
    }
    goto skip_3;
    // 0x806B0B80: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    skip_3:
    // 0x806B0B84: b           L_806B0B90
    // 0x806B0B88: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_806B0B90;
    // 0x806B0B88: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x806B0B8C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_806B0B90:
    // 0x806B0B90: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1730) << 16);
    // 0x806B0B94: lwc1        $f18, 0x16C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1730));
    // 0x806B0B98: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1734) << 16);
    // 0x806B0B9C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806B0BA0: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x806B0BA4: nop

    // 0x806B0BA8: bc1t        L_806B0BC0
    if (c1cs) {
        // 0x806B0BAC: nop
    
            goto L_806B0BC0;
    }
    // 0x806B0BAC: nop

    // 0x806B0BB0: lwc1        $f4, 0x16C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1734));
    // 0x806B0BB4: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x806B0BB8: nop

    // 0x806B0BBC: bc1f        L_806B0C48
    if (!c1cs) {
        // 0x806B0BC0: lui         $at, 0x806B
        ctx->r1 = S32(RELOC_HI16(598, 0X1738) << 16);
            goto L_806B0C48;
    }
L_806B0BC0:
    // 0x806B0BC0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1738) << 16);
    // 0x806B0BC4: lwc1        $f6, 0x16C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1738));
    // 0x806B0BC8: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B0BCC: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806B0BD0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X173C) << 16);
    // 0x806B0BD4: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x806B0BD8: nop

    // 0x806B0BDC: bc1f        L_806B0BEC
    if (!c1cs) {
        // 0x806B0BE0: nop
    
            goto L_806B0BEC;
    }
    // 0x806B0BE0: nop

    // 0x806B0BE4: b           L_806B0C14
    // 0x806B0BE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
        goto L_806B0C14;
    // 0x806B0BE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_806B0BEC:
    // 0x806B0BEC: lwc1        $f8, 0x16CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X173C));
    // 0x806B0BF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806B0BF4: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x806B0BF8: nop

    // 0x806B0BFC: bc1fl       L_806B0C10
    if (!c1cs) {
        // 0x806B0C00: lw          $t0, 0x138($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X138);
            goto L_806B0C10;
    }
    goto skip_4;
    // 0x806B0C00: lw          $t0, 0x138($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X138);
    skip_4:
    // 0x806B0C04: b           L_806B0C14
    // 0x806B0C08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_806B0C14;
    // 0x806B0C08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x806B0C0C: lw          $t0, 0x138($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X138);
L_806B0C10:
    // 0x806B0C10: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_806B0C14:
    // 0x806B0C14: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x806B0C18: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806B0C1C: bc1fl       L_806B0C40
    if (!c1cs) {
        // 0x806B0C20: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_806B0C40;
    }
    goto skip_5;
    // 0x806B0C20: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_5:
    // 0x806B0C24: add.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x806B0C28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806B0C2C: nop

    // 0x806B0C30: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B0C34: b           L_806B0C40
    // 0x806B0C38: nop

        goto L_806B0C40;
    // 0x806B0C38: nop

    // 0x806B0C3C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_806B0C40:
    // 0x806B0C40: b           L_806B0D10
    // 0x806B0C44: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
        goto L_806B0D10;
    // 0x806B0C44: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
L_806B0C48:
    // 0x806B0C48: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x806B0C4C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1740) << 16);
    // 0x806B0C50: bc1tl       L_806B0D14
    if (c1cs) {
        // 0x806B0C54: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_806B0D14;
    }
    goto skip_6;
    // 0x806B0C54: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_6:
    // 0x806B0C58: lwc1        $f8, 0x16D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1740));
    // 0x806B0C5C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1744) << 16);
    // 0x806B0C60: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x806B0C64: nop

    // 0x806B0C68: bc1tl       L_806B0D14
    if (c1cs) {
        // 0x806B0C6C: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_806B0D14;
    }
    goto skip_7;
    // 0x806B0C6C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_7:
    // 0x806B0C70: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B0C74: lwc1        $f10, 0x16D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1744));
    // 0x806B0C78: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1748) << 16);
    // 0x806B0C7C: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x806B0C80: nop

    // 0x806B0C84: bc1f        L_806B0C98
    if (!c1cs) {
        // 0x806B0C88: nop
    
            goto L_806B0C98;
    }
    // 0x806B0C88: nop

    // 0x806B0C8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806B0C90: b           L_806B0CB8
    // 0x806B0C94: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
        goto L_806B0CB8;
    // 0x806B0C94: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_806B0C98:
    // 0x806B0C98: lwc1        $f4, 0x16D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1748));
    // 0x806B0C9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806B0CA0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x806B0CA4: nop

    // 0x806B0CA8: bc1fl       L_806B0CBC
    if (!c1cs) {
        // 0x806B0CAC: lw          $t3, 0xC($v0)
        ctx->r11 = MEM_W(ctx->r2, 0XC);
            goto L_806B0CBC;
    }
    goto skip_8;
    // 0x806B0CAC: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    skip_8:
    // 0x806B0CB0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x806B0CB4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_806B0CB8:
    // 0x806B0CB8: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
L_806B0CBC:
    // 0x806B0CBC: beql        $t3, $zero, L_806B0CF4
    if (ctx->r11 == 0) {
        // 0x806B0CC0: lw          $t5, 0x4($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X4);
            goto L_806B0CF4;
    }
    goto skip_9;
    // 0x806B0CC0: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    skip_9:
    // 0x806B0CC4: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x806B0CC8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806B0CCC: beql        $t4, $zero, L_806B0CE8
    if (ctx->r12 == 0) {
        // 0x806B0CD0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_806B0CE8;
    }
    goto skip_10;
    // 0x806B0CD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_10:
    // 0x806B0CD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806B0CD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B0CDC: b           L_806B0D14
    // 0x806B0CE0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
        goto L_806B0D14;
    // 0x806B0CE0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x806B0CE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_806B0CE8:
    // 0x806B0CE8: b           L_806B0D14
    // 0x806B0CEC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
        goto L_806B0D14;
    // 0x806B0CEC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x806B0CF0: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
L_806B0CF4:
    // 0x806B0CF4: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1750) << 16);
    // 0x806B0CF8: beq         $t5, $zero, L_806B0D0C
    if (ctx->r13 == 0) {
        // 0x806B0CFC: nop
    
            goto L_806B0D0C;
    }
    // 0x806B0CFC: nop

    // 0x806B0D00: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X174C) << 16);
    // 0x806B0D04: b           L_806B0D10
    // 0x806B0D08: lwc1        $f0, 0x16DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X174C));
        goto L_806B0D10;
    // 0x806B0D08: lwc1        $f0, 0x16DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X174C));
L_806B0D0C:
    // 0x806B0D0C: lwc1        $f0, 0x16E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1750));
L_806B0D10:
    // 0x806B0D10: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_806B0D14:
    // 0x806B0D14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806B0D18: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x806B0D1C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1754) << 16);
    // 0x806B0D20: lwc1        $f6, 0x16E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1754));
    // 0x806B0D24: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x806B0D28: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806B0D2C: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x806B0D30: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806B0D34: nop

    // 0x806B0D38: bc1fl       L_806B0D4C
    if (!c1cs) {
        // 0x806B0D3C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806B0D4C;
    }
    goto skip_11;
    // 0x806B0D3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_11:
    // 0x806B0D40: jr          $ra
    // 0x806B0D44: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x806B0D44: swc1        $f12, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f12.u32l;
    // 0x806B0D48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806B0D4C:
    // 0x806B0D4C: nop

    // 0x806B0D50: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806B0D54: nop

    // 0x806B0D58: bc1fl       L_806B0D6C
    if (!c1cs) {
        // 0x806B0D5C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_806B0D6C;
    }
    goto skip_12;
    // 0x806B0D5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x806B0D60: b           L_806B0D6C
    // 0x806B0D64: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_806B0D6C;
    // 0x806B0D64: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x806B0D68: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806B0D6C:
    // 0x806B0D6C: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x806B0D70: jr          $ra
    // 0x806B0D74: nop

    return;
    // 0x806B0D74: nop

;}
RECOMP_FUNC void func_807362A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807362A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807362AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807362B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807362B4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B18) << 16);
    // 0x807362B8: lwc1        $f6, -0x6A88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B18));
    // 0x807362BC: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807362C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807362C4: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x807362C8: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807362CC: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807362D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807362D4: jal         0x800659EC
    // 0x807362D8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x807362D8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x807362DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807362E0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x807362E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807362E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807362EC: jr          $ra
    // 0x807362F0: nop

    return;
    // 0x807362F0: nop

;}
RECOMP_FUNC void func_805C71D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C71D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805C71D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C71DC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x805C71E0: jal         0x8004700C
    // 0x805C71E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C71E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805C71E8: beq         $v0, $zero, L_805C72A0
    if (ctx->r2 == 0) {
        // 0x805C71EC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_805C72A0;
    }
    // 0x805C71EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805C71F0: jal         0x80047AB8
    // 0x805C71F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x805C71F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x805C71F8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x805C71FC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805C7200: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805C7204: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x805C7208: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x805C720C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805C7210: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805C7214: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x805C7218: jal         0x80067114
    // 0x805C721C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x805C721C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x805C7220: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x805C7224: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805C7228: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C722C: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x805C7230: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805C7234: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x805C7238: beq         $t7, $zero, L_805C724C
    if (ctx->r15 == 0) {
        // 0x805C723C: add.s       $f2, $f0, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f16.fl;
            goto L_805C724C;
    }
    // 0x805C723C: add.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x805C7240: jal         0x80067114
    // 0x805C7244: nop

    func_80067114(rdram, ctx);
        goto after_3;
    // 0x805C7244: nop

    after_3:
    // 0x805C7248: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_805C724C:
    // 0x805C724C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805C7250: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C7254: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x805C7258: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x805C725C: nop

    // 0x805C7260: bc1fl       L_805C7278
    if (!c1cs) {
        // 0x805C7264: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_805C7278;
    }
    goto skip_0;
    // 0x805C7264: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x805C7268: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C726C: nop

    // 0x805C7270: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x805C7274: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_805C7278:
    // 0x805C7278: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C727C: nop

    // 0x805C7280: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805C7284: nop

    // 0x805C7288: bc1fl       L_805C7298
    if (!c1cs) {
        // 0x805C728C: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_805C7298;
    }
    goto skip_1;
    // 0x805C728C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x805C7290: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x805C7294: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_805C7298:
    // 0x805C7298: jal         0x805C70B0
    // 0x805C729C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_805C70B0(rdram, ctx);
        goto after_4;
    // 0x805C729C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_4:
L_805C72A0:
    // 0x805C72A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C72A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805C72A8: jr          $ra
    // 0x805C72AC: nop

    return;
    // 0x805C72AC: nop

;}
RECOMP_FUNC void func_804A1590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1590: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x804A1594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1598: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x804A159C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x804A15A0: nop

    // 0x804A15A4: bc1t        L_804A15F4
    if (c1cs) {
        // 0x804A15A8: nop
    
            goto L_804A15F4;
    }
    // 0x804A15A8: nop

    // 0x804A15AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A15B0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x804A15B4: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x804A15B8: nop

    // 0x804A15BC: bc1t        L_804A15F4
    if (c1cs) {
        // 0x804A15C0: nop
    
            goto L_804A15F4;
    }
    // 0x804A15C0: nop

    // 0x804A15C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804A15C8: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x804A15CC: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x804A15D0: nop

    // 0x804A15D4: bc1t        L_804A15F4
    if (c1cs) {
        // 0x804A15D8: nop
    
            goto L_804A15F4;
    }
    // 0x804A15D8: nop

    // 0x804A15DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804A15E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804A15E4: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x804A15E8: nop

    // 0x804A15EC: bc1f        L_804A15FC
    if (!c1cs) {
        // 0x804A15F0: nop
    
            goto L_804A15FC;
    }
    // 0x804A15F0: nop

L_804A15F4:
    // 0x804A15F4: jr          $ra
    // 0x804A15F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x804A15F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804A15FC:
    // 0x804A15FC: jr          $ra
    // 0x804A1600: nop

    return;
    // 0x804A1600: nop

;}
