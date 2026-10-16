#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80020E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E4C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80020E50: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x80020E54: beql        $t7, $zero, L_80020E70
    if (ctx->r15 == 0) {
        // 0x80020E58: lw          $t0, 0x4($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X4);
            goto L_80020E70;
    }
    goto skip_0;
    // 0x80020E58: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80020E5C: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80020E60: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80020E64: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80020E68: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x80020E6C: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
L_80020E70:
    // 0x80020E70: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x80020E74: beql        $t1, $zero, L_80020E90
    if (ctx->r9 == 0) {
        // 0x80020E78: lw          $t4, 0x8($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X8);
            goto L_80020E90;
    }
    goto skip_1;
    // 0x80020E78: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    skip_1:
    // 0x80020E7C: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x80020E80: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80020E84: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80020E88: sw          $t3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r11;
    // 0x80020E8C: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
L_80020E90:
    // 0x80020E90: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x80020E94: beq         $t5, $zero, L_80020EAC
    if (ctx->r13 == 0) {
        // 0x80020E98: nop
    
            goto L_80020EAC;
    }
    // 0x80020E98: nop

    // 0x80020E9C: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80020EA0: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80020EA4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80020EA8: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
L_80020EAC:
    // 0x80020EAC: jr          $ra
    // 0x80020EB0: nop

    return;
    // 0x80020EB0: nop

;}
RECOMP_FUNC void func_805A6D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6D2C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x805A6D30: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x805A6D34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A6D38: jal         0x80047090
    // 0x805A6D3C: addiu       $a0, $zero, 0x40B8
    ctx->r4 = ADD32(0, 0X40B8);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805A6D3C: addiu       $a0, $zero, 0x40B8
    ctx->r4 = ADD32(0, 0X40B8);
    after_0:
    // 0x805A6D40: lui         $at, 0x40B8
    ctx->r1 = S32(0X40B8 << 16);
    // 0x805A6D44: ori         $at, $at, 0x4400
    ctx->r1 = ctx->r1 | 0X4400;
    // 0x805A6D48: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x805A6D4C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x805A6D50: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805A6D54: jal         0x8004613C
    // 0x805A6D58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805A6D58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x805A6D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A6D64: jr          $ra
    // 0x805A6D68: nop

    return;
    // 0x805A6D68: nop

    // 0x805A6D6C: nop

;}
RECOMP_FUNC void func_8001A7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A7F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A7F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A7F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001A7FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A800: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A804: beq         $a0, $zero, L_8001A83C
    if (ctx->r4 == 0) {
        // 0x8001A808: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8001A83C;
    }
    // 0x8001A808: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001A80C: jal         0x8001AA08
    // 0x8001A810: nop

    func_8001AA08(rdram, ctx);
        goto after_0;
    // 0x8001A810: nop

    after_0:
    // 0x8001A814: beq         $v0, $zero, L_8001A82C
    if (ctx->r2 == 0) {
        // 0x8001A818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001A82C;
    }
    // 0x8001A818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A81C: jal         0x8001A900
    // 0x8001A820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_1;
    // 0x8001A820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001A824: jal         0x8001A4D4
    // 0x8001A828: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001A4D4(rdram, ctx);
        goto after_2;
    // 0x8001A828: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
L_8001A82C:
    // 0x8001A82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A830: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x8001A834: jal         0x8001AA84
    // 0x8001A838: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_8001AA84(rdram, ctx);
        goto after_3;
    // 0x8001A838: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_8001A83C:
    // 0x8001A83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A848: jr          $ra
    // 0x8001A84C: nop

    return;
    // 0x8001A84C: nop

;}
RECOMP_FUNC void func_8001F8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F8E4: jal         0x8001F27C
    // 0x8001F8E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001F27C(rdram, ctx);
        goto after_0;
    // 0x8001F8E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001F8EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001F8F0: swc1        $f0, 0x120($t6)
    MEM_W(0X120, ctx->r14) = ctx->f0.u32l;
    // 0x8001F8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F8F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F8FC: jr          $ra
    // 0x8001F900: nop

    return;
    // 0x8001F900: nop

;}
RECOMP_FUNC void func_8006CF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF04: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8006CF08: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x8006CF0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CF10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CF18: beq         $t6, $at, L_8006CF28
    if (ctx->r14 == ctx->r1) {
        // 0x8006CF1C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8006CF28;
    }
    // 0x8006CF1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006CF20: jal         0x8006CB78
    // 0x8006CF24: nop

    func_8006CB78(rdram, ctx);
        goto after_0;
    // 0x8006CF24: nop

    after_0:
L_8006CF28:
    // 0x8006CF28: jal         0x8006C3F0
    // 0x8006CF2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006C3F0(rdram, ctx);
        goto after_1;
    // 0x8006CF2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006CF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CF38: jr          $ra
    // 0x8006CF3C: nop

    return;
    // 0x8006CF3C: nop

;}
RECOMP_FUNC void func_80031CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031CB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031CBC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80031CC0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031CC4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80031CC8: bnel        $v0, $zero, L_80031D74
    if (ctx->r2 != 0) {
        // 0x80031CCC: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80031D74;
    }
    goto skip_0;
    // 0x80031CCC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x80031CD0: lw          $t6, -0x7BAC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BAC);
    // 0x80031CD4: addiu       $t7, $t6, -0x9
    ctx->r15 = ADD32(ctx->r14, -0X9);
    // 0x80031CD8: sltiu       $at, $t7, 0x10
    ctx->r1 = ctx->r15 < 0X10 ? 1 : 0;
    // 0x80031CDC: beq         $at, $zero, L_80031D2C
    if (ctx->r1 == 0) {
        // 0x80031CE0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80031D2C;
    }
    // 0x80031CE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031CE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80031CE8: addu        $at, $at, $t7
    gpr jr_addend_80031CF0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80031CEC: lw          $t7, 0x0($at)
    ctx->r15 = ADD32(ctx->r1, 0X0);
    // 0x80031CF0: jr          $t7
    // 0x80031CF4: nop

    switch (jr_addend_80031CF0 >> 2) {
        case 0: goto L_80031CF8; break;
        case 1: goto L_80031D00; break;
        case 2: goto L_80031D0C; break;
        case 3: goto L_80031D18; break;
        case 4: goto L_80031D2C; break;
        case 5: goto L_80031D2C; break;
        case 6: goto L_80031D2C; break;
        case 7: goto L_80031D2C; break;
        case 8: goto L_80031D2C; break;
        case 9: goto L_80031D2C; break;
        case 10: goto L_80031D2C; break;
        case 11: goto L_80031D2C; break;
        case 12: goto L_80031D24; break;
        case 13: goto L_80031D24; break;
        case 14: goto L_80031D24; break;
        case 15: goto L_80031D24; break;
        default: switch_error(__func__, 0x80031CF0, 0x800B0000);
    }
    // 0x80031CF4: nop

L_80031CF8:
    // 0x80031CF8: b           L_80031D2C
    // 0x80031CFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
        goto L_80031D2C;
    // 0x80031CFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80031D00:
    // 0x80031D00: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031D04: b           L_80031D2C
    // 0x80031D08: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_80031D2C;
    // 0x80031D08: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_80031D0C:
    // 0x80031D0C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80031D10: b           L_80031D2C
    // 0x80031D14: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_80031D2C;
    // 0x80031D14: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_80031D18:
    // 0x80031D18: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80031D1C: b           L_80031D2C
    // 0x80031D20: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_80031D2C;
    // 0x80031D20: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_80031D24:
    // 0x80031D24: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80031D28: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_80031D2C:
    // 0x80031D2C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80031D30: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80031D34: addiu       $t4, $t4, -0x1788
    ctx->r12 = ADD32(ctx->r12, -0X1788);
    // 0x80031D38: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80031D3C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80031D40: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80031D44: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80031D48: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80031D4C: jal         0x80030B7C
    // 0x80031D50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80030B7C(rdram, ctx);
        goto after_0;
    // 0x80031D50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80031D54: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80031D58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80031D60: jal         0x800411AC
    // 0x80031D64: sb          $zero, 0x1B4($v1)
    MEM_B(0X1B4, ctx->r3) = 0;
    func_800411AC(rdram, ctx);
        goto after_1;
    // 0x80031D64: sb          $zero, 0x1B4($v1)
    MEM_B(0X1B4, ctx->r3) = 0;
    after_1:
    // 0x80031D68: b           L_80031D7C
    // 0x80031D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031D7C;
    // 0x80031D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031D70: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
L_80031D74:
    // 0x80031D74: sw          $t5, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r13;
    // 0x80031D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031D7C:
    // 0x80031D7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031D80: jr          $ra
    // 0x80031D84: nop

    return;
    // 0x80031D84: nop

;}
RECOMP_FUNC void func_80034F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F2C: jr          $ra
    // 0x80034F30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80034F30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80551620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80551620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80551624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80551628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8055162C: jal         0x80045A34
    // 0x80551630: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80551630: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_0:
    // 0x80551634: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80551638: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8055163C: bne         $v0, $zero, L_8055164C
    if (ctx->r2 != 0) {
        // 0x80551640: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8055164C;
    }
    // 0x80551640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80551644: b           L_80551650
    // 0x80551648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80551650;
    // 0x80551648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8055164C:
    // 0x8055164C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80551650:
    // 0x80551650: jr          $ra
    // 0x80551654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80551654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002756C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002756C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80027570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80027574: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80027578: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8002757C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027580: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x80027584: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80027588: jal         0x80024680
    // 0x8002758C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x8002758C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_0:
    // 0x80027590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027594: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027598: jr          $ra
    // 0x8002759C: nop

    return;
    // 0x8002759C: nop

;}
RECOMP_FUNC void func_8001E20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E20C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E214: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8001E218: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8001E21C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001E220: bnel        $t6, $at, L_8001E258
    if (ctx->r14 != ctx->r1) {
        // 0x8001E224: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E258;
    }
    goto skip_0;
    // 0x8001E224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001E228: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x8001E22C: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8001E230: bnel        $t7, $at, L_8001E258
    if (ctx->r15 != ctx->r1) {
        // 0x8001E234: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E258;
    }
    goto skip_1;
    // 0x8001E234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8001E238: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x8001E23C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001E240: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x8001E244: bnel        $t9, $zero, L_8001E258
    if (ctx->r25 != 0) {
        // 0x8001E248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E258;
    }
    goto skip_2;
    // 0x8001E248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8001E24C: jal         0x8004012C
    // 0x8001E250: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8004012C(rdram, ctx);
        goto after_0;
    // 0x8001E250: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8001E254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E258:
    // 0x8001E258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E25C: jr          $ra
    // 0x8001E260: nop

    return;
    // 0x8001E260: nop

;}
RECOMP_FUNC void func_806F6B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6B84: jal         0x806F6B04
    // 0x806F6B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F6B04(rdram, ctx);
        goto after_0;
    // 0x806F6B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F6B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F6B90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F6B94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F6B98: jal         0x806F6BE4
    // 0x806F6B9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F6BE4(rdram, ctx);
        goto after_1;
    // 0x806F6B9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806F6BA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F6BA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F6BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F6BAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806F6BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F6BB4: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x806F6BB8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x806F6BBC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x806F6BC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F6BC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806F6BC8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806F6BCC: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806F6BD0: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x806F6BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6BDC: jr          $ra
    // 0x806F6BE0: nop

    return;
    // 0x806F6BE0: nop

;}
RECOMP_FUNC void func_8005D608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D610: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005D614: jal         0x80057DC0
    // 0x8005D618: addiu       $a0, $a0, -0x7DC8
    ctx->r4 = ADD32(ctx->r4, -0X7DC8);
    func_80057DC0(rdram, ctx);
        goto after_0;
    // 0x8005D618: addiu       $a0, $a0, -0x7DC8
    ctx->r4 = ADD32(ctx->r4, -0X7DC8);
    after_0:
    // 0x8005D61C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8005D620: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005D624: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005D628: bnel        $t6, $zero, L_8005D63C
    if (ctx->r14 != 0) {
        // 0x8005D62C: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_8005D63C;
    }
    goto skip_0;
    // 0x8005D62C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_0:
    // 0x8005D630: b           L_8005D63C
    // 0x8005D634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D63C;
    // 0x8005D634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D638: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8005D63C:
    // 0x8005D63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D644: jr          $ra
    // 0x8005D648: nop

    return;
    // 0x8005D648: nop

;}
RECOMP_FUNC void func_805D1738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1738: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D173C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D1740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D1744: jal         0x805D17AC
    // 0x805D1748: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805D17AC(rdram, ctx);
        goto after_0;
    // 0x805D1748: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805D174C: beq         $v0, $zero, L_805D1790
    if (ctx->r2 == 0) {
        // 0x805D1750: nop
    
            goto L_805D1790;
    }
    // 0x805D1750: nop

    // 0x805D1754: jal         0x805D17E4
    // 0x805D1758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D17E4(rdram, ctx);
        goto after_1;
    // 0x805D1758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805D175C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x805D1760: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805D1764: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805D1768: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805D176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D1774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D1778: jal         0x805D1974
    // 0x805D177C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D1974(rdram, ctx);
        goto after_2;
    // 0x805D177C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x805D1780: jal         0x805D1720
    // 0x805D1784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D1720(rdram, ctx);
        goto after_3;
    // 0x805D1784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805D1788: b           L_805D179C
    // 0x805D178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805D179C;
    // 0x805D178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D1790:
    // 0x805D1790: jal         0x800445A4
    // 0x805D1794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x805D1794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805D1798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D179C:
    // 0x805D179C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D17A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D17A4: jr          $ra
    // 0x805D17A8: nop

    return;
    // 0x805D17A8: nop

;}
RECOMP_FUNC void func_800528C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800528C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800528CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800528D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800528D4: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x800528D8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800528DC: beq         $t7, $zero, L_800528F8
    if (ctx->r15 == 0) {
        // 0x800528E0: nop
    
            goto L_800528F8;
    }
    // 0x800528E0: nop

    // 0x800528E4: jal         0x8005FE48
    // 0x800528E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x800528E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800528EC: jal         0x80052860
    // 0x800528F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80052860(rdram, ctx);
        goto after_1;
    // 0x800528F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800528F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800528F8:
    // 0x800528F8: jal         0x80064E84
    // 0x800528FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x800528FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80052900: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80052904: sw          $zero, 0x174($t8)
    MEM_W(0X174, ctx->r24) = 0;
    // 0x80052908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005290C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80052910: jr          $ra
    // 0x80052914: nop

    return;
    // 0x80052914: nop

;}
RECOMP_FUNC void func_8003BA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003BA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BA98: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8003BA9C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8003BAA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003BAA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003BAA8: jal         0x80047090
    // 0x8003BAAC: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8003BAAC: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    after_0:
    // 0x8003BAB0: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x8003BAB4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BAB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003BABC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8003BAC0: or          $a1, $v0, $t7
    ctx->r5 = ctx->r2 | ctx->r15;
    // 0x8003BAC4: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x8003BAC8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8003BACC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8003BAD0: jal         0x80046804
    // 0x8003BAD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x8003BAD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8003BAD8: bne         $v0, $zero, L_8003BAE8
    if (ctx->r2 != 0) {
        // 0x8003BADC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8003BAE8;
    }
    // 0x8003BADC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8003BAE0: b           L_8003BB10
    // 0x8003BAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003BB10;
    // 0x8003BAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BAE8:
    // 0x8003BAE8: lw          $t8, 0x16C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X16C);
    // 0x8003BAEC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8003BAF0: bnel        $t9, $zero, L_8003BB04
    if (ctx->r25 != 0) {
        // 0x8003BAF4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8003BB04;
    }
    goto skip_0;
    // 0x8003BAF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8003BAF8: jal         0x8003B890
    // 0x8003BAFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8003B890(rdram, ctx);
        goto after_2;
    // 0x8003BAFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8003BB00: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8003BB04:
    // 0x8003BB04: jal         0x8003B8B0
    // 0x8003BB08: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_8003B8B0(rdram, ctx);
        goto after_3;
    // 0x8003BB08: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x8003BB0C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8003BB10:
    // 0x8003BB10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BB14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003BB18: jr          $ra
    // 0x8003BB1C: nop

    return;
    // 0x8003BB1C: nop

;}
RECOMP_FUNC void func_8078F7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078F7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F7DC: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8078F7E0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078F7E4: bnel        $t6, $at, L_8078F830
    if (ctx->r14 != ctx->r1) {
        // 0x8078F7E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F830;
    }
    goto skip_0;
    // 0x8078F7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078F7EC: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078F7F0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078F7F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078F7F8: bnel        $t8, $zero, L_8078F830
    if (ctx->r24 != 0) {
        // 0x8078F7FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F830;
    }
    goto skip_1;
    // 0x8078F7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8078F800: lbu         $t9, -0x764C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X764C);
    // 0x8078F804: bnel        $t9, $zero, L_8078F830
    if (ctx->r25 != 0) {
        // 0x8078F808: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F830;
    }
    goto skip_2;
    // 0x8078F808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8078F80C: lbu         $t0, 0x165($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X165);
    // 0x8078F810: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078F814: beql        $t0, $at, L_8078F830
    if (ctx->r8 == ctx->r1) {
        // 0x8078F818: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F830;
    }
    goto skip_3;
    // 0x8078F818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8078F81C: jal         0x8004012C
    // 0x8078F820: nop

    func_8004012C(rdram, ctx);
        goto after_0;
    // 0x8078F820: nop

    after_0:
    // 0x8078F824: jal         0x800497D4
    // 0x8078F828: nop

    func_800497D4(rdram, ctx);
        goto after_1;
    // 0x8078F828: nop

    after_1:
    // 0x8078F82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078F830:
    // 0x8078F830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078F834: jr          $ra
    // 0x8078F838: nop

    return;
    // 0x8078F838: nop

;}
RECOMP_FUNC void func_804C95D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C95D0: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x804C95D4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804C95D8: sltiu       $at, $t7, 0x4
    ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
    // 0x804C95DC: bne         $at, $zero, L_804C961C
    if (ctx->r1 != 0) {
        // 0x804C95E0: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_804C961C;
    }
    // 0x804C95E0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x804C95E4: lh          $t1, 0x144($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X144);
    // 0x804C95E8: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x804C95EC: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x804C95F0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x804C95F4: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x804C95F8: lh          $t3, 0x144($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X144);
    // 0x804C95FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x804C9600: sw          $t0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r8;
    // 0x804C9604: slti        $at, $t3, 0xF
    ctx->r1 = SIGNED(ctx->r11) < 0XF ? 1 : 0;
    // 0x804C9608: bne         $at, $zero, L_804C961C
    if (ctx->r1 != 0) {
        // 0x804C960C: sltiu       $at, $t0, 0x1E
        ctx->r1 = ctx->r8 < 0X1E ? 1 : 0;
            goto L_804C961C;
    }
    // 0x804C960C: sltiu       $at, $t0, 0x1E
    ctx->r1 = ctx->r8 < 0X1E ? 1 : 0;
    // 0x804C9610: bne         $at, $zero, L_804C961C
    if (ctx->r1 != 0) {
        // 0x804C9614: sh          $zero, 0x144($a0)
        MEM_H(0X144, ctx->r4) = 0;
            goto L_804C961C;
    }
    // 0x804C9614: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x804C9618: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
L_804C961C:
    // 0x804C961C: jr          $ra
    // 0x804C9620: nop

    return;
    // 0x804C9620: nop

;}
RECOMP_FUNC void func_8000CBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBFC: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x8000CC00: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x8000CC04: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000CC08: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8000CC0C: sra         $v0, $v0, 8
    ctx->r2 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8000CC10: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8000CC14: sltiu       $at, $v0, 0x7F
    ctx->r1 = ctx->r2 < 0X7F ? 1 : 0;
    // 0x8000CC18: bnel        $at, $zero, L_8000CC2C
    if (ctx->r1 != 0) {
        // 0x8000CC1C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000CC2C;
    }
    goto skip_0;
    // 0x8000CC1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8000CC20: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8000CC24: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8000CC28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8000CC2C:
    // 0x8000CC2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000CC30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000CC34: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000CC38: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000CC3C: lwc1        $f4, 0x63D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63D4);
    // 0x8000CC40: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000CC44: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8000CC48: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000CC4C: add.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8000CC50: jr          $ra
    // 0x8000CC54: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8000CC54: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8045360C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045360C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453614: jal         0x8045341C
    // 0x80453618: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8045341C(rdram, ctx);
        goto after_0;
    // 0x80453618: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x8045361C: jal         0x80445CBC
    // 0x80453620: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80445CBC(rdram, ctx);
        goto after_1;
    // 0x80453620: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x80453624: jal         0x80445D08
    // 0x80453628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445D08(rdram, ctx);
        goto after_2;
    // 0x80453628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8045362C: jal         0x804444FC
    // 0x80453630: nop

    static_98_804444FC(rdram, ctx);
        goto after_3;
    // 0x80453630: nop

    after_3:
    // 0x80453634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045363C: jr          $ra
    // 0x80453640: nop

    return;
    // 0x80453640: nop

;}
RECOMP_FUNC void func_80526A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526A7C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526A80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80526A84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80526A88: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80526A8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80526A90: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80526A94: nop

    // 0x80526A98: bc1fl       L_80526AF0
    if (!c1cs) {
        // 0x80526A9C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80526AF0;
    }
    goto skip_0;
    // 0x80526A9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80526AA0: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80526AA4: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
    // 0x80526AA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526AAC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80526AB0: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80526AB4: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80526AB8: bne         $at, $zero, L_80526AD0
    if (ctx->r1 != 0) {
        // 0x80526ABC: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80526AD0;
    }
    // 0x80526ABC: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80526AC0: jal         0x80526C4C
    // 0x80526AC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80526C4C(rdram, ctx);
        goto after_0;
    // 0x80526AC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80526AC8: b           L_80526B00
    // 0x80526ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80526B00;
    // 0x80526ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526AD0:
    // 0x80526AD0: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80526AD4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80526AD8: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80526ADC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80526AE0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80526AE4: b           L_80526AFC
    // 0x80526AE8: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_80526AFC;
    // 0x80526AE8: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80526AEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80526AF0:
    // 0x80526AF0: nop

    // 0x80526AF4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80526AF8: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_80526AFC:
    // 0x80526AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526B00:
    // 0x80526B00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526B04: jr          $ra
    // 0x80526B08: nop

    return;
    // 0x80526B08: nop

;}
RECOMP_FUNC void func_80424550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80424554: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80424558: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042455C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80424560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424564: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80424568: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042456C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80424570: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80424574: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80424578: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042457C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80424580: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X328C) << 16);
    // 0x80424584: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80424588: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042458C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80424590: lw          $t2, 0x5C8C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(35, 0X328C));
    // 0x80424594: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80424598: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042459C: jal         0x80423E24
    // 0x804245A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80423E24(rdram, ctx);
        goto after_0;
    // 0x804245A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804245A4: jal         0x80423E80
    // 0x804245A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80423E80(rdram, ctx);
        goto after_1;
    // 0x804245A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804245AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804245B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804245B4: jr          $ra
    // 0x804245B8: nop

    return;
    // 0x804245B8: nop

;}
RECOMP_FUNC void func_804D6300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D6300: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(252, 0X5F0) << 16);
    // 0x804D6304: lw          $t6, 0x68F0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(252, 0X5F0));
    // 0x804D6308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D630C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D6310: bne         $t6, $zero, L_804D633C
    if (ctx->r14 != 0) {
        // 0x804D6314: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_804D633C;
    }
    // 0x804D6314: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D6318: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(252, 0X720) << 16);
    // 0x804D631C: lui         $a1, 0x804D
    ctx->r5 = S32(RELOC_HI16(252, 0X730) << 16);
    // 0x804D6320: addiu       $a1, $a1, 0x6A30
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(252, 0X730));
    // 0x804D6324: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(252, 0X720));
    // 0x804D6328: jal         0x8004667C
    // 0x804D632C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804D632C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x804D6330: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804D6334: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(252, 0X5F0) << 16);
    // 0x804D6338: sw          $t7, 0x68F0($at)
    MEM_W((int16_t)RELOC_LO16(252, 0X5F0), ctx->r1) = ctx->r15;
L_804D633C:
    // 0x804D633C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804D6340: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804D6344: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x804D6348: lui         $a2, 0x804D
    ctx->r6 = S32(RELOC_HI16(252, 0X38C) << 16);
    // 0x804D634C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x804D6350: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x804D6354: bnel        $t9, $zero, L_804D6368
    if (ctx->r25 != 0) {
        // 0x804D6358: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804D6368;
    }
    goto skip_0;
    // 0x804D6358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804D635C: jal         0x80057B28
    // 0x804D6360: addiu       $a2, $a2, 0x668C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(252, 0X38C));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804D6360: addiu       $a2, $a2, 0x668C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(252, 0X38C));
    after_1:
    // 0x804D6364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D6368:
    // 0x804D6368: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(252, 0X78) << 16);
    // 0x804D636C: addiu       $v0, $v0, 0x6378
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(252, 0X78));
    // 0x804D6370: jr          $ra
    // 0x804D6374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D6374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8040E1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E1E8: jal         0x8040DCF0
    // 0x8040E1EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040DCF0(rdram, ctx);
        goto after_0;
    // 0x8040E1EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040E1F0: bne         $v0, $zero, L_8040E208
    if (ctx->r2 != 0) {
        // 0x8040E1F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040E208;
    }
    // 0x8040E1F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040E1F8: jal         0x800445A4
    // 0x8040E1FC: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040E1FC: nop

    after_1:
    // 0x8040E200: b           L_8040E248
    // 0x8040E204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040E248;
    // 0x8040E204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E208:
    // 0x8040E208: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040E20C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8040E210: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8040E214: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x8040E218: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8040E21C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8040E220: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040E224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040E228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040E22C: jal         0x8040E254
    // 0x8040E230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040E230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8040E234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040E238: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8040E23C: jal         0x8005FE48
    // 0x8040E240: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8040E240: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    after_3:
    // 0x8040E244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E248:
    // 0x8040E248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E24C: jr          $ra
    // 0x8040E250: nop

    return;
    // 0x8040E250: nop

;}
RECOMP_FUNC void func_8002FDF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FDFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FE00: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FE04: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FE08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002FE0C: jal         0x8002F678
    // 0x8002FE10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FE10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FE14: beq         $v0, $zero, L_8002FE28
    if (ctx->r2 == 0) {
        // 0x8002FE18: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FE28;
    }
    // 0x8002FE18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FE1C: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FE20: addiu       $t6, $t6, -0x4394
    ctx->r14 = ADD32(ctx->r14, -0X4394);
    // 0x8002FE24: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FE28:
    // 0x8002FE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FE2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FE30: jr          $ra
    // 0x8002FE34: nop

    return;
    // 0x8002FE34: nop

;}
RECOMP_FUNC void func_800509EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800509EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800509F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800509F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800509F8: jal         0x800506B4
    // 0x800509FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800506B4(rdram, ctx);
        goto after_0;
    // 0x800509FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80050A00: bne         $v0, $zero, L_80050A10
    if (ctx->r2 != 0) {
        // 0x80050A04: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80050A10;
    }
    // 0x80050A04: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80050A08: b           L_80050A1C
    // 0x80050A0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050A1C;
    // 0x80050A0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050A10:
    // 0x80050A10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80050A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050A18: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80050A1C:
    // 0x80050A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050A24: jr          $ra
    // 0x80050A28: nop

    return;
    // 0x80050A28: nop

;}
RECOMP_FUNC void func_80400050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400050: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80400054: lui         $t6, 0x8040
    ctx->r14 = S32(RELOC_HI16(8, 0X1220) << 16);
    // 0x80400058: addiu       $t6, $t6, 0x1260
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(8, 0X1220));
    // 0x8040005C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80400060: jr          $ra
    // 0x80400064: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80400064: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8001C648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C648: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001C64C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C654: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x8001C658: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C65C: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8001C660: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001C664: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001C668: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8001C66C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001C670: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x8001C674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001C678: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8001C67C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8001C680: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001C684: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001C688: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8001C68C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001C690: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001C694: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8001C698: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001C69C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8001C6A0: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8001C6A4: jal         0x80066DE4
    // 0x8001C6A8: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8001C6A8: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8001C6AC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8001C6B0: jal         0x80066E88
    // 0x8001C6B4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8001C6B4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8001C6B8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001C6BC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C6C0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8001C6C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001C6C8: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001C6CC: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8001C6D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001C6D4: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C6DC: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C6E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001C6E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8001C6E8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8001C6EC: jal         0x800485B8
    // 0x8001C6F0: nop

    func_800485B8(rdram, ctx);
        goto after_2;
    // 0x8001C6F0: nop

    after_2:
    // 0x8001C6F4: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8001C6F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001C6FC: lwc1        $f0, -0x470($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X470);
    // 0x8001C700: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001C704: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001C708: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8001C70C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001C710: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001C714: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001C718: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8001C71C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x8001C720: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001C724: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8001C728: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001C72C: lbu         $t1, 0x165($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X165);
    // 0x8001C730: sb          $t1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r9;
    // 0x8001C734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C738: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C73C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001C740: jr          $ra
    // 0x8001C744: nop

    return;
    // 0x8001C744: nop

;}
RECOMP_FUNC void func_8043813C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043813C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438140: lwc1        $f2, 0xC8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80438144: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80438148: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8043814C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80438150: nop

    // 0x80438154: bc1f        L_80438178
    if (!c1cs) {
        // 0x80438158: nop
    
            goto L_80438178;
    }
    // 0x80438158: nop

    // 0x8043815C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80438160: nop

    // 0x80438164: bc1f        L_80438178
    if (!c1cs) {
        // 0x80438168: nop
    
            goto L_80438178;
    }
    // 0x80438168: nop

    // 0x8043816C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80438170: nop

    // 0x80438174: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
L_80438178:
    // 0x80438178: jr          $ra
    // 0x8043817C: nop

    return;
    // 0x8043817C: nop

;}
RECOMP_FUNC void func_806FD8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD8E4: jal         0x8004700C
    // 0x806FD8E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806FD8E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FD8EC: bne         $v0, $zero, L_806FD8FC
    if (ctx->r2 != 0) {
        // 0x806FD8F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806FD8FC;
    }
    // 0x806FD8F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FD8F4: b           L_806FD94C
    // 0x806FD8F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD94C;
    // 0x806FD8F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FD8FC:
    // 0x806FD8FC: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806FD900: bnel        $t6, $zero, L_806FD92C
    if (ctx->r14 != 0) {
        // 0x806FD904: lwc1        $f8, 0x84($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
            goto L_806FD92C;
    }
    goto skip_0;
    // 0x806FD904: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    skip_0:
    // 0x806FD908: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806FD90C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806FD910: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806FD914: nop

    // 0x806FD918: bc1fl       L_806FD94C
    if (!c1cs) {
        // 0x806FD91C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806FD94C;
    }
    goto skip_1;
    // 0x806FD91C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x806FD920: b           L_806FD94C
    // 0x806FD924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD94C;
    // 0x806FD924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FD928: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
L_806FD92C:
    // 0x806FD92C: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806FD930: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806FD934: nop

    // 0x806FD938: bc1fl       L_806FD94C
    if (!c1cs) {
        // 0x806FD93C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806FD94C;
    }
    goto skip_2;
    // 0x806FD93C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x806FD940: b           L_806FD94C
    // 0x806FD944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD94C;
    // 0x806FD944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FD948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FD94C:
    // 0x806FD94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD954: jr          $ra
    // 0x806FD958: nop

    return;
    // 0x806FD958: nop

;}
RECOMP_FUNC void func_8002513C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002513C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025144: jal         0x80024FF8
    // 0x80025148: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    func_80024FF8(rdram, ctx);
        goto after_0;
    // 0x80025148: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_0:
    // 0x8002514C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025154: jr          $ra
    // 0x80025158: nop

    return;
    // 0x80025158: nop

;}
RECOMP_FUNC void func_8002F9D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F9D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F9D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F9DC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8002F9E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F9E4: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F9E8: beql        $t6, $zero, L_8002FA08
    if (ctx->r14 == 0) {
        // 0x8002F9EC: lw          $t9, 0x34($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X34);
            goto L_8002FA08;
    }
    goto skip_0;
    // 0x8002F9EC: lw          $t9, 0x34($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X34);
    skip_0:
    // 0x8002F9F0: lw          $t7, 0x34($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X34);
    // 0x8002F9F4: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8002F9F8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002F9FC: b           L_8002FA14
    // 0x8002FA00: sw          $t8, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r24;
        goto L_8002FA14;
    // 0x8002FA00: sw          $t8, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r24;
    // 0x8002FA04: lw          $t9, 0x34($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X34);
L_8002FA08:
    // 0x8002FA08: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8002FA0C: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8002FA10: sw          $t0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r8;
L_8002FA14:
    // 0x8002FA14: lw          $t1, 0x34($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X34);
    // 0x8002FA18: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8002FA1C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8002FA20: sw          $t2, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r10;
    // 0x8002FA24: lbu         $t3, 0x18($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X18);
    // 0x8002FA28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002FA2C: bnel        $t3, $at, L_8002FAB0
    if (ctx->r11 != ctx->r1) {
        // 0x8002FA30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FAB0;
    }
    goto skip_1;
    // 0x8002FA30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8002FA34: lbu         $t4, 0x30($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X30);
    // 0x8002FA38: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8002FA3C: beql        $t4, $at, L_8002FAB0
    if (ctx->r12 == ctx->r1) {
        // 0x8002FA40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FAB0;
    }
    goto skip_2;
    // 0x8002FA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8002FA44: lw          $t5, 0x24($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X24);
    // 0x8002FA48: andi        $t6, $t5, 0x700
    ctx->r14 = ctx->r13 & 0X700;
    // 0x8002FA4C: beql        $t6, $zero, L_8002FAB0
    if (ctx->r14 == 0) {
        // 0x8002FA50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FAB0;
    }
    goto skip_3;
    // 0x8002FA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8002FA54: lbu         $t7, 0x154($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X154);
    // 0x8002FA58: bnel        $t7, $zero, L_8002FAB0
    if (ctx->r15 != 0) {
        // 0x8002FA5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FAB0;
    }
    goto skip_4;
    // 0x8002FA5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8002FA60: lbu         $t8, 0x155($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X155);
    // 0x8002FA64: bnel        $t8, $zero, L_8002FAB0
    if (ctx->r24 != 0) {
        // 0x8002FA68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FAB0;
    }
    goto skip_5;
    // 0x8002FA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8002FA6C: lbu         $t9, 0x1F8($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X1F8);
    // 0x8002FA70: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8002FA74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002FA78: bnel        $t9, $zero, L_8002FAB0
    if (ctx->r25 != 0) {
        // 0x8002FA7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FAB0;
    }
    goto skip_6;
    // 0x8002FA7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8002FA80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002FA84: jal         0x8002F678
    // 0x8002FA88: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FA88: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002FA8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002FA90: beq         $v0, $zero, L_8002FAAC
    if (ctx->r2 == 0) {
        // 0x8002FA94: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FAAC;
    }
    // 0x8002FA94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FA98: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x8002FA9C: addiu       $t0, $t0, -0x12C4
    ctx->r8 = ADD32(ctx->r8, -0X12C4);
    // 0x8002FAA0: sw          $t0, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r8;
    // 0x8002FAA4: lw          $t1, 0x138($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X138);
    // 0x8002FAA8: sw          $t1, 0xD4($a3)
    MEM_W(0XD4, ctx->r7) = ctx->r9;
L_8002FAAC:
    // 0x8002FAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FAB0:
    // 0x8002FAB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FAB4: jr          $ra
    // 0x8002FAB8: nop

    return;
    // 0x8002FAB8: nop

;}
RECOMP_FUNC void func_804466CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804466CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804466D0: addiu       $v1, $zero, 0xAC8
    ctx->r3 = ADD32(0, 0XAC8);
    // 0x804466D4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804466D8: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x804466DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804466E0: sw          $zero, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = 0;
    // 0x804466E4: addiu       $a1, $zero, 0x744
    ctx->r5 = ADD32(0, 0X744);
    // 0x804466E8: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x804466EC: sw          $t6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r14;
    // 0x804466F0: sw          $a1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r5;
    // 0x804466F4: sw          $a1, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r5;
    // 0x804466F8: sw          $a1, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->r5;
    // 0x804466FC: jr          $ra
    // 0x80446700: sw          $v1, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r3;
    return;
    // 0x80446700: sw          $v1, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_80038250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038258: jal         0x80021958
    // 0x8003825C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003825C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038260: bne         $v0, $zero, L_80038270
    if (ctx->r2 != 0) {
        // 0x80038264: nop
    
            goto L_80038270;
    }
    // 0x80038264: nop

    // 0x80038268: b           L_800382A4
    // 0x8003826C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800382A4;
    // 0x8003826C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038270:
    // 0x80038270: jal         0x800415FC
    // 0x80038274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80038274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038278: beq         $v0, $zero, L_80038288
    if (ctx->r2 == 0) {
        // 0x8003827C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80038288;
    }
    // 0x8003827C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038280: b           L_800382A4
    // 0x80038284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800382A4;
    // 0x80038284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038288:
    // 0x80038288: jal         0x8003776C
    // 0x8003828C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8003776C(rdram, ctx);
        goto after_2;
    // 0x8003828C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
    // 0x80038290: bnel        $v0, $zero, L_800382A4
    if (ctx->r2 != 0) {
        // 0x80038294: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800382A4;
    }
    goto skip_0;
    // 0x80038294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038298: b           L_800382A4
    // 0x8003829C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800382A4;
    // 0x8003829C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800382A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800382A4:
    // 0x800382A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800382A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800382AC: jr          $ra
    // 0x800382B0: nop

    return;
    // 0x800382B0: nop

;}
RECOMP_FUNC void func_805D35B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D35B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D35B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D35BC: jal         0x805D32D4
    // 0x805D35C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D32D4(rdram, ctx);
        goto after_0;
    // 0x805D35C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D35C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D35C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D35CC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x805D35D0: jal         0x805D3B18
    // 0x805D35D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D35D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D35D8: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805D35DC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x805D35E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805D35E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805D35E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D35EC: addiu       $v0, $v1, 0xC4
    ctx->r2 = ADD32(ctx->r3, 0XC4);
    // 0x805D35F0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2558) << 16);
    // 0x805D35F4: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x805D35F8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x805D35FC: lwc1        $f8, 0x3F88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X2558));
    // 0x805D3600: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x805D3604: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x805D3608: sh          $t6, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r14;
    // 0x805D360C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3614: jr          $ra
    // 0x805D3618: nop

    return;
    // 0x805D3618: nop

;}
RECOMP_FUNC void func_806E6EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E6EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E6EB8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E6EBC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806E6EC0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(658, 0X1B8) << 16);
    // 0x806E6EC4: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x806E6EC8: beq         $a3, $zero, L_806E6F44
    if (ctx->r7 == 0) {
        // 0x806E6ECC: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_806E6F44;
    }
    // 0x806E6ECC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x806E6ED0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x806E6ED4: lwc1        $f4, 0x7058($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(658, 0X1B8));
    // 0x806E6ED8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806E6EDC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(658, 0X220) << 16);
    // 0x806E6EE0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x806E6EE4: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x806E6EE8: lwc1        $f8, 0x70C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(658, 0X220));
    // 0x806E6EEC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(658, 0X224) << 16);
    // 0x806E6EF0: lui         $t0, 0x806E
    ctx->r8 = S32(RELOC_HI16(658, 0X1E4) << 16);
    // 0x806E6EF4: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x806E6EF8: lwc1        $f10, 0x70C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(658, 0X224));
    // 0x806E6EFC: addiu       $t0, $t0, 0x7084
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(658, 0X1E4));
    // 0x806E6F00: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806E6F04: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x806E6F08: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x806E6F0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806E6F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E6F14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806E6F18: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x806E6F1C: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x806E6F20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806E6F24: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806E6F28: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806E6F2C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x806E6F30: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806E6F34: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x806E6F38: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x806E6F3C: jal         0x806E7010
    // 0x806E6F40: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    func_806E7010(rdram, ctx);
        goto after_0;
    // 0x806E6F40: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    after_0:
L_806E6F44:
    // 0x806E6F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E6F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E6F4C: jr          $ra
    // 0x806E6F50: nop

    return;
    // 0x806E6F50: nop

;}
RECOMP_FUNC void func_8004E2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E2AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E2B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E2B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004E2B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004E2BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004E2C0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004E2C4: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004E2C8: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004E2CC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004E2D0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004E2D4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E2D8: addu        $s0, $t8, $t0
    ctx->r16 = ADD32(ctx->r24, ctx->r8);
    // 0x8004E2DC: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8004E2E0: beql        $v0, $zero, L_8004E334
    if (ctx->r2 == 0) {
        // 0x8004E2E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E334;
    }
    goto skip_0;
    // 0x8004E2E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004E2E8: beql        $v0, $at, L_8004E334
    if (ctx->r2 == ctx->r1) {
        // 0x8004E2EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E334;
    }
    goto skip_1;
    // 0x8004E2EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8004E2F0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004E2F4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E2F8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004E2FC: beq         $v0, $at, L_8004E330
    if (ctx->r2 == ctx->r1) {
        // 0x8004E300: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E330;
    }
    // 0x8004E300: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E304: beq         $v0, $at, L_8004E330
    if (ctx->r2 == ctx->r1) {
        // 0x8004E308: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004E330;
    }
    // 0x8004E308: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004E30C: jal         0x8004D038
    // 0x8004E310: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8004D038(rdram, ctx);
        goto after_0;
    // 0x8004E310: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x8004E314: lbu         $t1, 0x14($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X14);
    // 0x8004E318: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004E31C: beql        $t1, $zero, L_8004E334
    if (ctx->r9 == 0) {
        // 0x8004E320: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E334;
    }
    goto skip_2;
    // 0x8004E320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8004E324: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004E328: ori         $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 | 0XF0;
    // 0x8004E32C: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_8004E330:
    // 0x8004E330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E334:
    // 0x8004E334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004E338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E33C: jr          $ra
    // 0x8004E340: nop

    return;
    // 0x8004E340: nop

;}
RECOMP_FUNC void func_8006BC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC70: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006BC74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006BC78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8006BC7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8006BC80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006BC84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006BC88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006BC8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006BC90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006BC94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006BC98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BC9C: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8006BCA0: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x8006BCA4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8006BCA8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8006BCAC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BCB0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8006BCB4: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8006BCB8: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8006BCBC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8006BCC0: ori         $s2, $zero, 0x8000
    ctx->r18 = 0 | 0X8000;
    // 0x8006BCC4: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8006BCC8: mflo        $s6
    ctx->r22 = lo;
    // 0x8006BCCC: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8006BCD0: beq         $t8, $zero, L_8006BD74
    if (ctx->r24 == 0) {
        // 0x8006BCD4: sra         $s6, $s6, 16
        ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
            goto L_8006BD74;
    }
    // 0x8006BCD4: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
L_8006BCD8:
    // 0x8006BCD8: lhu         $t9, 0x0($fp)
    ctx->r25 = MEM_HU(ctx->r30, 0X0);
    // 0x8006BCDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006BCE0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8006BCE4: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BCE8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006BCEC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8006BCF0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8006BCF4: mflo        $t0
    ctx->r8 = lo;
    // 0x8006BCF8: addu        $a2, $t0, $s7
    ctx->r6 = ADD32(ctx->r8, ctx->r23);
    // 0x8006BCFC: jal         0x8006BB04
    // 0x8006BD00: nop

    func_8006BB04(rdram, ctx);
        goto after_0;
    // 0x8006BD00: nop

    after_0:
    // 0x8006BD04: lhu         $t2, 0x2($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X2);
    // 0x8006BD08: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8006BD0C: beq         $s2, $t2, L_8006BD58
    if (ctx->r18 == ctx->r10) {
        // 0x8006BD10: sll         $s0, $s0, 1
        ctx->r16 = S32(ctx->r16 << 1);
            goto L_8006BD58;
    }
    // 0x8006BD10: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8006BD14: addu        $s1, $fp, $s0
    ctx->r17 = ADD32(ctx->r30, ctx->r16);
    // 0x8006BD18: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
L_8006BD1C:
    // 0x8006BD1C: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006BD24: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8006BD28: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8006BD2C: mflo        $t3
    ctx->r11 = lo;
    // 0x8006BD30: addu        $a1, $t3, $s7
    ctx->r5 = ADD32(ctx->r11, ctx->r23);
    // 0x8006BD34: jal         0x8006BBEC
    // 0x8006BD38: nop

    func_8006BBEC(rdram, ctx);
        goto after_1;
    // 0x8006BD38: nop

    after_1:
    // 0x8006BD3C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006BD40: sltiu       $at, $s0, 0xA
    ctx->r1 = ctx->r16 < 0XA ? 1 : 0;
    // 0x8006BD44: beq         $at, $zero, L_8006BD58
    if (ctx->r1 == 0) {
        // 0x8006BD48: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8006BD58;
    }
    // 0x8006BD48: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8006BD4C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8006BD50: bne         $s2, $v0, L_8006BD1C
    if (ctx->r18 != ctx->r2) {
        // 0x8006BD54: nop
    
            goto L_8006BD1C;
    }
    // 0x8006BD54: nop

L_8006BD58:
    // 0x8006BD58: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006BD5C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8006BD60: addu        $s4, $s4, $s6
    ctx->r20 = ADD32(ctx->r20, ctx->r22);
    // 0x8006BD64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006BD68: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8006BD6C: bne         $v0, $t4, L_8006BCD8
    if (ctx->r2 != ctx->r12) {
        // 0x8006BD70: addiu       $fp, $fp, 0xA
        ctx->r30 = ADD32(ctx->r30, 0XA);
            goto L_8006BCD8;
    }
    // 0x8006BD70: addiu       $fp, $fp, 0xA
    ctx->r30 = ADD32(ctx->r30, 0XA);
L_8006BD74:
    // 0x8006BD74: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006BD78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006BD7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BD80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006BD84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006BD88: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006BD8C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BD90: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006BD94: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006BD98: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8006BD9C: jr          $ra
    // 0x8006BDA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006BDA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8064C8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C8F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C8F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C8FC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064C900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C904: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8064C908: blez        $v0, L_8064C918
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064C90C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8064C918;
    }
    // 0x8064C90C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064C910: b           L_8064C920
    // 0x8064C914: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064C920;
    // 0x8064C914: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064C918:
    // 0x8064C918: jal         0x8064CD50
    // 0x8064C91C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C91C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
L_8064C920:
    // 0x8064C920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064C924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C928: jr          $ra
    // 0x8064C92C: nop

    return;
    // 0x8064C92C: nop

;}
RECOMP_FUNC void func_8069EBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EBB0: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8069EBB4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069EBB8: lui         $t0, 0x806A
    ctx->r8 = S32(RELOC_HI16(577, 0X158) << 16);
    // 0x8069EBBC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8069EBC0: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x8069EBC4: addiu       $t0, $t0, -0x1AD8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(577, 0X158));
    // 0x8069EBC8: sw          $t7, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->r15;
    // 0x8069EBCC: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8069EBD0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8069EBD4: jr          $ra
    // 0x8069EBD8: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    return;
    // 0x8069EBD8: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
;}
RECOMP_FUNC void func_804F4CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4CF8: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x804F4CFC: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x804F4D00: addiu       $v1, $a0, 0x68
    ctx->r3 = ADD32(ctx->r4, 0X68);
    // 0x804F4D04: bne         $t6, $zero, L_804F4D70
    if (ctx->r14 != 0) {
        // 0x804F4D08: addiu       $v0, $v0, 0x6
        ctx->r2 = ADD32(ctx->r2, 0X6);
            goto L_804F4D70;
    }
    // 0x804F4D08: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x804F4D0C: addiu       $v1, $a0, 0x68
    ctx->r3 = ADD32(ctx->r4, 0X68);
    // 0x804F4D10: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x804F4D14: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x804F4D18: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x804F4D1C: beql        $at, $zero, L_804F4D68
    if (ctx->r1 == 0) {
        // 0x804F4D20: sw          $zero, 0xC($v1)
        MEM_W(0XC, ctx->r3) = 0;
            goto L_804F4D68;
    }
    goto skip_0;
    // 0x804F4D20: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    skip_0:
    // 0x804F4D24: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x804F4D28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804F4D2C: lui         $t2, 0x8051
    ctx->r10 = S32(RELOC_HI16(273, 0X207AC) << 16);
    // 0x804F4D30: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804F4D34: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x804F4D38: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x804F4D3C: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x804F4D40: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804F4D44: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x804F4D48: lhu         $t2, 0x4A3C($t2)
    ctx->r10 = MEM_HU(ctx->r10, (int16_t)RELOC_LO16(273, 0X207AC));
    // 0x804F4D4C: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x804F4D50: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x804F4D54: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x804F4D58: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x804F4D5C: b           L_804F4D7C
    // 0x804F4D60: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
        goto L_804F4D7C;
    // 0x804F4D60: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x804F4D64: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_804F4D68:
    // 0x804F4D68: jr          $ra
    // 0x804F4D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x804F4D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F4D70:
    // 0x804F4D70: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x804F4D74: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x804F4D78: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
L_804F4D7C:
    // 0x804F4D7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804F4D80: jr          $ra
    // 0x804F4D84: nop

    return;
    // 0x804F4D84: nop

;}
RECOMP_FUNC void func_8049F3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F3B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8049F3BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049F3C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049F3C4: jal         0x8049EF18
    // 0x8049F3C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8049EF18(rdram, ctx);
        goto after_0;
    // 0x8049F3C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8049F3CC: lh          $t6, 0x144($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X144);
    // 0x8049F3D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8049F3D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F3D8: bne         $t6, $at, L_8049F40C
    if (ctx->r14 != ctx->r1) {
        // 0x8049F3DC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8049F40C;
    }
    // 0x8049F3DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F3E0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8049F3E4: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x8049F3E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8049F3EC: jal         0x8049FBAC
    // 0x8049F3F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8049FBAC(rdram, ctx);
        goto after_1;
    // 0x8049F3F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8049F3F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8049F3F8: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x8049F3FC: jal         0x80048378
    // 0x8049F400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x8049F400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8049F404: b           L_8049F428
    // 0x8049F408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8049F428;
    // 0x8049F408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8049F40C:
    // 0x8049F40C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8049F410: jal         0x80067BBC
    // 0x8049F414: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8049F414: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8049F418: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8049F41C: jal         0x80067818
    // 0x8049F420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8049F420: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8049F424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8049F428:
    // 0x8049F428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049F42C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8049F430: jr          $ra
    // 0x8049F434: nop

    return;
    // 0x8049F434: nop

;}
RECOMP_FUNC void func_8052D71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D71C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8052D720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052D724: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8052D728: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052D72C: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8052D730: addiu       $a1, $zero, 0xF2C
    ctx->r5 = ADD32(0, 0XF2C);
    // 0x8052D734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8052D738: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8052D73C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8052D740: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8052D744: jal         0x80065728
    // 0x8052D748: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8052D748: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8052D74C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8052D750: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8052D754: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8052D758: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8052D75C: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8052D760: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8052D764: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    // 0x8052D768: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8052D76C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
L_8052D770:
    // 0x8052D770: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8052D774: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8052D778: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8052D77C: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x8052D780: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8052D784: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x8052D788: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8052D78C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8052D790: swc1        $f2, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8052D794: bne         $v1, $a0, L_8052D770
    if (ctx->r3 != ctx->r4) {
        // 0x8052D798: swc1        $f0, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = ctx->f0.u32l;
            goto L_8052D770;
    }
    // 0x8052D798: swc1        $f0, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8052D79C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8052D7A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052D7A4: addiu       $t7, $zero, 0x1D0
    ctx->r15 = ADD32(0, 0X1D0);
    // 0x8052D7A8: sw          $t7, 0xF00($a3)
    MEM_W(0XF00, ctx->r7) = ctx->r15;
    // 0x8052D7AC: sw          $zero, 0xF18($a3)
    MEM_W(0XF18, ctx->r7) = 0;
    // 0x8052D7B0: sw          $zero, 0xF20($a3)
    MEM_W(0XF20, ctx->r7) = 0;
    // 0x8052D7B4: swc1        $f8, 0xF14($a3)
    MEM_W(0XF14, ctx->r7) = ctx->f8.u32l;
    // 0x8052D7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052D7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8052D7C0: jr          $ra
    // 0x8052D7C4: nop

    return;
    // 0x8052D7C4: nop

;}
RECOMP_FUNC void func_80441A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441A38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80441A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441A40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441A44: jal         0x8004700C
    // 0x80441A48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80441A48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80441A4C: beq         $v0, $zero, L_80441AC4
    if (ctx->r2 == 0) {
        // 0x80441A50: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80441AC4;
    }
    // 0x80441A50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80441A54: jal         0x8043F33C
    // 0x80441A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F33C(rdram, ctx);
        goto after_1;
    // 0x80441A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80441A5C: jal         0x8043FDF0
    // 0x80441A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_2;
    // 0x80441A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80441A64: jal         0x8043F150
    // 0x80441A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_3;
    // 0x80441A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80441A6C: jal         0x8044045C
    // 0x80441A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_4;
    // 0x80441A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80441A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80441A78: jal         0x8043EF80
    // 0x80441A7C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    func_8043EF80(rdram, ctx);
        goto after_5;
    // 0x80441A7C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_5:
    // 0x80441A80: jal         0x8043F360
    // 0x80441A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_6;
    // 0x80441A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80441A88: beq         $v0, $zero, L_80441ABC
    if (ctx->r2 == 0) {
        // 0x80441A8C: nop
    
            goto L_80441ABC;
    }
    // 0x80441A8C: nop

    // 0x80441A90: jal         0x80440950
    // 0x80441A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_7;
    // 0x80441A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80441A98: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80441A9C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80441AA0: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80441AA4: beql        $t7, $at, L_80441AC8
    if (ctx->r15 == ctx->r1) {
        // 0x80441AA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80441AC8;
    }
    goto skip_0;
    // 0x80441AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80441AAC: jal         0x8043F93C
    // 0x80441AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_8;
    // 0x80441AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80441AB4: b           L_80441AC8
    // 0x80441AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441AC8;
    // 0x80441AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441ABC:
    // 0x80441ABC: jal         0x8043F93C
    // 0x80441AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_9;
    // 0x80441AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80441AC4:
    // 0x80441AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441AC8:
    // 0x80441AC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441ACC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80441AD0: jr          $ra
    // 0x80441AD4: nop

    return;
    // 0x80441AD4: nop

;}
RECOMP_FUNC void func_806EBDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EBDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EBDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EBDE8: jal         0x806EBD68
    // 0x806EBDEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806EBD68(rdram, ctx);
        goto after_0;
    // 0x806EBDEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EBDF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EBDF4: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(673, 0X4E0) << 16);
    // 0x806EBDF8: addiu       $t6, $t6, -0x41B0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(673, 0X4E0));
    // 0x806EBDFC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806EBE00: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(673, 0X450) << 16);
    // 0x806EBE04: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806EBE08: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806EBE0C: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x806EBE10: addiu       $t9, $t9, -0x4240
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(673, 0X450));
    // 0x806EBE14: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806EBE18: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x806EBE1C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x806EBE20: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806EBE24: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806EBE28: sw          $a0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r4;
    // 0x806EBE2C: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x806EBE30: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(673, 0X10) << 16);
    // 0x806EBE34: addiu       $t1, $t1, -0x4680
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(673, 0X10));
    // 0x806EBE38: sw          $t1, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r9;
    // 0x806EBE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EBE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EBE44: jr          $ra
    // 0x806EBE48: nop

    return;
    // 0x806EBE48: nop

    // 0x806EBE4C: nop

;}
RECOMP_FUNC void func_80446384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80446388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044638C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446390: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80446394: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446398: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044639C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x804463A0: sw          $a1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r5;
    // 0x804463A4: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x804463A8: sw          $t6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r14;
    // 0x804463AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804463B0: sw          $t7, 0x6CAC($at)
    MEM_W(0X6CAC, ctx->r1) = ctx->r15;
    // 0x804463B4: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131E4) << 16);
    // 0x804463B8: lw          $v1, 0x75C4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131E4));
    // 0x804463BC: beql        $v1, $zero, L_804463D0
    if (ctx->r3 == 0) {
        // 0x804463C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804463D0;
    }
    goto skip_0;
    // 0x804463C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804463C4: jalr        $v1
    // 0x804463C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804463C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x804463CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804463D0:
    // 0x804463D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804463D4: jr          $ra
    // 0x804463D8: nop

    return;
    // 0x804463D8: nop

;}
RECOMP_FUNC void func_80437960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437960: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80437964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437968: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8043796C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80437970: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437974: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80437978: lw          $v1, 0x180($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X180);
    // 0x8043797C: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x80437980: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80437984: bnel        $t7, $zero, L_804379C0
    if (ctx->r15 != 0) {
        // 0x80437988: addiu       $a1, $v0, 0x38
        ctx->r5 = ADD32(ctx->r2, 0X38);
            goto L_804379C0;
    }
    goto skip_0;
    // 0x80437988: addiu       $a1, $v0, 0x38
    ctx->r5 = ADD32(ctx->r2, 0X38);
    skip_0:
    // 0x8043798C: bne         $v1, $zero, L_80437A0C
    if (ctx->r3 != 0) {
        // 0x80437990: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80437A0C;
    }
    // 0x80437990: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80437994: jal         0x80437904
    // 0x80437998: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80437904(rdram, ctx);
        goto after_0;
    // 0x80437998: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8043799C: beq         $v0, $zero, L_80437A0C
    if (ctx->r2 == 0) {
        // 0x804379A0: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80437A0C;
    }
    // 0x804379A0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x804379A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x804379A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804379AC: jal         0x80437814
    // 0x804379B0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_80437814(rdram, ctx);
        goto after_1;
    // 0x804379B0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x804379B4: b           L_80437A10
    // 0x804379B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80437A10;
    // 0x804379B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804379BC: addiu       $a1, $v0, 0x38
    ctx->r5 = ADD32(ctx->r2, 0X38);
L_804379C0:
    // 0x804379C0: jal         0x80065490
    // 0x804379C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x804379C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x804379C8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x804379CC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804379D0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804379D4: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x804379D8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804379DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x804379E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x804379E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804379E8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804379EC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x804379F0: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804379F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804379F8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x804379FC: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80437A00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80437A04: jal         0x8043773C
    // 0x80437A08: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_8043773C(rdram, ctx);
        goto after_3;
    // 0x80437A08: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_3:
L_80437A0C:
    // 0x80437A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80437A10:
    // 0x80437A10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80437A14: jr          $ra
    // 0x80437A18: nop

    return;
    // 0x80437A18: nop

;}
RECOMP_FUNC void func_806F9CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9CC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F9CCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F9CD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F9CD4: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x806F9CD8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806F9CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F9CE0: bnel        $t6, $at, L_806F9D0C
    if (ctx->r14 != ctx->r1) {
        // 0x806F9CE4: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_806F9D0C;
    }
    goto skip_0;
    // 0x806F9CE4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x806F9CE8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x806F9CEC: jal         0x80067BBC
    // 0x806F9CF0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806F9CF0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x806F9CF4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x806F9CF8: jal         0x80067F78
    // 0x806F9CFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806F9CFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806F9D00: b           L_806F9D24
    // 0x806F9D04: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_806F9D24;
    // 0x806F9D04: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x806F9D08: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_806F9D0C:
    // 0x806F9D0C: jal         0x80067BBC
    // 0x806F9D10: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806F9D10: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x806F9D14: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x806F9D18: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806F9D1C: jal         0x800678F0
    // 0x806F9D20: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x806F9D20: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_806F9D24:
    // 0x806F9D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F9D28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F9D2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F9D30: jr          $ra
    // 0x806F9D34: nop

    return;
    // 0x806F9D34: nop

;}
RECOMP_FUNC void func_8046C50C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C50C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046C510: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046C514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046C518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046C51C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8046C520: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8046C524: jal         0x80062AEC
    // 0x8046C528: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8046C528: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8046C52C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8046C530: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046C534: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8046C538: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x8046C53C: beq         $a0, $zero, L_8046C54C
    if (ctx->r4 == 0) {
        // 0x8046C540: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_8046C54C;
    }
    // 0x8046C540: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8046C544: b           L_8046C5FC
    // 0x8046C548: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
        goto L_8046C5FC;
    // 0x8046C548: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
L_8046C54C:
    // 0x8046C54C: lhu         $a0, 0xC($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0XC);
    // 0x8046C550: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8046C554: bne         $a0, $at, L_8046C5E4
    if (ctx->r4 != ctx->r1) {
        // 0x8046C558: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8046C5E4;
    }
    // 0x8046C558: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8046C55C: beq         $v0, $at, L_8046C5D8
    if (ctx->r2 == ctx->r1) {
        // 0x8046C560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8046C5D8;
    }
    // 0x8046C560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046C564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046C568: jal         0x8046D3E8
    // 0x8046C56C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_8046D3E8(rdram, ctx);
        goto after_1;
    // 0x8046C56C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x8046C570: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8046C574: jal         0x8002FABC
    // 0x8046C578: lui         $a1, 0xC020
    ctx->r5 = S32(0XC020 << 16);
    func_8002FABC(rdram, ctx);
        goto after_2;
    // 0x8046C578: lui         $a1, 0xC020
    ctx->r5 = S32(0XC020 << 16);
    after_2:
    // 0x8046C57C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8046C580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8046C584: beq         $t8, $at, L_8046C5A0
    if (ctx->r24 == ctx->r1) {
        // 0x8046C588: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8046C5A0;
    }
    // 0x8046C588: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8046C58C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8046C590: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X1590) << 16);
    // 0x8046C594: lwc1        $f4, -0x2620($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X1590));
    // 0x8046C598: b           L_8046C5B4
    // 0x8046C59C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
        goto L_8046C5B4;
    // 0x8046C59C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
L_8046C5A0:
    // 0x8046C5A0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8046C5A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8046C5A8: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X1594) << 16);
    // 0x8046C5AC: lwc1        $f6, -0x261C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X1594));
    // 0x8046C5B0: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_8046C5B4:
    // 0x8046C5B4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8046C5B8: swc1        $f0, 0xC4($t9)
    MEM_W(0XC4, ctx->r25) = ctx->f0.u32l;
    // 0x8046C5BC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8046C5C0: jal         0x80067BBC
    // 0x8046C5C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8046C5C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x8046C5C8: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8046C5CC: jal         0x80067818
    // 0x8046C5D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8046C5D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8046C5D4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_8046C5D8:
    // 0x8046C5D8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8046C5DC: b           L_8046C5FC
    // 0x8046C5E0: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
        goto L_8046C5FC;
    // 0x8046C5E0: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
L_8046C5E4:
    // 0x8046C5E4: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8046C5E8: bne         $a0, $at, L_8046C5FC
    if (ctx->r4 != ctx->r1) {
        // 0x8046C5EC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8046C5FC;
    }
    // 0x8046C5EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8046C5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046C5F4: jal         0x8046D3E8
    // 0x8046C5F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8046D3E8(rdram, ctx);
        goto after_5;
    // 0x8046C5F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_8046C5FC:
    // 0x8046C5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046C600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046C604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046C608: jr          $ra
    // 0x8046C60C: nop

    return;
    // 0x8046C60C: nop

;}
RECOMP_FUNC void func_8046AA48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AA48: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046AA4C: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x8046AA50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8046AA54: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046AA58: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8046AA5C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8046AA60: nop

    // 0x8046AA64: bc1f        L_8046AAA8
    if (!c1cs) {
        // 0x8046AA68: nop
    
            goto L_8046AAA8;
    }
    // 0x8046AA68: nop

    // 0x8046AA6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8046AA70: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8046AA74: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8046AA78: nop

    // 0x8046AA7C: bc1f        L_8046AAA8
    if (!c1cs) {
        // 0x8046AA80: nop
    
            goto L_8046AAA8;
    }
    // 0x8046AA80: nop

    // 0x8046AA84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046AA88: nop

    // 0x8046AA8C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8046AA90: nop

    // 0x8046AA94: bc1fl       L_8046AAA8
    if (!c1cs) {
        // 0x8046AA98: swc1        $f12, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
            goto L_8046AAA8;
    }
    goto skip_0;
    // 0x8046AA98: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    skip_0:
    // 0x8046AA9C: jr          $ra
    // 0x8046AAA0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    return;
    // 0x8046AAA0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8046AAA4: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_8046AAA8:
    // 0x8046AAA8: jr          $ra
    // 0x8046AAAC: nop

    return;
    // 0x8046AAAC: nop

;}
RECOMP_FUNC void func_80676250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676250: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80676254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80676258: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067625C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676260: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80676264: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80676268: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x8067626C: blez        $v1, L_806762A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80676270: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_806762A4;
    }
    // 0x80676270: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80676274: jal         0x80675EF0
    // 0x80676278: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    func_80675EF0(rdram, ctx);
        goto after_0;
    // 0x80676278: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    after_0:
    // 0x8067627C: beq         $v0, $zero, L_806762E4
    if (ctx->r2 == 0) {
        // 0x80676280: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806762E4;
    }
    // 0x80676280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80676284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80676288: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8067628C: jal         0x80677A88
    // 0x80676290: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_1;
    // 0x80676290: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80676294: jal         0x80675B9C
    // 0x80676298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675B9C(rdram, ctx);
        goto after_2;
    // 0x80676298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8067629C: b           L_806762E4
    // 0x806762A0: nop

        goto L_806762E4;
    // 0x806762A0: nop

L_806762A4:
    // 0x806762A4: jal         0x800653D8
    // 0x806762A8: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x806762A8: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    after_3:
    // 0x806762AC: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x806762B0: beq         $t8, $zero, L_806762D4
    if (ctx->r24 == 0) {
        // 0x806762B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806762D4;
    }
    // 0x806762B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806762B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806762BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806762C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806762C4: jal         0x80677A88
    // 0x806762C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_4;
    // 0x806762C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x806762CC: b           L_806762E4
    // 0x806762D0: nop

        goto L_806762E4;
    // 0x806762D0: nop

L_806762D4:
    // 0x806762D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806762D8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806762DC: jal         0x80677A88
    // 0x806762E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_5;
    // 0x806762E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
L_806762E4:
    // 0x806762E4: jal         0x80675CD0
    // 0x806762E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675CD0(rdram, ctx);
        goto after_6;
    // 0x806762E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806762EC: bnel        $v0, $zero, L_80676300
    if (ctx->r2 != 0) {
        // 0x806762F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80676300;
    }
    goto skip_0;
    // 0x806762F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806762F4: jal         0x80675D48
    // 0x806762F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675D48(rdram, ctx);
        goto after_7;
    // 0x806762F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806762FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80676300:
    // 0x80676300: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80676304: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80676308: jr          $ra
    // 0x8067630C: nop

    return;
    // 0x8067630C: nop

;}
RECOMP_FUNC void func_8006F36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F36C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006F378: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x8006F37C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F380: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006F384: beq         $t7, $zero, L_8006F39C
    if (ctx->r15 == 0) {
        // 0x8006F388: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8006F39C;
    }
    // 0x8006F388: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F38C: jal         0x8006F49C
    // 0x8006F390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006F49C(rdram, ctx);
        goto after_0;
    // 0x8006F390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8006F394: b           L_8006F3B0
    // 0x8006F398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006F3B0;
    // 0x8006F398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F39C:
    // 0x8006F39C: jal         0x80053690
    // 0x8006F3A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80053690(rdram, ctx);
        goto after_1;
    // 0x8006F3A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8006F3A4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006F3A8: sw          $v0, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = ctx->r2;
    // 0x8006F3AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F3B0:
    // 0x8006F3B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F3B4: jr          $ra
    // 0x8006F3B8: nop

    return;
    // 0x8006F3B8: nop

;}
RECOMP_FUNC void func_805272E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805272E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805272E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805272EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805272F0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x805272F4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805272F8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805272FC: jal         0x80067BBC
    // 0x80527300: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80527300: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80527304: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    // 0x80527308: jal         0x80067818
    // 0x8052730C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8052730C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80527310: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80527314: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6170) << 16);
    // 0x80527318: lwc1        $f4, -0x3F90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6170));
    // 0x8052731C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80527320: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80527324: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(327, 0X4BFC) << 16);
    // 0x80527328: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(327, 0X4C50) << 16);
    // 0x8052732C: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(327, 0X1470) << 16);
    // 0x80527330: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80527334: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80527338: addiu       $t8, $t8, -0x5504
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(327, 0X4BFC));
    // 0x8052733C: addiu       $t9, $t9, -0x54B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(327, 0X4C50));
    // 0x80527340: addiu       $t0, $t0, 0x7370
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(327, 0X1470));
    // 0x80527344: sw          $t6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r14;
    // 0x80527348: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x8052734C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80527350: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80527354: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x80527358: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x8052735C: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80527360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527368: jr          $ra
    // 0x8052736C: nop

    return;
    // 0x8052736C: nop

;}
RECOMP_FUNC void func_8005E2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E2E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005E2EC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8005E2F0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005E2F4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8005E2F8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8005E2FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005E300: lw          $t7, 0x63D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63D0);
    // 0x8005E304: jr          $ra
    // 0x8005E308: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    return;
    // 0x8005E308: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8041FE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FE10: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8041FE14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8041FE18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8041FE1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8041FE20: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8041FE24: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8041FE28: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8041FE2C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8041FE30: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8041FE34: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8041FE38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8041FE3C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8041FE40: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(29, 0X3324) << 16);
    // 0x8041FE44: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8041FE48: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8041FE4C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8041FE50: lw          $t1, 0x984($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(29, 0X3324));
    // 0x8041FE54: jr          $ra
    // 0x8041FE58: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8041FE58: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805A37D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A37D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A37D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A37D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A37DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A37E0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805A37E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805A37E8: jal         0x805A33FC
    // 0x805A37EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_805A33FC(rdram, ctx);
        goto after_0;
    // 0x805A37EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805A37F0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805A37F4: jal         0x805A34F8
    // 0x805A37F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805A34F8(rdram, ctx);
        goto after_1;
    // 0x805A37F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805A37FC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x805A3800: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805A3804: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805A3808: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x805A380C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805A3810: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x805A3814: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x805A3818: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x805A381C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x805A3820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A3824: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A3828: jr          $ra
    // 0x805A382C: nop

    return;
    // 0x805A382C: nop

;}
RECOMP_FUNC void func_8044797C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044797C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80447980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80447984: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80447988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044798C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80447990: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80447994: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80447998: addiu       $t9, $zero, 0x1B6C
    ctx->r25 = ADD32(0, 0X1B6C);
    // 0x8044799C: subu        $t0, $t9, $a3
    ctx->r8 = SUB32(ctx->r25, ctx->r7);
    // 0x804479A0: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x804479A4: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804479A8: slti        $at, $t7, 0x3C0
    ctx->r1 = SIGNED(ctx->r15) < 0X3C0 ? 1 : 0;
    // 0x804479AC: beq         $at, $zero, L_804479B8
    if (ctx->r1 == 0) {
        // 0x804479B0: sw          $t7, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r15;
            goto L_804479B8;
    }
    // 0x804479B0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x804479B4: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
L_804479B8:
    // 0x804479B8: jal         0x804475C0
    // 0x804479BC: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_804475C0(rdram, ctx);
        goto after_0;
    // 0x804479BC: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_0:
    // 0x804479C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804479C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804479C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804479CC: jr          $ra
    // 0x804479D0: nop

    return;
    // 0x804479D0: nop

;}
RECOMP_FUNC void func_8079EB20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EB20: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8079EB24: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8079EB28: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8079EB2C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8079EB30: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8079EB34: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8079EB38: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8079EB3C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8079EB40: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x8079EB44: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8079EB48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8079EB4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8079EB50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079EB54: addiu       $s6, $s6, 0x7EA0
    ctx->r22 = ADD32(ctx->r22, 0X7EA0);
    // 0x8079EB58: addiu       $s2, $zero, 0x28
    ctx->r18 = ADD32(0, 0X28);
    // 0x8079EB5C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8079EB60: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8079EB64: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8079EB68: addiu       $s7, $sp, 0x5C
    ctx->r23 = ADD32(ctx->r29, 0X5C);
L_8079EB6C:
    // 0x8079EB6C: lw          $t6, 0xEC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XEC);
    // 0x8079EB70: sll         $t7, $fp, 2
    ctx->r15 = S32(ctx->r30 << 2);
    // 0x8079EB74: addu        $t7, $t7, $fp
    ctx->r15 = ADD32(ctx->r15, ctx->r30);
    // 0x8079EB78: beq         $t6, $zero, L_8079EBC8
    if (ctx->r14 == 0) {
        // 0x8079EB7C: sll         $t7, $t7, 3
        ctx->r15 = S32(ctx->r15 << 3);
            goto L_8079EBC8;
    }
    // 0x8079EB7C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8079EB80: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8079EB84: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8079EB88: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8079EB8C: lhu         $a1, 0xFE8($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0XFE8);
    // 0x8079EB90: jal         0x8079EA14
    // 0x8079EB94: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8079EA14(rdram, ctx);
        goto after_0;
    // 0x8079EB94: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x8079EB98: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8079EB9C: sh          $t1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r9;
    // 0x8079EBA0: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x8079EBA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8079EBA8:
    // 0x8079EBA8: lw          $a0, 0xEC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XEC);
    // 0x8079EBAC: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x8079EBB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8079EBB4: jal         0x8005C27C
    // 0x8079EBB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8079EBB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8079EBBC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8079EBC0: bne         $s0, $s2, L_8079EBA8
    if (ctx->r16 != ctx->r18) {
        // 0x8079EBC4: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8079EBA8;
    }
    // 0x8079EBC4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_8079EBC8:
    // 0x8079EBC8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8079EBCC: bne         $s4, $s5, L_8079EB6C
    if (ctx->r20 != ctx->r21) {
        // 0x8079EBD0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8079EB6C;
    }
    // 0x8079EBD0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8079EBD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8079EBD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079EBDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8079EBE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8079EBE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8079EBE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8079EBEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8079EBF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8079EBF4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8079EBF8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8079EBFC: jr          $ra
    // 0x8079EC00: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8079EC00: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_805D3358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D335C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3360: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805D3364: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805D3368: jal         0x805D32C8
    // 0x805D336C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D32C8(rdram, ctx);
        goto after_0;
    // 0x805D336C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D3370: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805D3378: jal         0x80045A34
    // 0x805D337C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805D337C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_1:
    // 0x805D3380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3384: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805D3388: beq         $v0, $zero, L_805D339C
    if (ctx->r2 == 0) {
        // 0x805D338C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805D339C;
    }
    // 0x805D338C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805D3390: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D3394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805D3398: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
L_805D339C:
    // 0x805D339C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D33A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D33A4: jr          $ra
    // 0x805D33A8: nop

    return;
    // 0x805D33A8: nop

;}
RECOMP_FUNC void func_8078DDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DDC0: jr          $ra
    // 0x8078DDC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8078DDC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807B29A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B29A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B29AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B29B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B29B4: jal         0x807B0E30
    // 0x807B29B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807B0E30(rdram, ctx);
        goto after_0;
    // 0x807B29B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807B29BC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x807B29C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B29C4: jal         0x80048F84
    // 0x807B29C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x807B29C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807B29CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B29D0: jal         0x80048F84
    // 0x807B29D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x807B29D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x807B29D8: jal         0x807B26B8
    // 0x807B29DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B26B8(rdram, ctx);
        goto after_3;
    // 0x807B29DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807B29E0: jal         0x807B20D8
    // 0x807B29E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B20D8(rdram, ctx);
        goto after_4;
    // 0x807B29E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807B29E8: jal         0x8004700C
    // 0x807B29EC: nop

    func_8004700C(rdram, ctx);
        goto after_5;
    // 0x807B29EC: nop

    after_5:
    // 0x807B29F0: beq         $v0, $zero, L_807B2A00
    if (ctx->r2 == 0) {
        // 0x807B29F4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807B2A00;
    }
    // 0x807B29F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807B29F8: jal         0x807B21D8
    // 0x807B29FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B21D8(rdram, ctx);
        goto after_6;
    // 0x807B29FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_807B2A00:
    // 0x807B2A00: jal         0x807B1F88
    // 0x807B2A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B1F88(rdram, ctx);
        goto after_7;
    // 0x807B2A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x807B2A08: jal         0x807B101C
    // 0x807B2A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B101C(rdram, ctx);
        goto after_8;
    // 0x807B2A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x807B2A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B2A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B2A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B2A1C: jr          $ra
    // 0x807B2A20: nop

    return;
    // 0x807B2A20: nop

;}
RECOMP_FUNC void func_804A49CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A49CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A49D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A49D4: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804A49D8: beql        $t6, $zero, L_804A4A14
    if (ctx->r14 == 0) {
        // 0x804A49DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A4A14;
    }
    goto skip_0;
    // 0x804A49DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A49E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A49E4: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804A49E8: jalr        $t9
    // 0x804A49EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804A49EC: nop

    after_0:
    // 0x804A49F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A49F4: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804A49F8: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804A49FC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804A4A00: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804A4A04: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804A4A08: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804A4A0C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x804A4A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A4A14:
    // 0x804A4A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A4A18: jr          $ra
    // 0x804A4A1C: nop

    return;
    // 0x804A4A1C: nop

;}
RECOMP_FUNC void func_80579F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579F18: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x80579F1C: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x80579F20: addiu       $t4, $t4, 0x7EA0
    ctx->r12 = ADD32(ctx->r12, 0X7EA0);
    // 0x80579F24: lbu         $t2, 0x34($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X34);
    // 0x80579F28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80579F2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80579F30: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80579F34: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80579F38: lw          $t6, 0x478($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X478);
    // 0x80579F3C: xori        $t8, $t2, 0x1
    ctx->r24 = ctx->r10 ^ 0X1;
    // 0x80579F40: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80579F44: lwc1        $f6, 0x30($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X30);
    // 0x80579F48: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x80579F4C: lw          $t0, 0x38($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X38);
    // 0x80579F50: lw          $t3, 0x38($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X38);
    // 0x80579F54: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80579F58: lw          $t7, 0x478($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X478);
    // 0x80579F5C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80579F60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80579F64: lwc1        $f8, 0x34($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X34);
    // 0x80579F68: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80579F6C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80579F70: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x80579F74: lw          $t8, 0x478($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X478);
    // 0x80579F78: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80579F7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80579F80: lwc1        $f10, 0x38($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80579F84: addiu       $a2, $a2, 0xC8
    ctx->r6 = ADD32(ctx->r6, 0XC8);
    // 0x80579F88: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80579F8C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80579F90: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80579F94: addiu       $t0, $t0, 0x60
    ctx->r8 = ADD32(ctx->r8, 0X60);
    // 0x80579F98: addiu       $t3, $t3, 0x60
    ctx->r11 = ADD32(ctx->r11, 0X60);
    // 0x80579F9C: swc1        $f18, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f18.u32l;
    // 0x80579FA0: lbu         $t9, 0x24($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X24);
    // 0x80579FA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80579FA8: andi        $t5, $t9, 0xFF0F
    ctx->r13 = ctx->r25 & 0XFF0F;
    // 0x80579FAC: sb          $t5, 0x24($t1)
    MEM_B(0X24, ctx->r9) = ctx->r13;
    // 0x80579FB0: lwc1        $f4, -0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80579FB4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80579FB8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80579FBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80579FC0: nop

    // 0x80579FC4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80579FC8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80579FCC: sh          $a1, -0x48($t0)
    MEM_H(-0X48, ctx->r8) = ctx->r5;
    // 0x80579FD0: sh          $a1, -0x48($t3)
    MEM_H(-0X48, ctx->r11) = ctx->r5;
    // 0x80579FD4: lwc1        $f10, -0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X8);
    // 0x80579FD8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80579FDC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80579FE0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80579FE4: nop

    // 0x80579FE8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80579FEC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80579FF0: sh          $a1, -0x40($t0)
    MEM_H(-0X40, ctx->r8) = ctx->r5;
    // 0x80579FF4: sh          $a1, -0x40($t3)
    MEM_H(-0X40, ctx->r11) = ctx->r5;
    // 0x80579FF8: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80579FFC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8057A000: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8057A004: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8057A008: nop

    // 0x8057A00C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A010: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A014: sh          $a1, -0x18($t0)
    MEM_H(-0X18, ctx->r8) = ctx->r5;
    // 0x8057A018: sh          $a1, -0x18($t3)
    MEM_H(-0X18, ctx->r11) = ctx->r5;
    // 0x8057A01C: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8057A020: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8057A024: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A028: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8057A02C: nop

    // 0x8057A030: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A034: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A038: sh          $a1, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r5;
    // 0x8057A03C: sh          $a1, -0x10($t3)
    MEM_H(-0X10, ctx->r11) = ctx->r5;
    // 0x8057A040: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057A044: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057A048: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A04C: beql        $a0, $v1, L_8057A190
    if (ctx->r4 == ctx->r3) {
        // 0x8057A050: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_8057A190;
    }
    goto skip_0;
    // 0x8057A050: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_0:
    // 0x8057A054: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_8057A058:
    // 0x8057A058: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057A05C: addiu       $t0, $t0, 0xC0
    ctx->r8 = ADD32(ctx->r8, 0XC0);
    // 0x8057A060: addiu       $t3, $t3, 0xC0
    ctx->r11 = ADD32(ctx->r11, 0XC0);
    // 0x8057A064: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A068: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8057A06C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8057A070: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A074: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A078: sh          $a1, -0xA8($t0)
    MEM_H(-0XA8, ctx->r8) = ctx->r5;
    // 0x8057A07C: sh          $a1, -0xA8($t3)
    MEM_H(-0XA8, ctx->r11) = ctx->r5;
    // 0x8057A080: lwc1        $f16, -0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X10);
    // 0x8057A084: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A088: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A08C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A090: nop

    // 0x8057A094: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A098: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A09C: sh          $a1, -0xA0($t0)
    MEM_H(-0XA0, ctx->r8) = ctx->r5;
    // 0x8057A0A0: sh          $a1, -0xA0($t3)
    MEM_H(-0XA0, ctx->r11) = ctx->r5;
    // 0x8057A0A4: lwc1        $f16, -0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8057A0A8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A0AC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A0B0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A0B4: nop

    // 0x8057A0B8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A0BC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A0C0: sh          $a1, -0x78($t0)
    MEM_H(-0X78, ctx->r8) = ctx->r5;
    // 0x8057A0C4: sh          $a1, -0x78($t3)
    MEM_H(-0X78, ctx->r11) = ctx->r5;
    // 0x8057A0C8: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x8057A0CC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A0D0: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A0D4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A0D8: nop

    // 0x8057A0DC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A0E0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A0E4: sh          $a1, -0x70($t0)
    MEM_H(-0X70, ctx->r8) = ctx->r5;
    // 0x8057A0E8: sh          $a1, -0x70($t3)
    MEM_H(-0X70, ctx->r11) = ctx->r5;
    // 0x8057A0EC: lwc1        $f16, -0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8057A0F0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A0F4: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A0F8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A0FC: nop

    // 0x8057A100: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A104: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A108: sh          $a1, -0x48($t0)
    MEM_H(-0X48, ctx->r8) = ctx->r5;
    // 0x8057A10C: sh          $a1, -0x48($t3)
    MEM_H(-0X48, ctx->r11) = ctx->r5;
    // 0x8057A110: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8057A114: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A118: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A11C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A120: nop

    // 0x8057A124: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A128: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A12C: sh          $a1, -0x40($t0)
    MEM_H(-0X40, ctx->r8) = ctx->r5;
    // 0x8057A130: sh          $a1, -0x40($t3)
    MEM_H(-0X40, ctx->r11) = ctx->r5;
    // 0x8057A134: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8057A138: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A13C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A140: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A144: nop

    // 0x8057A148: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A14C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A150: sh          $a1, -0x18($t0)
    MEM_H(-0X18, ctx->r8) = ctx->r5;
    // 0x8057A154: sh          $a1, -0x18($t3)
    MEM_H(-0X18, ctx->r11) = ctx->r5;
    // 0x8057A158: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8057A15C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A160: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A164: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A168: nop

    // 0x8057A16C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A170: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A174: sh          $a1, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r5;
    // 0x8057A178: sh          $a1, -0x10($t3)
    MEM_H(-0X10, ctx->r11) = ctx->r5;
    // 0x8057A17C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057A180: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A184: bnel        $a0, $v1, L_8057A058
    if (ctx->r4 != ctx->r3) {
        // 0x8057A188: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_8057A058;
    }
    goto skip_1;
    // 0x8057A188: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_1:
    // 0x8057A18C: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_8057A190:
    // 0x8057A190: addiu       $t0, $t0, 0xC0
    ctx->r8 = ADD32(ctx->r8, 0XC0);
    // 0x8057A194: addiu       $t3, $t3, 0xC0
    ctx->r11 = ADD32(ctx->r11, 0XC0);
    // 0x8057A198: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8057A19C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A1A0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8057A1A4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A1A8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A1AC: sh          $a1, -0xA8($t0)
    MEM_H(-0XA8, ctx->r8) = ctx->r5;
    // 0x8057A1B0: sh          $a1, -0xA8($t3)
    MEM_H(-0XA8, ctx->r11) = ctx->r5;
    // 0x8057A1B4: lwc1        $f16, -0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X10);
    // 0x8057A1B8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A1BC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A1C0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A1C4: nop

    // 0x8057A1C8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A1CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A1D0: sh          $a1, -0xA0($t0)
    MEM_H(-0XA0, ctx->r8) = ctx->r5;
    // 0x8057A1D4: sh          $a1, -0xA0($t3)
    MEM_H(-0XA0, ctx->r11) = ctx->r5;
    // 0x8057A1D8: lwc1        $f16, -0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8057A1DC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A1E0: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A1E4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A1E8: nop

    // 0x8057A1EC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A1F0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A1F4: sh          $a1, -0x78($t0)
    MEM_H(-0X78, ctx->r8) = ctx->r5;
    // 0x8057A1F8: sh          $a1, -0x78($t3)
    MEM_H(-0X78, ctx->r11) = ctx->r5;
    // 0x8057A1FC: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x8057A200: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A204: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A208: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A20C: nop

    // 0x8057A210: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A214: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A218: sh          $a1, -0x70($t0)
    MEM_H(-0X70, ctx->r8) = ctx->r5;
    // 0x8057A21C: sh          $a1, -0x70($t3)
    MEM_H(-0X70, ctx->r11) = ctx->r5;
    // 0x8057A220: lwc1        $f16, -0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X8);
    // 0x8057A224: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A228: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A22C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A230: nop

    // 0x8057A234: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A238: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A23C: sh          $a1, -0x48($t0)
    MEM_H(-0X48, ctx->r8) = ctx->r5;
    // 0x8057A240: sh          $a1, -0x48($t3)
    MEM_H(-0X48, ctx->r11) = ctx->r5;
    // 0x8057A244: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8057A248: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A24C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A250: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A254: nop

    // 0x8057A258: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A25C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A260: sh          $a1, -0x40($t0)
    MEM_H(-0X40, ctx->r8) = ctx->r5;
    // 0x8057A264: sh          $a1, -0x40($t3)
    MEM_H(-0X40, ctx->r11) = ctx->r5;
    // 0x8057A268: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8057A26C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A270: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A274: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A278: nop

    // 0x8057A27C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A280: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A284: sh          $a1, -0x18($t0)
    MEM_H(-0X18, ctx->r8) = ctx->r5;
    // 0x8057A288: sh          $a1, -0x18($t3)
    MEM_H(-0X18, ctx->r11) = ctx->r5;
    // 0x8057A28C: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8057A290: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057A294: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8057A298: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8057A29C: nop

    // 0x8057A2A0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057A2A4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057A2A8: sh          $a1, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r5;
    // 0x8057A2AC: sh          $a1, -0x10($t3)
    MEM_H(-0X10, ctx->r11) = ctx->r5;
    // 0x8057A2B0: jr          $ra
    // 0x8057A2B4: nop

    return;
    // 0x8057A2B4: nop

;}
RECOMP_FUNC void func_80019EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019EF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019EF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019EFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80019F00: jal         0x80019AC4
    // 0x80019F04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x80019F04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80019F08: beq         $v0, $zero, L_80019F7C
    if (ctx->r2 == 0) {
        // 0x80019F0C: lh          $t6, 0x1A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X1A);
            goto L_80019F7C;
    }
    // 0x80019F0C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80019F10: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x80019F14: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x80019F18: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80019F1C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80019F20: sh          $t7, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r15;
    // 0x80019F24: lh          $t8, 0x22($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X22);
    // 0x80019F28: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
    // 0x80019F2C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80019F30: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80019F34: nop

    // 0x80019F38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019F3C: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x80019F40: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x80019F44: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80019F48: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x80019F4C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80019F50: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80019F54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019F58: beq         $v1, $zero, L_80019F7C
    if (ctx->r3 == 0) {
        // 0x80019F5C: swc1        $f10, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
            goto L_80019F7C;
    }
    // 0x80019F5C: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x80019F60: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80019F64: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80019F68: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80019F6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80019F70: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80019F74: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80019F78: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
L_80019F7C:
    // 0x80019F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019F84: jr          $ra
    // 0x80019F88: nop

    return;
    // 0x80019F88: nop

    // 0x80019F8C: nop

;}
RECOMP_FUNC void func_8003A7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A7B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003A7B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A7B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003A7BC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8003A7C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003A7C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003A7C8: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8003A7CC: bne         $at, $zero, L_8003A840
    if (ctx->r1 != 0) {
        // 0x8003A7D0: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8003A840;
    }
    // 0x8003A7D0: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8003A7D4: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003A7D8: lwc1        $f14, 0x88($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8003A7DC: lw          $a2, 0x8C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8C);
    // 0x8003A7E0: jal         0x8003BC64
    // 0x8003A7E4: lw          $a3, 0x1EC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1EC);
    func_8003BC64(rdram, ctx);
        goto after_0;
    // 0x8003A7E4: lw          $a3, 0x1EC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1EC);
    after_0:
    // 0x8003A7E8: beq         $v0, $zero, L_8003A840
    if (ctx->r2 == 0) {
        // 0x8003A7EC: addiu       $a0, $v0, 0x6C
        ctx->r4 = ADD32(ctx->r2, 0X6C);
            goto L_8003A840;
    }
    // 0x8003A7EC: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
    // 0x8003A7F0: lw          $t9, 0x16C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X16C);
    // 0x8003A7F4: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x8003A7F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003A7FC: addiu       $t0, $t9, 0xD
    ctx->r8 = ADD32(ctx->r25, 0XD);
    // 0x8003A800: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8003A804: jal         0x80065490
    // 0x8003A808: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8003A808: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003A80C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A810: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003A814: jal         0x80065490
    // 0x8003A818: addiu       $a0, $a2, 0x78
    ctx->r4 = ADD32(ctx->r6, 0X78);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003A818: addiu       $a0, $a2, 0x78
    ctx->r4 = ADD32(ctx->r6, 0X78);
    after_2:
    // 0x8003A81C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003A820: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8003A824: addiu       $t1, $t1, -0x4DE8
    ctx->r9 = ADD32(ctx->r9, -0X4DE8);
    // 0x8003A828: jal         0x80044194
    // 0x8003A82C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x8003A82C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_3:
    // 0x8003A830: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8003A834: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8003A838: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8003A83C: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
L_8003A840:
    // 0x8003A840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003A844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003A848: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003A84C: jr          $ra
    // 0x8003A850: nop

    return;
    // 0x8003A850: nop

;}
RECOMP_FUNC void func_80428008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042800C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80428010: jal         0x8004700C
    // 0x80428014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80428014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80428018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042801C: beq         $v0, $zero, L_80428030
    if (ctx->r2 == 0) {
        // 0x80428020: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80428030;
    }
    // 0x80428020: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80428024: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80428028: nop

    // 0x8042802C: swc1        $f0, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f0.u32l;
L_80428030:
    // 0x80428030: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80428034: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80428038: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8042803C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x80428040: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80428044: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80428048: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x8042804C: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x80428050: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x80428054: jal         0x80427C2C
    // 0x80428058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80427C2C(rdram, ctx);
        goto after_1;
    // 0x80428058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8042805C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80428060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80428064: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80428068: jal         0x804288A0
    // 0x8042806C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804288A0(rdram, ctx);
        goto after_2;
    // 0x8042806C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80428070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80428074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80428078: jr          $ra
    // 0x8042807C: nop

    return;
    // 0x8042807C: nop

;}
RECOMP_FUNC void func_805CAD08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CAD08: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X938) << 16);
    // 0x805CAD0C: lwc1        $f0, -0x4E78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X938));
    // 0x805CAD10: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x805CAD14: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(453, 0X7D8) << 16);
    // 0x805CAD18: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x805CAD1C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x805CAD20: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x805CAD24: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805CAD28: lw          $t6, -0x4FD8($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(453, 0X7D8));
    // 0x805CAD2C: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(453, 0X810) << 16);
    // 0x805CAD30: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x805CAD34: sw          $t6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r14;
    // 0x805CAD38: lw          $t7, -0x4FA0($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(453, 0X810));
    // 0x805CAD3C: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(453, 0X848) << 16);
    // 0x805CAD40: addiu       $t8, $t8, -0x4F68
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(453, 0X848));
    // 0x805CAD44: addu        $a2, $v1, $t8
    ctx->r6 = ADD32(ctx->r3, ctx->r24);
    // 0x805CAD48: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    // 0x805CAD4C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x805CAD50: lui         $t0, 0x805D
    ctx->r8 = S32(RELOC_HI16(453, 0X880) << 16);
    // 0x805CAD54: addiu       $t0, $t0, -0x4F30
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(453, 0X880));
    // 0x805CAD58: addu        $a3, $v1, $t0
    ctx->r7 = ADD32(ctx->r3, ctx->r8);
    // 0x805CAD5C: sw          $t9, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r25;
    // 0x805CAD60: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x805CAD64: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X8B8) << 16);
    // 0x805CAD68: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805CAD6C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x805CAD70: lwc1        $f4, -0x4EF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X8B8));
    // 0x805CAD74: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X8F0) << 16);
    // 0x805CAD78: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805CAD7C: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x805CAD80: lwc1        $f6, -0x4EC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X8F0));
    // 0x805CAD84: swc1        $f6, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f6.u32l;
    // 0x805CAD88: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x805CAD8C: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x805CAD90: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x805CAD94: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805CAD98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x805CAD9C: jr          $ra
    // 0x805CADA0: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
    return;
    // 0x805CADA0: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
;}
RECOMP_FUNC void func_80050F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050F2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050F30: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80050F34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80050F38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050F3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050F40: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80050F44: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80050F48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80050F4C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80050F50: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80050F54: beq         $a1, $zero, L_80050FA8
    if (ctx->r5 == 0) {
        // 0x80050F58: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80050FA8;
    }
    // 0x80050F58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80050F5C: addiu       $s4, $zero, 0xA5
    ctx->r20 = ADD32(0, 0XA5);
    // 0x80050F60: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80050F64:
    // 0x80050F64: bnel        $t6, $zero, L_80050F98
    if (ctx->r14 != 0) {
        // 0x80050F68: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80050F98;
    }
    goto skip_0;
    // 0x80050F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80050F6C: jal         0x80050EE0
    // 0x80050F70: nop

    func_80050EE0(rdram, ctx);
        goto after_0;
    // 0x80050F70: nop

    after_0:
    // 0x80050F74: bne         $v0, $zero, L_80050F84
    if (ctx->r2 != 0) {
        // 0x80050F78: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80050F84;
    }
    // 0x80050F78: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80050F7C: b           L_80050FAC
    // 0x80050F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050FAC;
    // 0x80050F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050F84:
    // 0x80050F84: lbu         $t7, 0x0($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X0);
    // 0x80050F88: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80050F8C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80050F90: sb          $t8, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r24;
    // 0x80050F94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80050F98:
    // 0x80050F98: beq         $s2, $zero, L_80050FA8
    if (ctx->r18 == 0) {
        // 0x80050F9C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80050FA8;
    }
    // 0x80050F9C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80050FA0: bnel        $s1, $s4, L_80050F64
    if (ctx->r17 != ctx->r20) {
        // 0x80050FA4: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80050F64;
    }
    goto skip_1;
    // 0x80050FA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80050FA8:
    // 0x80050FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050FAC:
    // 0x80050FAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80050FB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050FB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80050FB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050FBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80050FC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80050FC4: jr          $ra
    // 0x80050FC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80050FC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001B6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B6F4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001B6F8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8001B6FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001B700: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001B704: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B708: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x8001B70C: nop

    // 0x8001B710: bc1fl       L_8001B728
    if (!c1cs) {
        // 0x8001B714: lwc1        $f2, 0x38($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X38);
            goto L_8001B728;
    }
    goto skip_0;
    // 0x8001B714: lwc1        $f2, 0x38($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X38);
    skip_0:
    // 0x8001B718: lwc1        $f2, -0x5CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5CC);
    // 0x8001B71C: jr          $ra
    // 0x8001B720: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001B720: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001B724: lwc1        $f2, 0x38($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X38);
L_8001B728:
    // 0x8001B728: jr          $ra
    // 0x8001B72C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001B72C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80045520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80045528: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004552C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80045530: lw          $s0, 0x16C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X16C);
    // 0x80045534: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80045538: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004553C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80045540: lw          $v1, 0x168($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X168);
    // 0x80045544: bnel        $t6, $at, L_80045574
    if (ctx->r14 != ctx->r1) {
        // 0x80045548: lbu         $t7, 0x24($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X24);
            goto L_80045574;
    }
    goto skip_0;
    // 0x80045548: lbu         $t7, 0x24($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X24);
    skip_0:
    // 0x8004554C: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    // 0x80045550: jal         0x8005D96C
    // 0x80045554: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8005D96C(rdram, ctx);
        goto after_0;
    // 0x80045554: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80045558: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004555C: bne         $v0, $at, L_8004556C
    if (ctx->r2 != ctx->r1) {
        // 0x80045560: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8004556C;
    }
    // 0x80045560: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80045564: b           L_800455C8
    // 0x80045568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800455C8;
    // 0x80045568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004556C:
    // 0x8004556C: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80045570: lbu         $t7, 0x24($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X24);
L_80045574:
    // 0x80045574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80045578: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8004557C: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x80045580: andi        $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 & 0XF0;
    // 0x80045584: sb          $t0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r8;
    // 0x80045588: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8004558C: sb          $t2, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r10;
    // 0x80045590: jal         0x800454EC
    // 0x80045594: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800454EC(rdram, ctx);
        goto after_1;
    // 0x80045594: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80045598: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8004559C: addiu       $a0, $s0, 0xD
    ctx->r4 = ADD32(ctx->r16, 0XD);
    // 0x800455A0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800455A4: lbu         $t3, 0x20($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X20);
    // 0x800455A8: addiu       $a1, $v1, 0x21
    ctx->r5 = ADD32(ctx->r3, 0X21);
    // 0x800455AC: jal         0x800655F4
    // 0x800455B0: sb          $t3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r11;
    func_800655F4(rdram, ctx);
        goto after_2;
    // 0x800455B0: sb          $t3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r11;
    after_2:
    // 0x800455B4: lh          $t4, 0xC0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XC0);
    // 0x800455B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800455BC: sh          $t4, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r12;
    // 0x800455C0: lh          $t5, 0xC2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XC2);
    // 0x800455C4: sh          $t5, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r13;
L_800455C8:
    // 0x800455C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800455CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800455D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800455D4: jr          $ra
    // 0x800455D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800455D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8046DD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046DD6C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8046DD70: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8046DD74: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8046DD78: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8046DD7C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8046DD80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046DD84: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8046DD88: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8046DD8C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8046DD90: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8046DD94: jr          $ra
    // 0x8046DD98: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8046DD98: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8046DD9C: nop

;}
RECOMP_FUNC void func_80566FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566FDC: jal         0x80566E48
    // 0x80566FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80566FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566FE4: jal         0x80566F88
    // 0x80566FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80566F88(rdram, ctx);
        goto after_1;
    // 0x80566FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80566FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566FF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80566FF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80566FF8: jal         0x805670F4
    // 0x80566FFC: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80566FFC: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_2:
    // 0x80567000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80567004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80567008: jr          $ra
    // 0x8056700C: nop

    return;
    // 0x8056700C: nop

;}
RECOMP_FUNC void func_8069E528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E528: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8069E52C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069E530: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8069E534: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8069E538: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8069E53C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8069E540: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8069E544: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8069E548: bnel        $t7, $at, L_8069E648
    if (ctx->r15 != ctx->r1) {
        // 0x8069E54C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069E648;
    }
    goto skip_0;
    // 0x8069E54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8069E550: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069E554: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(577, 0X904) << 16);
    // 0x8069E558: addiu       $t8, $t8, -0x132C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(577, 0X904));
    // 0x8069E55C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8069E560: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8069E564: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8069E568: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x8069E56C: addu        $a3, $a2, $t8
    ctx->r7 = ADD32(ctx->r6, ctx->r24);
    // 0x8069E570: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8069E574: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069E578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8069E57C: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8069E580: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8069E584: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x8069E588: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8069E58C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8069E590: lwc1        $f12, 0x20($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8069E594: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8069E598: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8069E59C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8069E5A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8069E5A4: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8069E5A8: sub.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8069E5AC: jal         0x80066DE4
    // 0x8069E5B0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8069E5B0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8069E5B4: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9E0) << 16);
    // 0x8069E5B8: lwc1        $f10, -0x1250($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9E0));
    // 0x8069E5BC: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9E4) << 16);
    // 0x8069E5C0: lwc1        $f18, -0x124C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9E4));
    // 0x8069E5C4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8069E5C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8069E5CC: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X934) << 16);
    // 0x8069E5D0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8069E5D4: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x8069E5D8: lwc1        $f6, -0x12FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X934));
    // 0x8069E5DC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8069E5E0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8069E5E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8069E5E8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8069E5EC: lui         $t4, 0x806A
    ctx->r12 = S32(RELOC_HI16(577, 0X904) << 16);
    // 0x8069E5F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8069E5F4: addiu       $t4, $t4, -0x132C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(577, 0X904));
    // 0x8069E5F8: addu        $t3, $v0, $a1
    ctx->r11 = ADD32(ctx->r2, ctx->r5);
    // 0x8069E5FC: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9E8) << 16);
    // 0x8069E600: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8069E604: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8069E608: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8069E60C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8069E610: bne         $a3, $t4, L_8069E620
    if (ctx->r7 != ctx->r12) {
        // 0x8069E614: swc1        $f10, 0x10C($t3)
        MEM_W(0X10C, ctx->r11) = ctx->f10.u32l;
            goto L_8069E620;
    }
    // 0x8069E614: swc1        $f10, 0x10C($t3)
    MEM_W(0X10C, ctx->r11) = ctx->f10.u32l;
    // 0x8069E618: lwc1        $f16, -0x1248($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9E8));
    // 0x8069E61C: swc1        $f16, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->f16.u32l;
L_8069E620:
    // 0x8069E620: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x8069E624: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8069E628: bne         $t5, $at, L_8069E644
    if (ctx->r13 != ctx->r1) {
        // 0x8069E62C: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_8069E644;
    }
    // 0x8069E62C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8069E630: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x8069E634: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8069E638: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x8069E63C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8069E640: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
L_8069E644:
    // 0x8069E644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069E648:
    // 0x8069E648: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8069E64C: jr          $ra
    // 0x8069E650: nop

    return;
    // 0x8069E650: nop

;}
RECOMP_FUNC void func_80574154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574154: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80574158: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8057415C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80574160: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80574164: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x80574168: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8057416C: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x80574170: jr          $ra
    // 0x80574174: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80574174: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80559054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559054: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80559058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8055905C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80559060: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80559064: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80559068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8055906C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80559070: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80559074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80559078: lwc1        $f2, 0x78($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8055907C: lwc1        $f12, 0x7C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80559080: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80559084: jal         0x80048F84
    // 0x80559088: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80559088: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8055908C: jal         0x805580E8
    // 0x80559090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80559090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80559094: jal         0x805582E0
    // 0x80559098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80559098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8055909C: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x805590A0: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X953C) << 16);
    // 0x805590A4: lwc1        $f0, 0x108C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X953C));
    // 0x805590A8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805590AC: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X93C0) << 16);
    // 0x805590B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805590B4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x805590B8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805590BC: lwc1        $f4, 0xF10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X93C0));
    // 0x805590C0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805590C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805590C8: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x805590CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805590D0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x805590D4: bc1fl       L_80559108
    if (!c1cs) {
        // 0x805590D8: lw          $t0, 0x10($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X10);
            goto L_80559108;
    }
    goto skip_0;
    // 0x805590D8: lw          $t0, 0x10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X10);
    skip_0:
    // 0x805590DC: jal         0x80559928
    // 0x805590E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x805590E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x805590E4: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x805590E8: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X93C0) << 16);
    // 0x805590EC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x805590F0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x805590F4: lwc1        $f12, 0xF10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X93C0));
    // 0x805590F8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x805590FC: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x80559100: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80559104: lw          $t0, 0x10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X10);
L_80559108:
    // 0x80559108: swc1        $f2, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f2.u32l;
    // 0x8055910C: lw          $t1, 0x10($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X10);
    // 0x80559110: swc1        $f12, 0x7C($t1)
    MEM_W(0X7C, ctx->r9) = ctx->f12.u32l;
    // 0x80559114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80559118: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8055911C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80559120: jr          $ra
    // 0x80559124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80559124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80067818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006781C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067820: jal         0x80011D1C
    // 0x80067824: nop

    func_80011D1C(rdram, ctx);
        goto after_0;
    // 0x80067824: nop

    after_0:
    // 0x80067828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006782C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067830: jr          $ra
    // 0x80067834: nop

    return;
    // 0x80067834: nop

;}
RECOMP_FUNC void func_800615D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800615D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800615D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800615D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800615DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800615E0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800615E4: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x800615E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800615EC: sw          $t6, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r14;
    // 0x800615F0: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800615F4: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800615F8: sh          $t7, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r15;
    // 0x800615FC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061600: lh          $t9, 0x56($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X56);
    // 0x80061604: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80061608: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8006160C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80061610: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80061614: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061618: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x8006161C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061620: lh          $t1, 0x58($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X58);
    // 0x80061624: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80061628: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8006162C: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80061630: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80061634: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80061638: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8006163C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061640: lh          $t3, 0x5A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5A);
    // 0x80061644: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x80061648: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8006164C: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80061650: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80061654: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061658: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x8006165C: jal         0x8005FFB4
    // 0x80061660: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    func_8005FFB4(rdram, ctx);
        goto after_0;
    // 0x80061660: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x80061664: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061668: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8006166C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80061670: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061674: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80061678: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8006167C: lh          $t5, 0x52($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X52);
    // 0x80061680: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x80061684: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80061688: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8006168C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80061690: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80061694: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80061698: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x8006169C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800616A0: lwc1        $f18, 0x8C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x800616A4: lh          $t7, 0x54($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X54);
    // 0x800616A8: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x800616AC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800616B0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800616B4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800616B8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800616BC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800616C0: beq         $a0, $zero, L_80061794
    if (ctx->r4 == 0) {
        // 0x800616C4: swc1        $f16, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
            goto L_80061794;
    }
    // 0x800616C4: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x800616C8: lh          $t8, 0x78($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X78);
    // 0x800616CC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800616D0: beql        $t8, $zero, L_80061798
    if (ctx->r24 == 0) {
        // 0x800616D4: lw          $t1, 0x4($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X4);
            goto L_80061798;
    }
    goto skip_0;
    // 0x800616D4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x800616D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800616DC: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x800616E0: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_800616E4:
    // 0x800616E4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800616E8: beql        $v1, $zero, L_80061780
    if (ctx->r3 == 0) {
        // 0x800616EC: addiu       $t9, $v0, 0x4
        ctx->r25 = ADD32(ctx->r2, 0X4);
            goto L_80061780;
    }
    goto skip_1;
    // 0x800616EC: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x800616F0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800616F4: beql        $t9, $v1, L_8006176C
    if (ctx->r25 == ctx->r3) {
        // 0x800616F8: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006176C;
    }
    goto skip_2;
    // 0x800616F8: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_2:
    // 0x800616FC: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x80061700: lwc1        $f6, 0xC8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80061704: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80061708: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8006170C: nop

    // 0x80061710: bc1fl       L_8006176C
    if (!c1cs) {
        // 0x80061714: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006176C;
    }
    goto skip_3;
    // 0x80061714: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_3:
    // 0x80061718: lw          $t0, 0x174($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X174);
    // 0x8006171C: sw          $t0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r8;
    // 0x80061720: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80061724: andi        $t3, $t2, 0xF00
    ctx->r11 = ctx->r10 & 0XF00;
    // 0x80061728: bnel        $t3, $zero, L_8006176C
    if (ctx->r11 != 0) {
        // 0x8006172C: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006176C;
    }
    goto skip_4;
    // 0x8006172C: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_4:
    // 0x80061730: lbu         $t4, 0x5($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X5);
    // 0x80061734: beq         $t4, $zero, L_80061748
    if (ctx->r12 == 0) {
        // 0x80061738: nop
    
            goto L_80061748;
    }
    // 0x80061738: nop

    // 0x8006173C: lbu         $t5, 0x10($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X10);
    // 0x80061740: beql        $t5, $zero, L_8006176C
    if (ctx->r13 == 0) {
        // 0x80061744: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006176C;
    }
    goto skip_5;
    // 0x80061744: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_5:
L_80061748:
    // 0x80061748: jal         0x80060274
    // 0x8006174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060274(rdram, ctx);
        goto after_1;
    // 0x8006174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80061750: beql        $v0, $zero, L_8006176C
    if (ctx->r2 == 0) {
        // 0x80061754: lh          $t7, 0x78($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X78);
            goto L_8006176C;
    }
    goto skip_6;
    // 0x80061754: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
    skip_6:
    // 0x80061758: jal         0x80060ED0
    // 0x8006175C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ED0(rdram, ctx);
        goto after_2;
    // 0x8006175C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80061760: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80061764: swc1        $f20, 0x120($t6)
    MEM_W(0X120, ctx->r14) = ctx->f20.u32l;
    // 0x80061768: lh          $t7, 0x78($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X78);
L_8006176C:
    // 0x8006176C: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80061770: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80061774: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80061778: sh          $t8, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r24;
    // 0x8006177C: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
L_80061780:
    // 0x80061780: beq         $a0, $zero, L_80061794
    if (ctx->r4 == 0) {
        // 0x80061784: sw          $t9, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r25;
            goto L_80061794;
    }
    // 0x80061784: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x80061788: lh          $t0, 0x78($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X78);
    // 0x8006178C: bnel        $t0, $zero, L_800616E4
    if (ctx->r8 != 0) {
        // 0x80061790: lw          $v0, 0x74($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X74);
            goto L_800616E4;
    }
    goto skip_7;
    // 0x80061790: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    skip_7:
L_80061794:
    // 0x80061794: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
L_80061798:
    // 0x80061798: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006179C: lh          $t2, 0x184($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X184);
    // 0x800617A0: beql        $t2, $zero, L_800617C8
    if (ctx->r10 == 0) {
        // 0x800617A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800617C8;
    }
    goto skip_8;
    // 0x800617A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x800617A8: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800617AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800617B0: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x800617B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800617B8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800617BC: jalr        $t9
    // 0x800617C0: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800617C0: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x800617C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800617C8:
    // 0x800617C8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800617CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800617D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800617D4: jr          $ra
    // 0x800617D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800617D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805E0C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E0C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E0C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E0C98: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x805E0C9C: addiu       $at, $zero, 0x453A
    ctx->r1 = ADD32(0, 0X453A);
    // 0x805E0CA0: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(483, 0X7A0) << 16);
    // 0x805E0CA4: bne         $t6, $at, L_805E0CCC
    if (ctx->r14 != ctx->r1) {
        // 0x805E0CA8: addiu       $a0, $a0, 0x1430
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(483, 0X7A0));
            goto L_805E0CCC;
    }
    // 0x805E0CA8: addiu       $a0, $a0, 0x1430
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(483, 0X7A0));
    // 0x805E0CAC: lui         $a0, 0x805E
    ctx->r4 = S32(RELOC_HI16(483, 0X790) << 16);
    // 0x805E0CB0: lui         $a1, 0x805E
    ctx->r5 = S32(RELOC_HI16(483, 0X7B0) << 16);
    // 0x805E0CB4: addiu       $a1, $a1, 0x1440
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(483, 0X7B0));
    // 0x805E0CB8: addiu       $a0, $a0, 0x1420
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(483, 0X790));
    // 0x805E0CBC: jal         0x8004667C
    // 0x805E0CC0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805E0CC0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x805E0CC4: b           L_805E0CDC
    // 0x805E0CC8: nop

        goto L_805E0CDC;
    // 0x805E0CC8: nop

L_805E0CCC:
    // 0x805E0CCC: lui         $a1, 0x805E
    ctx->r5 = S32(RELOC_HI16(483, 0X25B0) << 16);
    // 0x805E0CD0: addiu       $a1, $a1, 0x3240
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(483, 0X25B0));
    // 0x805E0CD4: jal         0x8004667C
    // 0x805E0CD8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_1;
    // 0x805E0CD8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
L_805E0CDC:
    // 0x805E0CDC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805E0CE0: lui         $a2, 0x805E
    ctx->r6 = S32(RELOC_HI16(483, 0X578) << 16);
    // 0x805E0CE4: addiu       $a2, $a2, 0x1208
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(483, 0X578));
    // 0x805E0CE8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805E0CEC: jal         0x80057B28
    // 0x805E0CF0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80057B28(rdram, ctx);
        goto after_2;
    // 0x805E0CF0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x805E0CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E0CF8: lui         $v0, 0x805E
    ctx->r2 = S32(RELOC_HI16(483, 0X78) << 16);
    // 0x805E0CFC: addiu       $v0, $v0, 0xD08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(483, 0X78));
    // 0x805E0D00: jr          $ra
    // 0x805E0D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805E0D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80799758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079975C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799760: jal         0x8079968C
    // 0x80799764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079968C(rdram, ctx);
        goto after_0;
    // 0x80799764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80799768: jal         0x807996E8
    // 0x8079976C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807996E8(rdram, ctx);
        goto after_1;
    // 0x8079976C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80799770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799778: jr          $ra
    // 0x8079977C: nop

    return;
    // 0x8079977C: nop

;}
RECOMP_FUNC void func_804B97E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B97E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B97E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B97EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B97F0: jal         0x804B97A0
    // 0x804B97F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804B97A0(rdram, ctx);
        goto after_0;
    // 0x804B97F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B97F8: bne         $v0, $zero, L_804B9810
    if (ctx->r2 != 0) {
        // 0x804B97FC: lui         $t6, 0x804C
        ctx->r14 = S32(RELOC_HI16(185, 0X14DC) << 16);
            goto L_804B9810;
    }
    // 0x804B97FC: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(185, 0X14DC) << 16);
    // 0x804B9800: jal         0x800445A4
    // 0x804B9804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804B9804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B9808: b           L_804B9880
    // 0x804B980C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804B9880;
    // 0x804B980C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B9810:
    // 0x804B9810: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804B9814: addiu       $t6, $t6, -0x6D04
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(185, 0X14DC));
    // 0x804B9818: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x804B981C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804B9820: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x804B9824: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x804B9828: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(185, 0X2A18) << 16);
    // 0x804B982C: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    // 0x804B9830: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804B9834: addiu       $t9, $t9, -0x57C8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(185, 0X2A18));
    // 0x804B9838: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x804B983C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804B9840: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804B9844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9848: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B984C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B9850: jal         0x804B9890
    // 0x804B9854: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B9890(rdram, ctx);
        goto after_2;
    // 0x804B9854: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804B9858: jal         0x804B945C
    // 0x804B985C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B945C(rdram, ctx);
        goto after_3;
    // 0x804B985C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B9860: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x804B9864: sh          $t1, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r9;
    // 0x804B9868: jal         0x804B7F14
    // 0x804B986C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7F14(rdram, ctx);
        goto after_4;
    // 0x804B986C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804B9870: lui         $t2, 0x804B
    ctx->r10 = S32(RELOC_HI16(185, 0X194) << 16);
    // 0x804B9874: addiu       $t2, $t2, 0x7FB4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(185, 0X194));
    // 0x804B9878: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x804B987C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B9880:
    // 0x804B9880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B9884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B9888: jr          $ra
    // 0x804B988C: nop

    return;
    // 0x804B988C: nop

;}
RECOMP_FUNC void func_8046BEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BEB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046BEBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8046BEC0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8046BEC4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8046BEC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BECC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8046BED0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046BED4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8046BED8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8046BEDC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8046BEE0: lui         $t2, 0x8047
    ctx->r10 = S32(RELOC_HI16(138, 0X2910) << 16);
    // 0x8046BEE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8046BEE8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8046BEEC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8046BEF0: lw          $t2, -0x3FB0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(138, 0X2910));
    // 0x8046BEF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8046BEF8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8046BEFC: jal         0x8046B3B0
    // 0x8046BF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046B3B0(rdram, ctx);
        goto after_0;
    // 0x8046BF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046BF04: jal         0x8046B338
    // 0x8046BF08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046B338(rdram, ctx);
        goto after_1;
    // 0x8046BF08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046BF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BF10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046BF14: jr          $ra
    // 0x8046BF18: nop

    return;
    // 0x8046BF18: nop

    // 0x8046BF1C: nop

;}
RECOMP_FUNC void func_80678FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80678FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80678FE0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80678FE4: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(538, 0X1448) << 16);
    // 0x80678FE8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80678FEC: addiu       $t6, $t6, -0x6C48
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(538, 0X1448));
    // 0x80678FF0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80678FF4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80678FF8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80678FFC: sh          $t8, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r24;
    // 0x80679000: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80679004: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80679008: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8067900C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80679010: jal         0x80048378
    // 0x80679014: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80679014: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x80679018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067901C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80679020: jr          $ra
    // 0x80679024: nop

    return;
    // 0x80679024: nop

;}
RECOMP_FUNC void func_80446F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446F60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80446F64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80446F68: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80446F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446F70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80446F74: bne         $a2, $zero, L_80446FB0
    if (ctx->r6 != 0) {
        // 0x80446F78: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80446FB0;
    }
    // 0x80446F78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446F7C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80446F80: lw          $v1, 0x60($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X60);
    // 0x80446F84: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80446F88: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80446F8C: bne         $at, $zero, L_80446FEC
    if (ctx->r1 != 0) {
        // 0x80446F90: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80446FEC;
    }
    // 0x80446F90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80446F94: jal         0x80445EC8
    // 0x80446F98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445EC8(rdram, ctx);
        goto after_0;
    // 0x80446F98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80446F9C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80446FA0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446FA4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446FA8: b           L_80446FEC
    // 0x80446FAC: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_80446FEC;
    // 0x80446FAC: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_80446FB0:
    // 0x80446FB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80446FB4: bnel        $a2, $at, L_80446FDC
    if (ctx->r6 != ctx->r1) {
        // 0x80446FB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80446FDC;
    }
    goto skip_0;
    // 0x80446FB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80446FBC: jal         0x80445EC8
    // 0x80446FC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445EC8(rdram, ctx);
        goto after_1;
    // 0x80446FC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80446FC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80446FC8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446FCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446FD0: b           L_80446FEC
    // 0x80446FD4: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_80446FEC;
    // 0x80446FD4: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x80446FD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80446FDC:
    // 0x80446FDC: bnel        $a2, $at, L_80446FF0
    if (ctx->r6 != ctx->r1) {
        // 0x80446FE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80446FF0;
    }
    goto skip_1;
    // 0x80446FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80446FE4: jal         0x80445F10
    // 0x80446FE8: nop

    func_80445F10(rdram, ctx);
        goto after_2;
    // 0x80446FE8: nop

    after_2:
L_80446FEC:
    // 0x80446FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446FF0:
    // 0x80446FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80446FF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80446FF8: jr          $ra
    // 0x80446FFC: nop

    return;
    // 0x80446FFC: nop

;}
RECOMP_FUNC void func_80048BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048BAC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80048BB0: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80048BB4: addiu       $a3, $a3, -0x74A4
    ctx->r7 = ADD32(ctx->r7, -0X74A4);
    // 0x80048BB8: addiu       $a2, $a2, 0x3E88
    ctx->r6 = ADD32(ctx->r6, 0X3E88);
    // 0x80048BBC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80048BC0: jal         0x80057F74
    // 0x80048BC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x80048BC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80048BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048BD0: jr          $ra
    // 0x80048BD4: nop

    return;
    // 0x80048BD4: nop

;}
RECOMP_FUNC void func_80064E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E84: beq         $a0, $zero, L_80064F30
    if (ctx->r4 == 0) {
        // 0x80064E88: sll         $t6, $a0, 4
        ctx->r14 = S32(ctx->r4 << 4);
            goto L_80064F30;
    }
    // 0x80064E88: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80064E8C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80064E90: bne         $t7, $zero, L_80064F30
    if (ctx->r15 != 0) {
        // 0x80064E94: addiu       $v1, $a0, -0x10
        ctx->r3 = ADD32(ctx->r4, -0X10);
            goto L_80064F30;
    }
    // 0x80064E94: addiu       $v1, $a0, -0x10
    ctx->r3 = ADD32(ctx->r4, -0X10);
    // 0x80064E98: beq         $v1, $zero, L_80064F30
    if (ctx->r3 == 0) {
        // 0x80064E9C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80064F30;
    }
    // 0x80064E9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80064EA0: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x80064EA4: beq         $t8, $zero, L_80064F30
    if (ctx->r24 == 0) {
        // 0x80064EA8: nop
    
            goto L_80064F30;
    }
    // 0x80064EA8: nop

    // 0x80064EAC: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x80064EB0: addiu       $at, $zero, 0x913
    ctx->r1 = ADD32(0, 0X913);
    // 0x80064EB4: bne         $t9, $at, L_80064F30
    if (ctx->r25 != ctx->r1) {
        // 0x80064EB8: nop
    
            goto L_80064F30;
    }
    // 0x80064EB8: nop

    // 0x80064EBC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80064EC0: lhu         $t0, 0x2($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X2);
    // 0x80064EC4: bnel        $t0, $zero, L_80064EFC
    if (ctx->r8 != 0) {
        // 0x80064EC8: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80064EFC;
    }
    goto skip_0;
    // 0x80064EC8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80064ECC: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80064ED0: sw          $a0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r4;
    // 0x80064ED4: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x80064ED8: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80064EDC: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80064EE0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80064EE4: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x80064EE8: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
    // 0x80064EEC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80064EF0: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80064EF4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80064EF8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_80064EFC:
    // 0x80064EFC: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x80064F00: bnel        $t7, $zero, L_80064F30
    if (ctx->r15 != 0) {
        // 0x80064F04: sh          $zero, 0x2($v0)
        MEM_H(0X2, ctx->r2) = 0;
            goto L_80064F30;
    }
    goto skip_1;
    // 0x80064F04: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    skip_1:
    // 0x80064F08: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80064F0C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80064F10: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80064F14: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80064F18: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x80064F1C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80064F20: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x80064F24: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80064F28: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x80064F2C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_80064F30:
    // 0x80064F30: jr          $ra
    // 0x80064F34: nop

    return;
    // 0x80064F34: nop

;}
RECOMP_FUNC void func_8000C3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C3A0: sw          $a1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r5;
    // 0x8000C3A4: lw          $t6, 0x50($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X50);
    // 0x8000C3A8: lbu         $t9, 0x60($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X60);
    // 0x8000C3AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000C3B0: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x8000C3B4: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8000C3B8: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x8000C3BC: lwc1        $f4, 0x6AA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AA8);
    // 0x8000C3C0: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x8000C3C4: jr          $ra
    // 0x8000C3C8: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8000C3C8: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80677F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80677F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80677F78: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80677F7C: addiu       $at, $zero, 0x4564
    ctx->r1 = ADD32(0, 0X4564);
    // 0x80677F80: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(538, 0X133C) << 16);
    // 0x80677F84: bne         $t6, $at, L_80677FE0
    if (ctx->r14 != ctx->r1) {
        // 0x80677F88: addiu       $v0, $v0, -0x6D54
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(538, 0X133C));
            goto L_80677FE0;
    }
    // 0x80677F88: addiu       $v0, $v0, -0x6D54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(538, 0X133C));
    // 0x80677F8C: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(538, 0X1420) << 16);
    // 0x80677F90: lw          $t7, -0x6C70($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(538, 0X1420));
    // 0x80677F94: lui         $a0, 0x8068
    ctx->r4 = S32(RELOC_HI16(538, 0X15B0) << 16);
    // 0x80677F98: addiu       $a0, $a0, -0x6AE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(538, 0X15B0));
    // 0x80677F9C: bne         $t7, $zero, L_80677FD4
    if (ctx->r15 != 0) {
        // 0x80677FA0: lui         $a1, 0x8068
        ctx->r5 = S32(RELOC_HI16(538, 0X15C0) << 16);
            goto L_80677FD4;
    }
    // 0x80677FA0: lui         $a1, 0x8068
    ctx->r5 = S32(RELOC_HI16(538, 0X15C0) << 16);
    // 0x80677FA4: addiu       $a1, $a1, -0x6AD0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(538, 0X15C0));
    // 0x80677FA8: jal         0x8004667C
    // 0x80677FAC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80677FAC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80677FB0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80677FB4: lui         $a2, 0x8068
    ctx->r6 = S32(RELOC_HI16(538, 0X578) << 16);
    // 0x80677FB8: addiu       $a2, $a2, -0x7B18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(538, 0X578));
    // 0x80677FBC: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80677FC0: jal         0x80057B28
    // 0x80677FC4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80677FC4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_1:
    // 0x80677FC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80677FCC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(538, 0X1420) << 16);
    // 0x80677FD0: sw          $t8, -0x6C70($at)
    MEM_W((int16_t)RELOC_LO16(538, 0X1420), ctx->r1) = ctx->r24;
L_80677FD4:
    // 0x80677FD4: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(538, 0X133C) << 16);
    // 0x80677FD8: b           L_80677FE0
    // 0x80677FDC: addiu       $v0, $v0, -0x6D54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(538, 0X133C));
        goto L_80677FE0;
    // 0x80677FDC: addiu       $v0, $v0, -0x6D54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(538, 0X133C));
L_80677FE0:
    // 0x80677FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80677FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80677FE8: jr          $ra
    // 0x80677FEC: nop

    return;
    // 0x80677FEC: nop

;}
RECOMP_FUNC void func_8002C35C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C35C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8002C360: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C36C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C370: addiu       $a1, $a1, -0x3578
    ctx->r5 = ADD32(ctx->r5, -0X3578);
    // 0x8002C374: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8002C378: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C37C: jal         0x80028118
    // 0x8002C380: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C380: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C384: jal         0x8002AE90
    // 0x8002C388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002AE90(rdram, ctx);
        goto after_1;
    // 0x8002C388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002C38C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C390: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C394: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8002C398: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002C39C: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C3A0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8002C3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C3A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C3AC: jr          $ra
    // 0x8002C3B0: nop

    return;
    // 0x8002C3B0: nop

;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008842C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80088430: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80088434: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80088438: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x8008843C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80088440: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80088444:
    // 0x80088444: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80088448: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008844C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80088450: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x80088454: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x80088458: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8008845C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80088460: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x80088464: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x80088468: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008846C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80088470: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x80088474: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80088478: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8008847C: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x80088480: bne         $at, $zero, L_80088444
    if (ctx->r1 != 0) {
        // 0x80088484: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_80088444;
    }
    // 0x80088484: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80088488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008848C: jr          $ra
    // 0x80088490: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80088490: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8004E450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004E458: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004E45C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004E460: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8004E464: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8004E468: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004E46C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004E470: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E474: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8004E478: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8004E47C: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8004E480: beql        $v0, $zero, L_8004E4B8
    if (ctx->r2 == 0) {
        // 0x8004E484: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E4B8;
    }
    goto skip_0;
    // 0x8004E484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004E488: beql        $v0, $at, L_8004E4B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004E48C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E4B8;
    }
    goto skip_1;
    // 0x8004E48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004E490: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8004E494: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E498: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004E49C: beq         $v0, $at, L_8004E4B4
    if (ctx->r2 == ctx->r1) {
        // 0x8004E4A0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E4B4;
    }
    // 0x8004E4A0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E4A4: beq         $v0, $at, L_8004E4B4
    if (ctx->r2 == ctx->r1) {
        // 0x8004E4A8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004E4B4;
    }
    // 0x8004E4A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004E4AC: jal         0x8004D11C
    // 0x8004E4B0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_8004D11C(rdram, ctx);
        goto after_0;
    // 0x8004E4B0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_0:
L_8004E4B4:
    // 0x8004E4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004E4B8:
    // 0x8004E4B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E4BC: jr          $ra
    // 0x8004E4C0: nop

    return;
    // 0x8004E4C0: nop

;}
RECOMP_FUNC void func_80680B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680B90: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80680B94: addiu       $at, $zero, 0x4578
    ctx->r1 = ADD32(0, 0X4578);
    // 0x80680B98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680B9C: beq         $v1, $at, L_80680BC4
    if (ctx->r3 == ctx->r1) {
        // 0x80680BA0: addiu       $t6, $zero, 0xB4
        ctx->r14 = ADD32(0, 0XB4);
            goto L_80680BC4;
    }
    // 0x80680BA0: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x80680BA4: addiu       $at, $zero, 0x4579
    ctx->r1 = ADD32(0, 0X4579);
    // 0x80680BA8: beq         $v1, $at, L_80680BCC
    if (ctx->r3 == ctx->r1) {
        // 0x80680BAC: addiu       $t7, $zero, 0xF0
        ctx->r15 = ADD32(0, 0XF0);
            goto L_80680BCC;
    }
    // 0x80680BAC: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x80680BB0: addiu       $at, $zero, 0x457A
    ctx->r1 = ADD32(0, 0X457A);
    // 0x80680BB4: beq         $v1, $at, L_80680BD4
    if (ctx->r3 == ctx->r1) {
        // 0x80680BB8: addiu       $t8, $zero, 0x12C
        ctx->r24 = ADD32(0, 0X12C);
            goto L_80680BD4;
    }
    // 0x80680BB8: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x80680BBC: b           L_80680BDC
    // 0x80680BC0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
        goto L_80680BDC;
    // 0x80680BC0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
L_80680BC4:
    // 0x80680BC4: b           L_80680BD8
    // 0x80680BC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80680BD8;
    // 0x80680BC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80680BCC:
    // 0x80680BCC: b           L_80680BD8
    // 0x80680BD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_80680BD8;
    // 0x80680BD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80680BD4:
    // 0x80680BD4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80680BD8:
    // 0x80680BD8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
L_80680BDC:
    // 0x80680BDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80680BE0: jr          $ra
    // 0x80680BE4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80680BE4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80671BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80671BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80671BEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80671BF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80671BF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80671BF8: lw          $s0, 0x1E0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1E0);
    // 0x80671BFC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80671C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80671C04: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80671C08: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80671C0C: beq         $a1, $zero, L_80671C38
    if (ctx->r5 == 0) {
        // 0x80671C10: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80671C38;
    }
    // 0x80671C10: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80671C14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80671C18: beq         $a1, $at, L_80671C48
    if (ctx->r5 == ctx->r1) {
        // 0x80671C1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80671C48;
    }
    // 0x80671C1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80671C20: beq         $a1, $at, L_80671C5C
    if (ctx->r5 == ctx->r1) {
        // 0x80671C24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80671C5C;
    }
    // 0x80671C24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80671C28: beql        $a1, $at, L_80671C74
    if (ctx->r5 == ctx->r1) {
        // 0x80671C2C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80671C74;
    }
    goto skip_0;
    // 0x80671C2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80671C30: b           L_80671C88
    // 0x80671C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80671C88;
    // 0x80671C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80671C38:
    // 0x80671C38: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671C3C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80671C40: jal         0x8005C27C
    // 0x80671C44: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80671C44: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_0:
L_80671C48:
    // 0x80671C48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80671C4C: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671C50: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80671C54: jal         0x8005C27C
    // 0x80671C58: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x80671C58: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
L_80671C5C:
    // 0x80671C5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80671C60: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671C64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80671C68: jal         0x8005C27C
    // 0x80671C6C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x80671C6C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80671C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80671C74:
    // 0x80671C74: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671C78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80671C7C: jal         0x8005C27C
    // 0x80671C80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x80671C80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80671C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80671C88:
    // 0x80671C88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80671C8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80671C90: jr          $ra
    // 0x80671C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80671C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807883A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807883A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807883A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807883A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807883AC: jal         0x80788238
    // 0x807883B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80788238(rdram, ctx);
        goto after_0;
    // 0x807883B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807883B4: jal         0x807882CC
    // 0x807883B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807882CC(rdram, ctx);
        goto after_1;
    // 0x807883B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807883BC: bnel        $v0, $zero, L_80788414
    if (ctx->r2 != 0) {
        // 0x807883C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80788414;
    }
    goto skip_0;
    // 0x807883C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807883C4: jal         0x80787FAC
    // 0x807883C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787FAC(rdram, ctx);
        goto after_2;
    // 0x807883C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807883CC: jal         0x80787414
    // 0x807883D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787414(rdram, ctx);
        goto after_3;
    // 0x807883D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807883D4: jal         0x8078749C
    // 0x807883D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078749C(rdram, ctx);
        goto after_4;
    // 0x807883D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807883DC: jal         0x80787598
    // 0x807883E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787598(rdram, ctx);
        goto after_5;
    // 0x807883E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807883E4: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807883E8: lhu         $t8, 0x52F0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X52F0);
    // 0x807883EC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x807883F0: beq         $t9, $zero, L_80788408
    if (ctx->r25 == 0) {
        // 0x807883F4: nop
    
            goto L_80788408;
    }
    // 0x807883F4: nop

    // 0x807883F8: jal         0x80787D9C
    // 0x807883FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787D9C(rdram, ctx);
        goto after_6;
    // 0x807883FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80788400: b           L_80788414
    // 0x80788404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80788414;
    // 0x80788404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80788408:
    // 0x80788408: jal         0x80787EA4
    // 0x8078840C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787EA4(rdram, ctx);
        goto after_7;
    // 0x8078840C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80788410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80788414:
    // 0x80788414: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80788418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078841C: jr          $ra
    // 0x80788420: nop

    return;
    // 0x80788420: nop

;}
RECOMP_FUNC void func_8042A5A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A5A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042A5A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042A5AC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042A5B0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8042A5B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042A5B8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8042A5BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042A5C0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8042A5C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042A5C8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8042A5CC: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(47, 0X9F8) << 16);
    // 0x8042A5D0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042A5D4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042A5D8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8042A5DC: lw          $t2, -0x5838($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(47, 0X9F8));
    // 0x8042A5E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042A5E4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042A5E8: jal         0x80429F8C
    // 0x8042A5EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80429F8C(rdram, ctx);
        goto after_0;
    // 0x8042A5EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042A5F0: jal         0x80429FE8
    // 0x8042A5F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80429FE8(rdram, ctx);
        goto after_1;
    // 0x8042A5F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042A5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042A5FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042A600: jr          $ra
    // 0x8042A604: nop

    return;
    // 0x8042A604: nop

    // 0x8042A608: nop

    // 0x8042A60C: nop

;}
RECOMP_FUNC void func_80474A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474A24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80474A28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80474A2C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80474A30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80474A34: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80474A38: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80474A3C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80474A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80474A44: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80474A48: lw          $t6, 0x6D10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X6D10);
    // 0x80474A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80474A50: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80474A54: beq         $t6, $at, L_80474AA0
    if (ctx->r14 == ctx->r1) {
        // 0x80474A58: addiu       $a1, $zero, 0x21C
        ctx->r5 = ADD32(0, 0X21C);
            goto L_80474AA0;
    }
    // 0x80474A58: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474A5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474A60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474A64: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294EC) << 16);
    // 0x80474A68: lwc1        $f4, -0x2354($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294EC));
    // 0x80474A6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80474A70: addiu       $t7, $zero, 0x1D10
    ctx->r15 = ADD32(0, 0X1D10);
    // 0x80474A74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80474A78: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80474A7C: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x80474A80: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474A84: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80474A88: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80474A8C: jal         0x804747CC
    // 0x80474A90: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_804747CC(rdram, ctx);
        goto after_0;
    // 0x80474A90: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80474A94: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80474A98: b           L_80474AF0
    // 0x80474A9C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80474AF0;
    // 0x80474A9C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80474AA0:
    // 0x80474AA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474AA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80474AA8: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294F0) << 16);
    // 0x80474AAC: lwc1        $f8, -0x2350($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294F0));
    // 0x80474AB0: lwc1        $f0, 0x6AA0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6AA0);
    // 0x80474AB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474AB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80474ABC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(164, 0X294F4) << 16);
    // 0x80474AC0: lwc1        $f16, -0x234C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(164, 0X294F4));
    // 0x80474AC4: addiu       $t8, $zero, 0x1D10
    ctx->r24 = ADD32(0, 0X1D10);
    // 0x80474AC8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80474ACC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80474AD0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80474AD4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80474AD8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80474ADC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80474AE0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80474AE4: jal         0x804748D0
    // 0x80474AE8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_804748D0(rdram, ctx);
        goto after_1;
    // 0x80474AE8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80474AEC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_80474AF0:
    // 0x80474AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80474AF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80474AF8: nop

    // 0x80474AFC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80474B00: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80474B04: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80474B08: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80474B0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80474B10: jr          $ra
    // 0x80474B14: nop

    return;
    // 0x80474B14: nop

;}
RECOMP_FUNC void func_8004FCB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FCB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004FCB4: slti        $at, $a1, 0x69
    ctx->r1 = SIGNED(ctx->r5) < 0X69 ? 1 : 0;
    // 0x8004FCB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FCBC: bne         $at, $zero, L_8004FCDC
    if (ctx->r1 != 0) {
        // 0x8004FCC0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8004FCDC;
    }
    // 0x8004FCC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004FCC4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8004FCC8: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x8004FCCC: jal         0x80064D1C
    // 0x8004FCD0: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8004FCD0: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    after_0:
    // 0x8004FCD4: b           L_8004FD30
    // 0x8004FCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004FD30;
    // 0x8004FCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004FCDC:
    // 0x8004FCDC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8004FCE0: lw          $v0, 0x108C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X108C);
    // 0x8004FCE4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004FCE8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004FCEC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8004FCF0: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8004FCF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004FCF8: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8004FCFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FD00: sw          $v0, 0x108C($at)
    MEM_W(0X108C, ctx->r1) = ctx->r2;
    // 0x8004FD04: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004FD08: addiu       $t8, $t8, -0x6560
    ctx->r24 = ADD32(ctx->r24, -0X6560);
    // 0x8004FD0C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8004FD10: bne         $at, $zero, L_8004FD20
    if (ctx->r1 != 0) {
        // 0x8004FD14: addu        $v1, $t7, $t8
        ctx->r3 = ADD32(ctx->r15, ctx->r24);
            goto L_8004FD20;
    }
    // 0x8004FD14: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004FD18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004FD1C: sw          $zero, 0x108C($at)
    MEM_W(0X108C, ctx->r1) = 0;
L_8004FD20:
    // 0x8004FD20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004FD24: sw          $t9, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r25;
    // 0x8004FD28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004FD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004FD30:
    // 0x8004FD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FD34: jr          $ra
    // 0x8004FD38: nop

    return;
    // 0x8004FD38: nop

;}
RECOMP_FUNC void func_8057A6CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057A6CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057A6D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057A6D4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8057A6D8: lw          $a2, -0x7638($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7638);
    // 0x8057A6DC: jal         0x80579F18
    // 0x8057A6E0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    func_80579F18(rdram, ctx);
        goto after_0;
    // 0x8057A6E0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8057A6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057A6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057A6EC: jr          $ra
    // 0x8057A6F0: nop

    return;
    // 0x8057A6F0: nop

;}
RECOMP_FUNC void func_804C0938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C093C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0940: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804C0944: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(197, 0X504) << 16);
    // 0x804C0948: addiu       $t8, $t8, 0x9C4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(197, 0X504));
    // 0x804C094C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C0950: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804C0954: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C0958: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804C095C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C0960: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C0964: beql        $v1, $zero, L_804C099C
    if (ctx->r3 == 0) {
        // 0x804C0968: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C099C;
    }
    goto skip_0;
    // 0x804C0968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C096C: jalr        $v1
    // 0x804C0970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C0970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C0974: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C0978: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804C097C: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804C0980: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804C0984: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804C0988: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804C098C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804C0990: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804C0994: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804C0998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C099C:
    // 0x804C099C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C09A0: jr          $ra
    // 0x804C09A4: nop

    return;
    // 0x804C09A4: nop

    // 0x804C09A8: nop

    // 0x804C09AC: nop

;}
RECOMP_FUNC void func_8003639C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003639C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800363A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800363A4: jal         0x80023EA0
    // 0x800363A8: nop

    func_80023EA0(rdram, ctx);
        goto after_0;
    // 0x800363A8: nop

    after_0:
    // 0x800363AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800363B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800363B4: jr          $ra
    // 0x800363B8: nop

    return;
    // 0x800363B8: nop

;}
RECOMP_FUNC void func_80462ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462ABC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80462AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80462AC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80462AC8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462ACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80462AD0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80462AD4: jal         0x80062684
    // 0x80462AD8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80462AD8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80462ADC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80462AE0: lw          $v0, 0xC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XC);
    // 0x80462AE4: beql        $v0, $zero, L_80462C44
    if (ctx->r2 == 0) {
        // 0x80462AE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80462C44;
    }
    goto skip_0;
    // 0x80462AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80462AEC: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80462AF0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A60) << 16);
    // 0x80462AF4: beql        $v1, $zero, L_80462C44
    if (ctx->r3 == 0) {
        // 0x80462AF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80462C44;
    }
    goto skip_1;
    // 0x80462AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80462AFC: lwc1        $f4, 0x3FF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A60));
    // 0x80462B00: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80462B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462B08: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80462B0C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80462B10: nop

    // 0x80462B14: bc1fl       L_80462B40
    if (!c1cs) {
        // 0x80462B18: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80462B40;
    }
    goto skip_2;
    // 0x80462B18: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    skip_2:
    // 0x80462B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462B20: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80462B24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80462B28: jal         0x80460634
    // 0x80462B2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80460634(rdram, ctx);
        goto after_1;
    // 0x80462B2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80462B30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80462B34: b           L_80462B50
    // 0x80462B38: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_80462B50;
    // 0x80462B38: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80462B3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80462B40:
    // 0x80462B40: jal         0x804606DC
    // 0x80462B44: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_804606DC(rdram, ctx);
        goto after_2;
    // 0x80462B44: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x80462B48: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80462B4C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_80462B50:
    // 0x80462B50: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    // 0x80462B54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80462B58: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80462B5C: bne         $t8, $at, L_80462C24
    if (ctx->r24 != ctx->r1) {
        // 0x80462B60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80462C24;
    }
    // 0x80462B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462B64: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80462B68: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80462B6C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80462B70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80462B74: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80462B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462B7C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A64) << 16);
    // 0x80462B80: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80462B84: nop

    // 0x80462B88: bc1fl       L_80462BB8
    if (!c1cs) {
        // 0x80462B8C: lwc1        $f0, 0x8($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
            goto L_80462BB8;
    }
    goto skip_3;
    // 0x80462B8C: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    skip_3:
    // 0x80462B90: jal         0x804606DC
    // 0x80462B94: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_804606DC(rdram, ctx);
        goto after_3;
    // 0x80462B94: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_3:
    // 0x80462B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462BA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80462BA4: jal         0x80463260
    // 0x80462BA8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80463260(rdram, ctx);
        goto after_4;
    // 0x80462BA8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x80462BAC: b           L_80462C44
    // 0x80462BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80462C44;
    // 0x80462BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80462BB4: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
L_80462BB8:
    // 0x80462BB8: lwc1        $f4, 0x3FF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A64));
    // 0x80462BBC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A68) << 16);
    // 0x80462BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462BC4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80462BC8: nop

    // 0x80462BCC: bc1f        L_80462C00
    if (!c1cs) {
        // 0x80462BD0: nop
    
            goto L_80462C00;
    }
    // 0x80462BD0: nop

    // 0x80462BD4: lwc1        $f6, 0x3FF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A68));
    // 0x80462BD8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A6C) << 16);
    // 0x80462BDC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80462BE0: nop

    // 0x80462BE4: bc1f        L_80462C00
    if (!c1cs) {
        // 0x80462BE8: nop
    
            goto L_80462C00;
    }
    // 0x80462BE8: nop

    // 0x80462BEC: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80462BF0: lwc1        $f16, 0x3FFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A6C));
    // 0x80462BF4: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80462BF8: b           L_80462C40
    // 0x80462BFC: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
        goto L_80462C40;
    // 0x80462BFC: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
L_80462C00:
    // 0x80462C00: jal         0x804606DC
    // 0x80462C04: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_804606DC(rdram, ctx);
        goto after_5;
    // 0x80462C04: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_5:
    // 0x80462C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462C10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80462C14: jal         0x80463260
    // 0x80462C18: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80463260(rdram, ctx);
        goto after_6;
    // 0x80462C18: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x80462C1C: b           L_80462C44
    // 0x80462C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80462C44;
    // 0x80462C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80462C24:
    // 0x80462C24: jal         0x804606DC
    // 0x80462C28: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_804606DC(rdram, ctx);
        goto after_7;
    // 0x80462C28: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_7:
    // 0x80462C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80462C30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462C34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80462C38: jal         0x80463260
    // 0x80462C3C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80463260(rdram, ctx);
        goto after_8;
    // 0x80462C3C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_8:
L_80462C40:
    // 0x80462C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80462C44:
    // 0x80462C44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80462C48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80462C4C: jr          $ra
    // 0x80462C50: nop

    return;
    // 0x80462C50: nop

;}
RECOMP_FUNC void func_8002AE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AE98: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8002AE9C: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8002AEA0: beql        $v0, $zero, L_8002AEC4
    if (ctx->r2 == 0) {
        // 0x8002AEA4: lw          $t8, 0x180($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X180);
            goto L_8002AEC4;
    }
    goto skip_0;
    // 0x8002AEA4: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    skip_0:
    // 0x8002AEA8: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8002AEAC: bnel        $v0, $t7, L_8002AEC4
    if (ctx->r2 != ctx->r15) {
        // 0x8002AEB0: lw          $t8, 0x180($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X180);
            goto L_8002AEC4;
    }
    goto skip_1;
    // 0x8002AEB0: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    skip_1:
    // 0x8002AEB4: jal         0x80061170
    // 0x8002AEB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80061170(rdram, ctx);
        goto after_0;
    // 0x8002AEB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002AEBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002AEC0: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
L_8002AEC4:
    // 0x8002AEC4: beql        $t8, $zero, L_8002AED8
    if (ctx->r24 == 0) {
        // 0x8002AEC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002AED8;
    }
    goto skip_2;
    // 0x8002AEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8002AECC: jal         0x8004816C
    // 0x8002AED0: nop

    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8002AED0: nop

    after_1:
    // 0x8002AED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002AED8:
    // 0x8002AED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AEDC: jr          $ra
    // 0x8002AEE0: nop

    return;
    // 0x8002AEE0: nop

;}
