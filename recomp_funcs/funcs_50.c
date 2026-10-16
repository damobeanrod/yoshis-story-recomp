#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80438B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80438B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438B68: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80438B6C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80438B70: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80438B74: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(80, 0X1960) << 16);
    // 0x80438B78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80438B7C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80438B80: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80438B84: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80438B88: lw          $t8, -0x5BE0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(80, 0X1960));
    // 0x80438B8C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80438B90: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80438B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80438B98: jal         0x80048490
    // 0x80438B9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80438B9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80438BA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80438BA4: jal         0x80048378
    // 0x80438BA8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80438BA8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80438BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80438BB4: jr          $ra
    // 0x80438BB8: nop

    return;
    // 0x80438BB8: nop

;}
RECOMP_FUNC void func_8040EE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EE38: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EE3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8040EE40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040EE44: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8040EE48: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8040EE4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8040EE50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8040EE54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EE58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8040EE5C: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8040EE60: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040EE64: lwc1        $f10, 0x10($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8040EE68: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8040EE6C: nop

    // 0x8040EE70: bc1f        L_8040EE88
    if (!c1cs) {
        // 0x8040EE74: nop
    
            goto L_8040EE88;
    }
    // 0x8040EE74: nop

    // 0x8040EE78: jal         0x8040EB60
    // 0x8040EE7C: nop

    func_8040EB60(rdram, ctx);
        goto after_0;
    // 0x8040EE7C: nop

    after_0:
    // 0x8040EE80: b           L_8040EE94
    // 0x8040EE84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040EE94;
    // 0x8040EE84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EE88:
    // 0x8040EE88: jal         0x8040F0B8
    // 0x8040EE8C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8040F0B8(rdram, ctx);
        goto after_1;
    // 0x8040EE8C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
    // 0x8040EE90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EE94:
    // 0x8040EE94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EE98: jr          $ra
    // 0x8040EE9C: nop

    return;
    // 0x8040EE9C: nop

;}
RECOMP_FUNC void func_806EE2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE2B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EE2B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EE2BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806EE2C0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806EE2C4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806EE2C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806EE2CC: beq         $v0, $at, L_806EE2E8
    if (ctx->r2 == ctx->r1) {
        // 0x806EE2D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806EE2E8;
    }
    // 0x806EE2D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EE2D4: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806EE2D8: beq         $v0, $at, L_806EE2F8
    if (ctx->r2 == ctx->r1) {
        // 0x806EE2DC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_806EE2F8;
    }
    // 0x806EE2DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806EE2E0: b           L_806EE32C
    // 0x806EE2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806EE32C;
    // 0x806EE2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EE2E8:
    // 0x806EE2E8: jal         0x806EE258
    // 0x806EE2EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_806EE258(rdram, ctx);
        goto after_0;
    // 0x806EE2EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x806EE2F0: b           L_806EE32C
    // 0x806EE2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806EE32C;
    // 0x806EE2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EE2F8:
    // 0x806EE2F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806EE2FC: jal         0x806EE124
    // 0x806EE300: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_806EE124(rdram, ctx);
        goto after_1;
    // 0x806EE300: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_1:
    // 0x806EE304: beq         $v0, $zero, L_806EE328
    if (ctx->r2 == 0) {
        // 0x806EE308: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_806EE328;
    }
    // 0x806EE308: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806EE30C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x806EE310: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x806EE314: jal         0x80067D5C
    // 0x806EE318: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x806EE318: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_2:
    // 0x806EE31C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x806EE320: jal         0x80067818
    // 0x806EE324: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806EE324: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_806EE328:
    // 0x806EE328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EE32C:
    // 0x806EE32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE330: jr          $ra
    // 0x806EE334: nop

    return;
    // 0x806EE334: nop

;}
RECOMP_FUNC void func_805A2A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A2A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A2A30: jal         0x805A27E8
    // 0x805A2A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A27E8(rdram, ctx);
        goto after_0;
    // 0x805A2A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A2A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A2A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2A40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805A2A44: jal         0x805A2B28
    // 0x805A2A48: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_1;
    // 0x805A2A48: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x805A2A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A2A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A2A54: jr          $ra
    // 0x805A2A58: nop

    return;
    // 0x805A2A58: nop

;}
RECOMP_FUNC void func_8004115C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004115C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80041160: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80041164: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80041168: lw          $t7, -0xB04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB04);
    // 0x8004116C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041170: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80041174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041178: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8004117C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80041180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041184: beq         $v1, $zero, L_8004119C
    if (ctx->r3 == 0) {
        // 0x80041188: nop
    
            goto L_8004119C;
    }
    // 0x80041188: nop

    // 0x8004118C: jalr        $v1
    // 0x80041190: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80041190: nop

    after_0:
    // 0x80041194: b           L_800411A0
    // 0x80041198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800411A0;
    // 0x80041198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004119C:
    // 0x8004119C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800411A0:
    // 0x800411A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800411A4: jr          $ra
    // 0x800411A8: nop

    return;
    // 0x800411A8: nop

;}
RECOMP_FUNC void func_80062BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80062BAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80062BB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80062BB4: jal         0x80065954
    // 0x80062BB8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80062BB8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80062BBC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80062BC0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80062BC4: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80062BC8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80062BCC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80062BD0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80062BD4: jal         0x80065954
    // 0x80062BD8: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80062BD8: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    after_1:
    // 0x80062BDC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80062BE0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80062BE4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80062BE8: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80062BEC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80062BF0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80062BF4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80062BF8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80062BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C00: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80062C04: nop

    // 0x80062C08: bc1fl       L_80062C40
    if (!c1cs) {
        // 0x80062C0C: lwc1        $f8, 0x4($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
            goto L_80062C40;
    }
    goto skip_0;
    // 0x80062C0C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80062C10: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80062C14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80062C18: nop

    // 0x80062C1C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80062C20: nop

    // 0x80062C24: bc1f        L_80062C34
    if (!c1cs) {
        // 0x80062C28: nop
    
            goto L_80062C34;
    }
    // 0x80062C28: nop

    // 0x80062C2C: b           L_80062C60
    // 0x80062C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80062C60;
    // 0x80062C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80062C34:
    // 0x80062C34: b           L_80062C60
    // 0x80062C38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80062C60;
    // 0x80062C38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80062C3C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
L_80062C40:
    // 0x80062C40: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80062C44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80062C48: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80062C4C: nop

    // 0x80062C50: bc1f        L_80062C60
    if (!c1cs) {
        // 0x80062C54: nop
    
            goto L_80062C60;
    }
    // 0x80062C54: nop

    // 0x80062C58: b           L_80062C60
    // 0x80062C5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80062C60;
    // 0x80062C5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80062C60:
    // 0x80062C60: jr          $ra
    // 0x80062C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80062C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062C68: nop

    // 0x80062C6C: nop

;}
RECOMP_FUNC void func_80019CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019CC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019CC4: jal         0x80019B94
    // 0x80019CC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80019B94(rdram, ctx);
        goto after_0;
    // 0x80019CC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80019CCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80019CD0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80019CD4: beq         $v0, $zero, L_80019D18
    if (ctx->r2 == 0) {
        // 0x80019CD8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80019D18;
    }
    // 0x80019CD8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80019CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019CE0: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
L_80019CE4:
    // 0x80019CE4: bnel        $v0, $t6, L_80019D10
    if (ctx->r2 != ctx->r14) {
        // 0x80019CE8: lw          $v1, 0x44($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X44);
            goto L_80019D10;
    }
    goto skip_0;
    // 0x80019CE8: lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X44);
    skip_0:
    // 0x80019CEC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80019CF0: bnel        $a1, $t7, L_80019D10
    if (ctx->r5 != ctx->r15) {
        // 0x80019CF4: lw          $v1, 0x44($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X44);
            goto L_80019D10;
    }
    goto skip_1;
    // 0x80019CF4: lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X44);
    skip_1:
    // 0x80019CF8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80019CFC: bnel        $a0, $t8, L_80019D10
    if (ctx->r4 != ctx->r24) {
        // 0x80019D00: lw          $v1, 0x44($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X44);
            goto L_80019D10;
    }
    goto skip_2;
    // 0x80019D00: lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X44);
    skip_2:
    // 0x80019D04: b           L_80019D1C
    // 0x80019D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80019D1C;
    // 0x80019D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019D0C: lw          $v1, 0x44($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X44);
L_80019D10:
    // 0x80019D10: bnel        $v1, $zero, L_80019CE4
    if (ctx->r3 != 0) {
        // 0x80019D14: lw          $t6, 0x4($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X4);
            goto L_80019CE4;
    }
    goto skip_3;
    // 0x80019D14: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    skip_3:
L_80019D18:
    // 0x80019D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80019D1C:
    // 0x80019D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019D24: jr          $ra
    // 0x80019D28: nop

    return;
    // 0x80019D28: nop

    // 0x80019D2C: nop

;}
RECOMP_FUNC void func_804F5A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5A00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804F5A04: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804F5A08: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x804F5A0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F5A10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804F5A14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804F5A18: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804F5A1C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5A20: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804F5A24: jal         0x804F4F50
    // 0x804F5A28: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_804F4F50(rdram, ctx);
        goto after_0;
    // 0x804F5A28: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_0:
    // 0x804F5A2C: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x804F5A30: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x804F5A34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804F5A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804F5A3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804F5A40: nop

    // 0x804F5A44: bc1fl       L_804F5A5C
    if (!c1cs) {
        // 0x804F5A48: swc1        $f0, 0x40($s1)
        MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
            goto L_804F5A5C;
    }
    goto skip_0;
    // 0x804F5A48: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    skip_0:
    // 0x804F5A4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804F5A50: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804F5A54: swc1        $f4, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f4.u32l;
    // 0x804F5A58: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
L_804F5A5C:
    // 0x804F5A5C: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x804F5A60: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x804F5A64: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804F5A68: nop

    // 0x804F5A6C: bc1fl       L_804F5ABC
    if (!c1cs) {
        // 0x804F5A70: lw          $t0, 0x10($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X10);
            goto L_804F5ABC;
    }
    goto skip_1;
    // 0x804F5A70: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x804F5A74: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x804F5A78: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x804F5A7C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x804F5A80: nop

    // 0x804F5A84: bc1fl       L_804F5ABC
    if (!c1cs) {
        // 0x804F5A88: lw          $t0, 0x10($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X10);
            goto L_804F5ABC;
    }
    goto skip_2;
    // 0x804F5A88: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x804F5A8C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x804F5A90: lw          $a1, 0x3C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X3C);
    // 0x804F5A94: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x804F5A98: lw          $v0, 0x1F4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X1F4);
    // 0x804F5A9C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x804F5AA0: lw          $a0, 0x115C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X115C);
    // 0x804F5AA4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x804F5AA8: lw          $t9, 0x1160($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1160);
    // 0x804F5AAC: jalr        $t9
    // 0x804F5AB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x804F5AB0: nop

    after_1:
    // 0x804F5AB4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804F5AB8: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
L_804F5ABC:
    // 0x804F5ABC: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x804F5AC0: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x804F5AC4: bne         $at, $zero, L_804F5B7C
    if (ctx->r1 != 0) {
        // 0x804F5AC8: sw          $v0, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r2;
            goto L_804F5B7C;
    }
    // 0x804F5AC8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x804F5ACC: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x804F5AD0: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x804F5AD4: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x804F5AD8: nop

    // 0x804F5ADC: bc1f        L_804F5B74
    if (!c1cs) {
        // 0x804F5AE0: nop
    
            goto L_804F5B74;
    }
    // 0x804F5AE0: nop

    // 0x804F5AE4: jal         0x804F4C94
    // 0x804F5AE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804F4C94(rdram, ctx);
        goto after_2;
    // 0x804F5AE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x804F5AEC: lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XC);
    // 0x804F5AF0: addiu       $at, $zero, 0x41EC
    ctx->r1 = ADD32(0, 0X41EC);
    // 0x804F5AF4: sw          $v0, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r2;
    // 0x804F5AF8: beq         $v1, $at, L_804F5B14
    if (ctx->r3 == ctx->r1) {
        // 0x804F5AFC: addiu       $t2, $zero, 0x12C
        ctx->r10 = ADD32(0, 0X12C);
            goto L_804F5B14;
    }
    // 0x804F5AFC: addiu       $t2, $zero, 0x12C
    ctx->r10 = ADD32(0, 0X12C);
    // 0x804F5B00: addiu       $at, $zero, 0x4594
    ctx->r1 = ADD32(0, 0X4594);
    // 0x804F5B04: beq         $v1, $at, L_804F5B54
    if (ctx->r3 == ctx->r1) {
        // 0x804F5B08: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_804F5B54;
    }
    // 0x804F5B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804F5B0C: b           L_804F5BE8
    // 0x804F5B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804F5BE8;
    // 0x804F5B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F5B14:
    // 0x804F5B14: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
    // 0x804F5B18: addiu       $t3, $s1, 0xC4
    ctx->r11 = ADD32(ctx->r17, 0XC4);
    // 0x804F5B1C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x804F5B20: jal         0x804F536C
    // 0x804F5B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804F536C(rdram, ctx);
        goto after_3;
    // 0x804F5B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804F5B28: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804F5B2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F5B30: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x804F5B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804F5B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F5B3C: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x804F5B40: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    // 0x804F5B44: jal         0x804F5CE8
    // 0x804F5B48: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_804F5CE8(rdram, ctx);
        goto after_4;
    // 0x804F5B48: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_4:
    // 0x804F5B4C: b           L_804F5BE8
    // 0x804F5B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804F5BE8;
    // 0x804F5B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F5B54:
    // 0x804F5B54: addiu       $t5, $s1, 0xC4
    ctx->r13 = ADD32(ctx->r17, 0XC4);
    // 0x804F5B58: jal         0x804F5598
    // 0x804F5B5C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    func_804F5598(rdram, ctx);
        goto after_5;
    // 0x804F5B5C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    after_5:
    // 0x804F5B60: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x804F5B64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804F5B68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804F5B6C: b           L_804F5BE4
    // 0x804F5B70: swc1        $f18, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f18.u32l;
        goto L_804F5BE4;
    // 0x804F5B70: swc1        $f18, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f18.u32l;
L_804F5B74:
    // 0x804F5B74: b           L_804F5BE4
    // 0x804F5B78: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
        goto L_804F5BE4;
    // 0x804F5B78: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_804F5B7C:
    // 0x804F5B7C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x804F5B80: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x804F5B84: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x804F5B88: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x804F5B8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804F5B90: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804F5B94: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804F5B98: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x804F5B9C: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X208D0) << 16);
    // 0x804F5BA0: lwc1        $f8, 0x4B60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X208D0));
    // 0x804F5BA4: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x804F5BA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F5BAC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804F5BB0: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x804F5BB4: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X208D4) << 16);
    // 0x804F5BB8: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x804F5BBC: swc1        $f18, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f18.u32l;
    // 0x804F5BC0: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x804F5BC4: lwc1        $f8, 0x4B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X208D4));
    // 0x804F5BC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804F5BCC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x804F5BD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F5BD4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804F5BD8: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804F5BDC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804F5BE0: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
L_804F5BE4:
    // 0x804F5BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F5BE8:
    // 0x804F5BE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804F5BEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804F5BF0: jr          $ra
    // 0x804F5BF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x804F5BF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80466940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466940: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(132, 0X1974) << 16);
    // 0x80466944: addiu       $v0, $v0, -0x7D4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(132, 0X1974));
    // 0x80466948: jr          $ra
    // 0x8046694C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8046694C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001AE7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001AE80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001AE84: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001AE88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001AE8C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001AE90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001AE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AE98: beq         $a0, $zero, L_8001AEB4
    if (ctx->r4 == 0) {
        // 0x8001AE9C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8001AEB4;
    }
    // 0x8001AE9C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001AEA0: lhu         $a0, 0x30($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X30);
    // 0x8001AEA4: jal         0x8001AF28
    // 0x8001AEA8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8001AF28(rdram, ctx);
        goto after_0;
    // 0x8001AEA8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001AEAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8001AEB0: sh          $v0, 0x30($a3)
    MEM_H(0X30, ctx->r7) = ctx->r2;
L_8001AEB4:
    // 0x8001AEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AEB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AEBC: jr          $ra
    // 0x8001AEC0: nop

    return;
    // 0x8001AEC0: nop

;}
RECOMP_FUNC void func_8004E79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E79C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004E7A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004E7A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004E7A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004E7AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004E7B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004E7B4: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x8004E7B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004E7BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004E7C0: jal         0x80047AB8
    // 0x8004E7C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004E7C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8004E7C8: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8004E7CC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8004E7D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E7D4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8004E7D8: lwc1        $f4, 0xC8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8004E7DC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8004E7E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E7E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004E7E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E7EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E7F0: bc1f        L_8004E824
    if (!c1cs) {
        // 0x8004E7F4: nop
    
            goto L_8004E824;
    }
    // 0x8004E7F4: nop

    // 0x8004E7F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E7FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E800: jal         0x8004DAA0
    // 0x8004E804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004DAA0(rdram, ctx);
        goto after_1;
    // 0x8004E804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8004E808: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E80C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004E814: jal         0x8004DDD4
    // 0x8004E818: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004DDD4(rdram, ctx);
        goto after_2;
    // 0x8004E818: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
    // 0x8004E81C: b           L_8004E840
    // 0x8004E820: nop

        goto L_8004E840;
    // 0x8004E820: nop

L_8004E824:
    // 0x8004E824: jal         0x8004DB70
    // 0x8004E828: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004DB70(rdram, ctx);
        goto after_3;
    // 0x8004E828: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x8004E82C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E830: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E834: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004E838: jal         0x8004DC08
    // 0x8004E83C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004DC08(rdram, ctx);
        goto after_4;
    // 0x8004E83C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_4:
L_8004E840:
    // 0x8004E840: jal         0x80049018
    // 0x8004E844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80049018(rdram, ctx);
        goto after_5;
    // 0x8004E844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8004E848: beq         $v0, $zero, L_8004E88C
    if (ctx->r2 == 0) {
        // 0x8004E84C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004E88C;
    }
    // 0x8004E84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E854: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E858: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8004E85C: jal         0x8004DF58
    // 0x8004E860: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004DF58(rdram, ctx);
        goto after_6;
    // 0x8004E860: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x8004E864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E868: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E86C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004E870: jal         0x8004DFC8
    // 0x8004E874: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004DFC8(rdram, ctx);
        goto after_7;
    // 0x8004E874: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_7:
    // 0x8004E878: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004E87C: sll         $t8, $t7, 28
    ctx->r24 = S32(ctx->r15 << 28);
    // 0x8004E880: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8004E884: b           L_8004E8C4
    // 0x8004E888: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
        goto L_8004E8C4;
    // 0x8004E888: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
L_8004E88C:
    // 0x8004E88C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E890: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004E894: jal         0x8004DE6C
    // 0x8004E898: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004DE6C(rdram, ctx);
        goto after_8;
    // 0x8004E898: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_8:
    // 0x8004E89C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8004E8A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E8A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E8A8: andi        $t0, $v0, 0xF0
    ctx->r8 = ctx->r2 & 0XF0;
    // 0x8004E8AC: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x8004E8B0: or          $t2, $v0, $t1
    ctx->r10 = ctx->r2 | ctx->r9;
    // 0x8004E8B4: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x8004E8B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8004E8BC: jal         0x8004E0B4
    // 0x8004E8C0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_8004E0B4(rdram, ctx);
        goto after_9;
    // 0x8004E8C0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_9:
L_8004E8C4:
    // 0x8004E8C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004E8C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004E8CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E8D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004E8D4: jr          $ra
    // 0x8004E8D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004E8D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805A04EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A04EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A04F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A04F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A04F8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805A04FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805A0500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A0504: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805A0508: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x805A050C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A0510: jal         0x80045A34
    // 0x805A0514: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A0514: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x805A0518: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805A051C: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x805A0520: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A0524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A0528: jal         0x805A0388
    // 0x805A052C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    func_805A0388(rdram, ctx);
        goto after_1;
    // 0x805A052C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    after_1:
    // 0x805A0530: bne         $v0, $zero, L_805A0548
    if (ctx->r2 != 0) {
        // 0x805A0534: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805A0548;
    }
    // 0x805A0534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A0538: jal         0x800447C8
    // 0x805A053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x805A053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A0540: b           L_805A057C
    // 0x805A0544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A057C;
    // 0x805A0544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A0548:
    // 0x805A0548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A054C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A0550: jal         0x805A0790
    // 0x805A0554: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805A0790(rdram, ctx);
        goto after_3;
    // 0x805A0554: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x805A0558: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805A055C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805A0560: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x805A0564: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805A0568: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A056C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x805A0570: jal         0x805A04D4
    // 0x805A0574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A04D4(rdram, ctx);
        goto after_4;
    // 0x805A0574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A0578: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A057C:
    // 0x805A057C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A0580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A0584: jr          $ra
    // 0x805A0588: nop

    return;
    // 0x805A0588: nop

;}
RECOMP_FUNC void func_8001CA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CA48: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8001CA4C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001CA50: lbu         $a1, 0x10($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X10);
    // 0x8001CA54: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x8001CA58: bne         $a1, $zero, L_8001CA78
    if (ctx->r5 != 0) {
        // 0x8001CA5C: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_8001CA78;
    }
    // 0x8001CA5C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8001CA60: jal         0x800447C8
    // 0x8001CA64: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8001CA64: nop

    after_0:
    // 0x8001CA68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001CA6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CA70: b           L_8001CB24
    // 0x8001CA74: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
        goto L_8001CB24;
    // 0x8001CA74: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
L_8001CA78:
    // 0x8001CA78: beq         $at, $zero, L_8001CA88
    if (ctx->r1 == 0) {
        // 0x8001CA7C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8001CA88;
    }
    // 0x8001CA7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001CA80: b           L_8001CA90
    // 0x8001CA84: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
        goto L_8001CA90;
    // 0x8001CA84: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
L_8001CA88:
    // 0x8001CA88: addiu       $t7, $a2, -0x4
    ctx->r15 = ADD32(ctx->r6, -0X4);
    // 0x8001CA8C: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
L_8001CA90:
    // 0x8001CA90: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8001CA94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001CA98: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001CA9C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8001CAA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001CAA4: nop

    // 0x8001CAA8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001CAAC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8001CAB0: nop

    // 0x8001CAB4: bc1fl       L_8001CAD4
    if (!c1cs) {
        // 0x8001CAB8: swc1        $f0, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
            goto L_8001CAD4;
    }
    goto skip_0;
    // 0x8001CAB8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8001CABC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8001CAC0:
    // 0x8001CAC0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8001CAC4: nop

    // 0x8001CAC8: bc1tl       L_8001CAC0
    if (c1cs) {
        // 0x8001CACC: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8001CAC0;
    }
    goto skip_1;
    // 0x8001CACC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x8001CAD0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_8001CAD4:
    // 0x8001CAD4: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8001CAD8: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8001CADC: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8001CAE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001CAE4: jal         0x80065ABC
    // 0x8001CAE8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8001CAE8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8001CAEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001CAF0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CAF4: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8001CAF8: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8001CAFC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001CB00: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001CB04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001CB08: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8001CB0C: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8001CB10: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8001CB14: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001CB18: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x8001CB1C: jal         0x800485B8
    // 0x8001CB20: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    func_800485B8(rdram, ctx);
        goto after_2;
    // 0x8001CB20: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    after_2:
L_8001CB24:
    // 0x8001CB24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CB28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CB2C: jr          $ra
    // 0x8001CB30: nop

    return;
    // 0x8001CB30: nop

;}
RECOMP_FUNC void func_805D3830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3838: jal         0x805D32C8
    // 0x805D383C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D32C8(rdram, ctx);
        goto after_0;
    // 0x805D383C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D3840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3844: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x805D3848: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D384C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D3850: jal         0x80045A34
    // 0x805D3854: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805D3854: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    after_1:
    // 0x805D3858: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D385C: beq         $v0, $zero, L_805D3B08
    if (ctx->r2 == 0) {
        // 0x805D3860: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805D3B08;
    }
    // 0x805D3860: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805D3864: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x805D3868: slti        $at, $v1, 0x45B1
    ctx->r1 = SIGNED(ctx->r3) < 0X45B1 ? 1 : 0;
    // 0x805D386C: bne         $at, $zero, L_805D38BC
    if (ctx->r1 != 0) {
        // 0x805D3870: addiu       $t6, $v1, -0x45CC
        ctx->r14 = ADD32(ctx->r3, -0X45CC);
            goto L_805D38BC;
    }
    // 0x805D3870: addiu       $t6, $v1, -0x45CC
    ctx->r14 = ADD32(ctx->r3, -0X45CC);
    // 0x805D3874: slti        $at, $v1, 0x45B3
    ctx->r1 = SIGNED(ctx->r3) < 0X45B3 ? 1 : 0;
    // 0x805D3878: bne         $at, $zero, L_805D389C
    if (ctx->r1 != 0) {
        // 0x805D387C: sltiu       $at, $t6, 0xA
        ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
            goto L_805D389C;
    }
    // 0x805D387C: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x805D3880: beq         $at, $zero, L_805D3AE8
    if (ctx->r1 == 0) {
        // 0x805D3884: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805D3AE8;
    }
    // 0x805D3884: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805D3888: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2560) << 16);
    // 0x805D388C: addu        $at, $at, $t6
    gpr jr_addend_805D3894 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805D3890: lw          $t6, 0x3F90($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(471, 0X2560));
    // 0x805D3894: jr          $t6
    // 0x805D3898: nop

    switch (jr_addend_805D3894 >> 2) {
        case 0: goto L_805D3A88; break;
        case 1: goto L_805D3AA0; break;
        case 2: goto L_805D3AB8; break;
        case 3: goto L_805D3AD0; break;
        case 4: goto L_805D3AE8; break;
        case 5: goto L_805D3AE8; break;
        case 6: goto L_805D3A40; break;
        case 7: goto L_805D3A28; break;
        case 8: goto L_805D3A58; break;
        case 9: goto L_805D3A70; break;
        default: switch_error(__func__, 0x805D3894, 0x805D3F90);
    }
    // 0x805D3898: nop

L_805D389C:
    // 0x805D389C: addiu       $at, $zero, 0x45B1
    ctx->r1 = ADD32(0, 0X45B1);
    // 0x805D38A0: beq         $v1, $at, L_805D3A00
    if (ctx->r3 == ctx->r1) {
        // 0x805D38A4: addiu       $t8, $zero, 0x45AE
        ctx->r24 = ADD32(0, 0X45AE);
            goto L_805D3A00;
    }
    // 0x805D38A4: addiu       $t8, $zero, 0x45AE
    ctx->r24 = ADD32(0, 0X45AE);
    // 0x805D38A8: addiu       $at, $zero, 0x45B2
    ctx->r1 = ADD32(0, 0X45B2);
    // 0x805D38AC: beq         $v1, $at, L_805D3A14
    if (ctx->r3 == ctx->r1) {
        // 0x805D38B0: addiu       $t9, $zero, 0x45AE
        ctx->r25 = ADD32(0, 0X45AE);
            goto L_805D3A14;
    }
    // 0x805D38B0: addiu       $t9, $zero, 0x45AE
    ctx->r25 = ADD32(0, 0X45AE);
    // 0x805D38B4: b           L_805D3AEC
    // 0x805D38B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D38B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D38BC:
    // 0x805D38BC: slti        $at, $v1, 0x45B0
    ctx->r1 = SIGNED(ctx->r3) < 0X45B0 ? 1 : 0;
    // 0x805D38C0: bne         $at, $zero, L_805D38DC
    if (ctx->r1 != 0) {
        // 0x805D38C4: addiu       $t7, $v1, -0x4569
        ctx->r15 = ADD32(ctx->r3, -0X4569);
            goto L_805D38DC;
    }
    // 0x805D38C4: addiu       $t7, $v1, -0x4569
    ctx->r15 = ADD32(ctx->r3, -0X4569);
    // 0x805D38C8: addiu       $at, $zero, 0x45B0
    ctx->r1 = ADD32(0, 0X45B0);
    // 0x805D38CC: beq         $v1, $at, L_805D39EC
    if (ctx->r3 == ctx->r1) {
        // 0x805D38D0: addiu       $t7, $zero, 0x45AE
        ctx->r15 = ADD32(0, 0X45AE);
            goto L_805D39EC;
    }
    // 0x805D38D0: addiu       $t7, $zero, 0x45AE
    ctx->r15 = ADD32(0, 0X45AE);
    // 0x805D38D4: b           L_805D3AEC
    // 0x805D38D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D38D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D38DC:
    // 0x805D38DC: slti        $at, $v1, 0x4571
    ctx->r1 = SIGNED(ctx->r3) < 0X4571 ? 1 : 0;
    // 0x805D38E0: bne         $at, $zero, L_805D38F8
    if (ctx->r1 != 0) {
        // 0x805D38E4: addiu       $at, $zero, 0x45AF
        ctx->r1 = ADD32(0, 0X45AF);
            goto L_805D38F8;
    }
    // 0x805D38E4: addiu       $at, $zero, 0x45AF
    ctx->r1 = ADD32(0, 0X45AF);
    // 0x805D38E8: beq         $v1, $at, L_805D39D8
    if (ctx->r3 == ctx->r1) {
        // 0x805D38EC: addiu       $t6, $zero, 0x45AE
        ctx->r14 = ADD32(0, 0X45AE);
            goto L_805D39D8;
    }
    // 0x805D38EC: addiu       $t6, $zero, 0x45AE
    ctx->r14 = ADD32(0, 0X45AE);
    // 0x805D38F0: b           L_805D3AEC
    // 0x805D38F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D38F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D38F8:
    // 0x805D38F8: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x805D38FC: beq         $at, $zero, L_805D3AE8
    if (ctx->r1 == 0) {
        // 0x805D3900: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_805D3AE8;
    }
    // 0x805D3900: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805D3904: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2588) << 16);
    // 0x805D3908: addu        $at, $at, $t7
    gpr jr_addend_805D3910 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805D390C: lw          $t7, 0x3FB8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(471, 0X2588));
    // 0x805D3910: jr          $t7
    // 0x805D3914: nop

    switch (jr_addend_805D3910 >> 2) {
        case 0: goto L_805D3918; break;
        case 1: goto L_805D3930; break;
        case 2: goto L_805D3948; break;
        case 3: goto L_805D3960; break;
        case 4: goto L_805D3978; break;
        case 5: goto L_805D3990; break;
        case 6: goto L_805D39A8; break;
        case 7: goto L_805D39C0; break;
        default: switch_error(__func__, 0x805D3910, 0x805D3FB8);
    }
    // 0x805D3914: nop

L_805D3918:
    // 0x805D3918: addiu       $t8, $zero, 0x4527
    ctx->r24 = ADD32(0, 0X4527);
    // 0x805D391C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x805D3920: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3924: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x805D3928: b           L_805D3AEC
    // 0x805D392C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D392C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3930:
    // 0x805D3930: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3934: addiu       $t9, $zero, 0x4527
    ctx->r25 = ADD32(0, 0X4527);
    // 0x805D3938: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x805D393C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3940: b           L_805D3AEC
    // 0x805D3944: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_805D3AEC;
    // 0x805D3944: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_805D3948:
    // 0x805D3948: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D394C: addiu       $t0, $zero, 0x4527
    ctx->r8 = ADD32(0, 0X4527);
    // 0x805D3950: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x805D3954: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3958: b           L_805D3AEC
    // 0x805D395C: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D395C: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3960:
    // 0x805D3960: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3964: addiu       $t1, $zero, 0x4527
    ctx->r9 = ADD32(0, 0X4527);
    // 0x805D3968: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x805D396C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3970: b           L_805D3AEC
    // 0x805D3974: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3974: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3978:
    // 0x805D3978: addiu       $t2, $zero, 0x4528
    ctx->r10 = ADD32(0, 0X4528);
    // 0x805D397C: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x805D3980: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3984: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x805D3988: b           L_805D3AEC
    // 0x805D398C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D398C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3990:
    // 0x805D3990: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3994: addiu       $t3, $zero, 0x4528
    ctx->r11 = ADD32(0, 0X4528);
    // 0x805D3998: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x805D399C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D39A0: b           L_805D3AEC
    // 0x805D39A4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_805D3AEC;
    // 0x805D39A4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_805D39A8:
    // 0x805D39A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D39AC: addiu       $t4, $zero, 0x4528
    ctx->r12 = ADD32(0, 0X4528);
    // 0x805D39B0: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x805D39B4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D39B8: b           L_805D3AEC
    // 0x805D39BC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D39BC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D39C0:
    // 0x805D39C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D39C4: addiu       $t5, $zero, 0x4528
    ctx->r13 = ADD32(0, 0X4528);
    // 0x805D39C8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x805D39CC: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D39D0: b           L_805D3AEC
    // 0x805D39D4: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D39D4: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D39D8:
    // 0x805D39D8: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x805D39DC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D39E0: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x805D39E4: b           L_805D3AEC
    // 0x805D39E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D39E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D39EC:
    // 0x805D39EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D39F0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x805D39F4: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D39F8: b           L_805D3AEC
    // 0x805D39FC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_805D3AEC;
    // 0x805D39FC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_805D3A00:
    // 0x805D3A00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3A04: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x805D3A08: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3A0C: b           L_805D3AEC
    // 0x805D3A10: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3A10: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3A14:
    // 0x805D3A14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3A18: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x805D3A1C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3A20: b           L_805D3AEC
    // 0x805D3A24: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3A24: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3A28:
    // 0x805D3A28: addiu       $t0, $zero, 0x45D1
    ctx->r8 = ADD32(0, 0X45D1);
    // 0x805D3A2C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x805D3A30: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3A34: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x805D3A38: b           L_805D3AEC
    // 0x805D3A3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D3A3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3A40:
    // 0x805D3A40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3A44: addiu       $t1, $zero, 0x45D1
    ctx->r9 = ADD32(0, 0X45D1);
    // 0x805D3A48: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x805D3A4C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3A50: b           L_805D3AEC
    // 0x805D3A54: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_805D3AEC;
    // 0x805D3A54: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_805D3A58:
    // 0x805D3A58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3A5C: addiu       $t2, $zero, 0x45D1
    ctx->r10 = ADD32(0, 0X45D1);
    // 0x805D3A60: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x805D3A64: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3A68: b           L_805D3AEC
    // 0x805D3A6C: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3A6C: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3A70:
    // 0x805D3A70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3A74: addiu       $t3, $zero, 0x45D1
    ctx->r11 = ADD32(0, 0X45D1);
    // 0x805D3A78: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x805D3A7C: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3A80: b           L_805D3AEC
    // 0x805D3A84: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3A84: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3A88:
    // 0x805D3A88: addiu       $t4, $zero, 0x44E2
    ctx->r12 = ADD32(0, 0X44E2);
    // 0x805D3A8C: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x805D3A90: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3A94: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x805D3A98: b           L_805D3AEC
    // 0x805D3A9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3AEC;
    // 0x805D3A9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3AA0:
    // 0x805D3AA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3AA4: addiu       $t5, $zero, 0x44E2
    ctx->r13 = ADD32(0, 0X44E2);
    // 0x805D3AA8: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x805D3AAC: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3AB0: b           L_805D3AEC
    // 0x805D3AB4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_805D3AEC;
    // 0x805D3AB4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_805D3AB8:
    // 0x805D3AB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3ABC: addiu       $t6, $zero, 0x44E2
    ctx->r14 = ADD32(0, 0X44E2);
    // 0x805D3AC0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x805D3AC4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x805D3AC8: b           L_805D3AEC
    // 0x805D3ACC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3ACC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3AD0:
    // 0x805D3AD0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3AD4: addiu       $t7, $zero, 0x44E2
    ctx->r15 = ADD32(0, 0X44E2);
    // 0x805D3AD8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x805D3ADC: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // 0x805D3AE0: b           L_805D3AEC
    // 0x805D3AE4: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_805D3AEC;
    // 0x805D3AE4: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_805D3AE8:
    // 0x805D3AE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3AEC:
    // 0x805D3AEC: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x805D3AF0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x805D3AF4: jal         0x805D3B18
    // 0x805D3AF8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    func_805D3B18(rdram, ctx);
        goto after_2;
    // 0x805D3AF8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_2:
    // 0x805D3AFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D3B00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805D3B04: sb          $v1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r3;
L_805D3B08:
    // 0x805D3B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3B10: jr          $ra
    // 0x805D3B14: nop

    return;
    // 0x805D3B14: nop

;}
RECOMP_FUNC void func_804347CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804347CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804347D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x804347D4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x804347D8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x804347DC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x804347E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x804347E4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804347E8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804347EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804347F0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x804347F4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x804347F8: addiu       $s1, $zero, 0x59
    ctx->r17 = ADD32(0, 0X59);
    // 0x804347FC: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80434800: addiu       $s3, $zero, 0xF0
    ctx->r19 = ADD32(0, 0XF0);
    // 0x80434804: addiu       $s0, $v0, 0x5CC
    ctx->r16 = ADD32(ctx->r2, 0X5CC);
L_80434808:
    // 0x80434808: jal         0x800653D8
    // 0x8043480C: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8043480C: nop

    after_0:
    // 0x80434810: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x80434814: mfhi        $t6
    ctx->r14 = hi;
    // 0x80434818: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8043481C: bne         $s2, $zero, L_80434828
    if (ctx->r18 != 0) {
        // 0x80434820: nop
    
            goto L_80434828;
    }
    // 0x80434820: nop

    // 0x80434824: break       7
    do_break(2151893028);
L_80434828:
    // 0x80434828: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8043482C: bne         $s2, $at, L_80434840
    if (ctx->r18 != ctx->r1) {
        // 0x80434830: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80434840;
    }
    // 0x80434830: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80434834: bne         $v0, $at, L_80434840
    if (ctx->r2 != ctx->r1) {
        // 0x80434838: nop
    
            goto L_80434840;
    }
    // 0x80434838: nop

    // 0x8043483C: break       6
    do_break(2151893052);
L_80434840:
    // 0x80434840: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80434844: jal         0x800653D8
    // 0x80434848: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80434848: nop

    after_1:
    // 0x8043484C: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x80434850: mfhi        $t7
    ctx->r15 = hi;
    // 0x80434854: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80434858: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8043485C: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x80434860: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80434864: bne         $s3, $zero, L_80434870
    if (ctx->r19 != 0) {
        // 0x80434868: nop
    
            goto L_80434870;
    }
    // 0x80434868: nop

    // 0x8043486C: break       7
    do_break(2151893100);
L_80434870:
    // 0x80434870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80434874: bne         $s3, $at, L_80434888
    if (ctx->r19 != ctx->r1) {
        // 0x80434878: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80434888;
    }
    // 0x80434878: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043487C: bne         $v0, $at, L_80434888
    if (ctx->r2 != ctx->r1) {
        // 0x80434880: nop
    
            goto L_80434888;
    }
    // 0x80434880: nop

    // 0x80434884: break       6
    do_break(2151893124);
L_80434888:
    // 0x80434888: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x8043488C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80434890: bgez        $s1, L_80434808
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80434894: swc1        $f10, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
            goto L_80434808;
    }
    // 0x80434894: swc1        $f10, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80434898: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8043489C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804348A0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804348A4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x804348A8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x804348AC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x804348B0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x804348B4: jr          $ra
    // 0x804348B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804348B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80564A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564A28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80564A2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80564A30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80564A34: jal         0x805640B8
    // 0x80564A38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805640B8(rdram, ctx);
        goto after_0;
    // 0x80564A38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80564A3C: jal         0x80564140
    // 0x80564A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80564140(rdram, ctx);
        goto after_1;
    // 0x80564A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80564A44: jal         0x8056417C
    // 0x80564A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8056417C(rdram, ctx);
        goto after_2;
    // 0x80564A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80564A4C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80564A50: lhu         $t8, 0x52C($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X52C);
    // 0x80564A54: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80564A58: beq         $t9, $zero, L_80564A70
    if (ctx->r25 == 0) {
        // 0x80564A5C: nop
    
            goto L_80564A70;
    }
    // 0x80564A5C: nop

    // 0x80564A60: jal         0x80564744
    // 0x80564A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80564744(rdram, ctx);
        goto after_3;
    // 0x80564A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80564A68: b           L_80564A7C
    // 0x80564A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80564A7C;
    // 0x80564A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80564A70:
    // 0x80564A70: jal         0x805648B8
    // 0x80564A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805648B8(rdram, ctx);
        goto after_4;
    // 0x80564A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80564A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80564A7C:
    // 0x80564A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80564A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80564A84: jr          $ra
    // 0x80564A88: nop

    return;
    // 0x80564A88: nop

;}
RECOMP_FUNC void func_800745B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800745B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800745B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800745BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800745C0: addiu       $a0, $a3, 0x40
    ctx->r4 = ADD32(ctx->r7, 0X40);
    // 0x800745C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800745C8: jal         0x80082210
    // 0x800745CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800745CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800745D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800745D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800745D8: jr          $ra
    // 0x800745DC: nop

    return;
    // 0x800745DC: nop

;}
RECOMP_FUNC void func_80026618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002661C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026620: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026624: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80026628: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8002662C: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x80026630: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80026634: jal         0x8006593C
    // 0x80026638: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80026638: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002663C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80026640: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026644: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80026648: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x8002664C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80026650: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026654: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80026658: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002665C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80026660: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026664: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80026668: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002666C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80026670: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80026674: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80026678: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002667C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80026680: nop

    // 0x80026684: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80026688: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002668C: nop

    // 0x80026690: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80026694: beql        $t0, $zero, L_800266E4
    if (ctx->r8 == 0) {
        // 0x80026698: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_800266E4;
    }
    goto skip_0;
    // 0x80026698: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x8002669C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800266A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800266A4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800266A8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800266AC: nop

    // 0x800266B0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800266B4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800266B8: nop

    // 0x800266BC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800266C0: bne         $t0, $zero, L_800266D8
    if (ctx->r8 != 0) {
        // 0x800266C4: nop
    
            goto L_800266D8;
    }
    // 0x800266C4: nop

    // 0x800266C8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800266CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800266D0: b           L_800266F0
    // 0x800266D4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800266F0;
    // 0x800266D4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800266D8:
    // 0x800266D8: b           L_800266F0
    // 0x800266DC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800266F0;
    // 0x800266DC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800266E0: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_800266E4:
    // 0x800266E4: nop

    // 0x800266E8: bltz        $t0, L_800266D8
    if (SIGNED(ctx->r8) < 0) {
        // 0x800266EC: nop
    
            goto L_800266D8;
    }
    // 0x800266EC: nop

L_800266F0:
    // 0x800266F0: lbu         $t2, 0x1F8($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1F8);
    // 0x800266F4: lw          $t5, 0x138($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X138);
    // 0x800266F8: lh          $t8, -0x7682($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7682);
    // 0x800266FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026700: sltu        $t3, $zero, $t2
    ctx->r11 = 0 < ctx->r10 ? 1 : 0;
    // 0x80026704: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80026708: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8002670C: slt         $t9, $zero, $t8
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80026710: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80026714: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80026718: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x8002671C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80026720: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80026724: lw          $t3, -0x3A68($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3A68);
    // 0x80026728: lui         $t4, 0x8002
    ctx->r12 = S32(0X8002 << 16);
    // 0x8002672C: addiu       $t4, $t4, 0x64B4
    ctx->r12 = ADD32(ctx->r12, 0X64B4);
    // 0x80026730: addu        $t5, $t3, $t0
    ctx->r13 = ADD32(ctx->r11, ctx->r8);
    // 0x80026734: sw          $t5, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r13;
    // 0x80026738: sw          $t4, 0x160($a1)
    MEM_W(0X160, ctx->r5) = ctx->r12;
    // 0x8002673C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026740: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026744: jr          $ra
    // 0x80026748: nop

    return;
    // 0x80026748: nop

;}
RECOMP_FUNC void func_8057DD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057DD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057DD3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057DD40: jal         0x80045A34
    // 0x8057DD44: addiu       $a1, $zero, 0x2D8
    ctx->r5 = ADD32(0, 0X2D8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8057DD44: addiu       $a1, $zero, 0x2D8
    ctx->r5 = ADD32(0, 0X2D8);
    after_0:
    // 0x8057DD48: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8057DD4C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8057DD50: bne         $v0, $zero, L_8057DD60
    if (ctx->r2 != 0) {
        // 0x8057DD54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057DD60;
    }
    // 0x8057DD54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057DD58: b           L_8057DD64
    // 0x8057DD5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8057DD64;
    // 0x8057DD5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8057DD60:
    // 0x8057DD60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8057DD64:
    // 0x8057DD64: jr          $ra
    // 0x8057DD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8057DD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80025908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002590C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025910: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80025914: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025918: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002591C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025920: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80025924: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80025928: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002592C: bc1fl       L_80025964
    if (!c1cs) {
        // 0x80025930: lbu         $t0, 0x1($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X1);
            goto L_80025964;
    }
    goto skip_0;
    // 0x80025930: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    skip_0:
    // 0x80025934: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025938: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x8002593C: lw          $t7, 0x9C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C);
    // 0x80025940: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80025944: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x80025948: sw          $v1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r3;
    // 0x8002594C: lw          $t8, 0xA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA0);
    // 0x80025950: addiu       $t9, $t9, 0x5898
    ctx->r25 = ADD32(ctx->r25, 0X5898);
    // 0x80025954: sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
    // 0x80025958: b           L_80025994
    // 0x8002595C: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
        goto L_80025994;
    // 0x8002595C: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80025960: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
L_80025964:
    // 0x80025964: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80025968: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8002596C: bne         $t0, $at, L_80025984
    if (ctx->r8 != ctx->r1) {
        // 0x80025970: lui         $t2, 0x8002
        ctx->r10 = S32(0X8002 << 16);
            goto L_80025984;
    }
    // 0x80025970: lui         $t2, 0x8002
    ctx->r10 = S32(0X8002 << 16);
    // 0x80025974: jal         0x80025854
    // 0x80025978: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
    func_80025854(rdram, ctx);
        goto after_0;
    // 0x80025978: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
    after_0:
    // 0x8002597C: b           L_80025998
    // 0x80025980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80025998;
    // 0x80025980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025984:
    // 0x80025984: addiu       $t2, $t2, 0x57EC
    ctx->r10 = ADD32(ctx->r10, 0X57EC);
    // 0x80025988: sw          $t1, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r9;
    // 0x8002598C: sb          $zero, 0x158($a1)
    MEM_B(0X158, ctx->r5) = 0;
    // 0x80025990: sw          $t2, 0x160($a1)
    MEM_W(0X160, ctx->r5) = ctx->r10;
L_80025994:
    // 0x80025994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025998:
    // 0x80025998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002599C: jr          $ra
    // 0x800259A0: nop

    return;
    // 0x800259A0: nop

;}
RECOMP_FUNC void func_804BED60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BED60: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x804BED64: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x804BED68: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x804BED6C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x804BED70: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x804BED74: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x804BED78: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x804BED7C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x804BED80: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x804BED84: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x804BED88: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x804BED8C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x804BED90: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804BED94: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804BED98: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804BED9C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804BEDA0: lui         $s4, 0x804C
    ctx->r20 = S32(RELOC_HI16(191, 0X3C80) << 16);
    // 0x804BEDA4: lui         $s5, 0x804C
    ctx->r21 = S32(RELOC_HI16(191, 0X3C8C) << 16);
    // 0x804BEDA8: lui         $s6, 0x804C
    ctx->r22 = S32(RELOC_HI16(191, 0X3D04) << 16);
    // 0x804BEDAC: lui         $s7, 0x804C
    ctx->r23 = S32(RELOC_HI16(191, 0X3CA4) << 16);
    // 0x804BEDB0: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x804BEDB4: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BEDB8: lwc1        $f24, 0x6C($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BEDBC: lwc1        $f26, 0x70($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BEDC0: lwc1        $f28, 0x74($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X74);
    // 0x804BEDC4: addiu       $s4, $s4, -0xA50
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(191, 0X3C80));
    // 0x804BEDC8: addiu       $s5, $s5, -0xA44
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(191, 0X3C8C));
    // 0x804BEDCC: addiu       $s6, $s6, -0x9CC
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(191, 0X3D04));
    // 0x804BEDD0: addiu       $s7, $s7, -0xA2C
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(191, 0X3CA4));
    // 0x804BEDD4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_804BEDD8:
    // 0x804BEDD8: jal         0x80047090
    // 0x804BEDDC: addiu       $a0, $zero, 0x412B
    ctx->r4 = ADD32(0, 0X412B);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804BEDDC: addiu       $a0, $zero, 0x412B
    ctx->r4 = ADD32(0, 0X412B);
    after_0:
    // 0x804BEDE0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804BEDE4: beq         $v0, $at, L_804BEEC4
    if (ctx->r2 == ctx->r1) {
        // 0x804BEDE8: andi        $s1, $v0, 0xFFFF
        ctx->r17 = ctx->r2 & 0XFFFF;
            goto L_804BEEC4;
    }
    // 0x804BEDE8: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x804BEDEC: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x804BEDF0: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x804BEDF4: lui         $at, 0x412B
    ctx->r1 = S32(0X412B << 16);
    // 0x804BEDF8: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x804BEDFC: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x804BEE00: lui         $a3, 0x804C
    ctx->r7 = S32(RELOC_HI16(191, 0X3C98) << 16);
    // 0x804BEE04: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x804BEE08: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x804BEE0C: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x804BEE10: or          $a0, $s1, $at
    ctx->r4 = ctx->r17 | ctx->r1;
    // 0x804BEE14: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x804BEE18: lw          $a3, -0xA38($a3)
    ctx->r7 = MEM_W(ctx->r7, (int16_t)RELOC_LO16(191, 0X3C98));
    // 0x804BEE1C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x804BEE20: jal         0x8004613C
    // 0x804BEE24: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804BEE24: nop

    after_1:
    // 0x804BEE28: beq         $v0, $zero, L_804BEEBC
    if (ctx->r2 == 0) {
        // 0x804BEE2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804BEEBC;
    }
    // 0x804BEE2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804BEE30: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x804BEE34: andi        $t8, $s1, 0x3FF
    ctx->r24 = ctx->r17 & 0X3FF;
    // 0x804BEE38: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x804BEE3C: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x804BEE40: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x804BEE44: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x804BEE48: lw          $t2, 0x138($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X138);
    // 0x804BEE4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804BEE50: jal         0x80047F9C
    // 0x804BEE54: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804BEE54: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    after_2:
    // 0x804BEE58: jal         0x804BBA18
    // 0x804BEE5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BBA18(rdram, ctx);
        goto after_3;
    // 0x804BEE5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BEE60: bne         $v0, $zero, L_804BEE70
    if (ctx->r2 != 0) {
        // 0x804BEE64: lui         $at, 0x804C
        ctx->r1 = S32(RELOC_HI16(191, 0X4210) << 16);
            goto L_804BEE70;
    }
    // 0x804BEE64: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4210) << 16);
    // 0x804BEE68: b           L_804BEEEC
    // 0x804BEE6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BEEEC;
    // 0x804BEE6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BEE70:
    // 0x804BEE70: lwc1        $f16, -0x4C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4210));
    // 0x804BEE74: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4214) << 16);
    // 0x804BEE78: lwc1        $f18, -0x4BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4214));
    // 0x804BEE7C: mul.s       $f20, $f24, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x804BEE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BEE84: mul.s       $f22, $f26, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x804BEE88: jal         0x8005FDC4
    // 0x804BEE8C: nop

    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x804BEE8C: nop

    after_4:
    // 0x804BEE90: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
    // 0x804BEE94: swc1        $f22, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f22.u32l;
    // 0x804BEE98: swc1        $f28, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f28.u32l;
    // 0x804BEE9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804BEEA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804BEEA4: jal         0x804BF004
    // 0x804BEEA8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_804BF004(rdram, ctx);
        goto after_5;
    // 0x804BEEA8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_5:
    // 0x804BEEAC: lh          $t3, 0x0($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X0);
    // 0x804BEEB0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x804BEEB4: b           L_804BEECC
    // 0x804BEEB8: sh          $t3, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r11;
        goto L_804BEECC;
    // 0x804BEEB8: sh          $t3, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r11;
L_804BEEBC:
    // 0x804BEEBC: b           L_804BEEEC
    // 0x804BEEC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BEEEC;
    // 0x804BEEC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BEEC4:
    // 0x804BEEC4: b           L_804BEEEC
    // 0x804BEEC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BEEEC;
    // 0x804BEEC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BEECC:
    // 0x804BEECC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x804BEED0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804BEED4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x804BEED8: addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    // 0x804BEEDC: addiu       $s2, $s2, 0x4C
    ctx->r18 = ADD32(ctx->r18, 0X4C);
    // 0x804BEEE0: bne         $s3, $at, L_804BEDD8
    if (ctx->r19 != ctx->r1) {
        // 0x804BEEE4: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_804BEDD8;
    }
    // 0x804BEEE4: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x804BEEE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BEEEC:
    // 0x804BEEEC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x804BEEF0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804BEEF4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804BEEF8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804BEEFC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804BEF00: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804BEF04: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x804BEF08: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x804BEF0C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x804BEF10: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x804BEF14: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x804BEF18: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x804BEF1C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x804BEF20: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x804BEF24: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x804BEF28: jr          $ra
    // 0x804BEF2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x804BEF2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80446A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446A5C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446A60: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80446A64: jr          $ra
    // 0x80446A68: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    return;
    // 0x80446A68: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_807AEA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AEA78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AEA7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AEA80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807AEA84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AEA88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x807AEA8C: jal         0x80047090
    // 0x807AEA90: addiu       $a0, $zero, 0x46EE
    ctx->r4 = ADD32(0, 0X46EE);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807AEA90: addiu       $a0, $zero, 0x46EE
    ctx->r4 = ADD32(0, 0X46EE);
    after_0:
    // 0x807AEA94: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807AEA98: bne         $v0, $at, L_807AEAA8
    if (ctx->r2 != ctx->r1) {
        // 0x807AEA9C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807AEAA8;
    }
    // 0x807AEA9C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807AEAA0: b           L_807AEB00
    // 0x807AEAA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AEB00;
    // 0x807AEAA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AEAA8:
    // 0x807AEAA8: lui         $at, 0x46EE
    ctx->r1 = S32(0X46EE << 16);
    // 0x807AEAAC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807AEAB0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x807AEAB4: ori         $a3, $a3, 0x7AE
    ctx->r7 = ctx->r7 | 0X7AE;
    // 0x807AEAB8: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x807AEABC: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x807AEAC0: jal         0x8004613C
    // 0x807AEAC4: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807AEAC4: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    after_1:
    // 0x807AEAC8: bne         $v0, $zero, L_807AEAD8
    if (ctx->r2 != 0) {
        // 0x807AEACC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_807AEAD8;
    }
    // 0x807AEACC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807AEAD0: b           L_807AEB00
    // 0x807AEAD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AEB00;
    // 0x807AEAD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AEAD8:
    // 0x807AEAD8: jal         0x80044194
    // 0x807AEADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x807AEADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AEAE0: jal         0x807AE9A0
    // 0x807AEAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AE9A0(rdram, ctx);
        goto after_3;
    // 0x807AEAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807AEAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AEAEC: jal         0x807AEA6C
    // 0x807AEAF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_807AEA6C(rdram, ctx);
        goto after_4;
    // 0x807AEAF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x807AEAF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x807AEAF8: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x807AEAFC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_807AEB00:
    // 0x807AEB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AEB04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AEB08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AEB0C: jr          $ra
    // 0x807AEB10: nop

    return;
    // 0x807AEB10: nop

    // 0x807AEB14: nop

    // 0x807AEB18: nop

    // 0x807AEB1C: nop

;}
RECOMP_FUNC void func_806CFD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFD94: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806CFD98: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x806CFD9C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806CFDA0: jr          $ra
    // 0x806CFDA4: sh          $t6, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r14;
    return;
    // 0x806CFDA4: sh          $t6, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void Fault_Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F884: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8006F888: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8006F88C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F890: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_8006F894:
    // 0x8006F894: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8006F898: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006F89C: bne         $t9, $sp, L_8006F894
    if (ctx->r25 != ctx->r29) {
        // 0x8006F8A0: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_8006F894;
    }
    // 0x8006F8A0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006F8A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F8A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006F8AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006F8B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006F8B4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006F8B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006F8BC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006F8C0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8006F8C4: addiu       $a0, $a0, -0x804
    ctx->r4 = ADD32(ctx->r4, -0X804);
    // 0x8006F8C8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8006F8CC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006F8D0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8006F8D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8006F8D8: jal         0x8008A510
    // 0x8006F8DC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    _Printf(rdram, ctx);
        goto after_0;
    // 0x8006F8DC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8006F8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F8E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006F8E8: jr          $ra
    // 0x8006F8EC: nop

    return;
    // 0x8006F8EC: nop

;}
RECOMP_FUNC void func_807429A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807429A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807429A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807429AC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807429B0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807429B4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807429B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807429BC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807429C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807429C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807429C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807429CC: jr          $ra
    // 0x807429D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807429D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80536A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80536A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536A60: jal         0x805367A4
    // 0x80536A64: nop

    func_805367A4(rdram, ctx);
        goto after_0;
    // 0x80536A64: nop

    after_0:
    // 0x80536A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80536A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536A70: jr          $ra
    // 0x80536A74: nop

    return;
    // 0x80536A74: nop

;}
RECOMP_FUNC void func_8004E57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E57C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E584: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004E588: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004E58C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8004E590: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004E594: jal         0x8004E4C4
    // 0x8004E598: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8004E4C4(rdram, ctx);
        goto after_0;
    // 0x8004E598: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x8004E59C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004E5A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004E5A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004E5A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004E5AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E5B0: jal         0x8004E4C4
    // 0x8004E5B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8004E4C4(rdram, ctx);
        goto after_1;
    // 0x8004E5B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8004E5B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E5BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E5C0: jr          $ra
    // 0x8004E5C4: nop

    return;
    // 0x8004E5C4: nop

;}
RECOMP_FUNC void func_804D8374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D837C: jal         0x804D88E4
    // 0x804D8380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804D88E4(rdram, ctx);
        goto after_0;
    // 0x804D8380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x804D8384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D8388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D838C: jr          $ra
    // 0x804D8390: nop

    return;
    // 0x804D8390: nop

;}
RECOMP_FUNC void func_8067A2B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A2B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8067A2B8: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8067A2BC: bne         $t6, $zero, L_8067A338
    if (ctx->r14 != 0) {
        // 0x8067A2C0: nop
    
            goto L_8067A338;
    }
    // 0x8067A2C0: nop

    // 0x8067A2C4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8067A2C8: lbu         $t8, 0x6($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X6);
    // 0x8067A2CC: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8067A2D0: bne         $t7, $zero, L_8067A338
    if (ctx->r15 != 0) {
        // 0x8067A2D4: andi        $t9, $t8, 0xF8
        ctx->r25 = ctx->r24 & 0XF8;
            goto L_8067A338;
    }
    // 0x8067A2D4: andi        $t9, $t8, 0xF8
    ctx->r25 = ctx->r24 & 0XF8;
    // 0x8067A2D8: bne         $t9, $at, L_8067A338
    if (ctx->r25 != ctx->r1) {
        // 0x8067A2DC: lbu         $v1, 0x7($sp)
        ctx->r3 = MEM_BU(ctx->r29, 0X7);
            goto L_8067A338;
    }
    // 0x8067A2DC: lbu         $v1, 0x7($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X7);
    // 0x8067A2E0: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x8067A2E4: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8067A2E8: bne         $at, $zero, L_8067A338
    if (ctx->r1 != 0) {
        // 0x8067A2EC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8067A338;
    }
    // 0x8067A2EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8067A2F0: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x8067A2F4: beq         $at, $zero, L_8067A338
    if (ctx->r1 == 0) {
        // 0x8067A2F8: nop
    
            goto L_8067A338;
    }
    // 0x8067A2F8: nop

    // 0x8067A2FC: lw          $t0, 0x28($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X28);
    // 0x8067A300: lui         $v1, 0x8068
    ctx->r3 = S32(RELOC_HI16(541, 0X2678) << 16);
    // 0x8067A304: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x8067A308: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8067A30C: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8067A310: lw          $v1, -0x3CD8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(541, 0X2678));
    // 0x8067A314: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8067A318: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X26A8) << 16);
    // 0x8067A31C: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x8067A320: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8067A324: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8067A328: lwc1        $f4, -0x3CA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X26A8));
    // 0x8067A32C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8067A330: sw          $t5, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r13;
    // 0x8067A334: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8067A338:
    // 0x8067A338: jr          $ra
    // 0x8067A33C: nop

    return;
    // 0x8067A33C: nop

;}
RECOMP_FUNC void func_805AE564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE564: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE568: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE56C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE570: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE574: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE578: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE57C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE580: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE584: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE588: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE58C: jr          $ra
    // 0x805AE590: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE590: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B233C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B233C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B2340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806B2344: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806B2348: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806B234C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B2350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B2354: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806B2358: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X1488) << 16);
    // 0x806B235C: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X14A4) << 16);
    // 0x806B2360: addiu       $a1, $a1, 0x2DF4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X14A4));
    // 0x806B2364: addiu       $a2, $a2, 0x2DD8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X1488));
    // 0x806B2368: jal         0x806B1A18
    // 0x806B236C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_806B1A18(rdram, ctx);
        goto after_0;
    // 0x806B236C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x806B2370: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806B2374: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X14C0) << 16);
    // 0x806B2378: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X1488) << 16);
    // 0x806B237C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x806B2380: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B2384: addiu       $a2, $a2, 0x2DD8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X1488));
    // 0x806B2388: addiu       $a1, $a1, 0x2E10
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X14C0));
    // 0x806B238C: jal         0x806B1A18
    // 0x806B2390: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_806B1A18(rdram, ctx);
        goto after_1;
    // 0x806B2390: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x806B2394: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x806B2398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B239C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B23A0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B23A4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B23A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B23AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B23B0: jr          $ra
    // 0x806B23B4: nop

    return;
    // 0x806B23B4: nop

;}
RECOMP_FUNC void func_80527250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527258: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052725C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80527260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80527264: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527268: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052726C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80527270: nop

    // 0x80527274: bc1fl       L_805272C8
    if (!c1cs) {
        // 0x80527278: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805272C8;
    }
    goto skip_0;
    // 0x80527278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x8052727C: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527280: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527284: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80527288: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8052728C: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527290: bne         $at, $zero, L_805272A8
    if (ctx->r1 != 0) {
        // 0x80527294: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_805272A8;
    }
    // 0x80527294: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80527298: jal         0x80527038
    // 0x8052729C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80527038(rdram, ctx);
        goto after_0;
    // 0x8052729C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x805272A0: b           L_805272D8
    // 0x805272A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805272D8;
    // 0x805272A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805272A8:
    // 0x805272A8: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x805272AC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x805272B0: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x805272B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805272B8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805272BC: b           L_805272D4
    // 0x805272C0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_805272D4;
    // 0x805272C0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x805272C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805272C8:
    // 0x805272C8: nop

    // 0x805272CC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x805272D0: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_805272D4:
    // 0x805272D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805272D8:
    // 0x805272D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805272DC: jr          $ra
    // 0x805272E0: nop

    return;
    // 0x805272E0: nop

;}
RECOMP_FUNC void func_8052FB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052FB1C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8052FB20: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(333, 0X1C68) << 16);
    // 0x8052FB24: addiu       $t6, $t6, -0x5D8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(333, 0X1C68));
    // 0x8052FB28: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8052FB2C: jr          $ra
    // 0x8052FB30: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8052FB30: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80532F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532F5C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80532F60: beql        $v0, $zero, L_80532F84
    if (ctx->r2 == 0) {
        // 0x80532F64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80532F84;
    }
    goto skip_0;
    // 0x80532F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80532F68: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x80532F6C: addiu       $at, $zero, 0x450E
    ctx->r1 = ADD32(0, 0X450E);
    // 0x80532F70: bnel        $t6, $at, L_80532F84
    if (ctx->r14 != ctx->r1) {
        // 0x80532F74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80532F84;
    }
    goto skip_1;
    // 0x80532F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80532F78: jal         0x80532DFC
    // 0x80532F7C: nop

    func_80532DFC(rdram, ctx);
        goto after_0;
    // 0x80532F7C: nop

    after_0:
    // 0x80532F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80532F84:
    // 0x80532F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532F88: jr          $ra
    // 0x80532F8C: nop

    return;
    // 0x80532F8C: nop

;}
RECOMP_FUNC void func_800360F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800360F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800360F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800360FC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80036104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036108: jal         0x800351BC
    // 0x8003610C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800351BC(rdram, ctx);
        goto after_0;
    // 0x8003610C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80036110: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80036114: bne         $v0, $zero, L_80036124
    if (ctx->r2 != 0) {
        // 0x80036118: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80036124;
    }
    // 0x80036118: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8003611C: b           L_80036198
    // 0x80036120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036198;
    // 0x80036120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036124:
    // 0x80036124: lbu         $t6, 0x1F8($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1F8);
    // 0x80036128: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003612C: bne         $t6, $zero, L_80036140
    if (ctx->r14 != 0) {
        // 0x80036130: nop
    
            goto L_80036140;
    }
    // 0x80036130: nop

    // 0x80036134: lw          $t7, 0x12EC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X12EC);
    // 0x80036138: beql        $t7, $zero, L_80036160
    if (ctx->r15 == 0) {
        // 0x8003613C: lw          $t8, 0x78($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X78);
            goto L_80036160;
    }
    goto skip_0;
    // 0x8003613C: lw          $t8, 0x78($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X78);
    skip_0:
L_80036140:
    // 0x80036140: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80036144: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80036148: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x8003614C: jalr        $t9
    // 0x80036150: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80036150: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80036154: b           L_80036198
    // 0x80036158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036198;
    // 0x80036158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003615C: lw          $t8, 0x78($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X78);
L_80036160:
    // 0x80036160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036164: beq         $t8, $zero, L_80036198
    if (ctx->r24 == 0) {
        // 0x80036168: nop
    
            goto L_80036198;
    }
    // 0x80036168: nop

    // 0x8003616C: lw          $t0, 0x14($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14);
    // 0x80036170: bne         $t0, $zero, L_80036188
    if (ctx->r8 != 0) {
        // 0x80036174: nop
    
            goto L_80036188;
    }
    // 0x80036174: nop

    // 0x80036178: jal         0x800360A0
    // 0x8003617C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800360A0(rdram, ctx);
        goto after_2;
    // 0x8003617C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80036180: b           L_80036198
    // 0x80036184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036198;
    // 0x80036184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036188:
    // 0x80036188: jal         0x80035FEC
    // 0x8003618C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80035FEC(rdram, ctx);
        goto after_3;
    // 0x8003618C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80036190: b           L_80036198
    // 0x80036194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036198;
    // 0x80036194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036198:
    // 0x80036198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003619C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800361A0: jr          $ra
    // 0x800361A4: nop

    return;
    // 0x800361A4: nop

;}
RECOMP_FUNC void func_8046ACB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046ACB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8046ACB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046ACBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046ACC0: jal         0x8004700C
    // 0x8046ACC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046ACC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046ACC8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8046ACCC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046ACD0: beq         $v0, $zero, L_8046ADB4
    if (ctx->r2 == 0) {
        // 0x8046ACD4: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_8046ADB4;
    }
    // 0x8046ACD4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8046ACD8: jal         0x8046B08C
    // 0x8046ACDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046B08C(rdram, ctx);
        goto after_1;
    // 0x8046ACDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046ACE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046ACE4: jal         0x80062684
    // 0x8046ACE8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_2;
    // 0x8046ACE8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x8046ACEC: jal         0x8046AA28
    // 0x8046ACF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046AA28(rdram, ctx);
        goto after_3;
    // 0x8046ACF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046ACF4: jal         0x8046AAB0
    // 0x8046ACF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046AAB0(rdram, ctx);
        goto after_4;
    // 0x8046ACF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8046ACFC: jal         0x80469FF4
    // 0x8046AD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469FF4(rdram, ctx);
        goto after_5;
    // 0x8046AD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8046AD04: jal         0x80469834
    // 0x8046AD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80469834(rdram, ctx);
        goto after_6;
    // 0x8046AD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8046AD0C: jal         0x8046A0DC
    // 0x8046AD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A0DC(rdram, ctx);
        goto after_7;
    // 0x8046AD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8046AD14: jal         0x8046AC6C
    // 0x8046AD18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046AC6C(rdram, ctx);
        goto after_8;
    // 0x8046AD18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8046AD1C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8046AD20: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8046AD24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8046AD28: jal         0x80469D08
    // 0x8046AD2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80469D08(rdram, ctx);
        goto after_9;
    // 0x8046AD2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_9:
    // 0x8046AD30: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8046AD34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046AD38: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046AD3C: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8046AD40: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8046AD44: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8046AD48: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8046AD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046AD50: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8046AD54: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8046AD58: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8046AD5C: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8046AD60: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8046AD64: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8046AD68: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046AD6C: jal         0x80469F00
    // 0x8046AD70: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    func_80469F00(rdram, ctx);
        goto after_10;
    // 0x8046AD70: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    after_10:
    // 0x8046AD74: beq         $v0, $zero, L_8046AD98
    if (ctx->r2 == 0) {
        // 0x8046AD78: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_8046AD98;
    }
    // 0x8046AD78: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8046AD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046AD80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046AD84: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8046AD88: jal         0x8046B2D8
    // 0x8046AD8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_11;
    // 0x8046AD8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x8046AD90: b           L_8046ADB8
    // 0x8046AD94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046ADB8;
    // 0x8046AD94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046AD98:
    // 0x8046AD98: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8046AD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046ADA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046ADA4: bne         $s0, $t8, L_8046ADB4
    if (ctx->r16 != ctx->r24) {
        // 0x8046ADA8: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8046ADB4;
    }
    // 0x8046ADA8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8046ADAC: jal         0x8046B2D8
    // 0x8046ADB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_12;
    // 0x8046ADB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
L_8046ADB4:
    // 0x8046ADB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046ADB8:
    // 0x8046ADB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046ADBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8046ADC0: jr          $ra
    // 0x8046ADC4: nop

    return;
    // 0x8046ADC4: nop

;}
RECOMP_FUNC void func_805AE114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE114: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE118: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE11C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE120: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE124: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE128: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE12C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE130: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE134: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE138: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE13C: jr          $ra
    // 0x805AE140: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE140: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8042E0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E0F8: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8042E0FC: addiu       $t7, $t6, -0x4089
    ctx->r15 = ADD32(ctx->r14, -0X4089);
    // 0x8042E100: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8042E104: beq         $at, $zero, L_8042E188
    if (ctx->r1 == 0) {
        // 0x8042E108: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8042E188;
    }
    // 0x8042E108: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8042E10C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B60) << 16);
    // 0x8042E110: addu        $at, $at, $t7
    gpr jr_addend_8042E118 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8042E114: lw          $t7, 0x1C40($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B60));
    // 0x8042E118: jr          $t7
    // 0x8042E11C: nop

    switch (jr_addend_8042E118 >> 2) {
        case 0: goto L_8042E120; break;
        case 1: goto L_8042E130; break;
        case 2: goto L_8042E140; break;
        case 3: goto L_8042E150; break;
        case 4: goto L_8042E160; break;
        case 5: goto L_8042E170; break;
        case 6: goto L_8042E180; break;
        default: switch_error(__func__, 0x8042E118, 0x80431C40);
    }
    // 0x8042E11C: nop

L_8042E120:
    // 0x8042E120: jal         0x8042EA74
    // 0x8042E124: nop

    func_8042EA74(rdram, ctx);
        goto after_0;
    // 0x8042E124: nop

    after_0:
    // 0x8042E128: b           L_8042E18C
    // 0x8042E12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042E18C;
    // 0x8042E12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E130:
    // 0x8042E130: jal         0x8042EF0C
    // 0x8042E134: nop

    func_8042EF0C(rdram, ctx);
        goto after_1;
    // 0x8042E134: nop

    after_1:
    // 0x8042E138: b           L_8042E18C
    // 0x8042E13C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042E18C;
    // 0x8042E13C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E140:
    // 0x8042E140: jal         0x8042F4BC
    // 0x8042E144: nop

    func_8042F4BC(rdram, ctx);
        goto after_2;
    // 0x8042E144: nop

    after_2:
    // 0x8042E148: b           L_8042E18C
    // 0x8042E14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042E18C;
    // 0x8042E14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E150:
    // 0x8042E150: jal         0x8043045C
    // 0x8042E154: nop

    func_8043045C(rdram, ctx);
        goto after_3;
    // 0x8042E154: nop

    after_3:
    // 0x8042E158: b           L_8042E18C
    // 0x8042E15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042E18C;
    // 0x8042E15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E160:
    // 0x8042E160: jal         0x80430A60
    // 0x8042E164: nop

    func_80430A60(rdram, ctx);
        goto after_4;
    // 0x8042E164: nop

    after_4:
    // 0x8042E168: b           L_8042E18C
    // 0x8042E16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042E18C;
    // 0x8042E16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E170:
    // 0x8042E170: jal         0x80431028
    // 0x8042E174: nop

    func_80431028(rdram, ctx);
        goto after_5;
    // 0x8042E174: nop

    after_5:
    // 0x8042E178: b           L_8042E18C
    // 0x8042E17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042E18C;
    // 0x8042E17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E180:
    // 0x8042E180: jal         0x80431228
    // 0x8042E184: nop

    func_80431228(rdram, ctx);
        goto after_6;
    // 0x8042E184: nop

    after_6:
L_8042E188:
    // 0x8042E188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E18C:
    // 0x8042E18C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E190: jr          $ra
    // 0x8042E194: nop

    return;
    // 0x8042E194: nop

;}
RECOMP_FUNC void func_80439E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439E7C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80439E80: lui         $t0, 0xB800
    ctx->r8 = S32(0XB800 << 16);
    // 0x80439E84: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80439E88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80439E8C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80439E90: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80439E94: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x80439E98: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80439E9C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80439EA0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80439EA4: jr          $ra
    // 0x80439EA8: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    return;
    // 0x80439EA8: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805A9168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A9168: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805A916C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A9170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A9174: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x805A9178: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805A917C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805A9180: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805A9184: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x805A9188: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A918C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A9190: jal         0x8004921C
    // 0x805A9194: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x805A9194: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    after_0:
    // 0x805A9198: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x805A919C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A91A0: jal         0x8004921C
    // 0x805A91A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805A91A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805A91A8: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x805A91AC: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x805A91B0: lbu         $t2, 0x145($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X145);
    // 0x805A91B4: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A91B8: lw          $t4, 0x168($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X168);
    // 0x805A91BC: lw          $a2, 0x16C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X16C);
    // 0x805A91C0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x805A91C4: lw          $t5, 0x80($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X80);
    // 0x805A91C8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x805A91CC: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x805A91D0: mflo        $t1
    ctx->r9 = lo;
    // 0x805A91D4: nop

    // 0x805A91D8: nop

    // 0x805A91DC: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805A91E0: mflo        $t3
    ctx->r11 = lo;
    // 0x805A91E4: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x805A91E8: jal         0x80064354
    // 0x805A91EC: nop

    func_80064354(rdram, ctx);
        goto after_2;
    // 0x805A91EC: nop

    after_2:
    // 0x805A91F0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x805A91F4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x805A91F8: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x805A91FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A9200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A9204: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805A9208: jr          $ra
    // 0x805A920C: nop

    return;
    // 0x805A920C: nop

;}
RECOMP_FUNC void func_8003B41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B41C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B424: jal         0x8004700C
    // 0x8003B428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003B428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B42C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8003B430: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B434: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003B438: beq         $v0, $zero, L_8003B4E8
    if (ctx->r2 == 0) {
        // 0x8003B43C: swc1        $f4, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
            goto L_8003B4E8;
    }
    // 0x8003B43C: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8003B440: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8003B444: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003B448: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003B44C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8003B450: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003B454: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003B458: nop

    // 0x8003B45C: bc1fl       L_8003B4B0
    if (!c1cs) {
        // 0x8003B460: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8003B4B0;
    }
    goto skip_0;
    // 0x8003B460: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8003B464: lui         $at, 0xC240
    ctx->r1 = S32(0XC240 << 16);
    // 0x8003B468: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B46C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8003B470: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B474: nop

    // 0x8003B478: bc1fl       L_8003B488
    if (!c1cs) {
        // 0x8003B47C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8003B488;
    }
    goto skip_1;
    // 0x8003B47C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x8003B480: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B484: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8003B488:
    // 0x8003B488: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003B48C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003B490: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8003B494: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B498: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003B49C: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003B4A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003B4A4: b           L_8003B4F4
    // 0x8003B4A8: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
        goto L_8003B4F4;
    // 0x8003B4A8: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8003B4AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8003B4B0:
    // 0x8003B4B0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003B4B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B4B8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8003B4BC: nop

    // 0x8003B4C0: bc1f        L_8003B4CC
    if (!c1cs) {
        // 0x8003B4C4: nop
    
            goto L_8003B4CC;
    }
    // 0x8003B4C4: nop

    // 0x8003B4C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8003B4CC:
    // 0x8003B4CC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003B4D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003B4D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003B4D8: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003B4DC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B4E0: b           L_8003B4F4
    // 0x8003B4E4: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
        goto L_8003B4F4;
    // 0x8003B4E4: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
L_8003B4E8:
    // 0x8003B4E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B4EC: nop

    // 0x8003B4F0: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
L_8003B4F4:
    // 0x8003B4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B4F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B4FC: jr          $ra
    // 0x8003B500: nop

    return;
    // 0x8003B500: nop

;}
RECOMP_FUNC void func_80673F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673F10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80673F14: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80673F18: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80673F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673F20: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80673F24: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80673F28: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80673F2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80673F30: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80673F34: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80673F38: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80673F3C: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(529, 0X1AA0) << 16);
    // 0x80673F40: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80673F44: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80673F48: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80673F4C: lw          $t2, 0x4A80($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(529, 0X1AA0));
    // 0x80673F50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80673F54: jal         0x80673CC8
    // 0x80673F58: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80673CC8(rdram, ctx);
        goto after_0;
    // 0x80673F58: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80673F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673F64: jr          $ra
    // 0x80673F68: nop

    return;
    // 0x80673F68: nop

;}
RECOMP_FUNC void func_80464FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464FE0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80464FE4: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80464FE8: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(125, 0X1C28) << 16);
    // 0x80464FEC: lw          $t6, 0x1250($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1250);
    // 0x80464FF0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80464FF4: addiu       $t8, $t8, 0x61F8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(125, 0X1C28));
    // 0x80464FF8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80464FFC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80465000: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80465004: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80465008: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8046500C: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80465010: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80465014: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80465018: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x8046501C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80465020: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80465024: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80465028: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8046502C: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x80465030: jr          $ra
    // 0x80465034: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x80465034: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_80710700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710700: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80710704: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80710708: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8071070C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80710710: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80710714: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80710718: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8071071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80710720: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80710724: andi        $a1, $t7, 0x10
    ctx->r5 = ctx->r15 & 0X10;
    // 0x80710728: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8071072C: jal         0x807106C8
    // 0x80710730: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    func_807106C8(rdram, ctx);
        goto after_0;
    // 0x80710730: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    after_0:
    // 0x80710734: lw          $t8, 0x1E0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1E0);
    // 0x80710738: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8071073C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80710740: slti        $at, $t9, 0x3C
    ctx->r1 = SIGNED(ctx->r25) < 0X3C ? 1 : 0;
    // 0x80710744: bne         $at, $zero, L_8071079C
    if (ctx->r1 != 0) {
        // 0x80710748: sw          $t9, 0x1E0($s1)
        MEM_W(0X1E0, ctx->r17) = ctx->r25;
            goto L_8071079C;
    }
    // 0x80710748: sw          $t9, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r25;
    // 0x8071074C: lw          $t1, -0x7470($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7470);
    // 0x80710750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80710754: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80710758: bnel        $t1, $at, L_80710794
    if (ctx->r9 != ctx->r1) {
        // 0x8071075C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80710794;
    }
    goto skip_0;
    // 0x8071075C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80710760: jal         0x8070F740
    // 0x80710764: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    func_8070F740(rdram, ctx);
        goto after_1;
    // 0x80710764: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    after_1:
    // 0x80710768: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x8071076C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80710770: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80710774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80710778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8071077C: jal         0x8070F668
    // 0x80710780: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8070F668(rdram, ctx);
        goto after_2;
    // 0x80710780: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_2:
    // 0x80710784: addiu       $a0, $zero, 0x206
    ctx->r4 = ADD32(0, 0X206);
    // 0x80710788: jal         0x80067818
    // 0x8071078C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8071078C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80710790: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80710794:
    // 0x80710794: jal         0x80710C50
    // 0x80710798: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80710C50(rdram, ctx);
        goto after_4;
    // 0x80710798: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_4:
L_8071079C:
    // 0x8071079C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807107A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807107A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807107A8: jr          $ra
    // 0x807107AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x807107AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80531B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531B34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80531B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80531B3C: jal         0x8004700C
    // 0x80531B40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80531B40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80531B44: beq         $v0, $zero, L_80531BB4
    if (ctx->r2 == 0) {
        // 0x80531B48: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80531BB4;
    }
    // 0x80531B48: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80531B4C: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x80531B50: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80531B54: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80531B58: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80531B5C: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x80531B60: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80531B64: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80531B68: lwc1        $f10, 0x268($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X268);
    // 0x80531B6C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80531B70: lwc1        $f4, 0x10($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80531B74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80531B78: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80531B7C: jal         0x80531A90
    // 0x80531B80: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_80531A90(rdram, ctx);
        goto after_1;
    // 0x80531B80: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80531B84: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80531B88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80531B8C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80531B90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80531B94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80531B98: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80531B9C: nop

    // 0x80531BA0: bc1f        L_80531BB4
    if (!c1cs) {
        // 0x80531BA4: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80531BB4;
    }
    // 0x80531BA4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80531BA8: sw          $t9, 0x1E0($t0)
    MEM_W(0X1E0, ctx->r8) = ctx->r25;
    // 0x80531BAC: jal         0x80531FB8
    // 0x80531BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80531FB8(rdram, ctx);
        goto after_2;
    // 0x80531BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80531BB4:
    // 0x80531BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80531BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80531BBC: jr          $ra
    // 0x80531BC0: nop

    return;
    // 0x80531BC0: nop

;}
RECOMP_FUNC void func_807C2F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2F00: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(904, 0X10) << 16);
    // 0x807C2F04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807C2F08: jr          $ra
    // 0x807C2F0C: addiu       $v0, $v0, 0x2F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(904, 0X10));
    return;
    // 0x807C2F0C: addiu       $v0, $v0, 0x2F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(904, 0X10));
;}
RECOMP_FUNC void func_8001C474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C474: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001C478: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001C47C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C484: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001C488: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001C48C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001C490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C494: jal         0x8006E154
    // 0x8001C498: addiu       $a1, $a1, -0x3BEC
    ctx->r5 = ADD32(ctx->r5, -0X3BEC);
    func_8006E154(rdram, ctx);
        goto after_0;
    // 0x8001C498: addiu       $a1, $a1, -0x3BEC
    ctx->r5 = ADD32(ctx->r5, -0X3BEC);
    after_0:
    // 0x8001C49C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001C4A0: jal         0x80045A34
    // 0x8001C4A4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8001C4A4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x8001C4A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001C4AC: lui         $t7, 0xEDCB
    ctx->r15 = S32(0XEDCB << 16);
    // 0x8001C4B0: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8001C4B4: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8001C4B8: ori         $t7, $t7, 0xA987
    ctx->r15 = ctx->r15 | 0XA987;
    // 0x8001C4BC: addiu       $t8, $t8, -0x1D20
    ctx->r24 = ADD32(ctx->r24, -0X1D20);
    // 0x8001C4C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C4C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001C4C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001C4CC: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x8001C4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C4D8: jr          $ra
    // 0x8001C4DC: nop

    return;
    // 0x8001C4DC: nop

;}
RECOMP_FUNC void func_804C8AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8AA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804C8AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C8AB0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804C8AB4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804C8AB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C8ABC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C8AC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C8AC4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C8AC8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804C8ACC: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x804C8AD0: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x804C8AD4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804C8AD8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804C8ADC: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804C8AE0: bc1f        L_804C8AF0
    if (!c1cs) {
        // 0x804C8AE4: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_804C8AF0;
    }
    // 0x804C8AE4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804C8AE8: b           L_804C8B10
    // 0x804C8AEC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
        goto L_804C8B10;
    // 0x804C8AEC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_804C8AF0:
    // 0x804C8AF0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804C8AF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C8AF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804C8AFC: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x804C8B00: nop

    // 0x804C8B04: bc1fl       L_804C8B14
    if (!c1cs) {
        // 0x804C8B08: c.eq.s      $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
            goto L_804C8B14;
    }
    goto skip_0;
    // 0x804C8B08: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    skip_0:
    // 0x804C8B0C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_804C8B10:
    // 0x804C8B10: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
L_804C8B14:
    // 0x804C8B14: nop

    // 0x804C8B18: bc1t        L_804C8C2C
    if (c1cs) {
        // 0x804C8B1C: nop
    
            goto L_804C8C2C;
    }
    // 0x804C8B1C: nop

    // 0x804C8B20: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x804C8B24: beq         $t9, $zero, L_804C8C2C
    if (ctx->r25 == 0) {
        // 0x804C8B28: nop
    
            goto L_804C8C2C;
    }
    // 0x804C8B28: nop

    // 0x804C8B2C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x804C8B30: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x804C8B34: jal         0x80066DE4
    // 0x804C8B38: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x804C8B38: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x804C8B3C: jal         0x80065954
    // 0x804C8B40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x804C8B40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x804C8B44: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X930) << 16);
    // 0x804C8B48: lwc1        $f12, -0x6D90($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X930));
    // 0x804C8B4C: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804C8B50: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804C8B54: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x804C8B58: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x804C8B5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x804C8B60: bc1fl       L_804C8B70
    if (!c1cs) {
        // 0x804C8B64: swc1        $f2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
            goto L_804C8B70;
    }
    goto skip_1;
    // 0x804C8B64: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    skip_1:
    // 0x804C8B68: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x804C8B6C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
L_804C8B70:
    // 0x804C8B70: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x804C8B74: jal         0x80049018
    // 0x804C8B78: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x804C8B78: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x804C8B7C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X934) << 16);
    // 0x804C8B80: lwc1        $f18, -0x6D8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X934));
    // 0x804C8B84: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804C8B88: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804C8B8C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804C8B90: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x804C8B94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C8B98: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804C8B9C: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x804C8BA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x804C8BA4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X908) << 16);
    // 0x804C8BA8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x804C8BAC: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x804C8BB0: lwc1        $f4, -0x6DB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X908));
    // 0x804C8BB4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804C8BB8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x804C8BBC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804C8BC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C8BC4: nop

    // 0x804C8BC8: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x804C8BCC: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x804C8BD0: nop

    // 0x804C8BD4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804C8BD8: bc1f        L_804C8C94
    if (!c1cs) {
        // 0x804C8BDC: add.s       $f20, $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
            goto L_804C8C94;
    }
    // 0x804C8BDC: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x804C8BE0: lwc1        $f10, 0x50($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X50);
    // 0x804C8BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C8BE8: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x804C8BEC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x804C8BF0: nop

    // 0x804C8BF4: bc1f        L_804C8C94
    if (!c1cs) {
        // 0x804C8BF8: nop
    
            goto L_804C8C94;
    }
    // 0x804C8BF8: nop

    // 0x804C8BFC: jal         0x8001D770
    // 0x804C8C00: nop

    func_8001D770(rdram, ctx);
        goto after_3;
    // 0x804C8C00: nop

    after_3:
    // 0x804C8C04: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x804C8C08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804C8C0C: lw          $a1, 0x34($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X34);
    // 0x804C8C10: jal         0x80067BF8
    // 0x804C8C14: lw          $a2, 0x38($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_4;
    // 0x804C8C14: lw          $a2, 0x38($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X38);
    after_4:
    // 0x804C8C18: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x804C8C1C: jal         0x80067818
    // 0x804C8C20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x804C8C20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x804C8C24: b           L_804C8C94
    // 0x804C8C28: nop

        goto L_804C8C94;
    // 0x804C8C28: nop

L_804C8C2C:
    // 0x804C8C2C: jal         0x80066DE4
    // 0x804C8C30: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x804C8C30: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_6:
    // 0x804C8C34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804C8C38: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x804C8C3C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(225, 0X938) << 16);
    // 0x804C8C40: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x804C8C44: nop

    // 0x804C8C48: bc1f        L_804C8C88
    if (!c1cs) {
        // 0x804C8C4C: nop
    
            goto L_804C8C88;
    }
    // 0x804C8C4C: nop

    // 0x804C8C50: jal         0x80066E88
    // 0x804C8C54: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x804C8C54: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x804C8C58: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x804C8C5C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804C8C60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804C8C64: nop

    // 0x804C8C68: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x804C8C6C: nop

    // 0x804C8C70: bc1f        L_804C8C80
    if (!c1cs) {
        // 0x804C8C74: nop
    
            goto L_804C8C80;
    }
    // 0x804C8C74: nop

    // 0x804C8C78: b           L_804C8C94
    // 0x804C8C7C: sub.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f12.fl;
        goto L_804C8C94;
    // 0x804C8C7C: sub.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f12.fl;
L_804C8C80:
    // 0x804C8C80: b           L_804C8C94
    // 0x804C8C84: sub.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f2.fl;
        goto L_804C8C94;
    // 0x804C8C84: sub.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f2.fl;
L_804C8C88:
    // 0x804C8C88: lwc1        $f8, -0x6D88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(225, 0X938));
    // 0x804C8C8C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x804C8C90: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
L_804C8C94:
    // 0x804C8C94: jal         0x800659EC
    // 0x804C8C98: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800659EC(rdram, ctx);
        goto after_8;
    // 0x804C8C98: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x804C8C9C: lui         $at, 0x42B2
    ctx->r1 = S32(0X42B2 << 16);
    // 0x804C8CA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804C8CA4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x804C8CA8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804C8CAC: nop

    // 0x804C8CB0: bc1f        L_804C8CC0
    if (!c1cs) {
        // 0x804C8CB4: nop
    
            goto L_804C8CC0;
    }
    // 0x804C8CB4: nop

    // 0x804C8CB8: b           L_804C8D00
    // 0x804C8CBC: swc1        $f2, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f2.u32l;
        goto L_804C8D00;
    // 0x804C8CBC: swc1        $f2, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f2.u32l;
L_804C8CC0:
    // 0x804C8CC0: jal         0x800659EC
    // 0x804C8CC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800659EC(rdram, ctx);
        goto after_9;
    // 0x804C8CC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x804C8CC8: lui         $at, 0xC2B2
    ctx->r1 = S32(0XC2B2 << 16);
    // 0x804C8CCC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804C8CD0: nop

    // 0x804C8CD4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x804C8CD8: nop

    // 0x804C8CDC: bc1f        L_804C8CEC
    if (!c1cs) {
        // 0x804C8CE0: nop
    
            goto L_804C8CEC;
    }
    // 0x804C8CE0: nop

    // 0x804C8CE4: b           L_804C8CF8
    // 0x804C8CE8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_804C8CF8;
    // 0x804C8CE8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_804C8CEC:
    // 0x804C8CEC: jal         0x800659EC
    // 0x804C8CF0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800659EC(rdram, ctx);
        goto after_10;
    // 0x804C8CF0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_10:
    // 0x804C8CF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804C8CF8:
    // 0x804C8CF8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x804C8CFC: swc1        $f2, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f2.u32l;
L_804C8D00:
    // 0x804C8D00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C8D04: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804C8D08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804C8D0C: jr          $ra
    // 0x804C8D10: nop

    return;
    // 0x804C8D10: nop

;}
RECOMP_FUNC void func_8066A5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A5F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066A5F8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8066A5FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8066A600: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8066A604: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8066A608: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8066A60C: jr          $ra
    // 0x8066A610: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8066A610: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80003998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003998: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000399C: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x800039A0: lw          $t6, 0x1F28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F28);
    // 0x800039A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800039A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800039AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800039B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800039B4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800039B8: sw          $t6, 0x1F2C($v0)
    MEM_W(0X1F2C, ctx->r2) = ctx->r14;
    // 0x800039BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800039C0: jal         0x80003698
    // 0x800039C4: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x800039C4: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    after_0:
    // 0x800039C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800039CC: addiu       $a0, $a0, 0x6D20
    ctx->r4 = ADD32(ctx->r4, 0X6D20);
    // 0x800039D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800039D4: jal         0x800036F0
    // 0x800039D8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800036F0(rdram, ctx);
        goto after_1;
    // 0x800039D8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800039DC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800039E0: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    // 0x800039E4: jal         0x80003698
    // 0x800039E8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80003698(rdram, ctx);
        goto after_2;
    // 0x800039E8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x800039EC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800039F0: addiu       $a0, $a0, 0x6E30
    ctx->r4 = ADD32(ctx->r4, 0X6E30);
    // 0x800039F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800039F8: jal         0x800036F0
    // 0x800039FC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_800036F0(rdram, ctx);
        goto after_3;
    // 0x800039FC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x80003A00: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003A04: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    // 0x80003A08: jal         0x80003698
    // 0x80003A0C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    func_80003698(rdram, ctx);
        goto after_4;
    // 0x80003A0C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x80003A10: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003A14: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x80003A18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003A1C: jal         0x800036F0
    // 0x80003A20: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800036F0(rdram, ctx);
        goto after_5;
    // 0x80003A20: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_5:
    // 0x80003A24: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003A28: jal         0x8000372C
    // 0x80003A2C: addiu       $a0, $a0, 0x6D1C
    ctx->r4 = ADD32(ctx->r4, 0X6D1C);
    func_8000372C(rdram, ctx);
        goto after_6;
    // 0x80003A2C: addiu       $a0, $a0, 0x6D1C
    ctx->r4 = ADD32(ctx->r4, 0X6D1C);
    after_6:
    // 0x80003A30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003A34: jal         0x8000372C
    // 0x80003A38: addiu       $a0, $a0, 0x6E2C
    ctx->r4 = ADD32(ctx->r4, 0X6E2C);
    func_8000372C(rdram, ctx);
        goto after_7;
    // 0x80003A38: addiu       $a0, $a0, 0x6E2C
    ctx->r4 = ADD32(ctx->r4, 0X6E2C);
    after_7:
    // 0x80003A3C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003A40: jal         0x8000372C
    // 0x80003A44: addiu       $a0, $a0, 0x6F3C
    ctx->r4 = ADD32(ctx->r4, 0X6F3C);
    func_8000372C(rdram, ctx);
        goto after_8;
    // 0x80003A44: addiu       $a0, $a0, 0x6F3C
    ctx->r4 = ADD32(ctx->r4, 0X6F3C);
    after_8:
    // 0x80003A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003A4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80003A54: jr          $ra
    // 0x80003A58: nop

    return;
    // 0x80003A58: nop

;}
RECOMP_FUNC void func_805A8F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A8F94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A8F98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A8F9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A8FA0: jal         0x80045A34
    // 0x805A8FA4: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A8FA4: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_0:
    // 0x805A8FA8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805A8FAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805A8FB0: bne         $v0, $zero, L_805A8FC0
    if (ctx->r2 != 0) {
        // 0x805A8FB4: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_805A8FC0;
    }
    // 0x805A8FB4: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x805A8FB8: b           L_805A9048
    // 0x805A8FBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A9048;
    // 0x805A8FBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A8FC0:
    // 0x805A8FC0: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(429, 0X254) << 16);
    // 0x805A8FC4: addiu       $t6, $t6, -0x70AC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(429, 0X254));
    // 0x805A8FC8: sw          $t6, 0x1F8($a3)
    MEM_W(0X1F8, ctx->r7) = ctx->r14;
    // 0x805A8FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A8FD0: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x805A8FD4: jal         0x80065728
    // 0x805A8FD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x805A8FD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x805A8FDC: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x805A8FE0: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x805A8FE4: jal         0x80064D1C
    // 0x805A8FE8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x805A8FE8: addiu       $a0, $zero, 0x300
    ctx->r4 = ADD32(0, 0X300);
    after_2:
    // 0x805A8FEC: bne         $v0, $zero, L_805A8FFC
    if (ctx->r2 != 0) {
        // 0x805A8FF0: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_805A8FFC;
    }
    // 0x805A8FF0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x805A8FF4: b           L_805A9048
    // 0x805A8FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A9048;
    // 0x805A8FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A8FFC:
    // 0x805A8FFC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x805A9000: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x805A9004: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x805A9008: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x805A900C: jal         0x80064D1C
    // 0x805A9010: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x805A9010: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_3:
    // 0x805A9014: bne         $v0, $zero, L_805A9024
    if (ctx->r2 != 0) {
        // 0x805A9018: sw          $v0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r2;
            goto L_805A9024;
    }
    // 0x805A9018: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x805A901C: b           L_805A9048
    // 0x805A9020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A9048;
    // 0x805A9020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A9024:
    // 0x805A9024: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A9028: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x805A902C: jal         0x80064D1C
    // 0x805A9030: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80064D1C(rdram, ctx);
        goto after_4;
    // 0x805A9030: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x805A9034: bne         $v0, $zero, L_805A9044
    if (ctx->r2 != 0) {
        // 0x805A9038: sw          $v0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r2;
            goto L_805A9044;
    }
    // 0x805A9038: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x805A903C: b           L_805A9048
    // 0x805A9040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A9048;
    // 0x805A9040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A9044:
    // 0x805A9044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A9048:
    // 0x805A9048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A904C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A9050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A9054: jr          $ra
    // 0x805A9058: nop

    return;
    // 0x805A9058: nop

;}
RECOMP_FUNC void func_806EC444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC444: lwc1        $f10, 0xE0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x806EC448: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806EC44C: lwc1        $f4, 0xEC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806EC450: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EC454: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x806EC458: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806EC45C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EC460: bc1f        L_806EC48C
    if (!c1cs) {
        // 0x806EC464: swc1        $f8, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
            goto L_806EC48C;
    }
    // 0x806EC464: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x806EC468: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806EC46C: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806EC470: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EC474: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x806EC478: nop

    // 0x806EC47C: bc1f        L_806EC4A8
    if (!c1cs) {
        // 0x806EC480: nop
    
            goto L_806EC4A8;
    }
    // 0x806EC480: nop

    // 0x806EC484: jr          $ra
    // 0x806EC488: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x806EC488: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_806EC48C:
    // 0x806EC48C: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806EC490: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EC494: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EC498: nop

    // 0x806EC49C: bc1f        L_806EC4A8
    if (!c1cs) {
        // 0x806EC4A0: nop
    
            goto L_806EC4A8;
    }
    // 0x806EC4A0: nop

    // 0x806EC4A4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_806EC4A8:
    // 0x806EC4A8: jr          $ra
    // 0x806EC4AC: nop

    return;
    // 0x806EC4AC: nop

;}
RECOMP_FUNC void func_8079B95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079B960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079B964: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8079B968: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8079B96C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8079B970: jal         0x80067BBC
    // 0x8079B974: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8079B974: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8079B978: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8079B97C: jal         0x80067818
    // 0x8079B980: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8079B980: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8079B984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079B988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079B98C: jr          $ra
    // 0x8079B990: nop

    return;
    // 0x8079B990: nop

;}
RECOMP_FUNC void func_805AE724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE724: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE728: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE72C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE730: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE734: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE738: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE73C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE740: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE744: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE748: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE74C: jr          $ra
    // 0x805AE750: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE750: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006988C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006988C: addiu       $sp, $sp, -0x438
    ctx->r29 = ADD32(ctx->r29, -0X438);
    // 0x80069890: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80069894: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069898: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006989C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800698A0: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x800698A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800698A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800698AC: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x800698B0: addiu       $s3, $s3, 0x6F58
    ctx->r19 = ADD32(ctx->r19, 0X6F58);
    // 0x800698B4: addiu       $s0, $s0, 0x6F1C
    ctx->r16 = ADD32(ctx->r16, 0X6F1C);
L_800698B8:
    // 0x800698B8: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x800698BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800698C0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800698C4: jal         0x800655F4
    // 0x800698C8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x800698C8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_0:
    // 0x800698CC: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x800698D0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800698D4: bne         $s0, $s3, L_800698B8
    if (ctx->r16 != ctx->r19) {
        // 0x800698D8: addu        $s1, $s1, $t6
        ctx->r17 = ADD32(ctx->r17, ctx->r14);
            goto L_800698B8;
    }
    // 0x800698D8: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x800698DC: jal         0x80069A80
    // 0x800698E0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_80069A80(rdram, ctx);
        goto after_1;
    // 0x800698E0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x800698E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800698E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800698EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800698F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800698F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800698F8: jr          $ra
    // 0x800698FC: addiu       $sp, $sp, 0x438
    ctx->r29 = ADD32(ctx->r29, 0X438);
    return;
    // 0x800698FC: addiu       $sp, $sp, 0x438
    ctx->r29 = ADD32(ctx->r29, 0X438);
;}
RECOMP_FUNC void func_80673CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673CD0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80673CD4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80673CD8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80673CDC: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(529, 0X1A64) << 16);
    // 0x80673CE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80673CE4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80673CE8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80673CEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80673CF0: lw          $t8, 0x4A44($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(529, 0X1A64));
    // 0x80673CF4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80673CF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80673CFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80673D00: jal         0x80048490
    // 0x80673D04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80673D04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80673D08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80673D0C: jal         0x80048378
    // 0x80673D10: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80673D10: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80673D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673D1C: jr          $ra
    // 0x80673D20: nop

    return;
    // 0x80673D20: nop

;}
RECOMP_FUNC void func_807BB0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB0A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB0AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB0B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807BB0B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807BB0B8: jal         0x807BA848
    // 0x807BB0BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_807BA848(rdram, ctx);
        goto after_0;
    // 0x807BB0BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x807BB0C0: jal         0x807BAB94
    // 0x807BB0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAB94(rdram, ctx);
        goto after_1;
    // 0x807BB0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BB0C8: jal         0x807BAC0C
    // 0x807BB0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAC0C(rdram, ctx);
        goto after_2;
    // 0x807BB0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807BB0D0: jal         0x807BAF34
    // 0x807BB0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAF34(rdram, ctx);
        goto after_3;
    // 0x807BB0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807BB0D8: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x807BB0DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807BB0E0: jal         0x807BA8F4
    // 0x807BB0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807BA8F4(rdram, ctx);
        goto after_4;
    // 0x807BB0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x807BB0E8: jal         0x807BAA7C
    // 0x807BB0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAA7C(rdram, ctx);
        goto after_5;
    // 0x807BB0EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807BB0F0: beq         $v0, $zero, L_807BB13C
    if (ctx->r2 == 0) {
        // 0x807BB0F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BB13C;
    }
    // 0x807BB0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB0F8: jal         0x807BAAFC
    // 0x807BB0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAAFC(rdram, ctx);
        goto after_6;
    // 0x807BB0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x807BB100: bnel        $v0, $zero, L_807BB118
    if (ctx->r2 != 0) {
        // 0x807BB104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BB118;
    }
    goto skip_0;
    // 0x807BB104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x807BB108: jal         0x807BAD68
    // 0x807BB10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAD68(rdram, ctx);
        goto after_7;
    // 0x807BB10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x807BB110: beq         $v0, $zero, L_807BB14C
    if (ctx->r2 == 0) {
        // 0x807BB114: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807BB14C;
    }
    // 0x807BB114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807BB118:
    // 0x807BB118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807BB120: jal         0x807BB7A4
    // 0x807BB124: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_807BB7A4(rdram, ctx);
        goto after_8;
    // 0x807BB124: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_8:
    // 0x807BB128: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807BB12C: nop

    // 0x807BB130: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x807BB134: b           L_807BB14C
    // 0x807BB138: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_807BB14C;
    // 0x807BB138: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_807BB13C:
    // 0x807BB13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB140: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807BB144: jal         0x807BB7A4
    // 0x807BB148: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_807BB7A4(rdram, ctx);
        goto after_9;
    // 0x807BB148: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_9:
L_807BB14C:
    // 0x807BB14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BB150: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807BB154: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807BB158: jr          $ra
    // 0x807BB15C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807BB15C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80737020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80737024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80737028: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8073702C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80737030: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80737034: jal         0x80736EA0
    // 0x80737038: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_80736EA0(rdram, ctx);
        goto after_0;
    // 0x80737038: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8073703C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80737040: jal         0x80736F20
    // 0x80737044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80736F20(rdram, ctx);
        goto after_1;
    // 0x80737044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80737048: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8073704C: jal         0x80736F20
    // 0x80737050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80736F20(rdram, ctx);
        goto after_2;
    // 0x80737050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80737054: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80737058: jal         0x80736FA0
    // 0x8073705C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80736FA0(rdram, ctx);
        goto after_3;
    // 0x8073705C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80737060: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80737064: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80737068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073706C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80737070: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80737074: beql        $v0, $zero, L_807370B4
    if (ctx->r2 == 0) {
        // 0x80737078: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_807370B4;
    }
    goto skip_0;
    // 0x80737078: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8073707C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80737080: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80737084: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80737088: beql        $v0, $zero, L_807370B4
    if (ctx->r2 == 0) {
        // 0x8073708C: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_807370B4;
    }
    goto skip_1;
    // 0x8073708C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80737090: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80737094: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80737098: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8073709C: beql        $v0, $zero, L_807370B4
    if (ctx->r2 == 0) {
        // 0x807370A0: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_807370B4;
    }
    goto skip_2;
    // 0x807370A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x807370A4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x807370A8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x807370AC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x807370B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
L_807370B4:
    // 0x807370B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807370B8: jr          $ra
    // 0x807370BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807370BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80457090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80457090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80457094: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80457098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045709C: addiu       $t6, $t6, -0x20C0
    ctx->r14 = ADD32(ctx->r14, -0X20C0);
    // 0x804570A0: lbu         $v0, 0x2A8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2A8);
    // 0x804570A4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x804570A8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x804570AC: beq         $v0, $zero, L_8045713C
    if (ctx->r2 == 0) {
        // 0x804570B0: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_8045713C;
    }
    // 0x804570B0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x804570B4: lw          $v0, -0x7200($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7200);
    // 0x804570B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804570BC: bnel        $v0, $at, L_804570D8
    if (ctx->r2 != ctx->r1) {
        // 0x804570C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_804570D8;
    }
    goto skip_0;
    // 0x804570C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x804570C4: jal         0x80456FA0
    // 0x804570C8: nop

    func_80456FA0(rdram, ctx);
        goto after_0;
    // 0x804570C8: nop

    after_0:
    // 0x804570CC: b           L_8045714C
    // 0x804570D0: nop

        goto L_8045714C;
    // 0x804570D0: nop

    // 0x804570D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_804570D8:
    // 0x804570D8: bnel        $v0, $at, L_804570F4
    if (ctx->r2 != ctx->r1) {
        // 0x804570DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804570F4;
    }
    goto skip_1;
    // 0x804570DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x804570E0: jal         0x80456F18
    // 0x804570E4: nop

    func_80456F18(rdram, ctx);
        goto after_1;
    // 0x804570E4: nop

    after_1:
    // 0x804570E8: b           L_8045714C
    // 0x804570EC: nop

        goto L_8045714C;
    // 0x804570EC: nop

    // 0x804570F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804570F4:
    // 0x804570F4: bne         $v0, $at, L_8045711C
    if (ctx->r2 != ctx->r1) {
        // 0x804570F8: nop
    
            goto L_8045711C;
    }
    // 0x804570F8: nop

    // 0x804570FC: jal         0x80444570
    // 0x80457100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80444570(rdram, ctx);
        goto after_2;
    // 0x80457100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80457104: jal         0x80456E84
    // 0x80457108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80456E84(rdram, ctx);
        goto after_3;
    // 0x80457108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8045710C: jal         0x80445BBC
    // 0x80457110: nop

    func_80445BBC(rdram, ctx);
        goto after_4;
    // 0x80457110: nop

    after_4:
    // 0x80457114: b           L_8045714C
    // 0x80457118: nop

        goto L_8045714C;
    // 0x80457118: nop

L_8045711C:
    // 0x8045711C: jal         0x8044453C
    // 0x80457120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8044453C(rdram, ctx);
        goto after_5;
    // 0x80457120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_5:
    // 0x80457124: jal         0x80456E04
    // 0x80457128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80456E04(rdram, ctx);
        goto after_6;
    // 0x80457128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x8045712C: jal         0x80445BBC
    // 0x80457130: nop

    func_80445BBC(rdram, ctx);
        goto after_7;
    // 0x80457130: nop

    after_7:
    // 0x80457134: b           L_8045714C
    // 0x80457138: nop

        goto L_8045714C;
    // 0x80457138: nop

L_8045713C:
    // 0x8045713C: jal         0x80457020
    // 0x80457140: nop

    func_80457020(rdram, ctx);
        goto after_8;
    // 0x80457140: nop

    after_8:
    // 0x80457144: jal         0x80445BBC
    // 0x80457148: nop

    func_80445BBC(rdram, ctx);
        goto after_9;
    // 0x80457148: nop

    after_9:
L_8045714C:
    // 0x8045714C: jal         0x80444504
    // 0x80457150: nop

    func_80444504(rdram, ctx);
        goto after_10;
    // 0x80457150: nop

    after_10:
    // 0x80457154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80457158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045715C: jr          $ra
    // 0x80457160: nop

    return;
    // 0x80457160: nop

;}
RECOMP_FUNC void func_806EE720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE720: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806EE724: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EE728: lwc1        $f14, 0x50($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EE72C: lbu         $v1, 0x30($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X30);
    // 0x806EE730: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D08) << 16);
    // 0x806EE734: beq         $v1, $zero, L_806EE76C
    if (ctx->r3 == 0) {
        // 0x806EE738: nop
    
            goto L_806EE76C;
    }
    // 0x806EE738: nop

    // 0x806EE73C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EE740: beq         $v1, $at, L_806EE780
    if (ctx->r3 == ctx->r1) {
        // 0x806EE744: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806EE780;
    }
    // 0x806EE744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806EE748: beq         $v1, $at, L_806EE7A0
    if (ctx->r3 == ctx->r1) {
        // 0x806EE74C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_806EE7A0;
    }
    // 0x806EE74C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806EE750: beq         $v1, $at, L_806EE7BC
    if (ctx->r3 == ctx->r1) {
        // 0x806EE754: lui         $at, 0x806F
        ctx->r1 = S32(RELOC_HI16(676, 0X4D00) << 16);
            goto L_806EE7BC;
    }
    // 0x806EE754: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D00) << 16);
    // 0x806EE758: lwc1        $f2, 0xC50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D00));
    // 0x806EE75C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D04) << 16);
    // 0x806EE760: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EE764: b           L_806EE7D4
    // 0x806EE768: lwc1        $f12, 0xC54($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D04));
        goto L_806EE7D4;
    // 0x806EE768: lwc1        $f12, 0xC54($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D04));
L_806EE76C:
    // 0x806EE76C: lwc1        $f2, 0xC58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D08));
    // 0x806EE770: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EE774: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D0C) << 16);
    // 0x806EE778: b           L_806EE7D4
    // 0x806EE77C: lwc1        $f12, 0xC5C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D0C));
        goto L_806EE7D4;
    // 0x806EE77C: lwc1        $f12, 0xC5C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D0C));
L_806EE780:
    // 0x806EE780: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x806EE784: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EE788: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D10) << 16);
    // 0x806EE78C: lwc1        $f2, 0xC60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D10));
    // 0x806EE790: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806EE794: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EE798: b           L_806EE7D8
    // 0x806EE79C: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
        goto L_806EE7D8;
    // 0x806EE79C: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
L_806EE7A0:
    // 0x806EE7A0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806EE7A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EE7A8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D14) << 16);
    // 0x806EE7AC: lwc1        $f2, 0xC64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D14));
    // 0x806EE7B0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D18) << 16);
    // 0x806EE7B4: b           L_806EE7D4
    // 0x806EE7B8: lwc1        $f12, 0xC68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D18));
        goto L_806EE7D4;
    // 0x806EE7B8: lwc1        $f12, 0xC68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D18));
L_806EE7BC:
    // 0x806EE7BC: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x806EE7C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EE7C4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D1C) << 16);
    // 0x806EE7C8: lwc1        $f2, 0xC6C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D1C));
    // 0x806EE7CC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D20) << 16);
    // 0x806EE7D0: lwc1        $f12, 0xC70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D20));
L_806EE7D4:
    // 0x806EE7D4: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
L_806EE7D8:
    // 0x806EE7D8: bnel        $t7, $zero, L_806EE814
    if (ctx->r15 != 0) {
        // 0x806EE7DC: neg.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
            goto L_806EE814;
    }
    goto skip_0;
    // 0x806EE7DC: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    skip_0:
    // 0x806EE7E0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x806EE7E4: nop

    // 0x806EE7E8: bc1fl       L_806EE804
    if (!c1cs) {
        // 0x806EE7EC: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EE804;
    }
    goto skip_1;
    // 0x806EE7EC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x806EE7F0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EE7F4: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x806EE7F8: b           L_806EE840
    // 0x806EE7FC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
        goto L_806EE840;
    // 0x806EE7FC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806EE800: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_806EE804:
    // 0x806EE804: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x806EE808: b           L_806EE840
    // 0x806EE80C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_806EE840;
    // 0x806EE80C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806EE810: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
L_806EE814:
    // 0x806EE814: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x806EE818: nop

    // 0x806EE81C: bc1fl       L_806EE838
    if (!c1cs) {
        // 0x806EE820: lwc1        $f6, 0x4($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EE838;
    }
    goto skip_2;
    // 0x806EE820: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x806EE824: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EE828: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x806EE82C: b           L_806EE840
    // 0x806EE830: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_806EE840;
    // 0x806EE830: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806EE834: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
L_806EE838:
    // 0x806EE838: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x806EE83C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_806EE840:
    // 0x806EE840: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EE844: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806EE848: nop

    // 0x806EE84C: bc1fl       L_806EE864
    if (!c1cs) {
        // 0x806EE850: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_806EE864;
    }
    goto skip_3;
    // 0x806EE850: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_3:
    // 0x806EE854: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806EE858: b           L_806EE87C
    // 0x806EE85C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
        goto L_806EE87C;
    // 0x806EE85C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EE860: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_806EE864:
    // 0x806EE864: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806EE868: nop

    // 0x806EE86C: bc1fl       L_806EE880
    if (!c1cs) {
        // 0x806EE870: add.s       $f14, $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
            goto L_806EE880;
    }
    goto skip_4;
    // 0x806EE870: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    skip_4:
    // 0x806EE874: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x806EE878: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_806EE87C:
    // 0x806EE87C: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
L_806EE880:
    // 0x806EE880: jr          $ra
    // 0x806EE884: swc1        $f14, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x806EE884: swc1        $f14, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80446088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446088: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044608C: addiu       $a1, $zero, 0x1EF0
    ctx->r5 = ADD32(0, 0X1EF0);
    // 0x80446090: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446094: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80446098: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044609C: sw          $zero, 0x6CA4($v1)
    MEM_W(0X6CA4, ctx->r3) = 0;
    // 0x804460A0: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x804460A4: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x804460A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804460AC: sw          $a2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r6;
    // 0x804460B0: sw          $a3, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r7;
    // 0x804460B4: sw          $a2, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r6;
    // 0x804460B8: sw          $a3, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->r7;
    // 0x804460BC: sw          $a1, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r5;
    // 0x804460C0: jr          $ra
    // 0x804460C4: swc1        $f4, 0x6AF0($v1)
    MEM_W(0X6AF0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x804460C4: swc1        $f4, 0x6AF0($v1)
    MEM_W(0X6AF0, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80437118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437118: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043711C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437120: lwc1        $f6, 0x50($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80437124: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80437128: jr          $ra
    // 0x8043712C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8043712C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_806B2204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2204: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B2208: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B220C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B2210: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B2214: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B2218: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B221C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B2220: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B2224: addiu       $t6, $zero, 0xDD4
    ctx->r14 = ADD32(0, 0XDD4);
    // 0x806B2228: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B222C: addiu       $a2, $zero, 0xA50
    ctx->r6 = ADD32(0, 0XA50);
    // 0x806B2230: addiu       $a3, $zero, 0xC30
    ctx->r7 = ADD32(0, 0XC30);
    // 0x806B2234: addiu       $a1, $zero, 0x99C
    ctx->r5 = ADD32(0, 0X99C);
    // 0x806B2238: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B223C: jal         0x806B195C
    // 0x806B2240: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B2240: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B2244: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B2248: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B224C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B2250: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B2254: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B2258: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B225C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B2260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B2264: jr          $ra
    // 0x806B2268: nop

    return;
    // 0x806B2268: nop

;}
RECOMP_FUNC void func_80429FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429FE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429FF0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80429FF4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80429FF8: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(47, 0X9F0) << 16);
    // 0x80429FFC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042A000: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042A004: lw          $t8, -0x5840($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(47, 0X9F0));
    // 0x8042A008: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042A00C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042A010: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042A014: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042A018: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042A01C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042A020: beql        $v1, $zero, L_8042A054
    if (ctx->r3 == 0) {
        // 0x8042A024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042A054;
    }
    goto skip_0;
    // 0x8042A024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042A028: jalr        $v1
    // 0x8042A02C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042A02C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042A030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042A034: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042A038: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042A03C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042A040: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042A044: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042A048: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042A04C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042A054:
    // 0x8042A054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042A058: jr          $ra
    // 0x8042A05C: nop

    return;
    // 0x8042A05C: nop

;}
RECOMP_FUNC void func_8046118C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046118C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80461190: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39F8) << 16);
    // 0x80461194: lwc1        $f4, 0x3F88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39F8));
    // 0x80461198: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8046119C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39FC) << 16);
    // 0x804611A0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804611A4: nop

    // 0x804611A8: bc1f        L_804611C8
    if (!c1cs) {
        // 0x804611AC: nop
    
            goto L_804611C8;
    }
    // 0x804611AC: nop

    // 0x804611B0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804611B4: bne         $t6, $zero, L_804611D4
    if (ctx->r14 != 0) {
        // 0x804611B8: nop
    
            goto L_804611D4;
    }
    // 0x804611B8: nop

    // 0x804611BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804611C0: jr          $ra
    // 0x804611C4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x804611C4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_804611C8:
    // 0x804611C8: lwc1        $f8, 0x3F8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39FC));
    // 0x804611CC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804611D0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
L_804611D4:
    // 0x804611D4: jr          $ra
    // 0x804611D8: nop

    return;
    // 0x804611D8: nop

;}
RECOMP_FUNC void func_807AE9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE9A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE9A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE9A8: jal         0x807AE95C
    // 0x807AE9AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807AE95C(rdram, ctx);
        goto after_0;
    // 0x807AE9AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AE9B0: bne         $v0, $zero, L_807AE9E4
    if (ctx->r2 != 0) {
        // 0x807AE9B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807AE9E4;
    }
    // 0x807AE9B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AE9B8: jal         0x800445A4
    // 0x807AE9BC: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x807AE9BC: nop

    after_1:
    // 0x807AE9C0: jal         0x8004700C
    // 0x807AE9C4: nop

    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x807AE9C4: nop

    after_2:
    // 0x807AE9C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807AE9CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AE9D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x807AE9D4: jal         0x8002F7AC
    // 0x807AE9D8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    func_8002F7AC(rdram, ctx);
        goto after_3;
    // 0x807AE9D8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_3:
    // 0x807AE9DC: b           L_807AEA18
    // 0x807AE9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807AEA18;
    // 0x807AE9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AE9E4:
    // 0x807AE9E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807AE9E8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AE9EC: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807AE9F0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AE9F4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807AE9F8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807AE9FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AEA00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AEA04: jal         0x807AEA24
    // 0x807AEA08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807AEA24(rdram, ctx);
        goto after_4;
    // 0x807AEA08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x807AEA0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AEA10: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x807AEA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AEA18:
    // 0x807AEA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AEA1C: jr          $ra
    // 0x807AEA20: nop

    return;
    // 0x807AEA20: nop

;}
RECOMP_FUNC void func_80665D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665D7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80665D80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80665D84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80665D88: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
    // 0x80665D8C: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80665D90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80665D94: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80665D98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80665D9C: lw          $a3, 0x2C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X2C);
    // 0x80665DA0: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x80665DA4: lw          $a1, 0x34($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X34);
    // 0x80665DA8: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80665DAC: lw          $t0, 0x14($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X14);
    // 0x80665DB0: andi        $t1, $a3, 0x3
    ctx->r9 = ctx->r7 & 0X3;
    // 0x80665DB4: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x80665DB8: beq         $t0, $zero, L_80665DC4
    if (ctx->r8 == 0) {
        // 0x80665DBC: addiu       $t6, $t0, -0x1
        ctx->r14 = ADD32(ctx->r8, -0X1);
            goto L_80665DC4;
    }
    // 0x80665DBC: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x80665DC0: sw          $t6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r14;
L_80665DC4:
    // 0x80665DC4: beq         $a3, $zero, L_80666190
    if (ctx->r7 == 0) {
        // 0x80665DC8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80666190;
    }
    // 0x80665DC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80665DCC: beq         $t1, $zero, L_80665EBC
    if (ctx->r9 == 0) {
        // 0x80665DD0: addu        $t0, $t1, $a3
        ctx->r8 = ADD32(ctx->r9, ctx->r7);
            goto L_80665EBC;
    }
    // 0x80665DD0: addu        $t0, $t1, $a3
    ctx->r8 = ADD32(ctx->r9, ctx->r7);
    // 0x80665DD4: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
    // 0x80665DD8: subu        $v0, $v0, $zero
    ctx->r2 = SUB32(ctx->r2, 0);
    // 0x80665DDC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80665DE0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665DE4: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665DE8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80665DEC: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80665DF0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80665DF4: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x80665DF8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80665DFC: nop

    // 0x80665E00: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665E04: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665E08: beql        $t0, $a3, L_80665E80
    if (ctx->r8 == ctx->r7) {
        // 0x80665E0C: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80665E80;
    }
    goto skip_0;
    // 0x80665E0C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_0:
    // 0x80665E10: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80665E14:
    // 0x80665E14: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80665E18: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665E1C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80665E20: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80665E24: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80665E28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80665E2C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80665E30: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80665E34: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665E38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80665E3C: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80665E40: nop

    // 0x80665E44: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665E48: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665E4C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80665E50: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665E54: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665E58: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80665E5C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80665E60: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x80665E64: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80665E68: nop

    // 0x80665E6C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665E70: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665E74: bnel        $t0, $a3, L_80665E14
    if (ctx->r8 != ctx->r7) {
        // 0x80665E78: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80665E14;
    }
    goto skip_1;
    // 0x80665E78: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_1:
    // 0x80665E7C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80665E80:
    // 0x80665E80: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80665E84: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665E88: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80665E8C: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80665E90: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80665E94: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80665E98: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80665E9C: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80665EA0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665EA4: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x80665EA8: nop

    // 0x80665EAC: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665EB0: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665EB4: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80665EB8: beq         $a3, $zero, L_80666190
    if (ctx->r7 == 0) {
        // 0x80665EBC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80666190;
    }
L_80665EBC:
    // 0x80665EBC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80665EC0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80665EC4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80665EC8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80665ECC: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665ED0: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80665ED4: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80665ED8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80665EDC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80665EE0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80665EE4: nop

    // 0x80665EE8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665EEC: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665EF0: beql        $a3, $zero, L_80666060
    if (ctx->r7 == 0) {
        // 0x80665EF4: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80666060;
    }
    goto skip_2;
    // 0x80665EF4: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_2:
    // 0x80665EF8: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80665EFC:
    // 0x80665EFC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80665F00: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665F04: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80665F08: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80665F0C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80665F10: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80665F14: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80665F18: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80665F1C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665F20: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x80665F24: nop

    // 0x80665F28: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665F2C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665F30: swc1        $f14, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f14.u32l;
    // 0x80665F34: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80665F38: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665F3C: lw          $t3, 0x3C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X3C);
    // 0x80665F40: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80665F44: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80665F48: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80665F4C: nop

    // 0x80665F50: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665F54: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665F58: swc1        $f16, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80665F5C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80665F60: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665F64: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x80665F68: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80665F6C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80665F70: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665F74: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x80665F78: nop

    // 0x80665F7C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665F80: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665F84: swc1        $f14, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f14.u32l;
    // 0x80665F88: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80665F8C: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665F90: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x80665F94: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80665F98: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80665F9C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80665FA0: nop

    // 0x80665FA4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665FA8: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665FAC: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80665FB0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665FB4: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665FB8: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80665FBC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80665FC0: lh          $t3, 0x2($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X2);
    // 0x80665FC4: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665FC8: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x80665FCC: nop

    // 0x80665FD0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665FD4: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665FD8: swc1        $f14, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f14.u32l;
    // 0x80665FDC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80665FE0: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665FE4: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80665FE8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80665FEC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80665FF0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80665FF4: nop

    // 0x80665FF8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665FFC: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80666000: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80666004: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80666008: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8066600C: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80666010: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80666014: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80666018: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8066601C: mtc1        $t4, $f14
    ctx->f14.u32l = ctx->r12;
    // 0x80666020: nop

    // 0x80666024: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80666028: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8066602C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80666030: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80666034: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80666038: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8066603C: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80666040: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80666044: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80666048: nop

    // 0x8066604C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80666050: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80666054: bnel        $a3, $zero, L_80665EFC
    if (ctx->r7 != 0) {
        // 0x80666058: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80665EFC;
    }
    goto skip_3;
    // 0x80666058: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_3:
    // 0x8066605C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80666060:
    // 0x80666060: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80666064: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80666068: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8066606C: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80666070: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80666074: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80666078: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x8066607C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80666080: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x80666084: nop

    // 0x80666088: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8066608C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80666090: swc1        $f14, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f14.u32l;
    // 0x80666094: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80666098: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8066609C: lw          $t3, 0x3C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X3C);
    // 0x806660A0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x806660A4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x806660A8: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x806660AC: nop

    // 0x806660B0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806660B4: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x806660B8: swc1        $f16, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f16.u32l;
    // 0x806660BC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x806660C0: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x806660C4: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x806660C8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x806660CC: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x806660D0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x806660D4: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x806660D8: nop

    // 0x806660DC: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806660E0: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806660E4: swc1        $f14, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f14.u32l;
    // 0x806660E8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x806660EC: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806660F0: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x806660F4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x806660F8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x806660FC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80666100: nop

    // 0x80666104: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80666108: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8066610C: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80666110: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80666114: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80666118: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x8066611C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80666120: lh          $t3, 0x2($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X2);
    // 0x80666124: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80666128: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x8066612C: nop

    // 0x80666130: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80666134: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80666138: swc1        $f14, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f14.u32l;
    // 0x8066613C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80666140: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80666144: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80666148: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8066614C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80666150: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80666154: nop

    // 0x80666158: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8066615C: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80666160: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80666164: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80666168: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8066616C: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80666170: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80666174: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80666178: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8066617C: mtc1        $t4, $f14
    ctx->f14.u32l = ctx->r12;
    // 0x80666180: nop

    // 0x80666184: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80666188: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8066618C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
L_80666190:
    // 0x80666190: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80666194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80666198: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8066619C: jal         0x80048F84
    // 0x806661A0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806661A0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x806661A4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806661A8: lui         $t9, 0x8066
    ctx->r25 = S32(RELOC_HI16(504, 0X2CC8) << 16);
    // 0x806661AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806661B0: lw          $t5, 0x1C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X1C);
    // 0x806661B4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x806661B8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x806661BC: lw          $t9, 0x7998($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(504, 0X2CC8));
    // 0x806661C0: jalr        $t9
    // 0x806661C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806661C4: nop

    after_1:
    // 0x806661C8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x806661CC: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x806661D0: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x806661D4: beq         $t8, $zero, L_80666210
    if (ctx->r24 == 0) {
        // 0x806661D8: nop
    
            goto L_80666210;
    }
    // 0x806661D8: nop

    // 0x806661DC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806661E0: addiu       $t4, $zero, 0x46
    ctx->r12 = ADD32(0, 0X46);
    // 0x806661E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806661E8: beq         $v0, $zero, L_806661FC
    if (ctx->r2 == 0) {
        // 0x806661EC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806661FC;
    }
    // 0x806661EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806661F0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x806661F4: b           L_80666210
    // 0x806661F8: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
        goto L_80666210;
    // 0x806661F8: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
L_806661FC:
    // 0x806661FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80666200: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x80666204: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80666208: jal         0x8066622C
    // 0x8066620C: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    func_8066622C(rdram, ctx);
        goto after_2;
    // 0x8066620C: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    after_2:
L_80666210:
    // 0x80666210: jal         0x80665110
    // 0x80666214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80665110(rdram, ctx);
        goto after_3;
    // 0x80666214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80666218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066621C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80666220: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80666224: jr          $ra
    // 0x80666228: nop

    return;
    // 0x80666228: nop

;}
RECOMP_FUNC void func_807606FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807606FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760700: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760704: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760708: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076070C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760710: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760714: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760718: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076071C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760720: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760724: jr          $ra
    // 0x80760728: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760728: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804BCEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BCEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BCEF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BCEFC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804BCF00: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804BCF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BCF08: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804BCF0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804BCF10: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804BCF14: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BCF18: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804BCF1C: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X400C) << 16);
    // 0x804BCF20: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804BCF24: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804BCF28: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804BCF2C: lw          $t2, -0x6C4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(191, 0X400C));
    // 0x804BCF30: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804BCF34: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804BCF38: jal         0x804BBC70
    // 0x804BCF3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804BBC70(rdram, ctx);
        goto after_0;
    // 0x804BCF3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BCF40: jal         0x804BBCCC
    // 0x804BCF44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804BBCCC(rdram, ctx);
        goto after_1;
    // 0x804BCF44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804BCF48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BCF4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BCF50: jr          $ra
    // 0x804BCF54: nop

    return;
    // 0x804BCF54: nop

;}
RECOMP_FUNC void func_8073A544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A544: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073A548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073A54C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073A550: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8073A554: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(739, 0X1F5C) << 16);
    // 0x8073A558: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8073A55C: addiu       $t6, $t6, -0x4674
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(739, 0X1F5C));
    // 0x8073A560: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8073A564: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073A568: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073A56C: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8073A570: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8073A574: jal         0x8073B8CC
    // 0x8073A578: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8073B8CC(rdram, ctx);
        goto after_0;
    // 0x8073A578: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8073A57C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8073A580: sw          $zero, 0x148($s0)
    MEM_W(0X148, ctx->r16) = 0;
    // 0x8073A584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073A588: jal         0x80045A34
    // 0x8073A58C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8073A58C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_1:
    // 0x8073A590: lui         $t9, 0x8074
    ctx->r25 = S32(RELOC_HI16(739, 0X7A0) << 16);
    // 0x8073A594: addiu       $t9, $t9, -0x5E30
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(739, 0X7A0));
    // 0x8073A598: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8073A59C: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x8073A5A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8073A5A4: jal         0x80064D1C
    // 0x8073A5A8: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x8073A5A8: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_2:
    // 0x8073A5AC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8073A5B0: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    // 0x8073A5B4: jal         0x80064D1C
    // 0x8073A5B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x8073A5B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    after_3:
    // 0x8073A5BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8073A5C0: jal         0x8073A024
    // 0x8073A5C4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    func_8073A024(rdram, ctx);
        goto after_4;
    // 0x8073A5C4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    after_4:
    // 0x8073A5C8: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x8073A5CC: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(739, 0X764) << 16);
    // 0x8073A5D0: addiu       $t1, $t1, -0x5E6C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(739, 0X764));
    // 0x8073A5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073A5D8: jal         0x8073A200
    // 0x8073A5DC: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    func_8073A200(rdram, ctx);
        goto after_5;
    // 0x8073A5DC: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    after_5:
    // 0x8073A5E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8073A5E4: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x8073A5E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073A5EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8073A5F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8073A5F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073A5F8: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8073A5FC: jr          $ra
    // 0x8073A600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8073A600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80024FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024FF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80024FFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80025000: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80025004: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x80025008: jal         0x80066E88
    // 0x8002500C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8002500C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80025010: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80025014: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80025018: lwc1        $f6, 0x100($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X100);
    // 0x8002501C: lwc1        $f16, 0x10C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x80025020: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80025024: nop

    // 0x80025028: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002502C: jal         0x80065954
    // 0x80025030: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80025030: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_1:
    // 0x80025034: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80025038: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002503C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025040: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80025044: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80025048: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002504C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80025050: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80025054: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80025058: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002505C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80025060: nop

    // 0x80025064: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80025068: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8002506C: nop

    // 0x80025070: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80025074: beql        $v0, $zero, L_800250C4
    if (ctx->r2 == 0) {
        // 0x80025078: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_800250C4;
    }
    goto skip_0;
    // 0x80025078: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8002507C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80025080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025084: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80025088: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8002508C: nop

    // 0x80025090: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80025094: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80025098: nop

    // 0x8002509C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800250A0: bne         $v0, $zero, L_800250B8
    if (ctx->r2 != 0) {
        // 0x800250A4: nop
    
            goto L_800250B8;
    }
    // 0x800250A4: nop

    // 0x800250A8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800250AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800250B0: b           L_800250D0
    // 0x800250B4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800250D0;
    // 0x800250B4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800250B8:
    // 0x800250B8: b           L_800250D0
    // 0x800250BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800250D0;
    // 0x800250BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800250C0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_800250C4:
    // 0x800250C4: nop

    // 0x800250C8: bltz        $v0, L_800250B8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800250CC: nop
    
            goto L_800250B8;
    }
    // 0x800250CC: nop

L_800250D0:
    // 0x800250D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800250D4: sltiu       $at, $v0, 0x28
    ctx->r1 = ctx->r2 < 0X28 ? 1 : 0;
    // 0x800250D8: beq         $at, $zero, L_800250E4
    if (ctx->r1 == 0) {
        // 0x800250DC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800250E4;
    }
    // 0x800250DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800250E0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
L_800250E4:
    // 0x800250E4: jal         0x80024D30
    // 0x800250E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80024D30(rdram, ctx);
        goto after_2;
    // 0x800250E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x800250EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800250F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800250F4: jr          $ra
    // 0x800250F8: nop

    return;
    // 0x800250F8: nop

;}
RECOMP_FUNC void func_806F1D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F1D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F1D8C: jal         0x80045A34
    // 0x806F1D90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F1D90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806F1D94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F1D98: bne         $v0, $zero, L_806F1DA8
    if (ctx->r2 != 0) {
        // 0x806F1D9C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806F1DA8;
    }
    // 0x806F1D9C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806F1DA0: b           L_806F1DB4
    // 0x806F1DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F1DB4;
    // 0x806F1DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F1DA8:
    // 0x806F1DA8: jal         0x806F1D70
    // 0x806F1DAC: nop

    func_806F1D70(rdram, ctx);
        goto after_1;
    // 0x806F1DAC: nop

    after_1:
    // 0x806F1DB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F1DB4:
    // 0x806F1DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F1DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F1DBC: jr          $ra
    // 0x806F1DC0: nop

    return;
    // 0x806F1DC0: nop

;}
RECOMP_FUNC void func_8068098C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8068098C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680994: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80680998: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(550, 0X219C) << 16);
    // 0x8068099C: addiu       $t8, $t8, 0x25AC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(550, 0X219C));
    // 0x806809A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806809A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806809A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806809AC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806809B0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806809B4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806809B8: beql        $v1, $zero, L_806809D8
    if (ctx->r3 == 0) {
        // 0x806809BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806809D8;
    }
    goto skip_0;
    // 0x806809BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806809C0: jalr        $v1
    // 0x806809C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806809C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806809C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806809CC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806809D0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x806809D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806809D8:
    // 0x806809D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806809DC: jr          $ra
    // 0x806809E0: nop

    return;
    // 0x806809E0: nop

;}
RECOMP_FUNC void func_80040C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040C14: jal         0x8002AFA0
    // 0x80040C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002AFA0(rdram, ctx);
        goto after_0;
    // 0x80040C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80040C1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80040C20: jal         0x80030A98
    // 0x80040C24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80030A98(rdram, ctx);
        goto after_1;
    // 0x80040C24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80040C28: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80040C2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040C30: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x80040C34: sw          $t6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r14;
    // 0x80040C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040C40: jr          $ra
    // 0x80040C44: nop

    return;
    // 0x80040C44: nop

;}
RECOMP_FUNC void func_8004106C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004106C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80041070: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80041074: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80041078: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8004107C: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80041080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041084: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80041088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004108C: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x80041090: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80041094: jalr        $t9
    // 0x80041098: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80041098: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8004109C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800410A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800410A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800410A8: jr          $ra
    // 0x800410AC: nop

    return;
    // 0x800410AC: nop

;}
RECOMP_FUNC void func_805DC618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC618: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805DC61C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DC620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DC624: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC628: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DC62C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805DC630: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805DC634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805DC638: jal         0x805DAE20
    // 0x805DC63C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_805DAE20(rdram, ctx);
        goto after_0;
    // 0x805DC63C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x805DC640: jal         0x805DBFBC
    // 0x805DC644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DBFBC(rdram, ctx);
        goto after_1;
    // 0x805DC644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805DC648: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x805DC64C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805DC650: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x805DC654: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x805DC658: bnel        $t7, $zero, L_805DC6D8
    if (ctx->r15 != 0) {
        // 0x805DC65C: lwc1        $f16, 0x60($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X60);
            goto L_805DC6D8;
    }
    goto skip_0;
    // 0x805DC65C: lwc1        $f16, 0x60($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X60);
    skip_0:
    // 0x805DC660: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x805DC664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DC668: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x805DC66C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x805DC670: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805DC674: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805DC678: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x805DC67C: nop

    // 0x805DC680: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x805DC684: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x805DC688: beql        $at, $zero, L_805DC740
    if (ctx->r1 == 0) {
        // 0x805DC68C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DC740;
    }
    goto skip_1;
    // 0x805DC68C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805DC690: lh          $v1, 0x58($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X58);
    // 0x805DC694: blez        $v1, L_805DC6BC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x805DC698: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_805DC6BC;
    }
    // 0x805DC698: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x805DC69C: sh          $t2, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r10;
    // 0x805DC6A0: lh          $t3, 0x58($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X58);
    // 0x805DC6A4: bne         $t3, $zero, L_805DC6BC
    if (ctx->r11 != 0) {
        // 0x805DC6A8: nop
    
            goto L_805DC6BC;
    }
    // 0x805DC6A8: nop

    // 0x805DC6AC: jal         0x800447C8
    // 0x805DC6B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x805DC6B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805DC6B4: b           L_805DC740
    // 0x805DC6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805DC740;
    // 0x805DC6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DC6BC:
    // 0x805DC6BC: jal         0x805DC0A8
    // 0x805DC6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DC0A8(rdram, ctx);
        goto after_3;
    // 0x805DC6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805DC6C4: jal         0x805DBB44
    // 0x805DC6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DBB44(rdram, ctx);
        goto after_4;
    // 0x805DC6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805DC6CC: b           L_805DC740
    // 0x805DC6D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805DC740;
    // 0x805DC6D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC6D4: lwc1        $f16, 0x60($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X60);
L_805DC6D8:
    // 0x805DC6D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805DC6DC: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
    // 0x805DC6E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805DC6E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805DC6E8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x805DC6EC: nop

    // 0x805DC6F0: addiu       $t7, $t6, 0x140
    ctx->r15 = ADD32(ctx->r14, 0X140);
    // 0x805DC6F4: slt         $at, $t7, $t4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x805DC6F8: beql        $at, $zero, L_805DC740
    if (ctx->r1 == 0) {
        // 0x805DC6FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DC740;
    }
    goto skip_2;
    // 0x805DC6FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805DC700: lh          $v1, 0x58($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X58);
    // 0x805DC704: blez        $v1, L_805DC72C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x805DC708: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_805DC72C;
    }
    // 0x805DC708: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x805DC70C: sh          $t9, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r25;
    // 0x805DC710: lh          $t0, 0x58($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X58);
    // 0x805DC714: bne         $t0, $zero, L_805DC72C
    if (ctx->r8 != 0) {
        // 0x805DC718: nop
    
            goto L_805DC72C;
    }
    // 0x805DC718: nop

    // 0x805DC71C: jal         0x800447C8
    // 0x805DC720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x805DC720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805DC724: b           L_805DC740
    // 0x805DC728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805DC740;
    // 0x805DC728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DC72C:
    // 0x805DC72C: jal         0x805DC010
    // 0x805DC730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DC010(rdram, ctx);
        goto after_6;
    // 0x805DC730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805DC734: jal         0x805DBB44
    // 0x805DC738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DBB44(rdram, ctx);
        goto after_7;
    // 0x805DC738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805DC73C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DC740:
    // 0x805DC740: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DC744: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805DC748: jr          $ra
    // 0x805DC74C: nop

    return;
    // 0x805DC74C: nop

;}
RECOMP_FUNC void func_80574514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80574518: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8057451C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80574520: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80574524: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80574528: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    // 0x8057452C: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x80574530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574534: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80574538: jal         0x80048F84
    // 0x8057453C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8057453C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80574540: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80574544: lhu         $t6, 0x4C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4C);
    // 0x80574548: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8057454C: bnel        $t7, $zero, L_80574580
    if (ctx->r15 != 0) {
        // 0x80574550: lw          $t9, 0x8($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X8);
            goto L_80574580;
    }
    goto skip_0;
    // 0x80574550: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x80574554: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80574558: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8057455C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80574560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80574564: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80574568: nop

    // 0x8057456C: bc1fl       L_80574580
    if (!c1cs) {
        // 0x80574570: lw          $t9, 0x8($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X8);
            goto L_80574580;
    }
    goto skip_1;
    // 0x80574570: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    skip_1:
    // 0x80574574: jal         0x8004A73C
    // 0x80574578: sh          $t8, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r24;
    func_8004A73C(rdram, ctx);
        goto after_1;
    // 0x80574578: sh          $t8, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r24;
    after_1:
    // 0x8057457C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
L_80574580:
    // 0x80574580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574584: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x80574588: beq         $t0, $zero, L_805745C0
    if (ctx->r8 == 0) {
        // 0x8057458C: nop
    
            goto L_805745C0;
    }
    // 0x8057458C: nop

    // 0x80574590: jal         0x80048F84
    // 0x80574594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80574594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80574598: lbu         $t1, 0x11($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X11);
    // 0x8057459C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x805745A0: beq         $at, $zero, L_805745C0
    if (ctx->r1 == 0) {
        // 0x805745A4: lui         $at, 0x8057
        ctx->r1 = S32(RELOC_HI16(381, 0XEE8) << 16);
            goto L_805745C0;
    }
    // 0x805745A4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEE8) << 16);
    // 0x805745A8: lwc1        $f10, 0x4D78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(381, 0XEE8));
    // 0x805745AC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x805745B0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805745B4: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x805745B8: jal         0x805743C8
    // 0x805745BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805743C8(rdram, ctx);
        goto after_3;
    // 0x805745BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_805745C0:
    // 0x805745C0: jal         0x8057440C
    // 0x805745C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8057440C(rdram, ctx);
        goto after_4;
    // 0x805745C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x805745C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805745CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805745D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805745D4: jr          $ra
    // 0x805745D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805745D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806D775C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D775C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D7760: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D7764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D7768: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D776C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D7770: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x806D7774: beq         $v1, $zero, L_806D7784
    if (ctx->r3 == 0) {
        // 0x806D7778: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_806D7784;
    }
    // 0x806D7778: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x806D777C: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x806D7780: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_806D7784:
    // 0x806D7784: bnel        $v1, $zero, L_806D7814
    if (ctx->r3 != 0) {
        // 0x806D7788: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D7814;
    }
    goto skip_0;
    // 0x806D7788: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x806D778C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x806D7790: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806D7794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7798: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x806D779C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806D77A0: jal         0x806D6D60
    // 0x806D77A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_806D6D60(rdram, ctx);
        goto after_0;
    // 0x806D77A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x806D77A8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806D77AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D77B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D77B4: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x806D77B8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B70) << 16);
    // 0x806D77BC: beq         $t7, $zero, L_806D77D4
    if (ctx->r15 == 0) {
        // 0x806D77C0: nop
    
            goto L_806D77D4;
    }
    // 0x806D77C0: nop

    // 0x806D77C4: jal         0x806D7A20
    // 0x806D77C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806D7A20(rdram, ctx);
        goto after_1;
    // 0x806D77C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x806D77CC: b           L_806D7814
    // 0x806D77D0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_806D7814;
    // 0x806D77D0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D77D4:
    // 0x806D77D4: lwc1        $f6, -0x78E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B70));
    // 0x806D77D8: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806D77DC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1AFC) << 16);
    // 0x806D77E0: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    // 0x806D77E4: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806D77E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806D77EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D77F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D77F4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x806D77F8: lwc1        $f8, -0x7954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1AFC));
    // 0x806D77FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D7800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D7804: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x806D7808: jal         0x806D7A20
    // 0x806D780C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    func_806D7A20(rdram, ctx);
        goto after_2;
    // 0x806D780C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    after_2:
    // 0x806D7810: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D7814:
    // 0x806D7814: jal         0x80048F84
    // 0x806D7818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x806D7818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x806D781C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D7820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D7824: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D7828: jr          $ra
    // 0x806D782C: nop

    return;
    // 0x806D782C: nop

;}
RECOMP_FUNC void func_8007C640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C648: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007C64C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007C650: jal         0x8007451C
    // 0x8007C654: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    func_8007451C(rdram, ctx);
        goto after_0;
    // 0x8007C654: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    after_0:
    // 0x8007C658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C65C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C660: jr          $ra
    // 0x8007C664: nop

    return;
    // 0x8007C664: nop

;}
RECOMP_FUNC void func_806E3D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E3D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E3D80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806E3D84: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806E3D88: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806E3D8C: addiu       $at, $zero, 0x46F5
    ctx->r1 = ADD32(0, 0X46F5);
    // 0x806E3D90: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E3D94: bne         $t6, $at, L_806E3DA8
    if (ctx->r14 != ctx->r1) {
        // 0x806E3D98: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_806E3DA8;
    }
    // 0x806E3D98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806E3D9C: sw          $t7, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r15;
    // 0x806E3DA0: jal         0x80044658
    // 0x806E3DA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80044658(rdram, ctx);
        goto after_0;
    // 0x806E3DA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_806E3DA8:
    // 0x806E3DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E3DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E3DB0: jr          $ra
    // 0x806E3DB4: nop

    return;
    // 0x806E3DB4: nop

;}
RECOMP_FUNC void func_8067A710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067A714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067A718: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067A71C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8067A720: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A724: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8067A728: lwc1        $f12, 0x3C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067A72C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067A730: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8067A734: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067A738: jal         0x80082050
    // 0x8067A73C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    truncf_recomp(rdram, ctx);
        goto after_0;
    // 0x8067A73C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8067A740: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067A744: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067A748: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A74C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A750: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067A754: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067A758: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8067A75C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8067A760: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A764: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067A768: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A76C: nop

    // 0x8067A770: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A774: beql        $t7, $zero, L_8067A7C4
    if (ctx->r15 == 0) {
        // 0x8067A778: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_8067A7C4;
    }
    goto skip_0;
    // 0x8067A778: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8067A77C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067A780: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A784: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067A788: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A78C: nop

    // 0x8067A790: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8067A794: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A798: nop

    // 0x8067A79C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A7A0: bne         $t7, $zero, L_8067A7B8
    if (ctx->r15 != 0) {
        // 0x8067A7A4: nop
    
            goto L_8067A7B8;
    }
    // 0x8067A7A4: nop

    // 0x8067A7A8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8067A7AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A7B0: b           L_8067A7D0
    // 0x8067A7B4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8067A7D0;
    // 0x8067A7B4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8067A7B8:
    // 0x8067A7B8: b           L_8067A7D0
    // 0x8067A7BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8067A7D0;
    // 0x8067A7BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8067A7C0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_8067A7C4:
    // 0x8067A7C4: nop

    // 0x8067A7C8: bltz        $t7, L_8067A7B8
    if (SIGNED(ctx->r15) < 0) {
        // 0x8067A7CC: nop
    
            goto L_8067A7B8;
    }
    // 0x8067A7CC: nop

L_8067A7D0:
    // 0x8067A7D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067A7D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067A7D8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8067A7DC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8067A7E0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8067A7E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8067A7E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A7EC: cvt.w.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8067A7F0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8067A7F4: nop

    // 0x8067A7F8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8067A7FC: beql        $t0, $zero, L_8067A84C
    if (ctx->r8 == 0) {
        // 0x8067A800: mfc1        $t0, $f16
        ctx->r8 = (int32_t)ctx->f16.u32l;
            goto L_8067A84C;
    }
    goto skip_1;
    // 0x8067A800: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x8067A804: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067A808: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067A80C: sub.s       $f16, $f2, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8067A810: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8067A814: nop

    // 0x8067A818: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8067A81C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8067A820: nop

    // 0x8067A824: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8067A828: bne         $t0, $zero, L_8067A840
    if (ctx->r8 != 0) {
        // 0x8067A82C: nop
    
            goto L_8067A840;
    }
    // 0x8067A82C: nop

    // 0x8067A830: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8067A834: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A838: b           L_8067A858
    // 0x8067A83C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8067A858;
    // 0x8067A83C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8067A840:
    // 0x8067A840: b           L_8067A858
    // 0x8067A844: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8067A858;
    // 0x8067A844: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8067A848: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
L_8067A84C:
    // 0x8067A84C: nop

    // 0x8067A850: bltz        $t0, L_8067A840
    if (SIGNED(ctx->r8) < 0) {
        // 0x8067A854: nop
    
            goto L_8067A840;
    }
    // 0x8067A854: nop

L_8067A858:
    // 0x8067A858: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x8067A85C: subu        $t2, $t8, $t1
    ctx->r10 = SUB32(ctx->r24, ctx->r9);
    // 0x8067A860: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8067A864: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8067A868: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067A86C: bgez        $t2, L_8067A880
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8067A870: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8067A880;
    }
    // 0x8067A870: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8067A874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A878: nop

    // 0x8067A87C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8067A880:
    // 0x8067A880: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8067A884: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8067A888: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067A88C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8067A890: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8067A894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A898: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8067A89C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067A8A0: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8067A8A4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8067A8A8: bc1f        L_8067A8BC
    if (!c1cs) {
        // 0x8067A8AC: swc1        $f18, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
            goto L_8067A8BC;
    }
    // 0x8067A8AC: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x8067A8B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067A8B4: nop

    // 0x8067A8B8: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_8067A8BC:
    // 0x8067A8BC: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x8067A8C0: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8067A8C4: bc1fl       L_8067A8E0
    if (!c1cs) {
        // 0x8067A8C8: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8067A8E0;
    }
    goto skip_2;
    // 0x8067A8C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_2:
    // 0x8067A8CC: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x8067A8D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8067A8D4: b           L_8067A8E8
    // 0x8067A8D8: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
        goto L_8067A8E8;
    // 0x8067A8D8: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
    // 0x8067A8DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8067A8E0:
    // 0x8067A8E0: nop

    // 0x8067A8E4: swc1        $f14, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f14.u32l;
L_8067A8E8:
    // 0x8067A8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067A8EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067A8F0: jr          $ra
    // 0x8067A8F4: nop

    return;
    // 0x8067A8F4: nop

;}
RECOMP_FUNC void func_8040B640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040B644: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040B648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040B64C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040B650: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8040B654: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040B658: jal         0x80048F84
    // 0x8040B65C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8040B65C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8040B660: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040B664: jal         0x80048F84
    // 0x8040B668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8040B668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8040B66C: jal         0x8040AE28
    // 0x8040B670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040AE28(rdram, ctx);
        goto after_2;
    // 0x8040B670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8040B674: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040B678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B67C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040B680: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8040B684: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8040B688: beq         $v1, $zero, L_8040B69C
    if (ctx->r3 == 0) {
        // 0x8040B68C: sw          $t6, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r14;
            goto L_8040B69C;
    }
    // 0x8040B68C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x8040B690: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040B694: jal         0x8040BA40
    // 0x8040B698: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040BA40(rdram, ctx);
        goto after_3;
    // 0x8040B698: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
L_8040B69C:
    // 0x8040B69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040B6A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040B6A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040B6A8: jr          $ra
    // 0x8040B6AC: nop

    return;
    // 0x8040B6AC: nop

;}
RECOMP_FUNC void func_80676CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80676CD0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80676CD4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80676CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80676CDC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80676CE0: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    // 0x80676CE4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80676CE8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80676CEC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X2608) << 16);
    // 0x80676CF0: bc1t        L_80676D7C
    if (c1cs) {
        // 0x80676CF4: swc1        $f6, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
            goto L_80676D7C;
    }
    // 0x80676CF4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80676CF8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80676CFC: lwc1        $f10, 0x7CC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X2608));
    // 0x80676D00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80676D04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80676D08: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80676D0C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80676D10: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80676D14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80676D18: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80676D1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80676D20: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80676D24: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80676D28: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80676D2C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80676D30: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80676D34: nop

    // 0x80676D38: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80676D3C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80676D40: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80676D44: nop

    // 0x80676D48: bc1f        L_80676D7C
    if (!c1cs) {
        // 0x80676D4C: nop
    
            goto L_80676D7C;
    }
    // 0x80676D4C: nop

    // 0x80676D50: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x80676D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80676D58: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x80676D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80676D60: jalr        $t9
    // 0x80676D64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80676D64: nop

    after_0:
    // 0x80676D68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80676D6C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80676D70: nop

    // 0x80676D74: swc1        $f14, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f14.u32l;
    // 0x80676D78: swc1        $f14, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f14.u32l;
L_80676D7C:
    // 0x80676D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80676D80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80676D84: jr          $ra
    // 0x80676D88: nop

    return;
    // 0x80676D88: nop

;}
RECOMP_FUNC void func_80574918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574918: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8057491C: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x80574920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80574924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80574928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057492C: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x80574930: jal         0x805747F4
    // 0x80574934: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    func_805747F4(rdram, ctx);
        goto after_0;
    // 0x80574934: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x80574938: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057493C: bne         $v0, $zero, L_80574960
    if (ctx->r2 != 0) {
        // 0x80574940: addiu       $v1, $v1, 0x7EA0
        ctx->r3 = ADD32(ctx->r3, 0X7EA0);
            goto L_80574960;
    }
    // 0x80574940: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80574944: lw          $a0, 0x9B0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X9B0);
    // 0x80574948: jal         0x805747F4
    // 0x8057494C: lh          $a1, 0x9A6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X9A6);
    func_805747F4(rdram, ctx);
        goto after_1;
    // 0x8057494C: lh          $a1, 0x9A6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X9A6);
    after_1:
    // 0x80574950: bnel        $v0, $zero, L_80574964
    if (ctx->r2 != 0) {
        // 0x80574954: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80574964;
    }
    goto skip_0;
    // 0x80574954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80574958: jal         0x805746D0
    // 0x8057495C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805746D0(rdram, ctx);
        goto after_2;
    // 0x8057495C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80574960:
    // 0x80574960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80574964:
    // 0x80574964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80574968: jr          $ra
    // 0x8057496C: nop

    return;
    // 0x8057496C: nop

;}
RECOMP_FUNC void func_805223C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805223C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805223C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805223CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805223D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805223D4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x805223D8: jal         0x80048060
    // 0x805223DC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    func_80048060(rdram, ctx);
        goto after_0;
    // 0x805223DC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x805223E0: jal         0x80044658
    // 0x805223E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x805223E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805223E8: jal         0x80066E88
    // 0x805223EC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x805223EC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_2:
    // 0x805223F0: jal         0x800653D8
    // 0x805223F4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x805223F4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x805223F8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x805223FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80522400: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80522404: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80522408: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8052240C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80522410: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X15E4) << 16);
    // 0x80522414: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80522418: lwc1        $f10, 0x3894($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X15E4));
    // 0x8052241C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80522420: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X15C4) << 16);
    // 0x80522424: addiu       $t1, $zero, 0x4034
    ctx->r9 = ADD32(0, 0X4034);
    // 0x80522428: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8052242C: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80522430: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80522434: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80522438: lwc1        $f18, 0x3874($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X15C4));
    // 0x8052243C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80522440: sh          $t1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r9;
    // 0x80522444: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80522448: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8052244C: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80522450: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80522454: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x80522458: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8052245C: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80522460: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80522464: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80522468: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8052246C: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80522470: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80522474: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80522478: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8052247C: lw          $t9, 0x54($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X54);
    // 0x80522480: jalr        $t9
    // 0x80522484: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80522484: nop

    after_4:
    // 0x80522488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052248C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80522490: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80522494: jr          $ra
    // 0x80522498: nop

    return;
    // 0x80522498: nop

;}
RECOMP_FUNC void eepmgr_SendRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D548: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007D54C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8007D550: lh          $t6, 0x48($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X48);
    // 0x8007D554: addiu       $a1, $a3, 0x48
    ctx->r5 = ADD32(ctx->r7, 0X48);
    // 0x8007D558: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8007D55C: beq         $t6, $zero, L_8007D56C
    if (ctx->r14 == 0) {
        // 0x8007D560: addiu       $a0, $a3, 0x14
        ctx->r4 = ADD32(ctx->r7, 0X14);
            goto L_8007D56C;
    }
    // 0x8007D560: addiu       $a0, $a3, 0x14
    ctx->r4 = ADD32(ctx->r7, 0X14);
L_8007D564:
    // 0x8007D564: b           L_8007D564
    pause_self(rdram);
    // 0x8007D568: nop

L_8007D56C:
    // 0x8007D56C: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8007D570: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007D578: jal         0x80082210
    // 0x8007D57C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D57C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    after_0:
    // 0x8007D580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D588: jr          $ra
    // 0x8007D58C: nop

    return;
    // 0x8007D58C: nop

;}
RECOMP_FUNC void func_80710A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80710A68: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80710A6C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80710A70: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80710A74: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80710A78: sh          $zero, -0x6DB8($at)
    MEM_H(-0X6DB8, ctx->r1) = 0;
    // 0x80710A7C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80710A80: sh          $zero, 0x13AA($v1)
    MEM_H(0X13AA, ctx->r3) = 0;
    // 0x80710A84: sh          $zero, 0x13AC($v1)
    MEM_H(0X13AC, ctx->r3) = 0;
    // 0x80710A88: sh          $zero, 0x13AE($v1)
    MEM_H(0X13AE, ctx->r3) = 0;
    // 0x80710A8C: sh          $zero, 0x13A8($v1)
    MEM_H(0X13A8, ctx->r3) = 0;
    // 0x80710A90: lbu         $t8, 0x13B2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X13B2);
    // 0x80710A94: lbu         $t5, 0x13B4($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X13B4);
    // 0x80710A98: ori         $t1, $t8, 0x4
    ctx->r9 = ctx->r24 | 0X4;
    // 0x80710A9C: ori         $t4, $t1, 0x10
    ctx->r12 = ctx->r9 | 0X10;
    // 0x80710AA0: sb          $t1, 0x13B2($a0)
    MEM_B(0X13B2, ctx->r4) = ctx->r9;
    // 0x80710AA4: ori         $t7, $t4, 0x20
    ctx->r15 = ctx->r12 | 0X20;
    // 0x80710AA8: sb          $t4, 0x13B2($a0)
    MEM_B(0X13B2, ctx->r4) = ctx->r12;
    // 0x80710AAC: ori         $t0, $t7, 0x2
    ctx->r8 = ctx->r15 | 0X2;
    // 0x80710AB0: sb          $t7, 0x13B2($a0)
    MEM_B(0X13B2, ctx->r4) = ctx->r15;
    // 0x80710AB4: ori         $t3, $t0, 0x1
    ctx->r11 = ctx->r8 | 0X1;
    // 0x80710AB8: sb          $t0, 0x13B2($a0)
    MEM_B(0X13B2, ctx->r4) = ctx->r8;
    // 0x80710ABC: sb          $t3, 0x13B2($a0)
    MEM_B(0X13B2, ctx->r4) = ctx->r11;
    // 0x80710AC0: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80710AC4: lbu         $t1, 0x13B5($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X13B5);
    // 0x80710AC8: andi        $t3, $t5, 0xFF1F
    ctx->r11 = ctx->r13 & 0XFF1F;
    // 0x80710ACC: lbu         $t7, 0x13B3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X13B3);
    // 0x80710AD0: andi        $t5, $t3, 0xE7
    ctx->r13 = ctx->r11 & 0XE7;
    // 0x80710AD4: sb          $t3, 0x13B4($a0)
    MEM_B(0X13B4, ctx->r4) = ctx->r11;
    // 0x80710AD8: sb          $t5, 0x13B4($a0)
    MEM_B(0X13B4, ctx->r4) = ctx->r13;
    // 0x80710ADC: andi        $t6, $t5, 0xF9
    ctx->r14 = ctx->r13 & 0XF9;
    // 0x80710AE0: andi        $t2, $t1, 0xFFF8
    ctx->r10 = ctx->r9 & 0XFFF8;
    // 0x80710AE4: sb          $t2, 0x13B5($a0)
    MEM_B(0X13B5, ctx->r4) = ctx->r10;
    // 0x80710AE8: sb          $t6, 0x13B4($a0)
    MEM_B(0X13B4, ctx->r4) = ctx->r14;
    // 0x80710AEC: andi        $t9, $t7, 0xFFCF
    ctx->r25 = ctx->r15 & 0XFFCF;
    // 0x80710AF0: lhu         $t7, 0x13B4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X13B4);
    // 0x80710AF4: sb          $t9, 0x13B3($a0)
    MEM_B(0X13B3, ctx->r4) = ctx->r25;
    // 0x80710AF8: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x80710AFC: andi        $t8, $t7, 0xFE7F
    ctx->r24 = ctx->r15 & 0XFE7F;
    // 0x80710B00: sh          $t8, 0x13B4($a0)
    MEM_H(0X13B4, ctx->r4) = ctx->r24;
    // 0x80710B04: lbu         $t9, 0x13B5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X13B5);
    // 0x80710B08: sb          $t4, 0x13B2($a0)
    MEM_B(0X13B2, ctx->r4) = ctx->r12;
    // 0x80710B0C: sb          $t0, 0x13B3($a0)
    MEM_B(0X13B3, ctx->r4) = ctx->r8;
    // 0x80710B10: andi        $t1, $t9, 0xFF9F
    ctx->r9 = ctx->r25 & 0XFF9F;
    // 0x80710B14: sb          $t1, 0x13B5($a0)
    MEM_B(0X13B5, ctx->r4) = ctx->r9;
    // 0x80710B18: andi        $t2, $t1, 0xE7
    ctx->r10 = ctx->r9 & 0XE7;
    // 0x80710B1C: jr          $ra
    // 0x80710B20: sb          $t2, 0x13B5($a0)
    MEM_B(0X13B5, ctx->r4) = ctx->r10;
    return;
    // 0x80710B20: sb          $t2, 0x13B5($a0)
    MEM_B(0X13B5, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_80518EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518EDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80518EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80518EE4: lbu         $t6, 0xF5($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF5);
    // 0x80518EE8: beql        $t6, $zero, L_80518F04
    if (ctx->r14 == 0) {
        // 0x80518EEC: sw          $zero, 0x14C($a0)
        MEM_W(0X14C, ctx->r4) = 0;
            goto L_80518F04;
    }
    goto skip_0;
    // 0x80518EEC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    skip_0:
    // 0x80518EF0: jal         0x80518D68
    // 0x80518EF4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_80518D68(rdram, ctx);
        goto after_0;
    // 0x80518EF4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_0:
    // 0x80518EF8: b           L_80518F08
    // 0x80518EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80518F08;
    // 0x80518EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80518F00: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
L_80518F04:
    // 0x80518F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80518F08:
    // 0x80518F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80518F0C: jr          $ra
    // 0x80518F10: nop

    return;
    // 0x80518F10: nop

;}
RECOMP_FUNC void func_800409F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800409F0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800409F4: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x800409F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800409FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040A00: lbu         $a3, 0xF5C($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0XF5C);
    // 0x80040A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040A08: lw          $v0, 0xF54($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XF54);
    // 0x80040A0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040A10: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80040A14:
    // 0x80040A14: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80040A18: beq         $t6, $zero, L_80040A24
    if (ctx->r14 == 0) {
        // 0x80040A1C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80040A24;
    }
    // 0x80040A1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80040A20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80040A24:
    // 0x80040A24: bne         $v1, $a0, L_80040A14
    if (ctx->r3 != ctx->r4) {
        // 0x80040A28: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_80040A14;
    }
    // 0x80040A28: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80040A2C: lw          $t7, 0xAB0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XAB0);
    // 0x80040A30: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80040A34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040A38: sw          $t7, -0x74AC($at)
    MEM_W(-0X74AC, ctx->r1) = ctx->r15;
    // 0x80040A3C: lw          $t8, 0xAB4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XAB4);
    // 0x80040A40: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80040A44: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80040A48: sw          $t8, -0x74A8($at)
    MEM_W(-0X74A8, ctx->r1) = ctx->r24;
    // 0x80040A4C: lw          $t9, 0xABC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XABC);
    // 0x80040A50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80040A54: sw          $t9, -0x74A4($at)
    MEM_W(-0X74A4, ctx->r1) = ctx->r25;
    // 0x80040A58: lw          $t0, 0xAB8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XAB8);
    // 0x80040A5C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80040A60: sw          $t0, -0x74A0($at)
    MEM_W(-0X74A0, ctx->r1) = ctx->r8;
    // 0x80040A64: lw          $t1, 0xAC0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XAC0);
    // 0x80040A68: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80040A6C: sw          $t1, -0x749C($at)
    MEM_W(-0X749C, ctx->r1) = ctx->r9;
    // 0x80040A70: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80040A74: jal         0x8006D774
    // 0x80040A78: sw          $a1, -0x7498($at)
    MEM_W(-0X7498, ctx->r1) = ctx->r5;
    func_8006D774(rdram, ctx);
        goto after_0;
    // 0x80040A78: sw          $a1, -0x7498($at)
    MEM_W(-0X7498, ctx->r1) = ctx->r5;
    after_0:
    // 0x80040A7C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80040A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80040A84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040A88: beq         $a3, $at, L_80040A9C
    if (ctx->r7 == ctx->r1) {
        // 0x80040A8C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80040A9C;
    }
    // 0x80040A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040A90: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80040A94: bne         $a3, $at, L_80040AAC
    if (ctx->r7 != ctx->r1) {
        // 0x80040A98: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80040AAC;
    }
    // 0x80040A98: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80040A9C:
    // 0x80040A9C: jal         0x8006E0FC
    // 0x80040AA0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x80040AA0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x80040AA4: b           L_80040ABC
    // 0x80040AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80040ABC;
    // 0x80040AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040AAC:
    // 0x80040AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040AB0: jal         0x8006E0FC
    // 0x80040AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x80040AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80040AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040ABC:
    // 0x80040ABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040AC0: jr          $ra
    // 0x80040AC4: nop

    return;
    // 0x80040AC4: nop

;}
RECOMP_FUNC void func_80736984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073698C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736990: jal         0x80047090
    // 0x80736994: addiu       $a0, $zero, 0x462D
    ctx->r4 = ADD32(0, 0X462D);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80736994: addiu       $a0, $zero, 0x462D
    ctx->r4 = ADD32(0, 0X462D);
    after_0:
    // 0x80736998: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073699C: lui         $at, 0x462D
    ctx->r1 = S32(0X462D << 16);
    // 0x807369A0: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807369A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807369A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807369AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807369B0: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x807369B4: jal         0x8004613C
    // 0x807369B8: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807369B8: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x807369BC: bne         $v0, $zero, L_807369CC
    if (ctx->r2 != 0) {
        // 0x807369C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807369CC;
    }
    // 0x807369C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807369C4: b           L_807369FC
    // 0x807369C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807369FC;
    // 0x807369C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807369CC:
    // 0x807369CC: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x807369D0: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x807369D4: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x807369D8: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x807369DC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x807369E0: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x807369E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807369E8: jal         0x80047F9C
    // 0x807369EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807369EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807369F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807369F4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x807369F8: sb          $t2, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r10;
L_807369FC:
    // 0x807369FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736A00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736A04: jr          $ra
    // 0x80736A08: nop

    return;
    // 0x80736A08: nop

;}
RECOMP_FUNC void func_807AF1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF1DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AF1E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF1E4: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x807AF1E8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807AF1EC: addiu       $at, $zero, 0x46F8
    ctx->r1 = ADD32(0, 0X46F8);
    // 0x807AF1F0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807AF1F4: bne         $t7, $at, L_807AF228
    if (ctx->r15 != ctx->r1) {
        // 0x807AF1F8: sw          $zero, 0x130($a0)
        MEM_W(0X130, ctx->r4) = 0;
            goto L_807AF228;
    }
    // 0x807AF1F8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AF1FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x807AF200: jal         0x80045A34
    // 0x807AF204: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807AF204: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AF208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AF20C: jal         0x807AF110
    // 0x807AF210: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_807AF110(rdram, ctx);
        goto after_1;
    // 0x807AF210: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_1:
    // 0x807AF214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AF218: jal         0x807AF508
    // 0x807AF21C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_807AF508(rdram, ctx);
        goto after_2;
    // 0x807AF21C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x807AF220: b           L_807AF24C
    // 0x807AF224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807AF24C;
    // 0x807AF224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AF228:
    // 0x807AF228: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x807AF22C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807AF230: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(865, 0X430) << 16);
    // 0x807AF234: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x807AF238: addiu       $t9, $t9, -0xAD0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(865, 0X430));
    // 0x807AF23C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AF240: jal         0x807AF508
    // 0x807AF244: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    func_807AF508(rdram, ctx);
        goto after_3;
    // 0x807AF244: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_3:
    // 0x807AF248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AF24C:
    // 0x807AF24C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807AF250: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AF254: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x807AF258: jr          $ra
    // 0x807AF25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807AF25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80473D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80473D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473D20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80473D24: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80473D28: jal         0x800447C8
    // 0x80473D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80473D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80473D30: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80473D34: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x80473D38: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80473D3C: lui         $a1, 0x8047
    ctx->r5 = S32(RELOC_HI16(161, 0X1394) << 16);
    // 0x80473D40: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80473D44: addiu       $a1, $a1, 0x4524
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(161, 0X1394));
    // 0x80473D48: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80473D4C: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x80473D50: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x80473D54: jalr        $t9
    // 0x80473D58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80473D58: nop

    after_1:
    // 0x80473D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80473D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80473D64: jr          $ra
    // 0x80473D68: nop

    return;
    // 0x80473D68: nop

;}
RECOMP_FUNC void gfxprint_setoffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F48C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8007F490: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8007F494: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x8007F498: jr          $ra
    // 0x8007F49C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    return;
    // 0x8007F49C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_805D3B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3B1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D3B20: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805D3B24: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805D3B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3B2C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805D3B30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x805D3B34: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x805D3B38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805D3B3C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x805D3B40: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805D3B44: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805D3B48: lui         $t2, 0x805D
    ctx->r10 = S32(RELOC_HI16(471, 0X2468) << 16);
    // 0x805D3B4C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D3B50: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805D3B54: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805D3B58: lw          $t2, 0x3E98($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(471, 0X2468));
    // 0x805D3B5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805D3B60: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805D3B64: jal         0x805D1CC0
    // 0x805D3B68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D1CC0(rdram, ctx);
        goto after_0;
    // 0x805D3B68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D3B6C: jal         0x805D1D7C
    // 0x805D3B70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805D1D7C(rdram, ctx);
        goto after_1;
    // 0x805D3B70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805D3B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3B7C: jr          $ra
    // 0x805D3B80: nop

    return;
    // 0x805D3B80: nop

    // 0x805D3B84: nop

    // 0x805D3B88: nop

    // 0x805D3B8C: nop

;}
RECOMP_FUNC void func_8058484C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058484C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584850: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584854: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584858: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058485C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584860: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584864: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584868: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058486C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584870: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584874: jr          $ra
    // 0x80584878: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584878: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806CD4FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD4FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD508: jal         0x806CCF00
    // 0x806CD50C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD50C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD510: jal         0x806CD470
    // 0x806CD514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD518: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806CD51C: blez        $v0, L_806CD52C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806CD520: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806CD52C;
    }
    // 0x806CD520: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806CD524: b           L_806CD5B8
    // 0x806CD528: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_806CD5B8;
    // 0x806CD528: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806CD52C:
    // 0x806CD52C: jal         0x800653D8
    // 0x806CD530: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x806CD530: nop

    after_2:
    // 0x806CD534: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x806CD538: beq         $t7, $zero, L_806CD548
    if (ctx->r15 == 0) {
        // 0x806CD53C: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_806CD548;
    }
    // 0x806CD53C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x806CD540: b           L_806CD5B8
    // 0x806CD544: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_806CD5B8;
    // 0x806CD544: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_806CD548:
    // 0x806CD548: jal         0x800653D8
    // 0x806CD54C: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x806CD54C: nop

    after_3:
    // 0x806CD550: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x806CD554: beq         $t9, $zero, L_806CD58C
    if (ctx->r25 == 0) {
        // 0x806CD558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CD58C;
    }
    // 0x806CD558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD55C: jal         0x800653D8
    // 0x806CD560: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x806CD560: nop

    after_4:
    // 0x806CD564: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x806CD568: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x806CD56C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x806CD570: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    // 0x806CD574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD57C: jal         0x806CED40
    // 0x806CD580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806CED40(rdram, ctx);
        goto after_5;
    // 0x806CD580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x806CD584: b           L_806CD5BC
    // 0x806CD588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806CD5BC;
    // 0x806CD588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CD58C:
    // 0x806CD58C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806CD590: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD594: jal         0x806CED40
    // 0x806CD598: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_806CED40(rdram, ctx);
        goto after_6;
    // 0x806CD598: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_6:
    // 0x806CD59C: jal         0x806CCCE4
    // 0x806CD5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_7;
    // 0x806CD5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806CD5A4: jal         0x806CC008
    // 0x806CD5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC008(rdram, ctx);
        goto after_8;
    // 0x806CD5A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806CD5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD5B0: jal         0x806CB8BC
    // 0x806CD5B4: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    func_806CB8BC(rdram, ctx);
        goto after_9;
    // 0x806CD5B4: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    after_9:
L_806CD5B8:
    // 0x806CD5B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CD5BC:
    // 0x806CD5BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD5C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD5C4: jr          $ra
    // 0x806CD5C8: nop

    return;
    // 0x806CD5C8: nop

;}
RECOMP_FUNC void func_8040FD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040FD24: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(26, 0X25F0) << 16);
    // 0x8040FD28: addiu       $t1, $t1, 0x1C70
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(26, 0X25F0));
    // 0x8040FD2C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8040FD30: addiu       $at, $t1, 0x7FFF
    ctx->r1 = ADD32(ctx->r9, 0X7FFF);
    // 0x8040FD34: sw          $a1, 0x39C9($at)
    MEM_W(0X39C9, ctx->r1) = ctx->r5;
    // 0x8040FD38: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x8040FD3C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8040FD40: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(26, 0XA5F0) << 16);
    // 0x8040FD44: divu        $zero, $a2, $t8
    lo = S32(U32(ctx->r6) / U32(ctx->r24)); hi = S32(U32(ctx->r6) % U32(ctx->r24));
    // 0x8040FD48: mflo        $v0
    ctx->r2 = lo;
    // 0x8040FD4C: addiu       $t2, $t2, -0x6390
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(26, 0XA5F0));
    // 0x8040FD50: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8040FD54: divu        $zero, $a3, $t9
    lo = S32(U32(ctx->r7) / U32(ctx->r25)); hi = S32(U32(ctx->r7) % U32(ctx->r25));
    // 0x8040FD58: mflo        $v1
    ctx->r3 = lo;
    // 0x8040FD5C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8040FD60: sw          $a2, 0x39D4($t2)
    MEM_W(0X39D4, ctx->r10) = ctx->r6;
    // 0x8040FD64: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040FD68: sw          $a3, 0x39D8($t2)
    MEM_W(0X39D8, ctx->r10) = ctx->r7;
    // 0x8040FD6C: sw          $v0, 0x39E4($t2)
    MEM_W(0X39E4, ctx->r10) = ctx->r2;
    // 0x8040FD70: sw          $v1, 0x39E8($t2)
    MEM_W(0X39E8, ctx->r10) = ctx->r3;
    // 0x8040FD74: sw          $t7, 0x39E0($t2)
    MEM_W(0X39E0, ctx->r10) = ctx->r15;
    // 0x8040FD78: sw          $t6, 0x39DC($t2)
    MEM_W(0X39DC, ctx->r10) = ctx->r14;
    // 0x8040FD7C: sw          $zero, 0x39D1($at)
    MEM_W(0X39D1, ctx->r1) = 0;
    // 0x8040FD80: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8040FD84: andi        $t0, $t6, 0xFFFF
    ctx->r8 = ctx->r14 & 0XFFFF;
    // 0x8040FD88: bne         $t8, $zero, L_8040FD94
    if (ctx->r24 != 0) {
        // 0x8040FD8C: nop
    
            goto L_8040FD94;
    }
    // 0x8040FD8C: nop

    // 0x8040FD90: break       7
    do_break(2151742864);
L_8040FD94:
    // 0x8040FD94: mflo        $t3
    ctx->r11 = lo;
    // 0x8040FD98: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8040FD9C: sw          $t4, 0x39ED($at)
    MEM_W(0X39ED, ctx->r1) = ctx->r12;
    // 0x8040FDA0: lw          $t5, 0x39D0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X39D0);
    // 0x8040FDA4: bne         $t9, $zero, L_8040FDB0
    if (ctx->r25 != 0) {
        // 0x8040FDA8: nop
    
            goto L_8040FDB0;
    }
    // 0x8040FDA8: nop

    // 0x8040FDAC: break       7
    do_break(2151742892);
L_8040FDB0:
    // 0x8040FDB0: sw          $t5, 0x39CD($at)
    MEM_W(0X39CD, ctx->r1) = ctx->r13;
    // 0x8040FDB4: sh          $t0, 0x39C0($t2)
    MEM_H(0X39C0, ctx->r10) = ctx->r8;
    // 0x8040FDB8: sh          $t0, 0x39C2($t2)
    MEM_H(0X39C2, ctx->r10) = ctx->r8;
    // 0x8040FDBC: sh          $t0, 0x39C4($t2)
    MEM_H(0X39C4, ctx->r10) = ctx->r8;
    // 0x8040FDC0: jr          $ra
    // 0x8040FDC4: sh          $t6, 0x39C6($t2)
    MEM_H(0X39C6, ctx->r10) = ctx->r14;
    return;
    // 0x8040FDC4: sh          $t6, 0x39C6($t2)
    MEM_H(0X39C6, ctx->r10) = ctx->r14;
;}
RECOMP_FUNC void func_805EC20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805EC20C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805EC210: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805EC214: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805EC218: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805EC21C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805EC220: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x805EC224: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x805EC228: jr          $ra
    // 0x805EC22C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x805EC22C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80444B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444B28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80444B2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80444B30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80444B34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80444B38: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80444B3C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80444B40: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80444B44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80444B48: jal         0x80047090
    // 0x80444B4C: addiu       $a0, $zero, 0x40F0
    ctx->r4 = ADD32(0, 0X40F0);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80444B4C: addiu       $a0, $zero, 0x40F0
    ctx->r4 = ADD32(0, 0X40F0);
    after_0:
    // 0x80444B50: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444B54: beq         $v0, $at, L_80444C80
    if (ctx->r2 == ctx->r1) {
        // 0x80444B58: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444C80;
    }
    // 0x80444B58: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80444B5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80444B60: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80444B64: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444B68: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80444B6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80444B70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80444B74: jal         0x8004613C
    // 0x80444B78: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444B78: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x80444B7C: beq         $v0, $zero, L_80444C80
    if (ctx->r2 == 0) {
        // 0x80444B80: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80444C80;
    }
    // 0x80444B80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80444B84: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80444B88: jal         0x80047F9C
    // 0x80444B8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444B8C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80444B90: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80444B94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80444B98: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80444B9C: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x80444BA0: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x80444BA4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FDC) << 16);
    // 0x80444BA8: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80444BAC: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80444BB0: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x80444BB4: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80444BB8: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x80444BBC: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80444BC0: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x80444BC4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80444BC8: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x80444BCC: lwc1        $f6, -0x7C44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FDC));
    // 0x80444BD0: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80444BD4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80444BD8: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80444BDC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80444BE0: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    // 0x80444BE4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80444BE8: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80444BEC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80444BF0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80444BF4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80444BF8: lhu         $a0, 0x3E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3E);
    // 0x80444BFC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80444C00: jal         0x8005D078
    // 0x80444C04: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005D078(rdram, ctx);
        goto after_3;
    // 0x80444C04: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80444C08: beq         $v0, $zero, L_80444C80
    if (ctx->r2 == 0) {
        // 0x80444C0C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80444C80;
    }
    // 0x80444C0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80444C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80444C14: jal         0x80047F9C
    // 0x80444C18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80444C18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80444C1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80444C20: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80444C24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80444C28: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80444C2C: sb          $t1, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r9;
    // 0x80444C30: lw          $t2, 0x478($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X478);
    // 0x80444C34: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FE0) << 16);
    // 0x80444C38: lw          $t6, 0x16C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X16C);
    // 0x80444C3C: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80444C40: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80444C44: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x80444C48: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x80444C4C: lw          $t3, 0x478($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X478);
    // 0x80444C50: lwc1        $f0, 0x4($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80444C54: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x80444C58: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x80444C5C: lw          $t4, 0x478($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X478);
    // 0x80444C60: lwc1        $f18, -0x7C40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FE0));
    // 0x80444C64: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80444C68: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x80444C6C: sb          $t5, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r13;
    // 0x80444C70: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80444C74: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x80444C78: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x80444C7C: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
L_80444C80:
    // 0x80444C80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80444C84: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80444C88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80444C8C: jr          $ra
    // 0x80444C90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80444C90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
