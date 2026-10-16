#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8003FAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FAA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8003FAA8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003FAAC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003FAB0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003FAB4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003FAB8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8003FABC: lbu         $t6, 0x12C8($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X12C8);
    // 0x8003FAC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003FAC4: lwc1        $f10, 0x2CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2CC);
    // 0x8003FAC8: sb          $t6, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r14;
    // 0x8003FACC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003FAD0: lw          $s2, 0x174($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X174);
    // 0x8003FAD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003FAD8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8003FADC: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8003FAE0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8003FAE4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003FAE8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x8003FAEC: lwc1        $f8, 0x8C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x8003FAF0: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x8003FAF4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003FAF8: jal         0x80065490
    // 0x8003FAFC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8003FAFC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8003FB00: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003FB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FB08: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003FB0C: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x8003FB10: bne         $at, $zero, L_8003FB40
    if (ctx->r1 != 0) {
        // 0x8003FB14: addiu       $a3, $sp, 0x4C
        ctx->r7 = ADD32(ctx->r29, 0X4C);
            goto L_8003FB40;
    }
    // 0x8003FB14: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x8003FB18: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8003FB1C: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x8003FB20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003FB24: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003FB28: jal         0x8003F894
    // 0x8003FB2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8003F894(rdram, ctx);
        goto after_1;
    // 0x8003FB2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x8003FB30: bnel        $v0, $zero, L_8003FB78
    if (ctx->r2 != 0) {
        // 0x8003FB34: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8003FB78;
    }
    goto skip_0;
    // 0x8003FB34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_0:
    // 0x8003FB38: b           L_8003FBD0
    // 0x8003FB3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8003FBD0;
    // 0x8003FB3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003FB40:
    // 0x8003FB40: jal         0x8003E520
    // 0x8003FB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E520(rdram, ctx);
        goto after_2;
    // 0x8003FB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003FB48: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8003FB4C: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003FB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FB54: jalr        $t9
    // 0x8003FB58: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8003FB58: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_3:
    // 0x8003FB5C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8003FB60: addiu       $a3, $a3, -0x19E8
    ctx->r7 = ADD32(ctx->r7, -0X19E8);
    // 0x8003FB64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003FB68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003FB6C: jal         0x8003E658
    // 0x8003FB70: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_8003E658(rdram, ctx);
        goto after_4;
    // 0x8003FB70: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x8003FB74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8003FB78:
    // 0x8003FB78: sb          $t0, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r8;
    // 0x8003FB7C: lbu         $t2, 0x12C8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X12C8);
    // 0x8003FB80: lhu         $t1, 0x12BE($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X12BE);
    // 0x8003FB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FB88: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x8003FB8C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8003FB90: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8003FB94: jal         0x8003E4C8
    // 0x8003FB98: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_8003E4C8(rdram, ctx);
        goto after_5;
    // 0x8003FB98: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_5:
    // 0x8003FB9C: jal         0x8003F85C
    // 0x8003FBA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8003F85C(rdram, ctx);
        goto after_6;
    // 0x8003FBA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8003FBA4: jal         0x8005FE48
    // 0x8003FBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_7;
    // 0x8003FBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8003FBAC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8003FBB0: sh          $zero, 0x10($t3)
    MEM_H(0X10, ctx->r11) = 0;
    // 0x8003FBB4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8003FBB8: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    // 0x8003FBBC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8003FBC0: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x8003FBC4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8003FBC8: sw          $zero, 0x44($t6)
    MEM_W(0X44, ctx->r14) = 0;
    // 0x8003FBCC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003FBD0:
    // 0x8003FBD0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003FBD4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FBD8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003FBDC: jr          $ra
    // 0x8003FBE0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8003FBE0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_806ED114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ED118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED11C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806ED120: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806ED124: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806ED128: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(676, 0X4594) << 16);
    // 0x806ED12C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806ED130: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806ED134: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806ED138: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806ED13C: lw          $t8, 0x4E4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(676, 0X4594));
    // 0x806ED140: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806ED144: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806ED148: jal         0x80048490
    // 0x806ED14C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806ED14C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806ED150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ED154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED158: jr          $ra
    // 0x806ED15C: nop

    return;
    // 0x806ED15C: nop

;}
RECOMP_FUNC void func_8001A7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A7A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A7A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A7A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001A7AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A7B0: jal         0x8001A374
    // 0x8001A7B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8001A374(rdram, ctx);
        goto after_0;
    // 0x8001A7B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001A7B8: beq         $v0, $zero, L_8001A7DC
    if (ctx->r2 == 0) {
        // 0x8001A7BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001A7DC;
    }
    // 0x8001A7BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001A7C0: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x8001A7C4: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x8001A7C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001A7CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7D0: jal         0x8001AA84
    // 0x8001A7D4: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_8001AA84(rdram, ctx);
        goto after_1;
    // 0x8001A7D4: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_1:
    // 0x8001A7D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8001A7DC:
    // 0x8001A7DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A7E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A7E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001A7E8: jr          $ra
    // 0x8001A7EC: nop

    return;
    // 0x8001A7EC: nop

;}
RECOMP_FUNC void func_80568084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80568088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8056808C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80568090: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80568094: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568098: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8056809C: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x805680A0: bnel        $t6, $zero, L_80568108
    if (ctx->r14 != 0) {
        // 0x805680A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80568108;
    }
    goto skip_0;
    // 0x805680A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x805680A8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805680AC: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805680B0: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x805680B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805680B8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805680BC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805680C0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805680C4: nop

    // 0x805680C8: bc1fl       L_80568104
    if (!c1cs) {
        // 0x805680CC: sw          $zero, 0x18($v1)
        MEM_W(0X18, ctx->r3) = 0;
            goto L_80568104;
    }
    goto skip_1;
    // 0x805680CC: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    skip_1:
    // 0x805680D0: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x805680D4: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x805680D8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805680DC: bnel        $t7, $zero, L_80568108
    if (ctx->r15 != 0) {
        // 0x805680E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80568108;
    }
    goto skip_2;
    // 0x805680E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x805680E4: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x805680E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805680EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805680F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805680F4: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x805680F8: b           L_80568104
    // 0x805680FC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
        goto L_80568104;
    // 0x805680FC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x80568100: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
L_80568104:
    // 0x80568104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80568108:
    // 0x80568108: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x8056810C: jal         0x80567DD4
    // 0x80568110: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80567DD4(rdram, ctx);
        goto after_0;
    // 0x80568110: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80568114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80568118: jal         0x80048F84
    // 0x8056811C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8056811C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80568120: jal         0x805677F4
    // 0x80568124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805677F4(rdram, ctx);
        goto after_2;
    // 0x80568124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80568128: jal         0x80567C4C
    // 0x8056812C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80567C4C(rdram, ctx);
        goto after_3;
    // 0x8056812C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80568130: bne         $v0, $zero, L_80568194
    if (ctx->r2 != 0) {
        // 0x80568134: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80568194;
    }
    // 0x80568134: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80568138: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8056813C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80568140: bne         $at, $zero, L_80568150
    if (ctx->r1 != 0) {
        // 0x80568144: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80568150;
    }
    // 0x80568144: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80568148: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x8056814C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80568150:
    // 0x80568150: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80568154: bne         $v0, $at, L_80568194
    if (ctx->r2 != ctx->r1) {
        // 0x80568158: nop
    
            goto L_80568194;
    }
    // 0x80568158: nop

    // 0x8056815C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80568160: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21A8) << 16);
    // 0x80568164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80568168: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x8056816C: lwc1        $f6, -0x68A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21A8));
    // 0x80568170: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80568174: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568178: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21AC) << 16);
    // 0x8056817C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80568180: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x80568184: lwc1        $f10, -0x68A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21AC));
    // 0x80568188: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8056818C: jal         0x80569310
    // 0x80568190: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    func_80569310(rdram, ctx);
        goto after_4;
    // 0x80568190: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    after_4:
L_80568194:
    // 0x80568194: jal         0x80567E60
    // 0x80568198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80567E60(rdram, ctx);
        goto after_5;
    // 0x80568198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8056819C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805681A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805681A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805681A8: jr          $ra
    // 0x805681AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805681AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80029128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002912C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029130: jal         0x80028A78
    // 0x80029134: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80028A78(rdram, ctx);
        goto after_0;
    // 0x80029134: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80029138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002913C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029140: jr          $ra
    // 0x80029144: nop

    return;
    // 0x80029144: nop

;}
RECOMP_FUNC void func_8042E750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E758: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042E75C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042E760: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042E764: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X32A4) << 16);
    // 0x8042E768: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042E76C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042E770: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042E774: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042E778: lw          $t8, 0x1384($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X32A4));
    // 0x8042E77C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042E780: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042E784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042E788: jal         0x80048490
    // 0x8042E78C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8042E78C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042E790: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042E794: jal         0x80048378
    // 0x8042E798: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042E798: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8042E79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E7A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E7A4: jr          $ra
    // 0x8042E7A8: nop

    return;
    // 0x8042E7A8: nop

;}
RECOMP_FUNC void func_80025898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002589C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800258A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800258A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800258A8: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x800258AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x800258B0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800258B4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x800258B8: jal         0x80024680
    // 0x800258BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x800258BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800258C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800258C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800258C8: bne         $v0, $at, L_800258F4
    if (ctx->r2 != ctx->r1) {
        // 0x800258CC: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_800258F4;
    }
    // 0x800258CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800258D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800258D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800258D8: lwc1        $f4, 0xC8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x800258DC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800258E0: nop

    // 0x800258E4: bc1fl       L_800258F8
    if (!c1cs) {
        // 0x800258E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800258F8;
    }
    goto skip_0;
    // 0x800258E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800258EC: jal         0x80025854
    // 0x800258F0: nop

    func_80025854(rdram, ctx);
        goto after_1;
    // 0x800258F0: nop

    after_1:
L_800258F4:
    // 0x800258F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800258F8:
    // 0x800258F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800258FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025900: jr          $ra
    // 0x80025904: nop

    return;
    // 0x80025904: nop

;}
RECOMP_FUNC void func_8043F054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F05C: jal         0x8043EF40
    // 0x8043F060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043EF40(rdram, ctx);
        goto after_0;
    // 0x8043F060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043F064: jal         0x80045BD8
    // 0x8043F068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8043F068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043F06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F074: jr          $ra
    // 0x8043F078: nop

    return;
    // 0x8043F078: nop

;}
RECOMP_FUNC void func_8043E158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E158: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8043E15C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8043E160: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8043E164: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8043E168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043E16C: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8043E170: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8043E174: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043E178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043E17C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8043E180: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8043E184: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(92, 0X1A00) << 16);
    // 0x8043E188: lbu         $s1, 0x5($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X5);
    // 0x8043E18C: bc1fl       L_8043E19C
    if (!c1cs) {
        // 0x8043E190: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_8043E19C;
    }
    goto skip_0;
    // 0x8043E190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    skip_0:
    // 0x8043E194: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8043E198: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
L_8043E19C:
    // 0x8043E19C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8043E1A0: lw          $v0, -0x15C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(92, 0X1A00));
    // 0x8043E1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043E1A8: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
    // 0x8043E1AC: sw          $v0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r2;
    // 0x8043E1B0: jal         0x8003A6F0
    // 0x8043E1B4: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
    func_8003A6F0(rdram, ctx);
        goto after_0;
    // 0x8043E1B4: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
    after_0:
    // 0x8043E1B8: beq         $s1, $zero, L_8043E230
    if (ctx->r17 == 0) {
        // 0x8043E1BC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8043E230;
    }
    // 0x8043E1BC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8043E1C0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8043E1C4: slti        $at, $s1, 0x14
    ctx->r1 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x8043E1C8: beq         $at, $zero, L_8043E228
    if (ctx->r1 == 0) {
        // 0x8043E1CC: nop
    
            goto L_8043E228;
    }
    // 0x8043E1CC: nop

    // 0x8043E1D0: jal         0x8004700C
    // 0x8043E1D4: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8043E1D4: nop

    after_1:
    // 0x8043E1D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8043E1DC: bne         $v0, $zero, L_8043E1EC
    if (ctx->r2 != 0) {
        // 0x8043E1E0: lbu         $a3, 0x6($s2)
        ctx->r7 = MEM_BU(ctx->r18, 0X6);
            goto L_8043E1EC;
    }
    // 0x8043E1E0: lbu         $a3, 0x6($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X6);
    // 0x8043E1E4: b           L_8043E228
    // 0x8043E1E8: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
        goto L_8043E228;
    // 0x8043E1E8: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
L_8043E1EC:
    // 0x8043E1EC: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8043E1F0: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    // 0x8043E1F4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8043E1F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8043E1FC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8043E200: jal         0x8043D1FC
    // 0x8043E204: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8043D1FC(rdram, ctx);
        goto after_2;
    // 0x8043E204: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x8043E208: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8043E20C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8043E210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8043E214: xori        $a3, $a3, 0x1
    ctx->r7 = ctx->r7 ^ 0X1;
    // 0x8043E218: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8043E21C: addu        $a0, $s0, $t9
    ctx->r4 = ADD32(ctx->r16, ctx->r25);
    // 0x8043E220: jal         0x8043D370
    // 0x8043E224: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_8043D370(rdram, ctx);
        goto after_3;
    // 0x8043E224: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_3:
L_8043E228:
    // 0x8043E228: b           L_8043E238
    // 0x8043E22C: sb          $s1, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r17;
        goto L_8043E238;
    // 0x8043E22C: sb          $s1, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r17;
L_8043E230:
    // 0x8043E230: jal         0x8043D320
    // 0x8043E234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043D320(rdram, ctx);
        goto after_4;
    // 0x8043E234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8043E238:
    // 0x8043E238: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x8043E23C: beq         $v0, $zero, L_8043E248
    if (ctx->r2 == 0) {
        // 0x8043E240: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8043E248;
    }
    // 0x8043E240: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8043E244: sb          $t0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r8;
L_8043E248:
    // 0x8043E248: jal         0x8043D07C
    // 0x8043E24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043D07C(rdram, ctx);
        goto after_5;
    // 0x8043E24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8043E250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8043E254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043E258: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E25C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8043E260: jr          $ra
    // 0x8043E264: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8043E264: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805367A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805367A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805367A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805367AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805367B0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x805367B4: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x805367B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805367BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x805367C0: lw          $v1, 0x6D94($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D94);
    // 0x805367C4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x805367C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805367CC: bne         $v1, $zero, L_805367FC
    if (ctx->r3 != 0) {
        // 0x805367D0: nop
    
            goto L_805367FC;
    }
    // 0x805367D0: nop

    // 0x805367D4: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x805367D8: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x805367DC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x805367E0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x805367E4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x805367E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x805367EC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x805367F0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805367F4: b           L_80536820
    // 0x805367F8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_80536820;
    // 0x805367F8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_805367FC:
    // 0x805367FC: bne         $v1, $at, L_80536818
    if (ctx->r3 != ctx->r1) {
        // 0x80536800: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80536818;
    }
    // 0x80536800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80536804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80536808: jal         0x80536114
    // 0x8053680C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_80536114(rdram, ctx);
        goto after_0;
    // 0x8053680C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_0:
    // 0x80536810: b           L_80536824
    // 0x80536814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80536824;
    // 0x80536814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80536818:
    // 0x80536818: jal         0x80536144
    // 0x8053681C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80536144(rdram, ctx);
        goto after_1;
    // 0x8053681C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_1:
L_80536820:
    // 0x80536820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80536824:
    // 0x80536824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536828: jr          $ra
    // 0x8053682C: nop

    return;
    // 0x8053682C: nop

;}
RECOMP_FUNC void func_807A0360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A0364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A0368: jal         0x807A0244
    // 0x807A036C: nop

    func_807A0244(rdram, ctx);
        goto after_0;
    // 0x807A036C: nop

    after_0:
    // 0x807A0370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A0374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A0378: jr          $ra
    // 0x807A037C: nop

    return;
    // 0x807A037C: nop

;}
RECOMP_FUNC void func_8064F138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F138: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F13C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F140: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F144: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F148: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F14C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F150: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F154: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F158: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F15C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F160: jr          $ra
    // 0x8064F164: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F164: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8005C850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C858: jal         0x8005C3B4
    // 0x8005C85C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005C3B4(rdram, ctx);
        goto after_0;
    // 0x8005C85C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C860: jal         0x8005C594
    // 0x8005C864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005C594(rdram, ctx);
        goto after_1;
    // 0x8005C864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8005C868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C86C: jal         0x8005D134
    // 0x8005C870: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_8005D134(rdram, ctx);
        goto after_2;
    // 0x8005C870: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_2:
    // 0x8005C874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C87C: jr          $ra
    // 0x8005C880: nop

    return;
    // 0x8005C880: nop

;}
RECOMP_FUNC void func_806EFE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFE6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EFE70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EFE74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EFE78: jal         0x806EC16C
    // 0x806EFE7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EFE7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EFE80: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EFE84: jal         0x800577D8
    // 0x806EFE88: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EFE88: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EFE8C: jal         0x806EF504
    // 0x806EFE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_2;
    // 0x806EFE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EFE94: jal         0x806EF584
    // 0x806EFE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_3;
    // 0x806EFE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EFE9C: jal         0x806EF638
    // 0x806EFEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF638(rdram, ctx);
        goto after_4;
    // 0x806EFEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EFEA4: jal         0x806EFBD8
    // 0x806EFEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EFBD8(rdram, ctx);
        goto after_5;
    // 0x806EFEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EFEAC: beq         $v0, $zero, L_806EFEC4
    if (ctx->r2 == 0) {
        // 0x806EFEB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EFEC4;
    }
    // 0x806EFEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFEB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFEB8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EFEBC: jal         0x806F0348
    // 0x806EFEC0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_6;
    // 0x806EFEC0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
L_806EFEC4:
    // 0x806EFEC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EFEC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EFECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EFED0: jr          $ra
    // 0x806EFED4: nop

    return;
    // 0x806EFED4: nop

;}
RECOMP_FUNC void func_8005A938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A938: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005A93C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005A940: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x8005A944: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A94C: sw          $a0, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->r4;
    // 0x8005A950: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x8005A954: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005A958: lw          $t8, 0xE8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XE8);
    // 0x8005A95C: beql        $t8, $zero, L_8005A988
    if (ctx->r24 == 0) {
        // 0x8005A960: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A988;
    }
    goto skip_0;
    // 0x8005A960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005A964: jal         0x80047AB8
    // 0x8005A968: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8005A968: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8005A96C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005A970: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005A974: lw          $a0, 0x478($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X478);
    // 0x8005A978: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8005A97C: jal         0x80065490
    // 0x8005A980: addiu       $a0, $a0, 0xDC
    ctx->r4 = ADD32(ctx->r4, 0XDC);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8005A980: addiu       $a0, $a0, 0xDC
    ctx->r4 = ADD32(ctx->r4, 0XDC);
    after_1:
    // 0x8005A984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A988:
    // 0x8005A988: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005A98C: jr          $ra
    // 0x8005A990: nop

    return;
    // 0x8005A990: nop

;}
RECOMP_FUNC void func_8045E3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045E3B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8045E3BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045E3C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045E3C4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8045E3C8: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x8045E3CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8045E3D0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8045E3D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8045E3D8: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x8045E3DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8045E3E0: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8045E3E4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8045E3E8: swc1        $f0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
    // 0x8045E3EC: swc1        $f0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f0.u32l;
    // 0x8045E3F0: swc1        $f0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f0.u32l;
    // 0x8045E3F4: swc1        $f0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f0.u32l;
    // 0x8045E3F8: jal         0x80047AB8
    // 0x8045E3FC: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8045E3FC: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    after_0:
    // 0x8045E400: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8045E404: jal         0x80047AB8
    // 0x8045E408: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8045E408: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x8045E40C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8045E410: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045E414: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8045E418: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8045E41C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8045E420: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8045E424: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8045E428: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8045E42C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8045E430: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8045E434: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8045E438: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8045E43C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8045E440: jal         0x8045DD20
    // 0x8045E444: nop

    func_8045DD20(rdram, ctx);
        goto after_2;
    // 0x8045E444: nop

    after_2:
    // 0x8045E448: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8045E44C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8045E450: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8045E454: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8045E458: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8045E45C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045E460: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8045E464: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8045E468: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8045E46C: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045E470: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8045E474: jal         0x8045DDAC
    // 0x8045E478: nop

    func_8045DDAC(rdram, ctx);
        goto after_3;
    // 0x8045E478: nop

    after_3:
    // 0x8045E47C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045E480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045E484: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8045E488: jr          $ra
    // 0x8045E48C: nop

    return;
    // 0x8045E48C: nop

;}
RECOMP_FUNC void func_806B0F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B0F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0F70: jal         0x8004700C
    // 0x806B0F74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806B0F74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B0F78: beq         $v0, $zero, L_806B0FBC
    if (ctx->r2 == 0) {
        // 0x806B0F7C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806B0FBC;
    }
    // 0x806B0F7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806B0F80: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X176C) << 16);
    // 0x806B0F84: lwc1        $f6, 0x16FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X176C));
    // 0x806B0F88: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1770) << 16);
    // 0x806B0F8C: lwc1        $f10, 0x1700($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1770));
    // 0x806B0F90: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806B0F94: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x806B0F98: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806B0F9C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B0FA0: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x806B0FA4: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806B0FA8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806B0FAC: nop

    // 0x806B0FB0: bc1fl       L_806B0FC0
    if (!c1cs) {
        // 0x806B0FB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B0FC0;
    }
    goto skip_0;
    // 0x806B0FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806B0FB8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_806B0FBC:
    // 0x806B0FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B0FC0:
    // 0x806B0FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B0FC4: jr          $ra
    // 0x806B0FC8: nop

    return;
    // 0x806B0FC8: nop

;}
RECOMP_FUNC void func_8001012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001012C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80010130: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x80010134: lh          $t6, 0x1D88($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1D88);
    // 0x80010138: lw          $t9, 0x1DAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1DAC);
    // 0x8001013C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80010140: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x80010144: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80010148: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001014C: lh          $v0, 0x1D90($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X1D90);
    // 0x80010150: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010154: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80010158: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001015C: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80010160: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80010164: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80010168: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x8001016C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80010170: mflo        $t0
    ctx->r8 = lo;
    // 0x80010174: sw          $t0, 0x4F28($v1)
    MEM_W(0X4F28, ctx->r3) = ctx->r8;
    // 0x80010178: beq         $v0, $zero, L_800101BC
    if (ctx->r2 == 0) {
        // 0x8001017C: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800101BC;
    }
    // 0x8001017C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80010180:
    // 0x80010180: lw          $t1, 0x2A30($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X2A30);
    // 0x80010184: addiu       $s0, $s1, 0x2A30
    ctx->r16 = ADD32(ctx->r17, 0X2A30);
    // 0x80010188: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8001018C: bnel        $s3, $t2, L_800101B0
    if (ctx->r19 != ctx->r10) {
        // 0x80010190: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800101B0;
    }
    goto skip_0;
    // 0x80010190: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80010194: jal         0x8000F984
    // 0x80010198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000F984(rdram, ctx);
        goto after_0;
    // 0x80010198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001019C: jal         0x8000CAB8
    // 0x800101A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000CAB8(rdram, ctx);
        goto after_1;
    // 0x800101A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800101A4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800101A8: lh          $v0, 0x6AA0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6AA0);
    // 0x800101AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800101B0:
    // 0x800101B0: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800101B4: bne         $at, $zero, L_80010180
    if (ctx->r1 != 0) {
        // 0x800101B8: addiu       $s1, $s1, 0x160
        ctx->r17 = ADD32(ctx->r17, 0X160);
            goto L_80010180;
    }
    // 0x800101B8: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
L_800101BC:
    // 0x800101BC: jal         0x8000B338
    // 0x800101C0: nop

    func_8000B338(rdram, ctx);
        goto after_2;
    // 0x800101C0: nop

    after_2:
    // 0x800101C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800101C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800101CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800101D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800101D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800101D8: jr          $ra
    // 0x800101DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800101DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Overlay_AllocateAndLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80081748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008174C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80081750: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80081754: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80081758: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8008175C: jal         0x80064DD0
    // 0x80081760: subu        $a0, $a3, $a2
    ctx->r4 = SUB32(ctx->r7, ctx->r6);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x80081760: subu        $a0, $a3, $a2
    ctx->r4 = SUB32(ctx->r7, ctx->r6);
    after_0:
    // 0x80081764: beq         $v0, $zero, L_8008178C
    if (ctx->r2 == 0) {
        // 0x80081768: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008178C;
    }
    // 0x80081768: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008176C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80081770: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80081774: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80081778: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8008177C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80081780: jal         0x8008169C
    // 0x80081784: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    Overlay_Load(rdram, ctx);
        goto after_1;
    // 0x80081784: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80081788: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8008178C:
    // 0x8008178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80081794: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80081798: jr          $ra
    // 0x8008179C: nop

    return;
    // 0x8008179C: nop

;}
RECOMP_FUNC void func_80429DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429DD0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(47, 0X10) << 16);
    // 0x80429DD4: addiu       $v0, $v0, -0x6220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(47, 0X10));
    // 0x80429DD8: jr          $ra
    // 0x80429DDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80429DDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807C4180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C4180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C4184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C4188: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807C418C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807C4190: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x807C4194: jal         0x80047090
    // 0x807C4198: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807C4198: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x807C419C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807C41A0: beq         $v0, $at, L_807C41F4
    if (ctx->r2 == ctx->r1) {
        // 0x807C41A4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807C41F4;
    }
    // 0x807C41A4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807C41A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C41AC: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x807C41B0: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x807C41B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807C41B8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x807C41BC: ori         $t8, $t7, 0x2400
    ctx->r24 = ctx->r15 | 0X2400;
    // 0x807C41C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C41C4: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    // 0x807C41C8: jal         0x8004613C
    // 0x807C41CC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807C41CC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    after_1:
    // 0x807C41D0: beq         $v0, $zero, L_807C41F4
    if (ctx->r2 == 0) {
        // 0x807C41D4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807C41F4;
    }
    // 0x807C41D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807C41D8: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x807C41DC: sh          $t9, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r25;
    // 0x807C41E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x807C41E4: jal         0x80047F9C
    // 0x807C41E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807C41E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807C41EC: b           L_807C41F8
    // 0x807C41F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_807C41F8;
    // 0x807C41F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_807C41F4:
    // 0x807C41F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C41F8:
    // 0x807C41F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C41FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C4200: jr          $ra
    // 0x807C4204: nop

    return;
    // 0x807C4204: nop

    // 0x807C4208: nop

    // 0x807C420C: nop

;}
RECOMP_FUNC void func_805A8794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A8798: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805A879C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805A87A0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805A87A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A87A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805A87AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x805A87B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x805A87B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A87B8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x805A87BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805A87C0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805A87C4: lui         $t2, 0x805B
    ctx->r10 = S32(RELOC_HI16(426, 0X1704) << 16);
    // 0x805A87C8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805A87CC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805A87D0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805A87D4: lw          $t2, -0x75AC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(426, 0X1704));
    // 0x805A87D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805A87DC: jal         0x805A8738
    // 0x805A87E0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_805A8738(rdram, ctx);
        goto after_0;
    // 0x805A87E0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x805A87E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A87E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A87EC: jr          $ra
    // 0x805A87F0: nop

    return;
    // 0x805A87F0: nop

    // 0x805A87F4: nop

    // 0x805A87F8: nop

    // 0x805A87FC: nop

;}
RECOMP_FUNC void func_806D0428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D042C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0430: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D0434: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D0438: jal         0x806D03E8
    // 0x806D043C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_806D03E8(rdram, ctx);
        goto after_0;
    // 0x806D043C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D0440: jal         0x806D0408
    // 0x806D0444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806D0408(rdram, ctx);
        goto after_1;
    // 0x806D0444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806D0448: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D044C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0450: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0454: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x806D0458: bnel        $a3, $zero, L_806D0490
    if (ctx->r7 != 0) {
        // 0x806D045C: lwc1        $f8, 0x4($t8)
        ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
            goto L_806D0490;
    }
    goto skip_0;
    // 0x806D045C: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    skip_0:
    // 0x806D0460: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D0464: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x806D0468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D046C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D0470: nop

    // 0x806D0474: bc1fl       L_806D04B4
    if (!c1cs) {
        // 0x806D0478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D04B4;
    }
    goto skip_1;
    // 0x806D0478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806D047C: jal         0x806D093C
    // 0x806D0480: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_806D093C(rdram, ctx);
        goto after_2;
    // 0x806D0480: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x806D0484: b           L_806D04B4
    // 0x806D0488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D04B4;
    // 0x806D0488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D048C: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
L_806D0490:
    // 0x806D0490: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806D0494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0498: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806D049C: nop

    // 0x806D04A0: bc1fl       L_806D04B4
    if (!c1cs) {
        // 0x806D04A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D04B4;
    }
    goto skip_2;
    // 0x806D04A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806D04A8: jal         0x806D093C
    // 0x806D04AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806D04AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_3:
    // 0x806D04B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D04B4:
    // 0x806D04B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D04B8: jr          $ra
    // 0x806D04BC: nop

    return;
    // 0x806D04BC: nop

;}
RECOMP_FUNC void func_804D8EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D8EB0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804D8EB4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804D8EB8: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(258, 0XE654) << 16);
    // 0x804D8EBC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804D8EC0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804D8EC4: lw          $t8, 0x7324($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(258, 0XE654));
    // 0x804D8EC8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804D8ECC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804D8ED0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804D8ED4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804D8ED8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804D8EDC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804D8EE0: beql        $v1, $zero, L_804D8F14
    if (ctx->r3 == 0) {
        // 0x804D8EE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804D8F14;
    }
    goto skip_0;
    // 0x804D8EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804D8EE8: jalr        $v1
    // 0x804D8EEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804D8EEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D8EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D8EF4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804D8EF8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804D8EFC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804D8F00: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804D8F04: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804D8F08: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804D8F0C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804D8F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D8F14:
    // 0x804D8F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D8F18: jr          $ra
    // 0x804D8F1C: nop

    return;
    // 0x804D8F1C: nop

;}
RECOMP_FUNC void func_806FBF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBF8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806FBF90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FBF94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806FBF98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806FBF9C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FBFA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806FBFA4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806FBFA8: lwc1        $f0, 0x14B4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14B4);
    // 0x806FBFAC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x806FBFB0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x806FBFB4: beql        $t6, $zero, L_806FBFD0
    if (ctx->r14 == 0) {
        // 0x806FBFB8: lwc1        $f8, 0x14A4($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X14A4);
            goto L_806FBFD0;
    }
    goto skip_0;
    // 0x806FBFB8: lwc1        $f8, 0x14A4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14A4);
    skip_0:
    // 0x806FBFBC: lwc1        $f4, 0x14A4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FBFC0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806FBFC4: b           L_806FBFD4
    // 0x806FBFC8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
        goto L_806FBFD4;
    // 0x806FBFC8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x806FBFCC: lwc1        $f8, 0x14A4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14A4);
L_806FBFD0:
    // 0x806FBFD0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
L_806FBFD4:
    // 0x806FBFD4: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x806FBFD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806FBFDC: bc1tl       L_806FBFF0
    if (c1cs) {
        // 0x806FBFE0: lui         $a2, 0x3D4C
        ctx->r6 = S32(0X3D4C << 16);
            goto L_806FBFF0;
    }
    goto skip_1;
    // 0x806FBFE0: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    skip_1:
    // 0x806FBFE4: jal         0x806FB994
    // 0x806FBFE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806FB994(rdram, ctx);
        goto after_0;
    // 0x806FBFE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x806FBFEC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
L_806FBFF0:
    // 0x806FBFF0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x806FBFF4: addiu       $a0, $s0, 0x14B4
    ctx->r4 = ADD32(ctx->r16, 0X14B4);
    // 0x806FBFF8: jal         0x806FBAE8
    // 0x806FBFFC: lw          $a1, 0x14B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14B8);
    func_806FBAE8(rdram, ctx);
        goto after_1;
    // 0x806FBFFC: lw          $a1, 0x14B8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14B8);
    after_1:
    // 0x806FC000: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x806FC004: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x806FC008: jal         0x80066E88
    // 0x806FC00C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806FC00C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x806FC010: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806FC014: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x806FC018: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806FC01C: swc1        $f6, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f6.u32l;
    // 0x806FC020: jal         0x80066DE4
    // 0x806FC024: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x806FC024: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x806FC028: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806FC02C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x806FC030: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806FC034: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806FC038: swc1        $f2, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f2.u32l;
    // 0x806FC03C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806FC040: bc1fl       L_806FC07C
    if (!c1cs) {
        // 0x806FC044: lwc1        $f16, 0xC8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
            goto L_806FC07C;
    }
    goto skip_2;
    // 0x806FC044: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    skip_2:
    // 0x806FC048: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x806FC04C: nop

    // 0x806FC050: bc1fl       L_806FC07C
    if (!c1cs) {
        // 0x806FC054: lwc1        $f16, 0xC8($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
            goto L_806FC07C;
    }
    goto skip_3;
    // 0x806FC054: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    skip_3:
    // 0x806FC058: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x806FC05C: jal         0x80067BBC
    // 0x806FC060: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806FC060: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_4:
    // 0x806FC064: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x806FC068: jal         0x80067818
    // 0x806FC06C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806FC06C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806FC070: b           L_806FC0B8
    // 0x806FC074: nop

        goto L_806FC0B8;
    // 0x806FC074: nop

    // 0x806FC078: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
L_806FC07C:
    // 0x806FC07C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806FC080: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x806FC084: nop

    // 0x806FC088: bc1f        L_806FC0B8
    if (!c1cs) {
        // 0x806FC08C: nop
    
            goto L_806FC0B8;
    }
    // 0x806FC08C: nop

    // 0x806FC090: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x806FC094: nop

    // 0x806FC098: bc1f        L_806FC0B8
    if (!c1cs) {
        // 0x806FC09C: nop
    
            goto L_806FC0B8;
    }
    // 0x806FC09C: nop

    // 0x806FC0A0: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x806FC0A4: jal         0x80067BBC
    // 0x806FC0A8: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x806FC0A8: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_6:
    // 0x806FC0AC: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x806FC0B0: jal         0x80067818
    // 0x806FC0B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x806FC0B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
L_806FC0B8:
    // 0x806FC0B8: jal         0x806FBF18
    // 0x806FC0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FBF18(rdram, ctx);
        goto after_8;
    // 0x806FC0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806FC0C0: beql        $v0, $zero, L_806FC120
    if (ctx->r2 == 0) {
        // 0x806FC0C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_806FC120;
    }
    goto skip_4;
    // 0x806FC0C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x806FC0C8: jal         0x800653D8
    // 0x806FC0CC: nop

    func_800653D8(rdram, ctx);
        goto after_9;
    // 0x806FC0CC: nop

    after_9:
    // 0x806FC0D0: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x806FC0D4: bne         $t7, $zero, L_806FC11C
    if (ctx->r15 != 0) {
        // 0x806FC0D8: lui         $v1, 0x8070
        ctx->r3 = S32(RELOC_HI16(700, 0X28D0) << 16);
            goto L_806FC11C;
    }
    // 0x806FC0D8: lui         $v1, 0x8070
    ctx->r3 = S32(RELOC_HI16(700, 0X28D0) << 16);
    // 0x806FC0DC: addiu       $v1, $v1, -0x3B00
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(700, 0X28D0));
    // 0x806FC0E0: sw          $zero, 0x14C4($s0)
    MEM_W(0X14C4, ctx->r16) = 0;
    // 0x806FC0E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806FC0E8: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x806FC0EC: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(700, 0X2754) << 16);
    // 0x806FC0F0: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x806FC0F4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806FC0F8: sw          $t8, 0x14CC($s0)
    MEM_W(0X14CC, ctx->r16) = ctx->r24;
    // 0x806FC0FC: lw          $t0, -0x3C7C($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(700, 0X2754));
    // 0x806FC100: sw          $t0, 0x14C8($s0)
    MEM_W(0X14C8, ctx->r16) = ctx->r8;
    // 0x806FC104: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x806FC108: jal         0x80067BBC
    // 0x806FC10C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x806FC10C: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_10:
    // 0x806FC110: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    // 0x806FC114: jal         0x80067818
    // 0x806FC118: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x806FC118: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
L_806FC11C:
    // 0x806FC11C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_806FC120:
    // 0x806FC120: jal         0x806FBA08
    // 0x806FC124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_806FBA08(rdram, ctx);
        goto after_12;
    // 0x806FC124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x806FC128: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x806FC12C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x806FC130: addiu       $a0, $s0, 0x14A8
    ctx->r4 = ADD32(ctx->r16, 0X14A8);
    // 0x806FC134: jal         0x806FBAE8
    // 0x806FC138: lw          $a1, 0x14AC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14AC);
    func_806FBAE8(rdram, ctx);
        goto after_13;
    // 0x806FC138: lw          $a1, 0x14AC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14AC);
    after_13:
    // 0x806FC13C: lwc1        $f4, 0x14A4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FC140: lwc1        $f6, 0x14A8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14A8);
    // 0x806FC144: lw          $t1, 0x14BC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14BC);
    // 0x806FC148: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x806FC14C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806FC150: bne         $t1, $zero, L_806FC1A4
    if (ctx->r9 != 0) {
        // 0x806FC154: swc1        $f8, 0x14A4($s0)
        MEM_W(0X14A4, ctx->r16) = ctx->f8.u32l;
            goto L_806FC1A4;
    }
    // 0x806FC154: swc1        $f8, 0x14A4($s0)
    MEM_W(0X14A4, ctx->r16) = ctx->f8.u32l;
    // 0x806FC158: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x806FC15C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FC160: lwc1        $f16, 0x14A4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FC164: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806FC168: nop

    // 0x806FC16C: bc1fl       L_806FC1DC
    if (!c1cs) {
        // 0x806FC170: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806FC1DC;
    }
    goto skip_5;
    // 0x806FC170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x806FC174: lw          $t2, 0x14C0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C0);
    // 0x806FC178: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806FC17C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806FC180: beql        $t2, $zero, L_806FC19C
    if (ctx->r10 == 0) {
        // 0x806FC184: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_806FC19C;
    }
    goto skip_6;
    // 0x806FC184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_6:
    // 0x806FC188: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FC18C: sw          $t3, 0x14BC($s0)
    MEM_W(0X14BC, ctx->r16) = ctx->r11;
    // 0x806FC190: b           L_806FC1D8
    // 0x806FC194: swc1        $f18, 0x14AC($s0)
    MEM_W(0X14AC, ctx->r16) = ctx->f18.u32l;
        goto L_806FC1D8;
    // 0x806FC194: swc1        $f18, 0x14AC($s0)
    MEM_W(0X14AC, ctx->r16) = ctx->f18.u32l;
    // 0x806FC198: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_806FC19C:
    // 0x806FC19C: b           L_806FC1D8
    // 0x806FC1A0: swc1        $f4, 0x14AC($s0)
    MEM_W(0X14AC, ctx->r16) = ctx->f4.u32l;
        goto L_806FC1D8;
    // 0x806FC1A0: swc1        $f4, 0x14AC($s0)
    MEM_W(0X14AC, ctx->r16) = ctx->f4.u32l;
L_806FC1A4:
    // 0x806FC1A4: lwc1        $f6, 0x14A4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14A4);
    // 0x806FC1A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FC1AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FC1B0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806FC1B4: nop

    // 0x806FC1B8: bc1fl       L_806FC1DC
    if (!c1cs) {
        // 0x806FC1BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806FC1DC;
    }
    goto skip_7;
    // 0x806FC1BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x806FC1C0: lw          $t4, 0x14C0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14C0);
    // 0x806FC1C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FC1C8: sw          $zero, 0x14BC($s0)
    MEM_W(0X14BC, ctx->r16) = 0;
    // 0x806FC1CC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x806FC1D0: sw          $t5, 0x14C0($s0)
    MEM_W(0X14C0, ctx->r16) = ctx->r13;
    // 0x806FC1D4: swc1        $f10, 0x14AC($s0)
    MEM_W(0X14AC, ctx->r16) = ctx->f10.u32l;
L_806FC1D8:
    // 0x806FC1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FC1DC:
    // 0x806FC1DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806FC1E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806FC1E4: jr          $ra
    // 0x806FC1E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806FC1E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80566328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8056632C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566330: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80566334: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(372, 0X3A0) << 16);
    // 0x80566338: addiu       $t6, $t6, 0x6400
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(372, 0X3A0));
    // 0x8056633C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80566340: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80566344: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80566348: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8056634C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80566350: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x80566354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80566358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8056635C: jal         0x805663A0
    // 0x80566360: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805663A0(rdram, ctx);
        goto after_0;
    // 0x80566360: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80566364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566368: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(372, 0X230) << 16);
    // 0x8056636C: addiu       $t9, $t9, 0x6290
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(372, 0X230));
    // 0x80566370: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x80566374: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80566378: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8056637C: jal         0x80045A34
    // 0x80566380: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80566380: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_1:
    // 0x80566384: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566388: jal         0x80566320
    // 0x8056638C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_80566320(rdram, ctx);
        goto after_2;
    // 0x8056638C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_2:
    // 0x80566390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566398: jr          $ra
    // 0x8056639C: nop

    return;
    // 0x8056639C: nop

;}
RECOMP_FUNC void func_8043DCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DCDC: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(92, 0XBC0) << 16);
    // 0x8043DCE0: addiu       $t6, $t6, -0x2400
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(92, 0XBC0));
    // 0x8043DCE4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8043DCE8: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8043DCEC: jr          $ra
    // 0x8043DCF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8043DCF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8057F18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F18C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8057F190: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8057F194: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8057F198: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8057F19C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057F1A0: jal         0x8057EFA0
    // 0x8057F1A4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8057EFA0(rdram, ctx);
        goto after_0;
    // 0x8057F1A4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8057F1A8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8057F1AC: bltz        $v0, L_8057F1D0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8057F1B0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8057F1D0;
    }
    // 0x8057F1B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8057F1B4:
    // 0x8057F1B4: jal         0x800447C8
    // 0x8057F1B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8057F1B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x8057F1BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8057F1C0: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8057F1C4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8057F1C8: beq         $at, $zero, L_8057F1B4
    if (ctx->r1 == 0) {
        // 0x8057F1CC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8057F1B4;
    }
    // 0x8057F1CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8057F1D0:
    // 0x8057F1D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8057F1D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057F1D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8057F1DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8057F1E0: jr          $ra
    // 0x8057F1E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8057F1E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806D30C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D30C4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806D30C8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x806D30CC: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806D30D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D30D4: nop

    // 0x806D30D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806D30DC: nop

    // 0x806D30E0: bc1fl       L_806D3110
    if (!c1cs) {
        // 0x806D30E4: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806D3110;
    }
    goto skip_0;
    // 0x806D30E4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x806D30E8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806D30EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806D30F0: nop

    // 0x806D30F4: bc1f        L_806D312C
    if (!c1cs) {
        // 0x806D30F8: nop
    
            goto L_806D312C;
    }
    // 0x806D30F8: nop

    // 0x806D30FC: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806D3100: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x806D3104: jr          $ra
    // 0x806D3108: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x806D3108: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x806D310C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_806D3110:
    // 0x806D3110: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806D3114: nop

    // 0x806D3118: bc1f        L_806D312C
    if (!c1cs) {
        // 0x806D311C: nop
    
            goto L_806D312C;
    }
    // 0x806D311C: nop

    // 0x806D3120: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806D3124: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x806D3128: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_806D312C:
    // 0x806D312C: jr          $ra
    // 0x806D3130: nop

    return;
    // 0x806D3130: nop

;}
RECOMP_FUNC void func_805E10B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E10B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805E10B8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805E10BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805E10C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E10C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E10C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E10CC: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
    // 0x805E10D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805E10D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805E10D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E10DC: jal         0x80048F84
    // 0x805E10E0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805E10E0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805E10E4: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x805E10E8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805E10EC: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805E10F0: beq         $t6, $zero, L_805E1114
    if (ctx->r14 == 0) {
        // 0x805E10F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805E1114;
    }
    // 0x805E10F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E10F8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805E10FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805E1100: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805E1104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805E1108: nop

    // 0x805E110C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805E1110: nop

L_805E1114:
    // 0x805E1114: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x805E1118: addiu       $at, $zero, 0x453A
    ctx->r1 = ADD32(0, 0X453A);
    // 0x805E111C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805E1120: beq         $t7, $at, L_805E1140
    if (ctx->r15 == ctx->r1) {
        // 0x805E1124: lui         $at, 0x805E
        ctx->r1 = S32(RELOC_HI16(483, 0X6B0) << 16);
            goto L_805E1140;
    }
    // 0x805E1124: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6B0) << 16);
    // 0x805E1128: lwc1        $f10, 0x1340($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6B0));
    // 0x805E112C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805E1130: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x805E1134: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x805E1138: b           L_805E1180
    // 0x805E113C: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
        goto L_805E1180;
    // 0x805E113C: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
L_805E1140:
    // 0x805E1140: lh          $t8, 0x144($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X144);
    // 0x805E1144: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6B8) << 16);
    // 0x805E1148: bne         $t8, $zero, L_805E116C
    if (ctx->r24 != 0) {
        // 0x805E114C: nop
    
            goto L_805E116C;
    }
    // 0x805E114C: nop

    // 0x805E1150: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6B4) << 16);
    // 0x805E1154: lwc1        $f6, 0x1344($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6B4));
    // 0x805E1158: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805E115C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x805E1160: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x805E1164: b           L_805E1180
    // 0x805E1168: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_805E1180;
    // 0x805E1168: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_805E116C:
    // 0x805E116C: lwc1        $f18, 0x1348($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6B8));
    // 0x805E1170: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805E1174: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x805E1178: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x805E117C: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
L_805E1180:
    // 0x805E1180: jal         0x800475EC
    // 0x805E1184: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_800475EC(rdram, ctx);
        goto after_1;
    // 0x805E1184: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_1:
    // 0x805E1188: beql        $v0, $zero, L_805E11A8
    if (ctx->r2 == 0) {
        // 0x805E118C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805E11A8;
    }
    goto skip_0;
    // 0x805E118C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805E1190: jal         0x8005FE48
    // 0x805E1194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x805E1194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805E1198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E119C: jal         0x805E11E0
    // 0x805E11A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_805E11E0(rdram, ctx);
        goto after_3;
    // 0x805E11A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x805E11A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805E11A8:
    // 0x805E11A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E11AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805E11B0: jr          $ra
    // 0x805E11B4: nop

    return;
    // 0x805E11B4: nop

;}
RECOMP_FUNC void func_8078F83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078F840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F844: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8078F848: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x8078F84C: bnel        $t6, $at, L_8078F860
    if (ctx->r14 != ctx->r1) {
        // 0x8078F850: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F860;
    }
    goto skip_0;
    // 0x8078F850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078F854: jal         0x8078FD84
    // 0x8078F858: nop

    func_8078FD84(rdram, ctx);
        goto after_0;
    // 0x8078F858: nop

    after_0:
    // 0x8078F85C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078F860:
    // 0x8078F860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078F864: jr          $ra
    // 0x8078F868: nop

    return;
    // 0x8078F868: nop

;}
RECOMP_FUNC void func_805DA298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DA29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA2A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805DA2A4: jal         0x80047090
    // 0x805DA2A8: addiu       $a0, $zero, 0x453C
    ctx->r4 = ADD32(0, 0X453C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805DA2A8: addiu       $a0, $zero, 0x453C
    ctx->r4 = ADD32(0, 0X453C);
    after_0:
    // 0x805DA2AC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805DA2B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x805DA2B4: beq         $v0, $at, L_805DA31C
    if (ctx->r2 == ctx->r1) {
        // 0x805DA2B8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805DA31C;
    }
    // 0x805DA2B8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805DA2BC: lui         $at, 0x453C
    ctx->r1 = S32(0X453C << 16);
    // 0x805DA2C0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x805DA2C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x805DA2C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DA2CC: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(477, 0XBAC) << 16);
    // 0x805DA2D0: lwc1        $f16, -0x5414($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(477, 0XBAC));
    // 0x805DA2D4: lwc1        $f4, 0x88($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X88);
    // 0x805DA2D8: lwc1        $f10, 0x8C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x805DA2DC: lw          $a1, 0x84($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X84);
    // 0x805DA2E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805DA2E4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805DA2E8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x805DA2EC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x805DA2F0: jal         0x8004613C
    // 0x805DA2F4: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805DA2F4: nop

    after_1:
    // 0x805DA2F8: beq         $v0, $zero, L_805DA31C
    if (ctx->r2 == 0) {
        // 0x805DA2FC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805DA31C;
    }
    // 0x805DA2FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805DA300: jal         0x80044194
    // 0x805DA304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805DA304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x805DA308: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x805DA30C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805DA310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805DA314: nop

    // 0x805DA318: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
L_805DA31C:
    // 0x805DA31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DA324: jr          $ra
    // 0x805DA328: nop

    return;
    // 0x805DA328: nop

;}
RECOMP_FUNC void func_800679B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800679B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800679B8: jal         0x80010730
    // 0x800679BC: nop

    func_80010730(rdram, ctx);
        goto after_0;
    // 0x800679BC: nop

    after_0:
    // 0x800679C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800679C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800679C8: jr          $ra
    // 0x800679CC: nop

    return;
    // 0x800679CC: nop

;}
RECOMP_FUNC void func_80450A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80450A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80450A80: jal         0x80046E88
    // 0x80450A84: addiu       $a0, $zero, 0x40EE
    ctx->r4 = ADD32(0, 0X40EE);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x80450A84: addiu       $a0, $zero, 0x40EE
    ctx->r4 = ADD32(0, 0X40EE);
    after_0:
    // 0x80450A88: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80450A8C: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80450A90: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(98, 0X13C9C) << 16);
    // 0x80450A94: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x80450A98: addiu       $t8, $t8, -0x7F84
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(98, 0X13C9C));
    // 0x80450A9C: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    // 0x80450AA0: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80450AA4: beq         $v0, $zero, L_80450AC0
    if (ctx->r2 == 0) {
        // 0x80450AA8: lw          $a3, 0x6D10($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X6D10);
            goto L_80450AC0;
    }
    // 0x80450AA8: lw          $a3, 0x6D10($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6D10);
    // 0x80450AAC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80450AB0: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x80450AB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80450AB8: jal         0x80065490
    // 0x80450ABC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x80450ABC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
L_80450AC0:
    // 0x80450AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80450AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450AC8: jr          $ra
    // 0x80450ACC: nop

    return;
    // 0x80450ACC: nop

;}
RECOMP_FUNC void nearbyintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082088: round.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = lroundf(ctx->f12.fl);
    // 0x8008208C: jr          $ra
    // 0x80082090: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x80082090: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_8042B86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042B86C: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x8042B870: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x8042B874: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8042B878: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8042B87C: addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // 0x8042B880: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8042B884: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042B888: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8042B88C: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x8042B890: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x8042B894: sw          $a2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r6;
    // 0x8042B898: jr          $ra
    // 0x8042B89C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x8042B89C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8041E244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041E248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E24C: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041E250: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041E254: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x8041E258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8041E25C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8041E260: jal         0x80065728
    // 0x8041E264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8041E264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041E268: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x8041E26C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8041E270: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8041E274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041E278: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8041E27C: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8041E280: sh          $t6, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r14;
    // 0x8041E284: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8041E288: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8041E28C: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8041E290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8041E298: jr          $ra
    // 0x8041E29C: nop

    return;
    // 0x8041E29C: nop

;}
RECOMP_FUNC void func_80475AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475AE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475AE4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475AE8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80475AEC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475AF0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475AF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475AF8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80475AFC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475B00: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475B04: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475B08: jr          $ra
    // 0x80475B0C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80475B0C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807C65D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C65D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C65DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C65E0: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x807C65E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807C65E8: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x807C65EC: addiu       $t7, $t6, 0x4C
    ctx->r15 = ADD32(ctx->r14, 0X4C);
    // 0x807C65F0: jal         0x80045A34
    // 0x807C65F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807C65F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x807C65F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807C65FC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807C6600: bne         $v0, $zero, L_807C6618
    if (ctx->r2 != 0) {
        // 0x807C6604: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807C6618;
    }
    // 0x807C6604: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807C6608: jal         0x800445A4
    // 0x807C660C: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x807C660C: nop

    after_1:
    // 0x807C6610: b           L_807C66C0
    // 0x807C6614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C66C0;
    // 0x807C6614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C6618:
    // 0x807C6618: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x807C661C: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(913, 0X920) << 16);
    // 0x807C6620: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807C6624: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807C6628: addiu       $t8, $t8, 0x6710
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(913, 0X920));
    // 0x807C662C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x807C6630: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807C6634: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C6638: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x807C663C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x807C6640: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x807C6644: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x807C6648: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807C664C: sw          $t0, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r8;
    // 0x807C6650: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    // 0x807C6654: lui         $at, 0xC321
    ctx->r1 = S32(0XC321 << 16);
    // 0x807C6658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C665C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x807C6660: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807C6664: addiu       $t2, $zero, 0x5DC
    ctx->r10 = ADD32(0, 0X5DC);
    // 0x807C6668: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(913, 0X974) << 16);
    // 0x807C666C: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x807C6670: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x807C6674: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x807C6678: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807C667C: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x807C6680: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x807C6684: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x807C6688: lwc1        $f10, 0x6764($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(913, 0X974));
    // 0x807C668C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x807C6690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C6694: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x807C6698: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x807C669C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807C66A0: sh          $t3, 0x30($t4)
    MEM_H(0X30, ctx->r12) = ctx->r11;
    // 0x807C66A4: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x807C66A8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807C66AC: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807C66B0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x807C66B4: jal         0x807C66CC
    // 0x807C66B8: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    func_807C66CC(rdram, ctx);
        goto after_2;
    // 0x807C66B8: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    after_2:
    // 0x807C66BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C66C0:
    // 0x807C66C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C66C4: jr          $ra
    // 0x807C66C8: nop

    return;
    // 0x807C66C8: nop

;}
RECOMP_FUNC void func_80475540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475540: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475544: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475548: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047554C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475550: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475554: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475558: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047555C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475560: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475564: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475568: jr          $ra
    // 0x8047556C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047556C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805DC0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC0A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DC0AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DC0B0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805DC0B4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC0B8: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x805DC0BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805DC0C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC0C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805DC0C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805DC0CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x805DC0D0: jal         0x805DD234
    // 0x805DC0D4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_805DD234(rdram, ctx);
        goto after_0;
    // 0x805DC0D4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x805DC0D8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2864) << 16);
    // 0x805DC0DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DC0E0: lwc1        $f4, -0x2A9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X2864));
    // 0x805DC0E4: jal         0x80062D14
    // 0x805DC0E8: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805DC0E8: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x805DC0EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC0F0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2868) << 16);
    // 0x805DC0F4: lwc1        $f8, -0x2A98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X2868));
    // 0x805DC0F8: lwc1        $f6, 0x60($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X60);
    // 0x805DC0FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DC100: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805DC104: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805DC108: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805DC10C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DC110: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x805DC114: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805DC118: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x805DC11C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805DC120: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x805DC124: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805DC128: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x805DC12C: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x805DC130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DC134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DC138: jr          $ra
    // 0x805DC13C: nop

    return;
    // 0x805DC13C: nop

;}
RECOMP_FUNC void func_80526254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052625C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80526260: jal         0x80064E84
    // 0x80526264: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80526264: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80526268: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8052626C: jal         0x80064E84
    // 0x80526270: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80526270: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_1:
    // 0x80526274: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80526278: jal         0x80064E84
    // 0x8052627C: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8052627C: lw          $a0, 0x24($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X24);
    after_2:
    // 0x80526280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526288: jr          $ra
    // 0x8052628C: nop

    return;
    // 0x8052628C: nop

;}
RECOMP_FUNC void func_80566F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566F28: jal         0x80566E48
    // 0x80566F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80566F2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566F34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80566F38: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80566F3C: jal         0x805670F4
    // 0x80566F40: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_805670F4(rdram, ctx);
        goto after_1;
    // 0x80566F40: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x80566F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566F4C: jr          $ra
    // 0x80566F50: nop

    return;
    // 0x80566F50: nop

;}
RECOMP_FUNC void func_8005772C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005772C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80057730: beq         $a0, $zero, L_8005774C
    if (ctx->r4 == 0) {
        // 0x80057734: nop
    
            goto L_8005774C;
    }
    // 0x80057734: nop

    // 0x80057738: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8005773C: beq         $t6, $zero, L_8005774C
    if (ctx->r14 == 0) {
        // 0x80057740: nop
    
            goto L_8005774C;
    }
    // 0x80057740: nop

    // 0x80057744: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80057748: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
L_8005774C:
    // 0x8005774C: jr          $ra
    // 0x80057750: nop

    return;
    // 0x80057750: nop

;}
RECOMP_FUNC void func_806DF050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF050: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x806DF054: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806DF058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806DF05C: bne         $t6, $at, L_806DF078
    if (ctx->r14 != ctx->r1) {
        // 0x806DF060: nop
    
            goto L_806DF078;
    }
    // 0x806DF060: nop

    // 0x806DF064: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x806DF068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DF06C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x806DF070: jr          $ra
    // 0x806DF074: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    return;
    // 0x806DF074: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_806DF078:
    // 0x806DF078: jr          $ra
    // 0x806DF07C: nop

    return;
    // 0x806DF07C: nop

;}
RECOMP_FUNC void func_804C1CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1CB8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804C1CBC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804C1CC0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C1CC4: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(203, 0XFD0) << 16);
    // 0x804C1CC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C1CCC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804C1CD0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C1CD4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C1CD8: lw          $t8, 0x2740($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(203, 0XFD0));
    // 0x804C1CDC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804C1CE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C1CE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C1CE8: jal         0x80048490
    // 0x804C1CEC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804C1CEC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804C1CF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C1CF4: jal         0x80048378
    // 0x804C1CF8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804C1CF8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804C1CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C1D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1D04: jr          $ra
    // 0x804C1D08: nop

    return;
    // 0x804C1D08: nop

;}
RECOMP_FUNC void func_804C3530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C353C: jal         0x80045A34
    // 0x804C3540: addiu       $a1, $zero, 0x6D8
    ctx->r5 = ADD32(0, 0X6D8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C3540: addiu       $a1, $zero, 0x6D8
    ctx->r5 = ADD32(0, 0X6D8);
    after_0:
    // 0x804C3544: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C3548: bne         $v0, $zero, L_804C3558
    if (ctx->r2 != 0) {
        // 0x804C354C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804C3558;
    }
    // 0x804C354C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C3550: b           L_804C3564
    // 0x804C3554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C3564;
    // 0x804C3554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C3558:
    // 0x804C3558: jal         0x804C350C
    // 0x804C355C: nop

    func_804C350C(rdram, ctx);
        goto after_1;
    // 0x804C355C: nop

    after_1:
    // 0x804C3560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C3564:
    // 0x804C3564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C356C: jr          $ra
    // 0x804C3570: nop

    return;
    // 0x804C3570: nop

;}
RECOMP_FUNC void func_8041DEAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DEAC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8041DEB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041DEB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041DEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041DEBC: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x8041DEC0: jal         0x80062D14
    // 0x8041DEC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80062D14(rdram, ctx);
        goto after_0;
    // 0x8041DEC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041DEC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041DECC: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x8041DED0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8041DED4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8041DED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041DEDC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8041DEE0: beq         $v0, $at, L_8041DEFC
    if (ctx->r2 == ctx->r1) {
        // 0x8041DEE4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8041DEFC;
    }
    // 0x8041DEE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8041DEE8: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x8041DEEC: beql        $v0, $at, L_8041DF28
    if (ctx->r2 == ctx->r1) {
        // 0x8041DEF0: lui         $at, 0x4367
        ctx->r1 = S32(0X4367 << 16);
            goto L_8041DF28;
    }
    goto skip_0;
    // 0x8041DEF0: lui         $at, 0x4367
    ctx->r1 = S32(0X4367 << 16);
    skip_0:
    // 0x8041DEF4: b           L_8041DF48
    // 0x8041DEF8: nop

        goto L_8041DF48;
    // 0x8041DEF8: nop

L_8041DEFC:
    // 0x8041DEFC: lui         $at, 0x4367
    ctx->r1 = S32(0X4367 << 16);
    // 0x8041DF00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041DF04: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041DF08: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8041DF0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041DF10: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8041DF14: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x8041DF18: swc1        $f16, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f16.u32l;
    // 0x8041DF1C: b           L_8041DF48
    // 0x8041DF20: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
        goto L_8041DF48;
    // 0x8041DF20: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8041DF24: lui         $at, 0x4367
    ctx->r1 = S32(0X4367 << 16);
L_8041DF28:
    // 0x8041DF28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041DF2C: lwc1        $f18, 0x3C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041DF30: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8041DF34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041DF38: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8041DF3C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8041DF40: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8041DF44: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_8041DF48:
    // 0x8041DF48: jal         0x8041FE10
    // 0x8041DF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8041FE10(rdram, ctx);
        goto after_1;
    // 0x8041DF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8041DF50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041DF54: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34E4) << 16);
    // 0x8041DF58: lwc1        $f0, 0xB44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34E4));
    // 0x8041DF5C: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8041DF60: lwc1        $f18, 0x7C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8041DF64: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(29, 0X2FE0) << 16);
    // 0x8041DF68: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8041DF6C: nop

    // 0x8041DF70: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8041DF74: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x8041DF78: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x8041DF7C: lw          $t7, 0x640($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(29, 0X2FE0));
    // 0x8041DF80: bne         $t7, $zero, L_8041DF90
    if (ctx->r15 != 0) {
        // 0x8041DF84: nop
    
            goto L_8041DF90;
    }
    // 0x8041DF84: nop

    // 0x8041DF88: jal         0x800447C8
    // 0x8041DF8C: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8041DF8C: nop

    after_2:
L_8041DF90:
    // 0x8041DF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041DF94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041DF98: jr          $ra
    // 0x8041DF9C: nop

    return;
    // 0x8041DF9C: nop

;}
RECOMP_FUNC void func_8004F42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F42C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8004F430: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8004F434: lh          $v0, 0x2($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2);
    // 0x8004F438: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8004F43C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8004F440: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004F444: jr          $ra
    // 0x8004F448: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x8004F448: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_80535BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535BC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535BC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535BCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535BD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535BD8: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X12D0) << 16);
    // 0x80535BDC: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X12E4) << 16);
    // 0x80535BE0: addiu       $a1, $a1, 0x6B74
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X12E4));
    // 0x80535BE4: addiu       $a2, $a2, 0x6B60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X12D0));
    // 0x80535BE8: jal         0x80535958
    // 0x80535BEC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535BEC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80535BF0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535BF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535BF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535BFC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535C00: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535C04: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535C10: jr          $ra
    // 0x80535C14: nop

    return;
    // 0x80535C14: nop

;}
RECOMP_FUNC void func_804B9890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B9894: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804B9898: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804B989C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804B98A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B98A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804B98A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804B98AC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804B98B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804B98B4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804B98B8: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(185, 0X2A58) << 16);
    // 0x804B98BC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804B98C0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804B98C4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804B98C8: lw          $t2, -0x5788($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(185, 0X2A58));
    // 0x804B98CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804B98D0: jal         0x804B9400
    // 0x804B98D4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804B9400(rdram, ctx);
        goto after_0;
    // 0x804B98D4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804B98D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B98DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B98E0: jr          $ra
    // 0x804B98E4: nop

    return;
    // 0x804B98E4: nop

;}
RECOMP_FUNC void func_8069942C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069942C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80699430: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80699434: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80699438: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8069943C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80699440: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80699444: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80699448: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8069944C: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(559, 0XD0) << 16);
    // 0x80699450: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80699454: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80699458: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8069945C: lw          $t1, -0x6B80($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(559, 0XD0));
    // 0x80699460: jr          $ra
    // 0x80699464: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80699464: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80699468: nop

    // 0x8069946C: nop

;}
RECOMP_FUNC void func_804C98B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C98B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C98B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C98B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C98BC: jal         0x804C9808
    // 0x804C98C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C9808(rdram, ctx);
        goto after_0;
    // 0x804C98C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C98C4: beq         $v0, $zero, L_804C992C
    if (ctx->r2 == 0) {
        // 0x804C98C8: addiu       $t6, $zero, 0xFF
        ctx->r14 = ADD32(0, 0XFF);
            goto L_804C992C;
    }
    // 0x804C98C8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804C98CC: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804C98D0: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(228, 0X790) << 16);
    // 0x804C98D4: sw          $t6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r14;
    // 0x804C98D8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804C98DC: addiu       $t7, $t7, -0x6530
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(228, 0X790));
    // 0x804C98E0: lui         $t0, 0x804D
    ctx->r8 = S32(RELOC_HI16(228, 0X3DC) << 16);
    // 0x804C98E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804C98E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C98EC: addiu       $t0, $t0, -0x68E4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(228, 0X3DC));
    // 0x804C98F0: sb          $t9, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r25;
    // 0x804C98F4: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x804C98F8: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x804C98FC: jal         0x804C9898
    // 0x804C9900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C9898(rdram, ctx);
        goto after_1;
    // 0x804C9900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C9904: jal         0x804C9518
    // 0x804C9908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C9518(rdram, ctx);
        goto after_2;
    // 0x804C9908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804C990C: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x804C9910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C9914: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C9918: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x804C991C: sb          $v0, 0x74($t2)
    MEM_B(0X74, ctx->r10) = ctx->r2;
    // 0x804C9920: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x804C9924: sw          $zero, 0x14($t3)
    MEM_W(0X14, ctx->r11) = 0;
    // 0x804C9928: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
L_804C992C:
    // 0x804C992C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C9930: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C9934: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C9938: jr          $ra
    // 0x804C993C: nop

    return;
    // 0x804C993C: nop

;}
RECOMP_FUNC void func_805564FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805564FC: lw          $t6, 0x548($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X548);
    // 0x80556500: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80556504: sw          $t7, 0x548($a1)
    MEM_W(0X548, ctx->r5) = ctx->r15;
    // 0x80556508: bgez        $t7, L_80556518
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8055650C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80556518;
    }
    // 0x8055650C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80556510: addiu       $v0, $t7, 0x3C
    ctx->r2 = ADD32(ctx->r15, 0X3C);
    // 0x80556514: sw          $v0, 0x548($a1)
    MEM_W(0X548, ctx->r5) = ctx->r2;
L_80556518:
    // 0x80556518: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8055651C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80556520: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80556524: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80556528: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x8055652C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80556530: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80556534: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80556538: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8055653C: jr          $ra
    // 0x80556540: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    return;
    // 0x80556540: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8001D908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D908: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8001D90C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8001D910: lw          $v1, 0x2C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X2C);
    // 0x8001D914: lw          $a3, 0x30($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X30);
    // 0x8001D918: lw          $t0, 0x34($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X34);
    // 0x8001D91C: lw          $t1, 0x38($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X38);
    // 0x8001D920: beq         $v1, $zero, L_8001DBE4
    if (ctx->r3 == 0) {
        // 0x8001D924: sw          $a1, 0x3C($a2)
        MEM_W(0X3C, ctx->r6) = ctx->r5;
            goto L_8001DBE4;
    }
    // 0x8001D924: sw          $a1, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r5;
    // 0x8001D928: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8001D92C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8001D930: beq         $a0, $zero, L_8001D9DC
    if (ctx->r4 == 0) {
        // 0x8001D934: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8001D9DC;
    }
    // 0x8001D934: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8001D938: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001D93C: beq         $v0, $v1, L_8001D994
    if (ctx->r2 == ctx->r3) {
        // 0x8001D940: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8001D994;
    }
    // 0x8001D940: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
L_8001D944:
    // 0x8001D944: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001D948: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001D94C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001D950: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D954: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001D958: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8001D95C: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8001D960: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8001D964: lh          $t7, -0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, -0X4);
    // 0x8001D968: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001D96C: nop

    // 0x8001D970: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D974: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x8001D978: lh          $t8, -0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X2);
    // 0x8001D97C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8001D980: nop

    // 0x8001D984: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D988: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8001D98C: bne         $v0, $v1, L_8001D944
    if (ctx->r2 != ctx->r3) {
        // 0x8001D990: lh          $t6, 0x0($a1)
        ctx->r14 = MEM_H(ctx->r5, 0X0);
            goto L_8001D944;
    }
    // 0x8001D990: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
L_8001D994:
    // 0x8001D994: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001D998: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001D99C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001D9A0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D9A4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8001D9A8: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8001D9AC: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8001D9B0: lh          $t7, -0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, -0X4);
    // 0x8001D9B4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001D9B8: nop

    // 0x8001D9BC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D9C0: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x8001D9C4: lh          $t8, -0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X2);
    // 0x8001D9C8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8001D9CC: nop

    // 0x8001D9D0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D9D4: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8001D9D8: beq         $v1, $zero, L_8001DBE4
    if (ctx->r3 == 0) {
        // 0x8001D9DC: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_8001DBE4;
    }
L_8001D9DC:
    // 0x8001D9DC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001D9E0: beq         $v1, $zero, L_8001DAEC
    if (ctx->r3 == 0) {
        // 0x8001D9E4: lh          $t9, 0x0($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X0);
            goto L_8001DAEC;
    }
    // 0x8001D9E4: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
L_8001D9E8:
    // 0x8001D9E8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001D9EC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001D9F0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001D9F4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D9F8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001D9FC: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x8001DA00: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8001DA04: swc1        $f18, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f18.u32l;
    // 0x8001DA08: lh          $t2, -0x16($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X16);
    // 0x8001DA0C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8001DA10: nop

    // 0x8001DA14: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA18: swc1        $f18, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f18.u32l;
    // 0x8001DA1C: lh          $t3, -0x14($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X14);
    // 0x8001DA20: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8001DA24: nop

    // 0x8001DA28: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA2C: swc1        $f18, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->f18.u32l;
    // 0x8001DA30: lh          $t4, -0x12($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X12);
    // 0x8001DA34: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8001DA38: nop

    // 0x8001DA3C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA40: swc1        $f18, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8001DA44: lh          $t5, -0x10($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X10);
    // 0x8001DA48: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8001DA4C: nop

    // 0x8001DA50: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA54: swc1        $f18, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f18.u32l;
    // 0x8001DA58: lh          $t6, -0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, -0XE);
    // 0x8001DA5C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001DA60: nop

    // 0x8001DA64: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA68: swc1        $f18, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8001DA6C: lh          $t7, -0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, -0XC);
    // 0x8001DA70: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001DA74: nop

    // 0x8001DA78: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA7C: swc1        $f18, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8001DA80: lh          $t8, -0xA($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XA);
    // 0x8001DA84: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8001DA88: nop

    // 0x8001DA8C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA90: swc1        $f18, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f18.u32l;
    // 0x8001DA94: lh          $t9, -0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X8);
    // 0x8001DA98: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001DA9C: nop

    // 0x8001DAA0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DAA4: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x8001DAA8: lh          $t2, -0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X6);
    // 0x8001DAAC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8001DAB0: nop

    // 0x8001DAB4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DAB8: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8001DABC: lh          $t3, -0x4($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X4);
    // 0x8001DAC0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8001DAC4: nop

    // 0x8001DAC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DACC: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x8001DAD0: lh          $t4, -0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X2);
    // 0x8001DAD4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8001DAD8: nop

    // 0x8001DADC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DAE0: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8001DAE4: bne         $v1, $zero, L_8001D9E8
    if (ctx->r3 != 0) {
        // 0x8001DAE8: lh          $t9, 0x0($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X0);
            goto L_8001D9E8;
    }
    // 0x8001DAE8: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
L_8001DAEC:
    // 0x8001DAEC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001DAF0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001DAF4: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001DAF8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DAFC: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x8001DB00: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x8001DB04: swc1        $f18, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f18.u32l;
    // 0x8001DB08: lh          $t2, -0x16($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X16);
    // 0x8001DB0C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8001DB10: nop

    // 0x8001DB14: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB18: swc1        $f18, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f18.u32l;
    // 0x8001DB1C: lh          $t3, -0x14($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X14);
    // 0x8001DB20: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8001DB24: nop

    // 0x8001DB28: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB2C: swc1        $f18, -0x10($t1)
    MEM_W(-0X10, ctx->r9) = ctx->f18.u32l;
    // 0x8001DB30: lh          $t4, -0x12($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X12);
    // 0x8001DB34: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8001DB38: nop

    // 0x8001DB3C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB40: swc1        $f18, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8001DB44: lh          $t5, -0x10($a1)
    ctx->r13 = MEM_H(ctx->r5, -0X10);
    // 0x8001DB48: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8001DB4C: nop

    // 0x8001DB50: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB54: swc1        $f18, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f18.u32l;
    // 0x8001DB58: lh          $t6, -0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, -0XE);
    // 0x8001DB5C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001DB60: nop

    // 0x8001DB64: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB68: swc1        $f18, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8001DB6C: lh          $t7, -0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, -0XC);
    // 0x8001DB70: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001DB74: nop

    // 0x8001DB78: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB7C: swc1        $f18, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8001DB80: lh          $t8, -0xA($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XA);
    // 0x8001DB84: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8001DB88: nop

    // 0x8001DB8C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DB90: swc1        $f18, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f18.u32l;
    // 0x8001DB94: lh          $t9, -0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X8);
    // 0x8001DB98: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001DB9C: nop

    // 0x8001DBA0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DBA4: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x8001DBA8: lh          $t2, -0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, -0X6);
    // 0x8001DBAC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8001DBB0: nop

    // 0x8001DBB4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DBB8: swc1        $f18, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8001DBBC: lh          $t3, -0x4($a1)
    ctx->r11 = MEM_H(ctx->r5, -0X4);
    // 0x8001DBC0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8001DBC4: nop

    // 0x8001DBC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DBCC: swc1        $f18, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f18.u32l;
    // 0x8001DBD0: lh          $t4, -0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, -0X2);
    // 0x8001DBD4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8001DBD8: nop

    // 0x8001DBDC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DBE0: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
L_8001DBE4:
    // 0x8001DBE4: jr          $ra
    // 0x8001DBE8: nop

    return;
    // 0x8001DBE8: nop

;}
RECOMP_FUNC void func_80063414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063414: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80063418: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006341C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80063420: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80063424: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80063428: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006342C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80063430: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80063434: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80063438: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006343C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80063440: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80063444: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80063448: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006344C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80063450: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x80063454: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80063458: lw          $s5, 0x28($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X28);
    // 0x8006345C: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x80063460: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80063464: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80063468: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8006346C: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x80063470: beq         $at, $zero, L_80063998
    if (ctx->r1 == 0) {
        // 0x80063474: addiu       $s6, $s5, 0x2
        ctx->r22 = ADD32(ctx->r21, 0X2);
            goto L_80063998;
    }
    // 0x80063474: addiu       $s6, $s5, 0x2
    ctx->r22 = ADD32(ctx->r21, 0X2);
    // 0x80063478: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8006347C: lw          $s4, 0xC($a2)
    ctx->r20 = MEM_W(ctx->r6, 0XC);
    // 0x80063480: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063484: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80063488: addiu       $s3, $v0, 0x2
    ctx->r19 = ADD32(ctx->r2, 0X2);
    // 0x8006348C: blez        $t0, L_80063990
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80063490: addiu       $s2, $s4, 0x2
        ctx->r18 = ADD32(ctx->r20, 0X2);
            goto L_80063990;
    }
    // 0x80063490: addiu       $s2, $s4, 0x2
    ctx->r18 = ADD32(ctx->r20, 0X2);
    // 0x80063494: andi        $v1, $t0, 0x3
    ctx->r3 = ctx->r8 & 0X3;
    // 0x80063498: beq         $v1, $zero, L_800635C0
    if (ctx->r3 == 0) {
        // 0x8006349C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800635C0;
    }
    // 0x8006349C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800634A0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800634A4: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
    // 0x800634A8: beq         $v0, $s7, L_8006353C
    if (ctx->r2 == ctx->r23) {
        // 0x800634AC: lh          $t8, 0x0($s1)
        ctx->r24 = MEM_H(ctx->r17, 0X0);
            goto L_8006353C;
    }
    // 0x800634AC: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
L_800634B0:
    // 0x800634B0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800634B4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800634B8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800634BC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800634C0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800634C4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800634C8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800634CC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800634D0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800634D4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800634D8: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800634DC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800634E0: lh          $t1, -0x8($s2)
    ctx->r9 = MEM_H(ctx->r18, -0X8);
    // 0x800634E4: lh          $t2, -0x8($s3)
    ctx->r10 = MEM_H(ctx->r19, -0X8);
    // 0x800634E8: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800634EC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800634F0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800634F4: nop

    // 0x800634F8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800634FC: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80063500: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063504: lh          $t6, -0x8($s1)
    ctx->r14 = MEM_H(ctx->r17, -0X8);
    // 0x80063508: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006350C: sh          $t7, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r15;
    // 0x80063510: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063514: lh          $t1, -0x8($s3)
    ctx->r9 = MEM_H(ctx->r19, -0X8);
    // 0x80063518: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006351C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063520: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80063524: nop

    // 0x80063528: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8006352C: sh          $t2, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r10;
    // 0x80063530: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
    // 0x80063534: bne         $v0, $s7, L_800634B0
    if (ctx->r2 != ctx->r23) {
        // 0x80063538: lh          $t8, 0x0($s1)
        ctx->r24 = MEM_H(ctx->r17, 0X0);
            goto L_800634B0;
    }
    // 0x80063538: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
L_8006353C:
    // 0x8006353C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80063540: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80063544: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80063548: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8006354C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063550: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80063554: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80063558: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8006355C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063560: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x80063564: lh          $t2, -0x8($s3)
    ctx->r10 = MEM_H(ctx->r19, -0X8);
    // 0x80063568: lh          $t1, -0x8($s2)
    ctx->r9 = MEM_H(ctx->r18, -0X8);
    // 0x8006356C: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80063570: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80063574: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80063578: nop

    // 0x8006357C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063580: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80063584: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063588: lh          $t6, -0x8($s1)
    ctx->r14 = MEM_H(ctx->r17, -0X8);
    // 0x8006358C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80063590: nop

    // 0x80063594: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80063598: sh          $t7, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r15;
    // 0x8006359C: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800635A0: lh          $t1, -0x8($s3)
    ctx->r9 = MEM_H(ctx->r19, -0X8);
    // 0x800635A4: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800635A8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800635AC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800635B0: nop

    // 0x800635B4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800635B8: sh          $t2, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r10;
    // 0x800635BC: beq         $s7, $t0, L_80063988
    if (ctx->r23 == ctx->r8) {
        // 0x800635C0: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_80063988;
    }
L_800635C0:
    // 0x800635C0: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800635C4: lh          $t3, 0x0($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X0);
    // 0x800635C8: beq         $s7, $t0, L_800637AC
    if (ctx->r23 == ctx->r8) {
        // 0x800635CC: lh          $t4, 0x0($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X0);
            goto L_800637AC;
    }
    // 0x800635CC: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
L_800635D0:
    // 0x800635D0: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800635D4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800635D8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800635DC: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x800635E0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800635E4: addiu       $s6, $s6, 0x10
    ctx->r22 = ADD32(ctx->r22, 0X10);
    // 0x800635E8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x800635EC: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x800635F0: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800635F4: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x800635F8: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800635FC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x80063600: lh          $t6, -0x20($s2)
    ctx->r14 = MEM_H(ctx->r18, -0X20);
    // 0x80063604: lh          $t7, -0x20($s3)
    ctx->r15 = MEM_H(ctx->r19, -0X20);
    // 0x80063608: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8006360C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80063610: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80063614: nop

    // 0x80063618: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006361C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80063620: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063624: lh          $t2, -0x20($s1)
    ctx->r10 = MEM_H(ctx->r17, -0X20);
    // 0x80063628: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006362C: sh          $t3, -0x10($s5)
    MEM_H(-0X10, ctx->r21) = ctx->r11;
    // 0x80063630: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063634: lh          $t6, -0x20($s3)
    ctx->r14 = MEM_H(ctx->r19, -0X20);
    // 0x80063638: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006363C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063640: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80063644: nop

    // 0x80063648: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006364C: sh          $t7, -0x10($s6)
    MEM_H(-0X10, ctx->r22) = ctx->r15;
    // 0x80063650: lh          $t8, -0x18($s4)
    ctx->r24 = MEM_H(ctx->r20, -0X18);
    // 0x80063654: lh          $t9, -0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, -0X18);
    // 0x80063658: subu        $t1, $t8, $t9
    ctx->r9 = SUB32(ctx->r24, ctx->r25);
    // 0x8006365C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80063660: nop

    // 0x80063664: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063668: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006366C: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x80063670: lh          $t2, -0x18($s2)
    ctx->r10 = MEM_H(ctx->r18, -0X18);
    // 0x80063674: lh          $t3, -0x18($s3)
    ctx->r11 = MEM_H(ctx->r19, -0X18);
    // 0x80063678: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8006367C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80063680: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80063684: nop

    // 0x80063688: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006368C: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80063690: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063694: lh          $t7, -0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, -0X18);
    // 0x80063698: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006369C: sh          $t8, -0xC($s5)
    MEM_H(-0XC, ctx->r21) = ctx->r24;
    // 0x800636A0: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800636A4: lh          $t2, -0x18($s3)
    ctx->r10 = MEM_H(ctx->r19, -0X18);
    // 0x800636A8: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800636AC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800636B0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800636B4: nop

    // 0x800636B8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800636BC: sh          $t3, -0xC($s6)
    MEM_H(-0XC, ctx->r22) = ctx->r11;
    // 0x800636C0: lh          $t4, -0x10($s4)
    ctx->r12 = MEM_H(ctx->r20, -0X10);
    // 0x800636C4: lh          $t5, -0x10($s1)
    ctx->r13 = MEM_H(ctx->r17, -0X10);
    // 0x800636C8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800636CC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800636D0: nop

    // 0x800636D4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800636D8: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800636DC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800636E0: lh          $t7, -0x10($s2)
    ctx->r15 = MEM_H(ctx->r18, -0X10);
    // 0x800636E4: lh          $t8, -0x10($s3)
    ctx->r24 = MEM_H(ctx->r19, -0X10);
    // 0x800636E8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800636EC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800636F0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800636F4: nop

    // 0x800636F8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800636FC: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80063700: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063704: lh          $t3, -0x10($s1)
    ctx->r11 = MEM_H(ctx->r17, -0X10);
    // 0x80063708: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006370C: sh          $t4, -0x8($s5)
    MEM_H(-0X8, ctx->r21) = ctx->r12;
    // 0x80063710: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063714: lh          $t7, -0x10($s3)
    ctx->r15 = MEM_H(ctx->r19, -0X10);
    // 0x80063718: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006371C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063720: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80063724: nop

    // 0x80063728: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006372C: sh          $t8, -0x8($s6)
    MEM_H(-0X8, ctx->r22) = ctx->r24;
    // 0x80063730: lh          $t9, -0x8($s4)
    ctx->r25 = MEM_H(ctx->r20, -0X8);
    // 0x80063734: lh          $t1, -0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, -0X8);
    // 0x80063738: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8006373C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80063740: nop

    // 0x80063744: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063748: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006374C: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x80063750: lh          $t3, -0x8($s2)
    ctx->r11 = MEM_H(ctx->r18, -0X8);
    // 0x80063754: lh          $t4, -0x8($s3)
    ctx->r12 = MEM_H(ctx->r19, -0X8);
    // 0x80063758: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8006375C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80063760: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80063764: nop

    // 0x80063768: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006376C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80063770: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063774: lh          $t8, -0x8($s1)
    ctx->r24 = MEM_H(ctx->r17, -0X8);
    // 0x80063778: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006377C: sh          $t9, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r25;
    // 0x80063780: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063784: lh          $t3, -0x8($s3)
    ctx->r11 = MEM_H(ctx->r19, -0X8);
    // 0x80063788: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006378C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063790: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80063794: nop

    // 0x80063798: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006379C: sh          $t4, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r12;
    // 0x800637A0: lh          $t3, 0x0($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X0);
    // 0x800637A4: bne         $s7, $t0, L_800635D0
    if (ctx->r23 != ctx->r8) {
        // 0x800637A8: lh          $t4, 0x0($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X0);
            goto L_800635D0;
    }
    // 0x800637A8: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
L_800637AC:
    // 0x800637AC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800637B0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800637B4: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x800637B8: addiu       $s6, $s6, 0x10
    ctx->r22 = ADD32(ctx->r22, 0X10);
    // 0x800637BC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800637C0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x800637C4: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x800637C8: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800637CC: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x800637D0: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800637D4: lh          $t7, -0x20($s3)
    ctx->r15 = MEM_H(ctx->r19, -0X20);
    // 0x800637D8: lh          $t6, -0x20($s2)
    ctx->r14 = MEM_H(ctx->r18, -0X20);
    // 0x800637DC: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800637E0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800637E4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800637E8: nop

    // 0x800637EC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800637F0: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800637F4: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x800637F8: lh          $t2, -0x20($s1)
    ctx->r10 = MEM_H(ctx->r17, -0X20);
    // 0x800637FC: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80063800: nop

    // 0x80063804: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80063808: sh          $t3, -0x10($s5)
    MEM_H(-0X10, ctx->r21) = ctx->r11;
    // 0x8006380C: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063810: lh          $t6, -0x20($s3)
    ctx->r14 = MEM_H(ctx->r19, -0X20);
    // 0x80063814: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80063818: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8006381C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80063820: nop

    // 0x80063824: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80063828: sh          $t7, -0x10($s6)
    MEM_H(-0X10, ctx->r22) = ctx->r15;
    // 0x8006382C: lh          $t9, -0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, -0X18);
    // 0x80063830: lh          $t8, -0x18($s4)
    ctx->r24 = MEM_H(ctx->r20, -0X18);
    // 0x80063834: subu        $t1, $t8, $t9
    ctx->r9 = SUB32(ctx->r24, ctx->r25);
    // 0x80063838: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8006383C: nop

    // 0x80063840: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063844: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x80063848: lh          $t3, -0x18($s3)
    ctx->r11 = MEM_H(ctx->r19, -0X18);
    // 0x8006384C: lh          $t2, -0x18($s2)
    ctx->r10 = MEM_H(ctx->r18, -0X18);
    // 0x80063850: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80063854: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80063858: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8006385C: nop

    // 0x80063860: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063864: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80063868: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x8006386C: lh          $t7, -0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, -0X18);
    // 0x80063870: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80063874: nop

    // 0x80063878: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006387C: sh          $t8, -0xC($s5)
    MEM_H(-0XC, ctx->r21) = ctx->r24;
    // 0x80063880: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063884: lh          $t2, -0x18($s3)
    ctx->r10 = MEM_H(ctx->r19, -0X18);
    // 0x80063888: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006388C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063890: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80063894: nop

    // 0x80063898: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006389C: sh          $t3, -0xC($s6)
    MEM_H(-0XC, ctx->r22) = ctx->r11;
    // 0x800638A0: lh          $t5, -0x10($s1)
    ctx->r13 = MEM_H(ctx->r17, -0X10);
    // 0x800638A4: lh          $t4, -0x10($s4)
    ctx->r12 = MEM_H(ctx->r20, -0X10);
    // 0x800638A8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800638AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800638B0: nop

    // 0x800638B4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800638B8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800638BC: lh          $t8, -0x10($s3)
    ctx->r24 = MEM_H(ctx->r19, -0X10);
    // 0x800638C0: lh          $t7, -0x10($s2)
    ctx->r15 = MEM_H(ctx->r18, -0X10);
    // 0x800638C4: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800638C8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800638CC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800638D0: nop

    // 0x800638D4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800638D8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800638DC: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x800638E0: lh          $t3, -0x10($s1)
    ctx->r11 = MEM_H(ctx->r17, -0X10);
    // 0x800638E4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800638E8: nop

    // 0x800638EC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800638F0: sh          $t4, -0x8($s5)
    MEM_H(-0X8, ctx->r21) = ctx->r12;
    // 0x800638F4: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800638F8: lh          $t7, -0x10($s3)
    ctx->r15 = MEM_H(ctx->r19, -0X10);
    // 0x800638FC: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80063900: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063904: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80063908: nop

    // 0x8006390C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80063910: sh          $t8, -0x8($s6)
    MEM_H(-0X8, ctx->r22) = ctx->r24;
    // 0x80063914: lh          $t1, -0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, -0X8);
    // 0x80063918: lh          $t9, -0x8($s4)
    ctx->r25 = MEM_H(ctx->r20, -0X8);
    // 0x8006391C: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x80063920: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80063924: nop

    // 0x80063928: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006392C: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x80063930: lh          $t4, -0x8($s3)
    ctx->r12 = MEM_H(ctx->r19, -0X8);
    // 0x80063934: lh          $t3, -0x8($s2)
    ctx->r11 = MEM_H(ctx->r18, -0X8);
    // 0x80063938: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006393C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80063940: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80063944: nop

    // 0x80063948: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006394C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80063950: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80063954: lh          $t8, -0x8($s1)
    ctx->r24 = MEM_H(ctx->r17, -0X8);
    // 0x80063958: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8006395C: nop

    // 0x80063960: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80063964: sh          $t9, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r25;
    // 0x80063968: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8006396C: lh          $t3, -0x8($s3)
    ctx->r11 = MEM_H(ctx->r19, -0X8);
    // 0x80063970: mul.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80063974: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063978: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8006397C: nop

    // 0x80063980: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80063984: sh          $t4, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r12;
L_80063988:
    // 0x80063988: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8006398C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80063990:
    // 0x80063990: b           L_80063D58
    // 0x80063994: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
        goto L_80063D58;
    // 0x80063994: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
L_80063998:
    // 0x80063998: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x8006399C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800639A0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800639A4: jal         0x800667D4
    // 0x800639A8: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    func_800667D4(rdram, ctx);
        goto after_0;
    // 0x800639A8: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800639AC: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800639B0: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800639B4: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800639B8: lw          $v0, 0x10($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X10);
    // 0x800639BC: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800639C0: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x800639C4: bnel        $v0, $zero, L_80063AEC
    if (ctx->r2 != 0) {
        // 0x800639C8: lw          $t2, 0x14($t1)
        ctx->r10 = MEM_W(ctx->r9, 0X14);
            goto L_80063AEC;
    }
    goto skip_0;
    // 0x800639C8: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    skip_0:
    // 0x800639CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800639D0: lw          $s4, 0xC($v1)
    ctx->r20 = MEM_W(ctx->r3, 0XC);
    // 0x800639D4: lw          $s2, 0x18($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X18);
    // 0x800639D8: blez        $t0, L_80063D58
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800639DC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80063D58;
    }
    // 0x800639DC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800639E0: addiu       $fp, $sp, 0x94
    ctx->r30 = ADD32(ctx->r29, 0X94);
L_800639E4:
    // 0x800639E4: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x800639E8: addiu       $t3, $sp, 0x7C
    ctx->r11 = ADD32(ctx->r29, 0X7C);
    // 0x800639EC: addiu       $t4, $sp, 0x9C
    ctx->r12 = ADD32(ctx->r29, 0X9C);
    // 0x800639F0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800639F4: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800639F8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800639FC: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063A00: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80063A04: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80063A08: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x80063A0C: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
    // 0x80063A10: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80063A14: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80063A18: add.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x80063A1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063A20: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80063A24: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x80063A28: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80063A2C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80063A30: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80063A34: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80063A38: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x80063A3C: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80063A40: lh          $t9, 0x2($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X2);
    // 0x80063A44: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80063A48: nop

    // 0x80063A4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80063A50: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x80063A54: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    // 0x80063A58: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80063A5C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80063A60: add.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f10.fl;
    // 0x80063A64: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063A68: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x80063A6C: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x80063A70: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80063A74: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80063A78: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80063A7C: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80063A80: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80063A84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80063A88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063A8C: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80063A90: jal         0x800669C0
    // 0x80063A94: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    func_800669C0(rdram, ctx);
        goto after_1;
    // 0x80063A94: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80063A98: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80063A9C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80063AA0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80063AA4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80063AA8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80063AAC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80063AB0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80063AB4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80063AB8: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80063ABC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063AC0: sh          $t6, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r14;
    // 0x80063AC4: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063AC8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80063ACC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80063AD0: bne         $s7, $t0, L_800639E4
    if (ctx->r23 != ctx->r8) {
        // 0x80063AD4: sh          $t8, -0x4($s6)
        MEM_H(-0X4, ctx->r22) = ctx->r24;
            goto L_800639E4;
    }
    // 0x80063AD4: sh          $t8, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r24;
    // 0x80063AD8: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80063ADC: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063AE0: b           L_80063D58
    // 0x80063AE4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
        goto L_80063D58;
    // 0x80063AE4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80063AE8: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
L_80063AEC:
    // 0x80063AEC: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80063AF0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80063AF4: bne         $t2, $t3, L_80063C2C
    if (ctx->r10 != ctx->r11) {
        // 0x80063AF8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80063C2C;
    }
    // 0x80063AF8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063AFC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80063B00: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063B04: addiu       $fp, $sp, 0x94
    ctx->r30 = ADD32(ctx->r29, 0X94);
    // 0x80063B08: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80063B0C: lw          $s1, -0xC($t4)
    ctx->r17 = MEM_W(ctx->r12, -0XC);
    // 0x80063B10: lw          $s4, 0xC($t4)
    ctx->r20 = MEM_W(ctx->r12, 0XC);
    // 0x80063B14: blez        $t0, L_80063D58
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80063B18: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80063D58;
    }
    // 0x80063B18: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80063B1C:
    // 0x80063B1C: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x80063B20: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
    // 0x80063B24: addiu       $t3, $sp, 0x9C
    ctx->r11 = ADD32(ctx->r29, 0X9C);
    // 0x80063B28: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80063B2C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80063B30: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80063B34: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063B38: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80063B3C: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80063B40: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x80063B44: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x80063B48: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80063B4C: nop

    // 0x80063B50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063B54: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80063B58: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
    // 0x80063B5C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80063B60: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80063B64: nop

    // 0x80063B68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80063B6C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x80063B70: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80063B74: add.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x80063B78: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80063B7C: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x80063B80: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x80063B84: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80063B88: nop

    // 0x80063B8C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80063B90: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x80063B94: lh          $t9, 0x2($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X2);
    // 0x80063B98: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80063B9C: nop

    // 0x80063BA0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063BA4: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x80063BA8: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    // 0x80063BAC: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80063BB0: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80063BB4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80063BB8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80063BBC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80063BC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063BC4: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80063BC8: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80063BCC: add.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f10.fl;
    // 0x80063BD0: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80063BD4: jal         0x800669C0
    // 0x80063BD8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    func_800669C0(rdram, ctx);
        goto after_2;
    // 0x80063BD8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80063BDC: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80063BE0: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80063BE4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80063BE8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80063BEC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80063BF0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80063BF4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80063BF8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80063BFC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80063C00: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80063C04: sh          $t5, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r13;
    // 0x80063C08: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063C0C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80063C10: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80063C14: bne         $s7, $t0, L_80063B1C
    if (ctx->r23 != ctx->r8) {
        // 0x80063C18: sh          $t7, -0x4($s6)
        MEM_H(-0X4, ctx->r22) = ctx->r15;
            goto L_80063B1C;
    }
    // 0x80063C18: sh          $t7, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r15;
    // 0x80063C1C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80063C20: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063C24: b           L_80063D58
    // 0x80063C28: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
        goto L_80063D58;
    // 0x80063C28: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
L_80063C2C:
    // 0x80063C2C: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80063C30: lw          $s1, -0xC($t9)
    ctx->r17 = MEM_W(ctx->r25, -0XC);
    // 0x80063C34: lw          $s4, 0xC($t9)
    ctx->r20 = MEM_W(ctx->r25, 0XC);
    // 0x80063C38: lw          $s2, 0x18($t9)
    ctx->r18 = MEM_W(ctx->r25, 0X18);
    // 0x80063C3C: blez        $t0, L_80063D58
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80063C40: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80063D58;
    }
    // 0x80063C40: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80063C44: addiu       $fp, $sp, 0x94
    ctx->r30 = ADD32(ctx->r29, 0X94);
L_80063C48:
    // 0x80063C48: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x80063C4C: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x80063C50: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80063C54: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80063C58: addiu       $t1, $sp, 0x9C
    ctx->r9 = ADD32(ctx->r29, 0X9C);
    // 0x80063C5C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80063C60: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063C64: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80063C68: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80063C6C: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x80063C70: lh          $t2, 0x0($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X0);
    // 0x80063C74: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80063C78: nop

    // 0x80063C7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063C80: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80063C84: lh          $t3, 0x0($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X0);
    // 0x80063C88: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80063C8C: nop

    // 0x80063C90: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80063C94: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x80063C98: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x80063C9C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80063CA0: nop

    // 0x80063CA4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063CA8: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80063CAC: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x80063CB0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80063CB4: nop

    // 0x80063CB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063CBC: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x80063CC0: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x80063CC4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80063CC8: nop

    // 0x80063CCC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80063CD0: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x80063CD4: lh          $t7, 0x2($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X2);
    // 0x80063CD8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80063CDC: nop

    // 0x80063CE0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063CE4: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x80063CE8: lh          $t8, 0x2($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2);
    // 0x80063CEC: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80063CF0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80063CF4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80063CF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80063CFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063D00: jal         0x800669C0
    // 0x80063D04: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    func_800669C0(rdram, ctx);
        goto after_3;
    // 0x80063D04: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80063D08: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80063D0C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80063D10: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80063D14: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80063D18: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80063D1C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80063D20: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80063D24: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80063D28: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80063D2C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80063D30: sh          $t3, -0x4($s5)
    MEM_H(-0X4, ctx->r21) = ctx->r11;
    // 0x80063D34: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80063D38: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063D3C: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80063D40: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80063D44: bne         $s7, $t0, L_80063C48
    if (ctx->r23 != ctx->r8) {
        // 0x80063D48: sh          $t5, -0x4($s6)
        MEM_H(-0X4, ctx->r22) = ctx->r13;
            goto L_80063C48;
    }
    // 0x80063D48: sh          $t5, -0x4($s6)
    MEM_H(-0X4, ctx->r22) = ctx->r13;
    // 0x80063D4C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80063D50: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063D54: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
L_80063D58:
    // 0x80063D58: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80063D5C: addiu       $s4, $v0, 0x4
    ctx->r20 = ADD32(ctx->r2, 0X4);
    // 0x80063D60: addiu       $s2, $s4, 0x2
    ctx->r18 = ADD32(ctx->r20, 0X2);
    // 0x80063D64: lw          $s5, 0x28($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X28);
    // 0x80063D68: andi        $v1, $t0, 0x3
    ctx->r3 = ctx->r8 & 0X3;
    // 0x80063D6C: blez        $t0, L_80063ED8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80063D70: addiu       $s6, $s5, 0x2
        ctx->r22 = ADD32(ctx->r21, 0X2);
            goto L_80063ED8;
    }
    // 0x80063D70: addiu       $s6, $s5, 0x2
    ctx->r22 = ADD32(ctx->r21, 0X2);
    // 0x80063D74: beq         $v1, $zero, L_80063DD8
    if (ctx->r3 == 0) {
        // 0x80063D78: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80063DD8;
    }
    // 0x80063D78: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80063D7C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80063D80:
    // 0x80063D80: lh          $t7, 0x0($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X0);
    // 0x80063D84: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80063D88: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80063D8C: sh          $t7, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r15;
    // 0x80063D90: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    // 0x80063D94: sh          $zero, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = 0;
    // 0x80063D98: sh          $zero, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = 0;
    // 0x80063D9C: sh          $t8, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r24;
    // 0x80063DA0: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x80063DA4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80063DA8: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80063DAC: sh          $t9, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r25;
    // 0x80063DB0: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x80063DB4: sb          $v1, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r3;
    // 0x80063DB8: sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
    // 0x80063DBC: sb          $v1, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r3;
    // 0x80063DC0: sb          $v1, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r3;
    // 0x80063DC4: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80063DC8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063DCC: bne         $a0, $s7, L_80063D80
    if (ctx->r4 != ctx->r23) {
        // 0x80063DD0: sh          $t1, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r9;
            goto L_80063D80;
    }
    // 0x80063DD0: sh          $t1, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r9;
    // 0x80063DD4: beq         $s7, $t0, L_80063ED8
    if (ctx->r23 == ctx->r8) {
        // 0x80063DD8: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_80063ED8;
    }
L_80063DD8:
    // 0x80063DD8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80063DDC:
    // 0x80063DDC: lh          $t2, 0x0($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X0);
    // 0x80063DE0: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80063DE4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80063DE8: sh          $t2, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r10;
    // 0x80063DEC: lh          $t3, 0x0($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X0);
    // 0x80063DF0: sh          $zero, -0x3C($s0)
    MEM_H(-0X3C, ctx->r16) = 0;
    // 0x80063DF4: sh          $zero, -0x3A($s0)
    MEM_H(-0X3A, ctx->r16) = 0;
    // 0x80063DF8: sh          $t3, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r11;
    // 0x80063DFC: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x80063E00: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x80063E04: addiu       $s6, $s6, 0x10
    ctx->r22 = ADD32(ctx->r22, 0X10);
    // 0x80063E08: sh          $t4, -0x38($s0)
    MEM_H(-0X38, ctx->r16) = ctx->r12;
    // 0x80063E0C: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x80063E10: sb          $v1, -0x34($s0)
    MEM_B(-0X34, ctx->r16) = ctx->r3;
    // 0x80063E14: sb          $v1, -0x33($s0)
    MEM_B(-0X33, ctx->r16) = ctx->r3;
    // 0x80063E18: sb          $v1, -0x32($s0)
    MEM_B(-0X32, ctx->r16) = ctx->r3;
    // 0x80063E1C: sb          $v1, -0x31($s0)
    MEM_B(-0X31, ctx->r16) = ctx->r3;
    // 0x80063E20: sh          $t5, -0x36($s0)
    MEM_H(-0X36, ctx->r16) = ctx->r13;
    // 0x80063E24: lh          $t6, -0xC($s5)
    ctx->r14 = MEM_H(ctx->r21, -0XC);
    // 0x80063E28: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x80063E2C: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x80063E30: sh          $t6, -0x30($s0)
    MEM_H(-0X30, ctx->r16) = ctx->r14;
    // 0x80063E34: lh          $t7, -0xC($s6)
    ctx->r15 = MEM_H(ctx->r22, -0XC);
    // 0x80063E38: sh          $zero, -0x2A($s0)
    MEM_H(-0X2A, ctx->r16) = 0;
    // 0x80063E3C: sh          $zero, -0x2C($s0)
    MEM_H(-0X2C, ctx->r16) = 0;
    // 0x80063E40: sh          $t7, -0x2E($s0)
    MEM_H(-0X2E, ctx->r16) = ctx->r15;
    // 0x80063E44: lh          $t8, -0x18($s4)
    ctx->r24 = MEM_H(ctx->r20, -0X18);
    // 0x80063E48: sh          $t8, -0x28($s0)
    MEM_H(-0X28, ctx->r16) = ctx->r24;
    // 0x80063E4C: lh          $t9, -0x18($s2)
    ctx->r25 = MEM_H(ctx->r18, -0X18);
    // 0x80063E50: sb          $v1, -0x24($s0)
    MEM_B(-0X24, ctx->r16) = ctx->r3;
    // 0x80063E54: sb          $v1, -0x23($s0)
    MEM_B(-0X23, ctx->r16) = ctx->r3;
    // 0x80063E58: sb          $v1, -0x22($s0)
    MEM_B(-0X22, ctx->r16) = ctx->r3;
    // 0x80063E5C: sb          $v1, -0x21($s0)
    MEM_B(-0X21, ctx->r16) = ctx->r3;
    // 0x80063E60: sh          $t9, -0x26($s0)
    MEM_H(-0X26, ctx->r16) = ctx->r25;
    // 0x80063E64: lh          $t1, -0x8($s5)
    ctx->r9 = MEM_H(ctx->r21, -0X8);
    // 0x80063E68: sh          $t1, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r9;
    // 0x80063E6C: lh          $t2, -0x8($s6)
    ctx->r10 = MEM_H(ctx->r22, -0X8);
    // 0x80063E70: sh          $zero, -0x1A($s0)
    MEM_H(-0X1A, ctx->r16) = 0;
    // 0x80063E74: sh          $zero, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = 0;
    // 0x80063E78: sh          $t2, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r10;
    // 0x80063E7C: lh          $t3, -0x10($s4)
    ctx->r11 = MEM_H(ctx->r20, -0X10);
    // 0x80063E80: sh          $t3, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r11;
    // 0x80063E84: lh          $t4, -0x10($s2)
    ctx->r12 = MEM_H(ctx->r18, -0X10);
    // 0x80063E88: sb          $v1, -0x14($s0)
    MEM_B(-0X14, ctx->r16) = ctx->r3;
    // 0x80063E8C: sb          $v1, -0x13($s0)
    MEM_B(-0X13, ctx->r16) = ctx->r3;
    // 0x80063E90: sb          $v1, -0x12($s0)
    MEM_B(-0X12, ctx->r16) = ctx->r3;
    // 0x80063E94: sb          $v1, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r3;
    // 0x80063E98: sh          $t4, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = ctx->r12;
    // 0x80063E9C: lh          $t5, -0x4($s5)
    ctx->r13 = MEM_H(ctx->r21, -0X4);
    // 0x80063EA0: sh          $t5, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r13;
    // 0x80063EA4: lh          $t6, -0x4($s6)
    ctx->r14 = MEM_H(ctx->r22, -0X4);
    // 0x80063EA8: sh          $zero, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = 0;
    // 0x80063EAC: sh          $zero, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = 0;
    // 0x80063EB0: sh          $t6, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r14;
    // 0x80063EB4: lh          $t7, -0x8($s4)
    ctx->r15 = MEM_H(ctx->r20, -0X8);
    // 0x80063EB8: sh          $t7, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r15;
    // 0x80063EBC: lh          $t8, -0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, -0X8);
    // 0x80063EC0: sb          $v1, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r3;
    // 0x80063EC4: sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
    // 0x80063EC8: sb          $v1, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r3;
    // 0x80063ECC: sb          $v1, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r3;
    // 0x80063ED0: bne         $s7, $t0, L_80063DDC
    if (ctx->r23 != ctx->r8) {
        // 0x80063ED4: sh          $t8, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r24;
            goto L_80063DDC;
    }
    // 0x80063ED4: sh          $t8, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r24;
L_80063ED8:
    // 0x80063ED8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80063EDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80063EE0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80063EE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80063EE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80063EEC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80063EF0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80063EF4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80063EF8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80063EFC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80063F00: jr          $ra
    // 0x80063F04: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80063F04: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_8006EC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EC64: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8006EC68: addiu       $at, $zero, 0x466B
    ctx->r1 = ADD32(0, 0X466B);
    // 0x8006EC6C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006EC70: beq         $v0, $at, L_8006EC94
    if (ctx->r2 == ctx->r1) {
        // 0x8006EC74: addiu       $at, $zero, 0x473C
        ctx->r1 = ADD32(0, 0X473C);
            goto L_8006EC94;
    }
    // 0x8006EC74: addiu       $at, $zero, 0x473C
    ctx->r1 = ADD32(0, 0X473C);
    // 0x8006EC78: beq         $v0, $at, L_8006ECB0
    if (ctx->r2 == ctx->r1) {
        // 0x8006EC7C: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_8006ECB0;
    }
    // 0x8006EC7C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8006EC80: addiu       $at, $zero, 0x473D
    ctx->r1 = ADD32(0, 0X473D);
    // 0x8006EC84: beq         $v0, $at, L_8006ECCC
    if (ctx->r2 == ctx->r1) {
        // 0x8006EC88: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_8006ECCC;
    }
    // 0x8006EC88: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8006EC8C: b           L_8006ECEC
    // 0x8006EC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006ECEC;
    // 0x8006EC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006EC94:
    // 0x8006EC94: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x8006EC98: beql        $t6, $zero, L_8006ECEC
    if (ctx->r14 == 0) {
        // 0x8006EC9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006ECEC;
    }
    goto skip_0;
    // 0x8006EC9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006ECA0: jal         0x8006EC10
    // 0x8006ECA4: nop

    func_8006EC10(rdram, ctx);
        goto after_0;
    // 0x8006ECA4: nop

    after_0:
    // 0x8006ECA8: b           L_8006ECEC
    // 0x8006ECAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006ECEC;
    // 0x8006ECAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006ECB0:
    // 0x8006ECB0: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8006ECB4: beql        $t7, $zero, L_8006ECEC
    if (ctx->r15 == 0) {
        // 0x8006ECB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006ECEC;
    }
    goto skip_1;
    // 0x8006ECB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006ECBC: jal         0x8006EC10
    // 0x8006ECC0: nop

    func_8006EC10(rdram, ctx);
        goto after_1;
    // 0x8006ECC0: nop

    after_1:
    // 0x8006ECC4: b           L_8006ECEC
    // 0x8006ECC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006ECEC;
    // 0x8006ECC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006ECCC:
    // 0x8006ECCC: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8006ECD0: beql        $t8, $zero, L_8006ECEC
    if (ctx->r24 == 0) {
        // 0x8006ECD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006ECEC;
    }
    goto skip_2;
    // 0x8006ECD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8006ECD8: jal         0x8006EC10
    // 0x8006ECDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006EC10(rdram, ctx);
        goto after_2;
    // 0x8006ECDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8006ECE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006ECE4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8006ECE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006ECEC:
    // 0x8006ECEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ECF0: jr          $ra
    // 0x8006ECF4: nop

    return;
    // 0x8006ECF4: nop

;}
RECOMP_FUNC void func_80568428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568428: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8056842C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80568430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80568434: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568438: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8056843C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568440: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80568444: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80568448: lwc1        $f12, 0x6C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8056844C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80568450: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80568454: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21B8) << 16);
    // 0x80568458: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8056845C: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80568460: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80568464: nop

    // 0x80568468: bc1fl       L_80568488
    if (!c1cs) {
        // 0x8056846C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80568488;
    }
    goto skip_0;
    // 0x8056846C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80568470: lwc1        $f16, -0x6898($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21B8));
    // 0x80568474: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80568478: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8056847C: b           L_80568494
    // 0x80568480: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
        goto L_80568494;
    // 0x80568480: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x80568484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80568488:
    // 0x80568488: jal         0x80569310
    // 0x8056848C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80569310(rdram, ctx);
        goto after_0;
    // 0x8056848C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80568490: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80568494:
    // 0x80568494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80568498: jal         0x80567DD4
    // 0x8056849C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80567DD4(rdram, ctx);
        goto after_1;
    // 0x8056849C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x805684A0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805684A4: jal         0x80048F84
    // 0x805684A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805684A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805684AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805684B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805684B4: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x805684B8: beq         $t6, $zero, L_805684C8
    if (ctx->r14 == 0) {
        // 0x805684BC: nop
    
            goto L_805684C8;
    }
    // 0x805684BC: nop

    // 0x805684C0: jal         0x80569310
    // 0x805684C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80569310(rdram, ctx);
        goto after_3;
    // 0x805684C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
L_805684C8:
    // 0x805684C8: jal         0x805677F4
    // 0x805684CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805677F4(rdram, ctx);
        goto after_4;
    // 0x805684CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805684D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805684D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805684D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805684DC: jr          $ra
    // 0x805684E0: nop

    return;
    // 0x805684E0: nop

;}
RECOMP_FUNC void func_8005B484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B488: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005B48C: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8005B490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B494: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005B498: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x8005B49C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8005B4A0: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8005B4A4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8005B4A8: jal         0x8005ABB0
    // 0x8005B4AC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8005ABB0(rdram, ctx);
        goto after_0;
    // 0x8005B4AC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005B4B0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8005B4B4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005B4B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8005B4BC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8005B4C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005B4C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005B4C8: bne         $v0, $zero, L_8005B4E4
    if (ctx->r2 != 0) {
        // 0x8005B4CC: sb          $t7, 0x15($a3)
        MEM_B(0X15, ctx->r7) = ctx->r15;
            goto L_8005B4E4;
    }
    // 0x8005B4CC: sb          $t7, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r15;
    // 0x8005B4D0: addiu       $a0, $a0, 0xC70
    ctx->r4 = ADD32(ctx->r4, 0XC70);
    // 0x8005B4D4: jal         0x80071380
    // 0x8005B4D8: addiu       $a1, $zero, 0x2BB
    ctx->r5 = ADD32(0, 0X2BB);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005B4D8: addiu       $a1, $zero, 0x2BB
    ctx->r5 = ADD32(0, 0X2BB);
    after_1:
    // 0x8005B4DC: b           L_8005B4F8
    // 0x8005B4E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B4F8;
    // 0x8005B4E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B4E4:
    // 0x8005B4E4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005B4E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005B4EC: jal         0x80073390
    // 0x8005B4F0: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    func_80073390(rdram, ctx);
        goto after_2;
    // 0x8005B4F0: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    after_2:
    // 0x8005B4F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005B4F8:
    // 0x8005B4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B500: jr          $ra
    // 0x8005B504: nop

    return;
    // 0x8005B504: nop

;}
RECOMP_FUNC void func_804BB290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BB294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB298: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x804BB29C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BB2A0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x804BB2A4: beql        $at, $zero, L_804BB2B4
    if (ctx->r1 == 0) {
        // 0x804BB2A8: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_804BB2B4;
    }
    goto skip_0;
    // 0x804BB2A8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
    // 0x804BB2AC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x804BB2B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_804BB2B4:
    // 0x804BB2B4: jal         0x804BB604
    // 0x804BB2B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804BB604(rdram, ctx);
        goto after_0;
    // 0x804BB2B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB2BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804BB2C0: beq         $v0, $zero, L_804BB300
    if (ctx->r2 == 0) {
        // 0x804BB2C4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804BB300;
    }
    // 0x804BB2C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BB2C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x804BB2CC: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x804BB2D0: beq         $t7, $zero, L_804BB2E0
    if (ctx->r15 == 0) {
        // 0x804BB2D4: nop
    
            goto L_804BB2E0;
    }
    // 0x804BB2D4: nop

    // 0x804BB2D8: b           L_804BB2F4
    // 0x804BB2DC: sb          $t8, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r24;
        goto L_804BB2F4;
    // 0x804BB2DC: sb          $t8, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r24;
L_804BB2E0:
    // 0x804BB2E0: jal         0x804BAD44
    // 0x804BB2E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804BAD44(rdram, ctx);
        goto after_1;
    // 0x804BB2E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x804BB2E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BB2EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804BB2F0: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
L_804BB2F4:
    // 0x804BB2F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB2F8: jal         0x804BB4C4
    // 0x804BB2FC: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    func_804BB4C4(rdram, ctx);
        goto after_2;
    // 0x804BB2FC: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    after_2:
L_804BB300:
    // 0x804BB300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BB308: jr          $ra
    // 0x804BB30C: nop

    return;
    // 0x804BB30C: nop

;}
RECOMP_FUNC void func_8002761C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002761C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80027620: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80027624: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x80027628: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8002762C: jr          $ra
    // 0x80027630: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    return;
    // 0x80027630: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_804452AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804452AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804452B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804452B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804452B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804452BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x804452C0: jal         0x80047090
    // 0x804452C4: addiu       $a0, $zero, 0x40F8
    ctx->r4 = ADD32(0, 0X40F8);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804452C4: addiu       $a0, $zero, 0x40F8
    ctx->r4 = ADD32(0, 0X40F8);
    after_0:
    // 0x804452C8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804452CC: beq         $v0, $at, L_80445598
    if (ctx->r2 == ctx->r1) {
        // 0x804452D0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80445598;
    }
    // 0x804452D0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804452D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804452D8: lui         $at, 0x40F8
    ctx->r1 = S32(0X40F8 << 16);
    // 0x804452DC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x804452E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804452E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804452E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x804452EC: jal         0x8004613C
    // 0x804452F0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804452F0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x804452F4: beq         $v0, $zero, L_80445598
    if (ctx->r2 == 0) {
        // 0x804452F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80445598;
    }
    // 0x804452F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804452FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80445300: jal         0x80047F9C
    // 0x80445304: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80445304: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80445308: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14008) << 16);
    // 0x8044530C: lwc1        $f0, -0x7C18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14008));
    // 0x80445310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80445314: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x80445318: addiu       $a0, $zero, 0x40F1
    ctx->r4 = ADD32(0, 0X40F1);
    // 0x8044531C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80445320: lui         $a2, 0xC21C
    ctx->r6 = S32(0XC21C << 16);
    // 0x80445324: lui         $a3, 0xC2F8
    ctx->r7 = S32(0XC2F8 << 16);
    // 0x80445328: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8044532C: jal         0x8005D078
    // 0x80445330: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8005D078(rdram, ctx);
        goto after_3;
    // 0x80445330: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80445334: beq         $v0, $zero, L_804453B8
    if (ctx->r2 == 0) {
        // 0x80445338: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804453B8;
    }
    // 0x80445338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8044533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80445340: jal         0x80047F9C
    // 0x80445344: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80445344: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80445348: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044534C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80445350: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80445354: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80445358: sb          $t7, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r15;
    // 0x8044535C: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x80445360: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1400C) << 16);
    // 0x80445364: lw          $t2, 0x16C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X16C);
    // 0x80445368: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8044536C: addiu       $a0, $zero, 0x40F2
    ctx->r4 = ADD32(0, 0X40F2);
    // 0x80445370: lui         $a2, 0xC21C
    ctx->r6 = S32(0XC21C << 16);
    // 0x80445374: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x80445378: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x8044537C: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x80445380: lui         $a3, 0xC2F8
    ctx->r7 = S32(0XC2F8 << 16);
    // 0x80445384: lwc1        $f0, 0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80445388: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x8044538C: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x80445390: lw          $t1, 0x478($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X478);
    // 0x80445394: lwc1        $f6, -0x7C14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1400C));
    // 0x80445398: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14014) << 16);
    // 0x8044539C: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x804453A0: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x804453A4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804453A8: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x804453AC: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x804453B0: b           L_804453C8
    // 0x804453B4: sb          $zero, 0x10($t2)
    MEM_B(0X10, ctx->r10) = 0;
        goto L_804453C8;
    // 0x804453B4: sb          $zero, 0x10($t2)
    MEM_B(0X10, ctx->r10) = 0;
L_804453B8:
    // 0x804453B8: jal         0x800445A4
    // 0x804453BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804453BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804453C0: b           L_8044559C
    // 0x804453C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8044559C;
    // 0x804453C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804453C8:
    // 0x804453C8: lw          $t3, 0xFB8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XFB8);
    // 0x804453CC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x804453D0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x804453D4: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x804453D8: bne         $t5, $zero, L_8044540C
    if (ctx->r13 != 0) {
        // 0x804453DC: nop
    
            goto L_8044540C;
    }
    // 0x804453DC: nop

    // 0x804453E0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14010) << 16);
    // 0x804453E4: lwc1        $f0, -0x7C10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14010));
    // 0x804453E8: addiu       $a0, $zero, 0x40F2
    ctx->r4 = ADD32(0, 0X40F2);
    // 0x804453EC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x804453F0: lui         $a2, 0xC280
    ctx->r6 = S32(0XC280 << 16);
    // 0x804453F4: lui         $a3, 0xC2F8
    ctx->r7 = S32(0XC2F8 << 16);
    // 0x804453F8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x804453FC: jal         0x8005D078
    // 0x80445400: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8005D078(rdram, ctx);
        goto after_6;
    // 0x80445400: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80445404: b           L_80445428
    // 0x80445408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80445428;
    // 0x80445408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8044540C:
    // 0x8044540C: lwc1        $f8, -0x7C0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14014));
    // 0x80445410: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14018) << 16);
    // 0x80445414: lwc1        $f10, -0x7C08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14018));
    // 0x80445418: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8044541C: jal         0x8005D078
    // 0x80445420: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_8005D078(rdram, ctx);
        goto after_7;
    // 0x80445420: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80445424: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80445428:
    // 0x80445428: beq         $v0, $zero, L_804454C0
    if (ctx->r2 == 0) {
        // 0x8044542C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804454C0;
    }
    // 0x8044542C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80445430: jal         0x80047F9C
    // 0x80445434: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80445434: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_8:
    // 0x80445438: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044543C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80445440: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80445444: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80445448: sb          $t6, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r14;
    // 0x8044544C: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x80445450: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1401C) << 16);
    // 0x80445454: lw          $t1, 0x16C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X16C);
    // 0x80445458: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8044545C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80445460: addiu       $a0, $zero, 0x4021
    ctx->r4 = ADD32(0, 0X4021);
    // 0x80445464: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x80445468: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x8044546C: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x80445470: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80445474: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x80445478: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x8044547C: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x80445480: lwc1        $f18, -0x7C04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1401C));
    // 0x80445484: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14020) << 16);
    // 0x80445488: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8044548C: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x80445490: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80445494: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x80445498: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x8044549C: sb          $t0, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r8;
    // 0x804454A0: lw          $t2, 0x16C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X16C);
    // 0x804454A4: sb          $t0, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r8;
    // 0x804454A8: lw          $t3, 0x16C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X16C);
    // 0x804454AC: sb          $zero, 0xF($t3)
    MEM_B(0XF, ctx->r11) = 0;
    // 0x804454B0: lw          $t4, 0x16C($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X16C);
    // 0x804454B4: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x804454B8: b           L_804454D0
    // 0x804454BC: sb          $zero, 0x10($t4)
    MEM_B(0X10, ctx->r12) = 0;
        goto L_804454D0;
    // 0x804454BC: sb          $zero, 0x10($t4)
    MEM_B(0X10, ctx->r12) = 0;
L_804454C0:
    // 0x804454C0: jal         0x800445A4
    // 0x804454C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x804454C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x804454C8: b           L_8044559C
    // 0x804454CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8044559C;
    // 0x804454CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804454D0:
    // 0x804454D0: lwc1        $f0, -0x7C00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14020));
    // 0x804454D4: lui         $a2, 0xC21C
    ctx->r6 = S32(0XC21C << 16);
    // 0x804454D8: lui         $a3, 0xC356
    ctx->r7 = S32(0XC356 << 16);
    // 0x804454DC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x804454E0: jal         0x8005D078
    // 0x804454E4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8005D078(rdram, ctx);
        goto after_10;
    // 0x804454E4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x804454E8: beq         $v0, $zero, L_80445578
    if (ctx->r2 == 0) {
        // 0x804454EC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80445578;
    }
    // 0x804454EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804454F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804454F4: jal         0x80047F9C
    // 0x804454F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x804454F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_11:
    // 0x804454FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80445500: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80445504: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80445508: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8044550C: sb          $t5, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r13;
    // 0x80445510: lw          $t6, 0x478($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X478);
    // 0x80445514: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14024) << 16);
    // 0x80445518: lw          $t9, 0x16C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X16C);
    // 0x8044551C: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80445520: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80445524: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x80445528: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x8044552C: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x80445530: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80445534: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x80445538: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x8044553C: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x80445540: lwc1        $f6, -0x7BFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14024));
    // 0x80445544: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80445548: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x8044554C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80445550: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x80445554: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x80445558: sb          $zero, 0xD($t9)
    MEM_B(0XD, ctx->r25) = 0;
    // 0x8044555C: lw          $t1, 0x16C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X16C);
    // 0x80445560: sb          $t0, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r8;
    // 0x80445564: lw          $t2, 0x16C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X16C);
    // 0x80445568: sb          $t0, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r8;
    // 0x8044556C: lw          $t3, 0x16C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X16C);
    // 0x80445570: b           L_80445588
    // 0x80445574: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
        goto L_80445588;
    // 0x80445574: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
L_80445578:
    // 0x80445578: jal         0x800445A4
    // 0x8044557C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_12;
    // 0x8044557C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80445580: b           L_8044559C
    // 0x80445584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8044559C;
    // 0x80445584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80445588:
    // 0x80445588: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x8044558C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80445590: jalr        $t9
    // 0x80445594: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x80445594: nop

    after_13:
L_80445598:
    // 0x80445598: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8044559C:
    // 0x8044559C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804455A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804455A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804455A8: jr          $ra
    // 0x804455AC: nop

    return;
    // 0x804455AC: nop

;}
RECOMP_FUNC void func_8041F950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F950: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8041F954: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041F958: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041F95C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F960: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041F964: jal         0x8041E9A8
    // 0x8041F968: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_8041E9A8(rdram, ctx);
        goto after_0;
    // 0x8041F968: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8041F96C: beq         $v0, $zero, L_8041F9F8
    if (ctx->r2 == 0) {
        // 0x8041F970: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8041F9F8;
    }
    // 0x8041F970: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041F974: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041F978: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8041F97C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041F980: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8041F984: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041F988: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3528) << 16);
    // 0x8041F98C: lwc1        $f10, 0xB88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3528));
    // 0x8041F990: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8041F994: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8041F998: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8041F99C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8041F9A0: addiu       $t7, $zero, 0x4034
    ctx->r15 = ADD32(0, 0X4034);
    // 0x8041F9A4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8041F9A8: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x8041F9AC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8041F9B0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8041F9B4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8041F9B8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8041F9BC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8041F9C0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8041F9C4: lw          $t9, 0x54($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X54);
    // 0x8041F9C8: jalr        $t9
    // 0x8041F9CC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8041F9CC: nop

    after_1:
    // 0x8041F9D0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8041F9D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F9D8: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8041F9DC: jal         0x8041E5E8
    // 0x8041F9E0: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    func_8041E5E8(rdram, ctx);
        goto after_2;
    // 0x8041F9E0: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    after_2:
    // 0x8041F9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F9E8: jal         0x8041E430
    // 0x8041F9EC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_8041E430(rdram, ctx);
        goto after_3;
    // 0x8041F9EC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8041F9F0: jal         0x8041F594
    // 0x8041F9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F594(rdram, ctx);
        goto after_4;
    // 0x8041F9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8041F9F8:
    // 0x8041F9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F9FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FA00: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8041FA04: jal         0x8041FE10
    // 0x8041FA08: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_5;
    // 0x8041FA08: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x8041FA0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041FA10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041FA14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8041FA18: jr          $ra
    // 0x8041FA1C: nop

    return;
    // 0x8041FA1C: nop

;}
RECOMP_FUNC void func_80058B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B98: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80058B9C: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x80058BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058BA8: addiu       $t7, $t6, 0x120
    ctx->r15 = ADD32(ctx->r14, 0X120);
    // 0x80058BAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80058BB0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80058BB4: jal         0x80058B44
    // 0x80058BB8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80058B44(rdram, ctx);
        goto after_0;
    // 0x80058BB8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80058BBC: beq         $v0, $zero, L_80058BCC
    if (ctx->r2 == 0) {
        // 0x80058BC0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80058BCC;
    }
    // 0x80058BC0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80058BC4: b           L_80058C00
    // 0x80058BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80058C00;
    // 0x80058BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058BCC:
    // 0x80058BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058BD0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80058BD4:
    // 0x80058BD4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80058BD8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80058BDC: bne         $t9, $zero, L_80058BF4
    if (ctx->r25 != 0) {
        // 0x80058BE0: nop
    
            goto L_80058BF4;
    }
    // 0x80058BE0: nop

    // 0x80058BE4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80058BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80058BEC: b           L_80058C00
    // 0x80058BF0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_80058C00;
    // 0x80058BF0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80058BF4:
    // 0x80058BF4: bne         $v0, $a0, L_80058BD4
    if (ctx->r2 != ctx->r4) {
        // 0x80058BF8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80058BD4;
    }
    // 0x80058BF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80058BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058C00:
    // 0x80058C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058C08: jr          $ra
    // 0x80058C0C: nop

    return;
    // 0x80058C0C: nop

;}
RECOMP_FUNC void func_8046475C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046475C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80464760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80464764: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80464768: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8046476C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80464770: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(125, 0X1D2C) << 16);
    // 0x80464774: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80464778: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8046477C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80464780: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80464784: lw          $t8, 0x62FC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(125, 0X1D2C));
    // 0x80464788: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8046478C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80464790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80464794: jal         0x80048490
    // 0x80464798: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80464798: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8046479C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804647A0: jal         0x80048378
    // 0x804647A4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804647A4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804647A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804647AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804647B0: jr          $ra
    // 0x804647B4: nop

    return;
    // 0x804647B4: nop

;}
RECOMP_FUNC void func_806B2B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2B8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2B90: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2B94: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2B98: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2B9C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2BA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2BA4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2BA8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2BAC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2BB0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2BB4: jr          $ra
    // 0x806B2BB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2BB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80057890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057898: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005789C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800578A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800578A4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800578A8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x800578AC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800578B0: jal         0x80056934
    // 0x800578B4: lw          $a0, 0x268($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X268);
    func_80056934(rdram, ctx);
        goto after_0;
    // 0x800578B4: lw          $a0, 0x268($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X268);
    after_0:
    // 0x800578B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800578BC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800578C0: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x800578C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800578C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800578CC: jr          $ra
    // 0x800578D0: nop

    return;
    // 0x800578D0: nop

;}
RECOMP_FUNC void func_805221B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805221B8: jr          $ra
    // 0x805221BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805221BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8004A73C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A73C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004A740: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8004A744: addiu       $v1, $v1, 0x5C4
    ctx->r3 = ADD32(ctx->r3, 0X5C4);
    // 0x8004A748: lhu         $t6, 0x4C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4C);
    // 0x8004A74C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8004A750: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004A754: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8004A758: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004A75C: sw          $t0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r8;
    // 0x8004A760: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004A764: lhu         $t1, 0x4C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4C);
    // 0x8004A768: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8004A76C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004A770: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8004A774: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8004A778: jr          $ra
    // 0x8004A77C: sw          $t5, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r13;
    return;
    // 0x8004A77C: sw          $t5, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_804600F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804600F0: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(119, 0X30C) << 16);
    // 0x804600F4: addiu       $v0, $v0, 0x3FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(119, 0X30C));
    // 0x804600F8: jr          $ra
    // 0x804600FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804600FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005B9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B9E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B9EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005B9F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005B9F4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8005B9F8: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x8005B9FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005BA00: addiu       $s1, $s1, -0x7F80
    ctx->r17 = ADD32(ctx->r17, -0X7F80);
    // 0x8005BA04: addiu       $s0, $s0, -0x4BB0
    ctx->r16 = ADD32(ctx->r16, -0X4BB0);
L_8005BA08:
    // 0x8005BA08: jal         0x8005B96C
    // 0x8005BA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005B96C(rdram, ctx);
        goto after_0;
    // 0x8005BA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8005BA10: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8005BA14: bne         $s0, $s1, L_8005BA08
    if (ctx->r16 != ctx->r17) {
        // 0x8005BA18: nop
    
            goto L_8005BA08;
    }
    // 0x8005BA18: nop

    // 0x8005BA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BA20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005BA24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005BA28: jr          $ra
    // 0x8005BA2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005BA2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804426E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804426E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804426E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804426EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804426F0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EF4) << 16);
    // 0x804426F4: lwc1        $f6, 0x3DF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EF4));
    // 0x804426F8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804426FC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EF8) << 16);
    // 0x80442700: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80442704: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80442708: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8044270C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80442710: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80442714: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80442718: lwc1        $f16, 0x3DF8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EF8));
    // 0x8044271C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80442720: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80442724: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80442728: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8044272C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80442730: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80442734: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80442738: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8044273C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80442740: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80442744: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    // 0x80442748: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8044274C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80442750: nop

    // 0x80442754: bc1fl       L_80442768
    if (!c1cs) {
        // 0x80442758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80442768;
    }
    goto skip_0;
    // 0x80442758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044275C: jal         0x8044284C
    // 0x80442760: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8044284C(rdram, ctx);
        goto after_0;
    // 0x80442760: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80442764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80442768:
    // 0x80442768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044276C: jr          $ra
    // 0x80442770: nop

    return;
    // 0x80442770: nop

;}
RECOMP_FUNC void func_8052D6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D6A0: jr          $ra
    // 0x8052D6A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8052D6A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8077050C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077050C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80770510: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80770514: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80770518: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8077051C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80770520: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80770524: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80770528: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8077052C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80770530: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80770534: jr          $ra
    // 0x80770538: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80770538: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80439498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439498: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043949C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804394A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804394A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804394A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804394AC: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x804394B0: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x804394B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804394B8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804394BC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x804394C0: bgez        $t6, L_804394D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x804394C4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_804394D8;
    }
    // 0x804394C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804394C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804394CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804394D0: nop

    // 0x804394D4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_804394D8:
    // 0x804394D8: bgez        $t7, L_804394F0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x804394DC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_804394F0;
    }
    // 0x804394DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804394E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804394E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804394E8: nop

    // 0x804394EC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_804394F0:
    // 0x804394F0: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x804394F4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x804394F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804394FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80439500: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80439504: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80439508: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8043950C: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80439510: lbu         $a2, 0xE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XE);
    // 0x80439514: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80439518: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x8043951C: nop

    // 0x80439520: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80439524: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x80439528: nop

    // 0x8043952C: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x80439530: beql        $a3, $zero, L_80439580
    if (ctx->r7 == 0) {
        // 0x80439534: mfc1        $a3, $f10
        ctx->r7 = (int32_t)ctx->f10.u32l;
            goto L_80439580;
    }
    goto skip_0;
    // 0x80439534: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80439538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043953C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80439540: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80439544: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x80439548: nop

    // 0x8043954C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80439550: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x80439554: nop

    // 0x80439558: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x8043955C: bne         $a3, $zero, L_80439574
    if (ctx->r7 != 0) {
        // 0x80439560: nop
    
            goto L_80439574;
    }
    // 0x80439560: nop

    // 0x80439564: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80439568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043956C: b           L_8043958C
    // 0x80439570: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_8043958C;
    // 0x80439570: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_80439574:
    // 0x80439574: b           L_8043958C
    // 0x80439578: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8043958C;
    // 0x80439578: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8043957C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
L_80439580:
    // 0x80439580: nop

    // 0x80439584: bltz        $a3, L_80439574
    if (SIGNED(ctx->r7) < 0) {
        // 0x80439588: nop
    
            goto L_80439574;
    }
    // 0x80439588: nop

L_8043958C:
    // 0x8043958C: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x80439590: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80439594: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80439598: jal         0x80438C18
    // 0x8043959C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80438C18(rdram, ctx);
        goto after_0;
    // 0x8043959C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x804395A0: lbu         $t0, 0x14($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X14);
    // 0x804395A4: lbu         $a1, 0x11($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X11);
    // 0x804395A8: lbu         $a2, 0x12($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X12);
    // 0x804395AC: lbu         $a3, 0x13($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X13);
    // 0x804395B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804395B4: jal         0x80438C7C
    // 0x804395B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80438C7C(rdram, ctx);
        goto after_1;
    // 0x804395B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x804395BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804395C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804395C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804395C8: jr          $ra
    // 0x804395CC: nop

    return;
    // 0x804395CC: nop

;}
RECOMP_FUNC void func_80440E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80440E3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80440E40: mul.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80440E44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80440E48: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80440E4C: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80440E50: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80440E54: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80440E58: bc1f        L_80440E90
    if (!c1cs) {
        // 0x80440E5C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80440E90;
    }
    // 0x80440E5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80440E60: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80440E64: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80440E68: bc1fl       L_80440E7C
    if (!c1cs) {
        // 0x80440E6C: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80440E7C;
    }
    goto skip_0;
    // 0x80440E6C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_0:
    // 0x80440E70: b           L_80440EC8
    // 0x80440E74: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_80440EC8;
    // 0x80440E74: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x80440E78: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80440E7C:
    // 0x80440E7C: nop

    // 0x80440E80: bc1fl       L_80440ECC
    if (!c1cs) {
        // 0x80440E84: lwc1        $f2, 0x0($a2)
        ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
            goto L_80440ECC;
    }
    goto skip_1;
    // 0x80440E84: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x80440E88: b           L_80440EC8
    // 0x80440E8C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80440EC8;
    // 0x80440E8C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80440E90:
    // 0x80440E90: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80440E94: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80440E98: nop

    // 0x80440E9C: bc1fl       L_80440EB0
    if (!c1cs) {
        // 0x80440EA0: lwc1        $f12, 0x10($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
            goto L_80440EB0;
    }
    goto skip_2;
    // 0x80440EA0: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    skip_2:
    // 0x80440EA4: b           L_80440EC8
    // 0x80440EA8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80440EC8;
    // 0x80440EA8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80440EAC: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
L_80440EB0:
    // 0x80440EB0: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
    // 0x80440EB4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80440EB8: nop

    // 0x80440EBC: bc1fl       L_80440ECC
    if (!c1cs) {
        // 0x80440EC0: lwc1        $f2, 0x0($a2)
        ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
            goto L_80440ECC;
    }
    goto skip_3;
    // 0x80440EC0: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    skip_3:
    // 0x80440EC4: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80440EC8:
    // 0x80440EC8: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
L_80440ECC:
    // 0x80440ECC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80440ED0: nop

    // 0x80440ED4: bc1fl       L_80440EEC
    if (!c1cs) {
        // 0x80440ED8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80440EEC;
    }
    goto skip_4;
    // 0x80440ED8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_4:
    // 0x80440EDC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80440EE0: jr          $ra
    // 0x80440EE4: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    return;
    // 0x80440EE4: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80440EE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80440EEC:
    // 0x80440EEC: lwc1        $f16, 0x14($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80440EF0: bc1f        L_80440F00
    if (!c1cs) {
        // 0x80440EF4: nop
    
            goto L_80440F00;
    }
    // 0x80440EF4: nop

    // 0x80440EF8: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80440EFC: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_80440F00:
    // 0x80440F00: jr          $ra
    // 0x80440F04: nop

    return;
    // 0x80440F04: nop

;}
RECOMP_FUNC void func_8045339C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045339C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804533A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804533A4: jal         0x804531D0
    // 0x804533A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x804533A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804533AC: beq         $v0, $zero, L_804533BC
    if (ctx->r2 == 0) {
        // 0x804533B0: nop
    
            goto L_804533BC;
    }
    // 0x804533B0: nop

    // 0x804533B4: jal         0x80452950
    // 0x804533B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80452950(rdram, ctx);
        goto after_1;
    // 0x804533B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_804533BC:
    // 0x804533BC: jal         0x8044DED8
    // 0x804533C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044DED8(rdram, ctx);
        goto after_2;
    // 0x804533C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804533C4: jal         0x8044E684
    // 0x804533C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044E684(rdram, ctx);
        goto after_3;
    // 0x804533C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x804533CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804533D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804533D4: jr          $ra
    // 0x804533D8: nop

    return;
    // 0x804533D8: nop

;}
RECOMP_FUNC void func_800577D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800577D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800577DC: beq         $a0, $zero, L_800577FC
    if (ctx->r4 == 0) {
        // 0x800577E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800577FC;
    }
    // 0x800577E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800577E4: jal         0x800574D0
    // 0x800577E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800574D0(rdram, ctx);
        goto after_0;
    // 0x800577E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800577EC: jal         0x800574F4
    // 0x800577F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800574F4(rdram, ctx);
        goto after_1;
    // 0x800577F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800577F4: jal         0x80057560
    // 0x800577F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80057560(rdram, ctx);
        goto after_2;
    // 0x800577F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_800577FC:
    // 0x800577FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057804: jr          $ra
    // 0x80057808: nop

    return;
    // 0x80057808: nop

;}
RECOMP_FUNC void func_8071165C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071165C: jr          $ra
    // 0x80711660: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80711660: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8044CD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CD4C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8044CD50: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8044CD54: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8044CD58: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8044CD5C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8044CD60: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8044CD64: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x8044CD68: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
L_8044CD6C:
    // 0x8044CD6C: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8044CD70: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8044CD74: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8044CD78: bnel        $at, $zero, L_8044CE0C
    if (ctx->r1 != 0) {
        // 0x8044CD7C: lhu         $t9, 0x2($v1)
        ctx->r25 = MEM_HU(ctx->r3, 0X2);
            goto L_8044CE0C;
    }
    goto skip_0;
    // 0x8044CD7C: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    skip_0:
    // 0x8044CD80: bne         $v0, $zero, L_8044CDB0
    if (ctx->r2 != 0) {
        // 0x8044CD84: sll         $a1, $a3, 1
        ctx->r5 = S32(ctx->r7 << 1);
            goto L_8044CDB0;
    }
    // 0x8044CD84: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8044CD88: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x8044CD8C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8044CD90: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8044CD94: addu        $t4, $t9, $a1
    ctx->r12 = ADD32(ctx->r25, ctx->r5);
    // 0x8044CD98: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8044CD9C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8044CDA0: nop

    // 0x8044CDA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8044CDA8: b           L_8044CE28
    // 0x8044CDAC: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
        goto L_8044CE28;
    // 0x8044CDAC: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
L_8044CDB0:
    // 0x8044CDB0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8044CDB4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x8044CDB8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8044CDBC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8044CDC0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8044CDC4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8044CDC8: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8044CDCC: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8044CDD0: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8044CDD4: sll         $t6, $t2, 1
    ctx->r14 = S32(ctx->r10 << 1);
    // 0x8044CDD8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8044CDDC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8044CDE0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8044CDE4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8044CDE8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8044CDEC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8044CDF0: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8044CDF4: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8044CDF8: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8044CDFC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8044CE00: b           L_8044CE28
    // 0x8044CE04: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
        goto L_8044CE28;
    // 0x8044CE04: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8044CE08: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
L_8044CE0C:
    // 0x8044CE0C: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x8044CE10: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8044CE14: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8044CE18: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8044CE1C: nop

    // 0x8044CE20: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8044CE24: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
L_8044CE28:
    // 0x8044CE28: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8044CE2C: bne         $t0, $t3, L_8044CD6C
    if (ctx->r8 != ctx->r11) {
        // 0x8044CE30: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8044CD6C;
    }
    // 0x8044CE30: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8044CE34: jr          $ra
    // 0x8044CE38: nop

    return;
    // 0x8044CE38: nop

;}
RECOMP_FUNC void func_8059EA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EA60: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8059EA64: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(405, 0X5E4) << 16);
    // 0x8059EA68: addiu       $t6, $t6, -0xFCC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(405, 0X5E4));
    // 0x8059EA6C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8059EA70: jr          $ra
    // 0x8059EA74: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
    return;
    // 0x8059EA74: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8046AE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AE04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046AE08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046AE0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046AE10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8046AE14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046AE18: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046AE1C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8046AE20: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8046AE24: nop

    // 0x8046AE28: bc1t        L_8046AE48
    if (c1cs) {
        // 0x8046AE2C: nop
    
            goto L_8046AE48;
    }
    // 0x8046AE2C: nop

    // 0x8046AE30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046AE34: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2994) << 16);
    // 0x8046AE38: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8046AE3C: nop

    // 0x8046AE40: bc1f        L_8046AE5C
    if (!c1cs) {
        // 0x8046AE44: nop
    
            goto L_8046AE5C;
    }
    // 0x8046AE44: nop

L_8046AE48:
    // 0x8046AE48: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2990) << 16);
    // 0x8046AE4C: lwc1        $f8, -0x3F30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2990));
    // 0x8046AE50: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8046AE54: b           L_8046AE68
    // 0x8046AE58: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_8046AE68;
    // 0x8046AE58: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8046AE5C:
    // 0x8046AE5C: lwc1        $f16, -0x3F2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2994));
    // 0x8046AE60: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8046AE64: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8046AE68:
    // 0x8046AE68: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046AE6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046AE70: jal         0x804697D8
    // 0x8046AE74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x8046AE74: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046AE78: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046AE7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8046AE80: jal         0x8046ADC8
    // 0x8046AE84: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    func_8046ADC8(rdram, ctx);
        goto after_1;
    // 0x8046AE84: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x8046AE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046AE8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046AE90: jr          $ra
    // 0x8046AE94: nop

    return;
    // 0x8046AE94: nop

;}
RECOMP_FUNC void func_806E7010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7010: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E7014: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E7018: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E701C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E7020: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E7024: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806E7028: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E702C: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(658, 0X210) << 16);
    // 0x806E7030: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E7034: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E7038: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E703C: lw          $t1, 0x70B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(658, 0X210));
    // 0x806E7040: jr          $ra
    // 0x806E7044: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E7044: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806E7048: nop

    // 0x806E704C: nop

;}
RECOMP_FUNC void func_80043A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043A14: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80043A18: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80043A1C: jr          $ra
    // 0x80043A20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80043A20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_8064F258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F258: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F25C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F260: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F264: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F268: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F26C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F270: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F274: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F278: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F27C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F280: jr          $ra
    // 0x8064F284: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F284: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073A938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A938: jr          $ra
    // 0x8073A93C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073A93C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005B54C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B54C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005B550: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8005B554: lw          $s5, 0x78($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X78);
    // 0x8005B558: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8005B55C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8005B560: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B564: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B568: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8005B56C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8005B570: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8005B574: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8005B578: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005B57C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005B580: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8005B584: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005B588: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005B58C: jal         0x8007340C
    // 0x8005B590: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_8007340C(rdram, ctx);
        goto after_0;
    // 0x8005B590: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8005B594: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005B598: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x8005B59C: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x8005B5A0: jal         0x800733B4
    // 0x8005B5A4: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    func_800733B4(rdram, ctx);
        goto after_1;
    // 0x8005B5A4: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    after_1:
    // 0x8005B5A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005B5AC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8005B5B0: jal         0x8007336C
    // 0x8005B5B4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_8007336C(rdram, ctx);
        goto after_2;
    // 0x8005B5B4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x8005B5B8: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x8005B5BC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005B5C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005B5C4: bne         $v0, $zero, L_8005B600
    if (ctx->r2 != 0) {
        // 0x8005B5C8: addiu       $s0, $v0, 0x4
        ctx->r16 = ADD32(ctx->r2, 0X4);
            goto L_8005B600;
    }
    // 0x8005B5C8: addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
    // 0x8005B5CC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8005B5D0: jal         0x80064DD0
    // 0x8005B5D4: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    func_80064DD0(rdram, ctx);
        goto after_3;
    // 0x8005B5D4: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x8005B5D8: bne         $v0, $zero, L_8005B5E8
    if (ctx->r2 != 0) {
        // 0x8005B5DC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8005B5E8;
    }
    // 0x8005B5DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8005B5E0: b           L_8005B678
    // 0x8005B5E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B678;
    // 0x8005B5E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B5E8:
    // 0x8005B5E8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8005B5EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005B5F0: jal         0x80073390
    // 0x8005B5F4: addu        $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    func_80073390(rdram, ctx);
        goto after_4;
    // 0x8005B5F4: addu        $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    after_4:
    // 0x8005B5F8: b           L_8005B678
    // 0x8005B5FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B678;
    // 0x8005B5FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005B600:
    // 0x8005B600: lbu         $s3, 0x0($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0X0);
    // 0x8005B604: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8005B608: jal         0x8005B484
    // 0x8005B60C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_8005B484(rdram, ctx);
        goto after_5;
    // 0x8005B60C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x8005B610: bne         $v0, $zero, L_8005B620
    if (ctx->r2 != 0) {
        // 0x8005B614: nop
    
            goto L_8005B620;
    }
    // 0x8005B614: nop

    // 0x8005B618: b           L_8005B678
    // 0x8005B61C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B678;
    // 0x8005B61C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B620:
    // 0x8005B620: blez        $s3, L_8005B674
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8005B624: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8005B674;
    }
    // 0x8005B624: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005B628: lh          $s2, 0x76($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X76);
L_8005B62C:
    // 0x8005B62C: lh          $t2, 0x10($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X10);
    // 0x8005B630: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8005B634: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8005B638: multu       $s2, $t2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B63C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005B640: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8005B644: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8005B648: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8005B64C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8005B650: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005B654: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8005B658: mflo        $t3
    ctx->r11 = lo;
    // 0x8005B65C: addu        $a2, $s5, $t3
    ctx->r6 = ADD32(ctx->r21, ctx->r11);
    // 0x8005B660: jal         0x8005B36C
    // 0x8005B664: nop

    func_8005B36C(rdram, ctx);
        goto after_6;
    // 0x8005B664: nop

    after_6:
    // 0x8005B668: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005B66C: bne         $s1, $s3, L_8005B62C
    if (ctx->r17 != ctx->r19) {
        // 0x8005B670: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8005B62C;
    }
    // 0x8005B670: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_8005B674:
    // 0x8005B674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005B678:
    // 0x8005B678: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B67C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005B680: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005B684: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B688: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8005B68C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8005B690: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8005B694: jr          $ra
    // 0x8005B698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005B698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800320C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800320C4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800320C8: lbu         $t6, -0x7668($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7668);
    // 0x800320CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800320D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800320D4: beq         $t6, $zero, L_800321C8
    if (ctx->r14 == 0) {
        // 0x800320D8: lw          $a2, 0x1F4($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X1F4);
            goto L_800321C8;
    }
    // 0x800320D8: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x800320DC: lbu         $t7, 0x1F8($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1F8);
    // 0x800320E0: bnel        $t7, $zero, L_800321CC
    if (ctx->r15 != 0) {
        // 0x800320E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800321CC;
    }
    goto skip_0;
    // 0x800320E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800320E8: lh          $t8, 0x150($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X150);
    // 0x800320EC: bnel        $t8, $zero, L_800321CC
    if (ctx->r24 != 0) {
        // 0x800320F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800321CC;
    }
    goto skip_1;
    // 0x800320F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800320F4: lw          $t9, 0x12EC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X12EC);
    // 0x800320F8: bnel        $t9, $zero, L_800321CC
    if (ctx->r25 != 0) {
        // 0x800320FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800321CC;
    }
    goto skip_2;
    // 0x800320FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80032100: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x80032104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032108: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003210C: beql        $v0, $at, L_80032120
    if (ctx->r2 == ctx->r1) {
        // 0x80032110: lbu         $t0, 0x111($a2)
        ctx->r8 = MEM_BU(ctx->r6, 0X111);
            goto L_80032120;
    }
    goto skip_3;
    // 0x80032110: lbu         $t0, 0x111($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X111);
    skip_3:
    // 0x80032114: bnel        $v1, $v0, L_800321CC
    if (ctx->r3 != ctx->r2) {
        // 0x80032118: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800321CC;
    }
    goto skip_4;
    // 0x80032118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8003211C: lbu         $t0, 0x111($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X111);
L_80032120:
    // 0x80032120: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80032124: beql        $t0, $zero, L_80032154
    if (ctx->r8 == 0) {
        // 0x80032128: lw          $t1, 0x24($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X24);
            goto L_80032154;
    }
    goto skip_5;
    // 0x80032128: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
    skip_5:
    // 0x8003212C: bne         $v1, $v0, L_80032140
    if (ctx->r3 != ctx->r2) {
        // 0x80032130: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80032140;
    }
    // 0x80032130: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80032134: jal         0x80032C5C
    // 0x80032138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80032C5C(rdram, ctx);
        goto after_0;
    // 0x80032138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003213C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80032140:
    // 0x80032140: jal         0x8002F19C
    // 0x80032144: nop

    func_8002F19C(rdram, ctx);
        goto after_1;
    // 0x80032144: nop

    after_1:
    // 0x80032148: b           L_800321CC
    // 0x8003214C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800321CC;
    // 0x8003214C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032150: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
L_80032154:
    // 0x80032154: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80032158: andi        $t2, $t1, 0x700
    ctx->r10 = ctx->r9 & 0X700;
    // 0x8003215C: beql        $t2, $zero, L_80032170
    if (ctx->r10 == 0) {
        // 0x80032160: lwc1        $f4, 0xC8($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_80032170;
    }
    goto skip_6;
    // 0x80032160: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    skip_6:
    // 0x80032164: b           L_80032190
    // 0x80032168: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
        goto L_80032190;
    // 0x80032168: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x8003216C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
L_80032170:
    // 0x80032170: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80032174: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    // 0x80032178: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003217C: nop

    // 0x80032180: bc1f        L_80032190
    if (!c1cs) {
        // 0x80032184: nop
    
            goto L_80032190;
    }
    // 0x80032184: nop

    // 0x80032188: b           L_80032190
    // 0x8003218C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
        goto L_80032190;
    // 0x8003218C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
L_80032190:
    // 0x80032190: bnel        $v1, $v0, L_800321B8
    if (ctx->r3 != ctx->r2) {
        // 0x80032194: sb          $zero, 0x158($a2)
        MEM_B(0X158, ctx->r6) = 0;
            goto L_800321B8;
    }
    goto skip_7;
    // 0x80032194: sb          $zero, 0x158($a2)
    MEM_B(0X158, ctx->r6) = 0;
    skip_7:
    // 0x80032198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003219C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800321A0: jal         0x80032C5C
    // 0x800321A4: sb          $a3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r7;
    func_80032C5C(rdram, ctx);
        goto after_2;
    // 0x800321A4: sb          $a3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r7;
    after_2:
    // 0x800321A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800321AC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800321B0: lbu         $a3, 0x1B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1B);
    // 0x800321B4: sb          $zero, 0x158($a2)
    MEM_B(0X158, ctx->r6) = 0;
L_800321B8:
    // 0x800321B8: jal         0x8002EE54
    // 0x800321BC: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    func_8002EE54(rdram, ctx);
        goto after_3;
    // 0x800321BC: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_3:
    // 0x800321C0: b           L_800321CC
    // 0x800321C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800321CC;
    // 0x800321C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800321C8:
    // 0x800321C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800321CC:
    // 0x800321CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800321D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800321D4: jr          $ra
    // 0x800321D8: nop

    return;
    // 0x800321D8: nop

;}
RECOMP_FUNC void func_80532D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532D94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80532D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80532D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80532DA0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80532DA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80532DA8: lw          $s0, 0x1C($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X1C);
    // 0x80532DAC: beq         $s0, $zero, L_80532DE8
    if (ctx->r16 == 0) {
        // 0x80532DB0: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_80532DE8;
    }
    // 0x80532DB0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80532DB4: jal         0x80048378
    // 0x80532DB8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80532DB8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80532DBC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80532DC0: jal         0x80047AB8
    // 0x80532DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80532DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80532DC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80532DCC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80532DD0: jal         0x80065490
    // 0x80532DD4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x80532DD4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_2:
    // 0x80532DD8: jal         0x8004816C
    // 0x80532DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004816C(rdram, ctx);
        goto after_3;
    // 0x80532DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80532DE0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80532DE4: sw          $zero, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = 0;
L_80532DE8:
    // 0x80532DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80532DEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80532DF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80532DF4: jr          $ra
    // 0x80532DF8: nop

    return;
    // 0x80532DF8: nop

;}
RECOMP_FUNC void func_8043AD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AD9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043ADA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043ADA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043ADA8: jal         0x80045A34
    // 0x8043ADAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8043ADAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8043ADB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043ADB4: bne         $v0, $zero, L_8043ADC4
    if (ctx->r2 != 0) {
        // 0x8043ADB8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8043ADC4;
    }
    // 0x8043ADB8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8043ADBC: b           L_8043ADD4
    // 0x8043ADC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043ADD4;
    // 0x8043ADC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043ADC4:
    // 0x8043ADC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8043ADC8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043ADCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043ADD0: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_8043ADD4:
    // 0x8043ADD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043ADD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043ADDC: jr          $ra
    // 0x8043ADE0: nop

    return;
    // 0x8043ADE0: nop

;}
RECOMP_FUNC void func_8051ADC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051ADC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051ADC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8051ADC8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8051ADCC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8051ADD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051ADD4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8051ADD8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8051ADDC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8051ADE0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8051ADE4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8051ADE8: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(294, 0XC98) << 16);
    // 0x8051ADEC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8051ADF0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8051ADF4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8051ADF8: lw          $t2, -0x4E48($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(294, 0XC98));
    // 0x8051ADFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8051AE00: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8051AE04: jal         0x8051AD50
    // 0x8051AE08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8051AD50(rdram, ctx);
        goto after_0;
    // 0x8051AE08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051AE0C: jal         0x8051A858
    // 0x8051AE10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8051A858(rdram, ctx);
        goto after_1;
    // 0x8051AE10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8051AE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051AE18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051AE1C: jr          $ra
    // 0x8051AE20: nop

    return;
    // 0x8051AE20: nop

    // 0x8051AE24: nop

    // 0x8051AE28: nop

    // 0x8051AE2C: nop

;}
RECOMP_FUNC void func_804706B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804706B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804706BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804706C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804706C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804706C8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804706CC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x804706D0: jal         0x8047012C
    // 0x804706D4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8047012C(rdram, ctx);
        goto after_0;
    // 0x804706D4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x804706D8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x804706DC: jal         0x80470274
    // 0x804706E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80470274(rdram, ctx);
        goto after_1;
    // 0x804706E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x804706E4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x804706E8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x804706EC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x804706F0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x804706F4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x804706F8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x804706FC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80470700: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80470704: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80470708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8047070C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80470710: jr          $ra
    // 0x80470714: nop

    return;
    // 0x80470714: nop

;}
RECOMP_FUNC void func_805A7A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A7A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7A40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A7A44: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A7A48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7A4C: jal         0x805A7440
    // 0x805A7A50: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_805A7440(rdram, ctx);
        goto after_0;
    // 0x805A7A50: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805A7A54: jal         0x800692D4
    // 0x805A7A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800692D4(rdram, ctx);
        goto after_1;
    // 0x805A7A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A7A5C: jal         0x805A7620
    // 0x805A7A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7620(rdram, ctx);
        goto after_2;
    // 0x805A7A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A7A64: beq         $v0, $zero, L_805A7A84
    if (ctx->r2 == 0) {
        // 0x805A7A68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A7A84;
    }
    // 0x805A7A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A7A70: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A7A74: jal         0x805A8794
    // 0x805A7A78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A8794(rdram, ctx);
        goto after_3;
    // 0x805A7A78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x805A7A7C: b           L_805A7AF0
    // 0x805A7A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A7AF0;
    // 0x805A7A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7A84:
    // 0x805A7A84: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x805A7A88: beq         $v0, $zero, L_805A7A98
    if (ctx->r2 == 0) {
        // 0x805A7A8C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805A7A98;
    }
    // 0x805A7A8C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805A7A90: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
    // 0x805A7A94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_805A7A98:
    // 0x805A7A98: bne         $v0, $zero, L_805A7AE4
    if (ctx->r2 != 0) {
        // 0x805A7A9C: nop
    
            goto L_805A7AE4;
    }
    // 0x805A7A9C: nop

    // 0x805A7AA0: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x805A7AA4: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x805A7AA8: lh          $t7, 0x184($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X184);
    // 0x805A7AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7AB0: beql        $t7, $zero, L_805A7AD4
    if (ctx->r15 == 0) {
        // 0x805A7AB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A7AD4;
    }
    goto skip_0;
    // 0x805A7AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x805A7AB8: jal         0x80047EB0
    // 0x805A7ABC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    func_80047EB0(rdram, ctx);
        goto after_4;
    // 0x805A7ABC: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x805A7AC0: beql        $v0, $zero, L_805A7AD4
    if (ctx->r2 == 0) {
        // 0x805A7AC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A7AD4;
    }
    goto skip_1;
    // 0x805A7AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x805A7AC8: jal         0x8004816C
    // 0x805A7ACC: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    func_8004816C(rdram, ctx);
        goto after_5;
    // 0x805A7ACC: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_5:
    // 0x805A7AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805A7AD4:
    // 0x805A7AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A7AD8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A7ADC: jal         0x805A8794
    // 0x805A7AE0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A8794(rdram, ctx);
        goto after_6;
    // 0x805A7AE0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_6:
L_805A7AE4:
    // 0x805A7AE4: jal         0x805A7460
    // 0x805A7AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7460(rdram, ctx);
        goto after_7;
    // 0x805A7AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805A7AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7AF0:
    // 0x805A7AF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A7AF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A7AF8: jr          $ra
    // 0x805A7AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805A7AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8042F4BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F4BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042F4C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042F4C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042F4C8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8042F4CC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8042F4D0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8042F4D4: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x8042F4D8: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8042F4DC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8042F4E0: addiu       $t7, $t7, 0x1230
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x8042F4E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8042F4E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042F4EC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8042F4F0: jal         0x80045A34
    // 0x8042F4F4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8042F4F4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8042F4F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8042F4FC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8042F500: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8042F504: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8042F508: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042F50C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8042F510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042F514: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x8042F518: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042F51C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042F520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042F524: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8042F528:
    // 0x8042F528: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8042F52C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8042F530: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042F534: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8042F538: bne         $a1, $v0, L_8042F528
    if (ctx->r5 != ctx->r2) {
        // 0x8042F53C: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8042F528;
    }
    // 0x8042F53C: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8042F540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F544: jal         0x8042F574
    // 0x8042F548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8042F574(rdram, ctx);
        goto after_1;
    // 0x8042F548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8042F54C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8042F550: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8042F554: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8042F558: jal         0x8042F4A4
    // 0x8042F55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042F4A4(rdram, ctx);
        goto after_2;
    // 0x8042F55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042F560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042F564: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042F568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042F56C: jr          $ra
    // 0x8042F570: nop

    return;
    // 0x8042F570: nop

;}
RECOMP_FUNC void func_8046FC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046FC9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046FCA0: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(149, 0X1234) << 16);
    // 0x8046FCA4: lwc1        $f2, 0xE44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(149, 0X1234));
    // 0x8046FCA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8046FCAC: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8046FCB0: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8046FCB4: lw          $v1, 0x1088($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1088);
    // 0x8046FCB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8046FCBC:
    // 0x8046FCBC: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FCC0: lh          $t0, 0xFE2($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE2);
    // 0x8046FCC4: lh          $t6, 0xF40($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XF40);
    // 0x8046FCC8: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FCCC: subu        $t5, $t0, $t1
    ctx->r13 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FCD0: lh          $t7, 0x1146($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FCD4: lw          $a0, 0x1084($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1084);
    // 0x8046FCD8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8046FCDC: subu        $t2, $t6, $t7
    ctx->r10 = SUB32(ctx->r14, ctx->r15);
    // 0x8046FCE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046FCE4: mflo        $t8
    ctx->r24 = lo;
    // 0x8046FCE8: subu        $t9, $t0, $t8
    ctx->r25 = SUB32(ctx->r8, ctx->r24);
    // 0x8046FCEC: nop

    // 0x8046FCF0: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FCF4: mflo        $t6
    ctx->r14 = lo;
    // 0x8046FCF8: nop

    // 0x8046FCFC: nop

    // 0x8046FD00: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FD04: mflo        $t7
    ctx->r15 = lo;
    // 0x8046FD08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8046FD0C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8046FD10: nop

    // 0x8046FD14: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8046FD18: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8046FD1C: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8046FD20: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8046FD24: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8046FD28: nop

    // 0x8046FD2C: sh          $t5, 0x10A2($a3)
    MEM_H(0X10A2, ctx->r7) = ctx->r13;
    // 0x8046FD30: lw          $t6, 0x108C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FD34: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8046FD38: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FD3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8046FD40: lh          $t0, 0xFE2($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE2);
    // 0x8046FD44: beq         $a1, $t4, L_8046FEFC
    if (ctx->r5 == ctx->r12) {
        // 0x8046FD48: multu       $t1, $t3
        result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8046FEFC;
    }
    // 0x8046FD48: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8046FD4C:
    // 0x8046FD4C: lh          $t7, 0xF40($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XF40);
    // 0x8046FD50: lh          $t8, 0x1146($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FD54: mflo        $t9
    ctx->r25 = lo;
    // 0x8046FD58: subu        $t5, $t0, $t9
    ctx->r13 = SUB32(ctx->r8, ctx->r25);
    // 0x8046FD5C: subu        $t2, $t7, $t8
    ctx->r10 = SUB32(ctx->r15, ctx->r24);
    // 0x8046FD60: subu        $t6, $t0, $t1
    ctx->r14 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FD64: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FD68: lh          $t0, 0xFE4($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE4);
    // 0x8046FD6C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8046FD70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8046FD74: mflo        $t7
    ctx->r15 = lo;
    // 0x8046FD78: nop

    // 0x8046FD7C: nop

    // 0x8046FD80: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FD84: mflo        $t8
    ctx->r24 = lo;
    // 0x8046FD88: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8046FD8C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8046FD90: lh          $t8, 0xF3A($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XF3A);
    // 0x8046FD94: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046FD98: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8046FD9C: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8046FDA0: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046FDA4: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8046FDA8: nop

    // 0x8046FDAC: sh          $t6, 0x109C($a3)
    MEM_H(0X109C, ctx->r7) = ctx->r14;
    // 0x8046FDB0: lw          $t7, 0x108C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FDB4: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FDB8: lh          $t9, 0x1146($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FDBC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8046FDC0: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FDC4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x8046FDC8: subu        $t7, $t0, $t1
    ctx->r15 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FDCC: mflo        $t5
    ctx->r13 = lo;
    // 0x8046FDD0: subu        $t6, $t0, $t5
    ctx->r14 = SUB32(ctx->r8, ctx->r13);
    // 0x8046FDD4: lh          $t0, 0xFDE($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFDE);
    // 0x8046FDD8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FDDC: mflo        $t8
    ctx->r24 = lo;
    // 0x8046FDE0: nop

    // 0x8046FDE4: nop

    // 0x8046FDE8: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FDEC: mflo        $t9
    ctx->r25 = lo;
    // 0x8046FDF0: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x8046FDF4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8046FDF8: lh          $t9, 0xF3C($a3)
    ctx->r25 = MEM_H(ctx->r7, 0XF3C);
    // 0x8046FDFC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046FE00: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8046FE04: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8046FE08: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046FE0C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8046FE10: nop

    // 0x8046FE14: sh          $t7, 0x109E($a3)
    MEM_H(0X109E, ctx->r7) = ctx->r15;
    // 0x8046FE18: lw          $t8, 0x108C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FE1C: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FE20: lh          $t5, 0x1146($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FE24: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8046FE28: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FE2C: subu        $t2, $t9, $t5
    ctx->r10 = SUB32(ctx->r25, ctx->r13);
    // 0x8046FE30: subu        $t8, $t0, $t1
    ctx->r24 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FE34: mflo        $t6
    ctx->r14 = lo;
    // 0x8046FE38: subu        $t7, $t0, $t6
    ctx->r15 = SUB32(ctx->r8, ctx->r14);
    // 0x8046FE3C: lh          $t0, 0xFE0($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE0);
    // 0x8046FE40: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FE44: mflo        $t9
    ctx->r25 = lo;
    // 0x8046FE48: nop

    // 0x8046FE4C: nop

    // 0x8046FE50: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FE54: mflo        $t5
    ctx->r13 = lo;
    // 0x8046FE58: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8046FE5C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8046FE60: lh          $t5, 0xF3E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XF3E);
    // 0x8046FE64: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046FE68: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8046FE6C: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8046FE70: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046FE74: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8046FE78: nop

    // 0x8046FE7C: sh          $t8, 0x10A0($a3)
    MEM_H(0X10A0, ctx->r7) = ctx->r24;
    // 0x8046FE80: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FE84: lw          $t9, 0x108C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FE88: lh          $t6, 0x1146($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FE8C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FE90: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8046FE94: subu        $t2, $t5, $t6
    ctx->r10 = SUB32(ctx->r13, ctx->r14);
    // 0x8046FE98: subu        $t9, $t0, $t1
    ctx->r25 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FE9C: mflo        $t7
    ctx->r15 = lo;
    // 0x8046FEA0: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x8046FEA4: lh          $t0, 0xFE2($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE2);
    // 0x8046FEA8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FEAC: mflo        $t5
    ctx->r13 = lo;
    // 0x8046FEB0: nop

    // 0x8046FEB4: nop

    // 0x8046FEB8: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FEBC: mflo        $t6
    ctx->r14 = lo;
    // 0x8046FEC0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8046FEC4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8046FEC8: nop

    // 0x8046FECC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046FED0: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8046FED4: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8046FED8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046FEDC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8046FEE0: nop

    // 0x8046FEE4: sh          $t9, 0x10A2($a3)
    MEM_H(0X10A2, ctx->r7) = ctx->r25;
    // 0x8046FEE8: lw          $t5, 0x108C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FEEC: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FEF0: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8046FEF4: bne         $a1, $t4, L_8046FD4C
    if (ctx->r5 != ctx->r12) {
        // 0x8046FEF8: multu       $t1, $t3
        result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8046FD4C;
    }
    // 0x8046FEF8: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8046FEFC:
    // 0x8046FEFC: mflo        $t9
    ctx->r25 = lo;
    // 0x8046FF00: subu        $t5, $t0, $t9
    ctx->r13 = SUB32(ctx->r8, ctx->r25);
    // 0x8046FF04: subu        $t6, $t0, $t1
    ctx->r14 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FF08: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FF0C: lh          $t7, 0xF40($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XF40);
    // 0x8046FF10: lh          $t8, 0x1146($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FF14: lh          $t0, 0xFE4($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE4);
    // 0x8046FF18: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8046FF1C: subu        $t2, $t7, $t8
    ctx->r10 = SUB32(ctx->r15, ctx->r24);
    // 0x8046FF20: mflo        $t7
    ctx->r15 = lo;
    // 0x8046FF24: nop

    // 0x8046FF28: nop

    // 0x8046FF2C: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FF30: mflo        $t8
    ctx->r24 = lo;
    // 0x8046FF34: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8046FF38: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8046FF3C: lh          $t8, 0xF3A($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XF3A);
    // 0x8046FF40: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046FF44: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8046FF48: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8046FF4C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046FF50: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8046FF54: nop

    // 0x8046FF58: sh          $t6, 0x109C($a3)
    MEM_H(0X109C, ctx->r7) = ctx->r14;
    // 0x8046FF5C: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FF60: lw          $t7, 0x108C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FF64: lh          $t9, 0x1146($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FF68: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FF6C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8046FF70: subu        $t7, $t0, $t1
    ctx->r15 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FF74: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x8046FF78: mflo        $t5
    ctx->r13 = lo;
    // 0x8046FF7C: subu        $t6, $t0, $t5
    ctx->r14 = SUB32(ctx->r8, ctx->r13);
    // 0x8046FF80: lh          $t0, 0xFDE($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFDE);
    // 0x8046FF84: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FF88: mflo        $t8
    ctx->r24 = lo;
    // 0x8046FF8C: nop

    // 0x8046FF90: nop

    // 0x8046FF94: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FF98: mflo        $t9
    ctx->r25 = lo;
    // 0x8046FF9C: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x8046FFA0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8046FFA4: lh          $t9, 0xF3C($a3)
    ctx->r25 = MEM_H(ctx->r7, 0XF3C);
    // 0x8046FFA8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8046FFAC: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8046FFB0: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8046FFB4: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8046FFB8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8046FFBC: nop

    // 0x8046FFC0: sh          $t7, 0x109E($a3)
    MEM_H(0X109E, ctx->r7) = ctx->r15;
    // 0x8046FFC4: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x8046FFC8: lw          $t8, 0x108C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X108C);
    // 0x8046FFCC: lh          $t5, 0x1146($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1146);
    // 0x8046FFD0: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FFD4: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8046FFD8: subu        $t8, $t0, $t1
    ctx->r24 = SUB32(ctx->r8, ctx->r9);
    // 0x8046FFDC: subu        $t2, $t9, $t5
    ctx->r10 = SUB32(ctx->r25, ctx->r13);
    // 0x8046FFE0: mflo        $t6
    ctx->r14 = lo;
    // 0x8046FFE4: subu        $t7, $t0, $t6
    ctx->r15 = SUB32(ctx->r8, ctx->r14);
    // 0x8046FFE8: lh          $t0, 0xFE0($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XFE0);
    // 0x8046FFEC: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8046FFF0: mflo        $t9
    ctx->r25 = lo;
    // 0x8046FFF4: nop

    // 0x8046FFF8: nop

    // 0x8046FFFC: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470000: mflo        $t5
    ctx->r13 = lo;
    // 0x80470004: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80470008: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8047000C: lh          $t5, 0xF3E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XF3E);
    // 0x80470010: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80470014: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x80470018: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8047001C: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80470020: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80470024: nop

    // 0x80470028: sh          $t8, 0x10A0($a3)
    MEM_H(0X10A0, ctx->r7) = ctx->r24;
    // 0x8047002C: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x80470030: lw          $t9, 0x108C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X108C);
    // 0x80470034: lh          $t6, 0x1146($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1146);
    // 0x80470038: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8047003C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80470040: subu        $t9, $t0, $t1
    ctx->r25 = SUB32(ctx->r8, ctx->r9);
    // 0x80470044: subu        $t2, $t5, $t6
    ctx->r10 = SUB32(ctx->r13, ctx->r14);
    // 0x80470048: mflo        $t7
    ctx->r15 = lo;
    // 0x8047004C: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x80470050: nop

    // 0x80470054: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470058: mflo        $t5
    ctx->r13 = lo;
    // 0x8047005C: nop

    // 0x80470060: nop

    // 0x80470064: multu       $t2, $t2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470068: mflo        $t6
    ctx->r14 = lo;
    // 0x8047006C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80470070: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80470074: nop

    // 0x80470078: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8047007C: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x80470080: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80470084: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80470088: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8047008C: nop

    // 0x80470090: sh          $t9, 0x10A2($a3)
    MEM_H(0X10A2, ctx->r7) = ctx->r25;
    // 0x80470094: lw          $t5, 0x108C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X108C);
    // 0x80470098: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8047009C: lw          $t6, 0x1090($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1090);
    // 0x804700A0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x804700A4: bne         $a2, $t4, L_8046FCBC
    if (ctx->r6 != ctx->r12) {
        // 0x804700A8: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_8046FCBC;
    }
    // 0x804700A8: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x804700AC: lh          $t1, 0x1148($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1148);
    // 0x804700B0: lh          $v1, 0x1146($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1146);
    // 0x804700B4: multu       $t1, $t1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804700B8: mflo        $t7
    ctx->r15 = lo;
    // 0x804700BC: nop

    // 0x804700C0: nop

    // 0x804700C4: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804700C8: mflo        $t8
    ctx->r24 = lo;
    // 0x804700CC: nop

    // 0x804700D0: nop

    // 0x804700D4: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804700D8: mflo        $t9
    ctx->r25 = lo;
    // 0x804700DC: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x804700E0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x804700E4: nop

    // 0x804700E8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804700EC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804700F0: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x804700F4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804700F8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x804700FC: jr          $ra
    // 0x80470100: sh          $t7, 0x114A($v0)
    MEM_H(0X114A, ctx->r2) = ctx->r15;
    return;
    // 0x80470100: sh          $t7, 0x114A($v0)
    MEM_H(0X114A, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_804BDC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDC70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804BDC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BDC78: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804BDC7C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x804BDC80: jal         0x8004700C
    // 0x804BDC84: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804BDC84: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x804BDC88: beq         $v0, $zero, L_804BDCA0
    if (ctx->r2 == 0) {
        // 0x804BDC8C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804BDCA0;
    }
    // 0x804BDC8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804BDC90: jal         0x80047AB8
    // 0x804BDC94: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x804BDC94: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x804BDC98: b           L_804BDCB4
    // 0x804BDC9C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_804BDCB4;
    // 0x804BDC9C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_804BDCA0:
    // 0x804BDCA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BDCA4: nop

    // 0x804BDCA8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x804BDCAC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x804BDCB0: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_804BDCB4:
    // 0x804BDCB4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804BDCB8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804BDCBC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804BDCC0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804BDCC4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804BDCC8: jal         0x80067114
    // 0x804BDCCC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x804BDCCC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x804BDCD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804BDCD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x804BDCD8: lui         $at, 0xC307
    ctx->r1 = S32(0XC307 << 16);
    // 0x804BDCDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BDCE0: nop

    // 0x804BDCE4: bc1fl       L_804BDD10
    if (!c1cs) {
        // 0x804BDCE8: c.le.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
            goto L_804BDD10;
    }
    goto skip_0;
    // 0x804BDCE8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    skip_0:
    // 0x804BDCEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804BDCF0: nop

    // 0x804BDCF4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x804BDCF8: nop

    // 0x804BDCFC: bc1fl       L_804BDD10
    if (!c1cs) {
        // 0x804BDD00: c.le.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
            goto L_804BDD10;
    }
    goto skip_1;
    // 0x804BDD00: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    skip_1:
    // 0x804BDD04: b           L_804BDD38
    // 0x804BDD08: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_804BDD38;
    // 0x804BDD08: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x804BDD0C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
L_804BDD10:
    // 0x804BDD10: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x804BDD14: bc1f        L_804BDD38
    if (!c1cs) {
        // 0x804BDD18: nop
    
            goto L_804BDD38;
    }
    // 0x804BDD18: nop

    // 0x804BDD1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804BDD20: nop

    // 0x804BDD24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BDD28: nop

    // 0x804BDD2C: bc1f        L_804BDD38
    if (!c1cs) {
        // 0x804BDD30: nop
    
            goto L_804BDD38;
    }
    // 0x804BDD30: nop

    // 0x804BDD34: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_804BDD38:
    // 0x804BDD38: jal         0x80066E88
    // 0x804BDD3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x804BDD3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x804BDD40: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804BDD44: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x804BDD48: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804BDD4C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804BDD50: jal         0x80066DE4
    // 0x804BDD54: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x804BDD54: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    after_4:
    // 0x804BDD58: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804BDD5C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x804BDD60: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804BDD64: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x804BDD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BDD6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804BDD70: jr          $ra
    // 0x804BDD74: nop

    return;
    // 0x804BDD74: nop

;}
RECOMP_FUNC void func_805231C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805231C4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805231C8: lw          $t6, -0x71F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71F0);
    // 0x805231CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805231D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805231D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805231D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805231DC: beq         $t7, $zero, L_80523230
    if (ctx->r15 == 0) {
        // 0x805231E0: nop
    
            goto L_80523230;
    }
    // 0x805231E0: nop

    // 0x805231E4: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
    // 0x805231E8: beql        $t8, $zero, L_8052321C
    if (ctx->r24 == 0) {
        // 0x805231EC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8052321C;
    }
    goto skip_0;
    // 0x805231EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x805231F0: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x805231F4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805231F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805231FC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80523200: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    // 0x80523204: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80523208: jal         0x8005FCA8
    // 0x8052320C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x8052320C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80523210: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80523214: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80523218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8052321C:
    // 0x8052321C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80523220: jal         0x80522AD4
    // 0x80523224: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80522AD4(rdram, ctx);
        goto after_1;
    // 0x80523224: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80523228: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8052322C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80523230:
    // 0x80523230: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80523234: lw          $t2, -0x72D8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X72D8);
    // 0x80523238: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8052323C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80523240: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80523244: addiu       $t5, $zero, 0x13
    ctx->r13 = ADD32(0, 0X13);
    // 0x80523248: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8052324C: bnel        $v1, $t3, L_80523268
    if (ctx->r3 != ctx->r11) {
        // 0x80523250: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80523268;
    }
    goto skip_1;
    // 0x80523250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80523254: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x80523258: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8052325C: jal         0x80523830
    // 0x80523260: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    func_80523830(rdram, ctx);
        goto after_2;
    // 0x80523260: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    after_2:
    // 0x80523264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80523268:
    // 0x80523268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052326C: jr          $ra
    // 0x80523270: nop

    return;
    // 0x80523270: nop

;}
RECOMP_FUNC void func_80473B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473B34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80473B38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80473B3C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80473B40: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80473B44: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80473B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473B4C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80473B50: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80473B54: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80473B58: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80473B5C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80473B60: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80473B64: lw          $t9, 0x38($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X38);
    // 0x80473B68: jalr        $t9
    // 0x80473B6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80473B6C: nop

    after_0:
    // 0x80473B70: bne         $v0, $zero, L_80473B80
    if (ctx->r2 != 0) {
        // 0x80473B74: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80473B80;
    }
    // 0x80473B74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80473B78: b           L_80473B8C
    // 0x80473B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80473B8C;
    // 0x80473B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80473B80:
    // 0x80473B80: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80473B84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80473B88: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
L_80473B8C:
    // 0x80473B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80473B90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80473B94: jr          $ra
    // 0x80473B98: nop

    return;
    // 0x80473B98: nop

;}
RECOMP_FUNC void func_800678B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800678B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800678B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800678B8: jal         0x80011C64
    // 0x800678BC: nop

    func_80011C64(rdram, ctx);
        goto after_0;
    // 0x800678BC: nop

    after_0:
    // 0x800678C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800678C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800678C8: jr          $ra
    // 0x800678CC: nop

    return;
    // 0x800678CC: nop

;}
RECOMP_FUNC void func_8042EA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EA74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042EA78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042EA7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042EA80: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8042EA84: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8042EA88: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8042EA8C: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(56, 0X3150) << 16);
    // 0x8042EA90: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8042EA94: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8042EA98: addiu       $t7, $t7, 0x1230
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(56, 0X3150));
    // 0x8042EA9C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8042EAA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042EAA4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8042EAA8: jal         0x80045A34
    // 0x8042EAAC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8042EAAC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8042EAB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8042EAB4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8042EAB8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8042EABC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8042EAC0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042EAC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8042EAC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042EACC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8042EAD0:
    // 0x8042EAD0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8042EAD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8042EAD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042EADC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8042EAE0: bne         $a1, $v0, L_8042EAD0
    if (ctx->r5 != ctx->r2) {
        // 0x8042EAE4: swc1        $f6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
            goto L_8042EAD0;
    }
    // 0x8042EAE4: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8042EAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EAEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042EAF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042EAF4: jal         0x8042EB3C
    // 0x8042EAF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042EB3C(rdram, ctx);
        goto after_1;
    // 0x8042EAF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8042EAFC: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x8042EB00: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X32BC) << 16);
    // 0x8042EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042EB08: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042EB0C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8042EB10: lwc1        $f8, 0x139C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X32BC));
    // 0x8042EB14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042EB18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042EB1C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x8042EB20: jal         0x8042EA5C
    // 0x8042EB24: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    func_8042EA5C(rdram, ctx);
        goto after_2;
    // 0x8042EB24: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8042EB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042EB2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042EB30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042EB34: jr          $ra
    // 0x8042EB38: nop

    return;
    // 0x8042EB38: nop

;}
