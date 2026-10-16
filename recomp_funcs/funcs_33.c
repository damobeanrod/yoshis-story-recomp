#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800067BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800067BC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800067C0: beq         $a0, $at, L_800067E4
    if (ctx->r4 == ctx->r1) {
        // 0x800067C4: lui         $t6, 0x800B
        ctx->r14 = S32(0X800B << 16);
            goto L_800067E4;
    }
    // 0x800067C4: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800067C8: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x800067CC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800067D0: lbu         $t7, 0x2950($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2950);
    // 0x800067D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800067D8: beq         $t7, $at, L_800067E4
    if (ctx->r15 == ctx->r1) {
        // 0x800067DC: nop
    
            goto L_800067E4;
    }
    // 0x800067DC: nop

    // 0x800067E0: sb          $a1, 0x2950($v0)
    MEM_B(0X2950, ctx->r2) = ctx->r5;
L_800067E4:
    // 0x800067E4: jr          $ra
    // 0x800067E8: nop

    return;
    // 0x800067E8: nop

;}
RECOMP_FUNC void func_80574624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80574628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057462C: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80574630: bnel        $t6, $zero, L_80574644
    if (ctx->r14 != 0) {
        // 0x80574634: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80574644;
    }
    goto skip_0;
    // 0x80574634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80574638: jal         0x80574A64
    // 0x8057463C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80574A64(rdram, ctx);
        goto after_0;
    // 0x8057463C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80574640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80574644:
    // 0x80574644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80574648: jr          $ra
    // 0x8057464C: nop

    return;
    // 0x8057464C: nop

;}
RECOMP_FUNC void func_80044A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044A54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044A58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80044A5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80044A60: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80044A64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80044A68: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044A6C: bne         $t6, $zero, L_80044A84
    if (ctx->r14 != 0) {
        // 0x80044A70: addiu       $a0, $a0, 0x560
        ctx->r4 = ADD32(ctx->r4, 0X560);
            goto L_80044A84;
    }
    // 0x80044A70: addiu       $a0, $a0, 0x560
    ctx->r4 = ADD32(ctx->r4, 0X560);
    // 0x80044A74: jal         0x80071380
    // 0x80044A78: addiu       $a1, $zero, 0x61D
    ctx->r5 = ADD32(0, 0X61D);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80044A78: addiu       $a1, $zero, 0x61D
    ctx->r5 = ADD32(0, 0X61D);
    after_0:
    // 0x80044A7C: b           L_80044AB8
    // 0x80044A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80044AB8;
    // 0x80044A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80044A84:
    // 0x80044A84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80044A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80044A8C: jalr        $t9
    // 0x80044A90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80044A90: nop

    after_1:
    // 0x80044A94: jal         0x8004488C
    // 0x80044A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004488C(rdram, ctx);
        goto after_2;
    // 0x80044A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80044A9C: jal         0x80044250
    // 0x80044AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044250(rdram, ctx);
        goto after_3;
    // 0x80044AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80044AA4: jal         0x8004445C
    // 0x80044AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004445C(rdram, ctx);
        goto after_4;
    // 0x80044AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80044AAC: jal         0x800451F0
    // 0x80044AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800451F0(rdram, ctx);
        goto after_5;
    // 0x80044AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80044AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80044AB8:
    // 0x80044AB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80044ABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044AC0: jr          $ra
    // 0x80044AC4: nop

    return;
    // 0x80044AC4: nop

;}
RECOMP_FUNC void func_800063A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800063A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800063AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800063B0: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800063B4: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x800063B8: lw          $t8, 0x1DAC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1DAC);
    // 0x800063BC: lh          $t0, 0x1D7C($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X1D7C);
    // 0x800063C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800063C4: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800063C8: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800063CC: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x800063D0: addiu       $s4, $s4, 0x6BE8
    ctx->r20 = ADD32(ctx->r20, 0X6BE8);
    // 0x800063D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800063D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800063DC: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800063E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800063E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800063E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800063EC: sw          $t6, 0x1DA4($s1)
    MEM_W(0X1DA4, ctx->r17) = ctx->r14;
    // 0x800063F0: mflo        $a1
    ctx->r5 = lo;
    // 0x800063F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800063F8: jal         0x80003698
    // 0x800063FC: nop

    func_80003698(rdram, ctx);
        goto after_0;
    // 0x800063FC: nop

    after_0:
    // 0x80006400: lw          $t1, 0x1DAC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1DAC);
    // 0x80006404: lh          $t3, 0x1D7C($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1D7C);
    // 0x80006408: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x8000640C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80006410: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80006414: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006418: sw          $v0, 0x1B50($s1)
    MEM_W(0X1B50, ctx->r17) = ctx->r2;
    // 0x8000641C: addiu       $s3, $s3, 0x6BC8
    ctx->r19 = ADD32(ctx->r19, 0X6BC8);
    // 0x80006420: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80006424: mflo        $t4
    ctx->r12 = lo;
    // 0x80006428: blezl       $t4, L_800064D8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000642C: lw          $a0, 0x1B54($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X1B54);
            goto L_800064D8;
    }
    goto skip_0;
    // 0x8000642C: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
    skip_0:
    // 0x80006430: lw          $t5, 0x1B54($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1B54);
L_80006434:
    // 0x80006434: lw          $t7, 0x1B50($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1B50);
    // 0x80006438: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000643C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80006440: lw          $a1, 0x1DA4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DA4);
    // 0x80006444: jal         0x800035F8
    // 0x80006448: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    func_800035F8(rdram, ctx);
        goto after_1;
    // 0x80006448: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x8000644C: bne         $v0, $zero, L_80006484
    if (ctx->r2 != 0) {
        // 0x80006450: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80006484;
    }
    // 0x80006450: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80006454: lw          $t8, 0x1EB8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1EB8);
    // 0x80006458: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000645C: bne         $t8, $zero, L_8000646C
    if (ctx->r24 != 0) {
        // 0x80006460: nop
    
            goto L_8000646C;
    }
    // 0x80006460: nop

    // 0x80006464: b           L_800064D4
    // 0x80006468: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_800064D4;
    // 0x80006468: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000646C:
    // 0x8000646C: jal         0x800035F8
    // 0x80006470: lw          $a1, 0x1DA4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DA4);
    func_800035F8(rdram, ctx);
        goto after_2;
    // 0x80006470: lw          $a1, 0x1DA4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DA4);
    after_2:
    // 0x80006474: bne         $v0, $zero, L_80006484
    if (ctx->r2 != 0) {
        // 0x80006478: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80006484;
    }
    // 0x80006478: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000647C: b           L_800064D4
    // 0x80006480: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_800064D4;
    // 0x80006480: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80006484:
    // 0x80006484: lw          $t9, 0x1DA4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1DA4);
    // 0x80006488: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000648C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80006490: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x80006494: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x80006498: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
    // 0x8000649C: lw          $t2, 0x1DAC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1DAC);
    // 0x800064A0: lh          $t4, 0x1D7C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1D7C);
    // 0x800064A4: lw          $t0, 0x1B54($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1B54);
    // 0x800064A8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800064AC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800064B0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800064B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800064B8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800064BC: sw          $t1, 0x1B54($s1)
    MEM_W(0X1B54, ctx->r17) = ctx->r9;
    // 0x800064C0: mflo        $t5
    ctx->r13 = lo;
    // 0x800064C4: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800064C8: bnel        $at, $zero, L_80006434
    if (ctx->r1 != 0) {
        // 0x800064CC: lw          $t5, 0x1B54($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X1B54);
            goto L_80006434;
    }
    goto skip_1;
    // 0x800064CC: lw          $t5, 0x1B54($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1B54);
    skip_1:
    // 0x800064D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800064D4:
    // 0x800064D4: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
L_800064D8:
    // 0x800064D8: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800064DC: addiu       $s3, $s3, 0x6BC8
    ctx->r19 = ADD32(ctx->r19, 0X6BC8);
    // 0x800064E0: beq         $a0, $zero, L_80006520
    if (ctx->r4 == 0) {
        // 0x800064E4: addiu       $t8, $zero, 0x500
        ctx->r24 = ADD32(0, 0X500);
            goto L_80006520;
    }
    // 0x800064E4: addiu       $t8, $zero, 0x500
    ctx->r24 = ADD32(0, 0X500);
    // 0x800064E8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800064EC: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x800064F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800064F4: sb          $s2, 0x1B60($v0)
    MEM_B(0X1B60, ctx->r2) = ctx->r18;
L_800064F8:
    // 0x800064F8: lw          $t6, 0x1B50($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1B50);
    // 0x800064FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006500: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80006504: sb          $s2, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r18;
    // 0x80006508: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
    // 0x8000650C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80006510: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80006514: sltu        $at, $s2, $a0
    ctx->r1 = ctx->r18 < ctx->r4 ? 1 : 0;
    // 0x80006518: bnel        $at, $zero, L_800064F8
    if (ctx->r1 != 0) {
        // 0x8000651C: sb          $s2, 0x1B60($v0)
        MEM_B(0X1B60, ctx->r2) = ctx->r18;
            goto L_800064F8;
    }
    goto skip_2;
    // 0x8000651C: sb          $s2, 0x1B60($v0)
    MEM_B(0X1B60, ctx->r2) = ctx->r18;
    skip_2:
L_80006520:
    // 0x80006520: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80006524: beq         $at, $zero, L_8000654C
    if (ctx->r1 == 0) {
        // 0x80006528: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_8000654C;
    }
    // 0x80006528: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000652C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80006530: addiu       $v1, $v1, 0x4E10
    ctx->r3 = ADD32(ctx->r3, 0X4E10);
    // 0x80006534: addu        $v0, $s1, $s2
    ctx->r2 = ADD32(ctx->r17, ctx->r18);
L_80006538:
    // 0x80006538: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000653C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80006540: bne         $at, $zero, L_80006538
    if (ctx->r1 != 0) {
        // 0x80006544: sb          $zero, 0x1B5F($v0)
        MEM_B(0X1B5F, ctx->r2) = 0;
            goto L_80006538;
    }
    // 0x80006544: sb          $zero, 0x1B5F($v0)
    MEM_B(0X1B5F, ctx->r2) = 0;
    // 0x80006548: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
L_8000654C:
    // 0x8000654C: lw          $t9, 0x1DAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1DAC);
    // 0x80006550: sb          $zero, 0x1D60($s1)
    MEM_B(0X1D60, ctx->r17) = 0;
    // 0x80006554: sb          $a0, 0x1D62($s1)
    MEM_B(0X1D62, ctx->r17) = ctx->r4;
    // 0x80006558: sw          $a0, 0x1B58($s1)
    MEM_W(0X1B58, ctx->r17) = ctx->r4;
    // 0x8000655C: sw          $t8, 0x1DA4($s1)
    MEM_W(0X1DA4, ctx->r17) = ctx->r24;
    // 0x80006560: blez        $t9, L_800065F4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80006564: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800065F4;
    }
    // 0x80006564: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80006568:
    // 0x80006568: lw          $t0, 0x1B54($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1B54);
    // 0x8000656C: lw          $t2, 0x1B50($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1B50);
    // 0x80006570: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80006574: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80006578: lw          $a1, 0x1DA4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DA4);
    // 0x8000657C: jal         0x800035F8
    // 0x80006580: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    func_800035F8(rdram, ctx);
        goto after_3;
    // 0x80006580: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x80006584: bne         $v0, $zero, L_800065BC
    if (ctx->r2 != 0) {
        // 0x80006588: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800065BC;
    }
    // 0x80006588: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000658C: lw          $t3, 0x1EB8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1EB8);
    // 0x80006590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80006594: bne         $t3, $zero, L_800065A4
    if (ctx->r11 != 0) {
        // 0x80006598: nop
    
            goto L_800065A4;
    }
    // 0x80006598: nop

    // 0x8000659C: b           L_800065F4
    // 0x800065A0: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
        goto L_800065F4;
    // 0x800065A0: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
L_800065A4:
    // 0x800065A4: jal         0x800035F8
    // 0x800065A8: lw          $a1, 0x1DA4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DA4);
    func_800035F8(rdram, ctx);
        goto after_4;
    // 0x800065A8: lw          $a1, 0x1DA4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1DA4);
    after_4:
    // 0x800065AC: bne         $v0, $zero, L_800065BC
    if (ctx->r2 != 0) {
        // 0x800065B0: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800065BC;
    }
    // 0x800065B0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800065B4: b           L_800065F4
    // 0x800065B8: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
        goto L_800065F4;
    // 0x800065B8: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
L_800065BC:
    // 0x800065BC: lw          $t4, 0x1DA4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1DA4);
    // 0x800065C0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800065C4: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x800065C8: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x800065CC: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x800065D0: sh          $t4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r12;
    // 0x800065D4: lw          $t7, 0x1DAC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1DAC);
    // 0x800065D8: lw          $t5, 0x1B54($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1B54);
    // 0x800065DC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800065E0: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800065E4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800065E8: bne         $at, $zero, L_80006568
    if (ctx->r1 != 0) {
        // 0x800065EC: sw          $t6, 0x1B54($s1)
        MEM_W(0X1B54, ctx->r17) = ctx->r14;
            goto L_80006568;
    }
    // 0x800065EC: sw          $t6, 0x1B54($s1)
    MEM_W(0X1B54, ctx->r17) = ctx->r14;
    // 0x800065F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800065F4:
    // 0x800065F4: lw          $s2, 0x1B58($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X1B58);
    // 0x800065F8: sltu        $at, $s2, $a0
    ctx->r1 = ctx->r18 < ctx->r4 ? 1 : 0;
    // 0x800065FC: beq         $at, $zero, L_80006648
    if (ctx->r1 == 0) {
        // 0x80006600: sll         $v1, $s2, 4
        ctx->r3 = S32(ctx->r18 << 4);
            goto L_80006648;
    }
    // 0x80006600: sll         $v1, $s2, 4
    ctx->r3 = S32(ctx->r18 << 4);
    // 0x80006604: addu        $v0, $s1, $s2
    ctx->r2 = ADD32(ctx->r17, ctx->r18);
    // 0x80006608: lw          $t8, 0x1B58($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1B58);
L_8000660C:
    // 0x8000660C: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80006610: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80006614: sb          $s2, 0x1C60($t0)
    MEM_B(0X1C60, ctx->r8) = ctx->r18;
    // 0x80006618: lw          $t3, 0x1B50($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1B50);
    // 0x8000661C: lw          $t1, 0x1B58($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1B58);
    // 0x80006620: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006624: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x80006628: subu        $t2, $s2, $t1
    ctx->r10 = SUB32(ctx->r18, ctx->r9);
    // 0x8000662C: sb          $t2, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r10;
    // 0x80006630: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
    // 0x80006634: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80006638: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000663C: sltu        $at, $s2, $a0
    ctx->r1 = ctx->r18 < ctx->r4 ? 1 : 0;
    // 0x80006640: bnel        $at, $zero, L_8000660C
    if (ctx->r1 != 0) {
        // 0x80006644: lw          $t8, 0x1B58($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X1B58);
            goto L_8000660C;
    }
    goto skip_3;
    // 0x80006644: lw          $t8, 0x1B58($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1B58);
    skip_3:
L_80006648:
    // 0x80006648: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8000664C: beq         $at, $zero, L_80006678
    if (ctx->r1 == 0) {
        // 0x80006650: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_80006678;
    }
    // 0x80006650: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80006654: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80006658: addiu       $v1, $v1, 0x4E10
    ctx->r3 = ADD32(ctx->r3, 0X4E10);
    // 0x8000665C: addu        $v0, $s1, $s2
    ctx->r2 = ADD32(ctx->r17, ctx->r18);
L_80006660:
    // 0x80006660: lw          $t5, 0x1B58($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1B58);
    // 0x80006664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006668: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000666C: bne         $at, $zero, L_80006660
    if (ctx->r1 != 0) {
        // 0x80006670: sb          $t5, 0x1C5F($v0)
        MEM_B(0X1C5F, ctx->r2) = ctx->r13;
            goto L_80006660;
    }
    // 0x80006670: sb          $t5, 0x1C5F($v0)
    MEM_B(0X1C5F, ctx->r2) = ctx->r13;
    // 0x80006674: lw          $a0, 0x1B54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1B54);
L_80006678:
    // 0x80006678: lw          $t6, 0x1B58($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1B58);
    // 0x8000667C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80006680: sb          $zero, 0x1D61($s1)
    MEM_B(0X1D61, ctx->r17) = 0;
    // 0x80006684: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x80006688: sb          $t7, 0x1D63($s1)
    MEM_B(0X1D63, ctx->r17) = ctx->r15;
    // 0x8000668C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006694: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006698: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000669C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800066A0: jr          $ra
    // 0x800066A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800066A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807043F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807043F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807043F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807043F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x807043FC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80704400: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80704404: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80704408: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8070440C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80704410: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3894) << 16);
    // 0x80704414: lwc1        $f10, 0x6D04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3894));
    // 0x80704418: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8070441C: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80704420: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80704424: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80704428: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8070442C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80704430: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80704434: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80704438: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8070443C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80704440: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80704444: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80704448: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8070444C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80704450: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80704454: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80704458: jalr        $t9
    // 0x8070445C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8070445C: nop

    after_0:
    // 0x80704460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80704464: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80704468: jr          $ra
    // 0x8070446C: nop

    return;
    // 0x8070446C: nop

;}
RECOMP_FUNC void func_8053589C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053589C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x805358A0: beql        $at, $zero, L_805358B4
    if (ctx->r1 == 0) {
        // 0x805358A4: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_805358B4;
    }
    goto skip_0;
    // 0x805358A4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x805358A8: jr          $ra
    // 0x805358AC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x805358AC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x805358B0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_805358B4:
    // 0x805358B4: beq         $at, $zero, L_805358F0
    if (ctx->r1 == 0) {
        // 0x805358B8: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_805358F0;
    }
    // 0x805358B8: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x805358BC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x805358C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805358C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805358C8: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x805358CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805358D0: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x805358D4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x805358D8: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x805358DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805358E0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805358E4: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x805358E8: jr          $ra
    // 0x805358EC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x805358EC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_805358F0:
    // 0x805358F0: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x805358F4: beq         $at, $zero, L_8053590C
    if (ctx->r1 == 0) {
        // 0x805358F8: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_8053590C;
    }
    // 0x805358F8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x805358FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535900: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80535904: jr          $ra
    // 0x80535908: nop

    return;
    // 0x80535908: nop

L_8053590C:
    // 0x8053590C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80535910: beq         $at, $zero, L_80535950
    if (ctx->r1 == 0) {
        // 0x80535914: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80535950;
    }
    // 0x80535914: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80535918: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x8053591C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80535920: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535924: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80535928: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8053592C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80535930: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80535934: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80535938: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8053593C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80535940: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80535944: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80535948: jr          $ra
    // 0x8053594C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x8053594C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_80535950:
    // 0x80535950: jr          $ra
    // 0x80535954: nop

    return;
    // 0x80535954: nop

;}
RECOMP_FUNC void func_806AF2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF2C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AF2CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AF2D0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806AF2D4: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(595, 0X1EC4) << 16);
    // 0x806AF2D8: addiu       $t6, $t6, -0x3FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(595, 0X1EC4));
    // 0x806AF2DC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806AF2E0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806AF2E4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806AF2E8: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x806AF2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AF2F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806AF2F4: jal         0x806AF64C
    // 0x806AF2F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806AF64C(rdram, ctx);
        goto after_0;
    // 0x806AF2F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x806AF2FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AF300: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806AF304: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AF308: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806AF30C: jr          $ra
    // 0x806AF310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806AF310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806763F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806763F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806763F8: lw          $v1, 0x2EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2EC);
    // 0x806763FC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80676400: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80676404: sw          $t6, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->r14;
    // 0x80676408: bne         $at, $zero, L_80676414
    if (ctx->r1 != 0) {
        // 0x8067640C: sw          $v1, 0x2E8($v0)
        MEM_W(0X2E8, ctx->r2) = ctx->r3;
            goto L_80676414;
    }
    // 0x8067640C: sw          $v1, 0x2E8($v0)
    MEM_W(0X2E8, ctx->r2) = ctx->r3;
    // 0x80676410: sw          $zero, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = 0;
L_80676414:
    // 0x80676414: jr          $ra
    // 0x80676418: nop

    return;
    // 0x80676418: nop

;}
RECOMP_FUNC void func_80023B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023B78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023B80: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80023B84: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80023B88: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80023B8C: lw          $t6, 0x1F4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1F4);
    // 0x80023B90: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80023B94: beql        $t6, $zero, L_80023BB8
    if (ctx->r14 == 0) {
        // 0x80023B98: lw          $t7, 0xAA4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0XAA4);
            goto L_80023BB8;
    }
    goto skip_0;
    // 0x80023B98: lw          $t7, 0xAA4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XAA4);
    skip_0:
    // 0x80023B9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80023BA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023BA4: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80023BA8: lwc1        $f4, -0x2B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B8);
    // 0x80023BAC: b           L_80023CF8
    // 0x80023BB0: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
        goto L_80023CF8;
    // 0x80023BB0: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80023BB4: lw          $t7, 0xAA4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XAA4);
L_80023BB8:
    // 0x80023BB8: lh          $a0, 0xADE($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XADE);
    // 0x80023BBC: beql        $t7, $zero, L_80023C14
    if (ctx->r15 == 0) {
        // 0x80023BC0: sh          $a0, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r4;
            goto L_80023C14;
    }
    goto skip_1;
    // 0x80023BC0: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    skip_1:
    // 0x80023BC4: lw          $v0, 0xF10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF10);
    // 0x80023BC8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80023BCC: beq         $v0, $at, L_80023BDC
    if (ctx->r2 == ctx->r1) {
        // 0x80023BD0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80023BDC;
    }
    // 0x80023BD0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80023BD4: bnel        $v0, $at, L_80023C14
    if (ctx->r2 != ctx->r1) {
        // 0x80023BD8: sh          $a0, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r4;
            goto L_80023C14;
    }
    goto skip_2;
    // 0x80023BD8: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    skip_2:
L_80023BDC:
    // 0x80023BDC: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    // 0x80023BE0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80023BE4: jal         0x8006593C
    // 0x80023BE8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80023BE8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80023BEC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80023BF0: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80023BF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023BF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80023BFC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x80023C00: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80023C04: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80023C08: b           L_80023C50
    // 0x80023C0C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
        goto L_80023C50;
    // 0x80023C0C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80023C10: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
L_80023C14:
    // 0x80023C14: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80023C18: jal         0x8006593C
    // 0x80023C1C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80023C1C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80023C20: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80023C24: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80023C28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023C2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80023C30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023C34: lwc1        $f8, -0x2B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B4);
    // 0x80023C38: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x80023C3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80023C40: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80023C44: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80023C48: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80023C4C: nop

L_80023C50:
    // 0x80023C50: lbu         $t8, 0xF5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XF5);
    // 0x80023C54: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80023C58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023C5C: bne         $t8, $at, L_80023C78
    if (ctx->r24 != ctx->r1) {
        // 0x80023C60: addiu       $v0, $a1, 0xC4
        ctx->r2 = ADD32(ctx->r5, 0XC4);
            goto L_80023C78;
    }
    // 0x80023C60: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x80023C64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80023C68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023C6C: nop

    // 0x80023C70: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80023C74: nop

L_80023C78:
    // 0x80023C78: beql        $a0, $zero, L_80023CE8
    if (ctx->r4 == 0) {
        // 0x80023C7C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80023CE8;
    }
    goto skip_3;
    // 0x80023C7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x80023C80: blez        $a0, L_80023CA0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80023C84: lui         $at, 0xC080
        ctx->r1 = S32(0XC080 << 16);
            goto L_80023CA0;
    }
    // 0x80023C84: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80023C88: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023C8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023C90: nop

    // 0x80023C94: mul.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80023C98: b           L_80023CB4
    // 0x80023C9C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
        goto L_80023CB4;
    // 0x80023C9C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_80023CA0:
    // 0x80023CA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80023CA4: nop

    // 0x80023CA8: mul.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80023CAC: nop

    // 0x80023CB0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_80023CB4:
    // 0x80023CB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80023CB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023CBC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80023CC0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80023CC4: nop

    // 0x80023CC8: bc1fl       L_80023CD8
    if (!c1cs) {
        // 0x80023CCC: swc1        $f2, 0xDC($a1)
        MEM_W(0XDC, ctx->r5) = ctx->f2.u32l;
            goto L_80023CD8;
    }
    goto skip_4;
    // 0x80023CCC: swc1        $f2, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f2.u32l;
    skip_4:
    // 0x80023CD0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80023CD4: swc1        $f2, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f2.u32l;
L_80023CD8:
    // 0x80023CD8: lwc1        $f8, -0x2B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B0);
    // 0x80023CDC: b           L_80023CF8
    // 0x80023CE0: swc1        $f8, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f8.u32l;
        goto L_80023CF8;
    // 0x80023CE0: swc1        $f8, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f8.u32l;
    // 0x80023CE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80023CE8:
    // 0x80023CE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023CEC: swc1        $f0, 0xDC($a1)
    MEM_W(0XDC, ctx->r5) = ctx->f0.u32l;
    // 0x80023CF0: lwc1        $f10, -0x2AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2AC);
    // 0x80023CF4: swc1        $f10, 0xE8($a1)
    MEM_W(0XE8, ctx->r5) = ctx->f10.u32l;
L_80023CF8:
    // 0x80023CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023D00: jr          $ra
    // 0x80023D04: nop

    return;
    // 0x80023D04: nop

;}
RECOMP_FUNC void func_805E5370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E5370: lui         $v0, 0x805F
    ctx->r2 = S32(RELOC_HI16(489, 0X6D98) << 16);
    // 0x805E5374: jr          $ra
    // 0x805E5378: addiu       $v0, $v0, -0x3EF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(489, 0X6D98));
    return;
    // 0x805E5378: addiu       $v0, $v0, -0x3EF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(489, 0X6D98));
;}
RECOMP_FUNC void func_8064ABD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064ABD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064ABDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064ABE0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064ABE4: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064ABE8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064ABEC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064ABF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064ABF4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8064ABF8: nop

    // 0x8064ABFC: bc1fl       L_8064AC2C
    if (!c1cs) {
        // 0x8064AC00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AC2C;
    }
    goto skip_0;
    // 0x8064AC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064AC04: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064AC08: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064AC0C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064AC10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064AC14: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x8064AC18: jal         0x8064AEA8
    // 0x8064AC1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064AEA8(rdram, ctx);
        goto after_0;
    // 0x8064AC1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064AC20: jal         0x8064A40C
    // 0x8064AC24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064AC24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064AC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064AC2C:
    // 0x8064AC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AC30: jr          $ra
    // 0x8064AC34: nop

    return;
    // 0x8064AC34: nop

;}
RECOMP_FUNC void func_806804A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806804A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806804A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806804A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806804AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806804B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806804B4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806804B8: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x806804BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806804C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806804C4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2230) << 16);
    // 0x806804C8: lwc1        $f6, 0x2640($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2230));
    // 0x806804CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806804D0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x806804D4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806804D8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x806804DC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806804E0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806804E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806804E8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x806804EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806804F0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x806804F4: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806804F8: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806804FC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80680500: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80680504: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80680508: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8068050C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80680510: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80680514: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80680518: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8068051C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80680520: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80680524: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80680528: jalr        $t9
    // 0x8068052C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8068052C: nop

    after_0:
    // 0x80680530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680534: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80680538: jr          $ra
    // 0x8068053C: nop

    return;
    // 0x8068053C: nop

;}
RECOMP_FUNC void func_80456384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456384: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80456388: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8045638C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80456390: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80456394: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456398: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8045639C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804563A0: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x804563A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804563A8: jal         0x8044EFA0
    // 0x804563AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804563AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x804563B0: jal         0x804449C0
    // 0x804563B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x804563B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804563B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804563BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804563C0: jal         0x80450490
    // 0x804563C4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x804563C4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x804563C8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x804563CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804563D0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x804563D4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804563D8: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x804563DC: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D64) << 16);
    // 0x804563E0: lw          $t9, -0x7EBC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D64));
    // 0x804563E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804563E8: jalr        $t9
    // 0x804563EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804563EC: nop

    after_3:
    // 0x804563F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x804563F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804563F8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804563FC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80456400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456404: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80456408: jal         0x80455D88
    // 0x8045640C: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80455D88(rdram, ctx);
        goto after_4;
    // 0x8045640C: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x80456410: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80456414: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80456418: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045641C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80456420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456424: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80456428: jal         0x80455D88
    // 0x8045642C: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    func_80455D88(rdram, ctx);
        goto after_5;
    // 0x8045642C: swc1        $f6, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x80456430: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80456434: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80456438: lw          $t2, 0xFB8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XFB8);
    // 0x8045643C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80456440: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x80456444: bnel        $t4, $zero, L_80456570
    if (ctx->r12 != 0) {
        // 0x80456448: lbu         $v0, 0xF5D($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
            goto L_80456570;
    }
    goto skip_0;
    // 0x80456448: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    skip_0:
    // 0x8045644C: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80456450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456454: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456458: bne         $v0, $zero, L_80456498
    if (ctx->r2 != 0) {
        // 0x8045645C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80456498;
    }
    // 0x8045645C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456460: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14188) << 16);
    // 0x80456464: lwc1        $f0, -0x7A98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14188));
    // 0x80456468: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8045646C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80456470: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1418C) << 16);
    // 0x80456474: lwc1        $f10, -0x7A94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1418C));
    // 0x80456478: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8045647C: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456480: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456484: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80456488: jal         0x80444B28
    // 0x8045648C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_6;
    // 0x8045648C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80456490: b           L_80456668
    // 0x80456494: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x80456494: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456498:
    // 0x80456498: bne         $v0, $at, L_804564DC
    if (ctx->r2 != ctx->r1) {
        // 0x8045649C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804564DC;
    }
    // 0x8045649C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804564A0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14190) << 16);
    // 0x804564A4: lwc1        $f0, -0x7A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14190));
    // 0x804564A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804564AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804564B0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14194) << 16);
    // 0x804564B4: lwc1        $f18, -0x7A8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14194));
    // 0x804564B8: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804564BC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x804564C0: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x804564C4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804564C8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x804564CC: jal         0x80444B28
    // 0x804564D0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_7;
    // 0x804564D0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x804564D4: b           L_80456668
    // 0x804564D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x804564D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804564DC:
    // 0x804564DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804564E0: bne         $v0, $at, L_80456524
    if (ctx->r2 != ctx->r1) {
        // 0x804564E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456524;
    }
    // 0x804564E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804564E8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14198) << 16);
    // 0x804564EC: lwc1        $f0, -0x7A88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14198));
    // 0x804564F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804564F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804564F8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1419C) << 16);
    // 0x804564FC: lwc1        $f6, -0x7A84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1419C));
    // 0x80456500: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456504: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80456508: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x8045650C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456510: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80456514: jal         0x80444B28
    // 0x80456518: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_8;
    // 0x80456518: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8045651C: b           L_80456668
    // 0x80456520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x80456520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456524:
    // 0x80456524: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456528: bne         $v0, $at, L_80456664
    if (ctx->r2 != ctx->r1) {
        // 0x8045652C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456664;
    }
    // 0x8045652C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456530: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141A0) << 16);
    // 0x80456534: lwc1        $f0, -0x7A80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141A0));
    // 0x80456538: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8045653C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80456540: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141A4) << 16);
    // 0x80456544: lwc1        $f10, -0x7A7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141A4));
    // 0x80456548: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x8045654C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80456550: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80456554: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456558: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8045655C: jal         0x80444B28
    // 0x80456560: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_9;
    // 0x80456560: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80456564: b           L_80456668
    // 0x80456568: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x80456568: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8045656C: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
L_80456570:
    // 0x80456570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456574: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456578: bne         $v0, $zero, L_804565B0
    if (ctx->r2 != 0) {
        // 0x8045657C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_804565B0;
    }
    // 0x8045657C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80456580: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141A8) << 16);
    // 0x80456584: lwc1        $f0, -0x7A78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141A8));
    // 0x80456588: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8045658C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80456590: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80456594: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456598: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8045659C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804565A0: jal         0x80444B28
    // 0x804565A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80444B28(rdram, ctx);
        goto after_10;
    // 0x804565A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x804565A8: b           L_80456668
    // 0x804565AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x804565AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804565B0:
    // 0x804565B0: bne         $v0, $at, L_804565EC
    if (ctx->r2 != ctx->r1) {
        // 0x804565B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804565EC;
    }
    // 0x804565B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804565B8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141AC) << 16);
    // 0x804565BC: lwc1        $f0, -0x7A74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141AC));
    // 0x804565C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804565C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804565C8: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x804565CC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x804565D0: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x804565D4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x804565D8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x804565DC: jal         0x80444B28
    // 0x804565E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_11;
    // 0x804565E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x804565E4: b           L_80456668
    // 0x804565E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x804565E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804565EC:
    // 0x804565EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804565F0: bne         $v0, $at, L_8045662C
    if (ctx->r2 != ctx->r1) {
        // 0x804565F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8045662C;
    }
    // 0x804565F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804565F8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141B0) << 16);
    // 0x804565FC: lwc1        $f0, -0x7A70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141B0));
    // 0x80456600: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456604: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456608: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x8045660C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80456610: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456614: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456618: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8045661C: jal         0x80444B28
    // 0x80456620: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80444B28(rdram, ctx);
        goto after_12;
    // 0x80456620: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80456624: b           L_80456668
    // 0x80456628: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80456668;
    // 0x80456628: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8045662C:
    // 0x8045662C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456630: bne         $v0, $at, L_80456664
    if (ctx->r2 != ctx->r1) {
        // 0x80456634: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80456664;
    }
    // 0x80456634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456638: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X141B4) << 16);
    // 0x8045663C: lwc1        $f0, -0x7A6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X141B4));
    // 0x80456640: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456644: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80456648: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x8045664C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80456650: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456654: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456658: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8045665C: jal         0x80444B28
    // 0x80456660: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80444B28(rdram, ctx);
        goto after_13;
    // 0x80456660: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
L_80456664:
    // 0x80456664: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80456668:
    // 0x80456668: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8045666C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80456670: jr          $ra
    // 0x80456674: nop

    return;
    // 0x80456674: nop

;}
RECOMP_FUNC void func_807AC660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC660: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807AC664: addiu       $at, $zero, 0x46EE
    ctx->r1 = ADD32(0, 0X46EE);
    // 0x807AC668: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(859, 0X2418) << 16);
    // 0x807AC66C: beq         $v0, $at, L_807AC698
    if (ctx->r2 == ctx->r1) {
        // 0x807AC670: addiu       $t6, $t6, -0x1588
        ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(859, 0X2418));
            goto L_807AC698;
    }
    // 0x807AC670: addiu       $t6, $t6, -0x1588
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(859, 0X2418));
    // 0x807AC674: addiu       $at, $zero, 0x46EF
    ctx->r1 = ADD32(0, 0X46EF);
    // 0x807AC678: beq         $v0, $at, L_807AC6AC
    if (ctx->r2 == ctx->r1) {
        // 0x807AC67C: addiu       $at, $zero, 0x46F0
        ctx->r1 = ADD32(0, 0X46F0);
            goto L_807AC6AC;
    }
    // 0x807AC67C: addiu       $at, $zero, 0x46F0
    ctx->r1 = ADD32(0, 0X46F0);
    // 0x807AC680: beq         $v0, $at, L_807AC6B8
    if (ctx->r2 == ctx->r1) {
        // 0x807AC684: addiu       $at, $zero, 0x46F2
        ctx->r1 = ADD32(0, 0X46F2);
            goto L_807AC6B8;
    }
    // 0x807AC684: addiu       $at, $zero, 0x46F2
    ctx->r1 = ADD32(0, 0X46F2);
    // 0x807AC688: beq         $v0, $at, L_807AC6C4
    if (ctx->r2 == ctx->r1) {
        // 0x807AC68C: nop
    
            goto L_807AC6C4;
    }
    // 0x807AC68C: nop

    // 0x807AC690: b           L_807AC6D0
    // 0x807AC694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AC6D0;
    // 0x807AC694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AC698:
    // 0x807AC698: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AC69C: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(859, 0X2340) << 16);
    // 0x807AC6A0: sw          $t6, -0x7288($at)
    MEM_W(-0X7288, ctx->r1) = ctx->r14;
    // 0x807AC6A4: jr          $ra
    // 0x807AC6A8: addiu       $v0, $v0, -0x1660
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X2340));
    return;
    // 0x807AC6A8: addiu       $v0, $v0, -0x1660
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X2340));
L_807AC6AC:
    // 0x807AC6AC: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(859, 0X69C) << 16);
    // 0x807AC6B0: jr          $ra
    // 0x807AC6B4: addiu       $v0, $v0, -0x3304
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X69C));
    return;
    // 0x807AC6B4: addiu       $v0, $v0, -0x3304
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X69C));
L_807AC6B8:
    // 0x807AC6B8: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(859, 0XC8C) << 16);
    // 0x807AC6BC: jr          $ra
    // 0x807AC6C0: addiu       $v0, $v0, -0x2D14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0XC8C));
    return;
    // 0x807AC6C0: addiu       $v0, $v0, -0x2D14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0XC8C));
L_807AC6C4:
    // 0x807AC6C4: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(859, 0X1360) << 16);
    // 0x807AC6C8: jr          $ra
    // 0x807AC6CC: addiu       $v0, $v0, -0x2640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X1360));
    return;
    // 0x807AC6CC: addiu       $v0, $v0, -0x2640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(859, 0X1360));
L_807AC6D0:
    // 0x807AC6D0: jr          $ra
    // 0x807AC6D4: nop

    return;
    // 0x807AC6D4: nop

;}
RECOMP_FUNC void func_805807F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805807F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805807F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805807F8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805807FC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80580800: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X45AC) << 16);
    // 0x80580804: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80580808: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8058080C: lw          $t8, 0x33BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X45AC));
    // 0x80580810: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80580814: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80580818: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8058081C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80580820: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80580824: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80580828: beql        $v1, $zero, L_8058085C
    if (ctx->r3 == 0) {
        // 0x8058082C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8058085C;
    }
    goto skip_0;
    // 0x8058082C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80580830: jalr        $v1
    // 0x80580834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80580834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80580838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8058083C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80580840: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80580844: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80580848: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8058084C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80580850: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80580854: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80580858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8058085C:
    // 0x8058085C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580860: jr          $ra
    // 0x80580864: nop

    return;
    // 0x80580864: nop

;}
RECOMP_FUNC void func_800504D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800504D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800504D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800504D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800504DC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800504E0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800504E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800504E8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800504EC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800504F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800504F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800504F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800504FC: bne         $a0, $zero, L_8005050C
    if (ctx->r4 != 0) {
        // 0x80050500: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8005050C;
    }
    // 0x80050500: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050504: b           L_800505BC
    // 0x80050508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800505BC;
    // 0x80050508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005050C:
    // 0x8005050C: lw          $s5, 0x1B8($s3)
    ctx->r21 = MEM_W(ctx->r19, 0X1B8);
    // 0x80050510: bnel        $s5, $zero, L_80050524
    if (ctx->r21 != 0) {
        // 0x80050514: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80050524;
    }
    goto skip_0;
    // 0x80050514: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_0:
    // 0x80050518: b           L_800505BC
    // 0x8005051C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800505BC;
    // 0x8005051C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80050520: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80050524:
    // 0x80050524: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80050528: jal         0x8004F5FC
    // 0x8005052C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8004F5FC(rdram, ctx);
        goto after_0;
    // 0x8005052C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x80050530: jal         0x800502E8
    // 0x80050534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800502E8(rdram, ctx);
        goto after_1;
    // 0x80050534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80050538: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8005053C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80050540: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80050544: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80050548:
    // 0x80050548: jal         0x8004F79C
    // 0x8005054C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004F79C(rdram, ctx);
        goto after_2;
    // 0x8005054C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80050550: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80050554: beq         $t6, $zero, L_8005058C
    if (ctx->r14 == 0) {
        // 0x80050558: andi        $s1, $v0, 0xFF
        ctx->r17 = ctx->r2 & 0XFF;
            goto L_8005058C;
    }
    // 0x80050558: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8005055C: jal         0x8004F7C4
    // 0x80050560: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8004F7C4(rdram, ctx);
        goto after_3;
    // 0x80050560: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80050564: beq         $v0, $zero, L_8005058C
    if (ctx->r2 == 0) {
        // 0x80050568: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8005058C;
    }
    // 0x80050568: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005056C: lui         $s2, 0x8006
    ctx->r18 = S32(0X8006 << 16);
    // 0x80050570: addiu       $s2, $s2, -0xA30
    ctx->r18 = ADD32(ctx->r18, -0XA30);
    // 0x80050574: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x80050578: jal         0x8004FE44
    // 0x8005057C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8004FE44(rdram, ctx);
        goto after_4;
    // 0x8005057C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80050580: sw          $s2, 0x1C0($s3)
    MEM_W(0X1C0, ctx->r19) = ctx->r18;
    // 0x80050584: b           L_800505AC
    // 0x80050588: ori         $s4, $s4, 0x1
    ctx->r20 = ctx->r20 | 0X1;
        goto L_800505AC;
    // 0x80050588: ori         $s4, $s4, 0x1
    ctx->r20 = ctx->r20 | 0X1;
L_8005058C:
    // 0x8005058C: bnel        $s4, $zero, L_800505B0
    if (ctx->r20 != 0) {
        // 0x80050590: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800505B0;
    }
    goto skip_1;
    // 0x80050590: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80050594: lbu         $t7, 0x0($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X0);
    // 0x80050598: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005059C: bnel        $t7, $zero, L_800505B0
    if (ctx->r15 != 0) {
        // 0x800505A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800505B0;
    }
    goto skip_2;
    // 0x800505A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800505A4: jal         0x8004FD3C
    // 0x800505A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004FD3C(rdram, ctx);
        goto after_5;
    // 0x800505A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
L_800505AC:
    // 0x800505AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800505B0:
    // 0x800505B0: bnel        $s0, $s6, L_80050548
    if (ctx->r16 != ctx->r22) {
        // 0x800505B4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80050548;
    }
    goto skip_3;
    // 0x800505B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_3:
    // 0x800505B8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800505BC:
    // 0x800505BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800505C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800505C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800505C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800505CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800505D0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800505D4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800505D8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800505DC: jr          $ra
    // 0x800505E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800505E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800505E4: nop

    // 0x800505E8: nop

    // 0x800505EC: nop

;}
RECOMP_FUNC void func_800080E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800080EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800080F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800080F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800080F8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800080FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80008100: jal         0x80008298
    // 0x80008104: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    func_80008298(rdram, ctx);
        goto after_0;
    // 0x80008104: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    after_0:
    // 0x80008108: bne         $v0, $zero, L_8000811C
    if (ctx->r2 != 0) {
        // 0x8000810C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8000811C;
    }
    // 0x8000810C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80008110: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80008114: b           L_80008284
    // 0x80008118: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80008284;
    // 0x80008118: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000811C:
    // 0x8000811C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80008120: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x80008124: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80008128: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8000812C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80008130: bne         $t8, $zero, L_80008144
    if (ctx->r24 != 0) {
        // 0x80008134: addiu       $t1, $t1, 0x4D10
        ctx->r9 = ADD32(ctx->r9, 0X4D10);
            goto L_80008144;
    }
    // 0x80008134: addiu       $t1, $t1, 0x4D10
    ctx->r9 = ADD32(ctx->r9, 0X4D10);
    // 0x80008138: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8000813C: b           L_80008284
    // 0x80008140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80008284;
    // 0x80008140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80008144:
    // 0x80008144: lw          $t2, 0x12C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C8);
    // 0x80008148: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000814C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80008150: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80008154: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80008158: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x8000815C: lw          $t4, 0x12DC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X12DC);
    // 0x80008160: addiu       $v1, $v1, 0x12CC
    ctx->r3 = ADD32(ctx->r3, 0X12CC);
    // 0x80008164: bnel        $t4, $at, L_80008174
    if (ctx->r12 != ctx->r1) {
        // 0x80008168: lw          $t6, 0x0($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X0);
            goto L_80008174;
    }
    goto skip_0;
    // 0x80008168: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8000816C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80008170: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
L_80008174:
    // 0x80008174: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80008178: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000817C: sw          $t6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r14;
    // 0x80008180: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80008184: sw          $t5, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r13;
    // 0x80008188: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x8000818C: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x80008190: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x80008194: sw          $s0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r16;
    // 0x80008198: sw          $t5, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r13;
    // 0x8000819C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800081A0: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x800081A4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800081A8: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x800081AC: srl         $a3, $a3, 30
    ctx->r7 = S32(U32(ctx->r7) >> 30);
    // 0x800081B0: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x800081B4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800081B8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800081BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800081C0: jal         0x8000571C
    // 0x800081C4: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    func_8000571C(rdram, ctx);
        goto after_1;
    // 0x800081C4: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    after_1:
    // 0x800081C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800081CC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800081D0: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800081D4: addiu       $t1, $t1, 0x4D10
    ctx->r9 = ADD32(ctx->r9, 0X4D10);
    // 0x800081D8: bne         $v0, $zero, L_8000821C
    if (ctx->r2 != 0) {
        // 0x800081DC: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_8000821C;
    }
    // 0x800081DC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800081E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800081E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800081E8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800081EC: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x800081F0: beq         $t8, $at, L_80008204
    if (ctx->r24 == ctx->r1) {
        // 0x800081F4: srl         $t9, $v0, 28
        ctx->r25 = S32(U32(ctx->r2) >> 28);
            goto L_80008204;
    }
    // 0x800081F4: srl         $t9, $v0, 28
    ctx->r25 = S32(U32(ctx->r2) >> 28);
    // 0x800081F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800081FC: bne         $t9, $at, L_80008210
    if (ctx->r25 != ctx->r1) {
        // 0x80008200: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80008210;
    }
    // 0x80008200: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_80008204:
    // 0x80008204: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80008208: b           L_80008284
    // 0x8000820C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80008284;
    // 0x8000820C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80008210:
    // 0x80008210: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x80008214: b           L_80008284
    // 0x80008218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80008284;
    // 0x80008218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000821C:
    // 0x8000821C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80008220: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x80008224: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80008228: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000822C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80008230: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80008234: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80008238: addiu       $t6, $t5, 0xF
    ctx->r14 = ADD32(ctx->r13, 0XF);
    // 0x8000823C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80008240: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80008244: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x80008248: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8000824C: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x80008250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008254: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80008258: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8000825C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80008260: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x80008264: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x80008268: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8000826C: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
    // 0x80008270: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80008274: sb          $t6, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r14;
    // 0x80008278: lw          $t7, 0x12C8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X12C8);
    // 0x8000827C: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80008280: sw          $t8, 0x12C8($t1)
    MEM_W(0X12C8, ctx->r9) = ctx->r24;
L_80008284:
    // 0x80008284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008288: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000828C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80008290: jr          $ra
    // 0x80008294: nop

    return;
    // 0x80008294: nop

;}
RECOMP_FUNC void func_8000BC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BC18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BC1C: jal         0x8000B9C0
    // 0x8000BC20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8000B9C0(rdram, ctx);
        goto after_0;
    // 0x8000BC20: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x8000BC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000BC2C: jr          $ra
    // 0x8000BC30: nop

    return;
    // 0x8000BC30: nop

;}
RECOMP_FUNC void func_8064ADB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064ADB8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064ADBC: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0XB68) << 16);
    // 0x8064ADC0: addiu       $t6, $t6, -0x53C8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0XB68));
    // 0x8064ADC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064ADC8: jr          $ra
    // 0x8064ADCC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064ADCC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8043EF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043EF80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043EF84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043EF88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043EF8C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x8043EF90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043EF94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043EF98: bne         $t6, $at, L_8043EFC4
    if (ctx->r14 != ctx->r1) {
        // 0x8043EF9C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8043EFC4;
    }
    // 0x8043EF9C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8043EFA0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8043EFA4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8043EFA8: jal         0x80067D5C
    // 0x8043EFAC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8043EFAC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8043EFB0: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x8043EFB4: jal         0x80067F78
    // 0x8043EFB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8043EFB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8043EFBC: b           L_8043EFE4
    // 0x8043EFC0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8043EFE4;
    // 0x8043EFC0: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_8043EFC4:
    // 0x8043EFC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8043EFC8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8043EFCC: jal         0x80067D5C
    // 0x8043EFD0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x8043EFD0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8043EFD4: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x8043EFD8: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043EFDC: jal         0x800678F0
    // 0x8043EFE0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8043EFE0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_8043EFE4:
    // 0x8043EFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043EFE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043EFEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043EFF0: jr          $ra
    // 0x8043EFF4: nop

    return;
    // 0x8043EFF4: nop

;}
RECOMP_FUNC void func_807BAB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAB94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BAB98: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807BAB9C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807BABA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807BABA4: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x807BABA8: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807BABAC: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x807BABB0: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x807BABB4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x807BABB8: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x807BABBC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x807BABC0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x807BABC4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807BABC8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x807BABCC: jr          $ra
    // 0x807BABD0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x807BABD0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8044A644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A644: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044A648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A64C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044A650: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A654: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A658: lw          $a1, 0x6A4C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A4C);
    // 0x8044A65C: beq         $a1, $zero, L_8044A674
    if (ctx->r5 == 0) {
        // 0x8044A660: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A674;
    }
    // 0x8044A660: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A664: jal         0x80050A2C
    // 0x8044A668: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044A668: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044A66C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A670: sw          $zero, 0x6A4C($v1)
    MEM_W(0X6A4C, ctx->r3) = 0;
L_8044A674:
    // 0x8044A674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A678: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044A67C: jr          $ra
    // 0x8044A680: nop

    return;
    // 0x8044A680: nop

;}
RECOMP_FUNC void func_8066A1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A1B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A1B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A1BC: jal         0x80669E80
    // 0x8066A1C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A1C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A1C4: jal         0x80669FA4
    // 0x8066A1C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A1C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066A1CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A1D0: addiu       $at, $zero, 0x4555
    ctx->r1 = ADD32(0, 0X4555);
    // 0x8066A1D4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8066A1D8: beq         $v0, $at, L_8066A1F0
    if (ctx->r2 == ctx->r1) {
        // 0x8066A1DC: addiu       $at, $zero, 0x455B
        ctx->r1 = ADD32(0, 0X455B);
            goto L_8066A1F0;
    }
    // 0x8066A1DC: addiu       $at, $zero, 0x455B
    ctx->r1 = ADD32(0, 0X455B);
    // 0x8066A1E0: beq         $v0, $at, L_8066A220
    if (ctx->r2 == ctx->r1) {
        // 0x8066A1E4: addiu       $at, $zero, 0x455C
        ctx->r1 = ADD32(0, 0X455C);
            goto L_8066A220;
    }
    // 0x8066A1E4: addiu       $at, $zero, 0x455C
    ctx->r1 = ADD32(0, 0X455C);
    // 0x8066A1E8: bnel        $v0, $at, L_8066A224
    if (ctx->r2 != ctx->r1) {
        // 0x8066A1EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A224;
    }
    goto skip_0;
    // 0x8066A1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8066A1F0:
    // 0x8066A1F0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8066A1F4: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8066A1F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A1FC: blez        $v0, L_8066A210
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8066A200: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8066A210;
    }
    // 0x8066A200: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8066A204: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8066A208: b           L_8066A220
    // 0x8066A20C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8066A220;
    // 0x8066A20C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8066A210:
    // 0x8066A210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8066A214: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8066A218: jal         0x8066A790
    // 0x8066A21C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A21C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_2:
L_8066A220:
    // 0x8066A220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A224:
    // 0x8066A224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A228: jr          $ra
    // 0x8066A22C: nop

    return;
    // 0x8066A22C: nop

;}
RECOMP_FUNC void func_804A3A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3A9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804A3AA0: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x804A3AA4: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x804A3AA8: jr          $ra
    // 0x804A3AAC: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    return;
    // 0x804A3AAC: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8044BE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BE84: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8044BE88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044BE8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8044BE90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8044BE94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8044BE98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8044BE9C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8044BEA0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8044BEA4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8044BEA8: lh          $a1, 0x4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X4);
    // 0x8044BEAC: jal         0x8044BE74
    // 0x8044BEB0: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    func_8044BE74(rdram, ctx);
        goto after_0;
    // 0x8044BEB0: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    after_0:
    // 0x8044BEB4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8044BEB8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8044BEBC: sh          $t6, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r14;
    // 0x8044BEC0: lh          $a1, 0x6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6);
    // 0x8044BEC4: jal         0x8044BE74
    // 0x8044BEC8: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    func_8044BE74(rdram, ctx);
        goto after_1;
    // 0x8044BEC8: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    after_1:
    // 0x8044BECC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8044BED0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x8044BED4: sh          $t7, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r15;
    // 0x8044BED8: lh          $a1, 0x8($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X8);
    // 0x8044BEDC: jal         0x8044BE74
    // 0x8044BEE0: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    func_8044BE74(rdram, ctx);
        goto after_2;
    // 0x8044BEE0: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    after_2:
    // 0x8044BEE4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8044BEE8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8044BEEC: sh          $t8, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r24;
    // 0x8044BEF0: lh          $a1, 0xA($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XA);
    // 0x8044BEF4: jal         0x8044BE74
    // 0x8044BEF8: lh          $a0, 0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA);
    func_8044BE74(rdram, ctx);
        goto after_3;
    // 0x8044BEF8: lh          $a0, 0xA($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XA);
    after_3:
    // 0x8044BEFC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8044BF00: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8044BF04: sh          $t9, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r25;
    // 0x8044BF08: lh          $a1, 0xC($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XC);
    // 0x8044BF0C: jal         0x8044BE74
    // 0x8044BF10: lh          $a0, 0xC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC);
    func_8044BE74(rdram, ctx);
        goto after_4;
    // 0x8044BF10: lh          $a0, 0xC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC);
    after_4:
    // 0x8044BF14: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8044BF18: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8044BF1C: sh          $t0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r8;
    // 0x8044BF20: lh          $a1, 0xE($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XE);
    // 0x8044BF24: jal         0x8044BE74
    // 0x8044BF28: lh          $a0, 0xE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XE);
    func_8044BE74(rdram, ctx);
        goto after_5;
    // 0x8044BF28: lh          $a0, 0xE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XE);
    after_5:
    // 0x8044BF2C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8044BF30: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8044BF34: sh          $t1, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r9;
    // 0x8044BF38: lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X2);
    // 0x8044BF3C: jal         0x8044BE74
    // 0x8044BF40: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_8044BE74(rdram, ctx);
        goto after_6;
    // 0x8044BF40: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_6:
    // 0x8044BF44: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8044BF48: slti        $at, $v0, 0xB5
    ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
    // 0x8044BF4C: bnel        $at, $zero, L_8044BF64
    if (ctx->r1 != 0) {
        // 0x8044BF50: slti        $at, $v0, -0xB4
        ctx->r1 = SIGNED(ctx->r2) < -0XB4 ? 1 : 0;
            goto L_8044BF64;
    }
    goto skip_0;
    // 0x8044BF50: slti        $at, $v0, -0xB4
    ctx->r1 = SIGNED(ctx->r2) < -0XB4 ? 1 : 0;
    skip_0:
    // 0x8044BF54: addiu       $v0, $v0, -0x168
    ctx->r2 = ADD32(ctx->r2, -0X168);
    // 0x8044BF58: b           L_8044BF70
    // 0x8044BF5C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_8044BF70;
    // 0x8044BF5C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8044BF60: slti        $at, $v0, -0xB4
    ctx->r1 = SIGNED(ctx->r2) < -0XB4 ? 1 : 0;
L_8044BF64:
    // 0x8044BF64: beq         $at, $zero, L_8044BF70
    if (ctx->r1 == 0) {
        // 0x8044BF68: addiu       $v0, $v0, 0x168
        ctx->r2 = ADD32(ctx->r2, 0X168);
            goto L_8044BF70;
    }
    // 0x8044BF68: addiu       $v0, $v0, 0x168
    ctx->r2 = ADD32(ctx->r2, 0X168);
    // 0x8044BF6C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8044BF70:
    // 0x8044BF70: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8044BF74: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8044BF78: sh          $t2, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r10;
    // 0x8044BF7C: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8044BF80: jal         0x8044BE74
    // 0x8044BF84: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    func_8044BE74(rdram, ctx);
        goto after_7;
    // 0x8044BF84: lh          $a0, 0x10($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X10);
    after_7:
    // 0x8044BF88: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8044BF8C: sh          $t3, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r11;
    // 0x8044BF90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044BF94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8044BF98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8044BF9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8044BFA0: jr          $ra
    // 0x8044BFA4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8044BFA4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_805D2A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2A80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D2A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D2A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D2A8C: jal         0x8004700C
    // 0x805D2A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D2A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D2A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2A98: jal         0x80062D14
    // 0x805D2A9C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805D2A9C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x805D2AA0: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x805D2AA4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805D2AA8: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x805D2AAC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805D2AB0: bne         $t7, $at, L_805D2BD0
    if (ctx->r15 != ctx->r1) {
        // 0x805D2AB4: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_805D2BD0;
    }
    // 0x805D2AB4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x805D2AB8: beql        $v1, $zero, L_805D2BD4
    if (ctx->r3 == 0) {
        // 0x805D2ABC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2BD4;
    }
    goto skip_0;
    // 0x805D2ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D2AC0: beq         $v1, $zero, L_805D2AE8
    if (ctx->r3 == 0) {
        // 0x805D2AC4: sw          $zero, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = 0;
            goto L_805D2AE8;
    }
    // 0x805D2AC4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805D2AC8: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x805D2ACC: slti        $at, $t9, 0xA0
    ctx->r1 = SIGNED(ctx->r25) < 0XA0 ? 1 : 0;
    // 0x805D2AD0: beq         $at, $zero, L_805D2AE0
    if (ctx->r1 == 0) {
        // 0x805D2AD4: nop
    
            goto L_805D2AE0;
    }
    // 0x805D2AD4: nop

    // 0x805D2AD8: b           L_805D2AF4
    // 0x805D2ADC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D2AF4;
    // 0x805D2ADC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D2AE0:
    // 0x805D2AE0: b           L_805D2AF4
    // 0x805D2AE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_805D2AF4;
    // 0x805D2AE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_805D2AE8:
    // 0x805D2AE8: jal         0x800653D8
    // 0x805D2AEC: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805D2AEC: nop

    after_2:
    // 0x805D2AF0: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
L_805D2AF4:
    // 0x805D2AF4: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805D2AF8: jal         0x805D1E54
    // 0x805D2AFC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805D1E54(rdram, ctx);
        goto after_3;
    // 0x805D2AFC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x805D2B00: beq         $v0, $zero, L_805D2BD0
    if (ctx->r2 == 0) {
        // 0x805D2B04: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805D2BD0;
    }
    // 0x805D2B04: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2B08: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x805D2B0C: jal         0x800653D8
    // 0x805D2B10: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805D2B10: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x805D2B14: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x805D2B18: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x805D2B1C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805D2B20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2B24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D2B28: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805D2B2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2B30: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805D2B34: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2B38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805D2B3C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D2B40: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805D2B44: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D2B48: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x805D2B4C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D2B50: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805D2B54: beq         $v1, $zero, L_805D2B80
    if (ctx->r3 == 0) {
        // 0x805D2B58: swc1        $f0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
            goto L_805D2B80;
    }
    // 0x805D2B58: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x805D2B5C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805D2B60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D2B64: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2B68: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2B6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805D2B70: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805D2B74: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805D2B78: b           L_805D2B9C
    // 0x805D2B7C: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
        goto L_805D2B9C;
    // 0x805D2B7C: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
L_805D2B80:
    // 0x805D2B80: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805D2B84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D2B88: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805D2B8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805D2B90: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805D2B94: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805D2B98: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
L_805D2B9C:
    // 0x805D2B9C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x805D2BA0: jal         0x805D354C
    // 0x805D2BA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_805D354C(rdram, ctx);
        goto after_5;
    // 0x805D2BA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_5:
    // 0x805D2BA8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805D2BAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805D2BB0: beq         $v1, $zero, L_805D2BC8
    if (ctx->r3 == 0) {
        // 0x805D2BB4: nop
    
            goto L_805D2BC8;
    }
    // 0x805D2BB4: nop

    // 0x805D2BB8: jal         0x805D1CC0
    // 0x805D2BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805D1CC0(rdram, ctx);
        goto after_6;
    // 0x805D2BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x805D2BC0: b           L_805D2BD4
    // 0x805D2BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805D2BD4;
    // 0x805D2BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2BC8:
    // 0x805D2BC8: jal         0x805D1CC0
    // 0x805D2BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805D1CC0(rdram, ctx);
        goto after_7;
    // 0x805D2BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_805D2BD0:
    // 0x805D2BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2BD4:
    // 0x805D2BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D2BDC: jr          $ra
    // 0x805D2BE0: nop

    return;
    // 0x805D2BE0: nop

;}
RECOMP_FUNC void func_8007B5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B5B0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8007B5B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007B5B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8007B5BC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8007B5C0: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8007B5C4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8007B5C8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8007B5CC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8007B5D0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8007B5D4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007B5D8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007B5DC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007B5E0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8007B5E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8007B5E8: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8007B5EC: lw          $t6, 0x1C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X1C);
    // 0x8007B5F0: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
    // 0x8007B5F4: lw          $t5, 0x10($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X10);
    // 0x8007B5F8: lui         $a1, 0xF0A
    ctx->r5 = S32(0XF0A << 16);
    // 0x8007B5FC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B600: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8007B604: lui         $fp, 0x1000
    ctx->r30 = S32(0X1000 << 16);
    // 0x8007B608: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x8007B60C: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x8007B610: lui         $s6, 0xB300
    ctx->r22 = S32(0XB300 << 16);
    // 0x8007B614: lui         $s5, 0xB400
    ctx->r21 = S32(0XB400 << 16);
    // 0x8007B618: lui         $s4, 0xE400
    ctx->r20 = S32(0XE400 << 16);
    // 0x8007B61C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007B620: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007B624: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x8007B628: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x8007B62C: lwc1        $f20, 0x0($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8007B630: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x8007B634: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B638: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007B63C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007B640: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007B644: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B648: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B64C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8007B650: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x8007B654: addiu       $t9, $zero, 0xCF0
    ctx->r25 = ADD32(0, 0XCF0);
    // 0x8007B658: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007B65C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007B660: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B664: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007B668: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8007B66C: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8007B670: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007B674: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8007B678: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B67C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B680: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8007B684: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8007B688: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B68C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8007B690: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B694: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B698: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x8007B69C: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x8007B6A0: ori         $t5, $t5, 0xFC7E
    ctx->r13 = ctx->r13 | 0XFC7E;
    // 0x8007B6A4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8007B6A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007B6AC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007B6B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B6B4: lw          $a1, 0x1C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1C);
    // 0x8007B6B8: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x8007B6BC: lw          $v0, 0x20($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X20);
    // 0x8007B6C0: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8007B6C4: div         $zero, $t6, $t9
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r25)));
    // 0x8007B6C8: bne         $t9, $zero, L_8007B6D4
    if (ctx->r25 != 0) {
        // 0x8007B6CC: nop
    
            goto L_8007B6D4;
    }
    // 0x8007B6CC: nop

    // 0x8007B6D0: break       7
    do_break(2147989200);
L_8007B6D4:
    // 0x8007B6D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B6D8: bne         $t9, $at, L_8007B6EC
    if (ctx->r25 != ctx->r1) {
        // 0x8007B6DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007B6EC;
    }
    // 0x8007B6DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007B6E0: bne         $t6, $at, L_8007B6EC
    if (ctx->r14 != ctx->r1) {
        // 0x8007B6E4: nop
    
            goto L_8007B6EC;
    }
    // 0x8007B6E4: nop

    // 0x8007B6E8: break       6
    do_break(2147989224);
L_8007B6EC:
    // 0x8007B6EC: mflo        $s7
    ctx->r23 = lo;
    // 0x8007B6F0: lw          $s1, 0xC($s3)
    ctx->r17 = MEM_W(ctx->r19, 0XC);
    // 0x8007B6F4: blez        $v0, L_8007BA18
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B6F8: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_8007BA18;
    }
    // 0x8007B6F8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8007B6FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8007B700: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8007B704:
    // 0x8007B704: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8007B708: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8007B70C: andi        $t4, $t4, 0xFFF
    ctx->r12 = ctx->r12 & 0XFFF;
    // 0x8007B710: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007B714: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
    // 0x8007B718: addu        $t3, $s1, $s7
    ctx->r11 = ADD32(ctx->r17, ctx->r23);
    // 0x8007B71C: slt         $at, $t7, $s7
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8007B720: addiu       $t2, $a1, -0x1
    ctx->r10 = ADD32(ctx->r5, -0X1);
    // 0x8007B724: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8007B728: beq         $at, $zero, L_8007B734
    if (ctx->r1 == 0) {
        // 0x8007B72C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8007B734;
    }
    // 0x8007B72C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8007B730: or          $s7, $t7, $zero
    ctx->r23 = ctx->r15 | 0;
L_8007B734:
    // 0x8007B734: addiu       $t1, $s7, -0x1
    ctx->r9 = ADD32(ctx->r23, -0X1);
    // 0x8007B738: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007B73C: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x8007B740: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x8007B744: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x8007B748: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x8007B74C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B750: andi        $t5, $t8, 0x7
    ctx->r13 = ctx->r24 & 0X7;
    // 0x8007B754: sll         $t6, $t5, 21
    ctx->r14 = S32(ctx->r13 << 21);
    // 0x8007B758: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007B75C: or          $t7, $t9, $a3
    ctx->r15 = ctx->r25 | ctx->r7;
    // 0x8007B760: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B764: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x8007B768: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B76C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007B770: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007B774: lw          $t5, 0x14($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X14);
    // 0x8007B778: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007B77C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B780: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8007B784: sll         $t9, $t6, 21
    ctx->r25 = S32(ctx->r14 << 21);
    // 0x8007B788: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8007B78C: lui         $t5, 0x708
    ctx->r13 = S32(0X708 << 16);
    // 0x8007B790: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8007B794: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x8007B798: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007B79C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8007B7A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B7A4: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007B7A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007B7AC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007B7B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B7B4: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8007B7B8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007B7BC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007B7C0: lw          $a1, 0x1C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1C);
    // 0x8007B7C4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B7C8: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8007B7CC: multu       $a1, $s7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B7D0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8007B7D4: mflo        $a2
    ctx->r6 = lo;
    // 0x8007B7D8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8007B7DC: slti        $at, $a2, 0x7FF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FF ? 1 : 0;
    // 0x8007B7E0: beq         $at, $zero, L_8007B7F0
    if (ctx->r1 == 0) {
        // 0x8007B7E4: nop
    
            goto L_8007B7F0;
    }
    // 0x8007B7E4: nop

    // 0x8007B7E8: b           L_8007B7F0
    // 0x8007B7EC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
        goto L_8007B7F0;
    // 0x8007B7EC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8007B7F0:
    // 0x8007B7F0: bgez        $v0, L_8007B7FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007B7F4: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_8007B7FC;
    }
    // 0x8007B7F4: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x8007B7F8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
L_8007B7FC:
    // 0x8007B7FC: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
    // 0x8007B800: bgtz        $v0, L_8007B810
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007B804: andi        $t9, $a3, 0xFFF
        ctx->r25 = ctx->r7 & 0XFFF;
            goto L_8007B810;
    }
    // 0x8007B804: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x8007B808: b           L_8007B814
    // 0x8007B80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8007B814;
    // 0x8007B80C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8007B810:
    // 0x8007B810: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8007B814:
    // 0x8007B814: bgtz        $v0, L_8007B824
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007B818: addiu       $t7, $a2, 0x7FF
        ctx->r15 = ADD32(ctx->r6, 0X7FF);
            goto L_8007B824;
    }
    // 0x8007B818: addiu       $t7, $a2, 0x7FF
    ctx->r15 = ADD32(ctx->r6, 0X7FF);
    // 0x8007B81C: b           L_8007B828
    // 0x8007B820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8007B828;
    // 0x8007B820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007B824:
    // 0x8007B824: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8007B828:
    // 0x8007B828: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8007B82C: bne         $a1, $zero, L_8007B838
    if (ctx->r5 != 0) {
        // 0x8007B830: nop
    
            goto L_8007B838;
    }
    // 0x8007B830: nop

    // 0x8007B834: break       7
    do_break(2147989556);
L_8007B838:
    // 0x8007B838: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B83C: bne         $a1, $at, L_8007B850
    if (ctx->r5 != ctx->r1) {
        // 0x8007B840: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007B850;
    }
    // 0x8007B840: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007B844: bne         $t7, $at, L_8007B850
    if (ctx->r15 != ctx->r1) {
        // 0x8007B848: nop
    
            goto L_8007B850;
    }
    // 0x8007B848: nop

    // 0x8007B84C: break       6
    do_break(2147989580);
L_8007B850:
    // 0x8007B850: mflo        $t8
    ctx->r24 = lo;
    // 0x8007B854: andi        $t5, $t8, 0xFFF
    ctx->r13 = ctx->r24 & 0XFFF;
    // 0x8007B858: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007B85C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8007B860: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007B864: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8007B868: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007B86C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B870: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8007B874: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007B878: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007B87C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B880: lw          $t9, 0x14($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X14);
    // 0x8007B884: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007B888: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007B88C: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x8007B890: lw          $t9, 0x1C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X1C);
    // 0x8007B894: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x8007B898: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007B89C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x8007B8A0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8007B8A4: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x8007B8A8: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x8007B8AC: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007B8B0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8007B8B4: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x8007B8B8: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8007B8BC: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8007B8C0: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8007B8C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007B8C8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007B8CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B8D4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007B8D8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B8DC: lw          $t5, 0x1C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X1C);
    // 0x8007B8E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B8E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B8E8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007B8EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007B8F0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007B8F4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007B8F8: or          $t5, $t9, $t1
    ctx->r13 = ctx->r25 | ctx->r9;
    // 0x8007B8FC: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8007B900: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8007B904: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007B908: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8007B90C: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x8007B910: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8007B914: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8007B918: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007B91C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B920: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007B924: blezl       $s7, L_8007B9F0
    if (SIGNED(ctx->r23) <= 0) {
        // 0x8007B928: lw          $a1, 0x1C($s3)
        ctx->r5 = MEM_W(ctx->r19, 0X1C);
            goto L_8007B9F0;
    }
    goto skip_0;
    // 0x8007B928: lw          $a1, 0x1C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1C);
    skip_0:
L_8007B92C:
    // 0x8007B92C: jal         0x80082730
    // 0x8007B930: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    fsin(rdram, ctx);
        goto after_0;
    // 0x8007B930: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8007B934: lwc1        $f4, 0x8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8007B938: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007B93C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007B940: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007B944: nop

    // 0x8007B948: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8007B94C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8007B950: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8007B954: nop

    // 0x8007B958: beq         $a1, $zero, L_8007B9DC
    if (ctx->r5 == 0) {
        // 0x8007B95C: nop
    
            goto L_8007B9DC;
    }
    // 0x8007B95C: nop

    // 0x8007B960: lw          $a3, 0x1C($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X1C);
    // 0x8007B964: sll         $a2, $s1, 2
    ctx->r6 = S32(ctx->r17 << 2);
    // 0x8007B968: andi        $a2, $a2, 0xFFF
    ctx->r6 = ctx->r6 & 0XFFF;
    // 0x8007B96C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8007B970: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x8007B974: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007B978: andi        $t5, $t8, 0xFFF
    ctx->r13 = ctx->r24 & 0XFFF;
    // 0x8007B97C: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x8007B980: addiu       $t9, $s1, 0x1
    ctx->r25 = ADD32(ctx->r17, 0X1);
    // 0x8007B984: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007B988: andi        $t5, $t8, 0xFFF
    ctx->r13 = ctx->r24 & 0XFFF;
    // 0x8007B98C: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x8007B990: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x8007B994: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007B998: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B99C: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8007B9A0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007B9A4: negu        $t8, $a1
    ctx->r24 = SUB32(0, ctx->r5);
    // 0x8007B9A8: sll         $t5, $s1, 5
    ctx->r13 = S32(ctx->r17 << 5);
    // 0x8007B9AC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8007B9B0: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8007B9B4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007B9B8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007B9BC: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8007B9C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007B9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B9C8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8007B9CC: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8007B9D0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007B9D4: sw          $s6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r22;
    // 0x8007B9D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8007B9DC:
    // 0x8007B9DC: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8007B9E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B9E4: bne         $s2, $s7, L_8007B92C
    if (ctx->r18 != ctx->r23) {
        // 0x8007B9E8: add.s       $f20, $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
            goto L_8007B92C;
    }
    // 0x8007B9E8: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x8007B9EC: lw          $a1, 0x1C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1C);
L_8007B9F0:
    // 0x8007B9F0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8007B9F4: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8007B9F8: multu       $a1, $s7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B9FC: subu        $v0, $v0, $s7
    ctx->r2 = SUB32(ctx->r2, ctx->r23);
    // 0x8007BA00: mflo        $t7
    ctx->r15 = lo;
    // 0x8007BA04: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8007BA08: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x8007BA0C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x8007BA10: bgtz        $v0, L_8007B704
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007BA14: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_8007B704;
    }
    // 0x8007BA14: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8007BA18:
    // 0x8007BA18: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8007BA1C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007BA20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BA24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BA28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8007BA2C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8007BA30: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x8007BA34: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8007BA38: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8007BA3C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8007BA40: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007BA44: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007BA48: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007BA4C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007BA50: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8007BA54: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BA58: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8007BA5C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8007BA60: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8007BA64: jr          $ra
    // 0x8007BA68: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8007BA68: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8042B18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042B18C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8042B190: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8042B194: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042B198: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8042B19C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8042B1A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8042B1A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8042B1A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042B1AC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8042B1B0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8042B1B4: jal         0x80064D1C
    // 0x8042B1B8: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8042B1B8: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x8042B1BC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8042B1C0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8042B1C4: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8042B1C8: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x8042B1CC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8042B1D0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8042B1D4: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x8042B1D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8042B1DC: sw          $t7, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r15;
    // 0x8042B1E0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8042B1E4: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8042B1E8: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8042B1EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8042B1F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8042B1F4: sw          $a3, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r7;
    // 0x8042B1F8: sw          $t0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r8;
    // 0x8042B1FC: sw          $s3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r19;
    // 0x8042B200: blez        $s0, L_8042B230
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8042B204: sw          $t8, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r24;
            goto L_8042B230;
    }
    // 0x8042B204: sw          $t8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r24;
    // 0x8042B208: lw          $a2, 0x3C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X3C);
    // 0x8042B20C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8042B210: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8042B214: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8042B218: addu        $a1, $t9, $a3
    ctx->r5 = ADD32(ctx->r25, ctx->r7);
L_8042B21C:
    // 0x8042B21C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8042B220: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042B224: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8042B228: bne         $at, $zero, L_8042B21C
    if (ctx->r1 != 0) {
        // 0x8042B22C: addu        $a0, $a0, $t2
        ctx->r4 = ADD32(ctx->r4, ctx->r10);
            goto L_8042B21C;
    }
    // 0x8042B22C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
L_8042B230:
    // 0x8042B230: blez        $a0, L_8042B2BC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8042B234: sw          $zero, 0x4C($v0)
        MEM_W(0X4C, ctx->r2) = 0;
            goto L_8042B2BC;
    }
    // 0x8042B234: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    // 0x8042B238: andi        $a2, $a0, 0x3
    ctx->r6 = ctx->r4 & 0X3;
    // 0x8042B23C: beq         $a2, $zero, L_8042B26C
    if (ctx->r6 == 0) {
        // 0x8042B240: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8042B26C;
    }
    // 0x8042B240: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8042B244: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8042B248: addu        $v1, $t0, $t3
    ctx->r3 = ADD32(ctx->r8, ctx->r11);
L_8042B24C:
    // 0x8042B24C: lw          $t4, 0x4C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4C);
    // 0x8042B250: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8042B254: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8042B258: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8042B25C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8042B260: bne         $a1, $s1, L_8042B24C
    if (ctx->r5 != ctx->r17) {
        // 0x8042B264: sw          $t6, 0x4C($v0)
        MEM_W(0X4C, ctx->r2) = ctx->r14;
            goto L_8042B24C;
    }
    // 0x8042B264: sw          $t6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r14;
    // 0x8042B268: beq         $s1, $a0, L_8042B2B8
    if (ctx->r17 == ctx->r4) {
        // 0x8042B26C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8042B2B8;
    }
L_8042B26C:
    // 0x8042B26C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8042B270: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8042B274: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x8042B278: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
L_8042B27C:
    // 0x8042B27C: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8042B280: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8042B284: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8042B288: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8042B28C: sw          $t3, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r11;
    // 0x8042B290: lw          $t5, -0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, -0XC);
    // 0x8042B294: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8042B298: sw          $t6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r14;
    // 0x8042B29C: lw          $t8, -0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X8);
    // 0x8042B2A0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8042B2A4: sw          $t9, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r25;
    // 0x8042B2A8: lw          $t3, -0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X4);
    // 0x8042B2AC: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8042B2B0: bne         $v1, $a1, L_8042B27C
    if (ctx->r3 != ctx->r5) {
        // 0x8042B2B4: sw          $t4, 0x4C($v0)
        MEM_W(0X4C, ctx->r2) = ctx->r12;
            goto L_8042B27C;
    }
    // 0x8042B2B4: sw          $t4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r12;
L_8042B2B8:
    // 0x8042B2B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8042B2BC:
    // 0x8042B2BC: lw          $t5, 0x4C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4C);
    // 0x8042B2C0: lw          $t6, 0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3C);
    // 0x8042B2C4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8042B2C8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8042B2CC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8042B2D0: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x8042B2D4: sw          $t8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r24;
    // 0x8042B2D8: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x8042B2DC: blez        $s3, L_8042B304
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8042B2E0: sw          $t3, 0x4C($v0)
        MEM_W(0X4C, ctx->r2) = ctx->r11;
            goto L_8042B304;
    }
    // 0x8042B2E0: sw          $t3, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r11;
L_8042B2E4:
    // 0x8042B2E4: lw          $a0, 0x4C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4C);
    // 0x8042B2E8: jal         0x80064D1C
    // 0x8042B2EC: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8042B2EC: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    after_1:
    // 0x8042B2F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8042B2F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042B2F8: bne         $s1, $s3, L_8042B2E4
    if (ctx->r17 != ctx->r19) {
        // 0x8042B2FC: sw          $v0, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r2;
            goto L_8042B2E4;
    }
    // 0x8042B2FC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8042B300: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8042B304:
    // 0x8042B304: lw          $a2, 0x3C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X3C);
    // 0x8042B308: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8042B30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042B310: blez        $a2, L_8042B378
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8042B314: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8042B378;
    }
    // 0x8042B314: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8042B318: lw          $t0, 0x44($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X44);
    // 0x8042B31C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
L_8042B320:
    // 0x8042B320: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8042B324: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8042B328: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x8042B32C: blez        $a2, L_8042B368
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8042B330: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8042B368;
    }
    // 0x8042B330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042B334: lw          $t4, 0x48($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X48);
    // 0x8042B338: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8042B33C: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
L_8042B340:
    // 0x8042B340: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8042B344: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8042B348: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8042B34C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8042B350: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8042B354: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8042B358: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8042B35C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8042B360: bne         $at, $zero, L_8042B340
    if (ctx->r1 != 0) {
        // 0x8042B364: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8042B340;
    }
    // 0x8042B364: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8042B368:
    // 0x8042B368: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8042B36C: bne         $at, $zero, L_8042B320
    if (ctx->r1 != 0) {
        // 0x8042B370: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8042B320;
    }
    // 0x8042B370: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8042B374: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8042B378:
    // 0x8042B378: blez        $s3, L_8042B3A4
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8042B37C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8042B3A4;
    }
    // 0x8042B37C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8042B380: sll         $a1, $a0, 3
    ctx->r5 = S32(ctx->r4 << 3);
    // 0x8042B384: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8042B388: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8042B38C:
    // 0x8042B38C: jal         0x80064D1C
    // 0x8042B390: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x8042B390: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8042B394: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8042B398: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042B39C: bne         $s1, $s3, L_8042B38C
    if (ctx->r17 != ctx->r19) {
        // 0x8042B3A0: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8042B38C;
    }
    // 0x8042B3A0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8042B3A4:
    // 0x8042B3A4: jal         0x80064D1C
    // 0x8042B3A8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x8042B3A8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x8042B3AC: lw          $a0, 0x4C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4C);
    // 0x8042B3B0: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x8042B3B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8042B3B8: jal         0x80064D1C
    // 0x8042B3BC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_4;
    // 0x8042B3BC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_4:
    // 0x8042B3C0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8042B3C4: lw          $a0, 0x4C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4C);
    // 0x8042B3C8: jal         0x80064D1C
    // 0x8042B3CC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_5;
    // 0x8042B3CC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_5:
    // 0x8042B3D0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8042B3D4: lw          $a0, 0x4C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4C);
    // 0x8042B3D8: jal         0x80064D1C
    // 0x8042B3DC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_6;
    // 0x8042B3DC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_6:
    // 0x8042B3E0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8042B3E4: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8042B3E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8042B3EC: jal         0x8042AA04
    // 0x8042B3F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8042AA04(rdram, ctx);
        goto after_7;
    // 0x8042B3F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x8042B3F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8042B3F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042B3FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042B400: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8042B404: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8042B408: jr          $ra
    // 0x8042B40C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8042B40C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80006C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006C44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80006C48: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006C50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80006C54: jal         0x800073BC
    // 0x80006C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006C5C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80006C60: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x80006C64: lw          $v1, 0x1D70($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1D70);
    // 0x80006C68: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006C6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80006C70: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006C74: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x80006C78: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x80006C7C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80006C80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80006C84: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80006C88: bne         $t9, $zero, L_80006C98
    if (ctx->r25 != 0) {
        // 0x80006C8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006C98;
    }
    // 0x80006C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006C90: b           L_80006CA0
    // 0x80006C94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80006CA0;
    // 0x80006C94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006C98:
    // 0x80006C98: lw          $t1, 0x1D70($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X1D70);
    // 0x80006C9C: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
L_80006CA0:
    // 0x80006CA0: jr          $ra
    // 0x80006CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804A3E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3E6C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A3E70: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A3E74: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A3E78: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A3E7C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A3E80: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A3E84: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A3E88: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A3E8C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A3E90: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A3E94: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A3E98: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A3E9C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A3EA0: lwc1        $f26, 0x3C($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A3EA4: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A3EA8: lwc1        $f28, 0x40($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A3EAC: bne         $s0, $zero, L_804A3EBC
    if (ctx->r16 != 0) {
        // 0x804A3EB0: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A3EBC;
    }
    // 0x804A3EB0: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A3EB4: b           L_804A3F5C
    // 0x804A3EB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A3F5C;
    // 0x804A3EB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A3EBC:
    // 0x804A3EBC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3EC0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A3EC4: beq         $s1, $zero, L_804A3F38
    if (ctx->r17 == 0) {
        // 0x804A3EC8: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A3F38;
    }
    // 0x804A3EC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A3ECC:
    // 0x804A3ECC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A3ED0: beq         $v0, $zero, L_804A3F30
    if (ctx->r2 == 0) {
        // 0x804A3ED4: nop
    
            goto L_804A3F30;
    }
    // 0x804A3ED4: nop

    // 0x804A3ED8: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A3EDC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A3EE0: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A3EE4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x804A3EE8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A3EEC: bc1f        L_804A3F30
    if (!c1cs) {
        // 0x804A3EF0: nop
    
            goto L_804A3F30;
    }
    // 0x804A3EF0: nop

    // 0x804A3EF4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x804A3EF8: lwc1        $f20, 0x40($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A3EFC: jal         0x804A3C08
    // 0x804A3F00: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A3F00: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x804A3F04: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A3F08: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x804A3F0C: jal         0x804A3C08
    // 0x804A3F10: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A3F10: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A3F14: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A3F18: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A3F1C: nop

    // 0x804A3F20: bc1f        L_804A3F30
    if (!c1cs) {
        // 0x804A3F24: nop
    
            goto L_804A3F30;
    }
    // 0x804A3F24: nop

    // 0x804A3F28: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A3F2C: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A3F30:
    // 0x804A3F30: bne         $s1, $zero, L_804A3ECC
    if (ctx->r17 != 0) {
        // 0x804A3F34: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A3ECC;
    }
    // 0x804A3F34: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A3F38:
    // 0x804A3F38: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3F3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A3F40: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A3F44: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A3F48: nop

    // 0x804A3F4C: bc1f        L_804A3F5C
    if (!c1cs) {
        // 0x804A3F50: nop
    
            goto L_804A3F5C;
    }
    // 0x804A3F50: nop

    // 0x804A3F54: b           L_804A3F5C
    // 0x804A3F58: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A3F5C;
    // 0x804A3F58: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A3F5C:
    // 0x804A3F5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A3F60: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A3F64: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A3F68: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A3F6C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A3F70: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A3F74: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A3F78: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A3F7C: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A3F80: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A3F84: jr          $ra
    // 0x804A3F88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A3F88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80446988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446988: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044698C: addiu       $v1, $zero, 0xAC8
    ctx->r3 = ADD32(0, 0XAC8);
    // 0x80446990: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446994: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x80446998: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044699C: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    // 0x804469A0: addiu       $a1, $zero, 0x744
    ctx->r5 = ADD32(0, 0X744);
    // 0x804469A4: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x804469A8: sw          $t6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r14;
    // 0x804469AC: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x804469B0: sw          $a1, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r5;
    // 0x804469B4: sw          $a1, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r5;
    // 0x804469B8: jr          $ra
    // 0x804469BC: sw          $v1, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->r3;
    return;
    // 0x804469BC: sw          $v1, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80062518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006251C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062520: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80062524: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80062528: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8006252C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80062530: jal         0x8005BB78
    // 0x80062534: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_8005BB78(rdram, ctx);
        goto after_0;
    // 0x80062534: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80062538: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8006253C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80062540: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80062544: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80062548: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x8006254C: jal         0x800655F4
    // 0x80062550: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800655F4(rdram, ctx);
        goto after_1;
    // 0x80062550: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80062554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062558: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006255C: jr          $ra
    // 0x80062560: nop

    return;
    // 0x80062560: nop

;}
RECOMP_FUNC void func_804532CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804532CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804532D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804532D4: jal         0x804531D0
    // 0x804532D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804531D0(rdram, ctx);
        goto after_0;
    // 0x804532D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804532DC: beql        $v0, $zero, L_804532F0
    if (ctx->r2 == 0) {
        // 0x804532E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804532F0;
    }
    goto skip_0;
    // 0x804532E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804532E4: jal         0x804528A0
    // 0x804532E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804528A0(rdram, ctx);
        goto after_1;
    // 0x804532E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804532EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804532F0:
    // 0x804532F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804532F4: jr          $ra
    // 0x804532F8: nop

    return;
    // 0x804532F8: nop

;}
RECOMP_FUNC void func_80736DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736DD0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80736DD4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80736DD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80736DDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80736DE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80736DE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80736DE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80736DEC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80736DF0: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X39B4) << 16);
    // 0x80736DF4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80736DF8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80736DFC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80736E00: lw          $t1, -0x6BEC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(736, 0X39B4));
    // 0x80736E04: jr          $ra
    // 0x80736E08: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80736E08: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80714820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714820: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80714824: slti        $at, $v0, 0x4679
    ctx->r1 = SIGNED(ctx->r2) < 0X4679 ? 1 : 0;
    // 0x80714828: bne         $at, $zero, L_80714848
    if (ctx->r1 != 0) {
        // 0x8071482C: addiu       $at, $zero, 0x4679
        ctx->r1 = ADD32(0, 0X4679);
            goto L_80714848;
    }
    // 0x8071482C: addiu       $at, $zero, 0x4679
    ctx->r1 = ADD32(0, 0X4679);
    // 0x80714830: beq         $v0, $at, L_807148D4
    if (ctx->r2 == ctx->r1) {
        // 0x80714834: addiu       $at, $zero, 0x467A
        ctx->r1 = ADD32(0, 0X467A);
            goto L_807148D4;
    }
    // 0x80714834: addiu       $at, $zero, 0x467A
    ctx->r1 = ADD32(0, 0X467A);
    // 0x80714838: beq         $v0, $at, L_807148D4
    if (ctx->r2 == ctx->r1) {
        // 0x8071483C: nop
    
            goto L_807148D4;
    }
    // 0x8071483C: nop

    // 0x80714840: b           L_80714904
    // 0x80714844: nop

        goto L_80714904;
    // 0x80714844: nop

L_80714848:
    // 0x80714848: slti        $at, $v0, 0x4678
    ctx->r1 = SIGNED(ctx->r2) < 0X4678 ? 1 : 0;
    // 0x8071484C: bne         $at, $zero, L_80714864
    if (ctx->r1 != 0) {
        // 0x80714850: addiu       $at, $zero, 0x4678
        ctx->r1 = ADD32(0, 0X4678);
            goto L_80714864;
    }
    // 0x80714850: addiu       $at, $zero, 0x4678
    ctx->r1 = ADD32(0, 0X4678);
    // 0x80714854: beq         $v0, $at, L_807148C8
    if (ctx->r2 == ctx->r1) {
        // 0x80714858: nop
    
            goto L_807148C8;
    }
    // 0x80714858: nop

    // 0x8071485C: b           L_80714904
    // 0x80714860: nop

        goto L_80714904;
    // 0x80714860: nop

L_80714864:
    // 0x80714864: slti        $at, $v0, 0x4638
    ctx->r1 = SIGNED(ctx->r2) < 0X4638 ? 1 : 0;
    // 0x80714868: bne         $at, $zero, L_80714884
    if (ctx->r1 != 0) {
        // 0x8071486C: addiu       $t6, $v0, -0x4621
        ctx->r14 = ADD32(ctx->r2, -0X4621);
            goto L_80714884;
    }
    // 0x8071486C: addiu       $t6, $v0, -0x4621
    ctx->r14 = ADD32(ctx->r2, -0X4621);
    // 0x80714870: addiu       $at, $zero, 0x4677
    ctx->r1 = ADD32(0, 0X4677);
    // 0x80714874: beq         $v0, $at, L_807148C8
    if (ctx->r2 == ctx->r1) {
        // 0x80714878: nop
    
            goto L_807148C8;
    }
    // 0x80714878: nop

    // 0x8071487C: b           L_80714904
    // 0x80714880: nop

        goto L_80714904;
    // 0x80714880: nop

L_80714884:
    // 0x80714884: sltiu       $at, $t6, 0x17
    ctx->r1 = ctx->r14 < 0X17 ? 1 : 0;
    // 0x80714888: beq         $at, $zero, L_80714904
    if (ctx->r1 == 0) {
        // 0x8071488C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80714904;
    }
    // 0x8071488C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80714890: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X1814) << 16);
    // 0x80714894: addu        $at, $at, $t6
    gpr jr_addend_8071489C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80714898: lw          $t6, 0x6034($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(730, 0X1814));
    // 0x8071489C: jr          $t6
    // 0x807148A0: nop

    switch (jr_addend_8071489C >> 2) {
        case 0: goto L_807148B0; break;
        case 1: goto L_807148B0; break;
        case 2: goto L_807148BC; break;
        case 3: goto L_807148BC; break;
        case 4: goto L_807148A4; break;
        case 5: goto L_807148F8; break;
        case 6: goto L_80714904; break;
        case 7: goto L_80714904; break;
        case 8: goto L_80714904; break;
        case 9: goto L_80714904; break;
        case 10: goto L_80714904; break;
        case 11: goto L_80714904; break;
        case 12: goto L_80714904; break;
        case 13: goto L_80714904; break;
        case 14: goto L_80714904; break;
        case 15: goto L_80714904; break;
        case 16: goto L_80714904; break;
        case 17: goto L_80714904; break;
        case 18: goto L_80714904; break;
        case 19: goto L_80714904; break;
        case 20: goto L_80714904; break;
        case 21: goto L_807148EC; break;
        case 22: goto L_807148E0; break;
        default: switch_error(__func__, 0x8071489C, 0x80716034);
    }
    // 0x807148A0: nop

L_807148A4:
    // 0x807148A4: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X1044) << 16);
    // 0x807148A8: jr          $ra
    // 0x807148AC: addiu       $v0, $v0, 0x5864
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1044));
    return;
    // 0x807148AC: addiu       $v0, $v0, 0x5864
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1044));
L_807148B0:
    // 0x807148B0: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X10B0) << 16);
    // 0x807148B4: jr          $ra
    // 0x807148B8: addiu       $v0, $v0, 0x58D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X10B0));
    return;
    // 0x807148B8: addiu       $v0, $v0, 0x58D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X10B0));
L_807148BC:
    // 0x807148BC: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X111C) << 16);
    // 0x807148C0: jr          $ra
    // 0x807148C4: addiu       $v0, $v0, 0x593C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X111C));
    return;
    // 0x807148C4: addiu       $v0, $v0, 0x593C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X111C));
L_807148C8:
    // 0x807148C8: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X1188) << 16);
    // 0x807148CC: jr          $ra
    // 0x807148D0: addiu       $v0, $v0, 0x59A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1188));
    return;
    // 0x807148D0: addiu       $v0, $v0, 0x59A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1188));
L_807148D4:
    // 0x807148D4: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X11F4) << 16);
    // 0x807148D8: jr          $ra
    // 0x807148DC: addiu       $v0, $v0, 0x5A14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X11F4));
    return;
    // 0x807148DC: addiu       $v0, $v0, 0x5A14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X11F4));
L_807148E0:
    // 0x807148E0: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X1378) << 16);
    // 0x807148E4: jr          $ra
    // 0x807148E8: addiu       $v0, $v0, 0x5B98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1378));
    return;
    // 0x807148E8: addiu       $v0, $v0, 0x5B98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1378));
L_807148EC:
    // 0x807148EC: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X1260) << 16);
    // 0x807148F0: jr          $ra
    // 0x807148F4: addiu       $v0, $v0, 0x5A80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1260));
    return;
    // 0x807148F4: addiu       $v0, $v0, 0x5A80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1260));
L_807148F8:
    // 0x807148F8: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X12A0) << 16);
    // 0x807148FC: jr          $ra
    // 0x80714900: addiu       $v0, $v0, 0x5AC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X12A0));
    return;
    // 0x80714900: addiu       $v0, $v0, 0x5AC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X12A0));
L_80714904:
    // 0x80714904: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(730, 0X1044) << 16);
    // 0x80714908: addiu       $v0, $v0, 0x5864
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(730, 0X1044));
    // 0x8071490C: jr          $ra
    // 0x80714910: nop

    return;
    // 0x80714910: nop

;}
RECOMP_FUNC void func_8078980C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078980C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80789810: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80789814: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80789818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078981C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80789820: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80789824: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80789828: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8078982C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80789830: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(787, 0X2EA0) << 16);
    // 0x80789834: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80789838: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078983C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80789840: lw          $t1, -0x6720($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(787, 0X2EA0));
    // 0x80789844: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80789848: jal         0x80048378
    // 0x8078984C: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x8078984C: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    after_0:
    // 0x80789850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80789854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80789858: jr          $ra
    // 0x8078985C: nop

    return;
    // 0x8078985C: nop

;}
RECOMP_FUNC void func_80423B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423B80: jal         0x80423A0C
    // 0x80423B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80423A0C(rdram, ctx);
        goto after_0;
    // 0x80423B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423B88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80423B8C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80423B90: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423B94: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423B98: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80423B9C: nop

    // 0x80423BA0: bc1fl       L_80423BEC
    if (!c1cs) {
        // 0x80423BA4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80423BEC;
    }
    goto skip_0;
    // 0x80423BA4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x80423BA8: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80423BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423BB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80423BB4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80423BB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80423BBC: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x80423BC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423BC4: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423BC8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80423BCC: nop

    // 0x80423BD0: bc1fl       L_80423C48
    if (!c1cs) {
        // 0x80423BD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80423C48;
    }
    goto skip_1;
    // 0x80423BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80423BD8: jal         0x80423DB8
    // 0x80423BDC: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    func_80423DB8(rdram, ctx);
        goto after_1;
    // 0x80423BDC: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    after_1:
    // 0x80423BE0: b           L_80423C48
    // 0x80423BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80423C48;
    // 0x80423BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423BE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80423BEC:
    // 0x80423BEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423BF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80423BF4: bc1f        L_80423C3C
    if (!c1cs) {
        // 0x80423BF8: nop
    
            goto L_80423C3C;
    }
    // 0x80423BF8: nop

    // 0x80423BFC: lwc1        $f10, 0xEC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80423C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80423C08: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80423C0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80423C10: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x80423C14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80423C18: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80423C1C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80423C20: nop

    // 0x80423C24: bc1fl       L_80423C48
    if (!c1cs) {
        // 0x80423C28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80423C48;
    }
    goto skip_2;
    // 0x80423C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80423C2C: jal         0x80423DB8
    // 0x80423C30: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    func_80423DB8(rdram, ctx);
        goto after_2;
    // 0x80423C30: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    after_2:
    // 0x80423C34: b           L_80423C48
    // 0x80423C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80423C48;
    // 0x80423C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80423C3C:
    // 0x80423C3C: jal         0x80423DB8
    // 0x80423C40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80423DB8(rdram, ctx);
        goto after_3;
    // 0x80423C40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80423C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80423C48:
    // 0x80423C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423C4C: jr          $ra
    // 0x80423C50: nop

    return;
    // 0x80423C50: nop

;}
RECOMP_FUNC void func_8044AAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AAE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044AAE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AAEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044AAF0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AAF4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AAF8: lw          $a1, 0x6A5C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A5C);
    // 0x8044AAFC: beq         $a1, $zero, L_8044AB14
    if (ctx->r5 == 0) {
        // 0x8044AB00: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044AB14;
    }
    // 0x8044AB00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044AB04: jal         0x80050A2C
    // 0x8044AB08: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044AB08: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044AB0C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AB10: sw          $zero, 0x6A5C($v1)
    MEM_W(0X6A5C, ctx->r3) = 0;
L_8044AB14:
    // 0x8044AB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AB18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044AB1C: jr          $ra
    // 0x8044AB20: nop

    return;
    // 0x8044AB20: nop

;}
RECOMP_FUNC void func_8070CC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CC68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8070CC6C: lwc1        $f16, 0xE0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8070CC70: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8070CC74: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8070CC78: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8070CC7C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8070CC80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070CC84: bc1f        L_8070CCB0
    if (!c1cs) {
        // 0x8070CC88: swc1        $f8, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
            goto L_8070CCB0;
    }
    // 0x8070CC88: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x8070CC8C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8070CC90: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8070CC94: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8070CC98: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8070CC9C: nop

    // 0x8070CCA0: bc1f        L_8070CCCC
    if (!c1cs) {
        // 0x8070CCA4: nop
    
            goto L_8070CCCC;
    }
    // 0x8070CCA4: nop

    // 0x8070CCA8: jr          $ra
    // 0x8070CCAC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8070CCAC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8070CCB0:
    // 0x8070CCB0: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8070CCB4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8070CCB8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8070CCBC: nop

    // 0x8070CCC0: bc1f        L_8070CCCC
    if (!c1cs) {
        // 0x8070CCC4: nop
    
            goto L_8070CCCC;
    }
    // 0x8070CCC4: nop

    // 0x8070CCC8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8070CCCC:
    // 0x8070CCCC: jr          $ra
    // 0x8070CCD0: nop

    return;
    // 0x8070CCD0: nop

;}
RECOMP_FUNC void func_8069B2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B2E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8069B2E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069B2E8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8069B2EC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8069B2F0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8069B2F4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8069B2F8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069B2FC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8069B300: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8069B304: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8069B308: jal         0x80066E88
    // 0x8069B30C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8069B30C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8069B310: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8069B314: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069B318: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8069B31C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8069B320: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8069B324: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8069B328: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x8069B32C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8069B330: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8069B334: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8069B338: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8069B33C: lw          $v1, 0x10($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X10);
    // 0x8069B340: beql        $v1, $at, L_8069B350
    if (ctx->r3 == ctx->r1) {
        // 0x8069B344: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_8069B350;
    }
    goto skip_0;
    // 0x8069B344: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    skip_0:
    // 0x8069B348: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8069B34C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_8069B350:
    // 0x8069B350: jal         0x80066DE4
    // 0x8069B354: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8069B354: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    after_1:
    // 0x8069B358: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X1930) << 16);
    // 0x8069B35C: lwc1        $f2, -0x3A00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(565, 0X1930));
    // 0x8069B360: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8069B364: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8069B368: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8069B36C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8069B370: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8069B374: lwc1        $f16, 0x88($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8069B378: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X18E8) << 16);
    // 0x8069B37C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8069B380: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8069B384: lwc1        $f8, -0x3A48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(565, 0X18E8));
    // 0x8069B388: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8069B38C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8069B390: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8069B394: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8069B398: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8069B39C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8069B3A0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8069B3A4: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8069B3A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8069B3AC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8069B3B0: lwc1        $f18, 0x8C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x8069B3B4: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8069B3B8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8069B3BC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8069B3C0: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8069B3C4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8069B3C8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x8069B3CC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8069B3D0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8069B3D4: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8069B3D8: lw          $t9, 0x28($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X28);
    // 0x8069B3DC: jalr        $t9
    // 0x8069B3E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8069B3E0: nop

    after_2:
    // 0x8069B3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069B3E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8069B3EC: jr          $ra
    // 0x8069B3F0: nop

    return;
    // 0x8069B3F0: nop

;}
RECOMP_FUNC void func_8079FBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FBE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079FBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079FBEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079FBF0: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x8079FBF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8079FBF8: jal         0x80047EB0
    // 0x8079FBFC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x8079FBFC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8079FC00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079FC04: bne         $v0, $zero, L_8079FC28
    if (ctx->r2 != 0) {
        // 0x8079FC08: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8079FC28;
    }
    // 0x8079FC08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8079FC0C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8079FC10: addiu       $t6, $t6, -0x7218
    ctx->r14 = ADD32(ctx->r14, -0X7218);
    // 0x8079FC14: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x8079FC18: jal         0x8003E478
    // 0x8079FC1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_1;
    // 0x8079FC1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8079FC20: b           L_8079FC74
    // 0x8079FC24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8079FC74;
    // 0x8079FC24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8079FC28:
    // 0x8079FC28: lw          $t7, 0x1E0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1E0);
    // 0x8079FC2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079FC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8079FC34: bne         $t7, $at, L_8079FC74
    if (ctx->r15 != ctx->r1) {
        // 0x8079FC38: nop
    
            goto L_8079FC74;
    }
    // 0x8079FC38: nop

    // 0x8079FC3C: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8079FC40: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8079FC44: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8079FC48: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8079FC4C: lhu         $t0, 0x18($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X18);
    // 0x8079FC50: sh          $t0, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r8;
    // 0x8079FC54: lw          $t3, 0x174($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X174);
    // 0x8079FC58: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8079FC5C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8079FC60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8079FC64: lhu         $t5, 0x1A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X1A);
    // 0x8079FC68: sh          $t5, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r13;
    // 0x8079FC6C: lw          $t8, 0x1EC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1EC);
    // 0x8079FC70: sw          $t8, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->r24;
L_8079FC74:
    // 0x8079FC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079FC78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079FC7C: jr          $ra
    // 0x8079FC80: nop

    return;
    // 0x8079FC80: nop

;}
RECOMP_FUNC void func_8002D9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D9B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D9B4: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x8002D9B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002D9BC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002D9C0: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x8002D9C4: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002D9C8: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x8002D9CC: addiu       $t8, $t8, 0x3A68
    ctx->r24 = ADD32(ctx->r24, 0X3A68);
    // 0x8002D9D0: addiu       $t9, $t9, 0x3B7C
    ctx->r25 = ADD32(ctx->r25, 0X3B7C);
    // 0x8002D9D4: sw          $t8, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r24;
    // 0x8002D9D8: sw          $t9, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r25;
    // 0x8002D9DC: jal         0x800230DC
    // 0x8002D9E0: sw          $zero, 0x190($v0)
    MEM_W(0X190, ctx->r2) = 0;
    func_800230DC(rdram, ctx);
        goto after_0;
    // 0x8002D9E0: sw          $zero, 0x190($v0)
    MEM_W(0X190, ctx->r2) = 0;
    after_0:
    // 0x8002D9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D9EC: jr          $ra
    // 0x8002D9F0: nop

    return;
    // 0x8002D9F0: nop

;}
RECOMP_FUNC void func_80676310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80676314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80676318: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067631C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80676320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80676324: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x80676328: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8067632C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80676330: blez        $v1, L_80676340
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80676334: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80676340;
    }
    // 0x80676334: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80676338: b           L_80676350
    // 0x8067633C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
        goto L_80676350;
    // 0x8067633C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
L_80676340:
    // 0x80676340: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80676344: jal         0x80677A88
    // 0x80676348: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80677A88(rdram, ctx);
        goto after_0;
    // 0x80676348: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067634C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80676350:
    // 0x80676350: jal         0x80675CD0
    // 0x80676354: nop

    func_80675CD0(rdram, ctx);
        goto after_1;
    // 0x80676354: nop

    after_1:
    // 0x80676358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067635C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80676360: jr          $ra
    // 0x80676364: nop

    return;
    // 0x80676364: nop

;}
RECOMP_FUNC void func_805DC2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC2A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DC2A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x805DC2A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x805DC2AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805DC2B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805DC2B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805DC2B8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC2BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x805DC2C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x805DC2C4: addiu       $s3, $zero, 0x50
    ctx->r19 = ADD32(0, 0X50);
L_805DC2C8:
    // 0x805DC2C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x805DC2CC: beql        $v0, $zero, L_805DC2F4
    if (ctx->r2 == 0) {
        // 0x805DC2D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_805DC2F4;
    }
    goto skip_0;
    // 0x805DC2D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x805DC2D4: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x805DC2D8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x805DC2DC: beql        $a1, $zero, L_805DC2F4
    if (ctx->r5 == 0) {
        // 0x805DC2E0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_805DC2F4;
    }
    goto skip_1;
    // 0x805DC2E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x805DC2E4: sb          $s2, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r18;
    // 0x805DC2E8: jal         0x8005FE48
    // 0x805DC2EC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x805DC2EC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_0:
    // 0x805DC2F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_805DC2F4:
    // 0x805DC2F4: bne         $s0, $s3, L_805DC2C8
    if (ctx->r16 != ctx->r19) {
        // 0x805DC2F8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_805DC2C8;
    }
    // 0x805DC2F8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x805DC2FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805DC300: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805DC304: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805DC308: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC30C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x805DC310: jr          $ra
    // 0x805DC314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805DC314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80004DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004DD4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80004DD8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004DDC: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x80004DE0: addiu       $s6, $s6, 0x4D10
    ctx->r22 = ADD32(ctx->r22, 0X4D10);
    // 0x80004DE4: lbu         $t6, 0x2A23($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X2A23);
    // 0x80004DE8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80004DEC: addiu       $t8, $t8, -0x6E9C
    ctx->r24 = ADD32(ctx->r24, -0X6E9C);
    // 0x80004DF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80004DF4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004DF8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80004DFC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80004E00: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80004E04: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80004E08: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004E0C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004E10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004E14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004E18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004E1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004E20: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80004E24: sw          $zero, 0x1B54($s6)
    MEM_W(0X1B54, ctx->r22) = 0;
    // 0x80004E28: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80004E2C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80004E30: sh          $t9, 0x1D7E($s6)
    MEM_H(0X1D7E, ctx->r22) = ctx->r25;
    // 0x80004E34: jal         0x8008BE00
    // 0x80004E38: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x80004E38: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
    after_0:
    // 0x80004E3C: lhu         $v1, 0x1D7E($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X1D7E);
    // 0x80004E40: lw          $t1, 0x1E7C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X1E7C);
    // 0x80004E44: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80004E48: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80004E4C: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x80004E50: mflo        $t2
    ctx->r10 = lo;
    // 0x80004E54: addiu       $t3, $t2, 0xF
    ctx->r11 = ADD32(ctx->r10, 0XF);
    // 0x80004E58: andi        $t4, $t3, 0xFFF0
    ctx->r12 = ctx->r11 & 0XFFF0;
    // 0x80004E5C: sh          $t4, 0x1D82($s6)
    MEM_H(0X1D82, ctx->r22) = ctx->r12;
    // 0x80004E60: lh          $a2, 0x1D82($s6)
    ctx->r6 = MEM_H(ctx->r22, 0X1D82);
    // 0x80004E64: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80004E68: sh          $v0, 0x1D80($s6)
    MEM_H(0X1D80, ctx->r22) = ctx->r2;
    // 0x80004E6C: bne         $t1, $zero, L_80004E78
    if (ctx->r9 != 0) {
        // 0x80004E70: nop
    
            goto L_80004E78;
    }
    // 0x80004E70: nop

    // 0x80004E74: break       7
    do_break(2147503732);
L_80004E78:
    // 0x80004E78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004E7C: bne         $t1, $at, L_80004E90
    if (ctx->r9 != ctx->r1) {
        // 0x80004E80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004E90;
    }
    // 0x80004E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004E84: bne         $v1, $at, L_80004E90
    if (ctx->r3 != ctx->r1) {
        // 0x80004E88: nop
    
            goto L_80004E90;
    }
    // 0x80004E88: nop

    // 0x80004E8C: break       6
    do_break(2147503756);
L_80004E90:
    // 0x80004E90: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x80004E94: addiu       $a0, $a2, 0x10
    ctx->r4 = ADD32(ctx->r6, 0X10);
    // 0x80004E98: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80004E9C: mflo        $t6
    ctx->r14 = lo;
    // 0x80004EA0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80004EA4: sh          $t7, 0x1D88($s6)
    MEM_H(0X1D88, ctx->r22) = ctx->r15;
    // 0x80004EA8: lh          $t0, 0x1D88($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X1D88);
    // 0x80004EAC: addiu       $t5, $a2, -0x10
    ctx->r13 = ADD32(ctx->r6, -0X10);
    // 0x80004EB0: sh          $t5, 0x1D86($s6)
    MEM_H(0X1D86, ctx->r22) = ctx->r13;
    // 0x80004EB4: div         $zero, $a2, $t0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r8)));
    // 0x80004EB8: mflo        $t8
    ctx->r24 = lo;
    // 0x80004EBC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80004EC0: sh          $a0, 0x1D84($s6)
    MEM_H(0X1D84, ctx->r22) = ctx->r4;
    // 0x80004EC4: bne         $t0, $zero, L_80004ED0
    if (ctx->r8 != 0) {
        // 0x80004EC8: nop
    
            goto L_80004ED0;
    }
    // 0x80004EC8: nop

    // 0x80004ECC: break       7
    do_break(2147503820);
L_80004ED0:
    // 0x80004ED0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004ED4: bne         $t0, $at, L_80004EE8
    if (ctx->r8 != ctx->r1) {
        // 0x80004ED8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80004EE8;
    }
    // 0x80004ED8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004EDC: bne         $a2, $at, L_80004EE8
    if (ctx->r6 != ctx->r1) {
        // 0x80004EE0: nop
    
            goto L_80004EE8;
    }
    // 0x80004EE0: nop

    // 0x80004EE4: break       6
    do_break(2147503844);
L_80004EE8:
    // 0x80004EE8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80004EEC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80004EF0: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x80004EF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004EF8: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80004EFC: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004F00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80004F04: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80004F08: sh          $t9, 0x1D8A($s6)
    MEM_H(0X1D8A, ctx->r22) = ctx->r25;
    // 0x80004F0C: lh          $a1, 0x1D8A($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X1D8A);
    // 0x80004F10: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80004F14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004F18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80004F1C: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x80004F20: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80004F24: addiu       $t2, $a1, -0x8
    ctx->r10 = ADD32(ctx->r5, -0X8);
    // 0x80004F28: sh          $t1, 0x1D8C($s6)
    MEM_H(0X1D8C, ctx->r22) = ctx->r9;
    // 0x80004F2C: sh          $t2, 0x1D8E($s6)
    MEM_H(0X1D8E, ctx->r22) = ctx->r10;
    // 0x80004F30: swc1        $f8, 0x1DA0($s6)
    MEM_W(0X1DA0, ctx->r22) = ctx->f8.u32l;
    // 0x80004F34: div.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80004F38: swc1        $f10, 0x1D94($s6)
    MEM_W(0X1D94, ctx->r22) = ctx->f10.u32l;
    // 0x80004F3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004F40: nop

    // 0x80004F44: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80004F48: swc1        $f6, 0x1D9C($s6)
    MEM_W(0X1D9C, ctx->r22) = ctx->f6.u32l;
    // 0x80004F4C: swc1        $f16, 0x1D98($s6)
    MEM_W(0X1D98, ctx->r22) = ctx->f16.u32l;
    // 0x80004F50: lbu         $t3, 0x5($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X5);
    // 0x80004F54: sw          $t3, 0x1DAC($s6)
    MEM_W(0X1DAC, ctx->r22) = ctx->r11;
    // 0x80004F58: lbu         $t4, 0x6($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X6);
    // 0x80004F5C: sh          $t4, 0x1D90($s6)
    MEM_H(0X1D90, ctx->r22) = ctx->r12;
    // 0x80004F60: lh          $t5, 0x1D90($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X1D90);
    // 0x80004F64: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80004F68: bne         $at, $zero, L_80004F74
    if (ctx->r1 != 0) {
        // 0x80004F6C: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80004F74;
    }
    // 0x80004F6C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80004F70: sh          $t6, 0x1D90($s6)
    MEM_H(0X1D90, ctx->r22) = ctx->r14;
L_80004F74:
    // 0x80004F74: lhu         $t7, 0xC($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0XC);
    // 0x80004F78: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80004F7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80004F80: sh          $t7, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r15;
    // 0x80004F84: lh          $t8, -0x3C4E($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3C4E);
    // 0x80004F88: lwc1        $f18, -0x4400($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4400);
    // 0x80004F8C: lwc1        $f16, 0x1E78($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X1E78);
    // 0x80004F90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004F94: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80004F98: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80004F9C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004FA0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80004FA4: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80004FA8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80004FAC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80004FB0: nop

    // 0x80004FB4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80004FB8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80004FBC: nop

    // 0x80004FC0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80004FC4: beq         $t1, $zero, L_80005010
    if (ctx->r9 == 0) {
        // 0x80004FC8: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80005010;
    }
    // 0x80004FC8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004FCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004FD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80004FD4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80004FD8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80004FDC: nop

    // 0x80004FE0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80004FE4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80004FE8: nop

    // 0x80004FEC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80004FF0: bne         $t1, $zero, L_80005008
    if (ctx->r9 != 0) {
        // 0x80004FF4: nop
    
            goto L_80005008;
    }
    // 0x80004FF4: nop

    // 0x80004FF8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80004FFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005000: b           L_80005020
    // 0x80005004: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80005020;
    // 0x80005004: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80005008:
    // 0x80005008: b           L_80005020
    // 0x8000500C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80005020;
    // 0x8000500C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80005010:
    // 0x80005010: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80005014: nop

    // 0x80005018: bltz        $t1, L_80005008
    if (SIGNED(ctx->r9) < 0) {
        // 0x8000501C: nop
    
            goto L_80005008;
    }
    // 0x8000501C: nop

L_80005020:
    // 0x80005020: sh          $t1, 0x1DB0($s6)
    MEM_H(0X1DB0, ctx->r22) = ctx->r9;
    // 0x80005024: lbu         $t2, 0x4($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X4);
    // 0x80005028: lh          $t4, 0x1D84($s6)
    ctx->r12 = MEM_H(ctx->r22, 0X1D84);
    // 0x8000502C: lh          $t6, 0x1D86($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X1D86);
    // 0x80005030: sh          $t2, 0x1D7C($s6)
    MEM_H(0X1D7C, ctx->r22) = ctx->r10;
    // 0x80005034: lh          $v0, 0x1D7C($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X1D7C);
    // 0x80005038: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000503C: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005040: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80005044: mflo        $t3
    ctx->r11 = lo;
    // 0x80005048: sh          $t3, 0x1D82($s6)
    MEM_H(0X1D82, ctx->r22) = ctx->r11;
    // 0x8000504C: nop

    // 0x80005050: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005054: mflo        $t5
    ctx->r13 = lo;
    // 0x80005058: sh          $t5, 0x1D84($s6)
    MEM_H(0X1D84, ctx->r22) = ctx->r13;
    // 0x8000505C: nop

    // 0x80005060: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005064: mflo        $t7
    ctx->r15 = lo;
    // 0x80005068: sh          $t7, 0x1D86($s6)
    MEM_H(0X1D86, ctx->r22) = ctx->r15;
    // 0x8000506C: nop

    // 0x80005070: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005074: mflo        $t8
    ctx->r24 = lo;
    // 0x80005078: sh          $t8, 0x1D88($s6)
    MEM_H(0X1D88, ctx->r22) = ctx->r24;
    // 0x8000507C: bnel        $at, $zero, L_80005094
    if (ctx->r1 != 0) {
        // 0x80005080: lw          $t2, 0x1DAC($s6)
        ctx->r10 = MEM_W(ctx->r22, 0X1DAC);
            goto L_80005094;
    }
    goto skip_0;
    // 0x80005080: lw          $t2, 0x1DAC($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X1DAC);
    skip_0:
    // 0x80005084: lh          $t9, 0x1D84($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X1D84);
    // 0x80005088: addiu       $t1, $t9, -0x10
    ctx->r9 = ADD32(ctx->r25, -0X10);
    // 0x8000508C: sh          $t1, 0x1D84($s6)
    MEM_H(0X1D84, ctx->r22) = ctx->r9;
    // 0x80005090: lw          $t2, 0x1DAC($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X1DAC);
L_80005094:
    // 0x80005094: lh          $t4, 0x1D88($s6)
    ctx->r12 = MEM_H(ctx->r22, 0X1D88);
    // 0x80005098: lbu         $t6, 0x7($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X7);
    // 0x8000509C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800050A0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800050A4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800050A8: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800050AC: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800050B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800050B4: addiu       $a0, $a0, 0x7630
    ctx->r4 = ADD32(ctx->r4, 0X7630);
    // 0x800050B8: mflo        $t5
    ctx->r13 = lo;
    // 0x800050BC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800050C0: addiu       $t9, $t8, 0x1E0
    ctx->r25 = ADD32(ctx->r24, 0X1E0);
    // 0x800050C4: sw          $t9, 0x1DA8($s6)
    MEM_W(0X1DA8, ctx->r22) = ctx->r25;
    // 0x800050C8: lw          $t2, 0x14($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X14);
    // 0x800050CC: lw          $t1, 0x10($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X10);
    // 0x800050D0: lw          $t4, 0x18($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X18);
    // 0x800050D4: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800050D8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800050DC: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x800050E0: lw          $t1, 0x24($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X24);
    // 0x800050E4: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800050E8: lw          $t5, 0x28($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X28);
    // 0x800050EC: lw          $t3, 0x2C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X2C);
    // 0x800050F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800050F4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800050F8: lw          $t4, 0x1EB0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X1EB0);
    // 0x800050FC: addu        $s0, $t6, $t5
    ctx->r16 = ADD32(ctx->r14, ctx->r13);
    // 0x80005100: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x80005104: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80005108: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8000510C: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
    // 0x80005110: subu        $v1, $t4, $v0
    ctx->r3 = SUB32(ctx->r12, ctx->r2);
    // 0x80005114: addiu       $v1, $v1, -0x100
    ctx->r3 = ADD32(ctx->r3, -0X100);
    // 0x80005118: sw          $v1, 0x2920($s6)
    MEM_W(0X2920, ctx->r22) = ctx->r3;
    // 0x8000511C: jal         0x800037CC
    // 0x80005120: sw          $v0, 0x292C($s6)
    MEM_W(0X292C, ctx->r22) = ctx->r2;
    func_800037CC(rdram, ctx);
        goto after_1;
    // 0x80005120: sw          $v0, 0x292C($s6)
    MEM_W(0X292C, ctx->r22) = ctx->r2;
    after_1:
    // 0x80005124: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005128: sw          $s0, 0x2930($s6)
    MEM_W(0X2930, ctx->r22) = ctx->r16;
    // 0x8000512C: sw          $s1, 0x2934($s6)
    MEM_W(0X2934, ctx->r22) = ctx->r17;
    // 0x80005130: jal         0x80003850
    // 0x80005134: addiu       $a0, $a0, 0x7640
    ctx->r4 = ADD32(ctx->r4, 0X7640);
    func_80003850(rdram, ctx);
        goto after_2;
    // 0x80005134: addiu       $a0, $a0, 0x7640
    ctx->r4 = ADD32(ctx->r4, 0X7640);
    after_2:
    // 0x80005138: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8000513C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005140: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    // 0x80005144: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80005148: sw          $t6, 0x2938($s6)
    MEM_W(0X2938, ctx->r22) = ctx->r14;
    // 0x8000514C: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x80005150: sw          $t5, 0x293C($s6)
    MEM_W(0X293C, ctx->r22) = ctx->r13;
    // 0x80005154: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x80005158: jal         0x800038D4
    // 0x8000515C: sw          $t7, 0x2940($s6)
    MEM_W(0X2940, ctx->r22) = ctx->r15;
    func_800038D4(rdram, ctx);
        goto after_3;
    // 0x8000515C: sw          $t7, 0x2940($s6)
    MEM_W(0X2940, ctx->r22) = ctx->r15;
    after_3:
    // 0x80005160: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80005164: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005168: addiu       $a0, $a0, 0x7654
    ctx->r4 = ADD32(ctx->r4, 0X7654);
    // 0x8000516C: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x80005170: sw          $t8, 0x2944($s6)
    MEM_W(0X2944, ctx->r22) = ctx->r24;
    // 0x80005174: lw          $t9, 0x20($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X20);
    // 0x80005178: sw          $t9, 0x2948($s6)
    MEM_W(0X2948, ctx->r22) = ctx->r25;
    // 0x8000517C: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x80005180: jal         0x80003998
    // 0x80005184: sw          $t1, 0x294C($s6)
    MEM_W(0X294C, ctx->r22) = ctx->r9;
    func_80003998(rdram, ctx);
        goto after_4;
    // 0x80005184: sw          $t1, 0x294C($s6)
    MEM_W(0X294C, ctx->r22) = ctx->r9;
    after_4:
    // 0x80005188: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8000518C: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x80005190: jal         0x800057BC
    // 0x80005194: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    func_800057BC(rdram, ctx);
        goto after_5;
    // 0x80005194: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    after_5:
    // 0x80005198: lw          $v1, 0x1EB8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X1EB8);
    // 0x8000519C: beq         $v1, $zero, L_800051A8
    if (ctx->r3 == 0) {
        // 0x800051A0: nop
    
            goto L_800051A8;
    }
    // 0x800051A0: nop

    // 0x800051A4: sw          $v1, 0x1EBC($s6)
    MEM_W(0X1EBC, ctx->r22) = ctx->r3;
L_800051A8:
    // 0x800051A8: jal         0x8000335C
    // 0x800051AC: nop

    func_8000335C(rdram, ctx);
        goto after_6;
    // 0x800051AC: nop

    after_6:
    // 0x800051B0: lw          $a1, 0x1DAC($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X1DAC);
    // 0x800051B4: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800051B8: addiu       $s3, $s3, 0x6BE8
    ctx->r19 = ADD32(ctx->r19, 0X6BE8);
    // 0x800051BC: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x800051C0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800051C4: subu        $a1, $a1, $at
    ctx->r5 = SUB32(ctx->r5, ctx->r1);
    // 0x800051C8: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800051CC: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x800051D0: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x800051D4: jal         0x8000363C
    // 0x800051D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8000363C(rdram, ctx);
        goto after_7;
    // 0x800051D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x800051DC: jal         0x8000C7E0
    // 0x800051E0: sw          $v0, 0x2A2C($s6)
    MEM_W(0X2A2C, ctx->r22) = ctx->r2;
    func_8000C7E0(rdram, ctx);
        goto after_8;
    // 0x800051E0: sw          $v0, 0x2A2C($s6)
    MEM_W(0X2A2C, ctx->r22) = ctx->r2;
    after_8:
    // 0x800051E4: jal         0x8000BDF0
    // 0x800051E8: nop

    func_8000BDF0(rdram, ctx);
        goto after_9;
    // 0x800051E8: nop

    after_9:
    // 0x800051EC: lh          $t2, 0x1D88($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X1D88);
    // 0x800051F0: lw          $t3, 0x1DAC($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X1DAC);
    // 0x800051F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800051F8: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800051FC: mflo        $a1
    ctx->r5 = lo;
    // 0x80005200: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80005204: jal         0x8000363C
    // 0x80005208: nop

    func_8000363C(rdram, ctx);
        goto after_10;
    // 0x80005208: nop

    after_10:
    // 0x8000520C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80005210: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80005214: sw          $v0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r2;
    // 0x80005218: addiu       $s1, $s1, 0x4D18
    ctx->r17 = ADD32(ctx->r17, 0X4D18);
    // 0x8000521C: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
L_80005220:
    // 0x80005220: lw          $a1, 0x1DA8($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X1DA8);
    // 0x80005224: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005228: jal         0x800035B4
    // 0x8000522C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    func_800035B4(rdram, ctx);
        goto after_11;
    // 0x8000522C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    after_11:
    // 0x80005230: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80005234: bne         $s0, $s1, L_80005220
    if (ctx->r16 != ctx->r17) {
        // 0x80005238: sw          $v0, 0x1DC0($s0)
        MEM_W(0X1DC0, ctx->r16) = ctx->r2;
            goto L_80005220;
    }
    // 0x80005238: sw          $v0, 0x1DC0($s0)
    MEM_W(0X1DC0, ctx->r16) = ctx->r2;
    // 0x8000523C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005240: jal         0x80003698
    // 0x80005244: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_80003698(rdram, ctx);
        goto after_12;
    // 0x80005244: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_12:
    // 0x80005248: jal         0x80002FF0
    // 0x8000524C: sw          $v0, 0x2A28($s6)
    MEM_W(0X2A28, ctx->r22) = ctx->r2;
    func_80002FF0(rdram, ctx);
        goto after_13;
    // 0x8000524C: sw          $v0, 0x2A28($s6)
    MEM_W(0X2A28, ctx->r22) = ctx->r2;
    after_13:
    // 0x80005250: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x80005254: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80005258: addiu       $v0, $v0, 0x4E68
    ctx->r2 = ADD32(ctx->r2, 0X4E68);
    // 0x8000525C: addiu       $s4, $s4, 0x4D10
    ctx->r20 = ADD32(ctx->r20, 0X4D10);
L_80005260:
    // 0x80005260: addiu       $s4, $s4, 0x158
    ctx->r20 = ADD32(ctx->r20, 0X158);
    // 0x80005264: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x80005268: bne         $at, $zero, L_80005260
    if (ctx->r1 != 0) {
        // 0x8000526C: sb          $zero, -0x13F($s4)
        MEM_B(-0X13F, ctx->r20) = 0;
            goto L_80005260;
    }
    // 0x8000526C: sb          $zero, -0x13F($s4)
    MEM_B(-0X13F, ctx->r20) = 0;
    // 0x80005270: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80005274: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x80005278: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x8000527C: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x80005280: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80005284: addiu       $s2, $s2, 0x4D28
    ctx->r18 = ADD32(ctx->r18, 0X4D28);
    // 0x80005288: sb          $t4, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r12;
    // 0x8000528C: lb          $t6, 0x1($s6)
    ctx->r14 = MEM_B(ctx->r22, 0X1);
    // 0x80005290: addiu       $s4, $s4, 0x4D10
    ctx->r20 = ADD32(ctx->r20, 0X4D10);
    // 0x80005294: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80005298: blez        $t6, L_80005598
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000529C: lui         $t5, 0x800B
        ctx->r13 = S32(0X800B << 16);
            goto L_80005598;
    }
    // 0x8000529C: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x800052A0: lui         $fp, 0x800B
    ctx->r30 = S32(0X800B << 16);
    // 0x800052A4: addiu       $t5, $t5, 0x4E50
    ctx->r13 = ADD32(ctx->r13, 0X4E50);
    // 0x800052A8: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800052AC: addiu       $fp, $fp, 0x4E40
    ctx->r30 = ADD32(ctx->r30, 0X4E40);
L_800052B0:
    // 0x800052B0: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800052B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800052B8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800052BC: addu        $s5, $t7, $s7
    ctx->r21 = ADD32(ctx->r15, ctx->r23);
    // 0x800052C0: lbu         $t8, 0x0($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X0);
    // 0x800052C4: sb          $t8, 0x1C($s4)
    MEM_B(0X1C, ctx->r20) = ctx->r24;
    // 0x800052C8: lbu         $t9, 0x1($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X1);
    // 0x800052CC: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x800052D0: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x800052D4: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800052D8: div         $zero, $t2, $t3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r11)));
    // 0x800052DC: sh          $t1, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r9;
    // 0x800052E0: mflo        $t4
    ctx->r12 = lo;
    // 0x800052E4: sh          $t4, 0x1E($s4)
    MEM_H(0X1E, ctx->r20) = ctx->r12;
    // 0x800052E8: lhu         $t6, 0x2($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X2);
    // 0x800052EC: bne         $t3, $zero, L_800052F8
    if (ctx->r11 != 0) {
        // 0x800052F0: nop
    
            goto L_800052F8;
    }
    // 0x800052F0: nop

    // 0x800052F4: break       7
    do_break(2147504884);
L_800052F8:
    // 0x800052F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800052FC: bne         $t3, $at, L_80005310
    if (ctx->r11 != ctx->r1) {
        // 0x80005300: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80005310;
    }
    // 0x80005300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005304: bne         $t2, $at, L_80005310
    if (ctx->r10 != ctx->r1) {
        // 0x80005308: nop
    
            goto L_80005310;
    }
    // 0x80005308: nop

    // 0x8000530C: break       6
    do_break(2147504908);
L_80005310:
    // 0x80005310: sh          $t6, 0x24($s4)
    MEM_H(0X24, ctx->r20) = ctx->r14;
    // 0x80005314: lhu         $t5, 0x4($s5)
    ctx->r13 = MEM_HU(ctx->r21, 0X4);
    // 0x80005318: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8000531C: andi        $a1, $t4, 0xFFFF
    ctx->r5 = ctx->r12 & 0XFFFF;
    // 0x80005320: sh          $t5, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r13;
    // 0x80005324: lhu         $t7, 0x6($s5)
    ctx->r15 = MEM_HU(ctx->r21, 0X6);
    // 0x80005328: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8000532C: sh          $t7, 0x28($s4)
    MEM_H(0X28, ctx->r20) = ctx->r15;
    // 0x80005330: lhu         $t8, 0x8($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X8);
    // 0x80005334: sh          $t8, 0x2A($s4)
    MEM_H(0X2A, ctx->r20) = ctx->r24;
    // 0x80005338: lb          $t9, 0xA($s5)
    ctx->r25 = MEM_B(ctx->r21, 0XA);
    // 0x8000533C: sb          $t9, 0x1D($s4)
    MEM_B(0X1D, ctx->r20) = ctx->r25;
    // 0x80005340: lhu         $t1, 0xC($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0XC);
    // 0x80005344: sb          $t2, 0x19($s4)
    MEM_B(0X19, ctx->r20) = ctx->r10;
    // 0x80005348: jal         0x800035B4
    // 0x8000534C: sh          $t1, 0x20($s4)
    MEM_H(0X20, ctx->r20) = ctx->r9;
    func_800035B4(rdram, ctx);
        goto after_14;
    // 0x8000534C: sh          $t1, 0x20($s4)
    MEM_H(0X20, ctx->r20) = ctx->r9;
    after_14:
    // 0x80005350: lhu         $a1, 0x6($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X6);
    // 0x80005354: sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // 0x80005358: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000535C: jal         0x800035B4
    // 0x80005360: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    func_800035B4(rdram, ctx);
        goto after_15;
    // 0x80005360: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    after_15:
    // 0x80005364: lbu         $t5, 0x118($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X118);
    // 0x80005368: lhu         $a1, 0x6($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X6);
    // 0x8000536C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80005370: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80005374: andi        $t7, $t5, 0xFF0F
    ctx->r15 = ctx->r13 & 0XFF0F;
    // 0x80005378: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // 0x8000537C: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x80005380: sw          $zero, 0x18($s2)
    MEM_W(0X18, ctx->r18) = 0;
    // 0x80005384: sb          $zero, 0x3($s2)
    MEM_B(0X3, ctx->r18) = 0;
    // 0x80005388: sb          $t3, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r11;
    // 0x8000538C: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
    // 0x80005390: sw          $fp, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r30;
    // 0x80005394: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x80005398: sw          $a1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r5;
    // 0x8000539C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800053A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800053A4: sb          $t9, 0x118($s2)
    MEM_B(0X118, ctx->r18) = ctx->r25;
    // 0x800053A8: andi        $t1, $t9, 0xF3
    ctx->r9 = ctx->r25 & 0XF3;
    // 0x800053AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800053B0: sb          $t1, 0x118($s2)
    MEM_B(0X118, ctx->r18) = ctx->r9;
    // 0x800053B4: lw          $a0, 0x118($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X118);
    // 0x800053B8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800053BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800053C0: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x800053C4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800053C8: sw          $t6, 0x120($s2)
    MEM_W(0X120, ctx->r18) = ctx->r14;
    // 0x800053CC: xor         $t4, $t3, $a0
    ctx->r12 = ctx->r11 ^ ctx->r4;
    // 0x800053D0: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x800053D4: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800053D8: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
    // 0x800053DC: srl         $t5, $t6, 8
    ctx->r13 = S32(U32(ctx->r14) >> 8);
    // 0x800053E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800053E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800053E8: xor         $t7, $t5, $a0
    ctx->r15 = ctx->r13 ^ ctx->r4;
    // 0x800053EC: sw          $t7, 0x118($s2)
    MEM_W(0X118, ctx->r18) = ctx->r15;
    // 0x800053F0: sw          $zero, 0x128($s2)
    MEM_W(0X128, ctx->r18) = 0;
    // 0x800053F4: sw          $t9, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->r25;
    // 0x800053F8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800053FC: sw          $a1, 0x12C($s2)
    MEM_W(0X12C, ctx->r18) = ctx->r5;
    // 0x80005400: swc1        $f6, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->f6.u32l;
    // 0x80005404: beq         $v0, $at, L_800054DC
    if (ctx->r2 == ctx->r1) {
        // 0x80005408: sw          $t8, 0x11C($s2)
        MEM_W(0X11C, ctx->r18) = ctx->r24;
            goto L_800054DC;
    }
    // 0x80005408: sw          $t8, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->r24;
    // 0x8000540C: ori         $t1, $zero, 0x8000
    ctx->r9 = 0 | 0X8000;
    // 0x80005410: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x80005414: mflo        $t2
    ctx->r10 = lo;
    // 0x80005418: sh          $t2, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r10;
    // 0x8000541C: bne         $v0, $zero, L_80005428
    if (ctx->r2 != 0) {
        // 0x80005420: nop
    
            goto L_80005428;
    }
    // 0x80005420: nop

    // 0x80005424: break       7
    do_break(2147505188);
L_80005428:
    // 0x80005428: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000542C: bne         $v0, $at, L_80005440
    if (ctx->r2 != ctx->r1) {
        // 0x80005430: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80005440;
    }
    // 0x80005430: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005434: bne         $t1, $at, L_80005440
    if (ctx->r9 != ctx->r1) {
        // 0x80005438: nop
    
            goto L_80005440;
    }
    // 0x80005438: nop

    // 0x8000543C: break       6
    do_break(2147505212);
L_80005440:
    // 0x80005440: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005444: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80005448: jal         0x8000363C
    // 0x8000544C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8000363C(rdram, ctx);
        goto after_16;
    // 0x8000544C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_16:
    // 0x80005450: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x80005454: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005458: jal         0x8000363C
    // 0x8000545C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000363C(rdram, ctx);
        goto after_17;
    // 0x8000545C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_17:
    // 0x80005460: sw          $v0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r2;
    // 0x80005464: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005468: jal         0x8000363C
    // 0x8000546C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000363C(rdram, ctx);
        goto after_18;
    // 0x8000546C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_18:
    // 0x80005470: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    // 0x80005474: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005478: jal         0x8000363C
    // 0x8000547C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8000363C(rdram, ctx);
        goto after_19;
    // 0x8000547C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_19:
    // 0x80005480: sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
    // 0x80005484: lh          $t3, 0x1D88($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X1D88);
    // 0x80005488: blezl       $t3, L_800054E0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000548C: lh          $t7, 0xE($s5)
        ctx->r15 = MEM_H(ctx->r21, 0XE);
            goto L_800054E0;
    }
    goto skip_1;
    // 0x8000548C: lh          $t7, 0xE($s5)
    ctx->r15 = MEM_H(ctx->r21, 0XE);
    skip_1:
    // 0x80005490: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80005494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80005498:
    // 0x80005498: jal         0x8000363C
    // 0x8000549C: addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    func_8000363C(rdram, ctx);
        goto after_20;
    // 0x8000549C: addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    after_20:
    // 0x800054A0: addiu       $t4, $v0, 0x1A0
    ctx->r12 = ADD32(ctx->r2, 0X1A0);
    // 0x800054A4: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x800054A8: sw          $t4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r12;
    // 0x800054AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800054B0: jal         0x8000363C
    // 0x800054B4: addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    func_8000363C(rdram, ctx);
        goto after_21;
    // 0x800054B4: addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    after_21:
    // 0x800054B8: addiu       $t6, $v0, 0x1A0
    ctx->r14 = ADD32(ctx->r2, 0X1A0);
    // 0x800054BC: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
    // 0x800054C0: sw          $t6, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r14;
    // 0x800054C4: lh          $t5, 0x1D88($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X1D88);
    // 0x800054C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800054CC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800054D0: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800054D4: bnel        $at, $zero, L_80005498
    if (ctx->r1 != 0) {
        // 0x800054D8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80005498;
    }
    goto skip_2;
    // 0x800054D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
L_800054DC:
    // 0x800054DC: lh          $t7, 0xE($s5)
    ctx->r15 = MEM_H(ctx->r21, 0XE);
L_800054E0:
    // 0x800054E0: beql        $t7, $zero, L_80005520
    if (ctx->r15 == 0) {
        // 0x800054E4: sw          $zero, 0x100($s2)
        MEM_W(0X100, ctx->r18) = 0;
            goto L_80005520;
    }
    goto skip_3;
    // 0x800054E4: sw          $zero, 0x100($s2)
    MEM_W(0X100, ctx->r18) = 0;
    skip_3:
    // 0x800054E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800054EC: jal         0x800035F8
    // 0x800054F0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800035F8(rdram, ctx);
        goto after_22;
    // 0x800054F0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_22:
    // 0x800054F4: sw          $v0, 0x108($s2)
    MEM_W(0X108, ctx->r18) = ctx->r2;
    // 0x800054F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800054FC: jal         0x800035F8
    // 0x80005500: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800035F8(rdram, ctx);
        goto after_23;
    // 0x80005500: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_23:
    // 0x80005504: sw          $v0, 0x100($s2)
    MEM_W(0X100, ctx->r18) = ctx->r2;
    // 0x80005508: lh          $a1, 0xE($s5)
    ctx->r5 = MEM_H(ctx->r21, 0XE);
    // 0x8000550C: jal         0x800046C8
    // 0x80005510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800046C8(rdram, ctx);
        goto after_24;
    // 0x80005510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x80005514: b           L_80005524
    // 0x80005518: lh          $t8, 0x10($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X10);
        goto L_80005524;
    // 0x80005518: lh          $t8, 0x10($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X10);
    // 0x8000551C: sw          $zero, 0x100($s2)
    MEM_W(0X100, ctx->r18) = 0;
L_80005520:
    // 0x80005520: lh          $t8, 0x10($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X10);
L_80005524:
    // 0x80005524: beql        $t8, $zero, L_80005564
    if (ctx->r24 == 0) {
        // 0x80005528: sw          $zero, 0x104($s2)
        MEM_W(0X104, ctx->r18) = 0;
            goto L_80005564;
    }
    goto skip_4;
    // 0x80005528: sw          $zero, 0x104($s2)
    MEM_W(0X104, ctx->r18) = 0;
    skip_4:
    // 0x8000552C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005530: jal         0x800035F8
    // 0x80005534: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800035F8(rdram, ctx);
        goto after_25;
    // 0x80005534: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_25:
    // 0x80005538: sw          $v0, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->r2;
    // 0x8000553C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005540: jal         0x800035F8
    // 0x80005544: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800035F8(rdram, ctx);
        goto after_26;
    // 0x80005544: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_26:
    // 0x80005548: sw          $v0, 0x104($s2)
    MEM_W(0X104, ctx->r18) = ctx->r2;
    // 0x8000554C: lh          $a1, 0x10($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X10);
    // 0x80005550: jal         0x800046C8
    // 0x80005554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800046C8(rdram, ctx);
        goto after_27;
    // 0x80005554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_27:
    // 0x80005558: b           L_80005568
    // 0x8000555C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
        goto L_80005568;
    // 0x8000555C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80005560: sw          $zero, 0x104($s2)
    MEM_W(0X104, ctx->r18) = 0;
L_80005564:
    // 0x80005564: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
L_80005568:
    // 0x80005568: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8000556C: lb          $t2, 0x1($s6)
    ctx->r10 = MEM_B(ctx->r22, 0X1);
    // 0x80005570: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005574: addiu       $t1, $t9, 0x158
    ctx->r9 = ADD32(ctx->r25, 0X158);
    // 0x80005578: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000557C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80005580: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80005584: addiu       $s4, $s4, 0x158
    ctx->r20 = ADD32(ctx->r20, 0X158);
    // 0x80005588: addiu       $s7, $s7, 0x12
    ctx->r23 = ADD32(ctx->r23, 0X12);
    // 0x8000558C: addiu       $s2, $s2, 0x158
    ctx->r18 = ADD32(ctx->r18, 0X158);
    // 0x80005590: bne         $at, $zero, L_800052B0
    if (ctx->r1 != 0) {
        // 0x80005594: addiu       $fp, $fp, 0x158
        ctx->r30 = ADD32(ctx->r30, 0X158);
            goto L_800052B0;
    }
    // 0x80005594: addiu       $fp, $fp, 0x158
    ctx->r30 = ADD32(ctx->r30, 0X158);
L_80005598:
    // 0x80005598: jal         0x800104A4
    // 0x8000559C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800104A4(rdram, ctx);
        goto after_28;
    // 0x8000559C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_28:
    // 0x800055A0: lh          $t3, 0x1D90($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X1D90);
    // 0x800055A4: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800055A8: addiu       $s0, $s0, 0x7740
    ctx->r16 = ADD32(ctx->r16, 0X7740);
    // 0x800055AC: blez        $t3, L_800055DC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800055B0: nop
    
            goto L_800055DC;
    }
    // 0x800055B0: nop

L_800055B4:
    // 0x800055B4: jal         0x80010300
    // 0x800055B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80010300(rdram, ctx);
        goto after_29;
    // 0x800055B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x800055BC: jal         0x80010230
    // 0x800055C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80010230(rdram, ctx);
        goto after_30;
    // 0x800055C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x800055C4: lh          $t4, 0x1D90($s6)
    ctx->r12 = MEM_H(ctx->r22, 0X1D90);
    // 0x800055C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800055CC: addiu       $s0, $s0, 0x160
    ctx->r16 = ADD32(ctx->r16, 0X160);
    // 0x800055D0: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800055D4: bne         $at, $zero, L_800055B4
    if (ctx->r1 != 0) {
        // 0x800055D8: nop
    
            goto L_800055B4;
    }
    // 0x800055D8: nop

L_800055DC:
    // 0x800055DC: jal         0x800063A8
    // 0x800055E0: lw          $a0, 0x1DAC($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X1DAC);
    func_800063A8(rdram, ctx);
        goto after_31;
    // 0x800055E0: lw          $a0, 0x1DAC($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X1DAC);
    after_31:
    // 0x800055E4: jal         0x800080D4
    // 0x800055E8: sw          $zero, 0xD84($s6)
    MEM_W(0XD84, ctx->r22) = 0;
    func_800080D4(rdram, ctx);
        goto after_32;
    // 0x800055E8: sw          $zero, 0xD84($s6)
    MEM_W(0XD84, ctx->r22) = 0;
    after_32:
    // 0x800055EC: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800055F0: jal         0x800097F0
    // 0x800055F4: sh          $t6, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r14;
    func_800097F0(rdram, ctx);
        goto after_33;
    // 0x800055F4: sh          $t6, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r14;
    after_33:
    // 0x800055F8: jal         0x800825F0
    // 0x800055FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_34;
    // 0x800055FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x80005600: jal         0x80090710
    // 0x80005604: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_35;
    // 0x80005604: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_35:
    // 0x80005608: jal         0x800825F0
    // 0x8000560C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_36;
    // 0x8000560C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80005610: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80005614: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005618: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000561C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005620: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80005624: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80005628: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000562C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80005630: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80005634: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80005638: jr          $ra
    // 0x8000563C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000563C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_807AA908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AA908: lw          $a2, 0xE4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE4);
    // 0x807AA90C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x807AA910: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807AA914: beq         $a2, $zero, L_807AA92C
    if (ctx->r6 == 0) {
        // 0x807AA918: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_807AA92C;
    }
    // 0x807AA918: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807AA91C: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x807AA920: sw          $t6, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->r14;
    // 0x807AA924: jr          $ra
    // 0x807AA928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x807AA928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AA92C:
    // 0x807AA92C: lw          $t7, 0xE0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE0);
    // 0x807AA930: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(853, 0X1BB0) << 16);
    // 0x807AA934: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
    // 0x807AA938: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x807AA93C: bne         $at, $zero, L_807AA950
    if (ctx->r1 != 0) {
        // 0x807AA940: sw          $a1, 0xE0($a0)
        MEM_W(0XE0, ctx->r4) = ctx->r5;
            goto L_807AA950;
    }
    // 0x807AA940: sw          $a1, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r5;
    // 0x807AA944: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x807AA948: sw          $a1, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->r5;
    // 0x807AA94C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_807AA950:
    // 0x807AA950: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x807AA954: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807AA958: lh          $t1, -0x4810($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(853, 0X1BB0));
    // 0x807AA95C: sh          $t1, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r9;
    // 0x807AA960: sw          $a3, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->r7;
    // 0x807AA964: jr          $ra
    // 0x807AA968: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x807AA968: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_805D354C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D354C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3554: jal         0x805D32D4
    // 0x805D3558: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D32D4(rdram, ctx);
        goto after_0;
    // 0x805D3558: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D355C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3560: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D3564: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805D3568: jal         0x805D3B18
    // 0x805D356C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D356C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D3570: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x805D3574: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D3578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805D357C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805D3580: addiu       $v0, $v1, 0xC4
    ctx->r2 = ADD32(ctx->r3, 0XC4);
    // 0x805D3584: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805D3588: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x805D358C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x805D3590: lw          $t7, 0x174($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X174);
    // 0x805D3594: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(471, 0X1A14) << 16);
    // 0x805D3598: addiu       $t6, $t6, 0x3444
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(471, 0X1A14));
    // 0x805D359C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805D35A0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x805D35A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D35A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D35AC: jr          $ra
    // 0x805D35B0: nop

    return;
    // 0x805D35B0: nop

;}
RECOMP_FUNC void func_80667CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80667CD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80667CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80667CDC: lui         $a0, 0x8066
    ctx->r4 = S32(RELOC_HI16(507, 0X280) << 16);
    // 0x80667CE0: lui         $a1, 0x8066
    ctx->r5 = S32(RELOC_HI16(507, 0X290) << 16);
    // 0x80667CE4: addiu       $a1, $a1, 0x7F60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(507, 0X290));
    // 0x80667CE8: addiu       $a0, $a0, 0x7F50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(507, 0X280));
    // 0x80667CEC: jal         0x8004667C
    // 0x80667CF0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80667CF0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x80667CF4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80667CF8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80667CFC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80667D00: lui         $a2, 0x8066
    ctx->r6 = S32(RELOC_HI16(507, 0X138) << 16);
    // 0x80667D04: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80667D08: lw          $t7, 0x5C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X5C);
    // 0x80667D0C: bnel        $t7, $zero, L_80667D20
    if (ctx->r15 != 0) {
        // 0x80667D10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80667D20;
    }
    goto skip_0;
    // 0x80667D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80667D14: jal         0x80057B28
    // 0x80667D18: addiu       $a2, $a2, 0x7E08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(507, 0X138));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80667D18: addiu       $a2, $a2, 0x7E08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(507, 0X138));
    after_1:
    // 0x80667D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80667D20:
    // 0x80667D20: lui         $v0, 0x8066
    ctx->r2 = S32(RELOC_HI16(507, 0X9C) << 16);
    // 0x80667D24: addiu       $v0, $v0, 0x7D6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(507, 0X9C));
    // 0x80667D28: jr          $ra
    // 0x80667D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80667D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805AB694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AB698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB69C: jal         0x805AAF60
    // 0x805AB6A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AAF60(rdram, ctx);
        goto after_0;
    // 0x805AB6A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AB6A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AB6A8: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805AB6AC: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x805AB6B0: jal         0x80065ABC
    // 0x805AB6B4: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x805AB6B4: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    after_1:
    // 0x805AB6B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AB6BC: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x805AB6C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB6C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AB6C8: jr          $ra
    // 0x805AB6CC: nop

    return;
    // 0x805AB6CC: nop

;}
RECOMP_FUNC void func_8076CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CBC0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8076CBC4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8076CBC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076CBCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076CBD0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8076CBD4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8076CBD8: jal         0x8002FCFC
    // 0x8076CBDC: nop

    func_8002FCFC(rdram, ctx);
        goto after_0;
    // 0x8076CBDC: nop

    after_0:
    // 0x8076CBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076CBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076CBE8: jr          $ra
    // 0x8076CBEC: nop

    return;
    // 0x8076CBEC: nop

;}
RECOMP_FUNC void func_80521BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521BA0: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(312, 0X10) << 16);
    // 0x80521BA4: addiu       $v0, $v0, 0x1BB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(312, 0X10));
    // 0x80521BA8: jr          $ra
    // 0x80521BAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80521BAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80742E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742E34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742E38: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742E3C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742E40: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742E44: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742E48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742E4C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742E50: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742E54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742E58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742E5C: jr          $ra
    // 0x80742E60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742E60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80010300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010300: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80010304: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80010308: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001030C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80010310: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80010314: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80010318: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x8001031C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80010320: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80010324: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80010328: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x8001032C: addiu       $t7, $t6, 0x2A30
    ctx->r15 = ADD32(ctx->r14, 0X2A30);
    // 0x80010330: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80010334: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010338: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001033C: addu        $s5, $t7, $t8
    ctx->r21 = ADD32(ctx->r15, ctx->r24);
    // 0x80010340: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80010344: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80010348: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001034C: addiu       $s3, $s3, -0x64A0
    ctx->r19 = ADD32(ctx->r19, -0X64A0);
    // 0x80010350: addiu       $s2, $s2, 0x6BE8
    ctx->r18 = ADD32(ctx->r18, 0X6BE8);
    // 0x80010354: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80010358: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001035C: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
L_80010360:
    // 0x80010360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80010364: jal         0x8000363C
    // 0x80010368: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    func_8000363C(rdram, ctx);
        goto after_0;
    // 0x80010368: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    after_0:
    // 0x8001036C: bne         $v0, $zero, L_8001037C
    if (ctx->r2 != 0) {
        // 0x80010370: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_8001037C;
    }
    // 0x80010370: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80010374: b           L_800103B4
    // 0x80010378: sw          $s3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r19;
        goto L_800103B4;
    // 0x80010378: sw          $s3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r19;
L_8001037C:
    // 0x8001037C: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x80010380: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80010384: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80010388: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001038C: sw          $s5, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r21;
    // 0x80010390: sw          $zero, 0x50($v1)
    MEM_W(0X50, ctx->r3) = 0;
    // 0x80010394: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x80010398: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x8001039C: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x800103A0: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x800103A4: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x800103A8: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x800103AC: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x800103B0: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
L_800103B4:
    // 0x800103B4: jal         0x8000D574
    // 0x800103B8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_8000D574(rdram, ctx);
        goto after_1;
    // 0x800103B8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x800103BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800103C0: bne         $s1, $s4, L_80010360
    if (ctx->r17 != ctx->r20) {
        // 0x800103C4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010360;
    }
    // 0x800103C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800103C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800103CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800103D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800103D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800103D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800103DC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800103E0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800103E4: jr          $ra
    // 0x800103E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800103E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80434340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434340: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80434344: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x80434348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043434C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80434350: beq         $t6, $zero, L_80434370
    if (ctx->r14 == 0) {
        // 0x80434354: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80434370;
    }
    // 0x80434354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80434358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043435C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80434360: jal         0x80434634
    // 0x80434364: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80434634(rdram, ctx);
        goto after_0;
    // 0x80434364: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80434368: jal         0x80433C30
    // 0x8043436C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80433C30(rdram, ctx);
        goto after_1;
    // 0x8043436C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80434370:
    // 0x80434370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80434374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80434378: jr          $ra
    // 0x8043437C: nop

    return;
    // 0x8043437C: nop

;}
RECOMP_FUNC void func_806D15C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D15C0: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(610, 0X13D4) << 16);
    // 0x806D15C4: addiu       $v0, $v0, 0x2994
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(610, 0X13D4));
    // 0x806D15C8: jr          $ra
    // 0x806D15CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806D15CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806E7DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7DA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806E7DAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806E7DB0: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x806E7DB4: addiu       $a3, $zero, 0x4027
    ctx->r7 = ADD32(0, 0X4027);
L_806E7DB8:
    // 0x806E7DB8: lw          $v0, 0x188($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X188);
    // 0x806E7DBC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x806E7DC0: beql        $v0, $zero, L_806E7DE0
    if (ctx->r2 == 0) {
        // 0x806E7DC4: lw          $v0, 0x18C($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X18C);
            goto L_806E7DE0;
    }
    goto skip_0;
    // 0x806E7DC4: lw          $v0, 0x18C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18C);
    skip_0:
    // 0x806E7DC8: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7DCC: bnel        $a3, $t6, L_806E7DE0
    if (ctx->r7 != ctx->r14) {
        // 0x806E7DD0: lw          $v0, 0x18C($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X18C);
            goto L_806E7DE0;
    }
    goto skip_1;
    // 0x806E7DD0: lw          $v0, 0x18C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18C);
    skip_1:
    // 0x806E7DD4: lbu         $t7, 0x165($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X165);
    // 0x806E7DD8: sb          $t7, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r15;
    // 0x806E7DDC: lw          $v0, 0x18C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18C);
L_806E7DE0:
    // 0x806E7DE0: beql        $v0, $zero, L_806E7E00
    if (ctx->r2 == 0) {
        // 0x806E7DE4: lw          $v0, 0x190($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X190);
            goto L_806E7E00;
    }
    goto skip_2;
    // 0x806E7DE4: lw          $v0, 0x190($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X190);
    skip_2:
    // 0x806E7DE8: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7DEC: bnel        $a3, $t8, L_806E7E00
    if (ctx->r7 != ctx->r24) {
        // 0x806E7DF0: lw          $v0, 0x190($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X190);
            goto L_806E7E00;
    }
    goto skip_3;
    // 0x806E7DF0: lw          $v0, 0x190($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X190);
    skip_3:
    // 0x806E7DF4: lbu         $t9, 0x165($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X165);
    // 0x806E7DF8: sb          $t9, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r25;
    // 0x806E7DFC: lw          $v0, 0x190($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X190);
L_806E7E00:
    // 0x806E7E00: beql        $v0, $zero, L_806E7E20
    if (ctx->r2 == 0) {
        // 0x806E7E04: lw          $v0, 0x194($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X194);
            goto L_806E7E20;
    }
    goto skip_4;
    // 0x806E7E04: lw          $v0, 0x194($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X194);
    skip_4:
    // 0x806E7E08: lhu         $t1, 0xC($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7E0C: bnel        $a3, $t1, L_806E7E20
    if (ctx->r7 != ctx->r9) {
        // 0x806E7E10: lw          $v0, 0x194($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X194);
            goto L_806E7E20;
    }
    goto skip_5;
    // 0x806E7E10: lw          $v0, 0x194($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X194);
    skip_5:
    // 0x806E7E14: lbu         $t2, 0x165($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X165);
    // 0x806E7E18: sb          $t2, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r10;
    // 0x806E7E1C: lw          $v0, 0x194($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X194);
L_806E7E20:
    // 0x806E7E20: beq         $v0, $zero, L_806E7E3C
    if (ctx->r2 == 0) {
        // 0x806E7E24: nop
    
            goto L_806E7E3C;
    }
    // 0x806E7E24: nop

    // 0x806E7E28: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7E2C: bne         $a3, $t3, L_806E7E3C
    if (ctx->r7 != ctx->r11) {
        // 0x806E7E30: nop
    
            goto L_806E7E3C;
    }
    // 0x806E7E30: nop

    // 0x806E7E34: lbu         $t4, 0x165($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X165);
    // 0x806E7E38: sb          $t4, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r12;
L_806E7E3C:
    // 0x806E7E3C: bne         $v1, $t0, L_806E7DB8
    if (ctx->r3 != ctx->r8) {
        // 0x806E7E40: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_806E7DB8;
    }
    // 0x806E7E40: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x806E7E44: jr          $ra
    // 0x806E7E48: nop

    return;
    // 0x806E7E48: nop

;}
RECOMP_FUNC void func_80553940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553940: lwc1        $f4, 0xDB8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XDB8);
    // 0x80553944: jr          $ra
    // 0x80553948: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80553948: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_807BAC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAC5C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BAC60: lhu         $t6, 0x28($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X28);
    // 0x807BAC64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x807BAC68: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x807BAC6C: sh          $t7, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r15;
    // 0x807BAC70: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BAC74: lhu         $a1, 0x28($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X28);
    // 0x807BAC78: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x807BAC7C: beql        $t9, $zero, L_807BACB8
    if (ctx->r25 == 0) {
        // 0x807BAC80: andi        $t2, $a1, 0x2
        ctx->r10 = ctx->r5 & 0X2;
            goto L_807BACB8;
    }
    goto skip_0;
    // 0x807BAC80: andi        $t2, $a1, 0x2
    ctx->r10 = ctx->r5 & 0X2;
    skip_0:
    // 0x807BAC84: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807BAC88: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807BAC8C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807BAC90: ori         $t0, $a1, 0x10
    ctx->r8 = ctx->r5 | 0X10;
    // 0x807BAC94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807BAC98: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x807BAC9C: nop

    // 0x807BACA0: bc1fl       L_807BACB8
    if (!c1cs) {
        // 0x807BACA4: andi        $t2, $a1, 0x2
        ctx->r10 = ctx->r5 & 0X2;
            goto L_807BACB8;
    }
    goto skip_1;
    // 0x807BACA4: andi        $t2, $a1, 0x2
    ctx->r10 = ctx->r5 & 0X2;
    skip_1:
    // 0x807BACA8: sh          $t0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r8;
    // 0x807BACAC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BACB0: lhu         $a1, 0x28($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X28);
    // 0x807BACB4: andi        $t2, $a1, 0x2
    ctx->r10 = ctx->r5 & 0X2;
L_807BACB8:
    // 0x807BACB8: beql        $t2, $zero, L_807BACF4
    if (ctx->r10 == 0) {
        // 0x807BACBC: andi        $t5, $a1, 0x4
        ctx->r13 = ctx->r5 & 0X4;
            goto L_807BACF4;
    }
    goto skip_2;
    // 0x807BACBC: andi        $t5, $a1, 0x4
    ctx->r13 = ctx->r5 & 0X4;
    skip_2:
    // 0x807BACC0: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x807BACC4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807BACC8: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807BACCC: ori         $t3, $a1, 0x20
    ctx->r11 = ctx->r5 | 0X20;
    // 0x807BACD0: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x807BACD4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x807BACD8: nop

    // 0x807BACDC: bc1fl       L_807BACF4
    if (!c1cs) {
        // 0x807BACE0: andi        $t5, $a1, 0x4
        ctx->r13 = ctx->r5 & 0X4;
            goto L_807BACF4;
    }
    goto skip_3;
    // 0x807BACE0: andi        $t5, $a1, 0x4
    ctx->r13 = ctx->r5 & 0X4;
    skip_3:
    // 0x807BACE4: sh          $t3, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r11;
    // 0x807BACE8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BACEC: lhu         $a1, 0x28($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X28);
    // 0x807BACF0: andi        $t5, $a1, 0x4
    ctx->r13 = ctx->r5 & 0X4;
L_807BACF4:
    // 0x807BACF4: beql        $t5, $zero, L_807BAD30
    if (ctx->r13 == 0) {
        // 0x807BACF8: andi        $t8, $a1, 0x8
        ctx->r24 = ctx->r5 & 0X8;
            goto L_807BAD30;
    }
    goto skip_4;
    // 0x807BACF8: andi        $t8, $a1, 0x8
    ctx->r24 = ctx->r5 & 0X8;
    skip_4:
    // 0x807BACFC: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x807BAD00: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807BAD04: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807BAD08: ori         $t6, $a1, 0x40
    ctx->r14 = ctx->r5 | 0X40;
    // 0x807BAD0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807BAD10: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x807BAD14: nop

    // 0x807BAD18: bc1fl       L_807BAD30
    if (!c1cs) {
        // 0x807BAD1C: andi        $t8, $a1, 0x8
        ctx->r24 = ctx->r5 & 0X8;
            goto L_807BAD30;
    }
    goto skip_5;
    // 0x807BAD1C: andi        $t8, $a1, 0x8
    ctx->r24 = ctx->r5 & 0X8;
    skip_5:
    // 0x807BAD20: sh          $t6, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r14;
    // 0x807BAD24: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BAD28: lhu         $a1, 0x28($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X28);
    // 0x807BAD2C: andi        $t8, $a1, 0x8
    ctx->r24 = ctx->r5 & 0X8;
L_807BAD30:
    // 0x807BAD30: beq         $t8, $zero, L_807BAD60
    if (ctx->r24 == 0) {
        // 0x807BAD34: nop
    
            goto L_807BAD60;
    }
    // 0x807BAD34: nop

    // 0x807BAD38: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x807BAD3C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807BAD40: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807BAD44: ori         $t9, $a1, 0x80
    ctx->r25 = ctx->r5 | 0X80;
    // 0x807BAD48: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807BAD4C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x807BAD50: nop

    // 0x807BAD54: bc1f        L_807BAD60
    if (!c1cs) {
        // 0x807BAD58: nop
    
            goto L_807BAD60;
    }
    // 0x807BAD58: nop

    // 0x807BAD5C: sh          $t9, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r25;
L_807BAD60:
    // 0x807BAD60: jr          $ra
    // 0x807BAD64: nop

    return;
    // 0x807BAD64: nop

;}
RECOMP_FUNC void func_804C8940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8940: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(225, 0X834) << 16);
    // 0x804C8944: addiu       $v0, $v0, -0x6E8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(225, 0X834));
    // 0x804C8948: jr          $ra
    // 0x804C894C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804C894C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80446478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446478: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044647C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446480: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446484: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80446488: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044648C: sw          $t6, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = ctx->r14;
    // 0x80446490: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80446494: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x80446498: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x8044649C: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x804464A0: sw          $a1, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r5;
    // 0x804464A4: sw          $v1, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r3;
    // 0x804464A8: sw          $a1, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r5;
    // 0x804464AC: jr          $ra
    // 0x804464B0: sw          $t7, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r15;
    return;
    // 0x804464B0: sw          $t7, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_804A4E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4E34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4E38: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4E3C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4E40: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4E44: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4E48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4E4C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4E50: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4E54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4E58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4E5C: jr          $ra
    // 0x804A4E60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4E60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044B740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B740: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8044B744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044B748: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8044B74C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8044B750: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8044B754: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8044B758: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8044B75C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8044B760: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8044B764: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B768: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x8044B76C: lui         $t8, 0x8045
    ctx->r24 = S32(RELOC_HI16(98, 0X137B4) << 16);
    // 0x8044B770: addiu       $t8, $t8, 0x7B94
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(98, 0X137B4));
    // 0x8044B774: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8044B778: addiu       $s0, $a1, 0x10
    ctx->r16 = ADD32(ctx->r5, 0X10);
    // 0x8044B77C: addiu       $s1, $a1, 0x2C
    ctx->r17 = ADD32(ctx->r5, 0X2C);
    // 0x8044B780: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x8044B784: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8044B788: jal         0x8044B6B4
    // 0x8044B78C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_8044B6B4(rdram, ctx);
        goto after_0;
    // 0x8044B78C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x8044B790: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8044B794: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B798: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8044B79C: addu        $v1, $t0, $at
    ctx->r3 = ADD32(ctx->r8, ctx->r1);
    // 0x8044B7A0: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8044B7A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044B7A8: lwc1        $f0, 0x6F14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6F14);
    // 0x8044B7AC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8044B7B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044B7B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8044B7B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8044B7BC: bc1f        L_8044B7DC
    if (!c1cs) {
        // 0x8044B7C0: nop
    
            goto L_8044B7DC;
    }
    // 0x8044B7C0: nop

    // 0x8044B7C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044B7C8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B7CC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8044B7D0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8044B7D4: b           L_8044B944
    // 0x8044B7D8: swc1        $f8, 0x6F14($at)
    MEM_W(0X6F14, ctx->r1) = ctx->f8.u32l;
        goto L_8044B944;
    // 0x8044B7D8: swc1        $f8, 0x6F14($at)
    MEM_W(0X6F14, ctx->r1) = ctx->f8.u32l;
L_8044B7DC:
    // 0x8044B7DC: lw          $a0, 0x7EA8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EA8);
    // 0x8044B7E0: lb          $a1, 0x3($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X3);
    // 0x8044B7E4: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8044B7E8: bnel        $at, $zero, L_8044B838
    if (ctx->r1 != 0) {
        // 0x8044B7EC: slti        $at, $a1, -0x5
        ctx->r1 = SIGNED(ctx->r5) < -0X5 ? 1 : 0;
            goto L_8044B838;
    }
    goto skip_0;
    // 0x8044B7EC: slti        $at, $a1, -0x5
    ctx->r1 = SIGNED(ctx->r5) < -0X5 ? 1 : 0;
    skip_0:
    // 0x8044B7F0: lbu         $t1, 0x6C80($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X6C80);
    // 0x8044B7F4: addiu       $a3, $a2, 0x5C
    ctx->r7 = ADD32(ctx->r6, 0X5C);
    // 0x8044B7F8: beql        $t1, $zero, L_8044B838
    if (ctx->r9 == 0) {
        // 0x8044B7FC: slti        $at, $a1, -0x5
        ctx->r1 = SIGNED(ctx->r5) < -0X5 ? 1 : 0;
            goto L_8044B838;
    }
    goto skip_1;
    // 0x8044B7FC: slti        $at, $a1, -0x5
    ctx->r1 = SIGNED(ctx->r5) < -0X5 ? 1 : 0;
    skip_1:
    // 0x8044B800: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8044B804: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8044B808: beq         $at, $zero, L_8044B818
    if (ctx->r1 == 0) {
        // 0x8044B80C: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_8044B818;
    }
    // 0x8044B80C: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8044B810: b           L_8044B81C
    // 0x8044B814: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
        goto L_8044B81C;
    // 0x8044B814: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_8044B818:
    // 0x8044B818: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_8044B81C:
    // 0x8044B81C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B820: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8044B824: jal         0x80445C4C
    // 0x8044B828: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    func_80445C4C(rdram, ctx);
        goto after_1;
    // 0x8044B828: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    after_1:
    // 0x8044B82C: b           L_8044B948
    // 0x8044B830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8044B948;
    // 0x8044B830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044B834: slti        $at, $a1, -0x5
    ctx->r1 = SIGNED(ctx->r5) < -0X5 ? 1 : 0;
L_8044B838:
    // 0x8044B838: beql        $at, $zero, L_8044B880
    if (ctx->r1 == 0) {
        // 0x8044B83C: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_8044B880;
    }
    goto skip_2;
    // 0x8044B83C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_2:
    // 0x8044B840: lbu         $t3, 0x6C80($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X6C80);
    // 0x8044B844: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B848: addiu       $a3, $a2, 0x5C
    ctx->r7 = ADD32(ctx->r6, 0X5C);
    // 0x8044B84C: beq         $t3, $zero, L_8044B87C
    if (ctx->r11 == 0) {
        // 0x8044B850: addu        $at, $at, $t0
        ctx->r1 = ADD32(ctx->r1, ctx->r8);
            goto L_8044B87C;
    }
    // 0x8044B850: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8044B854: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8044B858: blez        $v1, L_8044B868
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8044B85C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8044B868;
    }
    // 0x8044B85C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8044B860: b           L_8044B86C
    // 0x8044B864: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
        goto L_8044B86C;
    // 0x8044B864: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
L_8044B868:
    // 0x8044B868: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_8044B86C:
    // 0x8044B86C: jal         0x80445C4C
    // 0x8044B870: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    func_80445C4C(rdram, ctx);
        goto after_2;
    // 0x8044B870: sb          $zero, 0x6C80($at)
    MEM_B(0X6C80, ctx->r1) = 0;
    after_2:
    // 0x8044B874: b           L_8044B948
    // 0x8044B878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8044B948;
    // 0x8044B878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8044B87C:
    // 0x8044B87C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8044B880:
    // 0x8044B880: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8044B884: addiu       $a3, $a2, 0x5C
    ctx->r7 = ADD32(ctx->r6, 0X5C);
    // 0x8044B888: andi        $t5, $v0, 0x1000
    ctx->r13 = ctx->r2 & 0X1000;
    // 0x8044B88C: beq         $t5, $at, L_8044B8A0
    if (ctx->r13 == ctx->r1) {
        // 0x8044B890: andi        $t6, $v0, 0x8000
        ctx->r14 = ctx->r2 & 0X8000;
            goto L_8044B8A0;
    }
    // 0x8044B890: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x8044B894: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8044B898: bnel        $t6, $at, L_8044B948
    if (ctx->r14 != ctx->r1) {
        // 0x8044B89C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8044B948;
    }
    goto skip_3;
    // 0x8044B89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
L_8044B8A0:
    // 0x8044B8A0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8044B8A4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8044B8A8: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X1377C) << 16);
    // 0x8044B8AC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8044B8B0: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8044B8B4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8044B8B8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8044B8BC: lh          $v0, 0x7B5C($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(98, 0X1377C));
    // 0x8044B8C0: bltzl       $v0, L_8044B948
    if (SIGNED(ctx->r2) < 0) {
        // 0x8044B8C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8044B948;
    }
    goto skip_4;
    // 0x8044B8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8044B8C8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8044B8CC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8044B8D0: jal         0x804459EC
    // 0x8044B8D4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_804459EC(rdram, ctx);
        goto after_3;
    // 0x8044B8D4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x8044B8D8: jal         0x80445C24
    // 0x8044B8DC: nop

    func_80445C24(rdram, ctx);
        goto after_4;
    // 0x8044B8DC: nop

    after_4:
    // 0x8044B8E0: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8044B8E4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8044B8E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8044B8EC: sb          $t3, -0x7204($at)
    MEM_B(-0X7204, ctx->r1) = ctx->r11;
    // 0x8044B8F0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8044B8F4: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8044B8F8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8044B8FC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8044B900: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8044B904: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8044B908: jal         0x8044B6D8
    // 0x8044B90C: sb          $t4, -0x7203($at)
    MEM_B(-0X7203, ctx->r1) = ctx->r12;
    func_8044B6D8(rdram, ctx);
        goto after_5;
    // 0x8044B90C: sb          $t4, -0x7203($at)
    MEM_B(-0X7203, ctx->r1) = ctx->r12;
    after_5:
    // 0x8044B910: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8044B914: lui         $t7, 0x8045
    ctx->r15 = S32(RELOC_HI16(98, 0X13904) << 16);
    // 0x8044B918: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8044B91C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8044B920: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8044B924: lw          $t7, 0x7CE4($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(98, 0X13904));
    // 0x8044B928: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B92C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8044B930: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8044B934: sw          $t7, 0x6F04($at)
    MEM_W(0X6F04, ctx->r1) = ctx->r15;
    // 0x8044B938: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B93C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8044B940: swc1        $f10, 0x6F14($at)
    MEM_W(0X6F14, ctx->r1) = ctx->f10.u32l;
L_8044B944:
    // 0x8044B944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8044B948:
    // 0x8044B948: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8044B94C:
    // 0x8044B94C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8044B950: jal         0x80065490
    // 0x8044B954: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80065490(rdram, ctx);
        goto after_6;
    // 0x8044B954: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_6:
    // 0x8044B958: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8044B95C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8044B960: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8044B964: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8044B968: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8044B96C: bnel        $at, $zero, L_8044B94C
    if (ctx->r1 != 0) {
        // 0x8044B970: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8044B94C;
    }
    goto skip_5;
    // 0x8044B970: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
    // 0x8044B974: bltz        $s3, L_8044B9C8
    if (SIGNED(ctx->r19) < 0) {
        // 0x8044B978: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8044B9C8;
    }
    // 0x8044B978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044B97C: addiu       $a0, $s3, 0x1
    ctx->r4 = ADD32(ctx->r19, 0X1);
    // 0x8044B980: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x8044B984: beq         $a0, $zero, L_8044B9A8
    if (ctx->r4 == 0) {
        // 0x8044B988: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8044B9A8;
    }
    // 0x8044B988: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8044B98C:
    // 0x8044B98C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8044B990: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8044B994: bne         $v1, $v0, L_8044B98C
    if (ctx->r3 != ctx->r2) {
        // 0x8044B998: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8044B98C;
    }
    // 0x8044B998: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8044B99C: addiu       $t9, $s3, 0x1
    ctx->r25 = ADD32(ctx->r19, 0X1);
    // 0x8044B9A0: beql        $t9, $v0, L_8044B9CC
    if (ctx->r25 == ctx->r2) {
        // 0x8044B9A4: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_8044B9CC;
    }
    goto skip_6;
    // 0x8044B9A4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_6:
L_8044B9A8:
    // 0x8044B9A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8044B9AC: addiu       $t8, $s3, 0x1
    ctx->r24 = ADD32(ctx->r19, 0X1);
    // 0x8044B9B0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8044B9B4: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x8044B9B8: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8044B9BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8044B9C0: bne         $t8, $v0, L_8044B9A8
    if (ctx->r24 != ctx->r2) {
        // 0x8044B9C4: sb          $zero, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = 0;
            goto L_8044B9A8;
    }
    // 0x8044B9C4: sb          $zero, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = 0;
L_8044B9C8:
    // 0x8044B9C8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_8044B9CC:
    // 0x8044B9CC: beq         $at, $zero, L_8044B9E8
    if (ctx->r1 == 0) {
        // 0x8044B9D0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8044B9E8;
    }
    // 0x8044B9D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8044B9D4:
    // 0x8044B9D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8044B9D8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8044B9DC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8044B9E0: bne         $at, $zero, L_8044B9D4
    if (ctx->r1 != 0) {
        // 0x8044B9E4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8044B9D4;
    }
    // 0x8044B9E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8044B9E8:
    // 0x8044B9E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044B9EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8044B9F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8044B9F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B9F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8044B9FC: jr          $ra
    // 0x8044BA00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8044BA00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80740EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80740EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80740EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80740EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80740EEC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80740EF0: jalr        $t9
    // 0x80740EF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80740EF4: nop

    after_0:
    // 0x80740EF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80740EFC: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x80740F00: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80740F04: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80740F08: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80740F0C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80740F10: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80740F14: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80740F18: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x80740F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80740F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80740F24: jr          $ra
    // 0x80740F28: nop

    return;
    // 0x80740F28: nop

;}
RECOMP_FUNC void func_8005160C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005160C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051614: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051618: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005161C: sw          $zero, -0x57C4($at)
    MEM_W(-0X57C4, ctx->r1) = 0;
    // 0x80051620: addiu       $a0, $a0, -0x57C0
    ctx->r4 = ADD32(ctx->r4, -0X57C0);
    // 0x80051624: addiu       $a1, $zero, 0xA50
    ctx->r5 = ADD32(0, 0XA50);
    // 0x80051628: jal         0x80065728
    // 0x8005162C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8005162C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80051630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051638: jr          $ra
    // 0x8005163C: nop

    return;
    // 0x8005163C: nop

;}
RECOMP_FUNC void func_80433B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433B0C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80433B10: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80433B14: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X294C) << 16);
    // 0x80433B18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80433B1C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80433B20: lw          $t8, 0x63FC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(71, 0X294C));
    // 0x80433B24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80433B28: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80433B2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80433B30: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80433B34: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80433B38: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80433B3C: beql        $v1, $zero, L_80433B70
    if (ctx->r3 == 0) {
        // 0x80433B40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80433B70;
    }
    goto skip_0;
    // 0x80433B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80433B44: jalr        $v1
    // 0x80433B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80433B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80433B4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80433B50: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80433B54: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80433B58: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80433B5C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80433B60: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80433B64: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80433B68: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80433B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80433B70:
    // 0x80433B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80433B74: jr          $ra
    // 0x80433B78: nop

    return;
    // 0x80433B78: nop

;}
RECOMP_FUNC void func_80019C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019C4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019C50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80019C54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80019C58: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80019C5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80019C60: jal         0x80019B94
    // 0x80019C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80019B94(rdram, ctx);
        goto after_0;
    // 0x80019C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80019C68: beq         $v0, $zero, L_80019CA0
    if (ctx->r2 == 0) {
        // 0x80019C6C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80019CA0;
    }
    // 0x80019C6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80019C70: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80019C74: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_80019C78:
    // 0x80019C78: bnel        $s1, $t6, L_80019C98
    if (ctx->r17 != ctx->r14) {
        // 0x80019C7C: lw          $s0, 0x44($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X44);
            goto L_80019C98;
    }
    goto skip_0;
    // 0x80019C7C: lw          $s0, 0x44($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X44);
    skip_0:
    // 0x80019C80: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80019C84: bnel        $s2, $t7, L_80019C98
    if (ctx->r18 != ctx->r15) {
        // 0x80019C88: lw          $s0, 0x44($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X44);
            goto L_80019C98;
    }
    goto skip_1;
    // 0x80019C88: lw          $s0, 0x44($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X44);
    skip_1:
    // 0x80019C8C: jal         0x80019A78
    // 0x80019C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80019A78(rdram, ctx);
        goto after_1;
    // 0x80019C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80019C94: lw          $s0, 0x44($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X44);
L_80019C98:
    // 0x80019C98: bnel        $s0, $zero, L_80019C78
    if (ctx->r16 != 0) {
        // 0x80019C9C: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80019C78;
    }
    goto skip_2;
    // 0x80019C9C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_2:
L_80019CA0:
    // 0x80019CA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80019CA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80019CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80019CAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80019CB0: jr          $ra
    // 0x80019CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80019CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805D79A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D79A8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805D79AC: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(474, 0X718) << 16);
    // 0x805D79B0: addiu       $t6, $t6, -0x7FE8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(474, 0X718));
    // 0x805D79B4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805D79B8: lui         $t2, 0x805E
    ctx->r10 = S32(RELOC_HI16(474, 0X7E0) << 16);
    // 0x805D79BC: addiu       $t2, $t2, -0x7F20
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(474, 0X7E0));
    // 0x805D79C0: sw          $t6, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r14;
    // 0x805D79C4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D79C8: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x805D79CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805D79D0: lbu         $t0, 0x20($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X20);
    // 0x805D79D4: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x805D79D8: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x805D79DC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805D79E0: sw          $t2, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r10;
    // 0x805D79E4: jr          $ra
    // 0x805D79E8: sb          $t5, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r13;
    return;
    // 0x805D79E8: sb          $t5, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void func_80072470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072478: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8007247C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80072480: sw          $t6, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r14;
    // 0x80072484: lw          $t7, 0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X40);
    // 0x80072488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007248C: beq         $t7, $zero, L_800724A8
    if (ctx->r15 == 0) {
        // 0x80072490: nop
    
            goto L_800724A8;
    }
    // 0x80072490: nop

    // 0x80072494: lw          $a0, 0x40($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X40);
    // 0x80072498: lw          $a1, 0x44($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X44);
    // 0x8007249C: jal         0x80082210
    // 0x800724A0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800724A0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800724A4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_800724A8:
    // 0x800724A8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800724AC: addiu       $a0, $a0, -0x2730
    ctx->r4 = ADD32(ctx->r4, -0X2730);
    // 0x800724B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800724B4: jal         0x80082210
    // 0x800724B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800724B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800724BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800724C4: jr          $ra
    // 0x800724C8: nop

    return;
    // 0x800724C8: nop

;}
RECOMP_FUNC void func_806F7AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7AE4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7AE8: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x806F7AEC: ori         $t7, $t7, 0x103F
    ctx->r15 = ctx->r15 | 0X103F;
    // 0x806F7AF0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x806F7AF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7AF8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x806F7AFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x806F7B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7B04: lui         $t9, 0xB100
    ctx->r25 = S32(0XB100 << 16);
    // 0x806F7B08: lui         $t0, 0x6
    ctx->r8 = S32(0X6 << 16);
    // 0x806F7B0C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x806F7B10: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806F7B14: ori         $t0, $t0, 0x4
    ctx->r8 = ctx->r8 | 0X4;
    // 0x806F7B18: ori         $t9, $t9, 0x204
    ctx->r25 = ctx->r25 | 0X204;
    // 0x806F7B1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x806F7B20: jr          $ra
    // 0x806F7B24: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    return;
    // 0x806F7B24: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void func_8004F8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F8B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004F8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F8C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004F8C4: lw          $v1, 0x1B8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004F8C8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004F8CC: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8004F8D0: lh          $a0, 0x2($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X2);
    // 0x8004F8D4: jal         0x8006A99C
    // 0x8004F8D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8004F8D8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004F8DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004F8E0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8004F8E4: sh          $v0, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r2;
    // 0x8004F8E8: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8004F8EC: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x8004F8F0: jal         0x8006A99C
    // 0x8004F8F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8004F8F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8004F8F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F8FC: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8004F900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004F908: jr          $ra
    // 0x8004F90C: nop

    return;
    // 0x8004F90C: nop

;}
RECOMP_FUNC void func_8046AAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AAB0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8046AAB4: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x8046AAB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046AABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046AAC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046AAC4: lb          $t8, 0x3($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X3);
    // 0x8046AAC8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X297C) << 16);
    // 0x8046AACC: lwc1        $f6, -0x3F44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X297C));
    // 0x8046AAD0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8046AAD4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2980) << 16);
    // 0x8046AAD8: lwc1        $f10, -0x3F40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2980));
    // 0x8046AADC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8046AAE0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046AAE4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046AAE8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8046AAEC: nop

    // 0x8046AAF0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8046AAF4: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8046AAF8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8046AAFC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046AB00: jal         0x804697D8
    // 0x8046AB04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x8046AB04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046AB08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046AB0C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8046AB10: jal         0x8046AA48
    // 0x8046AB14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8046AA48(rdram, ctx);
        goto after_1;
    // 0x8046AB14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8046AB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046AB1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046AB20: jr          $ra
    // 0x8046AB24: nop

    return;
    // 0x8046AB24: nop

;}
RECOMP_FUNC void func_806FDDE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDDE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806FDDEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FDDF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806FDDF4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806FDDF8: jal         0x80057754
    // 0x806FDDFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80057754(rdram, ctx);
        goto after_0;
    // 0x806FDDFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x806FDE00: jal         0x806FD7F8
    // 0x806FDE04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806FD7F8(rdram, ctx);
        goto after_1;
    // 0x806FDE04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x806FDE08: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806FDE0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FDE10: jal         0x806FD60C
    // 0x806FDE14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806FD60C(rdram, ctx);
        goto after_2;
    // 0x806FDE14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x806FDE18: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806FDE1C: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x806FDE20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806FDE24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806FDE28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806FDE2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDE30: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806FDE34: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x806FDE38: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806FDE3C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x806FDE40: nop

    // 0x806FDE44: bc1f        L_806FDE54
    if (!c1cs) {
        // 0x806FDE48: nop
    
            goto L_806FDE54;
    }
    // 0x806FDE48: nop

    // 0x806FDE4C: jal         0x806FE468
    // 0x806FDE50: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_806FE468(rdram, ctx);
        goto after_3;
    // 0x806FDE50: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_3:
L_806FDE54:
    // 0x806FDE54: jal         0x806FDA5C
    // 0x806FDE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806FDA5C(rdram, ctx);
        goto after_4;
    // 0x806FDE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x806FDE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FDE60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806FDE64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806FDE68: jr          $ra
    // 0x806FDE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806FDE6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804544C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804544C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804544CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804544D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804544D4: jr          $ra
    // 0x804544D8: sw          $zero, 0x6A38($at)
    MEM_W(0X6A38, ctx->r1) = 0;
    return;
    // 0x804544D8: sw          $zero, 0x6A38($at)
    MEM_W(0X6A38, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80678620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678620: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80678624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80678628: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067862C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80678630: jal         0x8004700C
    // 0x80678634: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80678634: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80678638: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8067863C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80678640: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80678644: lh          $v1, 0x408($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X408);
    // 0x80678648: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8067864C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80678650: blez        $v1, L_80678664
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80678654: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80678664;
    }
    // 0x80678654: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80678658: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8067865C: b           L_8067866C
    // 0x80678660: sh          $t6, 0x408($a1)
    MEM_H(0X408, ctx->r5) = ctx->r14;
        goto L_8067866C;
    // 0x80678660: sh          $t6, 0x408($a1)
    MEM_H(0X408, ctx->r5) = ctx->r14;
L_80678664:
    // 0x80678664: addiu       $t7, $zero, 0x3F
    ctx->r15 = ADD32(0, 0X3F);
    // 0x80678668: sh          $t7, 0x408($a1)
    MEM_H(0X408, ctx->r5) = ctx->r15;
L_8067866C:
    // 0x8067866C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80678670: lwc1        $f4, 0x40C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40C);
    // 0x80678674: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80678678: swc1        $f6, 0x40C($a1)
    MEM_W(0X40C, ctx->r5) = ctx->f6.u32l;
    // 0x8067867C: lwc1        $f0, 0x40C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X40C);
    // 0x80678680: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80678684: nop

    // 0x80678688: bc1fl       L_8067869C
    if (!c1cs) {
        // 0x8067868C: lh          $v1, 0x408($a1)
        ctx->r3 = MEM_H(ctx->r5, 0X408);
            goto L_8067869C;
    }
    goto skip_0;
    // 0x8067868C: lh          $v1, 0x408($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X408);
    skip_0:
    // 0x80678690: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80678694: swc1        $f8, 0x40C($a1)
    MEM_W(0X40C, ctx->r5) = ctx->f8.u32l;
    // 0x80678698: lh          $v1, 0x408($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X408);
L_8067869C:
    // 0x8067869C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806786A0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x806786A4: addu        $v0, $a1, $t8
    ctx->r2 = ADD32(ctx->r5, ctx->r24);
    // 0x806786A8: swc1        $f10, 0x308($v0)
    MEM_W(0X308, ctx->r2) = ctx->f10.u32l;
    // 0x806786AC: lwc1        $f12, 0x40C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X40C);
    // 0x806786B0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x806786B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x806786B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806786BC: jal         0x80066DE4
    // 0x806786C0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806786C0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x806786C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x806786C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806786CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806786D0: lbu         $a0, 0x30($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X30);
    // 0x806786D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806786D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806786DC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x806786E0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806786E4: beq         $a0, $at, L_806787B4
    if (ctx->r4 == ctx->r1) {
        // 0x806786E8: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_806787B4;
    }
    // 0x806786E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x806786EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806786F0: beq         $a0, $at, L_80678708
    if (ctx->r4 == ctx->r1) {
        // 0x806786F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80678708;
    }
    // 0x806786F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806786F8: beq         $a0, $at, L_80678760
    if (ctx->r4 == ctx->r1) {
        // 0x806786FC: nop
    
            goto L_80678760;
    }
    // 0x806786FC: nop

    // 0x80678700: b           L_806787B8
    // 0x80678704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_806787B8;
    // 0x80678704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80678708:
    // 0x80678708: beql        $a2, $zero, L_806787B8
    if (ctx->r6 == 0) {
        // 0x8067870C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_806787B8;
    }
    goto skip_1;
    // 0x8067870C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80678710: lwc1        $f14, 0x88($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X88);
    // 0x80678714: lwc1        $f12, 0x88($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X88);
    // 0x80678718: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(538, 0X1460) << 16);
    // 0x8067871C: sub.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80678720: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80678724: nop

    // 0x80678728: bc1fl       L_80678740
    if (!c1cs) {
        // 0x8067872C: add.s       $f6, $f14, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
            goto L_80678740;
    }
    goto skip_2;
    // 0x8067872C: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    skip_2:
    // 0x80678730: lwc1        $f4, -0x6C30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(538, 0X1460));
    // 0x80678734: b           L_806787B4
    // 0x80678738: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
        goto L_806787B4;
    // 0x80678738: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8067873C: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
L_80678740:
    // 0x80678740: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(538, 0X1464) << 16);
    // 0x80678744: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80678748: nop

    // 0x8067874C: bc1fl       L_806787B8
    if (!c1cs) {
        // 0x80678750: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_806787B8;
    }
    goto skip_3;
    // 0x80678750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_3:
    // 0x80678754: lwc1        $f8, -0x6C2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(538, 0X1464));
    // 0x80678758: b           L_806787B4
    // 0x8067875C: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
        goto L_806787B4;
    // 0x8067875C: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
L_80678760:
    // 0x80678760: beql        $a2, $zero, L_806787B8
    if (ctx->r6 == 0) {
        // 0x80678764: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_806787B8;
    }
    goto skip_4;
    // 0x80678764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_4:
    // 0x80678768: lwc1        $f14, 0x88($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8067876C: lwc1        $f12, 0x88($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X88);
    // 0x80678770: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(538, 0X1468) << 16);
    // 0x80678774: sub.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80678778: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8067877C: nop

    // 0x80678780: bc1fl       L_80678798
    if (!c1cs) {
        // 0x80678784: add.s       $f4, $f14, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
            goto L_80678798;
    }
    goto skip_5;
    // 0x80678784: add.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
    skip_5:
    // 0x80678788: lwc1        $f18, -0x6C28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(538, 0X1468));
    // 0x8067878C: b           L_806787B4
    // 0x80678790: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
        goto L_806787B4;
    // 0x80678790: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80678794: add.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
L_80678798:
    // 0x80678798: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(538, 0X146C) << 16);
    // 0x8067879C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x806787A0: nop

    // 0x806787A4: bc1fl       L_806787B8
    if (!c1cs) {
        // 0x806787A8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_806787B8;
    }
    goto skip_6;
    // 0x806787A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_6:
    // 0x806787AC: lwc1        $f6, -0x6C24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(538, 0X146C));
    // 0x806787B0: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
L_806787B4:
    // 0x806787B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_806787B8:
    // 0x806787B8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
L_806787BC:
    // 0x806787BC: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x806787C0: bnel        $at, $zero, L_806787D4
    if (ctx->r1 != 0) {
        // 0x806787C4: lwc1        $f8, 0x308($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X308);
            goto L_806787D4;
    }
    goto skip_7;
    // 0x806787C4: lwc1        $f8, 0x308($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X308);
    skip_7:
    // 0x806787C8: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x806787CC: addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // 0x806787D0: lwc1        $f8, 0x308($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X308);
L_806787D4:
    // 0x806787D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x806787D8: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x806787DC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x806787E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x806787E4: bne         $at, $zero, L_806787F4
    if (ctx->r1 != 0) {
        // 0x806787E8: swc1        $f10, 0x304($v0)
        MEM_W(0X304, ctx->r2) = ctx->f10.u32l;
            goto L_806787F4;
    }
    // 0x806787E8: swc1        $f10, 0x304($v0)
    MEM_W(0X304, ctx->r2) = ctx->f10.u32l;
    // 0x806787EC: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x806787F0: addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
L_806787F4:
    // 0x806787F4: lwc1        $f18, 0x308($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X308);
    // 0x806787F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x806787FC: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x80678800: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80678804: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80678808: bne         $at, $zero, L_80678818
    if (ctx->r1 != 0) {
        // 0x8067880C: swc1        $f4, 0x304($v0)
        MEM_W(0X304, ctx->r2) = ctx->f4.u32l;
            goto L_80678818;
    }
    // 0x8067880C: swc1        $f4, 0x304($v0)
    MEM_W(0X304, ctx->r2) = ctx->f4.u32l;
    // 0x80678810: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80678814: addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
L_80678818:
    // 0x80678818: lwc1        $f6, 0x308($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X308);
    // 0x8067881C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80678820: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x80678824: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80678828: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8067882C: bne         $at, $zero, L_8067883C
    if (ctx->r1 != 0) {
        // 0x80678830: swc1        $f8, 0x304($v0)
        MEM_W(0X304, ctx->r2) = ctx->f8.u32l;
            goto L_8067883C;
    }
    // 0x80678830: swc1        $f8, 0x304($v0)
    MEM_W(0X304, ctx->r2) = ctx->f8.u32l;
    // 0x80678834: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80678838: addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
L_8067883C:
    // 0x8067883C: lwc1        $f10, 0x308($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X308);
    // 0x80678840: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80678844: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80678848: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8067884C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80678850: bne         $a0, $a1, L_806787BC
    if (ctx->r4 != ctx->r5) {
        // 0x80678854: swc1        $f18, 0x304($v0)
        MEM_W(0X304, ctx->r2) = ctx->f18.u32l;
            goto L_806787BC;
    }
    // 0x80678854: swc1        $f18, 0x304($v0)
    MEM_W(0X304, ctx->r2) = ctx->f18.u32l;
    // 0x80678858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067885C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80678860: jr          $ra
    // 0x80678864: nop

    return;
    // 0x80678864: nop

;}
RECOMP_FUNC void func_80525F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525F94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80525F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80525F9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80525FA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80525FA4: jal         0x80526290
    // 0x80525FA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_80526290(rdram, ctx);
        goto after_0;
    // 0x80525FA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x80525FAC: beq         $v0, $zero, L_805260C0
    if (ctx->r2 == 0) {
        // 0x80525FB0: nop
    
            goto L_805260C0;
    }
    // 0x80525FB0: nop

    // 0x80525FB4: jal         0x8052634C
    // 0x80525FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052634C(rdram, ctx);
        goto after_1;
    // 0x80525FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80525FBC: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80525FC0: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(327, 0X610C) << 16);
    // 0x80525FC4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80525FC8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80525FCC: addiu       $t6, $t6, -0x3FF4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0X610C));
    // 0x80525FD0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80525FD4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80525FD8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80525FDC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80525FE0: sh          $t8, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r24;
    // 0x80525FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80525FE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80525FEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80525FF0: jal         0x80527EA0
    // 0x80525FF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80527EA0(rdram, ctx);
        goto after_2;
    // 0x80525FF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80525FF8: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80525FFC: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(327, 0X5B4) << 16);
    // 0x80526000: addiu       $t9, $t9, 0x64B4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(327, 0X5B4));
    // 0x80526004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80526008: jal         0x80525F7C
    // 0x8052600C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80525F7C(rdram, ctx);
        goto after_3;
    // 0x8052600C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_3:
    // 0x80526010: jal         0x80047090
    // 0x80526014: addiu       $a0, $zero, 0x41EE
    ctx->r4 = ADD32(0, 0X41EE);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x80526014: addiu       $a0, $zero, 0x41EE
    ctx->r4 = ADD32(0, 0X41EE);
    after_4:
    // 0x80526018: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8052601C: bne         $v0, $at, L_80526034
    if (ctx->r2 != ctx->r1) {
        // 0x80526020: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80526034;
    }
    // 0x80526020: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80526024: jal         0x800445A4
    // 0x80526028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x80526028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8052602C: b           L_805260CC
    // 0x80526030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805260CC;
    // 0x80526030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80526034:
    // 0x80526034: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80526038: lui         $at, 0x41EE
    ctx->r1 = S32(0X41EE << 16);
    // 0x8052603C: ori         $at, $at, 0x400
    ctx->r1 = ctx->r1 | 0X400;
    // 0x80526040: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80526044: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80526048: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8052604C: jal         0x8004613C
    // 0x80526050: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x80526050: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_6:
    // 0x80526054: bne         $v0, $zero, L_8052606C
    if (ctx->r2 != 0) {
        // 0x80526058: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8052606C;
    }
    // 0x80526058: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8052605C: jal         0x800445A4
    // 0x80526060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x80526060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80526064: b           L_805260CC
    // 0x80526068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805260CC;
    // 0x80526068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052606C:
    // 0x8052606C: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80526070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80526074: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80526078: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x8052607C: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80526080: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
    // 0x80526084: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80526088: swc1        $f8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f8.u32l;
    // 0x8052608C: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x80526090: jal         0x80047F9C
    // 0x80526094: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80526094: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_8:
    // 0x80526098: jal         0x805260DC
    // 0x8052609C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805260DC(rdram, ctx);
        goto after_9;
    // 0x8052609C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x805260A0: jal         0x8005FDC4
    // 0x805260A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_10;
    // 0x805260A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x805260A8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x805260AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805260B0: jal         0x8052675C
    // 0x805260B4: sw          $s1, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r17;
    func_8052675C(rdram, ctx);
        goto after_11;
    // 0x805260B4: sw          $s1, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r17;
    after_11:
    // 0x805260B8: b           L_805260CC
    // 0x805260BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805260CC;
    // 0x805260BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805260C0:
    // 0x805260C0: jal         0x800445A4
    // 0x805260C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_12;
    // 0x805260C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x805260C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805260CC:
    // 0x805260CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805260D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805260D4: jr          $ra
    // 0x805260D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805260D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80673A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673A7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80673A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80673A84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80673A88: jal         0x80673808
    // 0x80673A8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80673808(rdram, ctx);
        goto after_0;
    // 0x80673A8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80673A90: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80673A94: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80673A98: lwc1        $f14, 0x24($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80673A9C: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x80673AA0: jal         0x80065ABC
    // 0x80673AA4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x80673AA4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80673AA8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80673AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673AB0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80673AB4: jal         0x80049D74
    // 0x80673AB8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x80673AB8: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x80673ABC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80673AC0: addiu       $a2, $a2, -0x2FC8
    ctx->r6 = ADD32(ctx->r6, -0X2FC8);
    // 0x80673AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673AC8: jal         0x8004D328
    // 0x80673ACC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D328(rdram, ctx);
        goto after_3;
    // 0x80673ACC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80673AD0: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80673AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673AD8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80673ADC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80673AE0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80673AE4: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80673AE8: lbu         $t9, 0x44($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X44);
    // 0x80673AEC: beql        $t9, $zero, L_80673B44
    if (ctx->r25 == 0) {
        // 0x80673AF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80673B44;
    }
    goto skip_0;
    // 0x80673AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80673AF4: jal         0x8004D618
    // 0x80673AF8: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x80673AF8: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    after_4:
    // 0x80673AFC: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80673B00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80673B04: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80673B08: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80673B0C: jal         0x8004A97C
    // 0x80673B10: lhu         $a0, 0x30($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X30);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x80673B10: lhu         $a0, 0x30($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X30);
    after_5:
    // 0x80673B14: jal         0x800659EC
    // 0x80673B18: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800659EC(rdram, ctx);
        goto after_6;
    // 0x80673B18: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80673B1C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80673B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673B28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80673B2C: jal         0x80673F0C
    // 0x80673B30: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80673F0C(rdram, ctx);
        goto after_7;
    // 0x80673B30: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x80673B34: jal         0x80673590
    // 0x80673B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80673590(rdram, ctx);
        goto after_8;
    // 0x80673B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80673B3C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80673B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673B44:
    // 0x80673B44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80673B48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80673B4C: jr          $ra
    // 0x80673B50: nop

    return;
    // 0x80673B50: nop

;}
RECOMP_FUNC void func_804F5BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5BF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F5BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F5C00: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804F5C04: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5C08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804F5C0C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x804F5C10: jal         0x804F4C94
    // 0x804F5C14: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_804F4C94(rdram, ctx);
        goto after_0;
    // 0x804F5C14: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x804F5C18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804F5C1C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804F5C20: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804F5C24: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804F5C28: beql        $v0, $t6, L_804F5C48
    if (ctx->r2 == ctx->r14) {
        // 0x804F5C2C: lwc1        $f6, 0x58($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X58);
            goto L_804F5C48;
    }
    goto skip_0;
    // 0x804F5C2C: lwc1        $f6, 0x58($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X58);
    skip_0:
    // 0x804F5C30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804F5C34: jal         0x804F59B4
    // 0x804F5C38: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_804F59B4(rdram, ctx);
        goto after_1;
    // 0x804F5C38: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x804F5C3C: b           L_804F5CDC
    // 0x804F5C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804F5CDC;
    // 0x804F5C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F5C44: lwc1        $f6, 0x58($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X58);
L_804F5C48:
    // 0x804F5C48: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804F5C4C: nop

    // 0x804F5C50: bc1fl       L_804F5C74
    if (!c1cs) {
        // 0x804F5C54: lwc1        $f16, 0x5C($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X5C);
            goto L_804F5C74;
    }
    goto skip_1;
    // 0x804F5C54: lwc1        $f16, 0x5C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X5C);
    skip_1:
    // 0x804F5C58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804F5C5C: nop

    // 0x804F5C60: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x804F5C64: lwc1        $f10, 0x58($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X58);
    // 0x804F5C68: b           L_804F5C98
    // 0x804F5C6C: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
        goto L_804F5C98;
    // 0x804F5C6C: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x804F5C70: lwc1        $f16, 0x5C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X5C);
L_804F5C74:
    // 0x804F5C74: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x804F5C78: nop

    // 0x804F5C7C: bc1f        L_804F5C98
    if (!c1cs) {
        // 0x804F5C80: nop
    
            goto L_804F5C98;
    }
    // 0x804F5C80: nop

    // 0x804F5C84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804F5C88: nop

    // 0x804F5C8C: swc1        $f18, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f18.u32l;
    // 0x804F5C90: lwc1        $f4, 0x5C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x804F5C94: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
L_804F5C98:
    // 0x804F5C98: jal         0x804F4F50
    // 0x804F5C9C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_804F4F50(rdram, ctx);
        goto after_2;
    // 0x804F5C9C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x804F5CA0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804F5CA4: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x804F5CA8: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x804F5CAC: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x804F5CB0: bne         $at, $zero, L_804F5CC0
    if (ctx->r1 != 0) {
        // 0x804F5CB4: sw          $v0, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r2;
            goto L_804F5CC0;
    }
    // 0x804F5CB4: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x804F5CB8: b           L_804F5CD8
    // 0x804F5CBC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
        goto L_804F5CD8;
    // 0x804F5CBC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_804F5CC0:
    // 0x804F5CC0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x804F5CC4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x804F5CC8: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x804F5CCC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804F5CD0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x804F5CD4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_804F5CD8:
    // 0x804F5CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F5CDC:
    // 0x804F5CDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804F5CE0: jr          $ra
    // 0x804F5CE4: nop

    return;
    // 0x804F5CE4: nop

;}
RECOMP_FUNC void func_806CD384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD384: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CD388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CD38C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CD390: lwc1        $f0, 0x864($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X864);
    // 0x806CD394: lwc1        $f4, 0x868($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X868);
    // 0x806CD398: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C2C) << 16);
    // 0x806CD39C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x806CD3A0: swc1        $f6, 0x868($v0)
    MEM_W(0X868, ctx->r2) = ctx->f6.u32l;
    // 0x806CD3A4: lwc1        $f10, 0x868($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X868);
    // 0x806CD3A8: lwc1        $f18, -0xCB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C2C));
    // 0x806CD3AC: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C30) << 16);
    // 0x806CD3B0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806CD3B4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806CD3B8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806CD3BC: swc1        $f6, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f6.u32l;
    // 0x806CD3C0: lwc1        $f10, -0xCB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C30));
    // 0x806CD3C4: lwc1        $f8, 0x864($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X864);
    // 0x806CD3C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806CD3CC: jr          $ra
    // 0x806CD3D0: swc1        $f16, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x806CD3D0: swc1        $f16, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_80073274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007327C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80073280: beql        $t6, $zero, L_800732A8
    if (ctx->r14 == 0) {
        // 0x80073284: lw          $t8, 0x1C($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X1C);
            goto L_800732A8;
    }
    goto skip_0;
    // 0x80073284: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    skip_0:
    // 0x80073288: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8007328C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80073290: beql        $t7, $at, L_800732A8
    if (ctx->r15 == ctx->r1) {
        // 0x80073294: lw          $t8, 0x1C($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X1C);
            goto L_800732A8;
    }
    goto skip_1;
    // 0x80073294: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    skip_1:
    // 0x80073298: jal         0x80073070
    // 0x8007329C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80073070(rdram, ctx);
        goto after_0;
    // 0x8007329C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800732A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800732A4: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
L_800732A8:
    // 0x800732A8: beql        $t8, $zero, L_800732BC
    if (ctx->r24 == 0) {
        // 0x800732AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800732BC;
    }
    goto skip_2;
    // 0x800732AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800732B0: jal         0x80073030
    // 0x800732B4: nop

    func_80073030(rdram, ctx);
        goto after_1;
    // 0x800732B4: nop

    after_1:
    // 0x800732B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800732BC:
    // 0x800732BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800732C0: jr          $ra
    // 0x800732C4: nop

    return;
    // 0x800732C4: nop

;}
RECOMP_FUNC void func_8005D5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D5A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D5B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005D5B4: jal         0x80057D78
    // 0x8005D5B8: addiu       $a0, $a0, -0x7DC8
    ctx->r4 = ADD32(ctx->r4, -0X7DC8);
    func_80057D78(rdram, ctx);
        goto after_0;
    // 0x8005D5B8: addiu       $a0, $a0, -0x7DC8
    ctx->r4 = ADD32(ctx->r4, -0X7DC8);
    after_0:
    // 0x8005D5BC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8005D5C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005D5C4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8005D5C8: beq         $t6, $zero, L_8005D5E4
    if (ctx->r14 == 0) {
        // 0x8005D5CC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8005D5E4;
    }
    // 0x8005D5CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D5D0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005D5D4: jal         0x80057DC0
    // 0x8005D5D8: addiu       $a0, $a0, -0x7DC8
    ctx->r4 = ADD32(ctx->r4, -0X7DC8);
    func_80057DC0(rdram, ctx);
        goto after_1;
    // 0x8005D5D8: addiu       $a0, $a0, -0x7DC8
    ctx->r4 = ADD32(ctx->r4, -0X7DC8);
    after_1:
    // 0x8005D5DC: b           L_8005D5F8
    // 0x8005D5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D5F8;
    // 0x8005D5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D5E4:
    // 0x8005D5E4: jal         0x80065728
    // 0x8005D5E8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8005D5E8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8005D5EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D5F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D5F4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8005D5F8:
    // 0x8005D5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D5FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D600: jr          $ra
    // 0x8005D604: nop

    return;
    // 0x8005D604: nop

;}
RECOMP_FUNC void func_8041D8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D8D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8041D8D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041D8DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041D8E0: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8041D8E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041D8E8: beql        $t6, $zero, L_8041D8FC
    if (ctx->r14 == 0) {
        // 0x8041D8EC: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_8041D8FC;
    }
    goto skip_0;
    // 0x8041D8EC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    skip_0:
    // 0x8041D8F0: jal         0x8004816C
    // 0x8041D8F4: nop

    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x8041D8F4: nop

    after_0:
    // 0x8041D8F8: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
L_8041D8FC:
    // 0x8041D8FC: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x8041D900: jal         0x8005FD1C
    // 0x8041D904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_1;
    // 0x8041D904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8041D908: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8041D90C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8041D910: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041D914: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8041D918: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8041D91C: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8041D920: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x8041D924: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8041D928: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041D92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041D930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041D934: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8041D938: jal         0x8041DAD8
    // 0x8041D93C: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    func_8041DAD8(rdram, ctx);
        goto after_2;
    // 0x8041D93C: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8041D940: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8041D944: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8041D948: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041D94C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8041D950: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8041D954: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8041D958: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8041D95C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34D0) << 16);
    // 0x8041D960: lwc1        $f10, 0xB30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34D0));
    // 0x8041D964: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8041D968: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x8041D96C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8041D970: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8041D974: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8041D978: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8041D97C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8041D980: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8041D984: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8041D988: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8041D98C: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8041D990: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8041D994: lw          $t9, 0x28($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X28);
    // 0x8041D998: jalr        $t9
    // 0x8041D99C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8041D99C: nop

    after_3:
    // 0x8041D9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041D9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041D9A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8041D9AC: jr          $ra
    // 0x8041D9B0: nop

    return;
    // 0x8041D9B0: nop

;}
RECOMP_FUNC void func_805D7E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7E6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D7E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7E74: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805D7E78: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(474, 0X24FC) << 16);
    // 0x805D7E7C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D7E80: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D7E84: addiu       $t6, $t6, -0x6204
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(474, 0X24FC));
    // 0x805D7E88: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805D7E8C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D7E90: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805D7E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D7E98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D7E9C: jal         0x805D7EBC
    // 0x805D7EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D7EBC(rdram, ctx);
        goto after_0;
    // 0x805D7EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805D7EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D7EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D7EAC: jr          $ra
    // 0x805D7EB0: nop

    return;
    // 0x805D7EB0: nop

;}
RECOMP_FUNC void func_80535EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535EBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80535EC0: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(351, 0X1A958) << 16);
    // 0x80535EC4: lwc1        $f0, 0x1E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(351, 0X1A958));
    // 0x80535EC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80535ECC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80535ED0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80535ED4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80535ED8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80535EDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535EE0: addiu       $t6, $zero, 0x1C98
    ctx->r14 = ADD32(0, 0X1C98);
    // 0x80535EE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80535EE8: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535EEC: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535EF0: addiu       $a1, $zero, 0x294
    ctx->r5 = ADD32(0, 0X294);
    // 0x80535EF4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80535EF8: jal         0x8053589C
    // 0x80535EFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8053589C(rdram, ctx);
        goto after_0;
    // 0x80535EFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80535F00: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80535F04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80535F08: addiu       $t8, $zero, 0x1C98
    ctx->r24 = ADD32(0, 0X1C98);
    // 0x80535F0C: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80535F10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80535F14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80535F18: addiu       $a1, $zero, 0x294
    ctx->r5 = ADD32(0, 0X294);
    // 0x80535F1C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535F20: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535F24: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80535F28: jal         0x8053589C
    // 0x80535F2C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_1;
    // 0x80535F2C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80535F30: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80535F34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535F3C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535F40: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535F44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80535F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80535F4C: jr          $ra
    // 0x80535F50: nop

    return;
    // 0x80535F50: nop

;}
RECOMP_FUNC void func_80050A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80050A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050A60: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80050A64: jal         0x800506B4
    // 0x80050A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800506B4(rdram, ctx);
        goto after_0;
    // 0x80050A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80050A6C: bne         $v0, $zero, L_80050AE0
    if (ctx->r2 != 0) {
        // 0x80050A70: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80050AE0;
    }
    // 0x80050A70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80050A74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80050A78: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80050A7C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80050A80: jal         0x80081744
    // 0x80050A84: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    Overlay_AllocateAndLoad(rdram, ctx);
        goto after_1;
    // 0x80050A84: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x80050A88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80050A8C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80050A90: jal         0x80051684
    // 0x80050A94: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    func_80051684(rdram, ctx);
        goto after_2;
    // 0x80050A94: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x80050A98: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80050A9C: bne         $a1, $zero, L_80050AD0
    if (ctx->r5 != 0) {
        // 0x80050AA0: nop
    
            goto L_80050AD0;
    }
    // 0x80050AA0: nop

    // 0x80050AA4: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80050AA8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80050AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80050AB0: jal         0x80064B64
    // 0x80050AB4: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    func_80064B64(rdram, ctx);
        goto after_3;
    // 0x80050AB4: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    after_3:
    // 0x80050AB8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050ABC: addiu       $a0, $a0, 0x9F0
    ctx->r4 = ADD32(ctx->r4, 0X9F0);
    // 0x80050AC0: jal         0x80071380
    // 0x80050AC4: addiu       $a1, $zero, 0x1A8
    ctx->r5 = ADD32(0, 0X1A8);
    Fault_HungUp(rdram, ctx);
        goto after_4;
    // 0x80050AC4: addiu       $a1, $zero, 0x1A8
    ctx->r5 = ADD32(0, 0X1A8);
    after_4:
    // 0x80050AC8: b           L_80050AE8
    // 0x80050ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050AE8;
    // 0x80050ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050AD0:
    // 0x80050AD0: jal         0x80050790
    // 0x80050AD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80050790(rdram, ctx);
        goto after_5;
    // 0x80050AD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80050AD8: b           L_80050AE8
    // 0x80050ADC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80050AE8;
    // 0x80050ADC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80050AE0:
    // 0x80050AE0: jal         0x80050820
    // 0x80050AE4: nop

    func_80050820(rdram, ctx);
        goto after_6;
    // 0x80050AE4: nop

    after_6:
L_80050AE8:
    // 0x80050AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050AEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050AF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80050AF4: jr          $ra
    // 0x80050AF8: nop

    return;
    // 0x80050AF8: nop

;}
RECOMP_FUNC void func_80680F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680F90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80680F94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80680F98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80680F9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80680FA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80680FA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80680FA8: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80680FAC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80680FB0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80680FB4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80680FB8: bne         $v0, $at, L_806810B4
    if (ctx->r2 != ctx->r1) {
        // 0x80680FBC: or          $s2, $a3, $zero
        ctx->r18 = ctx->r7 | 0;
            goto L_806810B4;
    }
    // 0x80680FBC: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80680FC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80680FC4: jal         0x80062AEC
    // 0x80680FC8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80680FC8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80680FCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80680FD0: beq         $v0, $at, L_80680FEC
    if (ctx->r2 == ctx->r1) {
        // 0x80680FD4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80680FEC;
    }
    // 0x80680FD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80680FD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80680FDC: beq         $v0, $at, L_80681054
    if (ctx->r2 == ctx->r1) {
        // 0x80680FE0: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80681054;
    }
    // 0x80680FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80680FE4: b           L_806810B8
    // 0x80680FE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806810B8;
    // 0x80680FE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80680FEC:
    // 0x80680FEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80680FF0: jal         0x80680F38
    // 0x80680FF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80680F38(rdram, ctx);
        goto after_1;
    // 0x80680FF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80680FF8: beq         $v0, $zero, L_806810B4
    if (ctx->r2 == 0) {
        // 0x80680FFC: lui         $at, 0x8068
        ctx->r1 = S32(RELOC_HI16(550, 0X2260) << 16);
            goto L_806810B4;
    }
    // 0x80680FFC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2260) << 16);
    // 0x80681000: lwc1        $f4, 0x2670($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2260));
    // 0x80681004: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80681008: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8068100C: nop

    // 0x80681010: bc1fl       L_80681040
    if (!c1cs) {
        // 0x80681014: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80681040;
    }
    goto skip_0;
    // 0x80681014: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80681018: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8068101C: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80681020: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80681024: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80681028: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8068102C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80681030: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80681034: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80681038: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8068103C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80681040:
    // 0x80681040: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80681044: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80681048: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8068104C: b           L_806810B4
    // 0x80681050: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
        goto L_806810B4;
    // 0x80681050: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_80681054:
    // 0x80681054: jal         0x80680F38
    // 0x80681058: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80680F38(rdram, ctx);
        goto after_2;
    // 0x80681058: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x8068105C: beq         $v0, $zero, L_806810B4
    if (ctx->r2 == 0) {
        // 0x80681060: lui         $at, 0x8068
        ctx->r1 = S32(RELOC_HI16(550, 0X2264) << 16);
            goto L_806810B4;
    }
    // 0x80681060: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2264) << 16);
    // 0x80681064: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80681068: lwc1        $f16, 0x2674($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2264));
    // 0x8068106C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80681070: nop

    // 0x80681074: bc1fl       L_806810A4
    if (!c1cs) {
        // 0x80681078: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806810A4;
    }
    goto skip_1;
    // 0x80681078: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x8068107C: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80681080: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80681084: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80681088: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8068108C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80681090: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80681094: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80681098: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8068109C: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x806810A0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806810A4:
    // 0x806810A4: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806810A8: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x806810AC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x806810B0: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_806810B4:
    // 0x806810B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806810B8:
    // 0x806810B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806810BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806810C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806810C4: jr          $ra
    // 0x806810C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806810C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806EA7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EA7FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EA800: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806EA804: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806EA808: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806EA80C: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(670, 0XDE8) << 16);
    // 0x806EA810: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806EA814: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806EA818: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806EA81C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EA820: lw          $t8, -0x4A48($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(670, 0XDE8));
    // 0x806EA824: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806EA828: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EA82C: jal         0x80048490
    // 0x806EA830: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806EA830: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806EA834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EA838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EA83C: jr          $ra
    // 0x806EA840: nop

    return;
    // 0x806EA840: nop

;}
RECOMP_FUNC void func_80003718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003718: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8000371C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80003720: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80003724: jr          $ra
    // 0x80003728: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    return;
    // 0x80003728: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_805741B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805741B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805741BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805741C0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x805741C4: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x805741C8: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x805741CC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805741D0: slti        $at, $v1, 0x200
    ctx->r1 = SIGNED(ctx->r3) < 0X200 ? 1 : 0;
    // 0x805741D4: addiu       $t7, $t6, -0x402D
    ctx->r15 = ADD32(ctx->r14, -0X402D);
    // 0x805741D8: beq         $at, $zero, L_805741FC
    if (ctx->r1 == 0) {
        // 0x805741DC: sh          $t7, 0x144($a0)
        MEM_H(0X144, ctx->r4) = ctx->r15;
            goto L_805741FC;
    }
    // 0x805741DC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    // 0x805741E0: lw          $t9, 0x174($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X174);
    // 0x805741E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805741E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805741EC: jal         0x8005FCA8
    // 0x805741F0: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x805741F0: sh          $t8, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r24;
    after_0:
    // 0x805741F4: b           L_80574270
    // 0x805741F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80574270;
    // 0x805741F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805741FC:
    // 0x805741FC: lw          $t1, 0x180($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X180);
    // 0x80574200: slti        $at, $v1, 0x232
    ctx->r1 = SIGNED(ctx->r3) < 0X232 ? 1 : 0;
    // 0x80574204: beq         $t1, $zero, L_80574244
    if (ctx->r9 == 0) {
        // 0x80574208: nop
    
            goto L_80574244;
    }
    // 0x80574208: nop

    // 0x8057420C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80574210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80574214: slti        $at, $v1, 0x232
    ctx->r1 = SIGNED(ctx->r3) < 0X232 ? 1 : 0;
    // 0x80574218: bne         $at, $zero, L_8057423C
    if (ctx->r1 != 0) {
        // 0x8057421C: swc1        $f4, 0x1C($a1)
        MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
            goto L_8057423C;
    }
    // 0x8057421C: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x80574220: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x80574224: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80574228: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8057422C: jal         0x8005FCA8
    // 0x80574230: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x80574230: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    after_1:
    // 0x80574234: b           L_80574270
    // 0x80574238: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80574270;
    // 0x80574238: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8057423C:
    // 0x8057423C: b           L_80574270
    // 0x80574240: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80574270;
    // 0x80574240: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80574244:
    // 0x80574244: beq         $at, $zero, L_80574258
    if (ctx->r1 == 0) {
        // 0x80574248: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80574258;
    }
    // 0x80574248: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8057424C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80574250: nop

    // 0x80574254: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
L_80574258:
    // 0x80574258: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8057425C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80574260: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80574264: jal         0x8005FCA8
    // 0x80574268: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    func_8005FCA8(rdram, ctx);
        goto after_2;
    // 0x80574268: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    after_2:
    // 0x8057426C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80574270:
    // 0x80574270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80574274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80574278: jr          $ra
    // 0x8057427C: nop

    return;
    // 0x8057427C: nop

;}
RECOMP_FUNC void func_80674674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80674678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067467C: jal         0x806741B8
    // 0x80674680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806741B8(rdram, ctx);
        goto after_0;
    // 0x80674680: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80674684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80674688: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8067468C: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x80674690: jal         0x80065ABC
    // 0x80674694: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x80674694: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    after_1:
    // 0x80674698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067469C: jal         0x80674304
    // 0x806746A0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_80674304(rdram, ctx);
        goto after_2;
    // 0x806746A0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x806746A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806746A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806746AC: jr          $ra
    // 0x806746B0: nop

    return;
    // 0x806746B0: nop

;}
RECOMP_FUNC void func_8002511C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002511C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025124: jal         0x80024FF8
    // 0x80025128: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_80024FF8(rdram, ctx);
        goto after_0;
    // 0x80025128: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_0:
    // 0x8002512C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025134: jr          $ra
    // 0x80025138: nop

    return;
    // 0x80025138: nop

;}
RECOMP_FUNC void func_80424204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80424208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042420C: jal         0x804241A4
    // 0x80424210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804241A4(rdram, ctx);
        goto after_0;
    // 0x80424210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80424218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042421C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80424220: jal         0x80424550
    // 0x80424224: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80424550(rdram, ctx);
        goto after_1;
    // 0x80424224: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80424228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042422C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424230: jr          $ra
    // 0x80424234: nop

    return;
    // 0x80424234: nop

;}
RECOMP_FUNC void func_8079BD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BD0C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8079BD10: lw          $t6, -0x7290($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7290);
    // 0x8079BD14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8079BD18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079BD1C: lbu         $t7, 0x41($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X41);
    // 0x8079BD20: beql        $t7, $zero, L_8079BD78
    if (ctx->r15 == 0) {
        // 0x8079BD24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079BD78;
    }
    goto skip_0;
    // 0x8079BD24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8079BD28: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8079BD2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8079BD30: add.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8079BD34: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8079BD38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8079BD3C: jal         0x8005FE48
    // 0x8079BD40: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8079BD40: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8079BD44: jal         0x800447C8
    // 0x8079BD48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8079BD48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8079BD4C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8079BD50: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8079BD54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8079BD58: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8079BD5C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8079BD60: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8079BD64: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x8079BD68: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x8079BD6C: jalr        $t9
    // 0x8079BD70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8079BD70: nop

    after_2:
    // 0x8079BD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079BD78:
    // 0x8079BD78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8079BD7C: jr          $ra
    // 0x8079BD80: nop

    return;
    // 0x8079BD80: nop

;}
RECOMP_FUNC void func_8066664C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066664C: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80666650: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80666654: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80666658: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8066665C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80666660: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80666664: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80666668: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8066666C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80666670: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80666674: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80666678: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x8066667C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80666680: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80666684: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80666688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8066668C: jal         0x8004921C
    // 0x80666690: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80666690: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    after_0:
    // 0x80666694: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80666698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066669C: jal         0x8004921C
    // 0x806666A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x806666A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806666A4: andi        $t8, $s1, 0xFF
    ctx->r24 = ctx->r17 & 0XFF;
    // 0x806666A8: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x806666AC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806666B0: lbu         $t7, 0x145($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X145);
    // 0x806666B4: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x806666B8: addiu       $s5, $sp, 0xBC
    ctx->r21 = ADD32(ctx->r29, 0XBC);
    // 0x806666BC: lw          $s3, 0x1F4($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X1F4);
    // 0x806666C0: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x806666C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x806666C8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x806666CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806666D0: lw          $s4, 0x88($v1)
    ctx->r20 = MEM_W(ctx->r3, 0X88);
    // 0x806666D4: mflo        $t6
    ctx->r14 = lo;
    // 0x806666D8: nop

    // 0x806666DC: nop

    // 0x806666E0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806666E4: mflo        $t8
    ctx->r24 = lo;
    // 0x806666E8: addu        $s2, $t9, $t8
    ctx->r18 = ADD32(ctx->r25, ctx->r24);
    // 0x806666EC: jal         0x80077338
    // 0x806666F0: nop

    func_80077338(rdram, ctx);
        goto after_2;
    // 0x806666F0: nop

    after_2:
    // 0x806666F4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x806666F8: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x806666FC: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80666700: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80666704: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80666708: ori         $t8, $t8, 0xACB0
    ctx->r24 = ctx->r24 | 0XACB0;
    // 0x8066670C: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x80666710: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80666714: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80666718: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8066671C: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80666720: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x80666724: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80666728: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x8066672C: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x80666730: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x80666734: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80666738: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x8066673C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80666740: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80666744: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80666748: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8066674C: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80666750: sw          $a1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r5;
    // 0x80666754: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80666758: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8066675C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80666760: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80666764: jal         0x8007711C
    // 0x80666768: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x80666768: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_3:
    // 0x8066676C: addiu       $s1, $sp, 0xC0
    ctx->r17 = ADD32(ctx->r29, 0XC0);
    // 0x80666770: jal         0x80080050
    // 0x80666774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80080050(rdram, ctx);
        goto after_4;
    // 0x80666774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80666778: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066677C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80666780: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x80666784: jal         0x80080C84
    // 0x80666788: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_80080C84(rdram, ctx);
        goto after_5;
    // 0x80666788: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x8066678C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80666790: jal         0x800806B0
    // 0x80666794: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800806B0(rdram, ctx);
        goto after_6;
    // 0x80666794: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80666798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066679C: jal         0x800805C8
    // 0x806667A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800805C8(rdram, ctx);
        goto after_7;
    // 0x806667A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x806667A4: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D78) << 16);
    // 0x806667A8: lwc1        $f6, 0x7A48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D78));
    // 0x806667AC: lwc1        $f4, 0x40($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X40);
    // 0x806667B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806667B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806667B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x806667BC: jal         0x800804E0
    // 0x806667C0: nop

    func_800804E0(rdram, ctx);
        goto after_8;
    // 0x806667C0: nop

    after_8:
    // 0x806667C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806667C8: lw          $a1, 0x44($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X44);
    // 0x806667CC: jal         0x80080440
    // 0x806667D0: lw          $a2, 0x48($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X48);
    func_80080440(rdram, ctx);
        goto after_9;
    // 0x806667D0: lw          $a2, 0x48($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X48);
    after_9:
    // 0x806667D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806667D8: jal         0x800806B0
    // 0x806667DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800806B0(rdram, ctx);
        goto after_10;
    // 0x806667DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x806667E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806667E4: jal         0x800805C8
    // 0x806667E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800805C8(rdram, ctx);
        goto after_11;
    // 0x806667E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x806667EC: lwc1        $f10, 0x40($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X40);
    // 0x806667F0: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D7C) << 16);
    // 0x806667F4: lwc1        $f18, 0x7A4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D7C));
    // 0x806667F8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x806667FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80666800: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80666804: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80666808: jal         0x800804E0
    // 0x8066680C: nop

    func_800804E0(rdram, ctx);
        goto after_12;
    // 0x8066680C: nop

    after_12:
    // 0x80666810: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80666814: jal         0x800817A0
    // 0x80666818: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    MtxConv_F2L(rdram, ctx);
        goto after_13;
    // 0x80666818: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8066681C: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80666820: lui         $t6, 0x104
    ctx->r14 = S32(0X104 << 16);
    // 0x80666824: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80666828: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8066682C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80666830: sw          $s3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r19;
    // 0x80666834: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80666838: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8066683C: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2500) << 16);
    // 0x80666840: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80666844: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80666848: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x8066684C: ori         $t8, $t8, 0x81FF
    ctx->r24 = ctx->r24 | 0X81FF;
    // 0x80666850: addiu       $t6, $t6, 0x71D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(504, 0X2500));
    // 0x80666854: lui         $s3, 0x73F
    ctx->r19 = S32(0X73F << 16);
    // 0x80666858: lui         $s7, 0xF548
    ctx->r23 = S32(0XF548 << 16);
    // 0x8066685C: lui         $s4, 0x1F
    ctx->r20 = S32(0X1F << 16);
    // 0x80666860: ori         $s4, $s4, 0xC03C
    ctx->r20 = ctx->r20 | 0XC03C;
    // 0x80666864: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x80666868: ori         $s3, $s3, 0xF080
    ctx->r19 = ctx->r19 | 0XF080;
    // 0x8066686C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80666870: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x80666874: lui         $s6, 0xE700
    ctx->r22 = S32(0XE700 << 16);
    // 0x80666878: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8066687C: lui         $s1, 0xF300
    ctx->r17 = S32(0XF300 << 16);
    // 0x80666880: lui         $s0, 0xE600
    ctx->r16 = S32(0XE600 << 16);
    // 0x80666884: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x80666888: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x8066688C: lui         $t4, 0xFD50
    ctx->r12 = S32(0XFD50 << 16);
    // 0x80666890: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x80666894: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80666898: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
L_8066689C:
    // 0x8066689C: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x806668A0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806668A4: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x806668A8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x806668AC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x806668B0: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x806668B4: sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9 << 3);
    // 0x806668B8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x806668BC: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806668C0: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x806668C4: sw          $ra, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r31;
    // 0x806668C8: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x806668CC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x806668D0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x806668D4: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    // 0x806668D8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x806668DC: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x806668E0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806668E4: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x806668E8: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x806668EC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x806668F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x806668F4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806668F8: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x806668FC: sw          $s3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r19;
    // 0x80666900: sw          $s1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r17;
    // 0x80666904: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80666908: addiu       $s2, $s2, 0x780
    ctx->r18 = ADD32(ctx->r18, 0X780);
    // 0x8066690C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80666910: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x80666914: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80666918: sw          $s6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r22;
    // 0x8066691C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x80666920: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80666924: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80666928: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8066692C: sw          $s7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r23;
    // 0x80666930: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80666934: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80666938: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x8066693C: sw          $s4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r20;
    // 0x80666940: sw          $fp, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r30;
    // 0x80666944: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    // 0x80666948: addiu       $t7, $v0, 0x2
    ctx->r15 = ADD32(ctx->r2, 0X2);
    // 0x8066694C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80666950: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80666954: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80666958: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x8066695C: or          $t6, $a2, $t8
    ctx->r14 = ctx->r6 | ctx->r24;
    // 0x80666960: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80666964: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80666968: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8066696C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x80666970: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x80666974: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
    // 0x80666978: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x8066697C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80666980: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80666984: or          $t7, $a2, $t6
    ctx->r15 = ctx->r6 | ctx->r14;
    // 0x80666988: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8066698C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80666990: bne         $t1, $s5, L_8066689C
    if (ctx->r9 != ctx->r21) {
        // 0x80666994: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_8066689C;
    }
    // 0x80666994: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80666998: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8066699C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x806669A0: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2700) << 16);
    // 0x806669A4: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806669A8: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x806669AC: addiu       $t6, $t6, 0x73D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(504, 0X2700));
    // 0x806669B0: ori         $t8, $t8, 0x103F
    ctx->r24 = ctx->r24 | 0X103F;
    // 0x806669B4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806669B8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x806669BC: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x806669C0: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806669C4: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x806669C8: sw          $s2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r18;
    // 0x806669CC: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x806669D0: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x806669D4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x806669D8: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x806669DC: sw          $ra, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r31;
    // 0x806669E0: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x806669E4: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x806669E8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806669EC: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x806669F0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x806669F4: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x806669F8: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x806669FC: lui         $t9, 0x713
    ctx->r25 = S32(0X713 << 16);
    // 0x80666A00: ori         $t9, $t9, 0xF080
    ctx->r25 = ctx->r25 | 0XF080;
    // 0x80666A04: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80666A08: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80666A0C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80666A10: sw          $s1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r17;
    // 0x80666A14: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80666A18: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80666A1C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80666A20: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80666A24: sw          $s6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r22;
    // 0x80666A28: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80666A2C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80666A30: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x80666A34: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80666A38: sw          $s7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r23;
    // 0x80666A3C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80666A40: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x80666A44: ori         $t6, $t6, 0xC010
    ctx->r14 = ctx->r14 | 0XC010;
    // 0x80666A48: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80666A4C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80666A50: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80666A54: sw          $fp, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r30;
    // 0x80666A58: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80666A5C: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2740) << 16);
    // 0x80666A60: addiu       $t6, $t6, 0x7410
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(504, 0X2740));
    // 0x80666A64: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80666A68: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80666A6C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80666A70: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80666A74: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80666A78: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80666A7C: lui         $t8, 0xBD00
    ctx->r24 = S32(0XBD00 << 16);
    // 0x80666A80: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80666A84: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x80666A88: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80666A8C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80666A90: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x80666A94: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80666A98: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
    // 0x80666A9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80666AA0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80666AA4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80666AA8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80666AAC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80666AB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80666AB4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80666AB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80666ABC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80666AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80666AC4: jr          $ra
    // 0x80666AC8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x80666AC8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_8043E040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E048: jal         0x8004700C
    // 0x8043E04C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043E04C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043E050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E054: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8043E058: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(92, 0X1A38) << 16);
    // 0x8043E05C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8043E060: addiu       $t7, $t7, -0x1588
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(92, 0X1A38));
    // 0x8043E064: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8043E068: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043E06C: beq         $v0, $zero, L_8043E0A8
    if (ctx->r2 == 0) {
        // 0x8043E070: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_8043E0A8;
    }
    // 0x8043E070: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8043E074: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8043E078: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8043E07C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x8043E080: lui         $v1, 0x8044
    ctx->r3 = S32(RELOC_HI16(92, 0X1A00) << 16);
    // 0x8043E084: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8043E088: nop

    // 0x8043E08C: bc1fl       L_8043E09C
    if (!c1cs) {
        // 0x8043E090: sll         $t0, $t9, 2
        ctx->r8 = S32(ctx->r25 << 2);
            goto L_8043E09C;
    }
    goto skip_0;
    // 0x8043E090: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    skip_0:
    // 0x8043E094: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8043E098: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
L_8043E09C:
    // 0x8043E09C: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8043E0A0: b           L_8043E0AC
    // 0x8043E0A4: lw          $v1, -0x15C0($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(92, 0X1A00));
        goto L_8043E0AC;
    // 0x8043E0A4: lw          $v1, -0x15C0($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(92, 0X1A00));
L_8043E0A8:
    // 0x8043E0A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8043E0AC:
    // 0x8043E0AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8043E0B0: sb          $t1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r9;
    // 0x8043E0B4: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x8043E0B8: sw          $v1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r3;
    // 0x8043E0BC: sw          $v1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r3;
    // 0x8043E0C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043E0C4: jal         0x8043E0F8
    // 0x8043E0C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043E0F8(rdram, ctx);
        goto after_1;
    // 0x8043E0C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8043E0CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E0D0: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8043E0D4: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x8043E0D8: jal         0x8043DFEC
    // 0x8043E0DC: sw          $t2, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r10;
    func_8043DFEC(rdram, ctx);
        goto after_2;
    // 0x8043E0DC: sw          $t2, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r10;
    after_2:
    // 0x8043E0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E0E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8043E0E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043E0EC: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8043E0F0: jr          $ra
    // 0x8043E0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8043E0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004F38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F38C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004F390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F394: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004F398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004F39C: jal         0x8004FC60
    // 0x8004F3A0: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_8004FC60(rdram, ctx);
        goto after_0;
    // 0x8004F3A0: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x8004F3A4: jal         0x8004FC60
    // 0x8004F3A8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    func_8004FC60(rdram, ctx);
        goto after_1;
    // 0x8004F3A8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_1:
    // 0x8004F3AC: jal         0x8004EEB8
    // 0x8004F3B0: lw          $a0, 0x1B8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1B8);
    func_8004EEB8(rdram, ctx);
        goto after_2;
    // 0x8004F3B0: lw          $a0, 0x1B8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1B8);
    after_2:
    // 0x8004F3B4: jal         0x8004EDB4
    // 0x8004F3B8: lw          $a0, 0x1BC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1BC);
    func_8004EDB4(rdram, ctx);
        goto after_3;
    // 0x8004F3B8: lw          $a0, 0x1BC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1BC);
    after_3:
    // 0x8004F3BC: jal         0x80064E84
    // 0x8004F3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064E84(rdram, ctx);
        goto after_4;
    // 0x8004F3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004F3C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F3C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F3CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004F3D0: jr          $ra
    // 0x8004F3D4: nop

    return;
    // 0x8004F3D4: nop

;}
RECOMP_FUNC void func_8004BBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BBD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004BBD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004BBDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004BBE0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004BBE4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004BBE8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004BBEC: lh          $v0, 0x6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X6);
    // 0x8004BBF0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004BBF4: lh          $t0, 0x10($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X10);
    // 0x8004BBF8: blez        $v0, L_8004BC38
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004BBFC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004BC38;
    }
    // 0x8004BBFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004BC00: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    // 0x8004BC04: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
L_8004BC08:
    // 0x8004BC08: sllv        $t7, $a0, $t6
    ctx->r15 = S32(ctx->r4 << (ctx->r14 & 31));
    // 0x8004BC0C: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8004BC10: bnel        $t8, $zero, L_8004BC24
    if (ctx->r24 != 0) {
        // 0x8004BC14: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004BC24;
    }
    goto skip_0;
    // 0x8004BC14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8004BC18: b           L_8004BD90
    // 0x8004BC1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004BD90;
    // 0x8004BC1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004BC20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004BC24:
    // 0x8004BC24: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004BC28: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004BC2C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004BC30: bnel        $at, $zero, L_8004BC08
    if (ctx->r1 != 0) {
        // 0x8004BC34: addu        $t6, $t0, $v1
        ctx->r14 = ADD32(ctx->r8, ctx->r3);
            goto L_8004BC08;
    }
    goto skip_1;
    // 0x8004BC34: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    skip_1:
L_8004BC38:
    // 0x8004BC38: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BC3C: slti        $at, $t9, 0x11
    ctx->r1 = SIGNED(ctx->r25) < 0X11 ? 1 : 0;
    // 0x8004BC40: bnel        $at, $zero, L_8004BC54
    if (ctx->r1 != 0) {
        // 0x8004BC44: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8004BC54;
    }
    goto skip_2;
    // 0x8004BC44: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_2:
    // 0x8004BC48: b           L_8004BD90
    // 0x8004BC4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004BD90;
    // 0x8004BC4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004BC50: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8004BC54:
    // 0x8004BC54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BC58: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BC5C: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8004BC60: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004BC64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004BC68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004BC6C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8004BC70: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BC74: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004BC78: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004BC7C: jal         0x800534C0
    // 0x8004BC80: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004BC80: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8004BC84: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004BC88: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004BC8C: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8004BC90: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004BC94: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x8004BC98: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x8004BC9C: bnel        $t3, $at, L_8004BCAC
    if (ctx->r11 != ctx->r1) {
        // 0x8004BCA0: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004BCAC;
    }
    goto skip_3;
    // 0x8004BCA0: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004BCA4: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8004BCA8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004BCAC:
    // 0x8004BCAC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004BCB0: beql        $v0, $zero, L_8004BD90
    if (ctx->r2 == 0) {
        // 0x8004BCB4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BD90;
    }
    goto skip_4;
    // 0x8004BCB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8004BCB8: beql        $v0, $at, L_8004BD90
    if (ctx->r2 == ctx->r1) {
        // 0x8004BCBC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BD90;
    }
    goto skip_5;
    // 0x8004BCBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x8004BCC0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004BCC4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004BCC8: andi        $a0, $v0, 0xF8
    ctx->r4 = ctx->r2 & 0XF8;
    // 0x8004BCCC: beq         $a0, $at, L_8004BD8C
    if (ctx->r4 == ctx->r1) {
        // 0x8004BCD0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004BD8C;
    }
    // 0x8004BCD0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004BCD4: beql        $a0, $at, L_8004BD90
    if (ctx->r4 == ctx->r1) {
        // 0x8004BCD8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BD90;
    }
    goto skip_6;
    // 0x8004BCD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_6:
    // 0x8004BCDC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8004BCE0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8004BCE4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8004BCE8: andi        $a1, $a0, 0x3F
    ctx->r5 = ctx->r4 & 0X3F;
    // 0x8004BCEC: xori        $t7, $a1, 0x4
    ctx->r15 = ctx->r5 ^ 0X4;
    // 0x8004BCF0: sltu        $t7, $zero, $t7
    ctx->r15 = 0 < ctx->r15 ? 1 : 0;
    // 0x8004BCF4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8004BCF8: beq         $t8, $zero, L_8004BD8C
    if (ctx->r24 == 0) {
        // 0x8004BCFC: srl         $t1, $a0, 6
        ctx->r9 = S32(U32(ctx->r4) >> 6);
            goto L_8004BD8C;
    }
    // 0x8004BCFC: srl         $t1, $a0, 6
    ctx->r9 = S32(U32(ctx->r4) >> 6);
    // 0x8004BD00: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8004BD04: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004BD08: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004BD0C: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8004BD10: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8004BD14: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x8004BD18: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x8004BD1C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8004BD20: lw          $t5, 0xA24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XA24);
    // 0x8004BD24: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8004BD28: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8004BD2C: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x8004BD30: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8004BD34: beq         $t2, $zero, L_8004BD8C
    if (ctx->r10 == 0) {
        // 0x8004BD38: sh          $t1, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r9;
            goto L_8004BD8C;
    }
    // 0x8004BD38: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x8004BD3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004BD40: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004BD44: lhu         $t3, 0x0($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X0);
    // 0x8004BD48: lw          $t4, 0x174($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X174);
    // 0x8004BD4C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004BD50: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8004BD54: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004BD58: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004BD5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004BD60: lw          $t5, 0x40($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X40);
    // 0x8004BD64: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8004BD68: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8004BD6C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BD70: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004BD74: jal         0x8004BBD4
    // 0x8004BD78: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004BBD4(rdram, ctx);
        goto after_1;
    // 0x8004BD78: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004BD7C: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004BD80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004BD84: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004BD88: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8004BD8C:
    // 0x8004BD8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004BD90:
    // 0x8004BD90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004BD94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004BD98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004BD9C: jr          $ra
    // 0x8004BDA0: nop

    return;
    // 0x8004BDA0: nop

;}
RECOMP_FUNC void func_804C6CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6CC8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C6CCC: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(221, 0X2E8) << 16);
    // 0x804C6CD0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804C6CD4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C6CD8: addiu       $t6, $t6, 0x6F48
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(221, 0X2E8));
    // 0x804C6CDC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804C6CE0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C6CE4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804C6CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C6CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804C6CF0: jal         0x804C6DFC
    // 0x804C6CF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804C6DFC(rdram, ctx);
        goto after_0;
    // 0x804C6CF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804C6CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C6CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C6D00: jr          $ra
    // 0x804C6D04: nop

    return;
    // 0x804C6D04: nop

;}
RECOMP_FUNC void func_8075FE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FE00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8075FE04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8075FE08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8075FE0C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8075FE10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8075FE14: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8075FE18: lw          $a2, 0x88($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X88);
    // 0x8075FE1C: jal         0x80045A34
    // 0x8075FE20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8075FE20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8075FE24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8075FE28: bne         $v0, $zero, L_8075FE40
    if (ctx->r2 != 0) {
        // 0x8075FE2C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8075FE40;
    }
    // 0x8075FE2C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8075FE30: jal         0x800445A4
    // 0x8075FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8075FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8075FE38: b           L_8075FF48
    // 0x8075FE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8075FF48;
    // 0x8075FE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8075FE40:
    // 0x8075FE40: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x8075FE44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8075FE48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8075FE4C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8075FE50: lw          $t8, 0x180($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X180);
    // 0x8075FE54: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8075FE58: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8075FE5C: beql        $t8, $zero, L_8075FE7C
    if (ctx->r24 == 0) {
        // 0x8075FE60: sra         $v1, $v1, 4
        ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
            goto L_8075FE7C;
    }
    goto skip_0;
    // 0x8075FE60: sra         $v1, $v1, 4
    ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
    skip_0:
    // 0x8075FE64: lw          $t9, 0x180($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X180);
    // 0x8075FE68: lwc1        $f8, 0x84($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X84);
    // 0x8075FE6C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8075FE70: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8075FE74: nop

    // 0x8075FE78: sra         $v1, $v1, 4
    ctx->r3 = S32(SIGNED(ctx->r3) >> 4);
L_8075FE7C:
    // 0x8075FE7C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8075FE80: beql        $v1, $zero, L_8075FEEC
    if (ctx->r3 == 0) {
        // 0x8075FE84: sw          $t3, 0x1EC($s0)
        MEM_W(0X1EC, ctx->r16) = ctx->r11;
            goto L_8075FEEC;
    }
    goto skip_1;
    // 0x8075FE84: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
    skip_1:
    // 0x8075FE88: beq         $v1, $at, L_8075FEB0
    if (ctx->r3 == ctx->r1) {
        // 0x8075FE8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8075FEB0;
    }
    // 0x8075FE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075FE90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8075FE94: beq         $v1, $at, L_8075FEC4
    if (ctx->r3 == ctx->r1) {
        // 0x8075FE98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8075FEC4;
    }
    // 0x8075FE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075FE9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8075FEA0: beq         $v1, $at, L_8075FED4
    if (ctx->r3 == ctx->r1) {
        // 0x8075FEA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8075FED4;
    }
    // 0x8075FEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075FEA8: b           L_8075FEF0
    // 0x8075FEAC: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
        goto L_8075FEF0;
    // 0x8075FEAC: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
L_8075FEB0:
    // 0x8075FEB0: jal         0x8004590C
    // 0x8075FEB4: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x8075FEB4: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    after_2:
    // 0x8075FEB8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8075FEBC: b           L_8075FEEC
    // 0x8075FEC0: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
        goto L_8075FEEC;
    // 0x8075FEC0: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
L_8075FEC4:
    // 0x8075FEC4: jal         0x8004590C
    // 0x8075FEC8: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x8075FEC8: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    after_3:
    // 0x8075FECC: b           L_8075FEEC
    // 0x8075FED0: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
        goto L_8075FEEC;
    // 0x8075FED0: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
L_8075FED4:
    // 0x8075FED4: jal         0x8004590C
    // 0x8075FED8: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x8075FED8: addiu       $a1, $a2, 0x600
    ctx->r5 = ADD32(ctx->r6, 0X600);
    after_4:
    // 0x8075FEDC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8075FEE0: b           L_8075FEEC
    // 0x8075FEE4: sw          $t2, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r10;
        goto L_8075FEEC;
    // 0x8075FEE4: sw          $t2, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r10;
    // 0x8075FEE8: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
L_8075FEEC:
    // 0x8075FEEC: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
L_8075FEF0:
    // 0x8075FEF0: lui         $t4, 0x8076
    ctx->r12 = S32(RELOC_HI16(760, 0X490) << 16);
    // 0x8075FEF4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8075FEF8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8075FEFC: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(760, 0X490));
    // 0x8075FF00: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8075FF04: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8075FF08: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8075FF0C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8075FF10: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8075FF14: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x8075FF18: sw          $t6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r14;
    // 0x8075FF1C: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8075FF20: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8075FF24: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8075FF28: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8075FF2C: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x8075FF30: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8075FF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075FF38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8075FF3C: jal         0x8075FF58
    // 0x8075FF40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8075FF58(rdram, ctx);
        goto after_5;
    // 0x8075FF40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8075FF44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8075FF48:
    // 0x8075FF48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8075FF4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8075FF50: jr          $ra
    // 0x8075FF54: nop

    return;
    // 0x8075FF54: nop

;}
RECOMP_FUNC void func_807990EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807990EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807990F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807990F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807990F8: jal         0x80047090
    // 0x807990FC: addiu       $a0, $zero, 0x46D9
    ctx->r4 = ADD32(0, 0X46D9);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807990FC: addiu       $a0, $zero, 0x46D9
    ctx->r4 = ADD32(0, 0X46D9);
    after_0:
    // 0x80799100: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80799104: bne         $v0, $at, L_80799114
    if (ctx->r2 != ctx->r1) {
        // 0x80799108: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80799114;
    }
    // 0x80799108: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8079910C: b           L_8079917C
    // 0x80799110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8079917C;
    // 0x80799110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80799114:
    // 0x80799114: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80799118: lui         $at, 0x46D9
    ctx->r1 = S32(0X46D9 << 16);
    // 0x8079911C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80799120: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    // 0x80799124: lw          $a2, 0x88($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X88);
    // 0x80799128: lw          $a3, 0x8C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8C);
    // 0x8079912C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x80799130: jal         0x8004613C
    // 0x80799134: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80799134: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x80799138: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x8079913C: bne         $v0, $zero, L_8079914C
    if (ctx->r2 != 0) {
        // 0x80799140: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8079914C;
    }
    // 0x80799140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80799144: b           L_8079917C
    // 0x80799148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8079917C;
    // 0x80799148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079914C:
    // 0x8079914C: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x80799150: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x80799154: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80799158: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8079915C: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x80799160: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80799164: jal         0x80047F9C
    // 0x80799168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80799168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8079916C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80799170: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80799174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80799178: sb          $t1, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r9;
L_8079917C:
    // 0x8079917C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80799184: jr          $ra
    // 0x80799188: nop

    return;
    // 0x80799188: nop

;}
RECOMP_FUNC void func_806B24FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B24FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2500: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2504: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2508: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B250C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2510: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2514: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2518: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B251C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2520: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2524: jr          $ra
    // 0x806B2528: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2528: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
